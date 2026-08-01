#!/bin/bash
# Run wpj2 under GDB to get a backtrace of the segfault.
# Usage: ./run_gdb.sh
#
# Make sure the ROM is in place before running:
#   ~/.config/wpj2-recomp/wpj2_jp.z64  (or input/wpj2.j1.z64)

cd "$(dirname "$0")/.."

echo "=== Running wpj2 under GDB ==="
echo "This will show the backtrace when it crashes."
echo ""

gdb -batch \
    -ex "set pagination off" \
    -ex "set debuginfod enabled off" \
    -ex "run" \
    -ex "bt 40" \
    -ex "info threads" \
    ./build/wpj2 \
    2>&1 | tee /tmp/wpj2_gdb.log

echo ""
echo "=== GDB output saved to /tmp/wpj2_gdb.log ==="
echo "Paste the backtrace back to me so I can fix the crash."
