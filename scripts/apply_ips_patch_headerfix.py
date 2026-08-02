#!/usr/bin/env python3
"""
Apply the WPJ2 English IPS patch, then RESTORE the 20-byte audio bank
header at ROM offset 0x68C280 to its original JP values.

Three IPS patches modify the header at 0x68C280:
  - 0x689200 (36608 bytes) — overlaps 0x68C280
  - 0x68A650 (10496 bytes) — overlaps 0x68C280
  - 0x68C285 (7552 bytes)  — starts at 0x68C285

All three are applied (for their text/data content), but AFTER all
patches are applied, we overwrite the 20 bytes at 0x68C280 with the
original JP header values. This tells the game to load the JP audio
bank data (59120 bytes from 0x68C280), which allows it to create
its main logic threads and proceed past the boot sequence.

The EN text data in the extended ROM area (>8MB) is still loaded
because the game follows EN-modified pointers to that area.
"""

import struct
import sys

ELF_OFFSET_DELTA = 0x1F400
ELF_MIN_ROM_OFFSET = 0x1000
ELF_MAX_ROM_OFFSET = 0xF24E0

# Original JP 20-byte audio bank header at ROM 0x68C280
JP_AUDIO_HEADER = bytes.fromhex('535049310001d40000002136000010cf0000b4d7')
AUDIO_HEADER_OFFSET = 0x68C280

def parse_ips(ips_data):
    assert ips_data[:5] == b'PATCH'
    pos = 5
    records = []
    while pos < len(ips_data):
        if ips_data[pos:pos+3] == b'EOF': break
        offset = struct.unpack('>I', b'\x00' + ips_data[pos:pos+3])[0]; pos += 3
        size = struct.unpack('>H', ips_data[pos:pos+2])[0]; pos += 2
        if size == 0:
            value = ips_data[pos]; pos += 1
            count = struct.unpack('>H', ips_data[pos:pos+2])[0]; pos += 2
            records.append((offset, bytes([value]) * count))
        else:
            records.append((offset, ips_data[pos:pos+size])); pos += size
    return records

def apply_to_rom(rom_data, records):
    max_offset = max(o + len(d) for o, d in records)
    rom = bytearray(rom_data)
    if max_offset > len(rom):
        rom.extend(b'\x00' * (max_offset - len(rom)))
    # Apply ALL patches
    for offset, data in records:
        rom[offset:offset + len(data)] = data
    # RESTORE the 20-byte audio bank header to JP values
    print(f'  Restoring JP audio header at 0x{AUDIO_HEADER_OFFSET:06X}')
    rom[AUDIO_HEADER_OFFSET:AUDIO_HEADER_OFFSET + 20] = JP_AUDIO_HEADER
    return bytes(rom)

def apply_to_elf(elf_data, records):
    elf = bytearray(elf_data)
    applied = 0
    for offset, data in records:
        if not (ELF_MIN_ROM_OFFSET <= offset < ELF_MAX_ROM_OFFSET):
            continue
        elf_offset = offset + ELF_OFFSET_DELTA
        end = elf_offset + len(data)
        if end <= len(elf):
            elf[elf_offset:end] = data
            applied += 1
    return bytes(elf), applied

def main():
    if len(sys.argv) != 6:
        print(f'Usage: {sys.argv[0]} <ips_file> <elf_in> <rom_in> <elf_out> <rom_out>')
        sys.exit(1)

    ips_file, elf_in, rom_in, elf_out, rom_out = sys.argv[1:6]

    print(f'Reading IPS patch: {ips_file}')
    ips_data = open(ips_file, 'rb').read()
    records = parse_ips(ips_data)
    print(f'  {len(records)} patch records')
    print()

    # Patch ELF (all code patches)
    print(f'Patching ELF: {elf_in}')
    elf_data = open(elf_in, 'rb').read()
    elf_patched, applied = apply_to_elf(elf_data, records)
    open(elf_out, 'wb').write(elf_patched)
    print(f'  Applied: {applied} code patches')
    print()

    # Patch ROM (all patches + restore JP audio header)
    print(f'Patching ROM (all patches + JP audio header restore): {rom_in}')
    rom_data = open(rom_in, 'rb').read()
    rom_patched = apply_to_rom(rom_data, records)
    open(rom_out, 'wb').write(rom_patched)
    print(f'  Size: {len(rom_data)} -> {len(rom_patched)} bytes')
    print()

    # Hash
    import hashlib
    md5 = hashlib.md5(rom_patched).hexdigest()
    print(f'Patched ROM MD5: {md5}')
    try:
        import xxhash
        xxh = xxhash.xxh3_64_digest(rom_patched)
        print(f'Patched ROM XXH3-64: 0x{int.from_bytes(xxh, "big"):016X}')
    except ImportError:
        pass

if __name__ == '__main__':
    main()
