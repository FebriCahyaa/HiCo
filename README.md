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
- [Installation](#installation)
- [Configuration](#configuration)
- [Command line](#command-line)
- [Building and testing](#building-and-testing)
- [Releases and updates](#releases-and-updates)
- [License](#license)

---

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
- Devices whose thermal configs are encrypted cannot be relaxed: the relaxed level then keeps
  stock thermal and says so (`hicod thermal scan` shows what would be tuned).

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

`hicod` is built as a small thermal framework:

```
dumps.tadiphone.dev ─ tools/xiaomi_devices.py ─▶ devices/xiaomi/<codename>.prop ─ tools/gen_device_db.py ─▶ jni/src/XiaomiDevices.gen.cpp
  (stock vendor partitions)                      (repository data only)                                  (compiled into hicod)
```

- **Device database** — facts read from the stock firmware of each Xiaomi, Redmi and POCO device:
  codename, name, SoC platform, the thermal services its vendor init scripts declare (exact
  names, so a daemon whose name lacks "thermal" is still stopped) and its thermal configs.
  `devices/xiaomi/*.prop` is **source data in this repository only**: `gen_device_db.py`
  compiles it into a sorted C++ table inside `hicod`. Nothing from `devices/` ships in the
  module, and nothing in it is written by hand.
- **Derived facts** (`DeviceDatabase.cpp`) — the SoC vendor (`soc_from_platform`) and traits
  (`mi_thermald`, `thermal-engine`, MediaTek thermal daemons, scene configs, …) are computed in
  C++ from the raw record, so the rules live in one tested place.
- **Core** (`ThermalController`) — what every device has: init thermal services, kernel zone
  governors, cooling devices, cpufreq caps.
- **Backends** (`ThermalBackend.hpp`, `Backend<Vendor>.cpp`) — vendor drivers: Qualcomm
  (`msm_thermal`, `msm_performance`, Adreno power levels), MediaTek (EARA), Xiaomi (thermal
  scene, `cpu_limits`). A backend runs only when it applies to the device's SoC and traits, so a
  MediaTek phone never receives Qualcomm writes; devices outside the database fall back to what
  their kernel exposes.
- **Actuator** — the single write path: journaled for exact restore, restricted to `/sys` and `/proc`.

**Thermal tuner** (`ThermalConfig.cpp`, `ThermalHalJson.cpp`) — reads and writes vendor thermal
configs in both formats: thermal-engine syntax (also used by plain-text mi_thermald configs) and
the AIDL/HIDL thermal HAL JSON (`thermal_info_config*.json`, used by AOSP-based ROMs and newer
vendors). In the HAL JSON only the `HotThreshold` levels LIGHT…CRITICAL are raised; EMERGENCY and
SHUTDOWN, battery / USB / BCL / power-amplifier sensors and number formatting are left as they are,
and after a HAL config is tuned the thermal HAL is restarted so it reads it. The tuner raises eligible trips by a **chipset
policy**: Qualcomm flagship +6 °C, other Qualcomm +5 °C, MediaTek Dimensity +5 °C, other
MediaTek / Exynos / Tensor / Unisoc / unknown +4 °C (HiCo's conservative defaults, not vendor
data; `relax_margin` overrides them). Shutdown sections, battery / charger / PMIC sensors,
descending monitors and virtual sensors are never changed; no trip is lowered; skin/board trips
stop at 55 °C and CPU/GPU trips at 105 °C and 10 °C below their own shutdown threshold; trip
order and hysteresis are kept. An independent verifier re-checks every tuned file before use.
The same code runs on the device (relaxed level) and in the repository:
[`tools/tune_thermal.py`](tools/tune_thermal.py) tunes every collected config with the host
build of `hicod` into `devices/xiaomi/<codename>/tuned/` and writes
[`docs/THERMAL_TUNING.md`](docs/THERMAL_TUNING.md); any verifier violation fails the workflow.

`hicod device` shows how the running phone is handled (database record, SoC, traits, backends);
`hicod device --list` prints the compiled database. The supported list is
[`docs/DEVICES.md`](docs/DEVICES.md).

**Thermal files:** the scanner also keeps each device's vendor thermal configuration files in
`devices/xiaomi/<codename>/thermal/` (repository only, never shipped), with an `index.tsv`
(SHA-256, size, format, trip points). Plain-text thermal-engine style files are parsed for their
highest trip and their shutdown threshold (`vendor_max_trip_c`, `vendor_shutdown_c` in the
record); encrypted files — common on recent Xiaomi firmware — are kept and counted but not
interpreted. Pre-Treble firmware is covered too (`system/etc`, `system/vendor/etc`).

**Refreshing the database:** **Actions → Update Xiaomi device profiles** (also monthly) scans
the Xiaomi, Redmi and POCO dump groups (`dumps/xiaomi`, `dumps/redmi`, `dumps/poco`; groups that
do not exist are skipped), regenerates `devices/`, `docs/DEVICES.md` and the C++ table, builds and tests it, and
opens a pull request. By default it uses **sparse mode**: the GitLab API only lists the dumps
(names), then each dump is partial-cloned (`--filter=blob:none --depth 1`) and only `build.prop`
and the vendor thermal files (`vendor/etc/thermal*`, `vendor/etc/init/*thermal*`,
`vendor/etc/init/hw/*.rc`) are checked out — a few MB per device instead of the whole firmware.
A server that ignores the filter is refused rather than downloaded in full. CI fails when the
compiled table is out of date with `devices/` (`gen_device_db.py --check`).

## ROMs: MIUI, HyperOS and AOSP

`hicod` detects the ROM family (`hicod device`, WebUI, installer): **HyperOS**
(`ro.mi.os.version.name`), **MIUI** (`ro.miui.ui.version.name`), **LineageOS**
(`ro.lineage.version`) and any other **AOSP-based** ROM (crDroid, PixelOS, Evolution X, …).
Everything that is not Xiaomi-specific works the same on all of them: init thermal services,
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

**WebUI** (KernelSU, APatch, MMRL, WebUI X), in English or Bahasa Indonesia:
- **Home** — status, CPU / GPU / battery gauges against the safety limits, one-tap mode and game
  level, what is currently changed, device / chipset / ROM / Flux
- **Monitor** — real-time throttling, refreshed every second (see below)
- **Games** — Flux's game list with a per-game switch (blacklist), other apps (whitelist), history
- **Settings** — the safety limits up front; every other option under *Advanced*
- **More** — restart or restore stock thermal, log, about

The action button (Magisk) toggles HiCo between automatic and off.

## Configuration

`/data/adb/.config/hico/hico.conf`, edited through the WebUI or `hicod config set`. Changes apply
immediately.

| Key | Default | Range | Description |
|---|---|---|---|
| `mode` | `auto` | auto / off | `off` keeps stock thermal everywhere |
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
hicod config list|get|set|reset|schema
hicod sessions [clear]     session history (JSON Lines: duration, unlocked time, peaks, trips)
hicod zones                zones, cooling devices and thermal services on this device
hicod monitor [--once] [--interval S]   live throttling, one line per second (Ctrl-C to stop)
hicod monitor --json       one throttling snapshot (the WebUI Monitor tab polls it every second)
hicod device [--list]      this device in the compiled database (SoC, traits, backends), or the whole database
hicod thermal scan         this device's thermal configs and what the relaxed level would tune
hicod thermal tune <file> [--platform P] [--margin N]    tuned config on stdout (repository tooling)
hicod thermal check <original> <tuned> [--platform P]   independent safety verification
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
