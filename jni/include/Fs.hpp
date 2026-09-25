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

#include <optional>
#include <string>
#include <string_view>
#include <vector>

/**
 * File access for the daemon.
 *
 * Every path in HiCo is absolute ("/sys/...", "/data/adb/..."). Host builds
 * (unit tests) prefix them with $HICO_ROOT so the whole daemon runs against a
 * fake sysfs tree; Android builds ignore that variable, so a root daemon can
 * never be redirected by its environment.
 */
namespace hico::fs {

/// Maps an absolute device path to the real path (identity on Android).
[[nodiscard]] std::string real(std::string_view path);

[[nodiscard]] bool exists(std::string_view path);
[[nodiscard]] bool is_dir(std::string_view path);

/// Reads at most @p max_bytes, trailing whitespace removed. nullopt when unreadable.
[[nodiscard]] std::optional<std::string> read(std::string_view path, size_t max_bytes = 4096);
[[nodiscard]] std::optional<long long> read_int(std::string_view path);

/**
 * Writes a kernel node (sysfs / procfs). The node must already exist: nothing
 * is created, symlinks are not followed, and only /sys and /proc are accepted.
 * A node that Flux (or a vendor daemon) made read-only is made writable first.
 */
bool write_node(std::string_view path, std::string_view value);

/// True for paths HiCo may write as kernel tunables (/sys/..., /proc/..., no "..").
[[nodiscard]] bool is_kernel_node(std::string_view path);

/// Replaces @p path atomically (tmp + fsync + rename, O_NOFOLLOW|O_EXCL on the tmp file).
bool write_atomic(std::string_view path, std::string_view content, unsigned mode = 0600);

/// Appends one line (adds the newline) with O_APPEND|O_NOFOLLOW; creates the file with @p mode.
bool append_line(std::string_view path, std::string_view line, unsigned mode = 0600);

/// Creates @p path (one level) with @p mode, or tightens the mode of an existing directory.
bool ensure_dir(std::string_view path, unsigned mode);

[[nodiscard]] std::vector<std::string> list_dir(std::string_view path);

/// Last path component of the symlink target of @p path ("" if not a symlink).
[[nodiscard]] std::string link_target_name(std::string_view path);

bool remove(std::string_view path);

} // namespace hico::fs

namespace hico::str {

[[nodiscard]] std::string trim(std::string_view s);
[[nodiscard]] std::vector<std::string> split(std::string_view s, char sep);
[[nodiscard]] bool icontains(std::string_view haystack, std::string_view needle);
[[nodiscard]] std::optional<long long> to_int(std::string_view s);

} // namespace hico::str
