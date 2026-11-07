# AmigaSDK-gcc
This pack contains the AmigaOS 4.1 SDK 54.25, MorphOS 3.20 SDK, plus extra SDKs fixed to work with the GCC compiler.

For AmigaOS 3, the 3.2 NDK and the C runtimes (newlib, clib2, ixemul) come from Bebbo's toolchain itself, so this pack does not duplicate them. It adds the extra SDKs below, a current libnix (`update-libnix.sh`), and json-c/magic built for every runtime and multilib.

Here are the extra included SDKs:

### AmigaOS 3
- Roadshow 1.5 TCP/IP stack http://roadshow.apc-tcp.de/download-en.php
- AmiSSL 5.27 http://aminet.net/package/util/libs/AmiSSL-v5-SDK
- Translator.library v42.4 http://aminet.net/package/util/libs/translator42
- Textfield.gadget v3.1 http://aminet.net/package/dev/gui/textfield
- json-c 0.19 https://github.com/sacredbanana/json-c
- Codesets 6.22 http://aminet.net/package/util/libs/codesets-6.22
- guigfx.library 20.1 http://aminet.net/package/dev/misc/guigfxlib
- Source Descriptions for FlexCat https://github.com/adtools/flexcat
- RxMUI 42.7 http://aminet.net/package/util/rexx/rxmui
- magic 5.48 https://github.com/sacredbanana/file
- MCC_ActionTextEditor 1.0 https://github.com/sacredbanana/MCC_ActionTextEditor
- MCC_AudioPlayer 1.0 https://github.com/sacredbanana/MCC_AudioPlayer
- Amiberry GL SDK (MiniGL V30, OpenGL ES 2.0/3.x) https://github.com/BlitterStudio/amiberry-gl-sdk
  - `ogles2.library` / `ogles3.library`: binary compatible with the PiStorm [ogles2](https://github.com/ladislawv/ogles2) / [ogles3](https://github.com/ladislawv/ogles3) libraries, so programs run on both Amiberry and PiStorm. Use `#include <proto/ogles3.h>` and link with `-logles3`, or `<proto/ogles2.h>` and `-logles2`.
  - `minigl.library`: `#include <proto/minigl.h>` and compile with `-DMINIGL_DISPATCH_ABI_TYPES`. Amiberry and PiStorm3D share the same MiniGL 29 ABI, but Amiberry's table has 9 extra buffer-object slots, so choose the import library by target:
    - `-lminigl` (from PiStorm3D 29.1): runs on PiStorm3D and Amiberry. Do not call the buffer-object functions (`glGenBuffers` … `glUnmapBuffer`), which PiStorm3D 29.1 lacks.
    - `-lminigl_dispatch` (from Amiberry): adds buffer objects, but `MiniGLOpen` refuses any library without them, including PiStorm3D 29.1.
  - Autodocs: `docs/Autodocs/ogles2.doc`, `ogles3.doc`. Licences and getting-started notes: `docs/Documentation/AmiberryGL`
- SDL2 (68k port 0.7.0) and SDL3 3.4.14, built from source https://github.com/SteffenHaeuser/SDL2_68k https://github.com/SteffenHaeuser/SDL3_68k
  - With SDL2_image, SDL2_mixer, SDL2_gfx, SDL2_sound, SDL2_net and SDL3_image, SDL3_mixer, SDL3_gfx, SDL3_sound, SDL3_net, using their built-in decoders (PNG/JPEG via stb_image, Ogg Vorbis, FLAC, MP3, MIDI, MOD in SDL2_sound)
  - libnix and clib2 only (use `-noixemul` or `-mcrt=clib2`). 68020+FPU builds by default (030 to 060), and a soft-float build picked by `-m68020` for machines without an FPU.
  - OpenGL through `minigl.library`. Link with e.g. `-lSDL3_image -lSDL3 -lminigl -latomic -lamiga -lm`; programs that never open a GL window run without minigl.library.
  - Build details, scripts and licences: `docs/Documentation/SDL`
- PiStorm3D 29.1 MiniGL import library (`libminigl.a`, see above) https://aminet.net/package/util/libs/PiStorm3D
  - Licences, SDK notes and FAQ: `docs/Documentation/PiStorm3D`. Not built with `-fbaserel`.
  
### AmigaOS 4
- AmiSSL 5.27 https://aminet.net/package/util/libs/AmiSSL-v5-SDK
- Cairo 53.3
- Flex 2.5.27
- Expat 53.6
- Execsg 54.32
- Minigl 2.24
- Pthreads 53.12
- Python 53.35
- SDI 1.7
- Flite Device 53.1 http://aminet.net/package/mus/misc/flite_device
- json-c 0.19 https://github.com/sacredbanana/json-c
- Codesets 6.22 https://aminet.net/package/util/libs/codesets-6.22
- guigfx.library 20.1 https://aminet.net/package/dev/misc/guigfxlib
- Source Descriptions for FlexCat https://github.com/adtools/flexcat
- magic 5.48 https://github.com/sacredbanana/file
- MCC_ActionTextEditor 1.0 https://github.com/sacredbanana/MCC_ActionTextEditor
- MCC_AudioPlayer 1.0 https://github.com/sacredbanana/MCC_AudioPlayer
- SDL2 2.32.10 and SDL3 3.4.18 (newlib, static and shared) https://github.com/AmigaPorts/SDL
  - Add-ons from [os4depot](https://www.os4depot.net): SDL2_image 2.9.0, SDL2_mixer 2.8.1, SDL2_ttf 2.24.0, SDL2_net 2.2.0, SDL2_gfx 1.0.4, SDL2_sound 1.0.3, SDL3_image 3.4.4, SDL3_mixer 3.2.4, SDL3_ttf 3.2.2, SDL3_gfx 1.0.1, plus the libraries they need: libpng, libjpeg, libtiff, libwebp, zlib, bzip2, FreeType, HarfBuzz, libogg, libvorbis, Opus/opusfile, FLAC, mpg123, libxmp, libmodplug
  - Installed in `SDK/local/newlib` and `SDK/local/common`, so no `-I`/`-L` flags are needed. SDL2 add-on headers include `"SDL.h"`, so add `-I/opt/amiga/ppc-amigaos/SDK/local/newlib/include/SDL2` (as `sdl2-config --cflags` would).
  - Static: `-lSDL3`. Shared: `-use-dynld -lSDL3 -athread=native` (ship `libSDL3-3.4.so`). Add `-athread=native` too when linking the mixer or sound add-ons.
  - Add-on link lines: image `-ltiff -lwebpdemux -lwebpmux -lwebp -lsharpyuv -ljpeg -lpng16 -lz -lpthread`, ttf `-lharfbuzz -lfreetype -lpng16 -lbz2 -lz -lpthread`, mixer `-lxmp -lmodplug -lopusfile -lopus -lvorbisfile -lvorbis -logg -lFLAC -lmpg123 -lstdc++ -lpthread`, each followed by `-lm`.
  - Versions, checksums and licences: `docs/Documentation/SDL`. The older SDL2 2.30.5 from the base image is still in `/opt/amiga/usr`.
  
### MorphOS
- json-c 0.19 https://github.com/sacredbanana/json-c
- Codesets 6.22 https://aminet.net/package/util/libs/codesets-6.22
- guigfx.library 20.1 https://aminet.net/package/dev/misc/guigfxlib
- Source Descriptions for FlexCat https://github.com/adtools/flexcat
- magic 5.48 https://github.com/sacredbanana/file
- MCC_ActionTextEditor 1.0 https://github.com/sacredbanana/MCC_ActionTextEditor
- MCC_AudioPlayer 1.0 https://github.com/sacredbanana/MCC_AudioPlayer
- SDL2 2.32.11 and SDL3 3.4.18 by BeWorld https://github.com/BeWorld2018/SDL
  - SDL2_image, SDL2_mixer, SDL2_ttf, SDL2_net, SDL2_gfx and SDL3_image 3.4.9, SDL3_mixer 3.3.0, SDL3_ttf 3.3.0 (no SDL3_net yet)
  - Link glue for the shared `sdl2*.library` / `sdl3*.library` from the [MorphOS-Storage](https://www.morphos-storage.net) packages, which users install. Build with `-noixemul`, e.g. `-lSDL3_image -lSDL3 -lGL`. SDL3 needs MorphOS 3.20.
  - Versions, checksums and licences: `docs/SDL`
- PowerSDL 16.1 (SDL 1.2.15) link libraries rebuilt for the current SDK, so `-lSDL` and its add-ons (`-lSDL_image`, `_mixer`, `_ttf`, `_net`, `_gfx`, `_sound`, smpeg) link again. Details: `docs/SDL/PowerSDL`

## Installation

To use, you have 2 options: either a native install or use one of the Docker images.

### Native

1. Install Bebbo's Amiga GCC devkit https://github.com/bebbo/amiga-gcc
2. Add the files in the `sdk` directory to your Bebbo toolkit installation. If any files exist already, replace them with new ones

### Docker

3 Dockerfiles are also included for building the AmigaOS 3/4 and MorphOS compiler dev environments with everything included.

To build them you can simply run `build.sh`.

Alternatively you can just download them. The latest images can be obtained by running `docker pull sacredbanana/amiga-compiler:m68k-amigaos`, `docker pull sacredbanana/amiga-compiler:ppc-amigaos` and `docker pull sacredbanana/amiga-compiler:ppc-morphos`.
