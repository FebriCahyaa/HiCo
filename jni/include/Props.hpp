/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <functional>
#include <string>
#include <string_view>

/**
 * Android system properties, used directly through bionic instead of spawning
 * `getprop` / `setprop` / `stop` / `start` shells.
 *
 * Host builds keep properties as files in $HICO_ROOT/__props__/ and emulate
 * init's ctl.start / ctl.stop, so service handling is unit-testable.
 */
namespace hico::props {

[[nodiscard]] std::string get(std::string_view name, std::string_view fallback = "");
bool set(std::string_view name, std::string_view value);

/// Calls @p fn for every property whose name starts with @p prefix.
void for_each(std::string_view prefix, const std::function<void(std::string_view name, std::string_view value)> &fn);

} // namespace hico::props
