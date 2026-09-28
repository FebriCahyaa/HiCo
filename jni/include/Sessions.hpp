/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <ctime>
#include <optional>
#include <string>
#include <string_view>

namespace hico {

/**
 * One session (a game, or a social / streaming app at the relaxed level), as shown in the WebUI history: how long the game ran
 * unlocked, how hot it got and how often the safety guard stepped in.
 */
struct Session {
    std::string package;
    std::string scenario = "game"; ///< game, social, media or other
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
