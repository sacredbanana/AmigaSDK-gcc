#ifndef PREFS_SCREENS_H
#define PREFS_SCREENS_H
/*
**    $VER: screens.h 54.16 (22.08.2022)
**
**    File format for Screens preferences
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

#define ID_SCRN MAKE_ID('S','C','R','N')

struct ScreensPrefs
{
    LONG  sp_Reserved[4]; /* System reserved                       */
    UWORD sp_Version;     /* Version of the ScreensPrefs structure */
    ULONG sp_GlobalFlags; /* Global screens flags                  */
};

#define ID_SCRD MAKE_ID('S','C','R','D')

struct ScreenDefinition
{
    ULONG           sd_Flags;            /* Screen specific flags      */
    TEXT            sd_ScreenName[128];  /* Screen public name         */
    TEXT            sd_ScreenTitle[128]; /* Screen title               */
    TEXT            sd_BaseName[32];     /* Screen database base name  */
    ULONG           sd_DisplayID;        /* Screen display mode        */
    UWORD           sd_Width;            /* Screen width               */
    UWORD           sd_Height;           /* Screen height              */
    UWORD           sd_Depth;            /* Screen depth               */
    UWORD           sd_Control;          /* Screen control flags       */
    struct TextAttr sd_Font;             /* Screen font attributes     */
    TEXT            sd_FontName[128];    /* Screen font name buffer    */
    ULONG           sd_Reserved[8];
    struct
    {
        UWORD Type;
        UWORD Flags;
    }               sd_Settings[4];      /* Screen settings attributes */
    ULONG           sd_Reserved2[16];
};

#define ID_PATH MAKE_ID('P','A','T','H')

/* Flags for ScreenDefinition.sd_Flags */
#define SDF_OVERRIDEPENS    0x00000001  /* Use only user-defined pens      */
#define SDF_OVERRIDEPALETTE 0x00000002  /* Use only user-defined palette   */
#define SDF_IGNOREPENS      0x00000004  /* Don't use user-defined pens     */
#define SDF_IGNOREPALETTE   0x00000008  /* Don't use user-defined palette  */
#define SDF_NOCOLORLOCKING  0x00000020  /* Don't lock user-defined colors  */
#define SDF_IGNOREATTRS     0x00000040  /* Ignore programmatical GUI attrs */
#define SDF_MODEAPPLYMASK   0x00000300  /* How to apply chosen screen mode */
#define SDF_FONTAPPLYMASK   0x00000C00  /* How to apply chosen font        */
#define SDF_RESERVED1       0x00001000  /* System reserved, don't use      */
#define SDF_RESERVED2       0x00002000  /* System reserved, don't use      */
#define SDF_AUTOMATIC       0x00010000  /* Allow automatic open/close      */
#define SDF_DISABLED        0x10000000  /* Ignore this screen definition   */
#define SDF_RESERVED3       0x20000000  /* System reserved, don't use      */

#define SDF_MODEAPPLY_NEVER 0x00000000  /* Never use these settings     */
#define SDF_MODEAPPLY_ASDEF 0x00000100  /* Only use as initial defaults */
#define SDF_MODEAPPLY_FORCE 0x00000200  /* Always force these settings  */

#define SDF_FONTAPPLY_NEVER 0x00000000  /* Never use these settings     */
#define SDF_FONTAPPLY_ASDEF 0x00000400  /* Only use as initial defaults */
#define SDF_FONTAPPLY_FORCE 0x00000800  /* Always force these settings  */

/* Indices for ScreenDefinition.sd_Settings */
#define SDS_GUI        0  /* GUI preferences     */
#define SDS_PALETTE    1  /* Palette preferences */
#define SDS_SCREENMODE 2  /* For future use      */
#define SDS_FONT       3  /* For future use      */
#define SDS_MAX        3  /* Highest index       */

/* Values for ScreenDefinition.sd_Settings[x].Type */
#define SDST_DEFAULTS 0
#define SDST_CUSTOM   1
#define SDST_LIKEWB   2  /* New for V51 */

/* Values for ScreenDefinition.sd_Settings[x].Flags */
#define SDSF_CUSTOMFILE 0x0001

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

#endif /* PREFS_SCREENS_H */
