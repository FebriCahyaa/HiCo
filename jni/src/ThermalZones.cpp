/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "ThermalZones.hpp"

#include "Fs.hpp"

#include <algorithm>
#include <array>

namespace hico::thermal {

namespace {

// Zone type names seen on Qualcomm (tsens), MediaTek, Exynos, Tensor, Unisoc and Kirin.
constexpr std::array kBatteryHints{
    "battery", "batt", "bms", "bcl", "vbat", "ibat", "socd", "charger", "chg", "usb", "pmic", "pm8", "pm7",
    "pmk", "pmr", "pmx", "smb", "qg", "fg", "mtktsbattery", "mtktscharger", "mtktsbtsnrpa", "vph",
};
constexpr std::array kCpuHints{
    "cpu", "cpuss", "apc", "tsens_tz_sensor", "mtktscpu", "soc_max", "cluster", "big", "mid", "little",
    "gold", "silver", "prime", "core",
};
constexpr std::array kGpuHints{"gpu", "g3d", "mali", "gpuss", "kgsl"};
constexpr std::array kPerfCoolingHints{"cpufreq", "cpu", "cluster", "gpu", "devfreq", "thermal-cpufreq", "mali", "kgsl", "cdsp", "apc"};

template <size_t N>
bool matches(std::string_view s, const std::array<const char *, N> &hints) {
    return std::any_of(hints.begin(), hints.end(), [s](const char *h) { return str::icontains(s, h); });
}

} // namespace

ZoneKind classify_zone(std::string_view type) {
    // Battery first: names like "pm8550b-bcl-lvl0" or "cpu-vbat" must stay protected.
    if (matches(type, kBatteryHints)) return ZoneKind::Battery;
    if (matches(type, kGpuHints)) return ZoneKind::Gpu;
    if (matches(type, kCpuHints)) return ZoneKind::Cpu;
    return ZoneKind::Other;
}

bool is_performance_cooling(std::string_view type) {
    // Battery / charging current limiters are cooling devices too; never release them.
    if (str::icontains(type, "batt") || str::icontains(type, "charge") || str::icontains(type, "bcl") ||
        str::icontains(type, "vbat") || str::icontains(type, "ibat")) {
        return false;
    }
    return matches(type, kPerfCoolingHints);
}

std::optional<double> normalize_temp(long long raw) {
    double c = 0;
    if (raw >= 1000 || raw <= -1000) c = static_cast<double>(raw) / 1000.0; // millidegrees (kernel ABI)
    else if (raw >= 200 || raw <= -200) c = static_cast<double>(raw) / 10.0; // decidegrees (some vendors)
    else c = static_cast<double>(raw);                                         // degrees
    if (c < -40.0 || c > 150.0) return std::nullopt;
    return c;
}

std::optional<double> Zone::temp_c() const {
    const auto raw = fs::read_int(dir + "/temp");
    if (!raw) return std::nullopt;
    return normalize_temp(*raw);
}

std::vector<Zone> zones() {
    std::vector<Zone> out;
    for (const auto &name : fs::list_dir(kThermalClass)) {
        if (!name.starts_with("thermal_zone")) continue;
        Zone z;
        z.dir = std::string(kThermalClass) + "/" + name;
        z.type = fs::read(z.dir + "/type", 128).value_or("");
        z.kind = classify_zone(z.type);
        out.push_back(std::move(z));
    }
    return out;
}

std::vector<CoolingDevice> cooling_devices() {
    std::vector<CoolingDevice> out;
    for (const auto &name : fs::list_dir(kThermalClass)) {
        if (!name.starts_with("cooling_device")) continue;
        CoolingDevice d;
        d.dir = std::string(kThermalClass) + "/" + name;
        d.type = fs::read(d.dir + "/type", 128).value_or("");
        out.push_back(std::move(d));
    }
    return out;
}

Temperatures read_temperatures(const std::vector<Zone> &cache) {
    Temperatures t;
    const auto keep_max = [](std::optional<double> &slot, std::optional<double> v) {
        if (v && (!slot || *v > *slot)) slot = v;
    };

    for (const auto &z : cache) {
        if (z.kind == ZoneKind::Cpu) keep_max(t.cpu, z.temp_c());
        else if (z.kind == ZoneKind::Gpu) keep_max(t.gpu, z.temp_c());
    }

    // The power_supply class reports the cell temperature in decidegrees on every vendor.
    if (const auto raw = fs::read_int("/sys/class/power_supply/battery/temp")) {
        const double c = static_cast<double>(*raw) / 10.0;
        if (c > -40.0 && c < 120.0) t.battery = c;
    }
    if (!t.battery) {
        for (const auto &z : cache) {
            if (z.kind == ZoneKind::Battery && (z.type == "battery" || z.type == "mtktsbattery")) {
                t.battery = z.temp_c();
                break;
            }
        }
    }
    return t;
}

} // namespace hico::thermal
