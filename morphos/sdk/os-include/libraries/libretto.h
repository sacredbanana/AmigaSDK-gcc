/* $VER: libretto.h 0.1 (26.01.2015) (c) 2015 Grzegorz Kraszewski. */

#ifndef LIBRARIES_LIBRETTO_H
#define LIBRARIES_LIBRETTO_H

#include <exec/types.h>
#include <utility/tagitem.h>
#include <intuition/classusr.h>

#define LIBRETTONAME "libretto.library"
#define LIBRETTOVERSION 0
#define LIBRETTOMINVERSION 0


/* Tags */

#define LTTA_FontFamily                (TAG_USER + 1)    // nullterminated ASCII string
#define LTTA_MetricsUnit               (TAG_USER + 2)    // enumerated units
#define LTTA_Text                      (TAG_USER + 3)    // text to be rendered, APTR
#define LTTA_Length                    (TAG_USER + 4)    // number of characters to process
#define LTTA_Target                    (TAG_USER + 5)    // pointer to target object, or target "data"
#define LTTA_Width                     (TAG_USER + 6)    // for not selfdescribing targets
#define LTTA_Height                    (TAG_USER + 7)    // for not selfdescribing targets
#define LTTA_ByteModulo                (TAG_USER + 8)    // for not selfdescribing targets
#define LTTA_Color                     (TAG_USER + 9)    // ARGB32 color of text


/* Special values */

#define LTTV_Pixels                    1                 // font metrics unit

#define LTTV_MonoRaster                1                 // monochrome raster
#define LTTV_GrayRaster                2                 // 8-bit grayscale raster

/* DrawTarget types */

#define LT_Target_RastPort             1
#define LT_Target_ArrayARGB32          2

/*
  Structure for text sizing
  Notes:
    1. Box width is Right - Left.
    2. Box height is Bottom - Top.
*/

struct LtExtent
{
	LONG Top;                          // top of the box relative to the origin (usually negative)
	LONG Bottom;                       // bottom of the box relative to the origin (usually positive)
	LONG Left;                         // left edge of box relative to the origin (often zero, sometimes negative)
	LONG Right;                        // right edge of box relative to the origin (usually positive)
	LONG AdvanceH;                     // horizontal advance of the origin (usually positive)
	LONG AdvanceV;                     // vertical advance of the origin (usually zero)
};


#endif   /* LIBRARIES_LIBRETTO_H */
