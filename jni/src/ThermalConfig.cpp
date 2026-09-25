/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "ThermalConfig.hpp"

#include "Fs.hpp"
#include "MiCrypt.hpp"
#include "ThermalZones.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <format>
#include <map>

namespace hico::thermalcfg {

namespace {

// ── Layout-preserving model ─────────────────────────────────────────────────

struct Line {
    std::string raw;
    int section = -1;
    bool header = false;
    std::string key;
    std::vector<std::string> values;
    std::string lead;     ///< indentation
    std::string sep;      ///< whitespace between key and first value
    std::string valsep;   ///< whitespace between values
    std::string tail;     ///< whitespace + comment after the values
};

struct Section {
    std::string name;
    std::map<std::string, int> keys; ///< key -> line index (first occurrence)
};

struct Model {
    std::vector<Line> lines;
    std::vector<Section> sections;
    bool trailing_newline = false;
};

bool is_space(char c) {
    return c == ' ' || c == '\t' || c == '\r';
}

Model parse(std::string_view content) {
    Model m;
    m.trailing_newline = !content.empty() && content.back() == '\n';
    size_t start = 0;
    while (start < content.size()) {
        size_t end = content.find('\n', start);
        if (end == std::string_view::npos) end = content.size();
        const std::string_view raw = content.substr(start, end - start);
        start = end + 1;

        Line l;
        l.raw = raw;
        l.section = static_cast<int>(m.sections.size()) - 1;

        const size_t hash = raw.find('#');
        std::string_view body = raw.substr(0, hash);
        size_t body_end = body.size();
        while (body_end > 0 && is_space(body[body_end - 1])) --body_end;
        l.tail = std::string(raw.substr(body_end));
        body = body.substr(0, body_end);

        size_t i = 0;
        while (i < body.size() && is_space(body[i])) ++i;
        l.lead = std::string(body.substr(0, i));
        const std::string_view text = body.substr(i);

        if (text.size() >= 2 && text.front() == '[' && text.back() == ']') {
            l.header = true;
            Section s;
            s.name = std::string(text.substr(1, text.size() - 2));
            m.sections.push_back(std::move(s));
            l.section = static_cast<int>(m.sections.size()) - 1;
        } else if (!text.empty()) {
            size_t k = 0;
            while (k < text.size() && !is_space(text[k])) ++k;
            l.key = std::string(text.substr(0, k));
            size_t v = k;
            while (v < text.size() && is_space(text[v])) ++v;
            l.sep = std::string(text.substr(k, v - k));
            l.valsep = " ";
            bool first_gap = true;
            size_t p = v;
            while (p < text.size()) {
                size_t q = p;
                while (q < text.size() && !is_space(text[q])) ++q;
                l.values.emplace_back(text.substr(p, q - p));
                size_t r = q;
                while (r < text.size() && is_space(text[r])) ++r;
                if (first_gap && r > q) {
                    l.valsep = std::string(text.substr(q, r - q));
                    first_gap = false;
                }
                p = r;
            }
            if (l.section >= 0) m.sections[static_cast<size_t>(l.section)].keys.emplace(l.key, static_cast<int>(m.lines.size()));
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

void set_values(Line &l, const std::vector<long long> &values) {
    std::string joined;
    for (size_t i = 0; i < values.size(); ++i) {
        if (i) joined += l.valsep;
        joined += std::to_string(values[i]);
    }
    l.values.clear();
    for (const long long v : values) l.values.push_back(std::to_string(v));
    l.raw = l.lead + l.key + l.sep + joined + l.tail;
}

// ── Section facts ───────────────────────────────────────────────────────────

const Line *find(const Model &m, const Section &s, std::string_view key) {
    const auto it = s.keys.find(std::string(key));
    return it == s.keys.end() ? nullptr : &m.lines[static_cast<size_t>(it->second)];
}

std::optional<std::vector<long long>> numbers(const Line *l) {
    if (!l || l->values.empty()) return std::nullopt;
    std::vector<long long> out;
    for (const auto &v : l->values) {
        const auto n = str::to_int(v);
        if (!n) return std::nullopt;
        out.push_back(*n);
    }
    return out;
}

/// thermal-engine uses millidegrees; old configs use degrees.
long long unit_of(const std::vector<long long> &v) {
    return std::any_of(v.begin(), v.end(), [](long long x) { return x >= 1000 || x <= -1000; }) ? 1000 : 1;
}

std::string sensor_of(const Model &m, const Section &s) {
    const Line *l = find(m, s, "sensor");
    return l && !l->values.empty() ? l->values.front() : std::string{};
}

bool is_shutdown(const Model &m, const Section &s) {
    for (const char *key : {"actions", "action"}) {
        if (const Line *l = find(m, s, key)) {
            for (const auto &v : l->values) {
                if (str::icontains(v, "shutdown")) return true;
            }
        }
    }
    return false;
}

/// Why a section may not be tuned ("" = eligible).
std::string ineligible(const Model &m, const Section &s) {
    if (!find(m, s, "thresholds") && !find(m, s, "set_point")) return "no trip points";
    if (is_shutdown(m, s)) return "shutdown section";
    if (find(m, s, "descending")) return "descending monitor";
    const Line *algo = find(m, s, "algo_type");
    const std::string a = algo && !algo->values.empty() ? algo->values.front() : "";
    if (a != "monitor" && a != "ss" && a != "pid") return std::format("algo_type '{}'", a);
    const std::string sensor = sensor_of(m, s);
    if (sensor.empty()) return "no sensor";
    if (thermal::classify_zone(sensor) == thermal::ZoneKind::Battery) return "battery / power sensor";
    return {};
}

/// Lowest shutdown threshold (same unit as the file) for each sensor.
std::map<std::string, long long> shutdown_by_sensor(const Model &m) {
    std::map<std::string, long long> out;
    for (const auto &s : m.sections) {
        if (!is_shutdown(m, s)) continue;
        const auto t = numbers(find(m, s, "thresholds"));
        if (!t || t->empty()) continue;
        const long long lowest = *std::min_element(t->begin(), t->end()) * (unit_of(*t) == 1 ? 1000 : 1);
        const std::string sensor = sensor_of(m, s);
        if (!out.contains(sensor) || lowest < out[sensor]) out[sensor] = lowest;
    }
    return out; // millidegrees
}

long long cap_for(const std::string &sensor, const Policy &p, const std::map<std::string, long long> &shutdowns) {
    const auto kind = thermal::classify_zone(sensor);
    long long cap = (kind == thermal::ZoneKind::Cpu || kind == thermal::ZoneKind::Gpu ? p.cap_cpu_c : p.cap_other_c) * 1000LL;
    if (const auto it = shutdowns.find(sensor); it != shutdowns.end()) {
        cap = std::min(cap, it->second - p.shutdown_guard_c * 1000LL);
    }
    return cap; // millidegrees
}

bool strictly_ascending(const std::vector<long long> &v) {
    return std::adjacent_find(v.begin(), v.end(), [](long long a, long long b) { return a >= b; }) == v.end();
}

} // namespace

Policy policy_for(SocVendor soc, std::string_view platform, int margin_override) {
    Policy p;
    std::string plat;
    for (const char c : platform) plat += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));

    // Defaults chosen conservatively by HiCo (not vendor data): larger thermal
    // design headroom on flagship SoCs, the least on unknown hardware.
    static constexpr std::array<std::string_view, 11> kQcomFlagship{
        "msmnile", "kona", "lahaina", "taro", "kalama", "pineapple", "sun", "canoe", "cliffs", "sdm845", "sdm855"};
    switch (soc) {
    case SocVendor::Qualcomm:
        if (std::find(kQcomFlagship.begin(), kQcomFlagship.end(), plat) != kQcomFlagship.end() ||
            (plat.starts_with("sm8") && plat.size() > 3)) {
            p.margin_c = 6;
            p.name = "qualcomm-flagship";
        } else {
            p.margin_c = 5;
            p.name = "qualcomm";
        }
        break;
    case SocVendor::MediaTek:
        if (plat.starts_with("mt68") || plat.starts_with("mt69")) {
            p.margin_c = 5;
            p.name = "mediatek-dimensity";
        } else {
            p.margin_c = 4;
            p.name = "mediatek";
        }
        break;
    case SocVendor::Exynos: p.name = "exynos"; break;
    case SocVendor::Tensor: p.name = "tensor"; break;
    case SocVendor::Unisoc: p.name = "unisoc"; break;
    case SocVendor::Unknown: p.name = "generic"; break;
    }
    if (margin_override >= 1 && margin_override <= 10) p.margin_c = margin_override;
    return p;
}

std::vector<std::string> device_config_files() {
    static constexpr std::array<std::string_view, 4> kDirs{"/vendor/etc", "/odm/etc", "/system/vendor/etc", "/system/etc"};
    std::vector<std::string> out;
    std::vector<std::string> seen;
    for (const auto dir : kDirs) {
        for (const auto &name : fs::list_dir(dir)) {
            const bool engine = name.starts_with("thermal") && name.ends_with(".conf");
            const bool hal = name.starts_with("thermal_info_config") && name.ends_with(".json");
            if (!engine && !hal) continue;
            if (std::find(seen.begin(), seen.end(), name) != seen.end()) continue; // first partition wins
            seen.push_back(name);
            out.push_back(std::string(dir) + "/" + name);
        }
    }
    return out;
}

static bool is_engine_text(std::string_view content) {
    if (content.empty()) return false;
    const std::string_view sample = content.substr(0, 4096);
    const auto binary = std::count_if(sample.begin(), sample.end(), [](char c) {
        const auto u = static_cast<unsigned char>(c);
        return u < 9 || (u > 13 && u < 32) || u == 127;
    });
    if (static_cast<size_t>(binary) * 20 > sample.size()) return false; // encrypted / binary
    const Model m = parse(content);
    return std::any_of(m.sections.begin(), m.sections.end(),
                       [&m](const Section &s) { return find(m, s, "thresholds") || find(m, s, "set_point"); });
}

static std::optional<Result> tune_engine(std::string_view content, const Policy &policy) {
    if (!is_engine_text(content)) return std::nullopt;

    Model m = parse(content);
    Result r;
    r.sections = static_cast<int>(m.sections.size());
    const auto shutdowns = shutdown_by_sensor(m);

    for (const auto &s : m.sections) {
        if (const std::string why = ineligible(m, s); !why.empty()) {
            if (why != "no trip points") r.notes.push_back(std::format("[{}] kept: {}", s.name, why));
            continue;
        }
        const long long cap = cap_for(sensor_of(m, s), policy, shutdowns);
        bool changed = false;
        bool rejected = false;

        // thresholds / thresholds_clr and set_point / set_point_clr move together.
        for (const auto &[trip_key, clr_key] : {std::pair{"thresholds", "thresholds_clr"}, std::pair{"set_point", "set_point_clr"}}) {
            const Line *trip_line = find(m, s, trip_key);
            if (!trip_line) continue;
            const auto trips = numbers(trip_line);
            const Line *clr_line = find(m, s, clr_key);
            const auto clrs = clr_line ? numbers(clr_line) : std::optional<std::vector<long long>>{};
            if (!trips || (clr_line && (!clrs || clrs->size() != trips->size()))) {
                r.notes.push_back(std::format("[{}] kept: unreadable {}", s.name, trip_key));
                rejected = true;
                continue;
            }
            const long long unit = unit_of(*trips);
            const long long milli = unit == 1000 ? 1 : 1000; // file unit -> millidegrees
            std::vector<long long> new_trips = *trips;
            for (auto &t : new_trips) {
                const long long raised = t + policy.margin_c * unit;
                const long long capped = std::min(raised * milli, cap) / milli;
                t = std::max(t, capped); // never lower a trip
            }
            if (trips->size() > 1 && (!strictly_ascending(*trips) || !strictly_ascending(new_trips))) {
                r.notes.push_back(std::format("[{}] kept: {} not strictly ascending after tuning", s.name, trip_key));
                rejected = true;
                continue;
            }
            if (new_trips == *trips) continue;

            set_values(m.lines[static_cast<size_t>(s.keys.at(trip_key))], new_trips);
            if (clrs) {
                std::vector<long long> new_clrs = *clrs;
                for (size_t i = 0; i < new_clrs.size(); ++i) new_clrs[i] += new_trips[i] - (*trips)[i]; // keep hysteresis
                set_values(m.lines[static_cast<size_t>(s.keys.at(clr_key))], new_clrs);
            }
            changed = true;
        }
        if (changed && !rejected) ++r.tuned_sections;
    }
    r.text = render(m);
    return r;
}

static std::vector<std::string> verify_engine(std::string_view original, std::string_view tuned, const Policy &policy) {
    std::vector<std::string> errors;
    const Model a = parse(original);
    const Model b = parse(tuned);
    if (a.lines.size() != b.lines.size() || a.sections.size() != b.sections.size()) {
        errors.emplace_back("line or section count changed");
        return errors;
    }
    const auto shutdowns = shutdown_by_sensor(a);

    for (size_t i = 0; i < a.lines.size(); ++i) {
        const Line &x = a.lines[i];
        const Line &y = b.lines[i];
        if (x.raw == y.raw) continue;

        const std::string where = std::format("line {}", i + 1);
        static constexpr std::array<std::string_view, 4> kTripKeys{"thresholds", "thresholds_clr", "set_point", "set_point_clr"};
        if (x.header || x.key != y.key || std::find(kTripKeys.begin(), kTripKeys.end(), x.key) == kTripKeys.end()) {
            errors.push_back(where + ": only trip values may change");
            continue;
        }
        const Section &sec = a.sections[static_cast<size_t>(x.section)];
        if (!ineligible(a, sec).empty()) {
            errors.push_back(std::format("{}: section [{}] must not change ({})", where, sec.name, ineligible(a, sec)));
            continue;
        }
        const auto ov = numbers(&x);
        const auto nv = numbers(&y);
        if (!ov || !nv || ov->size() != nv->size()) {
            errors.push_back(where + ": value count changed");
            continue;
        }
        const long long unit = unit_of(*ov);
        const long long milli = unit == 1000 ? 1 : 1000;
        const bool is_trip = x.key == "thresholds" || x.key == "set_point";
        const long long cap = cap_for(sensor_of(a, sec), policy, shutdowns);
        for (size_t k = 0; k < ov->size(); ++k) {
            const long long d = (*nv)[k] - (*ov)[k];
            if (d < 0) errors.push_back(std::format("{}: {} lowered", where, x.key));
            if (d > policy.margin_c * unit) errors.push_back(std::format("{}: {} raised beyond the margin", where, x.key));
            if (is_trip && d > 0 && (*nv)[k] * milli > cap) errors.push_back(std::format("{}: {} above the cap", where, x.key));
        }
        if (is_trip && ov->size() > 1 && strictly_ascending(*ov) && !strictly_ascending(*nv)) {
            errors.push_back(where + ": trips no longer ascending");
        }
    }

    // Hysteresis: a clear value must stay below its trip.
    for (size_t si = 0; si < b.sections.size(); ++si) {
        for (const auto &[trip_key, clr_key] : {std::pair{"thresholds", "thresholds_clr"}, std::pair{"set_point", "set_point_clr"}}) {
            const auto t = numbers(find(b, b.sections[si], trip_key));
            const auto c = numbers(find(b, b.sections[si], clr_key));
            const auto ot = numbers(find(a, a.sections[si], trip_key));
            const auto oc = numbers(find(a, a.sections[si], clr_key));
            if (!t || !c || !ot || !oc || t->size() != c->size() || ot->size() != oc->size()) continue;
            for (size_t k = 0; k < t->size(); ++k) {
                if ((*oc)[k] < (*ot)[k] && (*c)[k] >= (*t)[k]) {
                    errors.push_back(std::format("[{}]: {} no longer below {}", b.sections[si].name, clr_key, trip_key));
                }
            }
        }
    }
    return errors;
}

Format detect_format(std::string_view content) {
    if (haljson::is_config(content)) return Format::HalJson;
    if (is_engine_text(content)) return Format::Engine;
    if (mithermald::is_config(content)) return Format::MiThermald;
    if (const auto plain = micrypt::decrypt(content); plain && mithermald::is_config(*plain)) return Format::MiEncrypted;
    return Format::Unknown;
}

std::optional<std::string> plain_text(std::string_view content) {
    switch (detect_format(content)) {
    case Format::Unknown: return std::nullopt;
    case Format::MiEncrypted: return micrypt::decrypt(content);
    default: return std::string(content);
    }
}

bool is_tunable_text(std::string_view content) {
    return detect_format(content) != Format::Unknown;
}

std::optional<Result> tune(std::string_view content, const Policy &policy) {
    switch (detect_format(content)) {
    case Format::HalJson: return haljson::tune(content, policy);
    case Format::Engine: return tune_engine(content, policy);
    case Format::MiThermald: return mithermald::tune(content, policy);
    case Format::MiEncrypted: {
        // mi_thermald only loads encrypted configs: tune the plain text, encrypt the result again.
        auto r = mithermald::tune(*micrypt::decrypt(content), policy);
        if (r && r->tuned_sections > 0) r->text = micrypt::encrypt(r->text);
        else if (r) r->text = std::string(content);
        return r;
    }
    case Format::Unknown: break;
    }
    return std::nullopt;
}

std::vector<std::string> verify(std::string_view original, std::string_view tuned, const Policy &policy) {
    switch (detect_format(original)) {
    case Format::HalJson: return haljson::verify(original, tuned, policy);
    case Format::Engine: return verify_engine(original, tuned, policy);
    case Format::MiThermald: return mithermald::verify(original, tuned, policy);
    case Format::MiEncrypted: {
        const auto a = micrypt::decrypt(original);
        const auto b = micrypt::decrypt(tuned);
        if (!b) return {"tuned file is not a valid encrypted mi_thermald config"};
        return mithermald::verify(*a, *b, policy);
    }
    case Format::Unknown: break;
    }
    return original == tuned ? std::vector<std::string>{} : std::vector<std::string>{"unknown format must not change"};
}

} // namespace hico::thermalcfg
