/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Config.hpp"
#include "Daemon.hpp"
#include "ThermalConfig.hpp"
#include "DeviceProfile.hpp"
#include "FluxLink.hpp"
#include "Fs.hpp"
#include "HiCo.hpp"
#include "Journal.hpp"
#include "Log.hpp"
#include "MiCrypt.hpp"
#include "Monitor.hpp"
#include "ThermalServices.hpp"
#include "ThermalZones.hpp"

#include <chrono>
#include <cstdio>
#include <cstring>
#include <ctime>
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
    out("HiCo Thermal " HICO_VERSION " - device-aware thermal management\n\n"
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
        "  config preset <name>   apply a preset: daily, cool, balanced, extreme, overclock\n"
        "  config presets         presets and their values (JSON)\n"
        "  config upgrade         add new keys and normalise values (installer)\n"
        "  config schema          settings description (JSON)\n"
        "  sessions [clear]       gaming session history (JSON Lines)\n"
        "  zones                  thermal zones, cooling devices and services\n"
        "  monitor [--once] [--interval S]   live thermal state, temperatures, trips and cooling\n"
        "  monitor --json         one thermal snapshot (JSON, used by the WebUI)\n"
        "  device [--list]        this device in the compiled database, or the whole database\n"
        "  thermal scan           vendor thermal configs and what the relaxed level would tune\n"
        "  thermal policy [--platform P] [--margin N]\n"
        "  thermal tune <file> [--platform P] [--margin N]   tuned config on stdout\n"
        "  thermal check <original> <tuned> [--platform P] [--margin N]\n"
        "      tune/check also take --ceilings DIR (mi_thermald: that device's configs) and tune --plain\n"
        "  thermal table [--json]             current thermal zone/trip table\n"
        "  thermal sources [--json]           who controls thermal here: configs, daemons, HiCo overlays\n"
        "  thermal decrypt <in> [out]         encrypted mi_thermald config -> text\n"
        "  thermal encrypt <in> <out>         text -> encrypted mi_thermald config\n"
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
    set("device_source", device.codename_source);
    set("preset", std::string(matching_preset(Config::load(HICO_CONFIG_FILE))));
    set("device_profile", device.in_database ? "verified" : "generic");
    set("device_name", device.in_database ? str::trim(device.brand + " " + device.model) : "");
    set("soc", std::string(to_string(device.soc)));
    set("rom", std::string(to_string(device.rom)));
    set("rom_name", device.rom_name);

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
    if (sub == "presets") {
        std::string s = std::format(R"({{"current":"{}","presets":[)", matching_preset(cfg));
        bool first = true;
        for (const auto &p : config_presets()) {
            s += std::format(R"({}{{"name":"{}","values":{{)", first ? "" : ",", p.name);
            for (size_t i = 0; i < p.values.size(); ++i) {
                s += std::format(R"({}"{}":"{}")", i ? "," : "", p.values[i].first, p.values[i].second);
            }
            s += "}}";
            first = false;
        }
        out(s + "]}\n");
        return 0;
    }
    if (!ensure_dirs()) return 1;
    if (sub == "preset" && args.size() == 2) {
        if (const auto err = apply_preset(cfg, args[1])) {
            std::fprintf(stderr, "%s\n", err->c_str());
            return 1;
        }
    } else if (sub == "set" && args.size() == 3) {
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

    out(std::format("== Device\ncodename: {}{}\ndatabase: {}\n", d.codename.empty() ? "unknown" : d.codename,
                    d.codename_source.empty() ? "" : " (from " + d.codename_source + ")",
                    d.in_database ? "yes (" + d.source + ")" : "no, runtime detection only"));
    out(std::format("name: {} {}\nplatform: {} ({})\nandroid: {}\n", d.brand, d.model, d.platform.empty() ? "-" : d.platform,
                    to_string(d.soc), d.android.empty() ? "-" : d.android));
    out(std::format("rom: {} ({}){}\n", d.rom_name, to_string(d.rom),
                    d.in_database && d.rom != RomFamily::HyperOS && d.rom != RomFamily::Miui
                        ? "; database record is from the stock firmware, services are still detected live"
                        : ""));
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

/// hicod thermal ...: the thermal config tuner, on the device or over firmware files in the repository.
int cmd_thermal_table(const std::vector<std::string_view> &args) {
    bool json = false;
    for (const auto arg : args) {
        if (arg == "--json") json = true;
        else return usage();
    }
    const auto snapshot = monitor::sample();
    if (json) {
        out(monitor::to_json(snapshot) + "\n");
        return 0;
    }
    out(monitor::to_table(snapshot));
    return 0;
}

/// Thermal identification: which configs and daemons protect this phone, and which of them HiCo
/// currently overrides (journal: tuned copies mounted, services stopped). Read-only.
int cmd_thermal_sources(const std::vector<std::string_view> &args) {
    bool json = false;
    for (const auto arg : args) {
        if (arg == "--json") json = true;
        else return usage();
    }
    const DeviceProfile d = DeviceProfile::detect();
    Journal journal(HICO_JOURNAL_FILE);
    journal.load();
    const auto format_name = [](thermalcfg::Format f) -> std::string_view {
        switch (f) {
        case thermalcfg::Format::Engine: return "thermal-engine";
        case thermalcfg::Format::HalJson: return "thermal-hal-json";
        case thermalcfg::Format::MiThermald: return "mi_thermald";
        case thermalcfg::Format::MiEncrypted: return "mi_thermald-encrypted";
        case thermalcfg::Format::Unknown: break;
        }
        return "unknown";
    };
    const auto kind_name = [](services::Kind k) -> std::string_view {
        return k == services::Kind::Hal ? "hal" : k == services::Kind::Daemon ? "daemon" : "other";
    };
    struct ConfigInfo {
        std::string path;
        std::string_view format;
        size_t size = 0;
        bool tunable = false;
        bool hico = false;
    };
    std::vector<ConfigInfo> configs;
    for (const auto &path : thermalcfg::identify_config_files()) {
        const auto content = fs::read_raw(path, 4 << 20);
        if (!content) continue;
        // MediaTek thermal policies: identified by location, never tuned.
        const bool mtk = path.find("/.tp/") != std::string::npos;
        configs.push_back({path, mtk ? "mtk-thermal-policy" : format_name(thermalcfg::detect_format(*content)),
                           content->size(), !mtk && thermalcfg::plain_text(*content).has_value(), journal.has_mount(path)});
    }
    const auto svcs = services::thermal_services(d.thermal_services);
    std::vector<std::string> backends;
    for (const auto &b : make_backends(d)) backends.emplace_back(b->name());

    if (!json) {
        out(std::format("device: {} ({} {}, {} {}), database: {}\nrom: {}\nbackends: {}\nHiCo active: {}\n\n",
                        d.codename.empty() ? "unknown" : d.codename, d.brand, d.model, to_string(d.soc), d.platform,
                        d.in_database ? "yes" : "no", d.rom_name, join(backends), journal.empty() ? "no" : "yes"));
        out("== thermal configs\n");
        for (const auto &c : configs) {
            out(std::format("{:<52} {:<22} {:>8} B  {}{}\n", c.path, c.format, c.size, c.hico ? "HiCo (tuned copy)" : "vendor",
                            c.tunable ? "" : ", read-only"));
        }
        out("\n== thermal services\n");
        for (const auto &sv : svcs) {
            out(std::format("{:<40} {:<7} {}{}\n", sv.name, kind_name(sv.kind), sv.state,
                            journal.has_service(sv.name) ? " (stopped by HiCo)" : journal.has_restart(sv.name) ? " (restarted by HiCo)" : ""));
        }
        return 0;
    }
    std::string o = std::format(
        R"({{"device":{{"codename":"{}","brand":"{}","model":"{}","platform":"{}","soc":"{}","rom":"{}","rom_name":"{}","in_database":{},"source":"{}","backends":[)",
        json_escape(d.codename), json_escape(d.brand), json_escape(d.model), json_escape(d.platform), to_string(d.soc),
        to_string(d.rom), json_escape(d.rom_name), d.in_database ? "true" : "false", json_escape(d.source));
    for (size_t i = 0; i < backends.size(); ++i) o += std::format("{}\"{}\"", i ? "," : "", json_escape(backends[i]));
    o += std::format(R"(]}},"hico_active":{},"journal_entries":{},"configs":[)", journal.empty() ? "false" : "true", journal.size());
    for (size_t i = 0; i < configs.size(); ++i) {
        const auto &c = configs[i];
        o += std::format(R"({}{{"path":"{}","format":"{}","size":{},"tunable":{},"controller":"{}"}})", i ? "," : "",
                         json_escape(c.path), c.format, c.size, c.tunable ? "true" : "false", c.hico ? "hico" : "vendor");
    }
    o += "],\"services\":[";
    for (size_t i = 0; i < svcs.size(); ++i) {
        const auto &sv = svcs[i];
        const std::string_view by = journal.has_service(sv.name) ? "stopped" : journal.has_restart(sv.name) ? "restarted" : "";
        o += std::format(R"({}{{"name":"{}","kind":"{}","state":"{}","hico":"{}"}})", i ? "," : "", json_escape(sv.name),
                         kind_name(sv.kind), json_escape(sv.state), by);
    }
    o += "]}\n";
    out(o);
    return 0;
}

int cmd_thermal(const std::vector<std::string_view> &args) {
    if (args.empty()) return usage();
    if (args[0] == "table") return cmd_thermal_table({args.begin() + 1, args.end()});
    if (args[0] == "sources") return cmd_thermal_sources({args.begin() + 1, args.end()});
    std::string platform;
    int margin = 0;
    std::vector<std::string> files;
    std::string ceilings_dir;
    bool plain_out = false;
    for (size_t i = 1; i < args.size(); ++i) {
        if (args[i] == "--platform" && i + 1 < args.size()) platform = std::string(args[++i]);
        else if (args[i] == "--ceilings" && i + 1 < args.size()) ceilings_dir = std::string(args[++i]);
        else if (args[i] == "--plain") plain_out = true;
        else if (args[i] == "--margin" && i + 1 < args.size()) margin = static_cast<int>(str::to_int(args[++i]).value_or(0));
        else files.emplace_back(args[i]);
    }
    const DeviceProfile device = platform.empty() ? DeviceProfile::detect() : DeviceProfile{};
    const std::string plat = platform.empty() ? device.platform : platform;
    const SocVendor soc = platform.empty() ? device.soc : soc_from_platform(platform);
    auto policy = thermalcfg::policy_for(soc, plat, margin);
    // mi_thermald ceilings: from a directory of one device's configs (repository), or the device itself.
    const auto add_ceilings = [&policy](const std::string &path) {
        if (const auto raw = fs::read_raw(path, 512 * 1024)) {
            const auto fmt = thermalcfg::detect_format(*raw);
            if (fmt == thermalcfg::Format::MiThermald || fmt == thermalcfg::Format::MiEncrypted) {
                if (const auto plain = thermalcfg::plain_text(*raw)) {
                    thermalcfg::mithermald::collect_ceilings(*plain, policy.mi_ceilings);
                }
            }
        }
    };
    if (!ceilings_dir.empty()) {
        for (const auto &name : fs::list_dir(ceilings_dir)) {
            if (name.ends_with(".conf")) add_ceilings(ceilings_dir + "/" + name);
        }
    }

    // Encrypted mi_thermald configs: hicod thermal decrypt <in> [out], encrypt <in> <out>.
    if ((args[0] == "decrypt" || args[0] == "encrypt") && !files.empty() && files.size() <= 2) {
        const auto content = fs::read_raw(files[0], 512 * 1024);
        if (!content) {
            std::fprintf(stderr, "cannot read %s\n", files[0].c_str());
            return 1;
        }
        std::string result;
        if (args[0] == "decrypt") {
            const auto plain = micrypt::decrypt(*content);
            if (!plain) {
                std::fprintf(stderr, "%s is not an encrypted mi_thermald config\n", files[0].c_str());
                return 1;
            }
            result = *plain;
        } else {
            if (files.size() != 2) return usage(); // binary output only into a file
            result = micrypt::encrypt(*content);
        }
        if (files.size() == 2) return fs::write_atomic(files[1], result, 0644) ? 0 : 1;
        out(result);
        return 0;
    }
    const auto describe = [&] {
        return std::format("policy={} soc={} platform={} margin={} cap_cpu={} cap_other={} shutdown_guard={}", policy.name,
                           to_string(soc), plat.empty() ? "-" : plat, policy.margin_c, policy.cap_cpu_c, policy.cap_other_c,
                           policy.shutdown_guard_c);
    };

    if (args[0] == "policy") {
        out(describe() + "\n");
        return 0;
    }
    if (args[0] == "tune" && files.size() == 1) {
        const auto content = fs::read_raw(files[0], 512 * 1024);
        if (!content) {
            std::fprintf(stderr, "cannot read %s\n", files[0].c_str());
            return 1;
        }
        const auto r = thermalcfg::tune(*content, policy);
        if (!r) {
            std::fprintf(stderr, "%s sections=0 tuned=0 tunable=0\n", describe().c_str());
            return 2;
        }
        // --plain: an encrypted mi_thermald result as readable text (review, repository).
        out(plain_out ? thermalcfg::plain_text(r->text).value_or(r->text) : r->text);
        std::fprintf(stderr, "%s sections=%d tuned=%d tunable=1\n", describe().c_str(), r->sections, r->tuned_sections);
        for (const auto &n : r->notes) std::fprintf(stderr, "note: %s\n", n.c_str());
        return 0;
    }
    if (args[0] == "check" && files.size() == 2) {
        const auto a = fs::read_raw(files[0], 512 * 1024);
        const auto b = fs::read_raw(files[1], 512 * 1024);
        if (!a || !b) return 1;
        const auto errors = thermalcfg::verify(*a, *b, policy);
        for (const auto &e : errors) std::fprintf(stderr, "violation: %s\n", e.c_str());
        return errors.empty() ? 0 : 1;
    }
    if (args[0] == "scan") {
        // What the relaxed level would do on this device, without changing anything.
        for (const auto &path : thermalcfg::device_config_files()) add_ceilings(path);
        out(describe() + std::format(" mi_ceilings={}\n", policy.mi_ceilings.size()));
        for (const auto &path : thermalcfg::device_config_files()) {
            const bool mounted = fs::is_mounted(path);
            const auto content = fs::read_raw(path, 512 * 1024);
            const auto r = content ? thermalcfg::tune(*content, policy) : std::nullopt;
            out(std::format("{:<48} {}\n", path,
                            mounted ? "relaxed (mounted)"
                            : !content ? "unreadable"
                            : !r       ? "not tunable (unknown format)"
                                       : std::format("{} of {} sections tunable{}", r->tuned_sections, r->sections,
                                                     thermalcfg::detect_format(*content) == thermalcfg::Format::MiEncrypted
                                                         ? " (encrypted mi_thermald)"
                                                         : "")));
        }
        return 0;
    }
    return usage();
}

/// Live throttling view. Read-only: it never writes a node and works whether or not the daemon runs.
int cmd_monitor(const std::vector<std::string_view> &args) {
    bool json = false;
    bool once = false;
    long long interval = 1;
    for (size_t i = 0; i < args.size(); ++i) {
        if (args[i] == "--json") {
            json = true;
        } else if (args[i] == "--once") {
            once = true;
        } else if (args[i] == "--interval" && i + 1 < args.size()) {
            const auto v = str::to_int(args[++i]);
            if (!v || *v < 1 || *v > 60) {
                std::fprintf(stderr, "--interval must be 1-60 seconds\n");
                return 2;
            }
            interval = *v;
        } else {
            return usage();
        }
    }
    if (json) {
        out(monitor::to_json(monitor::sample()) + "\n");
        return 0;
    }
    for (;;) {
        const std::time_t now = std::time(nullptr);
        std::tm tm{};
        localtime_r(&now, &tm);
        char clock[16];
        std::strftime(clock, sizeof clock, "%H:%M:%S", &tm);
        out(std::format("{}  {}\n", clock, monitor::to_line(monitor::sample())));
        std::fflush(stdout);
        if (once) return 0;
        std::this_thread::sleep_for(std::chrono::seconds(interval));
    }
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
    if (cmd == "monitor") return cmd_monitor({args.begin() + 1, args.end()});
    if (cmd == "device") return cmd_device(args.size() > 1 && args[1] == "--list");
    if (cmd == "thermal") return cmd_thermal({args.begin() + 1, args.end()});
    return usage();
}
