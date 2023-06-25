#
# Makefile for charset drivers
#

CC		= gcc

CWFLAGS		= -Wall -W -Wundef -Wshadow -Wpointer-arith \
		  -Wbad-function-cast -Wconversion -Waggregate-return \
		  -Werror

CFLAGS		= $(CWFLAGS) -O2 -IV:include -fomit-frame-pointer -fno-builtin -c

LIBS		= -lc

LDFLAGS		= -nostartfiles -nostdlib -s

OBJS		= Amiga-1251.o                                \
		  ISO-8859-2.o   ISO-8859-3.o  ISO-8859-4.o   \
		  ISO-8859-5.o   ISO-8859-6.o  ISO-8859-7.o   \
		  ISO-8859-8.o   ISO-8859-9.o  ISO-8859-10.o  \
		  ISO-8859-13.o  ISO-8859-14.o ISO-8859-15.o  \
		  ISO-8859-16.o                               \
		  X-ATO-E2.o    X-ATO-PL.o     X-ATO-srpski.o \
		  startup.o

EXE		= Amiga-1251.charset                       \
		  ISO-8859-2.charset   ISO-8859-3.charset  \
		  ISO-8859-4.charset   ISO-8859-5.charset  \
		  ISO-8859-6.charset   ISO-8859-7.charset  \
		  ISO-8859-8.charset   ISO-8859-9.charset  \
		  ISO-8859-10.charset  ISO-8859-13.charset \
		  ISO-8859-14.charset  ISO-8859-15.charset \
		  ISO-8859-16.charset                      \
		  X-ATO-E2.charset     X-ATO-PL.charset    \
		  X-ATO-srpski.charset

all:		$(EXE)

startup.o:	startup.c
		$(CC) $(CFLAGS) $<

Amiga-1251.o:	Amiga-1251.c Amiga-1251.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-2.o:	ISO-8859-2.c ISO-8859-2.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-3.o:	ISO-8859-3.c ISO-8859-3.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-4.o:	ISO-8859-4.c ISO-8859-4.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-5.o:	ISO-8859-5.c ISO-8859-5.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-6.o:	ISO-8859-6.c ISO-8859-6.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-7.o:	ISO-8859-7.c ISO-8859-7.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-8.o:	ISO-8859-8.c ISO-8859-8.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-9.o:	ISO-8859-9.c ISO-8859-9.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-10.o:	ISO-8859-10.c ISO-8859-10.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-13.o:	ISO-8859-13.c ISO-8859-13.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-14.o:	ISO-8859-14.c ISO-8859-14.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-15.o:	ISO-8859-15.c ISO-8859-15.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

ISO-8859-16.o:	ISO-8859-16.c ISO-8859-16.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

X-ATO-E2.o:	X-ATO-E2.c X-ATO-E2.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

X-ATO-PL.o:	X-ATO-PL.c X-ATO-PL.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

X-ATO-srpski.o:	X-ATO-srpski.c X-ATO-srpski.charset_rev.h charsetdriver.c
		$(CC) $(CFLAGS) $<

Amiga-1251.charset:	       startup.o Amiga-1251.o
	$(CC) $(LDFLAGS) -o $@ startup.o Amiga-1251.o $(LIBS)
	protect $@ -e

ISO-8859-2.charset:	       startup.o ISO-8859-2.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-2.o $(LIBS)
	protect $@ -e

ISO-8859-3.charset:	       startup.o ISO-8859-3.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-3.o $(LIBS)
	protect $@ -e

ISO-8859-4.charset:	       startup.o ISO-8859-4.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-4.o $(LIBS)
	protect $@ -e

ISO-8859-5.charset:	       startup.o ISO-8859-5.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-5.o $(LIBS)
	protect $@ -e

ISO-8859-6.charset:	       startup.o ISO-8859-6.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-6.o $(LIBS)
	protect $@ -e

ISO-8859-7.charset:	       startup.o ISO-8859-7.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-7.o $(LIBS)
	protect $@ -e

ISO-8859-8.charset:	       startup.o ISO-8859-8.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-8.o $(LIBS)
	protect $@ -e

ISO-8859-9.charset:	       startup.o ISO-8859-9.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-9.o $(LIBS)
	protect $@ -e

ISO-8859-10.charset:	       startup.o ISO-8859-10.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-10.o $(LIBS)
	protect $@ -e

ISO-8859-13.charset:	       startup.o ISO-8859-13.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-13.o $(LIBS)
	protect $@ -e

ISO-8859-14.charset:	       startup.o ISO-8859-14.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-14.o $(LIBS)
	protect $@ -e

ISO-8859-15.charset:	       startup.o ISO-8859-15.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-15.o $(LIBS)
	protect $@ -e

ISO-8859-16.charset:	       startup.o ISO-8859-16.o
	$(CC) $(LDFLAGS) -o $@ startup.o ISO-8859-16.o $(LIBS)
	protect $@ -e

X-ATO-E2.charset:	       startup.o X-ATO-E2.o
	$(CC) $(LDFLAGS) -o $@ startup.o X-ATO-E2.o $(LIBS)
	protect $@ -e

X-ATO-PL.charset:	       startup.o X-ATO-PL.o
	$(CC) $(LDFLAGS) -o $@ startup.o X-ATO-PL.o $(LIBS)
	protect $@ -e

X-ATO-srpski.charset:	       startup.o X-ATO-srpski.o
	$(CC) $(LDFLAGS) -o $@ startup.o X-ATO-srpski.o $(LIBS)
	protect $@ -e

clean:
		-Delete $(OBJS) $(EXE)
