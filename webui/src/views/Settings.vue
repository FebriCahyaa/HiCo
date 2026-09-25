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

        <!-- Game level -->
        <h2 class="section">{{ $t('settings.section.games') }}</h2>
        <div class="m3-card p-5 mb-4">
          <div class="flex items-center justify-between mb-3">
            <p class="text-sm font-semibold text-on-surface">{{ $t('keys.game_level.title') }}</p>
            <button class="text-on-surface-variant" @click="info('game_level')">
              <InformationOutlineIcon :size="20" />
            </button>
          </div>
          <div class="segmented">
            <button
              v-for="lv in ['relaxed', 'max']"
              :key="lv"
              class="seg m3-press"
              :class="{ on: cfg.game_level === lv }"
              :disabled="cfg.mode === 'extreme'"
              @click="actions.setKey('game_level', lv)"
            >
              {{ $t(`level.${lv}`) }}
            </button>
          </div>
          <p class="text-xs text-on-surface-variant mt-3 leading-relaxed">
            {{
              cfg.mode === 'extreme'
                ? $t('settings.level_extreme')
                : $t(`level.${cfg.game_level || 'max'}_hint`)
            }}
          </p>
        </div>

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

        <!-- More -->
        <h2 class="section">{{ $t('settings.section.more') }}</h2>
        <div class="mb-4">
          <div v-for="e in entries" :key="e.key" class="md3-list">
            <RippleComponent class="md3-list-item" tabindex="0" @click="e.run">
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
              </div>
            </RippleComponent>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { computed, reactive, onMounted } from 'vue'
import { useRouter } from 'vue-router'
import { useI18n } from 'vue-i18n'
import { useHiCoStore } from '@/stores/HiCo'
import { useNotifyStore } from '@/stores/Notify'
import { useSettingsActions } from '@/composables/useSettingsActions'
import { PRESET_STYLE } from '@/helpers/presets'
import { LANGUAGES } from '@/helpers/Locales'

import RippleComponent from '@/components/ui/Ripple.vue'
import ToggleSwitch from '@/components/ui/ToggleSwitch.vue'
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
onMounted(() => hico.loadConfig())

const preset = computed(() => PRESET_STYLE[hico.currentPreset] || PRESET_STYLE.balanced)
const presetTitle = computed(() =>
  hico.currentPreset in PRESET_STYLE
    ? t(`presets.${hico.currentPreset}.title`)
    : t('presets.custom'),
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

function info(key) {
  notify.confirm({
    tone: 'info',
    title: t(`keys.${key}.title`),
    message: t(`keys.${key}.info`),
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
}

async function restoreStock() {
  const ok = await notify.confirm({
    tone: 'warning',
    title: t('settings.restore.title'),
    message: t('settings.restore.confirm'),
    confirmText: t('settings.restore.action'),
  })
  if (!ok) return
  try {
    await hico.restore()
    notify.success(t('settings.restore.done'))
  } catch (e) {
    notify.error(t('notify.failed', { error: e.message }))
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
  try {
    await hico.reset()
    notify.success(t('settings.reset.done'))
  } catch (e) {
    notify.error(t('notify.failed', { error: e.message }))
  }
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

const entries = [
  {
    key: 'advanced',
    icon: TuneIcon,
    shape: 'shape-pentagon',
    tone: 'bg-secondary-container text-on-secondary-container',
    run: () => router.push('/settings/advanced'),
  },
  {
    key: 'log',
    icon: TextIcon,
    shape: 'shape-cookie4',
    tone: 'bg-surface-container-highest text-on-surface',
    run: () => router.push('/settings/log'),
  },
  {
    key: 'language',
    icon: LanguageIcon,
    shape: 'shape-circle',
    tone: 'bg-surface-container-highest text-on-surface',
    run: switchLanguage,
    subtitle: () => LANGUAGES[locale.value],
  },
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
  {
    key: 'about',
    icon: InformationOutlineIcon,
    shape: 'shape-sunny',
    tone: 'bg-secondary-container text-on-secondary-container',
    run: () => router.push('/settings/about'),
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
