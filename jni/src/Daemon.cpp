/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Daemon.hpp"

#include "Fs.hpp"
#include "HiCo.hpp"
#include "Log.hpp"
#include "Sha256.hpp"

#include <algorithm>
#include <array>
#include <cerrno>
#include <csignal>
#include <cstring>
#include <format>

#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/inotify.h>
#include <sys/signalfd.h>
#include <sys/wait.h>
#include <unistd.h>

namespace hico {

namespace {
/// Past these margins above the user's safety limits the soft landing (tuned vendor
/// thermal) is not enough: full stock thermal protection comes back.
constexpr double kHardMarginCpu = 3.0;
constexpr double kHardMarginBattery = 1.0;
/// s, how long social / streaming apps keep their relaxed configs after leaving the foreground.
constexpr int kAppExitHold = 20;

/// Session scenario from a target source ("performance", "warm", "social", ...).
std::string scenario_of(std::string_view source) {
    if (source == "social" || source == "media") return std::string(source);
    if (source == "whitelist") return "other";
    return "game";
}
} // namespace

namespace {

/// Flux liveness / game re-check period outside games (inotify covers the fast path).
constexpr std::chrono::seconds kIdleInterval{30};
/// Re-check period while fluxd is installed but not running yet (boot order between modules is not fixed).
constexpr std::chrono::seconds kFluxStartingInterval{5};
/// How often the signed release manifest is re-verified while the daemon runs (docs/INTEGRITY.md);
/// always additionally checked once on the first tick after (re)start.
constexpr std::chrono::minutes kIntegrityInterval{30};
/// How often the revocation list (docs/INTEGRITY.md, "Lapis 4") is fetched — much less often
/// than the local manifest check: it only ever matters after the author publishes something new
/// to it, and every fetch is a real network request.
constexpr std::chrono::hours kRevocationInterval{24};

/// Posts an Android notification as the shell user, like fluxd does.
void notify(const std::string &message) {
#ifdef __ANDROID__
    const pid_t pid = fork();
    if (pid == 0) {
        const int devnull = open("/dev/null", O_WRONLY | O_CLOEXEC);
        if (devnull >= 0) {
            dup2(devnull, STDOUT_FILENO);
            dup2(devnull, STDERR_FILENO);
        }
        if (setgid(2000) != 0 || setuid(2000) != 0) _exit(126);
        const char *args[] = {"cmd", "notification", "post", "-t", HICO_NAME, HICO_TAG, message.c_str(), nullptr};
        execv("/system/bin/cmd", const_cast<char *const *>(args));
        _exit(127);
    }
    if (pid > 0) {
        int status = 0;
        waitpid(pid, &status, 0);
    }
#else
    LOGI("notify: {}", message);
#endif
}

std::string format_temp(const std::optional<double> &t) {
    return t ? std::format("{:.1f}", *t) : "";
}

log::Level to_level(int v) {
    return static_cast<log::Level>(std::clamp(v, 0, 3));
}

} // namespace

std::string_view to_string(State s) {
    switch (s) {
    case State::Idle: return "idle";
    case State::Boost: return "boost";
    case State::Relaxed: return "relaxed";
    case State::Safety: return "safety";
    case State::Suspended: return "suspended";
    case State::Disabled: return "disabled";
    }
    return "unknown";
}

std::string json_escape(std::string_view s) {
    std::string out;
    for (const char c : s) {
        switch (c) {
        case '"': out += "\\\""; break;
        case '\\': out += "\\\\"; break;
        case '\n': out += "\\n"; break;
        default:
            if (static_cast<unsigned char>(c) < 0x20) out += std::format("\\u{:04x}", c);
            else out += c;
        }
    }
    return out;
}

Daemon::Daemon() : journal_(HICO_JOURNAL_FILE), controller_(journal_) {
    reload_config();
}

void Daemon::reload_config() {
    cfg_ = Config::load(HICO_CONFIG_FILE);
    log::set_level(to_level(cfg_.log_level));
    const SafetyGuard::Limits limits{
        .cpu_limit = static_cast<double>(cfg_.safety_cpu_temp),
        .cpu_hysteresis = static_cast<double>(cfg_.safety_cpu_hysteresis),
        .battery_limit = static_cast<double>(cfg_.safety_battery_temp),
        .battery_hysteresis = static_cast<double>(cfg_.safety_battery_hysteresis),
        .cooldown = std::chrono::seconds(cfg_.safety_cooldown),
    };
    guard_.set_limits(limits);
    headroom_.set_limits(limits);
}

void Daemon::recover() {
    journal_.load();
    if (journal_.empty()) return;
    const auto r = controller_.restore();
    LOGW("recovered stock thermal left by a previous instance: {} nodes, {} services, {} failed", r.nodes, r.services,
         r.failed);
}

void Daemon::check_integrity(Clock::time_point now) {
    if (next_integrity_check_ && now < *next_integrity_check_) return;
    next_integrity_check_ = now + kIntegrityInterval;

    integrity_ = integrity::verify_manifest(HICO_MODULE_DIR);
    integrity_signals_ = integrity::runtime_signals();
    if (integrity_revoked_) {
        // Sticky: re-applied every time, so this 30-minute refresh (which knows nothing about
        // revocation) can never make a revoked build quietly look fine again in between the much
        // less frequent revocation re-checks below.
        integrity_.status = integrity::Status::Revoked;
        integrity_.reason = revocation_reason_;
    }
    if (integrity_.status == integrity::Status::Ok) {
        integrity_notified_ = false; // a fresh reinstall clears a previous failure
    }
    if (integrity_failed()) {
        LOGE("integrity: {} (manifest {})", integrity_.reason,
            integrity_.manifest_version.empty() ? "?" : integrity_.manifest_version);
    } else {
        // Ok or Missing (an older build, or the manifest was stripped) — neither is a failure.
        LOGD("integrity: {}", integrity_.reason);
    }
    if (integrity_signals_.debugger_attached || !integrity_signals_.hook_libraries.empty()) {
        // Informational only (see Integrity.hpp): logged and shown in status, never itself a
        // reason to fail-safe — both signals have too many legitimate explanations to act on
        // alone (see docs/INTEGRITY.md).
        LOGW("integrity: runtime signal(s) present (debugger_attached={}, hooks={})",
            integrity_signals_.debugger_attached, integrity_signals_.hook_libraries.size());
    }

    check_revocation(now);
}

void Daemon::check_revocation(Clock::time_point now) {
    if (!cfg_.check_revocation) return;
    if (integrity_.status != integrity::Status::Ok) return; // nothing to add to an already-known verdict
    if (next_revocation_check_ && now < *next_revocation_check_) return;
    next_revocation_check_ = now + kRevocationInterval;

    const auto own_hash = sha256::hash_file(fs::real(std::string(HICO_MODULE_DIR) + "/system/bin/hicod"));
    if (!own_hash) return; // could not hash ourselves: leave the local manifest's verdict alone

    const auto fetched = revocation_fetcher_ ? revocation_fetcher_() : std::nullopt;
    if (!fetched) {
        LOGD("revocation: could not fetch (no HTTPS tool, no network, or it timed out) — trying again later");
        return;
    }
    const auto list = integrity::parse_revocation_list(*fetched);
    if (!list) {
        LOGW("revocation: fetched list did not parse as one, ignoring it");
        return;
    }
    if (integrity::is_revoked(*list, sha256::to_hex(*own_hash))) {
        revocation_reason_ =
            std::format("this build was published as compromised (revocation list updated {})", list->updated_at);
        integrity_revoked_ = true;
        integrity_.status = integrity::Status::Revoked; // this tick's value; check_integrity() keeps it sticky after
        integrity_.reason = revocation_reason_;
        LOGE("revocation: {}", integrity_.reason);
    }
}

bool Daemon::integrity_failed() const {
    return integrity_.status != integrity::Status::Ok && integrity_.status != integrity::Status::Missing;
}

std::chrono::milliseconds Daemon::next_timeout() const {
    if (state_ == State::Boost || state_ == State::Relaxed || state_ == State::Safety) {
        return std::chrono::seconds(cfg_.poll_interval);
    }
    if (state_ == State::Suspended && flux_.availability == flux::Availability::NotRunning) return kFluxStartingInterval;
    return kIdleInterval;
}

void Daemon::begin_session(const Target &target, Clock::time_point now) {
    session_ = Session{};
    session_->package = target.package;
    session_->scenario = scenario_of(target.source);
    session_->started = std::time(nullptr);
    session_start_ = now;
    guard_.reset();
    safety_relaxed_ = safety_notified_ = stock_notified_ = false;
    LOGI("session started: {} (pid {}, {}, level {})", target.package, target.pid, target.source, to_string(target.level));
}

void Daemon::end_session(Clock::time_point now) {
    if (!session_) return;
    session_->duration_s = std::chrono::duration_cast<std::chrono::seconds>(now - session_start_).count();
    LOGI("{} session ended: {} after {}s ({}s boosted, peak CPU {} C, peak battery {} C, {} safety trips)",
         session_->scenario, session_->package, session_->duration_s, session_->boosted_s, format_temp(session_->peak_cpu),
         format_temp(session_->peak_battery), session_->trips);
    // Sessions shorter than a few seconds are focus blips, not play.
    if (session_->duration_s >= 5 && !sessions::append(HICO_SESSIONS_FILE, *session_)) {
        LOGW("cannot write {}", HICO_SESSIONS_FILE);
    }
    session_.reset();
}

void Daemon::transition(State next, Clock::time_point now, std::string reason) {
    const bool keeps_overlay = next == State::Boost || next == State::Relaxed || (next == State::Safety && safety_relaxed_);
    if (!keeps_overlay && controller_.unlocked()) {
        const auto r = controller_.restore();
        LOGI("thermal restored: {} nodes, {} services, {} configs{}", r.nodes, r.services, r.mounts,
             r.failed ? std::format(", {} failed", r.failed) : "");
        summary_ = {};
    }
    if (!keeps_overlay) applied_.reset();

    if (next != State::Boost && next != State::Relaxed && next != State::Safety) {
        end_session(now);
        exit_deadline_.reset();
    }

    if (next != state_ || reason != reason_ || !described_) {
        const std::string why = reason.empty() ? "" : " (" + reason + ")";
        if (described_) LOGI("state {} -> {}{}", to_string(state_), to_string(next), why);
        else LOGI("state {}{}", to_string(next), why);
        state_since_ = std::time(nullptr);
    }
    const bool changed = next != state_ || !described_;
    state_ = next;
    reason_ = std::move(reason);
    if (changed) {
        update_module_description();
        described_ = true;
    }
}

void Daemon::tick(Clock::time_point now) {
    const auto elapsed = last_tick_.time_since_epoch().count() ? now - last_tick_ : Clock::duration::zero();
    last_tick_ = now;

    flux_ = flux::probe();

    check_integrity(now);
    if (integrity_failed()) {
        // Ahead of mode=off and the Flux check on purpose: this must hold regardless of
        // anything else, and it must never unlock even once before the check runs.
        if (cfg_.notify && !integrity_notified_) {
            notify(std::format("HiCo Thermal integrity check failed ({}). Thermal stays at stock "
                               "until this is fixed (reinstall from the official release).",
                               integrity_.reason));
            integrity_notified_ = true;
        }
        transition(State::Disabled, now, "integrity: " + integrity_.reason);
        publish({});
        return;
    }

    if (cfg_.mode == Mode::Off) {
        transition(State::Disabled, now, "mode=off");
        publish({});
        return;
    }
    if (flux_.availability != flux::Availability::Ready) {
        // HiCo is a Flux add-on: without a working Flux it keeps stock thermal and says why.
        if (flux_.availability != flux::Availability::NotRunning && !flux_warned_ && cfg_.notify) {
            notify(std::format("Flux Tweaks is required ({}). HiCo keeps stock thermal until Flux is ready.",
                               flux::describe(flux_.availability)));
            flux_warned_ = true;
        }
        transition(State::Suspended, now, std::format("Flux {}", flux::describe(flux_.availability)));
        publish({});
        return;
    }

    const std::optional<Target> target = choose_target();
    const bool active = state_ == State::Boost || state_ == State::Relaxed || state_ == State::Safety;

    if (!target) {
        if (active) {
            // Hold briefly: Flux can drop and re-apply the profile around a quick app switch.
            // Apps (social, streaming) are switched between often: hold their relaxed configs a bit
            // longer so the vendor daemons are not restarted on every trip through the launcher.
            // Screen off releases at once.
            const bool app = session_ && (session_->scenario == "social" || session_->scenario == "media");
            const auto fg = app ? flux::foreground() : std::nullopt;
            const int hold = app && fg && fg->screen_awake ? std::max(cfg_.exit_delay, kAppExitHold) : cfg_.exit_delay;
            if (!exit_deadline_) exit_deadline_ = now + std::chrono::seconds(hold);
            if (now < *exit_deadline_) {
                publish(thermal::read_temperatures(zones_));
                return;
            }
        }
        transition(State::Idle, now, {});
        publish({});
        return;
    }
    exit_deadline_.reset();

    if (!session_ || session_->package != target->package) {
        end_session(now);
        begin_session(*target, now);
    }
    if (zones_.empty()) zones_ = thermal::zones();

    const auto temps = thermal::read_temperatures(zones_);
    session_->observe(temps.cpu, temps.battery);
    if (state_ == State::Boost || state_ == State::Relaxed) {
        session_->boosted_s += std::chrono::duration_cast<std::chrono::seconds>(elapsed).count();
    }

    if (guard_.update(temps.cpu, temps.battery, now)) {
        // Graduated protection: first the vendor thermal comes back with this device's tuned
        // template (the Relaxed level: every protection active, trips bounded by the phone's own
        // configs); full stock thermal only past a hard margin above the limit, or on devices
        // without a tunable vendor config. Avoids the FPS cliff of dropping straight to stock.
        const bool hard = (temps.cpu && *temps.cpu >= cfg_.safety_cpu_temp + kHardMarginCpu) ||
                          (temps.battery && *temps.battery >= cfg_.safety_battery_temp + kHardMarginBattery);
        const bool entering = state_ != State::Safety;
        if (entering) {
            ++session_->trips;
            LOGW("safety guard: {}, {} for {}", guard_.reason(),
                 hard || relax_unavailable_ ? "restoring stock thermal" : "vendor thermal back on (tuned template)",
                 target->package);
        }
        if (!hard && !relax_unavailable_) {
            if (applied_ != Level::Relaxed && controller_.unlocked()) controller_.restore();
            summary_ = {};
            summary_.configs = controller_.relax(cfg_);
            if (summary_.configs > 0) {
                applied_ = Level::Relaxed;
                safety_relaxed_ = true;
                if (entering && cfg_.notify && !safety_notified_) {
                    notify(std::format("Hot ({}): vendor thermal is back with this phone's tuned limits until it cools down.",
                                       guard_.reason()));
                    safety_notified_ = true;
                }
                transition(State::Safety, now, guard_.reason() + ", tuned vendor thermal");
                publish(temps);
                return;
            }
            relax_unavailable_ = true; // nothing to tune here: stock is the only protection
        }
        if (safety_relaxed_) LOGW("safety guard: past the hard margin, restoring stock thermal");
        safety_relaxed_ = false;
        // One notice per session for stock protection (plus the soft-landing one above).
        if (cfg_.notify && !stock_notified_) {
            notify(std::format("Thermal protection restored: {}", guard_.reason()));
            stock_notified_ = true;
        }
        transition(State::Safety, now, guard_.reason() + ", stock thermal");
    } else {
        safety_relaxed_ = false;
        Target t = *target;
        // Max only with headroom below the safety limit (every mode, extreme too): a phone that
        // starts or gets hot plays at the relaxed level instead of running into the guard.
        const bool was_warm = headroom_.warm();
        if (headroom_.update(temps.cpu, temps.battery, now) && t.level == Level::Max) {
            t.level = Level::Relaxed;
            t.source = "warm";
            if (!was_warm) LOGI("max held back ({}): relaxed level for {}", headroom_.reason(), t.package);
        } else if (was_warm && !headroom_.warm() && t.level == Level::Max) {
            LOGI("cooled down: max level for {}", t.package);
        }
        apply(t, now);
    }
    publish(temps);
}

std::optional<Daemon::Target> Daemon::choose_target() const {
    if (const auto game = flux::active_game(); game && !cfg_.is_blacklisted(game->package)) {
        // "stock" for games: the ROM's own thermal while playing (the user's explicit choice wins,
        // extreme mode included).
        if (cfg_.game_level == Level::Stock) return std::nullopt;
        Target t{game->package, game->pid, cfg_.game_level, game->lite() ? "performance_lite" : "performance"};
        // Flux runs Performance Lite when the device is already warm: do not go to max.
        if (game->lite() && !cfg_.unlock_on_lite) t.level = Level::Relaxed;
        // Extreme: every game at max; the safety guard remains the only limit.
        if (cfg_.mode == Mode::Extreme) t.level = Level::Max;
        return t;
    }
    // Apps that are not games are never pushed to the peak: social media, streaming and the
    // whitelist get the relaxed level at most, each scenario as the user chose.
    if (const auto fg = flux::foreground(); fg && fg->screen_awake && !cfg_.is_blacklisted(fg->package)) {
        if (const auto scenario = cfg_.app_scenario(fg->package)) {
            const Level level = std::min(cfg_.level_for(*scenario), Level::Relaxed);
            if (level == Level::Stock) return std::nullopt;
            const std::string_view source = *scenario == Scenario::Other ? "whitelist" : to_string(*scenario);
            return Target{fg->package, fg->pid, level, std::string(source)};
        }
    }
    return std::nullopt;
}

void Daemon::apply(const Target &target, Clock::time_point now) {
    // Switching between levels starts from stock: each level is journaled on its own.
    if (applied_ && *applied_ != target.level && controller_.unlocked()) {
        controller_.restore();
        summary_ = {};
    }
    const bool entering = applied_ != target.level || (state_ != State::Boost && state_ != State::Relaxed);
    applied_ = target.level;

    if (target.level == Level::Max) {
        // Re-applied every poll: vendor daemons (PowerKeeper, Joyose, thermal HAL) push limits back.
        summary_ = controller_.unlock(cfg_);
        if (entering) {
            LOGI("thermal unlocked for {}{}: {} services, {} zones, {} cooling devices, {} caps, {} vendor nodes, "
                 "{} trips raised{}",
                 target.package, cfg_.mode == Mode::Extreme ? " (extreme)" : "", summary_.services, summary_.zones,
                 summary_.cooling, summary_.caps, summary_.vendor, summary_.trips,
                 summary_.overclock ? ", cpufreq boost on" : "");
        }
        transition(State::Boost, now, target.package);
    } else {
        summary_ = {};
        summary_.configs = controller_.relax(cfg_);
        if (entering) {
            if (summary_.configs > 0) {
                LOGI("relaxed thermal for {} ({}): {} vendor configs tuned for {}", target.package, target.source,
                     summary_.configs, to_string(controller_.device().soc));
            } else {
                LOGI("relaxed level for {}: no tunable vendor thermal config on this device, stock thermal kept",
                     target.package);
            }
        }
        transition(State::Relaxed, now,
                   target.source == "warm" ? std::format("{}, {}", target.package, headroom_.reason()) : target.package);
    }
}

void Daemon::publish(const thermal::Temperatures &t) const {
    std::string out;
    const auto kv = [&out](std::string_view k, std::string_view v) { out += std::format("{}={}\n", k, v); };

    kv("state", to_string(state_));
    kv("reason", reason_);
    kv("game", session_ ? session_->package : "");
    kv("since", std::to_string(state_since_));
    kv("updated", std::to_string(std::time(nullptr)));
    kv("flux", flux::describe(flux_.availability));
    kv("flux_version", flux_.version);
    kv("cpu_temp", format_temp(t.cpu));
    kv("gpu_temp", format_temp(t.gpu));
    kv("battery_temp", format_temp(t.battery));
    kv("services", std::to_string(summary_.services));
    kv("zones", std::to_string(summary_.zones));
    kv("cooling", std::to_string(summary_.cooling));
    kv("caps", std::to_string(summary_.caps));
    kv("vendor", std::to_string(summary_.vendor));
    kv("configs", std::to_string(summary_.configs));
    kv("raised_trips", std::to_string(summary_.trips));
    kv("overclock", summary_.overclock ? "1" : "0");
    kv("mode", cfg_.mode == Mode::Extreme ? "extreme" : cfg_.mode == Mode::Off ? "off" : "auto");
    kv("level", applied_ ? to_string(*applied_) : "");
    kv("scenario", session_ ? session_->scenario : "");
    kv("game_level", to_string(cfg_.game_level));
    kv("social_level", to_string(cfg_.social_level));
    kv("media_level", to_string(cfg_.media_level));
    kv("trips", std::to_string(session_ ? session_->trips : 0));
    kv("xiaomi", controller_.is_xiaomi() ? "1" : "0");
    const DeviceProfile &dev = controller_.device();
    kv("device", dev.codename);
    kv("device_profile", dev.in_database ? "verified" : "generic");
    kv("soc", to_string(dev.soc));
    kv("rom", to_string(dev.rom));
    kv("rom_name", dev.rom_name);
    kv("backends", controller_.backend_names());
    kv("pid", std::to_string(getpid()));
    kv("version", HICO_VERSION);
    kv("integrity", std::string(integrity::to_string(integrity_.status)));
    kv("integrity_reason", integrity_.reason);
    kv("integrity_debugger", integrity_signals_.debugger_attached ? "1" : "0");
    kv("integrity_hooks", std::to_string(integrity_signals_.hook_libraries.size()));

    fs::write_atomic(HICO_STATE_FILE, out, 0600);
}

void Daemon::update_module_description() {
    const auto prop = fs::read(HICO_MODULE_PROP, 16 * 1024);
    if (!prop) return;

    std::string status;
    switch (state_) {
    case State::Idle: status = "\xE2\x9D\x84\xEF\xB8\x8F Daily: stock thermal"; break;
    case State::Boost: status = "\xF0\x9F\x94\xA5 Gaming: thermal unlocked (" + reason_ + ")"; break;
    case State::Relaxed: status = "\xF0\x9F\x8C\xA1\xEF\xB8\x8F Relaxed thermal (" + reason_ + ")"; break;
    case State::Safety: status = "\xE2\x9A\xA0\xEF\xB8\x8F Safety guard: " + reason_; break;
    case State::Suspended: status = "\xE2\x9D\x8C Flux Tweaks is required (" + reason_ + ")"; break;
    case State::Disabled:
        status = integrity_failed() ? "\xF0\x9F\x9B\x91 Integrity check failed — thermal stays at stock"
                                    : "\xE2\x8F\xB8\xEF\xB8\x8F Disabled in settings";
        break;
    }

    std::string out;
    for (const auto &line : str::split(*prop, '\n')) {
        if (line.starts_with("description=")) {
            out += "description=[" + status + "] Automatic thermal unlock for games, powered by Flux.\n";
        } else {
            out += line + '\n';
        }
    }
    fs::write_atomic(HICO_MODULE_PROP, out, 0644);
}

void Daemon::shutdown() {
    transition(state_ == State::Disabled ? State::Disabled : State::Idle, Clock::now(), "daemon stopped");
    fs::remove(HICO_STATE_FILE);
}

int Daemon::run() {
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGTERM);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGHUP);
    sigprocmask(SIG_BLOCK, &mask, nullptr);

    const int sfd = signalfd(-1, &mask, SFD_CLOEXEC | SFD_NONBLOCK);
    const int ifd = inotify_init1(IN_CLOEXEC | IN_NONBLOCK);
    const int efd = epoll_create1(EPOLL_CLOEXEC);
    if (sfd < 0 || ifd < 0 || efd < 0) {
        LOGE("cannot create event fds: {}", strerror(errno));
        return 1;
    }

    for (const int fd : {sfd, ifd}) {
        epoll_event ev{};
        ev.events = EPOLLIN;
        ev.data.fd = fd;
        epoll_ctl(efd, EPOLL_CTL_ADD, fd, &ev);
    }

    struct Watch {
        const char *path;
        uint32_t mask;
        int wd = -1;
    };
    // Flux's state files are rewritten in place (IN_CLOSE_WRITE); configs are
    // replaced by rename (IN_MOVED_TO); the Flux module directory reports
    // disable/remove markers (IN_CREATE/IN_DELETE) and uninstallation (IN_DELETE_SELF).
    std::array watches{
        Watch{FLUX_CONFIG_DIR, IN_CLOSE_WRITE | IN_MOVED_TO | IN_DELETE_SELF},
        Watch{FLUX_MODULE_DIR, IN_CREATE | IN_DELETE | IN_MOVED_TO | IN_DELETE_SELF},
        Watch{HICO_CONFIG_DIR, IN_CLOSE_WRITE | IN_MOVED_TO},
    };
    const auto arm_watches = [&] {
        for (auto &w : watches) {
            if (w.wd < 0) w.wd = inotify_add_watch(ifd, fs::real(w.path).c_str(), w.mask);
        }
    };

    arm_watches();
    tick(Clock::now());

    bool running = true;
    while (running) {
        const int timeout = static_cast<int>(next_timeout().count());
        epoll_event events[4];
        const int n = epoll_wait(efd, events, 4, timeout);
        if (n < 0 && errno != EINTR) {
            LOGE("epoll_wait: {}", strerror(errno));
            break;
        }

        for (int i = 0; i < n; ++i) {
            if (events[i].data.fd == sfd) {
                signalfd_siginfo si{};
                while (read(sfd, &si, sizeof(si)) == sizeof(si)) {
                    if (si.ssi_signo == SIGHUP) {
                        LOGI("SIGHUP: reloading configuration");
                        reload_config();
                    } else {
                        LOGI("signal {}: stopping", si.ssi_signo);
                        running = false;
                    }
                }
            } else if (events[i].data.fd == ifd) {
                alignas(inotify_event) char buf[4096];
                ssize_t len;
                while ((len = read(ifd, buf, sizeof(buf))) > 0) {
                    for (char *p = buf; p < buf + len;) {
                        const auto *ev = reinterpret_cast<const inotify_event *>(p);
                        const std::string_view name = ev->len ? std::string_view(ev->name) : std::string_view{};
                        for (auto &w : watches) {
                            if (w.wd != ev->wd) continue;
                            if (ev->mask & (IN_DELETE_SELF | IN_IGNORED)) w.wd = -1;
                            if (std::string_view(w.path) == HICO_CONFIG_DIR && name == "hico.conf") {
                                LOGI("configuration changed, reloading");
                                reload_config();
                            }
                        }
                        p += sizeof(inotify_event) + ev->len;
                    }
                }
            }
        }

        if (!running) break;
        arm_watches(); // Flux may be installed or reinstalled while HiCo runs
        tick(Clock::now());
    }

    shutdown();
    close(efd);
    close(ifd);
    close(sfd);
    return 0;
}

} // namespace hico
