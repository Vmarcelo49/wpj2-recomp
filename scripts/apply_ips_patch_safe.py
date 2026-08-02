#!/usr/bin/env python3
"""
Apply the WPJ2 English IPS patch to the ELF, but ONLY apply code patches
that are 4-byte aligned and modify complete MIPS instructions.

Many IPS patch records fall at odd offsets (e.g. 0x07E49F) which means
they modify individual bytes WITHIN a MIPS instruction, not the whole
instruction. When applied to the ELF, this corrupts the instruction
boundary and causes N64Recomp to generate broken C code.

Strategy:
- For code patches (in .main section, outside gspFast3D):
  - If the patch offset is 4-byte aligned AND the patch size is a multiple
    of 4, apply it (safe — modifies complete instructions)
  - Otherwise, skip it (unsafe — would corrupt instruction boundaries)
- For data patches (outside .main): apply to ROM only (always safe)

The ROM gets ALL patches (code + data) because the ROM is read byte-by-byte
via PI DMA, so alignment doesn't matter there.
"""

import struct
import sys

ELF_OFFSET_DELTA = 0x1F400
ELF_MIN_ROM_OFFSET = 0x1000
ELF_MAX_ROM_OFFSET = 0xF24E0
GSP_FAST3D_START = 0x0E6180
GSP_FAST3D_END   = 0x0E6500

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
    for offset, data in records:
        rom[offset:offset + len(data)] = data
    return bytes(rom)

def apply_to_elf_safe(elf_data, records):
    """Apply only 4-byte-aligned code patches to the ELF."""
    elf = bytearray(elf_data)
    applied = 0
    skipped_unaligned = 0
    skipped_gsp = 0
    skipped_data = 0
    
    for offset, data in records:
        if not (ELF_MIN_ROM_OFFSET <= offset < ELF_MAX_ROM_OFFSET):
            skipped_data += 1
            continue
        
        if GSP_FAST3D_START <= offset < GSP_FAST3D_END:
            skipped_gsp += 1
            continue
        
        # Check alignment: offset must be 4-byte aligned and data length
        # must be a multiple of 4 for safe instruction patching
        if (offset % 4) != 0 or (len(data) % 4) != 0:
            skipped_unaligned += 1
            continue
        
        elf_offset = offset + ELF_OFFSET_DELTA
        end = elf_offset + len(data)
        if end <= len(elf):
            elf[elf_offset:end] = data
            applied += 1
    
    return bytes(elf), applied, skipped_unaligned, skipped_gsp, skipped_data

def main():
    if len(sys.argv) != 6:
        print(f'Usage: {sys.argv[0]} <ips_file> <elf_in> <rom_in> <elf_out> <rom_out>')
        sys.exit(1)
    
    ips_file, elf_in, rom_in, elf_out, rom_out = sys.argv[1:6]
    
    print(f'Reading IPS patch: {ips_file}')
    ips_data = open(ips_file, 'rb').read()
    records = parse_ips(ips_data)
    print(f'  {len(records)} patch records total')
    
    # --- Patch ELF (safe: only aligned code patches, skip gspFast3D) ---
    print(f'\nPatching ELF (safe mode): {elf_in}')
    elf_data = open(elf_in, 'rb').read()
    elf_patched, applied, skipped_unaligned, skipped_gsp, skipped_data = \
        apply_to_elf_safe(elf_data, records)
    open(elf_out, 'wb').write(elf_patched)
    print(f'  Applied (aligned):     {applied}')
    print(f'  Skipped (unaligned):   {skipped_unaligned}')
    print(f'  Skipped (gspFast3D):   {skipped_gsp}')
    print(f'  Skipped (data-only):   {skipped_data}')
    print(f'  Output: {elf_out}')
    
    # --- Patch ROM (ALL patches) ---
    print(f'\nPatching ROM: {rom_in}')
    rom_data = open(rom_in, 'rb').read()
    rom_patched = apply_to_rom(rom_data, records)
    open(rom_out, 'wb').write(rom_patched)
    print(f'  All {len(records)} records applied')
    print(f'  Size: {len(rom_data)} → {len(rom_patched)} bytes')
    print(f'  Output: {rom_out}')
    
    # --- Hash ---
    import hashlib
    md5 = hashlib.md5(rom_patched).hexdigest()
    print(f'\nPatched ROM MD5: {md5}')
    try:
        import xxhash
        xxh = xxhash.xxh3_64_digest(rom_patched)
        print(f'Patched ROM XXH3-64: 0x{int.from_bytes(xxh, "big"):016X}')
    except ImportError:
        pass

if __name__ == '__main__':
    main()
