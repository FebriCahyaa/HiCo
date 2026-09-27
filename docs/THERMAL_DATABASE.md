# HiCo Thermal Database and Processing Pipeline

HiCo Thermal uses a device-aware knowledge database and a local source collector. The collector downloads public
Git repositories without GitHub/GitLab API calls during normal synchronization, extracts thermal-relevant files,
preserves provenance, generates HiCo candidates and validates the result before the data is committed.

## Processing layers

```text
public Git repositories
        │
        ▼
local collector (clone/fetch)
        │
        ▼
thermal-data/ + manifest.json
        │
        ├── original file
        ├── repository / branch / commit
        ├── OEM / ROM / device / Android
        └── repository role
        │
        ▼
HiCo parser / codec / mapper
        │
        ▼
HiCo Thermal generator
        │
        ▼
generated-thermal/
        │
        ▼
hicod thermal check
        │
        ▼
database/ + thermal tables
```

## Source storage

The canonical source path is:

```text
thermal-data/<ecosystem>/<vendor>/<rom>/<device>/<android>/<role>/<repository>/
    raw/<original repository path>
    manifest.json
```

`thermal-data/` stores the original bytes for thermal-relevant files that can be represented in the Git
repository. Every stored file receives a SHA-256 through the manifest. Large firmware-style blobs can use Git LFS
when the clone is configured for it.

## Unpack vs codec vs parser

- **Unpackers** open supported containers or filesystems such as ZIP, TAR, gzip, XZ, bzip2, Android sparse images,
  `super.img`, EROFS and ext4 when the required host tools are installed.
- **Codecs** convert known encoded thermal formats. The Xiaomi `mi_thermald_aes` adapter uses HiCo's existing
  native MiCrypt implementation.
- **Parsers** expose sensors, sections, thresholds, shutdown limits and other normalized facts.
- **Generator** invokes the host `hicod thermal tune` implementation and verifies its candidate with
  `hicod thermal check`.

## Unknown encrypted data

HiCo does not guess an encryption algorithm or bypass an unknown protection mechanism. An unknown encrypted or
opaque thermal artifact is retained when possible and recorded with provenance and hash information, but it is not
generated or tuned until a legitimate, verified codec is available.

## Workflows

`.github/workflows/database.yml` is intentionally read-only with respect to upstream sources. It verifies the
committed `thermal-data/` and `generated-thermal/` dataset, rebuilds the database deterministically and uploads
verification artifacts. `.github/workflows/build.yml` performs the normal C++/Python build and dataset checks.
`.github/workflows/tools.yml` provides the manual full mapping path for thermal roots already present in the
repository.

## Local update command

```shell
./tools/update-thermal.sh
```

This performs local repository synchronization, HiCo candidate generation, database rebuild and verification. Use
`./tools/update-thermal.sh --push` to commit and push the validated result.

## Current seeded database

The repository is seeded with the existing 212 Xiaomi device records. `sources/repositories.json` is generated
from those records so the local collector can refresh their public Git remotes without API discovery. Additional
OEM and custom-ROM repositories can be added to that index without changing the runtime engine.
