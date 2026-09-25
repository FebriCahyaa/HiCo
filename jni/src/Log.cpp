/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Log.hpp"

#include "Fs.hpp"

#include <cstdio>
#include <ctime>
#include <mutex>

#include <sys/stat.h>
#include <sys/time.h>

namespace hico::log {

namespace {

std::mutex g_mutex;
std::string g_path;
Level g_level = Level::Info;

char level_char(Level l) {
    switch (l) {
    case Level::Error: return 'E';
    case Level::Warn: return 'W';
    case Level::Info: return 'I';
    case Level::Debug: return 'D';
    }
    return '?';
}

std::string timestamp() {
    timeval tv{};
    gettimeofday(&tv, nullptr);
    tm local{};
    localtime_r(&tv.tv_sec, &local);
    char buf[32];
    const size_t n = strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &local);
    return std::format("{}.{:03}", std::string_view(buf, n), tv.tv_usec / 1000);
}

void rotate_if_needed() {
    struct stat st{};
    const std::string real = fs::real(g_path);
    if (::stat(real.c_str(), &st) == 0 && static_cast<size_t>(st.st_size) > kMaxBytes) {
        ::rename(real.c_str(), (real + ".old").c_str());
    }
}

} // namespace

void init(std::string path, Level level) {
    std::lock_guard lk(g_mutex);
    g_path = std::move(path);
    g_level = level;
}

void set_level(Level level) {
    std::lock_guard lk(g_mutex);
    g_level = level;
}

bool enabled(Level level) {
    std::lock_guard lk(g_mutex);
    return static_cast<int>(level) <= static_cast<int>(g_level);
}

void write(Level level, std::string_view msg) {
    std::lock_guard lk(g_mutex);
    const std::string line = std::format("{} {} {}", timestamp(), level_char(level), msg);
    if (g_path.empty()) {
        std::fprintf(stderr, "%s\n", line.c_str());
        return;
    }
    rotate_if_needed();
    fs::append_line(g_path, line, 0600);
}

} // namespace hico::log
