/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Monitor.hpp"

#include "Fs.hpp"

#include <algorithm>
#include <array>
#include <chrono>
#include <format>
#include <limits>
#include <string_view>

namespace hico::monitor {

namespace {

constexpr int kMaxTrips = 32;
constexpr double kElevatedHeadroomC = 5.0;

std::string base_name(std::string_view path) {
    return std::string(path.substr(path.rfind('/') + 1));
}

std::string json_escape(std::string_view value) {
    std::string out;
    out.reserve(value.size());
    for (const char ch : value) {
        switch (ch) {
        case '\\': out += "\\\\"; break;
        case '"': out += "\\\""; break;
        case '\n': out += "\\n"; break;
        case '\r': out += "\\r"; break;
        case '\t': out += "\\t"; break;
        default: out += ch; break;
        }
    }
    return out;
}

std::string json_opt(const std::optional<double> &value) {
    return value ? std::format("{:.1f}", *value) : "null";
}

struct TripSet {
    std::optional<double> passive;
    std::optional<double> hot;
    std::optional<double> critical;
    std::optional<double> highest;
    std::optional<double> next;
    int count = 0;
};

void update_min(std::optional<double> &dst, double value) {
    if (!dst || value < *dst) dst = value;
}

void update_max(std::optional<double> &dst, double value) {
    if (!dst || value > *dst) dst = value;
}

TripSet read_trips(const std::string &zone_dir, double current_c) {
    TripSet trips;
    for (int i = 0; i < kMaxTrips; ++i) {
        const std::string base = zone_dir + "/trip_point_" + std::to_string(i);
        const auto type_raw = fs::read(base + "_type");
        const auto temp_raw = fs::read_int(base + "_temp");
        if (!type_raw || !temp_raw) continue;

        const auto normalized = thermal::normalize_temp(*temp_raw);
        if (!normalized) continue;
        const std::string type = str::trim(*type_raw);
        const double temp = *normalized;
        ++trips.count;
        update_max(trips.highest, temp);
        if (temp > current_c && (!trips.next || temp < *trips.next)) trips.next = temp;

        if (str::icontains(type, "critical")) {
            update_min(trips.critical, temp);
        } else if (str::icontains(type, "hot")) {
            update_min(trips.hot, temp);
        } else if (str::icontains(type, "passive")) {
            update_min(trips.passive, temp);
        }
    }
    return trips;
}

std::string zone_state(const ZoneReading &zone) {
    if (zone.critical_trip_c && zone.temp_c >= *zone.critical_trip_c) return "critical";
    if ((zone.hot_trip_c && zone.temp_c >= *zone.hot_trip_c) ||
        (zone.passive_trip_c && zone.temp_c >= *zone.passive_trip_c)) {
        return "mitigating";
    }
    if (zone.headroom_c && *zone.headroom_c <= kElevatedHeadroomC) return "elevated";
    return zone.highest_trip_c ? "normal" : "unknown";
}

int state_rank(std::string_view state) {
    if (state == "critical") return 4;
    if (state == "mitigating") return 3;
    if (state == "elevated") return 2;
    if (state == "normal") return 1;
    return 0;
}

} // namespace

int Snapshot::active_cooling() const {
    int active = 0;
    for (const auto &device : cooling_devices) {
        if (device.cur > 0) ++active;
    }
    return active;
}

int Snapshot::cooling_device_count() const {
    return static_cast<int>(cooling_devices.size());
}

std::optional<double> Snapshot::hottest_temp_c() const {
    if (zones.empty()) return std::nullopt;
    return std::max_element(zones.begin(), zones.end(), [](const ZoneReading &a, const ZoneReading &b) {
               return a.temp_c < b.temp_c;
           })
        ->temp_c;
}

const ZoneReading *Snapshot::hottest_zone() const {
    if (zones.empty()) return nullptr;
    return &*std::max_element(zones.begin(), zones.end(), [](const ZoneReading &a, const ZoneReading &b) {
        return a.temp_c < b.temp_c;
    });
}

std::optional<double> Snapshot::closest_headroom_c() const {
    std::optional<double> result;
    for (const auto &zone : zones) {
        if (!zone.headroom_c) continue;
        if (!result || *zone.headroom_c < *result) result = zone.headroom_c;
    }
    return result;
}

const ZoneReading *Snapshot::closest_zone() const {
    const ZoneReading *result = nullptr;
    for (const auto &zone : zones) {
        if (!zone.headroom_c) continue;
        if (!result || *zone.headroom_c < *result->headroom_c) result = &zone;
    }
    return result;
}

Verdict Snapshot::verdict() const {
    bool elevated = false;
    bool mitigating = false;
    for (const auto &zone : zones) {
        if (zone.state == "critical") return Verdict::Critical;
        if (zone.state == "mitigating") mitigating = true;
        if (zone.state == "elevated") elevated = true;
    }
    if (mitigating || !cooling.empty()) return Verdict::Mitigating;
    if (elevated) return Verdict::Elevated;
    return Verdict::Normal;
}

std::string_view to_string(Verdict v) {
    switch (v) {
    case Verdict::Normal: return "normal";
    case Verdict::Elevated: return "elevated";
    case Verdict::Mitigating: return "mitigating";
    case Verdict::Critical: return "critical";
    }
    return "normal";
}

Snapshot sample(size_t max_zones) {
    Snapshot s;
    s.time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    for (const auto &d : thermal::cooling_devices()) {
        const long long cur = fs::read_int(d.dir + "/cur_state").value_or(0);
        const long long max = fs::read_int(d.dir + "/max_state").value_or(0);
        if (cur < 0 || max < 0) continue;
        Cooling reading{base_name(d.dir), d.type, cur, max};
        s.cooling_devices.push_back(reading);
        if (cur > 0) s.cooling.push_back(std::move(reading));
    }

    const auto zones = thermal::zones();
    for (const auto &z : zones) {
        const auto t = z.temp_c();
        if (!t) continue;

        ZoneReading r;
        r.name = base_name(z.dir);
        r.type = z.type;
        r.temp_c = *t;
        r.policy = fs::read(z.dir + "/policy").value_or("");
        r.protected_zone = z.is_protected();

        const TripSet trips = read_trips(z.dir, r.temp_c);
        r.passive_trip_c = trips.passive;
        r.hot_trip_c = trips.hot;
        r.critical_trip_c = trips.critical;
        r.highest_trip_c = trips.highest;
        r.next_trip_c = trips.next;
        if (r.next_trip_c) r.headroom_c = std::max(0.0, *r.next_trip_c - r.temp_c);
        r.at_or_above_trip =
            (r.passive_trip_c && r.temp_c >= *r.passive_trip_c) ||
            (r.hot_trip_c && r.temp_c >= *r.hot_trip_c) ||
            (r.critical_trip_c && r.temp_c >= *r.critical_trip_c);
        r.state = zone_state(r);

        if (r.at_or_above_trip) ++s.tripped_zones;
        if (r.protected_zone) ++s.protected_zones;
        s.zones.push_back(std::move(r));
    }

    std::stable_sort(s.zones.begin(), s.zones.end(), [](const ZoneReading &a, const ZoneReading &b) {
        const int ar = state_rank(a.state);
        const int br = state_rank(b.state);
        if (ar != br) return ar > br;
        if (a.at_or_above_trip != b.at_or_above_trip) return a.at_or_above_trip;
        return a.temp_c > b.temp_c;
    });
    if (max_zones > 0 && s.zones.size() > max_zones) s.zones.resize(max_zones);

    s.temps = thermal::read_temperatures(zones);
    return s;
}

std::string to_json(const Snapshot &s) {
    const ZoneReading *hottest = s.hottest_zone();
    const ZoneReading *closest = s.closest_zone();
    std::string out = std::format(
        R"({{"schema":"hico.monitor.v2","time":{},"verdict":"{}","zone_count":{},"zones_at_or_above_trip":{},"protected_zones":{},"active_cooling":{},"cooling_device_count":{},)"
        R"("hottest":{},"closest":{},"temperatures":{{"cpu":{},"gpu":{},"battery":{}}},"zones":[)",
        s.time_ms, to_string(s.verdict()), s.zones.size(), s.tripped_zones, s.protected_zones,
        s.active_cooling(), s.cooling_device_count(),
        hottest ? std::format(R"({{"name":"{}","type":"{}","temp":{:.1f}}})", json_escape(hottest->name),
                              json_escape(hottest->type), hottest->temp_c)
                : "null",
        closest ? std::format(R"({{"name":"{}","type":"{}","trip":{},"headroom":{}}})", json_escape(closest->name),
                              json_escape(closest->type), json_opt(closest->next_trip_c), json_opt(closest->headroom_c))
                : "null",
        json_opt(s.temps.cpu), json_opt(s.temps.gpu), json_opt(s.temps.battery));

    for (size_t i = 0; i < s.zones.size(); ++i) {
        const auto &z = s.zones[i];
        if (i) out += ',';
        out += std::format(
            R"({{"name":"{}","type":"{}","temp":{:.1f},"passive":{},"hot":{},"critical":{},"highest":{},"next":{},"headroom":{},"policy":"{}","state":"{}","at_or_above_trip":{},"protected":{}}})",
            json_escape(z.name), json_escape(z.type), z.temp_c, json_opt(z.passive_trip_c),
            json_opt(z.hot_trip_c), json_opt(z.critical_trip_c), json_opt(z.highest_trip_c), json_opt(z.next_trip_c),
            json_opt(z.headroom_c), json_escape(z.policy), z.state, z.at_or_above_trip ? "true" : "false",
            z.protected_zone ? "true" : "false");
    }
    out += "],\"cooling\":[";
    for (size_t i = 0; i < s.cooling.size(); ++i) {
        const auto &c = s.cooling[i];
        if (i) out += ',';
        out += std::format(R"({{"name":"{}","type":"{}","cur":{},"max":{}}})",
                           json_escape(c.name), json_escape(c.type), c.cur, c.max);
    }
    out += "],\"cooling_devices\":[";
    for (size_t i = 0; i < s.cooling_devices.size(); ++i) {
        const auto &c = s.cooling_devices[i];
        if (i) out += ',';
        out += std::format(R"({{"name":"{}","type":"{}","cur":{},"max":{},"active":{}}})",
                           json_escape(c.name), json_escape(c.type), c.cur, c.max, c.cur > 0 ? "true" : "false");
    }
    out += "]}";
    return out;
}

std::string to_line(const Snapshot &s) {
    const auto temp = [](const std::optional<double> &v) { return v ? std::format("{:.1f}C", *v) : std::string("-"); };
    const ZoneReading *hottest = s.hottest_zone();
    const ZoneReading *closest = s.closest_zone();
    std::string line = std::format("{:<10} zones {}  cooling {}/{}", to_string(s.verdict()), s.zones.size(),
                                     s.active_cooling(), s.cooling_device_count());
    if (hottest) line += std::format("  hottest {} {}", temp(hottest->temp_c), hottest->type);
    if (closest) line += std::format("  next {} +{}", temp(closest->next_trip_c), temp(closest->headroom_c));
    line += std::format("  trip {}  protected {}  sensors cpu {} gpu {} bat {}",
                        s.tripped_zones, s.protected_zones,
                        temp(s.temps.cpu), temp(s.temps.gpu), temp(s.temps.battery));
    return line;
}

std::string to_table(const Snapshot &s) {
    const auto value = [](const std::optional<double> &v) {
        return v ? std::format("{:.1f}", *v) : std::string("-");
    };
    const auto clamp = [](const std::string &v, size_t width) {
        return v.size() <= width ? v : v.substr(0, width);
    };

    std::string out;
    out += "ZONE               TYPE                 TEMP  PASSIVE  HOT  CRITICAL  HIGHEST  NEXT  HEADROOM  STATE       PROTECTED  POLICY\n";
    out += "------------------ -------------------- -----  -------  ---  --------  -------  ----  --------  ----------  ---------  ----------------\n";
    for (const auto &z : s.zones) {
        out += std::format("{:<18} {:<20} {:>4.1f} C  {:>7}  {:>3}  {:>8}  {:>7}  {:>4}  {:>8}  {:<10}  {:<9}  {}\n",
                           clamp(z.name, 18), clamp(z.type, 20), z.temp_c, value(z.passive_trip_c),
                           value(z.hot_trip_c), value(z.critical_trip_c), value(z.highest_trip_c),
                           value(z.next_trip_c), value(z.headroom_c), z.state,
                           z.protected_zone ? "yes" : "no", z.policy.empty() ? "-" : z.policy);
    }
    out += std::format("\nverdict={}  zones={}  at_or_above_trip={}  active_cooling={}  cooling_devices={}  protected_zones={}\n",
                       to_string(s.verdict()), s.zones.size(), s.tripped_zones, s.active_cooling(),
                       s.cooling_device_count(), s.protected_zones);
    out += "COOLING DEVICE     TYPE                 CUR   MAX   STATE\n";
    out += "------------------ -------------------- ----- ----- ------\n";
    for (const auto &c : s.cooling_devices) {
        out += std::format("{:<18} {:<20} {:>4}  {:>4}  {:<6}\n",
                           clamp(c.name, 18), clamp(c.type, 20), c.cur, c.max, c.cur > 0 ? "active" : "idle");
    }
    return out;
}


} // namespace hico::monitor
