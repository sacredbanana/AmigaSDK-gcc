#ifndef GRAPHICS_COMPOSITE_H
#define GRAPHICS_COMPOSITE_H
/*
**    $VER: composite.h 54.16 (22.08.2022)
**
**    Porter/Duff Image Composition
**
**    Copyright (C) 2008 Hans-Joerg Frieden.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

/****************************************************************************/

enum enPDOperator
{
	COMPOSITE_Clear				=	0,
	COMPOSITE_Src				=	1,
	COMPOSITE_Dest				=	2,
	COMPOSITE_Src_Over_Dest		=	3,
	COMPOSITE_Dest_Over_Src		=	4,
	COMPOSITE_Src_In_Dest		=	5,
	COMPOSITE_Dest_In_Src		=	6,
	COMPOSITE_Src_Out_Dest		=	7,
	COMPOSITE_Dest_Out_Src		=	8,
	COMPOSITE_Src_Atop_Dest		=	9,
	COMPOSITE_Dest_Atop_Src		=	10,
	COMPOSITE_Src_Xor_Dest		=	11,
	COMPOSITE_Plus				=	12,
	COMPOSITE_Maximum			=   13,
	COMPOSITE_Minimum			=   14,

	COMPOSITE_NumOperators 		=	15
};

/* Tag items for the Composite call */
#define COMPTAG_Base	TAG_USER

/* (uint32) X clip coordinate on source bitmap (defaults to 0) */
#define COMPTAG_SrcX			(COMPTAG_Base + 0)

/* (uint32) Y clip coordinate on source bitmap (defaults to 0) */
#define COMPTAG_SrcY			(COMPTAG_Base + 1)

/* (uint32) Width of clip rectangle on source (defaults to full width) */
#define COMPTAG_SrcWidth		(COMPTAG_Base + 2)

/* (uint32) Height of clip rectangle on source (defaults to full height) */
#define COMPTAG_SrcHeight		(COMPTAG_Base + 3)

/* (uint32) X clip coordinate on dest bitmap (defaults to 0) */
#define COMPTAG_DestX			(COMPTAG_Base + 4)

/* (uint32) Y clip coordinate on dest bitmap (defaults to 0) */
#define COMPTAG_DestY			(COMPTAG_Base + 5)

/* (uint32) Width of clip rectangle on dest (defaults to full width) */
#define COMPTAG_DestWidth		(COMPTAG_Base + 6)

/* (uint32) Height of clip rectangle on dest (defaults to full height) */
#define COMPTAG_DestHeight		(COMPTAG_Base + 7)

/* (fixpoint) (additional) Alpha for source bitmap (no default) */
#define COMPTAG_SrcAlpha		(COMPTAG_Base + 8)

/* (fixpoint) (additional) Alpha for destination bitmap (no default) */
#define COMPTAG_DestAlpha		(COMPTAG_Base + 9)

/* (fixpoint) X scale factor for source bitmap (defaults to 1.0) */
#define COMPTAG_ScaleX			(COMPTAG_Base + 10)

/* (fixpoint) Y scale factor for source bitmap (defaults to 1.0) */
#define COMPTAG_ScaleY			(COMPTAG_Base + 11)

/* (struct Bitmap *) Alpha mask for source. Specifying this tag overrides any
 * alpha that might be present in the source bitmap.
 */
#define COMPTAG_SrcAlphaMask	(COMPTAG_Base + 12)

/* (struct Bitmap *) Alpha mask for the destination. Specifying this tag
 * overrides any alpha that might be present in the destination bitmap.
 */
#define COMPTAG_DestAlphaMask	(COMPTAG_Base + 13)

/* (uint32, see defines below) Specifies a set of flags that may modify the
 * operation. See the defines below
 */
#define COMPTAG_Flags				(COMPTAG_Base + 18)

/* (int32) X Coordinate on the destination bitmap that the operation should be
 * applied to. Defaults to zero.
 */
#define COMPTAG_OffsetX				(COMPTAG_Base + 20)

/* (int32) Y Coordinate on the destination bitmap that the operation should be
 * applied to. Defaults to zero.
 */
#define COMPTAG_OffsetY				(COMPTAG_Base + 21)

/* (struct BitMap *) when the source and/or destination bitmaps are located in
 * main memory, this tag tells the graphics system to upload the bitmaps to
 * the same board the friend bitmap is located on.
 */
#define COMPTAG_FriendBitMap		(COMPTAG_Base + 22)

/* (uint32) the same as above, but a DisplayID is used as reference to the board
 * and not a bitmap.
 */
#define COMPTAG_DisplayID			(COMPTAG_Base + 23)

/* (uint32) the X/Y coordinates on the src alpha map to use for compositing. If not
 * specified, use the same as the SrcX and SrcY
 */
#define COMPTAG_SrcAlphaX			(COMPTAG_Base + 14)
#define COMPTAG_SrcAlphaY			(COMPTAG_Base + 15)

/* (uint32) the X/Y coordinates on the destination alpha map to use. If not
 * specified, use the DestX and DestY
 */
#define COMPTAG_DestAlphaX			(COMPTAG_Base + 16)
#define COMPTAG_DestAlphaY			(COMPTAG_Base + 17)

/*
 * The following group of tag items deals with direct triangle mapping. Read the
 * autodoc for a detailed explanation
 */
#define COMPTAG_VertexArray			(COMPTAG_Base + 30)
#define COMPTAG_IndexArray			(COMPTAG_Base + 31)
#define COMPTAG_VertexFormat		(COMPTAG_Base + 32)
#define COMPTAG_NumTriangles		(COMPTAG_Base + 33)

/*
 * This group of tag items can be used to specify up to four colors, either
 * as an 32 bit ARGB value, or as a set of discreet fixpoint numbers.
 *
 * The fixpoint numbers range is 0 to 1. Specifying a fixpoint component
 * overrides the ARGB value completely.
 */
#define COMPTAG_Color0				(COMPTAG_Base + 40)
#define COMPTAG_Color1				(COMPTAG_Base + 41)
#define COMPTAG_Color2				(COMPTAG_Base + 42)
#define COMPTAG_Color3				(COMPTAG_Base + 43)

#define COMPTAG_Color0_Red			(COMPTAG_Base + 44)
#define COMPTAG_Color0_Green		(COMPTAG_Base + 45)
#define COMPTAG_Color0_Blue			(COMPTAG_Base + 46)
#define COMPTAG_Color0_Alpha		(COMPTAG_Base + 47)

#define COMPTAG_Color1_Red			(COMPTAG_Base + 48)
#define COMPTAG_Color1_Green		(COMPTAG_Base + 49)
#define COMPTAG_Color1_Blue			(COMPTAG_Base + 50)
#define COMPTAG_Color1_Alpha		(COMPTAG_Base + 51)

#define COMPTAG_Color2_Red			(COMPTAG_Base + 52)
#define COMPTAG_Color2_Green		(COMPTAG_Base + 53)
#define COMPTAG_Color2_Blue			(COMPTAG_Base + 54)
#define COMPTAG_Color2_Alpha		(COMPTAG_Base + 55)

#define COMPTAG_Color3_Red			(COMPTAG_Base + 56)
#define COMPTAG_Color3_Green		(COMPTAG_Base + 57)
#define COMPTAG_Color3_Blue			(COMPTAG_Base + 58)
#define COMPTAG_Color3_Alpha		(COMPTAG_Base + 59)

/* Specifies the YUV to RGB conversion standard to use for YUV source bitmaps.
 * The options are:
 * - COMPYUV_BT601 - SD video standard ITU-R BT.601
 * - COMPYUV_BT709 - HD video standard ITU-R BT.709
 *
 * NOTE: This is only relevant if the source bitmap is in one of the YUV formats
 * (e.g., RGBFB_YUV420P).
 */
#define COMPTAG_SrcYUVStandard	(COMPTAG_Base + 60)
#define    COMPYUV_BT601			(0)
#define    COMPYUV_BT709			(1)

/** (float32*) Provide a custom YUV to RGB conversion matrix.
 * This is a pointer to a 3x4 matrix in row-major order. The 4th column is
 * the offset vector. Please note that all YUV values are in the range [0..1], so your
 * matrix coefficients will have to take this into account (some conversion 
 * formulae assume different ranges).
 *
 * NOTE: This is only relevant if the source bitmap is in one of the YUV formats
 * (e.g., RGBFB_YUV420P).
 */
#define COMPTAG_SrcYUVMatrix		(COMPTAG_Base + 61)

/*
 * Reserved
 */
#define COMPTAG_Private				(COMPTAG_Base + 34)
#define COMPTAG_Private2			(COMPTAG_Base + 35)

/* Vertex Array format flags */
#define COMPVF_STW0_Present			0x02
#define COMPVF_STW1_Present			0x04

/*
 * Flags for the COMPTAG_Flags tag item
 *
 * Currently defined flags are:
 * COMPFLAG_SrcAlphaOverride - If set, the value specified in SrcAlpha overrides
 * 		the value in the source bitmap, which means that the source bitmap is
 *      assumed to have a constant alpha over the entire image. If not set,
 * 		the SrcAlpha value is used to modulate/scale any other alpha channel.
 * COMPFLAG_DestAlphaOverride - Like COMPFLAG_SrcAlphaOverride, for the
 * 		destination bitmap.
 * COMPFLAG_SrcFilter - If set, enables bilinear filtering of the source bitmap
 * 		while scaling. While this can improve the quality of scaled images,
 * 		it might cause a dramatic slowdown when the operation is emulated
 * 		in software.
 * COMPFLAG_HardwareOnly - If set, the call will fail with an error code if
 * 		the operation cannot be performed in hardware. Reasons for this include
 * 		software-only bitmaps, unsupported color formats, etc.
 * COMPFLAG_ForceSoftware - If set, the operation will be emulated in software
 * 		even if it could be performed in hardware. This is mostly useful for
 * 		testing purposes. Setting this overrides COMPFLAG_HardwareOnly.
 * COMPFLAG_Color1Modulate - 	If set, then Color 1 is used as a modulate
 *  color for the src bitmap. That is, each color component of each pixel
 *  in the source bitmap is	multiplied with the color 1 (including its
 *  alpha). All other effects stay in effect. This flag can essentially
 *  be used to "tint" a bitmap in the given color
 */

#define COMPFLAG_SrcAlphaOverride	(1L << 0)
#define COMPFLAG_DestAlphaOverride	(1L << 1)
#define COMPFLAG_SrcFilter			(1L << 2)
#define COMPFLAG_HardwareOnly		(1L << 3)
#define COMPFLAG_IgnoreDestAlpha	(1L << 4)
#define COMPFLAG_ForceSoftware		(1L << 7)
#define COMPFLAG_Color1Modulate		(1L << 8)

/* Helper Macros to convert to/from fixpoint numbers */
#define COMP_FIX_ONE 0x00010000
#define COMP_FLOAT_TO_FIX(f) (int32)((float)COMP_FIX_ONE * (f))
#define COMP_FIX_TO_FLOAT(fix) ((float)(fix) / (float)COMP_FIX_ONE)
#define COMP_FIX_TO_UINT32(fix) ((fix) / COMP_FIX_ONE)


/* Possible constants for Source */
#define COMPSRC_SOLIDCOLOR ((struct BitMap *)1)

enum enCompositeError
{
	COMPERR_Success				=	0,
	COMPERR_Incompatible		=	1, 	/* Incompatible bitmaps for operation */
	COMPERR_Value				=	2, 	/* An input value is out of range */
	COMPERR_SoftwareFallback	=	3, 	/* Operation would fall back to
	 								       software emulation and hardware
	 									   only was requested */
	COMPERR_OutOfMemory			=	4,  /* The operation tried to allocate
	 									   memory but failed */
	COMPERR_Generic				=	5,  /* Some generic error has occurred */
	COMPERR_UnknownOperator		=	6,	/* Unknown operator specified */
	COMPERR_MissingInput		= 	7,  /* Missing a mandatory tag item */

};

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

#endif
