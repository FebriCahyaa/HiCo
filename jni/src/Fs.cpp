/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#include "Fs.hpp"

#include <algorithm>
#include <cctype>
#include <cerrno>
#include <charconv>
#include <cstdlib>

#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef __ANDROID__
#include <sys/mount.h>
#include <sys/xattr.h>
#endif

namespace hico::fs {

namespace {

const std::string &root() {
#ifdef __ANDROID__
    static const std::string r;
#else
    static const std::string r = [] {
        const char *env = std::getenv("HICO_ROOT");
        return std::string(env ? env : "");
    }();
#endif
    return r;
}

bool write_all(int fd, std::string_view data) {
    while (!data.empty()) {
        const ssize_t n = ::write(fd, data.data(), data.size());
        if (n < 0) {
            if (errno == EINTR) continue;
            return false;
        }
        data.remove_prefix(static_cast<size_t>(n));
    }
    return true;
}

} // namespace

std::string real(std::string_view path) {
    std::string out = root();
    out += path;
    return out;
}

bool exists(std::string_view path) {
    return ::access(real(path).c_str(), F_OK) == 0;
}

bool is_dir(std::string_view path) {
    struct stat st{};
    return ::stat(real(path).c_str(), &st) == 0 && S_ISDIR(st.st_mode);
}

std::optional<std::string> read(std::string_view path, size_t max_bytes) {
    const int fd = ::open(real(path).c_str(), O_RDONLY | O_CLOEXEC);
    if (fd < 0) return std::nullopt;

    std::string buf(max_bytes, '\0');
    size_t total = 0;
    while (total < max_bytes) {
        const ssize_t n = ::read(fd, buf.data() + total, max_bytes - total);
        if (n < 0) {
            if (errno == EINTR) continue;
            ::close(fd);
            return std::nullopt;
        }
        if (n == 0) break;
        total += static_cast<size_t>(n);
    }
    ::close(fd);

    buf.resize(total);
    while (!buf.empty() && std::isspace(static_cast<unsigned char>(buf.back()))) buf.pop_back();
    return buf;
}

std::optional<long long> read_int(std::string_view path) {
    const auto s = read(path, 64);
    if (!s) return std::nullopt;
    return str::to_int(*s);
}

bool is_kernel_node(std::string_view path) {
    if (!path.starts_with("/sys/") && !path.starts_with("/proc/")) return false;
    return path.find("/../") == std::string_view::npos && !path.ends_with("/..");
}

bool write_node(std::string_view path, std::string_view value) {
    if (!is_kernel_node(path)) return false;

    const std::string p = real(path);
    int fd = ::open(p.c_str(), O_WRONLY | O_CLOEXEC | O_NOFOLLOW | O_TRUNC);
    if (fd < 0 && errno == EACCES) {
        // Flux's profiler and some vendor daemons chmod 444 the nodes they own.
        ::chmod(p.c_str(), 0644);
        fd = ::open(p.c_str(), O_WRONLY | O_CLOEXEC | O_NOFOLLOW | O_TRUNC);
    }
    if (fd < 0) return false;

    const bool ok = write_all(fd, value);
    ::close(fd);
    return ok;
}

bool write_atomic(std::string_view path, std::string_view content, unsigned mode) {
    const std::string p = real(path);
    const std::string tmp = p + ".tmp." + std::to_string(::getpid());

    ::unlink(tmp.c_str());
    const int fd = ::open(tmp.c_str(), O_WRONLY | O_CREAT | O_EXCL | O_NOFOLLOW | O_CLOEXEC, mode);
    if (fd < 0) return false;

    const bool ok = write_all(fd, content) && ::fsync(fd) == 0;
    ::close(fd);
    if (!ok || ::rename(tmp.c_str(), p.c_str()) != 0) {
        ::unlink(tmp.c_str());
        return false;
    }
    return true;
}

bool append_line(std::string_view path, std::string_view line, unsigned mode) {
    const int fd = ::open(real(path).c_str(), O_WRONLY | O_CREAT | O_APPEND | O_NOFOLLOW | O_CLOEXEC, mode);
    if (fd < 0) return false;
    std::string buf(line);
    buf.push_back('\n');
    const bool ok = write_all(fd, buf);
    ::close(fd);
    return ok;
}

bool ensure_dir(std::string_view path, unsigned mode) {
    const std::string p = real(path);
    if (::mkdir(p.c_str(), mode) == 0) return true;
    if (errno != EEXIST) return false;

    struct stat st{};
    if (::lstat(p.c_str(), &st) != 0 || !S_ISDIR(st.st_mode)) return false; // refuse symlinks
    return ::chmod(p.c_str(), mode) == 0;
}

std::vector<std::string> list_dir(std::string_view path) {
    std::vector<std::string> out;
    DIR *dir = ::opendir(real(path).c_str());
    if (!dir) return out;
    while (const dirent *e = ::readdir(dir)) {
        const std::string_view name = e->d_name;
        if (name == "." || name == "..") continue;
        out.emplace_back(name);
    }
    ::closedir(dir);
    std::sort(out.begin(), out.end());
    return out;
}

std::string link_target_name(std::string_view path) {
    char buf[512];
    const ssize_t n = ::readlink(real(path).c_str(), buf, sizeof(buf) - 1);
    if (n <= 0) return {};
    const std::string_view target(buf, static_cast<size_t>(n));
    const size_t slash = target.rfind('/');
    return std::string(slash == std::string_view::npos ? target : target.substr(slash + 1));
}

std::optional<std::string> read_raw(std::string_view path, size_t max_bytes) {
    const int fd = ::open(real(path).c_str(), O_RDONLY | O_CLOEXEC);
    if (fd < 0) return std::nullopt;
    std::string out;
    char buf[8192];
    ssize_t n;
    while ((n = ::read(fd, buf, sizeof(buf))) > 0) {
        out.append(buf, static_cast<size_t>(n));
        if (out.size() > max_bytes) {
            ::close(fd);
            return std::nullopt;
        }
    }
    ::close(fd);
    if (n < 0) return std::nullopt;
    return out;
}

#ifdef __ANDROID__

bool bind_mount(std::string_view source, std::string_view target) {
    const std::string src(source), dst(target);
    char label[256];
    const ssize_t len = ::lgetxattr(dst.c_str(), "security.selinux", label, sizeof(label));
    if (len <= 0 || ::lsetxattr(src.c_str(), "security.selinux", label, static_cast<size_t>(len), 0) != 0) return false;
    return ::mount(src.c_str(), dst.c_str(), nullptr, MS_BIND, nullptr) == 0;
}

bool unmount(std::string_view target) {
    return ::umount2(std::string(target).c_str(), MNT_DETACH) == 0 || errno == EINVAL;
}

bool is_mounted(std::string_view target) {
    const auto info = read_raw("/proc/self/mountinfo", 4 * 1024 * 1024);
    if (!info) return false;
    for (const auto &line : str::split(*info, '\n')) {
        const auto fields = str::split(line, ' ');
        if (fields.size() > 4 && fields[4] == target) return true;
    }
    return false;
}

#else // Host emulation: record the mounts, never touch the real mount table.

namespace {
constexpr std::string_view kMounts = "/__mounts__";
std::vector<std::string> mounts() {
    return str::split(read(kMounts, 1 << 20).value_or(""), '\n');
}
bool save_mounts(const std::vector<std::string> &list) {
    std::string out;
    for (const auto &m : list) out += m + '\n';
    return write_atomic(kMounts, out, 0644);
}
} // namespace

bool bind_mount(std::string_view source, std::string_view target) {
    if (!exists(source) || !exists(target)) return false;
    auto list = mounts();
    list.push_back(std::string(target) + " <- " + std::string(source));
    return save_mounts(list);
}

bool unmount(std::string_view target) {
    auto list = mounts();
    std::erase_if(list, [target](const std::string &m) { return m.starts_with(std::string(target) + " <- "); });
    return save_mounts(list);
}

bool is_mounted(std::string_view target) {
    const auto list = mounts();
    return std::any_of(list.begin(), list.end(), [target](const std::string &m) { return m.starts_with(std::string(target) + " <- "); });
}

#endif

bool remove(std::string_view path) {
    return ::unlink(real(path).c_str()) == 0 || errno == ENOENT;
}

} // namespace hico::fs

namespace hico::str {

std::string trim(std::string_view s) {
    while (!s.empty() && std::isspace(static_cast<unsigned char>(s.front()))) s.remove_prefix(1);
    while (!s.empty() && std::isspace(static_cast<unsigned char>(s.back()))) s.remove_suffix(1);
    return std::string(s);
}

std::vector<std::string> split(std::string_view s, char sep) {
    std::vector<std::string> out;
    size_t start = 0;
    while (start <= s.size()) {
        const size_t end = s.find(sep, start);
        const auto part = trim(s.substr(start, end == std::string_view::npos ? std::string_view::npos : end - start));
        if (!part.empty()) out.push_back(part);
        if (end == std::string_view::npos) break;
        start = end + 1;
    }
    return out;
}

bool icontains(std::string_view haystack, std::string_view needle) {
    const auto it = std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end(), [](char a, char b) {
        return std::tolower(static_cast<unsigned char>(a)) == std::tolower(static_cast<unsigned char>(b));
    });
    return it != haystack.end();
}

std::optional<long long> to_int(std::string_view s) {
    const std::string t = trim(s);
    long long v = 0;
    const char *begin = t.data();
    const char *end = t.data() + t.size();
    if (begin != end && *begin == '+') ++begin;
    const auto [ptr, ec] = std::from_chars(begin, end, v);
    if (ec != std::errc{} || ptr != end || begin == end) return std::nullopt;
    return v;
}

} // namespace hico::str
