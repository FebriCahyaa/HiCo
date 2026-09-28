/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <array>
#include <optional>
#include <string>
#include <string_view>

namespace hico::sha256 {

inline constexpr size_t kDigestBytes = 32;
using Digest = std::array<unsigned char, kDigestBytes>;

/// SHA-256 of @p data.
[[nodiscard]] Digest hash(std::string_view data);

/// SHA-256 of a file's contents; nullopt when it cannot be read (missing, no permission, a
/// directory). Streams the file rather than loading it whole, so it is safe on large files.
[[nodiscard]] std::optional<Digest> hash_file(std::string_view path);

/// Lowercase hex encoding, and the reverse (nullopt on bad length/hex — same convention as
/// hico::ed25519::from_hex/to_hex).
[[nodiscard]] std::string to_hex(const Digest &digest);
[[nodiscard]] std::optional<Digest> from_hex(std::string_view hex);

} // namespace hico::sha256
