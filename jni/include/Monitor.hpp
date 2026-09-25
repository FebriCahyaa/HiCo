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
#include <vector>

/**
 * Live throttling monitor: what the kernel is actually allowing right now.
 *
 * Read-only. Every value comes from the kernel's effective limits, not from
 * HiCo's own settings: scaling_max_freq is the cpufreq policy maximum after
 * every QoS request (thermal cooling devices included), the Adreno thermal
 * power level or devfreq max_freq caps the GPU, and cooling devices report
 * their current state. A limit below the hardware maximum is throttling.
 */
namespace hico::monitor {

struct Cluster {
    std::string name;        ///< policyN
    std::string cpus;        ///< "0-3"
    int cores = 0;
    long long cur_mhz = 0;   ///< scaling_cur_freq
    long long min_mhz = 0;   ///< cpuinfo_min_freq
    long long max_mhz = 0;   ///< cpuinfo_max_freq (hardware)
    long long cap_mhz = 0;   ///< scaling_max_freq (effective limit)

    /// Share of the hardware maximum the cluster may use, 0-100.
    [[nodiscard]] int limit_pct() const;
    [[nodiscard]] bool throttled() const { return cap_mhz > 0 && cap_mhz < max_mhz; }
};

struct Gpu {
    std::string source;      ///< "kgsl" or the devfreq device name
    long long cur_mhz = 0;
    long long max_mhz = 0;   ///< highest available frequency
    long long cap_mhz = 0;   ///< current effective maximum
    int thermal_level = -1;  ///< Adreno thermal_pwrlevel (0 = no thermal cap), -1 if unknown

    [[nodiscard]] int limit_pct() const;
    [[nodiscard]] bool throttled() const { return cap_mhz > 0 && cap_mhz < max_mhz; }
};

struct Cooling {
    std::string name;        ///< cooling_deviceN
    std::string type;
    long long cur = 0;
    long long max = 0;
    bool performance = false; ///< throttles CPU or GPU clocks
};

struct ZoneReading {
    std::string name;        ///< thermal_zoneN
    std::string type;
    double temp_c = 0;
    std::optional<double> trip_c; ///< lowest passive / hot trip point
    bool tripped = false;    ///< at or above that trip: the kernel is throttling for it
};

enum class Verdict { None, Light, Heavy };

struct Snapshot {
    long long time_ms = 0;
    std::vector<Cluster> clusters;
    std::optional<Gpu> gpu;
    std::vector<Cooling> cooling;   ///< active devices only (cur_state > 0)
    std::vector<ZoneReading> zones; ///< tripped zones first, then the hottest
    int tripped_zones = 0;
    thermal::Temperatures temps;

    [[nodiscard]] int cpu_limit_pct() const; ///< core-weighted, 0-100
    [[nodiscard]] int active_performance_cooling() const;
    [[nodiscard]] Verdict verdict() const;
};

[[nodiscard]] std::string_view to_string(Verdict v);

/// Samples the current state. @p max_zones bounds the zone list.
[[nodiscard]] Snapshot sample(size_t max_zones = 6);

[[nodiscard]] std::string to_json(const Snapshot &s);
/// One line for `hicod monitor` in a terminal.
[[nodiscard]] std::string to_line(const Snapshot &s);

/// "0 1 2 3 6" -> "0-3,6".
[[nodiscard]] std::string cpu_ranges(const std::vector<int> &cpus);

} // namespace hico::monitor
