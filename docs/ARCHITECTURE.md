# HiCo Thermal Repository Architecture

## Two-zone model

The repository separates **input data** from **derived output**. The boundary
is strict: tools never rewrite input; input never contains anything a tool
produced.

    stock/     ← INPUT.   Read-only for tools. Written only by ingest.
    generated/ ← DERIVED. Regenerated from stock/ + tools/ at any time.

If `generated/` is deleted, the tools workflow rebuilds it. If `stock/` is
deleted, the ingest workflow refetches it from public sources.

## Zones

### `stock/` — canonical input

Ingested from public sources (LineageOS device trees on GitHub, PixelOS,
Xiaomi/OEM firmware dumps). Every file is recorded in
`stock/manifest.json` with `{url, revision, sha256, fetched_at, rom_variant}`.

Layout mirrors the on-device partition structure so files can be compared
directly across devices:

    stock/
    ├── manifest.json                          index of every ingested file
    ├── oem/<vendor>/<codename>/               vendor dump (OEM ROM)
    │   ├── source.json                        provenance for this device
    │   ├── device.prop                        identity: brand, model, SoC, Android
    │   └── vendor/etc/thermal/…               thermal files EXACTLY as shipped
    ├── rom/<rom>/<codename>/                  community ROM variant
    │   └── (same partition layout as oem/)
    └── evidence/                              supporting non-thermal source
        ├── device_tree/<vendor>/<codename>/   device.mk, BoardConfig.mk, ...
        └── kernel/<soc>/                      thermal.dtsi, defconfig

Rules:

1. Only `tools/ingest/*` writes here, via `ingest.yml`.
2. File contents are **never modified**. If decoding is required, the decoded
   form lives in `generated/decoded/`.
3. Path inside a device dir follows the source partition path
   (`vendor/etc/thermal/thermal-engine.conf`), not a HiCo-invented shape.
4. Large binary blobs (`.img`, `.bin`) are LFS-tracked
   (see `.gitattributes`).

### `generated/` — reproducible output

Every file here is the result of running `tools/` against `stock/`. Two runs
with the same inputs produce byte-identical output (matching HiCo's existing
determinism guarantee for `hico_evidence_parsers`).

    generated/
    ├── decoded/<vendor>/<codename>/           decoded stock (e.g. mi_thermald AES → plain)
    ├── tuned/<vendor>/<codename>/             tune_thermal output per profile
    │   ├── game.conf                          HiCo game profile
    │   ├── daily.conf                         HiCo daily profile (social, streaming)
    │   └── TEMPLATE.md                        stock → tuned trip diff
    ├── packed/<vendor>/<codename>/            re-encoded for the device's format
    ├── db/                                    lookup tables consumed by hicod
    │   ├── devices.json                       device DB across every OEM
    │   ├── mapping.json                       codename → SoC → thermal format
    │   ├── coverage.json                      OEM × ROM × device support matrix
    │   └── universal.json                     runtime table for hicod
    ├── reports/                               markdown verification reports
    │   ├── THERMAL_TUNING.md                  per-device tuning diff
    │   ├── COVERAGE.md                        support matrix rendered
    │   └── AUDIT.md                           parser/codec regression audit
    ├── module/                                flashable module zips per release
    └── artifacts/                             build outputs, not committed

Rules:

1. Only `tools/*` writes here.
2. Any file must trace back to a stock source (recorded in a sidecar or
   header) plus the tool version that produced it.
3. Repro: same `stock/` + same `tools/` version = byte-identical output.
4. `generated/artifacts/` is gitignored (native binaries, symbols). Everything
   else in `generated/` is tracked so status is visible without running tools.

## Runtime paths (unchanged)

Not part of either zone; these are code and product:

    jni/            hicod daemon (C++/native)
    module/         Magisk module template + install scripts
    webui/          Vue 3 control UI
    tools/          transformers (see below)
    tests/          unit tests + fixtures
    docs/           human documentation
    scripts/        shell helpers loaded at boot
    infra/          CI helpers
    .github/        workflows and templates

## Tools taxonomy

    tools/
    ├── ingest/            input plugins (one per OEM)
    │   ├── base.py        OEMSource ABC
    │   ├── xiaomi.py      migrated from tools/xiaomi_devices.py
    │   ├── samsung.py     (new)
    │   ├── pixel.py       (new — Pixel + AOSP)
    │   ├── oneplus.py     (new)
    │   ├── oppo_realme.py (new)
    │   ├── nothing.py     (new)
    │   ├── motorola.py    (new)
    │   ├── vivo.py        (new)
    │   └── asus.py        (new)
    ├── codecs/            format handlers
    │   ├── plain.py       thermal-engine.conf plaintext
    │   ├── mi_thermald_aes.py    (migrated from hico_thermal/codecs.py:MiThermaldCodec)
    │   ├── samsung_lsi.py (new)
    │   ├── aosp_hal_json.py     (new — Pixel & AOSP)
    │   ├── oplus_scene_xml.py    (new — OPPO/OnePlus/Realme scenes)
    │   ├── vivo_platform_xml.py  (new)
    │   └── moto_mmi.py    (new)
    ├── tune/              profile generators
    │   ├── game.py        (migrated from tune_thermal.py)
    │   └── daily.py       (new — social, streaming; low-heat, no perf drop)
    ├── verify/            correctness checks
    ├── hico_thermal/      internal codec + pack/unpack machinery (unchanged)
    └── (legacy top-level scripts stay until every caller is updated)

## Migration status

This commit lands the two-zone skeleton and documents the contract. It does
NOT yet move existing Xiaomi data from `devices/xiaomi/` into
`stock/oem/xiaomi/`, nor split `tools/xiaomi_devices.py` into the plugin
layout — those follow as separate commits so each is independently
reviewable and revertible.

Live location today (transitional):

    devices/xiaomi/<codename>.prop         → to move: stock/oem/xiaomi/<codename>/device.prop
    devices/xiaomi/<codename>/thermal/     → to move: stock/oem/xiaomi/<codename>/vendor/etc/thermal/
    devices/xiaomi/<codename>/tuned/       → to move: generated/tuned/xiaomi/<codename>/
    thermal-data/oem/xiaomi/               → to merge into stock/oem/xiaomi/
    generated-thermal/oem/xiaomi/          → to move: generated/packed/xiaomi/
    database/{thermal,devices,mapped,universal}/ → to consolidate: generated/db/
    sources/{registry,repositories,discovery,...}.json → to consolidate: stock/manifest.json
