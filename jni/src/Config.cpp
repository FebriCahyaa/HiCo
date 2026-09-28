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

using Member = std::variant<bool Config::*, int Config::*, Mode Config::*, Level Config::*, std::vector<std::string> Config::*>;

struct Field {
    ConfigKeyInfo info;
    Member member;
};

constexpr size_t kMaxListEntries = 64;

// clang-format off
const std::array kFields{
    Field{{"mode", "mode", 0, 0, "auto: unlock while Flux runs a game, extreme: auto without soft limits, off: never unlock"}, &Config::mode},
    Field{{"game_level", "level", 0, 2, "Games: max disables throttling, relaxed tunes the vendor thermal configs, stock keeps the ROM's thermal"}, &Config::game_level},
    Field{{"social_level", "level", 0, 1, "Social media apps: relaxed tunes the vendor thermal configs, stock keeps the ROM's thermal"}, &Config::social_level},
    Field{{"media_level", "level", 0, 1, "Streaming, video and music apps: relaxed or stock"}, &Config::media_level},
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
    Field{{"relax_margin", "int", 0, 10, "Relaxed level: degrees added to trip points (0 = chipset default)"}, &Config::relax_margin},
    Field{{"thermal_overclock", "bool", 0, 1, "Thermal overclock: cpufreq boost frequencies and the widest relaxed margin"}, &Config::thermal_overclock},
    Field{{"safety_cpu_temp", "int", 70, 105, "CPU temperature (C) that restores thermal protection"}, &Config::safety_cpu_temp},
    Field{{"safety_battery_temp", "int", 38, 52, "Battery temperature (C) that restores thermal protection"}, &Config::safety_battery_temp},
    Field{{"safety_cpu_hysteresis", "int", 3, 25, "CPU must cool this much (C) below the limit to unlock again"}, &Config::safety_cpu_hysteresis},
    Field{{"safety_battery_hysteresis", "int", 1, 10, "Battery must cool this much (C) below the limit to unlock again"}, &Config::safety_battery_hysteresis},
    Field{{"safety_cooldown", "int", 5, 600, "Minimum seconds protection stays on after a trip"}, &Config::safety_cooldown},
    Field{{"poll_interval", "int", 1, 10, "Seconds between temperature checks while gaming"}, &Config::poll_interval},
    Field{{"exit_delay", "int", 0, 30, "Seconds to wait after the game leaves before restoring"}, &Config::exit_delay},
    Field{{"notify", "bool", 0, 1, "Post a notification when the safety guard trips"}, &Config::notify},
    Field{{"log_level", "int", 0, 3, "0 error, 1 warning, 2 info, 3 debug"}, &Config::log_level},
    Field{{"social_apps", "list", 0, 0, "Social media apps (social_level)"}, &Config::social_apps},
    Field{{"media_apps", "list", 0, 0, "Streaming, video and music apps (media_level)"}, &Config::media_apps},
    Field{{"whitelist", "list", 0, 0, "Other apps (not games) that get the relaxed level, never max"}, &Config::whitelist},
    Field{{"blacklist", "list", 0, 0, "Packages that are never boosted, games included"}, &Config::blacklist},
};
// clang-format on

const std::array<ConfigKeyInfo, kFields.size()> kKeyInfo = [] {
    std::array<ConfigKeyInfo, kFields.size()> out{};
    for (size_t i = 0; i < kFields.size(); ++i) out[i] = kFields[i].info;
    return out;
}();

const Field *find_field(std::string_view key) {
    if (key == "excluded_games") key = "blacklist"; // renamed in 1.0.0
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
                else if (value == "extreme") cfg.*member = Mode::Extreme;
                else if (value == "off") cfg.*member = Mode::Off;
                else return std::format("{}: expected auto, extreme or off, got '{}'", field.info.key, value);
            } else if constexpr (std::is_same_v<T, Level>) {
                Level l;
                if (value == "max") l = Level::Max;
                else if (value == "relaxed") l = Level::Relaxed;
                else if (value == "stock") l = Level::Stock;
                else return std::format("{}: expected {}, got '{}'", field.info.key,
                                        field.info.max >= 2 ? "stock, relaxed or max" : "stock or relaxed", value);
                if (static_cast<int>(l) > field.info.max) {
                    // Only games may run with throttling off.
                    if (!clamp) return std::format("{}: max is for games only (stock or relaxed)", field.info.key);
                    l = static_cast<Level>(field.info.max);
                }
                cfg.*member = l;
            } else {
                std::vector<std::string> list;
                for (auto &pkg : str::split(value, ',')) {
                    if (!is_package_name(pkg)) return std::format("{}: '{}' is not a package name", field.info.key, pkg);
                    if (std::find(list.begin(), list.end(), pkg) == list.end()) list.push_back(std::move(pkg));
                }
                if (list.size() > kMaxListEntries) {
                    return std::format("{}: at most {} packages", field.info.key, kMaxListEntries);
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
                return cfg.*member == Mode::Auto ? "auto" : cfg.*member == Mode::Extreme ? "extreme" : "off";
            } else if constexpr (std::is_same_v<T, Level>) {
                return std::string(to_string(cfg.*member));
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

namespace {

using KV = std::pair<std::string_view, std::string_view>;

// Presets touch the level, the safety limits and the timing only; lists stay as they are.
// Safety limits never leave the schema ranges, so no preset can switch the guard off.
// Daily: for social media, streaming and general use. HiCo never touches the peak here; the
// vendor thermal system stays in charge with configs tuned for the chipset (Relaxed) for games,
// social media and streaming apps alike, so they do not stutter. No vendor limit is removed and
// clocks are never pinned. The other presets leave the social / media levels as the user set them.
constexpr std::array kDaily{
    KV{"mode", "auto"}, KV{"game_level", "relaxed"}, KV{"social_level", "relaxed"}, KV{"media_level", "relaxed"},
    KV{"unlock_on_lite", "0"}, KV{"thermal_overclock", "0"}, KV{"relax_margin", "2"}, KV{"safety_cpu_temp", "85"}, KV{"safety_battery_temp", "42"},
    KV{"safety_cooldown", "45"}, KV{"poll_interval", "3"},
};
constexpr std::array kCool{
    KV{"mode", "auto"}, KV{"game_level", "relaxed"}, KV{"unlock_on_lite", "0"}, KV{"thermal_overclock", "0"},
    KV{"relax_margin", "0"}, KV{"safety_cpu_temp", "88"}, KV{"safety_battery_temp", "43"},
    KV{"safety_cooldown", "60"}, KV{"poll_interval", "2"},
};
constexpr std::array kBalanced{
    KV{"mode", "auto"}, KV{"game_level", "max"}, KV{"unlock_on_lite", "1"}, KV{"thermal_overclock", "0"},
    KV{"relax_margin", "0"}, KV{"safety_cpu_temp", "95"}, KV{"safety_battery_temp", "46"},
    KV{"safety_cooldown", "30"}, KV{"poll_interval", "2"},
};
constexpr std::array kExtreme{
    KV{"mode", "extreme"}, KV{"game_level", "max"}, KV{"unlock_on_lite", "1"}, KV{"thermal_overclock", "0"},
    KV{"relax_margin", "0"}, KV{"safety_cpu_temp", "100"}, KV{"safety_battery_temp", "48"},
    KV{"safety_cooldown", "30"}, KV{"poll_interval", "1"},
};
constexpr std::array kOverclock{
    KV{"mode", "extreme"}, KV{"game_level", "max"}, KV{"unlock_on_lite", "1"}, KV{"thermal_overclock", "1"},
    KV{"relax_margin", "10"}, KV{"safety_cpu_temp", "102"}, KV{"safety_battery_temp", "49"},
    KV{"safety_cooldown", "20"}, KV{"poll_interval", "1"},
};

const std::array kPresets{
    ConfigPreset{"daily", kDaily},
    ConfigPreset{"cool", kCool},
    ConfigPreset{"balanced", kBalanced},
    ConfigPreset{"extreme", kExtreme},
    ConfigPreset{"overclock", kOverclock},
};

} // namespace

std::span<const ConfigPreset> config_presets() {
    return kPresets;
}

std::optional<std::string> apply_preset(Config &cfg, std::string_view name) {
    const auto it = std::find_if(kPresets.begin(), kPresets.end(), [name](const ConfigPreset &p) { return p.name == name; });
    if (it == kPresets.end()) return std::format("unknown preset '{}' (daily, cool, balanced, extreme, overclock)", name);
    Config next = cfg;
    for (const auto &[key, value] : it->values) {
        if (auto err = next.set(key, value)) return err;
    }
    cfg = std::move(next);
    return std::nullopt;
}

std::string_view matching_preset(const Config &cfg) {
    for (const auto &p : kPresets) {
        const bool all = std::all_of(p.values.begin(), p.values.end(),
                                     [&cfg](const KV &kv) { return cfg.get(kv.first) == kv.second; });
        if (all) return p.name;
    }
    return "custom";
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

bool Config::is_blacklisted(std::string_view package) const {
    return std::find(blacklist.begin(), blacklist.end(), package) != blacklist.end();
}

bool Config::is_whitelisted(std::string_view package) const {
    return std::find(whitelist.begin(), whitelist.end(), package) != whitelist.end();
}

std::string_view to_string(Level l) {
    switch (l) {
    case Level::Stock: return "stock";
    case Level::Relaxed: return "relaxed";
    case Level::Max: return "max";
    }
    return "stock";
}

std::string_view to_string(Scenario s) {
    switch (s) {
    case Scenario::Game: return "game";
    case Scenario::Social: return "social";
    case Scenario::Media: return "media";
    case Scenario::Other: return "other";
    }
    return "other";
}

std::vector<std::string> Config::default_social_apps() {
    return {
        "com.whatsapp", "com.whatsapp.w4b", "org.telegram.messenger", "org.thunderdog.challegram",
        "com.instagram.android", "com.instagram.barcelona", "com.facebook.katana", "com.facebook.lite",
        "com.facebook.orca", "com.zhiliaoapp.musically", "com.ss.android.ugc.trill", "com.twitter.android",
        "com.snapchat.android", "com.discord", "jp.naver.line.android", "com.reddit.frontpage",
        "com.pinterest", "com.linkedin.android", "com.tencent.mm", "com.viber.voip",
    };
}

std::vector<std::string> Config::default_media_apps() {
    return {
        "com.google.android.youtube", "app.revanced.android.youtube", "com.google.android.apps.youtube.music",
        "com.netflix.mediaclient", "com.spotify.music", "com.amazon.avod.thirdpartyclient",
        "com.disney.disneyplus", "in.startv.hotstar", "com.vidio.android", "tv.twitch.android.app",
        "com.vuclip.viu", "com.iqiyi.i18n", "com.tencent.qqlivei18n", "com.hbo.hbonow",
        "org.videolan.vlc", "com.mxtech.videoplayer.ad", "com.mxtech.videoplayer.pro", "is.xyz.mpv",
        "com.apple.android.music", "deezer.android.app",
    };
}

std::optional<Scenario> Config::app_scenario(std::string_view package) const {
    const auto in = [package](const std::vector<std::string> &l) {
        return std::find(l.begin(), l.end(), package) != l.end();
    };
    if (in(social_apps)) return Scenario::Social;
    if (in(media_apps)) return Scenario::Media;
    if (in(whitelist)) return Scenario::Other;
    return std::nullopt;
}

Level Config::level_for(Scenario s) const {
    switch (s) {
    case Scenario::Game: return game_level;
    case Scenario::Social: return social_level;
    case Scenario::Media: return media_level;
    case Scenario::Other: return Level::Relaxed;
    }
    return Level::Stock;
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
