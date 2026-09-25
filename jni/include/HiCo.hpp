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

#pragma once

#ifndef HICO_VERSION
#define HICO_VERSION "dev"
#endif

#define HICO_NAME "HiCo Thermal"
#define HICO_TAG "HiCoThermal"

// ── HiCo ─────────────────────────────────────────────────────────────────────
// Persistent data (survives reboots) lives next to Flux's config directory.
#define HICO_CONFIG_DIR "/data/adb/.config/hico"
#define HICO_CONFIG_FILE HICO_CONFIG_DIR "/hico.conf"
#define HICO_LOG_FILE HICO_CONFIG_DIR "/hico.log"
#define HICO_SESSIONS_FILE HICO_CONFIG_DIR "/sessions"

// Runtime data lives on tmpfs: it describes this boot only, so a reboot always
// starts from the stock thermal state, and nothing is written to flash while gaming.
#define HICO_RUNTIME_DIR "/dev/hico"
#define HICO_STATE_FILE HICO_RUNTIME_DIR "/state"
#define HICO_JOURNAL_FILE HICO_RUNTIME_DIR "/journal"
#define HICO_LOCK_FILE HICO_RUNTIME_DIR "/hicod.lock"

#define HICO_MODULE_DIR "/data/adb/modules/hico"
#define HICO_MODULE_PROP HICO_MODULE_DIR "/module.prop"

// ── Flux (required) ──────────────────────────────────────────────────────────
// HiCo does not detect games itself: fluxd already does it (game list, focus,
// PID tracking, screen state), and publishes the result in these files.
#define FLUX_MODULE_DIR "/data/adb/modules/flux"
#define FLUX_MODULE_PROP FLUX_MODULE_DIR "/module.prop"
#define FLUX_BINARY FLUX_MODULE_DIR "/system/bin/fluxd"
#define FLUX_CONFIG_DIR "/data/adb/.config/flux"
#define FLUX_LOCK_FILE FLUX_CONFIG_DIR "/.lock"
#define FLUX_PROFILE_FILE FLUX_CONFIG_DIR "/current_profile"
#define FLUX_GAMEINFO_FILE FLUX_CONFIG_DIR "/gameinfo"

/// Oldest Flux build HiCo supports (v1.2.0, native monitor). Keep in sync with
/// FLUX_MIN_VERSION_CODE in module/customize.sh.
#define FLUX_MIN_VERSION_CODE 46

namespace hico {

/// Mirrors FluxProfileMode in Flux's jni/include/Flux.hpp (written as an integer).
enum class FluxProfile : int {
    Unknown = -1,
    PerfCommon = 0,
    Performance = 1,
    PerformanceLite = 2,
    Balance = 3,
    Powersave = 4,
};

} // namespace hico
