# stock/ — canonical input zone

Read-only for tools. See `docs/ARCHITECTURE.md` for the full contract.

## What lives here

- `oem/<vendor>/<codename>/` — OEM firmware dumps (Xiaomi/MIUI, Samsung/One UI,
  OnePlus/OxygenOS, OPPO/ColorOS, Realme UI, Nothing OS, Motorola, Vivo,
  ASUS, Google Pixel).
- `rom/<source>/<vendor>__<codename>/` — thermal-relevant files of each
  custom-ROM device tree (LineageOS, crDroid, LMODroid, AOSPA, ArrowOS,
  DotOS, AlphaDroid, PixelOS, ProtonAOSP, AwakenOS, …): thermal configs,
  power-HAL / thermal-HAL setup, init files, build props, the device's
  `proprietary-files.txt`. Common trees (`sm8350-common`, …) are kept.
- `blobs/themuppets/<vendor>__<codename>/proprietary/…` — the stock vendor
  thermal blobs themselves (`thermal-*.conf`, `thermal_info_config*.json`,
  thermal HAL init / VINTF, power hints) from TheMuppets, i.e. what the
  OEM firmware ships, per device and per common tree.
- every device directory has `source.json`: upstream repo, branch, commit,
  and SHA-256 + size of every file (files over 2 MB are listed, not stored).
- `manifest/<source>.json` — what upstream lists (metadata only);
  `manifest/<source>.state.json` — what was fetched, at which commit, with
  what outcome (`ok` / `empty` / `failed`). `tools/ingest/diff_manifests.py`
  compares the two so a scheduled run fetches only what moved.
- `sources.yaml` — the source list (org / provider, branches, paths).
- `evidence/` — Supporting device-tree / kernel source referenced by ingest.

## What does NOT live here

- Anything a tool produced (belongs in `generated/`).
- Local scratch or cache.
- Files without a manifest entry.

## Who writes here

Only `tools/ingest/*` via `.github/workflows/ingest.yml`. Manual edits are
rejected in code review — reingest instead.

## Layout

    stock/
    ├── sources.yaml
    ├── manifest/
    │   ├── index.json
    │   ├── <source>.json          # listing
    │   └── <source>.state.json    # fetched commit per repository
    ├── rom/<source>/<vendor>__<codename>/
    │   ├── source.json
    │   └── … (thermal-relevant files, repo layout kept)
    ├── blobs/themuppets/<vendor>__<codename>/
    │   ├── source.json
    │   └── proprietary/vendor/etc/thermal-*.conf, …
    ├── oem/<vendor>/<codename>/    # firmware dumps
    └── evidence/

## Refresh

    python3 tools/ingest/list_device_repos.py           # re-list (GitHub API in CI)
    python3 tools/ingest/sparse_fetch.py --all --jobs 24  # full seed, resumable
    python3 tools/ingest/diff_manifests.py --out changed.json
    python3 tools/ingest/sparse_fetch.py --all --only-changed changed.json

`ingest.yml` runs the last two weekly and opens a pull request with the delta.
