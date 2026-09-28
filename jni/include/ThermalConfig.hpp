/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include "DeviceDatabase.hpp"

#include <map>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

/**
 * Vendor thermal configuration files: Qualcomm thermal-engine syntax (also used
 * by plain-text Xiaomi mi_thermald configs), and the thermal HAL's
 * thermal_info_config.json used by AOSP-based ROMs and newer vendor stacks.
 * Engine syntax:
 *
 *     [SKIN_MONITOR]
 *     algo_type        monitor
 *     sensor           quiet_therm
 *     thresholds       41000 43000
 *     thresholds_clr   39000 41000
 *     actions          cpu+gpu cpu+gpu
 *
 * The tuner raises the trip points of eligible sections by a per-chipset
 * margin ("relaxed" thermal): throttling starts later, but the vendor's
 * thermal daemon keeps running and keeps protecting the device. It never
 * touches shutdown sections, battery / charger / PMIC sensors, descending
 * (low-temperature or voltage) monitors, and never lowers a trip.
 *
 * One implementation serves both sides: hicod applies it on the device to the
 * device's own files, and the repository tools run the host build over every
 * collected firmware file (tools/tune_thermal.py) for review and CI.
 */
namespace hico::thermalcfg {

struct Policy {
    int margin_c = 4;            ///< raise eligible trips by this much
    int cap_cpu_c = 105;         ///< never raise a CPU/GPU sensor trip above this
    int cap_other_c = 55;        ///< never raise a skin / board sensor trip above this
    int shutdown_guard_c = 10;   ///< keep every trip this far below the lowest shutdown threshold
    std::string_view name = "generic";
    /// mi_thermald only: highest trip (m°C) the device's own configs use per
    /// "device|sensor" (usually its nolimits / game scene). A tuned section never
    /// goes above it, so each device gets a template anchored in Xiaomi's data.
    std::map<std::string, long long> mi_ceilings;
};

/// Tuning policy for a chipset. @p margin_override (1..10) replaces the chipset margin when set.
[[nodiscard]] Policy policy_for(SocVendor soc, std::string_view platform, int margin_override = 0);

enum class Format {
    Unknown,   ///< encrypted blob or unrelated format: never touched
    Engine,    ///< thermal-engine / plain-text mi_thermald syntax ([SECTION] + key values)
    HalJson,   ///< thermal HAL thermal_info_config*.json (AOSP / Pixel-style HAL, newer vendors)
    MiThermald,  ///< plain-text mi_thermald config (algo_type ss / monitor, trig / clr / target)
    MiEncrypted, ///< the same, AES-encrypted as recent Xiaomi firmware ships it (MiCrypt.hpp)
};

[[nodiscard]] Format detect_format(std::string_view content);

/// True for a config HiCo can tune (Engine or HalJson with trip points).
[[nodiscard]] bool is_tunable_text(std::string_view content);

struct Result {
    std::string text;       ///< tuned file (identical to the input when nothing changed)
    int sections = 0;       ///< sections in the file
    int tuned_sections = 0; ///< sections whose trips were raised
    std::vector<std::string> notes; ///< why sections were left alone
};

/// Tunes @p content; nullopt when it is not a tunable text config.
[[nodiscard]] std::optional<Result> tune(std::string_view content, const Policy &policy);

/// thermal*.conf files on this device: vendor partition first, then pre-Treble /system locations.
[[nodiscard]] std::vector<std::string> device_config_files();

/// device_config_files() plus files HiCo only identifies, never tunes: MediaTek's thermal policies
/// in /vendor/etc/.tp (thermal.conf, .thermal_policy_NN, .ht120.mtc; obfuscated by the vendor).
[[nodiscard]] std::vector<std::string> identify_config_files();

/// Independent safety check of a tuned file against its original. Returns the violations (empty = safe).
[[nodiscard]] std::vector<std::string> verify(std::string_view original, std::string_view tuned, const Policy &policy);

/// Thermal HAL JSON ("Sensors": [{"Name", "Type", "HotThreshold": [7 severity levels]}, ...]).
/// HotThreshold levels are NONE, LIGHT, MODERATE, SEVERE, CRITICAL, EMERGENCY, SHUTDOWN:
/// LIGHT..CRITICAL are raised, EMERGENCY and SHUTDOWN are never changed.
namespace haljson {
[[nodiscard]] bool is_config(std::string_view content);
[[nodiscard]] std::optional<Result> tune(std::string_view content, const Policy &policy);
[[nodiscard]] std::vector<std::string> verify(std::string_view original, std::string_view tuned, const Policy &policy);
} // namespace haljson

/**
 * Xiaomi mi_thermald configs (thermal-normal.conf, thermal-tgame.conf, ...).
 *
 * Sections use `trig` (rising thresholds), `clr` (release thresholds) and
 * `target` (the limit applied at each step) against a `sensor`, for a
 * `device`. Only sections that throttle performance are tuned: devices cpuN,
 * gpu, hotplug_cpuN and boost_limit. Battery / charging, brightness, torch,
 * modem, wifi, temp_state and download limits are never changed, nor are
 * sections with a battery-type sensor or descending (`reverse`) thresholds.
 *
 * A tuned section moves trig and clr up by the same amount (hysteresis and
 * order kept, targets untouched): the chipset margin, but never above the
 * highest trip the device's own configs use for that device and sensor
 * (Policy::mi_ceilings) nor the policy caps.
 */
namespace mithermald {
[[nodiscard]] bool is_config(std::string_view content);
/// "device|sensor" -> highest trig (m°C) in @p content, merged into @p into.
void collect_ceilings(std::string_view content, std::map<std::string, long long> &into);
[[nodiscard]] std::optional<Result> tune(std::string_view content, const Policy &policy);
[[nodiscard]] std::vector<std::string> verify(std::string_view original, std::string_view tuned, const Policy &policy);
} // namespace mithermald

/// Plain text of any tunable config: decrypted when it is an encrypted mi_thermald file.
[[nodiscard]] std::optional<std::string> plain_text(std::string_view content);

} // namespace hico::thermalcfg
