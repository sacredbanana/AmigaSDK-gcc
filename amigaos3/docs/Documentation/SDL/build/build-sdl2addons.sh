# usage: build-sdl2addons.sh <rt> <cpu>
rt=$1; cpu=$2; fail=0
case $cpu in 040) CPU="-m68040 -mhard-float";; 020fpu) CPU="-m68020 -m68881";; 020soft) CPU="-m68020 -msoft-float";; esac
case $rt in libnix) CRT="-noixemul";; clib2) CRT="-mcrt=clib2";; esac
INC=/stage/include/SDL2; O=/stage/$rt/$cpu/lib; T=/tmp/a2-$rt-$cpu; rm -rf $T; mkdir -p $T
MATH="-fno-builtin-floor -fno-builtin-ceil -fno-builtin-sin -fno-builtin-cos -fno-builtin-log10"
run(){ name=$1; shift; if make -s -j4 "$@" > $T/$name.log 2>&1; then echo "OK $name $rt $cpu"; else echo "FAIL $name $rt $cpu: $(grep -m3 -E 'error|Error' $T/$name.log | tr '\n' ' ')"; fail=1; fi; }
cp -r /s/SDL2_68k/SDL2_Image_AmigaOS3.1_68k-main $T/img; cd $T/img
run image -f Makefile.amigaos3 build BUILD_DIR=b ENABLE_TIF=1 ENABLE_WEBP=1 ENABLE_WEBP_DEMUX=0 CRTFLAGS="$CRT" CPUFLAGS="$CPU" \
  CPPFLAGS="-I$INC -Iinclude -Isrc -I. -DUSE_STBIMAGE -DLOAD_PNG -DLOAD_JPG -DLOAD_BMP -DLOAD_GIF -DLOAD_LBM -DLOAD_PCX -DLOAD_PNM -DLOAD_QOI -DLOAD_TGA -DLOAD_XCF -DLOAD_XPM -DLOAD_XV -DLOAD_SVG" LIBNAME=libSDL2_image.a && cp b/lib/libSDL2_image.a $O/
cp -r /s/SDL2_68k/SDL2_Mixer_AmigaOS3.1_68k-main $T/mix; cd $T/mix
MSRC="src/utils.c src/effect_stereoreverse.c src/effect_position.c src/effects_internal.c src/mixer.c src/music.c src/codecs/music_wav.c src/codecs/load_voc.c src/codecs/load_aiff.c src/codecs/music_ogg_stb.c src/codecs/music_drflac.c src/codecs/music_minimp3.c src/codecs/mp3utils.c src/codecs/music_timidity.c $(ls src/codecs/timidity/*.c | tr '\n' ' ')"
run mixer -f Makefile.amigaos3 build BUILD_DIR=b SRC="$MSRC" LIBNAME=libSDL2_mixer.a \
  CFLAGS="$CPU $CRT -O2 -fno-strict-aliasing -w -D_REENTRANT -DNO_SSE -DNO_MMX $MATH -I$INC -Isrc -Isrc/codecs -I. -DMUSIC_WAV -DMUSIC_OGG -DOGG_USE_STB -DMUSIC_FLAC_DRFLAC -DMUSIC_MP3_MINIMP3 -DMUSIC_MID_TIMIDITY" && cp b/lib/libSDL2_mixer.a $O/
cp -r /s/SDL2_68k/SDL2_gfx_AmigaOS3.1_68k-main $T/gfx; cd $T/gfx
run gfx -f Makefile.amigaos3 b/lib/libSDL2_gfx.a BUILD_DIR=b LIBNAME=libSDL2_gfx.a CPUFLAGS="$CPU" CRTFLAGS="$CRT" WARNFLAGS=-w CPPFLAGS="-I$INC -I." && cp b/lib/libSDL2_gfx.a $O/
cp -r /s/SDL2_68k/SDL2_sound_AmigaOS3.1_68k-main $T/snd; cd $T/snd
SSRC="src/SDL_sound.c src/SDL_sound_aiff.c src/SDL_sound_au.c src/SDL_sound_raw.c src/SDL_sound_voc.c src/SDL_sound_wav.c src/SDL_sound_flac.c src/SDL_sound_mp3.c src/SDL_sound_vorbis.c src/SDL_sound_modplug.c $(ls src/libmodplug/*.c | tr '\n' ' ')"
run sound -f Makefile.amigaos3 build BUILD_DIR=b SRCS="$SSRC" LIBNAME=libSDL2_sound.a CPUFLAGS="$CPU" CRTFLAGS="$CRT -DSOUND_SUPPORTS_MIDI=0 -DSOUND_SUPPORTS_SHN=0 -DSOUND_USE_DR_FLAC -DSOUND_USE_DR_MP3 -DSOUND_USE_STB_VORBIS -DDISABLE_COREAUDIO -Isrc/libmodplug" WARNFLAGS=-w INCLUDES="-Isrc -I$INC -I." && cp b/lib/libSDL2_sound.a $O/
cp -r /s/SDL2_68k/SDL_net-release-2.4.x $T/net; cd $T/net
run net -f Makefile.amigaos3 b/lib/libSDL2_net.a BUILD_DIR=b LIBNAME=libSDL2_net.a CPUFLAGS="$CPU" CRTFLAGS="$CRT" WARNFLAGS=-w SDL2_INC=$INC && cp b/lib/libSDL2_net.a $O/
