#ifndef DISKFONT_GLYPH_H
#define DISKFONT_GLYPH_H
/*
**    $VER: glyph.h 54.16 (22.08.2022)
**
**    structures for glyph libraries AKA font engines
**
**    Copyright (C) 1991-1992 Robert R. Burns
**        All Rights Reserved
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

/****************************************************************************/

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

/* A GlyphEngine must be acquired via OpenEngine and is read-only */
struct GlyphEngine
{
    struct Library *gle_Library; /* engine library */
    char *          gle_Name;    /* library basename: e.g. "bullet" */

    /* private library data follows... */
};

typedef LONG FIXED; /* 32 bit signed w/ 16 bits of fraction */

struct GlyphMap
{
    UWORD  glm_BMModulo;    /* # of bytes in row: always multiple of 4 */
    UWORD  glm_BMRows;      /* # of rows in bitmap */
    UWORD  glm_BlackLeft;   /* # of blank pixel columns at left */
    UWORD  glm_BlackTop;    /* # of blank rows at top */
    UWORD  glm_BlackWidth;  /* span of contiguous non-blank columns */
    UWORD  glm_BlackHeight; /* span of contiguous non-blank rows */
    FIXED  glm_XOrigin;     /* distance from upper left corner of bitmap */
    FIXED  glm_YOrigin;     /*   to initial CP, in fractional pixels */
    WORD   glm_X0;          /* approximation of XOrigin in whole pixels */
    WORD   glm_Y0;          /* approximation of YOrigin in whole pixels */
    WORD   glm_X1;          /* approximation of XOrigin + Width */
    WORD   glm_Y1;          /* approximation of YOrigin + Width */
    FIXED  glm_Width;       /* character advance, as fraction of em width */
    UBYTE *glm_BitMap;      /* actual glyph bitmap */
};

struct GlyphWidthEntry
{
    struct MinNode gwe_Node;  /* on list returned by OT_WidthList inquiry */
    UWORD          gwe_Code;  /* entry's character code value */
    FIXED          gwe_Width; /* character advance, as fraction of em width */
};

/* Structure returned when asking for OT_WidthList32,
 * the original GlyphWidthEntry structure is limited to
 * 16 bit glyph code (UWORD gwe_Code).
 */
struct GlyphWidthEntry32
{
    struct MinNode gwe32_Node;     /* on list returned by OT_WidthList32 inquiry */
    UWORD          gwe32_reserved; /* for alignment and backwards compatibility */
    FIXED          gwe32_Width;    /* character advance, as fraction of em width */
    ULONG          gwe32_Code;     /* entry's character code value */
};

/****************************************************************************/

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

#endif /* DISKFONT_GLYPH_H */
