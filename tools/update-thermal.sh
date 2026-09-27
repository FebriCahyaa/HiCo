#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

PUSH=0
WORKERS="${HICO_COLLECTOR_WORKERS:-4}"
GEN_WORKERS="${HICO_GENERATOR_WORKERS:-4}"
if [[ "${1:-}" == "--push" ]]; then
  PUSH=1
  shift
fi

if [[ $# -gt 0 ]]; then
  echo "usage: $0 [--push]" >&2
  exit 2
fi

echo "== HiCo Thermal local update =="

if [[ ! -s sources/repositories.json ]]; then
  python3 tools/hico_collector.py bootstrap
fi

if [[ ! -d thermal-data || -z "$(find thermal-data -name manifest.json -print -quit 2>/dev/null)" ]]; then
  python3 tools/hico_collector.py import-legacy
fi

python3 tools/hico_collector.py sync --workers "$WORKERS" --changed-only

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j"$(nproc)"
ctest --test-dir build --output-on-failure

python3 tools/hico_generator.py generate --hicod build/hicod --workers "$GEN_WORKERS"
python3 tools/hico_collector.py verify
python3 tools/hico_generator.py verify

python3 tools/hico_database.py build --root . --output database
python3 tools/hico_database.py thermal-table --root . --output database/tables
python3 tools/hico_database.py validate database
python3 tools/hico_database.py validate database/tables
python3 tools/gen_device_db.py --check
python3 tools/verify_webui.py

# Keep transient collector output out of commits.
rm -f sources/collector-last-run.json

git diff --check

git status --short

echo
if [[ "$PUSH" -eq 1 ]]; then
  git add thermal-data generated-thermal database sources/repositories.json sources/collector-state.json
  if git diff --cached --quiet; then
    echo "No thermal changes to commit."
    exit 0
  fi
  git commit -m "data(thermal): refresh collected sources and generate HiCo thermal" \
    -m "Collect public OEM and custom-ROM thermal artifacts locally, preserve source provenance and regenerate validated HiCo thermal candidates and database indexes."
  git push origin HEAD
  echo "Thermal dataset pushed successfully."
else
  echo "Prepared. Review git diff, then run:"
  echo "  $0 --push"
fi
