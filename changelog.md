# Unreleased

### Tamper detection: signed releases, runtime self-check, revocation list
- **Signed release manifest** (`docs/INTEGRITY.md`): releases are now Ed25519-signed, not just
  SHA-256-checksummed. `tools/sign_release.py` + `hico_sign` (offline, `HICO_INTEGRITY_PRIVATE_KEY`
  in `release.yml`) sign `system/bin/hicod`, every install/service script, the untouched
  `module.prop.orig` and the WebUI's aggregate hash; `hicod` verifies the signature against the
  public key compiled into it (`jni/include/IntegrityKey.hpp`) at every start and every 30 minutes
  while it runs. A mismatch blocks every thermal unlock, fail-safe to stock — never destructively.
  A build shipped without a manifest (an older release, or CI without the signing secret) is
  treated as unsigned, not as tampered. New `hicod integrity [--json]` command; the WebUI shows
  the same via `hicod thermal sources`.
- **Runtime signals**: `TracerPid` and known hook/injection library names in `/proc/self/maps` are
  logged and shown in status, informational only (too many legitimate explanations to act on alone).
- **Revocation list** (`docs/integrity/revoked.txt`): a small public file this project's own
  GitHub repository hosts; `hicod` fetches it at most once a day (best-effort, hard-bounded
  timeout, a plain anonymous request — see `EULA.md` §7) to check whether this exact, validly-signed
  build was later published as compromised (a leaked key, a build published by mistake, a
  redistributed cracked copy). New config key `check_revocation` (default on).
- Vendored: `jni/src/vendor/ed25519/` (Ed25519, Orson Peters, zlib) and `jni/src/vendor/sha256/`
  (SHA-256, Brad Conte, public domain, verified against the FIPS 180-2 test vectors).

### Thermal per scenario
- **Scenarios** page (replaces Games): pick the thermal per scenario. **Games**: OEM / HiCo
  Balanced / HiCo Aggressive; **Social media** and **Multimedia**: OEM / HiCo Balanced (never
  Aggressive). OEM keeps the ROM's thermal untouched; Balanced mounts the chipset-tuned copy of the
  vendor's own configs while the app is on screen and puts the stock files back 20 s after leaving
  it (at once when the screen turns off). New config keys `social_level`, `media_level`,
  `social_apps`, `media_apps` (common apps pre-listed), `game_level=stock`. Sessions record the scenario.
- **Monitor → Thermal sources** (`hicod thermal sources [--json]`): the phone's thermal configs
  (format, size, vendor or HiCo tuned copy), thermal daemons / HAL (stopped or reloaded by HiCo),
  device, chipset, ROM and whether the device database has a verified profile.
- Daily preset now also sets Social media and Multimedia to HiCo Balanced.

### More devices: ROM org vendor blobs, MediaTek
- New ingest source `rom-vendor-blobs` (provider `vendor-probe`): the `vendor_<oem>_<codename>`
  repositories that ArrowOS, crDroid, AlphaDroid, DotOS and others keep next to their device trees,
  probed with `git ls-remote` from the device-tree manifests, only for devices TheMuppets does not
  cover. 100 repositories found, 40 with stock thermal files (Xiaomi / Redmi, Realme, OPPO, OnePlus,
  MediaTek and older devices).
- Vendor blob paths now include MediaTek's thermal policies (`vendor/etc/.tp/`: thermal.conf,
  .thermal_policy_NN, .ht120.mtc) and `powerhint*.xml`; TheMuppets refetched with them.
- `hicod thermal sources` and the Monitor list MediaTek thermal policies as "MediaTek thermal policy"
  (read-only: the vendor obfuscates them, HiCo does not tune them).

### Stock thermal dataset and delta-only ingest
- `stock/` now holds the thermal-relevant files of 2,400+ custom-ROM device trees (LineageOS,
  crDroid, LMODroid, AOSPA, ArrowOS, DotOS, AlphaDroid, PixelOS, ProtonAOSP, AwakenOS) and the
  stock vendor thermal blobs of 209 devices / common trees from TheMuppets (Xiaomi, Motorola,
  Samsung, OnePlus, Google, LG, Sony, Nubia, Realme, …), each with a `source.json` recording the
  upstream commit and every file's SHA-256.
- `ingest.yml` fetches only what moved upstream: `pushed_at` first, then one `git ls-remote` per
  candidate against the commit in `stock/manifest/<source>.state.json`. The fetch matrix comes
  from the change set; fetched data travels as artifacts and `tools/ingest/merge_fetch.py` merges
  it (removed repositories and trees that lost their thermal files are cleaned up, failed ones keep
  their last good copy). Fixed: the old diff never saw a change, manifests were not passed between
  jobs, common trees were dropped, the DerpFest / Evolution X orgs were wrong, PR failures were hidden.
- New `repo-manifest` provider (TheMuppets `muppets.xml`, newest LineageOS branch per repository,
  no API quota) and `blob_paths` for vendor blobs. `tests/ingest_test.py` covers the cycle offline.
- **Daily preset**: social media, streaming and general use. The vendor thermal system stays in
  charge; foreground games get the Relaxed level only; safety 85 °C CPU / 42 °C battery.

# Unreleased

### Thermal monitor scope guard
- Monitor telemetry now exposes all discovered cooling devices as thermal state, with active/idle status and counts.
- Added a regression guard that rejects Flux/Tweaks/game/performance identifiers from the thermal monitor/tooling surfaces.
- `tools.yml` remains a thermal database/tooling workflow only; release packaging remains owned by `release.yml`.

### Thermal-only monitor and tables
- Refactored the live monitor to report thermal information only: all readable thermal zones, trip thresholds, headroom, thermal state, protected zones and active cooling devices. CPU/GPU clock caps, scheduler/performance data and game/Flux state are no longer part of the monitor contract.
- Added `hicod thermal table` and a full WebUI thermal-zone table backed directly by `hico.monitor.v2` JSON.
- Added repository thermal tables that keep **original maximum trip values** separate from **HiCo candidate maximum values** and calculate their delta per device/artifact/section. Candidate values are explicitly non-certified tuning candidates.
- Kept `.github/workflows/tools.yml` scoped to thermal tooling, remapping, validation and thermal database publication. `release.yml` remains the separate release packaging/publication workflow and now rebuilds the checked-in thermal Monitor WebUI before packaging.

# HiCo Thermal Changelog

## Unreleased

### Fixed
- Generic thermal tooling now supports recursive deep mapping of supported Android/archive containers with provenance for extracted artifacts.
- Added zstd stream detection/compression/decompression and integrated it into the generic thermal pack/unpack layer.
- Unified CI validates the topology suite and the expanded thermal tooling before publishing generated database data.

### New
- **Multi-vendor thermal knowledge ingestion**: added a source registry and Git-based ingestion pipeline covering OEM dumps,
  custom-ROM/device organizations and independent Android device/vendor/kernel repositories. Repository, branch and source
  commit provenance is retained for every ingested manifest.
- **Generic thermal artifact tooling**: added format detection, safe archive/filesystem unpacking, packing for supported
  archive/stream formats, codec registration, deterministic thermal mapping and mapping-set aggregation.
- **Known-codec boundary**: the existing Xiaomi `MiCrypt` implementation remains the only vendor-specific encryption codec
  currently enabled. Unknown encrypted binaries are kept as opaque metadata instead of guessing a decryption algorithm.
- **Deterministic knowledge database**: normalized device records, source manifests, thermal mappings and JSON schemas live
  under `database/` so validated Actions output can be committed directly to the source repository.
- **Unified Actions pipelines**: replaced the Xiaomi-only device workflow with one end-to-end database workflow and one
  tools/validation workflow. Matrix jobs produce artifacts; only the final merge/publish job writes generated database data.
- **WebUI integrity guard**: added a SHA-256 manifest covering the existing 107-file `webui/` tree; current thermal database
  work does not modify the WebUI.
- **Max only with headroom** (every mode, Extreme too): the max level removes every vendor limit
  and lifts the cpufreq caps, so a phone that was already hot went to the safety limit within
  seconds (a Redmi Note 13 Pro 5G started MLBB at 88.6 °C and sat at 95-96 °C). Now max needs the
  CPU 8 °C and the battery 2 °C below their safety limits; closer to them the game plays at the
  Relaxed level (vendor thermal with this phone's tuned template) and gets max back once the phone
  has cooled 5 °C (battery 1.5 °C) further for the safety cooldown. Home shows why max waits
- **Save log**: the Log page writes status, device, settings and the whole log to Download
- **Encrypted Xiaomi thermal configs**: mi_thermald's AES-encrypted `thermal-*.conf` files (recent
  Xiaomi, Redmi and POCO firmware) are now decrypted, tuned and encrypted again, so the Relaxed
  level (Cool template, whitelisted apps) works on those phones instead of keeping stock thermal.
  `hicod thermal decrypt` / `encrypt` convert them by hand. Independent AES-128 implementation of
  the format documented by mi-thermal-crypt; no code taken from it
- **Per-device thermal templates**: mi_thermald performance sections (cpu, gpu, core hotplug,
  boost_limit) are raised by the chipset margin but never above the highest trip the phone's own
  configs use for that limit (its nolimits / game scenes), so each device gets a template anchored
  in Xiaomi's data for that phone. Battery, charging, brightness, modem, wifi and temp_state
  sections are never changed. `devices/xiaomi/<codename>/tuned/TEMPLATE.md` lists every change
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
- Custom ROMs on Xiaomi vendors (e.g. RisingOS on garnet) were shown as "HyperOS (V816)": the
  vendor keeps the MIUI props. Without the MIUI framework a custom ROM's own props win, and
  Lineage forks are named from `ro.lineage.version` ("RisingOS 9")
- **HiCo stayed on stock thermal for most of a game after one safety trip**: releasing the guard
  required the CPU *and* the battery to cool by their hysteresis, and a battery at 45 °C during
  play never reached 43 °C, so a single CPU trip kept thermal locked (seen: 166 s unlocked out of
  a 2-hour session). Only the sensor that tripped now has to cool down
- **Graduated protection**: at a safety limit the vendor thermal system comes back with the
  device's tuned template first (every protection active, trips bounded by the phone's own
  configs); full stock thermal only 3 °C (CPU) / 1 °C (battery) past the limit, or on devices
  without a tunable config. No more FPS cliff when a limit is touched
- **Thermal HAL restart loop** in Extreme / `stop_thermal_hal`: a HAL that init or servicemanager
  restarts on demand was stopped again every poll, re-initialising and re-applying its limits each
  second (stutter). After three returns it is left running for the session
- Safety notifications: at most one for the soft landing and one for stock protection per game
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
