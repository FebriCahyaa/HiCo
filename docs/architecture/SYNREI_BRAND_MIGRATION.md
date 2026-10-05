# Synrei Brand Migration (Phase 4.5B)

**Status:** IMPLEMENTED on the host.
**CI:** not checked.
**Device:** NOT_TESTED.

## Identity

| Name | Role |
|---|---|
| **Synrei Thermal Intelligence** | Public thermal intelligence identity (part of the Zairenkai ecosystem). |
| **HiCo** | Preserved backend / technical compatibility identity: `hicod`, `hico`, paths, module ID. |

Public name: Synrei. Internal and technical name: HiCo. A legacy identifier does not mean the
implementation is obsolete: HiCo is the live thermal backend behind Synrei. Not every technical
identifier was renamed, and none was renamed on purpose.

This phase changes only human-readable labels. The following are unchanged:
- thermal policy, polling and the state machine;
- the safety, boost, relaxed, idle, suspended and disabled semantics;
- ownership, CPU frequency control, game and daily modes;
- persistence, the state file format, the database and events.

## Migration inventory

| Old identifier | Kind | Consumers | Public / technical | Decision | Compatibility requirement | Risk if renamed |
|---|---|---|---|---|---|---|
| "HiCo Thermal" label | text | `module.prop` name, `HICO_NAME` (notification title), `hicod` usage banner, start log line, `module.prop` description status, integrity notification, `customize.sh`/`action.sh` messages, WebUI title/Home/About/description, release title/notes | public | **Rebranded** to Synrei Thermal Intelligence | none | Low |
| "HiCo Thermal" in licence text | legal | `EULA.md`, `LICENSE`, `NOTICE.md`, file headers in `jni/`, `tests/`, `tools/`, WebUI `legal_summary` | legal attribution | **Unchanged** | Legal review required first | Legal |
| "HiCo Thermal" in CI/workflow names, `changelog.md` heading | CI / history | `.github/workflows/*` names, `release.yml` changelog-heading parser, `tools/update-thermal.sh` commit text | technical / historical | Unchanged, except the public release title | Heading parser depends on `# HiCo Thermal Changelog` | Release notes break |
| module ID `hico` | module | `module.prop`; Zairenkai `flux_profiler.sh`, `flux_utility.sh`, `uninstall.sh` (`/data/adb/modules/hico`) | compatibility | **Frozen** | Upgrades, Zairenkai ownership check | Duplicate module; thermal ownership lost |
| `hicod` (binary, CLI) | executable | `CMakeLists.txt`, `service.sh`, `action.sh`, WebUI exec calls, Zairenkai `flux_utility.sh` (`status`, `zones`, `device`) and `uninstall.sh` (`hicod restore`), `cli_test.sh` | compatibility | **Frozen**; help text shows Synrei | Same commands and output format | Uninstall restore and reports break |
| `/data/adb/.config/hico` (`hico.conf`, `hico.log`, `sessions`) | user data | `HiCo.hpp`, `uninstall.sh`, Zairenkai scripts | compatibility | **Frozen**, not migrated | Existing config keys and format | User configuration loss |
| `/dev/hico/state` (also `journal`, `hicod.lock`, `thermal/`) | runtime IPC | `hicod`; Zairenkai `SynreiThermalAdapter` (`kSynreiStatePath`), WebUI | compatibility | **Frozen** | Zairenkai reads it as Synrei evidence | Zairenkai loses thermal evidence; policy blocks |
| `HICO_TAG "HiCoThermal"` | notification tag | `Daemon.cpp` notify | technical | Frozen | Replaces an existing notification | Duplicate notifications |
| Config keys and state keys (`state=`, `updated`, …) | format | `Config.cpp`, `Daemon.cpp`, WebUI, Zairenkai | technical | Frozen | Readers parse them | Readers break |
| JSON output keys (e.g. `"hico"` in thermal sources) | API | WebUI, reports | technical | Frozen | WebUI parses them | WebUI breaks |
| `updateJson` → `FebriCahyaa/HiCo-Release` | update channel | `module.prop`, `release.yml` | compatibility | Frozen | Existing installs keep receiving updates | Updates stop |
| `hico_*` tools, `hico_sign`, `hico_core`, `hico_tests` | build / tools | `CMakeLists.txt`, `tools/`, workflows | technical | Frozen | CI job names and artifacts | CI breaks |
| `database/`, `thermal-data/`, `stock/`, `sources/`, `generated*/` | protected data | tools, tests, workflows | technical | **Untouched** | Schema, records and mappings preserved | Data loss |
| `README.md` | doc | humans | historical (D-12) | Untouched | Preserve | n/a |
| `module/webroot/` (built WebUI bundle) | tracked generated | module install | intentional legacy | Not regenerated | Rebuild at next WebUI release | Old labels shown until rebuilt |

Every remaining `HiCo`/`hico`/`hicod` occurrence is classified in `docs/architecture/hico_identifiers.tsv`;
`tests/synrei_brand_test.sh` fails on any unclassified file.

## Changed files

- `jni/include/HiCo.hpp`: adds `SYNREI_PUBLIC_NAME`; `HICO_NAME` now uses it. `HICO_TAG` and all paths are unchanged.
- `jni/src/main.cpp`: usage banner and start log label.
- `jni/src/Daemon.cpp`: module description status text and the integrity notification label.
- `module/module.prop`: `name` and `description`. `id` and `updateJson` are unchanged.
- `module/customize.sh`, `module/action.sh`: user messages.
- `webui/index.html`, `webui/src/views/{Home,About}.vue`, `webui/src/locales/{en,id}.json`: title, headings and description. The legal summary is unchanged.
- `.github/workflows/release.yml`: public release title and notes heading only.
- `CMakeLists.txt`: registers `synrei_brand` test.
- New: this document, `hico_identifiers.tsv`, `tests/synrei_brand_test.sh`.

## Zairenkai integration

Zairenkai → Synrei Thermal Intelligence → HiCo backend. The contract is unchanged:
- `/dev/hico/state`;
- `/data/adb/modules/hico` (module, `disable` and `remove` markers);
- `hicod status|zones|device|restore` and their output.

There is no second daemon or backend, and no duplicated thermal logic.

## Configuration

`/data/adb/.config/hico` is not moved, overwritten or auto-migrated. A Synrei configuration namespace
would be a future, separately reviewed migration (compatibility lookup first, never a move).

## Not done

- Licence and EULA text, which needs legal review.
- CI workflow names.
- The built `module/webroot` bundle (rebuild at the next WebUI release).
- The `HiCo-Release` repository name and the HiCo GitHub repository name (infrastructure decisions).
