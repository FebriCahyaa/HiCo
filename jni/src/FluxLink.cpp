/*
 * Copyright (C) 2026 FebriCahyaa
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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

} // namespace hico::flux
