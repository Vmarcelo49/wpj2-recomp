#!/usr/bin/env bash
# Build the standalone WPJ2 launcher without modifying the project CMake files.
set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd -- "${SCRIPT_DIR}/../.." && pwd)"
OUTPUT="${1:-${REPO_ROOT}/build/wpj2-launcher}"

if ! command -v pkg-config >/dev/null 2>&1; then
    echo "pkg-config is required" >&2
    exit 1
fi
if ! pkg-config --exists sdl2; then
    echo "SDL2 development files are required" >&2
    exit 1
fi

mkdir -p -- "$(dirname -- "${OUTPUT}")"
# shellcheck disable=SC2046
g++ -std=c++20 -O2 -Wall -Wextra -Wpedantic \
    $(pkg-config --cflags sdl2) \
    "${SCRIPT_DIR}/main.cpp" "${SCRIPT_DIR}/launcher_core.cpp" \
    -o "${OUTPUT}" \
    $(pkg-config --libs sdl2)

echo "Built ${OUTPUT}"
