#!/usr/bin/env bash
# Local Windows cross-build helper (best effort; native MSVC CI is supported path).
# Requires a CMake that selects a Windows toolchain. The cross compiler must be
# able to consume the Windows dependencies shipped in RT64's submodule.
set -euo pipefail

REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
BUILD_DIR="${BUILD_DIR:-$REPO/build-windows}"
TOOLCHAIN_FILE="${TOOLCHAIN_FILE:-$REPO/scripts/release/mingw-toolchain.cmake}"
GENERATOR="${GENERATOR:-Ninja}"

if [[ ! -f "$TOOLCHAIN_FILE" ]]; then
    echo "Toolchain file not found: $TOOLCHAIN_FILE" >&2
    echo "Pass TOOLCHAIN_FILE=/path/to/windows-toolchain.cmake" >&2
    exit 1
fi

if ! command -v cmake >/dev/null; then
    echo "cmake not found" >&2
    exit 1
fi

cmake -S "$REPO" -B "$BUILD_DIR" -G "$GENERATOR" \
    -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" \
    -DCMAKE_BUILD_TYPE=Release \
    -DWPJ2_PCH=OFF \
    "$@"
cmake --build "$BUILD_DIR" --config Release --target wpj2 --parallel

echo "Windows build output: $BUILD_DIR/wpj2.exe"
echo "Note: native MSVC + vcpkg is the supported release path; see docs/15-windows-release.md"
