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

#include <ctime>
#include <optional>
#include <string>
#include <string_view>

namespace hico {

/**
 * One gaming session, as shown in the WebUI history: how long the game ran
 * unlocked, how hot it got and how often the safety guard stepped in.
 */
struct Session {
    std::string package;
    std::time_t started = 0;   ///< wall clock, seconds
    long long duration_s = 0;  ///< whole session
    long long boosted_s = 0;   ///< time spent with thermal throttling disabled
    std::optional<double> peak_cpu;
    std::optional<double> peak_battery;
    int trips = 0;             ///< safety guard activations

    void observe(std::optional<double> cpu, std::optional<double> battery);
    /// One JSON object per line (the WebUI parses the file as JSON Lines).
    [[nodiscard]] std::string to_json() const;
};

namespace sessions {

inline constexpr size_t kMaxEntries = 100;

/// Appends @p s to @p path, keeping the newest kMaxEntries lines.
bool append(std::string_view path, const Session &s);

} // namespace sessions

} // namespace hico
