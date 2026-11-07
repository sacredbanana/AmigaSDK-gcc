set -e
S=/p/src/powersdl_src/source; O=/out/lib; mkdir -p $O/libnix/libb32
B=/tmp/b; rm -rf $B; cp -r $S $B
INC="-I$B/SDL/include -I/tmp -I/opt/ppc-morphos/usr/include -I/opt/ppc-morphos/usr/include/SDL"
cp $B/SDL/include/SDL_config.h.default /tmp/SDL_config.h 2>/dev/null || true
for a in image mixer ttf net gfx; do
  d=$B/SDL_$a; cd $d; m=morphos
  ppc-morphos-gcc $INC -I. -I$m -I$m/Developer -I$m/extras -w -noixemul -fomit-frame-pointer -mcpu=750 -DUSE_INLINE_STDARG -O2 -c $m/libSDL_${a}shared.c -o /tmp/shared.o
  rm -f /tmp/glue.a; perl /opt/ppc-morphos/bin/cvinclude.pl --fd=$m/Developer/fd/powersdl_${a}_lib.fd --clib=$m/Developer/clib/powersdl_${a}_protos.h --gluelib=/tmp/glue.a >/dev/null
  cp /tmp/glue.a $O/libSDL_$a.a; ppc-morphos-ar cru $O/libSDL_$a.a /tmp/shared.o; ppc-morphos-ranlib $O/libSDL_$a.a; echo "built SDL_$a"
done
cd $B/SDL_sound/MorphOS
ppc-morphos-gcc $INC -Iinclude -I$B/SDL/MorphOS -I$B/SDL/MorphOS/include -w -noixemul -mcpu=750 -O3 -c libSDL_sound.c -o /tmp/snd.o
rm -f /tmp/glue.a; perl /opt/ppc-morphos/bin/cvinclude.pl --fd=include/fd/powersdl_sound_lib.fd --clib=include/clib/powersdl_sound_protos.h --gluelib=/tmp/glue.a >/dev/null
cp /tmp/glue.a $O/libSDL_sound.a; ppc-morphos-ar cru $O/libSDL_sound.a /tmp/snd.o; ppc-morphos-ranlib $O/libSDL_sound.a; echo built SDL_sound
cd $B/smpeg/MorphOS
grep -nE "libsmpeg(-brel)?\.o:" -A3 Makefile | grep -E "CC|-c" | head -3
ppc-morphos-gcc $INC -Iinclude -I$B/SDL/MorphOS -I$B/SDL/MorphOS/include -w -noixemul -mcpu=750 -O3 -c libsmpeg.c -o /tmp/smpeg.o
ppc-morphos-gcc $INC -Iinclude -I$B/SDL/MorphOS -I$B/SDL/MorphOS/include -w -noixemul -mresident32 -mcpu=750 -O3 -c libsmpeg.c -o /tmp/smpeg-brel.o
rm -f /tmp/g1.a /tmp/g2.a; perl /opt/ppc-morphos/bin/cvinclude.pl --fd=include/fd/smpeg_lib.fd --clib=include/clib/smpeg_protos_real.h --gluelib=/tmp/g1.a; perl /opt/ppc-morphos/bin/cvinclude.pl --fd=include/fd/smpeg_lib.fd --clib=include/clib/smpeg_protos_real.h --brelgluelib=/tmp/g2.a >/dev/null
cp /tmp/g1.a $O/libnix/libsmpeg.a; ppc-morphos-ar cru $O/libnix/libsmpeg.a /tmp/smpeg.o; cp /tmp/g2.a $O/libnix/libb32/libsmpeg.a; ppc-morphos-ar cru $O/libnix/libb32/libsmpeg.a /tmp/smpeg-brel.o; ppc-morphos-ranlib $O/libnix/libsmpeg.a $O/libnix/libb32/libsmpeg.a; echo built smpeg
for l in SDL_image SDL_mixer SDL_ttf SDL_net SDL_gfx SDL_sound; do diff <(ppc-morphos-nm -g --defined-only /opt/ppc-morphos/usr/lib/lib$l.a | awk "{print \$3}" | sort -u) <(ppc-morphos-nm -g --defined-only $O/lib$l.a | awk "{print \$3}" | sort -u) >/dev/null && echo "$l same symbols" || echo "$l SYMBOLS DIFFER: $(diff <(ppc-morphos-nm -g --defined-only /opt/ppc-morphos/usr/lib/lib$l.a | awk "{print \$3}" | sort -u) <(ppc-morphos-nm -g --defined-only $O/lib$l.a | awk "{print \$3}" | sort -u) | head -4 | tr "\n" " ")"; done
diff <(ppc-morphos-nm -g --defined-only /opt/ppc-morphos/usr/lib/libnix/libsmpeg.a | awk "{print \$3}" | sort -u) <(ppc-morphos-nm -g --defined-only $O/libnix/libsmpeg.a | awk "{print \$3}" | sort -u) >/dev/null && echo "smpeg same symbols"
