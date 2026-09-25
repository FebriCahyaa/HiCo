import './assets/main.css'

import { createApp } from 'vue'
import { createPinia } from 'pinia'
import { createI18n } from 'vue-i18n'
import App from './App.vue'
import router from './router'
import { setI18n, LANGUAGES } from '@/helpers/Locales'

import en from '@/locales/en.json'
import id from '@/locales/id.json'

function preferredLocale() {
  try {
    const saved = localStorage.getItem('hico-language')
    if (saved && saved in LANGUAGES) return saved
  } catch {
    // storage unavailable
  }
  return (navigator.language || 'en').toLowerCase().startsWith('id') ? 'id' : 'en'
}

const i18n = createI18n({
  legacy: false,
  locale: preferredLocale(),
  fallbackLocale: 'en',
  messages: { en, id },
})
setI18n(i18n)
document.documentElement.lang = i18n.global.locale.value

const app = createApp(App)
app.use(createPinia())
app.use(i18n)
app.use(router)
router.isReady().then(() => app.mount('#app'))

export { i18n }
