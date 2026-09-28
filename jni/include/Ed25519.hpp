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

namespace hico::ed25519 {

inline constexpr size_t kSeedBytes = 32;
inline constexpr size_t kPublicKeyBytes = 32;
inline constexpr size_t kPrivateKeyBytes = 64; // seed + public key, as the vendored library packs it
inline constexpr size_t kSignatureBytes = 64;

using Seed = std::array<unsigned char, kSeedBytes>;
using PublicKey = std::array<unsigned char, kPublicKeyBytes>;
using PrivateKey = std::array<unsigned char, kPrivateKeyBytes>;
using Signature = std::array<unsigned char, kSignatureBytes>;

/// Deterministic keypair from a 32-byte seed (host tooling only: `hico_sign genkey`).
struct KeyPair {
    PublicKey public_key{};
    PrivateKey private_key{};
};
[[nodiscard]] KeyPair keypair_from_seed(const Seed &seed);

/// OS-random 32-byte seed (getrandom / /dev/urandom). Host tooling only.
[[nodiscard]] Seed random_seed();

/// Signs @p message (host tooling only: never on device, the private key never ships).
[[nodiscard]] Signature sign(std::string_view message, const PublicKey &pub, const PrivateKey &priv);

/// Verifies @p signature over @p message against @p pub. This is the only one of these
/// functions `hicod` calls on device.
[[nodiscard]] bool verify(const Signature &signature, std::string_view message, const PublicKey &pub);

/// Parses a lowercase hex string into a fixed-size byte array; nullopt on bad length/hex.
template <size_t N>
[[nodiscard]] std::optional<std::array<unsigned char, N>> from_hex(std::string_view hex);

/// Lowercase hex encoding of a fixed-size byte array.
template <size_t N>
[[nodiscard]] std::string to_hex(const std::array<unsigned char, N> &bytes);

extern template std::optional<PublicKey> from_hex<kPublicKeyBytes>(std::string_view);
extern template std::optional<PrivateKey> from_hex<kPrivateKeyBytes>(std::string_view);
extern template std::optional<Signature> from_hex<kSignatureBytes>(std::string_view);
extern template std::optional<Seed> from_hex<kSeedBytes>(std::string_view);
extern template std::string to_hex<kPublicKeyBytes>(const PublicKey &);
extern template std::string to_hex<kPrivateKeyBytes>(const PrivateKey &);
extern template std::string to_hex<kSignatureBytes>(const Signature &);
extern template std::string to_hex<kSeedBytes>(const Seed &);

} // namespace hico::ed25519
