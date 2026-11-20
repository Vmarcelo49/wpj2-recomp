#!/usr/bin/env bash
# Build both language variants plus the launcher into one release directory.
# This script is manual-only and does not contact CI.
set -euo pipefail

repo_root=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." && pwd)
version=$(tr -d '[:space:]' < "$repo_root/VERSION")
[[ -n "$version" ]] || { echo 'error: VERSION is empty' >&2; exit 1; }

build_root="${BUILD_ROOT:-$repo_root/build-release}"
dist_dir="${DIST_DIR:-$repo_root/dist}"
jp_build="$build_root/jp"
en_build="$build_root/en"
stage="$build_root/stage"
generated_en="${WPJ2_GENERATED_EN:-$repo_root/src/game/generated_en}"

[[ -f "$generated_en/recomp_overlays.inl" ]] || {
    echo "error: missing tracked EN generated sources: $generated_en" >&2
    exit 1
}

rm -rf -- "$stage"
mkdir -p -- "$stage/bin" "$stage/share/wpj2-recomp/patches" "$stage/share/wpj2-recomp/docs"

cmake -S "$repo_root" -B "$jp_build" -G Ninja \
    -DCMAKE_BUILD_TYPE=Release -DWPJ2_PCH=ON
cmake --build "$jp_build" --target wpj2 wpj2-launcher --parallel

cmake -S "$repo_root" -B "$en_build" -G Ninja \
    -DCMAKE_BUILD_TYPE=Release -DWPJ2_PCH=ON \
    -DWPJ2_ENGLISH_BUILD=ON -DWPJ2_GENERATED_DIR="$generated_en"
cmake --build "$en_build" --target wpj2 --parallel

install -m 755 -- "$jp_build/wpj2-jp" "$stage/bin/wpj2-jp"
install -m 755 -- "$jp_build/wpj2-launcher" "$stage/wpj2-recomp"
install -m 755 -- "$en_build/wpj2-en" "$stage/bin/wpj2-en"

install -m 644 -- "$repo_root/patches/Wpj2e_v1_z64.ips" \
    "$stage/share/wpj2-recomp/patches/Wpj2e_v1_z64.ips"
install -m 644 -- "$repo_root/LICENSE" "$repo_root/README.md" "$repo_root/VERSION" \
    "$repo_root/resources/fonts/Roboto-OFL.txt" "$stage/share/wpj2-recomp/"
cp -R -- "$repo_root/docs/." "$stage/share/wpj2-recomp/docs/"

cat > "$stage/RELEASE.json" <<EOF
{
  "version": "$version",
  "variants": ["jp", "en"],
  "translation_patch": "share/wpj2-recomp/patches/Wpj2e_v1_z64.ips"
}
EOF

mkdir -p -- "$dist_dir"
archive="$dist_dir/wpj2-recomp-linux-${version}.tar.zst"
tar --zstd -C "$stage" -cf "$archive" .
echo "Release directory: $stage"
echo "Archive: $archive"
