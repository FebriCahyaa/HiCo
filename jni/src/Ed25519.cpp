/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Ed25519.hpp"

#include "vendor/ed25519/ed25519.h"

namespace hico::ed25519 {

KeyPair keypair_from_seed(const Seed &seed) {
    KeyPair kp;
    ed25519_create_keypair(kp.public_key.data(), kp.private_key.data(), seed.data());
    return kp;
}

Seed random_seed() {
    Seed seed{};
    ed25519_create_seed(seed.data());
    return seed;
}

Signature sign(std::string_view message, const PublicKey &pub, const PrivateKey &priv) {
    Signature sig{};
    ed25519_sign(sig.data(), reinterpret_cast<const unsigned char *>(message.data()), message.size(), pub.data(),
                priv.data());
    return sig;
}

bool verify(const Signature &signature, std::string_view message, const PublicKey &pub) {
    return ed25519_verify(signature.data(), reinterpret_cast<const unsigned char *>(message.data()), message.size(),
                          pub.data()) != 0;
}

namespace {
constexpr char kHexDigits[] = "0123456789abcdef";
}

template <size_t N>
std::optional<std::array<unsigned char, N>> from_hex(std::string_view hex) {
    if (hex.size() != N * 2) return std::nullopt;
    std::array<unsigned char, N> out{};
    for (size_t i = 0; i < N; ++i) {
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

template <size_t N>
std::string to_hex(const std::array<unsigned char, N> &bytes) {
    std::string out(N * 2, '0');
    for (size_t i = 0; i < N; ++i) {
        out[i * 2] = kHexDigits[bytes[i] >> 4];
        out[i * 2 + 1] = kHexDigits[bytes[i] & 0xF];
    }
    return out;
}

// PublicKey/Seed share N=32 and PrivateKey/Signature share N=64: one instantiation covers both
// aliases (extern template in the header just needs a matching definition to link against).
template std::optional<std::array<unsigned char, kPublicKeyBytes>> from_hex<kPublicKeyBytes>(std::string_view);
template std::optional<std::array<unsigned char, kPrivateKeyBytes>> from_hex<kPrivateKeyBytes>(std::string_view);
template std::string to_hex<kPublicKeyBytes>(const std::array<unsigned char, kPublicKeyBytes> &);
template std::string to_hex<kPrivateKeyBytes>(const std::array<unsigned char, kPrivateKeyBytes> &);

} // namespace hico::ed25519
