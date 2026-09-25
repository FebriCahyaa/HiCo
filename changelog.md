# HiCo Thermal Changelog

## Unreleased

### New
- **Extreme mode** (`mode=extreme`): Auto without the soft limits. The thermal HAL is stopped too
  (the throttling engine on AOSP ROMs), every Flux game runs at Max, and zones whose governor
  cannot be switched to `user_space` (common on GKI kernels) get their passive trips raised by
  up to 15 °C, always 5 °C below the zone's critical trip, with their cooling devices released.
  Battery, charger and BCL protection stay untouched; the safety guard stays on
- **Thermal overclock** (`thermal_overclock`): cpufreq boost frequencies on where the kernel has
  them (`cpufreq/boost`), and the widest trip margin for the Relaxed level. Journaled and restored
- **Templates**: `hicod config preset cool|balanced|extreme|overclock` (and in the WebUI) set the
  mode, level, safety limits and timing in one step for users who do not want to tune each key;
  `hicod config presets` lists them and the one currently matched
- **New WebUI** (Vue 3, Material 3 Expressive, same design system as Flux Tweaks): Home with the
  state, temperatures against the safety limits, mode and template; Monitor; per-game switches for
  Flux's games and a whitelist for other apps; Settings with templates, safety sliders, an
  Advanced page for every key, log, language and an About page. Every risky choice asks first with
  an explanation (info, warning or danger) and every change is confirmed with a notification
- Flux Tweaks leaves the thermal zone governors and MediaTek EARA thermal to HiCo when HiCo is
  installed, so the two never write the same node

### Fixed
- Devices on custom ROMs were not found in the device database (e.g. garnet on an AOSP ROM whose
  product properties read `lineage_garnet` or a spoofed Pixel name). The codename is now looked up
  from the bootloader (`ro.boot.hwname`), the vendor / odm / system / product device properties,
  `ro.product.name` / `mod_device` with ROM prefixes and region suffixes stripped, and the
  vendor / odm fingerprints; `hicod device` and `status` show which property matched
- The installer extracts every WebUI file of the zip (each checked against its SHA-256)

## v1.0.0

### New
- Thermal throttling is disabled automatically while a Flux game runs and restored when it
  closes: stock thermal for daily use, full clocks while gaming
- Native C++ daemon (`hicod`) driven by Flux's profile files over inotify: no polling and no Java
  process outside games
- Flux Tweaks integration: required at install time and at runtime (stock thermal and a
  notification when Flux is missing, disabled, outdated or not running)
- Temperature safety guard (CPU and battery limits, hysteresis, cooldown) with notifications
- Xiaomi / Redmi / POCO support: `mi_thermald`, thermal scene (`sconfig`) and `cpu_limits`,
  re-asserted when PowerKeeper or Joyose push them back
- Qualcomm (`thermal-engine`, `msm_thermal`, `msm_performance`, kgsl) and MediaTek (EARA) thermal
  handling; thermal services discovered from init instead of a fixed list
- Game session history: play time, unlocked time, peak temperatures, safety trips
- Real-time throttling monitor (`hicod monitor`, WebUI Monitor tab, refreshed every second):
  effective CPU cluster and GPU caps against the hardware maximum, Adreno thermal level, active
  cooling devices, zones past their trip point, 60-second chart and a throttling event log
- WebUI with Home / Monitor / Games / Settings / More tabs, English and Bahasa Indonesia: temperature gauges
  against the safety limits, one-tap mode and game level, Flux's game list with a per-game switch,
  whitelist / blacklist editors, session history, advanced options kept out of the way

- Thermal framework: core controller plus per-vendor backends (Qualcomm, MediaTek, Xiaomi)
  selected from the device's SoC and traits, and a single journaled write path
- Xiaomi device database generated from stock firmware dumps (dumps.tadiphone.dev) and compiled
  into hicod: vendor thermal services, thermal configs, model and platform per codename; the data
  stays in the repository and is never shipped as files; a workflow refreshes it through a pull request

- Thermal tuner: reads and writes vendor thermal configs and raises eligible trips per chipset
  (shutdown, battery and descending sections never changed, independent verifier); runs on the
  device and over every collected firmware config in the repository (`tools/tune_thermal.py`)
- Relaxed level: vendor thermal daemons keep running with tuned configs (bind-mounted, journaled)
- Whitelist (non-game apps, relaxed level only) and blacklist (never boosted, games included);
  `game_level` for games
- AOSP-based ROMs: ROM detection (HyperOS, MIUI, LineageOS, AOSP) shown in the installer, WebUI
  and `hicod device`; the tuner also handles the thermal HAL JSON (`thermal_info_config*.json`)
  and restarts the thermal HAL after tuning it
- Three builds: `arm64` (64-bit, including 64-bit-only ROMs), `arm` (32-bit) and `universal`,
  each with its own update channel; the installer refuses a zip that does not match the ROM

### Security
- Undo journal validated before replay; only `/sys` and `/proc` nodes are ever written
- No shell in the daemon: services via system properties, notifications via `exec`
- Range-checked settings, `0600`/`0700` runtime files, SHA-256 verification of every installed file
