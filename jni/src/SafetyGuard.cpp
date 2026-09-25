/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "SafetyGuard.hpp"

#include <format>

namespace hico {

bool SafetyGuard::update(std::optional<double> cpu_c, std::optional<double> battery_c, Clock::time_point now) {
    // Never run unprotected blind: without any readable sensor, keep thermal on.
    if (!cpu_c && !battery_c) {
        if (!tripped_) reason_ = "no readable temperature sensor";
        tripped_ = true;
        tripped_at_ = now;
        return true;
    }

    const bool cpu_hot = cpu_c && *cpu_c >= limits_.cpu_limit;
    const bool battery_hot = battery_c && *battery_c >= limits_.battery_limit;

    if (cpu_hot || battery_hot) {
        cpu_tripped_ = cpu_tripped_ || cpu_hot;
        battery_tripped_ = battery_tripped_ || battery_hot;
        if (!tripped_) {
            reason_ = cpu_hot ? std::format("CPU {:.1f}°C ≥ {:.0f}°C", *cpu_c, limits_.cpu_limit)
                              : std::format("battery {:.1f}°C ≥ {:.0f}°C", *battery_c, limits_.battery_limit);
        }
        tripped_ = true;
        tripped_at_ = now; // cooldown restarts while still at the limit
        return true;
    }

    if (!tripped_) return false;

    // Only the sensor that tripped must cool by its hysteresis; the other one only has to stay
    // below its limit (checked above). Requiring both kept a CPU trip locked for a whole game
    // whenever the battery sat within its hysteresis band (45 C against a 46 - 3 C release).
    const bool cpu_cool = !cpu_tripped_ || !cpu_c || *cpu_c <= limits_.cpu_limit - limits_.cpu_hysteresis;
    const bool battery_cool =
        !battery_tripped_ || !battery_c || *battery_c <= limits_.battery_limit - limits_.battery_hysteresis;
    if (cpu_cool && battery_cool && now - tripped_at_ >= limits_.cooldown) {
        tripped_ = cpu_tripped_ = battery_tripped_ = false;
    }
    return tripped_;
}

void SafetyGuard::reset() {
    tripped_ = cpu_tripped_ = battery_tripped_ = false;
    reason_.clear();
    tripped_at_ = {};
}

} // namespace hico
