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

#include <memory>
#include <string_view>
#include <vector>

namespace hico {

/**
 * One vendor's thermal stack, as a plug-in of the thermal framework.
 *
 * The controller handles what every device has (init thermal services,
 * kernel thermal zones, cooling devices, cpufreq caps); a backend handles
 * the vendor-specific drivers on top. A backend runs only when it applies()
 * to the device, decided from the device database record (SoC vendor,
 * traits) and, for devices not in the database, from what the kernel
 * exposes. So a MediaTek phone never gets Qualcomm writes and vice versa.
 *
 * Adding a vendor: implement this interface in Backend<Vendor>.cpp and list
 * it in make_backends() (ThermalBackend.cpp).
 */
class ThermalBackend {
public:
    struct Result {
        int caps = 0;   ///< frequency / power-level caps lifted
        int vendor = 0; ///< vendor thermal nodes in the gaming state
    };

    virtual ~ThermalBackend() = default;

    [[nodiscard]] virtual std::string_view name() const = 0;
    [[nodiscard]] virtual bool applies(const DeviceProfile &device) const = 0;

    /// Enter (or re-assert) the gaming state. Must be idempotent: it runs on every poll.
    virtual Result unlock(Actuator &act, const Config &cfg) = 0;
};

[[nodiscard]] std::unique_ptr<ThermalBackend> make_qualcomm_backend();
[[nodiscard]] std::unique_ptr<ThermalBackend> make_mediatek_backend();
[[nodiscard]] std::unique_ptr<ThermalBackend> make_xiaomi_backend();

/// The backends that apply to @p device, in the order they run.
[[nodiscard]] std::vector<std::unique_ptr<ThermalBackend>> make_backends(const DeviceProfile &device);

/// Xiaomi / Redmi / POCO, from the database traits, properties or the thermal_message driver.
[[nodiscard]] bool is_xiaomi_device(const DeviceProfile &device);

} // namespace hico
