# Vendored: B-Con/crypto-algorithms sha256.c

Public-domain SHA-256 (FIPS 180-2) by Brad Conte, unmodified.

- Source: https://github.com/B-Con/crypto-algorithms
- License: public domain (see the repository's README.md — no separate LICENSE file upstream)

Verified against the NIST/FIPS 180-2 test vectors ("abc", the empty string,
the two-block message and the 1,000,000×'a' long vector) before vendoring —
all four match exactly.

The upstream README notes this is not hardened against side-channel attacks
and should not be used to hash secrets. That does not apply to how HiCo uses
it: hashing the contents of files that ship in the (public) release, to
detect tampering, never a secret key or password.

Used by HiCo's integrity layer (`jni/include/Sha256.hpp`, `jni/src/Sha256.cpp`)
alongside the vendored Ed25519 (`jni/src/vendor/ed25519/`) to build and verify
signed release manifests.
