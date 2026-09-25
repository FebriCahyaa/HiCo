import { defineStore } from 'pinia'
import { ref } from 'vue'
import { getBatchAppLabel, getAppIcon } from '@/helpers/KernelSU'

/** App names and icons, resolved once per package. */
export const useAppsStore = defineStore('apps', () => {
  const labels = ref({})
  const icons = ref({})

  async function resolve(packages) {
    const missing = [...new Set(packages)].filter((p) => p && !(p in labels.value))
    if (!missing.length) return
    for (const p of missing) labels.value[p] = p
    try {
      for (const { packageName, appName } of await getBatchAppLabel(missing)) {
        labels.value[packageName] = appName || packageName
      }
    } catch {
      // package names stay as labels
    }
    for (const p of missing) {
      getAppIcon(p, 96)
        .then((url) => (icons.value[p] = url))
        .catch(() => {})
    }
  }

  const label = (p) => labels.value[p] || p
  const icon = (p) => icons.value[p] || './app_icon_fallback.avif'

  return { labels, icons, resolve, label, icon }
})
