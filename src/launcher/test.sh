#!/usr/bin/env bash
# GUI-free smoke tests for the standalone launcher.
set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd -- "${SCRIPT_DIR}/../.." && pwd)"
TMP="$(mktemp -d)"
trap 'rm -rf "${TMP}"' EXIT

JP_ROM="${WPJ2_JP_ROM:-/mnt/disco2/Roms/N64/Wonder Project J2 - Koruro no Mori no Jozet (Japan).z64}"
LAUNCHER="${TMP}/wpj2-launcher"

"${SCRIPT_DIR}/build.sh" "${LAUNCHER}" >/dev/null

if [[ ! -f "${JP_ROM}" ]]; then
    echo "JP ROM not found at ${JP_ROM}; skipping ROM-dependent checks" >&2
    "${LAUNCHER}" --help >/dev/null
    echo "launcher tests OK (help only)"
    exit 0
fi

touch "${TMP}/wpj2.jp" "${TMP}/wpj2.en"
chmod +x "${TMP}/wpj2.jp" "${TMP}/wpj2.en"

JP_PLAN="$("${LAUNCHER}" --no-gui --dry-run --variant jp \
    --jp-rom "${JP_ROM}" --game-jp "${TMP}/wpj2.jp" --config "${TMP}/launcher.ini")"
grep -q '^WPJ2_VARIANT=jp$' <<<"${JP_PLAN}"
grep -q '^WPJ2_CONFIG_DIR=.*/jp$' <<<"${JP_PLAN}"

EN_PLAN="$("${LAUNCHER}" --no-gui --dry-run --variant en \
    --jp-rom "${JP_ROM}" --en-rom "${TMP}/english.z64" \
    --ips "${REPO_ROOT}/patches/Wpj2e_v1_z64.ips" \
    --game-en "${TMP}/wpj2.en" --config "${TMP}/launcher.ini")"
grep -q '^WPJ2_VARIANT=en$' <<<"${EN_PLAN}"
grep -q '^WPJ2_CONFIG_DIR=.*/en$' <<<"${EN_PLAN}"

if command -v xxhsum >/dev/null 2>&1; then
    EN_HASH="$(xxhsum -H3 "${TMP}/english.z64" | awk '{print $1}')"
    [[ "${EN_HASH}" == "XXH3_edf6bd1a8e68b1dc" ]]
fi

cat > "${TMP}/release.ini" <<EOF
variant=jp
jp_rom=${JP_ROM}
en_rom=${TMP}/english.z64
ips_patch=${REPO_ROOT}/patches/Wpj2e_v1_z64.ips
game_jp=missing/wpj2-jp
game_en=missing/wpj2-en
audio_volume=80
EOF
mkdir -p "${TMP}/bin"
touch "${TMP}/bin/wpj2-jp"
chmod +x "${TMP}/bin/wpj2-jp"
CONFIG_PLAN="$(cd "${TMP}" && "${LAUNCHER}" --no-gui --dry-run --config "${TMP}/release.ini")"
grep -q '^WPJ2_AUDIO_VOLUME=80$' <<<"${CONFIG_PLAN}"
grep -q "^exec=${TMP}/bin/wpj2-jp$" <<<"${CONFIG_PLAN}"

# English auto-patch: only the Japanese ROM is present.
rm -f "${TMP}/english.z64"
AUTO_DIR="${TMP}/auto"
mkdir -p "${AUTO_DIR}"
cp "${JP_ROM}" "${AUTO_DIR}/wpj2.j1.z64"
touch "${AUTO_DIR}/wpj2-en"
chmod +x "${AUTO_DIR}/wpj2-en"
AUTO_PLAN="$(cd "${AUTO_DIR}" && "${LAUNCHER}" --no-gui --dry-run \
    --variant en --config "${AUTO_DIR}/launcher.ini" \
    --jp-rom "${AUTO_DIR}/wpj2.j1.z64" \
    --en-rom "${AUTO_DIR}/wpj2.en.z64" \
    --ips "${REPO_ROOT}/patches/Wpj2e_v1_z64.ips" \
    --game-en "${AUTO_DIR}/wpj2-en")"
grep -q '^WPJ2_VARIANT=en$' <<<"${AUTO_PLAN}"
grep -q "^WPJ2_ROM=${AUTO_DIR}/wpj2.en.z64$" <<<"${AUTO_PLAN}"
if command -v xxhsum >/dev/null 2>&1; then
    AUTO_HASH="$(xxhsum -H3 "${AUTO_DIR}/wpj2.en.z64" | awk '{print $1}')"
    [[ "${AUTO_HASH}" == "XXH3_edf6bd1a8e68b1dc" ]]
fi

echo "launcher tests OK"
