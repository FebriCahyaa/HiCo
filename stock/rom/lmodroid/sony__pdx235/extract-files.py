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
    'hardware/sony',
    'vendor/qcom/opensource/display',
    'vendor/sony/sm6375-common',
]

lib_fixups: lib_fixups_user_type = {
    **lib_fixups,
}

blob_fixups: blob_fixups_user_type = {
    'vendor/lib64/camera/components/com.arcsoft.node.smooth_transition.so': blob_fixup()
        .add_needed('liblog.so'),
    'vendor/lib64/hw/fingerprint.default.so': blob_fixup()
        .binary_regex_replace(b'bix.fingerprint', b'fingerprint\x00\x00\x00\x00'),
    'vendor/lib64/libarcsoft_high_dynamic_range_v5.so': blob_fixup()
        .clear_symbol_version('remote_register_buf'),
    'vendor/lib64/libmorpho_movie_stabilizer.so': blob_fixup()
        .clear_symbol_version('AHardwareBuffer_acquire')
        .clear_symbol_version('AHardwareBuffer_describe')
        .clear_symbol_version('AHardwareBuffer_lockPlanes')
        .clear_symbol_version('AHardwareBuffer_release')
        .clear_symbol_version('AHardwareBuffer_unlock'),
    'vendor/lib64/libmorpho_single_camera.so': blob_fixup()
        .clear_symbol_version('remote_handle64_close')
        .clear_symbol_version('remote_handle64_invoke')
        .clear_symbol_version('remote_handle64_open')
        .clear_symbol_version('rpcmem_alloc')
        .clear_symbol_version('rpcmem_free'),
}  # fmt: skip

module = ExtractUtilsModule(
    'pdx235',
    'sony',
    namespace_imports=namespace_imports,
    blob_fixups=blob_fixups,
    lib_fixups=lib_fixups,
)

if __name__ == '__main__':
    utils = ExtractUtils.device_with_common(
        module, 'sm6375-common', module.vendor
    )
    utils.run()
