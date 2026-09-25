let i18nInstance = null

export function setI18n(i18n) {
  i18nInstance = i18n
}

/** Translation outside components (helpers). */
export function getTranslation(key, params) {
  return i18nInstance ? i18nInstance.global.t(key, params) : key
}

export const LANGUAGES = { en: 'English', id: 'Bahasa Indonesia' }
