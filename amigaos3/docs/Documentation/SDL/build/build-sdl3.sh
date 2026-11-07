# usage: build-sdl3.sh <rt> <cpu>
rt=$1; cpu=$2
case $cpu in 040) CPU="-m68040 -mhard-float";; 020fpu) CPU="-m68020 -m68881";; 020soft) CPU="-m68020 -msoft-float";; esac
case $rt in libnix) CRT="-noixemul";; clib2) CRT="-mcrt=clib2 -DNOIXEMUL";; esac
O=/stage/$rt/$cpu/lib; mkdir -p $O; T=/tmp/s3-$rt-$cpu; rm -rf $T; mkdir -p $T; export CPATH=/stage/include
run(){ name=$1; shift; if make -s -j4 "$@" > $T/$name.log 2>&1; then echo "OK $name $rt $cpu"; else echo "FAIL $name $rt $cpu: $(grep -m3 -E 'error|Error' $T/$name.log | tr '\n' ' ')"; return 1; fi; }
cp -r /s/SDL3_68k/SDL3 $T/core; cd $T/core; rm -rf build
run sdl3 -f Makefile.amigaos3 build/$rt/libSDL3.a build/$rt/libSDL3_test.a COMMON="-std=gnu99 -O2 $CPU -w -I./include -I./include/build_config -I./include/SDL3 -I./src -D__AMIGAOS3__ -DMINIGL_DISPATCH_ABI_TYPES" && cp build/$rt/libSDL3.a build/$rt/libSDL3_test.a $O/ || exit 1
cp -r /s/SDL3_68k/SDL_image-release-3.4.4 $T/img; cd $T/img; rm -rf build
if [ $rt = libnix ]; then L=build/libnix/libSDL3_image_libnix.a; else L=build/clib2/libSDL3_image.a; fi
run image3 -f Makefile.amigaos3 $L CPUFLAGS="$CPU" WARNINGS=-w SDL3_INC=-I/stage/include && cp $L $O/libSDL3_image.a
cp -r /s/SDL3_68k/SDL_mixer-release-3.2.x $T/mix; cd $T/mix; rm -rf build-amiga
run mixer3 -f Makefile.amiga build-amiga/$rt/lib/libSDL3_mixer.a CPUFLAGS="$CPU" WARNFLAGS=-w && cp build-amiga/$rt/lib/libSDL3_mixer.a $O/
cp -r /s/SDL3_68k/SDL3_gfx-master $T/gfx; cd $T/gfx
run gfx3 -f Makefile b/lib/libSDL3_gfx.a BUILD_DIR=b CPUFLAGS="$CPU" CRTFLAGS="$CRT" WARNFLAGS=-w && cp b/lib/libSDL3_gfx.a $O/
cp -r /s/SDL3_68k/SDL3_sound-main $T/snd; cd $T/snd
run sound3 -f Makefile.amiga library BUILD_DIR=b LIB_NAME=libSDL3_sound.a CPUFLAGS="$CPU" CRTFLAGS="$CRT" WARNFLAGS=-w && cp b/lib/libSDL3_sound.a $O/
cp -r /s/SDL3_68k/SDL_net-release-3.2.x $T/net; cd $T/net
ND=$( [ $rt = clib2 ] && echo -DSDLNET_CLIB2=1 || echo -DSDLNET_LIBNIX=1 )
run net3 -f Makefile.amiga b/lib/libSDL3_net.a BUILD_DIR=b LIB_NAME=libSDL3_net.a CPUFLAGS="$CPU" CRTFLAGS="$CRT" WARNFLAGS=-w COMMON_DEFS="-DBUILD_SDL -DSDL_BUILD_MAJOR_VERSION=3 -DSDL_BUILD_MINOR_VERSION=2 -DSDL_BUILD_MICRO_VERSION=1 -DSDLNET_AMIGAOS=1 $ND" && cp b/lib/libSDL3_net.a $O/
