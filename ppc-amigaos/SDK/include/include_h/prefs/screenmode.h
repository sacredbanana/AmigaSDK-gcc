#ifndef PREFS_SCREENMODE_H
#define PREFS_SCREENMODE_H
/*
**    $VER: screenmode.h 54.16 (22.08.2022)
**
**    File format for screen mode preferences
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

#define ID_SCRM MAKE_ID('S','C','R','M')

struct ScreenModePrefs
{
    ULONG smp_Reserved[3];
    UWORD smp_NomWidth;
    UWORD smp_NomHeight;
    ULONG smp_DisplayID;
    UWORD smp_Width;
    UWORD smp_Height;
    UWORD smp_Depth;
    UWORD smp_Control;
};

/* flags for ScreenModePrefs.smp_Control */
#define SMB_AUTOSCROLL 1

#define SMF_AUTOSCROLL (1<<0)

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

#endif /* PREFS_SCREENMODE_H */
