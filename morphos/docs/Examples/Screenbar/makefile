CC = ppc-morphos-gcc
STRIP = ppc-morphos-strip

OBJS = example_sbar.o
EOBJS = runtime_example.o
CFLAGS = -Wall -noixemul

all: Example.sbar runtime_example

Example.sbar: $(OBJS)
	@echo "Making $@..."
	@$(CC) $(CFLAGS) -nostdlib $(OBJS) -o $@.db -lm -labox -laboxstubs -ldebug -lc
	@$(STRIP) --strip-unneeded --remove-section=.comment $@.db -o $@
	@chmod u+x $@

runtime_example: $(EOBJS)
	$(CC) -noixemul $(EOBJS) -o $@.db
	$(STRIP) $(STRIPFLAGS) $@.db -o $@
	chmod u+x $@

clean:
	rm -f *.o *.db Example.sbar runtime_example 
