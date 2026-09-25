/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "ThermalBackend.hpp"

#include "Fs.hpp"
#include "Props.hpp"

namespace hico {

bool is_xiaomi_device(const DeviceProfile &device) {
    if (device.has(kTraitMiThermald)) return true;
    if (fs::is_dir("/sys/class/thermal/thermal_message")) return true;
    for (const std::string &brand : {device.brand, props::get("ro.product.manufacturer"), props::get("ro.product.brand"),
                                     props::get("ro.product.vendor.brand")}) {
        if (str::icontains(brand, "xiaomi") || str::icontains(brand, "redmi") || str::icontains(brand, "poco")) return true;
    }
    return false;
}

std::vector<std::unique_ptr<ThermalBackend>> make_backends(const DeviceProfile &device) {
    std::vector<std::unique_ptr<ThermalBackend>> candidates;
    candidates.push_back(make_qualcomm_backend());
    candidates.push_back(make_mediatek_backend());
    candidates.push_back(make_xiaomi_backend()); // last: OEM layer on top of the SoC vendor

    std::vector<std::unique_ptr<ThermalBackend>> out;
    for (auto &b : candidates) {
        if (b->applies(device)) out.push_back(std::move(b));
    }
    return out;
}

} // namespace hico
