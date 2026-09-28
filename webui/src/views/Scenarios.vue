<template>
  <div class="page h-full flex flex-col overflow-hidden">
    <div class="scrollbar-hidden pb-safe-nav flex-1 min-h-0 overflow-y-scroll">
      <div class="max-w-3xl mx-auto px-4 pt-6 pb-6">
        <h1 class="m3-headline text-[32px] text-on-surface px-1 mb-2">
          {{ $t('scenarios.title') }}
        </h1>
        <p class="text-xs text-on-surface-variant px-1 mb-4 leading-relaxed">
          {{ $t('scenarios.intro') }}
        </p>

        <!-- One level per scenario -->
        <div v-for="sc in scenarios" :key="sc.key" class="m3-card p-5 mb-3">
          <div class="flex items-center gap-3 mb-3">
            <span class="badge" :class="[sc.shape, sc.tone]"
              ><component :is="sc.icon" :size="20"
            /></span>
            <span class="flex-1 min-w-0">
              <span class="block text-sm font-semibold text-on-surface">{{
                $t(`scenarios.${sc.key}.title`)
              }}</span>
              <span class="block text-xs text-on-surface-variant mt-0.5">{{
                $t(`scenarios.${sc.key}.description`)
              }}</span>
            </span>
          </div>
          <div class="segmented">
            <button
              v-for="lv in sc.levels"
              :key="lv"
              class="seg m3-press"
              :class="{ on: levelOf(sc) === lv }"
              :disabled="sc.key === 'game' && cfg.mode === 'extreme'"
              @click="setLevel(sc, lv)"
            >
              {{ $t(`scenarios.level.${lv}`) }}
            </button>
          </div>
          <p class="text-xs text-on-surface-variant mt-3 leading-relaxed">
            {{
              sc.key === 'game' && cfg.mode === 'extreme'
                ? $t('settings.level_extreme')
                : $t(`scenarios.hint.${levelOf(sc)}`)
            }}
          </p>
        </div>

        <!-- Which apps belong to which scenario -->
        <h2 class="section">{{ $t('scenarios.apps_title') }}</h2>
        <div class="tabs mb-3" role="tablist">
          <button
            v-for="k in tabs"
            :key="k"
            role="tab"
            :aria-selected="tab === k"
            class="tab m3-press"
            :class="{ on: tab === k }"
            @click="tab = k"
          >
            {{ $t(`scenarios.tab.${k}`) }}
          </button>
        </div>
        <div class="bg-surface-container mb-3 px-4 py-3 rounded-full flex items-center gap-3">
          <SearchIcon class="text-on-surface-variant shrink-0" />
          <input
            v-model="query"
            type="text"
            :placeholder="$t('games.search')"
            class="bg-transparent border-none outline-none text-on-surface placeholder-on-surface-variant w-full"
          />
        </div>
        <p class="text-xs text-on-surface-variant px-2 mb-3 leading-relaxed">
          {{ $t(`scenarios.tab_hint.${tab}`) }}
        </p>

        <LoadingSpinner v-if="loading" class="pt-8" :size="48" />
        <div v-else-if="!shown.length" class="m3-card p-5 text-sm text-on-surface-variant">
          {{ tab === 'games' ? $t('games.empty_games') : $t('games.empty_apps') }}
        </div>
        <div v-else class="pb-4">
          <div v-for="pkg in shown" :key="pkg" class="md3-list">
            <div class="md3-list-item flex items-center gap-4 px-4 py-3">
              <img
                :src="apps.icon(pkg)"
                loading="lazy"
                class="app-icon"
                alt=""
                @error="iconError"
              />
              <div class="flex-1 min-w-0">
                <p class="text-sm font-semibold text-on-surface truncate">{{ apps.label(pkg) }}</p>
                <p class="text-xs text-on-surface-variant truncate">
                  {{ pkg
                  }}<template v-if="otherScenario(pkg)"> · {{ otherScenario(pkg) }}</template>
                </p>
              </div>
              <ToggleSwitch :model-value="isOn(pkg)" @update:modelValue="(v) => toggle(pkg, v)" />
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref, computed, onMounted, onActivated } from 'vue'
import { useI18n } from 'vue-i18n'
import { useHiCoStore } from '@/stores/HiCo'
import { useAppsStore } from '@/stores/Apps'
import { useNotifyStore } from '@/stores/Notify'
import { listApps } from '@/helpers/KernelSU'

import SearchIcon from '@/components/icons/Search.vue'
import GamesIcon from '@/components/icons/Games.vue'
import PersonIcon from '@/components/icons/Person.vue'
import VolumeUpIcon from '@/components/icons/VolumeUp.vue'
import ToggleSwitch from '@/components/ui/ToggleSwitch.vue'
import LoadingSpinner from '@/components/ui/LoadingSpinner.vue'

const { t } = useI18n()
const hico = useHiCoStore()
const apps = useAppsStore()
const notify = useNotifyStore()
const cfg = computed(() => hico.config)

// Max disables throttling, so only games may use it (hicod rejects it elsewhere too).
const scenarios = [
  {
    key: 'game',
    config: 'game_level',
    levels: ['stock', 'relaxed', 'max'],
    icon: GamesIcon,
    shape: 'shape-cookie9',
    tone: 'bg-primary-container text-on-primary-container',
  },
  {
    key: 'social',
    config: 'social_level',
    levels: ['stock', 'relaxed'],
    icon: PersonIcon,
    shape: 'shape-flower',
    tone: 'bg-secondary-container text-on-secondary-container',
  },
  {
    key: 'media',
    config: 'media_level',
    levels: ['stock', 'relaxed'],
    icon: VolumeUpIcon,
    shape: 'shape-clover4',
    tone: 'bg-tertiary-container text-on-tertiary-container',
  },
]
const levelOf = (sc) => cfg.value[sc.config] || (sc.key === 'game' ? 'max' : 'stock')

async function setLevel(sc, lv) {
  if (levelOf(sc) === lv) return
  try {
    await hico.set(sc.config, lv)
    notify.success(
      t('scenarios.saved', {
        scenario: t(`scenarios.${sc.key}.title`),
        level: t(`scenarios.level.${lv}`),
      }),
    )
  } catch (e) {
    notify.error(t('notify.failed', { error: e.message }))
  }
}

// Tabs: the list key each one edits. Games come from Flux; the switch there means "HiCo handles it".
const tabs = ['social', 'media', 'other', 'games']
const listKey = { social: 'social_apps', media: 'media_apps', other: 'whitelist' }
const tab = ref('social')
const query = ref('')
const loading = ref(true)
const userApps = ref([])

const members = (k) => hico.config[listKey[k]]?.split(',').filter(Boolean) || []
const isOn = (pkg) =>
  tab.value === 'games' ? !hico.blacklist.includes(pkg) : members(tab.value).includes(pkg)
// An app sits in one scenario at a time: show where else it is listed.
const otherScenario = (pkg) => {
  if (tab.value === 'games') return ''
  const k = ['social', 'media', 'other'].find((x) => x !== tab.value && members(x).includes(pkg))
  return k ? t(`scenarios.tab.${k}`) : ''
}

const byName = (a, b) => apps.label(a).localeCompare(apps.label(b))
const matches = (pkg) => {
  const q = query.value.trim().toLowerCase()
  return !q || pkg.toLowerCase().includes(q) || apps.label(pkg).toLowerCase().includes(q)
}
const shown = computed(() => {
  if (tab.value === 'games') return hico.games.filter(matches).sort(byName)
  const listed = members(tab.value)
  // Listed apps first (installed or not), then every other installed app that is not a game.
  const rest = userApps.value.filter((p) => !hico.games.includes(p) && !listed.includes(p))
  const installed = new Set(userApps.value)
  return [
    ...listed.filter((p) => installed.has(p) && matches(p)).sort(byName),
    ...rest.filter(matches).sort(byName),
  ]
})

async function load() {
  await Promise.all([hico.loadGames(), hico.loaded ? null : hico.loadConfig()])
  try {
    userApps.value = await listApps()
  } catch {
    userApps.value = []
  }
  await apps.resolve([...hico.games, ...userApps.value])
  loading.value = false
}
onMounted(load)
onActivated(() => hico.loadGames())

async function toggle(pkg, on) {
  try {
    if (tab.value === 'games') {
      await hico.setListed('blacklist', pkg, !on)
    } else {
      // Moving an app to this scenario takes it out of the others.
      if (on) {
        for (const k of ['social', 'media', 'other']) {
          if (k !== tab.value && members(k).includes(pkg))
            await hico.setListed(listKey[k], pkg, false)
        }
      }
      await hico.setListed(listKey[tab.value], pkg, on)
    }
    notify.success(t(on ? 'games.on' : 'games.off', { app: apps.label(pkg) }))
  } catch (e) {
    notify.error(t('notify.failed', { error: e.message }))
  }
}

const iconError = (e) => (e.target.src = './app_icon_fallback.avif')
</script>

<style scoped>
.section {
  font-size: 14px;
  font-weight: 600;
  color: var(--color-primary);
  padding: 16px 4px 8px;
}

.badge {
  width: 40px;
  height: 40px;
  display: grid;
  place-items: center;
  flex-shrink: 0;
}

.segmented {
  display: flex;
  gap: 2px;
}

.seg {
  flex: 1;
  min-width: 0;
  padding: 10px 8px;
  font-size: 13px;
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

.seg:disabled {
  opacity: 0.5;
}

.tabs {
  display: flex;
  gap: 2px;
}

.tab {
  flex: 1;
  min-width: 0;
  padding: 10px 6px;
  font-size: 13px;
  font-weight: 600;
  color: var(--color-on-surface-variant);
  background: var(--color-surface-container);
  border-radius: 8px;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
  transition:
    border-radius var(--m3-spring-fast-spatial-duration) var(--m3-spring-fast-spatial),
    background-color var(--m3-spring-fast-effects-duration) var(--m3-spring-fast-effects);
}

.tab:first-child {
  border-radius: 20px 8px 8px 20px;
}

.tab:last-child {
  border-radius: 8px 20px 20px 8px;
}

.tab.on {
  background: var(--color-secondary-container);
  color: var(--color-on-secondary-container);
  border-radius: 999px;
}

.app-icon {
  width: 44px;
  height: 44px;
  border-radius: 14px;
  object-fit: cover;
  flex-shrink: 0;
}
</style>
