/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "ThermalOwnership.hpp"

#include "HiCo.hpp"

#include <algorithm>

namespace hico::thermal_owner {

std::string_view to_string(Ownership o) {
    switch (o) {
    case Ownership::Stock: return "stock";
    case Ownership::Hico: return "hico";
    case Ownership::External: return "external";
    case Ownership::Inconsistent: return "inconsistent";
    }
    return "stock";
}

std::string candidate_path(std::string_view target) {
    std::string flat(target.starts_with('/') ? target.substr(1) : target);
    std::replace(flat.begin(), flat.end(), '/', '_');
    return std::string(HICO_RUNTIME_DIR "/thermal/") + flat;
}

bool is_hico_mount(const fs::MountEntry &entry, std::string_view target) {
    const std::string candidate = candidate_path(target);
    // A bind-mounted file reports its path inside the source filesystem: /dev is its own tmpfs,
    // so /dev/hico/thermal/x appears as /hico/thermal/x. Host builds record the full path.
    constexpr std::string_view dev = "/dev";
    if (entry.root == candidate || (candidate.starts_with(dev) && entry.root == std::string_view(candidate).substr(dev.size()))) {
        return true;
    }
    // Same file as the candidate (same device + inode): true whatever spelling the mount table used.
    return fs::same_file(target, candidate);
}

std::string module_id(std::string_view source) {
    for (const std::string_view marker : {std::string_view("/modules/"), std::string_view("/modules_update/")}) {
        const size_t at = source.find(marker);
        if (at == std::string_view::npos) continue;
        const std::string_view rest = source.substr(at + marker.size());
        const std::string_view id = rest.substr(0, rest.find('/'));
        const bool valid = !id.empty() && id.size() <= 64 &&
                           std::all_of(id.begin(), id.end(), [](char c) {
                               return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' ||
                                      c == '-' || c == '.';
                           });
        if (valid && id != "." && id != "..") return std::string(id);
    }
    return {};
}

Mount classify(const Journal &journal, std::string_view target) {
    Mount m;
    m.journaled = journal.has_mount(target);
    const auto entry = fs::mount_at(target);
    m.mounted = entry.has_value();

    if (!entry) {
        // A journaled mount that is not there is a stale record, not a healthy overlay.
        m.ownership = m.journaled ? Ownership::Inconsistent : Ownership::Stock;
    } else if (is_hico_mount(*entry, target)) {
        m.mount_source = candidate_path(target);
        m.ownership = m.journaled ? Ownership::Hico : Ownership::Inconsistent; // HiCo's file, but nothing to restore it by
    } else {
        m.mount_source = entry->root;
        m.mount_owner = module_id(entry->root);
        m.ownership = Ownership::External;
    }
    m.hico_owned = m.ownership == Ownership::Hico;
    m.external_owned = m.ownership == Ownership::External;
    return m;
}

} // namespace hico::thermal_owner
