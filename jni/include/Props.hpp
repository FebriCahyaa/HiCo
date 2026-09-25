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
