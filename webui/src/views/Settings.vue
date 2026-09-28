<template>
  <div class="page h-full flex flex-col overflow-hidden">
    <div class="scrollbar-hidden pb-safe-nav flex-1 min-h-0 overflow-y-scroll">
      <div class="max-w-3xl mx-auto px-4 pt-6 pb-6">
        <h1 class="m3-headline text-[32px] text-on-surface px-1 mb-4">
          {{ $t('settings.title') }}
        </h1>

        <!-- Easy start -->
        <RippleComponent
          class="preset-card m3-press block mb-4"
          tabindex="0"
          @click="router.push('/settings/presets')"
        >
          <div class="flex items-center gap-4">
            <span class="badge-lg" :class="[preset.shape, preset.tone]"
              ><component :is="preset.icon" :size="26"
            /></span>
            <div class="flex-1 min-w-0">
              <p class="text-xs font-semibold uppercase tracking-widest opacity-70">
                {{ $t('presets.title') }}
              </p>
              <p class="text-lg font-semibold">{{ presetTitle }}</p>
              <p class="text-xs opacity-80 mt-0.5">{{ $t('settings.preset_hint') }}</p>
            </div>
            <ChevronRightIcon class="opacity-70 rtl:rotate-180" :size="22" />
          </div>
        </RippleComponent>

        <!-- Levels per scenario live on the Scenarios page -->
        <h2 class="section">{{ $t('settings.section.games') }}</h2>
        <div class="md3-list mb-2">
          <RippleComponent class="md3-list-item" tabindex="0" @click="router.push('/scenarios')">
            <div class="flex items-center gap-4 px-5 py-4">
              <span class="badge shape-cookie9 bg-primary-container text-on-primary-container"
                ><TuneIcon :size="20"
              /></span>
              <span class="flex-1 min-w-0">
                <span class="block text-sm font-semibold text-on-surface">{{
                  $t('scenarios.title')
                }}</span>
                <span class="block text-xs text-on-surface-variant mt-1">{{
                  scenarioSummary
                }}</span>
              </span>
              <ChevronRightIcon class="text-on-surface-variant rtl:rotate-180" :size="20" />
            </div>
          </RippleComponent>
        </div>

        <h2 class="section">{{ $t('settings.section.behavior') }}</h2>
        <div class="mb-4">
          <div v-for="k in toggles" :key="k.key" class="md3-list">
            <div class="md3-list-item flex items-center gap-4 px-5 py-4">
              <span class="badge" :class="[k.shape, k.tone]"
                ><component :is="k.icon" :size="20"
              /></span>
              <span class="flex-1 min-w-0">
                <span class="block text-sm font-semibold text-on-surface">{{
                  $t(`keys.${k.key}.title`)
                }}</span>
                <span class="block text-xs text-on-surface-variant mt-1 leading-relaxed">{{
                  $t(`keys.${k.key}.help`)
                }}</span>
              </span>
              <ToggleSwitch
                :model-value="cfg[k.key] === '1'"
                @update:modelValue="(v) => actions.setKey(k.key, v)"
              />
            </div>
          </div>
        </div>

        <!-- Safety -->
        <h2 class="section">{{ $t('settings.section.safety') }}</h2>
        <div class="m3-card p-5 mb-4 space-y-5">
          <div v-for="l in limits" :key="l.key">
            <div class="flex items-center justify-between">
              <p class="text-sm font-semibold text-on-surface">{{ $t(`keys.${l.key}.title`) }}</p>
              <span class="value" :class="riskTone(l)"
                >{{ draft[l.key] ?? cfg[l.key] }} {{ l.unit }}</span
              >
            </div>
            <input
              type="range"
              class="slider"
              :min="l.min"
              :max="l.max"
              :value="draft[l.key] ?? cfg[l.key]"
              @input="draft[l.key] = Number($event.target.value)"
              @change="saveLimit(l, Number($event.target.value))"
            />
            <p class="text-xs text-on-surface-variant leading-relaxed">
              {{ $t(`keys.${l.key}.help`) }}
            </p>
          </div>
          <div class="note">
            <ShieldIcon class="shrink-0" :size="18" />
            <p class="text-xs leading-relaxed">{{ $t('settings.safety_note') }}</p>
          </div>
        </div>

        <!-- Diagnostics, appearance, system and about: each its own grouped surface -->
        <template v-for="grp in entryGroups" :key="grp.key">
          <h2 class="section">{{ $t(`settings.section.${grp.key}`) }}</h2>
          <div class="mb-4">
            <div v-for="e in grp.entries" :key="e.key" class="md3-list">
              <RippleComponent
                class="md3-list-item"
                tabindex="0"
                :aria-disabled="busy === e.key"
                @click="run(e)"
              >
                <div class="flex items-center gap-4 px-5 py-4">
                  <span class="badge" :class="[e.shape, e.tone]"
                    ><component :is="e.icon" :size="20"
                  /></span>
                  <span class="flex-1 min-w-0">
                    <span
                      class="block text-sm font-semibold"
                      :class="e.danger ? 'text-error' : 'text-on-surface'"
                      >{{ $t(`settings.${e.key}.title`) }}</span
                    >
                    <span class="block text-xs text-on-surface-variant mt-1">{{
                      e.subtitle ? e.subtitle() : $t(`settings.${e.key}.description`)
                    }}</span>
                  </span>
                  <LoadingSpinner v-if="busy === e.key" :size="20" />
                  <ChevronRightIcon
                    v-else-if="e.chevron"
                    class="text-on-surface-variant rtl:rotate-180 shrink-0"
                    :size="20"
                  />
                </div>
              </RippleComponent>
            </div>
          </div>
        </template>
      </div>
    </div>
  </div>
</template>

<script setup>
import { computed, reactive, ref, onMounted } from 'vue'
import { useRouter } from 'vue-router'
import { useI18n } from 'vue-i18n'
import { useHiCoStore } from '@/stores/HiCo'
import { useNotifyStore } from '@/stores/Notify'
import { useSettingsActions } from '@/composables/useSettingsActions'
import { PRESET_STYLE } from '@/helpers/presets'
import { LANGUAGES } from '@/helpers/Locales'

import RippleComponent from '@/components/ui/Ripple.vue'
import ToggleSwitch from '@/components/ui/ToggleSwitch.vue'
import LoadingSpinner from '@/components/ui/LoadingSpinner.vue'
import ChevronRightIcon from '@/components/icons/ChevronRight.vue'
import InformationOutlineIcon from '@/components/icons/InformationOutline.vue'
import ShieldIcon from '@/components/icons/Shield.vue'
import RocketIcon from '@/components/icons/Rocket.vue'
import LeafIcon from '@/components/icons/Leaf.vue'
import NotificationsActiveIcon from '@/components/icons/NotificationsActive.vue'
import TuneIcon from '@/components/icons/Tune.vue'
import RefreshIcon from '@/components/icons/Refresh.vue'
import SnowflakeIcon from '@/components/icons/Snowflake.vue'
import TextIcon from '@/components/icons/Text.vue'
import LanguageIcon from '@/components/icons/Language.vue'
import ErrorIcon from '@/components/icons/Error.vue'

const router = useRouter()
const { t, locale } = useI18n()
const hico = useHiCoStore()
const notify = useNotifyStore()
const actions = useSettingsActions()

const cfg = computed(() => hico.config)
const draft = reactive({})
const busy = ref('')
onMounted(() => hico.loadConfig())

const preset = computed(() => PRESET_STYLE[hico.currentPreset] || PRESET_STYLE.balanced)
const presetTitle = computed(() =>
  hico.currentPreset in PRESET_STYLE
    ? t(`presets.${hico.currentPreset}.title`)
    : t('presets.custom'),
)

const scenarioSummary = computed(() =>
  ['game', 'social', 'media']
    .map((k) => {
      const lv = cfg.value[`${k}_level`] || (k === 'game' ? 'max' : 'stock')
      return `${t(`scenarios.${k}.short`)}: ${t(`scenarios.level.${lv}`)}`
    })
    .join(' · '),
)

const toggles = [
  {
    key: 'thermal_overclock',
    icon: RocketIcon,
    shape: 'shape-burst',
    tone: 'bg-error-container text-on-error-container',
  },
  {
    key: 'unlock_on_lite',
    icon: LeafIcon,
    shape: 'shape-flower',
    tone: 'bg-secondary-container text-on-secondary-container',
  },
  {
    key: 'notify',
    icon: NotificationsActiveIcon,
    shape: 'shape-cookie9',
    tone: 'bg-primary-container text-on-primary-container',
  },
]

const limits = [
  { key: 'safety_cpu_temp', min: 70, max: 105, unit: '°C', warn: 98, danger: 102 },
  { key: 'safety_battery_temp', min: 38, max: 52, unit: '°C', warn: 47, danger: 50 },
]
const riskTone = (l) => {
  const v = Number(draft[l.key] ?? cfg.value[l.key])
  return v >= l.danger ? 'text-error' : v >= l.warn ? 'text-tertiary' : 'text-primary'
}

async function saveLimit(l, value) {
  if (value >= l.danger) {
    const ok = await notify.confirm({
      tone: 'danger',
      title: t('settings.limit_confirm.title'),
      message: t(`settings.limit_confirm.${l.key}`, { v: value }),
      confirmText: t('common.apply'),
    })
    if (!ok) {
      delete draft[l.key]
      return
    }
  }
  await actions.setKey(l.key, String(value))
  delete draft[l.key]
}

async function restart() {
  busy.value = 'restart'
  try {
    await hico.restart()
    notify.success(t('actions.restarted'))
  } catch (e) {
    notify.error(t('notify.failed', { error: e.message }))
  } finally {
    busy.value = ''
  }
}

async function restoreStock() {
  const ok = await notify.confirm({
    tone: 'warning',
    title: t('settings.restore.title'),
    message: t('settings.restore.confirm'),
    confirmText: t('settings.restore.action'),
  })
  if (!ok) return
  busy.value = 'restore'
  try {
    await hico.restore()
    notify.success(t('settings.restore.done'))
  } catch (e) {
    notify.error(t('notify.failed', { error: e.message }))
  } finally {
    busy.value = ''
  }
}

async function resetSettings() {
  const ok = await notify.confirm({
    tone: 'danger',
    title: t('settings.reset.title'),
    message: t('settings.reset.confirm'),
    confirmText: t('settings.reset.action'),
  })
  if (!ok) return
  busy.value = 'reset'
  try {
    await hico.reset()
    notify.success(t('settings.reset.done'))
  } catch (e) {
    notify.error(t('notify.failed', { error: e.message }))
  } finally {
    busy.value = ''
  }
}

function run(e) {
  if (busy.value) return
  e.run()
}

function switchLanguage() {
  const next = locale.value === 'id' ? 'en' : 'id'
  locale.value = next
  document.documentElement.lang = next
  try {
    localStorage.setItem('hico-language', next)
  } catch {
    // not remembered
  }
}

const entryGroups = [
  {
    key: 'diagnostics',
    entries: [
      {
        key: 'advanced',
        icon: TuneIcon,
        shape: 'shape-pentagon',
        tone: 'bg-secondary-container text-on-secondary-container',
        run: () => router.push('/settings/advanced'),
        chevron: true,
      },
      {
        key: 'log',
        icon: TextIcon,
        shape: 'shape-cookie4',
        tone: 'bg-surface-container-highest text-on-surface',
        run: () => router.push('/settings/log'),
        chevron: true,
      },
    ],
  },
  {
    key: 'appearance',
    entries: [
      {
        key: 'language',
        icon: LanguageIcon,
        shape: 'shape-circle',
        tone: 'bg-surface-container-highest text-on-surface',
        run: switchLanguage,
        subtitle: () => LANGUAGES[locale.value],
        chevron: true,
      },
    ],
  },
  {
    key: 'system',
    entries: [
      {
        key: 'restart',
        icon: RefreshIcon,
        shape: 'shape-clover4',
        tone: 'bg-primary-container text-on-primary-container',
        run: restart,
      },
      {
        key: 'restore',
        icon: SnowflakeIcon,
        shape: 'shape-cookie9',
        tone: 'bg-tertiary-container text-on-tertiary-container',
        run: restoreStock,
      },
      {
        key: 'reset',
        icon: ErrorIcon,
        shape: 'shape-cookie6',
        tone: 'bg-error-container text-on-error-container',
        run: resetSettings,
        danger: true,
      },
    ],
  },
  {
    key: 'about',
    entries: [
      {
        key: 'about',
        icon: InformationOutlineIcon,
        shape: 'shape-sunny',
        tone: 'bg-secondary-container text-on-secondary-container',
        run: () => router.push('/settings/about'),
        chevron: true,
      },
    ],
  },
]
</script>

<style scoped>
.section {
  font-size: 14px;
  font-weight: 600;
  color: var(--color-primary);
  padding: 8px 16px;
}

.preset-card {
  padding: 20px;
  border-radius: 32px;
  background: var(--color-primary-container);
  color: var(--color-on-primary-container);
}

.badge,
.badge-lg {
  width: 40px;
  height: 40px;
  display: grid;
  place-items: center;
  flex-shrink: 0;
}

.badge-lg {
  width: 52px;
  height: 52px;
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

.seg:disabled {
  opacity: 0.45;
}

.value {
  font-weight: 700;
  font-variant-numeric: tabular-nums;
}

.slider {
  width: 100%;
  margin: 10px 0 6px;
  accent-color: var(--color-primary);
}

.note {
  display: flex;
  gap: 10px;
  padding: 12px 14px;
  border-radius: 18px;
  background: var(--color-surface-container-high);
  color: var(--color-on-surface-variant);
}
</style>
