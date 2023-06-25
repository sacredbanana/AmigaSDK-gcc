#ifndef PREFS_WORKBENCH_H
#define PREFS_WORKBENCH_H
/*
**    $VER: workbench.h 54.16 (22.08.2022)
**
**    Workbench preferences file definitions
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

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

#define ID_WBNC MAKE_ID('W','B','N','C')

struct WorkbenchPrefs
{
    /* settings from workbench.library */
    ULONG            wbp_DefaultStackSize;  /* in bytes */
    ULONG            wbp_TypeRestartTime;   /* in seconds */
    /* settings from icon.library */
    ULONG            wbp_IconPrecision;     /* PRECISION_#? values */
    struct Rectangle wbp_EmbossRect;
    BOOL             wbp_Borderless;
    LONG             wbp_MaxNameLength;
    BOOL             wbp_NewIconsSupport;
    BOOL             wbp_ColorIconSupport;
    /* new for V45 */
    ULONG            wbp_ImageMemType;
    BOOL             wbp_LockPens;
    BOOL             wbp_NoTitleBar;
    BOOL             wbp_NoGauge;
    /* new for V50 */
    BOOL             wbp_ColumnDragging;
    UWORD            wbp_BlinkDuration;     /* in milliseconds */
    BOOL             wbp_LiveDragSelect;
    UWORD            wbp_BlinkRate;         /* in hertz */
    /* new for V51 */
    UWORD            wbp_TitleUpdateDelay;  /* in milliseconds */
    ULONG            wbp_CopyBufferSize;    /* in bytes */
    BOOL             wbp_LeftOutMarking;
    UBYTE            wbp_IconTransparency[4];
    BOOL             wbp_AllowTranspDefDisks;
    BOOL             wbp_LabelDragging;
    UBYTE            wbp_SelectEffect[8];   /* type + parameters */
    /* new for V52 */
    ULONG            wbp_TextColor[5];      /* bg, file, drawer, link, attrs */
    UBYTE            wbp_TextFlags[4];      /* as above, minus attrs */
    UBYTE            wbp_ReservedByte;
    UBYTE            wbp_TextIconMinSize;   /* 0 == off, 1 == auto, or 8..256 - 1 */
    UBYTE            wbp_TextDragTransparency;
    UBYTE            wbp_AutoCloseParent;
    ULONG            wbp_Flags;             /* assorted options */
    UBYTE            wbp_Reserved[4];
    /* new for V53 */
    UWORD            wbp_IconScaleFactor[4];
    UWORD            wbp_IconSizeBounds[8];
    UWORD            wbp_PreviewWidth;
    UWORD            wbp_PreviewHeight;
    UBYTE            wbp_PreviewFrameMode;
    UBYTE            wbp_PreviewInfoMode;
    WORD             wbp_PreviewInfoYDelta;
    ULONG            wbp_PreviewCacheLimit;
    ULONG            wbp_Reserved2[5];
};

/* Values for wbp_Flags */
#define WBF_DRAWERPOSMASK 0x00000003  /* Drawer placement mask (text mode) */
#define WBF_DRAWERPOSFREE 0x00000000  /* Place drawers mixed with files */
#define WBF_DRAWERPOSHEAD 0x00000001  /* Place drawers at top of list */
#define WBF_DRAWERPOSTAIL 0x00000002  /* Place drawers at bottom of list */
#define WBF_COLUMNHEADERS 0x00000010  /* Text columns have clickable headers */
#define WBF_MERGESIZETYPE 0x00000020  /* Use same column for size and type */
#define WBF_SHOWFILETYPES 0x00000040  /* Show detailed file types */
#define WBF_BOUNDTEXTVIEW 0x00000080  /* Limit drawer scrolling in text mode */
#define WBF_COLUMNSTRIPES 0x00000100  /* Vertical striping in text mode */
#define WBF_NOAUTOUPDATES 0x00001000  /* No auto update of drawer contents */
#define WBF_NEWDATESFIRST 0x00010000  /* By default show newest files first */

#define ID_WBHD MAKE_ID('W','B','H','D')

struct WorkbenchHiddenDevicePrefs
{
    TEXT whdp_Name[0]; /* C String including NULL char */
};

#define ID_WBTF MAKE_ID('W','B','T','F')

struct WorkbenchTitleFormatPrefs
{
    TEXT wtfp_Format[0];
};

#define ID_WBPC MAKE_ID('W','B','P','C')

struct WorkbenchPreviewCachePrefs
{
    TEXT wtpc_Path[0];
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

#endif /* PREFS_WORKBENCH_H */
