#ifndef PREFS_ASL_H
#define PREFS_ASL_H
/*
**    $VER: asl.h 54.16 (22.08.2022)
**
**    File format for ASL ("application support library") preferences
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

#ifndef   LIBRARIES_ASL_H
#include <libraries/asl.h>
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

#define ID_ASL MAKE_ID('A','S','L',' ')

struct AslPrefs
{
    int32  ap_Reserved[4];

    /* These members correspond directly to the associated
     * members of the 'AslSemaphore' data structure defined
     * in the <libraries/asl.h> header file by the same names.
     */
    uint8  ap_SortBy;
    uint8  ap_SortDrawers;
    uint8  ap_SortOrder;

    uint8  ap_SizePosition;

    int16  ap_RelativeLeft;
    int16  ap_RelativeTop;

    uint8  ap_RelativeWidth;
    uint8  ap_RelativeHeight;

    uint8  ap_MidButtonAction;
    uint8  ap_4thButtonAction;
    uint8  ap_5thButtonAction;

    uint16 ap_ShowColumns;

    uint8  ap_Striping;

    uint8  ap_FileStyle;
    uint8  ap_DrawerStyle;
    uint8  ap_LinkStyle;
};

/* Button actions */
#define ASLFRACTION_Nothing     0   /* Do nothing */
#define ASLFRACTION_Volumes     1   /* Volumes button */
#define ASLFRACTION_Parent      2   /* Parent button */
#define ASLFRACTION_Rename      3   /* Rename menu option */

/* Flag bits for showing columns */
#define FRB_SHOWSIZE            0   /* Show Size column */
#define FRB_SHOWTYPE            1   /* Show Type column */
#define FRB_SHOWPROTECTION      2   /* Show Protection column */
#define FRB_SHOWDATE            3   /* Show Date column */
#define FRB_SHOWCOMMENT         4   /* Show Comment column */

#define FRF_SHOWSIZE            (1L << FRB_SHOWSIZE)
#define FRF_SHOWTYPE            (1L << FRB_SHOWTYPE)
#define FRF_SHOWPROTECTION      (1L << FRB_SHOWPROTECTION)
#define FRF_SHOWDATE            (1L << FRB_SHOWDATE)
#define FRF_SHOWCOMMENT         (1L << FRB_SHOWCOMMENT)

/* Flag bits for striping */
#define FRB_ROWSTRIPES          0   /* Show row stripes */

#define FRF_ROWSTRIPES          (1L << FRB_ROWSTRIPES)

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

#endif /* PREFS_ASL_H */
