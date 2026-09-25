<template>
  <!-- Sub page: back button, hero badge + headline, scrolling body. -->
  <div class="page h-full flex flex-col overflow-hidden bg-surface">
    <div class="max-w-3xl mx-auto h-full flex flex-col w-full">
      <div class="flex-none p-5 pb-3">
        <button
          class="m3-press w-10 h-10 -ms-2 rounded-full grid place-items-center text-on-surface hover:bg-surface-container-high"
          :aria-label="$t('common.back')"
          @click="router.back()"
        >
          <ArrowLeftIcon class="w-6 h-6 rtl:rotate-180" />
        </button>
      </div>
      <div class="scrollbar-hidden pb-safe-nav flex-1 min-h-0 overflow-y-scroll px-4">
        <div class="flex items-center gap-4 mt-6 mb-4 px-1">
          <span class="hero-badge" :class="[shape, tone]"><component :is="icon" :size="28" /></span>
          <h1 class="m3-headline text-4xl text-on-surface">{{ title }}</h1>
        </div>
        <slot />
      </div>
    </div>
  </div>
</template>

<script setup>
import { useRouter } from 'vue-router'
import ArrowLeftIcon from '@/components/icons/ArrowLeft.vue'

defineProps({
  title: { type: String, required: true },
  icon: { type: Object, required: true },
  shape: { type: String, default: 'shape-cookie9' },
  tone: { type: String, default: 'bg-primary-container text-on-primary-container' },
})
const router = useRouter()
</script>

<style scoped>
.hero-badge {
  width: 56px;
  height: 56px;
  display: grid;
  place-items: center;
  flex-shrink: 0;
}
</style>
