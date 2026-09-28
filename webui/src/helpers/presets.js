import LeafIcon from '@/components/icons/Leaf.vue'
import SnowflakeIcon from '@/components/icons/Snowflake.vue'
import ThermostatIcon from '@/components/icons/Thermostat.vue'
import FlameIcon from '@/components/icons/Flame.vue'
import RocketIcon from '@/components/icons/Rocket.vue'

// Presets are defined in hicod (Config.cpp, `hicod config presets`); this adds how they look.
export const PRESET_STYLE = {
  daily: {
    icon: LeafIcon,
    shape: 'shape-flower',
    tone: 'bg-secondary-container text-on-secondary-container',
    risk: null,
  },
  cool: {
    icon: SnowflakeIcon,
    shape: 'shape-cookie9',
    tone: 'bg-secondary-container text-on-secondary-container',
    risk: null,
  },
  balanced: {
    icon: ThermostatIcon,
    shape: 'shape-clover4',
    tone: 'bg-primary-container text-on-primary-container',
    risk: null,
  },
  extreme: {
    icon: FlameIcon,
    shape: 'shape-sunny',
    tone: 'bg-tertiary-container text-on-tertiary-container',
    risk: 'warning',
  },
  overclock: {
    icon: RocketIcon,
    shape: 'shape-burst',
    tone: 'bg-error-container text-on-error-container',
    risk: 'danger',
  },
}
