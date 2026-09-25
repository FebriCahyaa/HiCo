/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Sessions.hpp"

#include "Fs.hpp"

#include <format>
#include <vector>

namespace hico {

namespace {

std::string json_number(const std::optional<double> &v) {
    return v ? std::format("{:.1f}", *v) : "null";
}

} // namespace

void Session::observe(std::optional<double> cpu, std::optional<double> battery) {
    if (cpu && (!peak_cpu || *cpu > *peak_cpu)) peak_cpu = cpu;
    if (battery && (!peak_battery || *battery > *peak_battery)) peak_battery = battery;
}

std::string Session::to_json() const {
    // Package names are [A-Za-z0-9._] (validated by Flux's game list), so no escaping is needed;
    // anything else is dropped to keep the file valid JSON.
    std::string pkg;
    for (char c : package) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '.' || c == '_') pkg += c;
    }
    return std::format(R"({{"game":"{}","start":{},"duration":{},"boosted":{},"peak_cpu":{},"peak_battery":{},"trips":{}}})",
                       pkg, static_cast<long long>(started), duration_s, boosted_s, json_number(peak_cpu),
                       json_number(peak_battery), trips);
}

namespace sessions {

bool append(std::string_view path, const Session &s) {
    std::vector<std::string> lines = str::split(fs::read(path, 256 * 1024).value_or(""), '\n');
    lines.push_back(s.to_json());
    const size_t first = lines.size() > kMaxEntries ? lines.size() - kMaxEntries : 0;

    std::string out;
    for (size_t i = first; i < lines.size(); ++i) {
        out += lines[i];
        out += '\n';
    }
    return fs::write_atomic(path, out, 0600);
}

} // namespace sessions

} // namespace hico
