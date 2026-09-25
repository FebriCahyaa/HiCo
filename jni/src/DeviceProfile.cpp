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

std::vector<CodenameCandidate> codename_candidates() {
    std::vector<CodenameCandidate> out;
    const auto add = [&out](std::string value, std::string_view source) {
        if (!is_valid_codename(value)) return;
        for (const auto &c : out) {
            if (c.codename == value) return;
        }
        out.push_back({std::move(value), std::string(source)});
    };
    // A value plus its parts: "lineage_garnet" -> garnet, "garnet_global" -> garnet.
    const auto add_value = [&add](const std::string &raw, std::string_view source) {
        std::string v = lower(str::trim(raw));
        std::replace(v.begin(), v.end(), '-', '_');
        add(v, source);
        const auto parts = str::split(v, '_');
        if (parts.size() > 1) {
            add(parts.back(), source);
            add(parts.front(), source);
        }
    };

    // Device properties, vendor side first: the vendor and odm partitions are
    // the device's own, the system/product ones belong to the (custom) ROM.
    for (const char *prop : {"ro.product.vendor.device", "ro.boot.hwname", "ro.product.odm.device",
                             "ro.product.device", "ro.product.system.device", "ro.product.product.device",
                             "ro.build.product", "ro.product.mod_device", "ro.product.vendor.name",
                             "ro.product.name", "ro.product.board"}) {
        add_value(props::get(prop), prop);
    }
    // Fingerprints: brand/product/device:release/...
    for (const char *prop : {"ro.vendor.build.fingerprint", "ro.odm.build.fingerprint",
                             "ro.bootimage.build.fingerprint", "ro.build.fingerprint"}) {
        const std::string fp = props::get(prop);
        const auto parts = str::split(fp.substr(0, fp.find(':')), '/');
        if (parts.size() >= 3) {
            add_value(parts[2], prop);
            add_value(parts[1], prop);
        }
    }
    return out;
}

std::string device_codename() {
    const auto c = codename_candidates();
    return c.empty() ? std::string{} : c.front().codename;
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
    const auto candidates = codename_candidates();
    DeviceProfile p;
    const DeviceRecord *record = nullptr;
    for (const auto &c : candidates) {
        if ((record = device_db::find(db, c.codename))) {
            p = from_record(*record);
            p.codename_source = c.source;
            break;
        }
    }
    if (!record) {
        if (!candidates.empty()) {
            p.codename = candidates.front().codename;
            p.codename_source = candidates.front().source;
        }
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
