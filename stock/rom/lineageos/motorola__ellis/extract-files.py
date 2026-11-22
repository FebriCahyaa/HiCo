#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

from extract_utils.fixups_blob import (
    blob_fixup,
    blob_fixups_user_type,
)
from extract_utils.fixups_lib import (
    lib_fixups,
    lib_fixups_user_type,
)
from extract_utils.main import (
    ExtractUtils,
    ExtractUtilsModule,
)

namespace_imports = [
    'hardware/mediatek',
    'hardware/mediatek/libmtkperf_client',
    'vendor/motorola/mt6765-common',
]

lib_fixups: lib_fixups_user_type = {
    **lib_fixups,
}

blob_fixups: blob_fixups_user_type = {
    'vendor/lib/hw/audio.primary.mt6765.so': blob_fixup()
        .add_needed('libstagefright_foundation-v33.so')
        .replace_needed('libalsautils.so', 'libalsautils-v31.so'),
    'vendor/lib/sensors.moto.so': blob_fixup()
        .add_needed('libbase_shim.so')
        .replace_needed('libutils.so', 'libutils-v32.so'),
    'vendor/lib/libcam.utils.sensorprovider.so': blob_fixup()
        .replace_needed('libsensorndkbridge.so', 'android.hardware.sensors@1.0-convert-shared.so'),
    ('vendor/lib/libmtkcam_stdutils.so', 'vendor/lib/hw/android.hardware.camera.provider@2.6-impl-mediatek.so'): blob_fixup()
        .replace_needed('libutils.so', 'libutils-v32.so'),
    ('vendor/lib/lib3a.flash.so', 'vendor/lib/libSQLiteModule_VER_ALL.so'): blob_fixup()
        .add_needed("liblog.so"),
    'vendor/lib/libcam.hal3a.v3.so': blob_fixup()
        .sig_replace('07 46 00 20 38 60 a0 20 0f f1 16 e9', '07 46 00 20 38 60 a0 20 be f7 ef fd')
        .sig_replace('00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 48 78 44 4e f1 b6 bd', '02 b5 40 f2 f8 60 50 f1 22 eb 02 bd'),
}  # fmt: skip

module = ExtractUtilsModule(
    'ellis',
    'motorola',
    blob_fixups=blob_fixups,
    lib_fixups=lib_fixups,
    namespace_imports=namespace_imports,
    add_firmware_proprietary_file=True,
)

if __name__ == '__main__':
    utils = ExtractUtils.device_with_common(module, 'mt6765-common', module.vendor)
    utils.run()
