# AmigaSDK-gcc
Contains the AmigaOS 3.2 NDK, AmigaOS 4.1 SDK 54.16, MorphOS 3.18 SDK, plus extra SDKs fixed to work with the GCC compiler.

Please note these are meant to be installed on top of Bebbo's Amiga GCC devkit https://github.com/bebbo/amiga-gcc so install that first if not done already.

The other included SDKs not counting the ones already included which are from Bebbo's SDK pack:
**AmigaOS 3**
- Roadshow 1.5 TCP/IP stack http://roadshow.apc-tcp.de/download-en.php
- AmiSSL 5.18 https://aminet.net/package/util/libs/AmiSSL-v5-SDK
- Translator.library v42.4 http://aminet.net/package/util/libs/translator42
- Textfield.gadget v3.1 http://aminet.net/package/dev/gui/textfield
- json-c 0.17 https://github.com/json-c/json-c
  
**AmigaOS 4**
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
  
**MorphOS**
- json-c 0.17 https://github.com/json-c/json-c

3 Dockerfiles are also included for building the AmigaOS 3/4 and MorphOS compiler dev environments with everything included.
The latest images can also be obtained by running `docker pull sacredbanana/amiga-compiler:m68k-amigaos`, `docker pull sacredbanana/amiga-compiler:ppc-amigaos` and `docker pull sacredbanana/amiga-compiler:ppc-morphos`.
