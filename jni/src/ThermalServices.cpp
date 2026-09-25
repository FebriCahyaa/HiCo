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

#include "ThermalServices.hpp"

#include "Fs.hpp"
#include "Props.hpp"

#include <algorithm>
#include <array>

namespace hico::services {

namespace {

constexpr std::string_view kSvcPrefix = "init.svc.";

// Not thermal policy daemons even though the name matches: one-shot helpers
// and profile loaders whose "stopped" state is normal.
constexpr std::array<std::string_view, 3> kIgnored{"thermal-symlinks", "vendor.thermal-symlinks", "thermal_loader"};

} // namespace

bool is_valid_name(std::string_view s) {
    if (s.empty() || s.size() > 96) return false;
    return std::all_of(s.begin(), s.end(), [](char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c == '-' ||
               c == '.' || c == '@';
    });
}

Kind classify(std::string_view s) {
    if (!is_valid_name(s)) return Kind::None;
    if (std::find(kIgnored.begin(), kIgnored.end(), s) != kIgnored.end()) return Kind::None;
    if (!str::icontains(s, "thermal")) return Kind::None;

    // The HAL (android.hardware.thermal / vendor.thermal-hal-*) and Android 9-10's
    // thermalserviced back IThermalService, which Flux reads for its thermal tiering.
    if (str::icontains(s, "hal") || str::icontains(s, "android.hardware") || s == "thermalservice") return Kind::Hal;
    return Kind::Daemon;
}

std::vector<Service> thermal_services() {
    std::vector<Service> out;
    props::for_each(kSvcPrefix, [&out](std::string_view name, std::string_view value) {
        const std::string_view svc = name.substr(kSvcPrefix.size());
        const Kind kind = classify(svc);
        if (kind == Kind::None) return;
        out.push_back({std::string(svc), kind, std::string(value)});
    });
    std::sort(out.begin(), out.end(), [](const Service &a, const Service &b) { return a.name < b.name; });
    return out;
}

bool is_running(std::string_view service) {
    const std::string state = props::get(std::string(kSvcPrefix) + std::string(service));
    return state == "running" || state == "restarting";
}

bool stop(std::string_view service) {
    return is_valid_name(service) && props::set("ctl.stop", service);
}

bool start(std::string_view service) {
    return is_valid_name(service) && props::set("ctl.start", service);
}

} // namespace hico::services
