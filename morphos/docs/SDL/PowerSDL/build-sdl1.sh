set -e
SRC=/p/src/powersdl_src/source/SDL
W=/tmp/w; rm -rf $W /tmp/m; mkdir -p $W/lib/libb32
cp -r $SRC/MorphOS /tmp/m; cd /tmp/m
sed -i '/_EXIT_4_TinyGLBase/d' sdl-startup.c
cp $SRC/include/SDL_config.h.default /tmp/SDL_config.h 2>/dev/null || true
INC="-Iinclude -I$SRC/include -I/tmp -I. -I/opt/ppc-morphos/usr/include"
CC="ppc-morphos-gcc -noixemul -mcpu=750 -Wall -O3 -w"
$CC $INC -c sdl-startup.c -o $W/sdl-startup.o
$CC -mresident32 $INC -c sdl-startup.c -o $W/sdl-startup-brel.o
$CC -mresident32 $INC -D__NO_SDL_CONSTRUCTORS -c sdl-startup.c -o $W/sdl-startup-brel-nc.o
$CC $INC -c libSDLstubs.c -o $W/libSDLstubs.o
$CC -mresident32 $INC -c libSDLstubs.c -o $W/libSDLstubs-brel.o
cd $W; ppc-morphos-ar cru lib/libSDL.a sdl-startup.o libSDLstubs.o
ppc-morphos-ar cru lib/libb32/libSDL.a sdl-startup-brel.o libSDLstubs-brel.o
ppc-morphos-ar cru lib/libb32/libSDL-nc.a sdl-startup-brel-nc.o libSDLstubs-brel.o
ppc-morphos-ranlib lib/libSDL.a lib/libb32/libSDL.a lib/libb32/libSDL-nc.a
echo "symbols new/old: $(ppc-morphos-nm -g --defined-only lib/libSDL.a | grep -c ' T ') / $(ppc-morphos-nm -g --defined-only /opt/ppc-morphos/usr/lib/libSDL.a | grep -c ' T ')"
diff <(ppc-morphos-nm -g --defined-only /opt/ppc-morphos/usr/lib/libSDL.a | awk '{print $3}' | sort -u) <(ppc-morphos-nm -g --defined-only lib/libSDL.a | awk '{print $3}' | sort -u) && echo "same exported symbols"
cd /t; ppc-morphos-gcc -noixemul s1.c -L$W/lib -lSDL -o /tmp/o && echo LINK-OK
ppc-morphos-gcc -noixemul -mresident32 s1.c -L$W/lib/libb32 -lSDL -o /tmp/o && echo LINK-B32-OK
printf '#include <SDL/SDL.h>\nint main(int c,char**v){SDL_Init(0);return 0;}\n' > /tmp/a.c
for a in image mixer ttf net gfx sound; do if ppc-morphos-gcc -noixemul /tmp/a.c -lSDL_$a -L$W/lib -lSDL -o /tmp/o 2>/tmp/e; then echo "addon $a ok"; else echo "addon $a FAIL: $(grep -m1 -oE 'omitted from [^ ]+|undefined reference to .[A-Za-z_0-9]+' /tmp/e)"; fi; done
cp -r $W/lib /out/
