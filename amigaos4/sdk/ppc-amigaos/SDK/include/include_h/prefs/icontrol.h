#ifndef PREFS_ICONTROL_H
#define PREFS_ICONTROL_H
/*
**    $VER: icontrol.h 54.16 (22.08.2022)
**
**    File format for intuition control preferences
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

#define ID_ICTL MAKE_ID('I','C','T','L')

struct IControlPrefs
{
    LONG  ic_Reserved[4];    /* System reserved                 */
    UWORD ic_TimeOut;        /* Verify timeout                  */
    WORD  ic_MetaDrag;       /* Meta drag mouse event           */
    ULONG ic_Flags;          /* IControl flags (see below)      */
    UBYTE ic_WBtoFront;      /* CKey: WB to front               */
    UBYTE ic_FrontToBack;    /* CKey: front screen to back      */
    UBYTE ic_ReqTrue;        /* CKey: Requester TRUE            */
    UBYTE ic_ReqFalse;       /* CKey: Requester FALSE           */
    UWORD ic_Reserved2;      /* System reserved                 */
    UWORD ic_VDragModes[2];  /* Virtual screen drag modes (V51) */
    ULONG ic_Reserved3[2];   /* System reserved                 */
};

/* Flags for IControlPrefs.ic_Flags */
#define ICB_COERCE_COLORS      0
#define ICB_COERCE_LACE        1
#define ICB_STRGAD_FILTER      2
#define ICB_MENUSNAP           3
#define ICB_MODEPROMOTE        4
#define ICB_SQUARE_RATIO       5  /* OBSOLETE */
#define ICB_SCREEN_ACTIVATION  6
#define ICB_OPAQUEMOVE         7
#define ICB_OPAQUESIZE         8
#define ICB_FORCESMART         9
#define ICB_NOSCREENDRAGGING  10
#define ICB_MIXSCREENDEPTHS   11
#define ICB_PLANARSUPPORT     12
#define ICB_CLUTPROMOTE_HC    13
#define ICB_CLUTPROMOTE_TC    14

#define ICF_COERCE_COLORS     (1 <<  0)
#define ICF_COERCE_LACE       (1 <<  1)
#define ICF_STRGAD_FILTER     (1 <<  2)
#define ICF_MENUSNAP          (1 <<  3)
#define ICF_MODEPROMOTE       (1 <<  4)
#define ICF_SQUARE_RATIO      (1 <<  5)  /* OBSOLETE */
#define ICF_SCREEN_ACTIVATION (1 <<  6)
#define ICF_OPAQUEMOVE        (1 <<  7)
#define ICF_OPAQUESIZE        (1 <<  8)
#define ICF_FORCESMART        (1 <<  9)
#define ICF_NOSCREENDRAGGING  (1 << 10)
#define ICF_MIXSCREENDEPTHS   (1 << 11)
#define ICF_PLANARSUPPORT     (1 << 12)
#define ICF_CLUTPROMOTEMASK   ((1 << 13) | (1 << 14))
#define ICF_CLUTPROMOTE_NO    0
#define ICF_CLUTPROMOTE_HC    (1 << 13)
#define ICF_CLUTPROMOTE_TC    (1 << 14)

/* Virtual screen drag modes */
#define ICVDM_TBOUND    0x0001  /* Bounded at the top */
#define ICVDM_BBOUND    0x0002  /* Bounded at the bottom */
#define ICVDM_LBOUND    0x0004  /* Bounded at the left */
#define ICVDM_RBOUND    0x0008  /* Bounded at the right */
#define ICVDM_BOUNDS    0x000F  /* Mask of all bound types */
#define ICVDM_TRNSDCLIP 0x0010  /* No opaque parts in display clip */

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

#endif /* PREFS_ICONTROL_H */
