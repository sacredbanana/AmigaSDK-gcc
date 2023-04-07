#ifndef PREFS_FONT_H
#define PREFS_FONT_H
/*
**	$VER: font.h 47.2 (17.02.2020)
**
**	File format for font preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#ifndef GRAPHICS_TEXT_H
#include <graphics/text.h>
#endif


/*****************************************************************************/


#define ID_FONT MAKE_ID('F','O','N','T')


#define FONTNAMESIZE (128)

struct FontPrefs
{
    LONG	    fp_Reserved[3];
    UWORD	    fp_Reserved2;
    UWORD	    fp_Type;
    UBYTE	    fp_FrontPen;
    UBYTE	    fp_BackPen;
    UBYTE	    fp_DrawMode;
    UBYTE	    fp_SpecialDrawMode;
    struct TextAttr fp_TextAttr;
    BYTE	    fp_Name[FONTNAMESIZE];
};


/* constants for FontPrefs.fp_Type */
#define FP_WBFONT     0
#define FP_SYSFONT    1
#define FP_SCREENFONT 2


/*****************************************************************************/


#endif /* PREFS_FONT_H */
