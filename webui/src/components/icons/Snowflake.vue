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
    <path d="M12 2v20M4.9 6l14.2 12M19.1 6 4.9 18" />
    <path d="m9 3 3 3 3-3M9 21l3-3 3 3M3 9.2l4.1 1.1L6 14.4M21 14.8l-4.1-1.1L18 9.6" />
  </svg>
</template>

<script setup>
defineProps({
  size: { type: [String, Number], default: 24 },
  color: { type: String, default: 'currentColor' },
})
</script>
