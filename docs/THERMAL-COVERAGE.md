# Thermal coverage roadmap

Where HiCo Thermal stands today across OEMs and ROMs, what really exists per
vendor, and how the "one workflow, many jobs" ingestion pipeline is planned.

## What HiCo already reads and tunes

`jni/src/ThermalConfig.cpp` detects the format at parse time; every format goes
through the same tune → verify → bind-mount pipeline (`ThermalController.cpp`,
`Journal.cpp`) and every change is reversible.

| Format id | File shape | OEMs that use it |
|---|---|---|
| `HalJson` | `/vendor/etc/thermal_info_config*.json` (Android Thermal HAL 2.0) | Google Pixel, Nothing, most OPlus (Oppo / Realme / OnePlus) devices on Android 12+, later Motorola, most AOSP-based ROMs |
| `Engine` | `/vendor/etc/thermal-engine.conf` (Qualcomm reference INI-style) | Qualcomm stock behaviour on older phones, Fairphone, older ASUS / ZTE / Nothing devices |
| `MiThermald` | Plaintext `thermal-*.conf` with `[sensor]`, `[cdev]`, `[limit]` sections | Older Xiaomi / Redmi / POCO before firmware encryption |
| `MiEncrypted` | The above wrapped in AES-128-CBC by `mi-thermald` | Xiaomi / Redmi / POCO firmware from roughly HyperOS onwards |

The tuning rules (`jni/src/ThermalConfig.cpp:mithermald::tune`,
`haljson::tune`, `tune_engine`) raise trip points by the chipset margin, never
above the highest trip the phone's own configs use for the same limit, and
never touch battery, charging, brightness, modem or Wi-Fi sections. Each tuned
file passes an independent verifier before HiCo bind-mounts it over the
original path. The stock files stay on disk untouched — bind mounts vanish on
reboot, on `hicod restore`, on module uninstall.

## Answers to the design questions

### "Do we already have MiCrypt?"

Yes. `jni/src/MiCrypt.cpp` is an independent AES-128-CBC + PKCS#7
implementation of the mi-thermald encrypted format (key and IV
`"thermalopenssl.h"`). Sources are format documentation only; no code was
taken from `adithya2306/mi-thermal-crypt`. It works both ways: decrypt for
inspection (`hicod thermal decrypt`), encrypt after tuning
(`hicod thermal encrypt`).

### "What about tools for Realme, Oppo, Samsung, OnePlus, Nothing, Pixel?"

Being honest about what each ecosystem actually needs, from public sources
(vendor firmware dumps on dumps.tadiphone.dev, TheMalwareGuy repo,
LineageOS mirrors, AOSP thermal HAL headers).

| OEM | Format(s) in `/vendor/etc/` | Encryption? | HiCo status |
|---|---|---|---|
| Google Pixel | AOSP HAL 2.0 JSON | none | ✅ works today via `HalJson` |
| Nothing | AOSP HAL 2.0 JSON (Snapdragon) | none | ✅ works today via `HalJson` |
| OPlus (Oppo, Realme, OnePlus after 2022) | AOSP HAL 2.0 JSON with OPlus extensions | none | ✅ base tuning works; extensions are a documentation gap |
| OPlus older (pre-ColorOS 12) | `thermal-engine.conf` derivatives (`thermal-engine.conf.xml`) | none | ⚠️ engine format works; XML variant needs a new parser |
| Motorola | AOSP HAL 2.0 JSON (later devices), `thermal-engine.conf` (older) | none | ✅ works today |
| Samsung Exynos | Thermal tables baked into DT (device tree blob), TMU driver | none, but **not user-space configurable** | ❌ almost nothing to tune from user space; needs `/sys/class/thermal/thermal_zoneN/policy` overrides only |
| Samsung Snapdragon | AOSP HAL 2.0 JSON (recent Sxx series) | none | ✅ works today |
| MediaTek stock | `thermal.conf` + thermal HAL JSON | none | ✅ engine + HAL JSON work |
| ASUS ROG | AOSP HAL 2.0 JSON + `thermal.conf` per game mode | none | ✅ base tuning works; game-mode selection needs a new probe |
| Vivo / iQOO | AOSP HAL 2.0 JSON with vivo-specific `governor` keys | reportedly obfuscated on newer firmware | ⚠️ base tuning works when plaintext; format probe needed |

The takeaway: **for every non-Xiaomi OEM in the "supported custom ROM" bracket
that HiCo cares about, the file is already plain JSON or plain INI.** The
Xiaomi encryption is an outlier. What is realistic to add:

- `tools/oplus_devices.py` — same shape as `xiaomi_devices.py`, scans Oppo /
  Realme / OnePlus dumps for `thermal_info_config*.json`, records the trip
  points HiCo would use as ceilings.
- `tools/aosp_devices.py` — Pixel, Nothing, Motorola scanner for HAL JSON.
  Small.
- `tools/mtk_devices.py` — MediaTek stock and Dimensity Pixel-style HAL scan.
- `tools/samsung_devices.py` — read-only: enumerates DT-baked TMU tables and
  captures which zones expose `user_space` so HiCo knows what it can and can't
  touch. There is no meaningful "tuning" here.

What is **not realistic** without new research:
- Full vivo / iQOO obfuscated JSON — needs someone to figure out the format
  first.
- Huawei / HarmonyOS — outside the "custom ROM available" bracket for now.

### "One YAML with many jobs for ingest?"

Yes, that is the plan. Sketch is in
`.github/workflows/ingest-thermals.yml` (added alongside this doc). It runs on
manual dispatch and monthly, and looks like:

```yaml
jobs:
  xiaomi:    { uses tools/xiaomi_devices.py, groups dumps/xiaomi ... }
  oplus:     { uses tools/oplus_devices.py (TODO), groups dumps/{oneplus,oppo,realme} }
  pixel:     { uses tools/aosp_devices.py  (TODO), groups dumps/google/pixel* }
  nothing:   { uses tools/aosp_devices.py  (TODO), groups dumps/nothing }
  mediatek:  { uses tools/mtk_devices.py   (TODO), groups where SoC = mt* }
  samsung:   { uses tools/samsung_devices.py (TODO), groups dumps/samsung }
  compile-db: { needs: [all of the above], runs tools/gen_device_db.py, opens a PR }
```

Each job writes into its own vendor subfolder under `devices/`, so parallel
jobs never touch the same file. The compile-db job aggregates every scan,
runs `tools/gen_device_db.py --check`, then opens one PR the maintainer
reviews before merge.

`.github/workflows/devices.yml` today is the Xiaomi-only start of this — it
already scans `dumps/xiaomi`, `dumps/redmi`, `dumps/poco` on
dumps.tadiphone.dev, decrypts mi_thermald configs, tunes them and opens a
pull request with the changes. Extending it to matrix form is the next
concrete step.

### "One YAML with many jobs for the tools too?"

Yes. The Tools validate matrix (planned as
`.github/workflows/tools-validate.yml`) fans out on
`{ tool × sample_firmware }`:

- `mi_thermald`: encrypt / decrypt / tune / verify round-trip on fixtures in
  `tests/fixtures/mi/`.
- `oplus_json`: parse / tune / verify on `tests/fixtures/oplus/`.
- `aosp_hal_json`: same on `tests/fixtures/aosp/`.
- `engine_conf`: same on `tests/fixtures/engine/`.

Every matrix cell runs one hicod host build and a set of fixture files. Failure
in any cell fails the whole run.

### "How does the Actions ingestion write the database back?"

The `devices.yml` workflow already does this the same way the plan calls for:

1. `tools/xiaomi_devices.py` clones each dump sparsely
   (`--sparse --workdir $RUNNER_TEMP`) so only `build.prop`, `thermal_zones/`
   and thermal configs are downloaded — most dumps are 5–20 GB otherwise.
2. Extracted data lands in `devices/xiaomi/<codename>/`, one folder per
   phone.
3. `tools/gen_device_db.py` compiles the folder tree into
   `jni/src/XiaomiDevices.gen.cpp`, which the daemon reads directly.
4. `tools/tune_thermal.py` runs the on-device tuner against every recorded
   config to catch regressions early, and writes
   `devices/xiaomi/<codename>/tuned/TEMPLATE.md`.
5. The workflow opens a pull request with all changes, so nothing is force-
   pushed to `main`. That is deliberate: every phone record is reviewed.

### "OEM stock vs HiCo tuned in the module"

Already the case, but the WebUI does not yet expose the choice cleanly.
`Journal.cpp` records every mount before it applies and unmounts it on
`restore()`. So the phone always has two thermal sets available:

- **OEM stock**: what the vendor ships. Restored on `hicod restore`, on
  reboot (bind mounts are volatile), on uninstall, on any safety trip past
  the hard margin, and immediately when a game closes.
- **HiCo tuned**: same file, trip points raised by the chipset margin, bind-
  mounted only while a game is running.

The planned WebUI option "which thermal to use in games" is: `oem`,
`hico_balanced`, `hico_aggressive`. Today the choice is fixed at
`hico_balanced` (the tuning margin from the chipset default). Adding
`oem` (never remap, just let the vendor throttle) is trivial and gets
skipped in `ThermalController::relax()` when set.

### "Daily mode"

Added in this commit. The preset is:
```
mode=auto, game_level=relaxed, unlock_on_lite=0,
relax_margin=2, safety_cpu_temp=85, safety_battery_temp=42,
safety_cooldown=45, poll_interval=3
```

The point of Daily is *not* to boost performance — it is to make sure HiCo
does not silently unlock while you are on Instagram, YouTube or Netflix.
Peak stays with the vendor thermal system. Games in the foreground still
get the Relaxed level so they do not stutter, but no vendor limit is
removed and clocks are never pinned. Social and streaming apps naturally
fall through to "no active target" in `Daemon::choose_target` and get zero
HiCo intervention.

## Order of work

1. ✅ **Daily preset** (this commit).
2. ✅ **This doc**: real coverage table, honest gaps.
3. Next PR: split `devices.yml` into a `ingest-thermals.yml` matrix with a
   real Xiaomi cell (current script) and empty cells for oplus / aosp / mtk
   / samsung that print "not implemented yet".
4. Next PR: `tools/aosp_devices.py` for Pixel / Nothing / Motorola. Simplest
   because the format is exactly the AOSP HAL 2.0 JSON HiCo already tunes.
5. Next PR: `tools/oplus_devices.py`.
6. Deferred: `tools/mtk_devices.py`, `tools/samsung_devices.py` (very
   different shape, less user-space to tune).

Each of these is a real, testable delta. The scaffolding is intentionally
not written all at once — it would be a lot of code that has never seen a
real device dump go through it.
