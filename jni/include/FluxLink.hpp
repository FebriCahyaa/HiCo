/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include "HiCo.hpp"

#include <optional>
#include <string>
#include <string_view>

#include <sys/types.h>

/**
 * The link to Flux Tweaks, which HiCo requires.
 *
 * fluxd owns game detection. On every profile change it writes
 * current_profile (FluxProfileMode as an integer) and gameinfo
 * ("<package> <pid> <uid>", or "NULL 0 0" outside games); HiCo watches both.
 */
namespace hico::flux {

enum class Availability {
    Ready,       ///< installed, enabled, supported version, fluxd running
    NotInstalled,
    Disabled,    ///< disabled or scheduled for removal in the root manager
    Outdated,    ///< older than FLUX_MIN_VERSION_CODE
    NotRunning,  ///< installed but fluxd is not running (boot in progress or crashed)
};

struct Status {
    Availability availability = Availability::NotInstalled;
    std::string version;   ///< module.prop "version"
    long long version_code = 0;
};

struct Game {
    std::string package;
    pid_t pid = 0;
    uid_t uid = 0;
    FluxProfile profile = FluxProfile::Unknown;

    [[nodiscard]] bool lite() const { return profile == FluxProfile::PerformanceLite; }
};

[[nodiscard]] Status probe();
[[nodiscard]] std::string_view describe(Availability a);

/// True while a process holds fluxd's singleton lock (F_GETLK, no side effects).
[[nodiscard]] bool daemon_running();

[[nodiscard]] FluxProfile read_profile();

/// The game Flux is boosting right now, if any.
[[nodiscard]] std::optional<Game> active_game();

struct Foreground {
    std::string package;
    pid_t pid = 0;
    bool screen_awake = false;
};

/// The app in the foreground according to fluxd's system monitor (FLUX_STATUS_FILE).
[[nodiscard]] std::optional<Foreground> foreground();

} // namespace hico::flux
