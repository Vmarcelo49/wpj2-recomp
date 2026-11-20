#!/usr/bin/env bash
# Build a Linux AppImage for wpj2-recomp from an existing or fresh CMake build.
set -euo pipefail

readonly APPIMAGETOOL_VERSION="1.9.1"
readonly TOOL_RELEASE_URL="https://github.com/AppImage/appimagetool/releases/download/${APPIMAGETOOL_VERSION}"

declare -A TOOL_SHA256=(
    [x86_64]="ed4ce84f0d9caff66f50bcca6ff6f35aae54ce8135408b3fa33abfc3cb384eb0"
    [aarch64]="f0837e7448a0c1e4e650a93bb3e85802546e60654ef287576f46c71c126a9158"
    [armhf]="42b61cba5495d8aaf418a5c9a015a49b85ad92efabcbd3c341f1540440e4e23d"
    [i686]="7ad9ff47c203aae0149b18f6df9e3018b2e2f470ea644a0413e3ded39e9e3bdb"
)

die() { printf 'error: %s\n' "$*" >&2; exit 1; }
info() { printf '==> %s\n' "$*" >&2; }

usage() {
    cat <<EOF
Usage: $(basename "$0") [options]

Build an AppImage containing the wpj2 binary, desktop entry, icon and the
English translation IPS patch as a data file. No copyrighted ROM is bundled.
Use --variant full for the release package with JP, EN and the launcher.

Options:
  --variant jp|en|full     ROM/code variant to package (default: jp)
  --generated-dir PATH     EN N64Recomp output; required for --variant en
  --build-dir PATH         CMake build directory (default: <repo>/build-appimage)
  --dist-dir PATH          Output directory (default: <repo>/dist)
  --output PATH            AppImage output file
  --appimagetool PATH      Use an existing appimagetool instead of downloading
  --cmake-arg ARG          Extra argument for the CMake configure step (repeatable)
  --skip-build             Reuse the binary in --build-dir
  --skip-deps              Do not bundle shared-library dependencies
  --keep-appdir            Keep the assembled AppDir for inspection
  -h, --help               Show this help

The pinned appimagetool ${APPIMAGETOOL_VERSION} is downloaded when no tool is
supplied. Set APPIMAGETOOL_CACHE to change the download cache directory.
EOF
}

repo_root=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." && pwd)
build_dir="$repo_root/build-appimage"
dist_dir="$repo_root/dist"
variant="jp"
generated_dir=""
output=""
appimagetool="${APPIMAGETOOL:-}"
keep_appdir=0
skip_build=0
skip_deps=0
declare -a cmake_args=()

while [[ $# -gt 0 ]]; do
    case "$1" in
        --variant)        variant=${2:?--variant requires a value}; shift 2 ;;
        --generated-dir)  generated_dir=${2:?--generated-dir requires a value}; shift 2 ;;
        --build-dir)      build_dir=${2:?--build-dir requires a value}; shift 2 ;;
        --dist-dir)       dist_dir=${2:?--dist-dir requires a value}; shift 2 ;;
        --output)         output=${2:?--output requires a value}; shift 2 ;;
        --appimagetool)   appimagetool=${2:?--appimagetool requires a value}; shift 2 ;;
        --cmake-arg)      cmake_args+=("${2:?--cmake-arg requires a value}"); shift 2 ;;
        --skip-build)     skip_build=1; shift ;;
        --skip-deps)      skip_deps=1; shift ;;
        --keep-appdir)    keep_appdir=1; shift ;;
        -h|--help)        usage; exit 0 ;;
        *)                die "unknown option: $1" ;;
    esac
done

[[ "$variant" == "jp" || "$variant" == "en" || "$variant" == "full" ]] || die "unknown variant: $variant"
arch=$(uname -m)
[[ -n "${TOOL_SHA256[$arch]:-}" ]] || die "unsupported architecture for pinned appimagetool: $arch"

if [[ "$variant" == "en" || "$variant" == "full" ]]; then
    [[ -n "$generated_dir" ]] || generated_dir="$repo_root/src/game/generated_en"
    [[ -f "$generated_dir/recomp_overlays.inl" ]] || die "incomplete EN generated tree: $generated_dir"
    generated_dir=$(cd -- "$generated_dir" && pwd)
fi

build_dir=$(mkdir -p -- "$build_dir" && cd -- "$build_dir" && pwd)
dist_dir=$(mkdir -p -- "$dist_dir" && cd -- "$dist_dir" && pwd)
work_dir="$build_dir/appimage"
appdir="$work_dir/AppDir"
if [[ -z "$output" ]]; then
    output="$dist_dir/WPJ2-Recomp-${variant}-${arch}.AppImage"
fi

download_tool() {
    local cache=${APPIMAGETOOL_CACHE:-$repo_root/.cache/appimagetool}
    local target="$cache/appimagetool-${APPIMAGETOOL_VERSION}-${arch}.AppImage"
    local expected=${TOOL_SHA256[$arch]}
    local tmp="${target}.part"

    if [[ -x "$target" ]] && printf '%s  %s\n' "$expected" "$target" | sha256sum -c --status; then
        printf '%s\n' "$target"
        return
    fi

    local url="${TOOL_RELEASE_URL}/appimagetool-${arch}.AppImage"
    info "Downloading pinned appimagetool ${APPIMAGETOOL_VERSION} for ${arch}"
    mkdir -p -- "$cache"
    rm -f -- "$tmp"
    if command -v curl >/dev/null 2>&1; then
        curl -fL --retry 3 --output "$tmp" "$url" || die "failed to download $url"
    elif command -v wget >/dev/null 2>&1; then
        wget -O "$tmp" "$url" || die "failed to download $url"
    else
        die "curl or wget is required to download appimagetool; install one or pass --appimagetool PATH"
    fi

    printf '%s  %s\n' "$expected" "$tmp" | sha256sum -c --status \
        || die "appimagetool checksum mismatch; refusing to use $tmp"
    mv -f -- "$tmp" "$target"
    chmod 755 -- "$target"
    printf '%s\n' "$target"
}

TOOL_CMD=()

set_tool_command() {
    local tool=$1
    if "$tool" --version >/dev/null 2>&1; then
        TOOL_CMD=("$tool")
        return
    fi
    if "$tool" --appimage-extract-and-run --version >/dev/null 2>&1; then
        TOOL_CMD=("$tool" --appimage-extract-and-run)
        return
    fi
    die "cannot execute appimagetool at $tool; install FUSE or provide a working tool with --appimagetool PATH"
}

bundle_dependencies() {
    local libdir="$appdir/usr/lib"
    mkdir -p -- "$libdir"

    declare -A seen=()
    local queue=()
    while IFS= read -r binary; do
        queue+=("$binary")
    done < <(find "$appdir/usr/bin" -maxdepth 1 -type f)
    while [[ ${#queue[@]} -gt 0 ]]; do
        local file=${queue[0]}
        queue=("${queue[@]:1}")
        [[ -f "$file" ]] || continue

        local line lib path name
        while IFS= read -r line; do
            path=""
            if [[ "$line" == *" => "* ]]; then
                path=${line#* => }
                path=${path%% \(*}
            elif [[ "$line" == /* ]]; then
                path=${line%% \(*}
            fi
            [[ -n "$path" && -f "$path" ]] || continue

            name=$(basename -- "$path")
            case "$name" in
                linux-vdso.so.1|libc.so.6|ld-linux*.so.*|ld-musl-*|libpthread.so.0|libdl.so.2|librt.so.1)
                    continue ;;
            esac
            [[ -n "${seen[$name]:-}" ]] && continue
            seen[$name]=1

            cp -L -- "$path" "$libdir/$name"
            queue+=("$libdir/$name")
        done < <(ldd "$file" 2>/dev/null || true)
    done
    info "Bundled ${#seen[@]} shared libraries"
}

contains_rom() {
    find "$appdir" -type f \( -iname '*.z64' -o -iname '*.n64' -o -iname '*.v64' \) -print -quit | grep -q .
}

info "Repository: $repo_root"
info "Build directory: $build_dir"
info "Variant: $variant"

if (( ! skip_build )); then
    info "Configuring and building JP variant"
    cmake -S "$repo_root" -B "$build_dir/jp" -G Ninja "${cmake_args[@]}"
    cmake --build "$build_dir/jp" --target wpj2 wpj2-launcher -j"$(nproc)"

    if [[ "$variant" != "jp" ]]; then
        info "Configuring and building EN variant"
        cmake -S "$repo_root" -B "$build_dir/en" -G Ninja \
            -DWPJ2_ENGLISH_BUILD=ON -DWPJ2_GENERATED_DIR="$generated_dir" "${cmake_args[@]}"
        cmake --build "$build_dir/en" --target wpj2 -j"$(nproc)"
    fi
fi

jp_binary="$build_dir/jp/wpj2-jp"
en_binary="$build_dir/en/wpj2-en"
launcher_binary="$build_dir/jp/wpj2-launcher"
[[ -x "$jp_binary" ]] || die "missing built binary: $jp_binary"
if [[ "$variant" != "jp" ]]; then
    [[ -x "$en_binary" ]] || die "missing built binary: $en_binary"
    [[ -x "$launcher_binary" ]] || die "missing built launcher: $launcher_binary"
fi
built_binary="$jp_binary"

rm -rf -- "$work_dir"
mkdir -p -- \
    "$appdir/usr/bin" \
    "$appdir/usr/lib" \
    "$appdir/usr/share/applications" \
    "$appdir/usr/share/icons/hicolor/128x128/apps" \
    "$appdir/usr/share/icons/hicolor/256x256/apps" \
    "$appdir/usr/share/pixmaps" \
    "$appdir/usr/share/wpj2/patches" \
    "$appdir/usr/share/doc/wpj2"

info "Installing project files into AppDir"
# Use explicit copies instead of `cmake --install`: the dependency install rules
# install helper executables that are not part of the wpj2 target.
install -m 755 -- "$built_binary" "$appdir/usr/bin/wpj2-jp"
if [[ "$variant" != "jp" ]]; then
    install -m 755 -- "$en_binary" "$appdir/usr/bin/wpj2-en"
    install -m 755 -- "$launcher_binary" "$appdir/usr/bin/wpj2-launcher"
fi
if [[ -f "$build_dir/jp/libwpj2_recompiled.a" ]]; then
    install -m 644 -- "$build_dir/jp/libwpj2_recompiled.a" "$appdir/usr/lib/libwpj2_recompiled.a"
fi

install -m 755 -- "$repo_root/resources/AppRun" "$appdir/AppRun"
install -m 644 -- "$repo_root/resources/wpj2.desktop" "$appdir/wpj2.desktop"
install -m 644 -- "$repo_root/resources/wpj2.desktop" "$appdir/usr/share/applications/wpj2.desktop"
install -m 644 -- "$repo_root/resources/icons/hicolor/128x128/apps/wpj2.png" \
    "$appdir/usr/share/icons/hicolor/128x128/apps/wpj2.png"
install -m 644 -- "$repo_root/resources/icons/hicolor/256x256/apps/wpj2.png" \
    "$appdir/usr/share/icons/hicolor/256x256/apps/wpj2.png"
install -m 644 -- "$repo_root/resources/icons/hicolor/256x256/apps/wpj2.png" "$appdir/usr/share/pixmaps/wpj2.png"
install -m 644 -- "$repo_root/resources/icons/hicolor/256x256/apps/wpj2.png" "$appdir/.DirIcon"
install -m 644 -- "$repo_root/resources/icons/hicolor/256x256/apps/wpj2.png" "$appdir/wpj2.png"

install -m 644 -- "$repo_root/patches/Wpj2e_v1_z64.ips" \
    "$appdir/usr/share/wpj2/patches/Wpj2e_v1_z64.ips"
install -m 644 -- "$repo_root/LICENSE" "$repo_root/README.md" \
    "$repo_root/docs/13-english-patch.md" \
    "$repo_root/resources/fonts/Roboto-OFL.txt" "$appdir/usr/share/doc/wpj2/"

if command -v desktop-file-validate >/dev/null 2>&1; then
    desktop-file-validate "$appdir/usr/share/applications/wpj2.desktop"
fi

if (( ! skip_deps )); then
    info "Bundling runtime libraries"
    bundle_dependencies
else
    info "Skipping runtime library bundling (--skip-deps)"
fi

if contains_rom; then
    die "a ROM was found in the AppDir; AppImages must not bundle copyrighted game data"
fi

{
    printf '{\n'
    printf '  "variant": "%s",\n' "$variant"
    printf '  "version": "%s",\n' "$(tr -d '[:space:]' < "$repo_root/VERSION")"
    printf '  "appimage_tool_version": "%s",\n' "$APPIMAGETOOL_VERSION"
    printf '  "built_utc": "%s",\n' "$(date -u +%Y-%m-%dT%H:%M:%SZ)"
    printf '  "translation_patch": {\n'
    printf '    "path": "usr/share/wpj2/patches/Wpj2e_v1_z64.ips",\n'
    printf '    "sha256": "%s"\n' "$(sha256sum "$appdir/usr/share/wpj2/patches/Wpj2e_v1_z64.ips" | cut -d' ' -f1)"
    printf '  }\n'
    printf '}\n'
} > "$appdir/usr/share/wpj2/manifest.json"

mkdir -p -- "$(dirname -- "$output")"
if [[ -z "$appimagetool" ]]; then
    appimagetool=$(download_tool)
fi
[[ -x "$appimagetool" ]] || die "appimagetool is not executable: $appimagetool"
set_tool_command "$appimagetool"

info "Creating AppImage: $output"
ARCH="$arch" "${TOOL_CMD[@]}" "$appdir" "$output"

if (( ! keep_appdir )); then
    rm -rf -- "$work_dir"
fi

info "Done: $output"
