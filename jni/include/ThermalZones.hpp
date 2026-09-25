/*
 * Copyright (C) 2026 FebriCahyaa
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <vector>

/**
 * Kernel thermal framework (/sys/class/thermal): zones, sensors and cooling devices.
 */
namespace hico::thermal {

inline constexpr std::string_view kThermalClass = "/sys/class/thermal";

enum class ZoneKind {
    Cpu,       ///< CPU clusters / cores (used by the safety guard)
    Gpu,
    Battery,   ///< battery, charger, PMIC, BCL: never touched
    Other,     ///< skin, modem, ddr, ...
};

struct Zone {
    std::string dir;   ///< /sys/class/thermal/thermal_zoneN
    std::string type;
    ZoneKind kind = ZoneKind::Other;

    [[nodiscard]] std::optional<double> temp_c() const;
    /// Battery zones protect the cell and the charger; HiCo never changes them.
    [[nodiscard]] bool is_protected() const { return kind == ZoneKind::Battery; }
};

struct CoolingDevice {
    std::string dir;   ///< /sys/class/thermal/cooling_deviceN
    std::string type;
};

[[nodiscard]] ZoneKind classify_zone(std::string_view type);
/// Cooling devices that throttle CPU or GPU clocks (released while gaming).
[[nodiscard]] bool is_performance_cooling(std::string_view type);

[[nodiscard]] std::vector<Zone> zones();
[[nodiscard]] std::vector<CoolingDevice> cooling_devices();

/// Converts a raw sensor reading (millidegrees, decidegrees or degrees) to °C; nullopt if implausible.
[[nodiscard]] std::optional<double> normalize_temp(long long raw);

struct Temperatures {
    std::optional<double> cpu;      ///< hottest CPU zone
    std::optional<double> gpu;
    std::optional<double> battery;
};

/// Reads the sensors the safety guard needs. @p cache avoids re-scanning zones every poll.
[[nodiscard]] Temperatures read_temperatures(const std::vector<Zone> &cache);

} // namespace hico::thermal
