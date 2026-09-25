/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include "DeviceDatabase.hpp"

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
};

/// Tuning policy for a chipset. @p margin_override (1..10) replaces the chipset margin when set.
[[nodiscard]] Policy policy_for(SocVendor soc, std::string_view platform, int margin_override = 0);

enum class Format {
    Unknown,   ///< encrypted blob or unrelated format: never touched
    Engine,    ///< thermal-engine / plain-text mi_thermald syntax ([SECTION] + key values)
    HalJson,   ///< thermal HAL thermal_info_config*.json (AOSP / Pixel-style HAL, newer vendors)
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

} // namespace hico::thermalcfg
