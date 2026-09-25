/*
 * Copyright (C) 2026 FebriCahyaa. All rights reserved.
 *
 * HiCo Thermal is proprietary software. Use is governed by EULA.md;
 * copying, redistribution or modification without written permission
 * from the author is prohibited.
 */

'use strict'

// Every action goes through hicod, which validates values again: the WebUI
// never writes files or sysfs nodes itself.
const HICOD = '/data/adb/modules/hico/system/bin/hicod'
const LOG_FILE = '/data/adb/.config/hico/hico.log'
const FLUX_RELEASES = 'https://github.com/FebriCahyaa/Flux/releases'

const LABELS = {
  mode: 'Mode',
  unlock_on_lite: 'Unlock in Performance Lite',
  game_level: 'Game level',
  whitelist: 'Whitelist (apps, relaxed only)',
  blacklist: 'Blacklist (never boosted)',
  relax_margin: 'Relaxed margin (°C, 0 = chipset default)',
  notify: 'Notifications',
  stop_thermal_services: 'Stop thermal services',
  stop_thermal_hal: 'Stop thermal HAL',
  zone_governor: 'Unthrottle kernel thermal zones',
  cooling_reset: 'Release cooling devices',
  cpu_clock_unlock: 'Unlock max CPU clock',
  gpu_unlock: 'Unlock GPU thermal cap',
  vendor_tweaks: 'Qualcomm / MediaTek drivers',
  xiaomi_tweaks: 'Xiaomi thermal',
  xiaomi_sconfig: 'Xiaomi thermal scene',
  safety_cpu_temp: 'CPU limit (°C)',
  safety_battery_temp: 'Battery limit (°C)',
  safety_cpu_hysteresis: 'CPU recovery margin (°C)',
  safety_battery_hysteresis: 'Battery recovery margin (°C)',
  safety_cooldown: 'Protection cooldown (s)',
  poll_interval: 'Check interval while gaming (s)',
  exit_delay: 'Restore delay after game (s)',
  log_level: 'Log level',
}

const GROUPS = [
  ['General', ['mode', 'game_level', 'unlock_on_lite', 'whitelist', 'blacklist', 'notify']],
  ['Relaxed level', ['relax_margin']],
  [
    'While gaming',
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
  [
    'Safety guard',
    ['safety_cpu_temp', 'safety_battery_temp', 'safety_cpu_hysteresis', 'safety_battery_hysteresis', 'safety_cooldown'],
  ],
  ['Advanced', ['poll_interval', 'exit_delay', 'log_level']],
]

const FLUX_REASONS = {
  not_installed: 'Flux Tweaks is not installed.',
  disabled: 'Flux Tweaks is disabled or scheduled for removal in your root manager.',
  outdated: 'Your Flux Tweaks is too old; update it to v1.2.0 or newer.',
  not_running: 'Flux Tweaks is installed but its daemon (fluxd) is not running yet.',
}

// ── Bridge ──────────────────────────────────────────────────────────────────

let callbackId = 0

function exec(command) {
  return new Promise((resolve, reject) => {
    if (typeof ksu === 'undefined') {
      reject(new Error('Open this page from your root manager (KernelSU, APatch, MMRL or WebUI X).'))
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

let toastTimer = null
function toast(message) {
  const el = document.getElementById('toast')
  el.textContent = message
  el.classList.add('show')
  clearTimeout(toastTimer)
  toastTimer = setTimeout(() => el.classList.remove('show'), 2500)
}

const $ = (id) => document.getElementById(id)

function el(tag, attrs = {}, ...children) {
  const node = document.createElement(tag)
  for (const [k, v] of Object.entries(attrs)) {
    if (k === 'class') node.className = v
    else if (k.startsWith('on')) node.addEventListener(k.slice(2), v)
    else node.setAttribute(k, v)
  }
  for (const c of children) node.append(c)
  return node
}

// ── Status ──────────────────────────────────────────────────────────────────

function formatTemp(v) {
  return v ? `${Number(v).toFixed(1)}°` : '–'
}

function formatDuration(seconds) {
  const s = Math.max(0, Math.round(seconds))
  if (s < 60) return `${s}s`
  const m = Math.floor(s / 60)
  if (m < 60) return `${m}m ${s % 60}s`
  return `${Math.floor(m / 60)}h ${m % 60}m`
}

const STATE_TEXT = {
  idle: () => 'Daily use: stock thermal protection is active.',
  boost: (s) => `Gaming: thermal throttling is disabled for ${s.game || s.reason}.`,
  relaxed: (s) =>
    Number(s.configs) > 0
      ? `Relaxed: ${s.game || s.reason} runs with ${s.configs} vendor thermal config(s) tuned for this chipset; the vendor thermal daemons keep protecting the device.`
      : `Relaxed level for ${s.game || s.reason}, but this device has no tunable (plain-text) thermal config: stock thermal is kept.`,
  safety: (s) => `Safety guard: ${s.reason}. Thermal protection is back on until the device cools down.`,
  suspended: () => 'Waiting for Flux Tweaks. Stock thermal protection is active.',
  disabled: () => 'Off: stock thermal protection everywhere, games included.',
  stopped: () => 'The HiCo service is not running. Stock thermal protection is active.',
}

async function refreshStatus() {
  let s
  try {
    const { stdout } = await exec(`${HICOD} status --json`)
    s = JSON.parse(stdout)
  } catch (e) {
    $('state-text').textContent = e.message
    return
  }

  const state = s.state || 'stopped'
  const pill = $('state-pill')
  pill.textContent = { idle: 'Daily', boost: 'Unlocked', relaxed: 'Relaxed', safety: 'Protected', suspended: 'Flux required', disabled: 'Off', stopped: 'Stopped' }[state] || state
  pill.className = `pill ${state}`
  $('state-text').textContent = (STATE_TEXT[state] || (() => state))(s)
  $('state-since').textContent = s.since && s.since !== '0' ? `since ${new Date(s.since * 1000).toLocaleTimeString()}` : ''

  const temps = [
    ['t-cpu', s.cpu_temp, 85],
    ['t-gpu', s.gpu_temp, 85],
    ['t-bat', s.battery_temp, 43],
  ]
  for (const [id, value, hot] of temps) {
    $(id).textContent = formatTemp(value)
    $(id).classList.toggle('hot', value && Number(value) >= hot)
  }

  const unlocked = state === 'boost'
  $('unlock-details').hidden = !(unlocked || state === 'safety' || state === 'relaxed')
  for (const key of ['services', 'zones', 'cooling', 'caps', 'vendor', 'configs', 'trips']) $(`d-${key}`).textContent = s[key] ?? '0'
  // Each level shows what it changes: max unlocks the thermal stack, relaxed tunes its configs.
  const relaxed = state === 'relaxed' || (state === 'safety' && s.level === 'relaxed')
  for (const key of ['services', 'zones', 'cooling', 'caps', 'vendor']) $(`d-${key}`).parentElement.hidden = relaxed
  $('d-configs').parentElement.hidden = !relaxed

  const fluxReady = s.flux === 'ready'
  $('flux-banner').hidden = fluxReady
  if (!fluxReady) {
    $('flux-banner-text').replaceChildren(
      FLUX_REASONS[s.flux] || `Flux status: ${s.flux}.`,
      ' ',
      el('a', { href: FLUX_RELEASES, target: '_blank', rel: 'noopener' }, 'Get Flux Tweaks'),
    )
  }
  $('flux-line').textContent = fluxReady ? `Linked to Flux Tweaks ${s.flux_version || ''}` : ''
  $('device-line').textContent =
    s.device_profile === 'verified'
      ? `Device profile: ${s.device_name || s.device} (${s.device}), from its stock firmware`
      : `No device profile for ${s.device || 'this device'}: runtime detection only`
  if (s.rom_name) $('device-line').textContent += ` · ROM: ${s.rom_name}`
  $('version').textContent = s.version || ''
}

// ── Settings ────────────────────────────────────────────────────────────────

const PACKAGE_LIST = /^[A-Za-z0-9._,\s]*$/

async function setConfig(key, value) {
  // Values are restricted to [A-Za-z0-9._,] before reaching the shell; hicod validates again.
  const safe = String(value).replace(/\s+/g, '')
  if (!/^[A-Za-z0-9._,]*$/.test(safe)) {
    toast('Invalid value')
    return false
  }
  const { errno, stderr } = await exec(`${HICOD} config set ${key} '${safe}'`)
  if (errno !== 0) {
    toast(stderr.trim() || 'Could not save')
    await loadSettings()
    return false
  }
  toast('Saved')
  setTimeout(refreshStatus, 500)
  return true
}

function control(item) {
  const { key, type, min, max, value } = item

  if (type === 'bool') {
    const input = el('input', { type: 'checkbox' })
    input.checked = value === '1'
    input.addEventListener('change', () => setConfig(key, input.checked ? '1' : '0'))
    return el('label', { class: 'switch' }, input, el('span'))
  }

  if (type === 'mode') {
    const select = el('select', {}, el('option', { value: 'auto' }, 'Automatic'), el('option', { value: 'off' }, 'Off'))
    select.value = value
    select.addEventListener('change', () => setConfig(key, select.value))
    return select
  }

  if (type === 'level') {
    const select = el('select', {}, el('option', { value: 'max' }, 'Max (games)'), el('option', { value: 'relaxed' }, 'Relaxed'))
    select.value = value
    select.addEventListener('change', () => setConfig(key, select.value))
    return select
  }

  if (type === 'int') {
    const input = el('input', { type: 'number', min: String(min), max: String(max), step: '1', inputmode: 'numeric' })
    input.value = value
    input.addEventListener('change', () => {
      const n = Math.round(Number(input.value))
      if (!Number.isFinite(n) || n < min || n > max) {
        toast(`Allowed range: ${min} – ${max}`)
        input.value = value
        return
      }
      setConfig(key, String(n))
    })
    return input
  }

  const placeholder = key === 'whitelist' ? 'com.android.camera, com.example.app' : 'com.example.game, com.other.app'
  const input = el('input', { type: 'text', placeholder, autocapitalize: 'off', spellcheck: 'false' })
  input.value = value.split(',').join(', ')
  input.addEventListener('change', () => {
    if (!PACKAGE_LIST.test(input.value)) {
      toast('Only package names separated by commas')
      return
    }
    setConfig(key, input.value)
  })
  return input
}

async function loadSettings() {
  const container = $('settings')
  let schema
  try {
    const { stdout } = await exec(`${HICOD} config schema`)
    schema = JSON.parse(stdout)
  } catch (e) {
    container.textContent = e.message
    return
  }

  const byKey = Object.fromEntries(schema.map((item) => [item.key, item]))
  const nodes = []
  for (const [title, keys] of GROUPS) {
    nodes.push(el('h3', { class: 'group-title' }, title))
    for (const key of keys) {
      const item = byKey[key]
      if (!item) continue
      const range = item.type === 'int' ? ` (${item.min}–${item.max})` : ''
      nodes.push(
        el(
          'div',
          { class: 'setting' },
          el('span', { class: 'name' }, LABELS[key] || key),
          control(item),
          el('span', { class: 'help' }, item.help + range),
        ),
      )
    }
  }
  container.replaceChildren(...nodes)
}

// ── Sessions ────────────────────────────────────────────────────────────────

async function loadSessions() {
  const { stdout } = await exec(`${HICOD} sessions`).catch(() => ({ stdout: '' }))
  const rows = stdout
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

  const container = $('sessions')
  if (!rows.length) {
    container.replaceChildren(el('p', { class: 'muted' }, "No sessions yet. Launch a game from Flux's game list."))
    return
  }

  const stat = (label, value) => el('div', { class: 'stat' }, el('span', { class: 'label' }, label), el('span', {}, value))
  const items = rows.slice(0, 30).map((r) =>
    el(
      'li',
      { class: 'session' },
      el('div', { class: 'game' }, r.game),
      el('div', { class: 'muted small' }, new Date(r.start * 1000).toLocaleString()),
      el(
        'div',
        { class: 'stats' },
        stat('Played', formatDuration(r.duration)),
        stat('Unlocked', formatDuration(r.boosted)),
        stat('Peak CPU', formatTemp(r.peak_cpu)),
        stat('Peak bat.', formatTemp(r.peak_battery)),
        stat('Trips', String(r.trips)),
      ),
    ),
  )
  container.replaceChildren(el('ul', { class: 'sessions' }, ...items))
}

async function loadLog() {
  const { stdout } = await exec(`tail -n 150 ${LOG_FILE} 2>/dev/null`).catch(() => ({ stdout: '' }))
  $('log').textContent = stdout || 'Empty'
}

// ── Wiring ──────────────────────────────────────────────────────────────────

$('reset-settings').addEventListener('click', async () => {
  if (!confirm('Restore every HiCo setting to its default?')) return
  await exec(`${HICOD} config reset`)
  toast('Defaults restored')
  loadSettings()
})

$('clear-sessions').addEventListener('click', async () => {
  if (!confirm('Delete the game session history?')) return
  await exec(`${HICOD} sessions clear`)
  loadSessions()
})

$('restart').addEventListener('click', async () => {
  await exec(`${HICOD} restore >/dev/null 2>&1; ${HICOD} daemon`)
  toast('Service restarted')
  setTimeout(refreshStatus, 800)
})

$('restore').addEventListener('click', async () => {
  const { stdout } = await exec(`${HICOD} restore`)
  toast(stdout.trim() || 'Stock thermal restored')
  refreshStatus()
})

document.querySelector('details').addEventListener('toggle', (e) => {
  if (e.target.open) loadLog()
})

let timer = null
function schedule() {
  clearInterval(timer)
  if (!document.hidden) timer = setInterval(refreshStatus, 2000)
}
document.addEventListener('visibilitychange', () => {
  schedule()
  if (!document.hidden) {
    refreshStatus()
    loadSessions()
  }
})

refreshStatus()
loadSettings()
loadSessions()
schedule()
