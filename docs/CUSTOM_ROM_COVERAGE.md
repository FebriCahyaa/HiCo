# Custom ROM & OEM source coverage

Registry: `stock/sources.yaml` (schema `hico.ingest-sources.v1`).

Every entry below was verified live at the time of the last commit to that
file by `tools/verify/rom_sources.py`. `ingest.yml` walks the registry and
sparse-fetches the paths under `thermal_paths:` from each org's device-tree
repositories.

## Custom ROM device-tree orgs

| ID | ROM | Provider / org | Repos |
|---|---|---|---|
| `lineageos` | LineageOS | github / LineageOS | ~1,500 device trees |
| `pixelos` | PixelOS | github / PixelOS-Devices | 115 |
| `crdroid` | crDroid | github / crdroidandroid | 1,334 |
| `derpfest` | DerpFest | github / DerpFest-AOSP | 430 |
| `evolutionx` | Evolution X | github / Evolution-X | 95 |
| `arrowos` | ArrowOS | github / ArrowOS-Devices | 356 |
| `risingos` | RisingOS | github / RisingOS-Revived | 94 |
| `aospa` | Paranoid Android | github / AOSPA | 580 |
| `dotos` | DotOS | github / DotOS-Devices | 556 |
| `voltageos` | Voltage OS | github / VoltageOS | 250 |
| `lmodroid` | LMODroid | github / LMODroid-Devices | 433 |
| `awakenos` | AwakenOS | github / AwakenOS-Devices | 16 |
| `alphadroid` | AlphaDroid | github / AlphaDroid-Devices | 215 |
| `spark` | Spark | github / spark-rom | 140 |
| `krypton` | Krypton | github / AOSP-Krypton | 106 |
| `protonaosp` | ProtonAOSP | github / ProtonAOSP | 126 |

## OEM firmware dumps

| ID | Group | Provider | Notes |
|---|---|---|---|
| `tadiphone-xiaomi` | dumps/xiaomi | gitlab / dumps.tadiphone.dev | Needs `TADIPHONE_TOKEN` secret in CI |
| `tadiphone-redmi` | dumps/redmi | gitlab / dumps.tadiphone.dev | Needs `TADIPHONE_TOKEN` secret in CI |
| `tadiphone-poco` | dumps/poco | gitlab / dumps.tadiphone.dev | Needs `TADIPHONE_TOKEN` secret in CI |

## What we take from each repo

Sparse-fetch keeps ingest cheap. The path list lives in
`stock/sources.yaml → thermal_paths:` and covers three groups:

1. **Actual thermal configs** (rare in device trees; usually shipped as
   vendor blobs): `thermal/**`, `thermal-engine*.conf`,
   `thermal_info_config*.json`, `thermal_zone_config*.xml`,
   `thermal_platform_supported_v*.xml`, `thermal-scenes-*.xml`,
   `thermal_srv_config.xml`, `mmi_thermal/**`, `power_hal_conf/**`.
2. **Init hooks that touch thermal**: `init.*thermal*.rc`,
   `init.*thermal*.sh`.
3. **Evidence** (device identity + what the ROM pulls from vendor):
   `AndroidProducts.mk`, `device.mk`, `device-*.mk`, `Android.bp`,
   `Android.mk`, `BoardConfig*.mk`, `extract-files.sh`,
   `proprietary-files.txt`, `system.prop`, `vendorsetup.sh`,
   `lineage.dependencies`, `sepolicy/**/*thermal*`.

## Adding a new source

1. Add an entry to `stock/sources.yaml`.
2. Run `python3 tools/verify/rom_sources.py` — must pass with 0 failures.
3. Open a PR. `ingest.yml` will pick the new source up on its next
   scheduled run.

## Removing a source

If an org disappears (moved, deleted, unreachable for weeks): remove its
entry from `stock/sources.yaml` and note the removal in the commit message.
Never leave a dead entry — the ingest workflow will fail loudly on it, which
is a false alarm we don't want to normalise.
