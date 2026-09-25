<template>
  <div class="page h-full flex flex-col overflow-hidden">
    <div class="max-w-3xl mx-auto h-full flex flex-col w-full">
      <div class="flex-none px-5 pt-6">
        <h1 class="m3-headline text-[32px] text-on-surface mb-4">{{ $t('games.title') }}</h1>
        <div class="tabs mb-3" role="tablist">
          <button
            v-for="k in ['games', 'apps']"
            :key="k"
            role="tab"
            :aria-selected="tab === k"
            class="tab m3-press"
            :class="{ on: tab === k }"
            @click="tab = k"
          >
            {{ $t(`games.tab_${k}`) }}
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
      </div>

      <div class="scrollbar-hidden pb-safe-nav flex-1 min-h-0 overflow-y-scroll px-4">
        <p class="text-xs text-on-surface-variant px-2 mb-3 leading-relaxed">
          {{ $t(`games.hint_${tab}`) }}
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
                <p class="text-xs text-on-surface-variant truncate">{{ pkg }}</p>
              </div>
              <ToggleSwitch
                :model-value="
                  tab === 'games' ? !hico.blacklist.includes(pkg) : hico.whitelist.includes(pkg)
                "
                @update:modelValue="(v) => toggle(pkg, v)"
              />
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
import ToggleSwitch from '@/components/ui/ToggleSwitch.vue'
import LoadingSpinner from '@/components/ui/LoadingSpinner.vue'

const { t } = useI18n()
const hico = useHiCoStore()
const apps = useAppsStore()
const notify = useNotifyStore()

const tab = ref('games')
const query = ref('')
const loading = ref(true)
const userApps = ref([])

const byName = (a, b) => apps.label(a).localeCompare(apps.label(b))
const matches = (pkg) => {
  const q = query.value.trim().toLowerCase()
  return !q || pkg.toLowerCase().includes(q) || apps.label(pkg).toLowerCase().includes(q)
}
const shown = computed(() => {
  const list =
    tab.value === 'games' ? hico.games : userApps.value.filter((p) => !hico.games.includes(p))
  return list.filter(matches).sort(byName)
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
  // Games: the switch shows "HiCo boosts this game" (off = blacklisted).
  // Other apps: on = whitelisted (relaxed level only, never max).
  if (tab.value === 'apps' && on) {
    const ok = await notify.confirm({
      tone: 'info',
      title: t('games.whitelist_confirm.title', { app: apps.label(pkg) }),
      message: t('games.whitelist_confirm.message'),
      confirmText: t('common.add'),
      remember: 'whitelist_info',
    })
    if (!ok) return
  }
  try {
    if (tab.value === 'games') await hico.setListed('blacklist', pkg, !on)
    else await hico.setListed('whitelist', pkg, on)
    notify.success(t(on ? 'games.on' : 'games.off', { app: apps.label(pkg) }))
  } catch (e) {
    notify.error(t('notify.failed', { error: e.message }))
  }
}

const iconError = (e) => (e.target.src = './app_icon_fallback.avif')
</script>

<style scoped>
.tabs {
  display: flex;
  gap: 2px;
}

.tab {
  flex: 1;
  padding: 10px 12px;
  font-size: 14px;
  font-weight: 600;
  color: var(--color-on-surface-variant);
  background: var(--color-surface-container);
  border-radius: 8px;
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
