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

/// auto: unlock while Flux runs a game; extreme: auto without the soft limits
/// (thermal HAL stopped too, zones that cannot switch governor get their passive
/// trips raised, every game at max); off: never unlock.
enum class Mode { Auto, Extreme, Off };

/// How far HiCo pushes the device for a running app. The order is the schema's
/// range: a key with max 1 accepts stock and relaxed only.
enum class Level {
    Stock,   ///< the ROM's own thermal, untouched ("OEM" in the WebUI)
    Relaxed, ///< vendor thermal daemons keep running with configs tuned for the chipset ("HiCo Balanced")
    Max,     ///< thermal throttling disabled, games only ("HiCo Aggressive")
};

/// What the foreground app is used for; each scenario has its own level.
enum class Scenario { Game, Social, Media, Other };

[[nodiscard]] std::string_view to_string(Scenario s);

[[nodiscard]] std::string_view to_string(Level l);

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
    Level game_level = Level::Max;     ///< level for Flux games (stock keeps the ROM's thermal)
    Level social_level = Level::Stock; ///< level for social media apps (stock or relaxed)
    Level media_level = Level::Stock;  ///< level for streaming / video / music apps (stock or relaxed)

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
    int relax_margin = 0;              ///< °C added to trips at the relaxed level; 0 = chipset default
    /// Thermal overclock: cpufreq boost frequencies on and the widest relaxed trip margin,
    /// so the chipset holds its fastest states longer. Safety guard still on.
    bool thermal_overclock = false;

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
    /// Social media apps (social_level); starts with the common ones.
    std::vector<std::string> social_apps = default_social_apps();
    /// Streaming, video and music apps (media_level); starts with the common ones.
    std::vector<std::string> media_apps = default_media_apps();
    /// Apps that are not games but get the relaxed level (never max) while in the foreground.
    std::vector<std::string> whitelist;
    /// Packages that are never boosted, games included.
    std::vector<std::string> blacklist;

    /// Loads @p path; missing keys keep their defaults, invalid values are clamped or ignored.
    static Config load(std::string_view path);
    bool save(std::string_view path) const;

    /// Validates and sets one key. Returns an error message on failure.
    std::optional<std::string> set(std::string_view key, std::string_view value);
    [[nodiscard]] std::optional<std::string> get(std::string_view key) const;

    [[nodiscard]] static std::vector<std::string> default_social_apps();
    [[nodiscard]] static std::vector<std::string> default_media_apps();

    [[nodiscard]] bool is_blacklisted(std::string_view package) const;
    /// Scenario of a non-game foreground app: Social, Media, Other (whitelist) or nullopt.
    [[nodiscard]] std::optional<Scenario> app_scenario(std::string_view package) const;
    [[nodiscard]] Level level_for(Scenario s) const;
    [[nodiscard]] bool is_whitelisted(std::string_view package) const;

    /// "key=value" for every key, in schema order.
    [[nodiscard]] std::string serialize(bool with_comments) const;
};

struct ConfigKeyInfo {
    std::string_view key;
    std::string_view type;  ///< "bool", "int", "mode", "level" or "list"
    int min;
    int max;
    std::string_view help;
};

[[nodiscard]] std::span<const ConfigKeyInfo> config_keys();

/// A ready-made set of values for users who do not want to tune each key.
struct ConfigPreset {
    std::string_view name;
    std::span<const std::pair<std::string_view, std::string_view>> values;
};

[[nodiscard]] std::span<const ConfigPreset> config_presets();

/// Applies preset @p name to @p cfg (lists are kept). Error message when unknown.
std::optional<std::string> apply_preset(Config &cfg, std::string_view name);

/// Name of the preset @p cfg currently matches, or "custom".
[[nodiscard]] std::string_view matching_preset(const Config &cfg);

} // namespace hico
