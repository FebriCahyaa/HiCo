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

namespace hico {

namespace {

std::vector<std::string> service_list(std::string_view value) {
    std::vector<std::string> out;
    for (auto &name : str::split(value, ',')) {
        if (services::is_valid_name(name)) out.push_back(std::move(name));
    }
    return out;
}

std::string clean(std::string_view v) {
    // Informational fields: printable ASCII only, bounded, no separators that could break the state file.
    std::string out;
    for (const char c : v.substr(0, 128)) {
        if (c >= 0x20 && c < 0x7f && c != '=') out += c;
    }
    return out;
}

} // namespace

bool is_valid_codename(std::string_view s) {
    if (s.empty() || s.size() > 64) return false;
    return std::all_of(s.begin(), s.end(), [](char c) { return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '_'; });
}

std::string device_codename() {
    for (const char *prop : {"ro.product.vendor.device", "ro.product.device"}) {
        std::string v = props::get(prop);
        std::transform(v.begin(), v.end(), v.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        if (is_valid_codename(v)) return v;
    }
    return {};
}

std::optional<DeviceProfile> DeviceProfile::load(std::string_view path, std::string_view codename) {
    const auto text = fs::read(path, 32 * 1024);
    if (!text) return std::nullopt;

    DeviceProfile p;
    for (const auto &line : str::split(*text, '\n')) {
        if (line.empty() || line.front() == '#') continue;
        const auto eq = line.find('=');
        if (eq == std::string::npos) continue;
        const std::string key = str::trim(std::string_view(line).substr(0, eq));
        const std::string_view value = std::string_view(line).substr(eq + 1);

        if (key == "codename") p.codename = str::trim(value);
        else if (key == "brand") p.brand = clean(value);
        else if (key == "model") p.model = clean(value);
        else if (key == "platform") p.platform = clean(value);
        else if (key == "android") p.android = clean(value);
        else if (key == "source") p.source = clean(value);
        else if (key == "thermal_services") p.thermal_services = service_list(value);
        else if (key == "thermal_configs") p.thermal_configs = str::split(clean(value), ',');
        else if (key == "mi_thermald") p.has_mi_thermald = str::trim(value) == "1";
    }
    if (p.codename != codename) return std::nullopt; // file renamed or corrupted
    return p;
}

std::optional<DeviceProfile> DeviceProfile::detect(std::string_view devices_dir) {
    const std::string codename = device_codename();
    if (codename.empty()) return std::nullopt;
    return load(std::string(devices_dir) + "/" + codename + ".prop", codename);
}

} // namespace hico
