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

#include "Journal.hpp"

#include "Fs.hpp"
#include "Log.hpp"
#include "ThermalServices.hpp"

#include <algorithm>

namespace hico {

namespace {

// One entry per line: "N\t<node>\t<value>" or "S\t<service>". Kernel node
// values are single-line; tabs and newlines are flattened to spaces.
std::string flatten(std::string_view v) {
    std::string out(v);
    std::replace_if(out.begin(), out.end(), [](char c) { return c == '\t' || c == '\n' || c == '\r'; }, ' ');
    return out;
}

} // namespace

Journal::Journal(std::string path) : path_(std::move(path)) {}

void Journal::load() {
    entries_.clear();
    const auto text = fs::read(path_, 256 * 1024);
    if (!text) return;

    for (const auto &line : str::split(*text, '\n')) {
        const auto tab1 = line.find('\t');
        if (tab1 == std::string::npos) continue;
        const std::string_view kind = std::string_view(line).substr(0, tab1);
        const std::string_view rest = std::string_view(line).substr(tab1 + 1);

        if (kind == "N") {
            const auto tab2 = rest.find('\t');
            if (tab2 == std::string_view::npos) continue;
            const std::string node(rest.substr(0, tab2));
            // Defense in depth: only kernel tunables are ever restored.
            if (!fs::is_kernel_node(node)) continue;
            entries_.push_back({Entry::Type::Node, node, std::string(rest.substr(tab2 + 1))});
        } else if (kind == "S" && services::is_valid_name(rest)) {
            entries_.push_back({Entry::Type::Service, std::string(rest), {}});
        }
    }
}

bool Journal::has_node(std::string_view node) const {
    return std::any_of(entries_.begin(), entries_.end(),
                       [node](const Entry &e) { return e.type == Entry::Type::Node && e.target == node; });
}

bool Journal::has_service(std::string_view service) const {
    return std::any_of(entries_.begin(), entries_.end(),
                       [service](const Entry &e) { return e.type == Entry::Type::Service && e.target == service; });
}

bool Journal::record_node(std::string_view node) {
    if (has_node(node)) return true;
    if (!fs::is_kernel_node(node)) return false;
    const auto value = fs::read(node, 1024);
    if (!value) return false;
    append({Entry::Type::Node, std::string(node), flatten(*value)});
    return true;
}

void Journal::record_service(std::string_view service) {
    if (has_service(service) || !services::is_valid_name(service)) return;
    append({Entry::Type::Service, std::string(service), {}});
}

void Journal::append(const Entry &e) {
    entries_.push_back(e);
    const std::string line = e.type == Entry::Type::Node ? "N\t" + e.target + "\t" + e.value : "S\t" + e.target;
    if (!fs::append_line(path_, line, 0600)) LOGW("journal: cannot write {}", path_);
}

Journal::RestoreResult Journal::restore() {
    RestoreResult r;
    for (auto it = entries_.rbegin(); it != entries_.rend(); ++it) {
        if (it->type == Entry::Type::Node) {
            if (fs::write_node(it->target, it->value)) {
                ++r.nodes;
            } else {
                ++r.failed;
                LOGW("restore: cannot write '{}' to {}", it->value, it->target);
            }
        } else {
            if (services::start(it->target)) {
                ++r.services;
            } else {
                ++r.failed;
                LOGW("restore: cannot start service {}", it->target);
            }
        }
    }
    entries_.clear();
    fs::remove(path_);
    return r;
}

} // namespace hico
