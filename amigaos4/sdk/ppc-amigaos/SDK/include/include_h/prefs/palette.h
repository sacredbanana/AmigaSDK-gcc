#ifndef PREFS_PALETTE_H
#define PREFS_PALETTE_H
/*
**    $VER: palette.h 54.16 (22.08.2022)
**
**    File format for palette preferences
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

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
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

#define ID_PALT MAKE_ID('P','A','L','T')

struct PalettePrefs
{
    LONG             pap_Reserved[3];    /* System reserved                */
    ULONG            pap_Flags;
    UWORD            pap_4ColorPens[32];
    UWORD            pap_8ColorPens[32];
    struct ColorSpec pap_Colors[32];     /* Used as full 16-bit RGB values */

    /* Fields added for V50, only valid if the PF_FULLPALETTE flag is set  */

    UBYTE            pap_RGBTable[768];
    UBYTE            pap_LockTable[256];
    ULONG            pap_Reserved2[4];
};

#define PF_FULLPALETTE 0x00000001  /* Extended V50 palette preferences */

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

#endif /* PREFS_PALETTE_H */
