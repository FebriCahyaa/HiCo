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
        int configs = 0;  ///< vendor thermal configs relaxed (relaxed level)
        int trips = 0;    ///< passive trips raised (extreme mode, zones without user_space)
        bool overclock = false; ///< cpufreq boost frequencies enabled
    };

    /// Enters the gaming state (idempotent). Called on entry and on every poll,
    /// which also re-asserts anything a vendor daemon changed back meanwhile.
    Summary unlock(const Config &cfg);

    /**
     * "Relaxed" level: the vendor thermal daemons keep running and protecting
     * the device, but with their plain-text configs tuned for this chipset
     * (ThermalConfig.hpp): each tuned copy is verified, bind-mounted over the
     * vendor file, and the running daemons are restarted to load it.
     * Idempotent. Returns the number of relaxed config files (0 when the
     * device has none that can be tuned, e.g. encrypted configs).
     */
    int relax(const Config &cfg);

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
    int raise_passive_trips();
    void plan_passive_trips();
    bool enable_cpufreq_boost();

    Journal &journal_;
    Actuator act_;
    DeviceProfile device_;
    bool xiaomi_ = false;
    std::vector<std::unique_ptr<ThermalBackend>> backends_;
    bool scanned_ = false;
    std::vector<thermal::Zone> zones_;              ///< zones HiCo may switch
    std::vector<thermal::CoolingDevice> cooling_;   ///< cooling devices HiCo may release
    /// Extreme mode only: CPU/GPU zones whose governor cannot be switched (no
    /// user_space, common on GKI kernels) and the cooling devices bound to them.
    std::vector<thermal::Zone> fixed_zones_;
    std::vector<thermal::CoolingDevice> fixed_cooling_;
    std::vector<std::pair<std::string, long long>> trip_targets_; ///< passive trip node -> raised temp (m°C)
    std::set<std::string> warned_services_;
};

} // namespace hico
