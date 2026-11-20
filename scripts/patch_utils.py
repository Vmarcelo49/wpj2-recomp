#!/usr/bin/env python3
"""Shared IPS parsing helpers for the WPJ2 patch utilities.

IPS RLE records store a 3-byte offset, a zero 2-byte size, then a 2-byte
big-endian count followed by a single value byte.  Reversing count and value
produces a corrupt ROM; see the upstream Flips implementation:

    https://github.com/Alcaro/Flips/blob/master/libips.cpp
"""

from pathlib import Path

IPS_MAGIC = b"PATCH"
IPS_EOF = b"EOF"


def parse_ips_detailed(data: bytes) -> list[tuple[int, bytes, bool]]:
    """Return ``(offset, data, is_rle)`` records in file order."""
    if data[:len(IPS_MAGIC)] != IPS_MAGIC:
        raise ValueError("not an IPS file")

    pos = len(IPS_MAGIC)
    records: list[tuple[int, bytes, bool]] = []
    while pos < len(data):
        if data[pos:pos + len(IPS_EOF)] == IPS_EOF:
            pos += len(IPS_EOF)
            if pos != len(data):
                raise ValueError(f"unexpected trailing data after IPS EOF at {pos}")
            return records
        if pos + 5 > len(data):
            raise ValueError(f"truncated IPS record at {pos}")

        offset = int.from_bytes(data[pos:pos + 3], "big")
        pos += 3
        size = int.from_bytes(data[pos:pos + 2], "big")
        pos += 2

        if size == 0:
            if pos + 3 > len(data):
                raise ValueError(f"truncated IPS RLE record at {pos}")
            count = int.from_bytes(data[pos:pos + 2], "big")
            pos += 2
            value = data[pos]
            pos += 1
            if count == 0:
                raise ValueError(f"zero-length IPS RLE record at {pos}")
            records.append((offset, bytes([value]) * count, True))
            continue

        if pos + size > len(data):
            raise ValueError(f"truncated IPS record at {pos}")
        records.append((offset, data[pos:pos + size], False))
        pos += size

    raise ValueError("IPS file has no EOF marker")


def parse_ips(data: bytes) -> list[tuple[int, bytes]]:
    """Return ``(offset, data)`` records in file order."""
    return [(offset, payload) for offset, payload, _ in parse_ips_detailed(data)]


def count_rle_records(data: bytes) -> int:
    """Count run-length-encoded records in an IPS file."""
    return sum(1 for _, _, is_rle in parse_ips_detailed(data) if is_rle)


def read_ips(path: str | Path) -> list[tuple[int, bytes]]:
    """Read and parse an IPS file."""
    return parse_ips(Path(path).read_bytes())
