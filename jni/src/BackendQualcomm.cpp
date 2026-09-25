/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "ThermalBackend.hpp"

#include "Cpufreq.hpp"
#include "Fs.hpp"
#include "Log.hpp"

#include <algorithm>
#include <array>
#include <format>
#include <map>

namespace hico {

namespace {

constexpr std::string_view kKgsl = "/sys/class/kgsl/kgsl-3d0";
constexpr std::string_view kMsmPerfMaxFreq = "/sys/module/msm_performance/parameters/cpu_max_freq";

struct Tunable {
    std::string_view node;
    std::string_view value;
};

// clang-format off
constexpr std::array kThermalDrivers{
    Tunable{"/sys/module/msm_thermal/parameters/enabled", "N"},   // legacy msm_thermal (pre-4.9 kernels)
    Tunable{"/sys/module/msm_thermal/core_control/enabled", "0"}, // core hotplug on heat
    Tunable{"/sys/kernel/msm_thermal/enabled", "0"},              // msm_thermal v2
};
// clang-format on

/// Qualcomm: msm_thermal, msm_performance CPU caps and the Adreno (kgsl) thermal power level.
class QualcommBackend final : public ThermalBackend {
public:
    std::string_view name() const override { return "qualcomm"; }

    bool applies(const DeviceProfile &d) const override {
        if (d.soc == SocVendor::Qualcomm) return true;
        if (d.soc != SocVendor::Unknown) return false;
        // Not in the database and no recognisable platform: go by what the kernel exposes.
        return fs::is_dir(kKgsl) || fs::exists(kMsmPerfMaxFreq) ||
               std::any_of(kThermalDrivers.begin(), kThermalDrivers.end(), [](const Tunable &t) { return fs::exists(t.node); });
    }

    Result unlock(Actuator &act, const Config &cfg) override {
        Result r;
        if (cfg.vendor_tweaks) {
            for (const auto &t : kThermalDrivers) {
                if (act.set(t.node, t.value)) ++r.vendor;
            }
        }
        if (cfg.gpu_unlock) {
            // thermal_pwrlevel: level the thermal stack caps the GPU at; max_pwrlevel: highest allowed (0 = fastest).
            if (act.set(std::string(kKgsl) + "/thermal_pwrlevel", "0")) ++r.caps;
            if (act.set(std::string(kKgsl) + "/max_pwrlevel", "0")) ++r.caps;
        }
        if (cfg.cpu_clock_unlock) r.caps += lift_msm_performance(act);
        return r;
    }

private:
    /// msm_performance cpu_max_freq: "cpu:freq" pairs, UINT_MAX meaning "no limit".
    static int lift_msm_performance(Actuator &act) {
        const auto current = fs::read(kMsmPerfMaxFreq);
        if (!current) return 0;

        std::map<int, long long> cpu_max;
        for (const auto &p : cpufreq::policies()) {
            for (int cpu : p.cpus) cpu_max[cpu] = p.max_freq;
        }
        std::string wanted;
        for (const auto &pair : str::split(*current, ' ')) {
            const auto colon = pair.find(':');
            if (colon == std::string::npos) continue;
            const auto cpu = str::to_int(std::string_view(pair).substr(0, colon));
            const auto freq = str::to_int(std::string_view(pair).substr(colon + 1));
            if (!cpu || !freq || !cpu_max.contains(static_cast<int>(*cpu))) continue;
            const long long max = cpu_max[static_cast<int>(*cpu)];
            if (*freq < max) wanted += std::format("{}:{} ", *cpu, max);
        }
        if (wanted.empty() || !act.journal().record_node(kMsmPerfMaxFreq)) return 0;
        wanted.pop_back();
        return act.poke(kMsmPerfMaxFreq, wanted) ? 1 : 0;
    }
};

} // namespace

std::unique_ptr<ThermalBackend> make_qualcomm_backend() {
    return std::make_unique<QualcommBackend>();
}

} // namespace hico
