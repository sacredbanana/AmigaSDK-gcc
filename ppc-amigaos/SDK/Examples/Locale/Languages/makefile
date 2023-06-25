#
# Makefile for language drivers
#

CC		= gcc

CWFLAGS		= -Wall -W -Wundef -Wshadow -Wpointer-arith \
		  -Wbad-function-cast -Wconversion -Waggregate-return \
		  -Werror

CFLAGS		= $(CWFLAGS) -m68020-60 -O2 -IV:include \
		  -fomit-frame-pointer -fno-builtin -c

LIBS		= -lc

LDFLAGS		= -nostartfiles -nostdlib -s

OBJS		= albanian.o                                          \
                                      belarusian_ISO-8859-5.o         \
		                      bosnian_ISO-8859-2.o            \
		                      bosnian_ISO-8859-16.o           \
		                      bulgarian_ISO-8859-5.o          \
		  catalan.o           catalan_ISO-8859-15.o           \
		                      croatian_ISO-8859-2.o           \
		                      croatian_ISO-8859-16.o          \
		                      czech_ISO-8859-2.o              \
		                      czech_X-ATO-E2.o                \
		  danish.o            danish_ISO-8859-15.o            \
		  dutch.o             dutch_ISO-8859-15.o             \
		                      english_ISO-8859-15.o           \
	                              esperanto_ISO-8859-3.o          \
		                      estonian_ISO-8859-15.o          \
	          faroese.o           faroese_ISO-8859-15.o           \
		  finnish.o           finnish_ISO-8859-15.o           \
		  french.o            french_ISO-8859-15.o            \
	          galician.o          galician_ISO-8859-15.o          \
		  german.o            german_ISO-8859-15.o            \
		                      greek_ISO-8859-7.o              \
		                      hebrew_ISO-8859-8.o             \
		                      hungarian_ISO-8859-2.o          \
		                      hungarian_ISO-8859-16.o         \
		  icelandic.o                                         \
		                      irish_ISO-8859-15.o             \
		  italian.o           italian_ISO-8859-15.o           \
		                      latvian_ISO-8859-13.o           \
		                      lithuanian_ISO-8859-13.o        \
                                      macedonian_ISO-8859-5.o         \
                  malay-indonesian.o  malay-malaysian.o               \
                                      maltese_ISO-8859-3.o            \
		  norwegian.o         norwegian_ISO-8859-15.o         \
		  norwegian-nynorsk.o norwegian-nynorsk_ISO-8859-15.o \
		                      polish_ISO-8859-2.o             \
		                      polish_ISO-8859-16.o            \
		                      polish_X-ATO-PL.o               \
		  portuguese.o        portuguese_ISO-8859-15.o        \
		  portuguese-brazil.o                                 \
		                      romanian_ISO-8859-16.o          \
		                      russian_ISO-8859-5.o            \
		                      russian_Amiga-1251.o            \
		                      serbian_ISO-8859-2.o            \
		                      serbian_ISO-8859-5.o            \
		                      serbian_ISO-8859-16.o           \
		                      serbian_X-ATO-srpski.o          \
		                      slovak_ISO-8859-2.o             \
		                      slovak_X-ATO-E2.o               \
		                      slovenian_ISO-8859-2.o          \
		                      slovenian_ISO-8859-16.o         \
	          spanish.o           spanish_ISO-8859-15.o           \
		  swedish.o           swedish_ISO-8859-15.o           \
		                      turkish_ISO-8859-9.o            \
		                      turkish_int_ISO-8859-9.o        \
		                      ukrainian_ISO-8859-5.o

EXE		= albanian.language                                                 \
		                             belarusian_ISO-8859-5.language         \
		                             bosnian_ISO-8859-2.language            \
		                             bosnian_ISO-8859-16.language           \
		                             bulgarian_ISO-8859-5.language          \
		  catalan.language           catalan_ISO-8859-15.language           \
		                             croatian_ISO-8859-2.language           \
		                             croatian_ISO-8859-16.language          \
		                             czech_ISO-8859-2.language              \
		                             czech_X-ATO-E2.language                \
		  danish.language            danish_ISO-8859-15.language            \
		  dutch.language             dutch_ISO-8859-15.language             \
		                             english_ISO-8859-15.language           \
		                             esperanto_ISO-8859-3.language          \
		                             estonian_ISO-8859-15.language          \
		  faroese.language           faroese_ISO-8859-15.language           \
		  finnish.language           finnish_ISO-8859-15.language           \
		  french.language            french_ISO-8859-15.language            \
		  galician.language          galician_ISO-8859-15.language          \
		  german.language            german_ISO-8859-15.language            \
		                             greek_ISO-8859-7.language              \
		                             hebrew_ISO-8859-8.language             \
		                             hungarian_ISO-8859-2.language          \
		                             hungarian_ISO-8859-16.language         \
		  icelandic.language                                                \
		                             irish_ISO-8859-15.language             \
		  italian.language           italian_ISO-8859-15.language           \
		                             latvian_ISO-8859-13.language           \
		                             lithuanian_ISO-8859-13.language        \
		                             macedonian_ISO-8859-5.language         \
                  malay-indonesian.language  malay-malaysian.language               \
		                             maltese_ISO-8859-3.language            \
		  norwegian.language         norwegian_ISO-8859-15.language         \
		  norwegian-nynorsk.language norwegian-nynorsk_ISO-8859-15.language \
		                             polish_ISO-8859-2.language             \
		                             polish_ISO-8859-16.language            \
		                             polish_X-ATO-PL.language               \
		  portuguese.language        portuguese_ISO-8859-15.language        \
		  portuguese-brazil.language                                        \
		                             romanian_ISO-8859-16.language          \
		                             russian_ISO-8859-5.language            \
		                             russian_Amiga-1251.language            \
		                             serbian_ISO-8859-2.language            \
		                             serbian_ISO-8859-5.language            \
		                             serbian_ISO-8859-16.language           \
		                             serbian_X-ATO-srpski.language          \
		                             slovak_ISO-8859-2.language             \
		                             slovak_X-ATO-E2.language               \
		                             slovenian_ISO-8859-2.language          \
		                             slovenian_ISO-8859-16.language         \
		  spanish.language           spanish_ISO-8859-15.language           \
		  swedish.language           swedish_ISO-8859-15.language           \
		                             turkish_ISO-8859-9.language            \
		                             turkish_int_ISO-8859-9.language        \
		                             ukrainian_ISO-8859-5.language

all:				$(EXE)

startup.o:			startup.c
				$(CC) $(CFLAGS) $<

albanian.o:			albanian.c albanian.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

belarusian_ISO-8859-5.o:	belarusian_ISO-8859-5.c belarusian_ISO-8859-5.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

bosnian_ISO-8859-2.o:		bosnian_ISO-8859-2.c bosnian_ISO-8859-2.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

bosnian_ISO-8859-16.o:		bosnian_ISO-8859-16.c bosnian_ISO-8859-16.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

bulgarian_ISO-8859-5.o:		bulgarian_ISO-8859-5.c bulgarian_ISO-8859-5.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

catalan.o:			catalan.c catalan.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

catalan_ISO-8859-15.o:		catalan_ISO-8859-15.c catalan_ISO-8859-15.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

croatian_ISO-8859-2.o:		croatian_ISO-8859-2.c croatian_ISO-8859-2.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

croatian_ISO-8859-16.o:		croatian_ISO-8859-16.c croatian_ISO-8859-16.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

czech_ISO-8859-2.o:		czech_ISO-8859-2.c czech_ISO-8859-2.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

czech_X-ATO-E2.o:		czech_X-ATO-E2.c czech_X-ATO-E2.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

danish.o:			danish.c danish.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

danish_ISO-8859-15.o:		danish_ISO-8859-15.c danish_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

dutch.o:			dutch.c dutch.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

dutch_ISO-8859-15.o:		dutch_ISO-8859-15.c dutch_ISO-8859-15.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

english_ISO-8859-15.o:		english_ISO-8859-15.c english_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

esperanto_ISO-8859-3.o:		esperanto_ISO-8859-3.c esperanto_ISO-8859-3.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

estonian_ISO-8859-15.o:		estonian_ISO-8859-15.c estonian_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

faroese.o:			faroese.c faroese.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

faroese_ISO-8859-15.o:		faroese_ISO-8859-15.c faroese_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

finnish.o:			finnish.c finnish.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

finnish_ISO-8859-15.o:		finnish_ISO-8859-15.c finnish_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

french.o:			french.c french.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

french_ISO-8859-15.o:		french_ISO-8859-15.c french_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

galician.o:			galician.c galician.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

galician_ISO-8859-15.o:		galician_ISO-8859-15.c galician_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

german.o:			german.c german.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

german_ISO-8859-15.o:		german_ISO-8859-15.c german_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

greek_ISO-8859-7.o:		greek_ISO-8859-7.c greek_ISO-8859-7.language_rev.h languagecharsetdriver.c
				$(CC) $(CFLAGS) $<

hebrew_ISO-8859-8.o:		hebrew_ISO-8859-8.c hebrew_ISO-8859-8.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

hungarian_ISO-8859-2.o:		hungarian_ISO-8859-2.c hungarian_ISO-8859-2.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

hungarian_ISO-8859-16.o:	hungarian_ISO-8859-16.c hungarian_ISO-8859-16.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

icelandic.o:			icelandic.c italian.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

irish_ISO-8859-15.o:		irish_ISO-8859-15.c irish_ISO-8859-15.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

italian.o:			italian.c italian.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

italian_ISO-8859-15.o:		italian_ISO-8859-15.c italian_ISO-8859-15.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

latvian_ISO-8859-13.o:		latvian_ISO-8859-13.c latvian_ISO-8859-13.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

lithuanian_ISO-8859-13.o:	lithuanian_ISO-8859-13.c lithuanian_ISO-8859-13.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

macedonian_ISO-8859-5.o:	macedonian_ISO-8859-5.c macedonian_ISO-8859-5.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

malay-indonesian.o:		malay-indonesian.c malay-indonesian.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

malay-malaysian.o:		malay-malaysian.c malay-malaysian.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

maltese_ISO-8859-3.o:		maltese_ISO-8859-3.c maltese_ISO-8859-3.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

norwegian.o:			norwegian.c norwegian.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

norwegian_ISO-8859-15.o:	norwegian_ISO-8859-15.c norwegian_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

norwegian-nynorsk.o:		norwegian-nynorsk.c norwegian-nynorsk.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

norwegian-nynorsk_ISO-8859-15.o: norwegian-nynorsk_ISO-8859-15.c norwegian-nynorsk_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

polish_ISO-8859-2.o:		polish_ISO-8859-2.c polish_ISO-8859-2.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

polish_ISO-8859-16.o:		polish_ISO-8859-16.c polish_ISO-8859-16.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

polish_X-ATO-PL.o:		polish_X-ATO-PL.c polish_X-ATO-PL.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

portuguese.o:			portuguese.c portuguese.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

portuguese_ISO-8859-15.o:	portuguese_ISO-8859-15.c portuguese_ISO-8859-15.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

portuguese-brazil.o:		portuguese-brazil.c portuguese-brazil.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

romanian_ISO-8859-16.o:		romanian_ISO-8859-16.c romanian_ISO-8859-16.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

russian_ISO-8859-5.o:		russian_ISO-8859-5.c russian_ISO-8859-5.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

russian_Amiga-1251.o:		russian_Amiga-1251.c russian_Amiga-1251.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

serbian_ISO-8859-2.o:		serbian_ISO-8859-2.c serbian_ISO-8859-2.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

serbian_ISO-8859-5.o:		serbian_ISO-8859-5.c serbian_ISO-8859-5.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

serbian_ISO-8859-16.o:		serbian_ISO-8859-16.c serbian_ISO-8859-16.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

serbian_X-ATO-srpski.o:		serbian_X-ATO-srpski.c serbian_X-ATO-srpski.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

slovak_ISO-8859-2.o:		slovak_ISO-8859-2.c slovak_ISO-8859-2.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

slovak_X-ATO-E2.o:		slovak_X-ATO-E2.c slovak_X-ATO-E2.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

slovenian_ISO-8859-2.o:		slovenian_ISO-8859-2.c slovenian_ISO-8859-2.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

slovenian_ISO-8859-16.o:	slovenian_ISO-8859-16.c slovenian_ISO-8859-16.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

spanish.o:			spanish.c spanish.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

spanish_ISO-8859-15.o:		spanish_ISO-8859-15.c spanish_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

swedish.o:			swedish.c swedish.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

swedish_ISO-8859-15.o:		swedish_ISO-8859-15.c swedish_ISO-8859-15.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<

turkish_ISO-8859-9.o:		turkish_ISO-8859-9.c turkish_ISO-8859-9.language_rev.h languagecharsetdriver.c
				$(CC) $(CFLAGS) $<

turkish_int_ISO-8859-9.o:	turkish_int_ISO-8859-9.c turkish_int_ISO-8859-9.language_rev.h languagedriver.c
				$(CC) $(CFLAGS) $<

ukrainian_ISO-8859-5.o:		ukrainian_ISO-8859-5.c ukrainian_ISO-8859-5.language_rev.h languagestrncmpdriver.c
				$(CC) $(CFLAGS) $<


albanian.language:		 startup.o albanian.o
		$(CC) $(LDFLAGS) startup.o albanian.o $(LIBS) -o $@
		protect $@ -e

belarusian_ISO-8859-5.language:	 startup.o belarusian_ISO-8859-5.o
		$(CC) $(LDFLAGS) startup.o belarusian_ISO-8859-5.o $(LIBS) -o $@
		protect $@ -e

bosnian_ISO-8859-2.language:	 startup.o bosnian_ISO-8859-2.o
		$(CC) $(LDFLAGS) startup.o bosnian_ISO-8859-2.o $(LIBS) -o $@
		protect $@ -e

bosnian_ISO-8859-16.language:	 startup.o bosnian_ISO-8859-16.o
		$(CC) $(LDFLAGS) startup.o bosnian_ISO-8859-16.o $(LIBS) -o $@
		protect $@ -e

bulgarian_ISO-8859-5.language:	 startup.o bulgarian_ISO-8859-5.o
		$(CC) $(LDFLAGS) startup.o bulgarian_ISO-8859-5.o $(LIBS) -o $@
		protect $@ -e

catalan.language:		 startup.o catalan.o
		$(CC) $(LDFLAGS) startup.o catalan.o $(LIBS) -o $@
		protect $@ -e

catalan_ISO-8859-15.language:	 startup.o catalan_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o catalan_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

croatian_ISO-8859-2.language:	 startup.o croatian_ISO-8859-2.o
		$(CC) $(LDFLAGS) startup.o croatian_ISO-8859-2.o $(LIBS) -o $@
		protect $@ -e

croatian_ISO-8859-16.language:	 startup.o croatian_ISO-8859-16.o
		$(CC) $(LDFLAGS) startup.o croatian_ISO-8859-16.o $(LIBS) -o $@
		protect $@ -e

czech_ISO-8859-2.language:	 startup.o czech_ISO-8859-2.o
		$(CC) $(LDFLAGS) startup.o czech_ISO-8859-2.o $(LIBS) -o $@
		protect $@ -e

czech_X-ATO-E2.language:	 startup.o czech_X-ATO-E2.o
		$(CC) $(LDFLAGS) startup.o czech_X-ATO-E2.o $(LIBS) -o $@
		protect $@ -e

danish.language:		 startup.o danish.o
		$(CC) $(LDFLAGS) startup.o danish.o $(LIBS) -o $@
		protect $@ -e

danish_ISO-8859-15.language:	 startup.o danish_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o danish_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

dutch.language:			 startup.o dutch.o
		$(CC) $(LDFLAGS) startup.o dutch.o $(LIBS) -o $@
		protect $@ -e

dutch_ISO-8859-15.language:	 startup.o dutch_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o dutch_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

english_ISO-8859-15.language:	 startup.o english_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o english_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

esperanto_ISO-8859-3.language:	 startup.o esperanto_ISO-8859-3.o
		$(CC) $(LDFLAGS) startup.o esperanto_ISO-8859-3.o $(LIBS) -o $@
		protect $@ -e

estonian_ISO-8859-15.language:	 startup.o estonian_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o estonian_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

faroese.language:		 startup.o faroese.o
		$(CC) $(LDFLAGS) startup.o faroese.o $(LIBS) -o $@
		protect $@ -e

faroese_ISO-8859-15.language:	 startup.o faroese_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o faroese_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

finnish.language:		 startup.o finnish.o
		$(CC) $(LDFLAGS) startup.o finnish.o $(LIBS) -o $@
		protect $@ -e

finnish_ISO-8859-15.language:	 startup.o finnish_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o finnish_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

french.language:		 startup.o french.o
		$(CC) $(LDFLAGS) startup.o french.o $(LIBS) -o $@
		protect $@ -e

french_ISO-8859-15.language:	 startup.o french_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o french_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

galician.language:		 startup.o galician.o
		$(CC) $(LDFLAGS) startup.o galician.o $(LIBS) -o $@
		protect $@ -e

galician_ISO-8859-15.language:	 startup.o galician_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o galician_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

german.language:		 startup.o german.o
		$(CC) $(LDFLAGS) startup.o german.o $(LIBS) -o $@
		protect $@ -e

german_ISO-8859-15.language:	 startup.o german_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o german_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

greek_ISO-8859-7.language:	 startup.o greek_ISO-8859-7.o
		$(CC) $(LDFLAGS) startup.o greek_ISO-8859-7.o $(LIBS) -o $@
		protect $@ -e

hebrew_ISO-8859-8.language:	 startup.o hebrew_ISO-8859-8.o
		$(CC) $(LDFLAGS) startup.o hebrew_ISO-8859-8.o $(LIBS) -o $@
		protect $@ -e

hungarian_ISO-8859-2.language:	 startup.o hungarian_ISO-8859-2.o
		$(CC) $(LDFLAGS) startup.o hungarian_ISO-8859-2.o $(LIBS) -o $@
		protect $@ -e

hungarian_ISO-8859-16.language:	 startup.o hungarian_ISO-8859-16.o
		$(CC) $(LDFLAGS) startup.o hungarian_ISO-8859-16.o $(LIBS) -o $@
		protect $@ -e

icelandic.language:		 startup.o icelandic.o
		$(CC) $(LDFLAGS) startup.o icelandic.o $(LIBS) -o $@
		protect $@ -e

irish_ISO-8859-15.language:	 startup.o irish_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o irish_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

italian.language:		 startup.o italian.o
		$(CC) $(LDFLAGS) startup.o italian.o $(LIBS) -o $@
		protect $@ -e

italian_ISO-8859-15.language:	 startup.o italian_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o italian_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

latvian_ISO-8859-13.language:	 startup.o latvian_ISO-8859-13.o
		$(CC) $(LDFLAGS) startup.o latvian_ISO-8859-13.o $(LIBS) -o $@
		protect $@ -e

lithuanian_ISO-8859-13.language: startup.o lithuanian_ISO-8859-13.o
		$(CC) $(LDFLAGS) startup.o lithuanian_ISO-8859-13.o $(LIBS) -o $@
		protect $@ -e

macedonian_ISO-8859-5.language:	 startup.o macedonian_ISO-8859-5.o
		$(CC) $(LDFLAGS) startup.o macedonian_ISO-8859-5.o $(LIBS) -o $@
		protect $@ -e

malay-indonesian.language:	 startup.o malay-indonesian.o
		$(CC) $(LDFLAGS) startup.o malay-indonesian.o $(LIBS) -o $@
		protect $@ -e

malay-malaysian.language:	 startup.o malay-malaysian.o
		$(CC) $(LDFLAGS) startup.o malay-malaysian.o $(LIBS) -o $@
		protect $@ -e

maltese_ISO-8859-3.language:	 startup.o maltese_ISO-8859-3.o
		$(CC) $(LDFLAGS) startup.o maltese_ISO-8859-3.o $(LIBS) -o $@
		protect $@ -e

norwegian.language:		 startup.o norwegian.o
		$(CC) $(LDFLAGS) startup.o norwegian.o $(LIBS) -o $@
		protect $@ -e

norwegian_ISO-8859-15.language:	 startup.o norwegian_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o norwegian_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

norwegian-nynorsk.language:	 startup.o norwegian-nynorsk.o
		$(CC) $(LDFLAGS) startup.o norwegian-nynorsk.o $(LIBS) -o $@
		protect $@ -e

norwegian-nynorsk_ISO-8859-15.language: startup.o norwegian-nynorsk_ISO-8859-15.o
		$(CC) $(LDFLAGS)        startup.o norwegian-nynorsk_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

polish_ISO-8859-2.language:	 startup.o polish_ISO-8859-2.o
		$(CC) $(LDFLAGS) startup.o polish_ISO-8859-2.o $(LIBS) -o $@
		protect $@ -e

polish_ISO-8859-16.language:	 startup.o polish_ISO-8859-16.o
		$(CC) $(LDFLAGS) startup.o polish_ISO-8859-16.o $(LIBS) -o $@
		protect $@ -e

polish_X-ATO-PL.language:	 startup.o polish_X-ATO-PL.o
		$(CC) $(LDFLAGS) startup.o polish_X-ATO-PL.o $(LIBS) -o $@
		protect $@ -e

portuguese.language:		 startup.o portuguese.o
		$(CC) $(LDFLAGS) startup.o portuguese.o $(LIBS) -o $@
		protect $@ -e

portuguese_ISO-8859-15.language: startup.o portuguese_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o portuguese_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

portuguese-brazil.language:	 startup.o portuguese-brazil.o
		$(CC) $(LDFLAGS) startup.o portuguese-brazil.o $(LIBS) -o $@
		protect $@ -e

romanian_ISO-8859-16.language:	 startup.o romanian_ISO-8859-16.o
		$(CC) $(LDFLAGS) startup.o romanian_ISO-8859-16.o $(LIBS) -o $@
		protect $@ -e

russian_Amiga-1251.language:	 startup.o russian_Amiga-1251.o
		$(CC) $(LDFLAGS) startup.o russian_Amiga-1251.o $(LIBS) -o $@
		protect $@ -e

russian_ISO-8859-5.language:	 startup.o russian_ISO-8859-5.o
		$(CC) $(LDFLAGS) startup.o russian_ISO-8859-5.o $(LIBS) -o $@
		protect $@ -e

serbian_ISO-8859-2.language:	 startup.o serbian_ISO-8859-2.o
		$(CC) $(LDFLAGS) startup.o serbian_ISO-8859-2.o $(LIBS) -o $@
		protect $@ -e

serbian_ISO-8859-5.language:	 startup.o serbian_ISO-8859-5.o
		$(CC) $(LDFLAGS) startup.o serbian_ISO-8859-5.o $(LIBS) -o $@
		protect $@ -e

serbian_ISO-8859-16.language:	 startup.o serbian_ISO-8859-16.o
		$(CC) $(LDFLAGS) startup.o serbian_ISO-8859-16.o $(LIBS) -o $@
		protect $@ -e

serbian_X-ATO-srpski.language:	 startup.o serbian_X-ATO-srpski.o
		$(CC) $(LDFLAGS) startup.o serbian_X-ATO-srpski.o $(LIBS) -o $@
		protect $@ -e

slovak_ISO-8859-2.language:	 startup.o slovak_ISO-8859-2.o
		$(CC) $(LDFLAGS) startup.o slovak_ISO-8859-2.o $(LIBS) -o $@
		protect $@ -e

slovak_X-ATO-E2.language:	 startup.o slovak_X-ATO-E2.o
		$(CC) $(LDFLAGS) startup.o slovak_X-ATO-E2.o $(LIBS) -o $@
		protect $@ -e

slovenian_ISO-8859-2.language:	 startup.o slovenian_ISO-8859-2.o
		$(CC) $(LDFLAGS) startup.o slovenian_ISO-8859-2.o $(LIBS) -o $@
		protect $@ -e

slovenian_ISO-8859-16.language:	 startup.o slovenian_ISO-8859-16.o
		$(CC) $(LDFLAGS) startup.o slovenian_ISO-8859-16.o $(LIBS) -o $@
		protect $@ -e

spanish.language:		 startup.o spanish.o
		$(CC) $(LDFLAGS) startup.o spanish.o $(LIBS) -o $@
		protect $@ -e

spanish_ISO-8859-15.language:	 startup.o spanish_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o spanish_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

swedish.language:		 startup.o swedish.o
		$(CC) $(LDFLAGS) startup.o swedish.o $(LIBS) -o $@
		protect $@ -e

swedish_ISO-8859-15.language:	 startup.o swedish_ISO-8859-15.o
		$(CC) $(LDFLAGS) startup.o swedish_ISO-8859-15.o $(LIBS) -o $@
		protect $@ -e

turkish_ISO-8859-9.language:	 startup.o turkish_ISO-8859-9.o
		$(CC) $(LDFLAGS) startup.o turkish_ISO-8859-9.o $(LIBS) -o $@
		protect $@ -e

turkish_int_ISO-8859-9.language: startup.o turkish_int_ISO-8859-9.o
		$(CC) $(LDFLAGS) startup.o turkish_int_ISO-8859-9.o $(LIBS) -o $@
		protect $@ -e

ukrainian_ISO-8859-5.language:	 startup.o ukrainian_ISO-8859-5.o
		$(CC) $(LDFLAGS) startup.o ukrainian_ISO-8859-5.o $(LIBS) -o $@
		protect $@ -e


clean:
		-Delete $(OBJS) $(EXE)
