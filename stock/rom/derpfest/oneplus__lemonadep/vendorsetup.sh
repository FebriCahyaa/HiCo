echo 'Starting to clone stuffs needed to build for lemonadep'

# Common
echo 'Cloning common tree'
git clone https://github.com/JYRRC/device_oneplus_sm8350-common.git -b derp device/oneplus/sm8350-common

# Vendor
echo 'Cloning vendor tree'
rm -rf vendor/oneplus/lemonadep && git clone https://github.com/JYRRC/vendor_oneplus_lemonadep.git -b derp vendor/oneplus/lemonadep

# Vendor Common
echo 'Cloning vendor tree'
rm -rf vendor/oneplus/sm8350-common && git clone https://github.com/JYRRC/vendor_oneplus_sm8350-common.git -b derp vendor/oneplus/sm8350-common

# Kernel
echo 'Cloning kernel tree'
git clone https://github.com/JYRRC/kernel_oneplus_sm8350.git -b udc kernel/oneplus/sm8350

# Hardware Oplus
echo 'Cloning hardware oplus'
rm -rf hardware/oplus && git clone https://github.com/JYRRC/hardware_oplus.git -b udc hardware/oplus

# ViperFx
echo 'Cloning Viper'
git clone https://github.com/JYRRC/packages_apps_ViPER4AndroidFX.git -b hzn packages/apps/ViPER4AndroidFX

# BCR
echo 'Cloning bcr'
git clone https://github.com/JYRRC/vendor_bcr.git -b main vendor/bcr

echo 'Cloning process is completed, now its time for lunch'
