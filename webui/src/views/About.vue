<template>
  <SubPage
    :title="$t('about.title')"
    :icon="InformationOutlineIcon"
    shape="shape-sunny"
    tone="bg-secondary-container text-on-secondary-container"
  >
    <!-- Identity -->
    <section class="hero mb-4">
      <p class="m3-headline text-3xl">HiCo Thermal</p>
      <p class="text-sm opacity-80 mt-1">{{ $t('about.tagline') }}</p>
      <div class="flex flex-wrap gap-1.5 mt-4">
        <span class="chip">v{{ s.version || '–' }}</span>
        <span class="chip">{{ $t('about.by') }} FebriCahyaa</span>
        <span class="chip">{{ $t('about.proprietary') }}</span>
      </div>
    </section>

    <p class="text-sm text-on-surface-variant leading-relaxed px-1 mb-5">
      {{ $t('about.description') }}
    </p>

    <!-- Features -->
    <h2 class="section">{{ $t('about.features_title') }}</h2>
    <div class="mb-5">
      <div v-for="f in features" :key="f.key" class="md3-list">
        <div class="md3-list-item flex items-center gap-4 px-5 py-4">
          <span class="badge" :class="[f.shape, f.tone]"
            ><component :is="f.icon" :size="20"
          /></span>
          <span class="flex-1 min-w-0">
            <span class="block text-sm font-semibold text-on-surface">{{
              $t(`about.features.${f.key}.title`)
            }}</span>
            <span class="block text-xs text-on-surface-variant mt-1 leading-relaxed">{{
              $t(`about.features.${f.key}.description`)
            }}</span>
          </span>
        </div>
      </div>
    </div>

    <!-- Flux -->
    <h2 class="section">{{ $t('about.flux_title') }}</h2>
    <div class="m3-card p-5 mb-5">
      <p class="text-sm text-on-surface leading-relaxed">{{ $t('about.flux_text') }}</p>
      <div class="split mt-4">
        <div>
          <p class="text-xs font-semibold text-primary mb-1">Flux Tweaks</p>
          <p class="text-xs text-on-surface-variant leading-relaxed">{{ $t('about.flux_owns') }}</p>
        </div>
        <div>
          <p class="text-xs font-semibold text-primary mb-1">HiCo Thermal</p>
          <p class="text-xs text-on-surface-variant leading-relaxed">{{ $t('about.hico_owns') }}</p>
        </div>
      </div>
    </div>

    <!-- Links -->
    <h2 class="section">{{ $t('about.links') }}</h2>
    <div class="mb-5">
      <div v-for="l in links" :key="l.url" class="md3-list">
        <RippleComponent class="md3-list-item" tabindex="0" @click="openWebsite(l.url)">
          <div class="flex items-center gap-4 px-5 py-4">
            <span class="badge shape-circle bg-surface-container-highest text-on-surface"
              ><GithubIcon :size="20"
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
    <div class="flex gap-3 px-1 mb-8">
      <ShieldIcon class="text-on-surface-variant shrink-0" :size="20" />
      <p class="text-xs text-on-surface-variant leading-relaxed">{{ $t('about.legal') }}</p>
    </div>
  </SubPage>
</template>

<script setup>
import { computed, onMounted } from 'vue'
import { useHiCoStore } from '@/stores/HiCo'
import { openWebsite } from '@/helpers/KernelSU'
import SubPage from '@/components/ui/SubPage.vue'
import RippleComponent from '@/components/ui/Ripple.vue'
import InformationOutlineIcon from '@/components/icons/InformationOutline.vue'
import GithubIcon from '@/components/icons/Github.vue'
import OpenInNewIcon from '@/components/icons/OpenInNew.vue'
import ShieldIcon from '@/components/icons/Shield.vue'
import FlameIcon from '@/components/icons/Flame.vue'
import SnowflakeIcon from '@/components/icons/Snowflake.vue'
import ChipsetIcon from '@/components/icons/Chipset.vue'
import RocketIcon from '@/components/icons/Rocket.vue'
import Smartphone from '@/components/icons/Smartphone.vue'

const hico = useHiCoStore()
const s = computed(() => hico.status)
onMounted(() => hico.status.version || hico.refreshStatus())

const features = [
  {
    key: 'auto',
    icon: FlameIcon,
    shape: 'shape-sunny',
    tone: 'bg-primary-container text-on-primary-container',
  },
  {
    key: 'safety',
    icon: ShieldIcon,
    shape: 'shape-cookie6',
    tone: 'bg-error-container text-on-error-container',
  },
  {
    key: 'restore',
    icon: SnowflakeIcon,
    shape: 'shape-cookie9',
    tone: 'bg-secondary-container text-on-secondary-container',
  },
  {
    key: 'devices',
    icon: Smartphone,
    shape: 'shape-clover4',
    tone: 'bg-tertiary-container text-on-tertiary-container',
  },
  {
    key: 'kernels',
    icon: ChipsetIcon,
    shape: 'shape-pentagon',
    tone: 'bg-primary-container text-on-primary-container',
  },
  {
    key: 'extreme',
    icon: RocketIcon,
    shape: 'shape-burst',
    tone: 'bg-tertiary-container text-on-tertiary-container',
  },
]

const links = [
  { key: 'hico', url: 'https://github.com/FebriCahyaa/HiCo-Release' },
  { key: 'flux', url: 'https://github.com/FebriCahyaa/Flux/releases' },
]
</script>

<style scoped>
.hero {
  padding: 22px;
  border-radius: 32px;
  background: var(--color-primary-container);
  color: var(--color-on-primary-container);
}

.chip {
  font-size: 11px;
  font-weight: 700;
  padding: 3px 10px;
  border-radius: 999px;
  background: color-mix(in srgb, var(--color-surface) 40%, transparent);
}

.section {
  font-size: 14px;
  font-weight: 600;
  color: var(--color-primary);
  padding: 8px 16px;
}

.badge {
  width: 40px;
  height: 40px;
  display: grid;
  place-items: center;
  flex-shrink: 0;
}

.split {
  display: grid;
  grid-template-columns: 1fr 1fr;
  gap: 12px;
}

.split > div {
  padding: 12px;
  border-radius: 18px;
  background: var(--color-surface-container-high);
}
</style>
