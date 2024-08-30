
CC = ppc-morphos-gcc
STRIP = ppc-morphos-strip

CFLAGS = -D__AMIGADATE__=\"$(shell date "+%d.%m.%y")\" -O2 -Wall -noixemul -mfused-madd -fomit-frame-pointer

OBJS = api.o wavey.o libfunctable.o lib.o libfunctions.o

all: wavey.btd

api.o: api.c context.h version.h
wavey.o: wavey.c context.h
libfunctable.o: libfunctable.c
libfunctions.o: libfunctions.c libdata.h
lib.o: lib.c libdata.h

wavey.btd: $(OBJS)
	$(CC) -nostdlib $(CFLAGS) -o $@.db $(OBJS) -lc -lm -lc -laboxstubs -ldebug
	$(STRIP) --strip-unneeded --remove-section=.comment $@.db -o $@
	chmod u+x $@

clean:
	rm -f *.o *.db *.btd

dump:
	objdump --section-headers --all-headers --reloc --disassemble-all wavey.btd.db >wavey.btd.dump

