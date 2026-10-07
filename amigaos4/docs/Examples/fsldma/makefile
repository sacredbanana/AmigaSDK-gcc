#
# Copyright 2021,2023 Trevor Dickinson. All rights reserved.
#
# This file is part of ExecSG.
# Licensed under the ExecSG license.
# See the LICENSING file for details.
#

CC      := ppc-amigaos-gcc
INCPATH := ../../include

OBJS := chainingdma_test.o copymemdma_test.o stress_dma_test.o
OBJS += fsldma_example_1.o fsldma_example_2.o fsldma_example_3.o
OBJS += fsldma_copymem64.o fsldma_copymem64tags.o

PRGS := chainingdma_test copymemdma_test stress_dma_test
PRGS += fsldma_example_1 fsldma_example_2 fsldma_example_3
PRGS += fsldma_copymem64 fsldma_copymem64tags

all: $(PRGS)

chainingdma_test: chainingdma_test.c
	$(CC) -I$(INCPATH) -o chainingdma_test chainingdma_test.c

copymemdma_test: copymemdma_test.c
	$(CC) -I$(INCPATH) -o copymemdma_test copymemdma_test.c

stress_dma_test: stress_dma_test.c
	$(CC) -I$(INCPATH) -o stress_dma_test stress_dma_test.c

fsldma_example_1: fsldma_example_1.c
	$(CC) -I$(INCPATH) -o fsldma_example_1 fsldma_example_1.c

fsldma_example_2: fsldma_example_2.c
	$(CC) -I$(INCPATH) -o fsldma_example_2 fsldma_example_2.c

fsldma_example_3: fsldma_example_3.c
	$(CC) -I$(INCPATH) -o fsldma_example_3 fsldma_example_3.c

fsldma_copymem64: fsldma_copymem64.c
	$(CC) -I$(INCPATH) -o fsldma_copymem64 fsldma_copymem64.c

fsldma_copymem64tags: fsldma_copymem64tags.c
	$(CC) -I$(INCPATH) -o fsldma_copymem64tags fsldma_copymem64tags.c

clean:
	$(RM) $(OBJS) $(PRGS)

