#!/usr/bin/env python3
from __future__ import annotations

import importlib.util
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TOOL = ROOT / "tools" / "hico_evidence_parsers.py"

spec = importlib.util.spec_from_file_location("hico_evidence_parsers", TOOL)
assert spec and spec.loader
h = importlib.util.module_from_spec(spec)
spec.loader.exec_module(h)

products = h.parse_android_products_mk(
    """
PRODUCT_MAKEFILES := $(LOCAL_DIR)/garnet.mk $(LOCAL_DIR)/garnet_vendor.mk
PRODUCT_MAKEFILES += $(LOCAL_DIR)/garnet-eng.mk
COMMON_LUNCH_CHOICES := lineage_garnet-userdebug lineage_garnet-eng
"""
)
assert products["schema"] == "hico.source-evidence-parsers.v1"
assert products["product_makefiles"] == [
    "$(LOCAL_DIR)/garnet-eng.mk",
    "$(LOCAL_DIR)/garnet.mk",
    "$(LOCAL_DIR)/garnet_vendor.mk",
]
assert products["common_lunch_choices"] == ["lineage_garnet-eng", "lineage_garnet-userdebug"]

# Continuations and += assignments must remain deterministic.
device = h.parse_device_mk(
    """
include $(LOCAL_PATH)/garnet-common.mk
$(call inherit-product, vendor/xiaomi/garnet/device-vendor.mk)
PRODUCT_PACKAGES += Foo Bar \\
    Baz Foo
PRODUCT_COPY_FILES := src/a:vendor/etc/a \\
    src/b:vendor/etc/b
PRODUCT_SOONG_NAMESPACES += vendor/xiaomi/garnet
DEVICE_PACKAGE_OVERLAYS := overlay/garnet
"""
)
assert device["product_packages"] == ["Bar", "Baz", "Foo"]
assert device["product_copy_files"] == ["src/a:vendor/etc/a", "src/b:vendor/etc/b"]
assert device["product_soong_namespaces"] == ["vendor/xiaomi/garnet"]
assert device["device_package_overlays"] == ["overlay/garnet"]
assert device["inherited_products"] == ["vendor/xiaomi/garnet/device-vendor.mk"]

bp = h.parse_android_bp(
    """
package { default_applicable_licenses: ["Android-Apache-2.0"] }
soong_namespace { imports: ["hardware/xiaomi", "vendor/xiaomi"] }
cc_library {
    name: "libgarnet",
    srcs: ["foo.cpp", "bar.cpp"],
    shared_libs: ["libbase"],
    defaults: ["garnet_defaults"],
}
"""
)
assert [m["type"] for m in bp["modules"]] == ["cc_library", "package", "soong_namespace"]
lib = next(m for m in bp["modules"] if m.get("name") == "libgarnet")
assert lib["srcs"] == ["bar.cpp", "foo.cpp"]
assert lib["shared_libs"] == ["libbase"]
assert lib["defaults"] == ["garnet_defaults"]
ns = next(m for m in bp["modules"] if m["type"] == "soong_namespace")
assert ns["imports"] == ["hardware/xiaomi", "vendor/xiaomi"]

mk = h.parse_android_mk(
    """
include $(CLEAR_VARS)
LOCAL_PATH := $(call my-dir)
LOCAL_MODULE := libgarnet
LOCAL_SRC_FILES := foo.cpp bar.cpp
LOCAL_SHARED_LIBRARIES += libbase
include $(BUILD_SHARED_LIBRARY)
include $(CLEAR_VARS)
LOCAL_MODULE := garnet_tool
LOCAL_SRC_FILES := main.cpp
include $(BUILD_EXECUTABLE)
"""
)
assert mk["build_includes"] == ["BUILD_EXECUTABLE", "BUILD_SHARED_LIBRARY"]
assert [m["module"] for m in mk["modules"]] == ["garnet_tool", "libgarnet"]
libmk = next(m for m in mk["modules"] if m["module"] == "libgarnet")
assert libmk["src_files"] == ["bar.cpp", "foo.cpp"]
assert libmk["shared_libraries"] == ["libbase"]

extract = h.parse_extract_files_sh(
    """
#!/bin/sh
source \"$HELPER\"
source ./extract-utils.sh
extract "$MY_DIR/../proprietary-files.txt" "$SRC"
extract_vendor_files vendor/proprietary-files.txt "$SRC"
"""
)
assert extract["sourced_scripts"] == ["$HELPER", "./extract-utils.sh"]
assert extract["proprietary_file_lists"] == ["$MY_DIR/../proprietary-files.txt", "vendor/proprietary-files.txt"]
assert len(extract["extract_calls"]) == 2

prop = h.parse_proprietary_files_txt(
    """
# comment
vendor/lib64/libgarnet.so
?vendor/etc/permissions/garnet.xml
vendor/etc/source.xml:vendor/etc/destination.xml
!system/lib64/liboptional.so|vendor/lib64/liboptional.so
"""
)
assert prop["entry_count"] == 4
assert any(x["source"] == "vendor/etc/permissions/garnet.xml" and x["prefix"] == "?" for x in prop["entries"])
assert any(
    x["source"] == "vendor/etc/source.xml"
    and x["destination"] == "vendor/etc/destination.xml"
    for x in prop["entries"]
)
assert any(x["prefix"] == "!" and x["destination"] == "vendor/lib64/liboptional.so" for x in prop["entries"])

# Determinism: repeated parsing of identical input must be byte-identical.
assert h.parse_android_products_mk("PRODUCT_MAKEFILES := b a\n") == h.parse_android_products_mk("PRODUCT_MAKEFILES := b a\n")
assert h.parse_proprietary_files_txt("a\nb\n") == h.parse_proprietary_files_txt("a\nb\n")

print("HiCo evidence parser test: PASS")
