#ifndef PREFS_FONT_H
#define PREFS_FONT_H

/*
	font prefs definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#ifndef GRAPHICS_TEXT_H
# include <graphics/text.h>
#endif

#pragma pack(2)


#define ID_FONT  MAKE_ID('F','O','N','T')

#define FONTNAMESIZE  (128)


struct FontPrefs
{
	LONG            fp_Reserved[3];
	UWORD           fp_Reserved2;
	UWORD           fp_Type;
	UBYTE           fp_FrontPen;
	UBYTE           fp_BackPen;
	UBYTE           fp_DrawMode;
	struct TextAttr fp_TextAttr;
	BYTE            fp_Name[FONTNAMESIZE];
};


#define FP_WBFONT      0
#define FP_SYSFONT     1
#define FP_SCREENFONT  2


#pragma pack()

#endif /* PREFS_FONT_H */
