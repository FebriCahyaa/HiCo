/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "ThermalConfig.hpp"

#include "Fs.hpp"
#include "ThermalZones.hpp"

#include <algorithm>
#include <format>
#include <limits>

namespace hico::thermalcfg::mithermald {

namespace {

struct Line {
    std::string raw;
    std::string key;
    std::vector<long long> nums; ///< numeric values (trig / clr)
    std::string first;           ///< first value as text (device, sensor, algo_type, reverse)
    std::string sep = "\t";      ///< whitespace between key and values, and between values
};

struct Section {
    std::string name;
    size_t begin = 0; ///< index of the header line
    std::vector<size_t> lines;
    int trig = -1, clr = -1, target = -1;
    std::string algo, device, sensor;
    bool reverse = false;
};

struct Model {
    std::vector<Line> lines;
    std::vector<Section> sections;
    bool trailing_newline = false;
};

bool is_ws(char c) {
    return c == ' ' || c == '\t' || c == '\r';
}

Model parse(std::string_view content) {
    Model m;
    m.trailing_newline = !content.empty() && content.back() == '\n';
    size_t pos = 0;
    while (pos < content.size()) {
        size_t end = content.find('\n', pos);
        if (end == std::string_view::npos) end = content.size();
        Line l;
        l.raw = std::string(content.substr(pos, end - pos));
        pos = end + 1;

        std::string_view t = l.raw;
        while (!t.empty() && is_ws(t.back())) t.remove_suffix(1);
        while (!t.empty() && is_ws(t.front())) t.remove_prefix(1);
        const size_t index = m.lines.size();
        if (t.size() >= 2 && t.front() == '[' && t.back() == ']') {
            Section s;
            s.name = std::string(t.substr(1, t.size() - 2));
            s.begin = index;
            m.sections.push_back(std::move(s));
        } else if (!t.empty() && t.front() != '#') {
            size_t k = 0;
            while (k < t.size() && !is_ws(t[k])) ++k;
            l.key = std::string(t.substr(0, k));
            size_t v = k;
            while (v < t.size() && is_ws(t[v])) ++v;
            if (v > k) l.sep = std::string(t.substr(k, v - k));
            for (auto &word : str::split(std::string(t.substr(v)), ' ')) {
                for (auto &w : str::split(word, '\t')) {
                    if (w.empty()) continue;
                    if (l.first.empty()) l.first = w;
                    if (auto n = str::to_int(w)) l.nums.push_back(*n);
                }
            }
            if (!m.sections.empty()) {
                Section &s = m.sections.back();
                s.lines.push_back(index);
                const int i = static_cast<int>(index);
                if (l.key == "trig") s.trig = i;
                else if (l.key == "clr") s.clr = i;
                else if (l.key == "target") s.target = i;
                else if (l.key == "algo_type") s.algo = l.first;
                else if (l.key == "device") s.device = l.first;
                else if (l.key == "sensor") s.sensor = l.first;
                else if (l.key == "reverse") s.reverse = l.first != "0";
            }
        }
        m.lines.push_back(std::move(l));
    }
    return m;
}

std::string render(const Model &m) {
    std::string out;
    for (size_t i = 0; i < m.lines.size(); ++i) {
        out += m.lines[i].raw;
        if (i + 1 < m.lines.size() || m.trailing_newline) out += '\n';
    }
    return out;
}

std::string format_line(const Line &l, const std::vector<long long> &nums) {
    std::string out = l.raw.substr(0, l.raw.find(l.key)) + l.key;
    for (const auto n : nums) out += l.sep + std::to_string(n);
    return out;
}

/// Devices whose limits cost performance: CPU clusters, GPU, core hotplug, boost.
bool is_performance_device(std::string_view device) {
    if (device.empty()) return false;
    for (const auto &part : str::split(std::string(device), '+')) {
        const bool perf = part.starts_with("cpu") || part.starts_with("hotplug_cpu") || part == "gpu" ||
                          part == "boost_limit";
        if (!perf) return false;
    }
    return true;
}

bool ascending(const std::vector<long long> &v) {
    return std::adjacent_find(v.begin(), v.end(), std::greater_equal<>()) == v.end();
}

std::string ceiling_key(const Section &s) {
    return s.device + "|" + s.sensor;
}

/// Why a section is left alone, or "" when it is eligible.
std::string skip_reason(const Model &m, const Section &s) {
    if (s.algo != "ss" && s.algo != "monitor") return "not a step / monitor algorithm";
    if (s.trig < 0 || s.target < 0) return "no trig / target";
    if (!is_performance_device(s.device)) return std::format("device {} is not a performance limit", s.device);
    if (thermal::classify_zone(s.sensor) == thermal::ZoneKind::Battery) return "battery / charger sensor";
    if (s.reverse) return "descending thresholds";
    const auto &trig = m.lines[static_cast<size_t>(s.trig)].nums;
    if (trig.empty() || !ascending(trig)) return "thresholds not strictly ascending";
    return {};
}

/// Cap (same unit as the file) for a sensor: CPU / GPU sensors up to cap_cpu_c, the rest (skin, virtual) cap_other_c.
long long sensor_cap(const Section &s, const Policy &p, long long unit) {
    const auto kind = thermal::classify_zone(s.sensor);
    const int c = (kind == thermal::ZoneKind::Cpu || kind == thermal::ZoneKind::Gpu) ? p.cap_cpu_c : p.cap_other_c;
    return static_cast<long long>(c) * unit;
}

long long unit_of(const std::vector<long long> &trig) {
    return !trig.empty() && trig.back() >= 1000 ? 1000 : 1; // millidegrees, or plain degrees
}

/// Amount every trig / clr of @p s is raised by (0 = unchanged).
long long shift_for(const Model &m, const Section &s, const Policy &p) {
    const auto &trig = m.lines[static_cast<size_t>(s.trig)].nums;
    const long long unit = unit_of(trig);
    long long limit = sensor_cap(s, p, unit);
    if (const auto it = p.mi_ceilings.find(ceiling_key(s)); it != p.mi_ceilings.end()) {
        limit = std::min(limit, unit == 1000 ? it->second : it->second / 1000);
    }
    return std::max(0LL, std::min(static_cast<long long>(p.margin_c) * unit, limit - trig.back()));
}

} // namespace

bool is_config(std::string_view content) {
    if (content.empty() || content.find('\0') != std::string_view::npos) return false;
    const Model m = parse(content);
    return std::any_of(m.sections.begin(), m.sections.end(),
                       [](const Section &s) { return !s.algo.empty() && s.trig >= 0 && s.target >= 0; });
}

void collect_ceilings(std::string_view content, std::map<std::string, long long> &into) {
    const Model m = parse(content);
    for (const auto &s : m.sections) {
        if (s.trig < 0 || s.reverse || s.device.empty()) continue;
        const auto &trig = m.lines[static_cast<size_t>(s.trig)].nums;
        if (trig.empty()) continue;
        const long long top = unit_of(trig) == 1000 ? trig.back() : trig.back() * 1000;
        auto &slot = into[ceiling_key(s)];
        slot = std::max(slot, top);
    }
}

std::optional<Result> tune(std::string_view content, const Policy &policy) {
    if (!is_config(content)) return std::nullopt;
    Model m = parse(content);
    Result r;
    r.sections = static_cast<int>(m.sections.size());
    for (const auto &s : m.sections) {
        if (const auto why = skip_reason(m, s); !why.empty()) {
            if (is_performance_device(s.device)) r.notes.push_back(std::format("[{}] kept: {}", s.name, why));
            continue;
        }
        const long long shift = shift_for(m, s, policy);
        if (shift == 0) {
            r.notes.push_back(std::format("[{}] kept: already at this device's highest trip", s.name));
            continue;
        }
        for (const int idx : {s.trig, s.clr}) {
            if (idx < 0) continue;
            Line &l = m.lines[static_cast<size_t>(idx)];
            std::vector<long long> nums = l.nums;
            for (auto &n : nums) n += shift;
            l.raw = format_line(l, nums);
            l.nums = std::move(nums);
        }
        ++r.tuned_sections;
    }
    r.text = render(m);
    return r;
}

std::vector<std::string> verify(std::string_view original, std::string_view tuned, const Policy &policy) {
    std::vector<std::string> errors;
    const Model a = parse(original);
    const Model b = parse(tuned);
    if (a.lines.size() != b.lines.size() || a.sections.size() != b.sections.size()) {
        return {"line or section count changed"};
    }
    for (size_t si = 0; si < a.sections.size(); ++si) {
        const Section &sa = a.sections[si];
        const Section &sb = b.sections[si];
        const bool eligible = skip_reason(a, sa).empty();
        long long shift = -1;
        for (const size_t li : sa.lines) {
            const Line &la = a.lines[li];
            const Line &lb = b.lines[li];
            if (la.raw == lb.raw) {
                if (eligible && (la.key == "trig" || la.key == "clr")) shift = shift < 0 ? 0 : shift;
                continue;
            }
            if (!eligible || (la.key != "trig" && la.key != "clr") || la.key != lb.key || la.nums.size() != lb.nums.size()) {
                errors.push_back(std::format("[{}] {} must not change", sa.name, la.key));
                continue;
            }
            for (size_t i = 0; i < la.nums.size(); ++i) {
                const long long d = lb.nums[i] - la.nums[i];
                if (d < 0) errors.push_back(std::format("[{}] {} lowered", sa.name, la.key));
                if (shift < 0) shift = d;
                else if (d != shift) errors.push_back(std::format("[{}] {} not shifted evenly", sa.name, la.key));
            }
        }
        // Caps and ceilings bound what HiCo raises; a section left as it is may already sit above them.
        if (!eligible || sb.trig < 0 || shift <= 0) continue;
        const auto &trig = b.lines[static_cast<size_t>(sb.trig)].nums;
        if (!ascending(trig)) errors.push_back(std::format("[{}] thresholds no longer ascending", sa.name));
        const long long unit = unit_of(a.lines[static_cast<size_t>(sa.trig)].nums);
        if (shift > static_cast<long long>(policy.margin_c) * unit) errors.push_back(std::format("[{}] raised more than the margin", sa.name));
        if (!trig.empty() && trig.back() > sensor_cap(sa, policy, unit)) errors.push_back(std::format("[{}] above the sensor cap", sa.name));
        if (const auto it = policy.mi_ceilings.find(ceiling_key(sa)); it != policy.mi_ceilings.end() && !trig.empty() &&
                                                                       trig.back() * (1000 / unit) > it->second) {
            errors.push_back(std::format("[{}] above the device's own highest trip", sa.name));
        }
    }
    return errors;
}

} // namespace hico::thermalcfg::mithermald
