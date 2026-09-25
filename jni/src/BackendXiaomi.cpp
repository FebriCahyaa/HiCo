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

#include <format>

namespace hico {

namespace {

constexpr std::string_view kThermalMessage = "/sys/class/thermal/thermal_message";

/// Xiaomi / Redmi / POCO: mi_thermald's thermal scene and per-cluster CPU limits.
class XiaomiBackend final : public ThermalBackend {
public:
    std::string_view name() const override { return "xiaomi"; }

    bool applies(const DeviceProfile &d) const override { return is_xiaomi_device(d); }

    Result unlock(Actuator &act, const Config &cfg) override {
        Result r;
        if (!cfg.xiaomi_tweaks || !fs::is_dir(kThermalMessage)) return r;

        // sconfig selects mi_thermald's thermal scene; PowerKeeper / Joyose also
        // write it when a game starts, which is why it is re-asserted on every poll.
        if (act.set(std::string(kThermalMessage) + "/sconfig", std::to_string(cfg.xiaomi_sconfig))) ++r.vendor;

        // cpu_limits ("cpuN freq") is the per-cluster cap the thermal stack pushes to
        // the kernel; a stopped mi_thermald leaves its last cap in place.
        const std::string limits = std::string(kThermalMessage) + "/cpu_limits";
        if (cfg.cpu_clock_unlock && fs::exists(limits)) {
            for (const auto &p : cpufreq::policies()) {
                if (!p.cpus.empty() && act.poke(limits, std::format("cpu{} {}", p.cpus.front(), p.max_freq))) ++r.vendor;
            }
        }
        return r;
    }
};

} // namespace

std::unique_ptr<ThermalBackend> make_xiaomi_backend() {
    return std::make_unique<XiaomiBackend>();
}

} // namespace hico
