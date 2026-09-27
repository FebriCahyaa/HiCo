# generated/ — reproducible derived zone

Every file here is produced by `tools/` from `stock/`. See
`docs/ARCHITECTURE.md` for the full contract.

## What lives here

- `decoded/<vendor>/<codename>/` — Codec-decoded stock (e.g. mi_thermald
  AES → plaintext).
- `tuned/<vendor>/<codename>/` — HiCo-tuned thermal per profile
  (`game.conf`, `daily.conf`) plus `TEMPLATE.md` diff.
- `packed/<vendor>/<codename>/` — Re-encoded back into each device's
  original format.
- `db/` — Consolidated JSON tables (devices, mapping, coverage, universal)
  consumed by hicod runtime.
- `reports/` — Human-readable audit and coverage markdown.
- `module/` — Flashable ZIP built for each release.
- `artifacts/` — Native binaries and symbols; **not committed**
  (see `.gitignore`).

## Determinism

Same `stock/` + same `tools/` version = byte-identical output. This mirrors
HiCo's existing determinism guarantee in `tests/hico_evidence_parsers_test.py`.

## Reproducing

    # From an empty generated/:
    python3 tools/hico_evidence.py verify --root sources/evidence
    python3 tools/tune/game.py  --hicod build/hicod
    python3 tools/tune/daily.py --hicod build/hicod
    python3 tools/hico_generator.py --emit-db generated/db

Or trigger `.github/workflows/tools.yml` and let CI run every OEM in
parallel.

## Deleting

Safe. Nothing here is authoritative; `generated/` is regenerable. If you
need to keep an old snapshot, tag the commit — do not preserve files by
copying.
