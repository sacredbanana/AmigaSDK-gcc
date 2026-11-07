# usage: build-sdl2core.sh <rt: libnix|clib2> <cpu: 040|020fpu|020soft>
set -e
rt=$1; cpu=$2
case $cpu in 040) CPU="-m68040 -mhard-float";; 020fpu) CPU="-m68020 -m68881";; 020soft) CPU="-m68020 -msoft-float";; esac
case $rt in libnix) CRT="-noixemul"; MK=Makefile.libnix;; clib2) CRT="-mcrt=clib2"; MK=Makefile;; esac
W=/tmp/sdl2-$rt-$cpu; rm -rf $W; cp -r /s/SDL2_68k/libSDL2-amigaos3-main $W; cd $W; rm -rf build
CF="-std=gnu99 -O2 $CPU $CRT -Wall -Wno-unused-parameter -Wno-sign-compare -w -I./include -I./src -D__AMIGAOS3__ -DMINIGL_DISPATCH_ABI_TYPES"
make -s -j8 -f $MK CFLAGS="$CF" > /tmp/log-$rt-$cpu 2>&1 || { echo "FAIL sdl2 $rt $cpu"; grep -m5 -E "error|Error" /tmp/log-$rt-$cpu; exit 1; }
O=/stage/$rt/$cpu; mkdir -p $O/lib; cp build/$rt/libSDL2.a build/$rt/libSDL2_test.a $O/lib/
echo "OK sdl2 $rt $cpu $(du -k build/$rt/libSDL2.a | cut -f1)K FPU-insns:$(m68k-amigaos-objdump -d build/$rt/libSDL2.a | grep -cE '\sf(move|add|mul|div|sub)')"
