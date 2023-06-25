# Uncomment the following line to compile under a foreign OS.
# CROSS_COMPILE = ppc-amigaos-

CC = $(CROSS_COMPILE)gcc

LDFLAGS = -L. -lauto

TestApp: testapp.o
	$(CC) -o $@ testapp.o $(LDFLAGS)
