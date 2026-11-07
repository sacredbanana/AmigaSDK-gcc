PowerSDL 16.1 (SDL 1.2.15) link libraries, rebuilt for the current MorphOS SDK
==============================================================================

The base image ships the link libraries from PowerSDL-SDK 16.1 (2013). The current
MorphOS linker refuses objects without the SDK identification ("The MorphOS SDK
identification omitted from libSDL.a(sdl-startup.o)"), so -lSDL and every add-on
failed to link. These files replace them, built from the PowerSDL 16.1 source with
the image's ppc-morphos-gcc 15.2 and the SDK's cvinclude.pl:

  usr/lib/libSDL.a, libb32/libSDL.a, libb32/libSDL-nc.a   sdl-startup + stubs
  usr/lib/libSDL_{image,mixer,ttf,net,gfx,sound}.a         cvinclude glue + *shared.o
  usr/lib/libnix/libsmpeg.a, libnix/libb32/libsmpeg.a     smpeg glue

They export exactly the same symbols as the originals. Programs still need the
PowerSDL user package (powersdl*.library) installed on the Amiga.

Source:  https://aminet.net/package/util/libs/powersdl_src  (powersdl_src.lha)
         sha256 ef1959edaf4794d433b68ffb20edf81fa50435c93773d2135d8b583b38b3c8a8
SDK:     PowerSDL-SDK_16.1.lha (MorphOS-Storage, Development/SDK), headers unchanged
         sha256 70e62c89b6feb4669c72aefd5a89690099171d26cdcf8dd60b946136c2cb8c6d

One source change: sdl-startup.c declares an alias _EXIT_4_TinyGLBase for a
destructor that is never defined; GCC 4 ignored it, GCC 15 rejects it, so the line
is dropped (the original object did not export that symbol either).

To rebuild: extract powersdl_src.lha to src/ next to these scripts and run them in
the ppc-morphos image (build-addons.sh needs perl's Tie::IxHash for cvinclude.pl):
  docker run --rm -e LC_ALL=C -v $PWD:/p -v $PWD/out:/out -v <test dir>:/t \
    sacredbanana/amiga-compiler:ppc-morphos bash /p/build-sdl1.sh
