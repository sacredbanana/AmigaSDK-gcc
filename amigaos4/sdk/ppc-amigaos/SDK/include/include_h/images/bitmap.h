#ifndef IMAGES_BITMAP_H
#define IMAGES_BITMAP_H
/*
**    $VER: bitmap.h 54.16 (22.08.2022)
**
**    Definitions for the bitmap.image BOOPSI class
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef   INTUITION_IMAGECLASS_H
#include <intuition/imageclass.h>
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

/*****************************************************************************/

#define BITMAP_Dummy              (REACTION_Dummy + 0x19000)

/*****************************************************************************/

/* Additional attributes defined by the bitmap class
 */

#define BITMAP_SourceFile         (BITMAP_Dummy + 1)
    /* (STRPTR) Filename of datatype object */

#define BITMAP_Screen             (BITMAP_Dummy + 2)
    /* (struct Screen *) Screen to remap the datatype image to */

#define BITMAP_Precision          (BITMAP_Dummy + 3)
    /* (ULONG) OBP_PRECISION to use in remapping */

#define BITMAP_Masking            (BITMAP_Dummy + 4)
    /* (BOOL) Draw image with transparent background if a mask or an alpha
       channel is available */

#define BITMAP_BitMap             (BITMAP_Dummy + 5)
    /* (struct BitMap *) Ready-to-use bitmap */

#define BITMAP_Width              (BITMAP_Dummy + 6)
    /* (LONG) Width of bitmap */

#define BITMAP_Height             (BITMAP_Dummy + 7)
    /* (LONG) Height of bitmap */

#define BITMAP_MaskPlane          (BITMAP_Dummy + 8)
    /* (APTR) Masking plane */

#define BITMAP_SelectSourceFile   (BITMAP_Dummy + 9)
    /* (STRPTR) Filename for "selected state" picture */

#define BITMAP_SelectBitMap       (BITMAP_Dummy + 10)
    /* (struct BitMap *) Bitmap for "selected state" */

#define BITMAP_SelectWidth        (BITMAP_Dummy + 11)
    /* (LONG) Width of "selected state" bitmap */

#define BITMAP_SelectHeight       (BITMAP_Dummy + 12)
    /* (LONG) Height of "selected state" bitmap */

#define BITMAP_SelectMaskPlane    (BITMAP_Dummy + 13)
    /* (APTR) Masking plane for "selected state" */

#define BITMAP_OffsetX            (BITMAP_Dummy + 14)
    /* (LONG) Left offset in (passed by application) bitmap */

#define BITMAP_OffsetY            (BITMAP_Dummy + 15)
    /* (LONG) Top offset in (passed by application) bitmap */

#define BITMAP_SelectOffsetX      (BITMAP_Dummy + 16)
    /* (LONG) Left offset in (passed by application) "selected state" bitmap */

#define BITMAP_SelectOffsetY      (BITMAP_Dummy + 17)
    /* (LONG) Top offset in (passed by application) "selected state" bitmap */

#define BITMAP_Transparent        (BITMAP_Dummy + 18)
    /* (BOOL) Make color zero transparent if no mask is available */

#define BITMAP_DisabledSourceFile (BITMAP_Dummy + 19)
    /* (STRPTR) Filename for "disabled state" picture (V51) */

#define BITMAP_DisabledBitMap     (BITMAP_Dummy + 20)
    /* (struct BitMap *) Bitmap for "disabled state" (V51) */

#define BITMAP_DisabledWidth      (BITMAP_Dummy + 21)
    /* (LONG) Width of "disabled state" bitmap (V51) */

#define BITMAP_DisabledHeight     (BITMAP_Dummy + 22)
    /* (LONG) Height of "disabled state" bitmap (V51) */

#define BITMAP_DisabledMaskPlane  (BITMAP_Dummy + 23)
    /* (APTR) Masking plane for "disabled state" (V51) */

#define BITMAP_DisabledOffsetX    (BITMAP_Dummy + 24)
    /* (LONG) Left offset in (passed by application) "disabled state"
       bitmap (V51) */

#define BITMAP_DisabledOffsetY    (BITMAP_Dummy + 25)
    /* (LONG) Top offset in (passed by application) "disabled state"
       bitmap (V51) */

#define BITMAP_HasAlpha           (BITMAP_Dummy + 26)
    /* (BOOL) Use the alpha channel embedded in the bitmaps supplied by
       the caller (if any); requires BITMAP_Masking to be TRUE as well.
       Don't pass this if the bitmaps are loaded from disk (V53) */

#define BITMAP_AlphaBitMap        (BITMAP_Dummy + 27)
    /* (struct BitMap *) Chunky 8-bit bitmap (in RGBFB_ALPHA8 format)
       defining the alpha channel for the "normal state" bitmap, to be
       used if BITMAP_Masking is TRUE. Overrides BITMAP_HasAlpha.
       Don't pass this if the normal bitmap is loaded from disk (V53) */

#define BITMAP_SelectAlphaBitMap  (BITMAP_Dummy + 28)
    /* (struct BitMap *) Chunky 8-bit bitmap (in RGBFB_ALPHA8 format)
       defining the alpha channel for the "selected state" bitmap, to be
       used if BITMAP_Masking is TRUE. Overrides BITMAP_HasAlpha.
       Don't pass this if the selected bitmap is loaded from disk (V53) */

#define BITMAP_DisabledAlphaBitMap (BITMAP_Dummy + 29)
    /* (struct BitMap *) Chunky 8-bit bitmap (in RGBFB_ALPHA8 format)
       defining the alpha channel for the "disabled state" bitmap, to be
       used if BITMAP_Masking is TRUE. Overrides BITMAP_HasAlpha.
       Don't pass this if the disabled bitmap is loaded from disk (V53) */

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

#endif /* IMAGES_BITMAP_H */
