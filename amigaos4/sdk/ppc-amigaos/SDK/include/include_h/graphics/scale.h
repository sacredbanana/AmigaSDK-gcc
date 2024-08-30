#ifndef GRAPHICS_SCALE_H
#define GRAPHICS_SCALE_H
/*
**    $VER: scale.h 54.16 (22.08.2022)
**
**    structure argument to BitMapScale()
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

struct BitScaleArgs
{
    UWORD          bsa_SrcX;         /* source origin            */
    UWORD          bsa_SrcY;         /*       "                  */
    UWORD          bsa_SrcWidth;     /* source size              */
    UWORD          bsa_SrcHeight;    /*       "                  */
    UWORD          bsa_XSrcFactor;   /* scale factor denominator */
    UWORD          bsa_YSrcFactor;   /*       "                  */
    UWORD          bsa_DestX;        /* destination origin       */
    UWORD          bsa_DestY;        /*       "                  */
    UWORD          bsa_DestWidth;    /* destination size result  */
    UWORD          bsa_DestHeight;   /*       "                  */
    UWORD          bsa_XDestFactor;  /* scale factor numerator   */
    UWORD          bsa_YDestFactor;  /*       "                  */
    struct BitMap *bsa_SrcBitMap;    /* source BitMap            */
    struct BitMap *bsa_DestBitMap;   /* destination BitMap       */
    ULONG          bsa_Flags;        /* reserved.  Must be zero! */
    UWORD          bsa_XDDA;         /* reserved                 */
    UWORD          bsa_YDDA;         /*       "                  */
    LONG           bsa_Reserved1;    /*       "                  */
    LONG           bsa_Reserved2;    /*       "                  */
};

#define BSAF_RESERVED1         1
#define BSAF_RESERVED2         2
#define BSAF_AVERAGE           4
#define BSAF_BILINEAR          8

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

#endif /* GRAPHICS_SCALE_H */
