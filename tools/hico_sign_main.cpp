/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

// hico_sign: the offline signing tool for HiCo's integrity manifests
// (jni/include/Integrity.hpp). Host-only — this is never built for Android and never ships in
// the module. See docs/INTEGRITY.md for the full release-signing workflow.
//
//   hico_sign genkey <priv_out> <pub_out>
//       Generates a fresh keypair from OS randomness. <priv_out> is written 0600 and must never
//       be committed to the repository; keep it as a release secret (a GitHub Actions encrypted
//       secret, a password manager, ...). <pub_out> is safe to publish — its content is exactly
//       what goes into jni/include/IntegrityKey.hpp's HICO_INTEGRITY_PUBLIC_KEY_HEX.
//
//   hico_sign sign <message_file> <priv_hex_file> <pub_hex_file>
//       Signs the exact bytes of <message_file> with the private key in <priv_hex_file> (as
//       written by genkey). Needs the matching public key too — the vendored library's 64-byte
//       "private key" is the seed's SHA-512 expansion, not [seed|pubkey], so there is no way to
//       recover the public key from it; pass genkey's own pub_out here. Prints the 128-hex-char
//       signature to stdout, nothing else.
//
//   hico_sign verify <message_file> <sig_hex> <pub_hex_file>
//       Verifies; prints "ok" and exits 0, or prints "FAILED" and exits 1. Not used by hicod
//       itself (that links Ed25519.hpp directly) — for checking a signature by hand or in CI
//       before a release ships.

#include "Ed25519.hpp"

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <sys/stat.h>

using namespace hico::ed25519;

namespace {

std::string read_file(const std::string &path) {
    std::ifstream f(path, std::ios::binary);
    if (!f) throw std::runtime_error("cannot read " + path);
    std::ostringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

std::string read_trimmed(const std::string &path) {
    std::string s = read_file(path);
    while (!s.empty() && (s.back() == '\n' || s.back() == '\r' || s.back() == ' ')) s.pop_back();
    return s;
}

void write_file(const std::string &path, std::string_view content, bool secret) {
    std::ofstream f(path, std::ios::binary | std::ios::trunc);
    if (!f) throw std::runtime_error("cannot write " + path);
    f << content;
    f.close();
    if (secret) ::chmod(path.c_str(), 0600);
}

int cmd_genkey(const std::string &priv_out, const std::string &pub_out) {
    const Seed seed = random_seed();
    const KeyPair kp = keypair_from_seed(seed);
    write_file(priv_out, to_hex(kp.private_key) + "\n", /*secret=*/true);
    write_file(pub_out, to_hex(kp.public_key) + "\n", /*secret=*/false);
    std::fprintf(stderr,
                "New keypair written.\n  private key: %s (0600 — keep this OUT of git, treat it "
                "as a release secret)\n  public key:  %s (safe to publish; paste into "
                "jni/include/IntegrityKey.hpp)\n",
                priv_out.c_str(), pub_out.c_str());
    return 0;
}

int cmd_sign(const std::string &message_file, const std::string &priv_hex_file, const std::string &pub_hex_file) {
    const std::string message = read_file(message_file);
    const auto priv = from_hex<kPrivateKeyBytes>(read_trimmed(priv_hex_file));
    const auto pub = from_hex<kPublicKeyBytes>(read_trimmed(pub_hex_file));
    if (!priv) {
        std::fprintf(stderr, "error: %s is not a %zu-character hex private key\n", priv_hex_file.c_str(),
                     kPrivateKeyBytes * 2);
        return 2;
    }
    if (!pub) {
        std::fprintf(stderr, "error: %s is not a %zu-character hex public key\n", pub_hex_file.c_str(),
                     kPublicKeyBytes * 2);
        return 2;
    }
    const Signature sig = sign(message, *pub, *priv);
    std::puts(to_hex(sig).c_str());
    return 0;
}

int cmd_verify(const std::string &message_file, const std::string &sig_hex, const std::string &pub_hex_file) {
    const std::string message = read_file(message_file);
    const auto sig = from_hex<kSignatureBytes>(sig_hex);
    const auto pub = from_hex<kPublicKeyBytes>(read_trimmed(pub_hex_file));
    if (!sig || !pub) {
        std::fprintf(stderr, "error: bad signature or public key hex\n");
        return 2;
    }
    const bool ok = verify(*sig, message, *pub);
    std::puts(ok ? "ok" : "FAILED");
    return ok ? 0 : 1;
}

int usage() {
    std::fputs("Usage:\n"
              "  hico_sign genkey <priv_out> <pub_out>\n"
              "  hico_sign sign <message_file> <priv_hex_file> <pub_hex_file>\n"
              "  hico_sign verify <message_file> <sig_hex> <pub_hex_file>\n",
              stderr);
    return 2;
}

} // namespace

int main(int argc, char **argv) {
    const std::vector<std::string> args(argv + 1, argv + argc);
    try {
        if (args.size() == 3 && args[0] == "genkey") return cmd_genkey(args[1], args[2]);
        if (args.size() == 4 && args[0] == "sign") return cmd_sign(args[1], args[2], args[3]);
        if (args.size() == 4 && args[0] == "verify") return cmd_verify(args[1], args[2], args[3]);
    } catch (const std::exception &e) {
        std::fprintf(stderr, "error: %s\n", e.what());
        return 2;
    }
    return usage();
}
