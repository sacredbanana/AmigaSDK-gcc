#ifndef LIBRARIES_ASL_H
#define LIBRARIES_ASL_H
/*
**    $VER: asl.h 54.16 (22.08.2022)
**
**    ASL library structures and constants
**
**    Copyright (c) 1989-1990 Charlie Heath.
**    Copyright (c) 1985-2008 Hyperion Entertainment VOF and Amiga, Inc.
**    All Rights Reserved.
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**    All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef   WORKBENCH_STARTUP_H
#include <workbench/startup.h>
#endif

#ifndef   GRAPHICS_TEXT_H
#include <graphics/text.h>
#endif

#ifndef   GRAPHICS_DISPLAYINFO_H
#include <graphics/displayinfo.h>
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

#define AslName "asl.library"
#define ASL_Dummy (TAG_USER + 0x00080000)

/*****************************************************************************/

/* Types of requesters known to ASL, used as arguments to AllocAslRequest() */
#define ASL_FileRequest       0
#define ASL_FontRequest       1
#define ASL_ScreenModeRequest 2

/*****************************************************************************
 *
 * ASL File Requester data structures and constants
 *
 * This structure must only be allocated by asl.library amd is READ-ONLY!
 * Control of the various fields is provided via tags when the requester
 * is created with AllocAslRequest() and when it is displayed via
 * AslRequest()
 */
struct FileRequester
{
    uint8         fr_Reserved0[4];
    STRPTR        fr_File;            /* Contents of File gadget on exit    */
    STRPTR        fr_Drawer;          /* Contents of Drawer gadget on exit  */
    uint8         fr_Reserved1[10];
    int16         fr_LeftEdge;        /* Coordinates of requester on exit   */
    int16         fr_TopEdge;
    int16         fr_Width;
    int16         fr_Height;
    uint8         fr_Reserved2[2];
    int32         fr_NumArgs;         /* Number of files selected           */
    struct WBArg *fr_ArgList;         /* List of files selected             */
    APTR          fr_UserData;        /* You can store your own data here   */
    uint8         fr_Reserved3[8];
    STRPTR        fr_Pattern;         /* Contents of Pattern gadget on exit */
};

/* File requester tag values, used by AllocAslRequest() and AslRequest() */

#define ASLFR_Window              (ASL_Dummy + 2)
   /* (struct Window *) Parent window. */

#define ASLFR_Screen              (ASL_Dummy + 40)
   /* (struct Screen *) Screen if no window specified. */

#define ASLFR_PubScreenName       (ASL_Dummy + 41)
   /* (CONST_STRPTR) Name of public screen. */

#define ASLFR_PrivateIDCMP        (ASL_Dummy + 42)
   /* (BOOL) Allocate private IDCMP? */

#define ASLFR_IntuiMsgFunc        (ASL_Dummy + 70)
   /* (struct Hook *) IntuiMessages function. */

#define ASLFR_SleepWindow         (ASL_Dummy + 43)
   /* (BOOL) Block ASLFR_Window input? */

#define ASLFR_UserData            (ASL_Dummy + 52)
   /* (APTR) What to put in fr_UserData. */

#define ASLFR_PopToFront          (ASL_Dummy + 131)
   /* (BOOL) Make the requester window visible when it opens (V44) */

#define ASLFR_Activate            (ASL_Dummy + 132)
   /* (BOOL) Activate the requester window when it opens (V45). */

#define ASLFR_TextAttr            (ASL_Dummy + 51)
   /* (struct TextAttr *) Text font to use for gadget text. */

#define ASLFR_Locale              (ASL_Dummy + 50)
   /* (struct Locale *) Locale ASL should use for text. */

#define ASLFR_TitleText           (ASL_Dummy + 1)
   /* (CONST_STRPTR) Title of requester. */

#define ASLFR_PositiveText        (ASL_Dummy + 18)
   /* (CONST_STRPTR) Positive gadget text. */

#define ASLFR_NegativeText        (ASL_Dummy + 19)
   /* (CONST_STRPTR) Negative gadget text. */

#define ASLFR_InitialLeftEdge     (ASL_Dummy + 3)
   /* (int16) Initial requester left edge. */

#define ASLFR_InitialTopEdge      (ASL_Dummy + 4)
   /* (int16) Initial requester top edge. */

#define ASLFR_InitialWidth        (ASL_Dummy + 5)
   /* (int16) Initial requester width. */

#define ASLFR_InitialHeight       (ASL_Dummy + 6)
   /* (int16) Initial requester height. */

#define ASLFR_InitialFile         (ASL_Dummy + 8)
   /* (CONST_STRPTR) Initial contents of File gadget. */

#define ASLFR_InitialDrawer       (ASL_Dummy + 9)
   /* (CONST_STRPTR) Initial contents of Drawer gadget. */

#define ASLFR_InitialPattern      (ASL_Dummy + 10)
   /* (CONST_STRPTR) Initial contents of Pattern gadget. */

#define ASLFR_InitialShowVolumes  (ASL_Dummy + 130)
   /* (BOOL) Initially show the volume list. (V44) */

#define ASLFR_Flags1              (ASL_Dummy + 20)
   /* (uint32) Option flags (see defines below). */

#define ASLFR_Flags2              (ASL_Dummy + 22)
   /* (uint32) Additional option flags (see defines below). */

#define ASLFR_DoSaveMode          (ASL_Dummy + 44)
   /* (BOOL) Being used for saving? */

#define ASLFR_DoMultiSelect       (ASL_Dummy + 45)
   /* (BOOL) Do multi-select? */

#define ASLFR_DoPatterns          (ASL_Dummy + 46)
   /* (BOOL) Display a Pattern gadget? */

#define ASLFR_DrawersOnly         (ASL_Dummy + 47)
   /* (BOOL) Don't display files? */

#define ASLFR_FilterFunc          (ASL_Dummy + 49)
   /* DEPRECATED (see autodoc) */

#define ASLFR_RejectIcons         (ASL_Dummy + 60)
   /* (BOOL) Display .info files? */

#define ASLFR_RejectPattern       (ASL_Dummy + 61)
   /* (CONST_STRPTR) Don't display files matching pattern. */

#define ASLFR_AcceptPattern       (ASL_Dummy + 62)
   /* (CONST_STRPTR) Accept only files matching pattern. */

#define ASLFR_FilterDrawers       (ASL_Dummy + 63)
   /* (BOOL) Also filter drawers with patterns. */

#define ASLFR_HookFunc            (ASL_Dummy + 7)
   /* DEPRECATED (see autodoc) */

#define ASLFR_FilterHook          (ASL_Dummy + 141)
   /* (struct Hook *) Hook to filter files and directories. (V52.27) */

#define ASLFR_SetSortBy           (ASL_Dummy + 124)
   /* (uint32) Set sort criteria (see defines below). */

#define ASLFR_GetSortBy           (ASL_Dummy + 125)
   /* (uint32 *) Get sort criteria. */

#define ASLFR_SetSortDrawers      (ASL_Dummy + 126)
   /* (uint32) Set placement of drawers in the list (see defines below). */

#define ASLFR_GetSortDrawers      (ASL_Dummy + 127)
   /* (uint32 *) Get placement of drawers in the list. */

#define ASLFR_SetSortOrder        (ASL_Dummy + 128)
   /* (uint32) Set sort order (see defines below) */

#define ASLFR_GetSortOrder        (ASL_Dummy + 129)
   /* (uint32) Get sort order. */

#define ASLFR_StayOnTop           (ASL_Dummy + 142 )
   /* (BOOL) Force the requester to stay on top of other windows */
   
/* Flag bits for the ASLFR_Flags1 tag */
#define FRB_FILTERFUNC     7    // DEPRECATED
#define FRB_INTUIFUNC      6    // DEPRECATED
#define FRB_DOSAVEMODE     5
#define FRB_PRIVATEIDCMP   4
#define FRB_DOMULTISELECT  3
#define FRB_DOPATTERNS     0

#define FRF_FILTERFUNC     (1L << FRB_FILTERFUNC)   // DEPRECATED
#define FRF_INTUIFUNC      (1L << FRB_INTUIFUNC)    // DEPRECATED
#define FRF_DOSAVEMODE     (1L << FRB_DOSAVEMODE)
#define FRF_PRIVATEIDCMP   (1L << FRB_PRIVATEIDCMP)
#define FRF_DOMULTISELECT  (1L << FRB_DOMULTISELECT)
#define FRF_DOPATTERNS     (1L << FRB_DOPATTERNS)

/* Flag bits for the ASLFR_Flags2 tag */
#define FRB_DRAWERSONLY    0
#define FRB_FILTERDRAWERS  1
#define FRB_REJECTICONS    2

#define FRF_DRAWERSONLY    (1L << FRB_DRAWERSONLY)
#define FRF_FILTERDRAWERS  (1L << FRB_FILTERDRAWERS)
#define FRF_REJECTICONS    (1L << FRB_REJECTICONS)

/* Sort criteria for the ASLFR_SetSortBy/ASLFR_GetSortBy tags */
#define ASLFRSORTBY_Name   0
#define ASLFRSORTBY_Date   1
#define ASLFRSORTBY_Size   2

/* Drawer placement for the ASLFR_SetSortDrawers/ASLFR_GetSortDrawers tags */
#define ASLFRSORTDRAWERS_First  0
#define ASLFRSORTDRAWERS_Mix    1
#define ASLFRSORTDRAWERS_Last   2

/* Sort order for the ASLFR_SetSortOrder/ASLFR_GetSortOrder tags */
#define ASLFRSORTORDER_Ascend   0
#define ASLFRSORTORDER_Descend  1

/*****************************************************************************
 *
 * ASL Font Requester data structures and constants
 *
 * This structure must only be allocated by asl.library and is READ-ONLY!
 * Control of the various fields is provided via tags when the requester
 * is created with AllocAslRequest() and when it is displayed via
 * AslRequest()
 */
struct FontRequester
{
    uint8            fo_Reserved0[8];
    struct TextAttr  fo_Attr;           /* Returned TextAttr                */
    uint8            fo_FrontPen;       /* Returned front pen               */
    uint8            fo_BackPen;        /* Returned back pen                */
    uint8            fo_DrawMode;       /* Returned drawing mode            */
    uint8            fo_SpecialDrawMode;/* Returned special drawmode (V50)  */
    APTR             fo_UserData;       /* You can store your own data here */
    int16            fo_LeftEdge;       /* Coordinates of requester on exit */
    int16            fo_TopEdge;
    int16            fo_Width;
    int16            fo_Height;
    struct TTextAttr fo_TAttr;          /* Returned TTextAttr. Since V50 it
                                         * contains a pointer to a TagList
                                         * with the TA_CharSet tag if
                                         * ASLFO_InitialCharSet was specified
                                         */
};

/* Font requester tag values, used by AllocAslRequest() and AslRequest() */

#define ASLFO_Window          (ASL_Dummy + 2)
   /* (struct Window *) Parent window. */

#define ASLFO_Screen          (ASL_Dummy + 40)
   /* (struct Screen *) Screen to open on if no window. */

#define ASLFO_PubScreenName   (ASL_Dummy + 41)
   /* (CONST_STRPTR) Name of public screen. */

#define ASLFO_PrivateIDCMP    (ASL_Dummy + 42)
   /* (BOOL) Allocate private IDCMP? */

#define ASLFO_IntuiMsgFunc    (ASL_Dummy + 70)
   /* (struct Hook *) Function to handle IntuiMessages. */

#define ASLFO_SleepWindow     (ASL_Dummy + 43)
   /* (BOOL) Block input in ASLFO_Window? */

#define ASLFO_UserData        (ASL_Dummy + 52)
   /* (APTR) What to put in fo_UserData. */

#define ASLFO_PopToFront      (ASL_Dummy + 131)
   /* (BOOL) Make the requester window visible when it opens. (V44) */

#define ASLFO_Activate        (ASL_Dummy + 132)
   /* (BOOL) Activate the requester window when it opens. (V45) */

#define ASLFO_TextAttr        (ASL_Dummy + 51)
   /* (struct TextAttr *) Text font to use for gadget text. */

#define ASLFO_Locale          (ASL_Dummy + 50)
   /* (struct Locale *) Locale ASL should use for text. */

#define ASLFO_TitleText       (ASL_Dummy + 1)
   /* (CONST_STRPTR) Title of requester. */

#define ASLFO_PositiveText    (ASL_Dummy + 18)
   /* (CONST_STRPTR) Positive gadget text. */

#define ASLFO_NegativeText    (ASL_Dummy + 19)
   /* (CONST_STRPTR) Negative gadget text. */

#define ASLFO_InitialLeftEdge (ASL_Dummy + 3)
   /* (int16) Initial requester left edge. */

#define ASLFO_InitialTopEdge  (ASL_Dummy + 4)
   /* (int16) Initial requester top edge. */

#define ASLFO_InitialWidth    (ASL_Dummy + 5)
   /* (int16) Initial requester width. */

#define ASLFO_InitialHeight   (ASL_Dummy + 6)
   /* (int16) Initial requester height. */

#define ASLFO_InitialName     (ASL_Dummy + 10)
   /* (CONST_STRPTR) Initial contents of Name gadget. */

#define ASLFO_InitialSize     (ASL_Dummy + 11)
   /* (CONST_STRPTR) Initial contents of Size gadget. */

#define ASLFO_InitialStyle    (ASL_Dummy + 12)
   /* (uint8) Initial font style. */

#define ASLFO_InitialFlags    (ASL_Dummy + 13)
   /* (uint8) Initial font flags for TextAttr. */

#define ASLFO_InitialFrontPen (ASL_Dummy + 14)
   /* (uint8) Initial front pen. */

#define ASLFO_InitialBackPen  (ASL_Dummy + 15)
   /* (uint8) Initial back pen. */

#define ASLFO_InitialDrawMode (ASL_Dummy + 59)
   /* (uint8) Initial draw mode. */

#define ASLFO_InitialSpecMode (ASL_Dummy + 139)
   /* (uint8) Initial special drawmode (see defines below). (V50) */

#define ASLFO_InitialCharSet  (ASL_Dummy + 134)
   /* (uint32) Initial charset. (V50) */

#define ASLFO_Flags           (ASL_Dummy + 20)
   /* (uint32) Option flags. */

#define ASLFO_DoFrontPen      (ASL_Dummy + 44)
   /* (BOOL) Display Front color selector? */

#define ASLFO_DoBackPen       (ASL_Dummy + 45)
   /* (BOOL) Display Back color selector? */

#define ASLFO_DoStyle         (ASL_Dummy + 46)
   /* (BOOL) Display Style checkboxes? */

#define ASLFO_DoDrawMode      (ASL_Dummy + 47)
   /* (BOOL) Display DrawMode cycle gadget? */

#define ASLFO_DoSpecialMode   (ASL_Dummy + 140)
   /* (BOOL) Display DrawMode cycle gadget with options Text,
    * Text+Background, Text+Outline, Text+Shadow? (V50) */

#define ASLFO_DoCharSet       (ASL_Dummy + 135)
   /* (BOOL) Display CharSet selector? (V50) */

#define ASLFO_SampleText      (ASL_Dummy + 133)
   /* (CONST_STRPTR) Text to display in font sample area. (V45) */

#define ASLFO_FixedWidthOnly  (ASL_Dummy + 48)
   /* (BOOL) Only allow fixed-width fonts? */

#define ASLFO_OTagOnly        (ASL_Dummy + 136)
   /* (BOOL) Only allow bullet API fonts? (V50) */

#define ASLFO_ScalableOnly    (ASL_Dummy + 137)
   /* (BOOL) Only allow scalable bullet API fonts? (V50) */

#define ASLFO_MinHeight       (ASL_Dummy + 16)
   /* (uint16) Minimum font height to display. */

#define ASLFO_MaxHeight       (ASL_Dummy + 17)
   /* (uint16) Maximum font height to display. */

#define ASLFO_FilterFunc      (ASL_Dummy + 49)
   /* (struct Hook *) Function to filter fonts. */

#define ASLFO_CSFilterFunc    (ASL_Dummy + 138)
   /* (struct Hook *) Function to filter charsets. */

#define ASLFO_HookFunc        (ASL_Dummy + 7)
   /* DEPRECATED (see autodoc) */

#define ASLFO_MaxFrontPen     (ASL_Dummy + 66)
   /* (uint8) Max # of colors in front palette. */

#define ASLFO_MaxBackPen      (ASL_Dummy + 67)
   /* (uint8) Max # of colors in back palette. */

#define ASLFO_ModeList        (ASL_Dummy + 21)
   /* (CONST_STRPTR *) Substitute list for drawmodes. */

#define ASLFO_FrontPens       (ASL_Dummy + 64)
   /* (uint8 *) Color table for front pen palette. */

#define ASLFO_BackPens        (ASL_Dummy + 65)
   /* (uint8 *) Color table for back pen palette. */

#define ASLFO_StayOnTop       (ASL_Dummy + 142 )
   /* (BOOL) Force the requester to stay on top of other windows */

#define ASLFO_SpecialModeBitMap (ASL_Dummy + 143)
   /* (struct BitMap *) BitMap to show behind the font preview in special mode */

#define ASLFO_SpecialModeBitMapWidth (ASL_Dummy + 144)
   /* (int32) Width of the BitMap */

#define ASLFO_SpecialModeBitMapHeight (ASL_Dummy + 145)
   /* (int32) Height of the BitMap */

/* Flag bits for ASLFO_Flags tag */
#define FOB_DOFRONTPEN     0
#define FOB_DOBACKPEN      1
#define FOB_DOSTYLE        2
#define FOB_DODRAWMODE     3
#define FOB_FIXEDWIDTHONLY 4
#define FOB_PRIVATEIDCMP   5
#define FOB_INTUIFUNC      6    // DEPRECATED
#define FOB_FILTERFUNC     7    // DEPRECATED

#define FOF_DOFRONTPEN     (1L << FOB_DOFRONTPEN)
#define FOF_DOBACKPEN      (1L << FOB_DOBACKPEN)
#define FOF_DOSTYLE        (1L << FOB_DOSTYLE)
#define FOF_DODRAWMODE     (1L << FOB_DODRAWMODE)
#define FOF_FIXEDWIDTHONLY (1L << FOB_FIXEDWIDTHONLY)
#define FOF_PRIVATEIDCMP   (1L << FOB_PRIVATEIDCMP)
#define FOF_INTUIFUNC      (1L << FOB_INTUIFUNC)    // DEPRECATED
#define FOF_FILTERFUNC     (1L << FOB_FILTERFUNC)   // DEPRECATED

/* Values for ASLFO_InitialSpecMode and fo_SpecialDrawMode (V50) */
#define FO_SPECIALMODE_NONE    0 /* Normal text   */
#define FO_SPECIALMODE_OUTLINE 1 /* Outlined text */
#define FO_SPECIALMODE_SHADOW  2 /* Shadowed text */

/*****************************************************************************
 *
 * ASL Screen Mode Requester data structures and constants
 *
 * This structure must only be allocated by asl.library and is READ-ONLY!
 * Control of the various fields is provided via tags when the requester
 * is created with AllocAslRequest() and when it is displayed via
 * AslRequest()
 */
struct ScreenModeRequester
{
    uint32 sm_DisplayID;            /* Display mode ID                  */
    uint32 sm_DisplayWidth;         /* Width of display in pixels       */
    uint32 sm_DisplayHeight;        /* Height of display in pixels      */
    uint16 sm_DisplayDepth;         /* Number of bit-planes of display  */
    uint16 sm_OverscanType;         /* Type of overscan of display      */
    BOOL   sm_AutoScroll;           /* Display should auto-scroll?      */

    uint32 sm_BitMapWidth;          /* Used to create your own BitMap   */
    uint32 sm_BitMapHeight;

    int16  sm_LeftEdge;             /* Coordinates of requester on exit */
    int16  sm_TopEdge;
    int16  sm_Width;
    int16  sm_Height;

    BOOL  sm_InfoOpened;           /* Info window opened on exit?      */
    int16 sm_InfoLeftEdge;         /* Last coordinates of Info window  */
    int16 sm_InfoTopEdge;
    int16 sm_InfoWidth;
    int16 sm_InfoHeight;

    APTR  sm_UserData;             /* You can store your own data here */
};

/* An Exec list of custom modes can be added to the list of available modes.
 * The DimensionInfo structure must be completely initialized, including the
 * Header. See <graphics/displayinfo.h>. Custom mode ID's must be in the range
 * 0xFFFF0000..0xFFFFFFFF. Regular properties which apply to your custom modes
 * can be added in the dn_PropertyFlags field. Custom properties are not
 * allowed.
 */
struct DisplayMode
{
    struct Node          dm_Node;             /* see ln_Name           */
    struct DimensionInfo dm_DimensionInfo;    /* mode description      */
    uint32               dm_PropertyFlags;    /* applicable properties */
};

/* ScreenMode requester tag values, used by AllocAslRequest() and
 * AslRequest()
 */

#define ASLSM_Window               (ASL_Dummy + 2)
   /* (struct Window *) Parent window. */

#define ASLSM_Screen               (ASL_Dummy + 40)
   /* (struct Screen *) Screen to open on if no window. */

#define ASLSM_PubScreenName        (ASL_Dummy + 41)
   /* (CONST_STRPTR) Name of public screen. */

#define ASLSM_PrivateIDCMP         (ASL_Dummy + 42)
   /* (BOOL) Allocate private IDCMP? */

#define ASLSM_IntuiMsgFunc         (ASL_Dummy + 70)
   /* (struct Hook *) Function to handle IntuiMessages. */

#define ASLSM_SleepWindow          (ASL_Dummy + 43)
   /* (BOOL) Block input in ASLSM_Window? */

#define ASLSM_UserData             (ASL_Dummy + 52)
   /* (APTR) What to put in sm_UserData. */

#define ASLSM_PopToFront           (ASL_Dummy + 131)
   /* (BOOL) Make the requester window visible when it opens. (V44) */

#define ASLSM_Activate             (ASL_Dummy + 132)
   /* (BOOL) Activate the requester window when it opens. (V45) */

#define ASLSM_TextAttr             (ASL_Dummy + 51)
   /* (struct TextAttr *) Text font to use for gadget text. */

#define ASLSM_Locale               (ASL_Dummy + 50)
   /* (struct Locale *) Locale ASL should use for text. */

#define ASLSM_TitleText            (ASL_Dummy + 1)
   /* (CONST_STRPTR) Title of requester. */

#define ASLSM_PositiveText         (ASL_Dummy + 18)
   /* (CONST_STRPTR) Positive gadget text. */

#define ASLSM_NegativeText         (ASL_Dummy + 19)
   /* (CONST_STRPTR) Negative gadget text. */

#define ASLSM_InitialLeftEdge      (ASL_Dummy + 3)
   /* (int16) Initial requester left edge. */

#define ASLSM_InitialTopEdge       (ASL_Dummy + 4)
   /* (int16) Initial requester top edge. */

#define ASLSM_InitialWidth         (ASL_Dummy + 5)
   /* (int16) Initial requester width. */

#define ASLSM_InitialHeight        (ASL_Dummy + 6)
   /* (int16) Initial requester height. */

#define ASLSM_InitialDisplayID     (ASL_Dummy + 100)
   /* (uint32) Initial display mode id. */

#define ASLSM_InitialDisplayWidth  (ASL_Dummy + 101)
   /* (uint32) Initial display width. */

#define ASLSM_InitialDisplayHeight (ASL_Dummy + 102)
   /* (uint32) Initial display height. */

#define ASLSM_InitialDisplayDepth  (ASL_Dummy + 103)
   /* (uint16) Initial display depth. */

#define ASLSM_InitialOverscanType  (ASL_Dummy + 104)
   /* (uint16) Initial type of overscan. */

#define ASLSM_InitialAutoScroll    (ASL_Dummy + 105)
   /* (BOOL) Initial autoscroll setting. */

#define ASLSM_InitialInfoOpened    (ASL_Dummy + 106)
   /* (BOOL) Info window initially opened? */

#define ASLSM_InitialInfoLeftEdge  (ASL_Dummy + 107)
   /* (int16) Initial Info window left edge. */

#define ASLSM_InitialInfoTopEdge   (ASL_Dummy + 108)
   /* (int16) Initial Info window top edge. */

#define ASLSM_DoWidth              (ASL_Dummy + 109)
   /* (BOOL) Display Width gadget? */

#define ASLSM_DoHeight             (ASL_Dummy + 110)
   /* (BOOL) Display Height gadget? */

#define ASLSM_DoDepth              (ASL_Dummy + 111)
   /* (BOOL) Display Depth gadget? */

#define ASLSM_DoOverscanType       (ASL_Dummy + 112)
   /* (BOOL) Display Overscan Type gadget? */

#define ASLSM_DoAutoScroll         (ASL_Dummy + 113)
   /* (BOOL) Display AutoScroll gadget? */

#define ASLSM_PropertyFlags        (ASL_Dummy + 114)
   /* (uint32) Must have these Property flags. */

#define ASLSM_PropertyMask         (ASL_Dummy + 115)
   /* (uint32) Only these should be looked at. */

#define ASLSM_MinWidth             (ASL_Dummy + 116)
   /* (uint32) Minimum display width to allow. */

#define ASLSM_MaxWidth             (ASL_Dummy + 117)
   /* (uint32) Maximum display width to allow. */

#define ASLSM_MinHeight            (ASL_Dummy + 118)
   /* (uint32) Minimum display height to allow. */

#define ASLSM_MaxHeight            (ASL_Dummy + 119)
   /* (uint32) Maximum display height to allow. */

#define ASLSM_MinDepth             (ASL_Dummy + 120)
   /* (uint16) Minimum display depth. */

#define ASLSM_MaxDepth             (ASL_Dummy + 121)
   /* (uint16) Maximum display depth. */

#define ASLSM_FilterFunc           (ASL_Dummy + 122)
   /* (struct Hook *) Function to filter mode id's. */

#define ASLSM_CustomSMList         (ASL_Dummy + 123)
   /* (struct List *) Exec list of struct DisplayMode. */

#define ASLSM_StayOnTop            (ASL_Dummy + 142 )
   /* (BOOL) Force the requester to stay on top of other windows */


/*****************************************************************************
 *
 * Obsolete ASL definitions, here for source code compatibility only.
 * Please do NOT use in new code.
 *
 * #define ASL_PRE_V38_NAMES if you really need these older names.
 */
#ifdef ASL_PRE_V38_NAMES
#define rf_File          fr_File
#define rf_Dir           fr_Drawer
#define rf_LeftEdge      fr_LeftEdge
#define rf_TopEdge       fr_TopEdge
#define rf_Width         fr_Width
#define rf_Height        fr_Height
#define rf_NumArgs       fr_NumArgs
#define rf_ArgList       fr_ArgList
#define rf_UserData      fr_UserData
#define rf_Pat           fr_Pattern
#define ASL_Hail         ASL_Dummy+1
#define ASL_Window       ASL_Dummy+2
#define ASL_LeftEdge     ASL_Dummy+3
#define ASL_TopEdge      ASL_Dummy+4
#define ASL_Width        ASL_Dummy+5
#define ASL_Height       ASL_Dummy+6
#define ASL_HookFunc     ASL_Dummy+7
#define ASL_File         ASL_Dummy+8
#define ASL_Dir          ASL_Dummy+9
#define ASL_FontName     ASL_Dummy+10
#define ASL_FontHeight   ASL_Dummy+11
#define ASL_FontStyles   ASL_Dummy+12
#define ASL_FontFlags    ASL_Dummy+13
#define ASL_FrontPen     ASL_Dummy+14
#define ASL_BackPen      ASL_Dummy+15
#define ASL_MinHeight    ASL_Dummy+16
#define ASL_MaxHeight    ASL_Dummy+17
#define ASL_OKText       ASL_Dummy+18
#define ASL_CancelText   ASL_Dummy+19
#define ASL_FuncFlags    ASL_Dummy+20
#define ASL_ModeList     ASL_Dummy+21
#define ASL_ExtFlags1    ASL_Dummy+22
#define ASL_Pattern      ASL_FontName
/* remember what I said up there? Do not use these anymore! */
#define FILB_DOWILDFUNC  7L
#define FILB_DOMSGFUNC   6L
#define FILB_SAVE        5L
#define FILB_NEWIDCMP    4L
#define FILB_MULTISELECT 3L
#define FILB_PATGAD      0L
#define FILF_DOWILDFUNC  (1L << FILB_DOWILDFUNC)
#define FILF_DOMSGFUNC   (1L << FILB_DOMSGFUNC)
#define FILF_SAVE        (1L << FILB_SAVE)
#define FILF_NEWIDCMP    (1L << FILB_NEWIDCMP)
#define FILF_MULTISELECT (1L << FILB_MULTISELECT)
#define FILF_PATGAD      (1L << FILB_PATGAD)
#define FIL1B_NOFILES    0L
#define FIL1B_MATCHDIRS  1L
#define FIL1F_NOFILES    (1L << FIL1B_NOFILES)
#define FIL1F_MATCHDIRS  (1L << FIL1B_MATCHDIRS)
#define FONB_FRONTCOLOR 0
#define FONB_BACKCOLOR  1
#define FONB_STYLES     2
#define FONB_DRAWMODE   3
#define FONB_FIXEDWIDTH 4
#define FONB_NEWIDCMP   5
#define FONB_DOMSGFUNC  6
#define FONB_DOWILDFUNC 7
#define FONF_FRONTCOLOR (1L << FONB_FRONTCOLOR)
#define FONF_BACKCOLOR  (1L << FONB_BACKCOLOR)
#define FONF_STYLES     (1L << FONB_STYLES)
#define FONF_DRAWMODE   (1L << FONB_DRAWMODE)
#define FONF_FIXEDWIDTH (1L << FONB_FIXEDWIDTH)
#define FONF_NEWIDCMP   (1L << FONB_NEWIDCMP)
#define FONF_DOMSGFUNC  (1L << FONB_DOMSGFUNC)
#define FONF_DOWILDFUNC (1L << FONB_DOWILDFUNC)
#endif

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

#endif /* LIBRARIES_ASL_H */
