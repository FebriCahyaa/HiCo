/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

// Thermal HAL configuration (thermal_info_config*.json), as used by the AOSP /
// Pixel-style thermal HAL on AOSP-based ROMs and by newer vendor stacks:
//
//   {"Sensors": [{"Name": "VIRTUAL-SKIN", "Type": "SKIN",
//                 "HotThreshold": ["NAN", 39.0, 43.0, 45.0, 47.0, 52.0, 55.0], ...}, ...]}
//
// HotThreshold has one entry per severity: NONE, LIGHT, MODERATE, SEVERE,
// CRITICAL, EMERGENCY, SHUTDOWN. Only LIGHT..CRITICAL are raised; EMERGENCY
// and SHUTDOWN never change. Edits replace number tokens in place, so the rest
// of the file stays byte-identical.

#include "ThermalConfig.hpp"

#include "Fs.hpp"
#include "ThermalZones.hpp"

#include <algorithm>
#include <cmath>
#include <format>

namespace hico::thermalcfg::haljson {

namespace {

constexpr size_t kLevels = 7;
constexpr size_t kFirstRaised = 1; // LIGHT
constexpr size_t kLastRaised = 4;  // CRITICAL
constexpr int kMaxDepth = 64;

// ── Minimal JSON parser that remembers where every value is in the source ──

struct Value {
    enum class Kind { Object, Array, String, Number, Literal } kind = Kind::Literal;
    size_t begin = 0;
    size_t end = 0;
    std::string text; ///< decoded string or raw number/literal
    std::vector<std::string> keys; ///< object member names, parallel to items
    std::vector<Value> items;      ///< array items, or object member values

    [[nodiscard]] const Value *get(std::string_view key) const {
        for (size_t i = 0; i < keys.size(); ++i) {
            if (keys[i] == key) return &items[i];
        }
        return nullptr;
    }
};

class Parser {
public:
    explicit Parser(std::string_view s) : s_(s) {}

    std::optional<Value> parse() {
        auto v = value(0);
        skip();
        if (!v || pos_ != s_.size()) return std::nullopt;
        return v;
    }

private:
    void skip() {
        while (pos_ < s_.size() && (s_[pos_] == ' ' || s_[pos_] == '\n' || s_[pos_] == '\r' || s_[pos_] == '\t')) ++pos_;
    }

    std::optional<Value> value(int depth) {
        if (depth > kMaxDepth) return std::nullopt;
        skip();
        if (pos_ >= s_.size()) return std::nullopt;
        const char c = s_[pos_];
        if (c == '{') return object(depth);
        if (c == '[') return array(depth);
        if (c == '"') return string();
        return scalar();
    }

    std::optional<Value> object(int depth) {
        Value v;
        v.kind = Value::Kind::Object;
        v.begin = pos_++;
        skip();
        if (pos_ < s_.size() && s_[pos_] == '}') {
            v.end = ++pos_;
            return v;
        }
        while (true) {
            skip();
            auto key = string();
            if (!key) return std::nullopt;
            skip();
            if (pos_ >= s_.size() || s_[pos_] != ':') return std::nullopt;
            ++pos_;
            auto val = value(depth + 1);
            if (!val) return std::nullopt;
            v.keys.push_back(key->text);
            v.items.push_back(std::move(*val));
            skip();
            if (pos_ < s_.size() && s_[pos_] == ',') {
                ++pos_;
                continue;
            }
            if (pos_ < s_.size() && s_[pos_] == '}') {
                v.end = ++pos_;
                return v;
            }
            return std::nullopt;
        }
    }

    std::optional<Value> array(int depth) {
        Value v;
        v.kind = Value::Kind::Array;
        v.begin = pos_++;
        skip();
        if (pos_ < s_.size() && s_[pos_] == ']') {
            v.end = ++pos_;
            return v;
        }
        while (true) {
            auto item = value(depth + 1);
            if (!item) return std::nullopt;
            v.items.push_back(std::move(*item));
            skip();
            if (pos_ < s_.size() && s_[pos_] == ',') {
                ++pos_;
                continue;
            }
            if (pos_ < s_.size() && s_[pos_] == ']') {
                v.end = ++pos_;
                return v;
            }
            return std::nullopt;
        }
    }

    std::optional<Value> string() {
        if (pos_ >= s_.size() || s_[pos_] != '"') return std::nullopt;
        Value v;
        v.kind = Value::Kind::String;
        v.begin = pos_++;
        while (pos_ < s_.size() && s_[pos_] != '"') {
            if (s_[pos_] == '\\') {
                if (++pos_ >= s_.size()) return std::nullopt;
                v.text += s_[pos_] == 'n' ? '\n' : s_[pos_]; // names never need more than this
            } else {
                v.text += s_[pos_];
            }
            ++pos_;
        }
        if (pos_ >= s_.size()) return std::nullopt;
        v.end = ++pos_;
        return v;
    }

    std::optional<Value> scalar() {
        Value v;
        v.begin = pos_;
        while (pos_ < s_.size() && std::string_view("+-.0123456789eEtruefalsn").find(s_[pos_]) != std::string_view::npos) {
            ++pos_;
        }
        if (pos_ == v.begin) return std::nullopt;
        v.end = pos_;
        v.text = std::string(s_.substr(v.begin, v.end - v.begin));
        if (v.text == "true" || v.text == "false" || v.text == "null") {
            v.kind = Value::Kind::Literal;
        } else {
            char *endp = nullptr;
            (void)std::strtod(v.text.c_str(), &endp);
            if (!endp || *endp != '\0') return std::nullopt;
            v.kind = Value::Kind::Number;
        }
        return v;
    }

    std::string_view s_;
    size_t pos_ = 0;
};

// ── Sensor rules ────────────────────────────────────────────────────────────

struct Sensor {
    std::string name;
    std::string type;
    const Value *hot = nullptr; ///< HotThreshold array
};

std::vector<Sensor> sensors(const Value &root) {
    std::vector<Sensor> out;
    const Value *list = root.kind == Value::Kind::Object ? root.get("Sensors") : nullptr;
    if (!list || list->kind != Value::Kind::Array) return out;
    for (const auto &item : list->items) {
        if (item.kind != Value::Kind::Object) continue;
        Sensor s;
        if (const Value *n = item.get("Name"); n && n->kind == Value::Kind::String) s.name = n->text;
        if (const Value *t = item.get("Type"); t && t->kind == Value::Kind::String) s.type = t->text;
        if (const Value *h = item.get("HotThreshold"); h && h->kind == Value::Kind::Array && h->items.size() == kLevels) {
            s.hot = h;
        }
        out.push_back(std::move(s));
    }
    return out;
}

/// Why a sensor may not be tuned ("" = eligible).
std::string ineligible(const Sensor &s) {
    if (!s.hot) return "no 7-level HotThreshold";
    std::string type;
    for (const char c : s.type) type += static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    if (type == "BATTERY" || type == "USB_PORT" || type.starts_with("BCL") || type == "POWER_AMPLIFIER") {
        return "battery / power sensor";
    }
    if (thermal::classify_zone(s.name) == thermal::ZoneKind::Battery) return "battery / power sensor";
    return {};
}

bool is_cpu_gpu(const Sensor &s) {
    const auto kind = thermal::classify_zone(s.name);
    return s.type == "CPU" || s.type == "GPU" || kind == thermal::ZoneKind::Cpu || kind == thermal::ZoneKind::Gpu;
}

std::optional<double> number(const Value &v) {
    if (v.kind != Value::Kind::Number) return std::nullopt;
    const double d = std::strtod(v.text.c_str(), nullptr);
    return std::isfinite(d) ? std::optional<double>(d) : std::nullopt;
}

/// Keeps the token's style: "39" stays an integer, "39.0" / "39.50" keep their decimals.
std::string format_like(const std::string &token, double value) {
    const auto dot = token.find('.');
    if (dot == std::string::npos || token.find_first_of("eE") != std::string::npos) {
        return std::format("{}", static_cast<long long>(std::llround(value)));
    }
    const int decimals = static_cast<int>(token.size() - dot - 1);
    return std::format("{:.{}f}", value, decimals);
}

double cap_for(const Sensor &s, const Policy &p) {
    double cap = is_cpu_gpu(s) ? p.cap_cpu_c : p.cap_other_c;
    // Stay below the sensor's own EMERGENCY / SHUTDOWN levels by the guard.
    for (size_t i = kLastRaised + 1; i < kLevels; ++i) {
        if (const auto v = number(s.hot->items[i])) cap = std::min(cap, *v - p.shutdown_guard_c);
    }
    return cap;
}

bool ascending(const std::vector<std::optional<double>> &levels) {
    std::optional<double> prev;
    for (const auto &l : levels) {
        if (!l) continue;
        if (prev && *l <= *prev) return false;
        prev = l;
    }
    return true;
}

} // namespace

bool is_config(std::string_view content) {
    const size_t first = content.find_first_not_of(" \t\r\n");
    if (first == std::string_view::npos || content[first] != '{' || content.size() > 1024 * 1024) return false;
    const auto root = Parser(content).parse();
    if (!root) return false;
    const auto list = sensors(*root);
    return std::any_of(list.begin(), list.end(), [](const Sensor &s) { return s.hot != nullptr; });
}

std::optional<Result> tune(std::string_view content, const Policy &policy) {
    if (!is_config(content)) return std::nullopt;
    const auto root = Parser(content).parse();
    const auto list = sensors(*root);

    Result r;
    r.sections = static_cast<int>(list.size());
    struct Edit {
        size_t begin, end;
        std::string text;
    };
    std::vector<Edit> edits;

    for (const auto &s : list) {
        if (const std::string why = ineligible(s); !why.empty()) {
            if (s.hot) r.notes.push_back(std::format("{} ({}) kept: {}", s.name, s.type, why));
            continue;
        }
        const double cap = cap_for(s, policy);
        std::vector<std::optional<double>> before, after;
        for (const auto &item : s.hot->items) before.push_back(number(item));
        after = before;
        for (size_t i = kFirstRaised; i <= kLastRaised; ++i) {
            if (!before[i]) continue;
            after[i] = std::max(*before[i], std::min(*before[i] + policy.margin_c, cap)); // never lower
        }
        if (after == before) continue;
        if (!ascending(before) || !ascending(after)) {
            r.notes.push_back(std::format("{} kept: severity levels not ascending after tuning", s.name));
            continue;
        }
        for (size_t i = kFirstRaised; i <= kLastRaised; ++i) {
            if (!before[i] || *after[i] == *before[i]) continue;
            const Value &tok = s.hot->items[i];
            edits.push_back({tok.begin, tok.end, format_like(tok.text, *after[i])});
        }
        ++r.tuned_sections;
    }

    r.text = std::string(content);
    std::sort(edits.begin(), edits.end(), [](const Edit &a, const Edit &b) { return a.begin > b.begin; });
    for (const auto &e : edits) r.text.replace(e.begin, e.end - e.begin, e.text);
    return r;
}

std::vector<std::string> verify(std::string_view original, std::string_view tuned, const Policy &policy) {
    std::vector<std::string> errors;
    const auto a = Parser(original).parse();
    const auto b = Parser(tuned).parse();
    if (!a || !b) return {"tuned file is not valid JSON"};
    const auto sa = sensors(*a);
    const auto sb = sensors(*b);
    if (sa.size() != sb.size()) return {"sensor count changed"};

    // Everything outside the LIGHT..CRITICAL tokens of eligible sensors must be byte-identical.
    std::vector<std::pair<size_t, size_t>> ra, rb;
    for (size_t i = 0; i < sa.size(); ++i) {
        if (sa[i].name != sb[i].name || sa[i].type != sb[i].type || !sa[i].hot != !sb[i].hot) {
            errors.push_back(std::format("sensor {} changed identity", i));
            continue;
        }
        if (!ineligible(sa[i]).empty()) continue;
        for (size_t l = kFirstRaised; l <= kLastRaised; ++l) {
            ra.emplace_back(sa[i].hot->items[l].begin, sa[i].hot->items[l].end);
            rb.emplace_back(sb[i].hot->items[l].begin, sb[i].hot->items[l].end);
        }
    }
    if (!errors.empty()) return errors;
    size_t pa = 0, pb = 0;
    for (size_t k = 0; k <= ra.size(); ++k) {
        const size_t ea = k < ra.size() ? ra[k].first : original.size();
        const size_t eb = k < rb.size() ? rb[k].first : tuned.size();
        if (original.substr(pa, ea - pa) != tuned.substr(pb, eb - pb)) {
            errors.emplace_back("content outside LIGHT..CRITICAL thresholds changed");
            return errors;
        }
        if (k < ra.size()) {
            pa = ra[k].second;
            pb = rb[k].second;
        }
    }

    for (size_t i = 0; i < sa.size(); ++i) {
        if (!ineligible(sa[i]).empty()) continue;
        const double cap = cap_for(sa[i], policy);
        std::vector<std::optional<double>> before, after;
        for (size_t l = 0; l < kLevels; ++l) {
            before.push_back(number(sa[i].hot->items[l]));
            after.push_back(number(sb[i].hot->items[l]));
        }
        for (size_t l = kFirstRaised; l <= kLastRaised; ++l) {
            if (!before[l] != !after[l]) {
                errors.push_back(std::format("{}: level {} changed type", sa[i].name, l));
                continue;
            }
            if (!before[l]) continue;
            const double d = *after[l] - *before[l];
            if (d < -1e-9) errors.push_back(std::format("{}: level {} lowered", sa[i].name, l));
            if (d > policy.margin_c + 1e-9) errors.push_back(std::format("{}: level {} raised beyond the margin", sa[i].name, l));
            if (d > 1e-9 && *after[l] > cap + 1e-9) errors.push_back(std::format("{}: level {} above the cap", sa[i].name, l));
        }
        if (ascending(before) && !ascending(after)) errors.push_back(std::format("{}: levels no longer ascending", sa[i].name));
    }
    return errors;
}

} // namespace hico::thermalcfg::haljson
