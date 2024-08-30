#
#  Chart-Demo
#  by Ilkka Lehtoranta
#
#  Based on Graph-Demo by Christian Rosentreter
#
#  $Id: Makefile,v 1.4 2013/01/06 08:55:02 itix Exp $
#

DEMOEXE    = Chart-Demo

CWARNS     = -Wall -W
CDEFS      =
CFLAGS     = $(CWARNS) $(CDEFS) -O3 -mcpu=750
LIBS       = -laboxstubs -labox

all: $(DEMOEXE)

$(DEMOEXE): $(DEMOEXE).c ../../../../development/os-include/mui/Chart_mcc.h
	ppc-morphos-gcc -noixemul $(CFLAGS) $(DEMOEXE).c $(LIBS) -o $@.db
	ppc-morphos-strip --strip-all --strip-unneeded --remove-section .comment $@.db -o $@
	chmod +x $@

dump:
	objdump --disassemble-all --reloc $(DEMOEXE).db >$(DEMOEXE).s

clean:
	rm -f *.o $(DEMOEXE).db $(DEMOEXE)
