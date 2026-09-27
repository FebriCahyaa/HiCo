# stock/ — canonical input zone

Read-only for tools. See `docs/ARCHITECTURE.md` for the full contract.

## What lives here

- `oem/<vendor>/<codename>/` — OEM firmware dumps (Xiaomi/MIUI, Samsung/One UI,
  OnePlus/OxygenOS, OPPO/ColorOS, Realme UI, Nothing OS, Motorola, Vivo,
  ASUS, Google Pixel).
- `rom/<rom>/<codename>/` — Community ROM variants for the same device
  (LineageOS, PixelOS, crDroid, AOSP).
- `evidence/` — Supporting device-tree / kernel source referenced by ingest.
- `manifest.json` — Provenance index: every file's origin URL, revision,
  SHA-256, fetch time.

## What does NOT live here

- Anything a tool produced (belongs in `generated/`).
- Local scratch or cache.
- Files without a manifest entry.

## Who writes here

Only `tools/ingest/*` via `.github/workflows/ingest.yml`. Manual edits are
rejected in code review — reingest instead.

## Layout

    stock/
    ├── manifest.json
    ├── oem/
    │   ├── xiaomi/<codename>/
    │   │   ├── source.json
    │   │   ├── device.prop
    │   │   └── vendor/etc/thermal/…
    │   ├── samsung/<codename>/
    │   ├── oneplus/<codename>/
    │   ├── oppo/<codename>/
    │   ├── realme/<codename>/
    │   ├── google/<codename>/
    │   ├── nothing/<codename>/
    │   ├── motorola/<codename>/
    │   ├── vivo/<codename>/
    │   └── asus/<codename>/
    ├── rom/
    │   ├── lineageos/<codename>/
    │   ├── pixelos/<codename>/
    │   ├── crdroid/<codename>/
    │   └── aosp/<codename>/
    └── evidence/
        ├── device_tree/<vendor>/<codename>/
        └── kernel/<soc>/
