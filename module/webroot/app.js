/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

'use strict'

// Every action goes through hicod, which validates values again: the WebUI
// never writes files or sysfs nodes itself. Flux's game list is only read.
const HICOD = '/data/adb/modules/hico/system/bin/hicod'
const LOG_FILE = '/data/adb/.config/hico/hico.log'
const FLUX_GAMELIST = '/data/adb/.config/flux/gamelist.json'
const FLUX_RELEASES = 'https://github.com/FebriCahyaa/Flux/releases'

// ── Strings (English / Bahasa Indonesia) ────────────────────────────────────

const STRINGS = {
  en: {
    tab_home: 'Home',
    tab_games: 'Games',
    tab_settings: 'Settings',
    tab_more: 'More',
    flux_required: 'Flux Tweaks is required',
    get_flux: 'Get Flux Tweaks',
    hico_mode: 'HiCo',
    auto: 'Auto',
    off: 'Off',
    mode_auto: 'Unlocks while Flux runs a game',
    mode_off: 'Stock thermal everywhere',
    game_level: 'Game level',
    max: 'Max',
    relaxed: 'Relaxed',
    level_max: 'Throttling off, safety guard on',
    level_relaxed: 'Vendor thermal kept, trips raised',
    active_changes: 'Active changes',
    this_device: 'This device',
    flux_games: 'Flux game list',
    flux_games_help:
      'HiCo boosts the games Flux detects. The list comes from Flux Tweaks (installed games from its database plus the ones you add in the Flux WebUI). Switch a game off to never boost it.',
    search_games: 'Search games',
    no_games: 'No games found in Flux. Add games in the Flux WebUI.',
    no_match: 'No game matches your search.',
    whitelist: 'Other apps',
    relaxed_only: 'Relaxed only',
    whitelist_help: 'Apps that are not games (camera, maps, …) get the relaxed level while on screen, never max.',
    blacklist: 'Never boost',
    never_boosted: 'Blocked',
    blacklist_help: 'These packages are never boosted, games included.',
    add: 'Add',
    history: 'Game history',
    clear: 'Clear',
    tap_again: 'Tap again',
    no_sessions: 'No sessions yet. Launch a game from Flux.',
    played: 'Played',
    unlocked: 'Unlocked',
    peak_cpu: 'Peak CPU',
    peak_battery: 'Peak batt.',
    trips: (n) => `${n} safety trip${n === 1 ? '' : 's'}`,
    advanced: 'Advanced',
    advanced_help: 'What is unlocked, relaxed margin, timings',
    reset_defaults: 'Reset all settings',
    service: 'Service',
    restart: 'Restart',
    restore: 'Restore & stop',
    restore_help: 'Restore puts every thermal value back to stock and stops HiCo until the next reboot or restart.',
    log: 'Log',
    refresh: 'Refresh',
    log_empty: 'Log is empty',
    about: 'About',
    about_text:
      'HiCo Thermal unlocks thermal throttling only while you play and restores stock thermal right after. Part of the Flux ecosystem. Private software, licensed under the EULA.',
    releases: 'Releases',
    saved: 'Saved',
    save_failed: 'Could not save',
    invalid_pkg: 'Enter a package name like com.example.app',
    defaults_restored: 'Defaults restored',
    restarted: 'Service restarted',
    restored: 'Stock thermal restored',
    no_bridge: 'Open this page from your root manager (KernelSU, APatch, MMRL or WebUI X).',
    cpu: 'CPU',
    gpu: 'GPU',
    battery: 'Battery',
    limit: (v) => `limit ${v}°`,
    device: 'Device',
    chipset: 'Chipset',
    rom: 'ROM',
    flux: 'Flux',
    profile: 'Profile',
    profile_verified: 'Stock firmware data',
    profile_generic: 'Runtime detection',
    backends: 'Backends',
    since: (time) => `since ${time}`,
    reason_performance: 'Performance',
    reason_performance_lite: 'Performance Lite',
    reason_whitelist: 'Whitelisted app',
    facts: {
      services: 'Services stopped',
      zones: 'Zones unthrottled',
      cooling: 'Cooling released',
      caps: 'Clock caps lifted',
      vendor: 'Vendor nodes',
      configs: 'Configs tuned',
      trips: 'Safety trips',
    },
    flux_short: { not_installed: 'Not installed', disabled: 'Disabled', outdated: 'Outdated', not_running: 'Not running' },
    flux_reasons: {
      not_installed: 'Flux Tweaks is not installed. HiCo keeps stock thermal until it is.',
      disabled: 'Flux Tweaks is disabled or scheduled for removal in your root manager.',
      outdated: 'Your Flux Tweaks is too old. Update it to v1.2.0 or newer.',
      not_running: 'Flux Tweaks is installed but fluxd is not running yet.',
    },
    states: {
      idle: ['Daily', 'Stock thermal', 'Full protection. Start a game from Flux to unlock.'],
      boost: ['Gaming', 'Thermal unlocked', 'Throttling is off. The safety guard watches CPU and battery.'],
      relaxed: ['Relaxed', 'Tuned thermal', 'Vendor thermal keeps running with trips raised for this chipset.'],
      relaxed_none: ['Relaxed', 'Stock thermal', 'No tunable thermal config on this device, stock thermal is kept.'],
      safety: ['Protected', 'Cooling down', 'Thermal protection is back until the device cools down.'],
      suspended: ['Waiting', 'Flux required', 'Stock thermal stays on until Flux Tweaks is ready.'],
      disabled: ['Off', 'HiCo is off', 'Stock thermal everywhere, games included.'],
      stopped: ['Stopped', 'Service not running', 'Stock thermal is active. Restart the service in More.'],
    },
    groups: {
      basic: 'Essentials',
      max: 'Max level unlocks',
      relaxed: 'Relaxed level',
      safety: 'Safety guard',
      timing: 'Service',
    },
    labels: {
      unlock_on_lite: ['Unlock in Performance Lite', 'Flux uses Lite when the phone is already warm. Off: relaxed level instead.'],
      notify: ['Notifications', 'Notify when the safety guard restores protection'],
      safety_cpu_temp: ['CPU limit', 'Protection comes back at this CPU temperature'],
      safety_battery_temp: ['Battery limit', 'Protection comes back at this battery temperature'],
      stop_thermal_services: ['Stop thermal daemons', 'thermal-engine, mi_thermald and similar'],
      stop_thermal_hal: ['Stop thermal HAL', "Breaks Android's thermal API while gaming (Flux uses it)"],
      zone_governor: ['Unthrottle kernel zones', 'user_space governor; critical trips stay active'],
      cooling_reset: ['Release cooling devices', 'Battery-bound devices are never touched'],
      cpu_clock_unlock: ['Unlock CPU max clock', 'Keep scaling_max_freq at the hardware maximum'],
      gpu_unlock: ['Unlock GPU cap', 'Adreno thermal power levels'],
      vendor_tweaks: ['Qualcomm / MediaTek drivers', 'msm_thermal, msm_performance, EARA'],
      xiaomi_tweaks: ['Xiaomi thermal', 'Thermal scene and CPU limits (MIUI / HyperOS)'],
      xiaomi_sconfig: ['Xiaomi thermal scene', 'Scene written while gaming'],
      relax_margin: ['Relaxed margin', '°C added to trips, 0 = chipset default'],
      safety_cpu_hysteresis: ['CPU recovery margin', 'Cool this much below the limit before unlocking again'],
      safety_battery_hysteresis: ['Battery recovery margin', 'Cool this much below the limit before unlocking again'],
      safety_cooldown: ['Protection cooldown', 'Minimum time protection stays on after a trip'],
      poll_interval: ['Check interval', 'Seconds between temperature checks while gaming'],
      exit_delay: ['Restore delay', 'Seconds to wait after the game leaves'],
      log_level: ['Log level', '0 error · 1 warning · 2 info · 3 debug'],
    },
  },
  id: {
    tab_home: 'Beranda',
    tab_games: 'Game',
    tab_settings: 'Pengaturan',
    tab_more: 'Lainnya',
    flux_required: 'Flux Tweaks diperlukan',
    get_flux: 'Unduh Flux Tweaks',
    hico_mode: 'HiCo',
    auto: 'Otomatis',
    off: 'Mati',
    mode_auto: 'Terbuka saat Flux menjalankan game',
    mode_off: 'Thermal bawaan di semua kondisi',
    game_level: 'Level game',
    max: 'Maks',
    relaxed: 'Santai',
    level_max: 'Throttling mati, pengaman suhu aktif',
    level_relaxed: 'Thermal vendor tetap jalan, batas dinaikkan',
    active_changes: 'Perubahan aktif',
    this_device: 'Perangkat ini',
    flux_games: 'Daftar game Flux',
    flux_games_help:
      'HiCo membuka thermal untuk game yang dideteksi Flux. Daftarnya berasal dari Flux Tweaks (game terpasang dari database Flux plus game yang kamu tambahkan di WebUI Flux). Matikan sebuah game agar tidak pernah di-boost.',
    search_games: 'Cari game',
    no_games: 'Tidak ada game di Flux. Tambahkan game lewat WebUI Flux.',
    no_match: 'Tidak ada game yang cocok.',
    whitelist: 'Aplikasi lain',
    relaxed_only: 'Hanya santai',
    whitelist_help: 'Aplikasi non-game (kamera, peta, …) mendapat level santai saat tampil di layar, tidak pernah maks.',
    blacklist: 'Jangan di-boost',
    never_boosted: 'Diblokir',
    blacklist_help: 'Paket ini tidak pernah di-boost, termasuk game.',
    add: 'Tambah',
    history: 'Riwayat game',
    clear: 'Hapus',
    tap_again: 'Ketuk lagi',
    no_sessions: 'Belum ada sesi. Jalankan game lewat Flux.',
    played: 'Main',
    unlocked: 'Terbuka',
    peak_cpu: 'Puncak CPU',
    peak_battery: 'Puncak bat.',
    trips: (n) => `${n}× pengaman aktif`,
    advanced: 'Lanjutan',
    advanced_help: 'Yang dibuka, margin santai, waktu',
    reset_defaults: 'Kembalikan semua pengaturan',
    service: 'Layanan',
    restart: 'Mulai ulang',
    restore: 'Pulihkan & hentikan',
    restore_help: 'Pulihkan mengembalikan semua nilai thermal ke bawaan dan menghentikan HiCo sampai reboot atau dimulai ulang.',
    log: 'Log',
    refresh: 'Muat ulang',
    log_empty: 'Log kosong',
    about: 'Tentang',
    about_text:
      'HiCo Thermal membuka throttling thermal hanya saat kamu bermain dan langsung mengembalikan thermal bawaan setelahnya. Bagian dari ekosistem Flux. Perangkat lunak privat, berlisensi EULA.',
    releases: 'Rilis',
    saved: 'Tersimpan',
    save_failed: 'Gagal menyimpan',
    invalid_pkg: 'Masukkan nama paket seperti com.contoh.app',
    defaults_restored: 'Pengaturan bawaan dipulihkan',
    restarted: 'Layanan dimulai ulang',
    restored: 'Thermal bawaan dipulihkan',
    no_bridge: 'Buka halaman ini dari root manager (KernelSU, APatch, MMRL atau WebUI X).',
    cpu: 'CPU',
    gpu: 'GPU',
    battery: 'Baterai',
    limit: (v) => `batas ${v}°`,
    device: 'Perangkat',
    chipset: 'Chipset',
    rom: 'ROM',
    flux: 'Flux',
    profile: 'Profil',
    profile_verified: 'Data firmware stok',
    profile_generic: 'Deteksi otomatis',
    backends: 'Backend',
    since: (time) => `sejak ${time}`,
    reason_performance: 'Performance',
    reason_performance_lite: 'Performance Lite',
    reason_whitelist: 'Aplikasi whitelist',
    facts: {
      services: 'Layanan dihentikan',
      zones: 'Zona dibuka',
      cooling: 'Pendingin dilepas',
      caps: 'Batas clock dibuka',
      vendor: 'Node vendor',
      configs: 'Config disetel',
      trips: 'Pengaman aktif',
    },
    flux_short: { not_installed: 'Belum terpasang', disabled: 'Nonaktif', outdated: 'Versi lama', not_running: 'Belum berjalan' },
    flux_reasons: {
      not_installed: 'Flux Tweaks belum terpasang. HiCo memakai thermal bawaan sampai terpasang.',
      disabled: 'Flux Tweaks dinonaktifkan atau dijadwalkan dihapus di root manager.',
      outdated: 'Flux Tweaks terlalu lama. Perbarui ke v1.2.0 atau lebih baru.',
      not_running: 'Flux Tweaks terpasang tetapi fluxd belum berjalan.',
    },
    states: {
      idle: ['Harian', 'Thermal bawaan', 'Perlindungan penuh. Jalankan game lewat Flux untuk membuka.'],
      boost: ['Bermain', 'Thermal terbuka', 'Throttling mati. Pengaman memantau suhu CPU dan baterai.'],
      relaxed: ['Santai', 'Thermal disetel', 'Thermal vendor tetap jalan dengan batas dinaikkan untuk chipset ini.'],
      relaxed_none: ['Santai', 'Thermal bawaan', 'Tidak ada config thermal yang bisa disetel, thermal bawaan dipakai.'],
      safety: ['Terlindungi', 'Mendinginkan', 'Perlindungan thermal aktif kembali sampai perangkat dingin.'],
      suspended: ['Menunggu', 'Perlu Flux', 'Thermal bawaan tetap aktif sampai Flux Tweaks siap.'],
      disabled: ['Mati', 'HiCo mati', 'Thermal bawaan di semua kondisi, termasuk game.'],
      stopped: ['Berhenti', 'Layanan tidak berjalan', 'Thermal bawaan aktif. Mulai ulang layanan di Lainnya.'],
    },
    groups: {
      basic: 'Utama',
      max: 'Yang dibuka di level maks',
      relaxed: 'Level santai',
      safety: 'Pengaman suhu',
      timing: 'Layanan',
    },
    labels: {
      unlock_on_lite: ['Buka di Performance Lite', 'Flux memakai Lite saat HP sudah hangat. Mati: level santai.'],
      notify: ['Notifikasi', 'Beri tahu saat pengaman suhu aktif'],
      safety_cpu_temp: ['Batas CPU', 'Perlindungan kembali pada suhu CPU ini'],
      safety_battery_temp: ['Batas baterai', 'Perlindungan kembali pada suhu baterai ini'],
      stop_thermal_services: ['Hentikan daemon thermal', 'thermal-engine, mi_thermald dan sejenisnya'],
      stop_thermal_hal: ['Hentikan thermal HAL', 'API thermal Android mati saat bermain (dipakai Flux)'],
      zone_governor: ['Buka zona kernel', 'Governor user_space; trip kritis tetap aktif'],
      cooling_reset: ['Lepas perangkat pendingin', 'Yang terkait baterai tidak pernah disentuh'],
      cpu_clock_unlock: ['Buka clock maks CPU', 'scaling_max_freq tetap di maksimum hardware'],
      gpu_unlock: ['Buka batas GPU', 'Power level thermal Adreno'],
      vendor_tweaks: ['Driver Qualcomm / MediaTek', 'msm_thermal, msm_performance, EARA'],
      xiaomi_tweaks: ['Thermal Xiaomi', 'Thermal scene dan batas CPU (MIUI / HyperOS)'],
      xiaomi_sconfig: ['Thermal scene Xiaomi', 'Scene yang dipakai saat bermain'],
      relax_margin: ['Margin santai', '°C ditambahkan ke trip, 0 = bawaan chipset'],
      safety_cpu_hysteresis: ['Margin pemulihan CPU', 'Harus turun sebanyak ini di bawah batas sebelum dibuka lagi'],
      safety_battery_hysteresis: ['Margin pemulihan baterai', 'Harus turun sebanyak ini di bawah batas sebelum dibuka lagi'],
      safety_cooldown: ['Jeda perlindungan', 'Waktu minimum perlindungan aktif setelah trip'],
      poll_interval: ['Interval cek', 'Detik antar cek suhu saat bermain'],
      exit_delay: ['Jeda pemulihan', 'Detik menunggu setelah game ditutup'],
      log_level: ['Level log', '0 error · 1 peringatan · 2 info · 3 debug'],
    },
  },
}

const UNITS = {
  safety_cpu_temp: '°C',
  safety_battery_temp: '°C',
  safety_cpu_hysteresis: '°C',
  safety_battery_hysteresis: '°C',
  relax_margin: '°C',
  safety_cooldown: 's',
  poll_interval: 's',
  exit_delay: 's',
}

// Mode and game level live on Home, the lists on Games; everything else is here.
const VENDORS = {
  qualcomm: 'Qualcomm',
  mediatek: 'MediaTek',
  exynos: 'Exynos',
  tensor: 'Tensor',
  unisoc: 'Unisoc',
  xiaomi: 'Xiaomi',
}
const vendorName = (v) => VENDORS[v] || v

const BASIC = ['safety_cpu_temp', 'safety_battery_temp', 'unlock_on_lite', 'notify']
const ADVANCED = [
  [
    'max',
    [
      'stop_thermal_services',
      'stop_thermal_hal',
      'zone_governor',
      'cooling_reset',
      'cpu_clock_unlock',
      'gpu_unlock',
      'vendor_tweaks',
      'xiaomi_tweaks',
      'xiaomi_sconfig',
    ],
  ],
  ['relaxed', ['relax_margin']],
  ['safety', ['safety_cpu_hysteresis', 'safety_battery_hysteresis', 'safety_cooldown']],
  ['timing', ['poll_interval', 'exit_delay', 'log_level']],
]

function storageGet(key) {
  try {
    return localStorage.getItem(key)
  } catch {
    return null
  }
}

function storageSet(key, value) {
  try {
    localStorage.setItem(key, value)
  } catch {
    // Storage can be unavailable in some WebViews; the choice is just not remembered.
  }
}

let lang = storageGet('hico.lang') || ((navigator.language || '').toLowerCase().startsWith('id') ? 'id' : 'en')
const t = (key) => STRINGS[lang][key] ?? STRINGS.en[key] ?? key

// ── Bridge ──────────────────────────────────────────────────────────────────

let callbackId = 0

function exec(command) {
  return new Promise((resolve, reject) => {
    if (typeof ksu === 'undefined') {
      reject(new Error(t('no_bridge')))
      return
    }
    const name = `hico_exec_${Date.now()}_${callbackId++}`
    window[name] = (errno, stdout, stderr) => {
      delete window[name]
      resolve({ errno, stdout: stdout || '', stderr: stderr || '' })
    }
    try {
      ksu.exec(command, '{}', name)
    } catch (e) {
      delete window[name]
      reject(e)
    }
  })
}

// ── Helpers ─────────────────────────────────────────────────────────────────

const $ = (id) => document.getElementById(id)

function el(tag, attrs = {}, ...children) {
  const node = document.createElement(tag)
  for (const [k, v] of Object.entries(attrs)) {
    if (v === undefined || v === null || v === false) continue
    if (k === 'class') node.className = v
    else if (k === 'style') node.style.cssText = v
    else if (k.startsWith('on')) node.addEventListener(k.slice(2), v)
    else node.setAttribute(k, v === true ? '' : v)
  }
  for (const c of children) if (c !== null && c !== undefined) node.append(c)
  return node
}

const SVG_NS = 'http://www.w3.org/2000/svg'

function icon(name) {
  const s = document.createElementNS(SVG_NS, 'svg')
  s.setAttribute('aria-hidden', 'true')
  const use = document.createElementNS(SVG_NS, 'use')
  use.setAttribute('href', `#i-${name}`)
  s.append(use)
  return s
}

let toastTimer = null
function toast(message) {
  const node = $('toast')
  node.textContent = message
  node.classList.add('show')
  clearTimeout(toastTimer)
  toastTimer = setTimeout(() => node.classList.remove('show'), 2200)
}

// Two taps instead of confirm(): some root manager WebViews do not show JS dialogs.
function confirmTap(button, action) {
  const label = button.querySelector('[data-i18n]') || button
  let timer = null
  const disarm = () => {
    clearTimeout(timer)
    button.dataset.armed = ''
    label.textContent = t(label.dataset.i18n)
  }
  button.addEventListener('click', async () => {
    if (button.dataset.armed !== '1') {
      button.dataset.armed = '1'
      label.textContent = t('tap_again')
      timer = setTimeout(disarm, 3000)
      return
    }
    disarm()
    await action()
  })
}

function formatTemp(v) {
  return v === '' || v === undefined || v === null || Number.isNaN(Number(v)) ? '–' : `${Math.round(Number(v))}°`
}

function formatDuration(seconds) {
  const s = Math.max(0, Math.round(seconds))
  if (s < 60) return `${s}s`
  const m = Math.floor(s / 60)
  if (m < 60) return `${m}m`
  return `${Math.floor(m / 60)}h ${m % 60}m`
}

const PACKAGE = /^[A-Za-z][A-Za-z0-9_]*(\.[A-Za-z0-9_]+)+$/

// App labels come from the root manager when it exposes them (KernelSU / WebUI X);
// otherwise a readable name is derived from the package.
const labels = {}

function loadLabels(packages) {
  const missing = packages.filter((p) => !(p in labels))
  if (!missing.length) return
  try {
    if (typeof ksu !== 'undefined' && typeof ksu.getPackagesInfo === 'function') {
      const info = JSON.parse(ksu.getPackagesInfo(JSON.stringify(missing)))
      for (const i of Array.isArray(info) ? info : []) {
        if (i && i.packageName && i.appLabel) labels[i.packageName] = String(i.appLabel)
      }
    }
  } catch {
    // Older managers: fall back to derived names.
  }
  for (const p of missing) if (!(p in labels)) labels[p] = ''
}

const GENERIC = new Set([
  'com', 'org', 'net', 'android', 'game', 'games', 'global', 'gp', 'google', 'play', 'en', 'app',
  'mobile', 'client', 'release', 'os', 'intl', 'sea', 'na', 'eu', 'jp', 'kr', 'tw', 'cn', 'id',
])

function appName(pkg) {
  if (labels[pkg]) return labels[pkg]
  const parts = pkg.split('.').filter((p) => !GENERIC.has(p.toLowerCase()))
  const word = parts.length ? parts[parts.length - 1] : pkg.split('.').pop()
  return word
    .replace(/[_-]+/g, ' ')
    .replace(/([a-z])([A-Z])/g, '$1 $2')
    .replace(/\b\w/g, (c) => c.toUpperCase())
}

function avatar(pkg, id) {
  let h = 0
  for (const c of pkg) h = (h * 31 + c.charCodeAt(0)) % 360
  return el('span', { class: 'avatar', style: `--h:${h}`, id }, appName(pkg).charAt(0).toUpperCase())
}

// ── State ───────────────────────────────────────────────────────────────────

const state = {
  tab: 'home',
  status: null,
  config: {}, // key -> schema item from `hicod config schema`
  games: [], // [{pkg, lite}] from Flux's gamelist.json
  sessions: [],
}

const cfg = (key) => state.config[key]?.value ?? ''
const listOf = (key) =>
  cfg(key)
    .split(',')
    .map((s) => s.trim())
    .filter(Boolean)

// ── Config writes ───────────────────────────────────────────────────────────

async function setConfig(key, value) {
  // Values are restricted to [A-Za-z0-9._,] before reaching the shell; hicod validates again.
  const safe = String(value).replace(/\s+/g, '')
  if (!/^[A-Za-z0-9._,]*$/.test(safe)) {
    toast(t('save_failed'))
    return false
  }
  let res
  try {
    res = await exec(`${HICOD} config set ${key} '${safe}'`)
  } catch (e) {
    toast(e.message)
    return false
  }
  if (res.errno !== 0) {
    toast(res.stderr.trim() || t('save_failed'))
    await loadConfig()
    return false
  }
  if (state.config[key]) state.config[key].value = safe
  toast(t('saved'))
  setTimeout(refreshStatus, 500)
  return true
}

async function setList(key, packages) {
  await setConfig(key, [...new Set(packages)].join(','))
  renderLists()
}

// ── Home ────────────────────────────────────────────────────────────────────

const HERO_ICONS = {
  idle: 'thermo',
  boost: 'flame',
  relaxed: 'leaf',
  safety: 'shield',
  suspended: 'alert',
  disabled: 'power',
  stopped: 'alert',
}

function renderGauge(id, label, value, limit) {
  const node = $(id)
  const v = value === '' || value === undefined || value === null ? null : Number(value)
  const lim = Number(limit) || 0
  const ratio = v === null || !lim ? 0 : Math.min(1, Math.max(0, v / lim))
  const C = 2 * Math.PI * 34
  const arc = C * 0.75 // 270° dial

  node.className = `gauge ${v === null ? 'none' : ratio >= 0.97 ? 'hot' : ratio >= 0.85 ? 'warm' : ''}`
  if (!node.firstChild) {
    const s = document.createElementNS(SVG_NS, 'svg')
    s.setAttribute('viewBox', '0 0 80 80')
    for (const cls of ['track', 'fill']) {
      const c = document.createElementNS(SVG_NS, 'circle')
      c.setAttribute('cx', '40')
      c.setAttribute('cy', '40')
      c.setAttribute('r', '34')
      c.setAttribute('class', cls)
      s.append(c)
    }
    node.append(
      el('div', { class: 'ring' }, s, el('span', { class: 'value' })),
      el('span', { class: 'label' }),
      el('span', { class: 'limit' }),
    )
  }
  node.querySelector('.track').setAttribute('stroke-dasharray', `${arc} ${C}`)
  const fill = node.querySelector('.fill')
  fill.setAttribute('stroke-dasharray', `${arc * ratio} ${C}`)
  fill.style.visibility = ratio > 0 ? 'visible' : 'hidden'
  node.querySelector('.value').textContent = formatTemp(v)
  node.querySelector('.label').textContent = label
  node.querySelector('.limit').textContent = lim ? t('limit')(lim) : ''
}

function fact(k, v) {
  return el('div', { class: 'fact' }, el('span', { class: 'k' }, k), el('span', { class: 'v' }, v || '–'))
}

function renderHome() {
  const s = state.status
  if (!s) return
  const st = s.state || 'stopped'
  const relaxedNone = st === 'relaxed' && !(Number(s.configs) > 0)
  const [kicker, title, desc] = t('states')[relaxedNone ? 'relaxed_none' : st] || [st, st, '']

  $('hero').className = `hero ${st}`
  $('hero-icon').setAttribute('href', `#i-${HERO_ICONS[st] || 'alert'}`)
  $('hero-kicker').textContent = kicker
  $('hero-title').textContent = title
  $('hero-desc').textContent = st === 'safety' && s.reason ? `${desc} (${s.reason})` : desc

  const active = ['boost', 'relaxed', 'safety'].includes(st) && Boolean(s.game)
  $('hero-app').hidden = !active
  if (active) {
    loadLabels([s.game])
    $('hero-avatar').replaceWith(avatar(s.game, 'hero-avatar'))
    $('hero-app-name').textContent = appName(s.game)
    const since =
      Number(s.since) > 0
        ? t('since')(new Date(s.since * 1000).toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' }))
        : ''
    const reason = STRINGS[lang][`reason_${s.reason}`] || ''
    $('hero-app-meta').textContent = [reason, since].filter(Boolean).join(' · ')
  }

  renderGauge('g-cpu', t('cpu'), s.cpu_temp, cfg('safety_cpu_temp'))
  renderGauge('g-gpu', t('gpu'), s.gpu_temp, cfg('safety_cpu_temp'))
  renderGauge('g-bat', t('battery'), s.battery_temp, cfg('safety_battery_temp'))

  const fluxReady = s.flux === 'ready'
  $('flux-banner').hidden = fluxReady || st === 'stopped'
  if (!fluxReady) {
    $('flux-banner-text').textContent = t('flux_reasons')[s.flux] || `Flux: ${s.flux}`
    $('flux-link').href = FLUX_RELEASES
  }

  // What the current level changed.
  const relaxed = st === 'relaxed' || (st === 'safety' && s.level === 'relaxed')
  const keys = relaxed ? ['configs', 'trips'] : ['services', 'zones', 'cooling', 'caps', 'vendor', 'trips']
  $('applied-card').hidden = !['boost', 'relaxed', 'safety'].includes(st)
  $('applied').replaceChildren(...keys.map((k) => fact(t('facts')[k], s[k] ?? '0')))

  const fluxText = fluxReady ? s.flux_version || 'OK' : t('flux_short')[s.flux] || s.flux
  $('device').replaceChildren(
    fact(t('device'), s.device_name ? `${s.device_name} (${s.device})` : s.device),
    fact(t('chipset'), s.soc && s.soc !== 'unknown' ? vendorName(s.soc) : ''),
    fact(t('rom'), s.rom_name),
    fact(t('flux'), fluxText),
    fact(t('profile'), s.device_profile === 'verified' ? t('profile_verified') : t('profile_generic')),
    ...(s.backends ? [fact(t('backends'), s.backends.split(',').map(vendorName).join(', '))] : []),
  )

  $('version').textContent = s.version ? `v${s.version}` : ' '
}

function renderSegments() {
  for (const [id, key, helpId, helps] of [
    ['seg-mode', 'mode', 'mode-help', { auto: 'mode_auto', off: 'mode_off' }],
    ['seg-level', 'game_level', 'level-help', { max: 'level_max', relaxed: 'level_relaxed' }],
  ]) {
    const value = cfg(key)
    for (const b of $(id).querySelectorAll('button')) {
      const on = b.dataset.value === value
      b.classList.toggle('on', on)
      b.setAttribute('role', 'radio')
      b.setAttribute('aria-checked', String(on))
    }
    $(helpId).textContent = helps[value] ? t(helps[value]) : ''
  }
}

async function refreshStatus() {
  try {
    const { stdout } = await exec(`${HICOD} status --json`)
    state.status = JSON.parse(stdout)
  } catch (e) {
    state.status = { state: 'stopped' }
    renderHome()
    $('hero-desc').textContent = e.message
    return
  }
  renderHome()
}

// ── Games ───────────────────────────────────────────────────────────────────

async function loadGames() {
  let list = {}
  try {
    const { stdout } = await exec(`cat ${FLUX_GAMELIST} 2>/dev/null`)
    list = JSON.parse(stdout || '{}')
  } catch {
    list = {}
  }
  state.games = Object.entries(list && typeof list === 'object' ? list : {})
    .filter(([pkg]) => PACKAGE.test(pkg))
    .map(([pkg, v]) => ({ pkg, lite: Boolean(v && v.lite_mode) }))
  loadLabels(state.games.map((g) => g.pkg))
  state.games.sort((a, b) => appName(a.pkg).localeCompare(appName(b.pkg)))
  renderGames()
}

function renderGames() {
  const query = $('games-search').value.trim().toLowerCase()
  const blocked = new Set(listOf('blacklist'))
  $('games-count').textContent = String(state.games.length)

  const shown = state.games.filter(
    (g) => !query || g.pkg.toLowerCase().includes(query) || appName(g.pkg).toLowerCase().includes(query),
  )
  if (!shown.length) {
    $('games').replaceChildren(el('li', { class: 'empty' }, t(state.games.length ? 'no_match' : 'no_games')))
    return
  }
  $('games').replaceChildren(
    ...shown.map((g) => {
      const on = !blocked.has(g.pkg)
      const input = el('input', { type: 'checkbox', 'aria-label': appName(g.pkg) })
      input.checked = on
      input.addEventListener('change', () => {
        const list = listOf('blacklist').filter((p) => p !== g.pkg)
        if (!input.checked) list.push(g.pkg)
        setList('blacklist', list)
      })
      return el(
        'li',
        { class: `app${on ? '' : ' off'}` },
        avatar(g.pkg),
        el('div', { class: 'meta' }, el('span', { class: 'name' }, appName(g.pkg)), el('span', { class: 'pkg' }, g.pkg)),
        g.lite ? el('span', { class: 'badge lite' }, 'Lite') : null,
        el('label', { class: 'switch' }, input, el('span')),
      )
    }),
  )
}

function renderChips(key) {
  const packages = listOf(key)
  loadLabels(packages)
  $(key).replaceChildren(
    ...packages.map((pkg) =>
      el(
        'span',
        { class: 'chip', title: pkg },
        el('span', {}, labels[pkg] ? `${labels[pkg]} · ${pkg}` : pkg),
        el(
          'button',
          {
            type: 'button',
            'aria-label': `Remove ${pkg}`,
            onclick: () => setList(key, listOf(key).filter((p) => p !== pkg)),
          },
          icon('x'),
        ),
      ),
    ),
  )
}

function renderLists() {
  renderChips('whitelist')
  renderChips('blacklist')
  renderGames()
}

function wireAdd(formId, key) {
  $(formId).addEventListener('submit', (e) => {
    e.preventDefault()
    const input = e.target.elements.pkg
    const pkg = input.value.trim()
    if (!PACKAGE.test(pkg)) {
      toast(t('invalid_pkg'))
      return
    }
    input.value = ''
    setList(key, [...listOf(key), pkg])
  })
}

async function loadSessions() {
  const { stdout } = await exec(`${HICOD} sessions`).catch(() => ({ stdout: '' }))
  state.sessions = stdout
    .split('\n')
    .map((line) => {
      try {
        return JSON.parse(line)
      } catch {
        return null
      }
    })
    .filter(Boolean)
    .reverse()
    .slice(0, 30)
  renderSessions()
}

function renderSessions() {
  const rows = state.sessions
  if (!rows.length) {
    $('sessions').replaceChildren(el('p', { class: 'empty' }, t('no_sessions')))
    return
  }
  loadLabels(rows.map((r) => r.game))
  const stat = (k, v) => el('div', { class: 'stat' }, el('span', { class: 'k' }, k), el('span', {}, v))
  $('sessions').replaceChildren(
    ...rows.map((r) =>
      el(
        'div',
        { class: 'session' },
        el(
          'div',
          { class: 'session-head' },
          avatar(r.game),
          el(
            'div',
            { class: 'meta' },
            el('strong', {}, appName(r.game)),
            el(
              'span',
              { class: 'muted small' },
              new Date(r.start * 1000).toLocaleString([], { dateStyle: 'medium', timeStyle: 'short' }),
            ),
          ),
          Number(r.trips) > 0 ? el('span', { class: 'badge soft-bad' }, t('trips')(Number(r.trips))) : null,
        ),
        el(
          'div',
          { class: 'stats' },
          stat(t('played'), formatDuration(r.duration)),
          stat(t('unlocked'), formatDuration(r.boosted)),
          stat(t('peak_cpu'), formatTemp(r.peak_cpu)),
          stat(t('peak_battery'), formatTemp(r.peak_battery)),
        ),
      ),
    ),
  )
}

// ── Settings ────────────────────────────────────────────────────────────────

function settingRow(item) {
  const { key, type, min, max, value } = item
  const [name, help] = t('labels')[key] || [key, item.help]

  if (type === 'bool') {
    const input = el('input', { type: 'checkbox', 'aria-label': name })
    input.checked = value === '1'
    input.addEventListener('change', () => setConfig(key, input.checked ? '1' : '0'))
    return el(
      'div',
      { class: 'setting' },
      el('span', { class: 'name' }, name),
      el('label', { class: 'switch' }, input, el('span')),
      el('span', { class: 'help' }, help),
    )
  }

  if (type === 'int') {
    const unit = UNITS[key] || ''
    const shown = (v) => (key === 'relax_margin' && Number(v) === 0 ? t('auto') : `${v}${unit}`)
    const out = el('span', { class: 'val' }, shown(value))
    const input = el('input', { type: 'range', min: String(min), max: String(max), step: '1', 'aria-label': name })
    input.value = value
    input.addEventListener('input', () => (out.textContent = shown(input.value)))
    input.addEventListener('change', () => setConfig(key, input.value))
    return el(
      'div',
      { class: 'setting slider' },
      el('span', { class: 'name' }, name),
      out,
      el(
        'div',
        { class: 'row' },
        el('span', { class: 'muted small' }, String(min)),
        input,
        el('span', { class: 'muted small' }, String(max)),
      ),
      el('span', { class: 'help' }, help),
    )
  }
  return null
}

function renderSettings() {
  const rows = (keys) => keys.map((k) => state.config[k] && settingRow(state.config[k])).filter(Boolean)
  $('settings-basic').replaceChildren(el('h3', { class: 'group-title' }, t('groups').basic), ...rows(BASIC))
  $('settings-advanced').replaceChildren(
    ...ADVANCED.flatMap(([group, keys]) => [el('h3', { class: 'group-title' }, t('groups')[group]), ...rows(keys)]),
  )
}

async function loadConfig() {
  try {
    const { stdout } = await exec(`${HICOD} config schema`)
    state.config = Object.fromEntries(JSON.parse(stdout).map((item) => [item.key, item]))
  } catch (e) {
    $('settings-basic').textContent = e.message
    return
  }
  renderSegments()
  renderSettings()
  renderLists()
  renderHome()
}

// ── More ────────────────────────────────────────────────────────────────────

async function loadLog() {
  const { stdout } = await exec(`tail -n 200 ${LOG_FILE} 2>/dev/null`).catch(() => ({ stdout: '' }))
  const log = $('log')
  log.textContent = stdout.trim() || t('log_empty')
  log.scrollTop = log.scrollHeight
}

// ── Navigation, language, wiring ────────────────────────────────────────────

function showTab(tab) {
  state.tab = tab
  for (const section of document.querySelectorAll('main .tab')) section.hidden = section.dataset.tab !== tab
  for (const b of document.querySelectorAll('.tabbar button')) {
    b.classList.toggle('active', b.dataset.tab === tab)
    b.setAttribute('aria-current', b.dataset.tab === tab ? 'page' : 'false')
  }
  window.scrollTo(0, 0)
  if (tab === 'home') refreshStatus()
  else if (tab === 'games') {
    loadGames()
    loadSessions()
  } else if (tab === 'more') loadLog()
  schedule()
}

function applyLanguage() {
  document.documentElement.lang = lang
  for (const node of document.querySelectorAll('[data-i18n]')) node.textContent = t(node.dataset.i18n)
  $('games-search').placeholder = t('search_games')
  $('lang').textContent = lang === 'id' ? 'EN' : 'ID'
  renderSegments()
  renderSettings()
  renderLists()
  renderSessions()
  renderHome()
}

for (const b of document.querySelectorAll('.tabbar button')) b.addEventListener('click', () => showTab(b.dataset.tab))

$('lang').addEventListener('click', () => {
  lang = lang === 'id' ? 'en' : 'id'
  storageSet('hico.lang', lang)
  applyLanguage()
})

for (const [id, key] of [
  ['seg-mode', 'mode'],
  ['seg-level', 'game_level'],
]) {
  $(id).addEventListener('click', async (e) => {
    const b = e.target.closest('button')
    if (!b || b.dataset.value === cfg(key)) return
    if (await setConfig(key, b.dataset.value)) renderSegments()
  })
}

$('games-search').addEventListener('input', renderGames)
wireAdd('whitelist-add', 'whitelist')
wireAdd('blacklist-add', 'blacklist')

confirmTap($('clear-sessions'), async () => {
  await exec(`${HICOD} sessions clear`)
  loadSessions()
})

confirmTap($('reset-settings'), async () => {
  await exec(`${HICOD} config reset`)
  toast(t('defaults_restored'))
  loadConfig()
})

$('restart').addEventListener('click', async () => {
  await exec(`${HICOD} restore >/dev/null 2>&1; ${HICOD} daemon`)
  toast(t('restarted'))
  setTimeout(refreshStatus, 800)
})

confirmTap($('restore'), async () => {
  const { stdout } = await exec(`${HICOD} restore`)
  toast(stdout.trim() || t('restored'))
  refreshStatus()
})

$('load-log').addEventListener('click', loadLog)

// Live status only while Home is on screen.
let timer = null
function schedule() {
  clearInterval(timer)
  if (!document.hidden && state.tab === 'home') timer = setInterval(refreshStatus, 2000)
}
document.addEventListener('visibilitychange', () => {
  schedule()
  if (!document.hidden && state.tab === 'home') refreshStatus()
})

applyLanguage()
loadConfig()
refreshStatus()
schedule()
