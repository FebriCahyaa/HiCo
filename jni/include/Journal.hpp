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

namespace hico {

/**
 * Undo log of every change HiCo makes to the system.
 *
 * The original value of a node, a stopped service, a relaxed config bind-mounted
 * over a vendor file, or a daemon restarted to load it, is appended to
 * HICO_JOURNAL_FILE *before* the change is made, so the stock
 * thermal state can be restored even if hicod is killed mid-game:
 * `hicod restore` (run by service.sh at start, uninstall.sh and Flux's
 * uninstall.sh) replays the journal. It lives on tmpfs, so it never outlives
 * the boot it describes.
 */
class Journal {
public:
    explicit Journal(std::string path);

    /// Loads entries left by a previous (crashed) instance.
    void load();

    /// Records the current value of @p node once per session. False if it cannot be read.
    bool record_node(std::string_view node);
    void record_service(std::string_view service);
    /// A file bind-mounted over @p target (vendor thermal config); restore unmounts it.
    void record_mount(std::string_view target);
    /// A service restarted to pick up changed configs; restore restarts it again (after unmounting).
    void record_restart(std::string_view service);

    [[nodiscard]] bool has_node(std::string_view node) const;
    [[nodiscard]] bool has_service(std::string_view service) const;
    [[nodiscard]] bool has_mount(std::string_view target) const;
    [[nodiscard]] bool has_restart(std::string_view service) const;
    [[nodiscard]] bool empty() const { return entries_.empty(); }

    /// Vendor/system thermal config paths HiCo may overlay (no "..", absolute, known partitions).
    [[nodiscard]] static bool is_config_path(std::string_view path);
    [[nodiscard]] size_t size() const { return entries_.size(); }

    struct RestoreResult {
        int nodes = 0;
        int services = 0;
        int mounts = 0;
        int failed = 0;
    };

    /// Undoes every recorded change, newest first, then clears the journal.
    RestoreResult restore();

private:
    struct Entry {
        enum class Type { Node, Service, Mount, Restart } type;
        std::string target;
        std::string value;
    };

    void append(const Entry &e);
    [[nodiscard]] bool has(Entry::Type type, std::string_view target) const;

    std::string path_;
    std::vector<Entry> entries_;
};

} // namespace hico
