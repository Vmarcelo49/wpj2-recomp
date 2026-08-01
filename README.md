# Wonder Project J2 — PC Recompilation

> Native PC port of *Wonder Project J2* (ワープロジェクトJ2), Enix/Givro, 1996, N64.
> Built using the N64Recomp methodology with RT64 hardware-accelerated renderer.

## Status

**Phase 6 complete** — The game boots, plays audio, renders graphics via RT64 (Vulkan),
and runs stably for 60+ seconds on real hardware (AMD RX 9070 XT, Wayland).

### What works
- ✅ Full boot sequence (IPL3 → entrypoint → main game loop)
- ✅ 8547 recompiled MIPS functions (N64Recomp)
- ✅ RSP audio microcode (aspMain) via RSPRecomp with 904 indirect branch targets
- ✅ RT64 Vulkan renderer with HLE GBI display list interpretation
- ✅ SDL2 audio (queue-based, auto-frequency switching)
- ✅ SDL2 input (keyboard + gamepad, hot-plug)
- ✅ Wayland + X11 display support
- ✅ 60 FPS stable, no crashes

### What doesn't work yet
- Controller Pak (MPK) saves — stubs return PFS_ERR_NOPACK
- Modern features (high-res, fullscreen toggle, fast-forward) — Phase 7
- Distribution packaging (AppImage, Windows .exe) — Phase 8

## Quick Start

### Prerequisites

- **Linux** (tested on Ubuntu 24.04 and Arch Linux)
- **Vulkan-capable GPU** with drivers (Intel, AMD, or NVIDIA)
- **CMake 3.24+**, **Ninja**, **gcc 13+** or **clang 16+**
- **SDL2** development libraries
- **ccache** (recommended for faster rebuilds)
- **mold** linker (recommended)
- **Python 3** with `xxhash` package (for ROM hash verification)
- **ROM** of Wonder Project J2 (Japanese, `.z64` format, MD5: `0ff1f8628d8fe69582db54572d2bea79`)

### Build

```bash
# Clone with submodules
git clone --recursive https://github.com/Vmarcelo49/wpj2-recomp.git
cd wpj2-recomp

# Build N64Recomp + RSPRecomp tools (one-time)
cmake -B build_tools -S tools/N64Recomp -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build_tools --target N64RecompCLI RSPRecomp

# Generate recompiled sources from ELF (one-time, or when wpj2.j1.toml changes)
./build_tools/N64Recomp wpj2.j1.toml
./build_tools/RSPRecomp aspMain.j1.rsp.toml

# Configure and build the game
cmake -B build -G Ninja -DWPJ2_DEV=ON -DWPJ2_PCH=ON
cmake --build build --target wpj2
```

### Run

```bash
# Place your ROM (one-time — the game will copy it to ~/.config/wpj2-recomp/)
mkdir -p input
cp /path/to/your/wpj2.j1.z64 input/

# Run the game
./build/wpj2

# On Wayland sessions, SDL2 should auto-detect. If you get a Vulkan surface
# error, try forcing Wayland:
SDL_VIDEODRIVER=wayland ./build/wpj2
```

### Controls

| N64 Button | Keyboard | Gamepad |
|---|---|---|
| A | Enter / Space | A |
| B | Left Shift / Z | B / Y |
| Z | X | X / L / R |
| Start | C / Backspace | Start / Back |
| D-pad | Arrow keys / WASD | D-pad |
| Analog | — | Left stick |

## Project Structure

```
WPJ2-recomp/
├── src/
│   ├── main.cpp                      # SDL2 + recomp::start integration
│   ├── game/
│   │   ├── register_overlays.cpp     # Static-init registration of section_table
│   │   ├── manual_stubs.cpp          # Auto-generated stubs for unrecompilable funcs
│   │   └── generated/                # N64Recomp output (8547 funcs in 53 files)
│   ├── rsp/
│   │   ├── rsp_dispatch.cpp          # aspMain for M_AUDTASK, nop for M_GFXTASK
│   │   └── generated/aspMain.c       # RSPRecomp output (904 labels)
│   ├── graphics/
│   │   └── rt64_renderer.cpp         # RT64 Application integration
│   └── audio_input/
│       ├── audio.cpp                 # SDL2 audio backend
│       ├── input.cpp                 # SDL2 keyboard + gamepad
│       └── controller_pak.cpp        # CPK supplementary stubs
├── include/
│   ├── shims.h                       # _recomp function declarations
│   ├── macros.h                      # N64 type defs
│   └── generated/wpj2_pch.h          # Precompiled header
├── lib/
│   ├── N64ModernRuntime/             # ultramodern + librecomp (submodule)
│   └── RT64/                         # RT64 renderer (submodule)
├── tools/
│   └── N64Recomp/                    # N64Recomp + RSPRecomp (submodule)
├── decomp/
│   └── wonder/                       # WPJ2 decompilation (submodule, reference)
├── docs/                             # Technical documentation (12 files)
├── scripts/                          # Build automation scripts
├── wpj2.j1.toml                      # N64Recomp config (165 manual_funcs)
├── aspMain.j1.rsp.toml               # RSPRecomp config (904 indirect targets)
├── CMakeLists.txt                    # Build config (ccache, PCH, mold, RT64_STATIC)
├── WORKLOG.md                        # Development progress log
└── README.md                         # This file
```

## Build Performance

| Scenario | Time |
|---|---|
| Clean build (cold cache) | ~3 min |
| Clean build (ccache warm) | ~17s |
| Incremental (1 file) | <1s |
| Incremental (main.cpp) | ~2.5s |

Build optimizations: ccache, mold linker, precompiled headers, Ninja with `-j7`.

## Documentation

- [Technical Profile](docs/01-technical-profile.md) — ROM specs, save type, ucode
- [Methodology](docs/02-methodology.md) — Driver+workers, phase-gated
- [Toolchain](docs/03-toolchain.md) — N64Recomp, RT64, RSPRecomp
- [Execution Plan](docs/04-execution-plan.md) — Phases 0–8
- [Save System](docs/05-save-system.md) — Controller Pak implementation
- [Risks Register](docs/06-risks.md) — Identified risks
- [WPJ2 Specifics](docs/07-wpj2-specifics.md) — Game-specific details
- [Build Performance](docs/12-build-performance.md) — Optimization guide

## License & Legal

MIT License — see [LICENSE](LICENSE).

This project does not distribute ROMs or copyrighted assets. Users must supply
their own legally-obtained ROM of Wonder Project J2. Recompilation is a fair-use
preservation technique.

## Acknowledgments

- [N64Recomp](https://github.com/N64Recomp/N64Recomp) — recompilation toolchain
- [RT64](https://github.com/rt64/rt64) — hardware-accelerated N64 renderer
- [LLONSIT-glitch/wonder](https://github.com/LLONSIT-glitch/wonder) — WPJ2 decompilation
- [Zelda64Recomp](https://github.com/Zelda64Recomp/Zelda64Recomp) — reference implementation
