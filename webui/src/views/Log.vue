<template>
  <SubPage
    :title="$t('settings.log.title')"
    :icon="TextIcon"
    shape="shape-cookie4"
    tone="bg-surface-container-highest text-on-surface"
  >
    <div class="flex gap-2 mb-3">
      <button
        v-for="f in ['all', 'warn']"
        :key="f"
        class="chip m3-press"
        :class="
          filter === f
            ? 'bg-secondary-container text-on-secondary-container'
            : 'bg-surface-container text-on-surface-variant'
        "
        @click="filter = f"
      >
        {{ $t(`log.${f}`) }}
      </button>
      <button
        class="chip m3-press ms-auto bg-primary text-on-primary disabled:opacity-60"
        :disabled="saving"
        @click="save"
      >
        {{ $t('log.save') }}
      </button>
    </div>
    <div ref="box" class="log scrollbar-hidden mb-8">
      <p v-if="!shown.length" class="text-on-surface-variant">{{ $t('log.empty') }}</p>
      <p v-for="(l, i) in shown" :key="i" :class="tone(l)">{{ l }}</p>
    </div>
  </SubPage>
</template>

<script setup>
import { ref, computed, nextTick, onMounted, onActivated, onDeactivated, onUnmounted } from 'vue'
import { useI18n } from 'vue-i18n'
import { useHiCoStore } from '@/stores/HiCo'
import { useNotifyStore } from '@/stores/Notify'
import SubPage from '@/components/ui/SubPage.vue'
import TextIcon from '@/components/icons/Text.vue'

const hico = useHiCoStore()
const notify = useNotifyStore()
const { t } = useI18n()
const saving = ref(false)
const lines = ref([])
const filter = ref('all')
const box = ref(null)

const isWarn = (l) => / (W|E|warning|error)[: ]/i.test(l)
const shown = computed(() => (filter.value === 'warn' ? lines.value.filter(isWarn) : lines.value))
const tone = (l) =>
  / (E|error)[: ]/i.test(l) ? 'text-error' : isWarn(l) ? 'text-tertiary' : 'text-on-surface'

async function load() {
  try {
    lines.value = (await hico.log()).split('\n').filter(Boolean)
  } catch {
    lines.value = []
  }
  await nextTick()
  if (box.value) box.value.scrollTop = box.value.scrollHeight
}

async function save() {
  saving.value = true
  try {
    const path = await hico.saveLog()
    notify.success(t('log.saved', { path }))
  } catch {
    notify.error(t('log.save_failed'))
  } finally {
    saving.value = false
  }
}

let timer = null
const start = () => {
  stop()
  load()
  timer = setInterval(load, 3000)
}
const stop = () => timer && clearInterval(timer)
onMounted(start)
onActivated(start)
onDeactivated(stop)
onUnmounted(stop)
</script>

<style scoped>
.chip {
  padding: 6px 14px;
  border-radius: 999px;
  font-size: 13px;
  font-weight: 600;
}

.log {
  max-height: 65vh;
  overflow-y: auto;
  padding: 14px;
  border-radius: 24px;
  background: var(--color-surface-container);
  font-family: ui-monospace, monospace;
  font-size: 11px;
  line-height: 1.55;
  word-break: break-word;
}
</style>
