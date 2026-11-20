# 13 — English Translation (native recomp)

English dialogue is available when the **canonical translated ROM** is paired
with **CPU sources recompiled from that ROM**. Using only the English ROM data
with Japanese-compiled CPU code reaches the early scene but then stalls.

## Why the old attempts failed

The tracked pre-fix patch scripts decoded IPS run-length records as
`value, count`. The correct IPS layout is `count, value`: a two-byte big-endian
count followed by one value byte. See the
[Flips reference implementation](https://github.com/Alcaro/Flips/blob/master/libips.cpp).
The old decoder produced an invalid ROM with the hardcoded hash
`0x67E5F70F31E1E6D7`.

The corrected canonical ROM has:

- size 8,912,896 bytes (`0x880000`)
- MD5 `3c02f56dd7b1a06be83a7a288755612f`
- SHA256 `cf0e08c8349291ee5561ba03fa82287a505acece1644588001937b0abc732d31`
- XXH3-64 `0xEDF6BD1A8E68B1DC`

It was produced independently with upstream Flips from the verified Japanese
ROM and the tracked IPS patch. The CIC6102 checksums are valid
(`4f1e88f7 4a5a3f96` for the translated ROM); the old image is not.

The old `apply_ips_patch_audiofix*.py`, `apply_ips_patch_headerfix.py`,
`apply_ips_patch_safe.py`, and `apply_ips_patch_smart.py` scripts were removed:
they were written around the bad decode and their diagnoses were invalid.

## Correct patch tooling

Run the regression tests:

```bash
python3 scripts/test_patch_tools.py
```

`scripts/ips_to_bps.py` applies IPS correctly and can generate a BPS image:

```bash
python3 scripts/ips_to_bps.py \
  --ips patches/Wpj2e_v1_z64.ips \
  --rom /path/to/wpj2.j1.z64 \
  --bps /path/to/english.bps
```

The BPS was verified with both upstream Flips and librecomp's patcher.

## Runtime prerequisites

The tracked VI patch is applied automatically during CMake configuration. It
fixes an upstream null-mode dereference that otherwise crashes startup.

## Generate and build the English CPU variant

`scripts/generate_en_cpu.py` reconstructs N64Recomp symbols from the tracked
generated section table and regenerates the English CPU from the canonical
ROM. It requires a built `build_tools/N64Recomp`.

```bash
python3 scripts/generate_en_cpu.py \
  --repo /path/to/wpj2-recomp \
  --jp-rom /path/to/wpj2.j1.z64 \
  --work /path/to/wpj2-work/cpu
```

Then build with the generated EN sources and a separate build directory:

```bash
cmake -B build-en -G Ninja \
  -DWPJ2_GENERATED_DIR=/path/to/wpj2-work/cpu/generated_en \
  -DWPJ2_ENGLISH_BUILD=ON
cmake --build build-en --target wpj2
```

The two built variants must not share a config directory. Each build selects
its own ROM hash and game id. `WPJ2_CONFIG_DIR` isolates saves and ROM copies;
`WPJ2_ROM` overrides the input ROM for testing.

## Verified result

Canonical English ROM plus the regenerated English CPU renders readable
English dialogue and advances on input. The only executable changes are 175
annotated MIPS instruction words in 34 functions, mostly text pointer and
layout adjustments. No emulator-specific RSP patching or selective ROM-range
guesswork is required.
