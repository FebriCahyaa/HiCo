/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include <chrono>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace hico::integrity {

/**
 * Signed release manifest, produced offline by `hico_sign` (tools/hico_sign_main.cpp) and
 * verified here with the public key compiled into this binary (IntegrityKey.hpp). See
 * docs/INTEGRITY.md for the full design and its limits.
 *
 * Text format (LF-terminated, no trailing whitespace):
 *
 *     schema=hico.integrity-manifest.v1
 *     version=<module version string>
 *     built_at=<ISO 8601 UTC>
 *     file <sha256hex> <path>
 *     file <sha256hex> <path>
 *     ...
 *     signature=<ed25519 signature, 128 lowercase hex chars>
 *
 * `file` lines are sorted by (path, sha256) and a path may repeat: HiCo ships a different
 * `system/bin/hicod` per ABI in the "universal" build, so verification accepts a match against
 * *any* listed hash for a given path rather than requiring exactly one. The signed message is
 * every byte of the file up to (not including) the final `signature=` line — this is a plain
 * byte range, not a JSON canonicalisation, so there is nothing for the two sides (this parser
 * and tools/sign_release.py) to disagree about.
 */
struct ParsedManifest {
    std::string schema;
    std::string version;
    std::string built_at;
    std::vector<std::pair<std::string, std::string>> files; // (path, sha256 hex), as listed
    std::string signature_hex;
    std::string signed_message; // exact bytes that were signed; for verify_manifest_text()
};

/// Splits the raw manifest text into its fields; nullopt on a structurally invalid file (this is
/// a format check only — it does not verify the signature or hash any file).
[[nodiscard]] std::optional<ParsedManifest> parse_manifest(std::string_view text);

enum class Status {
    Ok,
    Missing,        ///< manifest file not present (never shipped, or removed)
    BadFormat,       ///< present but not a well-formed manifest
    BadSignature,    ///< well-formed, but the signature does not verify with the embedded key
    FileMismatch,    ///< signature is valid, but a listed file's on-disk hash matches none of it
    FileMissing,     ///< signature is valid, but a listed file is not present on disk
    Revoked,         ///< signature is valid, but this exact build was later published as compromised
};

[[nodiscard]] std::string_view to_string(Status s);

struct FileResult {
    std::string path;
    Status status; ///< only Ok, FileMismatch or FileMissing
};

struct Report {
    Status status = Status::Missing;
    std::string reason;                ///< human-readable, for logs and hicod status
    std::string manifest_version;
    std::vector<FileResult> files;      ///< only populated once the signature itself verified
    [[nodiscard]] bool ok() const { return status == Status::Ok; }
};

/// Verifies the manifest at @p module_dir + "/integrity.manifest": signature first (against the
/// embedded public key), then every listed file's current SHA-256 under @p module_dir.
[[nodiscard]] Report verify_manifest(std::string_view module_dir);

/**
 * The pull-based revocation list (docs/INTEGRITY.md's "Lapis 4"): a small, public, unsigned text
 * file this repository publishes, that hicod checks itself against every so often. Its only job
 * is to let the author say "this exact, otherwise validly-signed build turned out to be
 * compromised" after the fact — a leaked signing key, a build published by mistake, or a cracked
 * copy some other party is redistributing with its own (still validly self-consistent) manifest.
 * A locally-tampered build is already caught by verify_manifest(); this is for the case
 * verify_manifest() cannot catch: the build itself, signed by the real key, is the problem.
 *
 * Deliberately unsigned: it travels over HTTPS from raw.githubusercontent.com (TLS is the trust
 * boundary, same as every other file this project's tooling already pulls from GitHub) and only
 * this repository's own write access can change it — no different, trust-wise, from update.json,
 * which every root manager already fetches the same way. Fetching it is best-effort and bounded
 * by a hard timeout: it can only make hicod refuse to unlock, never make it hang.
 *
 * Text format (LF-terminated), deliberately the same shape as ParsedManifest's:
 *
 *     schema=hico.revocation.v1
 *     updated_at=<ISO 8601 UTC>
 *     revoked <sha256hex of a system/bin/hicod build>
 *     revoked <sha256hex of another one>
 *     ...
 */
struct RevocationList {
    std::string schema;
    std::string updated_at;
    std::vector<std::string> revoked_hashes;
};

[[nodiscard]] std::optional<RevocationList> parse_revocation_list(std::string_view text);

/// True when @p hicod_sha256 (this build's own system/bin/hicod hash, lowercase hex) is listed.
[[nodiscard]] bool is_revoked(const RevocationList &list, std::string_view hicod_sha256);

/// The URL fetch_revocation_list() reads. A plain, anonymous GET — no device identifier, no
/// query string, nothing a request to this URL could not already tell GitHub on its own.
inline constexpr std::string_view kRevocationListUrl =
    "https://raw.githubusercontent.com/FebriCahyaa/HiCo/main/docs/integrity/revoked.txt";

/// Best-effort fetch of kRevocationListUrl via whichever of curl/wget is present on the device,
/// hard-bounded by @p timeout (enforced by the `timeout` coreutil, which SIGKILLs an overrunning
/// child) so this can never hang the daemon. nullopt on anything short of a full, timely 200
/// response — no tool present, no network, a timeout, a non-200 status — and a caller should
/// always treat that the same as "nothing revoked" (fail-open): this is a kill switch for
/// finding out something is compromised sooner, not a gate that must succeed to run at all.
[[nodiscard]] std::optional<std::string> fetch_revocation_list(std::chrono::seconds timeout = std::chrono::seconds(5));

/// Signals from the currently running process that suggest it is being debugged or hooked.
/// Best-effort: their absence is not proof nothing is attached, only their presence is
/// meaningful (see docs/INTEGRITY.md — this is one signal among several, not a guarantee).
struct RuntimeSignals {
    bool debugger_attached = false;         ///< TracerPid != 0 in /proc/self/status
    std::vector<std::string> hook_libraries; ///< known hook-framework names seen in /proc/self/maps
};
[[nodiscard]] RuntimeSignals runtime_signals();

} // namespace hico::integrity
