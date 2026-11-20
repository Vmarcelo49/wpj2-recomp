# 16 — Linux AppImage release

This document describes the AppImage packaging script at
[`scripts/release/build-appimage.sh`](../scripts/release/build-appimage.sh).

The release AppImage uses `--variant full` and contains the Japanese game,
English game, startup launcher, desktop entry, icons, documentation and the
English translation IPS patch. **It never contains a ROM.** Users place their own legally obtained Japanese
ROM beside the AppImage. With no ROM present, the launcher shows "Rom not
detected, please place the rom on the same folder as the executable" and a
"Check for Rom" button.

## Prerequisites

- Linux on `x86_64`, `aarch64`, `armhf` or `i686`
- CMake 3.24+, Ninja and a C++20 compiler
- `curl` or `wget` if the pinned tool must be downloaded
- FUSE for running AppImages, or the tool's built-in `--appimage-extract-and-run`
  fallback, which the script selects automatically
- A Vulkan-capable GPU/driver for actually playing the game

The script downloads [appimagetool](https://github.com/AppImage/appimagetool)
`1.9.1` and verifies its SHA256 checksum. Override the cache with
`APPIMAGETOOL_CACHE`, or pass an existing tool with `--appimagetool PATH`.

## Build the release AppImage

The tracked `src/game/generated_en` tree is used by default.

```bash
./scripts/release/build-appimage.sh --variant full
```

The result is `dist/WPJ2-Recomp-full-<arch>.AppImage`. The AppImage starts the
language/settings launcher by default. Single-variant AppImages are still
available with `--variant jp` or `--variant en`.

## Run

Use the launcher to select Japanese or English. To bypass it, set
`WPJ2_LANGUAGE=jp|en` and pass the matching ROM as the first argument or with
`WPJ2_ROM`:

```bash
WPJ2_LANGUAGE=jp ./dist/WPJ2-Recomp-full-x86_64.AppImage /path/to/wpj2.j1.z64
WPJ2_LANGUAGE=en WPJ2_ROM=/path/to/wpj2.en.z64 \
  ./dist/WPJ2-Recomp-full-x86_64.AppImage
```

`AppRun` also exports:

- `WPJ2_DATA_DIR` — packaged data root
- `WPJ2_PATCH_DIR` — directory containing the translation patch
- `WPJ2_TRANSLATION_PATCH` — full path to `Wpj2e_v1_z64.ips`
- `WPJ2_CONFIG_DIR` — defaults to `$XDG_CONFIG_HOME/wpj2-recomp-appimage`

The `english.z64` image produced by the tracked IPS patch must match the
English build's ROM hash. The patch is included for verification and
reproducibility; it is not applied at runtime.

## AppDir layout

```text
AppDir/
  AppRun
  .DirIcon
  wpj2.desktop
  usr/
    bin/wpj2
    lib/                       # bundled runtime libraries
    share/
      applications/wpj2.desktop
      icons/hicolor/128x128/apps/wpj2.png
      icons/hicolor/256x256/apps/wpj2.png
      pixmaps/wpj2.png
      wpj2/
        manifest.json
        patches/Wpj2e_v1_z64.ips
      doc/wpj2/
        LICENSE
        README.md
        13-english-patch.md
```

The script refuses to produce an AppImage if any `*.z64`, `*.n64` or `*.v64`
file appears in the AppDir.

## Useful options

```text
--build-dir PATH       existing or new CMake build directory
--dist-dir PATH        output directory
--output PATH          exact AppImage output path
--skip-build           package the binary already in --build-dir
--skip-deps            do not bundle shared libraries
--keep-appdir          keep AppDir under <build-dir>/appimage for inspection
--cmake-arg ARG        extra CMake configure option, repeatable
```

Example using an optimized existing build:

```bash
./scripts/release/build-appimage.sh \
  --build-dir build-release \
  --skip-build \
  --keep-appdir
```

## Verification

```bash
file dist/WPJ2-Recomp-jp-x86_64.AppImage

# Inspect bundled files without launching the game.
./dist/WPJ2-Recomp-jp-x86_64.AppImage --appimage-extract
find squashfs-root -name Wpj2e_v1_z64.ips -o -name wpj2.desktop

# Validate the desktop file in the kept AppDir.
desktop-file-validate build-appimage/appimage/AppDir/wpj2.desktop
```

## Required CMake install rules

The script copies the binary, static library, desktop file, icons and patch
directly into the AppDir. It does not call `cmake --install` because dependency
install rules currently try to install helper executables that are not built by
the `wpj2` target. No CI workflow is added; packaging is a manual step.

For a proper `cmake --install` layout, the project should add:

```cmake
install(FILES resources/wpj2.desktop DESTINATION share/applications)
install(FILES resources/icons/hicolor/128x128/apps/wpj2.png
        DESTINATION share/icons/hicolor/128x128/apps)
install(FILES resources/icons/hicolor/256x256/apps/wpj2.png
        DESTINATION share/icons/hicolor/256x256/apps)
install(FILES patches/Wpj2e_v1_z64.ips DESTINATION share/wpj2/patches)
install(FILES LICENSE README.md docs/13-english-patch.md
        DESTINATION share/doc/wpj2)
```

The existing rules already install `wpj2` into `bin` and the static library
into `lib`.

## Limitations

- Dynamic libraries are copied from the build host. The AppImage therefore
  cannot be older than the build host's glibc baseline.
- The game still requires a Vulkan-capable display and a user-supplied ROM.
- The Japanese and English variants have different CPU code and must be
  packaged as separate AppImages.
