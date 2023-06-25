#ifndef IMAGES_FILLER_H
#define IMAGES_FILLER_H
/*
**    $VER: filler.h 54.16 (22.08.2022)
**
**    Definitions for the Filler BOOPSI class
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef   INTUITION_GADGETCLASS_H
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

/* image placement adjustment flags. (default is to centre image.)
 */
#define FILLER_PLACEMENT_LEFT   1 /* takes priority over
                                     FILLER_PLACEMENT_RIGHT */
#define FILLER_PLACEMENT_RIGHT  2
#define FILLER_PLACEMENT_TOP    4 /* takes priority over
                                     FILLER_PLACEMENT_BOTTOM */
#define FILLER_PLACEMENT_BOTTOM 8

/*****************************************************************************/

/* image mode flags.
 */
#define FILLER_MODE_NORMAL  0 /* single image (default) */
#define FILLER_MODE_SCALED  1 /* image scaled to fill entire area */
#define FILLER_MODE_CONTAIN 2 /* image scaled to maximum size possible
                                 within area, maintaining aspect ratio */
#define FILLER_MODE_FIT     3 /* image scaled to fill entire area,
                                 maintaining aspect ratio */
#define FILLER_MODE_TILED   4 /* image is tiled across entire area */

/*****************************************************************************/

/* scale mode flags.
 */
#define FILLER_SCALE_SIMPLE   0 /* nearest pixel (default) */
#define FILLER_SCALE_BILINEAR 1 /* bilinear */

/*****************************************************************************/

/* Additional attributes defined by the Filler class
 */
#define FILLER_Dummy             (REACTION_Dummy+0x0006666)

#define FILLER_Screen            (FILLER_Dummy+1)
   /* (struct Screen *) Screen for pen allocation (default: None)
      (OM_NEW, OM_SET) */

#define FILLER_BackgroundColour  (FILLER_Dummy+2)
#define FILLER_BackgroundColor   FILLER_BackgroundColour
   /* (uint32) Background fill ARGB colour (default: 0 (transparent))
      (OM_NEW, OM_SET) */

#define FILLER_ImageFilename     (FILLER_Dummy+3)
   /* (STRPTR) File to load as image. (OM_NEW, OM_SET) */

#define FILLER_TopLeftColour     (FILLER_Dummy+4)
#define FILLER_TopRightColour    (FILLER_Dummy+5)
#define FILLER_BottomLeftColour  (FILLER_Dummy+6)
#define FILLER_BottomRightColour (FILLER_Dummy+7)
#define FILLER_TopLeftColor      FILLER_TopLeftColour
#define FILLER_TopRightColor     FILLER_TopRightColour
#define FILLER_BottomLeftColor   FILLER_BottomLeftColour
#define FILLER_BottomRightColor  FILLER_BottomRightColour
   /* (uint32) Four ARGB colours used to render gradient over area
      (default: 0 (transparent)) (OM_NEW, OM_SET) */

#define FILLER_ImageMode         (FILLER_Dummy+8)
   /* (uint32) The image mode, see above flags. (OM_NEW, OM_SET) */

#define FILLER_ImagePlacement    (FILLER_Dummy+9)
   /* (uint32) The image placement, see above flags. (OM_NEW, OM_SET) */

#define FILLER_ImageBuffer       (FILLER_Dummy+10)
   /* (struct SizedBuffer *) Buffer to load as image. (OM_NEW, OM_SET) */

#define FILLER_ImageAddress      (FILLER_Dummy+11)
#define FILLER_ImageSize         (FILLER_Dummy+12)
   /* (APTR), (uint32) Alternative way to import an image from memory. 
      Both these attributes must be set before the image is loaded.
      Also see FILLER_ImageBuffer.
      (OM_NEW, OM_SET) */

#define FILLER_ScaleMode         (FILLER_Dummy+13)
   /* (uint32) The scale mode, see above flags. (OM_NEW, OM_SET) */

/*****************************************************************************/

/* structure required for FILLER_ImageBuffer */

struct SizedBuffer
{
   APTR   SB_Buffer;
   uint32 SB_Size;
};

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

#endif /* IMAGES_FILLER_H */
