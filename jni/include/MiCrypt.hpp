/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace hico::micrypt {

/**
 * Xiaomi mi_thermald config encryption.
 *
 * Recent Xiaomi firmware ships its thermal-*.conf files encrypted and
 * mi_thermald only loads encrypted files. The format is AES-128-CBC with
 * PKCS#7 padding, key and IV both the 16 ASCII bytes "thermalopenssl.h"
 * (documented by the mi-thermal-crypt project; this is an independent
 * implementation of FIPS-197 AES, no code taken from it).
 */

/// Plain text of an encrypted config, or nullopt when @p data is not one
/// (wrong size, bad padding, or the result is not text).
[[nodiscard]] std::optional<std::string> decrypt(std::string_view data);

/// Encrypted form of @p text, as mi_thermald expects it.
[[nodiscard]] std::string encrypt(std::string_view text);

/// Raw AES-128-CBC with PKCS#7 (tests): @p key and @p iv are 16 bytes.
[[nodiscard]] std::string cbc_encrypt(std::string_view data, std::string_view key, std::string_view iv);
[[nodiscard]] std::optional<std::string> cbc_decrypt(std::string_view data, std::string_view key, std::string_view iv);

} // namespace hico::micrypt
