/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include "Journal.hpp"

#include <set>
#include <string>
#include <string_view>

namespace hico {

/**
 * The only way the thermal framework writes to the system.
 *
 * set()  journals the original value first, so restore() puts it back exactly.
 * poke() writes without journaling: for values the stock thermal stack
 *        recomputes by itself once it runs again (cooling states, caps).
 */
class Actuator {
public:
    explicit Actuator(Journal &journal) : journal_(journal) {}

    /// Journaled write; true when the node now holds @p value. False when the node is absent.
    bool set(std::string_view node, std::string_view value);
    /// Unjournaled write of an existing node.
    bool poke(std::string_view node, std::string_view value);

    [[nodiscard]] Journal &journal() { return journal_; }
    void reset_warnings() { warned_.clear(); }

private:
    void warn_once(std::string_view node, std::string_view value);

    Journal &journal_;
    std::set<std::string> warned_;
};

} // namespace hico
