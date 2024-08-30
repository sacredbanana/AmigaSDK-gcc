
SHELL	=	/bin/sh

##############################################################################

CODETYPE	=	PPC
VERSION		=	0

##############################################################################

G_IPATH		=
G_DEFINES	=	-noixemul -D$(CODETYPE)
G_OPTFLAGS	=	-O2 -fomit-frame-pointer -fverbose-asm -mno-prototype -mcpu=604 -mregnames -Wformat -Wunused -Wuninitialized -Wconversion -Wstrict-prototypes -Werror-implicit-function-declaration


APATH		=	-iinclude/
AFLAGS		=	-M4000

##############################################################################

all: ppcstackswap.elf procmessages.elf


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

SRC		=

GLOBAL		=

##############################################################################

OBJS	=


##############################################################################
#
# ppcstackswap Elf Project
#
ppcstackswap.elf:	ppcstackswap.o $(OBJS)
	ppc-morphos-ld -L./lib -r ppcstackswap.o $(OBJS) /gg/ppc-morphos/lib/libdebug.a -o $@

procmessages.elf:	procmessages.o $(OBJS)
	ppc-morphos-ld -L./lib -r procmessages.o $(OBJS) /gg/ppc-morphos/lib/libdebug.a -o $@

bump:
	bumprev2 VERSION=$(VERSION) FILE=ppcstackswap_version TAG=ppcstackswap ADD="© 2000 by Ralph Schmidt"

dump:
	ppc-morphos-objdump --section-headers --all-headers --reloc --disassemble-all ppcstackswap.elf >ppcstackswap.elf.dump

##############################################################################
.PHONY: all

