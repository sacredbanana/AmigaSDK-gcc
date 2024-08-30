#ifndef GUIGFX_MCC_H
#define GUIGFX_MCC_H

/***************************************************************************

 Magic User Interface - MUI
 Copyright (C) 1992-2006 by Stefan Stuntz <stefan@stuntz.com>
 Copyright (C) 2006-2021 by Thore Boeckelmann, Jens Maus
 All Rights Reserved.

 This program/documents may not in whole or in part, be copied, photocopied
 reproduced, translated or reduced to any electronic medium or machine
 readable form without prior consent, in writing, from the above authors.

 With this document the authors makes no warrenties or representations,
 either expressed or implied, with respect to MUI. The information
 presented herein is being supplied on an "AS IS" basis and is expressly
 subject to change without notice. The entire risk as to the use of this
 information is assumed by the user.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 IN NO EVENT WILL THE AUTHORS BE LIABLE FOR DIRECT, INDIRECT, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES RESULTING FROM ANY CLAIM ARISING OUT OF THE
 INFORMATION PRESENTED HEREIN, EVEN IF IT HAS BEEN ADVISED OF THE
 POSSIBILITIES OF SUCH DAMAGES.

 MUI Official Support Site:  http://www.sasg.com/

 $Id$

***************************************************************************/

/*
 * Guigfx.mcc
 *
 * Guigfx.mcc was originally developed by Matthias Bethke.
 * This is an AmigaOS native reimplementation included in MUI for AmigaOS for convenience.
*/

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif
#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack(2)
  #elif defined(__VBCC__)
    #pragma amiga-align
  #endif
#endif

/***********************************************************************/

#define MUIC_Guigfx          "Guigfx.mcc"
#define GuigfxObject         MUI_NewObject(MUIC_Guigfx

/***********************************************************************/

#define MUIA_Guigfx_Picture             0xfec20000 /* [ISG] APTR                            */
#define MUIA_Guigfx_FileName            0xfec20001 /* [IS.] CONST_STRPTR                    */
#define MUIA_Guigfx_BitmapInfo          0xfec20002 /* [IS.] struct MUIP_Guigfx_BitMapInfo * */
#define MUIA_Guigfx_ImageInfo           0xfec20003 /* [IS.] struct MUIP_Guigfx_ImageInfo *  */
#define MUIA_Guigfx_Transparency        0xfec20004 /* [ISG] ULONG                           */
#define MUIA_Guigfx_TransparentColor    0xfec20005 /* [ISG] ULONG                           */
#define MUIA_Guigfx_Quality             0xfec20006 /* [ISG] ULONG                           */
#define MUIA_Guigfx_ScaleMode           0xfec20007 /* [ISG] ULONG                           */
#define MUIA_Guigfx_ShowRect            0xfec20008 /* [ISG] struct Rect32 *                 */

// quality settings
#define MUIV_Guigfx_Quality_Low         0
#define MUIV_Guigfx_Quality_Medium      1
#define MUIV_Guigfx_Quality_High        2
#define MUIV_Guigfx_Quality_Best        3

// scaling flags
#define NISMB_SCALEUP                   0       /* allow image to grow */
#define NISMB_SCALEDOWN                 1       /* allow image to shrink */
#define NISMB_KEEPASPECT_PICTURE        2       /* keep picture's aspect ratio */
#define NISMB_KEEPASPECT_SCREEN         3       /* take screen's aspect ratio into account */

#define NISMF_NONE                      0
#define NISMF_SCALEUP                   (1 << NISMB_SCALEUP)
#define NISMF_SCALEDOWN                 (1 << NISMB_SCALEDOWN)
#define NISMF_KEEPASPECT_PICTURE        (1 << NISMB_KEEPASPECT_PICTURE)
#define NISMF_KEEPASPECT_SCREEN         (1 << NISMB_KEEPASPECT_SCREEN)

#define NISMF_SCALEFREE                 (NISMF_SCALEUP | NISMF_SCALEDOWN)
#define NISMF_KEEPASPECT                (NISMF_KEEPASPECT_PICTURE | NISMF_KEEPASPECT_SCREEN)
#define NISMF_SCALEMASK                 0x0f    /* all scaling bits */

// transparency flags
#define NITRB_MASK                      0       /* use mask plane if present in picture */
#define NITRB_RGB                       1       /* use RGB value as mask (see MUIA_Guigfx_TransparentColor) */

#define NITRF_MASK                      (1 << NITRB_MASK)
#define NITRF_RGB                       (1 << NITRB_RGB)

// additional info for passing bitmaps to Guigfx.mcc
struct MUIP_Guigfx_BitMapInfo
{
	UWORD Version;          /* MUST be set to NEWIMAGE_BITMAPINFO_VERSION */
	UWORD pad;              /* longword padding, always set to zero for now! */
	struct BitMap *Bitmap;  /* bitmap to show */
	ULONG *ColorTable;      /* palette pointer or special value, see below */
	PLANEPTR Mask;          /* optional, may be NULL */
	UWORD AspectX;          /* picture's horizontal pixel aspect, optional */
	UWORD AspectY;          /* picture's vertical pixel aspect, optional */
};

#define NEWIMAGE_BITMAPINFO_VERSION     1

// additional info for passing intuition images to Guigfx.mcc
struct MUIP_Guigfx_ImageInfo
{
	UWORD Version;          /* MUST be set to NEWIMAGE_IMAGEINFO_VERSION */
	UWORD pad;              /* longword padding, always set to zero for now! */
	struct Image *Image;    /* intuition image to show */
	ULONG *ColorTable;      /* palette pointer or special value, see below */
};

#define NEWIMAGE_IMAGEINFO_VERSION      1

#define MUIV_Guigfx_WBPalette           ((ULONG *)(-1))    /* Workbench's palette (icons!) */
#define MUIV_Guigfx_GreyPalette         ((ULONG *)(-3))    /* Greyscale palette */
#define MUIV_Guigfx_CurrentPalette      ((ULONG *)(-5))    /* Current screen's palette. Probably not very useful in applications */

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* GUIGFX_MCC_H */
