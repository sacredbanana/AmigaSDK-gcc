#ifndef PREFS_FONT_H
#define PREFS_FONT_H
/*
**    $VER: font.h 54.16 (22.08.2022)
**
**    File format for font preferences
**
**    Copyright (C) 1985-2007 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#ifndef   GRAPHICS_TEXT_H
#include <graphics/text.h>
#endif

/*****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

#define ID_FONT MAKE_ID('F','O','N','T')

#define FONTNAMESIZE (128)

struct FontPrefs
{
    LONG            fp_Reserved[3];
    UWORD           fp_Reserved2;
    UWORD           fp_Type;
    UBYTE           fp_FrontPen;
    UBYTE           fp_BackPen;
    UBYTE           fp_DrawMode;
    UBYTE           fp_SpecialDrawMode;
    struct TextAttr fp_TextAttr;
    TEXT            fp_Name[FONTNAMESIZE];
};

/* constants for FontPrefs.fp_Type */
#define FP_WBFONT     0
#define FP_SYSFONT    1
#define FP_SCREENFONT 2
#define FP_DRAWERFONT 3  /* New for V52 */
#define FP_TEXTFONT   4  /* New for V52 */

/*****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* PREFS_FONT_H */
