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
  - `minigl.library`: Amiberry only (it uses Amiberry's dispatch table). Compile with `-DMINIGL_DISPATCH_ABI_TYPES` and link with `-lminigl_dispatch`.
  - Autodocs: `docs/Autodocs/ogles2.doc`, `ogles3.doc`. Licences and getting-started notes: `docs/Documentation/AmiberryGL`
  
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
  
### MorphOS
- json-c 0.19 https://github.com/sacredbanana/json-c
- Codesets 6.22 https://aminet.net/package/util/libs/codesets-6.22
- guigfx.library 20.1 https://aminet.net/package/dev/misc/guigfxlib
- Source Descriptions for FlexCat https://github.com/adtools/flexcat
- magic 5.48 https://github.com/sacredbanana/file
- MCC_ActionTextEditor 1.0 https://github.com/sacredbanana/MCC_ActionTextEditor
- MCC_AudioPlayer 1.0 https://github.com/sacredbanana/MCC_AudioPlayer

## Installation

To use, you have 2 options: either a native install or use one of the Docker images.

### Native

1. Install Bebbo's Amiga GCC devkit https://github.com/bebbo/amiga-gcc
2. Add the files in the `sdk` directory to your Bebbo toolkit installation. If any files exist already, replace them with new ones

### Docker

3 Dockerfiles are also included for building the AmigaOS 3/4 and MorphOS compiler dev environments with everything included.

To build them you can simply run `build.sh`.

Alternatively you can just download them. The latest images can be obtained by running `docker pull sacredbanana/amiga-compiler:m68k-amigaos`, `docker pull sacredbanana/amiga-compiler:ppc-amigaos` and `docker pull sacredbanana/amiga-compiler:ppc-morphos`.
