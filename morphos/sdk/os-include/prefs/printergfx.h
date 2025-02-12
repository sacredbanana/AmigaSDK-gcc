#ifndef PREFS_PRINTERGFX_H
#define PREFS_PRINTERGFX_H

/*
	printer graphics prefs definitions

	Copyright � 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#pragma pack(2)


#define ID_PGFX  MAKE_ID('P','G','F','X')


struct PrinterGfxPrefs
{
	LONG  pg_Reserved[4];
	UWORD pg_Aspect;
	UWORD pg_Shade;
	UWORD pg_Image;
	WORD  pg_Threshold;
	UBYTE pg_ColorCorrect;
	UBYTE pg_Dimensions;
	UBYTE pg_Dithering;
	UWORD pg_GraphicFlags;
	UBYTE pg_PrintDensity;
	UWORD pg_PrintMaxWidth;
	UWORD pg_PrintMaxHeight;
	UBYTE pg_PrintXOffset;
	UBYTE pg_PrintYOffset;
};


#define PA_HORIZONTAL  0
#define PA_VERTICAL    1


#define PS_BW           0
#define PS_GREYSCALE    1
#define PS_COLOR        2
#define PS_GREY_SCALE2  3


#define PI_POSITIVE  0
#define PI_NEGATIVE  1


#define PCCB_RED    0
#define PCCB_GREEN  1
#define PCCB_BLUE   2

#define PCCF_RED    (1<<PCCB_RED)
#define PCCF_GREEN  (1<<PCCB_GREEN)
#define PCCF_BLUE   (1<<PCCB_BLUE)


#define PD_IGNORE    0
#define PD_BOUNDED   1
#define PD_ABSOLUTE  2
#define PD_PIXEL     3
#define PD_MULTIPLY  4


#define PD_ORDERED   0
#define PD_HALFTONE  1
#define PD_FLOYD     2


#define PGFB_CENTER_IMAGE     0
#define PGFB_INTEGER_SCALING  1
#define PGFB_ANTI_ALIAS       2

#define PGFF_CENTER_IMAGE     (1<<PGFB_CENTER_IMAGE)
#define PGFF_INTEGER_SCALING  (1<<PGFB_INTEGER_SCALING)
#define PGFF_ANTI_ALIAS       (1<<PGFB_ANTI_ALIAS)


#pragma pack()

#endif /* PREFS_PRINTERGFX_H */
