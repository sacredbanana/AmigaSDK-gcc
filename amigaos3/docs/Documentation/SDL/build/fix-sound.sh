# localize the decoder libraries embedded in SDL2_sound/SDL3_sound so they do not clash with SDL_mixer's copies
for lib in /stage/*/*/lib/libSDL2_sound.a /stage/*/*/lib/libSDL3_sound.a; do
  d=$(mktemp -d); cd $d; m68k-amigaos-ar x $lib
  for o in *.o; do m68k-amigaos-objcopy -w --localize-symbol='_stb_vorbis_*' --localize-symbol='_drflac_*' --localize-symbol='_drmp3_*' --localize-symbol='_drwav_*' --localize-symbol='_mp3dec_*' --localize-symbol='_drmp3dec_*' $o; done
  rm $lib; m68k-amigaos-ar rcs $lib $(m68k-amigaos-ar t /dev/null 2>/dev/null; ls *.o); cd /; rm -rf $d
done; echo localized
