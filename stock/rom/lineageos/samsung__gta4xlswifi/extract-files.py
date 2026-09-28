#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: 2024 The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

from extract_utils.fixups_blob import (
    blob_fixup,
    blob_fixups_user_type,
)
from extract_utils.main import (
    ExtractUtils,
    ExtractUtilsModule,
)

namespace_imports = [
    'device/samsung/gta4xls-common',
    'hardware/samsung_slsi-linaro/exynos',
    'hardware/samsung_slsi-linaro/graphics',
    'hardware/samsung_slsi-linaro/interfaces',
    'vendor/samsung/gta4xls-common',
]

blob_fixups: blob_fixups_user_type = {
    'vendor/lib64/libexynoscamera3.so': blob_fixup()
        .add_needed('libshim_camera.so'),
} # fmt: skip

module = ExtractUtilsModule(
    'gta4xlswifi',
    'samsung',
    namespace_imports=namespace_imports,
    add_firmware_proprietary_file=True,
    blob_fixups=blob_fixups,
)

if __name__ == '__main__':
    utils = ExtractUtils.device_with_common(
        module, 'gta4xls-common', module.vendor
    )
    utils.run()
