# kernel/xiaomi
rm -rf kernel/xiaomi
git clone -b lineage-21 https://github.com/surya-aosp/kernel_xiaomi_surya.git kernel/xiaomi/surya --depth=1

# vendor/xiaomi
rm -rf vendor/xiaomi
git clone -b aosp https://github.com/surya-aosp/vendor_xiaomi_surya.git vendor/xiaomi/surya --depth=1

# firmware/xiaomi
rm -rf firmware/xiaomi
git clone -b tiramisu https://gitlab.com/apaosha/firmware_xiaomi_surya.git firmware/xiaomi/surya --depth=1

# vendor/gcgop
rm -rf vendor/gcgop
git clone -b qpr2 https://github.com/surya-aosp/vendor_gcgop.git vendor/gcgop --depth=1

