/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include "Config.hpp"
#include "DeviceProfile.hpp"
#include "Journal.hpp"
#include "ThermalZones.hpp"

#include <set>
#include <string>
#include <string_view>
#include <vector>

namespace hico {

/**
 * Switches the device between the stock thermal state and the gaming state.
 *
 * Division of labour inside the ecosystem: Flux's profiler already sets CPU
 * governors, frequencies, GPU and scheduler tunables per profile. HiCo only
 * owns the *thermal* layer on top of it:
 *
 *   - userspace thermal daemons (stopped through init, restarted afterwards)
 *   - kernel thermal zone governors (user_space: no throttling, but the
 *     thermal core still handles critical trips, so hardware shutdown
 *     protection is never disabled)
 *   - CPU/GPU cooling devices (released, except those bound to battery zones)
 *   - frequency caps left behind by thermal drivers (CPU max freq, msm_performance,
 *     kgsl thermal power level)
 *   - vendor thermal drivers: Qualcomm msm_thermal, MediaTek EARA, Xiaomi thermal_message
 *
 * Every change is journaled first, so restore() returns the exact stock values.
 */
class ThermalController {
public:
    explicit ThermalController(Journal &journal);
    ThermalController(Journal &journal, std::optional<DeviceProfile> profile);

    struct Summary {
        int services = 0; ///< thermal daemons stopped
        int zones = 0;    ///< zones switched to user_space
        int cooling = 0;  ///< cooling devices released
        int caps = 0;     ///< frequency caps lifted
        int vendor = 0;   ///< vendor nodes changed
    };

    /// Enters the gaming state (idempotent). Called on entry and on every poll,
    /// which also re-asserts anything a vendor daemon changed back meanwhile.
    Summary unlock(const Config &cfg);

    /// Returns to the stock thermal state.
    Journal::RestoreResult restore();

    [[nodiscard]] bool unlocked() const { return !journal_.empty(); }
    [[nodiscard]] bool is_xiaomi() const { return xiaomi_; }
    [[nodiscard]] const std::optional<DeviceProfile> &profile() const { return profile_; }

private:
    void scan();
    bool set_node(std::string_view node, std::string_view value);
    int stop_services(const Config &cfg);
    int switch_zone_governors();
    int release_cooling_devices();
    int lift_cpu_caps(const Config &cfg);
    int lift_gpu_caps();
    int qualcomm_mediatek();
    int xiaomi(const Config &cfg);

    Journal &journal_;
    std::optional<DeviceProfile> profile_;
    bool xiaomi_ = false;
    bool scanned_ = false;
    std::vector<thermal::Zone> zones_;              ///< zones HiCo may switch
    std::vector<thermal::CoolingDevice> cooling_;   ///< cooling devices HiCo may release
    std::set<std::string> warned_; ///< one-time warnings per node / service
};

[[nodiscard]] bool detect_xiaomi();

} // namespace hico
