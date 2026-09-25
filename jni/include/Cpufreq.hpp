/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <string>
#include <vector>

namespace hico::cpufreq {

struct Policy {
    std::string dir;        ///< /sys/devices/system/cpu/cpufreq/policyN
    std::vector<int> cpus;  ///< related CPUs
    long long max_freq = 0; ///< cpuinfo_max_freq (hardware maximum), kHz
};

/// cpufreq policies with a known hardware maximum.
[[nodiscard]] std::vector<Policy> policies();

} // namespace hico::cpufreq
