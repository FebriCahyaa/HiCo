/*
 * Copyright (C) 2026 FebriCahyaa
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Props.hpp"

#include "Fs.hpp"

#ifdef __ANDROID__
#include <sys/system_properties.h>
#else
#include <sys/stat.h>
#endif

namespace hico::props {

#ifdef __ANDROID__

std::string get(std::string_view name, std::string_view fallback) {
    const std::string key(name);
    const prop_info *pi = __system_property_find(key.c_str());
    if (!pi) return std::string(fallback);

    std::string out;
    __system_property_read_callback(
        pi,
        [](void *cookie, const char *, const char *value, uint32_t) { *static_cast<std::string *>(cookie) = value; },
        &out);
    return out.empty() ? std::string(fallback) : out;
}

bool set(std::string_view name, std::string_view value) {
    return __system_property_set(std::string(name).c_str(), std::string(value).c_str()) == 0;
}

void for_each(std::string_view prefix, const std::function<void(std::string_view, std::string_view)> &fn) {
    struct Ctx {
        std::string_view prefix;
        const std::function<void(std::string_view, std::string_view)> *fn;
    } ctx{prefix, &fn};

    __system_property_foreach(
        [](const prop_info *pi, void *cookie) {
            __system_property_read_callback(
                pi,
                [](void *c, const char *name, const char *value, uint32_t) {
                    const auto *ctx = static_cast<Ctx *>(c);
                    if (std::string_view(name).starts_with(ctx->prefix)) (*ctx->fn)(name, value);
                },
                cookie);
        },
        &ctx);
}

#else // Host emulation for tests

namespace {
std::string prop_path(std::string_view name) {
    return "/__props__/" + std::string(name);
}
} // namespace

std::string get(std::string_view name, std::string_view fallback) {
    const auto v = fs::read(prop_path(name));
    return v && !v->empty() ? *v : std::string(fallback);
}

bool set(std::string_view name, std::string_view value) {
    ::mkdir(fs::real("/__props__").c_str(), 0755);
    // Emulate init: ctl.stop / ctl.start change the service state property.
    if (name == "ctl.stop" || name == "ctl.start") {
        const std::string svc = "init.svc." + std::string(value);
        fs::append_line("/__props__/__ctl_log__", std::string(name) + " " + std::string(value));
        return fs::write_atomic(prop_path(svc), name == "ctl.stop" ? "stopped" : "running", 0644);
    }
    return fs::write_atomic(prop_path(name), value, 0644);
}

void for_each(std::string_view prefix, const std::function<void(std::string_view, std::string_view)> &fn) {
    for (const auto &name : fs::list_dir("/__props__")) {
        if (!name.starts_with(prefix) || name.find(".tmp.") != std::string::npos) continue;
        fn(name, get(name));
    }
}

#endif

} // namespace hico::props
