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

/// Flux liveness / game re-check period outside games (inotify covers the fast path).
constexpr std::chrono::seconds kIdleInterval{30};
/// Re-check period while fluxd is installed but not running yet (boot order between modules is not fixed).
constexpr std::chrono::seconds kFluxStartingInterval{5};

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
    guard_.set_limits({
        .cpu_limit = static_cast<double>(cfg_.safety_cpu_temp),
        .cpu_hysteresis = static_cast<double>(cfg_.safety_cpu_hysteresis),
        .battery_limit = static_cast<double>(cfg_.safety_battery_temp),
        .battery_hysteresis = static_cast<double>(cfg_.safety_battery_hysteresis),
        .cooldown = std::chrono::seconds(cfg_.safety_cooldown),
    });
}

void Daemon::recover() {
    journal_.load();
    if (journal_.empty()) return;
    const auto r = controller_.restore();
    LOGW("recovered stock thermal left by a previous instance: {} nodes, {} services, {} failed", r.nodes, r.services,
         r.failed);
}

std::chrono::milliseconds Daemon::next_timeout() const {
    if (state_ == State::Boost || state_ == State::Safety) return std::chrono::seconds(cfg_.poll_interval);
    if (state_ == State::Suspended && flux_.availability == flux::Availability::NotRunning) return kFluxStartingInterval;
    return kIdleInterval;
}

void Daemon::begin_session(const flux::Game &game, Clock::time_point now) {
    session_ = Session{};
    session_->package = game.package;
    session_->started = std::time(nullptr);
    session_start_ = now;
    guard_.reset();
    LOGI("game session started: {} (pid {}, flux profile {})", game.package, game.pid,
         game.lite() ? "performance_lite" : "performance");
}

void Daemon::end_session(Clock::time_point now) {
    if (!session_) return;
    session_->duration_s = std::chrono::duration_cast<std::chrono::seconds>(now - session_start_).count();
    LOGI("game session ended: {} after {}s ({}s boosted, peak CPU {} C, peak battery {} C, {} safety trips)",
         session_->package, session_->duration_s, session_->boosted_s, format_temp(session_->peak_cpu),
         format_temp(session_->peak_battery), session_->trips);
    // Sessions shorter than a few seconds are focus blips, not play.
    if (session_->duration_s >= 5 && !sessions::append(HICO_SESSIONS_FILE, *session_)) {
        LOGW("cannot write {}", HICO_SESSIONS_FILE);
    }
    session_.reset();
}

void Daemon::transition(State next, Clock::time_point now, std::string reason) {
    if (next != State::Boost && controller_.unlocked()) {
        const auto r = controller_.restore();
        LOGI("thermal restored: {} nodes, {} services{}", r.nodes, r.services,
             r.failed ? std::format(", {} failed", r.failed) : "");
        summary_ = {};
    }

    if (next != State::Boost && next != State::Safety) {
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

    std::optional<flux::Game> game = flux::active_game();
    if (game && game->lite() && !cfg_.unlock_on_lite) game.reset();
    if (game && cfg_.is_excluded(game->package)) game.reset();

    if (!game) {
        if (state_ == State::Boost || state_ == State::Safety) {
            // Hold briefly: Flux can drop and re-apply the profile around a quick app switch.
            if (!exit_deadline_) exit_deadline_ = now + std::chrono::seconds(cfg_.exit_delay);
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

    if (!session_ || session_->package != game->package) {
        end_session(now);
        begin_session(*game, now);
    }
    if (zones_.empty()) zones_ = thermal::zones();

    const auto temps = thermal::read_temperatures(zones_);
    session_->observe(temps.cpu, temps.battery);
    if (state_ == State::Boost) {
        session_->boosted_s += std::chrono::duration_cast<std::chrono::seconds>(elapsed).count();
    }

    if (guard_.update(temps.cpu, temps.battery, now)) {
        if (state_ != State::Safety) {
            ++session_->trips;
            LOGW("safety guard: {}, restoring thermal protection for {}", guard_.reason(), game->package);
            if (cfg_.notify) notify(std::format("Thermal protection restored: {}", guard_.reason()));
        }
        transition(State::Safety, now, guard_.reason());
    } else {
        const bool entering = state_ != State::Boost;
        // Re-applied every poll: vendor daemons (PowerKeeper, Joyose, thermal HAL) push limits back.
        summary_ = controller_.unlock(cfg_);
        if (entering) {
            LOGI("thermal unlocked for {}: {} services, {} zones, {} cooling devices, {} caps, {} vendor nodes",
                 game->package, summary_.services, summary_.zones, summary_.cooling, summary_.caps, summary_.vendor);
        }
        transition(State::Boost, now, game->package);
    }
    publish(temps);
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
    kv("trips", std::to_string(session_ ? session_->trips : 0));
    kv("xiaomi", controller_.is_xiaomi() ? "1" : "0");
    kv("device", device_codename());
    kv("device_profile", controller_.profile() ? "verified" : "generic");
    kv("pid", std::to_string(getpid()));
    kv("version", HICO_VERSION);

    fs::write_atomic(HICO_STATE_FILE, out, 0600);
}

void Daemon::update_module_description() {
    const auto prop = fs::read(HICO_MODULE_PROP, 16 * 1024);
    if (!prop) return;

    std::string status;
    switch (state_) {
    case State::Idle: status = "\xE2\x9D\x84\xEF\xB8\x8F Daily: stock thermal"; break;
    case State::Boost: status = "\xF0\x9F\x94\xA5 Gaming: thermal unlocked (" + reason_ + ")"; break;
    case State::Safety: status = "\xE2\x9A\xA0\xEF\xB8\x8F Safety guard: " + reason_; break;
    case State::Suspended: status = "\xE2\x9D\x8C Flux Tweaks is required (" + reason_ + ")"; break;
    case State::Disabled: status = "\xE2\x8F\xB8\xEF\xB8\x8F Disabled in settings"; break;
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
