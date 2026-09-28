/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

#pragma once

#include "Config.hpp"
#include "FluxLink.hpp"
#include "Journal.hpp"
#include "SafetyGuard.hpp"
#include "Sessions.hpp"
#include "ThermalController.hpp"
#include "ThermalZones.hpp"

#include <chrono>
#include <optional>
#include <string>
#include <string_view>

namespace hico {

enum class State {
    Idle,      ///< stock thermal (no game)
    Boost,     ///< game running, thermal throttling disabled (level max)
    Relaxed,   ///< game or whitelisted app, vendor thermal running with relaxed configs
    Safety,    ///< game running, but the safety guard restored thermal protection
    Suspended, ///< Flux missing, disabled, outdated or not running: stock thermal
    Disabled,  ///< mode=off: stock thermal
};

[[nodiscard]] std::string_view to_string(State s);

/**
 * The HiCo state machine.
 *
 *              Flux ready + game             temp >= limit
 *   Idle ────────────────────────▶ Boost ─────────────────▶ Safety
 *    ▲                              │  ▲    cooled + cooldown  │
 *    └──────── game left ───────────┘  └───────────────────────┘
 *        (after exit_delay)
 *
 *   Any state ── Flux gone / mode=off ──▶ Suspended / Disabled (stock thermal)
 *
 * Levels per scenario: a Flux game gets game_level (Boost at max, Relaxed
 * otherwise, stock thermal for "stock"; a Performance Lite game with
 * unlock_on_lite=0 gets Relaxed); social media apps get social_level and
 * streaming apps media_level (stock or Relaxed, never max); an app on the
 * whitelist gets Relaxed; the blacklist is never boosted.
 *
 * tick() is the only place that decides; the event loop just calls it when
 * Flux's files, the config or a timer change. Stock thermal is the default
 * in every state except Boost.
 */
class Daemon {
public:
    using Clock = std::chrono::steady_clock;

    Daemon();

    /// Runs the event loop until SIGTERM/SIGINT; always leaves stock thermal behind.
    int run();

    /// One evaluation. Public so tests can drive the state machine directly.
    void tick(Clock::time_point now);

    void reload_config();

    /// Undo changes left by a previous instance that died while gaming.
    void recover();

    /// Restores stock thermal and closes the session (shutdown path).
    void shutdown();

    [[nodiscard]] State state() const { return state_; }
    [[nodiscard]] const Config &config() const { return cfg_; }
    [[nodiscard]] std::chrono::milliseconds next_timeout() const;

private:
    void transition(State next, Clock::time_point now, std::string reason);
    struct Target {
        std::string package;
        pid_t pid = 0;
        Level level = Level::Relaxed;
        std::string source; ///< "performance", "performance_lite", "warm" (max held back), "social", "media" or "whitelist"
    };
    [[nodiscard]] std::optional<Target> choose_target() const;
    void apply(const Target &target, Clock::time_point now);
    void begin_session(const Target &target, Clock::time_point now);
    void end_session(Clock::time_point now);
    void publish(const thermal::Temperatures &t) const;
    void update_module_description();

    Config cfg_;
    Journal journal_;
    ThermalController controller_;
    SafetyGuard guard_;
    HeadroomGuard headroom_; ///< max level only with headroom below the safety limits
    State state_ = State::Idle;
    std::string reason_;
    flux::Status flux_;
    std::vector<thermal::Zone> zones_;

    std::optional<Session> session_;
    Clock::time_point session_start_{};
    Clock::time_point last_tick_{};
    std::optional<Clock::time_point> exit_deadline_;
    std::time_t state_since_ = 0;
    bool described_ = false; ///< module.prop description written at least once
    bool flux_warned_ = false; ///< "Flux required" notification posted this boot
    /// Safety state with the vendor thermal running on the device's tuned template
    /// (soft landing) instead of full stock; full stock only past the hard margin.
    bool safety_relaxed_ = false;
    bool relax_unavailable_ = false; ///< no tunable vendor config on this device
    bool safety_notified_ = false;   ///< soft-landing notification posted this session
    bool stock_notified_ = false;    ///< stock-protection notification posted this session
    ThermalController::Summary summary_;
    std::optional<Level> applied_; ///< level currently applied to the system
};

/// Serialises the runtime state file into JSON for `hicod status --json` (WebUI).
[[nodiscard]] std::string json_escape(std::string_view s);

} // namespace hico
