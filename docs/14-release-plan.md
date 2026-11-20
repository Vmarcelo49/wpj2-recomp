# 14 — Release Plan

This document defines the supported release artifacts and their layout.

## Principles

- No copyrighted ROM is distributed. Users place their own Japanese `.z64` beside the executable; the launcher
searches that folder and shows a ROM prompt when none is found.
- The community translation patch is distributed as data.
- The English build requires CPU code regenerated from the translated ROM.
  It is a separate executable, not a runtime data swap.
- A launcher selects the language and starts the matching executable.

## Installed layout

A release install prefix contains:

```
wpj2-recomp / WPJ2-Recompiled.exe    user-facing launcher (archive root)
bin/wpj2-jp                         Japanese game
bin/wpj2-en                         English game
share/wpj2-recomp/
  patches/Wpj2e_v1_z64.ips          bundled translation patch
  docs/                             project documentation
  LICENSE
  README.md
share/applications/wpj2.desktop
share/icons/hicolor/128x128/apps/wpj2.png
share/icons/hicolor/256x256/apps/wpj2.png
```

The release icon comes from `resources/icons/wpj2-source.png`. Regenerate all
PNG and Windows ICO variants with `python3 scripts/generate_icons.py`.

Windows archives use the same logical structure under the archive root.

## Build matrix

| Artifact | Language | Generated CPU source | ROM expected by game |
|---|---|---|---|
| `wpj2-jp` | Japanese | tracked `src/game/generated` | original JP ROM |
| `wpj2-en` | English | `scripts/generate_en_cpu.py` output | canonical EN ROM |

Both binaries must be built from the same source revision. The launcher and
release scripts must verify that the bundled patch produces the canonical EN
hash `0xEDF6BD1A8E68B1DC` before starting the English binary.

## Linux

The Linux release is an AppImage containing both game binaries, the launcher,
the translation patch, desktop metadata, and documentation. See
[16-linux-appimage.md](16-linux-appimage.md).

## Windows

The Windows release is a ZIP containing the same logical layout. See
[15-windows-release.md](15-windows-release.md).

## Launcher

The startup menu chooses Japanese or English and writes settings to the
per-user config directory. It then launches the matching binary with an
explicit ROM and config directory. See [17-launcher.md](17-launcher.md).
