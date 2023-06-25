#ifndef GRAPHICS_BLITATTR_H
#define GRAPHICS_BLITATTR_H
/*
**    $VER: blitattr.h 54.16 (22.08.2022)
**
**    tag definitions for BltBitMapTagList, BltBitMapTags
**
**    Copyright (C) 1985-2006 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

#define BLTBMTAGS_BASE          (TAG_USER)
/* attributes specifying the source and destination coordinates
 * of the blit operation. Default is 0 (WORD). */
#define BLITA_SrcX              (BLTBMTAGS_BASE + 1)
#define BLITA_SrcY              (BLTBMTAGS_BASE + 2)
#define BLITA_DestX             (BLTBMTAGS_BASE + 3)
#define BLITA_DestY             (BLTBMTAGS_BASE + 4)
/* size of blit operation, default is 0 (WORD) */
#define BLITA_Width             (BLTBMTAGS_BASE + 5)
#define BLITA_Height            (BLTBMTAGS_BASE + 6)
/* source and destination object, also see BLITT definitions below
 * default is NULL (APTR) */
#define BLITA_Source            (BLTBMTAGS_BASE + 7)
#define BLITA_Dest              (BLTBMTAGS_BASE + 8)
/* minterm of blit, default is 0xc0 (copy blit, UBYTE) */
#define BLITA_Minterm           (BLTBMTAGS_BASE + 9)
/* blit mask, default is 0xff (UBYTE) if BLITA_Dest is not
 * a rastport otherwise the rp->Mask value of the destination
 * rastport is used. */
#define BLITA_Mask              (BLTBMTAGS_BASE + 10)
/* see BltMaskBitMapRastPort() */
#define BLITA_MaskPlane         (BLTBMTAGS_BASE + 11)
/* 8bit alpha mask, default is NULL (APTR). Mask and source
 * bitmap must have the same dimension */
#define BLITA_AlphaMask         (BLTBMTAGS_BASE + 12)
/* specifies the bytes per row value of the source object, if
 * source is neither a rastport nor a bitmap (UWORD) */
#define BLITA_SrcBytesPerRow    (BLTBMTAGS_BASE + 13)
/* type of source object, default is BLITT_BITMAP */
#define BLITA_SrcType           (BLTBMTAGS_BASE + 14)
/* specifies the bytes per row value of the destination object, if
 * destination is neither a rastport nor a bitmap (UWORD) */
#define BLITA_DestBytesPerRow   (BLTBMTAGS_BASE + 15)
/* type of destination object, default is BLITT_BITMAP */
#define BLITA_DestType          (BLTBMTAGS_BASE + 16)
/* use alpha data stored in the source object for transparent
 * blits, default is FALSE (BOOL). BLITA_UseSrcAlpha and
 * BLITA_AlphaMask are mutually-exclusive. */
#define BLITA_UseSrcAlpha       (BLTBMTAGS_BASE + 17)
/* not implemented yet */
#define BLITA_UseDestAlpha      (BLTBMTAGS_BASE + 18)
/* global alpha value applied to each pixel, default is
 * 0xffffffff (ULONG, 32 bit left justified fraction).
 * A value of ULONG_MAX means non-opaque blit unless
 * BLIT_UseSrcAlpha is TRUE or BLITA_AlphaMask is used.
 * To convert an 8bit alpha value to 32bit one multiply it
 * by 0x01010101. BLITA_Alpha can be used in combination
 * with the two tags mentioned above. */
#define BLITA_Alpha             (BLTBMTAGS_BASE + 19)
/* color lookuptable (256 entries each 4bytes large, format
 * 0x00RRGGBB) to use when blitting chunky bitmaps to
 * directmapped bitmaps. Default is NULL (APTR), means palette
 * of destination bitmap is used (if available). Currently not
 * supported by alpha blits. */
#define BLITA_CLUT              (BLTBMTAGS_BASE + 20)

/* possible types for BLITA_SrcType / BLITA_DestType */
#define BLITT_BITMAP            0 /* a bitmap (default) */
#define BLITT_RASTPORT          1 /* a rastport         */
#define BLITT_TEMPLATE          2 /* 1bit template, source only!       */
#define BLITT_ALPHATEMPLATE     3 /* 8bit alpha template, source only! */
#define BLITT_CHUNKY            4 /* 8bit chunky buffer */
#define BLITT_RGB24             5 /* 24bit RGB buffer   */
#define BLITT_ARGB32            6 /* 32bit ARGB buffer  */
#define BLITT_RGB16             7 /* 16bit RGB buffer (same as RGBFB_R5G6B5) */

/****************************************************************************/

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* GRAPHICS_BLITATTR_H */
