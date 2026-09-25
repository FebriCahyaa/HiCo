# Third-party notices

HiCo Thermal is proprietary (see [LICENSE](LICENSE) and [EULA.md](EULA.md)). The following
files come from other projects and remain under their original license, Apache License 2.0
(http://www.apache.org/licenses/LICENSE-2.0). Their license terms, not HiCo's EULA, apply to them.

| File | Origin |
|---|---|
| `module/verify.sh` | Flux Tweaks installer integrity check, derived from Encore Tweaks |
| `module/META-INF/com/google/android/update-binary`, `updater-script` | Magisk module installer template, as shipped with Flux Tweaks / Encore Tweaks |
| `.github/scripts/changelog.sh` | Flux Tweaks release tooling |
| `.github/scripts/gen_sha256sum.sh` | Flux Tweaks / Encore Tweaks build tooling |
| `webui/src/assets/*.css`, `webui/src/components/**`, `webui/src/helpers/{KernelSU,WXInterfaces,WebViewCompat}.js`, `webui/src/stores/Notify.js`, `webui/src/App.vue` and their build output in `module/webroot/` | Flux Tweaks WebUI, derived from Encore Tweaks |

The WebUI font, **Google Sans Flex** (`webui/src/assets/fonts/`, bundled in `module/webroot/assets/`),
is licensed under the SIL Open Font License 1.1 (https://openfontlicense.org), © Google LLC.

## Flux Tweaks (Apache License 2.0)
Source: https://github.com/FebriCahyaa/Flux

    Copyright (C) 2024-2026 FebriCahyaa

## Encore Tweaks (Apache License 2.0)
Source: https://github.com/Rem01Gaming/encore

    Copyright (C) 2024-2026 Rem01Gaming

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

## mi-thermal-crypt (format reference only)
The encrypted mi_thermald config format (AES-128-CBC, PKCS#7, key and IV "thermalopenssl.h") is
documented by https://github.com/adithya2306/mi-thermal-crypt (Adithya R). That repository has no
license, so none of its code is used: `jni/src/MiCrypt.cpp` is an independent implementation of
AES (FIPS-197) that reads and writes the same format.

## Firmware dumps
Device profiles in `devices/` are facts (names, file names, service names) read from Xiaomi
firmware dumps published at https://dumps.tadiphone.dev/dumps/xiaomi. No firmware files are
redistributed. Xiaomi, Redmi and POCO are trademarks of Xiaomi Inc.; HiCo Thermal is not
affiliated with or endorsed by Xiaomi.
