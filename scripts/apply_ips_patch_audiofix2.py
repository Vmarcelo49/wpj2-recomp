#!/usr/bin/env python3
"""
Apply the WPJ2 English IPS patch, then RESTORE specific ROM areas
to their original JP values to fix the audio sequence data corruption.

The EN patch at 0x689200 (36608 bytes) fills the audio sequence/bank
area with 0x09 bytes, replacing structured JP audio data. The game
reads this data via PI DMA (8-byte entries at 0x689B90-0x689BB0) and
uses them as audio sequence pointers. With 0x09 bytes, the game gets
invalid pointers and hangs after 3 display lists.

Fix: After applying all EN patches, overwrite the area 0x689200-0x6923F0
(36608 bytes) with the original JP data. This preserves:
- English text in the extended ROM area (>8MB)
- English font/rendering code patches (in the ELF)
- English text patches at other ROM offsets (0x689FCA, 0x68B8E0, etc.
  are within this range and WILL be lost — some menu text will be JP)

Trade-off: Some menu text (Start, Delete Diary, etc.) will be in Japanese,
but the game will boot and run instead of hanging.
"""

import struct
import sys

ELF_OFFSET_DELTA = 0x1F400
ELF_MIN_ROM_OFFSET = 0x1000
ELF_MAX_ROM_OFFSET = 0xF24E0

# Area to restore to JP: the 36608-byte audio sequence/bank region
# that the EN patch fills with 0x09.
RESTORE_START = 0x689200
RESTORE_SIZE = 36608
RESTORE_END = RESTORE_START + RESTORE_SIZE  # 0x6923F0

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
    # RESTORE the audio sequence area to JP values
    print(f'  Restoring JP audio data at 0x{RESTORE_START:06X}-0x{RESTORE_END:06X} ({RESTORE_SIZE} bytes)')
    rom[RESTORE_START:RESTORE_END] = rom_data[RESTORE_START:RESTORE_END]
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

    # Patch ROM (all patches + restore JP audio data)
    print(f'Patching ROM (all patches + JP audio restore): {rom_in}')
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
