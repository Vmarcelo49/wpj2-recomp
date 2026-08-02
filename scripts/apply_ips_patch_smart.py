#!/usr/bin/env python3
"""
Apply the WPJ2 English IPS patch, but SKIP patches that fall in the
gspFast3D RSP ucode area. The translation patch NOPs out this code
because traditional emulators HLE the RSP graphics microcode — but
in our recomp setup, N64Recomp recompiles this code as regular
functions. NOPping it causes the recompiled functions to do nothing,
leading to deadlocks.

We skip code patches in the ROM range 0x0E6180-0x0E6500 (VRAM
0x800E6180-0x800E6500), which is where the gspFast3D ucode lives
in the .main section.

All other patches (text data, font rendering code, menu code, etc.)
are applied normally.
"""

import struct
import sys
import os

ELF_OFFSET_DELTA = 0x1F400
ELF_MIN_ROM_OFFSET = 0x1000
ELF_MAX_ROM_OFFSET = 0xF24E0

# gspFast3D ucode area in ROM (within .main section).
# The translation patch NOPs out this entire region because traditional
# emulators don't execute RSP code — they HLE it. In our recomp setup,
# N64Recomp recompiles this code, so we must NOT patch it.
GSP_FAST3D_START = 0x0E6180
GSP_FAST3D_END   = 0x0E6500

def parse_ips(ips_data):
    assert ips_data[:5] == b'PATCH', 'Not an IPS file'
    pos = 5
    records = []
    while pos < len(ips_data):
        if ips_data[pos:pos+3] == b'EOF':
            break
        offset = struct.unpack('>I', b'\x00' + ips_data[pos:pos+3])[0]; pos += 3
        size = struct.unpack('>H', ips_data[pos:pos+2])[0]; pos += 2
        if size == 0:
            value = ips_data[pos]; pos += 1
            count = struct.unpack('>H', ips_data[pos:pos+2])[0]; pos += 2
            records.append((offset, bytes([value]) * count))
        else:
            records.append((offset, ips_data[pos:pos+size])); pos += size
    return records

def is_in_gsp_fast3d(offset, data_len):
    """Check if a patch record falls within the gspFast3D ucode area."""
    patch_end = offset + data_len
    return offset >= GSP_FAST3D_START and patch_end <= GSP_FAST3D_END

def apply_to_rom(rom_data, records):
    max_offset = max(o + len(d) for o, d in records)
    rom = bytearray(rom_data)
    if max_offset > len(rom):
        rom.extend(b'\x00' * (max_offset - len(rom)))
    for offset, data in records:
        rom[offset:offset + len(data)] = data
    return bytes(rom)

def apply_to_elf(elf_data, records):
    """Apply code patches to ELF, SKIPPING gspFast3D ucode patches."""
    elf = bytearray(elf_data)
    applied = 0
    skipped_gsp = 0
    skipped_data = 0
    
    for offset, data in records:
        if not (ELF_MIN_ROM_OFFSET <= offset < ELF_MAX_ROM_OFFSET):
            skipped_data += 1
            continue
        
        if is_in_gsp_fast3d(offset, len(data)):
            skipped_gsp += 1
            continue
        
        elf_offset = offset + ELF_OFFSET_DELTA
        end = elf_offset + len(data)
        if end <= len(elf):
            elf[elf_offset:end] = data
            applied += 1
    
    return bytes(elf), applied, skipped_gsp, skipped_data

def main():
    if len(sys.argv) != 6:
        print(f'Usage: {sys.argv[0]} <ips_file> <elf_in> <rom_in> <elf_out> <rom_out>')
        sys.exit(1)
    
    ips_file, elf_in, rom_in, elf_out, rom_out = sys.argv[1:6]
    
    print(f'Reading IPS patch: {ips_file}')
    ips_data = open(ips_file, 'rb').read()
    records = parse_ips(ips_data)
    print(f'  {len(records)} patch records')
    
    # Count gspFast3D patches
    gsp_count = sum(1 for o, d in records if is_in_gsp_fast3d(o, len(d)))
    print(f'  gspFast3D ucode patches (SKIPPED for ELF): {gsp_count}')
    print(f'  gspFast3D range: 0x{GSP_FAST3D_START:06X}-0x{GSP_FAST3D_END:06X}')
    print()
    
    # --- Patch ELF (skip gspFast3D) ---
    print(f'Patching ELF: {elf_in}')
    elf_data = open(elf_in, 'rb').read()
    elf_patched, applied, skipped_gsp, skipped_data = apply_to_elf(elf_data, records)
    open(elf_out, 'wb').write(elf_patched)
    print(f'  Applied: {applied} code patches')
    print(f'  Skipped: {skipped_gsp} gspFast3D, {skipped_data} data-only')
    print(f'  Output: {elf_out} ({len(elf_patched)} bytes)')
    print()
    
    # --- Patch ROM (ALL patches, including gspFast3D NOPs) ---
    print(f'Patching ROM: {rom_in}')
    rom_data = open(rom_in, 'rb').read()
    rom_patched = apply_to_rom(rom_data, records)
    open(rom_out, 'wb').write(rom_patched)
    print(f'  All {len(records)} records applied (including gspFast3D NOPs)')
    print(f'  Original: {len(rom_data)} bytes, Patched: {len(rom_patched)} bytes')
    print(f'  Output: {rom_out}')
    print()
    
    # --- Compute new ROM hash ---
    import hashlib
    md5 = hashlib.md5(rom_patched).hexdigest()
    print(f'Patched ROM MD5: {md5}')
    
    try:
        import xxhash
        xxh = xxhash.xxh3_64_digest(rom_patched)
        xxh_int_be = int.from_bytes(xxh, 'big')
        print(f'Patched ROM XXH3-64: 0x{xxh_int_be:016X}')
    except ImportError:
        print('  (install xxhash for XXH3 hash)')

if __name__ == '__main__':
    main()
