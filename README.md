# AmigaSDK-gcc
This pack contains the AmigaOS 3.2 NDK, AmigaOS 4.1 SDK 54.16, MorphOS 3.18 SDK, plus extra SDKs fixed to work with the GCC compiler.

Here are the extra included SDKs:

### AmigaOS 3
- Roadshow 1.5 TCP/IP stack http://roadshow.apc-tcp.de/download-en.php
- AmiSSL 5.18 https://aminet.net/package/util/libs/AmiSSL-v5-SDK
- Translator.library v42.4 http://aminet.net/package/util/libs/translator42
- Textfield.gadget v3.1 http://aminet.net/package/dev/gui/textfield
- json-c 0.17 https://github.com/json-c/json-c
- Codesets 6.22 https://aminet.net/package/util/libs/codesets-6.22
- guigfx.library 20.1 https://aminet.net/package/dev/misc/guigfxlib
- Source Descriptions for FlexCat https://github.com/adtools/flexcat
  
### AmigaOS 4
- AmiSSL 5.18 https://aminet.net/package/util/libs/AmiSSL-v5-SDK
- Cairo 53.3
- Flex 2.5.27
- Expat 53.6
- Execsg 54.3
- Minigl 2.24
- Pthreads 53.12
- Python 53.35
- SDI 1.7
- Flite Device 53.1 http://aminet.net/package/mus/misc/flite_device
- json-c 0.17 https://github.com/json-c/json-c
- Codesets 6.22 https://aminet.net/package/util/libs/codesets-6.22
- guigfx.library 20.1 https://aminet.net/package/dev/misc/guigfxlib
- Source Descriptions for FlexCat https://github.com/adtools/flexcat
  
### MorphOS
- json-c 0.17 https://github.com/json-c/json-c
- Codesets 6.22 https://aminet.net/package/util/libs/codesets-6.22
- guigfx.library 20.1 https://aminet.net/package/dev/misc/guigfxlib
- Source Descriptions for FlexCat https://github.com/adtools/flexcat

## Installation

To use, you have 2 options: either a native install or use one of the Docker images.

### Native

1. Install Bebbo's Amiga GCC devkit https://github.com/bebbo/amiga-gcc
2. Add the files in the `sdk` directory to your Bebbo toolkit installation. If any files exist already, replace them with new ones

### Docker

3 Dockerfiles are also included for building the AmigaOS 3/4 and MorphOS compiler dev environments with everything included.

To build them you can simply run `build.sh`.

Alternatively you can just download them. The latest images can be obtained by running `docker pull sacredbanana/amiga-compiler:m68k-amigaos`, `docker pull sacredbanana/amiga-compiler:ppc-amigaos` and `docker pull sacredbanana/amiga-compiler:ppc-morphos`.
