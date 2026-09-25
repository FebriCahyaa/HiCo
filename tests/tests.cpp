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

} // namespace

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
        {"levels, whitelist, blacklist", test_levels_whitelist_blacklist},
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
