#!/usr/bin/env python3
"""Convert the WPJ2 English IPS patch into a BPS patch for verification.

Every IPS record is applied in file order. The resulting BPS patch is useful
for independent verification with upstream Flips and librecomp's patcher. A
ROM patch alone is not sufficient for this recomp: execution changes must be
generated into the CPU code as well. See docs/13-english-patch.md.

Usage:
    python3 scripts/ips_to_bps.py \
        --ips patches/Wpj2e_v1_z64.ips \
        --rom /path/to/wpj2.j1.z64 \
        --bps /path/to/english.bps \
        [--patched-rom /path/to/english.z64]
"""

import argparse
import binascii
import struct

from patch_utils import read_ips

BPS_MAGIC = b"BPS1"


def encode_number(value: int) -> bytes:
    """Encode a BPS variable-length integer."""
    if value < 0:
        raise ValueError("negative BPS number")
    out = bytearray()
    while value >= 0x80:
        out.append(value & 0x7F)
        value = (value >> 7) - 1
    out.append(value | 0x80)
    return bytes(out)


def crc32(data: bytes) -> int:
    return binascii.crc32(data) & 0xFFFFFFFF


def make_bps(source: bytes, target: bytes) -> bytes:
    """Encode source->target using only SourceRead/TargetRead actions."""
    actions = bytearray()
    i = 0
    src_len, tgt_len = len(source), len(target)
    while i < tgt_len:
        if i < src_len and source[i] == target[i]:
            j = i + 1
            while j < tgt_len and j < src_len and source[j] == target[j]:
                j += 1
            actions += encode_number(((j - i - 1) << 2) | 0)  # SourceRead
        else:
            j = i + 1
            while j < tgt_len and (j >= src_len or source[j] != target[j]):
                j += 1
            actions += encode_number(((j - i - 1) << 2) | 1)  # TargetRead
            actions += target[i:j]
        i = j

    header = BPS_MAGIC + encode_number(src_len) + encode_number(tgt_len)
    header += encode_number(0)  # metadata length
    body = header + bytes(actions)
    # The patch checksum covers every preceding byte, including the source and
    # target checksums.
    checked = body + struct.pack("<II", crc32(source), crc32(target))
    return checked + struct.pack("<I", crc32(checked))


def build_target(rom: bytes, records: list[tuple[int, bytes]]) -> bytes:
    """Apply every IPS record in file order."""
    max_end = max((offset + len(data) for offset, data in records), default=0)
    target = bytearray(rom)
    if max_end > len(target):
        target.extend(b"\x00" * (max_end - len(target)))
    for offset, data in records:
        target[offset:offset + len(data)] = data
    return bytes(target)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--ips", required=True, help="input IPS patch")
    parser.add_argument("--rom", required=True, help="original Japanese .z64 ROM")
    parser.add_argument("--bps", required=True, help="output BPS patch")
    parser.add_argument("--patched-rom", help="also write the resulting ROM")
    args = parser.parse_args()

    records = read_ips(args.ips)
    rom = open(args.rom, "rb").read()
    target = build_target(rom, records)

    with open(args.bps, "wb") as f:
        f.write(make_bps(rom, target))
    print(f"BPS written: {args.bps}")

    if args.patched_rom:
        with open(args.patched_rom, "wb") as f:
            f.write(target)
        print(f"Patched ROM written: {args.patched_rom}")


if __name__ == "__main__":
    main()
