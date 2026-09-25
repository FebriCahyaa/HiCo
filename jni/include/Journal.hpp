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

#include <string>
#include <string_view>
#include <vector>

namespace hico {

/**
 * Undo log of every change HiCo makes to the system.
 *
 * The original value of a node (or the fact that a service was stopped) is
 * appended to HICO_JOURNAL_FILE *before* the change is made, so the stock
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

    [[nodiscard]] bool has_node(std::string_view node) const;
    [[nodiscard]] bool has_service(std::string_view service) const;
    [[nodiscard]] bool empty() const { return entries_.empty(); }
    [[nodiscard]] size_t size() const { return entries_.size(); }

    struct RestoreResult {
        int nodes = 0;
        int services = 0;
        int failed = 0;
    };

    /// Undoes every recorded change, newest first, then clears the journal.
    RestoreResult restore();

private:
    struct Entry {
        enum class Type { Node, Service } type;
        std::string target;
        std::string value;
    };

    void append(const Entry &e);

    std::string path_;
    std::vector<Entry> entries_;
};

} // namespace hico
