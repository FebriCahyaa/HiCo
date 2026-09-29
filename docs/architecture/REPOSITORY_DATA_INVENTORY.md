# Repository Data Inventory — HiCo Thermal (future Synrei)

Required by the Repository Data Preservation Lock of the Zairenkai programme: nothing in this
repository may be moved, renamed, regenerated-over, truncated or deleted until it is listed here and
in `DELETION_MANIFEST.md`. Ecosystem-level baseline, migration matrix and agent state live in
`FebriCahyaa/Flux` under `docs/architecture/` and `docs/agent-state/`.

| | |
|---|---|
| Audited commit | `main` @ `a61cad023aa65bfce21e46bda1016045ad5b9c80` |
| Audit branch | `ccr-0dc934d1-0a6zta` (no code or data changes) |
| Tracked files | 45,453 (~211 MB) |
| License | Proprietary — `EULA.md` (not Apache-2.0 like Flux and SynthesisCore) |
| Audit date | 2026-09-29 |

Classes: AUTHORITATIVE, DEPENDENCY, HISTORICAL, TEST, FIXTURE, GENERATED (tool output tracked in
git and consumed as-is), DERIVED (reproducible, still tracked), UNKNOWN (preserved, never read as
obsolete).

## Important reading of `docs/ARCHITECTURE.md`

That document says `generated/` "is rebuilt" and `stock/` "is refetched" if deleted. Under the
preservation lock this describes **reproducibility**, not permission to delete: upstream sources
move, rewrite history or disappear, and a refetch can produce different bytes than the evidence
recorded here. Deleting any of these trees requires a `DELETION_MANIFEST.md` entry.

## Engineering datasets (protected)

| Path | Files | Size | Role | Consumers | Class | Reproducible | CI | Runtime | Tests |
|---|---|---|---|---|---|---|---|---|---|
| `stock/` | 32,529 | 157 MB | Canonical ingested input: `rom/<rom>/<codename>/` (LineageOS 11,705, crDroid 4,792, LMODroid 4,017, EvolutionX 2,045, ArrowOS, AOSPA, DerpFest, AlphaDroid, DotOS, PixelOS, …), `oem/`, `blobs/` (TheMuppets, rom-vendor-blobs), `manifest/`, `evidence/`, `sources.yaml` | `tools/ingest/*`, `tools/verify/rom_sources.py`, `tools/seed_local.sh`, `ingest.yml` | AUTHORITATIVE + HISTORICAL (provenance: url, revision, sha256, fetched_at) | only by refetch; bytes not guaranteed | yes (ingest) | no | indirect |
| `thermal-data/` | 3,237 | 9.3 MB | Canonical raw thermal source dataset (`oem/…`) | `tools/hico_database.py`, `tools/hico_generator.py`, `build.yml`, `database.yml`, `tools.yml` | AUTHORITATIVE | no | yes | no | yes |
| `generated-thermal/` | 4,930 | 12.6 MB | HiCo candidates generated from raw sources, verified by `hicod thermal check` (`index.json`, `oem/…`) | `tools/hico_generator.py`, `build.yml`, `database.yml`, `tools.yml` | GENERATED (tracked, verified) | yes, by the generator | yes | no | yes |
| `devices/` | 3,759 | 7.9 MB | Source device facts: `<vendor>/<codename>.prop` and raw thermal configs (xiaomi 3,745; samsung, oneplus, oppo, realme, motorola, google) | `tools/gen_device_db.py` → `jni/src/DeviceDatabase.gen.cpp`; `tools/hico_collector.py`, `hico_database.py`, `hico_thermal/`; tests `cli_test.sh`, `database_test.py`, `scanner_test.py`, `thermal_table_test.py`, `tests.cpp`; `build.yml` | AUTHORITATIVE | no | yes | compiled into `hicod` | yes |
| `database/devices/` | 212 | — | Generated runtime profile per device (`profile.json`) | `hico_database.py build/validate`, `database_test.py` | GENERATED | yes | yes | no | yes |
| `database/thermal/` | 191 | — | Normalised source/provenance index | `hico_database.py`, `hico_relationships.py` | GENERATED | yes | yes | no | yes |
| `database/mapped/` | 190 | — | Deterministic artifact mappings | `hico_database.py merge_mappings`, `database.yml` | GENERATED | yes | yes | no | yes |
| `database/tables/` | 4 | — | Static thermal value tables (`thermal.json`, `thermal-tuning.csv`, `thermal-artifacts.csv`, `THERMAL_TABLE.md`) | `thermal_table_test.py`, `hico_database.py validate database/tables` | AUTHORITATIVE | no | yes | no | yes |
| `database/schema/` | 8 | — | Machine-readable schemas used by validation | `hico_database.py validate`, `universal_schema_test.py` | AUTHORITATIVE | no | yes | no | yes |
| `database/universal/`, `database/index.json`, `database/README.md` | 4 | — | Universal runtime table index and docs | `hico_database.py`, tests | GENERATED / docs | yes | yes | no | yes |
| `sources/*.json` | 7 | — | Repository registry, discovery snapshot, relationships, collector state, thermal candidates, thermal filter | `hico_collector.py`, `hico_discovery.py`, `hico_relationships.py`, `hico_thermal_filter.py`, `hico_database.py`, tests, `build.yml` | AUTHORITATIVE (indexes) | partly, by collectors | yes | no | yes |
| `sources/evidence/` | 69 | — | Canonical source evidence (`github/…`, `index.json`) | `hico_evidence.py verify --root sources/evidence`, `hico_evidence_audit.py --strict`, tests | AUTHORITATIVE (evidence) | no | yes | no | yes |
| `generated/` | 7 | 1.5 KB | Two-zone skeleton (`db/`, `decoded/`, `module/`, `packed/`, `reports/`, `tuned/` README placeholders) | `docs/ARCHITECTURE.md` | DERIVED (placeholder) | yes | no | no | no |
| `jni/src/DeviceDatabase.gen.cpp` | 1 | — | Device database compiled into `hicod` | `jni/Android.mk`, CMake; `gen_device_db.py --check` in CI | GENERATED (tracked, must stay in sync) | yes | yes | **yes** | yes |

## Source, build and product

| Path | Files | Role | Consumers | Class |
|---|---|---|---|---|
| `jni/include/`, `jni/src/*.cpp` (excl. generated) | 26 + 30 | `hicod`: controller, backends (Qualcomm, MediaTek, Xiaomi), journal, SafetyGuard, FluxLink, ownership, sessions, monitor, integrity | ndk-build, CMake | AUTHORITATIVE |
| `jni/src/vendor/{ed25519,sha256}` | — | Vendored crypto with NOTICE | CMake `vendor_crypto`, ndk-build | DEPENDENCY |
| `jni/Android.mk`, `jni/Application.mk`, `CMakeLists.txt` | 3 | Device and host builds | CI | AUTHORITATIVE |
| `module/*.sh`, `module.prop`, `META-INF/` | 8 | Installer (requires Flux), boot service, uninstall, verify, action | root managers, `compile_zip.sh` | AUTHORITATIVE |
| `module/webroot/` | 7 | Built WebUI committed to the repository (`index-*.js/css`, fonts, icon) | `compile_zip.sh` copies `module/`; `verify_webui.py`; release rebuilds | GENERATED (tracked, packaged) |
| `webui/` | 108 | Vue 3 WebUI source (Monitor, Presets, Scenarios, Advanced, Log) | Bun build, `verify_webui.py` | AUTHORITATIVE |
| `tools/` | 40 | Collectors, ingest plugins, codecs, generator, database builder, evidence, signing | workflows, tests | AUTHORITATIVE |
| `tests/` | 23 | C++ unit tests, CLI test, 21 Python suites | CMake, `build.yml`, `tools.yml` | TEST |
| `docs/` | 19 | Architecture, database, evidence, integrity, release validation, phase notes | humans | AUTHORITATIVE / HISTORICAL (`docs/phase/`) |
| `.github/` | 9 | build, database, ingest, release, tools workflows; build-module action; scripts | GitHub Actions | AUTHORITATIVE (CI) |
| `version` | 1 | `1.0.0` | CMake, release | AUTHORITATIVE |
| `changelog.md` | 1 | Changelog | release | HISTORICAL |
| `LICENSE`, `EULA.md`, `NOTICE.md` | 3 | Legal; shipped in the zip | `compile_zip.sh` | AUTHORITATIVE (legal) |
| `.gitattributes` | 1 | LFS rules for `*.img`/`*.bin` under `thermal-data/` and `generated-thermal/` | git | DEPENDENCY |
| `.gitignore` | 1 | Ignores build output, collector cache, **signing keys** (`priv.hex`, `*_priv.hex`, `*.private.hex`) | git | DEPENDENCY |
| `README.md` | 1 | **Currently holds "HiCo Phase 2 Final Local Cleanup" instructions, not a project README** | humans | HISTORICAL — phase document, preserve, never remove (owner decision, Flux `DECISIONS.md` D-12) |

## Runtime data on the device (not repository data)

| Path | Producer | Consumers | Notes |
|---|---|---|---|
| `/data/adb/.config/hico/hico.conf` | WebUI / installer | `hicod`, Flux `flux_profiler.sh` (`mode=off` check) | User settings |
| `/data/adb/.config/hico/hico.log`, `sessions` | `hicod` | WebUI, Flux `save_logs` | Persistent |
| `/dev/hico/{state,journal,hicod.lock}` | `hicod` | `hicod restore`, WebUI | tmpfs: journal never outlives the boot |
| Flux files read: `/data/adb/.config/flux/{current_profile,gameinfo,.lock,synthesis_core.json,gamelist.json}`, `/data/adb/modules/flux/module.prop` | fluxd | `hicod` `FluxLink`, WebUI | Frozen contracts (Flux `DECISIONS.md` D-04) |

## UNKNOWN entries

None. (`README.md` reclassified HISTORICAL by owner decision D-12.)
