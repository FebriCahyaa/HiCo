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

} // namespace hico::flux
