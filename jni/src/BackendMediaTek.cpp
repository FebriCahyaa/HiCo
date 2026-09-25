/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "ThermalBackend.hpp"

#include "Fs.hpp"

namespace hico {

namespace {

constexpr std::string_view kEara = "/sys/kernel/eara_thermal/enable";

/// MediaTek: EARA thermal (game-aware thermal throttling). The thermal daemons
/// (thermal_manager, thermal_core, thermalloadalgod) are handled as services.
class MediaTekBackend final : public ThermalBackend {
public:
    std::string_view name() const override { return "mediatek"; }

    bool applies(const DeviceProfile &d) const override {
        if (d.soc == SocVendor::MediaTek || d.has(kTraitMtkThermal)) return true;
        return d.soc == SocVendor::Unknown && fs::exists(kEara);
    }

    Result unlock(Actuator &act, const Config &cfg) override {
        Result r;
        if (cfg.vendor_tweaks && act.set(kEara, "0")) ++r.vendor;
        return r;
    }
};

} // namespace

std::unique_ptr<ThermalBackend> make_mediatek_backend() {
    return std::make_unique<MediaTekBackend>();
}

} // namespace hico
