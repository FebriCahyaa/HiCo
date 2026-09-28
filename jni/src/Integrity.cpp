/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Integrity.hpp"

#include "Ed25519.hpp"
#include "Fs.hpp"
#include "IntegrityKey.hpp"
#include "Sha256.hpp"

#include <algorithm>
#include <array>
#include <format>
#include <sstream>

#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

namespace hico::integrity {

namespace {

ed25519::PublicKey embedded_public_key() {
    // A malformed compiled-in key is a build-time mistake, not something to guess around at
    // runtime: every signature would silently fail to verify, which is safe (fails closed) but
    // confusing to debug, so this is worth catching loudly in a test rather than here.
    return ed25519::from_hex<ed25519::kPublicKeyBytes>(HICO_INTEGRITY_PUBLIC_KEY_HEX).value_or(ed25519::PublicKey{});
}

} // namespace

std::optional<ParsedManifest> parse_manifest(std::string_view text) {
    std::string_view t = text;
    while (!t.empty() && (t.back() == '\n' || t.back() == '\r')) t.remove_suffix(1);
    if (t.empty()) return std::nullopt;

    const size_t last_nl = t.rfind('\n');
    const std::string_view last_line = last_nl == std::string_view::npos ? t : t.substr(last_nl + 1);
    if (!last_line.starts_with("signature=")) return std::nullopt;
    const std::string_view sig_hex = last_line.substr(std::string_view("signature=").size());
    if (sig_hex.size() != ed25519::kSignatureBytes * 2) return std::nullopt;

    ParsedManifest m;
    m.signature_hex = std::string(sig_hex);
    m.signed_message = std::string(t.substr(0, last_nl == std::string_view::npos ? 0 : last_nl + 1));

    for (const auto &line : str::split(m.signed_message, '\n')) {
        if (line.starts_with("schema=")) {
            m.schema = line.substr(7);
        } else if (line.starts_with("version=")) {
            m.version = line.substr(8);
        } else if (line.starts_with("built_at=")) {
            m.built_at = line.substr(9);
        } else if (line.starts_with("file ")) {
            std::istringstream in{line};
            std::string tag, hash, path;
            in >> tag >> hash >> path;
            if (tag != "file" || hash.size() != sha256::kDigestBytes * 2 || path.empty()) return std::nullopt;
            m.files.emplace_back(std::move(path), std::move(hash));
        } else {
            return std::nullopt; // unknown line: safer to refuse than to silently ignore it
        }
    }
    if (m.schema != "hico.integrity-manifest.v1" || m.files.empty()) return std::nullopt;
    return m;
}

std::string_view to_string(Status s) {
    switch (s) {
    case Status::Ok: return "ok";
    case Status::Missing: return "missing";
    case Status::BadFormat: return "bad-format";
    case Status::BadSignature: return "bad-signature";
    case Status::FileMismatch: return "file-mismatch";
    case Status::FileMissing: return "file-missing";
    case Status::Revoked: return "revoked";
    }
    return "unknown";
}

Report verify_manifest(std::string_view module_dir) {
    Report report;
    const std::string manifest_path = std::string(module_dir) + "/integrity.manifest";
    const auto text = fs::read_raw(manifest_path, 1 << 20);
    if (!text) {
        report.status = Status::Missing;
        report.reason = "no integrity.manifest in the module (older build, or removed)";
        return report;
    }

    const auto parsed = parse_manifest(*text);
    if (!parsed) {
        report.status = Status::BadFormat;
        report.reason = "integrity.manifest is not well-formed";
        return report;
    }
    report.manifest_version = parsed->version;

    const auto sig = ed25519::from_hex<ed25519::kSignatureBytes>(parsed->signature_hex);
    if (!sig || !ed25519::verify(*sig, parsed->signed_message, embedded_public_key())) {
        report.status = Status::BadSignature;
        report.reason = "integrity.manifest signature does not verify: the module was repackaged "
                        "or its integrity manifest was edited";
        return report;
    }

    // Group by path: a path may be listed more than once (one build flavor ships a different
    // system/bin/hicod per ABI), any one matching hash is accepted.
    std::vector<std::string> paths;
    for (const auto &[path, hash] : parsed->files) {
        if (std::find(paths.begin(), paths.end(), path) == paths.end()) paths.push_back(path);
    }

    for (const auto &path : paths) {
        // sha256::hash_file() takes a real filesystem path, unlike fs::read()/read_raw(), which
        // resolve relative to $HICO_ROOT themselves — resolve this one the same way by hand, or
        // every file check here would silently look outside the test/host sandbox.
        const auto digest = sha256::hash_file(fs::real(std::string(module_dir) + "/" + path));
        if (!digest) {
            report.files.push_back({path, Status::FileMissing});
            continue;
        }
        const std::string hex = sha256::to_hex(*digest);
        const bool matches = std::any_of(parsed->files.begin(), parsed->files.end(),
                                        [&](const auto &f) { return f.first == path && f.second == hex; });
        report.files.push_back({path, matches ? Status::Ok : Status::FileMismatch});
    }

    const auto bad = std::find_if(report.files.begin(), report.files.end(),
                                  [](const FileResult &f) { return f.status != Status::Ok; });
    if (bad == report.files.end()) {
        report.status = Status::Ok;
        report.reason = std::format("{} files verified against the signed manifest", report.files.size());
    } else {
        report.status = bad->status;
        report.reason = std::format("{} does not match the signed manifest ({})", bad->path, to_string(bad->status));
    }
    return report;
}

std::optional<RevocationList> parse_revocation_list(std::string_view text) {
    RevocationList list;
    bool saw_schema = false;
    for (const auto &line : str::split(text, '\n')) {
        if (line.starts_with("schema=")) {
            list.schema = line.substr(7);
            saw_schema = true;
        } else if (line.starts_with("updated_at=")) {
            list.updated_at = line.substr(11);
        } else if (line.starts_with("revoked ")) {
            std::string hash = line.substr(8);
            hash = std::string(str::trim(hash));
            if (hash.size() != sha256::kDigestBytes * 2) return std::nullopt;
            list.revoked_hashes.push_back(std::move(hash));
        } else {
            return std::nullopt; // unknown line: refuse rather than silently ignore it
        }
    }
    if (!saw_schema || list.schema != "hico.revocation.v1") return std::nullopt;
    return list;
}

bool is_revoked(const RevocationList &list, std::string_view hicod_sha256) {
    return std::find(list.revoked_hashes.begin(), list.revoked_hashes.end(), hicod_sha256) !=
          list.revoked_hashes.end();
}

namespace {

/// The first of these that exists is used, in order (docs/INTEGRITY.md — this list is
/// intentionally conservative; none of these is guaranteed present on every ROM, and that is
/// fine, see fetch_revocation_list()'s own contract).
constexpr std::array<std::array<const char *, 2>, 3> kFetchCommands{{
    {"/system/bin/curl", "-fsSL"},
    {"/system/bin/wget", "-qO-"},
    {"/system/xbin/wget", "-qO-"},
}};

} // namespace

std::optional<std::string> fetch_revocation_list(std::chrono::seconds timeout) {
    const char *argv0 = nullptr;
    const char *flag = nullptr;
    for (const auto &cmd : kFetchCommands) {
        if (::access(cmd[0], X_OK) == 0) {
            argv0 = cmd[0];
            flag = cmd[1];
            break;
        }
    }
    if (!argv0) return std::nullopt; // no HTTPS client on this device: fail open, try again later

    int pipefd[2];
    if (::pipe(pipefd) != 0) return std::nullopt;

    const pid_t pid = ::fork();
    if (pid < 0) {
        ::close(pipefd[0]);
        ::close(pipefd[1]);
        return std::nullopt;
    }
    if (pid == 0) {
        ::close(pipefd[0]);
        ::dup2(pipefd[1], STDOUT_FILENO);
        const int devnull = ::open("/dev/null", O_WRONLY | O_CLOEXEC);
        if (devnull >= 0) ::dup2(devnull, STDERR_FILENO);
        const std::string url(kRevocationListUrl);
        const char *argv[] = {argv0, flag, url.c_str(), nullptr};
        ::execv(argv0, const_cast<char *const *>(argv));
        _exit(127);
    }
    ::close(pipefd[1]);

    // A hard wall-clock bound, enforced here rather than trusted to an external `timeout`
    // binary that may not exist either: read with a deadline, and kill the child the moment it
    // is exceeded, however far into the response it got.
    std::string out;
    constexpr size_t kMaxBytes = 64 * 1024; // this file is a handful of lines; anything past this is not it
    const auto deadline = std::chrono::steady_clock::now() + timeout;
    bool ok = true;
    while (true) {
        const auto remaining = deadline - std::chrono::steady_clock::now();
        const auto remaining_ms = std::chrono::duration_cast<std::chrono::milliseconds>(remaining).count();
        if (remaining_ms <= 0) {
            ok = false;
            break;
        }
        pollfd pfd{pipefd[0], POLLIN, 0};
        const int pr = ::poll(&pfd, 1, static_cast<int>(remaining_ms));
        if (pr < 0) {
            ok = false;
            break;
        }
        if (pr == 0) {
            ok = false; // timed out
            break;
        }
        char buf[4096];
        const ssize_t n = ::read(pipefd[0], buf, sizeof(buf));
        if (n < 0) {
            ok = false;
            break;
        }
        if (n == 0) break; // child closed its end: done
        out.append(buf, static_cast<size_t>(n));
        if (out.size() > kMaxBytes) {
            ok = false;
            break;
        }
    }
    ::close(pipefd[0]);

    if (!ok) {
        ::kill(pid, SIGKILL); // still running (timed out or read failed): never leave it behind
    }
    int status = 0;
    ::waitpid(pid, &status, 0);
    if (!ok) return std::nullopt;
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) return std::nullopt;
    if (out.empty()) return std::nullopt;
    return out;
}

RuntimeSignals runtime_signals() {
    RuntimeSignals out;

    if (const auto status = fs::read("/proc/self/status", 8192)) {
        for (const auto &line : str::split(*status, '\n')) {
            if (!line.starts_with("TracerPid:")) continue;
            const auto pid = str::to_int(str::trim(line.substr(10)));
            out.debugger_attached = pid.value_or(0) != 0;
            break;
        }
    }

    // Library names that are specific to injection/hooking tools, not merely something a
    // coincidental path might contain — kept short and deliberately conservative: this is
    // informational (see docs/INTEGRITY.md), a false alarm here is worse than a miss.
    static constexpr std::array<std::string_view, 6> kHookMarkers{
        "frida-agent", "frida-gadget", "gum-js-loop", "linjector", "substrated", "FridaGadget",
    };
    if (const auto maps = fs::read("/proc/self/maps", 1 << 20)) {
        for (const auto marker : kHookMarkers) {
            if (str::icontains(*maps, marker) &&
                std::find(out.hook_libraries.begin(), out.hook_libraries.end(), marker) == out.hook_libraries.end()) {
                out.hook_libraries.emplace_back(marker);
            }
        }
    }
    return out;
}

} // namespace hico::integrity
