#ifndef GRAPHICS_SPRITE_H
#define GRAPHICS_SPRITE_H
/*
**    $VER: sprite.h 54.16 (22.08.2022)
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

#define SPRITE_ATTACHED 0x80

struct SimpleSprite
{
    UWORD *posctldata;
    UWORD  height;
    UWORD  x, y;    /* current position */
    UWORD  num;
};

struct ExtSprite
{
    struct SimpleSprite es_SimpleSprite; /* conventional simple sprite
                                          * structure */
    UWORD               es_wordwidth;    /* graphics use only,
                                          * subject to change */
    UWORD               es_flags;        /* graphics use only,
                                          * subject to change */
};

/* tags for AllocSpriteData() */
#define SPRITEA_Width         0x81000000
#define SPRITEA_XReplication  0x81000002
#define SPRITEA_YReplication  0x81000004
#define SPRITEA_OutputHeight  0x81000006
#define SPRITEA_Attached      0x81000008
#define SPRITEA_OldDataFormat 0x8100000a /* MUST pass in outputheight
                                          * if using this tag */

/* tags for GetExtSprite() */
#define GSTAG_SPRITE_NUM      0x82000020
#define GSTAG_ATTACHED        0x82000022
#define GSTAG_SOFTSPRITE      0x82000024

/* tags valid for either GetExtSprite or ChangeExtSprite */
#define GSTAG_SCANDOUBLED     0x83000000 /* request "NTSC-Like" height
                                          * if possible. */

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

#endif /* GRAPHICS_SPRITE_H */
