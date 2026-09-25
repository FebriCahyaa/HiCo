/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Config.hpp"
#include "Daemon.hpp"
#include "DeviceProfile.hpp"
#include "FluxLink.hpp"
#include "Fs.hpp"
#include "HiCo.hpp"
#include "Log.hpp"
#include "ThermalServices.hpp"
#include "ThermalZones.hpp"

#include <chrono>
#include <cstdio>
#include <cstring>
#include <format>
#include <string>
#include <string_view>
#include <thread>
#include <vector>

#include <fcntl.h>
#include <signal.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace hico;

namespace {

void out(std::string_view s) {
    std::fwrite(s.data(), 1, s.size(), stdout);
}

int usage() {
    out("HiCo Thermal " HICO_VERSION " - automatic thermal unlock for games (requires Flux Tweaks)\n\n"
        "Usage: hicod <command>\n\n"
        "  daemon                 start the background service\n"
        "  run                    run in the foreground (debugging)\n"
        "  status [--json]        current state, temperatures and Flux link\n"
        "  restore                stop the service and restore stock thermal now\n"
        "  flux                   check the Flux Tweaks dependency (exit 0 when ready)\n"
        "  config list            show every setting\n"
        "  config get <key>\n"
        "  config set <key> <value>\n"
        "  config reset           restore default settings\n"
        "  config upgrade         add new keys and normalise values (installer)\n"
        "  config schema          settings description (JSON)\n"
        "  sessions [clear]       gaming session history (JSON Lines)\n"
        "  zones                  thermal zones, cooling devices and services\n"
        "  device [--list]        this device in the compiled database, or the whole database\n"
        "  version\n");
    return 2;
}

bool ensure_dirs() {
    return fs::ensure_dir(HICO_CONFIG_DIR, 0700) && fs::ensure_dir(HICO_RUNTIME_DIR, 0700);
}

/// PID of the running daemon (verified by its comm name), or 0.
pid_t daemon_pid() {
    const int fd = open(fs::real(HICO_LOCK_FILE).c_str(), O_RDONLY | O_CLOEXEC | O_NOFOLLOW);
    if (fd < 0) return 0;
    const bool held = flock(fd, LOCK_EX | LOCK_NB) != 0 && errno == EWOULDBLOCK;
    if (!held) flock(fd, LOCK_UN);
    close(fd);
    if (!held) return 0;

    const auto pid = str::to_int(fs::read(HICO_LOCK_FILE, 32).value_or("")).value_or(0);
    if (pid <= 0) return 0;
    // Never signal a recycled PID that is not hicod.
    if (fs::read("/proc/" + std::to_string(pid) + "/comm", 64) != "hicod") return 0;
    return static_cast<pid_t>(pid);
}

/// Holds the singleton lock for the lifetime of the process. Returns false if another daemon runs.
bool acquire_lock() {
    const int fd = open(fs::real(HICO_LOCK_FILE).c_str(), O_RDWR | O_CREAT | O_CLOEXEC | O_NOFOLLOW, 0600);
    if (fd < 0 || flock(fd, LOCK_EX | LOCK_NB) != 0) {
        if (fd >= 0) close(fd);
        return false;
    }
    const std::string pid = std::to_string(getpid());
    if (ftruncate(fd, 0) != 0 || pwrite(fd, pid.data(), pid.size(), 0) < 0) return false;
    return true; // fd intentionally kept open
}

int cmd_daemon(bool foreground) {
    if (!ensure_dirs()) {
        std::fprintf(stderr, "cannot create %s or %s\n", HICO_CONFIG_DIR, HICO_RUNTIME_DIR);
        return 1;
    }
    if (daemon_pid() != 0) {
        std::fprintf(stderr, "hicod is already running\n");
        return 1;
    }
    if (!foreground && daemon(0, 0) != 0) {
        std::perror("daemon");
        return 1;
    }
    if (!acquire_lock()) {
        std::fprintf(stderr, "hicod is already running\n");
        return 1;
    }

    log::init(foreground ? "" : HICO_LOG_FILE, log::Level::Info);
    Daemon d;
    LOGI("HiCo Thermal {} started (pid {})", HICO_VERSION, getpid());
    d.recover();
    return d.run();
}

int cmd_restore() {
    log::init("", log::Level::Warn);
    if (const pid_t pid = daemon_pid()) {
        kill(pid, SIGTERM);
        // The daemon restores stock thermal itself before exiting.
        for (int i = 0; i < 50 && kill(pid, 0) == 0; ++i) std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    Journal journal(HICO_JOURNAL_FILE);
    journal.load();
    const auto r = journal.restore();
    fs::remove(HICO_STATE_FILE);
    out(std::format("stock thermal restored ({} nodes, {} services, {} failed)\n", r.nodes, r.services, r.failed));
    return r.failed ? 1 : 0;
}

int cmd_status(bool json) {
    const auto state = fs::read(HICO_STATE_FILE, 8192);
    const bool running = daemon_pid() != 0;
    const auto flux_status = flux::probe();
    const auto temps = thermal::read_temperatures(thermal::zones());
    const auto opt = [](const std::optional<double> &v) { return v ? std::format("{:.1f}", *v) : std::string{}; };

    std::vector<std::pair<std::string, std::string>> kv;
    if (running && state) {
        for (const auto &line : str::split(*state, '\n')) {
            const auto eq = line.find('=');
            if (eq != std::string::npos) kv.emplace_back(line.substr(0, eq), line.substr(eq + 1));
        }
    } else {
        kv.emplace_back("state", "stopped");
    }
    // Live readings override the daemon's last sample (it only samples often while gaming).
    const auto set = [&kv](const std::string &k, const std::string &v) {
        for (auto &[key, value] : kv) {
            if (key == k) {
                value = v;
                return;
            }
        }
        kv.emplace_back(k, v);
    };
    set("running", running ? "1" : "0");
    set("flux", std::string(flux::describe(flux_status.availability)));
    set("flux_version", flux_status.version);
    set("cpu_temp", opt(temps.cpu));
    set("gpu_temp", opt(temps.gpu));
    set("battery_temp", opt(temps.battery));
    set("version", HICO_VERSION);
    const DeviceProfile device = DeviceProfile::detect();
    set("device", device.codename);
    set("device_profile", device.in_database ? "verified" : "generic");
    set("device_name", device.in_database ? str::trim(device.brand + " " + device.model) : "");
    set("soc", std::string(to_string(device.soc)));

    if (!json) {
        for (const auto &[k, v] : kv) out(std::format("{}={}\n", k, v));
        return running ? 0 : 1;
    }
    std::string s = "{";
    for (size_t i = 0; i < kv.size(); ++i) {
        s += std::format("{}\"{}\":\"{}\"", i ? "," : "", json_escape(kv[i].first), json_escape(kv[i].second));
    }
    out(s + "}\n");
    return 0;
}

int cmd_flux() {
    const auto st = flux::probe();
    out(std::format("flux={}\nversion={}\nversion_code={}\nmin_version_code={}\n", flux::describe(st.availability),
                    st.version, st.version_code, FLUX_MIN_VERSION_CODE));
    return st.availability == flux::Availability::Ready ? 0 : 1;
}

int cmd_config(const std::vector<std::string_view> &args) {
    log::init("", log::Level::Error);
    if (args.empty()) return usage();
    Config cfg = Config::load(HICO_CONFIG_FILE);
    const std::string_view sub = args[0];

    if (sub == "list") {
        out(cfg.serialize(false));
        return 0;
    }
    if (sub == "get" && args.size() == 2) {
        const auto v = cfg.get(args[1]);
        if (!v) {
            std::fprintf(stderr, "unknown key\n");
            return 1;
        }
        out(*v + "\n");
        return 0;
    }
    if (sub == "schema") {
        std::string s = "[";
        bool first = true;
        for (const auto &k : config_keys()) {
            s += std::format(R"({}{{"key":"{}","type":"{}","min":{},"max":{},"help":"{}","value":"{}"}})", first ? "" : ",",
                             k.key, k.type, k.min, k.max, json_escape(k.help), json_escape(cfg.get(k.key).value_or("")));
            first = false;
        }
        out(s + "]\n");
        return 0;
    }
    if (!ensure_dirs()) return 1;
    if (sub == "set" && args.size() == 3) {
        if (const auto err = cfg.set(args[1], args[2])) {
            std::fprintf(stderr, "%s\n", err->c_str());
            return 1;
        }
    } else if (sub == "reset") {
        cfg = Config{};
    } else if (sub == "upgrade") {
        // Rewrites the file with every current key (new keys get defaults, invalid values are clamped).
    } else {
        return usage();
    }
    // The daemon watches the file and reloads it (IN_MOVED_TO from the atomic rename).
    if (!cfg.save(HICO_CONFIG_FILE)) {
        std::fprintf(stderr, "cannot write %s\n", HICO_CONFIG_FILE);
        return 1;
    }
    return 0;
}

int cmd_sessions(bool clear) {
    if (clear) return fs::remove(HICO_SESSIONS_FILE) ? 0 : 1;
    if (const auto s = fs::read(HICO_SESSIONS_FILE, 256 * 1024); s && !s->empty()) out(*s + "\n");
    return 0;
}

std::string join(const std::vector<std::string> &v) {
    std::string out;
    for (const auto &s : v) out += (out.empty() ? "" : ", ") + s;
    return out.empty() ? "-" : out;
}

void print_device(const DeviceProfile &d) {
    static constexpr std::pair<Trait, const char *> kTraitNames[] = {
        {kTraitMiThermald, "mi_thermald"},        {kTraitThermalEngine, "thermal-engine"},
        {kTraitMtkThermal, "mtk-thermal"},        {kTraitSceneConfigs, "scene-configs"},
        {kTraitNoLimitsScene, "nolimits-scene"},  {kTraitThermalHal, "thermal-hal"},
    };
    std::vector<std::string> traits;
    for (const auto &[bit, name] : kTraitNames) {
        if (d.has(bit)) traits.emplace_back(name);
    }
    std::vector<std::string> backends;
    for (const auto &b : make_backends(d)) backends.emplace_back(b->name());

    out(std::format("== Device\ncodename: {}\ndatabase: {}\n", d.codename.empty() ? "unknown" : d.codename,
                    d.in_database ? "yes (" + d.source + ")" : "no, runtime detection only"));
    out(std::format("name: {} {}\nplatform: {} ({})\nandroid: {}\n", d.brand, d.model, d.platform.empty() ? "-" : d.platform,
                    to_string(d.soc), d.android.empty() ? "-" : d.android));
    out(std::format("traits: {}\nbackends: {}\n", join(traits), join(backends)));
    out(std::format("declared thermal services: {}\nthermal configs: {}\n", join(d.thermal_services),
                    d.thermal_configs.size()));
}

int cmd_device(bool list) {
    if (!list) {
        print_device(DeviceProfile::detect());
        return 0;
    }
    out(std::format("# compiled device database: {}\n", device_db::generated_from()));
    for (const auto &r : device_db::records()) {
        out(std::format("{:<20} {:<10} {} {}\n", r.codename, to_string(soc_from_platform(r.platform)), r.brand, r.model));
    }
    return 0;
}

int cmd_zones() {
    const auto kind = [](thermal::ZoneKind k) {
        switch (k) {
        case thermal::ZoneKind::Cpu: return "cpu";
        case thermal::ZoneKind::Gpu: return "gpu";
        case thermal::ZoneKind::Battery: return "battery (protected)";
        case thermal::ZoneKind::Other: return "other";
        }
        return "";
    };

    out("== Thermal zones\n");
    for (const auto &z : thermal::zones()) {
        const auto t = z.temp_c();
        out(std::format("{:<18} {:<28} {:>7} {:<12} {}\n", z.dir.substr(z.dir.rfind('/') + 1), z.type,
                        t ? std::format("{:.1f}C", *t) : "-", fs::read(z.dir + "/policy").value_or("-"), kind(z.kind)));
    }
    out("\n== Cooling devices\n");
    for (const auto &d : thermal::cooling_devices()) {
        out(std::format("{:<18} {:<28} state {}/{}{}\n", d.dir.substr(d.dir.rfind('/') + 1), d.type,
                        fs::read(d.dir + "/cur_state").value_or("?"), fs::read(d.dir + "/max_state").value_or("?"),
                        thermal::is_performance_cooling(d.type) ? "" : "  (kept)"));
    }
    const DeviceProfile device = DeviceProfile::detect();
    out("\n");
    print_device(device);

    out("\n== Thermal services\n");
    for (const auto &s : services::thermal_services(device.thermal_services)) {
        out(std::format("{:<36} {:<10} {}\n", s.name, s.state, s.kind == services::Kind::Hal ? "hal" : "daemon"));
    }
    return 0;
}

} // namespace

int main(int argc, char **argv) {
    std::vector<std::string_view> args(argv + 1, argv + argc);
    if (args.empty()) return usage();

    const std::string_view cmd = args[0];
    if (cmd == "version" || cmd == "--version") {
        out(HICO_VERSION "\n");
        return 0;
    }
    if (cmd == "help" || cmd == "--help") {
        usage();
        return 0;
    }

#ifdef __ANDROID__
    if (getuid() != 0) {
        std::fprintf(stderr, "hicod must run as root\n");
        return 1;
    }
#endif
    umask(077);

    if (cmd == "daemon") return cmd_daemon(false);
    if (cmd == "run") return cmd_daemon(true);
    if (cmd == "restore" || cmd == "stop") return cmd_restore();
    if (cmd == "status") return cmd_status(args.size() > 1 && args[1] == "--json");
    if (cmd == "flux") return cmd_flux();
    if (cmd == "config") return cmd_config({args.begin() + 1, args.end()});
    if (cmd == "sessions") return cmd_sessions(args.size() > 1 && args[1] == "clear");
    if (cmd == "zones") return cmd_zones();
    if (cmd == "device") return cmd_device(args.size() > 1 && args[1] == "--list");
    return usage();
}
