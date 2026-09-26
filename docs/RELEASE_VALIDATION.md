# HiCo Thermal Release Validation

This report records the local validation performed against the uploaded HiCo source after the thermal tooling and database pipeline changes.

## Scope

The existing project layout was preserved. In particular, `webui/` and `module/` were not modified by the database/tooling work.

## Local checks

- CMake Debug build: PASS
- CTest: 2/2 PASS
- Python compilation for tools/tests: PASS
- `tests/hico_tools_test.py`: PASS
- `tests/topology_test.py`: PASS
- `tests/database_test.py`: PASS
- `tests/scanner_test.py`: 14/14 PASS
- `tools/gen_device_db.py --check`: PASS
- `tools/hico_database.py validate database`: PASS
- `tools/verify_webui.py`: PASS
- Workflow YAML parse: PASS for `build.yml`, `database.yml`, `release.yml`, `tools.yml`

## Seeded repository data

- Device records: 212
- Thermal artifact records in the normalized device database: 3047
- Existing thermal roots remapped locally: 190
- Local mapped artifacts: 3237
- Local decode/analysis failures: 0
- Local deep-map container expansions: 0 (the current seeded thermal roots contain no supported nested containers)
- Existing WebUI files verified: 107
- Existing module files verified: 15

## Codec boundary

The only vendor-specific cryptographic codec currently implemented is the existing Xiaomi `MiCrypt` integration for the `mi_thermald` format. Known plaintext formats are parsed directly. Unknown encrypted or opaque binaries are retained as metadata/hash records and are not passed to an invented decryptor.

## External source ingestion

The full online ingestion run against Tadiphone, ROM organizations and independent maintainer repositories was not executed in the local build environment because that environment does not provide the required outbound repository/API access. The Actions pipeline is configured to perform that discovery, matrix ingestion, mapping, validation and publish sequence in GitHub Actions.
