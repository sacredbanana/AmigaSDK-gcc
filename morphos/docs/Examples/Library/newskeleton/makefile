
SHELL	=	/bin/sh

##############################################################################

CODETYPE	=	PPC
VERSION		=	0

OUT = skeletonnew.library

##############################################################################

G_IPATH    = -I./os-include
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

#	 -mstrict-align	\


##############################################################################

all: os-include/ppcinline/skeletonnew.h \
     os-include/proto/skeletonnew.h \
     $(OUT) \
     libskeletonnew_shared.a \
     test

clean:
	rm -f $(OUT).elf $(OUT).db $(OUT).dump test	*.o *.a os-include/ppcinline/skeletonnew.h os-include/proto/skeletonnew.h os-include/fd/skeletonnew_lib.fd


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
# new library skeleton
#

GLOBAL = libdata.h os-include/libraries/skeletonnew.h

lib.o:		   $(SRC)lib.c		   $(GLOBAL) skeletonnew.library.h
libfunctions.o:	   $(SRC)libfunctions.c		   $(GLOBAL)
libfunctable.o:	   $(SRC)libfunctable.c		   $(GLOBAL)

OBJS = lib.o \
	libfunctions.o \
	libfunctable.o

os-include/fd/skeletonnew_lib.fd: libfunctable.c os-include/clib/skeletonnew_protos.h
	@mkdir -p os-include/fd
	genfd.pl $< >$@

os-include/ppcinline/skeletonnew.h: os-include/fd/skeletonnew_lib.fd os-include/clib/skeletonnew_protos.h
	@mkdir -p os-include/ppcinline
	cvinclude.pl --fd os-include/fd/skeletonnew_lib.fd --clib os-include/clib/skeletonnew_protos.h --inline $@

os-include/proto/skeletonnew.h: os-include/fd/skeletonnew_lib.fd
	@mkdir -p os-include/proto
	cvinclude.pl --fd os-include/fd/skeletonnew_lib.fd --proto $@

lib_glue.a: os-include/clib/skeletonnew_protos.h os-include/fd/skeletonnew_lib.fd os-include/ppcinline/skeletonnew.h os-include/proto/skeletonnew.h
	cvinclude.pl --fd os-include/fd/skeletonnew_lib.fd --clib os-include/clib/skeletonnew_protos.h --gluelib lib_glue.a

libskeletonnew_shared.a: lib_shared.o lib_glue.a
	@-rm -f libskeletonnew_shared.a
	cp lib_glue.a libskeletonnew_shared.a
	$(AR) cru libskeletonnew_shared.a lib_shared.o
	ppc-morphos-ranlib libskeletonnew_shared.a

test.o: test.c os-include/ppcinline/skeletonnew.h os-include/proto/skeletonnew.h

#####################################################################
#
# Link Project
#

#####################################################################
#
# Project skeletonnew.library
#

$(OUT): $(OBJS)
	ppc-morphos-ld -fl libnix $(OBJS) -o $(OUT).db -lc -lm -lmath -ldebug
	ppc-morphos-strip -o $(OUT).elf --remove-section=.comment $(OUT).db


bump:
	bumprev2 VERSION $(VERSION) FILE $(OUT) TAG $(OUT) ADD "© 2002-2003 by Ralph Schmidt, written by Ralph Schmidt"


dump:
	ppc-morphos-objdump --section-headers --all-headers --reloc --disassemble-all $(OUT).db >$(OUT).dump


install: all
	@mkdir -p /sys/libs/
	cp $(OUT).elf /sys/libs/$(OUT)
	cp libskeletonnew_shared.a /gg/ppc-morphos/lib/libskeletonnew.a
	@-flushlib $(OUT)

#####################################################################
#
# Project test
#

test: test.o
	ppc-morphos-gcc test.o -o test -noixemul -lc -lm

