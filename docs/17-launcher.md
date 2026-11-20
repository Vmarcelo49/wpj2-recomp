# 17 — Startup Launcher and Language Selection

## Research: how other N64 recomps do it

`Zelda64Recomp` keeps its launcher **inside the game process**. Its RmlUi
launcher validates the user-provided ROM with `recomp::select_rom()`, shows
"Select ROM / Play / Controls / Settings / Mods", and calls
`recomp::start_game(game_id)` when the user presses Play
([`src/ui/ui_launcher.cpp`](https://github.com/Zelda64Recomp/Zelda64Recomp/blob/dev/src/ui/ui_launcher.cpp),
local research copy: `wpj2-work/z64recomp-research/src/ui/ui_launcher.cpp`).
The main program registers one `recomp::GameEntry`, loads JSON settings, and
calls `recomp::start()`
([`src/main/main.cpp`](https://github.com/Zelda64Recomp/Zelda64Recomp/blob/dev/src/main/main.cpp),
[`src/game/config.cpp`](https://github.com/Zelda64Recomp/Zelda64Recomp/blob/dev/src/game/config.cpp)).
That works because one CPU binary serves one supported ROM.

The shared [recomp-ui](https://github.com/RetroPortingToolKit/recomp-ui)
project generalizes this pattern: a console-agnostic Dear ImGui launcher sends
a `SystemProfile` plus host-provided facts through a small C ABI, and hosts
retain ROM checks and direct-boot setup. It also standardizes CLI switches
`--launcher`, `--no-launcher`, and `--skip-launcher`
([recomp-ui README](https://github.com/RetroPortingToolKit/recomp-ui#readme),
[architecture](https://github.com/RetroPortingToolKit/recomp-ui/blob/main/docs/ARCHITECTURE.md)).
Local copies are under `wpj2-work/recomp-ui-research/`.

## Why WPJ2 needs a different shape

WPJ2 has two mutually incompatible native binaries:

- **JP**: recompiled from the original Japanese ELF/ROM.
- **EN**: recompiled from the canonical translated ROM; 175 executable words
  change across 34 functions ([doc 13](13-english-patch.md)).

A single-process launcher that merely calls `recomp::start_game()` cannot swap
the CPU code. A runtime IPS patch cannot fix this either, because execution
comes from generated C. Therefore the launcher is a **small separate process**
that selects a variant, validates/prepares its ROM, and `exec`s the matching
game binary with an explicit environment.

## Implemented minimal launcher

Sources live in `src/launcher/` and depend only on SDL2 plus the C++ standard
library. There is no Dear ImGui, RmlUi, or scripting dependency. The launcher
is intended for **manually built, VERSION-gated releases**: it never builds the
game, never publishes artifacts, and never runs in CI. The release version is
the checked-in `VERSION` file (currently `0.1.0-rc1`); manual release scripts
must gate on that value before packaging the launcher and both game binaries.

| File | Purpose |
|---|---|
| `launcher_core.hpp/.cpp` | config, ROM verification, IPS application, launch plan, process launch |
| `main.cpp` | SDL2 menu and CLI front end |
| `build.sh` | standalone build script (no CMake changes required) |
| `test.sh` | compile + CLI smoke test |

Build directly:

```bash
cd /home/marcelo/Agent/wpj2-recomp
./src/launcher/build.sh ./build/wpj2-launcher
```

The SDL UI uses Roboto Regular, licensed under SIL OFL 1.1. The TTF and its
license are kept in `resources/fonts/`; `scripts/generate_launcher_font.py`
bakes antialiased printable ASCII into `src/launcher/embedded_font.hpp`, which
is rendered through an SDL texture with linear filtering. The launcher does
not need a runtime font library.

On startup the launcher searches the folder containing the running executable
(and, for AppImages, the folder containing the AppImage) for a valid Japanese
or English ROM. If none is found, it shows only the ROM prompt and a "Check
for Rom" button. Clicking the button or pressing Enter repeats the search.

When a ROM is found, the SDL UI has one keyboard-driven screen:

- Up/Down: select a row.
- Left/Right: change language, fullscreen, integer scaling, volume, or graphics API.
- Enter: validate ROM and launch the matching executable.
- S: save the INI config.
- Esc: quit.

A no-GUI path is available for scripts and testing:

```bash
./build/wpj2-launcher --no-gui --dry-run --variant en \
  --jp-rom /path/to/wpj2.j1.z64 \
  --en-rom ./input/wpj2.en.z64 \
  --game-en ./build-en/wpj2
```

Use `--help` for all options. `--no-launcher` semantics from recomp-ui can be
approximated by saving `skip_launcher=1` in the host wrapper; the current game
binary does not read that setting yet.

## Configuration

Default config: `~/.config/wpj2-recomp/launcher.ini` (override with `--config`).
It is a small INI file with these keys:

```ini
variant=en
jp_rom=input/wpj2.j1.z64
en_rom=input/wpj2.en.z64
ips_patch=patches/Wpj2e_v1_z64.ips
game_jp=bin/wpj2-jp
game_en=bin/wpj2-en
config_dir=
fullscreen=0
integer_scaling=1
audio_volume=100
skip_launcher=0
```

The values above are development defaults. A manual release writes absolute
paths for `bin/wpj2-jp`, `bin/wpj2-en`, the bundled IPS, and the user's chosen
ROM locations. The launcher also recognizes the release executable names
`bin/wpj2-jp`, `bin/wpj2-en`, `wpj2-jp`, and `wpj2-en` relative to the current
directory when the configured path is absent.

Each variant gets its own runtime config directory:
`<config_dir>/jp` or `<config_dir>/en`. This prevents mixing saves and cached
ROMs between Japanese and English builds.

Release packaging remains a manual, VERSION-gated step: build the two binaries
and launcher from the same source revision, verify the patch/hashes, then
assemble the archive. The launcher itself does not trigger builds or uploads.

## Environment contract passed to the game

| Variable | Meaning |
|---|---|
| `WPJ2_LAUNCHER=1` | Marks a launcher-initiated session |
| `WPJ2_VARIANT=jp|en` | Selected translation variant |
| `WPJ2_ROM` | Absolute path to the verified ROM for that variant |
| `WPJ2_CONFIG_DIR` | Per-variant runtime config/save directory |
| `WPJ2_FULLSCREEN=0|1` | Requested window mode |
| `WPJ2_INTEGER_SCALING=0|1` | Requested scaling mode |
| `WPJ2_AUDIO_VOLUME=0..100` | Requested volume |

`WPJ2_ROM` and `WPJ2_CONFIG_DIR` are already honored by `src/main.cpp`.
The other five are emitted by the launcher but require the game-side
integration listed below. Unlike recomp-ui's in-process `recomp::start_game()`,
this is an explicit process boundary, so settings must travel through the
environment or a shared config file.

## Translation patch handling

The launcher does **not** trust a stale `input/wpj2.en.z64`:

1. Verify the Japanese ROM size and CIC6102 checksum
   (`e43c9765 05b1c1be`).
2. Verify the English ROM size and CIC6102 checksum
   (`4f1e88f7 4a5a3f96`).
3. If the English ROM is missing/invalid, applying the IPS is automatic when
   English is launched. The tracked IPS uses the correct RLE order: `count` is
   two-byte big-endian field, `value` is the following byte.
4. Reject patches whose output is not exactly 8,912,896 bytes, and re-verify
   the generated image before launching.

In CLI testing, the generated ROM was byte-identical to the independent
Flips-produced canonical image (XXH3-64 `0xEDF6BD1A8E68B1DC`). The game binary
still performs its own XXH3 hash check through librecomp.

## Integration requirements (not implemented here)

I did not edit `CMakeLists.txt` or `src/main.cpp`, as requested.

1. **CMake**: add `add_executable(wpj2-launcher src/launcher/main.cpp
   src/launcher/launcher_core.cpp)`, link SDL2, and install it beside both game
   binaries. `build.sh` is the standalone equivalent. Keep this target out of
   automatic CI; include it only in manually gated release builds.
2. **Game settings**: teach `src/main.cpp` to read `WPJ2_FULLSCREEN`,
   `WPJ2_INTEGER_SCALING`, and `WPJ2_AUDIO_VOLUME`. `WPJ2_VARIANT` can be used
   for diagnostics and to refuse a mismatched executable early.
3. **Packaging**: ship both `wpj2.jp` and `wpj2.en` (or `build/wpj2` and
   `build-en/wpj2`) plus `patches/Wpj2e_v1_z64.ips` when the English build is
   included.
4. **ROM discovery**: the default paths assume the launcher runs from the repo
   root. Installers should write absolute paths into `launcher.ini`.
5. **Optional**: adopt recomp-ui-style `--no-launcher` / `--skip-launcher`
   switches in the game binary if a single executable is later desired.

## Verification status

No GUI was used. The launcher was compiled with `-Wall -Wextra -Wpedantic` and
exercised through `--no-gui --dry-run`:

- JP variant produced the expected `WPJ2_VARIANT=jp`, JP ROM path, per-variant
  config directory, and Japanese executable.
- EN variant generated the canonical English ROM from the tracked IPS, verified
  its CIC checksum, and produced the EN launch plan.
- The generated ROM matched `wpj2-work/reference/english.z64` byte-for-byte.
