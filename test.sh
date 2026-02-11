#!/usr/bin/env bash
set -euo pipefail

# Kompilácia programu
gcc -Iinclude src/z2.c src/functions.c src/data.c -lm -o program

PROGRAM="./program"
IN_DIR="test_cases/stdin"
OUT_DIR="test_cases/stdout"

PASS=0
FAIL=0

for input in $(find "$IN_DIR" -type f -name "*.txt" | sort); do
    rel="${input#$IN_DIR/}"
    expected="$OUT_DIR/$rel"

    mkdir -p .tmp
    out=".tmp/output.tmp"

    "$PROGRAM" < "$input" > "$out"

    if diff -q -w -B "$out" "$expected" >/dev/null; then
        echo "✅ $rel"
        ((PASS++))
    else
        echo "❌ $rel"
        ((FAIL++))
    fi
done

rm -rf .tmp

echo ""
echo "Passed: $PASS"
echo "Failed: $FAIL"

if [[ $FAIL -ne 0 ]]; then
    exit 1
fi