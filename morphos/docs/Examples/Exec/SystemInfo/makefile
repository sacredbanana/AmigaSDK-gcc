
SHELL	=	/bin/sh

##############################################################################

TARGET		=	PPC
CODETYPE	=	PPC
VERSION		=	0

##############################################################################

G_IPATH		=
G_DEFINES	=	-D$(CODETYPE)
G_OPTFLAGS	=	-noixemul -O2		  \
			-fomit-frame-pointer	\
			-fverbose-asm		\
			-mno-prototype		\
			-mcpu=604		\
			-mregnames		\
			-Wall			\
			-Wformat		\
			-Wunused		\
			-Wuninitialized		\
			-Wconversion		\
			-Wstrict-prototypes	\
			-Werror-implicit-function-declaration

APATH		=	-iinclude/
AFLAGS		=	-M4000

##############################################################################

.PHONY: all clean

all:	systeminfo

clean:
	rm -f *.s *.o$(TARGET) systeminfo

##############################################################################

.SUFFIXES: .o$(TARGET) .asm

.c.o$(TARGET):
	@echo "Making $@..."
	@ppc-morphos-gcc $(G_CFLAGS) $(G_OPTFLAGS) $(G_DEBUG) $(G_DEFINES) $(G_IPATH) -S -o $*.s $*.c
	@ppc-morphos-as -o$*.o$(TARGET) $*.s

.s.o$(TARGET):
	@echo "Making $@..."
	@ppc-morphos-as -o$*.o$(TARGET) $*.s


.asm.o$(TARGET):
	@echo "Making $@..."
	@basm $(AFLAGS) $(APATH) -o$*.o$(TARGET) $*.asm

##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################
##############################################################################

SRC		=

systeminfo.o$(TARGET):	systeminfo.c systeminfo.h

#####################################################################
#
# Link Project
#

#####################################################################
#
# Project systeminfo
#

systeminfo:	systeminfo.o$(TARGET)
	@echo "Making $@..."
	@ppc-morphos-gcc -noixemul systeminfo.o$(TARGET) -o systeminfo -laboxstubs -lmath -lm

BUMP:
	bumprev2 VERSION=$(VERSION) FILE=$(SRC)systeminfo TAG=systeminfo ADD="© 2002 by Ralph Schmidt, written by Ralph Schmidt"
