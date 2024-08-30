
SHELL	=	/bin/sh

##############################################################################

CODETYPE	=	PPC
VERSION		=	0

OUT = skeletoncpp.library

##############################################################################

G_IPATH    = -I./os-include
G_DEFINES  = -noixemul
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

all: $(OUT) \
     libskeletoncpp_shared.a \
     test

clean:
	rm -f $(OUT).elf $(OUT).db $(OUT).dump test	*.o *.a


##############################################################################

.c.o:
	ppc-morphos-gcc $(G_CFLAGS) $(G_OPTFLAGS) $(G_DEBUG) $(G_DEFINES) $(G_IPATH) -o $*.o -c $*.c

.cpp.o:
	ppc-morphos-g++ $(G_CFLAGS) $(G_OPTFLAGS) $(G_DEBUG) $(G_DEFINES) $(G_IPATH) -o $*.o -c $*.cpp

##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
#
# c++ library skeleton
#

GLOBAL = libdata.h os-include/libraries/skeletoncpp.h

lib.o:		   $(SRC)lib.c		   $(GLOBAL) skeletoncpp.library.h
libsections.o:	   $(SRC)libsections.c
libfunctions.o:	   $(SRC)libfunctions.cpp		   $(GLOBAL)
libfunctable.o:	   $(SRC)libfunctable.c		   $(GLOBAL)

OBJS = lib.o \
	libsections.o \
	libfunctions.o \
	libfunctable.o

lib_glue.a: os-include/clib/skeletoncpp_protos.h os-include/fd/skeletoncpp_lib.fd
	cvinclude.pl --fd os-include/fd/skeletoncpp_lib.fd --clib os-include/clib/skeletoncpp_protos.h --gluelib lib_glue.a

libskeletoncpp_shared.a: lib_shared.o lib_glue.a
	@-rm -f libskeletoncpp_shared.a
	cp lib_glue.a libskeletoncpp_shared.a
	$(AR) cru libskeletoncpp_shared.a lib_shared.o
	ppc-morphos-ranlib libskeletoncpp_shared.a

test.o: test.cpp

#####################################################################
#
# Link Project
#

#####################################################################
#
# Project skeletoncpp.library
#

$(OUT): $(OBJS)
	ppc-morphos-g++ -noixemul -nostartfiles $^ -o $@.db -lc -lm -lmath -ldebug
	ppc-morphos-strip -o $@.elf --remove-section=.comment $@.db


bump:
	bumprev2 VERSION $(VERSION) FILE $(OUT) TAG $(OUT) ADD "© 2005 by Sigbjørn Skjæret, written by Ralph Schmidt and Sigbjørn Skjæret"


dump:
	ppc-morphos-objdump --section-headers --all-headers --syms --reloc --disassemble-all --demangle $(OUT).db >$(OUT).dump


install: all
	@mkdir -p /sys/libs/
	cp $(OUT).elf /sys/libs/$(OUT)
	cp libskeletoncpp_shared.a /gg/ppc-morphos/lib/libskeletoncpp.a
	@-flushlib $(OUT)

#####################################################################
#
# Project test
#

test: test.o libskeletoncpp_shared.a
	ppc-morphos-g++ -noixemul $< -o test -L. -lskeletoncpp_shared -lc -lm

