<template>
  <SubPage
    :title="$t('settings.advanced.title')"
    :icon="TuneIcon"
    shape="shape-pentagon"
    tone="bg-secondary-container text-on-secondary-container"
  >
    <div class="warn glass-surface mb-5 m3-enter">
      <WarningIcon class="shrink-0" :size="24" />
      <div>
        <p class="text-sm font-semibold">{{ $t('advanced.warning_title') }}</p>
        <p class="text-xs leading-relaxed mt-1 opacity-90">{{ $t('advanced.warning') }}</p>
      </div>
    </div>

    <template v-for="g in groups" :key="g.key">
      <h2 class="section">{{ $t(`advanced.group.${g.key}`) }}</h2>
      <div class="mb-5 m3-enter">
        <div v-for="k in g.keys.filter((k) => byKey[k])" :key="k" class="md3-list">
          <div class="md3-list-item flex items-center gap-4 px-5 py-4">
            <span class="flex-1 min-w-0">
              <span
                class="block text-sm font-semibold"
                :class="isWarned(k) ? warnedClass(k) : 'text-on-surface'"
                >{{ title(k) }}</span
              >
              <span class="block text-xs text-on-surface-variant mt-1 leading-relaxed">{{
                help(k)
              }}</span>
            </span>
            <ToggleSwitch
              v-if="byKey[k].type === 'bool'"
              :model-value="byKey[k].value === '1'"
              @update:modelValue="(v) => actions.setKey(k, v)"
            />
            <div v-else class="stepper">
              <button class="m3-press" :disabled="num(k) <= byKey[k].min" @click="step(k, -1)">
                −
              </button>
              <span class="tabular-nums">{{ byKey[k].value }}</span>
              <button class="m3-press" :disabled="num(k) >= byKey[k].max" @click="step(k, 1)">
                +
              </button>
            </div>
          </div>
        </div>
      </div>
    </template>
  </SubPage>
</template>

<script setup>
import { computed, onMounted } from 'vue'
import { useI18n } from 'vue-i18n'
import { useHiCoStore } from '@/stores/HiCo'
import { useSettingsActions } from '@/composables/useSettingsActions'
import SubPage from '@/components/ui/SubPage.vue'
import ToggleSwitch from '@/components/ui/ToggleSwitch.vue'
import TuneIcon from '@/components/icons/Tune.vue'
import WarningIcon from '@/components/icons/Warning.vue'

const { t, te } = useI18n()
const hico = useHiCoStore()
const actions = useSettingsActions()
onMounted(() => hico.loadConfig())

// Same table useSettingsActions() already confirms against before enabling a
// key: read-only here, just to color the row consistently with that warning.
const isWarned = (k) => k in actions.WARN_ON
const warnedClass = (k) => (actions.WARN_ON[k] === 'danger' ? 'text-error' : 'text-tertiary')

const groups = [
  {
    key: 'unlock',
    keys: [
      'stop_thermal_services',
      'stop_thermal_hal',
      'zone_governor',
      'cooling_reset',
      'cpu_clock_unlock',
      'gpu_unlock',
      'vendor_tweaks',
      'xiaomi_tweaks',
      'xiaomi_sconfig',
      'relax_margin',
    ],
  },
  {
    key: 'safety',
    keys: ['safety_cpu_hysteresis', 'safety_battery_hysteresis', 'safety_cooldown'],
  },
  { key: 'service', keys: ['poll_interval', 'exit_delay', 'log_level'] },
]

const byKey = computed(() => Object.fromEntries(hico.schema.map((k) => [k.key, k])))
const title = (k) => (te(`keys.${k}.title`) ? t(`keys.${k}.title`) : k)
const help = (k) => (te(`keys.${k}.help`) ? t(`keys.${k}.help`) : byKey.value[k]?.help)
const num = (k) => Number(byKey.value[k]?.value || 0)

let pending = null
function step(k, d) {
  const info = byKey.value[k]
  const next = Math.min(info.max, Math.max(info.min, num(k) + d))
  info.value = String(next) // shown at once; saved after taps settle
  clearTimeout(pending)
  pending = setTimeout(() => actions.setKey(k, String(next)), 500)
}
</script>

<style scoped>
.section {
  font-size: 14px;
  font-weight: 600;
  color: var(--color-primary);
  padding: 8px 4px;
}

.warn {
  display: flex;
  gap: 12px;
  padding: 16px;
  border-radius: 24px;
  color: var(--color-tertiary);
  box-shadow: inset 0 0 0 1px var(--color-tertiary-container);
}

.warn p {
  color: var(--color-on-surface);
}

.stepper {
  display: flex;
  align-items: center;
  gap: 4px;
  flex-shrink: 0;
  border-radius: 999px;
  background: var(--color-surface-container-highest);
  padding: 2px;
}

.stepper button {
  width: 32px;
  height: 32px;
  border-radius: 999px;
  font-size: 18px;
  font-weight: 700;
  color: var(--color-primary);
}

.stepper button:disabled {
  opacity: 0.35;
}

.stepper span {
  min-width: 28px;
  text-align: center;
  font-size: 14px;
  font-weight: 700;
  color: var(--color-on-surface);
}
</style>
