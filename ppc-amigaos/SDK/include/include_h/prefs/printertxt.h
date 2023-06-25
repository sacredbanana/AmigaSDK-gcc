#ifndef PREFS_PRINTERTXT_H
#define PREFS_PRINTERTXT_H
/*
**    $VER: printertxt.h 54.16 (22.08.2022)
**
**    File format for text printer preferences
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

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

#define ID_PTXT MAKE_ID('P','T','X','T')
#define ID_PUNT MAKE_ID('P','U','N','T')
#define ID_PDEV MAKE_ID('P','D','E','V')

#define DRIVERNAMESIZE 30 /* Filename size     */
#define DEVICENAMESIZE 32 /* .device name size */
#define UNITNAMESIZE   32 /* Unit name size    */

struct PrinterTxtPrefs
{
    LONG  pt_Reserved[4];            /* System reserved            */
    TEXT  pt_Driver[DRIVERNAMESIZE]; /* printer driver filename    */
    UBYTE pt_Port;                   /* printer port connection    */
    UBYTE pt_Flags;                  /* printer.device flags (V51) */

    UWORD pt_PaperType;
    UWORD pt_PaperSize;
    UWORD pt_PaperLength;            /* Paper length in # of lines */

    UWORD pt_Pitch;
    UWORD pt_Spacing;
    UWORD pt_LeftMargin;             /* Left margin                */
    UWORD pt_RightMargin;            /* Right margin               */
    UWORD pt_Quality;
};

/* constants for PrinterTxtPrefs.pt_Port */
#define PP_PARALLEL 0
#define PP_SERIAL   1

/* bit definitions for PrinterTxtPrefs.pt_Flags */
#define PF_REINITDRIVER 1

/* constants for PrinterTxtPrefs.pt_PaperType */
#define PT_FANFOLD  0
#define PT_SINGLE   1

/* constants for PrinterTxtPrefs.pt_PaperSize */
#define PS_US_LETTER   0
#define PS_US_LEGAL    1
#define PS_N_TRACTOR   2
#define PS_W_TRACTOR   3
#define PS_CUSTOM      4
#define PS_EURO_A0     5 /* European size A0: 841 x 1189 */
#define PS_EURO_A1     6 /* European size A1: 594 x  841 */
#define PS_EURO_A2     7 /* European size A2: 420 x  594 */
#define PS_EURO_A3     8 /* European size A3: 297 x  420 */
#define PS_EURO_A4     9 /* European size A4: 210 x  297 */
#define PS_EURO_A5    10 /* European size A5: 148 x  210 */
#define PS_EURO_A6    11 /* European size A6: 105 x  148 */
#define PS_EURO_A7    12 /* European size A7:  74 x  105 */
#define PS_EURO_A8    13 /* European size A8:  52 x   74 */

/* constants for PrinterTxtPrefs.pt_PrintPitch */
#define PP_PICA  0
#define PP_ELITE 1
#define PP_FINE  2

/* constants for PrinterTxtPrefs.pt_PrintSpacing */
#define PS_SIX_LPI   0
#define PS_EIGHT_LPI 1

/* constants for PrinterTxtPrefs.pt_PrintQuality */
#define PQ_DRAFT  0
#define PQ_LETTER 1

/* PrinterUnitPrefs is used from printer.device to open
   the connection device
*/
struct PrinterUnitPrefs
{
    LONG  pu_Reserved[4];                /* System reserved              */
    LONG  pu_UnitNum;                    /* Unit number for OpenDevice() */
    ULONG pu_OpenDeviceFlags;            /* Flags for OpenDevice()       */
    TEXT  pu_DeviceName[DEVICENAMESIZE]; /* Name for OpenDevice()        */
};

/* PrinterDeviceUnitPrefs is used as descriptor for printer device
   units.
*/
struct PrinterDeviceUnitPrefs
{
    LONG pd_Reserved[4];            /* System reserved              */
    LONG pd_UnitNum;                /* Unit number for OpenDevice() */
    TEXT pd_UnitName[UNITNAMESIZE]; /* Symbolic name of the unit    */
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

#endif /* PREFS_PRINTERTXT_H */
