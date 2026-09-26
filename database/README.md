# HiCo Thermal Knowledge Database

`database/` is the generated, validated knowledge layer for HiCo Thermal. It keeps device identity, vendor/ROM provenance, thermal-relevant artifact metadata, parsed thermal mappings and future baseline/profile data separate from the runtime module.

The repository database is not a firmware mirror. Small text artifacts may be retained when permitted by the ingestion policy; proprietary or unsupported binary data is represented by metadata and hashes instead of being redistributed.

## Data layers

- `devices/` — normalized profiles generated from the device records already present in this repository.
- `sources/ingested/` — manifests and permitted raw text artifacts discovered from external OEM/ROM/device-tree repositories.
- `mapped/` — deterministic thermal artifact mappings produced by the tool workflow.
- `schema/` — machine-readable schemas used by CI validation.

## Identity model

A device is resolved from hardware/vendor/build information, while ROM integrations are tracked separately. The same hardware can therefore have multiple variants such as stock OEM, AOSP, LineageOS or PixelOS without collapsing them into one indistinguishable record.

## Codec policy

The codec registry is explicit. `mi_thermald_aes` is the adapter around HiCo's existing Xiaomi `MiCrypt` implementation. Plain-text, JSON and XML thermal files use their normal parsers. Unknown encrypted or opaque binary files remain metadata-only until a codec is known and can be implemented and verified legitimately.

## Reproducibility

Every externally ingested repository records provider, repository, branch, source commit and file provenance. Matrix workers produce artifacts; only the merge/publish job writes generated database content back to the repository after validation.
