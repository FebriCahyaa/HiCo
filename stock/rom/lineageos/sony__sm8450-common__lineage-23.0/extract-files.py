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
    'device/sony/sm8450-common',
    'hardware/qcom-caf/sm8450',
    'hardware/qcom-caf/wlan',
    'hardware/sony',
    'vendor/qcom/opensource/commonsys-intf/display',
    'vendor/qcom/opensource/commonsys/display',
    'vendor/qcom/opensource/dataservices',
    'vendor/qcom/opensource/display',
]


def lib_fixup_vendor_suffix(lib: str, partition: str, *args, **kwargs):
    return f'{lib}_vendor' if partition == 'vendor' else None


lib_fixups: lib_fixups_user_type = {
    **lib_fixups,
    (
        'com.qualcomm.qti.dpm.api@1.0',
        'libmmosal',
        'vendor.qti.diaghal@1.0',
        'vendor.qti.hardware.fm@1.0',
        'vendor.qti.hardware.wifidisplaysession@1.0',
        'vendor.qti.imsrtpservice@3.0',
    ): lib_fixup_vendor_suffix,
}

blob_fixups: blob_fixups_user_type = {
    'vendor/bin/qcc-trd': blob_fixup()
        .replace_needed('libgrpc++_unsecure.so', 'libgrpc++_unsecure_prebuilt.so'),
    ('vendor/bin/hw/android.hardware.security.keymint-service-qti', 'vendor/lib64/libqtikeymint.so'): blob_fixup()
        .replace_needed('android.hardware.security.keymint-V1-ndk_platform.so', 'android.hardware.security.keymint-V1-ndk.so')
        .replace_needed('android.hardware.security.secureclock-V1-ndk_platform.so', 'android.hardware.security.secureclock-V1-ndk.so')
        .replace_needed('android.hardware.security.sharedsecret-V1-ndk_platform.so', 'android.hardware.security.sharedsecret-V1-ndk.so')
        .add_needed('android.hardware.security.rkp-V1-ndk.so'),
    ('vendor/bin/hw/vendor.semc.hardware.extlight-service.somc', 'vendor/lib64/vendor.semc.hardware.extlight-V1-ndk_platform.so'): blob_fixup()
        .replace_needed('android.hardware.light-V1-ndk_platform.so','android.hardware.light-V1-ndk.so'),
    'vendor/bin/hw/vendor.semc.hardware.secd@1.1-service': blob_fixup()
        .add_needed('android.hardware.security.rkp-V1-ndk.so'),
    'vendor/bin/keyprovd': blob_fixup()
        .add_needed('android.hardware.security.rkp-V1-ndk.so')
        .add_needed('libbase_shim.so'),
    'vendor/bin/thermal-engine-v2': blob_fixup()
        .binary_regex_replace(b'oem/etc/thermal-engine.conf', b'odm/etc/thermal-engine.conf'),
    'vendor/etc/init/vendor.sensors.sscrpcd.rc': blob_fixup()
        .regex_replace('class early_hal', 'class core'),
    'vendor/etc/seccomp_policy/c2audio.vendor.ext-arm64.policy': blob_fixup()
        .add_line_if_missing('setsockopt: 1'),
    'vendor/etc/sensors/hals.conf': blob_fixup()
        .add_line_if_missing('sensors.dynamic_sensor_hal.so'),
    'vendor/etc/msm_irqbalance.conf': blob_fixup()
        .regex_replace('IGNORED_IRQ=27,23,38$', 'IGNORED_IRQ=27,23,38,115,332'),
    'vendor/etc/media_codecs_taro.xml': blob_fixup()
        .regex_replace('.*media_codecs_(c2_audio|google_audio|google_c2|google_telephony|dolby_audio|sony_c2_audio|vendor_audio).*\n', ''),
    'vendor/etc/wfdconfig.xml': blob_fixup()
        .regex_replace('<M4Enable>0</M4Enable>', '<M4Enable>1</M4Enable>')
        .regex_replace('<UIBCValid>0</UIBCValid>', '<UIBCValid>1</UIBCValid>')
        .regex_replace('<USB>1</USB>', '<USB>3</USB>'),
    'vendor/lib64/libiVptApi.so': blob_fixup()
        .add_needed('libiVptLibC.so'),
    'vendor/lib64/libiVptLibC.so': blob_fixup()
        .add_needed('libcrypto.so')
        .add_needed('libiVptHkiDec.so'),
    'vendor/lib64/vendor.libdpmframework.so': blob_fixup()
        .add_needed('libhidlbase_shim.so'),
}  # fmt: skip


module = ExtractUtilsModule(
    'sm8450-common',
    'sony',
    namespace_imports=namespace_imports,
    blob_fixups=blob_fixups,
    lib_fixups=lib_fixups,
)

if __name__ == '__main__':
    utils = ExtractUtils.device(module)
    utils.run()
