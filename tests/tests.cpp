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
#include "DeviceProfile.hpp"
#include "FluxLink.hpp"
#include "Fs.hpp"
#include "HiCo.hpp"
#include "Journal.hpp"
#include "Log.hpp"
#include "Props.hpp"
#include "SafetyGuard.hpp"
#include "Sessions.hpp"
#include "ThermalController.hpp"
#include "ThermalServices.hpp"
#include "ThermalZones.hpp"

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
    CHECK(!c.set("excluded_games", "com.a.b, com.c_d ,com.a.b"));
    CHECK_EQ(c.excluded_games.size(), 2u);
    CHECK(c.is_excluded("com.c_d"));
    CHECK(c.set("excluded_games", "com.a;rm -rf /").has_value());

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

    // Performance Lite (Flux saw thermal pressure) with unlock_on_lite=0 stays stock.
    write_config("unlock_on_lite=0\n");
    d.reload_config();
    start_game("com.dts.freefireth", 2);
    d.tick(t += 1s);
    CHECK(d.state() == State::Idle);

    // Excluded games stay stock.
    write_config("excluded_games=com.dts.freefireth\n");
    d.reload_config();
    start_game("com.dts.freefireth", 1);
    d.tick(t += 1s);
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

void test_device_profile() {
    build_device();
    // Synthetic profile ("testdev" is not a real codename).
    const std::string dir = HICO_XIAOMI_DEVICES_DIR;
    put(dir + "/testdev.prop", "# generated\ncodename=testdev\nbrand=Redmi\nmodel=Test Phone\nplatform=testsoc\n"
                               "source=https://example.invalid/dump\nmi_thermald=1\n"
                               "thermal_services=mi_thermald,vendor.tmd_daemon,bad;name\n"
                               "thermal_configs=thermal-normal.conf,thermal-tgame.conf\n");
    put("/__props__/ro.product.vendor.device", "testdev");
    put("/__props__/init.svc.vendor.tmd_daemon", "running"); // vendor thermal daemon without "thermal" in its name

    CHECK_EQ(device_codename(), std::string("testdev"));
    const auto p = DeviceProfile::detect(dir);
    CHECK(p.has_value());
    CHECK(p && p->model == "Test Phone" && p->has_mi_thermald);
    CHECK(p && p->thermal_services.size() == 2); // invalid name dropped
    CHECK(p && p->thermal_configs.size() == 2);

    // A profile whose codename does not match its file name is ignored.
    put(dir + "/other.prop", "codename=testdev\n");
    CHECK(!DeviceProfile::load(dir + "/other.prop", "other"));
    // Codenames are validated before building a path.
    put("/__props__/ro.product.vendor.device", "../../etc");
    put("/__props__/ro.product.device", "");
    CHECK(device_codename().empty());
    CHECK(!DeviceProfile::detect(dir));
    put("/__props__/ro.product.vendor.device", "testdev");

    Journal journal(HICO_JOURNAL_FILE);
    ThermalController c(journal, p);
    CHECK(c.profile().has_value());
    const auto s = c.unlock(Config{});
    CHECK_EQ(s.services, 3);
    CHECK_EQ(props::get("init.svc.vendor.tmd_daemon"), std::string("stopped"));
    c.restore();
    CHECK_EQ(props::get("init.svc.vendor.tmd_daemon"), std::string("running"));

    // Without a profile the same daemon is not recognised (name-based detection only).
    Journal j2(HICO_JOURNAL_FILE);
    ThermalController generic(j2, std::nullopt);
    generic.unlock(Config{});
    CHECK_EQ(props::get("init.svc.vendor.tmd_daemon"), std::string("running"));
    generic.restore();

    Daemon d;
    d.tick(Daemon::Clock::time_point{} + 100s);
    CHECK(get(HICO_STATE_FILE).find("device_profile=verified") != std::string::npos);
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
        {"device profile", test_device_profile},
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
