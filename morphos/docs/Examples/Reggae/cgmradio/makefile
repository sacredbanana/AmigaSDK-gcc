# makefile for CgmRadio

CC = ppc-morphos-gcc-9
STRIP = strip
CFLAGS = -O2 -noixemul -I../libvstring -L../libvstring
LIBS = -lvstring

.PHONY: libvstring clean deepclean

all: libvstring CgmRadio

clean:
	rm -fv *.o CgmRadio

deepclean: clean
	make -C libvstring clean

CgmRadio: main.o playlist.o
	$(CC) $(CFLAGS) -o $@.db $^ $(LIBS)
	$(STRIP) --strip-unneeded --remove-section .comment -o $@ $@.db
	Protect $@ +E

main.o: main.c playlist.h
	$(CC) -c $(CFLAGS) -o $@ $<

playlist.o: playlist.c playlist.h main.h
	$(CC) -c $(CFLAGS) -o $@ $<

libvstring:
	make -C ../libvstring
