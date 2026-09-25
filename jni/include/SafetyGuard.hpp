/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <chrono>
#include <optional>
#include <string>

namespace hico {

/**
 * Decides whether it is safe to keep thermal throttling disabled.
 *
 * Trips when the CPU or battery reaches its limit; releases only after both
 * are below (limit - hysteresis) AND the cooldown has elapsed, so the device
 * does not oscillate between protected and unlocked around the threshold.
 *
 * Pure logic (time is passed in) so it is fully unit-tested.
 */
class SafetyGuard {
public:
    using Clock = std::chrono::steady_clock;

    struct Limits {
        double cpu_limit = 95;
        double cpu_hysteresis = 10;
        double battery_limit = 46;
        double battery_hysteresis = 3;
        std::chrono::seconds cooldown{30};
    };

    void set_limits(const Limits &l) { limits_ = l; }

    /// Feeds one sample. Returns true while protection must stay on.
    bool update(std::optional<double> cpu_c, std::optional<double> battery_c, Clock::time_point now);

    [[nodiscard]] bool tripped() const { return tripped_; }
    /// Why the guard tripped last ("cpu 96.0C >= 95C").
    [[nodiscard]] const std::string &reason() const { return reason_; }

    /// Clears the trip state (new game session).
    void reset();

private:
    Limits limits_;
    bool tripped_ = false;
    std::string reason_;
    Clock::time_point tripped_at_{};
};

} // namespace hico
