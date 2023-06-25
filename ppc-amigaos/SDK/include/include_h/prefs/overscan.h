#ifndef PREFS_OVERSCAN_H
#define PREFS_OVERSCAN_H
/*
**    $VER: overscan.h 54.16 (22.08.2022)
**
**    File format for overscan preferences
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

#ifndef   GRAPHICS_GFX_H
#include <graphics/gfx.h>
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

#define ID_OSCN MAKE_ID('O','S','C','N')

#define OSCAN_MAGIC  0xFEDCBA89

struct OverscanPrefs
{
    ULONG            os_Reserved;
    ULONG            os_Magic;
    UWORD            os_HStart;
    UWORD            os_HStop;
    UWORD            os_VStart;
    UWORD            os_VStop;
    ULONG            os_DisplayID;
    Point            os_ViewPos;
    Point            os_Text;
    struct Rectangle os_Standard;
};

/* os_HStart, os_HStop, os_VStart, os_VStop can only be looked at if
 * os_Magic equals OSCAN_MAGIC. If os_Magic is set to any other value,
 * these four fields are undefined
 */

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

#endif /* PREFS_OVERSCAN_H */
