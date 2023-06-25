# Makefile for a few CompositeTags() YUV test programs.
#
# Author: Hans de Ruiter
#
# Revisions:
# - Initial Version 31 January 2014
#
#
# Copyright (c) 2014 by Hans de Ruiter

TARGETS = CompositeYUV CompositeYUVExt CompositeYUVBlitStream

CC = gcc
AS = 
STRIP = strip

CFLAGS = -Wall -mcrt=newlib -std=gnu99 -O3 -Wunused-variable -I..  -gstabs

LDFLAGS	= -lauto


all: 	$(TARGETS) 

define PROGRAM_template
$(1).o: $(1).c 
	$(CC) $(CFLAGS) -c $(1).c -o $(1).o

$(1).debug: $(1).o 
	$(CC) $(CFLAGS)  -o $(1).debug $(1).o $(LDFLAGS) 

$(1): $(1).debug 
	$(STRIP) $(1).debug -o $(1)

OBJS += $(1).o
TARGETS_DEBUG += $(1).debug
endef

.PHONY: clean 

$(foreach prog,$(TARGETS),$(eval $(call PROGRAM_template,$(prog))))

clean:
	rm $(OBJS) $(TARGETS) $(TARGETS_DEBUG)
