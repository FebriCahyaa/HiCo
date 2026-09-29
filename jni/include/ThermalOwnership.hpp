/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include "Fs.hpp"
#include "Journal.hpp"

#include <string>
#include <string_view>

namespace hico::thermal_owner {

/**
 * Who controls a vendor thermal config right now.
 *
 * "Is something mounted on it" is not the same question as "did HiCo mount it": Magisk
 * modules bind-mount their own thermal configs over /vendor/etc, and those must never be
 * reported (or counted) as HiCo's work. Ownership therefore needs both the mount table
 * (what is mounted, and from where) and HiCo's journal (what HiCo says it mounted).
 */
enum class Ownership {
    Stock,        ///< nothing mounted, nothing journaled: the ROM's own file
    Hico,         ///< mounted from HiCo's runtime directory, and journaled
    External,     ///< mounted from somewhere else (typically a Magisk/KernelSU module)
    Inconsistent, ///< journal and mount table disagree (journal without mount, HiCo mount without journal)
};

struct Mount {
    Ownership ownership = Ownership::Stock;
    bool mounted = false;        ///< something is mounted on the target
    bool journaled = false;      ///< HiCo's journal records a mount on the target
    bool hico_owned = false;     ///< == (ownership == Hico)
    bool external_owned = false; ///< == (ownership == External)
    std::string mount_source;    ///< file the top-most mount comes from ("" when nothing is mounted)
    std::string mount_owner;     ///< module id when the source is under a modules directory, else ""
};

[[nodiscard]] std::string_view to_string(Ownership o);

/// Where HiCo writes the tuned copy for @p target ("/dev/hico/thermal/vendor_etc_thermal-x.conf").
[[nodiscard]] std::string candidate_path(std::string_view target);

/// True when the top-most mount on @p target comes from HiCo's own candidate file for it.
[[nodiscard]] bool is_hico_mount(const fs::MountEntry &entry, std::string_view target);

/// Module id of a mount source such as "/adb/modules/fast_charging/vendor/etc/x.conf"; "" if it is not one.
[[nodiscard]] std::string module_id(std::string_view source);

/// Classifies one config path from the live mount table and the journal.
[[nodiscard]] Mount classify(const Journal &journal, std::string_view target);

} // namespace hico::thermal_owner
