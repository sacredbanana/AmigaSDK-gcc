
SHELL = /bin/sh

##############################################################################

CODETYPE = PPC
VERSION  = 0

OUT = skeletonrel.library

##############################################################################

G_IPATH	   = -I./os-include
G_DEFINES  = -noixemul -DUSE_INLINE_STDARG
G_OPTFLAGS = -O2 \
	-Wall \
	-mresident32 \
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

#	 -mstrict-align \

##############################################################################

all: os-include/ppcinline/skeletonrel.h \
     os-include/proto/skeletonrel.h \
     $(OUT).elf \
     libskeletonrel_shared.a \
     test

clean:
	rm -f $(OUT).elf $(OUT).db $(OUT).dump test	*.o *.a os-include/ppcinline/skeletonrel.h os-include/proto/skeletonrel.h

##############################################################################

.c.o:
	ppc-morphos-gcc $(G_CFLAGS) $(G_OPTFLAGS) $(G_DEBUG) $(G_DEFINES) $(G_IPATH) -o $*.o -c $*.c

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


GLOBAL = libdata.h os-include/libraries/skeletonrel.h

lib.o:          lib.c          $(GLOBAL) skeletonrel.library.h
libdata.o:      libdata.c      $(GLOBAL)
libfunctions.o: libfunctions.c $(GLOBAL)
libfunctable.o: libfunctable.c $(GLOBAL)

OBJS = lib.o \
	libdata.o \
	libfunctions.o \
	libfunctable.o

os-include/ppcinline/skeletonrel.h: os-include/fd/skeletonrel_lib.fd os-include/clib/skeletonrel_protos.h
	@mkdir -p os-include/ppcinline
	cvinclude.pl --fd os-include/fd/skeletonrel_lib.fd --clib os-include/clib/skeletonrel_protos.h --inline $@

os-include/proto/skeletonrel.h: os-include/fd/skeletonrel_lib.fd
	@mkdir -p os-include/proto
	cvinclude.pl --fd os-include/fd/skeletonrel_lib.fd --proto $@

lib_glue.a: os-include/clib/skeletonrel_protos.h os-include/fd/skeletonrel_lib.fd os-include/ppcinline/skeletonrel.h os-include/proto/skeletonrel.h
	cvinclude.pl --fd os-include/fd/skeletonrel_lib.fd --clib os-include/clib/skeletonrel_protos.h --gluelib lib_glue.a

libskeletonrel_shared.a: lib_shared.o lib_glue.a
	@-rm -f libskeletonrel_shared.a
	cp lib_glue.a libskeletonrel_shared.a
	$(AR) cru libskeletonrel_shared.a lib_shared.o
	ppc-morphos-ranlib libskeletonrel_shared.a

test.o: test.c os-include/ppcinline/skeletonrel.h os-include/proto/skeletonrel.h

#####################################################################
#
# Link Project
#

#####################################################################
#
# Project skeletonrel.library
#

$(OUT).elf: $(OBJS)
	ppc-morphos-gcc -noixemul -nostdlib -mresident32 $(OBJS) -o $(OUT).db -lmath -ldebug
	ppc-morphos-strip -o $(OUT).elf --remove-section=.comment $(OUT).db


bump:
	bumprev2 VERSION $(VERSION) FILE $(OUT) TAG skeletonrel.library ADD "© 2002-2006 by Sigbjørn Skjæret, written by Ralph Schmidt, Emmanuel Lesueur and Sigbjørn Skjæret"


dump:
	ppc-morphos-objdump --section-headers --all-headers --reloc --disassemble-all $(OUT).db >$(OUT).dump


install: all
	@mkdir -p /sys/libs/
	cp $(OUT).elf /sys/libs/$(OUT)
	cp libskeletonrel_shared.a /gg/ppc-morphos/lib/libskeletonrel.a
	@-flushlib $(OUT)


#####################################################################
#
# Project test
#

test:
	ppc-morphos-gcc test.c -o test $(G_IPATH) -O2 -noixemul -lc

