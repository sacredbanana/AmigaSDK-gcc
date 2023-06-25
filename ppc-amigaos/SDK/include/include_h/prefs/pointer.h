#ifndef PREFS_POINTER_H
#define PREFS_POINTER_H
/*
**    $VER: pointer.h 54.16 (22.08.2022)
**
**    File format for pointer preferences
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

/*****************************************************************************/

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

#define ID_PNTR MAKE_ID('P','N','T','R')

/*****************************************************************************/

struct PointerPrefs
{
    ULONG pp_Reserved[4];
    UWORD pp_Which;       /* 0=NORMAL, 1=BUSY */
    UWORD pp_Size;        /* see <intuition/pointerclass.h> */
    UWORD pp_Width;       /* Width in pixels */
    UWORD pp_Height;      /* Height in pixels */
    UWORD pp_Depth;       /* Depth */
    UWORD pp_YSize;       /* YSize */
    UWORD pp_X, pp_Y;     /* Hotspot */

    /* Color Table:  numEntries = (1 << pp_Depth) - 1 */

    /* Data follows */
};

/*****************************************************************************/

/* constants for PointerPrefs.pp_Which */
#define WBP_NORMAL 0
#define WBP_BUSY   1

/*****************************************************************************/

struct RGBTable
{
    UBYTE t_Red;
    UBYTE t_Green;
    UBYTE t_Blue;
};

/*****************************************************************************/

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

#endif /* PREFS_POINTER_H */
