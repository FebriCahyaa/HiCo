<template>
  <SubPage
    :title="$t('presets.title')"
    :icon="TuneIcon"
    shape="shape-cookie12"
    tone="bg-tertiary-container text-on-tertiary-container"
  >
    <p class="text-sm text-on-surface-variant leading-relaxed px-1 mb-5">
      {{ $t('presets.brief') }}
    </p>

    <div class="space-y-3 mb-5">
      <RippleComponent
        v-for="(p, i) in hico.presets"
        :key="p.name"
        class="preset m3-enter block"
        :class="{ active: hico.currentPreset === p.name }"
        :style="{ animationDelay: `${i * 50}ms` }"
        tabindex="0"
        @click="choose(p.name)"
      >
        <div class="flex items-start gap-4">
          <span class="badge" :class="[style(p).shape, style(p).tone]"
            ><component :is="style(p).icon" :size="24"
          /></span>
          <div class="flex-1 min-w-0">
            <div class="flex flex-wrap items-center gap-2">
              <p class="text-base font-semibold text-on-surface">
                {{ $t(`presets.${p.name}.title`) }}
              </p>
              <span v-if="hico.currentPreset === p.name" class="tag bg-primary text-on-primary">{{
                $t('presets.active')
              }}</span>
              <span
                v-else-if="p.name === 'balanced'"
                class="tag bg-primary-container text-on-primary-container"
                >{{ $t('presets.recommended') }}</span
              >
              <span
                v-if="style(p).risk"
                class="tag"
                :class="
                  style(p).risk === 'danger'
                    ? 'bg-error-container text-on-error-container'
                    : 'bg-tertiary-container text-on-tertiary-container'
                "
              >
                {{ $t(`presets.risk_${style(p).risk}`) }}
              </span>
            </div>
            <p class="text-xs text-on-surface-variant mt-1 leading-relaxed">
              {{ $t(`presets.${p.name}.description`) }}
            </p>
            <div class="flex flex-wrap gap-1 mt-3">
              <span
                v-for="k in highlights"
                :key="k"
                class="tag bg-surface-container-highest text-on-surface"
              >
                {{ $t(`presets.fact.${k}`, { v: valueLabel(k, p.values[k]) }) }}
              </span>
            </div>
          </div>
        </div>
      </RippleComponent>
    </div>

    <div v-if="hico.currentPreset === 'custom'" class="flex gap-3 px-1 mb-4">
      <TuneIcon class="text-on-surface-variant shrink-0" :size="20" />
      <p class="text-xs text-on-surface-variant leading-relaxed">{{ $t('presets.custom_note') }}</p>
    </div>
    <div class="flex gap-3 px-1 mb-8">
      <InformationOutlineIcon class="text-on-surface-variant shrink-0" :size="20" />
      <p class="text-xs text-on-surface-variant leading-relaxed">{{ $t('presets.note') }}</p>
    </div>
  </SubPage>
</template>

<script setup>
import { onMounted } from 'vue'
import { useI18n } from 'vue-i18n'
import { useHiCoStore } from '@/stores/HiCo'
import { useSettingsActions } from '@/composables/useSettingsActions'
import { PRESET_STYLE } from '@/helpers/presets'
import SubPage from '@/components/ui/SubPage.vue'
import RippleComponent from '@/components/ui/Ripple.vue'
import TuneIcon from '@/components/icons/Tune.vue'
import InformationOutlineIcon from '@/components/icons/InformationOutline.vue'

const { t } = useI18n()
const hico = useHiCoStore()
const actions = useSettingsActions()
onMounted(() => hico.loadConfig())

const style = (p) => PRESET_STYLE[p.name] || PRESET_STYLE.balanced
const highlights = [
  'mode',
  'game_level',
  'safety_cpu_temp',
  'safety_battery_temp',
  'thermal_overclock',
]
function valueLabel(key, v) {
  if (key === 'mode') return t(`mode.${v}.title`)
  if (key === 'game_level') return t(`scenarios.level.${v}`)
  if (key === 'thermal_overclock') return v === '1' ? t('common.on') : t('common.off')
  return v
}

const choose = (name) => name !== hico.currentPreset && actions.applyPreset(name)
</script>

<style scoped>
.preset {
  padding: 18px;
  border-radius: 28px;
  background: var(--color-surface-container);
  transition: border-radius var(--m3-spring-fast-spatial-duration) var(--m3-spring-fast-spatial);
}

.preset.active {
  border-radius: 36px;
  background: var(--color-surface-container-highest);
  box-shadow: inset 0 0 0 2px var(--color-primary);
}

.badge {
  width: 48px;
  height: 48px;
  display: grid;
  place-items: center;
  flex-shrink: 0;
}

.tag {
  font-size: 11px;
  font-weight: 650;
  padding: 2px 9px;
  border-radius: 999px;
}
</style>
