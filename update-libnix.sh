#!/usr/bin/env bash
# Refresh amigaos3/sdk/m68k-amigaos/libnix from the latest bebbo/libnix.
#
# Overlays libnix's own files only -- non-libnix files that live in the same
# tree (include/json-c, lib/**/libjson-c.a, ...) are left untouched.
#
# Afterwards, rebuild the cross-compiler image as usual (./build.sh or
# docker build -f Dockerfile.m68k-amigaos .) to pick the new files up.
# NOTE: after refreshing libnix you must rebuild json-c against the new headers
# (errno became *__errno). newlib, clib2 and libamisslstubs are unaffected.
# See the comment block at the top of Dockerfile.libnix.

set -euo pipefail

cd "$(dirname "$0")"
DEST=amigaos3/sdk/m68k-amigaos/libnix
BRANCH="${LIBNIX_BRANCH:-master}"

[[ -d "$DEST" ]] || { echo "error: $DEST not found (run from the repo root)" >&2; exit 1; }

echo "==> current libnix revision in repo:"
cat "$DEST/libnix-revision.txt" 2>/dev/null | sed 's/^/    /' || echo "    (unknown - never refreshed by this script)"

before=$(mktemp); find "$DEST" -type f -exec shasum -a 1 {} + 2>/dev/null | sort -k2 > "$before"

echo "==> building libnix ($BRANCH) and exporting into $DEST"
# Empty build context (the Dockerfile needs no files from the repo), and
# --output writes the scratch stage straight into the repo as an overlay.
docker build \
  --build-arg "LIBNIX_BRANCH=$BRANCH" \
  --output "type=local,dest=$DEST" \
  - < Dockerfile.libnix

echo "==> new libnix revision:"
sed 's/^/    /' "$DEST/libnix-revision.txt"

after=$(mktemp); find "$DEST" -type f -exec shasum -a 1 {} + 2>/dev/null | sort -k2 > "$after"
echo "==> files changed:"
join -j2 -o 1.1,2.1,0 "$before" "$after" 2>/dev/null | awk '$1!=$2 {print "    M " $3}' | sed "s|$DEST/||"
comm -13 <(awk '{print $2}' "$before") <(awk '{print $2}' "$after") | sed "s|^|    + |;s|$DEST/||"
echo "==> sanity: non-libnix files still present:"
printf "    include/json-c: %s files\n" "$(ls "$DEST/include/json-c" 2>/dev/null | wc -l | tr -d ' ')"
printf "    libjson-c.a copies: %s\n" "$(find "$DEST/lib" -name libjson-c.a 2>/dev/null | wc -l | tr -d ' ')"
rm -f "$before" "$after"
echo "==> done. Rebuild the cross-compiler image to use it."
