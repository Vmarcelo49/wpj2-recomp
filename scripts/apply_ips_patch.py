#!/usr/bin/env python3
"""
Apply the WPJ2 English IPS patch to both the ELF binary and the ROM.

IPS format:
  Header: "PATCH" (5 bytes)
  Records:
    3 bytes offset (big-endian)
    2 bytes size (big-endian)
    if size == 0: RLE record (1 byte value, 2 bytes count)
    else: size bytes of data
  Footer: "EOF" (3 bytes)

ELF mapping: ELF_offset = ROM_offset + 0x1F400 (for .entry + .main sections)
ROM is patched directly at the IPS offset.

Usage:
  python3 apply_ips_patch.py <ips_file> <elf_file> <rom_file> <output_elf> <output_rom>
"""

import struct
import sys
import os

# ELF program header for .main segment:
#   ELF offset 0x020400, VirtAddr 0x80000400, PhysAddr 0x00001000
# So: ELF_offset = PhysAddr + (0x020400 - 0x00001000) = PhysAddr + 0x1F400
# And: PhysAddr = ROM_offset (for PI DMA)
# Therefore: ELF_offset = ROM_offset + 0x1F400
ELF_OFFSET_DELTA = 0x1F400

# The .main segment in the ELF spans:
#   PhysAddr 0x00001000 to 0x00001000 + 0xF14E0 = 0x000F24E0
# So ROM offsets 0x1000 to 0xF24E0 map to the ELF.
ELF_MIN_ROM_OFFSET = 0x1000
ELF_MAX_ROM_OFFSET = 0xF24E0

def parse_ips(ips_data):
    """Parse an IPS file and return a list of (offset, data_bytes) records."""
    assert ips_data[:5] == b'PATCH', 'Not an IPS file'
    pos = 5
    records = []
    
    while pos < len(ips_data):
        if ips_data[pos:pos+3] == b'EOF':
            break
        
        offset = struct.unpack('>I', b'\x00' + ips_data[pos:pos+3])[0]
        pos += 3
        size = struct.unpack('>H', ips_data[pos:pos+2])[0]
        pos += 2
        
        if size == 0:
            # RLE record: fill count bytes with value
            value = ips_data[pos]
            pos += 1
            count = struct.unpack('>H', ips_data[pos:pos+2])[0]
            pos += 2
            records.append((offset, bytes([value]) * count))
        else:
            records.append((offset, ips_data[pos:pos+size]))
            pos += size
    
    return records

def apply_to_rom(rom_data, records):
    """Apply all IPS records to the ROM. The ROM may need to grow beyond 8MB."""
    # Find the maximum offset to determine the new ROM size
    max_offset = 0
    for offset, data in records:
        end = offset + len(data)
        if end > max_offset:
            max_offset = end
    
    # Create a new ROM buffer that's large enough
    new_size = max(max_offset, len(rom_data))
    rom = bytearray(rom_data)
    if new_size > len(rom):
        rom.extend(b'\x00' * (new_size - len(rom)))
    
    # Apply patches
    for offset, data in records:
        rom[offset:offset + len(data)] = data
    
    return bytes(rom)

def apply_to_elf(elf_data, records):
    """Apply only the records that fall within the .main/.entry sections."""
    elf = bytearray(elf_data)
    applied = 0
    skipped = 0
    
    for offset, data in records:
        if ELF_MIN_ROM_OFFSET <= offset < ELF_MAX_ROM_OFFSET:
            elf_offset = offset + ELF_OFFSET_DELTA
            end = elf_offset + len(data)
            if end <= len(elf):
                elf[elf_offset:end] = data
                applied += 1
            else:
                # Patch extends beyond ELF — skip (shouldn't happen for .main)
                skipped += 1
        else:
            skipped += 1
    
    return bytes(elf), applied, skipped

def main():
    if len(sys.argv) != 6:
        print(f'Usage: {sys.argv[0]} <ips_file> <elf_in> <rom_in> <elf_out> <rom_out>')
        sys.exit(1)
    
    ips_file = sys.argv[1]
    elf_in = sys.argv[2]
    rom_in = sys.argv[3]
    elf_out = sys.argv[4]
    rom_out = sys.argv[5]
    
    print(f'Reading IPS patch: {ips_file}')
    ips_data = open(ips_file, 'rb').read()
    records = parse_ips(ips_data)
    print(f'  {len(records)} patch records')
    
    total_bytes = sum(len(d) for _, d in records)
    max_offset = max(o + len(d) for o, d in records)
    print(f'  {total_bytes} total patched bytes')
    print(f'  Patch range: 0x{records[0][0]:06X} - 0x{max_offset:06X}')
    print()
    
    # --- Patch ELF ---
    print(f'Patching ELF: {elf_in}')
    elf_data = open(elf_in, 'rb').read()
    elf_patched, elf_applied, elf_skipped = apply_to_elf(elf_data, records)
    open(elf_out, 'wb').write(elf_patched)
    print(f'  Applied: {elf_applied} records, Skipped: {elf_skipped} (runtime-only)')
    print(f'  Output: {elf_out} ({len(elf_patched)} bytes)')
    print()
    
    # --- Patch ROM ---
    print(f'Patching ROM: {rom_in}')
    rom_data = open(rom_in, 'rb').read()
    rom_patched = apply_to_rom(rom_data, records)
    open(rom_out, 'wb').write(rom_patched)
    print(f'  All {len(records)} records applied')
    print(f'  Original size: {len(rom_data)} bytes ({len(rom_data)/1024/1024:.2f} MB)')
    print(f'  Patched size:  {len(rom_patched)} bytes ({len(rom_patched)/1024/1024:.2f} MB)')
    print(f'  Output: {rom_out}')
    print()
    
    # --- Compute new ROM hash ---
    import hashlib
    md5 = hashlib.md5(rom_patched).hexdigest()
    print(f'Patched ROM MD5: {md5}')
    
    # Compute XXH3 hash (needed for recomp::GameEntry)
    try:
        import xxhash
        xxh = xxhash.xxh3_64_digest(rom_patched)
        xxh_int = int.from_bytes(xxh, 'little')
        # The C function returns the hash as unsigned long long directly,
        # which is the big-endian interpretation of the digest bytes.
        xxh_int_be = int.from_bytes(xxh, 'big')
        print(f'Patched ROM XXH3-64 (hex): {xxh.hex()}')
        print(f'Patched ROM XXH3-64 (int, BE): {xxh_int_be}')
    except ImportError:
        print('  (install xxhash: pip install xxhash)')

if __name__ == '__main__':
    main()
