#ifndef IMAGES_PENMAP_H
#define IMAGES_PENMAP_H

/*
	penmap.image definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_IMAGECLASS_H
# include <intuition/imageclass.h>
#endif


/* Attributes defined by penmap.image */

#define PENMAP_Dummy        (REACTION_Dummy + 0x18000)
#define PENMAP_SelectBGPen  (PENMAP_Dummy + 1)
#define PENMAP_SelectData   (PENMAP_Dummy + 2)
#define PENMAP_RenderBGPen  (IA_BGPen)
#define PENMAP_RenderData   (IA_Data)
#define PENMAP_Palette      (PENMAP_Dummy + 3)
#define PENMAP_Screen       (PENMAP_Dummy + 4)
#define PENMAP_ImageType    (PENMAP_Dummy + 5)
#define PENMAP_Transparent  (PENMAP_Dummy + 6)
#define PENMAP_Precision    (PENMAP_Dummy + 8)
#define PENMAP_ColorMap     (PENMAP_Dummy + 9)
#define PENMAP_MaskBlit     (PENMAP_Dummy + 10)


/* PENMAP_ImageType types */

#define IMAGE_CHUNKY    0
#define IMAGE_IMAGE     1
#define IMAGE_DRAWLIST  2


/* Useful macros */

#ifndef IMAGE_WIDTH
# define IMAGE_WIDTH(i)  (((UWORD *)(i))[0])
#endif

#ifndef IMAGE_HEIGHT
# define IMAGE_HEIGHT(i)  (((UWORD *)(i))[1])
#endif


#endif /* IMAGES_PENMAP_H */
