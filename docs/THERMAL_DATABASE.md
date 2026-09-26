# HiCo Thermal Database and Processing Pipeline

HiCo Thermal uses a device-aware knowledge database instead of assuming that every Android device has the same thermal implementation. The hardware, vendor stack, ROM integration and repository provenance are kept as separate facts and joined during profile resolution.

## Processing layers

```text
OEM dumps / ROM trees / vendor trees / kernel trees
                     │
                     ▼
              source discovery
                     │
                     ▼
              partial Git clone
                     │
                     ▼
             thermal-relevant scan
                     │
          ┌──────────┴──────────┐
          ▼                     ▼
      known codec           unknown data
          │                     │
     decode in memory      metadata + hash
          │                     │
          └──────────┬──────────┘
                     ▼
              parser / mapper
                     │
                     ▼
             normalized database
                     │
                     ▼
                validation
                     │
                     ▼
                  publish
```

## Unpack vs codec vs parser

- **Unpackers** open containers or filesystems such as ZIP, TAR, gzip, XZ, bzip2, Android sparse images, Android `super.img`, EROFS and ext4 when the required host tools are installed.
- **Codecs** convert the contents of a thermal artifact between encoded and decoded representations. The current Xiaomi `mi_thermald_aes` codec is an adapter around the existing native `MiCrypt` implementation in HiCo.
- **Parsers** understand the decoded content and expose sensors, sections, thresholds and other normalized facts.

These responsibilities are deliberately separate. A new vendor therefore does not require a fake "vendor crypt" implementation when its thermal files are actually plaintext or exposed through a HAL/runtime interface.

## Unknown encrypted data

HiCo never guesses an encryption algorithm or attempts to bypass a protection mechanism. Unknown encrypted/opaque data is recorded with provenance and hash information and remains non-tunable until a legitimate, verified codec is available.

## Source provenance

Every external repository manifest records provider, repository, branch, source commit, URL and relevant file paths. Dependency files such as `lineage.dependencies`, `evolution.dependencies` and `.gitmodules` are also inspected so the database can preserve relationships between device trees and common/vendor/kernel repositories.

## Repository storage policy

Small text/JSON/XML artifacts may be copied into the generated database when they meet the ingestion policy. Large or binary proprietary material is not blindly redistributed. The normalized mapping can still describe the artifact, its parser/codec status and SHA-256 information without copying the blob.

## Workflows

### Database workflow

`.github/workflows/database.yml` performs one complete run:

```text
audit/build → discover → ingestion matrix → mapping matrix → merge → validation → publish
```

Matrix workers never push to Git. The final publish job is the only writer after validation succeeds.

### Tools workflow

`.github/workflows/tools.yml` validates tool changes. A manual run in `full` mode maps every repository thermal root currently in `devices/` and every permitted raw source root under `database/sources/ingested/raw/`, then publishes the deterministic mapping under `database/mapped/`.

## Current seeded database

The uploaded repository already contained 212 device records. The generated seed database is intentionally preserved in the source tree. Its external-source expansion is performed by the Actions workflow, not assumed to have run locally.

## Deep mapping and generic unpack

`hico-thermal deep-map` and `deep-map-set` recursively inspect supported Android/archive containers and map thermal-relevant files discovered inside them. The expansion layer is independent from the codec layer: a container can be unpacked even when an enclosed encrypted file remains opaque. Filesystem extraction is opt-in with `--filesystem-extract`; unknown encryption is never guessed.

Supported optional external tools include `simg2img`, `lpunpack`, `fsck.erofs`, `debugfs`, and `zstd`. Their absence is reported explicitly instead of silently substituting an unsafe implementation.


## Thermal value table

HiCo maintains two distinct thermal tables. The live table (`hicod thermal table`) is read directly
from the running kernel thermal framework and contains actual zone temperatures, trip thresholds,
headroom, thermal state and cooling-device state at sample time. The repository table under
`database/tables/` is static source analysis: it records the highest original trip value found in the
source artifact and the highest HiCo candidate value generated for that same scope. The candidate
column is never presented as a measured safety limit.


The Tools workflow does not watch its own generated `database/**` push output, preventing a publish/
remap loop. Pull requests still include database changes in the validation path.
