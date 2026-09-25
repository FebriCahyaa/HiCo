/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Cpufreq.hpp"

#include "Fs.hpp"

namespace hico::cpufreq {

namespace {
constexpr std::string_view kCpufreqDir = "/sys/devices/system/cpu/cpufreq";
} // namespace

std::vector<Policy> policies() {
    std::vector<Policy> out;
    for (const auto &name : fs::list_dir(kCpufreqDir)) {
        if (!name.starts_with("policy")) continue;
        Policy p;
        p.dir = std::string(kCpufreqDir) + "/" + name;
        p.max_freq = fs::read_int(p.dir + "/cpuinfo_max_freq").value_or(0);
        for (const auto &cpu : str::split(fs::read(p.dir + "/related_cpus").value_or(""), ' ')) {
            if (const auto n = str::to_int(cpu)) p.cpus.push_back(static_cast<int>(*n));
        }
        if (p.cpus.empty()) {
            if (const auto n = str::to_int(std::string_view(name).substr(6))) p.cpus.push_back(static_cast<int>(*n));
        }
        if (p.max_freq > 0) out.push_back(std::move(p));
    }
    return out;
}

} // namespace hico::cpufreq
