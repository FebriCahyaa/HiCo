/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "FluxLink.hpp"

#include "Fs.hpp"

#include <cstdio>

#include <fcntl.h>
#include <unistd.h>

namespace hico::flux {

namespace {

std::optional<std::string> module_prop(std::string_view key) {
    const auto text = fs::read(FLUX_MODULE_PROP, 16 * 1024);
    if (!text) return std::nullopt;
    for (const auto &line : str::split(*text, '\n')) {
        if (line.size() > key.size() && line.starts_with(key) && line[key.size()] == '=') {
            return str::trim(std::string_view(line).substr(key.size() + 1));
        }
    }
    return std::nullopt;
}

bool fluxd_process_exists() {
    for (const auto &entry : fs::list_dir("/proc")) {
        if (entry.empty() || entry.find_first_not_of("0123456789") != std::string::npos) continue;
        if (fs::read("/proc/" + entry + "/comm", 64) == "fluxd") return true;
    }
    return false;
}

} // namespace

bool daemon_running() {
    const int fd = ::open(fs::real(FLUX_LOCK_FILE).c_str(), O_RDONLY | O_CLOEXEC | O_NOFOLLOW);
    if (fd >= 0) {
        struct flock fl{};
        fl.l_type = F_WRLCK;
        fl.l_whence = SEEK_SET;
        const bool held = ::fcntl(fd, F_GETLK, &fl) == 0 && fl.l_type != F_UNLCK;
        ::close(fd);
        if (held) return true;
    }
    // The lock is authoritative; the process scan covers a fluxd that could
    // not take it (e.g. its config directory was recreated).
    return fluxd_process_exists();
}

Status probe() {
    Status st;
    if (!fs::is_dir(FLUX_MODULE_DIR) || !fs::exists(FLUX_BINARY)) {
        st.availability = Availability::NotInstalled;
        return st;
    }

    st.version = module_prop("version").value_or("");
    st.version_code = str::to_int(module_prop("versionCode").value_or("")).value_or(0);

    if (fs::exists(FLUX_MODULE_DIR "/disable") || fs::exists(FLUX_MODULE_DIR "/remove")) {
        st.availability = Availability::Disabled;
    } else if (st.version_code > 0 && st.version_code < FLUX_MIN_VERSION_CODE) {
        st.availability = Availability::Outdated;
    } else if (!daemon_running()) {
        st.availability = Availability::NotRunning;
    } else {
        st.availability = Availability::Ready;
    }
    return st;
}

std::string_view describe(Availability a) {
    switch (a) {
    case Availability::Ready: return "ready";
    case Availability::NotInstalled: return "not_installed";
    case Availability::Disabled: return "disabled";
    case Availability::Outdated: return "outdated";
    case Availability::NotRunning: return "not_running";
    }
    return "unknown";
}

FluxProfile read_profile() {
    const auto v = fs::read_int(FLUX_PROFILE_FILE);
    if (!v || *v < 0 || *v > static_cast<int>(FluxProfile::Powersave)) return FluxProfile::Unknown;
    return static_cast<FluxProfile>(*v);
}

std::optional<Game> active_game() {
    const FluxProfile profile = read_profile();
    if (profile != FluxProfile::Performance && profile != FluxProfile::PerformanceLite) return std::nullopt;

    const auto info = fs::read(FLUX_GAMEINFO_FILE, 512);
    if (!info) return std::nullopt;

    const auto fields = str::split(*info, ' ');
    if (fields.empty() || fields[0] == "NULL") return std::nullopt;

    Game g;
    g.package = fields[0];
    g.profile = profile;
    if (fields.size() > 1) g.pid = static_cast<pid_t>(str::to_int(fields[1]).value_or(0));
    if (fields.size() > 2) g.uid = static_cast<uid_t>(str::to_int(fields[2]).value_or(0));

    // fluxd writes gameinfo before running the profiler; a game that already
    // died is reported by fluxd's PID tracker shortly after, but do not boost it.
    if (g.pid > 0 && !fs::exists("/proc/" + std::to_string(g.pid))) return std::nullopt;
    return g;
}

std::optional<Foreground> foreground() {
    const auto text = fs::read(FLUX_STATUS_FILE, 16 * 1024);
    if (!text) return std::nullopt;
    Foreground f;
    for (const auto &line : str::split(*text, '\n')) {
        const auto fields = str::split(line, ' ');
        if (fields.size() >= 2 && fields[0] == "focused_app") {
            f.package = fields[1];
            if (fields.size() >= 3) f.pid = static_cast<pid_t>(str::to_int(fields[2]).value_or(0));
        } else if (fields.size() >= 2 && fields[0] == "screen_awake") {
            f.screen_awake = fields[1] == "1";
        }
    }
    if (f.package.empty() || f.package == "NULL") return std::nullopt;
    return f;
}

} // namespace hico::flux
