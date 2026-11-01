#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: The LineageOS Project
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
    'hardware/qcom-caf/sm8450-6.6',
]

blob_fixups: blob_fixups_user_type = {
    ('odm/etc/customization/XQ-GH44/config.prop', 'odm/etc/customization/XQ-GH54_EEA/config.prop', 'odm/etc/customization/XQ-GH74/config.prop'): blob_fixup()
        .regex_replace('vendor', 'odm'),
}  # fmt: skip


module = ExtractUtilsModule(
    'pdx268',
    'sony',
    namespace_imports=namespace_imports,
    blob_fixups=blob_fixups,
)

if __name__ == '__main__':
    utils = ExtractUtils.device_with_common(module, 'elbe-common', module.vendor)
    utils.run()
