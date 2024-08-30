BLANKERNAME = simple.btd

CC = ppc-morphos-gcc
STRIP = ppc-morphos-strip

CFLAGS = -D__AMIGADATE__=\"$(shell date "+%d.%m.%y")\" -D__COPYRIGHTYEAR__=\"$(shell date "+%Y")\" -O2 -Wall -noixemul -mfused-madd -fomit-frame-pointer

OBJS = lib.o libfunctable.o libfunctions.o blanker.o

all: $(BLANKERNAME)

blanker.o: blanker.c
libfunctable.o: libfunctable.c
libfunctions.o: libfunctions.c libdata.h
lib.o: lib.c libdata.h

$(BLANKERNAME): $(OBJS)
	$(CC) -nostdlib $(CFLAGS) -o $@.db $(OBJS) -lc -lm -lc -laboxstubs -ldebug
	$(STRIP) --strip-unneeded --remove-section=.comment $@.db -o $@
	chmod u+x $@

clean:
	rm -f *.o *.db *.btd

dump:
	objdump --section-headers --all-headers --reloc --disassemble-all $(BLANKERNAME).db >$(BLANKERNAME).dump

install: $(BLANKERNAME)
	cp $(BLANKERNAME) SYS:Classes/Blankers/$(BLANKERNAME)
	FlushLib $(BLANKERNAME)
