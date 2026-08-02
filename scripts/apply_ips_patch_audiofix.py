#!/usr/bin/env python3
"""
Apply the WPJ2 English IPS patch, but SKIP the audio bank header patch
at offset 0x68C285 that causes the game to hang.

The patch at 0x68C285 modifies a 20-byte SPI1 audio bank header at
0x68C280. The modification changes pointers/sizes in the header,
causing the game to skip loading 59120 bytes of audio bank data
from 0x68C280. Without this data, the game can't create its main
logic threads (6 and 7) and hangs after 3 display lists.

By skipping this specific IPS record, the game reads the original
JP audio bank header and loads the JP audio data. The EN code patches
(English text rendering, font, etc.) are still applied, so the game
displays English text but may play Japanese audio.
"""

import struct
import sys

ELF_OFFSET_DELTA = 0x1F400
ELF_MIN_ROM_OFFSET = 0x1000
ELF_MAX_ROM_OFFSET = 0xF24E0

# IPS record to skip: the audio bank header patch at 0x68C285
SKIP_OFFSETS = {0x68C285}

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
    max_offset = max(o + len(d) for o, d in records if o not in SKIP_OFFSETS)
    rom = bytearray(rom_data)
    if max_offset > len(rom):
        rom.extend(b'\x00' * (max_offset - len(rom)))
    for offset, data in records:
        if offset in SKIP_OFFSETS:
            print(f'  SKIP ROM patch at 0x{offset:06X} (audio bank header)')
            continue
        rom[offset:offset + len(data)] = data
    return bytes(rom)

def apply_to_elf(elf_data, records):
    elf = bytearray(elf_data)
    applied = 0
    skipped = 0
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
    print(f'  Skipping offsets: {[f"0x{o:06X}" for o in sorted(SKIP_OFFSETS)]}')
    print()

    # Patch ELF (all code patches, no skips needed — skip offset is in data area)
    print(f'Patching ELF: {elf_in}')
    elf_data = open(elf_in, 'rb').read()
    elf_patched, applied = apply_to_elf(elf_data, records)
    open(elf_out, 'wb').write(elf_patched)
    print(f'  Applied: {applied} code patches')
    print()

    # Patch ROM (skip the audio bank header patch)
    print(f'Patching ROM (skipping audio bank header): {rom_in}')
    rom_data = open(rom_in, 'rb').read()
    rom_patched = apply_to_rom(rom_data, records)
    open(rom_out, 'wb').write(rom_patched)
    print(f'  Size: {len(rom_data)} → {len(rom_patched)} bytes')
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
