/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace hico {

enum class Mode { Auto, Off };

/**
 * User settings (HICO_CONFIG_FILE, "key=value" lines).
 *
 * Every key is described once in the schema (Config.cpp) with its type and
 * allowed range. Values outside the range are clamped when loading and
 * rejected by set(), so the daemon never acts on an unsafe value, whoever
 * edited the file.
 */
struct Config {
    Mode mode = Mode::Auto;

    // What is unlocked while a game runs
    bool unlock_on_lite = true;        ///< also unlock when Flux runs Performance Lite
    bool stop_thermal_services = true; ///< stop userspace thermal daemons (thermal-engine, mi_thermald, ...)
    bool stop_thermal_hal = false;     ///< also stop the thermal HAL (breaks Android's thermal API while gaming)
    bool zone_governor = true;         ///< kernel thermal zones -> user_space governor (critical trips stay armed)
    bool cooling_reset = true;         ///< release CPU/GPU cooling devices
    bool cpu_clock_unlock = true;      ///< keep scaling_max_freq at cpuinfo_max_freq
    bool gpu_unlock = true;            ///< lift GPU thermal power-level caps
    bool vendor_tweaks = true;         ///< Qualcomm / MediaTek thermal drivers
    bool xiaomi_tweaks = true;         ///< Xiaomi thermal_message scene and CPU limits
    int xiaomi_sconfig = 10;           ///< thermal scene used while gaming

    // Safety guard
    int safety_cpu_temp = 95;          ///< °C, CPU temperature that restores thermal protection
    int safety_battery_temp = 46;      ///< °C, battery temperature that restores thermal protection
    int safety_cpu_hysteresis = 10;    ///< °C below the limit before unlocking again
    int safety_battery_hysteresis = 3; ///< °C below the limit before unlocking again
    int safety_cooldown = 30;          ///< s, minimum time protection stays on after a trip

    // Daemon
    int poll_interval = 2;             ///< s, temperature check period while a game runs
    int exit_delay = 3;                ///< s, grace period after the game leaves before restoring
    bool notify = true;                ///< Android notification when the safety guard trips
    int log_level = 2;                 ///< 0 error, 1 warn, 2 info, 3 debug
    std::vector<std::string> excluded_games;

    /// Loads @p path; missing keys keep their defaults, invalid values are clamped or ignored.
    static Config load(std::string_view path);
    bool save(std::string_view path) const;

    /// Validates and sets one key. Returns an error message on failure.
    std::optional<std::string> set(std::string_view key, std::string_view value);
    [[nodiscard]] std::optional<std::string> get(std::string_view key) const;

    [[nodiscard]] bool is_excluded(std::string_view package) const;

    /// "key=value" for every key, in schema order.
    [[nodiscard]] std::string serialize(bool with_comments) const;
};

struct ConfigKeyInfo {
    std::string_view key;
    std::string_view type;  ///< "bool", "int", "mode" or "list"
    int min;
    int max;
    std::string_view help;
};

[[nodiscard]] std::span<const ConfigKeyInfo> config_keys();

} // namespace hico
