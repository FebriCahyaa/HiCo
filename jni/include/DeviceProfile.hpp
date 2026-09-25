/*
 * Copyright (C) 2026 FebriCahyaa
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace hico {

/**
 * What the stock firmware of one device ships for thermal, taken from its
 * vendor partition (tools/xiaomi_devices.py reads the public firmware dumps
 * and generates devices/xiaomi/<codename>.prop; nothing in it is hand-written).
 *
 * The profile complements runtime detection, it never replaces it: services
 * are still discovered from init.svc.* on the device, and the profile adds
 * the exact service names the vendor declares in its init scripts, so a
 * thermal daemon whose name does not contain "thermal" is not missed.
 */
struct DeviceProfile {
    std::string codename;      ///< ro.product.vendor.device
    std::string brand;
    std::string model;
    std::string platform;      ///< ro.board.platform
    std::string android;       ///< Android release of the dumped firmware
    std::string source;        ///< dump the profile was generated from
    std::vector<std::string> thermal_services; ///< services declared by vendor thermal init scripts
    std::vector<std::string> thermal_configs;  ///< vendor/etc thermal configuration files
    bool has_mi_thermald = false;

    /// Parses a generated profile; nullopt when missing or not for @p codename.
    static std::optional<DeviceProfile> load(std::string_view path, std::string_view codename);

    /// The profile of this device (ro.product.vendor.device, then ro.product.device), if one ships.
    static std::optional<DeviceProfile> detect(std::string_view devices_dir);
};

/// Device codename as the firmware reports it ("" if unknown).
[[nodiscard]] std::string device_codename();

/// Codenames are [a-z0-9_] (validated before building a path from them).
[[nodiscard]] bool is_valid_codename(std::string_view s);

} // namespace hico
