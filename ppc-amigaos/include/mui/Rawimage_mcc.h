#ifndef RAWIMAGE_MCC_H
#define RAWIMAGE_MCC_H

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
 * Rawimage.mcc
 *
 * Rawimage.mcc was originally developed by Christian Rosentreter for MorphOS.
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

#define MUIC_Rawimage       "Rawimage.mcc"
#define RawimageObject      MUI_NewObject(MUIC_Rawimage

/***********************************************************************/

struct MUI_RawimageData
{
    ULONG ri_Width;
    ULONG ri_Height;
    ULONG ri_Format;
    ULONG ri_Size;
    ULONG ri_Data[0];
};

#define RAWIMAGE_PIXELFORMAT_ARGB    0
#define RAWIMAGE_PIXELFORMAT_RGB     1

#define RAWIMAGE_FORMAT_RAW_ARGB_ID  RAWIMAGE_PIXELFORMAT_ARGB
#define RAWIMAGE_FORMAT_RAW_RGB_ID   RAWIMAGE_PIXELFORMAT_RGB
#define RAWIMAGE_FORMAT_BZ2_ARGB_ID  MAKE_ID('B', 'Z', '2', RAWIMAGE_PIXELFORMAT_ARGB)
#define RAWIMAGE_FORMAT_BZ2_RGB_ID   MAKE_ID('B', 'Z', '2', RAWIMAGE_PIXELFORMAT_RGB )
#define RAWIMAGE_FORMAT_Z_ARGB_ID    MAKE_ID('Z', 0x0, 0x0, RAWIMAGE_PIXELFORMAT_ARGB)
#define RAWIMAGE_FORMAT_Z_RGB_ID     MAKE_ID('Z', 0x0, 0x0, RAWIMAGE_PIXELFORMAT_RGB )
#define RAWIMAGE_FORMAT_RLE_ARGB_ID  MAKE_ID('R', 'L', 'E', RAWIMAGE_PIXELFORMAT_ARGB)
#define RAWIMAGE_FORMAT_RLE_RGB_ID   MAKE_ID('R', 'L', 'E', RAWIMAGE_PIXELFORMAT_RGB )
#define RAWIMAGE_FORMAT_LZMA_ARGB_ID MAKE_ID('L', 'Z', 'M', RAWIMAGE_PIXELFORMAT_ARGB)
#define RAWIMAGE_FORMAT_LZMA_RGB_ID  MAKE_ID('L', 'Z', 'M', RAWIMAGE_PIXELFORMAT_RGB )

/***********************************************************************/

#define MUIA_Rawimage_Data  0xfed10014   /* [ISG]  struct MUI_RawimageData *      */

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* RAWIMAGE_MCC_H */
