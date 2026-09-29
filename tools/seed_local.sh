#!/usr/bin/env bash
# tools/seed_local.sh — one-time local seed for stock/
#
# Run this ONCE from a developer machine to populate stock/ with all thermal
# files. After the initial seed is committed and pushed, the weekly ingest.yml
# workflow only fetches deltas (10–30 min instead of 14–22 h).
#
# Usage:
#   export GH_TOKEN="ghp_..."    # GitHub PAT (repo scope) — needed for API rate limits
#   bash tools/seed_local.sh
#
# Or fetch only specific sources:
#   bash tools/seed_local.sh lineageos crdroid
#
# Requirements:
#   - Python 3.10+
#   - git (2.25+ recommended, for sparse-checkout --no-cone)
#   - A GitHub Personal Access Token with "repo" scope (set as GH_TOKEN)
#   - ~30–50 GB free disk space (sparse fetches; blobs are tiny)
#   - A reliable internet connection (thousands of git ls-remote calls)
#
# Expected runtime:
#   ROM sources (lineageos, crdroid, etc.)   4–10 h   (largest, ~7000 repos each)
#   Blob sources (themuppets, rom-vendor)    2–4 h
#   OEM dump sources (tadiphone-*)           2–4 h    (public GitLab, no token)
#   Total, single run:                      ~14–22 h
#
# The state files in stock/manifest/*.state.json track every completed device,
# so if the script is interrupted you can just re-run and it will resume from
# where it stopped.

set -euo pipefail
cd "$(dirname "$0")/.."

JOBS=${JOBS:-16}
PYTHON=${PYTHON:-python3}
LOG_DIR="$(pwd)/logs/seed"
mkdir -p "$LOG_DIR"

# ── ROM sources (must run FIRST — OEM sources gate on ROM manifests) ─────────
ROM_SOURCES=(
  lineageos
  crdroid
  pixelos
  derpfest
  evolutionx
  arrowos
  aospa
  dotos
  voltageos
  lmodroid
  awakenos
  alphadroid
  spark
  protonaosp
)

# ── Blob sources ──────────────────────────────────────────────────────────────
BLOB_SOURCES=(
  themuppets
  rom-vendor-blobs
)

# ── OEM dump sources (public GitLab, no token needed) ────────────────────────
OEM_SOURCES=(
  tadiphone-xiaomi
  tadiphone-redmi
  tadiphone-poco
  tadiphone-samsung
  tadiphone-oneplus
  tadiphone-oppo
  tadiphone-realme
  tadiphone-motorola
  tadiphone-google
)

# ── Helpers ───────────────────────────────────────────────────────────────────

log() { echo "[$(date -u +%H:%M:%S)] $*"; }

check_gh_token() {
  if [[ -z "${GH_TOKEN:-}" ]]; then
    echo "WARNING: GH_TOKEN is not set."
    echo "  GitHub API calls will be rate-limited to 60/h (anonymous)."
    echo "  Set GH_TOKEN to a PAT with 'repo' scope for 5000 req/h:"
    echo "    export GH_TOKEN=\"ghp_...\""
    echo ""
    read -rp "Continue without token? [y/N] " yn
    [[ "$yn" =~ ^[Yy]$ ]] || { echo "Aborted."; exit 1; }
  fi
}

list_and_fetch() {
  local sid="$1"
  local log_file="$LOG_DIR/${sid}.log"

  log "=== $sid: listing repositories ==="
  # rom-vendor-blobs (vendor-probe) ignored --jobs entirely until this fix and
  # always ran 32 parallel git ls-remote probes across every ROM source's
  # combined device list (1000+ URLs) — the real cause of a signal-9 kill
  # right as that source starts, regardless of $JOBS used for sparse_fetch.py.
  if ! GH_TOKEN="${GH_TOKEN:-}" $PYTHON tools/ingest/list_device_repos.py \
        --only "$sid" --jobs "$JOBS" 2>&1 | tee -a "$log_file"; then
    log "WARNING: list_device_repos failed for $sid (check $log_file)"
    return 1
  fi

  log "=== $sid: fetching thermal files (jobs=$JOBS) ==="
  # `!` on a pipeline inverts $? itself, not just the if/else branch taken —
  # `rc=$?` read afterward would capture that inverted value (always 0 or 1),
  # never the real exit code. Disable errexit so a nonzero sparse_fetch.py
  # doesn't abort the script here, then read ${PIPESTATUS[0]} as the very
  # next statement, before anything else can overwrite it.
  set +e
  $PYTHON tools/ingest/sparse_fetch.py \
        --source "$sid" --jobs "$JOBS" 2>&1 | tee -a "$log_file"
  local rc=${PIPESTATUS[0]}
  set -e
  if [[ $rc -eq 2 ]]; then
    # Exit 2 means some repos failed — not fatal; they'll be retried next run.
    log "WARNING: $sid finished with some failures (rc=2); see $log_file"
  elif [[ $rc -ne 0 ]]; then
    log "ERROR: sparse_fetch.py failed for $sid (rc=$rc); see $log_file"
    return 1
  fi

  log "=== $sid: committing ==="
  git add "stock/manifest/${sid}.json" \
          "stock/manifest/${sid}.state.json" \
          "stock/rom/${sid}" \
          "stock/blobs/${sid}" \
          "stock/oem/${sid}" 2>/dev/null || true
  if git diff --cached --quiet; then
    log "$sid: nothing to commit (all already up-to-date)"
  else
    local summary
    summary="$(git diff --cached --stat | tail -n 1)"
    git commit -q \
      -m "ingest(seed): fetch ${sid} thermal files" \
      -m "$summary" \
      -m "Co-Authored-By: Claude Sonnet 4.6 <noreply@anthropic.com>" \
      -m "Claude-Session: https://claude.ai/code/session_0149ijLanJp6yoyAj4w7AYQX"
    log "$sid: committed — $summary"
  fi
}

# ── Main ──────────────────────────────────────────────────────────────────────

check_gh_token

# Configure git identity if not set
if ! git config user.email >/dev/null 2>&1; then
  git config user.email "febricahya1234@gmail.com"
  git config user.name  "HiCo Seed"
fi

# Build the list of sources to process
SOURCES_TO_RUN=()
if [[ $# -gt 0 ]]; then
  SOURCES_TO_RUN=("$@")
else
  SOURCES_TO_RUN=("${ROM_SOURCES[@]}" "${BLOB_SOURCES[@]}" "${OEM_SOURCES[@]}")
fi

log "Sources to seed: ${SOURCES_TO_RUN[*]}"
log "Logs: $LOG_DIR"
log "Jobs per source: $JOBS"
echo ""

FAILED=()
for sid in "${SOURCES_TO_RUN[@]}"; do
  started=$(date +%s)
  if list_and_fetch "$sid"; then
    elapsed=$(( $(date +%s) - started ))
    log "$sid: done in $(( elapsed / 60 ))m $(( elapsed % 60 ))s"
  else
    log "FAILED: $sid — continuing with remaining sources"
    FAILED+=("$sid")
  fi
  echo ""
done

# Final push
log "=== Pushing all commits to origin ==="
BRANCH=$(git rev-parse --abbrev-ref HEAD)
git push -u origin "$BRANCH"

echo ""
log "=== Seed complete ==="
if [[ ${#FAILED[@]} -gt 0 ]]; then
  log "The following sources had errors (re-run to retry):"
  for sid in "${FAILED[@]}"; do
    log "  - $sid  (log: $LOG_DIR/${sid}.log)"
  done
  echo ""
  log "Re-run with: bash tools/seed_local.sh ${FAILED[*]}"
  exit 2
fi
log "All sources seeded successfully."
