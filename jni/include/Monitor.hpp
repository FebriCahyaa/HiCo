/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include "ThermalZones.hpp"

#include <optional>
#include <string>
#include <string_view>
#include <vector>

/**
 * Read-only thermal monitor.
 *
 * The monitor intentionally reports only thermal information: zone
 * temperatures, trip thresholds, thermal headroom, thermal states and
 * active cooling devices. CPU/GPU clocks and scheduler/performance metrics
 * belong to other components and are deliberately not exposed here.
 */
namespace hico::monitor {

struct Cooling {
    std::string name;        ///< cooling_deviceN
    std::string type;
    long long cur = 0;
    long long max = 0;
};

struct ZoneReading {
    std::string name;        ///< thermal_zoneN
    std::string type;
    double temp_c = 0;
    std::optional<double> passive_trip_c;   ///< lowest passive trip, if present
    std::optional<double> hot_trip_c;       ///< lowest hot trip, if present
    std::optional<double> critical_trip_c;  ///< lowest critical trip, if present
    std::optional<double> highest_trip_c;   ///< highest trip of any type reported by sysfs
    std::optional<double> next_trip_c;      ///< nearest trip strictly above the current temperature
    std::optional<double> headroom_c;       ///< next_trip_c - temp_c
    std::string policy;                     ///< current kernel thermal governor/policy
    std::string state;                      ///< normal/elevated/mitigating/critical/unknown
    bool at_or_above_trip = false;
    bool protected_zone = false;            ///< battery/charger/PMIC protection zone

    /// Highest threshold currently known for this zone.
    [[nodiscard]] std::optional<double> highest() const { return highest_trip_c; }
};

enum class Verdict { Normal, Elevated, Mitigating, Critical };

struct Snapshot {
    long long time_ms = 0;
    std::vector<Cooling> cooling;   ///< currently active cooling devices (cur_state > 0)
    std::vector<Cooling> cooling_devices; ///< all readable kernel cooling devices
    std::vector<ZoneReading> zones; ///< all readable thermal zones, sorted by severity/temperature
    int tripped_zones = 0;          ///< zones at or above at least one reported trip threshold
    int protected_zones = 0;        ///< battery/charger/PMIC protection zones included in the reading
    thermal::Temperatures temps;    ///< hottest CPU/GPU/battery values for summary consumers

    [[nodiscard]] int active_cooling() const;
    [[nodiscard]] int cooling_device_count() const;
    [[nodiscard]] std::optional<double> hottest_temp_c() const;
    [[nodiscard]] const ZoneReading *hottest_zone() const;
    [[nodiscard]] std::optional<double> closest_headroom_c() const;
    [[nodiscard]] const ZoneReading *closest_zone() const;
    [[nodiscard]] Verdict verdict() const;
};

[[nodiscard]] std::string_view to_string(Verdict v);

/// Samples all readable thermal zones by default. @p max_zones may limit the result for CLI callers.
[[nodiscard]] Snapshot sample(size_t max_zones = 0);

[[nodiscard]] std::string to_json(const Snapshot &s);
/// One line for `hicod monitor` in a terminal.
[[nodiscard]] std::string to_line(const Snapshot &s);
/// Tabular thermal view used by `hicod thermal table`.
[[nodiscard]] std::string to_table(const Snapshot &s);

} // namespace hico::monitor
