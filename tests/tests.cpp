/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

// Host unit tests. Every device path is redirected under a temporary
// $HICO_ROOT holding a simulated Snapdragon / Xiaomi device with Flux installed.

#include "Config.hpp"
#include "Daemon.hpp"
#include "DeviceDatabase.hpp"
#include "DeviceProfile.hpp"
#include "FluxLink.hpp"
#include "Fs.hpp"
#include "HiCo.hpp"
#include "Journal.hpp"
#include "Log.hpp"
#include "MiCrypt.hpp"
#include "Monitor.hpp"
#include "Props.hpp"
#include "SafetyGuard.hpp"
#include "Sessions.hpp"
#include "ThermalBackend.hpp"
#include "ThermalConfig.hpp"
#include "ThermalController.hpp"
#include "ThermalServices.hpp"
#include "ThermalZones.hpp"

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace hico;
using namespace std::chrono_literals;
namespace stdfs = std::filesystem;

namespace {

int g_failures = 0;
int g_checks = 0;
std::string g_root;

#define CHECK(cond)                                                                                                    \
    do {                                                                                                               \
        ++g_checks;                                                                                                    \
        if (!(cond)) {                                                                                                 \
            ++g_failures;                                                                                              \
            std::cerr << "  FAIL " << __FILE__ << ":" << __LINE__ << ": " #cond "\n";                                  \
        }                                                                                                              \
    } while (0)

#define CHECK_EQ(a, b)                                                                                                 \
    do {                                                                                                               \
        ++g_checks;                                                                                                    \
        const auto va_ = (a);                                                                                          \
        const auto vb_ = (b);                                                                                          \
        if (!(va_ == vb_)) {                                                                                           \
            ++g_failures;                                                                                              \
            std::cerr << "  FAIL " << __FILE__ << ":" << __LINE__ << ": " #a " == " #b "\n";                           \
        }                                                                                                              \
    } while (0)

void put(const std::string &path, const std::string &content) {
    const stdfs::path p = g_root + path;
    stdfs::create_directories(p.parent_path());
    FILE *f = std::fopen(p.c_str(), "w");
    std::fputs(content.c_str(), f);
    std::fclose(f);
}

std::string get(const std::string &path) {
    return fs::read(path, 1 << 20).value_or("<missing>");
}

void link(const std::string &target, const std::string &path) {
    stdfs::create_symlink(target, g_root + path);
}

void zone(int n, const std::string &type, int milli_c, const std::string &policies = "step_wise user_space") {
    const std::string d = "/sys/class/thermal/thermal_zone" + std::to_string(n);
    put(d + "/type", type + "\n");
    put(d + "/temp", std::to_string(milli_c) + "\n");
    put(d + "/policy", "step_wise\n");
    put(d + "/available_policies", policies + "\n");
}

void cdev(int n, const std::string &type, int state) {
    const std::string d = "/sys/class/thermal/cooling_device" + std::to_string(n);
    put(d + "/type", type + "\n");
    put(d + "/cur_state", std::to_string(state) + "\n");
    put(d + "/max_state", "10\n");
}

void set_cpu_temp(int milli_c) {
    put("/sys/class/thermal/thermal_zone0/temp", std::to_string(milli_c) + "\n");
}

void set_battery_temp(int deci_c) {
    put("/sys/class/power_supply/battery/temp", std::to_string(deci_c) + "\n");
}

/// Flux Tweaks installed, running (fluxd in /proc), balance profile.
void install_flux() {
    put("/data/adb/modules/flux/system/bin/fluxd", "");
    put("/data/adb/modules/flux/module.prop",
        "id=flux\nname=Flux Tweaks\nversion=1.2.1 (48-15d4f05-release)\nversionCode=48\n");
    put("/data/adb/.config/flux/current_profile", "3\n");
    put("/data/adb/.config/flux/gameinfo", "NULL 0 0\n");
    put("/proc/4242/comm", "fluxd\n");
}

void start_game(const std::string &pkg, int profile = 1) {
    put("/proc/31337/comm", pkg + "\n");
    put("/data/adb/.config/flux/gameinfo", pkg + " 31337 10123\n");
    put("/data/adb/.config/flux/current_profile", std::to_string(profile) + "\n");
}

void stop_game() {
    put("/data/adb/.config/flux/gameinfo", "NULL 0 0\n");
    put("/data/adb/.config/flux/current_profile", "3\n");
}

/// A Snapdragon Xiaomi phone with the usual thermal stack.
void build_device() {
    stdfs::remove_all(g_root);
    stdfs::create_directories(g_root + HICO_RUNTIME_DIR);
    stdfs::create_directories(g_root + HICO_CONFIG_DIR);

    zone(0, "cpu-1-0-usr", 45000);
    zone(1, "battery", 35000);
    zone(2, "gpuss-0-usr", 50000);
    zone(3, "skin-msm-therm", 38000, "step_wise"); // no user_space governor
    zone(4, "pm8550b-bcl-lvl0", 0);
    cdev(0, "thermal-cpufreq-0", 3);
    cdev(1, "gpu", 2);
    cdev(2, "thermal-cpufreq-1", 1); // bound to the battery zone: must be kept
    cdev(3, "battery", 1);
    cdev(4, "cpu-isolate0", 1); // bound to the skin zone (not switchable): kept
    link("../cooling_device0", "/sys/class/thermal/thermal_zone0/cdev0");
    link("../cooling_device2", "/sys/class/thermal/thermal_zone1/cdev0");
    link("../cooling_device4", "/sys/class/thermal/thermal_zone3/cdev0");
    put("/sys/class/thermal/thermal_zone0/cdev0_trip_point", "1\n");

    set_battery_temp(350);

    put("/sys/devices/system/cpu/cpufreq/policy0/cpuinfo_max_freq", "2016000\n");
    put("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq", "1497600\n");
    put("/sys/devices/system/cpu/cpufreq/policy0/related_cpus", "0 1 2 3\n");
    put("/sys/devices/system/cpu/cpufreq/policy4/cpuinfo_max_freq", "3187200\n");
    put("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq", "3187200\n");
    put("/sys/devices/system/cpu/cpufreq/policy4/related_cpus", "4 5 6 7\n");
    put("/sys/module/msm_performance/parameters/cpu_max_freq",
        "0:1497600 1:1497600 2:1497600 3:1497600 4:4294967295 5:4294967295 6:4294967295 7:4294967295\n");
    put("/sys/class/kgsl/kgsl-3d0/thermal_pwrlevel", "3\n");
    put("/sys/class/kgsl/kgsl-3d0/max_pwrlevel", "0\n");
    put("/sys/module/msm_thermal/parameters/enabled", "Y\n");
    put("/sys/class/thermal/thermal_message/sconfig", "0\n");
    put("/sys/class/thermal/thermal_message/cpu_limits", "\n");

    put("/__props__/init.svc.thermal-engine", "running");
    put("/__props__/init.svc.mi_thermald", "running");
    put("/__props__/init.svc.vendor.thermal-hal-2-0", "running");
    put("/__props__/init.svc.vendor.thermal-symlinks", "stopped");
    put("/__props__/init.svc.surfaceflinger", "running");
    put("/__props__/ro.product.brand", "Xiaomi");

    put(HICO_MODULE_PROP, "id=hico\nname=HiCo Thermal\ndescription=placeholder\n");
    install_flux();
}

void write_config(const std::string &lines) {
    put(HICO_CONFIG_FILE, lines);
}

// ── Tests ──────────────────────────────────────────────────────────────────

void test_monitor() {
    build_device();
    // policy0 is capped at 1497.6 of 2016 MHz (build_device), policy4 runs free.
    put("/sys/devices/system/cpu/cpufreq/policy0/scaling_cur_freq", "1497600\n");
    put("/sys/devices/system/cpu/cpufreq/policy0/cpuinfo_min_freq", "300000\n");
    put("/sys/devices/system/cpu/cpufreq/policy4/scaling_cur_freq", "2400000\n");
    put("/sys/devices/system/cpu/cpufreq/policy4/cpuinfo_min_freq", "500000\n");
    // Adreno: thermal_pwrlevel 3 (build_device) caps the GPU at the fourth-fastest level.
    put("/sys/class/kgsl/kgsl-3d0/gpu_available_frequencies", "257000000 680000000 443000000 900000000 587000000\n");
    put("/sys/class/kgsl/kgsl-3d0/gpuclk", "443000000\n");
    // CPU zone at 45 C past its 44 C passive trip; the battery zone past its trip is never counted.
    put("/sys/class/thermal/thermal_zone0/trip_point_0_type", "passive\n");
    put("/sys/class/thermal/thermal_zone0/trip_point_0_temp", "44000\n");
    put("/sys/class/thermal/thermal_zone0/trip_point_1_type", "critical\n");
    put("/sys/class/thermal/thermal_zone0/trip_point_1_temp", "40000\n");
    put("/sys/class/thermal/thermal_zone1/trip_point_0_type", "passive\n");
    put("/sys/class/thermal/thermal_zone1/trip_point_0_temp", "30000\n");
    put("/sys/class/thermal/thermal_zone2/trip_point_0_type", "hot\n");
    put("/sys/class/thermal/thermal_zone2/trip_point_0_temp", "95000\n");

    auto s = monitor::sample();
    CHECK_EQ(s.clusters.size(), 2u);
    const auto &little = s.clusters[0].name == "policy0" ? s.clusters[0] : s.clusters[1];
    const auto &big = s.clusters[0].name == "policy0" ? s.clusters[1] : s.clusters[0];
    CHECK_EQ(little.cpus, std::string("0-3"));
    CHECK_EQ(little.cap_mhz, 1497LL);
    CHECK_EQ(little.max_mhz, 2016LL);
    CHECK_EQ(little.min_mhz, 300LL);
    CHECK(little.throttled());
    CHECK_EQ(little.limit_pct(), 74);
    CHECK(!big.throttled());
    CHECK_EQ(big.limit_pct(), 100);
    CHECK_EQ(big.cur_mhz, 2400LL);
    CHECK_EQ(s.cpu_limit_pct(), 87); // (74*4 + 100*4) / 8

    CHECK(s.gpu.has_value());
    CHECK_EQ(s.gpu->source, std::string("kgsl"));
    CHECK_EQ(s.gpu->max_mhz, 900LL);
    CHECK_EQ(s.gpu->cap_mhz, 443LL); // levels 900, 680, 587, 443, 257: level 3
    CHECK_EQ(s.gpu->cur_mhz, 443LL);
    CHECK_EQ(s.gpu->thermal_level, 3);
    CHECK_EQ(s.gpu->limit_pct(), 49);

    // Active cooling: cpufreq-0 (3), gpu (2), cpufreq-1 (1), battery (1), cpu-isolate0 (1).
    CHECK_EQ(s.cooling.size(), 5u);
    CHECK(s.active_performance_cooling() >= 3);

    CHECK_EQ(s.tripped_zones, 1); // CPU zone only: the battery zone is protected
    CHECK(!s.zones.empty());
    CHECK_EQ(s.zones[0].type, std::string("cpu-1-0-usr"));
    CHECK(s.zones[0].tripped);
    CHECK(s.zones[0].trip_c && *s.zones[0].trip_c == 44.0); // lowest passive/hot, critical ignored
    CHECK(s.verdict() == monitor::Verdict::Heavy);

    const std::string json = monitor::to_json(s);
    CHECK(json.find(R"("verdict":"heavy")") != std::string::npos);
    CHECK(json.find(R"("gpu_limit":49)") != std::string::npos);
    CHECK(json.find(R"("cpus":"0-3")") != std::string::npos);
    CHECK(monitor::to_line(s).find("heavy") == 0);

    // Everything released: no throttling.
    put("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq", "2016000\n");
    put("/sys/class/kgsl/kgsl-3d0/thermal_pwrlevel", "0\n");
    for (int i = 0; i < 5; ++i) put("/sys/class/thermal/cooling_device" + std::to_string(i) + "/cur_state", "0\n");
    set_cpu_temp(40000);
    s = monitor::sample();
    CHECK_EQ(s.cpu_limit_pct(), 100);
    CHECK_EQ(s.gpu->limit_pct(), 100);
    CHECK_EQ(s.tripped_zones, 0);
    CHECK(s.verdict() == monitor::Verdict::None);

    // Only a light cap.
    put("/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq", "2841600\n");
    s = monitor::sample();
    CHECK(s.verdict() == monitor::Verdict::Light);

    CHECK_EQ(monitor::cpu_ranges({0, 1, 2, 3, 6, 7, 5}), std::string("0-3,5-7"));
    CHECK_EQ(monitor::cpu_ranges({4}), std::string("4"));
}

void test_strings_and_paths() {
    CHECK_EQ(str::to_int(" 42\n"), std::optional<long long>(42));
    CHECK_EQ(str::to_int("-7"), std::optional<long long>(-7));
    CHECK(!str::to_int("4x"));
    CHECK(!str::to_int(""));
    CHECK_EQ(str::split("a, b,,c ", ',').size(), 3u);
    CHECK(str::icontains("Vendor.Thermal-Engine", "thermal"));

    CHECK(fs::is_kernel_node("/sys/class/thermal/thermal_zone0/policy"));
    CHECK(fs::is_kernel_node("/proc/sys/kernel/foo"));
    CHECK(!fs::is_kernel_node("/data/adb/modules/flux/module.prop"));
    CHECK(!fs::is_kernel_node("/sys/../data/adb/x"));
    CHECK(!fs::write_node("/data/adb/.config/hico/evil", "1"));
}

void test_config() {
    Config c;
    CHECK(c.mode == Mode::Auto);
    CHECK_EQ(c.safety_cpu_temp, 95);

    CHECK(!c.set("safety_cpu_temp", "90"));
    CHECK_EQ(c.safety_cpu_temp, 90);
    CHECK(c.set("safety_cpu_temp", "130").has_value()); // rejected, not clamped
    CHECK_EQ(c.safety_cpu_temp, 90);
    CHECK(c.set("stop_thermal_hal", "maybe").has_value());
    CHECK(c.set("nope", "1").has_value());
    CHECK(!c.set("mode", "off"));
    CHECK(c.mode == Mode::Off);
    CHECK(!c.set("blacklist", "com.a.b, com.c_d ,com.a.b"));
    CHECK_EQ(c.blacklist.size(), 2u);
    CHECK(c.is_blacklisted("com.c_d"));
    CHECK(c.set("blacklist", "com.a;rm -rf /").has_value());
    CHECK(!c.set("excluded_games", "com.old.name")); // pre-1.0 key maps to blacklist
    CHECK(c.is_blacklisted("com.old.name"));
    CHECK(!c.set("whitelist", "com.android.camera"));
    CHECK(c.is_whitelisted("com.android.camera"));
    CHECK(c.game_level == Level::Max);
    CHECK(!c.set("game_level", "relaxed") && c.game_level == Level::Relaxed);
    CHECK(c.set("game_level", "turbo").has_value());
    CHECK(c.set("relax_margin", "11").has_value());

    // Hand-edited file: out-of-range numbers are clamped, garbage is ignored.
    write_config("safety_cpu_temp=200\nsafety_battery_temp=10\npoll_interval=abc\nunknown=1\nnotify=0\n");
    const Config loaded = Config::load(HICO_CONFIG_FILE);
    CHECK_EQ(loaded.safety_cpu_temp, 105);
    CHECK_EQ(loaded.safety_battery_temp, 38);
    CHECK_EQ(loaded.poll_interval, 2);
    CHECK(!loaded.notify);

    CHECK(c.save(HICO_CONFIG_FILE));
    const Config round = Config::load(HICO_CONFIG_FILE);
    CHECK(round.serialize(false) == c.serialize(false));
    CHECK_EQ(round.get("mode"), std::optional<std::string>("off"));
}

void test_classification() {
    using thermal::ZoneKind;
    CHECK(thermal::classify_zone("cpu-1-0-usr") == ZoneKind::Cpu);
    CHECK(thermal::classify_zone("mtktscpu") == ZoneKind::Cpu);
    CHECK(thermal::classify_zone("BIG") == ZoneKind::Cpu);
    CHECK(thermal::classify_zone("gpuss-0-usr") == ZoneKind::Gpu);
    CHECK(thermal::classify_zone("battery") == ZoneKind::Battery);
    CHECK(thermal::classify_zone("pm8550b-bcl-lvl0") == ZoneKind::Battery);
    CHECK(thermal::classify_zone("cpu-vbat") == ZoneKind::Battery);
    CHECK(thermal::classify_zone("socd") == ZoneKind::Battery);
    CHECK(thermal::classify_zone("skin-msm-therm") == ZoneKind::Other);

    CHECK(thermal::is_performance_cooling("thermal-cpufreq-0"));
    CHECK(thermal::is_performance_cooling("gpu"));
    CHECK(!thermal::is_performance_cooling("battery"));
    CHECK(!thermal::is_performance_cooling("pm8550b-bcl"));

    CHECK_EQ(thermal::normalize_temp(45000), std::optional<double>(45.0));
    CHECK_EQ(thermal::normalize_temp(450), std::optional<double>(45.0));
    CHECK_EQ(thermal::normalize_temp(45), std::optional<double>(45.0));
    CHECK(!thermal::normalize_temp(999000)); // 999 C: broken sensor

    using services::Kind;
    CHECK(services::classify("thermal-engine") == Kind::Daemon);
    CHECK(services::classify("vendor.thermal-engine") == Kind::Daemon);
    CHECK(services::classify("mi_thermald") == Kind::Daemon);
    CHECK(services::classify("vendor.thermal-hal-2-0") == Kind::Hal);
    CHECK(services::classify("android.hardware.thermal@2.0-service.mock") == Kind::Hal);
    CHECK(services::classify("thermalservice") == Kind::Hal);
    CHECK(services::classify("vendor.thermal-symlinks") == Kind::None);
    CHECK(services::classify("surfaceflinger") == Kind::None);
    CHECK(services::classify("thermal;reboot") == Kind::None);
}

void test_safety_guard() {
    SafetyGuard g;
    g.set_limits({.cpu_limit = 95, .cpu_hysteresis = 10, .battery_limit = 46, .battery_hysteresis = 3, .cooldown = 30s});
    const auto t0 = SafetyGuard::Clock::time_point{} + 1000s;

    CHECK(!g.update(80.0, 38.0, t0));
    CHECK(g.update(96.0, 38.0, t0 + 1s));
    CHECK(g.reason().find("CPU") != std::string::npos);
    CHECK(g.update(90.0, 38.0, t0 + 40s)); // below limit but inside hysteresis
    CHECK(g.update(84.0, 38.0, t0 + 20s)); // cool, but cooldown not elapsed
    CHECK(!g.update(84.0, 38.0, t0 + 32s)); // cool + cooldown

    CHECK(g.update(70.0, 46.5, t0 + 100s)); // battery trip
    CHECK(g.reason().find("battery") != std::string::npos);
    CHECK(g.update(70.0, 44.0, t0 + 200s)); // needs <= 43
    CHECK(!g.update(70.0, 43.0, t0 + 200s));

    // A CPU trip is released once the CPU cooled, even while the battery sits inside its own
    // hysteresis band (below its limit): only the sensor that tripped has to cool down.
    CHECK(g.update(96.0, 44.0, t0 + 250s));
    CHECK(!g.update(84.0, 45.0, t0 + 281s));

    CHECK(g.update(std::nullopt, std::nullopt, t0 + 300s)); // blind: stay protected
    CHECK(!g.update(50.0, std::nullopt, t0 + 331s));        // one sensor is enough
}

void test_flux_link() {
    build_device();
    CHECK(flux::probe().availability == flux::Availability::Ready);
    CHECK_EQ(flux::probe().version_code, 48);
    CHECK(!flux::active_game());

    start_game("com.miHoYo.GenshinImpact");
    const auto g = flux::active_game();
    CHECK(g.has_value());
    CHECK(g && g->package == "com.miHoYo.GenshinImpact" && g->pid == 31337 && g->uid == 10123 && !g->lite());

    start_game("com.miHoYo.GenshinImpact", 2);
    CHECK(flux::active_game() && flux::active_game()->lite());

    stdfs::remove_all(g_root + "/proc/31337"); // game died, fluxd has not noticed yet
    CHECK(!flux::active_game());

    put("/data/adb/.config/flux/current_profile", "garbage\n");
    CHECK(flux::read_profile() == FluxProfile::Unknown);

    stdfs::remove_all(g_root + "/proc/4242");
    CHECK(flux::probe().availability == flux::Availability::NotRunning);
    install_flux();

    put("/data/adb/modules/flux/disable", "");
    CHECK(flux::probe().availability == flux::Availability::Disabled);
    stdfs::remove(g_root + "/data/adb/modules/flux/disable");

    put("/data/adb/modules/flux/module.prop", "id=flux\nversion=1.0.0\nversionCode=20\n");
    CHECK(flux::probe().availability == flux::Availability::Outdated);

    stdfs::remove_all(g_root + "/data/adb/modules/flux");
    CHECK(flux::probe().availability == flux::Availability::NotInstalled);
}

void test_controller() {
    build_device();
    Config cfg;
    Journal journal(HICO_JOURNAL_FILE);
    ThermalController c(journal);
    CHECK(c.is_xiaomi());

    const auto s = c.unlock(cfg);
    CHECK_EQ(s.services, 2);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("stopped"));
    CHECK_EQ(props::get("init.svc.mi_thermald"), std::string("stopped"));
    CHECK_EQ(props::get("init.svc.vendor.thermal-hal-2-0"), std::string("running")); // HAL kept by default
    CHECK_EQ(props::get("init.svc.surfaceflinger"), std::string("running"));

    CHECK_EQ(get("/sys/class/thermal/thermal_zone0/policy"), std::string("user_space"));
    CHECK_EQ(get("/sys/class/thermal/thermal_zone2/policy"), std::string("user_space"));
    CHECK_EQ(get("/sys/class/thermal/thermal_zone1/policy"), std::string("step_wise")); // battery
    CHECK_EQ(get("/sys/class/thermal/thermal_zone3/policy"), std::string("step_wise")); // no user_space
    CHECK_EQ(get("/sys/class/thermal/thermal_zone4/policy"), std::string("step_wise")); // BCL
    CHECK_EQ(s.zones, 2);

    CHECK_EQ(get("/sys/class/thermal/cooling_device0/cur_state"), std::string("0"));
    CHECK_EQ(get("/sys/class/thermal/cooling_device1/cur_state"), std::string("0"));
    CHECK_EQ(get("/sys/class/thermal/cooling_device2/cur_state"), std::string("1")); // battery-bound
    CHECK_EQ(get("/sys/class/thermal/cooling_device3/cur_state"), std::string("1")); // battery type
    CHECK_EQ(get("/sys/class/thermal/cooling_device4/cur_state"), std::string("1")); // skin-bound

    CHECK_EQ(get("/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq"), std::string("2016000"));
    CHECK_EQ(get("/sys/module/msm_performance/parameters/cpu_max_freq"),
             std::string("0:2016000 1:2016000 2:2016000 3:2016000"));
    CHECK_EQ(get("/sys/class/kgsl/kgsl-3d0/thermal_pwrlevel"), std::string("0"));
    CHECK_EQ(get("/sys/module/msm_thermal/parameters/enabled"), std::string("N"));
    CHECK_EQ(get("/sys/class/thermal/thermal_message/sconfig"), std::string("10"));
    CHECK_EQ(get("/sys/class/thermal/thermal_message/cpu_limits"), std::string("cpu4 3187200"));

    // A vendor daemon pushes limits back mid-game: the next poll re-asserts them.
    put("/__props__/init.svc.mi_thermald", "running");
    put("/sys/class/thermal/thermal_message/sconfig", "0\n");
    put("/sys/class/kgsl/kgsl-3d0/thermal_pwrlevel", "5\n");
    c.unlock(cfg);
    CHECK_EQ(props::get("init.svc.mi_thermald"), std::string("stopped"));
    CHECK_EQ(get("/sys/class/thermal/thermal_message/sconfig"), std::string("10"));
    CHECK_EQ(get("/sys/class/kgsl/kgsl-3d0/thermal_pwrlevel"), std::string("0"));

    // A crashed daemon's journal is enough to restore everything.
    Journal recovered(HICO_JOURNAL_FILE);
    recovered.load();
    CHECK_EQ(recovered.size(), journal.size());

    const auto r = c.restore();
    CHECK_EQ(r.failed, 0);
    CHECK_EQ(r.services, 2);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running"));
    CHECK_EQ(props::get("init.svc.mi_thermald"), std::string("running"));
    CHECK_EQ(get("/sys/class/thermal/thermal_zone0/policy"), std::string("step_wise"));
    CHECK_EQ(get("/sys/class/thermal/thermal_zone2/policy"), std::string("step_wise"));
    CHECK_EQ(get("/sys/class/kgsl/kgsl-3d0/thermal_pwrlevel"), std::string("3")); // original, not the vendor's 5
    CHECK_EQ(get("/sys/module/msm_thermal/parameters/enabled"), std::string("Y"));
    CHECK_EQ(get("/sys/class/thermal/thermal_message/sconfig"), std::string("0"));
    CHECK_EQ(get("/sys/module/msm_performance/parameters/cpu_max_freq"),
             std::string("0:1497600 1:1497600 2:1497600 3:1497600 4:4294967295 5:4294967295 6:4294967295 7:4294967295"));
    CHECK(!fs::exists(HICO_JOURNAL_FILE));
    CHECK(!c.unlocked());

    // Opt-in: stop the HAL too; opt-out: leave zones alone.
    cfg.stop_thermal_hal = true;
    cfg.zone_governor = false;
    c.unlock(cfg);
    CHECK_EQ(props::get("init.svc.vendor.thermal-hal-2-0"), std::string("stopped"));
    CHECK_EQ(get("/sys/class/thermal/thermal_zone0/policy"), std::string("step_wise"));
    c.restore();
    CHECK_EQ(props::get("init.svc.vendor.thermal-hal-2-0"), std::string("running"));

    // A service that was already stopped is never started by restore.
    put("/__props__/init.svc.thermal-engine", "stopped");
    c.unlock(Config{});
    c.restore();
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("stopped"));

    // Extreme mode: HAL stopped, the zone without user_space gets its passive trip raised
    // (15 C, staying 5 C under its critical trip) and its cooling device released.
    // Thermal overclock turns cpufreq boost on. Everything comes back on restore.
    build_device();
    put("/sys/class/thermal/thermal_zone3/trip_point_0_type", "passive\n");
    put("/sys/class/thermal/thermal_zone3/trip_point_0_temp", "45000\n");
    put("/sys/class/thermal/thermal_zone3/trip_point_1_type", "passive\n");
    put("/sys/class/thermal/thermal_zone3/trip_point_1_temp", "58000\n");
    put("/sys/class/thermal/thermal_zone3/trip_point_2_type", "critical\n");
    put("/sys/class/thermal/thermal_zone3/trip_point_2_temp", "68000\n");
    put("/sys/devices/system/cpu/cpufreq/boost", "0\n");
    Journal je(HICO_JOURNAL_FILE);
    ThermalController ex(je);
    Config xcfg;
    xcfg.mode = Mode::Extreme;
    xcfg.thermal_overclock = true;
    const auto xs = ex.unlock(xcfg);
    CHECK_EQ(props::get("init.svc.vendor.thermal-hal-2-0"), std::string("stopped"));
    CHECK_EQ(get("/sys/class/thermal/thermal_zone3/trip_point_0_temp"), std::string("60000"));
    CHECK_EQ(get("/sys/class/thermal/thermal_zone3/trip_point_1_temp"), std::string("63000")); // capped: critical - 5
    CHECK_EQ(get("/sys/class/thermal/thermal_zone3/trip_point_2_temp"), std::string("68000")); // critical untouched
    CHECK_EQ(get("/sys/class/thermal/cooling_device4/cur_state"), std::string("0"));
    CHECK_EQ(get("/sys/class/thermal/cooling_device2/cur_state"), std::string("1")); // battery-bound: never
    CHECK_EQ(get("/sys/devices/system/cpu/cpufreq/boost"), std::string("1"));
    CHECK(xs.trips == 2 && xs.overclock);
    ex.unlock(xcfg); // polls do not raise the trips again
    CHECK_EQ(get("/sys/class/thermal/thermal_zone3/trip_point_0_temp"), std::string("60000"));
    ex.restore();
    CHECK_EQ(get("/sys/class/thermal/thermal_zone3/trip_point_0_temp"), std::string("45000"));
    CHECK_EQ(get("/sys/class/thermal/thermal_zone3/trip_point_1_temp"), std::string("58000"));
    CHECK_EQ(get("/sys/devices/system/cpu/cpufreq/boost"), std::string("0"));
    CHECK_EQ(props::get("init.svc.vendor.thermal-hal-2-0"), std::string("running"));
}

void test_journal_rejects_tampering() {
    build_device();
    put(HICO_JOURNAL_FILE, "N\t/data/adb/modules/flux/module.prop\tpwned\nS\tfoo;reboot\n"
                           "N\t/sys/class/thermal/thermal_zone0/policy\tstep_wise\n");
    put("/sys/class/thermal/thermal_zone0/policy", "user_space\n");
    Journal j(HICO_JOURNAL_FILE);
    j.load();
    CHECK_EQ(j.size(), 1u);
    j.restore();
    CHECK_EQ(get("/sys/class/thermal/thermal_zone0/policy"), std::string("step_wise"));
    CHECK(get("/data/adb/modules/flux/module.prop").find("pwned") == std::string::npos);
}

void test_daemon_state_machine() {
    build_device();
    write_config("exit_delay=3\nsafety_cooldown=10\npoll_interval=2\n");
    Daemon d;
    auto t = Daemon::Clock::time_point{} + 10000s;

    d.tick(t);
    CHECK(d.state() == State::Idle);
    CHECK(get(HICO_STATE_FILE).find("state=idle") != std::string::npos);
    CHECK(get(HICO_MODULE_PROP).find("Daily") != std::string::npos);
    CHECK(d.next_timeout() == std::chrono::milliseconds(30000));

    start_game("com.mobile.legends");
    d.tick(t += 1s);
    CHECK(d.state() == State::Boost);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("stopped"));
    CHECK(get(HICO_STATE_FILE).find("game=com.mobile.legends") != std::string::npos);
    CHECK(get(HICO_MODULE_PROP).find("thermal unlocked") != std::string::npos);
    CHECK(d.next_timeout() == std::chrono::milliseconds(2000));

    // Overheat -> safety: stock thermal is back while the game still runs.
    set_cpu_temp(97000);
    d.tick(t += 2s);
    CHECK(d.state() == State::Safety);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running"));
    CHECK_EQ(get("/sys/class/thermal/thermal_zone0/policy"), std::string("step_wise"));
    CHECK(get(HICO_STATE_FILE).find("trips=1") != std::string::npos);

    set_cpu_temp(80000);
    d.tick(t += 2s);
    CHECK(d.state() == State::Safety); // cooldown
    d.tick(t += 10s);
    CHECK(d.state() == State::Boost);
    CHECK_EQ(get("/sys/class/thermal/thermal_zone0/policy"), std::string("user_space"));

    // Game leaves: held for exit_delay, then stock thermal.
    stop_game();
    d.tick(t += 1s);
    CHECK(d.state() == State::Boost);
    d.tick(t += 3s);
    CHECK(d.state() == State::Idle);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running"));
    CHECK(!fs::exists(HICO_JOURNAL_FILE));

    const std::string history = get(HICO_SESSIONS_FILE);
    CHECK(history.find(R"("game":"com.mobile.legends")") != std::string::npos);
    CHECK(history.find(R"("trips":1)") != std::string::npos);
    CHECK(history.find(R"("peak_cpu":97.0)") != std::string::npos);

    // Performance Lite (Flux saw thermal pressure) with unlock_on_lite=0: relaxed, never max.
    write_config("unlock_on_lite=0\n");
    d.reload_config();
    start_game("com.dts.freefireth", 2);
    d.tick(t += 1s);
    CHECK(d.state() == State::Relaxed);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running"));

    // Blacklisted games stay stock (old key name still accepted).
    write_config("excluded_games=com.dts.freefireth\n");
    d.reload_config();
    start_game("com.dts.freefireth", 1);
    d.tick(t += 1s);
    CHECK(d.state() == State::Relaxed); // leaving the previous session: exit_delay grace period
    d.tick(t += 3s);
    CHECK(d.state() == State::Idle);

    // Flux disabled mid-game: stock thermal immediately, no exit delay.
    write_config("exit_delay=10\n");
    d.reload_config();
    d.tick(t += 1s);
    CHECK(d.state() == State::Boost);
    put("/data/adb/modules/flux/disable", "");
    d.tick(t += 1s);
    CHECK(d.state() == State::Suspended);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running"));
    CHECK(get(HICO_MODULE_PROP).find("Flux Tweaks is required") != std::string::npos);
    stdfs::remove(g_root + "/data/adb/modules/flux/disable");

    // mode=off
    write_config("mode=off\n");
    d.reload_config();
    d.tick(t += 1s);
    CHECK(d.state() == State::Disabled);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running"));

    // Crash recovery: a journal left behind is replayed at startup.
    write_config("");
    Daemon crashed;
    crashed.tick(t += 1s);
    CHECK(crashed.state() == State::Boost);
    Daemon fresh;
    fresh.recover();
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running"));
    CHECK_EQ(get("/sys/class/thermal/thermal_zone0/policy"), std::string("step_wise"));
}

void test_sessions_are_bounded() {
    build_device();
    Session s;
    s.package = "com.game\"inject";
    s.duration_s = 60;
    for (size_t i = 0; i < sessions::kMaxEntries + 20; ++i) sessions::append(HICO_SESSIONS_FILE, s);
    CHECK_EQ(str::split(get(HICO_SESSIONS_FILE), '\n').size(), sessions::kMaxEntries);
    CHECK(get(HICO_SESSIONS_FILE).find("com.gameinject") != std::string::npos);
}

// Synthetic records ("testdev*" codenames do not exist), sorted by codename like the generated table.
constexpr std::array<std::string_view, 3> kTestServices{"mi_thermald", "vendor.thermal-hal-2-0", "vendor.tmd_daemon"};
constexpr std::array<std::string_view, 2> kTestConfigs{"thermal-nolimits.conf", "thermal-tgame.conf"};
constexpr std::array<std::string_view, 3> kMtkServices{"thermal", "thermal_manager", "thermalloadalgod"};
constexpr std::array kTestDb{
    DeviceRecord{"testdev", "Redmi", "Test Phone", "taro", "14", "https://example.invalid/dump", kTestServices, kTestConfigs},
    DeviceRecord{"testmtk", "Xiaomi", "Test MTK", "mt6893", "14", "https://example.invalid/mtk", kMtkServices, {}},
};

std::vector<std::string> backend_names(const DeviceProfile &d) {
    std::vector<std::string> out;
    for (const auto &b : make_backends(d)) out.emplace_back(b->name());
    return out;
}

void test_device_database() {
    build_device();

    // Lookup and derived facts.
    CHECK(device_db::find(kTestDb, "testdev") == &kTestDb[0]);
    CHECK(device_db::find(kTestDb, "testmtk") == &kTestDb[1]);
    CHECK(device_db::find(kTestDb, "nope") == nullptr);
    CHECK(device_db::find({}, "testdev") == nullptr);
    CHECK_EQ(traits_of(kTestDb[0]), static_cast<std::uint32_t>(kTraitMiThermald | kTraitThermalHal |
                                                               kTraitSceneConfigs | kTraitNoLimitsScene));
    CHECK(traits_of(kTestDb[1]) == kTraitMtkThermal);

    CHECK(soc_from_platform("taro") == SocVendor::Qualcomm);
    CHECK(soc_from_platform("msmnile") == SocVendor::Qualcomm);
    CHECK(soc_from_platform("sm8650") == SocVendor::Qualcomm);
    CHECK(soc_from_platform("MT6893") == SocVendor::MediaTek);
    CHECK(soc_from_platform("exynos2100") == SocVendor::Exynos);
    CHECK(soc_from_platform("gs201") == SocVendor::Tensor);
    CHECK(soc_from_platform("ums512") == SocVendor::Unisoc);
    CHECK(soc_from_platform("sc8280xp") == SocVendor::Unknown); // Qualcomm compute, not Unisoc
    CHECK(soc_from_platform("") == SocVendor::Unknown);
    CHECK(soc_from_platform("mtk") == SocVendor::Unknown);      // no model number

    // The running device is found by its codename.
    put("/__props__/ro.product.vendor.device", "TestDev");
    const DeviceProfile p = DeviceProfile::detect(kTestDb);
    CHECK(p.in_database && p.codename == "testdev" && p.model == "Test Phone");
    CHECK(p.soc == SocVendor::Qualcomm && p.has(kTraitMiThermald));
    CHECK_EQ(p.thermal_services.size(), 3u);

    // Not in the database: live properties, SoC from ro.board.platform.
    put("/__props__/ro.product.vendor.device", "unknowndev");
    put("/__props__/ro.board.platform", "mt6789");
    const DeviceProfile live = DeviceProfile::detect(kTestDb);
    CHECK(!live.in_database && live.codename == "unknowndev" && live.soc == SocVendor::MediaTek);
    put("/__props__/ro.board.platform", "");

    // Presets set several keys at once and are recognised afterwards.
    {
        Config c;
        CHECK_EQ(std::string(matching_preset(c)), std::string("balanced"));
        CHECK(!apply_preset(c, "extreme"));
        CHECK(c.mode == Mode::Extreme && c.safety_cpu_temp == 100 && c.poll_interval == 1);
        CHECK_EQ(std::string(matching_preset(c)), std::string("extreme"));
        CHECK(!apply_preset(c, "overclock") && c.thermal_overclock && c.relax_margin == 10);
        CHECK(apply_preset(c, "nope").has_value());
        CHECK(!c.set("mode", "extreme") && c.get("mode") == std::string("extreme"));
        c.safety_cpu_temp = 97;
        CHECK_EQ(std::string(matching_preset(c)), std::string("custom"));
    }

    // Custom ROMs: product props renamed or spoofed, the real codename is found elsewhere.
    put("/__props__/ro.product.vendor.device", "");
    put("/__props__/ro.product.device", "lineage_testdev");
    const DeviceProfile prefixed = DeviceProfile::detect(kTestDb);
    CHECK(prefixed.in_database && prefixed.codename == "testdev" && prefixed.codename_source == "ro.product.device");
    put("/__props__/ro.product.device", "husky"); // Pixel name spoofed for Play Integrity
    put("/__props__/ro.boot.hwname", "testdev");
    CHECK(DeviceProfile::detect(kTestDb).in_database);
    put("/__props__/ro.boot.hwname", "");
    put("/__props__/ro.vendor.build.fingerprint", "Redmi/testdev_global/testdev:15/AP3A/1:user/release-keys");
    const DeviceProfile fp = DeviceProfile::detect(kTestDb);
    CHECK(fp.in_database && fp.codename_source == "ro.vendor.build.fingerprint");
    put("/__props__/ro.vendor.build.fingerprint", "");
    CHECK(!DeviceProfile::detect(kTestDb).in_database && DeviceProfile::detect(kTestDb).codename == "husky");

    // Codenames are validated.
    put("/__props__/ro.product.vendor.device", "../../etc");
    put("/__props__/ro.product.device", "");
    CHECK(device_codename().empty());
    CHECK(!DeviceProfile::detect(kTestDb).in_database);

    // Backends follow the SoC: the simulated device exposes Qualcomm AND MediaTek nodes.
    put("/sys/kernel/eara_thermal/enable", "1\n");
    CHECK(backend_names(DeviceProfile::from_record(kTestDb[0])) == (std::vector<std::string>{"qualcomm", "xiaomi"}));
    CHECK(backend_names(DeviceProfile::from_record(kTestDb[1])) == (std::vector<std::string>{"mediatek", "xiaomi"}));

    Journal jq(HICO_JOURNAL_FILE);
    ThermalController qcom(jq, DeviceProfile::from_record(kTestDb[0]));
    qcom.unlock(Config{});
    CHECK_EQ(get("/sys/module/msm_thermal/parameters/enabled"), std::string("N"));
    CHECK_EQ(get("/sys/kernel/eara_thermal/enable"), std::string("1")); // MediaTek node left alone
    qcom.restore();

    Journal jm(HICO_JOURNAL_FILE);
    ThermalController mtk(jm, DeviceProfile::from_record(kTestDb[1]));
    mtk.unlock(Config{});
    CHECK_EQ(get("/sys/kernel/eara_thermal/enable"), std::string("0"));
    CHECK_EQ(get("/sys/module/msm_thermal/parameters/enabled"), std::string("Y")); // Qualcomm nodes left alone
    CHECK_EQ(get("/sys/class/kgsl/kgsl-3d0/thermal_pwrlevel"), std::string("3"));
    mtk.restore();
    CHECK_EQ(get("/sys/kernel/eara_thermal/enable"), std::string("1"));

    // Unknown SoC (not in the database, no platform): backends chosen from what the kernel exposes.
    DeviceProfile unknown;
    CHECK(backend_names(unknown) == (std::vector<std::string>{"qualcomm", "mediatek", "xiaomi"}));

    // A vendor-declared daemon without "thermal" in its name is stopped only with the database record.
    put("/__props__/init.svc.vendor.tmd_daemon", "running");
    Journal j1(HICO_JOURNAL_FILE);
    ThermalController with_db(j1, DeviceProfile::from_record(kTestDb[0]));
    CHECK_EQ(with_db.unlock(Config{}).services, 3);
    CHECK_EQ(props::get("init.svc.vendor.tmd_daemon"), std::string("stopped"));
    with_db.restore();
    CHECK_EQ(props::get("init.svc.vendor.tmd_daemon"), std::string("running"));

    Journal j2(HICO_JOURNAL_FILE);
    ThermalController generic(j2, DeviceProfile{});
    generic.unlock(Config{});
    CHECK_EQ(props::get("init.svc.vendor.tmd_daemon"), std::string("running"));
    generic.restore();

    // The generated table is sorted (binary search relies on it).
    const auto db = device_db::records();
    CHECK(std::is_sorted(db.begin(), db.end(), [](const DeviceRecord &a, const DeviceRecord &b) { return a.codename < b.codename; }));
    CHECK(device_db::generated_from().find("dumps.tadiphone.dev") != std::string_view::npos);

    Daemon d;
    d.tick(Daemon::Clock::time_point{} + 100s);
    CHECK(get(HICO_STATE_FILE).find("backends=") != std::string::npos);
}
// A Qualcomm-style thermal-engine config with every kind of section the tuner must handle.
const std::string kEngineConf = R"(# vendor thermal config
[VIRTUAL-CPU]
algo_type virtual
trip_sensor cpu-1-0-usr
thresholds 90000

[SKIN_MONITOR]
algo_type        monitor
sensor           quiet_therm
thresholds       41000   43000   45000   # skin steps
thresholds_clr   39000   41000   43000
actions          cpu+gpu cpu+gpu cpu+gpu
action_info      1804800+2 1497600+3 1190400+4

[CPU_SS]
algo_type ss
sensor cpu-1-0-usr
device cpu4
set_point 95000
set_point_clr 65000

[CPU_SHUTDOWN]
algo_type monitor
sensor cpu-1-0-usr
thresholds 115000
thresholds_clr 110000
actions shutdown
action_info 5000

[BATT_MONITOR]
algo_type monitor
sensor battery
thresholds 45000
thresholds_clr 43000
actions battery
action_info 1

[LOW_TEMP]
algo_type monitor
sensor quiet_therm
descending
thresholds 5000
thresholds_clr 7000
actions cpu
action_info 1
)";

void test_thermal_tuner() {
    using namespace thermalcfg;
    CHECK(policy_for(SocVendor::Qualcomm, "taro").margin_c == 6);
    CHECK(policy_for(SocVendor::Qualcomm, "SM8650").margin_c == 6);
    CHECK(policy_for(SocVendor::Qualcomm, "bengal").margin_c == 5);
    CHECK(policy_for(SocVendor::MediaTek, "mt6893").margin_c == 5);
    CHECK(policy_for(SocVendor::MediaTek, "mt6765").margin_c == 4);
    CHECK(policy_for(SocVendor::Unknown, "").margin_c == 4);
    CHECK(policy_for(SocVendor::Unknown, "", 8).margin_c == 8);
    CHECK(policy_for(SocVendor::Unknown, "", 11).margin_c == 4); // out of range: ignored

    const Policy p = policy_for(SocVendor::Qualcomm, "taro");
    const auto r = tune(kEngineConf, p);
    CHECK(r.has_value());
    if (!r) return;
    CHECK_EQ(r->sections, 6);
    CHECK_EQ(r->tuned_sections, 2);
    // Skin trips +6 C, hysteresis kept, layout and comment kept.
    CHECK(r->text.find("thresholds       47000   49000   51000   # skin steps") != std::string::npos);
    CHECK(r->text.find("thresholds_clr   45000   47000   49000") != std::string::npos);
    // Step-wise CPU set point +6 C.
    CHECK(r->text.find("set_point 101000\nset_point_clr 71000") != std::string::npos);
    // Untouched: shutdown, battery, descending, virtual sensors.
    CHECK(r->text.find("thresholds 115000\nthresholds_clr 110000\nactions shutdown") != std::string::npos);
    CHECK(r->text.find("sensor battery\nthresholds 45000") != std::string::npos);
    CHECK(r->text.find("descending\nthresholds 5000") != std::string::npos);
    CHECK(r->text.find("trip_sensor cpu-1-0-usr\nthresholds 90000") != std::string::npos);
    CHECK(verify(kEngineConf, r->text, p).empty());

    // The independent check catches every unsafe edit.
    auto tampered = r->text;
    tampered.replace(tampered.find("thresholds 115000"), 17, "thresholds 125000");
    CHECK(!verify(kEngineConf, tampered, p).empty()); // shutdown changed
    tampered = r->text;
    tampered.replace(tampered.find("set_point 101000"), 16, "set_point 104000");
    CHECK(!verify(kEngineConf, tampered, p).empty()); // beyond the margin
    tampered = r->text;
    tampered.replace(tampered.find("set_point 101000"), 16, "set_point 090000");
    CHECK(!verify(kEngineConf, tampered, p).empty()); // lowered
    tampered = r->text;
    tampered.replace(tampered.find("action_info 5000"), 16, "action_info 9000");
    CHECK(!verify(kEngineConf, tampered, p).empty()); // non-trip key changed

    // Caps: skin trips stop at 55 C; a collapsed ladder is left as the vendor wrote it.
    const auto capped = tune("[S]\nalgo_type monitor\nsensor skin\nthresholds 50000 53000\nactions cpu cpu\n", p);
    CHECK(capped && capped->text.find("thresholds 55000 55000") == std::string::npos);
    CHECK(capped && capped->tuned_sections == 0);
    const auto capped2 = tune("[S]\nalgo_type monitor\nsensor skin\nthresholds 48000 50000\nactions cpu cpu\n", p);
    CHECK(capped2 && capped2->text.find("thresholds 54000 55000") != std::string::npos);
    // Guard below the same sensor's shutdown: 100 C shutdown -> trips at most 90 C.
    const auto guarded = tune("[C]\nalgo_type monitor\nsensor cpu-0\nthresholds 88000\nactions cpu\n"
                              "[OFF]\nalgo_type monitor\nsensor cpu-0\nthresholds 100000\nactions shutdown\n", p);
    CHECK(guarded && guarded->text.find("thresholds 90000\n") != std::string::npos);
    // Old configs in degrees keep their unit.
    const auto degrees = tune("[S]\nalgo_type monitor\nsensor skin_therm\nthresholds 45 50\nactions cpu cpu\n", p);
    CHECK(degrees && degrees->text.find("thresholds 51 55") != std::string::npos);
    // Encrypted blobs and unrelated text are not tunable.
    CHECK(!tune(std::string("\x13\x9f\x01binary\x02\x00\x03", 12) + std::string(64, '\x01'), p));
    CHECK(!tune("just words\n", p));
}

void test_relaxed_overlay() {
    build_device();
    put("/vendor/etc/thermal-engine.conf", kEngineConf);
    put("/vendor/etc/thermal-tgame.conf", std::string("\x13\x9f\x01\x02", 4) + std::string(64, '\x01'));
    put("/__props__/init.svc.thermal-engine", "running");

    DeviceProfile qcom;
    qcom.soc = SocVendor::Qualcomm;
    qcom.platform = "taro";
    Journal journal(HICO_JOURNAL_FILE);
    ThermalController c(journal, qcom);

    CHECK_EQ(c.relax(Config{}), 1); // the encrypted config is skipped
    const std::string mounts = get("/__mounts__");
    CHECK(mounts.find("/vendor/etc/thermal-engine.conf <- /dev/hico/thermal/vendor_etc_thermal-engine.conf") !=
          std::string::npos);
    CHECK(get("/dev/hico/thermal/vendor_etc_thermal-engine.conf").find("47000") != std::string::npos);
    CHECK(fs::read_raw("/vendor/etc/thermal-engine.conf", 1 << 20) == kEngineConf); // vendor file never written
    CHECK(get("/__props__/__ctl_log__").find("ctl.restart thermal-engine") != std::string::npos);
    CHECK(get("/__props__/__ctl_log__").find("ctl.restart vendor.thermal-hal-2-0") == std::string::npos); // HAL not
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running")); // daemons keep protecting

    // Idempotent: a tuned file is never tuned again, daemons are not restarted again.
    const size_t restarts = get("/__props__/__ctl_log__").size();
    CHECK_EQ(c.relax(Config{}), 1);
    CHECK_EQ(get("/__props__/__ctl_log__").size(), restarts);

    // A crashed daemon's journal restores it: unmount first, then restart.
    Journal recovered(HICO_JOURNAL_FILE);
    recovered.load();
    CHECK(recovered.has_mount("/vendor/etc/thermal-engine.conf"));
    // Journal order: restarts recorded before the mounts, so the reverse replay unmounts first.
    const std::string jtext = get(HICO_JOURNAL_FILE);
    CHECK(jtext.find("R\tthermal-engine") < jtext.find("M\t/vendor/etc/thermal-engine.conf"));
    const auto r = recovered.restore();
    CHECK_EQ(r.mounts, 1);
    CHECK_EQ(r.failed, 0);
    CHECK(get("/__mounts__").find("thermal-engine.conf") == std::string::npos);
    const std::string log = get("/__props__/__ctl_log__");
    CHECK(log.rfind("ctl.restart thermal-engine") > restarts - 1); // restarted after unmount

    // The journal refuses mount targets outside the vendor/system partitions.
    put(HICO_JOURNAL_FILE, "M\t/data/adb/modules/flux/module.prop\nM\t/vendor/../data/x\n");
    Journal hostile(HICO_JOURNAL_FILE);
    hostile.load();
    CHECK(hostile.empty());
}

void test_levels_whitelist_blacklist() {
    build_device();
    put("/vendor/etc/thermal-engine.conf", kEngineConf);
    put("/__props__/ro.board.platform", "taro");
    const auto focus = [](const std::string &pkg, bool screen) {
        put(FLUX_STATUS_FILE, "synthesis_version 3\nfocused_app " + pkg + " 555 10050\nscreen_awake " + (screen ? "1" : "0") + "\n");
    };
    auto t = Daemon::Clock::time_point{} + 20000s;

    // A whitelisted app (not a game) gets the relaxed level only.
    write_config("whitelist=com.android.camera\nexit_delay=0\n");
    Daemon d;
    focus("com.android.camera", true);
    d.tick(t += 1s);
    CHECK(d.state() == State::Relaxed);
    CHECK(get(HICO_STATE_FILE).find("level=relaxed") != std::string::npos);
    CHECK(get(HICO_STATE_FILE).find("configs=1") != std::string::npos);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running")); // never the max level
    CHECK(get(HICO_MODULE_PROP).find("Relaxed thermal") != std::string::npos);

    // Screen off or another app: back to stock, configs unmounted.
    focus("com.android.camera", false);
    d.tick(t += 1s);
    CHECK(d.state() == State::Idle);
    CHECK(get("/__mounts__").find("thermal-engine.conf") == std::string::npos);
    focus("com.whatsapp", true);
    d.tick(t += 1s);
    CHECK(d.state() == State::Idle);

    // A game gets max; switching the level mid-session goes through stock.
    start_game("com.mobile.legends");
    d.tick(t += 1s);
    CHECK(d.state() == State::Boost);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("stopped"));
    write_config("game_level=relaxed\nexit_delay=0\n");
    d.reload_config();
    d.tick(t += 1s);
    CHECK(d.state() == State::Relaxed);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running"));
    CHECK(get("/__mounts__").find("thermal-engine.conf") != std::string::npos);
    write_config("exit_delay=0\n");
    d.reload_config();
    d.tick(t += 1s);
    CHECK(d.state() == State::Boost);
    CHECK(get("/__mounts__").find("thermal-engine.conf") == std::string::npos);

    // The blacklist wins over everything, games and whitelist alike.
    write_config("blacklist=com.mobile.legends,com.android.camera\nwhitelist=com.android.camera\nexit_delay=0\n");
    d.reload_config();
    d.tick(t += 1s);
    CHECK(d.state() == State::Idle);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running"));
    stop_game();
    focus("com.android.camera", true);
    d.tick(t += 1s);
    CHECK(d.state() == State::Idle);
}

// Pixel/AOSP-style thermal HAL config, as shipped by AOSP-based ROMs.
const std::string kHalJson = R"({
    "Sensors":[
        {
            "Name":"VIRTUAL-SKIN",
            "Type":"SKIN",
            "HotThreshold":["NAN", 39.0, 43.0, 45.0, 47.0, 52.0, 55.0],
            "HotHysteresis":[0.0, 1.9, 1.9, 1.9, 1.9, 1.9, 1.9],
            "Multiplier":0.001
        },
        {
            "Name":"cpu-1-0-usr",
            "Type":"CPU",
            "HotThreshold":["NAN", "NAN", "NAN", 95, "NAN", "NAN", 125]
        },
        {
            "Name":"battery",
            "Type":"BATTERY",
            "HotThreshold":["NAN", 38.0, 40.0, 42.0, 44.0, 50.0, 60.0]
        },
        {
            "Name":"VIRTUAL-SKIN-HIGH",
            "Type":"SKIN",
            "HotThreshold":["NAN", 44.0, 46.0, 47.5, 48.0, 50.0, 55.0]
        }
    ],
    "CoolingDevices":[{"Name":"cpu-cluster0","Type":"CPU"}]
}
)";

void test_hal_json_tuner() {
    using namespace thermalcfg;
    CHECK(detect_format(kHalJson) == Format::HalJson);
    CHECK(detect_format(kEngineConf) == Format::Engine);
    CHECK(detect_format("{\"Sensors\": []}") == Format::Unknown); // nothing to tune
    CHECK(detect_format("{ broken json") == Format::Unknown);

    const Policy p = policy_for(SocVendor::Qualcomm, "taro"); // +6 C
    const auto r = tune(kHalJson, p);
    CHECK(r.has_value());
    if (!r) return;
    CHECK_EQ(r->sections, 4);
    CHECK_EQ(r->tuned_sections, 2);
    // Skin LIGHT..CRITICAL +6, capped 10 C below EMERGENCY (52 -> 42 max): 39 -> 42, the rest stay (never lowered).
    CHECK(r->text.find(R"("HotThreshold":["NAN", 42.0, 43.0, 45.0, 47.0, 52.0, 55.0])") != std::string::npos);
    // CPU SEVERE 95 -> 101 (integer style kept), SHUTDOWN 125 untouched.
    CHECK(r->text.find(R"("HotThreshold":["NAN", "NAN", "NAN", 101, "NAN", "NAN", 125])") != std::string::npos);
    // Battery never changed.
    CHECK(r->text.find(R"("HotThreshold":["NAN", 38.0, 40.0, 42.0, 44.0, 50.0, 60.0])") != std::string::npos);
    // Guard leaves no room below EMERGENCY 50 for the high skin sensor: unchanged.
    CHECK(r->text.find(R"("HotThreshold":["NAN", 44.0, 46.0, 47.5, 48.0, 50.0, 55.0])") != std::string::npos);
    // Only those number tokens changed: same length difference as the edits.
    CHECK(verify(kHalJson, r->text, p).empty());

    auto tampered = r->text;
    tampered.replace(tampered.find("125]"), 3, "135");
    CHECK(!verify(kHalJson, tampered, p).empty()); // SHUTDOWN changed
    tampered = r->text;
    tampered.replace(tampered.find("\"Multiplier\":0.001"), 18, "\"Multiplier\":0.002");
    CHECK(!verify(kHalJson, tampered, p).empty()); // content outside thresholds
    tampered = r->text;
    tampered.replace(tampered.find(", 101,"), 6, ", 104,");
    CHECK(!verify(kHalJson, tampered, p).empty()); // beyond the margin
}

void test_rom_and_hal_overlay() {
    build_device();
    // ROM detection.
    CHECK(detect_rom().first == RomFamily::Aosp);
    put("/__props__/ro.lineage.version", "22.1");
    CHECK(detect_rom().first == RomFamily::Lineage && detect_rom().second == "LineageOS 22.1");
    put("/__props__/ro.modversion", "crDroidAndroid-15.0");
    CHECK(detect_rom().second == "crDroidAndroid-15.0");
    put("/__props__/ro.mi.os.version.name", "OS2.0");
    CHECK(detect_rom().first == RomFamily::HyperOS);
    put("/__props__/ro.mi.os.version.name", "");
    put("/__props__/ro.miui.ui.version.name", "V14");
    CHECK(detect_rom().first == RomFamily::Miui);
    // HyperOS still reports MIUI UI code V816; without ro.mi.os.version.name it must not read as MIUI.
    put("/__props__/ro.miui.ui.version.name", "V816");
    put("/__props__/ro.build.version.incremental", "OS2.0.3.0.VNRMIXM");
    CHECK(detect_rom().first == RomFamily::HyperOS && detect_rom().second == "HyperOS OS2.0.3.0.VNRMIXM");
    put("/__props__/ro.build.version.incremental", "V14.0.1.0");
    CHECK(detect_rom().first == RomFamily::HyperOS && detect_rom().second == "HyperOS (V816)");
    put("/__props__/ro.mi.os.version.incremental", "OS1.0.8.0.UNOMIXM");
    CHECK(detect_rom().second == "HyperOS OS1.0.8.0.UNOMIXM");
    put("/__props__/ro.mi.os.version.incremental", "");
    put("/__props__/ro.miui.ui.version.name", "V140");
    CHECK(detect_rom().first == RomFamily::Miui);

    // AOSP ROM with a thermal HAL JSON and no thermal-engine: relaxing restarts the HAL, not the daemons.
    put("/__props__/ro.miui.ui.version.name", "");
    // Custom AOSP ROM: name from its own property, version from ro.modversion.
    put("/__props__/ro.lineage.version", "");
    put("/__props__/ro.modversion", "12.2-Vanilla");
    put("/__props__/ro.crdroid.build.version", "12.2");
    CHECK(detect_rom().first == RomFamily::Aosp && detect_rom().second == "crDroid 12.2-Vanilla");
    put("/__props__/ro.modversion", "crDroidAndroid-16.0-12.2");
    CHECK(detect_rom().second == "crDroidAndroid-16.0-12.2"); // name already in the version
    put("/__props__/ro.crdroid.build.version", "");
    // Unknown ROM: found through its version key in build.prop.
    put("/__props__/ro.modversion", "3.1-Vanilla");
    put("/system/build.prop", "ro.build.version.sdk=36\nro.product.version=1\nro.nebula.build.version=3.1\n");
    CHECK(detect_rom().second == "Nebula 3.1-Vanilla");
    put("/system/build.prop", "ro.build.version.sdk=36\n");
    put("/__props__/ro.modversion", "");
    put("/vendor/etc/thermal_info_config.json", kHalJson);
    DeviceProfile qcom;
    qcom.soc = SocVendor::Qualcomm;
    qcom.platform = "taro";
    Journal journal(HICO_JOURNAL_FILE);
    ThermalController c(journal, qcom);
    CHECK_EQ(c.relax(Config{}), 1);
    CHECK(get("/__mounts__").find("/vendor/etc/thermal_info_config.json <- ") != std::string::npos);
    const std::string log = get("/__props__/__ctl_log__");
    CHECK(log.find("ctl.restart vendor.thermal-hal-2-0") != std::string::npos);
    CHECK(log.find("ctl.restart thermal-engine") == std::string::npos);
    CHECK(fs::read_raw("/vendor/etc/thermal_info_config.json", 1 << 20) == kHalJson);
    const auto r = c.restore();
    CHECK_EQ(r.mounts, 1);
    CHECK(get("/__mounts__").find("thermal_info_config.json") == std::string::npos);
}

} // namespace

void test_mi_thermald() {
    using namespace thermalcfg;
    // AES-128 (FIPS-197 C.1): first CBC block with a zero IV is the ECB result.
    const auto unhex = [](std::string_view h) {
        std::string o;
        for (size_t i = 0; i < h.size(); i += 2) o += static_cast<char>(std::stoi(std::string(h.substr(i, 2)), nullptr, 16));
        return o;
    };
    const std::string ct = micrypt::cbc_encrypt(unhex("00112233445566778899aabbccddeeff"),
                                                unhex("000102030405060708090a0b0c0d0e0f"), std::string(16, '\0'));
    CHECK(ct.substr(0, 16) == unhex("69c4e0d86a7b0430d8cdb78070b4c55a"));

    const std::string stock =
        "[VIRTUAL-SENSOR0]\nalgo_type\tVirtual\nsensors\tcpu_therm\tbattery\n\n"
        "[TGAME-SS-CPU4]\nalgo_type\tss\nsensor\tVIRTUAL-SENSOR0\ndevice\tcpu4\npolling\t2000\n"
        "trig\t46000\t47000\t48000\nclr\t45000\t46000\t47000\ntarget\t1344000\t1190400\t960000\n\n"
        "[TGAME-MONITOR-GPU]\nalgo_type\tmonitor\nsensor\tVIRTUAL-SENSOR0\ndevice\tgpu\ntrig\t45000\t46000\n"
        "clr\t44000\t45000\ntarget\t4\t5\n\n"
        "[TGAME-MONITOR-BATTERY]\nalgo_type\tmonitor\nsensor\tVIRTUAL-SENSOR0\ndevice\tbattery\n"
        "trig\t40000\nclr\t38000\ntarget\t1500\n\n"
        "[TGAME-MONITOR-TEMP_STATE]\nalgo_type\tmonitor\nsensor\tVIRTUAL-SENSOR0\ndevice\ttemp_state\n"
        "trig\t46000\nclr\t44000\ntarget\t110100000\n";
    const std::string nolimits =
        "[NOLIMITS-SS-CPU4]\nalgo_type\tss\nsensor\tVIRTUAL-SENSOR0\ndevice\tcpu4\ntrig\t51000\nclr\t49000\ntarget\t691200\n\n"
        "[NOLIMITS-MONITOR-GPU]\nalgo_type\tmonitor\nsensor\tVIRTUAL-SENSOR0\ndevice\tgpu\ntrig\t48000\nclr\t45000\ntarget\t1\n";

    // Encrypted round trip, and format detection on both forms.
    const std::string enc = micrypt::encrypt(stock);
    CHECK(micrypt::decrypt(enc) == stock);
    CHECK(detect_format(stock) == Format::MiThermald);
    CHECK(detect_format(enc) == Format::MiEncrypted);
    CHECK(!micrypt::decrypt("not encrypted at all!!").has_value());

    Policy p = policy_for(SocVendor::Qualcomm, "parrot"); // +5 C
    mithermald::collect_ceilings(stock, p.mi_ceilings);
    mithermald::collect_ceilings(nolimits, p.mi_ceilings);
    CHECK_EQ(p.mi_ceilings["cpu4|VIRTUAL-SENSOR0"], 51000LL);

    const auto r = tune(enc, p);
    CHECK(r && r->tuned_sections == 2);
    CHECK(detect_format(r->text) == Format::MiEncrypted); // re-encrypted for mi_thermald
    const std::string tuned = *micrypt::decrypt(r->text);
    // CPU4 bounded by the device's own nolimits trip (51 C): +3 instead of +5, clr moved alike.
    CHECK(tuned.find("trig\t49000\t50000\t51000\nclr\t48000\t49000\t50000\ntarget\t1344000") != std::string::npos);
    CHECK(tuned.find("trig\t47000\t48000\nclr\t46000\t47000") != std::string::npos); // GPU up to 48 C
    CHECK(tuned.find("device\tbattery\ntrig\t40000") != std::string::npos);            // battery untouched
    CHECK(tuned.find("device\ttemp_state\ntrig\t46000") != std::string::npos);         // temp_state untouched
    CHECK(verify(enc, r->text, p).empty());

    // Without ceilings the margin applies, capped at 55 C for a skin / virtual sensor.
    Policy wide = policy_for(SocVendor::Qualcomm, "parrot", 10);
    const auto w = mithermald::tune(stock, wide);
    CHECK(w && w->text.find("trig\t55000\t56000") == std::string::npos);
    CHECK(w->text.find("trig\t53000\t54000\t55000") != std::string::npos);

    // The verifier rejects anything beyond the rules.
    const std::string bad = mithermald::tune(stock, p)->text;
    const auto replace = [](std::string s, std::string_view a, std::string_view b) {
        s.replace(s.find(a), a.size(), b);
        return s;
    };
    CHECK(!mithermald::verify(stock, replace(bad, "trig\t49000\t50000\t51000", "trig\t52000\t53000\t54000"), p).empty());
    CHECK(!mithermald::verify(stock, replace(stock, "trig\t40000", "trig\t45000"), p).empty()); // battery
    CHECK(!mithermald::verify(stock, replace(stock, "target\t4\t5", "target\t1\t1"), p).empty());
}

void test_graduated_safety() {
    // A device with a tunable vendor config: the safety guard first brings the vendor thermal
    // back with the tuned template, and only restores full stock past the hard margin.
    build_device();
    put("/vendor/etc/thermal-engine.conf", kEngineConf);
    write_config("safety_cooldown=10\npoll_interval=2\n");
    Daemon d;
    auto t = Daemon::Clock::time_point{} + 20000s;
    start_game("com.mobile.legends");
    d.tick(t += 1s);
    CHECK(d.state() == State::Boost);

    set_cpu_temp(96000); // limit 95: soft landing
    d.tick(t += 2s);
    CHECK(d.state() == State::Safety);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("running"));                  // protection back
    CHECK(get("/__mounts__").find("/vendor/etc/thermal-engine.conf") != std::string::npos); // tuned template
    CHECK(get(HICO_STATE_FILE).find("tuned vendor thermal") != std::string::npos);

    set_cpu_temp(98500); // 95 + 3: hard margin, full stock
    d.tick(t += 2s);
    CHECK(d.state() == State::Safety);
    CHECK(get("/__mounts__").find("/vendor/etc/thermal-engine.conf") == std::string::npos);
    CHECK(get(HICO_STATE_FILE).find("stock thermal") != std::string::npos);

    set_cpu_temp(80000); // cooled: back to the unlock
    d.tick(t += 12s);
    CHECK(d.state() == State::Boost);
    CHECK_EQ(props::get("init.svc.thermal-engine"), std::string("stopped"));
    CHECK(get(HICO_STATE_FILE).find("trips=1") != std::string::npos);
    stop_game();
    d.tick(t += 1s); // exit grace period starts
    d.tick(t += 5s);
    CHECK(d.state() == State::Idle);

    // A thermal HAL the system restarts every time it is stopped is left running after a few
    // returns, instead of being stopped (and re-initialising) on every poll.
    build_device();
    Journal j(HICO_JOURNAL_FILE);
    ThermalController c(j, DeviceProfile{});
    Config x;
    x.mode = Mode::Extreme;
    for (int i = 0; i < 5; ++i) {
        c.unlock(x);
        put("/__props__/init.svc.vendor.thermal-hal-2-0", "running"); // servicemanager brings it back
    }
    const std::string ctl = get("/__props__/__ctl_log__");
    size_t stops = 0;
    for (size_t pos = 0; (pos = ctl.find("ctl.stop vendor.thermal-hal-2-0", pos)) != std::string::npos; ++pos) ++stops;
    CHECK_EQ(stops, 3u);
    c.restore();
}

int main() {
    char tmpl[] = "/tmp/hico-test-XXXXXX";
    if (!mkdtemp(tmpl)) return 1;
    g_root = std::string(tmpl) + "/root";
    setenv("HICO_ROOT", g_root.c_str(), 1);
    log::init("", log::Level::Warn);

    const std::vector<std::pair<const char *, std::function<void()>>> tests{
        {"strings and paths", test_strings_and_paths},
        {"config", test_config},
        {"classification", test_classification},
        {"safety guard", test_safety_guard},
        {"flux link", test_flux_link},
        {"thermal controller", test_controller},
        {"journal tampering", test_journal_rejects_tampering},
        {"daemon state machine", test_daemon_state_machine},
        {"session history", test_sessions_are_bounded},
        {"device database", test_device_database},
        {"thermal tuner", test_thermal_tuner},
        {"relaxed overlay", test_relaxed_overlay},
        {"graduated safety and respawning HAL", test_graduated_safety},
        {"levels, whitelist, blacklist", test_levels_whitelist_blacklist},
        {"thermal HAL JSON tuner", test_hal_json_tuner},
        {"mi_thermald crypt and tuner", test_mi_thermald},
        {"ROM detection and HAL overlay", test_rom_and_hal_overlay},
        {"throttling monitor", test_monitor},
    };

    for (const auto &[name, fn] : tests) {
        const int before = g_failures;
        build_device();
        fn();
        std::cout << (g_failures == before ? "PASS " : "FAIL ") << name << "\n";
    }

    stdfs::remove_all(tmpl);
    std::cout << g_checks << " checks, " << g_failures << " failures\n";
    return g_failures ? 1 : 0;
}
