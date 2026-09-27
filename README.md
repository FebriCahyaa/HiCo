# HiCo Thermal

<p align="center">
  <b>Automatic thermal unlock for games, part of the Flux ecosystem</b><br/>
  Magisk · KernelSU · APatch · arm64 / arm · requires <a href="https://github.com/FebriCahyaa/Flux">Flux Tweaks</a><br/>
  Private software · <a href="EULA.md">EULA</a>
</p>

HiCo Thermal disables thermal throttling **only while you play**. As soon as Flux Tweaks puts a
game in the foreground, HiCo lifts the thermal limits so the CPU and GPU can hold their maximum
clocks; when the game closes, every stock thermal setting is put back, so daily use never
overheats. A temperature guard stays on the whole time and hands control back to the stock
thermal stack if the device gets too hot.

- [How it works](#how-it-works)
- [What is unlocked](#what-is-unlocked)
- [Safety](#safety)
- [Thermal framework and device database](#thermal-framework-and-device-database)
- [Knowledge database ingestion and tools](#knowledge-database-ingestion-and-tools)
- [Installation](#installation)
- [Configuration](#configuration)
- [Command line](#command-line)
- [Building and testing](#building-and-testing)
- [Releases and updates](#releases-and-updates)
- [License](#license)

---

## Thermal Monitor

`hicod monitor` is a read-only thermal monitor. It reports all readable kernel thermal zones, temperatures, passive/hot/critical trip thresholds, the highest and next trip, headroom, current thermal state, protected zones, active cooling devices and the active thermal policy. It does not report or control CPU/GPU clocks, scheduler settings, network, memory, I/O, game tuning or other performance tweaks.

`hicod thermal table` prints the same live thermal data as a terminal table; `hicod thermal table --json` emits the monitor snapshot in machine-readable form. The WebUI Monitor uses the same JSON source and presents the full thermal-zone table.

The repository also contains `database/tables/thermal.json`, `thermal-artifacts.csv`, `thermal-tuning.csv` and `THERMAL_TABLE.md`. These distinguish the original highest trip value observed in source data from the HiCo candidate produced by the device-specific tuning rules. Candidate values are planning/tuning outputs, not measured or certified safety limits.

## How it works

```
 Flux Tweaks (fluxd)                          HiCo Thermal (hicod)
 game list, focus, PID, screen ──writes──▶  current_profile + gameinfo ──inotify──▶ state machine
                                                                                    │
                   Idle ── game ──▶ Boost ── too hot ──▶ Safety                     │
                    ▲                 │  ◀── cooled down ──┘                         ▼
                    └── game left ────┘                         thermal layer (journaled)
```

| State | When | Thermal |
|---|---|---|
| **Idle** | No game | Stock |
| **Boost** | Flux runs a game with `game_level=max` (default) | Unlocked |
| **Relaxed** | A game with `game_level=relaxed`, a Performance Lite game with `unlock_on_lite=0`, or a **whitelisted** app | Vendor thermal running with configs tuned for the chipset |
| **Safety** | A game runs but CPU or battery reached its limit | Stock until it cools down |
| **Suspended** | Flux is missing, disabled, outdated or not running | Stock |
| **Disabled** | `mode=off` | Stock |

**Modes:** `auto` (default) unlocks as above; `extreme` is Auto without the soft limits — the
thermal HAL is stopped too, every game runs at max, and zones that cannot switch to the
`user_space` governor (common on GKI kernels) get their passive trips raised (by up to 15 °C,
always 5 °C below the zone's critical trip) and their cooling devices released; `off` never
unlocks. The safety guard applies in every mode.

HiCo does not detect games on its own: **Flux Tweaks is required.** Flux already tracks the
foreground app, the game list, the game's PID and the screen state; HiCo watches the two files
fluxd writes on every profile change (`current_profile`, `gameinfo`) with `inotify`, so it costs
nothing between games — no polling, no Java process. The installer refuses to install without
Flux, and at runtime HiCo keeps stock thermal (and says so in the module description and a
notification) whenever Flux is not ready.

Inside the ecosystem the work is split cleanly: **Flux** owns performance profiles (governors,
frequencies, GPU, scheduler, I/O); **HiCo** owns the thermal layer on top of it.

## What is unlocked

Every change is appended to an undo journal (on tmpfs, `/dev/hico/journal`) **before** it is made,
and replayed to restore the exact original values.

| Layer | While gaming | Notes |
|---|---|---|
| Thermal daemons | Stopped through init (`ctl.stop`) | Found from `init.svc.*`: `thermal-engine`, `vendor.thermal-engine`, `mi_thermald`, `thermald`, … Only services that were running are restarted afterwards |
| Thermal HAL | Kept (optional) | Stopping it breaks Android's thermal API, which Flux uses for Performance Lite |
| Kernel thermal zones | `user_space` governor | Battery, charger, PMIC and BCL zones are never touched; the kernel still handles **critical trips** |
| Cooling devices | Released (`cur_state 0`) | Except those bound to battery zones or zones that stay throttled |
| CPU clock | `scaling_max_freq` kept at `cpuinfo_max_freq` | Plus Qualcomm `msm_performance` caps |
| GPU | kgsl `thermal_pwrlevel` / `max_pwrlevel` → 0 | |
| Qualcomm / MediaTek | `msm_thermal`, core control, EARA thermal | Legacy and current kernels |
| Xiaomi / Redmi / POCO | `thermal_message/sconfig` game scene, `cpu_limits` cleared | Re-asserted every poll, as PowerKeeper / Joyose write them back |

Vendor daemons that push limits back mid-game are overridden on the next poll (every 2 s while
gaming).

## Levels, whitelist and blacklist

| Level | Who | What happens |
|---|---|---|
| **max** | Games only (Flux game list), `game_level=max` | Thermal throttling disabled (table above), safety guard on |
| **relaxed** | Games with `game_level=relaxed`, Performance Lite with `unlock_on_lite=0`, whitelisted apps | The vendor thermal daemons **keep running**; their plain-text configs are tuned for the chipset (trips raised, shutdown untouched), bind-mounted over the stock files and the daemons restarted to load them |
| stock | Everything else | Nothing changed |

- **Whitelist** (`whitelist`): apps that are not games but should get more headroom (camera,
  video editor, emulator, …). They never reach the max level — only games do.
- **Blacklist** (`blacklist`): packages that are never boosted, games included. It wins over
  the game list and the whitelist.
- Encrypted mi_thermald configs (recent Xiaomi firmware) are decrypted, tuned and encrypted again
  (mi_thermald only loads encrypted files). `hicod thermal scan` shows what would be tuned.

**mi_thermald templates.** mi_thermald configs describe each limit as a section with rising
`trig` and release `clr` thresholds and a `target` per step (a CPU frequency, a GPU level, ...),
one file per scene (normal, tgame, mgame, nolimits, camera, ...). HiCo tunes only the sections
that cost performance (`cpuN`, `gpu`, `hotplug_cpuN`, `boost_limit`): trig and clr move up
together by the chipset margin, **never above the highest trip the phone's own configs use for
that limit and sensor** (normally its nolimits or game scene) nor the 55 °C skin / 105 °C CPU
caps; targets are never changed. Battery / charging, brightness, torch, modem, wifi, temp_state
and download-limit sections, battery sensors and descending thresholds stay stock. Example,
garnet `thermal-tgame.conf` at the Relaxed level: CPU4 46/47/48 °C → 49/50/51 °C (Xiaomi's own
nolimits trip is 51 °C), GPU 45/46 °C → 47/48 °C, boost_limit unchanged (already at its ceiling).
Every device's template is generated in the repository (`devices/xiaomi/<codename>/tuned/TEMPLATE.md`,
[docs/THERMAL_TUNING.md](docs/THERMAL_TUNING.md)); on the phone the same code builds it from the
phone's own files.

## Safety

- **Temperature guard** — CPU (hottest CPU zone) and battery temperatures are checked every
  `poll_interval` seconds while gaming. At `safety_cpu_temp` (default 95 °C) or
  `safety_battery_temp` (default 46 °C) the stock thermal stack is restored immediately and a
  notification is posted. Unlocking resumes only after the device cooled by the hysteresis margin
  *and* the cooldown elapsed, so it never oscillates.
- **No blind unlock** — without a readable temperature sensor, HiCo keeps stock thermal.
- **Hardware protection untouched** — zones are never disabled, only their governor changes, so
  critical-trip shutdown keeps working; battery/charging protection is never modified.
- **Crash safe** — a stopped or crashed daemon leaves its journal on tmpfs; the next start,
  `hicod restore`, uninstall (HiCo's or Flux's) replay it. A reboot always starts from stock.
- **Hardened** — only `/sys` and `/proc` nodes are written (no `..`, no symlinks), services are
  controlled through properties (no shell), journal entries are validated before replay, config
  values are range-checked, runtime files are `0600` in `0700` directories, the installer checks
  the SHA-256 of every file.

## Thermal framework and device database

`hicod` is the runtime thermal framework. The repository-side dataset is kept separate from the
runtime device table so the same hardware can have multiple stock and custom-ROM thermal sources
without collapsing their provenance.

```text
Public OEM / ROM / vendor / kernel repositories
                      │
                      ▼
               local collector
                      │
          clone / fetch without API tokens
                      │
                      ▼
                thermal-data/
                      │
             ┌────────┴────────┐
             ▼                 ▼
          raw files         manifests
             │                 │
             └────────┬────────┘
                      ▼
              HiCo Thermal parser
                      │
             detect / decode / map
                      │
                      ▼
              HiCo Thermal generator
                      │
                      ▼
               generated-thermal/
                      │
                 independent check
                      │
                      ▼
                  database/
```

- **Runtime device database** — `devices/xiaomi/*.prop` remains the compatibility table compiled by `gen_device_db.py`.
- **Canonical thermal source dataset** — `thermal-data/` stores original thermal-relevant files plus provenance. The collector records repository, branch, exact commit, OEM, ROM family, device, Android release and repository role.
- **Generated HiCo Thermal** — `generated-thermal/` contains candidates produced by the same host `hicod thermal tune` implementation used by the runtime. Original files are never modified.
- **Knowledge database** — `database/` indexes normalized device facts, source provenance, mappings and generated thermal candidates.

**Thermal tuner** (`ThermalConfig.cpp`, `ThermalHalJson.cpp`) supports the vendor formats implemented by
HiCo: thermal-engine text, `mi_thermald`, Xiaomi encrypted `MiCrypt` configs and AIDL/HIDL thermal HAL JSON.
The safety verifier checks the original-versus-candidate transformation before a generated file can be
marked valid. Shutdown/critical protection, battery/charger/PMIC scopes and other protected sections remain
subject to the engine's explicit policy.

`tools/hico_thermal.py` provides detect/decode/unpack/pack/map operations. `tools/hico_collector.py`
provides the token-free local collection path, while `tools/hico_generator.py` builds and verifies HiCo
thermal candidates from the collected source files.

**Thermal files:** the legacy Xiaomi device data under `devices/xiaomi/<codename>/thermal/` is retained for
runtime compatibility. The canonical multi-source dataset is `thermal-data/`, where paths are organized as
`ecosystem/vendor/rom/device/android/role/repository/raw/` and each repository has a `manifest.json`.

## Local thermal collection and generation

Normal synchronization deliberately does **not** call the GitHub or GitLab REST APIs. It uses a local
repository index and public Git remotes, so public sources can be cloned/fetched without API tokens.
The cache is outside the repository by default (`~/.cache/hico/repos`); only the thermal-relevant files
and their manifests are committed to HiCo.

First bootstrap the known public repositories already represented by the seeded device database:

```shell
python3 tools/hico_collector.py bootstrap
python3 tools/hico_collector.py import-legacy
```

Synchronize the source dataset:

```shell
python3 tools/hico_collector.py sync --changed-only --workers 4
```

Then build the host engine and generate candidates:

```shell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j"$(nproc)"
python3 tools/hico_generator.py generate --hicod build/hicod --workers 4
```

The complete local pipeline is wrapped by:

```shell
./tools/update-thermal.sh
```

Use `./tools/update-thermal.sh --push` to commit and push the collected thermal dataset, generated
candidates and regenerated database after all validation steps pass. The default commit message is
`data(thermal): refresh collected sources and generate HiCo thermal`.

## Knowledge database ingestion and tools

The collection layer is intentionally broader than Xiaomi. `sources/registry.json` describes OEM dump
groups, custom-ROM device organizations and generic independent sources. `sources/repositories.json` is
the concrete repository index used by the local collector. It is seeded from the currently known Xiaomi
source records and can later be extended from additional discovery snapshots.

The data layers are deliberately explicit:

```text
sources/                 repository definitions and collector state
thermal-data/            original thermal source files + manifests
generated-thermal/       HiCo-generated candidates + verification reports
database/                normalized indexes, mappings and tables
devices/                 legacy/runtime Xiaomi compatibility data
```

Unknown encrypted or opaque artifacts remain available as raw source material when their size is compatible
with repository storage, while their parser/codec status is recorded. HiCo never guesses an encryption
algorithm. Large firmware-style blobs can use Git LFS when the clone is configured for it.

### Actions

**Actions → HiCo Thermal Database** is now a verification/build workflow only. It reads the committed
`thermal-data/` and `generated-thermal/` dataset, builds the host engine, runs the test suite, rebuilds the
database deterministically and uploads the verification artifact. It does not discover or clone upstream
repositories and does not write cloud infrastructure.

**Actions → HiCo Thermal Tools** validates the parser/codec/unpack/map toolchain and can perform a full mapping
of the thermal roots already committed to the repository.

The existing `webui/` directory remains protected by its SHA-256 integrity manifest and is validated as part
of the normal tool/build workflows.

## ROMs: MIUI, HyperOS and AOSP

`hicod` detects the ROM family (`hicod device`, WebUI, installer): **HyperOS**
(`ro.mi.os.version.name`), **MIUI** (`ro.miui.ui.version.name`), **LineageOS**
(`ro.lineage.version`) and any other **AOSP-based** ROM (crDroid, PixelOS, Evolution X, …).
The device is found in the database even when a custom ROM renames the product properties
(`lineage_garnet`, `garnet_global`, a Pixel name spoofed for Play Integrity): the codename is
looked up from `ro.boot.hwname`, the vendor / odm / system / product device properties,
`ro.product.name` / `mod_device` without ROM prefixes or region suffixes, and the vendor / odm
fingerprints. Everything that is not Xiaomi-specific works the same on all of them: init thermal services,
kernel zones, cooling devices, cpufreq, Qualcomm / MediaTek backends and the thermal tuner, which
also handles the thermal HAL JSON most AOSP ROMs ship. The Xiaomi backend (thermal scene,
`cpu_limits`) only acts where those nodes exist, so it is inert on AOSP ROMs without them. On a
custom ROM the database record describes the device's stock firmware; `hicod device` says so.

## Installation

1. Install **[Flux Tweaks](https://github.com/FebriCahyaa/Flux/releases) v1.2.0 or newer** first.
2. Flash the zip for your ROM in Magisk, KernelSU or APatch and reboot:

   | Zip | For |
   |---|---|
   | `hico-*-arm64.zip` | 64-bit ROMs (arm64-v8a), including **64-bit-only** AOSP ROMs without a 32-bit userspace |
   | `hico-*-arm.zip` | 32-bit ROMs (armeabi-v7a) |
   | `hico-*-universal.zip` | Both; the installer picks the right binary |

   The installer shows the ROM's ABIs and refuses a zip that does not match, naming the right one.
   Each zip has its own update channel (`update-arm64.json`, `update-arm.json`, `update.json`), so
   the root manager keeps offering the same build.
3. Play: games from Flux's game list unlock thermal automatically.

**Which games?** HiCo does not guess: it follows fluxd, which boosts the focused app only when it
is in Flux's `gamelist.json`. Flux builds that file at install from its `gamelist.txt` database
(about 530 known game packages, kept only if installed) and you add or remove games in the Flux
WebUI. HiCo never edits Flux's list; its own **blacklist** can switch a Flux game off for HiCo, and
the **whitelist** gives non-game apps the relaxed level only.

**WebUI** (KernelSU, APatch, MMRL, WebUI X), in English or Bahasa Indonesia, built with Vue 3 in
the same Material 3 Expressive design as Flux Tweaks (source in `webui/`, built into
`module/webroot/` with `cd webui && bun install && bun run build`):
- **Home** — state and what is changed right now, CPU / GPU / battery against the safety limits,
  mode (Off / Auto / Extreme), current template, device (database record and the property the
  codename came from), chipset, ROM, Flux
- **Monitor** — real-time throttling, refreshed every second while on screen (see below)
- **Games** — Flux's games with a per-game switch (blacklist) and other apps (whitelist)
- **Settings** — templates, game level, thermal overclock, safety sliders, *Advanced* (every
  key), log, language, restart / restore / reset, **About**

Risky choices (Extreme, templates, overclock, high safety limits, stopping the HAL, reset) ask
first with an explanation; every change is confirmed with a notification.

The action button (Magisk) toggles HiCo between automatic and off.

## Configuration

`/data/adb/.config/hico/hico.conf`, edited through the WebUI or `hicod config set`. Changes apply
immediately.

**Templates** set the mode, level, safety limits and timing in one step (lists are kept):

| Template | Mode | Level | Overclock | CPU / battery limit | Poll |
|---|---|---|---|---|---|
| `cool` | auto | relaxed (no unlock in Lite) | off | 88 / 43 °C | 2 s |
| `balanced` (defaults) | auto | max | off | 95 / 46 °C | 2 s |
| `extreme` | extreme | max | off | 100 / 48 °C | 1 s |
| `overclock` | extreme | max | on, relax margin 10 | 102 / 49 °C | 1 s |

`hicod config preset <name>` applies one; `hicod config presets` lists them (JSON) with the one
the current settings match.

| Key | Default | Range | Description |
|---|---|---|---|
| `mode` | `auto` | auto / extreme / off | `extreme`: Auto without soft limits; `off` keeps stock thermal everywhere |
| `thermal_overclock` | `0` | | cpufreq boost frequencies on and the widest relaxed trip margin |
| `unlock_on_lite` | `1` | | Also unlock in Flux's Performance Lite |
| `game_level` | `max` | max / relaxed | Level for Flux games |
| `whitelist` | | packages | Non-game apps that get the relaxed level (never max) |
| `blacklist` | | packages | Never boosted, games included (was `excluded_games`) |
| `relax_margin` | `0` | 0–10 °C | Relaxed level trip raise; 0 = chipset default |
| `stop_thermal_services` | `1` | | Stop userspace thermal daemons |
| `stop_thermal_hal` | `0` | | Also stop the thermal HAL |
| `zone_governor` | `1` | | Kernel zones → `user_space` |
| `cooling_reset` | `1` | | Release CPU/GPU cooling devices |
| `cpu_clock_unlock` | `1` | | Keep max CPU clock at hardware max |
| `gpu_unlock` | `1` | | Lift GPU thermal caps |
| `vendor_tweaks` | `1` | | Qualcomm / MediaTek drivers |
| `xiaomi_tweaks` | `1` | | Xiaomi thermal scene and CPU limits |
| `xiaomi_sconfig` | `10` | 0–30 | Xiaomi thermal scene while gaming |
| `safety_cpu_temp` | `95` | 70–105 °C | CPU limit |
| `safety_battery_temp` | `46` | 38–52 °C | Battery limit |
| `safety_cpu_hysteresis` | `10` | 3–25 °C | Cool-down margin before unlocking again |
| `safety_battery_hysteresis` | `3` | 1–10 °C | |
| `safety_cooldown` | `30` | 5–600 s | Minimum protection time after a trip |
| `poll_interval` | `2` | 1–10 s | Check period while gaming |
| `exit_delay` | `3` | 0–30 s | Grace period after the game leaves |
| `notify` | `1` | | Notifications |
| `log_level` | `2` | 0–3 | error, warning, info, debug |

## Throttling monitor

`hicod monitor` shows what the kernel **actually allows right now**, read-only, whether HiCo is
unlocked or not:

| Signal | Source | Throttling when |
|---|---|---|
| CPU clusters | `cpufreq/policyN`: `scaling_cur_freq`, `scaling_max_freq`, `cpuinfo_max_freq` | the effective cap (`scaling_max_freq`, after every thermal / QoS request) is below the hardware maximum |
| GPU | Adreno `kgsl-3d0` (`gpuclk`, power-level table, `thermal_pwrlevel`, `max_pwrlevel`) or the GPU `devfreq` device (Mali / MediaTek / Exynos) | the cap is below the fastest level, or the Adreno thermal level is above 0 |
| Cooling devices | `cooling_deviceN/cur_state` | a CPU / GPU cooling device is above state 0 |
| Thermal zones | `trip_point_N_type` / `_temp` | the zone is at or past its lowest passive / hot trip (battery zones are shown, never counted) |

The verdict is **none** (everything at hardware maximum), **light** (every cap ≥ 80 %) or
**heavy**. The CPU figure is weighted by core count. In the WebUI the Monitor tab refreshes every
second while it is on screen: verdict, allowed CPU / GPU speed, a 60-second chart of allowed speed
and temperatures, a bar per cluster and GPU showing current clock, cap and the part lost to
throttling, active cooling devices, zones past their trip, and a log of every cap that appears,
changes or lifts. Nothing is stored; polling stops when the tab or the WebUI is closed.

## Command line

```
hicod status [--json]      state, temperatures, Flux link
hicod restore              stop the service and restore stock thermal now
hicod flux                 check the Flux dependency
hicod config list|get|set|reset|schema|preset <name>|presets
hicod sessions [clear]     session history (JSON Lines: duration, unlocked time, peaks, trips)
hicod zones                zones, cooling devices and thermal services on this device
hicod monitor [--once] [--interval S]   live throttling, one line per second (Ctrl-C to stop)
hicod monitor --json       one throttling snapshot (the WebUI Monitor tab polls it every second)
hicod device [--list]      this device in the compiled database (SoC, traits, backends), or the whole database
hicod thermal scan         this device's thermal configs and what the relaxed level would tune
hicod thermal tune <file> [--platform P] [--margin N]    tuned config on stdout (repository tooling)
hicod thermal check <original> <tuned> [--platform P]   independent safety verification
hicod thermal decrypt <in> [out]     encrypted mi_thermald config -> text
hicod thermal encrypt <in> <out>     text -> encrypted mi_thermald config
```

Files: `/data/adb/.config/hico/` (settings, `hico.log`, `sessions`), `/dev/hico/` (live state,
journal, lock).

## Building and testing

```shell
ndk-build -j"$(nproc)"                        # Android binary (NDK r29), libs/<abi>/hicod

cmake -S . -B build && cmake --build build     # host build
ctest --test-dir build --output-on-failure     # unit + end-to-end tests
```

The host build redirects every device path under `$HICO_ROOT` (ignored on Android), so the tests
run the real daemon — inotify, epoll, signals — against a simulated Snapdragon/Xiaomi device with
Flux installed. CI runs them under AddressSanitizer and UBSan, then builds the flashable zip.
See [Releases and updates](#releases-and-updates) for publishing.

## Releases and updates

The source repository is private, and root managers cannot read files from a private repository
(no token may ever ship inside the module). Releases are therefore published to the **public**
repository [FebriCahyaa/HiCo-Release](https://github.com/FebriCahyaa/HiCo-Release), which holds
only what users need: the flashable zips (GitHub Release: arm64, arm and universal), one
`update*.json` per zip, `changelog.md`,
`EULA.md` and a README. `module.prop` points `updateJson` there, so Magisk, KernelSU and APatch
show **Update** with the changelog and download the zip directly.

One-time setup:
1. Create the public repository `FebriCahyaa/HiCo-Release` (an initial README commit is enough).
2. Create a fine-grained personal access token limited to that repository with
   **Contents: Read and write**, and add it to this repository as the secret `RELEASE_TOKEN`.

Then run **Actions → Release** with a version (e.g. `1.0.1`). The workflow builds and tests the
module, creates release `v1.0.1` in HiCo-Release with the three zips and their SHA-256, and commits the
new `update.json`, `update-arm64.json`, `update-arm.json` and changelog there. Pre-releases are not offered as updates.

## License

HiCo Thermal is **private, proprietary software** — © 2026 FebriCahyaa, all rights reserved. Use
is governed by the [EULA](EULA.md) (English and Bahasa Indonesia), accepted when installing.
Third-party components keep their own licenses, listed in [NOTICE.md](NOTICE.md).
