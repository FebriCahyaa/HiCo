<template>
  <SubPage
    :title="$t('settings.log.title')"
    :icon="TextIcon"
    shape="shape-cookie4"
    tone="bg-surface-container-highest text-on-surface"
  >
    <!-- Current status: reads the same store field Home.vue already shows -->
    <div class="status-row m3-enter mb-4">
      <span class="dot" :class="hico.running ? 'dot-on' : 'dot-off'" />
      <span class="flex-1 min-w-0">
        <span class="block text-sm font-semibold text-on-surface">{{ $t('log.engine') }}</span>
        <span class="block text-xs text-on-surface-variant">{{ engineState }}</span>
      </span>
      <span v-if="hico.status.version" class="text-xs text-on-surface-variant tabular-nums"
        >v{{ hico.status.version }}</span
      >
    </div>

    <!-- Recent activity -->
    <h2 class="section">{{ $t('log.sessions_title') }}</h2>
    <div v-if="!sessions.length" class="m3-card p-4 mb-4 text-sm text-on-surface-variant">
      {{ $t('log.sessions_empty') }}
    </div>
    <div v-else class="mb-4">
      <div v-for="s in sessions.slice(0, 8)" :key="s._key" class="md3-list">
        <RippleComponent class="md3-list-item" tabindex="0" @click="openSession(s)">
          <div class="flex items-center gap-4 px-5 py-3">
            <span class="badge" :class="[scenarioShape(s.scenario), scenarioTone(s.scenario)]"
              ><component :is="scenarioIcon(s.scenario)" :size="18"
            /></span>
            <span class="flex-1 min-w-0">
              <span class="block text-sm font-semibold text-on-surface truncate">{{
                apps.label(s.game)
              }}</span>
              <span class="block text-xs text-on-surface-variant">{{
                $t(scenarioLabelKey(s.scenario))
              }}</span>
            </span>
            <span class="text-xs text-on-surface-variant tabular-nums shrink-0">{{
              formatClock(s.start)
            }}</span>
          </div>
        </RippleComponent>
      </div>
    </div>

    <!-- Log viewer -->
    <h2 class="section">{{ $t('settings.log.title') }}</h2>
    <div class="toolbar glass-surface mb-3">
      <button
        v-for="f in ['all', 'warn']"
        :key="f"
        class="chip m3-press"
        :class="
          filter === f
            ? 'bg-secondary-container text-on-secondary-container'
            : 'bg-surface-container text-on-surface-variant'
        "
        @click="filter = f"
      >
        {{ $t(`log.${f}`) }}
      </button>
    </div>

    <LoadingSpinner v-if="loading" class="pt-6 pb-6" :size="40" />
    <div v-else-if="logError" class="m3-card p-4 mb-8 text-sm text-on-surface-variant">
      {{ $t('log.unavailable') }}
    </div>
    <div v-else ref="box" class="log scrollbar-hidden mb-8">
      <p v-if="!shown.length" class="text-on-surface-variant text-sm">{{ $t('log.empty') }}</p>
      <div v-for="(l, i) in shown" :key="i" class="entry">
        <template v-if="l.time">
          <div class="entry-meta">
            <span class="time">{{ l.time }}</span>
            <span class="level" :class="levelTone(l.level)">{{ levelLabel(l.level) }}</span>
          </div>
          <p class="msg">{{ l.msg }}</p>
        </template>
        <p v-else class="raw">{{ l.raw }}</p>
      </div>
    </div>

    <!-- Actions -->
    <h2 class="section">{{ $t('log.actions_title') }}</h2>
    <div class="space-y-2 mb-8">
      <RippleComponent class="action-row glass-surface block" tabindex="0" @click="save">
        <div class="flex items-center gap-4">
          <span class="badge shape-cookie4 bg-primary-container text-on-primary-container"
            ><ContentSaveIcon :size="18"
          /></span>
          <span class="flex-1 min-w-0">
            <span class="block text-sm font-semibold text-on-surface">{{ $t('log.save') }}</span>
            <span class="block text-xs text-on-surface-variant">{{ $t('log.save_hint') }}</span>
          </span>
          <LoadingSpinner v-if="saving" :size="18" />
        </div>
      </RippleComponent>

      <RippleComponent
        class="action-row glass-surface block"
        :class="{ 'action-row-disabled': !sessions.length }"
        :tabindex="sessions.length ? 0 : -1"
        role="button"
        :aria-disabled="!sessions.length"
        @click="sessions.length && clearSessions()"
      >
        <div class="flex items-center gap-4">
          <span class="badge shape-cookie6 bg-error-container text-on-error-container"
            ><NoEntryIcon :size="18"
          /></span>
          <span class="flex-1 min-w-0">
            <span
              class="block text-sm font-semibold"
              :class="sessions.length ? 'text-error' : 'text-on-surface-variant'"
              >{{ $t('log.clear') }}</span
            >
            <span class="block text-xs text-on-surface-variant">{{
              sessions.length ? $t('log.clear_hint') : $t('log.clear_none')
            }}</span>
          </span>
          <LoadingSpinner v-if="clearing" :size="18" />
        </div>
      </RippleComponent>
    </div>

    <!-- Session detail -->
    <BottomSheet v-model:open="sheetOpen" :title="sheetTitle">
      <div v-if="sheetSession" class="space-y-3">
        <div class="detail-row">
          <span class="text-xs text-on-surface-variant">{{ $t('log.session.scenario') }}</span>
          <span class="text-sm text-on-surface">{{
            $t(scenarioLabelKey(sheetSession.scenario))
          }}</span>
        </div>
        <div class="detail-row">
          <span class="text-xs text-on-surface-variant">{{ $t('log.session.started') }}</span>
          <span class="text-sm text-on-surface">{{ formatClock(sheetSession.start) }}</span>
        </div>
        <div class="detail-row">
          <span class="text-xs text-on-surface-variant">{{ $t('log.session.duration') }}</span>
          <span class="text-sm text-on-surface tabular-nums">{{
            formatDuration(sheetSession.duration)
          }}</span>
        </div>
        <div class="detail-row">
          <span class="text-xs text-on-surface-variant">{{ $t('log.session.boosted') }}</span>
          <span class="text-sm text-on-surface tabular-nums">{{
            formatDuration(sheetSession.boosted)
          }}</span>
        </div>
        <div class="detail-row">
          <span class="text-xs text-on-surface-variant">{{ $t('log.session.peak_cpu') }}</span>
          <span class="text-sm text-on-surface tabular-nums">{{
            formatTemp(sheetSession.peak_cpu)
          }}</span>
        </div>
        <div class="detail-row">
          <span class="text-xs text-on-surface-variant">{{ $t('log.session.peak_battery') }}</span>
          <span class="text-sm text-on-surface tabular-nums">{{
            formatTemp(sheetSession.peak_battery)
          }}</span>
        </div>
        <div class="detail-row">
          <span class="text-xs text-on-surface-variant">{{ $t('log.session.trips') }}</span>
          <span class="text-sm text-on-surface tabular-nums">{{ sheetSession.trips || 0 }}</span>
        </div>
      </div>
    </BottomSheet>
  </SubPage>
</template>

<script setup>
import { ref, computed, nextTick, onMounted, onActivated, onDeactivated, onUnmounted } from 'vue'
import { useI18n } from 'vue-i18n'
import { useHiCoStore } from '@/stores/HiCo'
import { useAppsStore } from '@/stores/Apps'
import { useNotifyStore } from '@/stores/Notify'
import SubPage from '@/components/ui/SubPage.vue'
import RippleComponent from '@/components/ui/Ripple.vue'
import LoadingSpinner from '@/components/ui/LoadingSpinner.vue'
import BottomSheet from '@/components/ui/BottomSheet.vue'
import TextIcon from '@/components/icons/Text.vue'
import ContentSaveIcon from '@/components/icons/ContentSave.vue'
import NoEntryIcon from '@/components/icons/NoEntry.vue'
import GamesIcon from '@/components/icons/Games.vue'
import PersonIcon from '@/components/icons/Person.vue'
import VolumeUpIcon from '@/components/icons/VolumeUp.vue'
import AppWindowIcon from '@/components/icons/AppWindow.vue'

const hico = useHiCoStore()
const apps = useAppsStore()
const notify = useNotifyStore()
const { t } = useI18n()

const saving = ref(false)
const clearing = ref(false)
const loading = ref(true)
const logError = ref(false)
const lines = ref([])
const filter = ref('all')
const box = ref(null)

const engineState = computed(() =>
  hico.status.state ? t(`state.${hico.status.state}.title`) : t('log.engine_unknown'),
)

// Backend log line format is fixed ("YYYY-MM-DD HH:MM:SS.mmm L msg", Log.hpp):
// parse it exactly, never invent a timestamp/level for a line that doesn't match.
const LOG_RE = /^\d{4}-\d{2}-\d{2} (\d{2}:\d{2}:\d{2})\.\d{3} ([EWID]) (.*)$/
const parseLine = (raw) => {
  const m = LOG_RE.exec(raw)
  return m
    ? { raw, time: m[1], level: m[2], msg: m[3] }
    : { raw, time: null, level: null, msg: raw }
}
// Only used as a fallback for a line the strict parser above couldn't read,
// same heuristic the previous implementation used for every line.
const legacyIsWarn = (raw) => / (W|E|warning|error)[: ]/i.test(raw)
const matchesWarnFilter = (l) =>
  l.level ? l.level === 'W' || l.level === 'E' : legacyIsWarn(l.raw)
const levelTone = (level) =>
  ({ E: 'text-error', W: 'text-tertiary', I: 'text-on-surface', D: 'text-on-surface-variant' })[
    level
  ] || 'text-on-surface'
const levelLabel = (level) =>
  ({
    E: t('log.level.error'),
    W: t('log.level.warn'),
    I: t('log.level.info'),
    D: t('log.level.debug'),
  })[level] || level

const shown = computed(() =>
  filter.value === 'warn' ? lines.value.filter(matchesWarnFilter) : lines.value,
)

async function loadLog() {
  try {
    lines.value = (await hico.log()).split('\n').filter(Boolean).map(parseLine)
    logError.value = false
  } catch {
    lines.value = []
    logError.value = true
  }
  loading.value = false
  await nextTick()
  if (box.value) box.value.scrollTop = box.value.scrollHeight
}

async function save() {
  saving.value = true
  try {
    const path = await hico.saveLog()
    notify.success(t('log.saved', { path }))
  } catch {
    notify.error(t('log.save_failed'))
  } finally {
    saving.value = false
  }
}

async function clearSessions() {
  const ok = await notify.confirm({
    tone: 'danger',
    title: t('log.clear_confirm.title'),
    message: t('log.clear_confirm.message'),
    confirmText: t('log.clear'),
  })
  if (!ok) return
  clearing.value = true
  try {
    await hico.clearSessions()
    notify.success(t('log.clear_done'))
  } catch (e) {
    notify.error(t('notify.failed', { error: e.message }))
  } finally {
    clearing.value = false
  }
}

// Sessions and the daemon status are one-off reads on open, not part of the
// 3 s log-refresh loop below: they change far less often than the log.
const sessions = computed(() => hico.sessions.map((s, i) => ({ ...s, _key: `${s.start}-${i}` })))
async function loadOnce() {
  await Promise.all([hico.refreshStatus(), hico.loadSessions()])
  const pkgs = hico.sessions.map((s) => s.game).filter(Boolean)
  if (pkgs.length) apps.resolve(pkgs)
}

// Same icon/shape/tone triples Scenarios.vue uses for these scenario types,
// so a session here reads as the same "thing" as its card there.
const SCENARIO_ICON = {
  game: GamesIcon,
  social: PersonIcon,
  media: VolumeUpIcon,
  other: AppWindowIcon,
}
const SCENARIO_SHAPE = {
  game: 'shape-cookie9',
  social: 'shape-flower',
  media: 'shape-clover4',
  other: 'shape-circle',
}
const SCENARIO_TONE = {
  game: 'bg-primary-container text-on-primary-container',
  social: 'bg-secondary-container text-on-secondary-container',
  media: 'bg-tertiary-container text-on-tertiary-container',
  other: 'bg-surface-container-highest text-on-surface',
}
const SCENARIO_LABEL_KEY = {
  game: 'scenarios.game.title',
  social: 'scenarios.tab.social',
  media: 'scenarios.tab.media',
  other: 'scenarios.tab.other',
}
const scenarioIcon = (k) => SCENARIO_ICON[k] || SCENARIO_ICON.other
const scenarioShape = (k) => SCENARIO_SHAPE[k] || SCENARIO_SHAPE.other
const scenarioTone = (k) => SCENARIO_TONE[k] || SCENARIO_TONE.other
const scenarioLabelKey = (k) => SCENARIO_LABEL_KEY[k] || SCENARIO_LABEL_KEY.other

const formatClock = (unixSeconds) =>
  unixSeconds
    ? new Date(unixSeconds * 1000).toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })
    : '–'
const formatDuration = (s) => {
  const n = Number(s || 0)
  if (n < 60) return `${n}s`
  const m = Math.floor(n / 60)
  return m < 60 ? `${m}m` : `${Math.floor(m / 60)}h ${m % 60}m`
}
const formatTemp = (v) => (v === null || v === undefined ? '–' : `${Number(v).toFixed(1)} °C`)

const sheetOpen = ref(false)
const sheetSession = ref(null)
const sheetTitle = computed(() => (sheetSession.value ? apps.label(sheetSession.value.game) : ''))
function openSession(s) {
  sheetSession.value = s
  sheetOpen.value = true
}

let timer = null
const start = () => {
  stop()
  loading.value = true
  loadLog()
  loadOnce()
  timer = setInterval(loadLog, 3000)
}
const stop = () => timer && clearInterval(timer)
onMounted(start)
onActivated(start)
onDeactivated(stop)
onUnmounted(stop)
</script>

<style scoped>
.section {
  font-size: 14px;
  font-weight: 600;
  color: var(--color-primary);
  padding: 8px 4px;
}

.status-row {
  display: flex;
  align-items: center;
  gap: 12px;
  padding: 14px 16px;
  border-radius: 24px;
  background: var(--color-surface-container);
}

.dot {
  width: 10px;
  height: 10px;
  border-radius: 999px;
  flex-shrink: 0;
}

.dot-on {
  background: var(--color-primary);
}

.dot-off {
  background: var(--color-outline);
}

.badge {
  width: 40px;
  height: 40px;
  display: grid;
  place-items: center;
  flex-shrink: 0;
}

.toolbar {
  display: flex;
  gap: 8px;
  padding: 8px;
  border-radius: 20px;
}

.chip {
  padding: 6px 14px;
  border-radius: 999px;
  font-size: 13px;
  font-weight: 600;
}

.log {
  max-height: 50vh;
  overflow-y: auto;
  padding: 14px;
  border-radius: 24px;
  background: var(--color-surface-container);
}

.entry {
  padding: 7px 0;
  border-bottom: 1px solid var(--color-outline-variant);
}

.entry:last-child {
  border-bottom: 0;
}

.entry-meta {
  display: flex;
  align-items: center;
  gap: 8px;
  margin-bottom: 2px;
}

.time {
  font-family: ui-monospace, monospace;
  font-size: 11px;
  color: var(--color-on-surface-variant);
}

.level {
  font-size: 10px;
  font-weight: 750;
  letter-spacing: 0.04em;
}

.msg {
  font-size: 13px;
  line-height: 1.4;
  color: var(--color-on-surface);
  word-break: break-word;
}

.raw {
  font-family: ui-monospace, monospace;
  font-size: 11px;
  line-height: 1.6;
  color: var(--color-on-surface-variant);
  white-space: pre;
  overflow-x: auto;
}

.action-row {
  padding: 14px 16px;
  border-radius: 20px;
}

.action-row-disabled {
  opacity: 0.5;
  pointer-events: none;
}

.detail-row {
  display: flex;
  flex-direction: column;
  gap: 4px;
  padding: 12px 14px;
  border-radius: 16px;
  background: var(--color-surface-container-high);
}
</style>
