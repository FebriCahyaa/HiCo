#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: 2024 The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

from extract_utils.fixups_blob import (
    blob_fixup,
    blob_fixups_user_type,
)

from extract_utils.fixups_lib import (
    lib_fixup_remove,
    lib_fixups,
    lib_fixups_user_type,
)

from extract_utils.main import (
    ExtractUtils,
    ExtractUtilsModule,
)

namespace_imports = [
    'device/samsung/universal9830-common',
    'hardware/samsung',
    'hardware/samsung_slsi-linaro/exynos',
    'hardware/samsung_slsi-linaro/exynos/gralloc/gralloc3',
    'hardware/samsung_slsi-linaro/graphics',
    'hardware/samsung_slsi-linaro/interfaces',
    'vendor/samsung/universal9830-common'
]


def lib_fixup_vendor_suffix(lib: str, partition: str, *args, **kwargs):
    return f'{lib}_{partition}' if partition == 'vendor' else None

lib_fixups: lib_fixups_user_type = {
    **lib_fixups,
    (
        'libuuid',
    ): lib_fixup_vendor_suffix,
}

blob_fixups: blob_fixups_user_type = {
    'vendor/lib64/libexynoscamera3.so': blob_fixup()
        .sig_replace('14 00 00 94 0A', '1F 20 03 D5 0A')
        .sig_replace('A8 FF FF 97', '1F 20 03 D5')
        .sig_replace('AB 02 20 36', '1F 20 03 D5'),
    'vendor/lib64/sensors.sensorhub.so': blob_fixup()
        .add_needed('libutils-v32.so')
        .binary_regex_replace(b'_ZN7android6Thread3runEPKcim', b'_ZN7utils326Thread3runEPKcim'),
    'vendor/firmware/wlan/qcom_cfg.ini': blob_fixup()
        .regex_replace('swlan0', 'wlan1')
        .regex_replace('gChannelBondingMode24GHz=0', 'gChannelBondingMode24GHz=1'),
}  # fmt: skip

module = ExtractUtilsModule(
    'r8s',
    'samsung',
    blob_fixups=blob_fixups,
    lib_fixups=lib_fixups,
    namespace_imports=namespace_imports,
)

if __name__ == '__main__':
    utils = ExtractUtils.device_with_common(module, 'universal9830-common', module.vendor)
    utils.run()
