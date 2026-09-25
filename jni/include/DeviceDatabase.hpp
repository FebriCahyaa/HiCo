/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <cstdint>
#include <span>
#include <string_view>

/**
 * The device database compiled into hicod.
 *
 * Pipeline (all generated, nothing typed by hand):
 *
 *   firmware dumps ──tools/xiaomi_devices.py──▶ devices/xiaomi/<codename>.prop (repository only)
 *                  ──tools/gen_device_db.py───▶ jni/src/XiaomiDevices.gen.cpp (this table)
 *
 * The .prop files never ship in the module: the facts they hold are compiled
 * in, so the table cannot be edited on a device and needs no parsing at boot.
 * Records hold raw facts from the vendor partition; everything derived from
 * them (SoC vendor, traits, which thermal backends run) is computed in C++ by
 * the functions below, so the rules live in one tested place.
 */
namespace hico {

struct DeviceRecord {
    std::string_view codename; ///< ro.product.vendor.device, lowercase
    std::string_view brand;
    std::string_view model;    ///< market name when the firmware has one
    std::string_view platform; ///< ro.board.platform
    std::string_view android;  ///< system Android release of the dumped firmware
    std::string_view source;   ///< dump URL (firmware branch) the record was read from
    std::span<const std::string_view> services; ///< thermal services declared by vendor init scripts
    std::span<const std::string_view> configs;  ///< thermal configuration files in vendor/etc
};

enum class SocVendor : std::uint8_t { Unknown, Qualcomm, MediaTek, Exynos, Tensor, Unisoc };

[[nodiscard]] std::string_view to_string(SocVendor v);

/// SoC vendor from a board platform / hardware name (msmnile, taro, mt6893, exynos2100, gs201, ums512, ...).
[[nodiscard]] SocVendor soc_from_platform(std::string_view platform);

/// Facts about a device's thermal stack, derived from its record.
enum Trait : std::uint32_t {
    kTraitMiThermald = 1u << 0,     ///< Xiaomi mi_thermald daemon
    kTraitThermalEngine = 1u << 1,  ///< Qualcomm thermal-engine (service or config)
    kTraitMtkThermal = 1u << 2,     ///< MediaTek thermal daemons (thermal_manager, thermal_core, thermalloadalgod)
    kTraitSceneConfigs = 1u << 3,   ///< per-scene thermal configs (thermal-<scene>.conf, e.g. tgame/mgame)
    kTraitNoLimitsScene = 1u << 4,  ///< a "nolimits" thermal scene ships
    kTraitThermalHal = 1u << 5,     ///< a thermal HAL service is declared
};

[[nodiscard]] std::uint32_t traits_of(const DeviceRecord &r);

namespace device_db {

/// Every compiled record, sorted by codename (generated).
[[nodiscard]] std::span<const DeviceRecord> records();

/// Where the compiled table came from (generated): dump group and record count.
[[nodiscard]] std::string_view generated_from();

/// Binary search in a codename-sorted table.
[[nodiscard]] const DeviceRecord *find(std::span<const DeviceRecord> table, std::string_view codename);

} // namespace device_db

} // namespace hico
