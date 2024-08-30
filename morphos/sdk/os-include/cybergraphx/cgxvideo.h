/*
**	$VER: cgxvideo.h 43.17 (5.03.2021)
**
**	include file for cgxvideo.library
**
**	Copyright © 1996-1998 by phase5 digital products
**	Copyright © 1999-2008 by Vision Factory Development
**	Copyright © 2009-2021 by MorphOS Team/VFD 
**
**	All Rights reserved.
**
*/

#ifndef LIBRARIES_CGXVIDEO_H
#define LIBRARIES_CGXVIDEO_H

#include <exec/types.h>

struct VLayerHandle;


#define VOA_LeftIndent    0x88000001
#define VOA_RightIndent   0x88000002
#define VOA_TopIndent     0x88000003
#define VOA_BottomIndent  0x88000004

#define VOA_SrcType       0x88000005
#define VOA_SrcWidth      0x88000006
#define VOA_SrcHeight     0x88000007

#define VOA_Error         0x88000008

#define VOA_UseColorKey   0x88000009

#define VOA_UseBackfill   0x8800000a

#define VOA_UseFilter     0x8800000c

#define VOA_BaseAddress   0x88000030
#define VOA_ColorKeyPen   0x88000031
#define VOA_ColorKey      0x88000032

/* v42 additions */
#define VOA_Identifier    0x8800000b

#define VOA_FrameBase0    0x88000033
#define VOA_FrameBase1    0x88000034
#define VOA_FrameType     0x88000035

#define VOA_Width         0x88000036
#define VOA_Height        0x88000037
#define VOA_Modulo        0x88000038      /* may be specified by CreateVLayerTagList() for v43 */

/* V43 additions */

#define VOA_DoubleBuffer  0x8800000d
#define VOA_InterLaced    0x8800000e
#define VOA_CaptureMode   0x8800000f

#define VOA_BaseOffset    0x88000039

/* V50 additions */

#define VOA_FrameIndex    0x88000010
#define VOA_MultiBuffer   0x88000011
#define VOA_ZoomRect      0x88000012

#define VOA_BaseOffset0   0x88000040
#define VOA_BaseOffset1   0x88000041
#define VOA_BaseOffset2   0x88000042
#define VOA_BaseOffset3   0x88000043
#define VOA_BaseOffset4   0x88000044
#define VOA_BaseOffset5   0x88000045


#define VOA_Color0SP            0x88000050
#define VOA_Color1SP            0x88000051
#define VOA_Color2SP            0x88000052
#define VOA_Color3SP            0x88000053
#define VOA_Color4SP            0x88000054
#define VOA_Color5SP            0x88000055
#define VOA_Color6SP            0x88000056
#define VOA_Color7SP            0x88000057
#define VOA_Color8SP            0x88000058
#define VOA_Color9SP            0x88000059
#define VOA_Color10SP           0x8800005A
#define VOA_Color11SP           0x8800005B
#define VOA_Color12SP           0x8800005C
#define VOA_Color13SP           0x8800005D
#define VOA_Color14SP           0x8800005E
#define VOA_Color15SP           0x8800005F

#define VOA_SubPicture          0x88000060
#define VOA_EnableSP            0x88000061
#define VOA_StreamRectSP        0x88000062
#define VOA_ColConSP            0x88000063
#define VOA_HLEnableSP          0x88000065
#define VOA_HLRectSP            0x88000064
#define VOA_HLColConSP          0x88000066
#define VOA_SrcWidthSP          0x88000067
#define VOA_SrcHeightSP         0x88000068

#define VOA_ColorKeyFill        0x88000070

#define VSQ_Dummy               (TAG_USER + 0xA5000)
#define VSQ_SupportedFeatures   (VSQ_Dummy + 1UL)

#define VSQ_FEAT_OVERLAY        (1UL << 0)
#define VSQ_FEAT_DOUBLEBUFFER   (1UL << 1)
#define VSQ_FEAT_MULTIBUFFER    (1UL << 2)
#define VSQ_FEAT_COLORKEYING    (1UL << 3)
#define VSQ_FEAT_FILTERING      (1UL << 4)
#define VSQ_FEAT_CAPTUREMODE    (1UL << 5)
#define VSQ_FEAT_INTERLACE      (1UL << 6)
#define VSQ_FEAT_ZOOMRECT       (1UL << 7)
#define VSQ_FEAT_SUBPICTURE     (1UL << 8)

#define VSQ_SupportedFormats    (VSQ_Dummy + 2UL)

#define VSQ_FMT_YUYV            (1UL << 0)
#define VSQ_FMT_R5G5B5_LE       (1UL << 1)
#define VSQ_FMT_R5G6B5_LE       (1UL << 2)
#define VSQ_FMT_YUV420_PLANAR   (1UL << 3)

#define VSQ_MaxWidth            (VSQ_Dummy + 3UL)       /* will return maximum width for overlay */

#define VSQ_MaxWidthSP          (VSQ_Dummy + 4UL)       /* will return maximum width for subpicture */

/* possible errors returned with VOA_Error tag */

#define VOERR_OK                0       /* No error */
#define VOERR_INVSCRMODE        1       /* video overlay not possible for that mode */
#define VOERR_NOOVLMEMORY       2       /* No memory for video overlay */
#define VOERR_INVSRCFMT         3       /* Source format not supported */
#define VOERR_NOMEMORY          4       /* Not enough memory */

/* Source data types              */
/* see cgxvideo.doc for more info */

#define SRCFMT_YUV16    0       /* obsolete */
#define SRCFMT_YCbCr16  1
#define SRCFMT_RGB15    2       /* this format is actually byte swapped */
#define SRCFMT_R5G5B5PC 2
#define SRCFMT_RGB16    3       /* this format is actually byte swapped */
#define SRCFMT_R5G6B5PC 3
#define SRCFMT_YCbCr420 4       /* YUV planar */

#endif /* LIBRARIES_CGXVIDEO_H */
