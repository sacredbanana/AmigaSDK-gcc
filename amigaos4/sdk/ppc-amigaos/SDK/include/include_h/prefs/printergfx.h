#ifndef PREFS_PRINTERGFX_H
#define PREFS_PRINTERGFX_H
/*
**    $VER: printergfx.h 54.16 (22.08.2022)
**
**    File format for graphics printer preferences
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
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

#define ID_PGFX MAKE_ID('P','G','F','X')

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
    UBYTE pg_PrintDensity;   /* Print density 1 - 7 */
    UWORD pg_PrintMaxWidth;
    UWORD pg_PrintMaxHeight;
    UBYTE pg_PrintXOffset;
    UBYTE pg_PrintYOffset;
};

/* constants for PrinterGfxPrefs.pg_Aspect */
#define PA_HORIZONTAL 0
#define PA_VERTICAL   1

/* constants for PrinterGfxPrefs.pg_Shade */
#define PS_BW          0
#define PS_GREYSCALE   1
#define PS_COLOR       2
#define PS_GREY_SCALE2 3

/* constants for PrinterGfxPrefs.pg_Image */
#define PI_POSITIVE 0
#define PI_NEGATIVE 1

/* flags for PrinterGfxPrefs.pg_ColorCorrect */
#define PCCB_RED   1 /* color correct red shades   */
#define PCCB_GREEN 2 /* color correct green shades */
#define PCCB_BLUE  3 /* color correct blue shades  */

#define PCCF_RED   (1<<0)
#define PCCF_GREEN (1<<1)
#define PCCF_BLUE  (1<<2)

/* constants for PrinterGfxPrefs.pg_Dimensions */
#define PD_IGNORE   0 /* ignore max width/height settings */
#define PD_BOUNDED  1 /* use max w/h as boundaries        */
#define PD_ABSOLUTE 2 /* use max w/h as absolutes         */
#define PD_PIXEL    3 /* use max w/h as prt pixels        */
#define PD_MULTIPLY 4 /* use max w/h as multipliers       */

/* constants for PrinterGfxPrefs.pg_Dithering */
#define PD_ORDERED  0 /* ordered dithering         */
#define PD_HALFTONE 1 /* halftone dithering        */
#define PD_FLOYD    2 /* Floyd-Steinberg dithering */

/* flags for PrinterGfxPrefs.pg_GraphicsFlags */
#define PGFB_CENTER_IMAGE    0 /* center image on paper */
#define PGFB_INTEGER_SCALING 1 /* force integer scaling */
#define PGFB_ANTI_ALIAS      2 /* anti-alias image      */

#define PGFF_CENTER_IMAGE    (1<<0)
#define PGFF_INTEGER_SCALING (1<<1)
#define PGFF_ANTI_ALIAS      (1<<2)

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

#endif /* PREFS_PRINTERGFX_H */
