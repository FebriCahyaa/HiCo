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
    'hardware/lge',
    'hardware/qcom-caf/common/libqti-perfd-client',
    'hardware/qcom-caf/sm8250',
    'hardware/qcom-caf/wlan',
    'vendor/qcom/opensource/commonsys-intf/display',
    'vendor/qcom/opensource/commonsys/display',
    'vendor/qcom/opensource/dataservices',
    'vendor/qcom/opensource/display',
]

def lib_fixup_vendor_suffix(lib: str, partition: str, *args, **kwargs):
    return f'{lib}_vendor' if partition in ['odm', 'vendor'] else None

lib_fixups: lib_fixups_user_type = {
    **lib_fixups,
    (
        'com.qti.stats.pdlib',
        'com.qualcomm.qti.dpm.api@1.0',
        'libmmosal',
        'vendor.qti.imsrtpservice@3.0',
    ): lib_fixup_vendor_suffix,
}

def lib_fixup_system_ext_suffix(lib: str, partition: str, *args, **kwargs):
    return f'{lib}_system_ext' if partition in ['system_ext'] else None

lib_fixups: lib_fixups_user_type = {
    **lib_fixups,
    (
        'libarcsoft_beauty_picselfie',
        'libarcsoft_dualcam_portraitlighting',
        'libarcsoft_dualcam_refocus',
        'libarcsoft_dualcam_refocus_front',
        'libarcsoft_dualcam_refocus_rear_t',
        'libarcsoft_makeup',
        'libarcsoft_picselfie_algorithm',
        'libarcsoft_singlecam_portrait_lighting',
        'libcvp2',
        'libcvp2_hfi',
        'libcvp_common',
        'libdepthmapdecoder.arcsoft',
        'liblghdri',
        'libmorpho_image_stab31',
        'libmpbase',
        'libSRIyuv',
        'vendor.lge.hardware.vss_ims@1.0',
    ): lib_fixup_system_ext_suffix,
}

blob_fixups: blob_fixups_user_type = {
    'vendor/etc/init/vendor.sensors.sscrpcd.rc': blob_fixup()
        .regex_replace('class early_hal', 'class core'),
    'vendor/lib64/liblgdnnsnpe.so': blob_fixup()
        .replace_needed('libstdc++.so', 'libstdc++_vendor.so'),
    'vendor/lib64/libimagerwrapper.so': blob_fixup()
        .add_needed('liblog.so'),
    'vendor/lib64/libwvhidl.so': blob_fixup()
        .add_needed('libcrypto_shim.so'),
    'vendor/lib64/vendor.qti.hardware.camera.postproc@1.0-service-impl.so': blob_fixup()
	    .sig_replace('9A 0A 00 94', 'E0 03 00 AA'),
    'vendor/lib64/libdpps.so': blob_fixup()
        .replace_needed('libtinyxml2.so', 'libtinyxml2-v34.so'),
}  # fmt: skip

module = ExtractUtilsModule(
    'timelm',
    'lge',
    blob_fixups=blob_fixups,
    lib_fixups=lib_fixups,
    namespace_imports=namespace_imports,
)

if __name__ == '__main__':
    utils = ExtractUtils.device(module)
    utils.run()
