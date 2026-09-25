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

#include <format>
#include <string>
#include <string_view>

/**
 * Small file logger. Lines look like Flux's ("YYYY-MM-DD HH:MM:SS.mmm L msg")
 * so both logs read the same in a bug report. The file is capped at
 * kMaxBytes and rotated once to hico.log.old.
 */
namespace hico::log {

enum class Level : int { Error = 0, Warn = 1, Info = 2, Debug = 3 };

inline constexpr size_t kMaxBytes = 256 * 1024;

/// Log to @p path; an empty path logs to stderr (CLI and tests).
void init(std::string path, Level level);
void set_level(Level level);
[[nodiscard]] bool enabled(Level level);
void write(Level level, std::string_view msg);

} // namespace hico::log

#define HICO_LOG(LEVEL, ...)                                                                                           \
    do {                                                                                                               \
        if (::hico::log::enabled(LEVEL)) ::hico::log::write(LEVEL, std::format(__VA_ARGS__));                          \
    } while (0)

#define LOGE(...) HICO_LOG(::hico::log::Level::Error, __VA_ARGS__)
#define LOGW(...) HICO_LOG(::hico::log::Level::Warn, __VA_ARGS__)
#define LOGI(...) HICO_LOG(::hico::log::Level::Info, __VA_ARGS__)
#define LOGD(...) HICO_LOG(::hico::log::Level::Debug, __VA_ARGS__)
