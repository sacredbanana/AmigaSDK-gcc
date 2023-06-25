# 
# $Id: Makefile,v 1.3 2009-11-05 02:54:09 ssolie Exp $
# 

# Uncomment the next line if you are cross compiling
CROSS_COMPILE = ppc-amigaos-

CC     = $(CROSS_COMPILE)gcc 
CXX    = $(CROSS_COMPILE)c++ 
AS     = $(CROSS_COMPILE)as 
LD     = $(CROSS_COMPILE)ld 
RM     = rm

# Change these as required
DEFINES  = -D__NOLIBBASE__ -D__NOGLOBALIFACE__
OPTIMIZE = -O3
DEBUG    = -gstabs #-DDEBUG
CFLAGS   = -Wall $(DEFINES) $(OPTIMIZE) $(DEBUG)

# Flags passed to gcc during linking
LINK = 

# Name of the "thing" to build
TARGET = PrefsObjectsExample

# Additional linker libraries
LIBS = 

# Source code files used in this project
# Add any additional files to this line

CSRCS   =	PrefsObjectsExample.c

COBJS   = $(CSRCS:.c=.o)
OBJS    = $(COBJS)

# Rules for building
$(TARGET): $(OBJS)
	$(CC) $(LINK) -o $(TARGET) $(OBJS) $(LIBS)
	
.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)

