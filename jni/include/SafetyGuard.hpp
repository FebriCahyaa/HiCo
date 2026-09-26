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
    bool cpu_tripped_ = false;     ///< the CPU limit was reached during this trip
    bool battery_tripped_ = false; ///< the battery limit was reached during this trip
    std::string reason_;
    Clock::time_point tripped_at_{};
};

/**
 * Headroom for the max level. Max removes every vendor limit and lifts the
 * cpufreq caps, which on a phone that is already hot (a game started right
 * after charging or a heavy app, or a long session) sends the CPU to the safety
 * limit within seconds. Below the limit by a margin the game gets max; closer to
 * it the relaxed level (vendor thermal with the tuned template) until the phone
 * has cooled well below that margin for the cooldown.
 *
 * Pure logic (time is passed in), unit-tested.
 */
class HeadroomGuard {
public:
    using Clock = std::chrono::steady_clock;

    static constexpr double kCpuMargin = 8.0;     ///< max needs the CPU this far below its safety limit
    static constexpr double kCpuRelease = 5.0;    ///< and this much further to get max back
    static constexpr double kBatteryMargin = 2.0;
    static constexpr double kBatteryRelease = 1.5;

    void set_limits(const SafetyGuard::Limits &l) { limits_ = l; }

    /// Feeds one sample. Returns true while there is not enough headroom for max.
    bool update(std::optional<double> cpu_c, std::optional<double> battery_c, Clock::time_point now);

    [[nodiscard]] bool warm() const { return warm_; }
    /// Why max is held back ("CPU 88.6°C, max from 87°C").
    [[nodiscard]] const std::string &reason() const { return reason_; }

private:
    SafetyGuard::Limits limits_;
    bool warm_ = false;
    std::string reason_;
    Clock::time_point warm_at_{};
};

} // namespace hico
