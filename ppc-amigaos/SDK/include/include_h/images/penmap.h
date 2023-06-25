#ifndef IMAGES_PENMAP_H
#define IMAGES_PENMAP_H
/*
**    $VER: penmap.h 54.16 (22.08.2022)
**
**    Definitions for the penmap.image BOOPSI class
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

/* Additional attributes defined by penmap.image */
#define PENMAP_Dummy            (REACTION_Dummy + 0x18000)

#define PENMAP_SelectBGPen      (PENMAP_Dummy + 1)
    /* (WORD) Selected render background pen. */

#define PENMAP_SelectData       (PENMAP_Dummy + 2)
    /* () Optional renderng data for mode IDS_SELECTED. */

#define PENMAP_RenderBGPen      IA_BGPen
    /* (WORD) Background pen. */

#define PENMAP_RenderData       IA_Data
    /* () rendering data for mode IDS_NORMAL. */

#define PENMAP_Palette          (PENMAP_Dummy + 3)
    /* () OM_NEW/OM_SET/OM_GET palette data. */

#define PENMAP_Screen           (PENMAP_Dummy + 4)
    /* (struct Screen *) Screen this penmap will be displayed in. */

#define PENMAP_ImageType        (PENMAP_Dummy + 5)
    /* (UWORD) Currently Unsupported. */

#define PENMAP_Transparent      (PENMAP_Dummy + 6)
    /* (UWORD) OM_NEW/OM_SET - If set, color entry 0 will map
     * to screen/window background pen. */

#define PENMAP_Precision        (PENMAP_Dummy + 8)
    /* (UWORD) OM_NEW/OM_SET -ObtainBestPen precision,
       defaults to PRECISION_IMAGE */

#define PENMAP_ColorMap         (PENMAP_Dummy + 9)
    /* (struct ColorMap *) OM_NEW/OM_SET - ColorMap to use
       when remapping pens */

#define PENMAP_MaskBlit         (PENMAP_Dummy + 10)
    /* (BOOL) Blit image using blitmask for true transparancy, recommended
       when a penmap is used in a layout group for a logo, allowing the
       backfill to show thru/around the image. Penmap will automatically
       create the required mask plane for you. */

#define PENMAP_Compressed       (PENMAP_Dummy + 11)
    /* (ULONG) Compression type used for image data (V50).
       Supported are: cmpNone (default), cmpByteRun1 */

#define PENMAP_MaskPlane        (PENMAP_Dummy + 12)
    /* (uint8*) Mask plane generated when PENMAP_MaskBlit is TRUE. (V53.3) */

#define PENMAP_SelectMaskPlane  (PENMAP_Dummy + 13)
    /* (uint8*) Mask plane generated when PENMAP_MaskBlit is TRUE. (V53.3) */

/*****************************************************************************/

/* Definitions for PENMAP_ImageType
 */
#define IMAGE_CHUNKY   0 /* Supported Default */
#define IMAGE_IMAGE    1 /* Currently unsupported. */
#define IMAGE_DRAWLIST 2 /* Currently unsupported. */

/* Macros to extract the source width and height data.
 */
#ifndef IMAGE_WIDTH
#define IMAGE_WIDTH(i)  (((UWORD *)(i))[0])
#endif
#ifndef IMAGE_HEIGHT
#define IMAGE_HEIGHT(i) (((UWORD *)(i))[1])
#endif

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

#endif /* IMAGES_PENMAP_H */
