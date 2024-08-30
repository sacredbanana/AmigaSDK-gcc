
SHELL = /bin/sh

##############################################################################

CODETYPE = PPC
VERSION  = 0

OUT = skeletonnix.library

##############################################################################

G_IPATH	   = -I./os-include
G_DEFINES  = -noixemul -DUSE_INLINE_STDARG
G_OPTFLAGS = -O2 \
	-Wall \
	-fomit-frame-pointer \
	-fverbose-asm \
	-mno-prototype \
	-mcpu=604e \
	-mregnames \
	-Wformat \
	-Wunused \
	-Wuninitialized	\
	-Wconversion \
	-Wstrict-prototypes	\
	-Werror-implicit-function-declaration
GPP_OPTFLAGS = -O2 \
	-Wall \
	-fomit-frame-pointer \
	-fverbose-asm \
	-mno-prototype \
	-mcpu=604e \
	-mregnames \
	-Wformat \
	-Wunused \
	-Wuninitialized	\
	-Wconversion \

#	 -mstrict-align \

##############################################################################

all: os-include/ppcinline/skeletonnix.h \
     os-include/proto/skeletonnix.h \
     $(OUT).elf \
     libskeletonnix_shared.a \
     test

clean:
	rm -f $(OUT).elf $(OUT).db $(OUT).dump test	*.o *.a os-include/ppcinline/skeletonnix.h os-include/proto/skeletonnix.h static staticbrel

##############################################################################

.c.o:
	ppc-morphos-gcc-9 -mresident32 $(G_CFLAGS) $(G_OPTFLAGS) $(G_DEBUG) $(G_DEFINES) $(G_IPATH) -o $*.o -c $*.c

.cpp.o:
	ppc-morphos-g++-9 -mresident32 $(G_CFLAGS) $(GPP_OPTFLAGS) $(G_DEBUG) $(G_DEFINES) $(G_IPATH) -o $*.o -c $*.cpp

lib.o: lib.c
	ppc-morphos-gcc-9 $(G_CFLAGS) $(G_OPTFLAGS) $(G_DEBUG) $(G_DEFINES) $(G_IPATH) -o $*.o -c $*.c

##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
#
# ABox Emulation
#


GLOBAL = libdata.h os-include/libraries/skeletonnix.h

lib.o:          lib.c          $(GLOBAL) skeletonnix.library.h
libdata.o:      libdata.c      $(GLOBAL)
libsections.o:  libsections.c
libfunctions.o: libfunctions.c $(GLOBAL)
libfunctable.o: libfunctable.c $(GLOBAL)

OBJS = lib.o \
	libdata.o \
	libsections.o \
	libfunctions.o \
	libfunctable.o \
	class.o

os-include/ppcinline/skeletonnix.h: os-include/fd/skeletonnix_lib.fd os-include/clib/skeletonnix_protos.h
	@mkdir -p os-include/ppcinline
	cvinclude.pl --fd os-include/fd/skeletonnix_lib.fd --clib os-include/clib/skeletonnix_protos.h --inline $@

os-include/proto/skeletonnix.h: os-include/fd/skeletonnix_lib.fd
	@mkdir -p os-include/proto
	cvinclude.pl --fd os-include/fd/skeletonnix_lib.fd --proto $@

lib_glue.a: os-include/clib/skeletonnix_protos.h os-include/fd/skeletonnix_lib.fd os-include/ppcinline/skeletonnix.h os-include/proto/skeletonnix.h
	cvinclude.pl --fd os-include/fd/skeletonnix_lib.fd --clib os-include/clib/skeletonnix_protos.h --brelgluelib lib_glue.a

libskeletonnix_shared.a: lib_shared.o lib_glue.a
	@-rm -f libskeletonnix_shared.a
	cp lib_glue.a libskeletonnix_shared.a
	ppc-morphos-ar cru libskeletonnix_shared.a lib_shared.o
	ppc-morphos-ranlib libskeletonnix_shared.a

test.o: test.c os-include/ppcinline/skeletonnix.h os-include/proto/skeletonnix.h

#####################################################################
#
# Link Project
#

#####################################################################
#
# Project skeletonnix.library
#

$(OUT).elf: $(OBJS)
	ppc-morphos-g++-9 -noixemul -nostartfiles -mresident32 $(OBJS) -o $(OUT).db -lmath -ldebug -Xlinker -Map=$(OUT).map
	ppc-morphos-strip -o $(OUT).elf --remove-section=.comment $(OUT).db


bump:
	bumprev2 VERSION $(VERSION) FILE $(OUT) TAG skeletonnix.library ADD "© 2002-2006 by Sigbjørn Skjæret, written by Ralph Schmidt, Emmanuel Lesueur and Sigbjørn Skjæret"


dump:
	ppc-morphos-objdump --section-headers --all-headers --reloc --disassemble-all $(OUT).db >$(OUT).dump


install: all
	@mkdir -p /sys/libs/
	cp $(OUT).elf /sys/libs/$(OUT)
	cp libskeletonnix_shared.a /gg/ppc-morphos/lib/libskeletonnix.a
	@-flushlib $(OUT)


#####################################################################
#
# Project test
#

test:
	ppc-morphos-gcc-9 test.c -o test $(G_IPATH) -O2 -noixemul -lc

static: class.cpp class.h static.cpp
	ppc-morphos-g++-9 -o static static.cpp -noixemul -std=gnu++17 -Wall

staticbrel: class.cpp class.h static.cpp
	ppc-morphos-g++-9 -o staticbrel static.cpp -noixemul -mresident32 -std=gnu++17 -Wall
