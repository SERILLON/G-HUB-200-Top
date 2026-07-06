#!/bin/bash
set -euo pipefail

echo "Running clang-format checks..."
FAILED=0

FILES=$(git ls-files '*.c' '*.h' || true)
if [ -n "$FILES" ]; then
  for f in $FILES; do
    tmp=$(mktemp)
    clang-format -style=file "$f" > "$tmp" || { echo "clang-format failed on $f"; FAILED=1; rm -f "$tmp"; continue; }
    if ! diff -u "$f" "$tmp" > /dev/null; then
      echo "File needs formatting: $f"
      diff -u "$f" "$tmp" || true
      FAILED=1
    fi
    rm -f "$tmp"
  done
else
  echo "No C files found."
fi

echo "Running cppcheck..."
if ! cppcheck --enable=all --error-exitcode=1 --quiet src include; then
  FAILED=1
fi

if [ "$FAILED" -ne 0 ]; then
  echo "Style checks failed."
  exit 1
fi
echo "Style checks passed."
