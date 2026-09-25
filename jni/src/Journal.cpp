/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
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
        } else if (kind == "M" && is_config_path(rest)) {
            entries_.push_back({Entry::Type::Mount, std::string(rest), {}});
        } else if (kind == "R" && services::is_valid_name(rest)) {
            entries_.push_back({Entry::Type::Restart, std::string(rest), {}});
        }
    }
}

bool Journal::is_config_path(std::string_view p) {
    if (p.find("/../") != std::string_view::npos || p.ends_with("/..")) return false;
    return p.starts_with("/vendor/") || p.starts_with("/odm/") || p.starts_with("/system/");
}

bool Journal::has(Entry::Type type, std::string_view target) const {
    return std::any_of(entries_.begin(), entries_.end(),
                       [&](const Entry &e) { return e.type == type && e.target == target; });
}

bool Journal::has_node(std::string_view node) const {
    return has(Entry::Type::Node, node);
}

bool Journal::has_service(std::string_view service) const {
    return has(Entry::Type::Service, service);
}

bool Journal::has_mount(std::string_view target) const {
    return has(Entry::Type::Mount, target);
}

bool Journal::has_restart(std::string_view service) const {
    return has(Entry::Type::Restart, service);
}

void Journal::record_mount(std::string_view target) {
    if (has_mount(target) || !is_config_path(target)) return;
    append({Entry::Type::Mount, std::string(target), {}});
}

void Journal::record_restart(std::string_view service) {
    if (has_restart(service) || !services::is_valid_name(service)) return;
    append({Entry::Type::Restart, std::string(service), {}});
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
    std::string line;
    switch (e.type) {
    case Entry::Type::Node: line = "N\t" + e.target + "\t" + e.value; break;
    case Entry::Type::Service: line = "S\t" + e.target; break;
    case Entry::Type::Mount: line = "M\t" + e.target; break;
    case Entry::Type::Restart: line = "R\t" + e.target; break;
    }
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
        } else if (it->type == Entry::Type::Service) {
            if (services::start(it->target)) {
                ++r.services;
            } else {
                ++r.failed;
                LOGW("restore: cannot start service {}", it->target);
            }
        } else if (it->type == Entry::Type::Mount) {
            if (fs::unmount(it->target)) {
                ++r.mounts;
            } else {
                ++r.failed;
                LOGW("restore: cannot unmount {}", it->target);
            }
        } else if (services::is_running(it->target)) {
            // Recorded before the mounts, so it runs after they are gone: the daemon reloads stock configs.
            if (!services::restart(it->target)) {
                ++r.failed;
                LOGW("restore: cannot restart service {}", it->target);
            }
        }
    }
    entries_.clear();
    fs::remove(path_);
    return r;
}

} // namespace hico
