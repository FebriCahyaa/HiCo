import { createRouter, createWebHashHistory } from 'vue-router'
import { WXEventHandler } from 'webuix'

import Home from '@/views/Home.vue'
import Scenarios from '@/views/Scenarios.vue'
import Monitor from '@/views/Monitor.vue'
import Settings from '@/views/Settings.vue'
import Presets from '@/views/Presets.vue'
import Advanced from '@/views/Advanced.vue'
import Log from '@/views/Log.vue'
import About from '@/views/About.vue'

window.wx = new WXEventHandler()

// Hash history: the WebUI is served from the module directory by several
// root managers (KernelSU, APatch, MMRL, WebUI X), not always at "/".
const router = createRouter({
  history: createWebHashHistory(),
  routes: [
    { path: '/', name: 'Home', component: Home },
    { path: '/scenarios', name: 'Scenarios', component: Scenarios },
    { path: '/games', redirect: '/scenarios' },
    { path: '/monitor', name: 'Monitor', component: Monitor },
    { path: '/settings', name: 'Settings', component: Settings },
    { path: '/settings/presets', name: 'Presets', component: Presets },
    { path: '/settings/advanced', name: 'Advanced', component: Advanced },
    { path: '/settings/log', name: 'Log', component: Log },
    { path: '/settings/about', name: 'About', component: About },
    { path: '/:pathMatch(.*)*', redirect: '/' },
  ],
})

// Back button (WebUI X): up one level, exit from Home.
wx.on(window, 'back', () => {
  const current = router.currentRoute.value.path || '/'
  if (current === '/') {
    window.webui?.exit?.()
    return
  }
  const segments = current.split('/').filter(Boolean)
  router.push(segments.length > 1 ? '/' + segments.slice(0, -1).join('/') : '/')
})

export default router
