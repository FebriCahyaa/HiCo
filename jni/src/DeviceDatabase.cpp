/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "DeviceDatabase.hpp"

#include "Fs.hpp"

#include <algorithm>
#include <array>
#include <cctype>

namespace hico {

namespace {

bool starts_with_digits(std::string_view s, std::string_view prefix) {
    if (s.size() <= prefix.size() || !s.starts_with(prefix)) return false;
    return std::isdigit(static_cast<unsigned char>(s[prefix.size()])) != 0;
}

// Qualcomm board platforms use codenames rather than model numbers.
constexpr std::array<std::string_view, 32> kQualcommCodenames{
    "msmnile", "kona",   "lahaina", "taro",     "kalama", "pineapple", "sun",    "canoe",
    "lito",    "atoll",  "holi",    "bengal",   "trinket", "sdmmagpie", "sdmshrike", "yupik",
    "cape",    "ukee",   "parrot",  "crow",     "volcano", "blair",   "khaje",  "monaco",
    "neo",     "anorak", "niobe",   "cliffs",   "ravelin", "seraph",  "tuna",   "qcom",
};

} // namespace

std::string_view to_string(SocVendor v) {
    switch (v) {
    case SocVendor::Unknown: return "unknown";
    case SocVendor::Qualcomm: return "qualcomm";
    case SocVendor::MediaTek: return "mediatek";
    case SocVendor::Exynos: return "exynos";
    case SocVendor::Tensor: return "tensor";
    case SocVendor::Unisoc: return "unisoc";
    }
    return "unknown";
}

SocVendor soc_from_platform(std::string_view raw) {
    std::string p;
    for (const char c : raw) p += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    const std::string_view s = p;
    if (s.empty()) return SocVendor::Unknown;

    if (starts_with_digits(s, "mt") || s.starts_with("mediatek")) return SocVendor::MediaTek;
    if (starts_with_digits(s, "msm") || starts_with_digits(s, "sdm") || starts_with_digits(s, "sm") ||
        starts_with_digits(s, "apq") || starts_with_digits(s, "qcs")) {
        return SocVendor::Qualcomm;
    }
    if (std::find(kQualcommCodenames.begin(), kQualcommCodenames.end(), s) != kQualcommCodenames.end()) {
        return SocVendor::Qualcomm;
    }
    if (s.starts_with("exynos") || s.starts_with("universal") || starts_with_digits(s, "s5e")) return SocVendor::Exynos;
    if (starts_with_digits(s, "gs") || s == "zuma" || s == "zumapro" || s == "laguna") return SocVendor::Tensor;
    // Not "sc<digits>": Qualcomm uses it too (sc7280, sc8280xp).
    if (starts_with_digits(s, "ums") || starts_with_digits(s, "sp") || s.starts_with("unisoc")) {
        return SocVendor::Unisoc;
    }
    return SocVendor::Unknown;
}

std::uint32_t traits_of(const DeviceRecord &r) {
    std::uint32_t t = 0;
    for (const auto svc : r.services) {
        if (svc.find("mi_thermald") != std::string_view::npos) t |= kTraitMiThermald;
        if (svc.find("thermal-engine") != std::string_view::npos) t |= kTraitThermalEngine;
        if (svc == "thermal_manager" || svc == "thermal_core" || svc == "thermalloadalgod") t |= kTraitMtkThermal;
        if (str::icontains(svc, "hal") || str::icontains(svc, "android.hardware")) t |= kTraitThermalHal;
    }
    for (const auto cfg : r.configs) {
        if (cfg == "thermal-engine.conf") t |= kTraitThermalEngine;
        if (cfg.find("game") != std::string_view::npos) t |= kTraitSceneConfigs;
        if (cfg.find("nolimits") != std::string_view::npos) t |= kTraitNoLimitsScene;
    }
    return t;
}

namespace device_db {

const DeviceRecord *find(std::span<const DeviceRecord> table, std::string_view codename) {
    const auto it = std::lower_bound(table.begin(), table.end(), codename,
                                     [](const DeviceRecord &r, std::string_view key) { return r.codename < key; });
    return it != table.end() && it->codename == codename ? &*it : nullptr;
}

} // namespace device_db

} // namespace hico
