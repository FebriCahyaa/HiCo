/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

// ─────────────────────────────────────────────────────────────────────────────
// PLACEHOLDER DEV/TEST KEY — regenerate before the first real release.
//
//   1. Build the host tools:  cmake -B build && cmake --build build --target hico_sign
//   2. Generate a real keypair, offline, once:  build/hico_sign genkey priv.hex pub.hex
//   3. Paste priv.hex's contents into pub.hex below (HICO_INTEGRITY_PUBLIC_KEY_HEX)... no —
//      paste PUB.hex here, and keep priv.hex OUT of this repository. Store it as a GitHub
//      Actions encrypted secret (or an offline password manager) and pass it to
//      tools/sign_release.py only at release time. If the private key is ever committed or
//      leaked, every signature it ever made must be treated as compromised: generate a new
//      pair, update this file, and every future release re-signs with the new key (older
//      releases stay verifiable only against the old one, which is now untrusted).
//
// This key is PUBLIC by design (that is the point of asymmetric signing): shipping it in the
// binary is safe. What must never ship, and never be committed, is the matching private key.
//
// This placeholder's seed is the fixed, non-secret byte sequence {7, 8, 9, ..., 38} — reproduced
// in tests/integrity_test.cpp so the test suite can sign manifests the way a real release would,
// without a real private key ever existing in this repository. A real release key must come from
// hico_sign genkey (OS randomness), never a fixed seed like this one.
// ─────────────────────────────────────────────────────────────────────────────
#define HICO_INTEGRITY_PUBLIC_KEY_HEX "00d05a1d1ea251396d557afbd4588b3c6d99dbeb972fed10a32562ea26dcdcfa"
