#ifndef PREFS_PRINTERPS_H
#define PREFS_PRINTERPS_H
/*
**    $VER: printerps.h 54.16 (22.08.2022)
**
**    File format for PostScript printer preferences
**
**    Copyright (C) 1985-2007 Hyperion Entertainment VOF and Amiga, Inc.
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

#define ID_PSPD MAKE_ID('P','S','P','D')

struct PrinterPSPrefs
{
    int32 ps_Reserved[4]; /* System reserved */

    /* Global printing attributes */
    uint8 ps_DriverMode;
    uint8 ps_PaperFormat;
    uint8 ps_Reserved1[2];
    int32 ps_Copies;
    int32 ps_PaperWidth;
    int32 ps_PaperHeight;
    int32 ps_HorizontalDPI;
    int32 ps_VerticalDPI;

    /* Text Options */
    uint8 ps_Font;
    uint8 ps_Pitch;
    uint8 ps_Orientation;
    uint8 ps_Tab;
    uint8 ps_Reserved2[8];

    /* Text Dimensions */
    int32 ps_LeftMargin;
    int32 ps_RightMargin;
    int32 ps_TopMargin;
    int32 ps_BottomMargin;
    int32 ps_FontPointSize;
    int32 ps_Leading;
    uint8 ps_Reserved3[8];

    /* Graphics Options */
    int32 ps_LeftEdge;
    int32 ps_TopEdge;
    int32 ps_Width;
    int32 ps_Height;
    uint8 ps_Image;
    uint8 ps_Shading;
    uint8 ps_Dithering;
    uint8 ps_Reserved4[9];

    /* Graphics Scaling */
    uint8 ps_Aspect;
    uint8 ps_ScalingType;
    uint8 ps_Reserved5;
    uint8 ps_Centering;
    uint8 ps_Reserved6[8];
};

/* All measurements are in Millipoints which is 1/1000 of a point, or
 * in other words 1/72000 of an inch
 */

/* constants for PrinterPSPrefs.ps_DriverMode */
#define DM_POSTSCRIPT  0
#define DM_PASSTHROUGH 1

/* constants for PrinterPSPrefs.ps_PaperFormat */
#define PF_USLETTER  0
#define PF_USLEGAL   1
#define PF_A4        2
#define PF_CUSTOM    3
/* The following were added with V52.4 of the PrinterPS prefs editor */
#define PF_A0        4
#define PF_A1        5
#define PF_A2        6
#define PF_A3        7
#define PF_A5        8
#define PF_A6        9
#define PF_A7       10
#define PF_A8       11
#define PF_A9       12
#define PF_A10      13
#define PF_B0       14
#define PF_B1       15
#define PF_B2       16
#define PF_B3       17
#define PF_B4       18
#define PF_B5       19
#define PF_B6       20
#define PF_B7       21
#define PF_B8       22
#define PF_B9       23
#define PF_B10      24
#define PF_C0       25
#define PF_C1       26
#define PF_C2       27
#define PF_C3       28
#define PF_C4       29
#define PF_C5       30
#define PF_C6       31
#define PF_C7       32
#define PF_C8       33
#define PF_C9       34
#define PF_C10      35

/* constants for PrinterPSPrefs.ps_Font */
#define FONT_COURIER      0
#define FONT_TIMES        1
#define FONT_HELVETICA    2
#define FONT_HELV_NARROW  3
#define FONT_AVANTGARDE   4
#define FONT_BOOKMAN      5
#define FONT_NEWCENT      6
#define FONT_PALATINO     7
#define FONT_ZAPFCHANCERY 8

/* constants for PrinterPSPrefs.ps_Pitch */
#define PITCH_NORMAL     0
#define PITCH_COMPRESSED 1
#define PITCH_EXPANDED   2

/* constants for PrinterPSPrefs.ps_Orientation */
#define ORIENT_PORTRAIT  0
#define ORIENT_LANDSCAPE 1

/* constants for PrinterPSPrefs.ps_Tab */
#define TAB_4     0
#define TAB_8     1
#define TAB_QUART 2
#define TAB_HALF  3
#define TAB_INCH  4

/* constants for PrinterPSPrefs.ps_Image */
#define IM_POSITIVE 0
#define IM_NEGATIVE 1

/* constants for PrinterPSPrefs.ps_Shading */
#define SHAD_BW        0
#define SHAD_GREYSCALE 1
#define SHAD_COLOR     2

/* constants for PrinterPSPrefs.ps_Dithering */
#define DITH_DEFAULT 0
#define DITH_DOTTY   1
#define DITH_VERT    2
#define DITH_HORIZ   3
#define DITH_DIAG    4

/* constants for PrinterPSPrefs.ps_Aspect */
#define ASP_HORIZ 0
#define ASP_VERT  1

/* constants for PrinterPSPrefs.ps_ScalingType */
#define ST_ASPECT_ASIS 0
#define ST_ASPECT_WIDE 1
#define ST_ASPECT_TALL 2
#define ST_ASPECT_BOTH 3
#define ST_FITS_WIDE   4
#define ST_FITS_TALL   5
#define ST_FITS_BOTH   6

/* constants for PrinterPSPrefs.ps_Centering */
#define CENT_NONE  0
#define CENT_HORIZ 1
#define CENT_VERT  2
#define CENT_BOTH  3

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

#endif /* PREFS_PRINTERPS_H */
