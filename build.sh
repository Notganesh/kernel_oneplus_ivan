export LC_ALL=C && export USE_CCACHE=1
ccache -M 100G
export ARCH=arm64
export KBUILD_BUILD_HOST="$HOSST"
export KBUILD_BUILD_USER="$USEER"
git clone --depth=1 https://github.com/techyminati/android_prebuilts_clang_host_linux-x86_clang-6443078  clang
git clone --depth=1 https://github.com/LineageOS/android_prebuilts_gcc_linux-x86_aarch64_aarch64-linux-android-4.9 los-4.9-64
git clone --depth=1 https://github.com/LineageOS/android_prebuilts_gcc_linux-x86_arm_arm-linux-androideabi-4.9 los-4.9-32
@@ -45,7 +45,7 @@ function zupload()
if  [ -d "AnyKernel" ]; then	
	rm -rf AnyKernel
fi
git clone --depth=1 https://github.com/oneplus-mt6877/AnyKernel3.git AnyKernel
cp out/arch/arm64/boot/Image.gz-dtb AnyKernel
cd AnyKernel
zip -r9 TEST-OSS-KERNEL-IVAN.zip *
