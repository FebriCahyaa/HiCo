/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Actuator.hpp"

#include "Fs.hpp"
#include "Log.hpp"

namespace hico {

void Actuator::warn_once(std::string_view node, std::string_view value) {
    if (warned_.insert(std::string(node)).second) LOGW("cannot write '{}' to {}", value, node);
}

bool Actuator::set(std::string_view node, std::string_view value) {
    const auto current = fs::read(node, 1024);
    if (!current) return false; // absent on this device
    if (*current == value) return true;

    if (!journal_.record_node(node)) return false;
    if (fs::write_node(node, value)) return true;
    warn_once(node, value);
    return false;
}

bool Actuator::poke(std::string_view node, std::string_view value) {
    if (!fs::exists(node)) return false;
    if (fs::write_node(node, value)) return true;
    warn_once(node, value);
    return false;
}

} // namespace hico
