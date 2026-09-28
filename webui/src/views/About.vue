<template>
  <SubPage
    :title="$t('about.title')"
    :icon="InformationOutlineIcon"
    shape="shape-sunny"
    tone="bg-secondary-container text-on-secondary-container"
  >
    <!-- Identity -->
    <section class="hero glass-surface m3-enter mb-5 text-center">
      <span class="hero-badge shape-sunny bg-primary text-on-primary">
        <FlameIcon :size="30" />
      </span>
      <p class="m3-headline text-3xl mt-3">HiCo Thermal</p>
      <p class="text-sm text-on-surface-variant mt-1">{{ $t('about.tagline') }}</p>
      <span class="chip mt-4">v{{ hico.status.version || '–' }}</span>
    </section>

    <p class="text-sm text-on-surface-variant leading-relaxed px-1 mb-5">
      {{ $t('about.description') }}
    </p>

    <!-- System -->
    <h2 class="section">{{ $t('about.system_title') }}</h2>
    <div class="stat-grid mb-5">
      <div class="stat">
        <span class="text-xs text-on-surface-variant">{{ $t('about.system.device') }}</span>
        <span class="text-sm font-semibold text-on-surface truncate">{{ deviceLabel }}</span>
      </div>
      <div class="stat">
        <span class="text-xs text-on-surface-variant">{{ $t('about.system.android') }}</span>
        <span class="text-sm font-semibold text-on-surface truncate">{{ androidLabel }}</span>
      </div>
      <div class="stat">
        <span class="text-xs text-on-surface-variant">{{ $t('about.system.kernel') }}</span>
        <span class="text-sm font-semibold text-on-surface truncate">{{
          system?.kernel || $t('about.unavailable')
        }}</span>
      </div>
      <div class="stat">
        <span class="text-xs text-on-surface-variant">{{ $t('about.system.arch') }}</span>
        <span class="text-sm font-semibold text-on-surface truncate">{{
          system?.arch || $t('about.unavailable')
        }}</span>
      </div>
      <div class="stat">
        <span class="text-xs text-on-surface-variant">{{ $t('about.system.root') }}</span>
        <span class="text-sm font-semibold text-on-surface truncate">{{ rootManager }}</span>
      </div>
    </div>

    <!-- Thermal engine -->
    <h2 class="section">{{ $t('about.engine_title') }}</h2>
    <div class="m3-card p-5 mb-5">
      <div class="flex items-center gap-3 mb-4">
        <span class="dot" :class="hico.running ? 'dot-on' : 'dot-off'" />
        <span class="text-sm font-semibold text-on-surface">{{ engineState }}</span>
      </div>
      <div class="stat-grid">
        <div class="stat">
          <span class="text-xs text-on-surface-variant">{{ $t('about.engine.preset') }}</span>
          <span class="text-sm font-semibold text-on-surface truncate">{{ presetTitle }}</span>
        </div>
        <div class="stat">
          <span class="text-xs text-on-surface-variant">{{ $t('about.engine.flux') }}</span>
          <span class="text-sm font-semibold text-on-surface truncate">{{
            hico.status.flux_version || fluxLabel
          }}</span>
        </div>
      </div>
      <p class="text-xs text-on-surface-variant leading-relaxed mt-4">
        {{ $t('about.flux_text') }}
      </p>
    </div>

    <!-- Integrity -->
    <h2 class="section">{{ $t('about.integrity_title') }}</h2>
    <LoadingSpinner v-if="integrityLoading" class="pt-4 pb-4" :size="36" />
    <div v-else-if="!integrity" class="m3-card p-4 mb-5 text-sm text-on-surface-variant">
      {{ $t('about.integrity.unavailable') }}
    </div>
    <div v-else class="glass-surface p-5 mb-5">
      <div class="flex items-center gap-3">
        <component :is="integrityIcon" :size="22" :class="integrityTone" />
        <span class="flex-1 min-w-0">
          <span class="block text-sm font-semibold" :class="integrityTone">{{
            $t(`about.integrity.status.${integrity.status}`)
          }}</span>
          <span class="block text-xs text-on-surface-variant mt-0.5">{{ integrity.reason }}</span>
        </span>
      </div>
      <div class="stat-grid mt-4">
        <div class="stat">
          <span class="text-xs text-on-surface-variant">{{ $t('about.integrity.manifest') }}</span>
          <span class="text-sm font-semibold text-on-surface truncate">{{
            integrity.manifest_version || $t('about.unavailable')
          }}</span>
        </div>
        <div class="stat">
          <span class="text-xs text-on-surface-variant">{{ $t('about.integrity.files') }}</span>
          <span class="text-sm font-semibold text-on-surface truncate">{{
            $t('about.integrity.files_n', { n: integrity.files.length })
          }}</span>
        </div>
      </div>
      <div class="runtime-note mt-3">
        <InformationOutlineIcon class="shrink-0" :size="16" />
        <p class="text-xs leading-relaxed">
          {{
            integrity.debugger_attached || integrity.hook_libraries > 0
              ? $t('about.integrity.runtime_flagged', { n: integrity.hook_libraries })
              : $t('about.integrity.runtime_clear')
          }}
        </p>
      </div>
    </div>

    <!-- Resources -->
    <h2 class="section">{{ $t('about.section.resources') }}</h2>
    <div class="mb-5">
      <div v-for="l in links" :key="l.key" class="md3-list">
        <RippleComponent class="md3-list-item" tabindex="0" @click="openWebsite(l.url)">
          <div class="flex items-center gap-4 px-5 py-4">
            <span class="badge shape-circle bg-surface-container-highest text-on-surface"
              ><component :is="l.icon" :size="20"
            /></span>
            <span class="flex-1 min-w-0">
              <span class="block text-sm font-semibold text-on-surface">{{
                $t(`about.link.${l.key}`)
              }}</span>
              <span class="block text-xs text-on-surface-variant truncate">{{
                l.url.replace('https://', '')
              }}</span>
            </span>
            <OpenInNewIcon class="text-on-surface-variant" :size="20" />
          </div>
        </RippleComponent>
      </div>
    </div>

    <!-- Legal -->
    <h2 class="section">{{ $t('about.section.legal') }}</h2>
    <div class="mb-5">
      <div class="md3-list">
        <RippleComponent class="md3-list-item" tabindex="0" @click="openLegal('license')">
          <div class="flex items-center gap-4 px-5 py-4">
            <span class="badge shape-circle bg-surface-container-highest text-on-surface"
              ><ShieldIcon :size="20"
            /></span>
            <span class="flex-1 min-w-0 text-sm font-semibold text-on-surface">{{
              $t('about.legal.license')
            }}</span>
            <ChevronRightIcon class="text-on-surface-variant rtl:rotate-180" :size="20" />
          </div>
        </RippleComponent>
      </div>
      <div class="md3-list">
        <RippleComponent class="md3-list-item" tabindex="0" @click="openLegal('notice')">
          <div class="flex items-center gap-4 px-5 py-4">
            <span class="badge shape-circle bg-surface-container-highest text-on-surface"
              ><TextIcon :size="20"
            /></span>
            <span class="flex-1 min-w-0 text-sm font-semibold text-on-surface">{{
              $t('about.legal.notice')
            }}</span>
            <ChevronRightIcon class="text-on-surface-variant rtl:rotate-180" :size="20" />
          </div>
        </RippleComponent>
      </div>
    </div>

    <!-- Footer -->
    <div class="footer mb-8">
      <p class="text-sm font-semibold text-on-surface">HiCo Thermal</p>
      <p class="text-xs text-on-surface-variant mt-1 leading-relaxed">{{ $t('about.footer') }}</p>
      <p class="text-xs text-on-surface-variant mt-3">{{ $t('about.built_for') }}</p>
      <p class="text-[11px] text-on-surface-variant mt-4 leading-relaxed opacity-80">
        {{ $t('about.legal_summary') }}
      </p>
    </div>

    <!-- Legal detail sheet -->
    <BottomSheet v-model:open="legalOpen" :title="legalTitle">
      <LoadingSpinner v-if="legalLoading" class="pt-4 pb-4" :size="32" />
      <p v-else-if="legalError" class="text-sm text-on-surface-variant">
        {{ $t('about.legal.unavailable') }}
      </p>
      <pre v-else class="legal-text">{{ legalText }}</pre>
    </BottomSheet>
  </SubPage>
</template>

<script setup>
import { ref, computed, onMounted } from 'vue'
import { useI18n } from 'vue-i18n'
import { useHiCoStore, HICOD } from '@/stores/HiCo'
import { PRESET_STYLE } from '@/helpers/presets'
import { openWebsite, readFile, isKSUWebUI, isRunningOnWebUIX } from '@/helpers/KernelSU'
import SubPage from '@/components/ui/SubPage.vue'
import RippleComponent from '@/components/ui/Ripple.vue'
import LoadingSpinner from '@/components/ui/LoadingSpinner.vue'
import BottomSheet from '@/components/ui/BottomSheet.vue'
import InformationOutlineIcon from '@/components/icons/InformationOutline.vue'
import GithubIcon from '@/components/icons/Github.vue'
import OpenInNewIcon from '@/components/icons/OpenInNew.vue'
import ShieldIcon from '@/components/icons/Shield.vue'
import TextIcon from '@/components/icons/Text.vue'
import FlameIcon from '@/components/icons/Flame.vue'
import ChevronRightIcon from '@/components/icons/ChevronRight.vue'
import CheckCircleFilledIcon from '@/components/icons/CheckCircleFilled.vue'
import WarningIcon from '@/components/icons/Warning.vue'
import ErrorIcon from '@/components/icons/Error.vue'

const { t } = useI18n()
const hico = useHiCoStore()

onMounted(() => hico.status.version || hico.refreshStatus())

// Module root, derived from the same HICOD path the store already exports
// (no second copy of that path): LICENSE/EULA.md/NOTICE.md sit beside system/bin/hicod.
const MODULE_DIR = HICOD.replace(/\/system\/bin\/hicod$/, '')

const deviceLabel = computed(
  () => hico.status.device_name || hico.status.device || t('about.unavailable'),
)
const engineState = computed(() =>
  hico.status.state ? t(`state.${hico.status.state}.title`) : t('about.unavailable'),
)
const presetTitle = computed(() =>
  hico.currentPreset in PRESET_STYLE
    ? t(`presets.${hico.currentPreset}.title`)
    : t('presets.custom'),
)
const FLUX_LABEL_KEY = {
  ready: 'about.flux_status.ready',
  not_installed: 'about.flux_status.not_installed',
  disabled: 'about.flux_status.disabled',
  outdated: 'about.flux_status.outdated',
  not_running: 'about.flux_status.not_running',
}
const fluxLabel = computed(() =>
  hico.status.flux && FLUX_LABEL_KEY[hico.status.flux]
    ? t(FLUX_LABEL_KEY[hico.status.flux])
    : t('about.unavailable'),
)

// System facts not exposed by any hicod command (only device/thermal facts are):
// one getprop/uname read, the same exec() channel saveLog() already uses.
const system = ref(null)
const androidLabel = computed(() => {
  if (!system.value?.android) return t('about.unavailable')
  return system.value.sdk
    ? `${system.value.android} (API ${system.value.sdk})`
    : system.value.android
})
const rootManager = computed(() => {
  if (isRunningOnWebUIX()) return 'WebUI X'
  if (isKSUWebUI()) return 'KernelSU'
  return t('about.unavailable')
})

// Signed release manifest check (docs/INTEGRITY.md): the same read-only command the daemon
// itself runs every 30 minutes, independent of whether it is currently running.
const integrity = ref(null)
const integrityLoading = ref(true)
const INTEGRITY_TONE = {
  ok: 'text-primary',
  missing: 'text-on-surface-variant',
  'bad-format': 'text-error',
  'bad-signature': 'text-error',
  'file-mismatch': 'text-error',
  'file-missing': 'text-error',
  revoked: 'text-error',
}
const INTEGRITY_ICON = {
  ok: CheckCircleFilledIcon,
  missing: InformationOutlineIcon,
  'bad-format': ErrorIcon,
  'bad-signature': ErrorIcon,
  'file-mismatch': ErrorIcon,
  'file-missing': ErrorIcon,
  revoked: WarningIcon,
}
const integrityTone = computed(
  () => INTEGRITY_TONE[integrity.value?.status] || 'text-on-surface-variant',
)
const integrityIcon = computed(
  () => INTEGRITY_ICON[integrity.value?.status] || InformationOutlineIcon,
)

onMounted(async () => {
  try {
    system.value = await hico.systemInfo()
  } catch {
    system.value = null
  }
  try {
    integrity.value = await hico.integrityCheck()
  } catch {
    integrity.value = null
  } finally {
    integrityLoading.value = false
  }
})

const links = [
  { key: 'hico', url: 'https://github.com/FebriCahyaa/HiCo-Release', icon: GithubIcon },
  { key: 'flux', url: 'https://github.com/FebriCahyaa/Flux/releases', icon: GithubIcon },
  { key: 'issues', url: 'https://github.com/FebriCahyaa/HiCo-Release/issues', icon: GithubIcon },
]

// LICENSE and NOTICE.md are shipped beside hicod (module/customize.sh); read on demand
// so About doesn't pay for two file reads it may never need.
const legalOpen = ref(false)
const legalKind = ref('')
const legalText = ref('')
const legalLoading = ref(false)
const legalError = ref(false)
const legalTitle = computed(() =>
  legalKind.value === 'license' ? t('about.legal.license') : t('about.legal.notice'),
)
async function openLegal(kind) {
  legalKind.value = kind
  legalOpen.value = true
  legalLoading.value = true
  legalError.value = false
  try {
    const file = kind === 'license' ? 'LICENSE' : 'NOTICE.md'
    legalText.value = await readFile(`${MODULE_DIR}/${file}`)
  } catch {
    legalError.value = true
  } finally {
    legalLoading.value = false
  }
}
</script>

<style scoped>
.hero {
  padding: 28px 20px;
  border-radius: 36px;
}

.hero-badge {
  width: 56px;
  height: 56px;
  display: inline-grid;
  place-items: center;
}

.chip {
  display: inline-block;
  font-size: 11px;
  font-weight: 700;
  padding: 3px 12px;
  border-radius: 999px;
  background: var(--color-surface-container-high);
  color: var(--color-on-surface-variant);
}

.section {
  font-size: 14px;
  font-weight: 600;
  color: var(--color-primary);
  padding: 8px 16px 8px 4px;
}

.badge {
  width: 40px;
  height: 40px;
  display: grid;
  place-items: center;
  flex-shrink: 0;
}

.stat-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(130px, 1fr));
  gap: 8px;
}

.stat {
  display: flex;
  flex-direction: column;
  gap: 2px;
  min-width: 0;
  padding: 10px 12px;
  border-radius: 16px;
  background: var(--color-surface-container-high);
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

.runtime-note {
  display: flex;
  gap: 8px;
  padding: 10px 12px;
  border-radius: 16px;
  background: var(--color-surface-container-high);
  color: var(--color-on-surface-variant);
}

.footer {
  text-align: center;
  padding: 8px 16px;
}

.legal-text {
  white-space: pre-wrap;
  word-break: break-word;
  font-family: ui-monospace, monospace;
  font-size: 11px;
  line-height: 1.6;
  color: var(--color-on-surface);
}
</style>
