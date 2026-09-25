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
        if (!tripped_) {
            reason_ = cpu_hot ? std::format("CPU {:.1f}°C ≥ {:.0f}°C", *cpu_c, limits_.cpu_limit)
                              : std::format("battery {:.1f}°C ≥ {:.0f}°C", *battery_c, limits_.battery_limit);
        }
        tripped_ = true;
        tripped_at_ = now; // cooldown restarts while still at the limit
        return true;
    }

    if (!tripped_) return false;

    const bool cpu_cool = !cpu_c || *cpu_c <= limits_.cpu_limit - limits_.cpu_hysteresis;
    const bool battery_cool = !battery_c || *battery_c <= limits_.battery_limit - limits_.battery_hysteresis;
    if (cpu_cool && battery_cool && now - tripped_at_ >= limits_.cooldown) {
        tripped_ = false;
    }
    return tripped_;
}

void SafetyGuard::reset() {
    tripped_ = false;
    reason_.clear();
    tripped_at_ = {};
}

} // namespace hico
