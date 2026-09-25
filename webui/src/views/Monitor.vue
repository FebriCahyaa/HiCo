<template>
  <div class="page h-full flex flex-col overflow-hidden">
    <div class="scrollbar-hidden pb-safe-nav flex-1 min-h-0 overflow-y-scroll">
      <div class="max-w-3xl mx-auto px-4 pt-6 pb-6 space-y-3">
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
          <!-- Verdict -->
          <section class="hero" :class="verdict.card">
            <p class="text-xs font-semibold uppercase tracking-widest opacity-70">
              {{ $t('monitor.verdict') }}
            </p>
            <h2 class="m3-headline text-2xl mt-1">{{ $t(`monitor.v.${snap.verdict}.title`) }}</h2>
            <p class="text-sm mt-1 opacity-90">{{ $t(`monitor.v.${snap.verdict}.description`) }}</p>
            <div class="grid grid-cols-2 gap-2 mt-4">
              <div class="stat">
                <span class="text-xs opacity-70">{{ $t('monitor.cpu_allowed') }}</span>
                <span class="m3-headline text-2xl tabular-nums">{{ snap.cpu_limit }}%</span>
              </div>
              <div class="stat">
                <span class="text-xs opacity-70">{{ $t('monitor.gpu_allowed') }}</span>
                <span class="m3-headline text-2xl tabular-nums"
                  >{{ snap.gpu_limit ?? '–' }}{{ snap.gpu_limit === null ? '' : '%' }}</span
                >
              </div>
            </div>
          </section>

          <!-- Last minute -->
          <section class="m3-card p-5">
            <div class="flex items-center justify-between mb-2">
              <h3 class="text-sm font-semibold text-primary">{{ $t('monitor.allowed_chart') }}</h3>
              <span class="legend"><i class="bg-primary" />CPU <i class="bg-tertiary" />GPU</span>
            </div>
            <LineChart
              :series="limitSeries"
              :height="96"
              :min="0"
              :max="100"
              unit="%"
              :label="$t('monitor.allowed_chart')"
            />
            <div class="flex items-center justify-between mt-4 mb-2">
              <h3 class="text-sm font-semibold text-primary">{{ $t('monitor.temp_chart') }}</h3>
              <span class="legend"
                ><i class="bg-error" />CPU <i class="bg-secondary" />{{ $t('home.battery') }}</span
              >
            </div>
            <LineChart
              :series="tempSeries"
              :height="96"
              unit="°"
              :label="$t('monitor.temp_chart')"
            />
          </section>

          <!-- Clusters and GPU -->
          <section class="m3-card p-5">
            <h3 class="text-sm font-semibold text-primary mb-3">{{ $t('monitor.clocks') }}</h3>
            <div class="space-y-3">
              <div v-for="c in bars" :key="c.name">
                <div class="flex justify-between text-sm mb-1">
                  <span class="text-on-surface"
                    >{{ c.name }}
                    <span class="text-on-surface-variant text-xs">{{ c.sub }}</span></span
                  >
                  <span class="tabular-nums text-on-surface-variant">
                    <b class="text-on-surface">{{ c.cur }}</b> / {{ c.cap }} MHz
                  </span>
                </div>
                <div class="bar">
                  <div class="bar-cap" :style="{ width: `${c.capPct}%` }" />
                  <div
                    class="bar-cur"
                    :class="c.throttled ? 'bg-error' : 'bg-primary'"
                    :style="{ width: `${c.curPct}%` }"
                  />
                </div>
                <p v-if="c.throttled" class="text-[11px] text-error mt-1">
                  {{ $t('monitor.capped', { pct: 100 - c.limit }) }}
                </p>
              </div>
            </div>
          </section>

          <!-- Throttling sources -->
          <section v-if="activeCooling.length || tripped.length" class="m3-card p-5">
            <h3 class="text-sm font-semibold text-primary mb-3">{{ $t('monitor.sources') }}</h3>
            <div v-for="c in activeCooling" :key="c.name" class="row">
              <span class="text-sm text-on-surface truncate">{{ c.type }}</span>
              <span class="text-xs text-on-surface-variant tabular-nums">{{
                $t('monitor.state', { cur: c.cur, max: c.max })
              }}</span>
            </div>
            <div v-for="z in tripped" :key="z.name" class="row">
              <span class="text-sm text-on-surface truncate">{{ z.type }}</span>
              <span class="text-xs text-error tabular-nums"
                >{{ z.temp.toFixed(1) }} °C ≥ {{ z.trip }} °C</span
              >
            </div>
          </section>
          <p v-else class="text-xs text-on-surface-variant px-2">{{ $t('monitor.no_sources') }}</p>
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
const history = ref([]) // last 60 snapshots
const HISTORY = 60

const VERDICT = {
  none: 'bg-primary-container text-on-primary-container',
  light: 'bg-tertiary-container text-on-tertiary-container',
  heavy: 'bg-error-container text-on-error-container',
}
const verdict = computed(() => ({ card: VERDICT[snap.value?.verdict] || VERDICT.none }))

const series = (pick) => history.value.map((h) => pick(h) ?? null)
const limitSeries = computed(() => [
  { values: series((h) => h.cpu_limit), color: 'var(--color-primary)', area: true },
  { values: series((h) => h.gpu_limit), color: 'var(--color-tertiary)' },
])
const tempSeries = computed(() => [
  { values: series((h) => h.temps?.cpu), color: 'var(--color-error)' },
  { values: series((h) => h.temps?.battery), color: 'var(--color-secondary)' },
])

const bars = computed(() => {
  const s = snap.value
  if (!s) return []
  const out = s.clusters.map((c) => ({
    name: c.name,
    sub: `CPU ${c.cpus}`,
    cur: c.cur,
    cap: c.cap || c.max,
    curPct: c.max ? (c.cur / c.max) * 100 : 0,
    capPct: c.max ? ((c.cap || c.max) / c.max) * 100 : 100,
    limit: c.limit,
    throttled: c.limit < 100,
  }))
  if (s.gpu) {
    out.push({
      name: 'GPU',
      sub: s.gpu.source,
      cur: s.gpu.cur,
      cap: s.gpu.cap || s.gpu.max,
      curPct: s.gpu.max ? (s.gpu.cur / s.gpu.max) * 100 : 0,
      capPct: s.gpu.max ? ((s.gpu.cap || s.gpu.max) / s.gpu.max) * 100 : 100,
      limit: s.gpu.limit,
      throttled: s.gpu.limit < 100,
    })
  }
  return out
})

const activeCooling = computed(() => (snap.value?.cooling || []).filter((c) => c.perf && c.cur > 0))
const tripped = computed(() => (snap.value?.zones || []).filter((z) => z.tripped))

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
const stop = () => timer && clearInterval(timer)
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

.bar {
  position: relative;
  height: 10px;
  border-radius: 999px;
  background: color-mix(in srgb, var(--color-error) 25%, var(--color-surface-container-highest));
  overflow: hidden;
}

.bar-cap {
  position: absolute;
  inset: 0 auto 0 0;
  background: var(--color-surface-container-highest);
  border-radius: 999px;
}

.bar-cur {
  position: absolute;
  inset: 0 auto 0 0;
  border-radius: 999px;
  transition: width 400ms ease;
}

.row {
  display: flex;
  justify-content: space-between;
  gap: 12px;
  padding: 8px 0;
  border-top: 1px solid var(--color-outline-variant);
}

.row:first-of-type {
  border-top: 0;
}
</style>
