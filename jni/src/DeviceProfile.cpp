/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "DeviceProfile.hpp"

#include "Fs.hpp"
#include "Props.hpp"
#include "ThermalServices.hpp"

#include <algorithm>
#include <cctype>
#include <string>

namespace hico {

namespace {

std::vector<std::string> to_strings(std::span<const std::string_view> in) {
    return {in.begin(), in.end()};
}

std::string lower(std::string v) {
    std::transform(v.begin(), v.end(), v.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return v;
}

} // namespace

bool is_valid_codename(std::string_view s) {
    if (s.empty() || s.size() > 64) return false;
    return std::all_of(s.begin(), s.end(), [](char c) { return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '_'; });
}

std::string device_codename() {
    for (const char *prop : {"ro.product.vendor.device", "ro.product.device"}) {
        const std::string v = lower(props::get(prop));
        if (is_valid_codename(v)) return v;
    }
    return {};
}

DeviceProfile DeviceProfile::from_record(const DeviceRecord &r) {
    DeviceProfile p;
    p.codename = r.codename;
    p.brand = r.brand;
    p.model = r.model;
    p.platform = r.platform;
    p.android = r.android;
    p.source = r.source;
    for (const auto svc : r.services) {
        if (services::is_valid_name(svc)) p.thermal_services.emplace_back(svc);
    }
    p.thermal_configs = to_strings(r.configs);
    p.soc = soc_from_platform(r.platform);
    p.traits = traits_of(r);
    p.in_database = true;
    return p;
}

DeviceProfile DeviceProfile::detect(std::span<const DeviceRecord> db) {
    const std::string codename = device_codename();
    DeviceProfile p;
    if (const DeviceRecord *r = codename.empty() ? nullptr : device_db::find(db, codename)) {
        p = from_record(*r);
    } else {
        p.codename = codename;
        p.brand = props::get("ro.product.brand");
        p.model = props::get("ro.product.model");
        p.platform = props::get("ro.board.platform");
    }
    // A record from an older dump may lack the platform; the live device always knows it.
    if (p.soc == SocVendor::Unknown) {
        for (const char *prop : {"ro.board.platform", "ro.soc.model", "ro.hardware"}) {
            p.soc = soc_from_platform(props::get(prop));
            if (p.soc != SocVendor::Unknown) break;
        }
    }
    return p;
}

} // namespace hico
