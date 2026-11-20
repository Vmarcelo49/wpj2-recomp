#!/usr/bin/env python3
"""Regression tests for the WPJ2 IPS/BPS tooling. No GUI or extra packages.

Run: python3 scripts/test_patch_tools.py

Canonical-file tests skip when the user-supplied JP ROM, verified English ROM,
or upstream Flips binary is unavailable. Override paths with WPJ2_JP_ROM,
WPJ2_EN_ROM and WPJ2_FLIPS.
"""

import hashlib
import os
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path

import ips_to_bps
import patch_utils

REPO = Path(__file__).resolve().parents[1]
WORK = REPO.parent / "wpj2-work"
JP_ROM = Path(os.environ.get("WPJ2_JP_ROM", str(REPO / "input" / "wpj2.j1.z64")))
EN_ROM = Path(os.environ.get("WPJ2_EN_ROM", str(WORK / "reference" / "english.z64")))
IPS_FILE = REPO / "patches" / "Wpj2e_v1_z64.ips"
FLIPS = Path(os.environ.get("WPJ2_FLIPS", str(WORK / "reference" / "flips-upstream" / "flips")))

EXPECTED_EN_SIZE = 8912896
EXPECTED_EN_MD5 = "3c02f56dd7b1a06be83a7a288755612f"
EXPECTED_RLE_RECORDS = 47


def count_rle_records(data: bytes) -> int:
    """Count IPS records whose size field is zero."""
    assert data[:5] == b"PATCH"
    pos = 5
    count = 0
    while data[pos:pos + 3] != b"EOF":
        pos += 3
        size = int.from_bytes(data[pos:pos + 2], "big")
        pos += 2
        if size == 0:
            count += 1
            pos += 3  # 2-byte count + 1-byte value
        else:
            pos += size
    return count


def read_bps_number(patch: bytes, pos: int) -> tuple[int, int]:
    """Independent decoder for the BPS variable-length integer format."""
    data = 0
    shift = 1
    while True:
        byte = patch[pos]
        pos += 1
        data += (byte & 0x7F) * shift
        if byte & 0x80:
            break
        shift <<= 7
        data += shift
    return data, pos


def decode_bps(patch: bytes, source: bytes) -> tuple[bytes, int, int, tuple[int, int, int]]:
    """Decode a BPS patch without using ips_to_bps.py's encoder logic."""
    if patch[:4] != b"BPS1":
        raise ValueError("not a BPS patch")
    pos = 4
    src_len, pos = read_bps_number(patch, pos)
    tgt_len, pos = read_bps_number(patch, pos)
    meta_len, pos = read_bps_number(patch, pos)
    pos += meta_len

    output = bytearray()
    actions_end = len(patch) - 12
    while pos < actions_end:
        action, pos = read_bps_number(patch, pos)
        length = (action >> 2) + 1
        kind = action & 3
        if kind == 0:  # SourceRead from the current output position.
            output.extend(source[len(output):len(output) + length])
        elif kind == 1:  # TargetRead
            output.extend(patch[pos:pos + length])
            pos += length
        else:
            # make_bps only emits SourceRead and TargetRead.
            raise ValueError(f"unsupported BPS action {kind} in test decoder")

    source_crc, target_crc, patch_crc = struct.unpack("<III", patch[-12:])
    return bytes(output), src_len, tgt_len, (source_crc, target_crc, patch_crc)


class IpsParserTests(unittest.TestCase):
    def test_rle_record_field_order(self):
        patch = (b"PATCH"
                 + (0x10).to_bytes(3, "big") + (0).to_bytes(2, "big")
                 + (5).to_bytes(2, "big") + b"\xaa"
                 + (0x20).to_bytes(3, "big") + (3).to_bytes(2, "big") + b"xyz"
                 + b"EOF")
        expected = [(0x10, b"\xaa" * 5), (0x20, b"xyz")]
        for parse in (patch_utils.parse_ips,):
            with self.subTest(parser=parse.__module__):
                self.assertEqual(parse(patch), expected)

    def test_malformed_records_are_rejected(self):
        cases = [
            b"PATCH" + (0).to_bytes(3, "big") + (1).to_bytes(2, "big") + b"x",
            b"PATCH" + b"EOF" + b"junk",
            b"PATCH" + (0).to_bytes(3, "big") + (0).to_bytes(2, "big") + b"\x05",
        ]
        for patch in cases:
            with self.subTest(patch=patch):
                with self.assertRaises(ValueError):
                    patch_utils.parse_ips(patch)

    @unittest.skipUnless(IPS_FILE.exists(), "tracked IPS patch missing")
    def test_tracked_patch_structure(self):
        raw = IPS_FILE.read_bytes()
        records = patch_utils.parse_ips(raw)
        self.assertEqual(len(records), 410)
        self.assertEqual(count_rle_records(raw), EXPECTED_RLE_RECORDS)
        self.assertEqual(patch_utils.count_rle_records(raw), EXPECTED_RLE_RECORDS)
        self.assertEqual(max(offset + len(data) for offset, data in records), EXPECTED_EN_SIZE)

    @unittest.skipUnless(IPS_FILE.exists() and JP_ROM.exists() and EN_ROM.exists(),
                         "canonical JP/EN ROMs missing")
    def test_rebuilt_image_matches_upstream_flips(self):
        en = EN_ROM.read_bytes()
        self.assertEqual(len(en), EXPECTED_EN_SIZE)
        self.assertEqual(hashlib.md5(en).hexdigest(), EXPECTED_EN_MD5)
        patched = ips_to_bps.build_target(JP_ROM.read_bytes(), patch_utils.read_ips(IPS_FILE))
        self.assertEqual(patched, en)


class BpsTests(unittest.TestCase):
    def test_small_roundtrip_and_checksums(self):
        source = bytes(range(256)) * 8
        target = bytearray(source)
        target[100:104] = b"TEST"
        target += b"\xff" * 300
        target = bytes(target)
        patch = ips_to_bps.make_bps(source, target)

        decoded, src_len, tgt_len, crcs = decode_bps(patch, source)
        self.assertEqual(decoded, target)
        self.assertEqual((src_len, tgt_len), (len(source), len(target)))
        self.assertEqual(crcs, (
            ips_to_bps.crc32(source),
            ips_to_bps.crc32(target),
            ips_to_bps.crc32(patch[:-4]),
        ))

    def test_unsupported_bps_actions_are_rejected(self):
        patch = b"BPS1" + b"\x88\x88\x80\x82\x80" + b"\x00" * 12
        with self.assertRaisesRegex(ValueError, "unsupported BPS action"):
            decode_bps(patch, bytes(8))

    @unittest.skipUnless(IPS_FILE.exists() and JP_ROM.exists() and EN_ROM.exists(),
                         "canonical JP/EN ROMs missing")
    def test_full_patch_applies_with_upstream_flips(self):
        if not FLIPS.exists():
            self.skipTest("upstream Flips CLI not built")
        source = JP_ROM.read_bytes()
        target = EN_ROM.read_bytes()
        patch = ips_to_bps.make_bps(source, target)
        with tempfile.TemporaryDirectory() as tmp:
            tmp = Path(tmp)
            patch_path = tmp / "english.bps"
            out_path = tmp / "english.z64"
            patch_path.write_bytes(patch)
            result = subprocess.run(
                [str(FLIPS), "--apply", "--exact", str(patch_path), str(JP_ROM), str(out_path)],
                capture_output=True, text=True,
            )
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            self.assertEqual(out_path.read_bytes(), target)


if __name__ == "__main__":
    unittest.main(verbosity=2)
