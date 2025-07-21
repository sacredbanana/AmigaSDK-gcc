#!/usr/bin/env bash
# This script combines all documentation files into a single output file.
# This is useful for generating a comprehensive documentation file that can be easily searched or indexed
# by AI systems.

OUTPUT="combined-docs.txt"
find . -type f \( -iname '*.doc' -o -iname '*.txt' \) ! -iname "$OUTPUT" -print0 \
  | while IFS= read -r -d '' file; do
      printf "\n\n===== %s =====\n\n" "$file"
      cat "$file"
    done > "$OUTPUT"