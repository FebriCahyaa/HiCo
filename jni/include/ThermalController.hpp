/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include "Actuator.hpp"
#include "Config.hpp"
#include "DeviceProfile.hpp"
#include "Journal.hpp"
#include "ThermalBackend.hpp"
#include "ThermalZones.hpp"

#include <memory>
#include <set>
#include <string>
#include <vector>

namespace hico {

/**
 * Core of the thermal framework: switches the device between the stock
 * thermal state and the gaming state.
 *
 * Division of labour inside the ecosystem: Flux's profiler already sets CPU
 * governors, frequencies, GPU and scheduler tunables per profile. HiCo only
 * owns the *thermal* layer on top of it. The controller handles what every
 * device has:
 *
 *   - userspace thermal daemons (stopped through init, restarted afterwards),
 *     including the exact names the device database declares for this device
 *   - kernel thermal zone governors (user_space: no throttling, but the
 *     thermal core still handles critical trips, so hardware shutdown
 *     protection is never disabled)
 *   - CPU/GPU cooling devices (released, except those bound to battery zones)
 *   - cpufreq caps left behind by thermal drivers
 *
 * and delegates vendor drivers to the backends that apply to this device
 * (ThermalBackend.hpp: Qualcomm, MediaTek, Xiaomi).
 *
 * Every journaled change is recorded first, so restore() returns the exact stock values.
 */
class ThermalController {
public:
    /// Uses the running device's profile (compiled device database + live properties).
    explicit ThermalController(Journal &journal);
    ThermalController(Journal &journal, DeviceProfile device);

    struct Summary {
        int services = 0; ///< thermal daemons stopped
        int zones = 0;    ///< zones switched to user_space
        int cooling = 0;  ///< cooling devices released
        int caps = 0;     ///< frequency caps lifted
        int vendor = 0;   ///< vendor nodes in the gaming state
    };

    /// Enters the gaming state (idempotent). Called on entry and on every poll,
    /// which also re-asserts anything a vendor daemon changed back meanwhile.
    Summary unlock(const Config &cfg);

    /// Returns to the stock thermal state.
    Journal::RestoreResult restore();

    [[nodiscard]] bool unlocked() const { return !journal_.empty(); }
    [[nodiscard]] const DeviceProfile &device() const { return device_; }
    [[nodiscard]] bool is_xiaomi() const { return xiaomi_; }
    /// Names of the backends running on this device, comma-separated.
    [[nodiscard]] std::string backend_names() const;

private:
    void scan();
    int stop_services(const Config &cfg);
    int switch_zone_governors();
    int release_cooling_devices();
    int lift_cpufreq_caps(const Config &cfg);

    Journal &journal_;
    Actuator act_;
    DeviceProfile device_;
    bool xiaomi_ = false;
    std::vector<std::unique_ptr<ThermalBackend>> backends_;
    bool scanned_ = false;
    std::vector<thermal::Zone> zones_;              ///< zones HiCo may switch
    std::vector<thermal::CoolingDevice> cooling_;   ///< cooling devices HiCo may release
    std::set<std::string> warned_services_;
};

} // namespace hico
