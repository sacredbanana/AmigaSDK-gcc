
CFLAGS = -gstabs -O2 -Wall

CC = gcc
AR = ar
RANLIB = ranlib
DEBUGLIB =
LFLAGS = -gstabs

all: radiff

radiff: radiff.o
	$(CC) -o radiff radiff.o $(LFLAGS)

radiff.o: radiff.c
	$(CC) -c radiff.c -o radiff.o $(CFLAGS)
