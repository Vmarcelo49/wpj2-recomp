# Building and Packaging wpj2-recomp

This file collects all developer, build-toolchain, and release-packaging
instructions. End users should start with the [README](../README.md) instead.

## Contents

- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Clone and build](#clone-and-build)
- [CMake options](#cmake-options)
- [Build performance](#build-performance)
- [Toolchain notes](#toolchain-notes)
- [English CPU variant](#english-cpu-variant)
- [Release packaging](#release-packaging)
- [Tests](#tests)
- [Build troubleshooting](#build-troubleshooting)
- [Further technical docs](#further-technical-docs)

## Overview

This project statically recompiles the N64 game into native code. The input is
a decompilation ELF (or a reconstructed symbol table) plus the user's original
Japanese ROM; the output is a native executable that uses N64ModernRuntime for
libultra behavior and RT64 for Vulkan rendering. Build outputs are not
emulator ROMs: game logic lives in generated C/C++, while the ROM supplies data
read via PI DMA.

Key directories:

```
src/main.cpp                  SDL2 + recomp::start integration
src/game/generated/           N64Recomp output for Japanese (8,547 functions)
src/game/generated_en/        tracked N64Recomp output for English
src/rsp/generated/aspMain.c   RSPRecomp output (904 labels)
src/graphics/                 RT64 renderer
src/audio_input/              SDL2 audio, input, Controller Pak
src/launcher/                 startup language/settings launcher
scripts/                      patch, generation, release scripts
tools/N64Recomp/              N64Recomp + RSPRecomp (submodule)
lib/N64ModernRuntime/         runtime (submodule)
lib/RT64/                     renderer (submodule)
decomp/wonder/                WPJ2 decompilation (submodule, reference)
```

## Prerequisites

### Linux (development)

- Linux (tested on Ubuntu 24.04 and Arch Linux)
- CMake 3.24+, Ninja, GCC 12+ (GCC 13+ recommended) or Clang 16+
- SDL2 development libraries
- Vulkan loader/driver (the game needs a Vulkan-capable GPU to render)
- Python 3 with `xxhash` for ROM hash verification
- Optional: `ccache` (faster rebuilds), `mold` (faster linking)

Example (Ubuntu):

```bash
sudo apt install -y ninja-build cmake g++ pkg-config \
  libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev \
  vulkan-validationlayers-dev python3-pip binutils-mips-linux-gnu libpng-dev
pip install xxhash
```

### Windows (release)

The supported Windows build is native MSVC on `windows-2022` via the manual
GitHub Actions workflow described in
[15-windows-release.md](15-windows-release.md). Local MinGW is experimental
and not verified (see that document).

## Clone and build

```bash
# Clone with all submodules
git clone --recursive https://github.com/Vmarcelo49/wpj2-recomp.git
cd wpj2-recomp

# Build N64Recomp + RSPRecomp tools (one-time)
cmake -B build_tools -S tools/N64Recomp -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build_tools --target N64RecompCLI RSPRecomp

# Regenerate recompiled sources if needed (normally already tracked)
./build_tools/N64Recomp wpj2.j1.toml
./build_tools/RSPRecomp aspMain.j1.rsp.toml

# Configure and build the Japanese game plus launcher
cmake -B build -G Ninja -DWPJ2_DEV=ON -DWPJ2_PCH=ON
cmake --build build --target wpj2 wpj2-launcher
```

The runtime submodule needs a small VI null-mode fix. CMake detects it and
applies the tracked patch automatically on first configure; the patch lives at
`patches/N64ModernRuntime/vi-null-mode.patch`. If the submodule is missing or
has unexpected local changes, configure fails with an explicit message.

Run from the repository root (the game copies the ROM into its config dir):

```bash
mkdir -p input
cp /path/to/wpj2.j1.z64 input/
./build/wpj2-jp

# Or use the launcher, which also needs the ROM beside the executable:
./build/wpj2-launcher
```

`WPJ2_ROM` selects a ROM explicitly, and `WPJ2_CONFIG_DIR` isolates saves and
cached ROM files. On Wayland, SDL2 normally auto-detects the display; if Vulkan
surface creation fails, try `SDL_VIDEODRIVER=wayland ./build/wpj2-jp`.

## CMake options

| Option | Default | Meaning |
|---|---|---|
| `WPJ2_DEV` | OFF | RelWithDebInfo, no LTO; faster iteration |
| `WPJ2_PCH` | ON | Precompile `recomp.h` + `shims.h` for generated sources |
| `WPJ2_UNITY` | OFF | Merge all `funcs_*.c` into one TU; not recommended |
| `WPJ2_LINKER` | `mold` | `mold` / `lld` / `gold` / `ld`; auto-detected |
| `WPJ2_GENERATED_DIR` | tracked JP tree | CPU source directory for the selected variant |
| `WPJ2_ENGLISH_BUILD` | OFF | Build `wpj2-en` with the English ROM hash/id |
| `WPJ2_BUILD_LAUNCHER` | ON | Build `wpj2-launcher` |

On non-MSVC x86, `-mssse3 -msse4.1` are applied for the RSP backend. Windows
builds use RT64's bundled SDL2 instead of `find_package(SDL2)`, and skip GCC-only
flags.

## Build performance

Typical timings (from [12-build-performance.md](12-build-performance.md)):

| Scenario | Time |
|---|---|
| Clean build, cold cache | ~3 min |
| Clean build, warm ccache | ~17 s |
| Incremental (one generated file) | <1 s |
| Incremental (`main.cpp`) | ~2.5 s |

The speedup comes from ccache (default 2 GiB), mold, a precompiled header, and
Ninja job pooling (`N-1` cores). Useful commands:

```bash
ccache -s          # hit/miss stats
ccache -z          # reset stats
ccache -C          # clear cache
ccache -M 5G       # enlarge cache
```

## Toolchain notes

From [03-toolchain.md](03-toolchain.md):

| Component | Purpose |
|---|---|
| N64Recomp | Translates N64 code into C (build target `N64RecompCLI`) |
| RSPRecomp | Recompiles the `aspMain` audio microcode to x86 SIMD |
| N64ModernRuntime | libultra reimplementation used by the generated code |
| RT64 | Vulkan renderer, replays Fast3D/F3DEX/S2DEX display lists |
| SDL2 | Window, audio, keyboard and gamepad |

Important details:

- The audio microcode mounts at IMEM `0x04001080`, not `0x04001000`.
- Generated code needs hidden visibility and `-fno-strict-aliasing`; a game
  symbol named `send` would otherwise collide with libc `send(2)`.
- The decomp ([LLONSIT-glitch/wonder](https://github.com/LLONSIT-glitch/wonder))
  provides the ELF with symbols. Ghidra is not required for normal builds.
- Use `g++` on Linux; clang + libstdc++ 2.24-era setups have had `u8string`
  problems in CI.

## English CPU variant

Full explanation: [13-english-patch.md](13-english-patch.md).

English text and layout changes alter executable code as well as data, so the
English ROM must be paired with CPU sources regenerated from that ROM. The
tracked IPS patch had to be decoded with the correct RLE field order
(2-byte count, then 1-byte value); the old scripts reversed it and produced an
invalid image.

Canonical English ROM: 8,912,896 bytes, MD5
`3c02f56dd7b1a06be83a7a288755612f`, XXH3-64 `0xEDF6BD1A8E68B1DC`.

To regenerate CPU sources (requires `build_tools/N64Recomp`):

```bash
python3 scripts/generate_en_cpu.py \
  --repo /path/to/wpj2-recomp \
  --jp-rom /path/to/wpj2.j1.z64 \
  --work /path/to/wpj2-work/cpu
```

Then build in a separate directory:

```bash
cmake -B build-en -G Ninja \
  -DWPJ2_GENERATED_DIR=/path/to/wpj2-work/cpu/generated_en \
  -DWPJ2_ENGLISH_BUILD=ON
cmake --build build-en --target wpj2
```

The checked-in `src/game/generated_en/` tree lets release builds skip ROM-based
regeneration. `scripts/ips_to_bps.py` can produce a BPS for independent
verification. Never mix JP and EN generated trees or config directories.

## Release packaging

Release principles and layout: [14-release-plan.md](14-release-plan.md). The
user-facing executable (AppImage or `WPJ2-Recompiled.exe`) is the launcher; game
binaries live in `bin/`. No ROM is ever bundled.

### Combined Linux archive

```bash
./scripts/release/build-release.sh
```

Produces `dist/wpj2-recomp-linux-<VERSION>.tar.zst` with both games, the
launcher, patch, docs, and `RELEASE.json`.

### Linux AppImage

Full guide: [16-linux-appimage.md](16-linux-appimage.md).

```bash
./scripts/release/build-appimage.sh --variant full
```

Output: `dist/WPJ2-Recomp-full-<arch>.AppImage`. The script downloads a
SHA256-verified `appimagetool` 1.9.1 if needed, bundles runtime libraries, and
refuses to package any ROM. To inspect without launching:

```bash
./dist/WPJ2-Recomp-full-x86_64.AppImage --appimage-extract
```

Single-language AppImages are available with `--variant jp` / `--variant en`.
AppImage builds inherit the build host's glibc baseline.

### Windows

Full guide: [15-windows-release.md](15-windows-release.md). The workflow
`.github/workflows/windows.yml` is **manual only** (`workflow_dispatch`) and the
supplied version must equal the checked-in `VERSION` file; pushes and pull
requests never trigger a build. It produces
`wpj2-windows-x64-<version>.zip` containing `WPJ2-Recompiled.exe`, `bin/`, the
patch, docs and required DLLs. Native MSVC is the supported path; the
`scripts/release/build-windows.sh` MinGW helper is experimental.

### Icons and font

Release artwork and generated assets:

- `resources/icons/wpj2-source.png` — source icon; regenerate PNG/ICO variants
  with `python3 scripts/generate_icons.py`.
- `resources/fonts/Roboto.ttf` (SIL OFL 1.1) — embedded in the launcher via
  `scripts/generate_launcher_font.py`; no runtime font library is needed.

## Tests

```bash
# IPS/BPS tooling (provide a JP ROM path via WPJ2_JP_ROM if not in input/)
WPJ2_JP_ROM=/path/to/wpj2.j1.z64 python3 scripts/test_patch_tools.py

# Launcher compile + CLI smoke test
bash src/launcher/test.sh
```

Both are GUI-free. The full patch test compares the rebuilt image with an
independently Flips-produced canonical English ROM when it is available at
`../wpj2-work/reference/english.z64` (overridable with `WPJ2_EN_ROM`).

## Build troubleshooting

- **`recomp.h` not found while building PCH** — check `include_directories`
  in `CMakeLists.txt`; the PCH references `recomp.h` from N64ModernRuntime and
  local `shims.h`.
- **`macros.h` redefines `PTR(x)`** — do not reintroduce `#define PTR(x) x*`;
  `ultramodern/ultra64.h` defines `PTR` as `int32_t` in recomp mode.
- **Slow cold builds** — verify configure logged a ccache path; install ccache
  if missing.
- **`rdram not declared`** — a header redefined `PTR`/`RDRAM_ARG`; only
  `ultramodern/ultra64.h` may define them.
- **Windows configure cannot find SDL2** — use the MSVC/vcpkg workflow; local
  MinGW cannot link RT64's bundled MSVC `.lib` files.
- **AppImage will not start** — install FUSE or try
  `--appimage-extract-and-run`.

## Further technical docs

- [01 — Technical profile](01-technical-profile.md)
- [02 — Methodology](02-methodology.md)
- [03 — Toolchain](03-toolchain.md)
- [04 — Execution plan](04-execution-plan.md)
- [05 — Save system](05-save-system.md)
- [06 — Risks](06-risks.md)
- [07 — Game specifics](07-wpj2-specifics.md)
- [08 — AI workflow](08-ia-workflow.md)
- [09 — Validation](09-validation.md)
- [10 — Resources](10-resources.md)
- [11 — Glossary](11-glossary.md)
- [12 — Build performance](12-build-performance.md)
- [13 — English translation](13-english-patch.md)
- [14 — Release plan](14-release-plan.md)
- [15 — Windows release](15-windows-release.md)
- [16 — Linux AppImage](16-linux-appimage.md)
- [17 — Launcher](17-launcher.md)
