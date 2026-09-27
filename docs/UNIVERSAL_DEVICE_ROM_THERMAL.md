# Universal Device + ROM + Thermal Source Model

## Goals

HiCo treats these as separate identities:

1. **Device** — physical hardware identity: OEM, codename, platform and SoC vendor.
2. **ROM** — operating-system/build identity: family, Android release and ecosystem.
3. **Thermal source** — a repository/commit and its thermal artifacts, with provenance and source layer.

## Why this matters

A Xiaomi `garnet` device can have stock HyperOS and several AOSP-derived ROMs. Those ROMs may keep the
same vendor/kernel stack while replacing `/system` and `/product`. They must therefore point to the same
hardware record while retaining separate ROM and thermal-source records.

## Canonical IDs

```text
device_id = <oem>/<codename>
rom_id    = <rom-family>/<android-major>
source_id = <provider>/<repository>@<commit>
```

The Android component in `rom_id` intentionally identifies an Android-generation environment, not an exact ROM release.
An exact release can be added later without changing the device identity.

## Source layers

A thermal source records where the relevant material comes from:

```text
firmware
vendor
odm
system
system_ext
product
kernel
device-tree
hal
init
unknown
```

Unknown sources remain valid and are stored rather than guessed.

## Migration policy

The universal knowledge layer is additive first. The existing Xiaomi runtime table continues to compile normally.
Once the universal dataset is populated and validated for multiple OEMs, the runtime compiler can be migrated from
`XiaomiDevices.gen.cpp` to a vendor-neutral generated table in a separate change.
