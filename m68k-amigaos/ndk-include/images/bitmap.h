#ifndef IMAGES_BITMAP_H
#define IMAGES_BITMAP_H
/*
**	$VER: bitmap.h 47.3 (12.7.2021)
**
**	Definitions for the bitmap.image BOOPSI class
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef INTUITION_IMAGECLASS_H
#include <intuition/imageclass.h>
#endif

/*****************************************************************************/

#define BITMAP_Dummy		   (REACTION_Dummy + 0x19000)

/*****************************************************************************/

/* Additional attributes defined by the bitmap class
 */

#define BITMAP_SourceFile        (BITMAP_Dummy + 1)
   /* (STRPTR) Filename of datatype object */

#define BITMAP_Screen            (BITMAP_Dummy + 2)
   /* (struct Screen *) Screen to remap the datatype image to */

#define BITMAP_Precision         (BITMAP_Dummy + 3)
   /* (ULONG) OBP_PRECISION to use in remapping */

#define BITMAP_Masking           (BITMAP_Dummy + 4)
   /* (BOOL) Mask image */

#define BITMAP_BitMap            (BITMAP_Dummy + 5)
   /* (struct BitMap *) Ready-to-use bitmap */

#define BITMAP_Width             (BITMAP_Dummy + 6)
   /* (LONG) Width of bitmap */

#define BITMAP_Height            (BITMAP_Dummy + 7)
   /* (LONG) Height of bitmap */

#define BITMAP_MaskPlane         (BITMAP_Dummy + 8)
   /* (APTR) Masking plane */

#define BITMAP_SelectSourceFile  (BITMAP_Dummy + 9)
   /* (STRPTR) */

#define BITMAP_SelectBitMap      (BITMAP_Dummy + 10)
   /* (struct BitMap */

#define BITMAP_SelectWidth       (BITMAP_Dummy + 11)
   /* (LONG) */

#define BITMAP_SelectHeight      (BITMAP_Dummy + 12)
   /* (LONG) */

#define BITMAP_SelectMaskPlane   (BITMAP_Dummy + 13)
   /* (APTR) */

#define BITMAP_OffsetX           (BITMAP_Dummy + 14)
   /* (LONG) */

#define BITMAP_OffsetY           (BITMAP_Dummy + 15)
   /* (LONG) */

#define BITMAP_SelectOffsetX     (BITMAP_Dummy + 16)
   /* (LONG) */

#define BITMAP_SelectOffsetY     (BITMAP_Dummy + 17)
   /* (LONG) */

#define BITMAP_Transparent       (BITMAP_Dummy + 18)
   /* (BOOL) Make color zero transparent if no mask is available */

#define BITMAP_DisabledSourceFile  (BITMAP_Dummy + 19) /* OS4ONLY */

#define BITMAP_DisabledBitMap      (BITMAP_Dummy + 20) /* OS4ONLY */

#define BITMAP_DisabledWidth       (BITMAP_Dummy + 21) /* OS4ONLY */

#define BITMAP_DisabledHeight      (BITMAP_Dummy + 22) /* OS4ONLY */

#define BITMAP_DisabledMaskPlane   (BITMAP_Dummy + 23) /* OS4ONLY */

#define BITMAP_DisabledOffsetX     (BITMAP_Dummy + 24) /* OS4ONLY */

#define BITMAP_DisabledOffsetY     (BITMAP_Dummy + 25) /* OS4ONLY */

#define BITMAP_HasAlpha            (BITMAP_Dummy + 26) /* OS4ONLY */

#define BITMAP_AlphaBitMap         (BITMAP_Dummy + 27) /* OS4ONLY */

#define BITMAP_SelectAlphaBitMap   (BITMAP_Dummy + 28) /* OS4ONLY */

#define BITMAP_DisabledAlphaBitMap (BITMAP_Dummy + 29) /* OS4ONLY */

/*****************************************************************************/

#endif /* IMAGES_BITMAP_H */
