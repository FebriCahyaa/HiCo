import { useI18n } from 'vue-i18n'
import { useHiCoStore } from '@/stores/HiCo'
import { useNotifyStore } from '@/stores/Notify'
import { PRESET_STYLE } from '@/helpers/presets'

/** Mode, preset and single-key changes with the right warning first and feedback after. */
export function useSettingsActions() {
  const { t, tm, rt } = useI18n()
  const hico = useHiCoStore()
  const notify = useNotifyStore()

  async function guarded(action, success) {
    try {
      await action()
      notify.success(success)
      hico.refreshStatus()
      return true
    } catch (e) {
      notify.error(t('notify.failed', { error: e.message }))
      return false
    }
  }

  async function setMode(mode) {
    if (mode === hico.config.mode) return false
    if (mode === 'extreme') {
      const ok = await notify.confirm({
        tone: 'warning',
        title: t('mode.confirm.extreme.title'),
        message: t('mode.confirm.extreme.message'),
        points: [
          t('mode.confirm.extreme.p1'),
          t('mode.confirm.extreme.p2'),
          t('mode.confirm.extreme.p3'),
        ],
        confirmText: t('mode.confirm.extreme.action'),
      })
      if (!ok) return false
    } else if (mode === 'off') {
      const ok = await notify.confirm({
        tone: 'info',
        title: t('mode.confirm.off.title'),
        message: t('mode.confirm.off.message'),
        confirmText: t('mode.confirm.off.action'),
      })
      if (!ok) return false
    }
    return guarded(() => hico.set('mode', mode), t('mode.saved', { mode: t(`mode.${mode}.title`) }))
  }

  async function applyPreset(name) {
    const risk = PRESET_STYLE[name]?.risk
    const ok = await notify.confirm({
      tone: risk || 'info',
      title: t('presets.confirm_title', { name: t(`presets.${name}.title`) }),
      message: t(`presets.${name}.confirm`),
      points: tm(`presets.${name}.points`).map((m) => rt(m)),
      confirmText: t('presets.apply'),
    })
    if (!ok) return false
    return guarded(
      () => hico.applyPreset(name),
      t('presets.applied', { name: t(`presets.${name}.title`) }),
    )
  }

  /** Keys that deserve a warning before they are switched on. */
  const WARN_ON = {
    thermal_overclock: 'danger',
    stop_thermal_hal: 'warning',
  }

  async function setKey(key, value) {
    const tone = WARN_ON[key]
    if (tone && (value === true || value === '1')) {
      const ok = await notify.confirm({
        tone,
        title: t(`keys.${key}.title`),
        message: t(`keys.${key}.warn`),
        confirmText: t('common.enable'),
      })
      if (!ok) return false
    }
    const v = typeof value === 'boolean' ? (value ? '1' : '0') : value
    return guarded(() => hico.set(key, v), t('notify.saved'))
  }

  return { setMode, applyPreset, setKey, WARN_ON }
}
