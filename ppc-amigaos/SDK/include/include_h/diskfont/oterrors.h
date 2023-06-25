#ifndef DISKFONT_OTERRORS_H
#define DISKFONT_OTERRORS_H
/*
**    $VER: oterrors.h 54.16 (22.08.2022)
**
**    error results from outline libraries AKA font engines
**
**    Copyright (C) 1991-1992 Robert R. Burns
**        All Rights Reserved
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

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

/* PRELIMINARY */
#define OTERR_Failure      -1 /* catch-all for error */
#define OTERR_Success       0 /* no error */
#define OTERR_BadTag        1 /* inappropriate tag for function */
#define OTERR_UnknownTag    2 /* unknown tag for function */
#define OTERR_BadData       3 /* catch-all for bad tag data */
#define OTERR_NoMemory      4 /* insufficient memory for operation */
#define OTERR_NoFace        5 /* no typeface currently specified */
#define OTERR_BadFace       6 /* typeface specification problem */
#define OTERR_NoGlyph       7 /* no glyph specified */
#define OTERR_BadGlyph      8 /* bad glyph code or glyph range */
#define OTERR_NoShear       9 /* shear only partially specified */
#define OTERR_NoRotate     10 /* rotate only partially specified */
#define OTERR_TooSmall     11 /* typeface metrics yield tiny glyphs */
#define OTERR_UnknownGlyph 12 /* glyph not known by engine */

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

#endif /* DISKFONT_OTERRORS_H */
