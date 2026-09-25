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

#include "ThermalController.hpp"

#include "Fs.hpp"
#include "HiCo.hpp"
#include "Log.hpp"
#include "Props.hpp"
#include "ThermalServices.hpp"

#include <algorithm>
#include <array>
#include <map>

namespace hico {

namespace {

constexpr std::string_view kCpufreqDir = "/sys/devices/system/cpu/cpufreq";
constexpr std::string_view kXiaomiThermal = "/sys/class/thermal/thermal_message";
constexpr std::string_view kMsmPerfMaxFreq = "/sys/module/msm_performance/parameters/cpu_max_freq";
constexpr std::string_view kKgsl = "/sys/class/kgsl/kgsl-3d0";

struct Policy {
    std::string dir;
    std::vector<int> cpus;
    long long max_freq = 0;
};

std::vector<Policy> cpufreq_policies() {
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

bool has_word(std::string_view list, std::string_view word) {
    const auto words = str::split(list, ' ');
    return std::find(words.begin(), words.end(), word) != words.end();
}

} // namespace

bool detect_xiaomi() {
    if (fs::is_dir(kXiaomiThermal)) return true;
    for (const char *prop : {"ro.product.manufacturer", "ro.product.brand", "ro.product.vendor.brand"}) {
        const std::string v = props::get(prop);
        if (str::icontains(v, "xiaomi") || str::icontains(v, "redmi") || str::icontains(v, "poco")) return true;
    }
    return false;
}

ThermalController::ThermalController(Journal &journal)
    : ThermalController(journal, DeviceProfile::detect(HICO_XIAOMI_DEVICES_DIR)) {}

ThermalController::ThermalController(Journal &journal, std::optional<DeviceProfile> profile)
    : journal_(journal), profile_(std::move(profile)),
      xiaomi_(detect_xiaomi() || (profile_ && profile_->has_mi_thermald)) {
    if (profile_) {
        LOGI("device profile: {} {} ({}, {}), {} declared thermal services, from {}", profile_->brand, profile_->model,
             profile_->codename, profile_->platform, profile_->thermal_services.size(), profile_->source);
    } else {
        LOGI("no device profile for '{}': using runtime detection only", device_codename());
    }
}

void ThermalController::scan() {
    if (scanned_) return;
    scanned_ = true;

    // Cooling devices bound to a zone HiCo does not switch keep obeying that
    // zone: battery/BCL protection and zones without a user_space governor.
    std::set<std::string> kept_cdevs;
    for (auto &z : thermal::zones()) {
        const bool switchable =
            !z.is_protected() && has_word(fs::read(z.dir + "/available_policies").value_or(""), "user_space");
        if (switchable) {
            zones_.push_back(std::move(z));
            continue;
        }
        for (const auto &entry : fs::list_dir(z.dir)) {
            if (entry.starts_with("cdev") && entry.find('_') == std::string::npos) {
                const std::string target = fs::link_target_name(z.dir + "/" + entry);
                if (!target.empty()) kept_cdevs.insert(target);
            }
        }
    }

    for (auto &d : thermal::cooling_devices()) {
        const std::string name = d.dir.substr(d.dir.rfind('/') + 1);
        if (thermal::is_performance_cooling(d.type) && !kept_cdevs.contains(name)) cooling_.push_back(std::move(d));
    }

    LOGI("thermal: {} switchable zones, {} releasable cooling devices, xiaomi={}", zones_.size(), cooling_.size(),
         xiaomi_);
}

bool ThermalController::set_node(std::string_view node, std::string_view value) {
    const auto current = fs::read(node, 1024);
    if (!current) return false; // absent on this device
    if (*current == value) return true;

    if (!journal_.record_node(node)) return false;
    if (fs::write_node(node, value)) return true;

    if (warned_.insert(std::string(node)).second) LOGW("cannot write '{}' to {}", value, node);
    return false;
}

int ThermalController::stop_services(const Config &cfg) {
    if (!cfg.stop_thermal_services) return 0;

    int stopped = 0;
    static const std::vector<std::string> kNone;
    for (const auto &svc : services::thermal_services(profile_ ? profile_->thermal_services : kNone)) {
        if (svc.kind == services::Kind::Hal && !cfg.stop_thermal_hal) continue;

        const bool running = svc.state == "running" || svc.state == "restarting";
        if (!running) {
            // Count services HiCo stopped earlier in this session.
            if (journal_.has_service(svc.name)) ++stopped;
            continue;
        }

        // Journal first: a service stopped by HiCo is always restarted on restore.
        journal_.record_service(svc.name);
        if (services::stop(svc.name)) {
            ++stopped;
            LOGI("stopped thermal service {}", svc.name);
        } else if (warned_.insert("svc:" + svc.name).second) {
            LOGW("cannot stop thermal service {}", svc.name);
        }
    }
    return stopped;
}

int ThermalController::switch_zone_governors() {
    int switched = 0;
    for (const auto &z : zones_) {
        if (set_node(z.dir + "/policy", "user_space")) ++switched;
    }
    return switched;
}

int ThermalController::release_cooling_devices() {
    int released = 0;
    for (const auto &d : cooling_) {
        const auto state = fs::read_int(d.dir + "/cur_state");
        if (!state) continue;
        // Not journaled: once the zone governors are restored they recompute
        // every cooling state from the live temperatures.
        if (*state == 0 || fs::write_node(d.dir + "/cur_state", "0")) ++released;
    }
    return released;
}

int ThermalController::lift_cpu_caps(const Config &cfg) {
    if (!cfg.cpu_clock_unlock) return 0;

    int lifted = 0;
    const auto policies = cpufreq_policies();
    std::map<int, long long> cpu_max;

    for (const auto &p : policies) {
        for (int cpu : p.cpus) cpu_max[cpu] = p.max_freq;

        // Flux's profiler sets scaling_max_freq for the profile; thermal drivers
        // lower it while hot. Only re-raise a cap, never journal it: Flux's
        // balance profile owns the value outside games.
        const auto cur = fs::read_int(p.dir + "/scaling_max_freq");
        if (cur && *cur < p.max_freq && fs::write_node(p.dir + "/scaling_max_freq", std::to_string(p.max_freq))) {
            ++lifted;
            LOGD("cpufreq: {} max {} -> {}", p.dir, *cur, p.max_freq);
        }
    }

    // Qualcomm msm_performance: "cpu:freq" pairs; UINT_MAX means "no limit".
    if (const auto current = fs::read(kMsmPerfMaxFreq)) {
        std::string wanted;
        for (const auto &pair : str::split(*current, ' ')) {
            const auto colon = pair.find(':');
            if (colon == std::string::npos) continue;
            const auto cpu = str::to_int(std::string_view(pair).substr(0, colon));
            const auto freq = str::to_int(std::string_view(pair).substr(colon + 1));
            if (!cpu || !freq || !cpu_max.contains(static_cast<int>(*cpu))) continue;
            if (*freq < cpu_max[static_cast<int>(*cpu)]) {
                wanted += std::format("{}:{} ", *cpu, cpu_max[static_cast<int>(*cpu)]);
            }
        }
        if (!wanted.empty() && journal_.record_node(kMsmPerfMaxFreq)) {
            wanted.pop_back();
            if (fs::write_node(kMsmPerfMaxFreq, wanted)) ++lifted;
        }
    }
    return lifted;
}

int ThermalController::lift_gpu_caps() {
    int lifted = 0;
    // kgsl: thermal_pwrlevel is the level the thermal stack caps the GPU at,
    // max_pwrlevel the highest level allowed (0 = fastest).
    if (fs::exists(std::string(kKgsl) + "/thermal_pwrlevel") && set_node(std::string(kKgsl) + "/thermal_pwrlevel", "0")) {
        ++lifted;
    }
    if (fs::exists(std::string(kKgsl) + "/max_pwrlevel") && set_node(std::string(kKgsl) + "/max_pwrlevel", "0")) {
        ++lifted;
    }
    return lifted;
}

int ThermalController::qualcomm_mediatek() {
    struct Tunable {
        std::string_view node;
        std::string_view value;
    };
    // clang-format off
    static constexpr std::array kTunables{
        Tunable{"/sys/module/msm_thermal/parameters/enabled", "N"},   // legacy msm_thermal (pre-4.9 kernels)
        Tunable{"/sys/module/msm_thermal/core_control/enabled", "0"}, // core hotplug on heat
        Tunable{"/sys/kernel/msm_thermal/enabled", "0"},              // msm_thermal v2
        Tunable{"/sys/kernel/eara_thermal/enable", "0"},              // MediaTek EARA thermal
    };
    // clang-format on

    int changed = 0;
    for (const auto &t : kTunables) {
        if (fs::exists(t.node) && set_node(t.node, t.value)) ++changed;
    }
    return changed;
}

int ThermalController::xiaomi(const Config &cfg) {
    if (!xiaomi_ || !fs::is_dir(kXiaomiThermal)) return 0;

    int changed = 0;
    // sconfig selects mi_thermald's thermal scene; PowerKeeper / Joyose also
    // write it when a game starts, which is why it is re-asserted on every poll.
    if (set_node(std::string(kXiaomiThermal) + "/sconfig", std::to_string(cfg.xiaomi_sconfig))) ++changed;

    // cpu_limits ("cpuN freq") is the per-cluster cap the thermal stack pushes
    // to the kernel; a stopped mi_thermald leaves its last cap in place.
    const std::string limits = std::string(kXiaomiThermal) + "/cpu_limits";
    if (cfg.cpu_clock_unlock && fs::exists(limits)) {
        for (const auto &p : cpufreq_policies()) {
            if (!p.cpus.empty() && fs::write_node(limits, std::format("cpu{} {}", p.cpus.front(), p.max_freq))) ++changed;
        }
    }
    return changed;
}

ThermalController::Summary ThermalController::unlock(const Config &cfg) {
    scan();

    Summary s;
    // Daemons first, so they cannot fight the kernel changes below.
    s.services = stop_services(cfg);
    if (cfg.zone_governor) {
        s.zones = switch_zone_governors();
        // Releasing cooling devices only sticks when their zone no longer throttles.
        if (cfg.cooling_reset) s.cooling = release_cooling_devices();
    }
    s.caps = lift_cpu_caps(cfg);
    if (cfg.gpu_unlock) s.caps += lift_gpu_caps();
    if (cfg.vendor_tweaks) s.vendor = qualcomm_mediatek();
    if (cfg.xiaomi_tweaks) s.vendor += xiaomi(cfg);
    return s;
}

Journal::RestoreResult ThermalController::restore() {
    const auto r = journal_.restore();
    warned_.clear();
    return r;
}

} // namespace hico
