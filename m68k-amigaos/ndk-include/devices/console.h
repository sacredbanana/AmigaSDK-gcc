#ifndef DEVICES_CONSOLE_H
#define DEVICES_CONSOLE_H
/*
**	$VER: console.h 47.1 (28.6.2019)
**
**	Console device command definitions
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifndef EXEC_TYPES_H
#include	<exec/types.h>
#endif

#ifndef EXEC_IO_H
#include	<exec/io.h>
#endif	/* EXEC_IO_H */

/****** Console commands ******/
#define CD_ASKKEYMAP		(CMD_NONSTD+0)
#define CD_SETKEYMAP		(CMD_NONSTD+1)
#define CD_ASKDEFAULTKEYMAP	(CMD_NONSTD+2)
#define CD_SETDEFAULTKEYMAP	(CMD_NONSTD+3)
#define CD_SETUPSCROLLBACK	(CMD_NONSTD+4)
#define CD_SETSCROLLBACKPOSITION (CMD_NONSTD+5)

/****** SGR parameters ******/

#define SGR_PRIMARY	0
#define SGR_BOLD	1
#define SGR_ITALIC	3
#define SGR_UNDERSCORE	4
#define SGR_NEGATIVE	7

#define	SGR_NORMAL	22	/* default foreground color, not bold */
#define	SGR_NOTITALIC	23
#define	SGR_NOTUNDERSCORE 24
#define	SGR_POSITIVE	27

/* these names refer to the ANSI standard, not the implementation */
#define SGR_BLACK	30
#define SGR_RED		31
#define SGR_GREEN	32
#define SGR_YELLOW	33
#define SGR_BLUE	34
#define SGR_MAGENTA	35
#define SGR_CYAN	36
#define SGR_WHITE	37
#define SGR_DEFAULT	39

#define SGR_BLACKBG	40
#define SGR_REDBG	41
#define SGR_GREENBG	42
#define SGR_YELLOWBG	43
#define SGR_BLUEBG	44
#define SGR_MAGENTABG	45
#define SGR_CYANBG	46
#define SGR_WHITEBG	47
#define SGR_DEFAULTBG	49

/* these names refer to the implementation, they are the preferred */
/* names for use with the Amiga console device. */
#define SGR_CLR0	30
#define SGR_CLR1	31
#define SGR_CLR2	32
#define SGR_CLR3	33
#define SGR_CLR4	34
#define SGR_CLR5	35
#define SGR_CLR6	36
#define SGR_CLR7	37

#define SGR_CLR0BG	40
#define SGR_CLR1BG	41
#define SGR_CLR2BG	42
#define SGR_CLR3BG	43
#define SGR_CLR4BG	44
#define SGR_CLR5BG	45
#define SGR_CLR6BG	46
#define SGR_CLR7BG	47


/****** DSR parameters ******/

#define DSR_CPR		6

/****** CTC parameters ******/
#define CTC_HSETTAB	0
#define CTC_HCLRTAB	2
#define CTC_HCLRTABSALL	5

/******	TBC parameters ******/
#define TBC_HCLRTAB	0
#define TBC_HCLRTABSALL	3

/******	SM and RM parameters ******/
#define M_LNM	20	/* linefeed newline mode */
#define M_ASM	">1"	/* auto scroll mode */
#define M_AWM	"?7"	/* auto wrap mode */


struct ConsoleScrollback
{
	APTR cs_ScrollerGadget;
	UWORD cs_NumLines;
};

#endif	/* DEVICES_CONSOLE_H */
