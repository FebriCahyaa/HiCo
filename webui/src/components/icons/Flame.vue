<template>
  <svg
    :width="size"
    :height="size"
    viewBox="0 0 24 24"
    fill="none"
    :stroke="color"
    stroke-width="2"
    stroke-linecap="round"
    stroke-linejoin="round"
    aria-hidden="true"
  >
    <path
      d="M12 22c4 0 7-2.8 7-6.8 0-3.9-2.6-6.4-4.4-8.9-.4 2-1.3 3.3-2.6 4C12 7.4 10.6 4.4 8 2c.3 3.4-3 6-3 11.2C5 18.2 8 22 12 22Z"
    />
    <path d="M12 22c-1.7 0-3-1.3-3-3 0-2 1.6-3 2.2-4.6.8 1 2.2 1.7 2.7 3 .7 2-.4 4.6-1.9 4.6Z" />
  </svg>
</template>

<script setup>
defineProps({
  size: { type: [String, Number], default: 24 },
  color: { type: String, default: 'currentColor' },
})
</script>
