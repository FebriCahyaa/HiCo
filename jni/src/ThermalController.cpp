/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "ThermalController.hpp"

#include "Cpufreq.hpp"
#include "HiCo.hpp"
#include "ThermalConfig.hpp"
#include "Fs.hpp"
#include "Log.hpp"
#include "ThermalServices.hpp"

#include <algorithm>
#include <array>
#include <set>

namespace hico {

namespace {

bool has_word(std::string_view list, std::string_view word) {
    const auto words = str::split(list, ' ');
    return std::find(words.begin(), words.end(), word) != words.end();
}

} // namespace

ThermalController::ThermalController(Journal &journal) : ThermalController(journal, DeviceProfile::detect()) {}

ThermalController::ThermalController(Journal &journal, DeviceProfile device)
    : journal_(journal), act_(journal), device_(std::move(device)), xiaomi_(is_xiaomi_device(device_)),
      backends_(make_backends(device_)) {
    if (device_.in_database) {
        LOGI("device: {} {} ({}, {} {}), {} declared thermal services, from {}", device_.brand, device_.model,
             device_.codename, to_string(device_.soc), device_.platform, device_.thermal_services.size(), device_.source);
    } else {
        LOGI("device '{}' ({}) is not in the device database ({}): runtime detection only", device_.codename,
             to_string(device_.soc), device_db::generated_from());
    }
    LOGI("thermal backends: {}", backend_names().empty() ? "none" : backend_names());
}

std::string ThermalController::backend_names() const {
    std::string out;
    for (const auto &b : backends_) {
        if (!out.empty()) out += ',';
        out += b->name();
    }
    return out;
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

    LOGI("thermal: {} switchable zones, {} releasable cooling devices", zones_.size(), cooling_.size());
}

int ThermalController::stop_services(const Config &cfg) {
    if (!cfg.stop_thermal_services) return 0;

    int stopped = 0;
    for (const auto &svc : services::thermal_services(device_.thermal_services)) {
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
        } else if (warned_services_.insert(svc.name).second) {
            LOGW("cannot stop thermal service {}", svc.name);
        }
    }
    return stopped;
}

int ThermalController::switch_zone_governors() {
    int switched = 0;
    for (const auto &z : zones_) {
        if (act_.set(z.dir + "/policy", "user_space")) ++switched;
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
        if (*state == 0 || act_.poke(d.dir + "/cur_state", "0")) ++released;
    }
    return released;
}

int ThermalController::lift_cpufreq_caps(const Config &cfg) {
    if (!cfg.cpu_clock_unlock) return 0;

    int lifted = 0;
    for (const auto &p : cpufreq::policies()) {
        // Flux's profiler sets scaling_max_freq for the profile; thermal drivers
        // lower it while hot. Only re-raise a cap, never journal it: Flux's
        // balance profile owns the value outside games.
        const auto cur = fs::read_int(p.dir + "/scaling_max_freq");
        if (cur && *cur < p.max_freq && act_.poke(p.dir + "/scaling_max_freq", std::to_string(p.max_freq))) {
            ++lifted;
            LOGD("cpufreq: {} max {} -> {}", p.dir, *cur, p.max_freq);
        }
    }
    return lifted;
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
    s.caps = lift_cpufreq_caps(cfg);
    for (auto &b : backends_) {
        const auto r = b->unlock(act_, cfg);
        s.caps += r.caps;
        s.vendor += r.vendor;
    }
    return s;
}

int ThermalController::relax(const Config &cfg) {
    const auto policy = thermalcfg::policy_for(device_.soc, device_.platform, cfg.relax_margin);

    struct Pending {
        std::string target;
        std::string tuned;
    };
    std::vector<Pending> pending;
    int relaxed = 0;
    for (const auto &path : thermalcfg::device_config_files()) {
        // Already overlaid (this session or a crashed one): never tune a tuned file again.
        if (journal_.has_mount(path) || fs::is_mounted(path)) {
            ++relaxed;
            continue;
        }
        const auto original = fs::read_raw(path, 512 * 1024);
        if (!original) continue;
        const auto result = thermalcfg::tune(*original, policy);
        if (!result || result->tuned_sections == 0) continue;
        if (const auto errors = thermalcfg::verify(*original, result->text, policy); !errors.empty()) {
            LOGW("relax: {} rejected by verification: {}", path, errors.front());
            continue;
        }
        pending.push_back({path, result->text});
    }
    if (pending.empty()) return relaxed;

    if (!fs::ensure_dir(HICO_RUNTIME_DIR "/thermal", 0755)) return relaxed;

    // Restarts are journaled before the mounts, so a restore unmounts first and then restarts.
    std::vector<std::string> daemons;
    for (const auto &svc : services::thermal_services(device_.thermal_services)) {
        if (svc.kind == services::Kind::Daemon && (svc.state == "running" || svc.state == "restarting")) {
            journal_.record_restart(svc.name);
            daemons.push_back(svc.name);
        }
    }

    for (const auto &p : pending) {
        std::string flat = p.target.substr(1);
        std::replace(flat.begin(), flat.end(), '/', '_');
        const std::string source = std::string(HICO_RUNTIME_DIR "/thermal/") + flat;
        if (!fs::write_atomic(source, p.tuned, 0644)) continue;
        journal_.record_mount(p.target);
        if (fs::bind_mount(source, p.target)) {
            ++relaxed;
            LOGI("relaxed thermal config {} ({} policy)", p.target, policy.name);
        } else {
            LOGW("relax: cannot bind-mount over {}", p.target);
        }
    }
    for (const auto &d : daemons) {
        if (services::restart(d)) LOGI("restarted thermal service {} to load relaxed configs", d);
    }
    return relaxed;
}

Journal::RestoreResult ThermalController::restore() {
    const auto r = journal_.restore();
    act_.reset_warnings();
    warned_services_.clear();
    return r;
}

} // namespace hico
