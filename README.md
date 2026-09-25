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
- [Xiaomi device profiles](#xiaomi-device-profiles)
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
| **Boost** | Flux runs a game (Performance, and Performance Lite unless disabled) | Unlocked |
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

## Xiaomi device profiles

HiCo adapts to each device at runtime (services from `init.svc.*`, zones and cooling devices
from `/sys/class/thermal`). On top of that, Xiaomi, Redmi and POCO devices get a **profile read
from their own stock firmware**:
[`tools/xiaomi_devices.py`](tools/xiaomi_devices.py) scans the vendor partition of every dump on
[dumps.tadiphone.dev/dumps/xiaomi](https://dumps.tadiphone.dev/dumps/xiaomi) and records the
codename, model, SoC platform, the thermal services declared in the vendor's thermal init scripts
(exact names, so a thermal daemon whose name does not contain "thermal" is still stopped) and
the thermal configuration files it ships.

- Profiles: [`devices/xiaomi/`](devices/xiaomi), one `<codename>.prop` each, with the URL of the
  dump it came from. Nothing is written by hand.
- Supported list: [`docs/DEVICES.md`](docs/DEVICES.md).
- Refresh: **Actions → Update Xiaomi device profiles** (also monthly) opens a pull request.
- The installer copies only this phone's profile (checksum-verified); `hicod status` and the
  WebUI show `verified` or `generic`.


1. Install **[Flux Tweaks](https://github.com/FebriCahyaa/Flux/releases) v1.2.0 or newer** first.
2. Flash `hico-*.zip` in Magisk, KernelSU or APatch and reboot.
3. Play: games from Flux's game list unlock thermal automatically. Open HiCo's WebUI for live
   temperatures, settings and your session history.

The action button (Magisk) toggles HiCo between automatic and off.

## Configuration

`/data/adb/.config/hico/hico.conf`, edited through the WebUI or `hicod config set`. Changes apply
immediately.

| Key | Default | Range | Description |
|---|---|---|---|
| `mode` | `auto` | auto / off | `off` keeps stock thermal everywhere |
| `unlock_on_lite` | `1` | | Also unlock in Flux's Performance Lite |
| `excluded_games` | | packages | Games that never unlock |
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

## Command line

```
hicod status [--json]      state, temperatures, Flux link
hicod restore              stop the service and restore stock thermal now
hicod flux                 check the Flux dependency
hicod config list|get|set|reset|schema
hicod sessions [clear]     session history (JSON Lines: duration, unlocked time, peaks, trips)
hicod zones                zones, cooling devices and thermal services on this device
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
only what users need: the flashable zip (GitHub Release), `update.json`, `changelog.md`,
`EULA.md` and a README. `module.prop` points `updateJson` there, so Magisk, KernelSU and APatch
show **Update** with the changelog and download the zip directly.

One-time setup:
1. Create the public repository `FebriCahyaa/HiCo-Release` (an initial README commit is enough).
2. Create a fine-grained personal access token limited to that repository with
   **Contents: Read and write**, and add it to this repository as the secret `RELEASE_TOKEN`.

Then run **Actions → Release** with a version (e.g. `1.0.1`). The workflow builds and tests the
module, creates release `v1.0.1` in HiCo-Release with the zip and its SHA-256, and commits the
new `update.json` and changelog there. Pre-releases are not offered as updates.

## License

HiCo Thermal is **private, proprietary software** — © 2026 FebriCahyaa, all rights reserved. Use
is governed by the [EULA](EULA.md) (English and Bahasa Indonesia), accepted when installing.
Third-party components keep their own licenses, listed in [NOTICE.md](NOTICE.md).
