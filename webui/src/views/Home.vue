<template>
  <div class="page h-full flex flex-col overflow-hidden">
    <div class="scrollbar-hidden pb-safe-nav flex-1 min-h-0 overflow-y-scroll">
      <div class="max-w-3xl mx-auto px-4 pt-6 pb-6 space-y-3">
        <!-- Header -->
        <div class="flex items-end justify-between px-1 mb-2">
          <div>
            <h1 class="m3-headline text-[32px] text-on-surface leading-none">HiCo Thermal</h1>
            <p class="text-sm text-on-surface-variant mt-1">{{ $t('home.tagline') }}</p>
          </div>
          <span class="chip whitespace-nowrap bg-surface-container-high text-on-surface-variant"
            >v{{ s.version || '–' }}</span
          >
        </div>

        <!-- Service not running -->
        <div
          v-if="loaded && !hico.running"
          class="banner bg-error-container text-on-error-container"
        >
          <WarningIcon class="shrink-0" :size="22" />
          <div class="flex-1">
            <p class="text-sm font-semibold">{{ $t('home.stopped.title') }}</p>
            <p class="text-xs mt-1 opacity-90">{{ $t('home.stopped.description') }}</p>
          </div>
          <button class="btn-tonal m3-press" @click="restart">{{ $t('actions.restart') }}</button>
        </div>

        <!-- Flux not ready -->
        <div
          v-else-if="loaded && s.flux && s.flux !== 'ready'"
          class="banner bg-tertiary-container text-on-tertiary-container"
        >
          <InformationOutlineIcon class="shrink-0" :size="22" />
          <div class="flex-1">
            <p class="text-sm font-semibold">{{ $t('home.flux.title') }}</p>
            <p class="text-xs mt-1 opacity-90">
              {{ $t('home.flux.description', { state: s.flux }) }}
            </p>
          </div>
        </div>

        <!-- State hero -->
        <section class="hero m3-enter" :class="stateInfo.card">
          <div class="flex items-center gap-4">
            <span class="hero-badge" :class="[stateInfo.shape, stateInfo.badge]">
              <component :is="stateInfo.icon" :size="30" />
            </span>
            <div class="flex-1 min-w-0">
              <p class="text-xs font-semibold uppercase tracking-widest opacity-70">
                {{ $t('home.state') }}
              </p>
              <h2 class="m3-headline text-2xl leading-tight">
                {{ $t(`state.${stateKey}.title`) }}
              </h2>
            </div>
            <span v-if="s.mode === 'extreme'" class="chip bg-tertiary text-on-tertiary">{{
              $t('mode.extreme.title')
            }}</span>
          </div>
          <p class="text-sm mt-3 opacity-90 leading-relaxed">
            {{ $t(`state.${stateKey}.description`) }}
          </p>

          <div v-if="s.game" class="game-row mt-4">
            <img :src="apps.icon(s.game)" class="w-10 h-10 rounded-xl" alt="" @error="iconError" />
            <div class="flex-1 min-w-0">
              <p class="text-sm font-semibold truncate">{{ apps.label(s.game) }}</p>
              <p class="text-xs opacity-70">
                {{ $t('home.level', { level: $t(`level.${s.level || 'max'}`) }) }}
                <span v-if="sinceText"> · {{ sinceText }}</span>
              </p>
            </div>
          </div>

          <!-- What is changed right now -->
          <div v-if="changes.length" class="flex flex-wrap gap-1.5 mt-3">
            <span v-for="c in changes" :key="c.key" class="chip bg-surface/40">
              {{ $t(`changes.${c.key}`, { n: c.n }) }}
            </span>
          </div>
        </section>

        <!-- Temperatures against the safety limits -->
        <section class="m3-card p-5">
          <div class="flex items-center justify-between mb-4">
            <h3 class="text-sm font-semibold text-primary">{{ $t('home.temps') }}</h3>
            <button
              class="text-on-surface-variant"
              :aria-label="$t('home.temps_info')"
              @click="tempsInfo"
            >
              <InformationOutlineIcon :size="20" />
            </button>
          </div>
          <div class="space-y-4">
            <div v-for="m in meters" :key="m.key">
              <div class="flex justify-between text-sm mb-1.5">
                <span class="text-on-surface-variant">{{ $t(`home.${m.key}`) }}</span>
                <span class="font-semibold tabular-nums" :class="m.tone">
                  {{ m.value === null ? '–' : `${m.value.toFixed(1)} °C` }}
                  <span v-if="m.limit" class="text-on-surface-variant font-normal">
                    / {{ m.limit }} °C</span
                  >
                </span>
              </div>
              <div class="meter">
                <div class="meter-fill" :class="m.fill" :style="{ width: `${m.pct}%` }" />
                <div v-if="m.limit" class="meter-limit" :style="{ left: `${m.limitPct}%` }" />
              </div>
            </div>
          </div>
        </section>

        <!-- Mode -->
        <section class="m3-card p-5">
          <h3 class="text-sm font-semibold text-primary mb-3">{{ $t('home.mode') }}</h3>
          <div class="segmented" role="radiogroup">
            <button
              v-for="m in ['off', 'auto', 'extreme']"
              :key="m"
              role="radio"
              :aria-checked="hico.config.mode === m"
              class="seg m3-press"
              :class="{ on: hico.config.mode === m, extreme: m === 'extreme' }"
              @click="actions.setMode(m)"
            >
              {{ $t(`mode.${m}.title`) }}
            </button>
          </div>
          <p class="text-xs text-on-surface-variant mt-3 leading-relaxed">
            {{ $t(`mode.${hico.config.mode || 'auto'}.description`) }}
          </p>
        </section>

        <!-- Template -->
        <RippleComponent
          class="m3-card p-5 block"
          tabindex="0"
          @click="router.push('/settings/presets')"
        >
          <div class="flex items-center gap-4">
            <span class="badge" :class="[preset.shape, preset.tone]"
              ><component :is="preset.icon" :size="22"
            /></span>
            <div class="flex-1 min-w-0">
              <p class="text-xs text-on-surface-variant">{{ $t('home.preset') }}</p>
              <p class="text-base font-semibold text-on-surface">{{ presetTitle }}</p>
            </div>
            <ChevronRightIcon class="text-on-surface-variant rtl:rotate-180" :size="22" />
          </div>
        </RippleComponent>

        <!-- Device -->
        <section class="m3-card p-5">
          <div class="flex items-center justify-between mb-3">
            <h3 class="text-sm font-semibold text-primary">{{ $t('home.device') }}</h3>
            <span
              class="chip"
              :class="
                verified
                  ? 'bg-primary-container text-on-primary-container'
                  : 'bg-surface-container-highest text-on-surface-variant'
              "
              >{{ verified ? $t('device.verified') : $t('device.generic') }}</span
            >
          </div>
          <p class="text-lg font-semibold text-on-surface">
            {{ s.device_name || s.device || '–' }}
          </p>
          <p class="text-xs text-on-surface-variant font-mono mt-0.5">
            {{ s.device || '–' }}<span v-if="s.device_source"> · {{ s.device_source }}</span>
          </p>
          <div class="facts mt-4">
            <div v-for="f in facts" :key="f.key" class="fact">
              <span class="text-[11px] text-on-surface-variant">{{ $t(`device.${f.key}`) }}</span>
              <span class="text-sm font-semibold text-on-surface truncate">{{
                f.value || '–'
              }}</span>
            </div>
          </div>
          <p
            v-if="loaded && !verified"
            class="text-xs text-on-surface-variant mt-4 leading-relaxed"
          >
            {{ $t('device.generic_hint') }}
          </p>
        </section>
      </div>
    </div>
  </div>
</template>

<script setup>
import { computed, onMounted, onActivated, onDeactivated, onUnmounted, ref } from 'vue'
import { useRouter } from 'vue-router'
import { useI18n } from 'vue-i18n'
import { useHiCoStore } from '@/stores/HiCo'
import { useAppsStore } from '@/stores/Apps'
import { useNotifyStore } from '@/stores/Notify'
import { useSettingsActions } from '@/composables/useSettingsActions'
import { PRESET_STYLE } from '@/helpers/presets'

import RippleComponent from '@/components/ui/Ripple.vue'
import WarningIcon from '@/components/icons/Warning.vue'
import InformationOutlineIcon from '@/components/icons/InformationOutline.vue'
import ChevronRightIcon from '@/components/icons/ChevronRight.vue'
import FlameIcon from '@/components/icons/Flame.vue'
import SnowflakeIcon from '@/components/icons/Snowflake.vue'
import ShieldIcon from '@/components/icons/Shield.vue'
import PauseIcon from '@/components/icons/Pause.vue'
import ThermostatIcon from '@/components/icons/Thermostat.vue'
import LeafIcon from '@/components/icons/Leaf.vue'

const router = useRouter()
const { t, locale } = useI18n()
const hico = useHiCoStore()
const apps = useAppsStore()
const notify = useNotifyStore()
const actions = useSettingsActions()

const loaded = ref(false)
const s = computed(() => hico.status)

const STATES = {
  boost: {
    icon: FlameIcon,
    shape: 'shape-sunny',
    card: 'bg-primary-container text-on-primary-container',
    badge: 'bg-primary text-on-primary',
  },
  relaxed: {
    icon: LeafIcon,
    shape: 'shape-flower',
    card: 'bg-secondary-container text-on-secondary-container',
    badge: 'bg-secondary text-on-secondary',
  },
  safety: {
    icon: ShieldIcon,
    shape: 'shape-cookie6',
    card: 'bg-error-container text-on-error-container',
    badge: 'bg-error text-on-error',
  },
  idle: {
    icon: SnowflakeIcon,
    shape: 'shape-cookie9',
    card: 'bg-surface-container-high text-on-surface',
    badge: 'bg-surface-container-highest text-on-surface',
  },
  suspended: {
    icon: PauseIcon,
    shape: 'shape-clover4',
    card: 'bg-tertiary-container text-on-tertiary-container',
    badge: 'bg-tertiary text-on-tertiary',
  },
  disabled: {
    icon: PauseIcon,
    shape: 'shape-clover4',
    card: 'bg-surface-container-high text-on-surface',
    badge: 'bg-surface-container-highest text-on-surface',
  },
  stopped: {
    icon: WarningIcon,
    shape: 'shape-burst',
    card: 'bg-error-container text-on-error-container',
    badge: 'bg-error text-on-error',
  },
}
const stateKey = computed(() => (s.value.state in STATES ? s.value.state : 'idle'))
const stateInfo = computed(() => STATES[stateKey.value] || STATES.idle)

const changes = computed(() => {
  if (!['boost', 'relaxed'].includes(stateKey.value)) return []
  const keys = ['services', 'zones', 'cooling', 'caps', 'vendor', 'configs', 'raised_trips']
  const out = keys.map((key) => ({ key, n: Number(s.value[key] || 0) })).filter((c) => c.n > 0)
  if (s.value.overclock === '1') out.push({ key: 'overclock', n: 1 })
  return out
})

const sinceText = computed(() => {
  const since = Number(s.value.since || 0)
  if (!since) return ''
  const secs = Math.max(0, Math.round(Date.now() / 1000 - since))
  const m = Math.floor(secs / 60)
  return m ? t('home.for_min', { m }) : t('home.for_sec', { s: secs })
})

const num = (v) => (v === undefined || v === '' || v === null ? null : Number(v))
const meters = computed(() => {
  const limits = {
    cpu: Number(hico.config.safety_cpu_temp || 95),
    battery: Number(hico.config.safety_battery_temp || 46),
  }
  return [
    { key: 'cpu', value: num(s.value.cpu_temp), limit: limits.cpu, scale: 110 },
    { key: 'gpu', value: num(s.value.gpu_temp), limit: null, scale: 110 },
    { key: 'battery', value: num(s.value.battery_temp), limit: limits.battery, scale: 55 },
  ].map((m) => {
    const ratio = m.value === null ? 0 : m.limit ? m.value / m.limit : m.value / 95
    return {
      ...m,
      pct: Math.min(100, ((m.value || 0) / m.scale) * 100),
      limitPct: m.limit ? Math.min(100, (m.limit / m.scale) * 100) : 0,
      tone: ratio >= 0.95 ? 'text-error' : ratio >= 0.85 ? 'text-tertiary' : 'text-on-surface',
      fill: ratio >= 0.95 ? 'bg-error' : ratio >= 0.85 ? 'bg-tertiary' : 'bg-primary',
    }
  })
})

const verified = computed(() => s.value.device_profile === 'verified')
const facts = computed(() => [
  { key: 'soc', value: s.value.soc },
  { key: 'rom', value: s.value.rom_name || s.value.rom },
  { key: 'flux', value: s.value.flux_version || s.value.flux },
  { key: 'backends', value: (s.value.backends || '').replace(/,/g, ', ') },
])

const preset = computed(() => PRESET_STYLE[hico.currentPreset] || PRESET_STYLE.balanced)
const presetTitle = computed(() =>
  hico.currentPreset in PRESET_STYLE
    ? t(`presets.${hico.currentPreset}.title`)
    : t('presets.custom'),
)

function tempsInfo() {
  notify.confirm({
    tone: 'info',
    title: t('home.temps'),
    message: t('home.temps_info'),
    cancelText: null,
  })
}

async function restart() {
  try {
    await hico.restart()
    notify.success(t('actions.restarted'))
  } catch (e) {
    notify.error(t('notify.failed', { error: e.message }))
  }
  refresh()
}

async function refresh() {
  await hico.refreshStatus()
  if (s.value.game) apps.resolve([s.value.game])
  loaded.value = true
}

let timer = null
const start = () => {
  stop()
  refresh()
  timer = setInterval(refresh, 3000)
}
const stop = () => timer && clearInterval(timer)
onMounted(() => {
  hico.loadConfig()
  start()
})
onActivated(start)
onDeactivated(stop)
onUnmounted(stop)

const iconError = (e) => (e.target.src = './app_icon_fallback.avif')
void locale
</script>

<style scoped>
.chip {
  font-size: 11px;
  font-weight: 700;
  padding: 3px 10px;
  border-radius: 999px;
}

.banner {
  display: flex;
  gap: 12px;
  align-items: center;
  padding: 16px;
  border-radius: 24px;
}

.btn-tonal {
  flex-shrink: 0;
  padding: 8px 14px;
  border-radius: 999px;
  font-size: 13px;
  font-weight: 650;
  background: var(--color-surface);
  color: var(--color-on-surface);
}

.hero {
  padding: 20px;
  border-radius: 32px;
}

.hero-badge {
  width: 60px;
  height: 60px;
  display: grid;
  place-items: center;
  flex-shrink: 0;
}

.game-row {
  display: flex;
  align-items: center;
  gap: 12px;
  padding: 10px 12px;
  border-radius: 20px;
  background: color-mix(in srgb, var(--color-surface) 35%, transparent);
}

.badge {
  width: 44px;
  height: 44px;
  display: grid;
  place-items: center;
  flex-shrink: 0;
}

.meter {
  position: relative;
  height: 10px;
  border-radius: 999px;
  background: var(--color-surface-container-highest);
  overflow: visible;
}

.meter-fill {
  height: 100%;
  border-radius: 999px;
  transition: width var(--m3-spring-default-spatial-duration) var(--m3-spring-default-spatial);
}

.meter-limit {
  position: absolute;
  top: -3px;
  bottom: -3px;
  width: 3px;
  border-radius: 2px;
  background: var(--color-error);
}

.segmented {
  display: flex;
  gap: 2px;
}

.seg {
  flex: 1;
  padding: 10px 8px;
  font-size: 14px;
  font-weight: 600;
  color: var(--color-on-surface-variant);
  background: var(--color-surface-container-highest);
  border-radius: 8px;
  transition:
    border-radius var(--m3-spring-fast-spatial-duration) var(--m3-spring-fast-spatial),
    background-color var(--m3-spring-fast-effects-duration) var(--m3-spring-fast-effects);
}

.seg:first-child {
  border-radius: 20px 8px 8px 20px;
}

.seg:last-child {
  border-radius: 8px 20px 20px 8px;
}

.seg.on {
  border-radius: 999px;
  background: var(--color-primary);
  color: var(--color-on-primary);
}

.seg.on.extreme {
  background: var(--color-tertiary);
  color: var(--color-on-tertiary);
}

.facts {
  display: grid;
  grid-template-columns: 1fr 1fr;
  gap: 8px;
}

.fact {
  display: flex;
  flex-direction: column;
  gap: 2px;
  min-width: 0;
  padding: 10px 12px;
  border-radius: 16px;
  background: var(--color-surface-container-high);
}
</style>
