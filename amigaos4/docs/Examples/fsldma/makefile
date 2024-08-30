#
# Copyright 2021 Trevor Dickinson. All rights reserved.
#
# This file is part of ExecSG.
# Licensed under the ExecSG license.
# See the LICENSING file for details.
#

CC = ppc-amigaos-gcc
CFLAGS = -g
INCPATH = ../../include

OBJS = chainingdma_test.o copymemdma_test.o fsldma_example_1.o fsldma_example_2.o fsldma_example_3.o stress_dma_test.o
PRGS = chainingdma_test copymemdma_test fsldma_example_1 fsldma_example_2 fsldma_example_3 stress_dma_test

all: $(PRGS)

chainingdma_test: chainingdma_test.o
	$(CC) -o $@ $<

chainingdma_test.o: ${@:.o=.c}
	$(CC) -I$(INCPATH) -c ${@:.o=.c}

copymemdma_test: copymemdma_test.o
	$(CC) -o $@ $<

copymemdma_test.o: ${@:.o=.c}
	$(CC) -I$(INCPATH) -c ${@:.o=.c}

fsldma_example_1: fsldma_example_1.o
	$(CC) -o $@ $<

fsldma_example_1.o: ${@:.o=.c}
	$(CC) -I$(INCPATH) -c ${@:.o=.c}

fsldma_example_2: fsldma_example_2.o
	$(CC) -o $@ $<

fsldma_example_2.o: ${@:.o=.c}
	$(CC) -I$(INCPATH) -c ${@:.o=.c}

fsldma_example_3: fsldma_example_3.o
	$(CC) -o $@ $<

fsldma_example_3.o: ${@:.o=.c}
	$(CC) -I$(INCPATH) -c ${@:.o=.c}

stress_dma_test: stress_dma_test.o
	$(CC) -o $@ $<

stress_dma_test.o: ${@:.o=.c}
	$(CC) -I$(INCPATH) -c ${@:.o=.c}

clean:
	$(RM) $(OBJS) $(PRGS)

