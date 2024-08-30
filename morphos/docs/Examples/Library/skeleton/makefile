
SHELL = /bin/sh

##############################################################################

VERSION = 0

OUT = skeleton.library

##############################################################################

G_IPATH	    = -I./os-include
G_DEFINES   = -noixemul
G_OPTFLAGS	= \
	-O2 \
	-Wall \
	-fomit-frame-pointer \
	-fverbose-asm \
	-mno-prototype \
	-mcpu=604e \
	-mregnames \
	-Wformat \
	-Wunused \
	-Wuninitialized \
	-Wconversion \
	-Wstrict-prototypes	\
	-Werror-implicit-function-declaration \
#	 -mstrict-align		 \

##############################################################################

all: os-include/ppcinline/skeleton.h \
     os-include/proto/skeleton.h \
     $(OUT).elf \
	 libskeleton_shared.a \
	 test

clean:
	rm -f $(OUT).elf $(OUT).db $(OUT).dump test	*.o *.a os-include/ppcinline/skeleton.h os-include/proto/skeleton.h

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

GLOBAL =   libdata.h os-include/libraries/skeleton.h

lib.o:          $(SRC)lib.c          $(GLOBAL)
libfunctions.o:	$(SRC)libfunctions.c $(GLOBAL)
libfunctable.o:	$(SRC)libfunctable.c $(GLOBAL)

OBJS = \
	lib.o \
	libfunctions.o \
	libfunctable.o \

os-include/ppcinline/skeleton.h: os-include/fd/skeleton_lib.fd os-include/clib/skeleton_protos.h
	@mkdir -p os-include/ppcinline
	cvinclude.pl --fd os-include/fd/skeleton_lib.fd --clib os-include/clib/skeleton_protos.h --inline $@

os-include/proto/skeleton.h: os-include/fd/skeleton_lib.fd
	@mkdir -p os-include/proto
	cvinclude.pl --fd os-include/fd/skeleton_lib.fd --clib os-include/clib/skeleton_protos.h --proto $@

lib_glue.a: os-include/clib/skeleton_protos.h os-include/fd/skeleton_lib.fd os-include/ppcinline/skeleton.h os-include/proto/skeleton.h
	cvinclude.pl --fd os-include/fd/skeleton_lib.fd --clib os-include/clib/skeleton_protos.h --gluelib lib_glue.a

libskeleton_shared.a: lib_shared.o lib_glue.a
	@-rm -f libskeleton_shared.a
	cp lib_glue.a libskeleton_shared.a
	$(AR) cru libskeleton_shared.a lib_shared.o
	ppc-morphos-ranlib libskeleton_shared.a

test.o: test.c os-include/ppcinline/skeleton.h os-include/proto/skeleton.h

#####################################################################
#
# Link Project
#

#####################################################################
#
# Project skeleton.library
#

$(OUT).elf: $(OBJS)
	ppc-morphos-ld -fl libnix $(OBJS) -o $(OUT).db -lm -lmath -ldebug
	ppc-morphos-strip -o $(OUT).elf --remove-section=.comment $(OUT).db


bump:
	bumprev2 VERSION $(VERSION) FILE $(OUT) TAG $(OUT) ADD "© 2000 by Ralph Schmidt, written by Ralph Schmidt"


dump:
	ppc-morphos-objdump --section-headers --all-headers --reloc --disassemble-all $(OUT).db >$(OUT).dump

install: all
	@mkdir -p /sys/libs/
	cp $(OUT).elf /sys/libs/$(OUT)
	cp libskeleton_shared.a /gg/ppc-morphos/lib/libskeleton.a
	@-flushlib $(OUT)

#####################################################################
#
# Project test
#

test: test.o
	ppc-morphos-gcc test.o -o test -lc -noixemul

