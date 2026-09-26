/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "MiCrypt.hpp"

#include <algorithm>
#include <array>
#include <cstdint>

namespace hico::micrypt {

namespace {

using Block = std::array<std::uint8_t, 16>;
using RoundKeys = std::array<std::uint8_t, 176>; // 11 round keys (AES-128)

constexpr std::string_view kMiKey = "thermalopenssl.h";

// FIPS-197 S-box and its inverse, computed once from the GF(2^8) definition.
struct Tables {
    std::array<std::uint8_t, 256> sbox{};
    std::array<std::uint8_t, 256> inv{};
    Tables() {
        std::uint8_t p = 1, q = 1;
        do {
            // p runs through the multiplicative group (x3), q through its inverses (/3).
            p = static_cast<std::uint8_t>(p ^ (p << 1) ^ ((p & 0x80) ? 0x1B : 0));
            q = static_cast<std::uint8_t>(q ^ (q << 1));
            q = static_cast<std::uint8_t>(q ^ (q << 2));
            q = static_cast<std::uint8_t>(q ^ (q << 4));
            if (q & 0x80) q ^= 0x09;
            const auto rotl = [](std::uint8_t x, int s) { return static_cast<std::uint8_t>((x << s) | (x >> (8 - s))); };
            const std::uint8_t x = static_cast<std::uint8_t>(q ^ rotl(q, 1) ^ rotl(q, 2) ^ rotl(q, 3) ^ rotl(q, 4) ^ 0x63);
            sbox[p] = x;
        } while (p != 1);
        sbox[0] = 0x63;
        for (int i = 0; i < 256; ++i) inv[sbox[i]] = static_cast<std::uint8_t>(i);
    }
};

const Tables &tables() {
    static const Tables t;
    return t;
}

std::uint8_t xtime(std::uint8_t x) {
    return static_cast<std::uint8_t>((x << 1) ^ ((x & 0x80) ? 0x1B : 0));
}

std::uint8_t mul(std::uint8_t a, std::uint8_t b) {
    std::uint8_t r = 0;
    while (b) {
        if (b & 1) r ^= a;
        a = xtime(a);
        b >>= 1;
    }
    return r;
}

RoundKeys expand_key(std::string_view key) {
    const auto &t = tables();
    RoundKeys w{};
    std::copy_n(reinterpret_cast<const std::uint8_t *>(key.data()), 16, w.begin());
    std::uint8_t rcon = 1;
    for (size_t i = 16; i < w.size(); i += 4) {
        std::array<std::uint8_t, 4> tmp{w[i - 4], w[i - 3], w[i - 2], w[i - 1]};
        if (i % 16 == 0) {
            tmp = {static_cast<std::uint8_t>(t.sbox[tmp[1]] ^ rcon), t.sbox[tmp[2]], t.sbox[tmp[3]], t.sbox[tmp[0]]};
            rcon = xtime(rcon);
        }
        for (size_t j = 0; j < 4; ++j) w[i + j] = static_cast<std::uint8_t>(w[i + j - 16] ^ tmp[j]);
    }
    return w;
}

void add_round_key(Block &s, const RoundKeys &w, int round) {
    for (size_t i = 0; i < 16; ++i) s[i] ^= w[static_cast<size_t>(round) * 16 + i];
}

// State is column-major: byte (row r, column c) at s[c * 4 + r].
void shift_rows(Block &s, bool inverse) {
    Block o = s;
    for (int r = 1; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            const int from = inverse ? (c - r + 4) % 4 : (c + r) % 4;
            s[static_cast<size_t>(c * 4 + r)] = o[static_cast<size_t>(from * 4 + r)];
        }
    }
}

void mix_columns(Block &s, bool inverse) {
    static constexpr std::uint8_t kFwd[4] = {2, 3, 1, 1};
    static constexpr std::uint8_t kInv[4] = {14, 11, 13, 9};
    const auto *m = inverse ? kInv : kFwd;
    for (size_t c = 0; c < 4; ++c) {
        const std::uint8_t *col = &s[c * 4];
        std::array<std::uint8_t, 4> out{};
        for (size_t r = 0; r < 4; ++r) {
            out[r] = static_cast<std::uint8_t>(mul(col[0], m[(4 - r) % 4]) ^ mul(col[1], m[(5 - r) % 4]) ^
                                               mul(col[2], m[(6 - r) % 4]) ^ mul(col[3], m[(7 - r) % 4]));
        }
        std::copy(out.begin(), out.end(), &s[c * 4]);
    }
}

void encrypt_block(Block &s, const RoundKeys &w) {
    const auto &t = tables();
    add_round_key(s, w, 0);
    for (int round = 1; round <= 10; ++round) {
        for (auto &b : s) b = t.sbox[b];
        shift_rows(s, false);
        if (round != 10) mix_columns(s, false);
        add_round_key(s, w, round);
    }
}

void decrypt_block(Block &s, const RoundKeys &w) {
    const auto &t = tables();
    add_round_key(s, w, 10);
    for (int round = 9; round >= 0; --round) {
        shift_rows(s, true);
        for (auto &b : s) b = t.inv[b];
        add_round_key(s, w, round);
        if (round != 0) mix_columns(s, true);
    }
}

Block to_block(std::string_view s, size_t off) {
    Block b{};
    std::copy_n(reinterpret_cast<const std::uint8_t *>(s.data()) + off, 16, b.begin());
    return b;
}

bool looks_like_text(std::string_view s) {
    if (s.empty()) return false;
    const auto binary = std::count_if(s.begin(), s.end(), [](char c) {
        const auto u = static_cast<unsigned char>(c);
        return u < 9 || (u > 13 && u < 32) || u == 127;
    });
    return binary == 0;
}

} // namespace

std::string cbc_encrypt(std::string_view data, std::string_view key, std::string_view iv) {
    const RoundKeys w = expand_key(key);
    const size_t pad = 16 - data.size() % 16;
    std::string in(data);
    in.append(pad, static_cast<char>(pad));

    std::string out;
    out.reserve(in.size());
    Block prev = to_block(iv, 0);
    for (size_t off = 0; off < in.size(); off += 16) {
        Block b = to_block(in, off);
        for (size_t i = 0; i < 16; ++i) b[i] ^= prev[i];
        encrypt_block(b, w);
        out.append(reinterpret_cast<const char *>(b.data()), 16);
        prev = b;
    }
    return out;
}

std::optional<std::string> cbc_decrypt(std::string_view data, std::string_view key, std::string_view iv) {
    if (data.empty() || data.size() % 16 != 0) return std::nullopt;
    const RoundKeys w = expand_key(key);
    std::string out;
    out.reserve(data.size());
    Block prev = to_block(iv, 0);
    for (size_t off = 0; off < data.size(); off += 16) {
        const Block cipher = to_block(data, off);
        Block b = cipher;
        decrypt_block(b, w);
        for (size_t i = 0; i < 16; ++i) b[i] ^= prev[i];
        out.append(reinterpret_cast<const char *>(b.data()), 16);
        prev = cipher;
    }
    // PKCS#7: 1..16 bytes, all equal to the count.
    const size_t pad = static_cast<unsigned char>(out.back());
    if (pad == 0 || pad > 16) return std::nullopt;
    // data.size() is a non-zero multiple of 16, so len >= 0. Copying the prefix
    // (rather than resize) keeps GCC 13 -O2 from a false -Wrestrict on the shrink.
    const size_t len = data.size() - pad;
    for (size_t i = len; i < data.size(); ++i) {
        if (static_cast<unsigned char>(out[i]) != pad) return std::nullopt;
    }
    return std::string(out.data(), len);
}

std::optional<std::string> decrypt(std::string_view data) {
    auto plain = cbc_decrypt(data, kMiKey, kMiKey);
    if (!plain || !looks_like_text(*plain)) return std::nullopt;
    return plain;
}

std::string encrypt(std::string_view text) {
    return cbc_encrypt(text, kMiKey, kMiKey);
}

} // namespace hico::micrypt
