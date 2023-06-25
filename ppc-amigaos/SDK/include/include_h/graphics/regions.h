#ifndef GRAPHICS_REGIONS_H
#define GRAPHICS_REGIONS_H
/*
**    $VER: regions.h 54.16 (22.08.2022)
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

#ifndef   GRAPHICS_GFX_H
#include <graphics/gfx.h>
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

struct RegionRectangle
{
    struct RegionRectangle *Next;
    struct RegionRectangle *Prev;
    struct Rectangle        bounds;
};

struct Region
{
    struct Rectangle        bounds;
    struct RegionRectangle *RegionRectangle;
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

#endif /* GRAPHICS_REGIONS_H */
