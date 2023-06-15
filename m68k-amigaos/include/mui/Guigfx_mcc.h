/*
** $Id: Guigfx_mcc.h 1.1 2000/03/30 22:38:31 msbethke Exp $
*/

#ifndef MUI_GUIGFX_MCC_H

#ifndef GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

#define MUIC_Guigfx "Guigfx.mcc"
#define GuigfxObject MUI_NewObject(MUIC_Guigfx

#define NEWIMAGE_TAGBASE 0xfec20000


/* Attributes defined by Guigfx.mcc */

#define MUIA_Guigfx_Picture	(NEWIMAGE_TAGBASE+0)					/* [ISG] APTR */
#define MUIA_Guigfx_FileName (NEWIMAGE_TAGBASE+1)					/* [IS ] STRPTR */
#define MUIA_Guigfx_BitmapInfo (NEWIMAGE_TAGBASE+2)				/* [IS ] struct MUIP_Guigfx_BitMapInfo* */
#define MUIA_Guigfx_ImageInfo (NEWIMAGE_TAGBASE+3)					/* [IS ] struct MUIP_Guigfx_ImageInfo* */
#define MUIA_Guigfx_Transparency (NEWIMAGE_TAGBASE+4)				/* [ISG] ULONG */
#define MUIA_Guigfx_TransparentColor (NEWIMAGE_TAGBASE+5)		/* [ISG] ULONG */
#define MUIA_Guigfx_Quality (NEWIMAGE_TAGBASE+6)					/* [ISG] ULONG */
#define MUIA_Guigfx_ScaleMode (NEWIMAGE_TAGBASE+7)					/* [ISG] ULONG */
#define MUIA_Guigfx_ShowRect (NEWIMAGE_TAGBASE+8)					/* [ISG] struct Rect32* */

/* Quality settings */
#define MUIV_Guigfx_Quality_Low		0
#define MUIV_Guigfx_Quality_Medium	1
#define MUIV_Guigfx_Quality_High 	2
#define MUIV_Guigfx_Quality_Best		3


/* Scaling flags */
#define NISMB_SCALEUP            0		/* allow image to grow */
#define NISMB_SCALEDOWN          1		/* allow image to shrink */
#define NISMB_KEEPASPECT_PICTURE 2		/* keep picture's aspect ratio */
#define NISMB_KEEPASPECT_SCREEN  3		/* take screen's aspect ratio into account */

#define NISMF_NONE               0		
#define NISMF_SCALEUP            (1<<NISMB_SCALEUP)
#define NISMF_SCALEDOWN          (1<<NISMB_SCALEDOWN)
#define NISMF_KEEPASPECT_PICTURE (1<<NISMB_KEEPASPECT_PICTURE)
#define NISMF_KEEPASPECT_SCREEN  (1<<NISMB_KEEPASPECT_SCREEN)

/* combinations */
#define NISMF_SCALEFREE          (NISMF_SCALEUP | NISMF_SCALEDOWN)
#define NISMF_KEEPASPECT         (NISMF_KEEPASPECT_PICTURE | NISMF_KEEPASPECT_SCREEN)
#define NISMF_SCALEMASK 0x0f		/* all scaling bits */


/* transparency flags */
#define NITRB_MASK 0				/* use mask plane if present in picture */
#define NITRB_RGB  1				/* use RGB value as mask
											(see MUIA_Guigfx_TransparentColor) */

#define NITRF_MASK (1<<NITRB_MASK)
#define NITRF_RGB  (1<<NITRB_RGB)


/* additional info for passing bitmaps to Guigfx.mcc */
#define NEWIMAGE_BITMAPINFO_VERSION 1

struct MUIP_Guigfx_BitMapInfo
{
	UWORD	Version; 			/* set to NEWIMAGE_BITMAPINFO_VERSION */
	UWORD pad;					/* longword padding, always set to zero for now! */
	struct BitMap *Bitmap;	/* bitmap to show */
	ULONG *ColorTable;		/* palette pointer or special value, see below */
	PLANEPTR Mask;				/* optional, may be NULL */
	UWORD AspectX, AspectY;	/* picture's pixel aspect horizontal/vertical, optional */
};

/* additional info for passing intuition images to Guigfx.mcc */
#define NEWIMAGE_IMAGEINFO_VERSION 1

struct MUIP_Guigfx_ImageInfo
{
	UWORD Version;				/* set to NEWIMAGE_IMAGEINFO_VERSION */
	UWORD pad;					/* longword padding, always set to zero for now! */
	struct Image *Image;		/* intuition image to show */
	ULONG *ColorTable;		/* palette pointer or special value, see below */
};

#define MUIV_Guigfx_WBPalette (-1)		/* Workbench's palette (icons!) */
#define MUIV_Guigfx_GreyPalette (-3)		/* Greyscale palette */
#define MUIV_Guigfx_CurrentPalette (-5)	/* Current screen's palette.
															Probably not very useful in applications */

#endif /* MUI_GUIGFX_MCC_H */
