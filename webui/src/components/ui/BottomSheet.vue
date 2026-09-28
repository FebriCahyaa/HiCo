<template>
  <!--
    Generic detail sheet: a scrim + glass-surface panel that rises from the
    bottom on mobile (M3 Expressive default spatial spring). Same open/close
    contract as ConfirmDialog (v-model:open), so any card can drive it.
  -->
  <Teleport to="body">
    <Transition name="sheet">
      <div
        v-if="open"
        class="scrim fixed inset-0 z-[70] flex items-end justify-center md:items-center"
        @click="close"
      >
        <div
          class="sheet glass-surface w-full max-w-lg"
          role="dialog"
          aria-modal="true"
          :aria-label="title"
          @click.stop
        >
          <span class="handle" aria-hidden="true" />
          <div class="px-5 pt-1 pb-2 flex items-start justify-between gap-3">
            <h2 v-if="title" class="m3-headline text-xl text-on-surface leading-tight">
              {{ title }}
            </h2>
            <button
              class="close-btn m3-press shrink-0"
              :aria-label="$t('common.close')"
              @click="close"
            >
              <CloseIcon :size="18" />
            </button>
          </div>
          <div class="sheet-body px-5 pb-5">
            <slot />
          </div>
        </div>
      </div>
    </Transition>
  </Teleport>
</template>

<script setup>
import CloseIcon from '@/components/icons/Close.vue'

const props = defineProps({
  open: { type: Boolean, default: false },
  title: { type: String, default: '' },
})
const emit = defineEmits(['update:open'])
const close = () => emit('update:open', false)
</script>

<style scoped>
.scrim {
  background: rgb(0 0 0 / 0.5);
}

.sheet {
  max-height: 85vh;
  overflow-y: auto;
  border-radius: 28px 28px 0 0;
  padding-top: 10px;
  padding-bottom: env(safe-area-inset-bottom, 0px);
  box-shadow: 0 -8px 32px rgb(0 0 0 / 0.3);
}

@media (min-width: 768px) {
  .sheet {
    border-radius: 28px;
    margin-bottom: 24px;
  }
}

.handle {
  display: block;
  width: 36px;
  height: 4px;
  margin: 0 auto 12px;
  border-radius: 999px;
  background: var(--color-outline-variant);
}

@media (min-width: 768px) {
  .handle {
    display: none;
  }
}

.close-btn {
  width: 32px;
  height: 32px;
  display: grid;
  place-items: center;
  border-radius: 999px;
  color: var(--color-on-surface-variant);
  background: var(--color-surface-container-high);
}

.sheet-enter-active,
.sheet-leave-active {
  transition: opacity var(--m3-spring-fast-effects-duration) var(--m3-spring-fast-effects);
}

.sheet-enter-active .sheet {
  transition: transform var(--m3-spring-default-spatial-duration) var(--m3-spring-default-spatial);
}

.sheet-leave-active .sheet {
  transition: transform var(--m3-spring-fast-spatial-duration) var(--m3-spring-fast-spatial);
}

.sheet-enter-from,
.sheet-leave-to {
  opacity: 0;
}

.sheet-enter-from .sheet,
.sheet-leave-to .sheet {
  transform: translateY(100%);
}

@media (min-width: 768px) {
  .sheet-enter-from .sheet,
  .sheet-leave-to .sheet {
    transform: translateY(24px) scale(0.96);
  }
}

@media (prefers-reduced-motion: reduce) {
  .sheet-enter-active,
  .sheet-leave-active,
  .sheet-enter-active .sheet,
  .sheet-leave-active .sheet {
    transition: none;
  }
}
</style>
