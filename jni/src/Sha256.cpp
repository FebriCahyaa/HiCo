/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Sha256.hpp"

// sha256.h (unlike the vendored ed25519.h) has no extern "C" guard of its own: without this,
// a C++ translation unit would declare these with C++ (mangled) linkage while sha256.c — compiled
// as plain C — defines them with C linkage, and the two would never link.
extern "C" {
#include "vendor/sha256/sha256.h"
}

#include <array>
#include <cstdio>

namespace hico::sha256 {

namespace {
constexpr char kHexDigits[] = "0123456789abcdef";
// A file this large is not something HiCo's integrity manifest ever lists (the biggest entry is
// the hicod binary itself, a few MB); refuse to stream past this so a symlink loop or an odd
// device node cannot make a periodic self-check hang.
constexpr long kMaxHashBytes = 64 * 1024 * 1024;
} // namespace

Digest hash(std::string_view data) {
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, reinterpret_cast<const BYTE *>(data.data()), data.size());
    Digest out{};
    sha256_final(&ctx, out.data());
    return out;
}

std::optional<Digest> hash_file(std::string_view path) {
    FILE *f = std::fopen(std::string(path).c_str(), "rb");
    if (!f) return std::nullopt;

    SHA256_CTX ctx;
    sha256_init(&ctx);
    std::array<unsigned char, 64 * 1024> buf{};
    long total = 0;
    size_t n;
    while ((n = std::fread(buf.data(), 1, buf.size(), f)) > 0) {
        total += static_cast<long>(n);
        if (total > kMaxHashBytes) {
            std::fclose(f);
            return std::nullopt;
        }
        sha256_update(&ctx, buf.data(), n);
    }
    const bool ok = std::feof(f) && !std::ferror(f);
    std::fclose(f);
    if (!ok) return std::nullopt;

    Digest out{};
    sha256_final(&ctx, out.data());
    return out;
}

std::string to_hex(const Digest &digest) {
    std::string out(kDigestBytes * 2, '0');
    for (size_t i = 0; i < kDigestBytes; ++i) {
        out[i * 2] = kHexDigits[digest[i] >> 4];
        out[i * 2 + 1] = kHexDigits[digest[i] & 0xF];
    }
    return out;
}

std::optional<Digest> from_hex(std::string_view hex) {
    if (hex.size() != kDigestBytes * 2) return std::nullopt;
    Digest out{};
    for (size_t i = 0; i < kDigestBytes; ++i) {
        int byte = 0;
        for (int j = 0; j < 2; ++j) {
            const char c = hex[i * 2 + j];
            int v;
            if (c >= '0' && c <= '9') v = c - '0';
            else if (c >= 'a' && c <= 'f') v = c - 'a' + 10;
            else if (c >= 'A' && c <= 'F') v = c - 'A' + 10;
            else return std::nullopt;
            byte = (byte << 4) | v;
        }
        out[i] = static_cast<unsigned char>(byte);
    }
    return out;
}

} // namespace hico::sha256
