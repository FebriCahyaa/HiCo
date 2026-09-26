<template>
  <div class="page h-full flex flex-col overflow-hidden">
    <div class="scrollbar-hidden pb-safe-nav flex-1 min-h-0 overflow-y-scroll">
      <div class="max-w-4xl mx-auto px-4 pt-6 pb-6 space-y-3">
        <div class="flex items-end justify-between px-1 mb-2">
          <h1 class="m3-headline text-[32px] text-on-surface leading-none">
            {{ $t('monitor.title') }}
          </h1>
          <button class="live m3-press" :class="{ paused }" @click="paused = !paused">
            <span class="dot" />{{ paused ? $t('monitor.paused') : $t('monitor.live') }}
          </button>
        </div>

        <LoadingSpinner v-if="!snap && !error" class="pt-10" :size="48" />
        <div v-else-if="error" class="m3-card p-5 text-sm text-on-surface-variant">{{ error }}</div>

        <template v-else>
          <section class="hero" :class="verdict.card">
            <p class="text-xs font-semibold uppercase tracking-widest opacity-70">
              {{ $t('monitor.verdict') }}
            </p>
            <h2 class="m3-headline text-2xl mt-1">{{ $t(`monitor.v.${snap.verdict}.title`) }}</h2>
            <p class="text-sm mt-1 opacity-90">{{ $t(`monitor.v.${snap.verdict}.description`) }}</p>

            <div class="grid grid-cols-2 md:grid-cols-4 gap-2 mt-4">
              <div class="stat">
                <span class="text-xs opacity-70">{{ $t('monitor.hottest') }}</span>
                <span class="m3-headline text-xl tabular-nums">{{ formatTemp(snap.hottest?.temp) }}</span>
                <span class="text-xs text-on-surface-variant truncate">{{ snap.hottest?.type || '–' }}</span>
              </div>
              <div class="stat">
                <span class="text-xs opacity-70">{{ $t('monitor.next_trip') }}</span>
                <span class="m3-headline text-xl tabular-nums">{{ formatTemp(snap.closest?.trip) }}</span>
                <span class="text-xs text-on-surface-variant tabular-nums">
                  {{ formatHeadroom(snap.closest?.headroom) }}
                </span>
              </div>
              <div class="stat">
                <span class="text-xs opacity-70">{{ $t('monitor.zone_count') }}</span>
                <span class="m3-headline text-xl tabular-nums">{{ snap.zone_count }}</span>
                <span class="text-xs text-on-surface-variant"
                  >{{ snap.zones_at_or_above_trip }} {{ $t('monitor.at_trip') }}</span
                >
              </div>
              <div class="stat">
                <span class="text-xs opacity-70">{{ $t('monitor.active_cooling') }}</span>
                <span class="m3-headline text-xl tabular-nums">{{ snap.active_cooling }}</span>
                <span class="text-xs text-on-surface-variant"
                  >{{ snap.protected_zones }} {{ $t('monitor.protected') }}</span
                >
              </div>
            </div>
          </section>

          <section class="m3-card p-5">
            <div class="flex items-center justify-between mb-2">
              <h3 class="text-sm font-semibold text-primary">{{ $t('monitor.temp_chart') }}</h3>
              <span class="legend"><i class="bg-primary" />{{ $t('monitor.hottest') }} <i class="bg-secondary" />{{ $t('home.battery') }}</span>
            </div>
            <LineChart
              :series="tempSeries"
              :height="110"
              unit="°C"
              :label="$t('monitor.temp_chart')"
            />
          </section>

          <section class="m3-card p-5">
            <div class="flex items-center justify-between mb-3">
              <div>
                <h3 class="text-sm font-semibold text-primary">{{ $t('monitor.zones') }}</h3>
                <p class="text-xs text-on-surface-variant mt-1">
                  {{ $t('monitor.zones_description') }}
                </p>
              </div>
              <span class="text-xs tabular-nums text-on-surface-variant"
                >{{ snap.zone_count }} {{ $t('monitor.zone_count_label') }}</span
              >
            </div>

            <div class="table-wrap">
              <table class="thermal-table">
                <thead>
                  <tr>
                    <th>{{ $t('monitor.zone') }}</th>
                    <th>{{ $t('monitor.type') }}</th>
                    <th>{{ $t('monitor.temperature') }}</th>
                    <th>{{ $t('monitor.passive') }}</th>
                    <th>{{ $t('monitor.hot') }}</th>
                    <th>{{ $t('monitor.critical') }}</th>
                    <th>{{ $t('monitor.highest') }}</th>
                    <th>{{ $t('monitor.next') }}</th>
                    <th>{{ $t('monitor.headroom') }}</th>
                    <th>{{ $t('monitor.state') }}</th>
                    <th>{{ $t('monitor.protected') }}</th>
                    <th>{{ $t('monitor.policy') }}</th>
                  </tr>
                </thead>
                <tbody>
                  <tr v-for="z in snap.zones" :key="z.name">
                    <td class="font-medium">{{ z.name }}</td>
                    <td class="muted">{{ z.type }}</td>
                    <td class="tabular-nums">{{ formatTemp(z.temp) }}</td>
                    <td class="tabular-nums">{{ formatTemp(z.passive) }}</td>
                    <td class="tabular-nums">{{ formatTemp(z.hot) }}</td>
                    <td class="tabular-nums">{{ formatTemp(z.critical) }}</td>
                    <td class="tabular-nums">{{ formatTemp(z.highest) }}</td>
                    <td class="tabular-nums">{{ formatTemp(z.next) }}</td>
                    <td class="tabular-nums">{{ formatHeadroom(z.headroom) }}</td>
                    <td><span class="state-pill" :class="stateClass(z.state)">{{ z.state }}</span></td>
                    <td>{{ z.protected ? $t('monitor.yes') : $t('monitor.no') }}</td>
                    <td class="muted">{{ z.policy || '–' }}</td>
                  </tr>
                </tbody>
              </table>
            </div>
          </section>

          <section class="grid md:grid-cols-2 gap-3">
            <div class="m3-card p-5">
              <h3 class="text-sm font-semibold text-primary mb-3">{{ $t('monitor.cooling') }}</h3>
              <div v-if="snap.cooling_devices?.length" class="space-y-1">
                <div v-for="c in snap.cooling_devices" :key="c.name" class="row">
                  <span class="text-sm text-on-surface truncate">{{ c.type || c.name }}</span>
                  <span class="text-xs tabular-nums" :class="c.active ? 'text-primary' : 'text-on-surface-variant'">{{ c.active ? $t('monitor.active') : $t('monitor.idle') }} · {{ c.cur }} / {{ c.max }}</span>
                </div>
              </div>
              <p v-else class="text-xs text-on-surface-variant">{{ $t('monitor.no_cooling') }}</p>
            </div>

            <div class="m3-card p-5">
              <h3 class="text-sm font-semibold text-primary mb-3">{{ $t('monitor.trip_zones') }}</h3>
              <div v-if="tripped.length" class="space-y-1">
                <div v-for="z in tripped" :key="`trip-${z.name}`" class="row">
                  <span class="text-sm text-on-surface truncate">{{ z.type }}</span>
                  <span class="text-xs text-error tabular-nums">{{ formatTemp(z.temp) }}</span>
                </div>
              </div>
              <p v-else class="text-xs text-on-surface-variant">{{ $t('monitor.no_trip_zones') }}</p>
            </div>
          </section>
        </template>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref, computed, onMounted, onActivated, onDeactivated, onUnmounted } from 'vue'
import { useI18n } from 'vue-i18n'
import { useHiCoStore } from '@/stores/HiCo'
import LineChart from '@/components/ui/LineChart.vue'
import LoadingSpinner from '@/components/ui/LoadingSpinner.vue'

const { t } = useI18n()
const hico = useHiCoStore()

const snap = ref(null)
const error = ref('')
const paused = ref(false)
const history = ref([])
const HISTORY = 60

const verdictClasses = {
  normal: 'bg-primary-container text-on-primary-container',
  elevated: 'bg-tertiary-container text-on-tertiary-container',
  mitigating: 'bg-secondary-container text-on-secondary-container',
  critical: 'bg-error-container text-on-error-container',
}
const verdict = computed(() => ({ card: verdictClasses[snap.value?.verdict] || verdictClasses.normal }))

const series = (pick) => history.value.map((h) => pick(h) ?? null)
const tempSeries = computed(() => [
  { values: series((h) => h.hottest?.temp), color: 'var(--color-primary)', area: true },
  { values: series((h) => h.temperatures?.battery), color: 'var(--color-secondary)' },
])

const tripped = computed(() => (snap.value?.zones || []).filter((z) => z.at_or_above_trip))

const formatTemp = (value) => (value === null || value === undefined ? '–' : `${Number(value).toFixed(1)} °C`)
const formatHeadroom = (value) => (value === null || value === undefined ? '–' : `${Number(value).toFixed(1)} °C`)
const stateClass = (state) =>
  ({
    normal: 'state-normal',
    elevated: 'state-elevated',
    mitigating: 'state-mitigating',
    critical: 'state-critical',
  })[state] || 'state-unknown'

async function tick() {
  if (paused.value || document.hidden) return
  try {
    const s = await hico.monitor()
    snap.value = s
    history.value = [...history.value.slice(-(HISTORY - 1)), s]
    error.value = ''
  } catch (e) {
    if (!snap.value) error.value = t('monitor.error', { error: e.message })
  }
}

let timer = null
const start = () => {
  stop()
  tick()
  timer = setInterval(tick, 1000)
}
const stop = () => {
  if (timer) {
    clearInterval(timer)
    timer = null
  }
}
onMounted(start)
onActivated(start)
onDeactivated(stop)
onUnmounted(stop)
</script>

<style scoped>
.hero {
  padding: 20px;
  border-radius: 32px;
}

.stat {
  display: flex;
  flex-direction: column;
  padding: 12px 14px;
  border-radius: 20px;
  background: color-mix(in srgb, var(--color-surface) 35%, transparent);
}

.live {
  display: inline-flex;
  align-items: center;
  gap: 6px;
  font-size: 13px;
  font-weight: 600;
  color: var(--color-primary);
}

.live .dot {
  width: 8px;
  height: 8px;
  border-radius: 999px;
  background: var(--color-primary);
  animation: pulse 1.4s ease-in-out infinite;
}

.live.paused {
  color: var(--color-on-surface-variant);
}

.live.paused .dot {
  animation: none;
  background: var(--color-outline);
}

@keyframes pulse {
  50% {
    opacity: 0.3;
  }
}

.legend {
  display: inline-flex;
  align-items: center;
  gap: 6px;
  font-size: 11px;
  color: var(--color-on-surface-variant);
}

.legend i {
  width: 10px;
  height: 3px;
  border-radius: 2px;
  display: inline-block;
}

.table-wrap {
  overflow-x: auto;
  border: 1px solid var(--color-outline-variant);
  border-radius: 20px;
}

.thermal-table {
  width: 100%;
  min-width: 1120px;
  border-collapse: separate;
  border-spacing: 0;
  font-size: 12px;
}

.thermal-table th,
.thermal-table td {
  padding: 10px 12px;
  text-align: left;
  border-bottom: 1px solid var(--color-outline-variant);
  white-space: nowrap;
}

.thermal-table th {
  position: sticky;
  top: 0;
  z-index: 1;
  background: var(--color-surface-container-high);
  color: var(--color-on-surface-variant);
  font-size: 11px;
  font-weight: 700;
  text-transform: uppercase;
  letter-spacing: 0.04em;
}

.thermal-table tbody tr:last-child td {
  border-bottom: 0;
}

.muted {
  color: var(--color-on-surface-variant);
}

.state-pill {
  display: inline-flex;
  align-items: center;
  padding: 3px 8px;
  border-radius: 999px;
  font-size: 11px;
  font-weight: 700;
}

.state-normal {
  color: var(--color-on-primary-container);
  background: var(--color-primary-container);
}

.state-elevated {
  color: var(--color-on-tertiary-container);
  background: var(--color-tertiary-container);
}

.state-mitigating {
  color: var(--color-on-secondary-container);
  background: var(--color-secondary-container);
}

.state-critical {
  color: var(--color-on-error-container);
  background: var(--color-error-container);
}

.state-unknown {
  color: var(--color-on-surface-variant);
  background: var(--color-surface-container-highest);
}

.row {
  display: flex;
  justify-content: space-between;
  gap: 12px;
  padding: 8px 0;
  border-top: 1px solid var(--color-outline-variant);
}

.row:first-child {
  border-top: 0;
}
</style>
