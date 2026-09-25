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
#include <tuple>

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

std::string_view to_string(RomFamily r) {
    switch (r) {
    case RomFamily::HyperOS: return "hyperos";
    case RomFamily::Miui: return "miui";
    case RomFamily::Lineage: return "lineage";
    case RomFamily::Aosp: return "aosp";
    }
    return "aosp";
}

namespace {

// Custom ROMs record their name in a version property of their own. Unknown
// properties simply do not exist on a device, so a wrong guess costs nothing.
struct KnownRom {
    const char *prop;
    const char *name;
};
constexpr KnownRom kKnownRoms[] = {
    {"ro.crdroid.build.version", "crDroid"},    {"ro.evolution.version", "Evolution X"},
    {"org.evolution.version", "Evolution X"},   {"org.pixelos.version", "PixelOS"},
    {"ro.pixelos.version", "PixelOS"},          {"org.pixelexperience.version", "Pixel Experience"},
    {"ro.rising.version", "RisingOS"},          {"ro.risingos.version", "RisingOS"},
    {"ro.derpfest.version", "DerpFest"},        {"ro.matrixx.version", "Matrixx"},
    {"ro.infinity.version", "Infinity X"},      {"ro.afterlife.version", "AfterlifeOS"},
    {"ro.alpha.build.version", "AlphaDroid"},   {"ro.voltage.version", "VoltageOS"},
    {"ro.aospa.version", "Paranoid Android"},   {"ro.potato.version", "POSP"},
    {"ro.havoc.version", "Havoc-OS"},           {"ro.arrow.version", "ArrowOS"},
    {"ro.superior.version", "SuperiorOS"},      {"ro.yaap.version", "YAAP"},
    {"ro.cherish.version", "CherishOS"},        {"ro.statix.version", "StatiXOS"},
    {"ro.axion.version", "AxionOS"},            {"ro.elixir.version", "Project Elixir"},
    {"ro.bliss.version", "BlissROM"},           {"ro.lunaris.version", "LunarisAOSP"},
};

// Namespaces of AOSP / vendor properties that are not a ROM name.
constexpr std::string_view kNotRom[] = {
    "build", "product", "system", "vendor", "odm", "bootimage", "boot", "system_ext", "apex", "vndk",
    "adb", "carrier", "config", "kernel", "hardware", "oem", "com", "lineage", "miui", "mi", "sf",
    "opengles", "gsm", "telephony", "hwui", "crypto", "treble", "virtual_ab", "surface_flinger",
};

bool contains_ci(std::string_view haystack, std::string_view needle) {
    return str::icontains(haystack, needle);
}

/// Fallback for ROMs not in the table: a "ro.<name>.version" / "org.<name>.version" key in the
/// system / product / system_ext build.prop. Returns {display name, version}.
std::pair<std::string, std::string> rom_from_build_props() {
    for (const char *file : {"/system/build.prop", "/system_ext/etc/build.prop", "/product/etc/build.prop"}) {
        const auto text = fs::read(file, 256 * 1024);
        if (!text) continue;
        for (const auto &line : str::split(*text, '\n')) {
            const auto eq = line.find('=');
            if (eq == std::string::npos) continue;
            const std::string key = str::trim(line.substr(0, eq));
            const std::string value = str::trim(line.substr(eq + 1));
            if (value.empty() || !(key.starts_with("ro.") || key.starts_with("org."))) continue;
            const auto parts = str::split(key, '.');
            const bool version_key = (parts.size() == 3 && parts[2] == "version") ||
                                     (parts.size() == 4 && parts[2] == "build" && parts[3] == "version");
            if (!version_key) continue;
            const std::string &ns = parts[1];
            if (ns.size() < 3 || ns.size() > 24 || !std::all_of(ns.begin(), ns.end(), [](char c) { return std::isalnum(static_cast<unsigned char>(c)); }))
                continue;
            if (std::find(std::begin(kNotRom), std::end(kNotRom), ns) != std::end(kNotRom)) continue;
            std::string name = ns;
            name[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(name[0])));
            return {name, value};
        }
    }
    return {};
}

/// HyperOS keeps ro.miui.ui.version.name at V816 and up; MIUI never went past V140.
bool is_hyperos_ui_code(std::string_view v) {
    if (v.size() < 2 || (v[0] != 'V' && v[0] != 'v')) return false;
    const auto n = str::to_int(v.substr(1));
    return n && *n >= 816;
}

} // namespace

std::pair<RomFamily, std::string> detect_rom() {
    // Xiaomi: HyperOS first (its own props, or the MIUI UI code it still reports), then MIUI.
    if (const std::string v = props::get("ro.mi.os.version.name"); !v.empty()) return {RomFamily::HyperOS, "HyperOS " + v};
    const std::string miui = props::get("ro.miui.ui.version.name");
    if (const std::string v = props::get("ro.mi.os.version.incremental"); !v.empty()) return {RomFamily::HyperOS, "HyperOS " + v};
    if (is_hyperos_ui_code(miui)) {
        const std::string inc = props::get("ro.build.version.incremental");
        return {RomFamily::HyperOS, inc.starts_with("OS") ? "HyperOS " + inc : "HyperOS (" + miui + ")"};
    }
    if (!miui.empty()) return {RomFamily::Miui, "MIUI " + miui};

    // Custom ROMs: name from the ROM's own property, version from ro.modversion when present.
    const bool lineage_based = !props::get("ro.lineage.version").empty();
    const RomFamily family = lineage_based ? RomFamily::Lineage : RomFamily::Aosp;
    const std::string mod = props::get("ro.modversion");
    const auto named = [&](const std::string &name, const std::string &version) {
        const std::string &v = mod.empty() ? version : mod;
        return std::pair{family, contains_ci(v, name) ? v : name + " " + v};
    };
    for (const auto &rom : kKnownRoms) {
        if (const std::string v = props::get(rom.prop); !v.empty()) return named(rom.name, v);
    }
    if (lineage_based) return {RomFamily::Lineage, mod.empty() ? "LineageOS " + props::get("ro.lineage.version") : mod};
    if (const auto [name, version] = rom_from_build_props(); !name.empty()) return named(name, version);

    std::string name = mod;
    if (name.empty()) name = props::get("ro.build.display.id");
    return {RomFamily::Aosp, name.empty() ? "AOSP" : name};
}

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
    std::tie(p.rom, p.rom_name) = detect_rom();
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
