#ifndef INTUITION_BITMAPSHARE_H
#define INTUITION_BITMAPSHARE_H
/*
**    $VER: bitmapshare.h 54.16 (22.08.2022)
**
**    Bitmap sharing routines: structures and definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
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

/* Tags for ObtainBitMapSourceA() */

#define BMS_Dummy     (TAG_USER + 0x01547300)
#define BMS_NoDiskIO  (BMS_Dummy + 1)      /* Only open if already in memory */
#define BMS_DoMask    (BMS_Dummy + 2)      /* Generate a mask, if possible   */
#define BMS_DoOutline (BMS_Dummy + 3)      /* Load outline mask, if present  */
#define BMS_DoShade   (BMS_Dummy + 4)      /* Load shading maps, if present  */

/* Tags for ObtainBitMapInstanceA() */

#define BMI_Dummy         (TAG_USER + 0x01547400)
#define BMI_Exclusive     (BMI_Dummy +  1)  /* Is this bitmap exclusive? */
#define BMI_DoLevels      (BMI_Dummy +  2)  /* Generate brighter/darker
                                               variants? */
#define BMI_Offsets       (BMI_Dummy +  3)  /* Packed backfill offsets */
#define BMI_LayerInfo     (BMI_Dummy +  4)  /* Is this a LayerInfo backfill? */
#define BMI_ReferencePen  (BMI_Dummy +  5)  /* Base pen this bitmap is
                                               associated to */
#define BMI_GradientSpec  (BMI_Dummy +  6)  /* Gradient specification for
                                               backfill */
#define BMI_CacheGradient (BMI_Dummy +  7)  /* Packed W:H to rasterize
                                               gradient */
#define BMI_GradientAxis  (BMI_Dummy +  8)  /* Tile rasterized gradient on
                                               this axis */
#define BMI_IgnoreDomain  (BMI_Dummy +  9)  /* Always use whole RastPort as
                                               domain */
#define BMI_TileLeft      (BMI_Dummy + 10)  /* Left offset for backfill tile
                                               (V51) */
#define BMI_TileTop       (BMI_Dummy + 11)  /* Top offset for backfill tile
                                               (V51) */
#define BMI_TileWidth     (BMI_Dummy + 12)  /* Width of backfill tile (V51) */
#define BMI_TileHeight    (BMI_Dummy + 13)  /* Height of backfill tile (V51) */

/* Tags for BitMapInstanceControlA() */

#define BMICTRL_Dummy (TAG_USER + 0x01547600)

#define BMICTRL_GetBitMap           (BMICTRL_Dummy + 1)
   /* (struct BitMap **) Get actual BitMap address. */

#define BMICTRL_GetHook             (BMICTRL_Dummy + 2)
   /* (struct Hook **) Get backfill hook address. */

#define BMICTRL_GetOffsets          (BMICTRL_Dummy + 3)
   /* (ULONG *) Get backfill offsets, packed in a single longword. */

#define BMICTRL_SetOffsets          (BMICTRL_Dummy + 4)
   /* (ULONG) Set backfill offsets, packed in a single longword; */
   /* this ONLY applies to instances allocated in exclusive mode. */

#define BMICTRL_GetWidth            (BMICTRL_Dummy + 5)
   /* (ULONG *) Get width of BitMap. */

#define BMICTRL_GetHeight           (BMICTRL_Dummy + 6)
   /* (ULONG *) Get height of BitMap. */

#define BMICTRL_GetBrightBitMap     (BMICTRL_Dummy + 7)
   /* (struct BitMap **) Get address of bright-level BitMap (if any). */

#define BMICTRL_GetHalfBrightBitMap (BMICTRL_Dummy + 8)
   /* (struct BitMap **) Get address of half-bright-level BitMap (if any). */

#define BMICTRL_GetHalfDarkBitMap   (BMICTRL_Dummy + 9)
   /* (struct BitMap **) Get address of half-dark-level BitMap (if any). */

#define BMICTRL_GetDarkBitMap       (BMICTRL_Dummy + 10)
   /* (struct BitMap **) Get address of dark-level BitMap (if any). */

#define BMICTRL_GetMaskBitMap       (BMICTRL_Dummy + 11)
   /* (struct BitMap **) Get address of single-plane mask bitmap (if any). */

#define BMICTRL_GetOutlineBitMap    (BMICTRL_Dummy + 12)
   /* (struct BitMap **) Get address of single-plane outline bitmap (if any) */

#define BMICTRL_GetShineMap         (BMICTRL_Dummy + 13)
   /* (UBYTE **) Get address of bright shading alpha map array (if any). */

#define BMICTRL_GetShadowMap        (BMICTRL_Dummy + 14)
   /* (UBYTE **) Get address of dark shading alpha map array (if any). */

#define BMICTRL_GetAlphaMap         (BMICTRL_Dummy + 15)
   /* (UBYTE **) Get address of alpha blending map array (if any). */

#define BMICTRL_GetShadeMaskBitMap  (BMICTRL_Dummy + 16)
   /* (struct BitMap **) Get address of single-plane shade mask bitmap
      (if any). */

#define BMICTRL_GetScreen           (BMICTRL_Dummy + 17)
   /* (struct Screen **) Get address of the reference screen (may be NULL). */

#define BMICTRL_GetBitMapSource     (BMICTRL_Dummy + 18)
   /* (APTR *) Get address of the BitMapSource this instance was obtained
      from. */

#define BMICTRL_GetGradientSpec     (BMICTRL_Dummy + 19)
   /* (GRADSPEC **) Get address of gradient specification (if any). */

#define BMICTRL_SetGradientSpec     (BMICTRL_Dummy + 20)
   /* (GRADSPEC *) Set gradient specification; this ONLY applies to */
   /* instances allocated in exclusive mode. */

#define BMICTRL_GetReferencePen     (BMICTRL_Dummy + 21)
   /* (ULONG *) Get reference pen index. */

#define BMICTRL_GetOutlineMap       (BMICTRL_Dummy + 22)
   /* (UBYTE **) Get address of outline alpha map array (if any). */

#define BMICTRL_GetTileLeft         (BMICTRL_Dummy + 23)
   /* (ULONG *) Get left offset of backfill tile. (V51) */

#define BMICTRL_GetTileTop          (BMICTRL_Dummy + 24)
   /* (ULONG *) Get top offset of backfill tile. (V51) */

#define BMICTRL_GetTileWidth        (BMICTRL_Dummy + 25)
   /* (ULONG *) Get width of backfill tile. (V51) */

#define BMICTRL_GetTileHeight       (BMICTRL_Dummy + 26)
   /* (ULONG *) Get height of backfill tile. (V51) */

#define BMICTRL_GetTileBox          (BMICTRL_Dummy + 27)
   /* (struct IBox *) Get backfill tile box in one go. (V51) */

#define BMICTRL_SetTileLeft         (BMICTRL_Dummy + 28)
   /* (UWORD) Set left offset of backfill tile; this ONLY applies to */
   /* instances allocated in exclusive mode. (V51) */

#define BMICTRL_SetTileTop          (BMICTRL_Dummy + 29)
   /* (UWORD) Set top offset of backfill tile; this ONLY applies to */
   /* instances allocated in exclusive mode. (V51) */

#define BMICTRL_SetTileWidth        (BMICTRL_Dummy + 30)
   /* (UWORD) Set width of backfill tile; this ONLY applies to */
   /* instances allocated in exclusive mode. (V51) */

#define BMICTRL_SetTileHeight       (BMICTRL_Dummy + 31)
   /* (UWORD) Set height of backfill tile; this ONLY applies to */
   /* instances allocated in exclusive mode. (V51) */

#define BMICTRL_SetReferencePen     (BMICTRL_Dummy + 32)
   /* (ULONG) Set reference pen index; this ONLY applies to */
   /* instances allocated in exclusive mode. (V51) */

/* Useful type definitions */
typedef APTR BitMapSource;
typedef APTR BitMapInstance;

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

#endif  /* INTUITION_BITMAPSHARE_H */
