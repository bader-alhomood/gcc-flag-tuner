#!/usr/bin/env bash
# Records which optimisation flags this gcc supports and which ones -O3 turns on.
set -euo pipefail

OUT=results/inventory
mkdir -p "$OUT"

gcc --version | head -1 > "$OUT/gcc_version.txt"

for level in O2 O3; do
  gcc -Q --help=optimizers -$level > "$OUT/${level}_raw.txt"
  awk '$2 == "[enabled]"  {print $1}' "$OUT/${level}_raw.txt" > "$OUT/${level}_enabled.txt"
  awk '$2 == "[disabled]" {print $1}' "$OUT/${level}_raw.txt" > "$OUT/${level}_disabled.txt"
done

comm -13 <(sort "$OUT/O2_enabled.txt") <(sort "$OUT/O3_enabled.txt") > "$OUT/O3_only.txt"

echo "Compiler:               $(cat "$OUT/gcc_version.txt")"
echo "On/off flags in total:  $(( $(wc -l < "$OUT/O3_enabled.txt") + $(wc -l < "$OUT/O3_disabled.txt") ))"
echo "Enabled at -O3:         $(wc -l < "$OUT/O3_enabled.txt")"
echo "Disabled at -O3:        $(wc -l < "$OUT/O3_disabled.txt")"
echo "Added by -O3 over -O2:  $(wc -l < "$OUT/O3_only.txt")"