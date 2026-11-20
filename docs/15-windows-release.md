# 15 — Windows Release Build

## Supported path: native MSVC via GitHub Actions

The maintained Windows build uses native MSVC on `windows-2022` with SDL2 from
RT64's bundled Windows dependency. The workflow is
`.github/workflows/windows.yml`. It runs **only** through `workflow_dispatch`,
and the requested version must match the checked-in `VERSION` file; pushes and
pull requests never trigger it. It:

1. checks out all submodules recursively;
2. builds the JP variant and launcher from tracked JP generated code;
3. builds the EN variant from tracked `src/game/generated_en`;
4. stages both binaries, the launcher, the translation patch, DLLs and docs;
5. uploads one `wpj2-windows-x64-<version>.zip` Actions artifact.

Release bundles do not include a ROM. Users place their own legally obtained
Japanese ROM beside `WPJ2-Recompiled.exe`. When no ROM is present, the launcher
shows "Rom not detected, please place the rom on the same folder as the
executable" with a "Check for Rom" button.

## Portability status

The root CMake file now selects the generator from the command line, skips
ccache/Linux linker logic on Windows, guards GNU-only options, uses RT64's
bundled MSVC SDL2 on Windows, detects an already-applied VI patch, and can use
`patch` when no submodule `.git` directory is present. `.gitattributes`
preserves patch bytes on all platforms. Native MSVC remains the supported
release path; no automatic CI build is configured.

## Local MinGW helper

`scripts/release/build-windows.sh` and `scripts/release/mingw-toolchain.cmake`
are provided as an experimental starting point only. CMake configuration now
succeeds with the local MinGW toolchain, but compilation stops inside RT64's
Plume backend because that submodule expects the correctly cased `Windows.h`
from MSVC headers. Local MinGW support is therefore **not claimed or verified**.
Native MSVC is the supported Windows release path.
