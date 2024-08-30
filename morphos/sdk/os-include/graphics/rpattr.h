#ifndef GRAPHICS_RPATTR_H
#define GRAPHICS_RPATTR_H

/*
	graphics Set/GetRPAttr definitions (V51)

	Copyright © 2012 The MorphOS Development Team, All Rights Reserved.
*/


#define RPTAG_Font        0x80000000
#define RPTAG_APen        0x80000002
#define RPTAG_BPen        0x80000003
#define RPTAG_DrMd        0x80000004
#define RPTAG_OutLinePen  0x80000005
#define RPTAG_OutlinePen  0x80000005
#define RPTAG_WriteMask   0x80000006
#define RPTAG_MaxPen      0x80000007

#define RPTAG_DrawBounds  0x80000008

/*** V50 ***/

#define RPTAG_PenMode     0x80000080    /* Enable/Disable PenMode (Defaults to TRUE) */
#define RPTAG_FgColor     0x80000081    /* 32bit Foreground Color used when PenMode is FALSE */
#define RPTAG_BgColor     0x80000082    /* 32bit Background Color used when PenMode is FALSE */

#define RPTAG_AlphaMode   0x80000083    /* (NYI) Enable/Disable AlphaMode (Defaults to FALSE) */
					/* Can only work when PenMode is disabled */
#define RPTAG_RetainAlpha 0x80000084    /* (NYI) Retain target Alpha channel if TRUE (Defaults to FALSE) */
					/* Only makes sense for target formats with alpha channel */
/*** V51.13 (MorphOS 3) ***/

#define RPTAG_XPos        0x80000085    /* Graphics pen X position */
#define RPTAG_YPos        0x80000086    /* Graphics pen Y position */

#endif /* GRAPHICS_RPATTR_H */
