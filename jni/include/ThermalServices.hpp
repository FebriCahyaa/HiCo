/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <string>
#include <string_view>
#include <vector>

/**
 * Userspace thermal daemons, controlled through init (ctl.stop / ctl.start).
 *
 * Services are discovered from init.svc.* properties instead of a fixed list,
 * so vendor renames (thermal-engine, vendor.thermal-engine, mi_thermald,
 * thermald, vendor.thermal-symlinks, ...) are all found.
 */
namespace hico::services {

enum class Kind {
    None,    ///< not a thermal service
    Daemon,  ///< thermal policy daemon (thermal-engine, mi_thermald, thermald, ...)
    Hal,     ///< thermal HAL / framework provider: Android's thermal API depends on it
};

[[nodiscard]] Kind classify(std::string_view service);

/// init service names: letters, digits, '_', '-', '.', '@' (validated before any ctl.* write).
[[nodiscard]] bool is_valid_name(std::string_view service);

struct Service {
    std::string name;
    Kind kind = Kind::None;
    std::string state; ///< running, stopped, restarting, ...
};

/// Thermal services found in init.svc.*, plus @p declared (names a device profile
/// took from the vendor's thermal init scripts) when init knows them.
[[nodiscard]] std::vector<Service> thermal_services(const std::vector<std::string> &declared = {});

bool stop(std::string_view service);
bool start(std::string_view service);
[[nodiscard]] bool is_running(std::string_view service);

} // namespace hico::services
