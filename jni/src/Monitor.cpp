/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Monitor.hpp"

#include "Cpufreq.hpp"
#include "Daemon.hpp"
#include "Fs.hpp"

#include <algorithm>
#include <chrono>
#include <format>

namespace hico::monitor {

namespace {

constexpr std::string_view kKgsl = "/sys/class/kgsl/kgsl-3d0";
constexpr std::string_view kDevfreq = "/sys/class/devfreq";
constexpr int kMaxTrips = 32;

std::string base_name(std::string_view path) {
    return std::string(path.substr(path.rfind('/') + 1));
}

int pct(long long part, long long whole) {
    if (whole <= 0 || part <= 0) return 100;
    return static_cast<int>(std::clamp((part * 100 + whole / 2) / whole, 0LL, 100LL));
}

/// Frequency list in Hz ("257000000 342000000 ...") sorted high to low.
std::vector<long long> frequencies(std::string_view path) {
    std::vector<long long> out;
    for (const auto &f : str::split(fs::read(path, 8192).value_or(""), ' ')) {
        if (const auto v = str::to_int(f); v && *v > 0) out.push_back(*v);
    }
    std::sort(out.rbegin(), out.rend());
    return out;
}

long long mhz_from_hz(long long hz) {
    return hz / 1000000;
}

std::optional<Gpu> read_kgsl() {
    if (!fs::is_dir(kKgsl)) return std::nullopt;
    const std::string d(kKgsl);
    Gpu g;
    g.source = "kgsl";
    const auto levels = frequencies(d + "/gpu_available_frequencies");
    long long cur = fs::read_int(d + "/gpuclk").value_or(0);
    if (cur <= 0) cur = fs::read_int(d + "/devfreq/cur_freq").value_or(0);
    g.cur_mhz = mhz_from_hz(cur);
    g.thermal_level = static_cast<int>(fs::read_int(d + "/thermal_pwrlevel").value_or(-1));

    if (!levels.empty()) {
        // Power level 0 is the fastest; the effective cap is the slower of the thermal and max levels.
        g.max_mhz = mhz_from_hz(levels.front());
        const long long thermal = std::max(0LL, fs::read_int(d + "/thermal_pwrlevel").value_or(0));
        const long long user = std::max(0LL, fs::read_int(d + "/max_pwrlevel").value_or(0));
        const auto level = static_cast<size_t>(std::min<long long>(std::max(thermal, user), static_cast<long long>(levels.size()) - 1));
        g.cap_mhz = mhz_from_hz(levels[level]);
    } else {
        g.max_mhz = mhz_from_hz(fs::read_int(d + "/max_gpuclk").value_or(0));
        g.cap_mhz = g.max_mhz;
    }
    if (g.max_mhz <= 0 && g.cur_mhz <= 0) return std::nullopt;
    return g;
}

bool is_gpu_devfreq(std::string_view name) {
    for (const auto hint : {"gpu", "mali", "kgsl", "g3d", "sgpu"}) {
        if (str::icontains(name, hint)) return true;
    }
    return false;
}

std::optional<Gpu> read_devfreq_gpu() {
    for (const auto &name : fs::list_dir(kDevfreq)) {
        const std::string d = std::string(kDevfreq) + "/" + name;
        if (!is_gpu_devfreq(name) && !is_gpu_devfreq(str::trim(fs::read(d + "/name").value_or("")))) continue;
        Gpu g;
        g.source = name;
        g.cur_mhz = mhz_from_hz(fs::read_int(d + "/cur_freq").value_or(0));
        g.cap_mhz = mhz_from_hz(fs::read_int(d + "/max_freq").value_or(0));
        const auto levels = frequencies(d + "/available_frequencies");
        g.max_mhz = levels.empty() ? g.cap_mhz : mhz_from_hz(levels.front());
        if (g.max_mhz > 0) return g;
    }
    return std::nullopt;
}

/// Lowest passive or hot trip point of a zone (the ones that throttle; critical shuts down).
std::optional<double> throttle_trip(const std::string &zone_dir) {
    std::optional<double> lowest;
    for (int i = 0; i < kMaxTrips; ++i) {
        const std::string base = zone_dir + "/trip_point_" + std::to_string(i);
        const auto type = fs::read(base + "_type");
        if (!type) break;
        const std::string t = str::trim(*type);
        if (t != "passive" && t != "hot") continue;
        const auto raw = fs::read_int(base + "_temp");
        if (!raw || *raw <= 0) continue;
        const auto c = thermal::normalize_temp(*raw);
        if (c && (!lowest || *c < *lowest)) lowest = c;
    }
    return lowest;
}

std::string json_opt(const std::optional<double> &v) {
    return v ? std::format("{:.1f}", *v) : "null";
}

} // namespace

int Cluster::limit_pct() const {
    return pct(cap_mhz, max_mhz);
}

int Gpu::limit_pct() const {
    return pct(cap_mhz, max_mhz);
}

int Snapshot::cpu_limit_pct() const {
    long long weighted = 0;
    long long cores = 0;
    for (const auto &c : clusters) {
        const int n = std::max(1, c.cores);
        weighted += static_cast<long long>(c.limit_pct()) * n;
        cores += n;
    }
    return cores ? static_cast<int>((weighted + cores / 2) / cores) : 100;
}

int Snapshot::active_performance_cooling() const {
    return static_cast<int>(std::count_if(cooling.begin(), cooling.end(), [](const Cooling &c) { return c.performance; }));
}

Verdict Snapshot::verdict() const {
    int worst = 100;
    for (const auto &c : clusters) worst = std::min(worst, c.limit_pct());
    if (gpu) worst = std::min(worst, gpu->limit_pct());
    const bool gpu_thermal = gpu && gpu->thermal_level > 0;
    if (worst >= 100 && !gpu_thermal && active_performance_cooling() == 0 && tripped_zones == 0) return Verdict::None;
    return worst >= 80 ? Verdict::Light : Verdict::Heavy;
}

std::string_view to_string(Verdict v) {
    switch (v) {
    case Verdict::None: return "none";
    case Verdict::Light: return "light";
    case Verdict::Heavy: return "heavy";
    }
    return "none";
}

std::string cpu_ranges(const std::vector<int> &cpus) {
    std::vector<int> v = cpus;
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    std::string out;
    for (size_t i = 0; i < v.size();) {
        size_t j = i;
        while (j + 1 < v.size() && v[j + 1] == v[j] + 1) ++j;
        if (!out.empty()) out += ',';
        out += j > i ? std::format("{}-{}", v[i], v[j]) : std::to_string(v[i]);
        i = j + 1;
    }
    return out;
}

Snapshot sample(size_t max_zones) {
    Snapshot s;
    s.time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    for (const auto &p : cpufreq::policies()) {
        Cluster c;
        c.name = base_name(p.dir);
        c.cpus = cpu_ranges(p.cpus);
        c.cores = static_cast<int>(p.cpus.size());
        c.max_mhz = p.max_freq / 1000;
        c.min_mhz = fs::read_int(p.dir + "/cpuinfo_min_freq").value_or(0) / 1000;
        c.cur_mhz = fs::read_int(p.dir + "/scaling_cur_freq").value_or(0) / 1000;
        c.cap_mhz = fs::read_int(p.dir + "/scaling_max_freq").value_or(p.max_freq) / 1000;
        s.clusters.push_back(std::move(c));
    }

    s.gpu = read_kgsl();
    if (!s.gpu) s.gpu = read_devfreq_gpu();

    for (const auto &d : thermal::cooling_devices()) {
        const long long cur = fs::read_int(d.dir + "/cur_state").value_or(0);
        if (cur <= 0) continue;
        s.cooling.push_back({base_name(d.dir), d.type, cur, fs::read_int(d.dir + "/max_state").value_or(0),
                             thermal::is_performance_cooling(d.type)});
    }

    const auto zones = thermal::zones();
    for (const auto &z : zones) {
        const auto t = z.temp_c();
        if (!t) continue;
        ZoneReading r{base_name(z.dir), z.type, *t, throttle_trip(z.dir), false};
        // Battery / charger zones protect the cell; their trips are reported but never counted as throttling.
        r.tripped = r.trip_c && *t >= *r.trip_c && !z.is_protected();
        if (r.tripped) ++s.tripped_zones;
        s.zones.push_back(std::move(r));
    }
    std::stable_sort(s.zones.begin(), s.zones.end(), [](const ZoneReading &a, const ZoneReading &b) {
        if (a.tripped != b.tripped) return a.tripped;
        return a.temp_c > b.temp_c;
    });
    if (s.zones.size() > max_zones) s.zones.resize(max_zones);

    s.temps = thermal::read_temperatures(zones);
    return s;
}

std::string to_json(const Snapshot &s) {
    std::string out = std::format(
        R"({{"time":{},"verdict":"{}","cpu_limit":{},"gpu_limit":{},"cooling_active":{},"tripped_zones":{},)"
        R"("temps":{{"cpu":{},"gpu":{},"battery":{}}},"clusters":[)",
        s.time_ms, to_string(s.verdict()), s.cpu_limit_pct(), s.gpu ? std::to_string(s.gpu->limit_pct()) : "null",
        s.active_performance_cooling(), s.tripped_zones, json_opt(s.temps.cpu), json_opt(s.temps.gpu),
        json_opt(s.temps.battery));
    for (size_t i = 0; i < s.clusters.size(); ++i) {
        const auto &c = s.clusters[i];
        out += std::format(R"({}{{"name":"{}","cpus":"{}","cores":{},"cur":{},"min":{},"max":{},"cap":{},"limit":{}}})",
                           i ? "," : "", json_escape(c.name), json_escape(c.cpus), c.cores, c.cur_mhz, c.min_mhz,
                           c.max_mhz, c.cap_mhz, c.limit_pct());
    }
    out += "],\"gpu\":";
    if (s.gpu) {
        out += std::format(R"({{"source":"{}","cur":{},"max":{},"cap":{},"limit":{},"thermal_level":{}}})",
                           json_escape(s.gpu->source), s.gpu->cur_mhz, s.gpu->max_mhz, s.gpu->cap_mhz,
                           s.gpu->limit_pct(), s.gpu->thermal_level);
    } else {
        out += "null";
    }
    out += ",\"cooling\":[";
    for (size_t i = 0; i < s.cooling.size(); ++i) {
        const auto &c = s.cooling[i];
        out += std::format(R"({}{{"name":"{}","type":"{}","cur":{},"max":{},"perf":{}}})", i ? "," : "",
                           json_escape(c.name), json_escape(c.type), c.cur, c.max, c.performance ? "true" : "false");
    }
    out += "],\"zones\":[";
    for (size_t i = 0; i < s.zones.size(); ++i) {
        const auto &z = s.zones[i];
        out += std::format(R"({}{{"name":"{}","type":"{}","temp":{:.1f},"trip":{},"tripped":{}}})", i ? "," : "",
                           json_escape(z.name), json_escape(z.type), z.temp_c, json_opt(z.trip_c),
                           z.tripped ? "true" : "false");
    }
    out += "]}";
    return out;
}

std::string to_line(const Snapshot &s) {
    const auto temp = [](const std::optional<double> &v) { return v ? std::format("{:.1f}C", *v) : std::string("-"); };
    std::string line = std::format("{:<6} CPU {:>3}%", to_string(s.verdict()), s.cpu_limit_pct());
    for (const auto &c : s.clusters) {
        line += std::format("  [{} {}/{}{}]", c.cpus, c.cur_mhz, c.cap_mhz, c.throttled() ? std::format(" of {}", c.max_mhz) : "");
    }
    if (s.gpu) {
        line += std::format("  GPU {:>3}% {}/{}MHz", s.gpu->limit_pct(), s.gpu->cur_mhz, s.gpu->cap_mhz);
        if (s.gpu->thermal_level > 0) line += std::format(" lvl{}", s.gpu->thermal_level);
    }
    line += std::format("  cooling {}  tripped {}  cpu {} gpu {} bat {}", s.active_performance_cooling(), s.tripped_zones,
                        temp(s.temps.cpu), temp(s.temps.gpu), temp(s.temps.battery));
    return line;
}

} // namespace hico::monitor
