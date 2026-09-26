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
        LOGI("device: {} {} ({}, {} {}), {} declared thermal services", device_.brand, device_.model,
             device_.codename, to_string(device_.soc), device_.platform, device_.thermal_services.size());
        LOGD("device record: {}", device_.source);
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
    // The latter are released in extreme mode only, after their passive trips
    // were raised; battery-bound devices are never released.
    std::set<std::string> protected_cdevs;
    std::set<std::string> fixed_cdevs;
    const auto bound_cdevs = [](const thermal::Zone &z, std::set<std::string> &into) {
        for (const auto &entry : fs::list_dir(z.dir)) {
            if (entry.starts_with("cdev") && entry.find('_') == std::string::npos) {
                const std::string target = fs::link_target_name(z.dir + "/" + entry);
                if (!target.empty()) into.insert(target);
            }
        }
    };
    for (auto &z : thermal::zones()) {
        if (z.is_protected()) {
            bound_cdevs(z, protected_cdevs);
            continue;
        }
        if (has_word(fs::read(z.dir + "/available_policies").value_or(""), "user_space")) {
            zones_.push_back(std::move(z));
            continue;
        }
        bound_cdevs(z, fixed_cdevs);
        fixed_zones_.push_back(std::move(z));
    }

    for (auto &d : thermal::cooling_devices()) {
        const std::string name = d.dir.substr(d.dir.rfind('/') + 1);
        if (!thermal::is_performance_cooling(d.type) || protected_cdevs.contains(name)) continue;
        if (fixed_cdevs.contains(name)) fixed_cooling_.push_back(std::move(d));
        else cooling_.push_back(std::move(d));
    }

    plan_passive_trips();
    LOGI("thermal: {} switchable zones, {} releasable cooling devices, {} fixed zones ({} cooling devices, extreme mode)",
         zones_.size(), cooling_.size(), fixed_zones_.size(), fixed_cooling_.size());
}

int ThermalController::stop_services(const Config &cfg) {
    if (!cfg.stop_thermal_services) return 0;

    int stopped = 0;
    for (const auto &svc : services::thermal_services(device_.thermal_services)) {
        // Extreme mode stops the HAL too: on AOSP ROMs it is the thermal-engine replacement.
        if (svc.kind == services::Kind::Hal && !cfg.stop_thermal_hal && cfg.mode != Mode::Extreme) continue;

        const bool running = svc.state == "running" || svc.state == "restarting";
        if (!running) {
            // Count services HiCo stopped earlier in this session.
            if (journal_.has_service(svc.name)) ++stopped;
            continue;
        }
        if (respawning_.contains(svc.name)) continue;
        // Stopped by HiCo and running again: init or servicemanager restarts it on demand (lazy
        // AIDL thermal HALs come back as soon as the framework asks). Stopping it on every poll
        // only makes it re-initialise and re-apply its limits each second, which stutters worse
        // than leaving it alone: after a few returns it is left running for this session.
        if (journal_.has_service(svc.name) && ++respawns_[svc.name] >= kMaxRespawns) {
            respawning_.insert(svc.name);
            LOGW("thermal service {} is restarted by the system each time it is stopped; left running "
                 "(its cooling devices are still released every poll)",
                 svc.name);
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

/**
 * Extreme mode, zones whose governor cannot be switched: raise their passive
 * trips (Linux: trip_point_N_temp is writable with CONFIG_THERMAL_WRITABLE_TRIPS,
 * enabled on GKI) by up to 15 °C, always staying 5 °C below the zone's own
 * critical/hot trip, so the kernel still shuts the device down in time.
 * Journaled: restore() writes the stock trips back.
 */
int ThermalController::raise_passive_trips() {
    int raised = 0;
    for (const auto &[node, target] : trip_targets_) {
        if (act_.set(node, std::to_string(target))) ++raised;
    }
    return raised;
}

/// Target temperatures for the passive trips of fixed zones, from their stock values (scan()).
void ThermalController::plan_passive_trips() {
    for (const auto &z : fixed_zones_) {
        std::optional<long long> ceiling;
        std::vector<std::pair<std::string, long long>> passive;
        for (int i = 0; i < 32; ++i) {
            const std::string base = z.dir + "/trip_point_" + std::to_string(i);
            const auto type = fs::read(base + "_type");
            if (!type) break;
            const auto temp = fs::read_int(base + "_temp");
            if (!temp || *temp <= 0) continue;
            const std::string t = str::trim(*type);
            if (t == "critical" || t == "hot") {
                if (!ceiling || *temp < *ceiling) ceiling = *temp;
            } else if (t == "passive") {
                passive.emplace_back(base + "_temp", *temp);
            }
        }
        for (const auto &[node, temp] : passive) {
            // Millidegrees (kernel ABI); a zone without a critical trip stops at 105 °C.
            const long long limit = ceiling ? *ceiling - 5000 : 105000;
            const long long target = std::min(temp + 15000, limit);
            if (target > temp) trip_targets_.emplace_back(node, target);
        }
    }
}

/// Thermal overclock: boost frequencies (cpufreq core "boost", drivers with boost OPPs).
bool ThermalController::enable_cpufreq_boost() {
    constexpr std::string_view kBoost = "/sys/devices/system/cpu/cpufreq/boost";
    return fs::exists(kBoost) && act_.set(kBoost, "1");
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
    if (cfg.mode == Mode::Extreme) {
        s.trips = raise_passive_trips();
        if (cfg.cooling_reset) {
            for (const auto &d : fixed_cooling_) {
                const auto state = fs::read_int(d.dir + "/cur_state");
                if (state && (*state == 0 || act_.poke(d.dir + "/cur_state", "0"))) ++s.cooling;
            }
        }
    }
    if (cfg.thermal_overclock) s.overclock = enable_cpufreq_boost();
    s.caps = lift_cpufreq_caps(cfg);
    for (auto &b : backends_) {
        const auto r = b->unlock(act_, cfg);
        s.caps += r.caps;
        s.vendor += r.vendor;
    }
    return s;
}

int ThermalController::relax(const Config &cfg) {
    // Thermal overclock uses the widest margin; the tuner's hard caps still apply.
    auto policy = thermalcfg::policy_for(device_.soc, device_.platform, cfg.thermal_overclock ? 10 : cfg.relax_margin);
    const auto files = thermalcfg::device_config_files();
    // mi_thermald: this device's own highest trip per device/sensor (nolimits, game scenes)
    // bounds every tuned section, so the template follows Xiaomi's data for this phone.
    for (const auto &path : files) {
        if (journal_.has_mount(path) || fs::is_mounted(path)) continue;
        const auto raw = fs::read_raw(path, 512 * 1024);
        if (!raw) continue;
        const auto fmt = thermalcfg::detect_format(*raw);
        if (fmt != thermalcfg::Format::MiThermald && fmt != thermalcfg::Format::MiEncrypted) continue;
        if (const auto plain = thermalcfg::plain_text(*raw)) thermalcfg::mithermald::collect_ceilings(*plain, policy.mi_ceilings);
    }

    struct Pending {
        std::string target;
        std::string tuned;
        bool hal = false; ///< thermal HAL JSON: the HAL must be restarted to read it
    };
    std::vector<Pending> pending;
    int relaxed = 0;
    for (const auto &path : files) {
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
        pending.push_back({path, result->text, thermalcfg::detect_format(*original) == thermalcfg::Format::HalJson});
    }
    if (pending.empty()) return relaxed;

    if (!fs::ensure_dir(HICO_RUNTIME_DIR "/thermal", 0755)) return relaxed;

    // Restarts are journaled before the mounts, so a restore unmounts first and then restarts.
    // Engine configs are read by the thermal daemons; HAL JSON by the thermal HAL (AOSP-based ROMs).
    const bool hal_configs = std::any_of(pending.begin(), pending.end(), [](const Pending &p) { return p.hal; });
    const bool engine_configs = std::any_of(pending.begin(), pending.end(), [](const Pending &p) { return !p.hal; });
    std::vector<std::string> daemons;
    for (const auto &svc : services::thermal_services(device_.thermal_services)) {
        const bool wanted = svc.kind == services::Kind::Hal ? hal_configs : engine_configs;
        if (wanted && (svc.state == "running" || svc.state == "restarting")) {
            journal_.record_restart(svc.name);
            daemons.push_back(svc.name);
        }
    }

    std::vector<std::string> tuned_names;
    for (const auto &p : pending) {
        std::string flat = p.target.substr(1);
        std::replace(flat.begin(), flat.end(), '/', '_');
        const std::string source = std::string(HICO_RUNTIME_DIR "/thermal/") + flat;
        if (!fs::write_atomic(source, p.tuned, 0644)) continue;
        journal_.record_mount(p.target);
        if (fs::bind_mount(source, p.target)) {
            ++relaxed;
            tuned_names.push_back(p.target.substr(p.target.rfind('/') + 1));
            LOGD("relaxed thermal config {} ({} policy)", p.target, policy.name);
        } else {
            LOGW("relax: cannot bind-mount over {}", p.target);
        }
    }
    if (!tuned_names.empty()) {
        // One line instead of one per file (garnet has 17): the list is still there to check.
        std::string list;
        for (const auto &n : tuned_names) list += (list.empty() ? "" : ", ") + n;
        LOGI("relaxed {} of this phone's thermal configs ({} policy): {}", tuned_names.size(), policy.name, list);
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
    respawns_.clear();
    respawning_.clear();
    return r;
}

} // namespace hico
