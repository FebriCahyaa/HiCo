/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <cstdint>
#include <utility>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "DeviceDatabase.hpp"

namespace hico {

/// The ROM running on the device (the database describes the stock firmware).
enum class RomFamily {
    HyperOS,
    Miui,
    Lineage, ///< LineageOS and ROMs built on it (crDroid, ...)
    Aosp,    ///< any other AOSP-based ROM
};

[[nodiscard]] std::string_view to_string(RomFamily r);

/// ROM family and display name from system properties.
[[nodiscard]] std::pair<RomFamily, std::string> detect_rom();

/**
 * The thermal facts HiCo knows about the running device.
 *
 * Built from the compiled device database (DeviceDatabase.hpp) when the
 * device's codename is in it, otherwise from live properties only. It
 * complements runtime detection, never replaces it: services are still
 * discovered from init.svc.*, and the database adds the exact names the
 * vendor declares, so a thermal daemon whose name lacks "thermal" is not missed.
 */
struct DeviceProfile {
    std::string codename;
    std::string codename_source; ///< property the codename was read from (detect() only)
    std::string brand;
    std::string model;
    std::string platform;
    std::string android;
    std::string source;        ///< dump the record was generated from ("" when not in the database)
    std::vector<std::string> thermal_services; ///< declared by vendor thermal init scripts
    std::vector<std::string> thermal_configs;  ///< vendor/etc thermal configuration files
    SocVendor soc = SocVendor::Unknown;
    std::uint32_t traits = 0;  ///< Trait bits
    bool in_database = false;  ///< true: built from a compiled record
    RomFamily rom = RomFamily::Aosp; ///< ROM actually running (detect() only)
    std::string rom_name;      ///< e.g. "HyperOS OS2.0", "LineageOS 22.1"

    [[nodiscard]] bool has(Trait t) const { return (traits & t) != 0; }

    [[nodiscard]] static DeviceProfile from_record(const DeviceRecord &r);

    /// Profile of the running device: its database record, or live properties only.
    [[nodiscard]] static DeviceProfile detect(std::span<const DeviceRecord> db = device_db::records());
};

/// Device codename as the firmware reports it ("" if unknown).
[[nodiscard]] std::string device_codename();

/// A possible codename and the property it came from.
struct CodenameCandidate {
    std::string codename;
    std::string source;
};

/**
 * Every codename the firmware hints at, most trusted first. Custom ROMs often
 * rename the product properties ("lineage_garnet", "garnet_global", a Pixel
 * name spoofed for Play Integrity) while the bootloader's ro.boot.hwname and
 * the vendor/odm fingerprints keep the real device name, so detect() tries
 * each of them against the database.
 */
[[nodiscard]] std::vector<CodenameCandidate> codename_candidates();

/// Codenames are [a-z0-9_].
[[nodiscard]] bool is_valid_codename(std::string_view s);

} // namespace hico
