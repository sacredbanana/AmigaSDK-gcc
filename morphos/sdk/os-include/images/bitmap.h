#ifndef IMAGES_BITMAP_H
#define IMAGES_BITMAP_H

/*
	bitmap.image definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_IMAGECLASS_H
# include <intuition/imageclass.h>
#endif


/* Attributes defined by bitmap.image */

#define BITMAP_Dummy             (REACTION_Dummy + 0x19000)
#define BITMAP_SourceFile        (BITMAP_Dummy + 1)
#define BITMAP_Screen            (BITMAP_Dummy + 2)
#define BITMAP_Precision         (BITMAP_Dummy + 3)
#define BITMAP_Masking           (BITMAP_Dummy + 4)
#define BITMAP_BitMap            (BITMAP_Dummy + 5)
#define BITMAP_Width             (BITMAP_Dummy + 6)
#define BITMAP_Height            (BITMAP_Dummy + 7)
#define BITMAP_MaskPlane         (BITMAP_Dummy + 8)
#define BITMAP_SelectSourceFile  (BITMAP_Dummy + 9)
#define BITMAP_SelectBitMap      (BITMAP_Dummy + 10)
#define BITMAP_SelectWidth       (BITMAP_Dummy + 11)
#define BITMAP_SelectHeight      (BITMAP_Dummy + 12)
#define BITMAP_SelectMaskPlane   (BITMAP_Dummy + 13)
#define BITMAP_OffsetX           (BITMAP_Dummy + 14)
#define BITMAP_OffsetY           (BITMAP_Dummy + 15)
#define BITMAP_SelectOffsetX     (BITMAP_Dummy + 16)
#define BITMAP_SelectOffsetY     (BITMAP_Dummy + 17)


#endif /* IMAGES_BITMAP_H */
