/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Config.hpp"

#include "Fs.hpp"
#include "Log.hpp"

#include <algorithm>
#include <array>
#include <format>
#include <variant>

namespace hico {

namespace {

using Member = std::variant<bool Config::*, int Config::*, Mode Config::*, std::vector<std::string> Config::*>;

struct Field {
    ConfigKeyInfo info;
    Member member;
};

constexpr size_t kMaxExcludedGames = 64;

// clang-format off
const std::array kFields{
    Field{{"mode", "mode", 0, 0, "auto: unlock while Flux runs a game, off: never unlock"}, &Config::mode},
    Field{{"unlock_on_lite", "bool", 0, 1, "Also unlock while Flux runs Performance Lite"}, &Config::unlock_on_lite},
    Field{{"stop_thermal_services", "bool", 0, 1, "Stop userspace thermal daemons while gaming"}, &Config::stop_thermal_services},
    Field{{"stop_thermal_hal", "bool", 0, 1, "Also stop the thermal HAL (disables Android thermal API while gaming)"}, &Config::stop_thermal_hal},
    Field{{"zone_governor", "bool", 0, 1, "Switch kernel thermal zones to the user_space governor while gaming"}, &Config::zone_governor},
    Field{{"cooling_reset", "bool", 0, 1, "Release CPU/GPU cooling devices while gaming"}, &Config::cooling_reset},
    Field{{"cpu_clock_unlock", "bool", 0, 1, "Keep CPU max frequency at its hardware maximum while gaming"}, &Config::cpu_clock_unlock},
    Field{{"gpu_unlock", "bool", 0, 1, "Lift GPU thermal power-level caps while gaming"}, &Config::gpu_unlock},
    Field{{"vendor_tweaks", "bool", 0, 1, "Qualcomm and MediaTek thermal drivers"}, &Config::vendor_tweaks},
    Field{{"xiaomi_tweaks", "bool", 0, 1, "Xiaomi thermal scene and CPU limits"}, &Config::xiaomi_tweaks},
    Field{{"xiaomi_sconfig", "int", 0, 30, "Xiaomi thermal scene used while gaming"}, &Config::xiaomi_sconfig},
    Field{{"safety_cpu_temp", "int", 70, 105, "CPU temperature (C) that restores thermal protection"}, &Config::safety_cpu_temp},
    Field{{"safety_battery_temp", "int", 38, 52, "Battery temperature (C) that restores thermal protection"}, &Config::safety_battery_temp},
    Field{{"safety_cpu_hysteresis", "int", 3, 25, "CPU must cool this much (C) below the limit to unlock again"}, &Config::safety_cpu_hysteresis},
    Field{{"safety_battery_hysteresis", "int", 1, 10, "Battery must cool this much (C) below the limit to unlock again"}, &Config::safety_battery_hysteresis},
    Field{{"safety_cooldown", "int", 5, 600, "Minimum seconds protection stays on after a trip"}, &Config::safety_cooldown},
    Field{{"poll_interval", "int", 1, 10, "Seconds between temperature checks while gaming"}, &Config::poll_interval},
    Field{{"exit_delay", "int", 0, 30, "Seconds to wait after the game leaves before restoring"}, &Config::exit_delay},
    Field{{"notify", "bool", 0, 1, "Post a notification when the safety guard trips"}, &Config::notify},
    Field{{"log_level", "int", 0, 3, "0 error, 1 warning, 2 info, 3 debug"}, &Config::log_level},
    Field{{"excluded_games", "list", 0, 0, "Comma-separated packages that never unlock"}, &Config::excluded_games},
};
// clang-format on

const std::array<ConfigKeyInfo, kFields.size()> kKeyInfo = [] {
    std::array<ConfigKeyInfo, kFields.size()> out{};
    for (size_t i = 0; i < kFields.size(); ++i) out[i] = kFields[i].info;
    return out;
}();

const Field *find_field(std::string_view key) {
    const auto it = std::find_if(kFields.begin(), kFields.end(), [key](const Field &f) { return f.info.key == key; });
    return it == kFields.end() ? nullptr : &*it;
}

std::optional<bool> parse_bool(std::string_view v) {
    if (v == "1" || v == "true" || v == "on" || v == "yes") return true;
    if (v == "0" || v == "false" || v == "off" || v == "no") return false;
    return std::nullopt;
}

bool is_package_name(std::string_view s) {
    if (s.empty() || s.size() > 128) return false;
    return std::all_of(s.begin(), s.end(), [](char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '.' || c == '_';
    });
}

/// Applies @p value to @p field. @p clamp: clamp out-of-range integers instead of rejecting them.
std::optional<std::string> apply(Config &cfg, const Field &field, std::string_view raw, bool clamp) {
    const std::string value = str::trim(raw);

    return std::visit(
        [&](auto member) -> std::optional<std::string> {
            using T = std::remove_cvref_t<decltype(cfg.*member)>;

            if constexpr (std::is_same_v<T, bool>) {
                const auto b = parse_bool(value);
                if (!b) return std::format("{}: expected 0 or 1, got '{}'", field.info.key, value);
                cfg.*member = *b;
            } else if constexpr (std::is_same_v<T, int>) {
                const auto n = str::to_int(value);
                if (!n) return std::format("{}: expected a number, got '{}'", field.info.key, value);
                if (*n < field.info.min || *n > field.info.max) {
                    if (!clamp) {
                        return std::format("{}: {} is outside {}..{}", field.info.key, *n, field.info.min, field.info.max);
                    }
                    cfg.*member = static_cast<int>(std::clamp<long long>(*n, field.info.min, field.info.max));
                } else {
                    cfg.*member = static_cast<int>(*n);
                }
            } else if constexpr (std::is_same_v<T, Mode>) {
                if (value == "auto") cfg.*member = Mode::Auto;
                else if (value == "off") cfg.*member = Mode::Off;
                else return std::format("{}: expected auto or off, got '{}'", field.info.key, value);
            } else {
                std::vector<std::string> list;
                for (auto &pkg : str::split(value, ',')) {
                    if (!is_package_name(pkg)) return std::format("{}: '{}' is not a package name", field.info.key, pkg);
                    if (std::find(list.begin(), list.end(), pkg) == list.end()) list.push_back(std::move(pkg));
                }
                if (list.size() > kMaxExcludedGames) {
                    return std::format("{}: at most {} packages", field.info.key, kMaxExcludedGames);
                }
                cfg.*member = std::move(list);
            }
            return std::nullopt;
        },
        field.member);
}

std::string format_value(const Config &cfg, const Field &field) {
    return std::visit(
        [&](auto member) -> std::string {
            using T = std::remove_cvref_t<decltype(cfg.*member)>;
            if constexpr (std::is_same_v<T, bool>) {
                return cfg.*member ? "1" : "0";
            } else if constexpr (std::is_same_v<T, int>) {
                return std::to_string(cfg.*member);
            } else if constexpr (std::is_same_v<T, Mode>) {
                return cfg.*member == Mode::Auto ? "auto" : "off";
            } else {
                std::string out;
                for (const auto &pkg : cfg.*member) {
                    if (!out.empty()) out += ',';
                    out += pkg;
                }
                return out;
            }
        },
        field.member);
}

} // namespace

std::span<const ConfigKeyInfo> config_keys() {
    return kKeyInfo;
}

Config Config::load(std::string_view path) {
    Config cfg;
    const auto text = fs::read(path, 64 * 1024);
    if (!text) return cfg;

    int line_no = 0;
    for (const auto &line : str::split(*text, '\n')) {
        ++line_no;
        if (line.empty() || line.front() == '#') continue;
        const size_t eq = line.find('=');
        if (eq == std::string::npos) continue;

        const std::string key = str::trim(std::string_view(line).substr(0, eq));
        const Field *field = find_field(key);
        if (!field) {
            LOGW("config: unknown key '{}' (line {}) ignored", key, line_no);
            continue;
        }
        if (const auto err = apply(cfg, *field, std::string_view(line).substr(eq + 1), true)) {
            LOGW("config: {} (line {}), keeping {}", *err, line_no, format_value(cfg, *field));
        }
    }
    return cfg;
}

bool Config::save(std::string_view path) const {
    return fs::write_atomic(path, serialize(true), 0600);
}

std::optional<std::string> Config::set(std::string_view key, std::string_view value) {
    const Field *field = find_field(key);
    if (!field) return std::format("unknown key '{}'", key);
    Config next = *this;
    if (auto err = apply(next, *field, value, false)) return err;
    *this = std::move(next);
    return std::nullopt;
}

std::optional<std::string> Config::get(std::string_view key) const {
    const Field *field = find_field(key);
    if (!field) return std::nullopt;
    return format_value(*this, *field);
}

bool Config::is_excluded(std::string_view package) const {
    return std::find(excluded_games.begin(), excluded_games.end(), package) != excluded_games.end();
}

std::string Config::serialize(bool with_comments) const {
    std::string out;
    if (with_comments) {
        out += "# HiCo Thermal configuration. Edit with `hicod config set <key> <value>` or the WebUI;\n"
               "# values are validated and out-of-range numbers are clamped.\n";
    }
    for (const auto &field : kFields) {
        if (with_comments) {
            out += std::format("\n# {}", field.info.help);
            if (field.info.type == "int") out += std::format(" [{}..{}]", field.info.min, field.info.max);
            out += '\n';
        }
        out += std::format("{}={}\n", field.info.key, format_value(*this, field));
    }
    return out;
}

} // namespace hico
