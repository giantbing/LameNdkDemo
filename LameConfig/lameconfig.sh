#!/bin/bash
NDK=/home/giantbing/android-ndk-r15c
PREBUILT=$NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64
PLATFORM=$NDK/platforms/android-14/arch-arm
export PATH=$PATH:$PREBUILT/bin:$PLATFORM/usr/include:

#export LDFLAGS="-nostdlib -Bdynamic -Wl,--whole-archive -Wl,--no-undefined -Wl,-z,noexecstack  -Wl,-z,nocopyreloc -Wl,-soname,/system/lib/libz.so -Wl,-rpath-link=$ARM_LIB,-dynamic-linker=/system/bin/linker -L$PLATFORM/usr/lib -L$PREBUILT/arm-linux-androideabi/lib -L$NDK/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi -lgnustl_static -L$NDK/sources/cxx-stl/stlport/libs/armeabi -lstlport_static -lc -lgcc -lm -ldl "
#export CFLAGS="-I$NDK/sources/cxx-stl/gnu-libstdc++/4.6/include -I$NDK/sources/cxx-stl/stlport/stlport -I$PLATFORM/usr/include -fpic -DANDROID -fpic -mthumb-interwork -ffunction-sections -funwind-tables -fstack-protector -fno-short-enums -D__ARM_ARCH_5__ -D__ARM_ARCH_5T__ -D__ARM_ARCH_5E__ -D__ARM_ARCH_5TE__  -Wno-psabi -march=armv5te -mtune=xscale -msoft-float -mthumb -Os -fomit-frame-pointer -fno-strict-aliasing -finline-limit=64 -DANDROID  -Wa,--noexecstack -MMD -MP"
export LDFLAGS="-L$PLATFORM/usr/lib -L$PREBUILT/arm-linux-androideabi/lib -march=armv7-a -O3"
export CFLAGS="-I$PLATFORM/usr/include -march=armv7-a -O3"

export CPPFLAGS="$CFLAGS"
export CFLAGS="$CFLAGS"
export CXXFLAGS="$CFLAGS"
export LDFLAGS="$LDFLAGS"

export AS=$PREBUILT/bin/arm-linux-androideabi-as
export LD=$PREBUILT/bin/arm-linux-androideabi-ld
export CXX="$PREBUILT/bin/arm-linux-androideabi-g++ --sysroot=${PLATFORM}"
export CC="$PREBUILT/bin/arm-linux-androideabi-gcc --sysroot=${PLATFORM} -march=armv7-a "
export NM=$PREBUILT/bin/arm-linux-androideabi-nm
export STRIP=$PREBUILT/bin/arm-linux-androideabi-strip
export RANLIB=$PREBUILT/bin/arm-linux-androideabi-ranlib
export AR=$PREBUILT/bin/arm-linux-androideabi-ar

./configure --host=arm-linux \
--disable-shared \
--disable-frontend \
--enable-static \
--prefix=/home/giantbing/lame-android/armv7a

make clean
make -j8
make install 

