import { defineStore } from 'pinia'
import { ref, computed } from 'vue'
import { exec } from 'kernelsu'

export const HICOD = '/data/adb/modules/hico/system/bin/hicod'
const LOG_FILE = '/data/adb/.config/hico/hico.log'
const FLUX_GAMELIST = '/data/adb/.config/flux/gamelist.json'

/** Values go through hicod, which validates them again; quotes are never passed through. */
const quote = (v) => `'${String(v).replace(/'/g, '')}'`

async function run(cmd) {
  const { errno, stdout, stderr } = await exec(cmd)
  if (errno !== 0) throw new Error((stderr || stdout || `exit ${errno}`).trim())
  return stdout || ''
}

/**
 * Everything the WebUI knows about hicod: live status, settings (schema with
 * values), presets, the Flux game list and HiCo's session history.
 */
export const useHiCoStore = defineStore('hico', () => {
  const status = ref({})
  const schema = ref([])
  const presets = ref([])
  const currentPreset = ref('custom')
  const games = ref([])
  const sessions = ref([])
  const loaded = ref(false)

  const config = computed(() => Object.fromEntries(schema.value.map((k) => [k.key, k.value])))
  const running = computed(() => status.value.running === '1')
  const list = (key) => (config.value[key] || '').split(',').filter(Boolean)
  const blacklist = computed(() => list('blacklist'))
  const whitelist = computed(() => list('whitelist'))

  async function refreshStatus() {
    try {
      status.value = JSON.parse(await run(`${HICOD} status --json`))
    } catch {
      // hicod exits 1 when the service is stopped but still prints the JSON
      try {
        const { stdout } = await exec(`${HICOD} status --json`)
        status.value = JSON.parse(stdout)
      } catch {
        status.value = { state: 'stopped', running: '0' }
      }
    }
  }

  async function loadConfig() {
    try {
      schema.value = JSON.parse(await run(`${HICOD} config schema`))
      const p = JSON.parse(await run(`${HICOD} config presets`))
      presets.value = p.presets
      currentPreset.value = p.current
    } catch (e) {
      console.error('config:', e)
    }
    loaded.value = true
  }

  async function set(key, value) {
    await run(`${HICOD} config set ${key} ${quote(value)}`)
    await loadConfig()
  }

  async function applyPreset(name) {
    await run(`${HICOD} config preset ${quote(name)}`)
    await loadConfig()
  }

  async function setListed(key, pkg, on) {
    const current = list(key).filter((p) => p !== pkg)
    if (on) current.push(pkg)
    await set(key, current.join(','))
  }

  async function loadGames() {
    try {
      games.value = Object.keys(JSON.parse(await run(`cat ${FLUX_GAMELIST}`)) || {}).sort()
    } catch {
      games.value = []
    }
  }

  async function loadSessions() {
    try {
      sessions.value = (await run(`${HICOD} sessions`))
        .split('\n')
        .filter(Boolean)
        .map((l) => {
          try {
            return JSON.parse(l)
          } catch {
            return null
          }
        })
        .filter(Boolean)
        .reverse()
    } catch {
      sessions.value = []
    }
  }

  const monitor = () => run(`${HICOD} monitor --json`).then((s) => JSON.parse(s))
  const log = (lines = 200) => run(`tail -n ${lines} ${LOG_FILE} 2>/dev/null`)
  // One text file in Download for bug reports: state, device, settings and the whole
  // log (with the part rotated to .old). Prints the path.
  const saveLog = () =>
    run(
      'd=/sdcard/Download; mkdir -p "$d"; ' +
        'dev=$(getprop ro.product.vendor.device); [ -n "$dev" ] || dev=$(getprop ro.product.device); ' +
        'f="$d/hico_log_${dev:-device}_$(date +%Y-%m-%d_%H-%M-%S).txt"; ' +
        `{ echo "== status"; ${HICOD} status 2>&1; echo; echo "== device"; ${HICOD} device 2>&1; ` +
        `echo; echo "== config"; ${HICOD} config list 2>&1; echo; echo "== log"; ` +
        `cat ${LOG_FILE}.old ${LOG_FILE} 2>/dev/null; } >"$f" && echo "$f"`,
    ).then((s) => s.trim())
  const restart = () => run(`${HICOD} restore >/dev/null 2>&1; ${HICOD} daemon`)
  const restore = () => run(`${HICOD} restore`)
  const reset = () => run(`${HICOD} config reset`).then(loadConfig)
  const clearSessions = () => run(`${HICOD} sessions clear`).then(loadSessions)

  return {
    status,
    schema,
    presets,
    currentPreset,
    config,
    games,
    sessions,
    loaded,
    running,
    blacklist,
    whitelist,
    refreshStatus,
    saveLog,
    loadConfig,
    set,
    applyPreset,
    setListed,
    loadGames,
    loadSessions,
    monitor,
    log,
    restart,
    restore,
    reset,
    clearSessions,
  }
})
