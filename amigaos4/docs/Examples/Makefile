#/***************************************************************************
#
# Magic User Interface - MUI
# Copyright (C) 1992-2004 by Stefan Stuntz <stefan@stuntz.com>
# All Rights Reserved.
#
# This program/documents may not in whole or in part, be copied, photocopied
# reproduced, translated or reduced to any electronic medium or machine
# readable form without prior consent, in writing, from the above authors.
#
# With this document the authors makes no warrenties or representations,
# either expressed or implied, with respect to MUI. The information
# presented herein is being supplied on an "AS IS" basis and is expressly
# subject to change without notice. The entire risk as to the use of this
# information is assumed by the user.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# IN NO EVENT WILL THE AUTHORS BE LIABLE FOR DIRECT, INDIRECT, INCIDENTAL,
# OR CONSEQUENTIAL DAMAGES RESULTING FROM ANY CLAIM ARISING OUT OF THE
# INFORMATION PRESENTED HEREIN, EVEN IF IT HAS BEEN ADVISED OF THE
# POSSIBILITIES OF SUCH DAMAGES.
#
# MUI Official Support Site:  http://www.sasg.com/
#
# $Id$
#
#***************************************************************************/

###########################################################################
# This makefile is a very generic one. It tries to identify both, the host
# and the target operating system for which MUI should be compiled.
# However, this auto-detection can be easily overridden by directly
# specifying an option on the commandline while calling 'make'.
#
# Example:
#
# # to explicitly compile for AmigaOS3
# > make OS=os3
#
# # to compile for AmigaOS4 but without debugging
# > make OS=os4 DEBUG=
#

#############################################
# find out the HOST operating system
# on which this makefile is run
HOST ?= $(shell uname)
ifeq ($(HOST), AmigaOS)
  ifeq ($(shell uname -m), powerpc)
    HOST = AmigaOS4
  endif
  ifeq ($(shell uname -m), ppc)
    HOST = AmigaOS4
  endif
endif

# if no host is identifed (no uname tool)
# we assume a AmigaOS build
ifeq ($(HOST),)
  HOST = AmigaOS
endif

#############################################
# now we find out the target OS for
# which we are going to compile MUI in case
# the caller didn't yet define OS himself
ifndef (OS)
  ifeq ($(HOST), AmigaOS4)
    OS = os4
  else
  ifeq ($(HOST), AmigaOS)
    OS = os3
  else
    OS = os4
  endif
  endif
endif

#############################################
# define common commands we use in this
# makefile. Please note that each of them
# might be overridden on the commandline.

# common commands
RM      = rm -f #delete force
RMDIR   = rm -rf #delete force all
MKDIR   = mkdir -p #makedir force all
CHMOD   = chmod 755 #protect FLAGS=rwed
CAT     = cat #type
CC      = gcc
STRIP   = strip
OBJDUMP = objdump

# path definitions
CDUP   = /
CDTHIS =
NIL    = NIL:

###########################################################################
# CPU and DEBUG can be defined outside, defaults to above
# using e.g. "make DEBUG= CPU=-mcpu=603e" produces optimized non-debug
# PPC-603e version
#
# OPTFLAGS are disabled by DEBUG normally!
#
# ignored warnings are:
# none - because we want to compile with -Wall all the time

# Common compiler/linker flags
WARN       = -W -Wall -Wwrite-strings -Wpointer-arith -Wsign-compare -fno-strict-aliasing #-Wunreachable-code
OPTFLAGS   = -O3 -fomit-frame-pointer
DEBUG      = -DDEBUG -fno-omit-frame-pointer #-O0
DEBUGSYM   = -g -gstabs
CFLAGS     = -I. -I$(INCDIR)  $(CPU) $(WARN) $(OPTFLAGS) $(DEBUG) $(DEBUGSYM) -DAMIGAOS
LDFLAGS    = $(CPU) $(DEBUGSYM)
LDLIBS     = -L$(LIB) -lm
STRIPFLAGS = --preserve-dates -R.comment -R.sdata2 -S

# different options per target OS
ifeq ($(OS), os4)

  ##############################
  # AmigaOS4

  # Compiler/link/strip commands
  ifneq ($(HOST), AmigaOS4)
    CC      = ppc-amigaos-gcc
    STRIP   = ppc-amigaos-strip
    OBJDUMP = ppc-amigaos-objdump
  else
    HCFLAGS += -mcrt=newlib
  endif

  # Compiler/Linker flags
  CRT      = newlib
  CPU      = -mcpu=powerpc #-mstrict-align
  WARN     += -Wdeclaration-after-statement -Wdisabled-optimization
  REDEFINE = -DCoerceMethod=ICoerceMethod -DDoMethod=IDoMethod \
             -DDoSuperMethod=IDoSuperMethod -DDoSuperMethodA=IDoSuperMethodA
  CFLAGS   += -mcrt=$(CRT) -D__USE_INLINE__ -D__NEW_TIMEVAL_DEFINITION_USED__ -D__USE_CLASSIC_MINTERM__ \
              $(REDEFINE) -Wa,-mregnames
  LDFLAGS  += -mcrt=$(CRT)
  DEMOLIBS = -lauto
  CFGFLAGS = -DOS4

else
ifeq ($(OS), os3)

  ##############################
  # AmigaOS3

  # Compiler/link/strip commands
  ifneq ($(HOST), AmigaOS)
    CC      = m68k-amigaos-gcc
    STRIP   = m68k-amigaos-strip
    OBJDUMP = m68k-amigaos-objdump
  endif

  # Compiler/Linker flags
  CPU	    = -m68020-60 -msoft-float
  CFLAGS  += -I./include/netinclude -DNO_INLINE_STDARG -D__CLIB2__ -D__amigaos3__
  LDFLAGS += -noixemul
  LDLIBS  += -ldebug -lmui -lm


endif
endif

# override some variables for non-native builds (cross-compiler)
ifneq ($(HOST), AmigaOS)
ifneq ($(HOST), AmigaOS4)
    # when we end up here this is either a unix or Aros host
    # so lets use unix kind of commands
    RM      = rm -f
    RMDIR   = rm -rf
    MKDIR   = mkdir -p
    CHMOD   = chmod 755
    CAT     = cat

    CDUP   = ../
    CDTHIS = ./
    NIL    = /dev/null
endif
endif

# Directories
PREFIX    = $(CDTHIS)
INCDIR    = $(PREFIX)include

# CPU and DEBUG can be defined outside, defaults to above
# using e.g. "make DEBUG= CPU=-m68060" produces optimized non-debug 68060 version
#
# OPTFLAGS are disabled by DEBUG normally!
#
# ignored warnings are:
# none - because we want to compile with -Wall all the time
#

DEMOS = Animals      \
        AppWindow    \
        Balancing    \
        BoopsiDoor   \
        Class1       \
        Class2       \
        Class3       \
        Class4       \
        DragnDrop    \
        EnvBrowser   \
        InputHandler \
        Layout       \
        Menus        \
        MUI-Demo     \
        MultiSel     \
        NewStuff     \
        Pages        \
        Popup        \
        ShowHide     \
        Slidorama    \
        Subtask      \
        Virtual

ifeq ($(OS), os3)
DEMOS += WbMan
endif

#

.PHONY: all
all: $(DEMOS)

#

#

.PHONY: strip
strip: $(DEMOS)
	-$(STRIP) $(STRIPFLAGS) $^

.PHONY: clean
clean:
	@echo "  CLEAN"
	@-$(RM) $(DEMOS) $(addsuffix .debug,$(DEMOS))

.PHONY: cleanall
cleanall: clean
	@echo "  CLEANALL"

%: %.c demo.h
	@echo "  CC/LD $@.debug"
	@$(CC) $(CFLAGS) -D__USE_OLD_TIMEVAL__ -I. $< -o $@.debug $(LDLIBS) $(DEMOLIBS)
	@echo "  CC/LD $@"
	@$(STRIP) $(STRIPFLAGS) -o $@ $@.debug
	@$(CHMOD) $@
