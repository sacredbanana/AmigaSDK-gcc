#ifndef LIBRARIES_DOCKY_H
#define LIBRARIES_DOCKY_H

/*
**    $VER: docky.h 54.16 (22.08.2022)
**
**    Structure and method definitions for the docky library system.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif

/******************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/******************************************************************************/

#define DOCKYVERSION   ((uint32)(((  53  )<<16)|(  1  )))
#define DOCKYINITSTAGE_ZERO 0
#define DOCKYINITSTAGE_ONE  1



/*
** --- Docky Init Sequence ---
**
** The following steps are the typical sequence how AmiDock opens a docky.
**
**  DockyGet(DOCKYGET_Version, ...);
**  DockySet(DOCKYSET_DockyFileName, ...); -> not done for an AppDocky
**  DockySet(DOCKYSET_DockyAttention, ...);
**  DockySet(DOCKYSET_DockyPrefs, ...);
**  DockySet(DOCKYSET_Screen, ...);
**  DockySet(DOCKYSET_Window, ...);
**  DockySet(DOCKYSET_DockTypeChange, ...);
**  DockySet(DOCKYSET_DockOrientationChange, ...);
**  DockyGet(DOCKYGET_InvisibleProcess, ...);
**  DockyGet(DOCKYGET_Notifications, ...);
**  DockyGet(DOCKYGET_FrameDelay, ...);
**  [- future expansion -]
**  DockySet(DOCKYSET_DockFontChange, ...);
**  DockyGet(DOCKYGET_RenderMode, ...);
**  DockyGet(DOCKYGET_ShowsName, ...);
**  DockySet(DOCKYSET_DockScaleFactor, ...);
**  DockyGet(DOCKYGET_GetSize, ...);
**  DockyGet(DOCKYGET_SupportsComposite, ...);
**  DockyGet(DOCKYGET_CompositeMode, ...);
**  DockyGet(DOCKYSET_RenderDestination, ...);
*/


struct DockyPosition
{
	int32 x, y;
};

struct DockySize
{
	int32 width, height;
};

struct DockyAbsPosition
{
	struct DockyPosition absPos;
	struct DockyPosition dockyPos;
};

struct DockyPosSize
{
	struct DockyPosition pos;
	struct DockySize size;
};


struct DockyRenderDestination
{
	uint32 renderMode; // enum enDockyRenderMode
	struct DockySize renderSize;

	UBYTE pad[4]; // for future extension

	union
	{
		UBYTE *map; // currently unused
		struct RastPort *RP; // RP->BitMap is of type RGBFB_ALPHA8
	} alpha;

	union
	{
		UBYTE *RGB;
		struct RastPort *RP;
	} render;
};

struct DockyCategoryNr
{
	int32 dockNr;
	int32 categoryNr;
};

struct DockyObjectNr
{
	int32 dockNr;
	int32 categoryNr;
	int32 objectNr;
};

struct DockyDockyDND
{
	struct DockyPosition pos;
	STRPTR objectPath;
};

struct DockyObjectDND
{
	struct DockyObjectNr obj;
	STRPTR objectPath;
};

struct DockyDockPosition
{
	int32 dockNr;
	struct DockyPosition pos;
};

struct DockyObjectClick
{
	struct DockyObjectNr obj;
	STRPTR objectPath;
};

struct DockyDockMove
{
	int32 oldDockNr;
	int32 newDockNr;
};

struct DockyCategoryMove
{
	int32 dockNr;
	int32 oldCategoryNr;
	int32 newCategoryNr;
};

struct DockyObjectMove
{
	struct DockyCategoryNr cat;
	int32 oldObjectNr;
	int32 newObjectNr;
};

struct DockyDockSize
{
	struct DockyCategoryNr cat;
	struct DockySize size;
};

struct DockyDockInfo
{
	int32 dockNr;
	STRPTR dockName;
};

struct DockyCategoryInfo
{
	struct DockyCategoryNr cat;
	STRPTR categoryName;
};

struct DockyObjectInfo
{
	struct DockyObjectNr obj;
	STRPTR objectPath;
	STRPTR objectName; // ignored on insert!
	STRPTR objectIcon; // 53.1
};

struct DockyUnHideAnim
{
	int32 dockNr;
	int32 fromX, fromY;
};

struct DockyDockState
{
	int32 dockNr;
	int32 state;
};

struct DockyDockBackground
{
	int32 dockNr;
	STRPTR imagePath;
};

struct DockyDockFont
{
	int32 dockNr;
	struct TextAttr *ta;
	uint8 frontPen;
	uint8 backPen;
	uint8 drawMode;
};

struct DockyDockType
{
	int32 dockNr;
	uint32 dockType; // enum enAmiDockDockType
};

struct DockyRunWB
{
	STRPTR fileName; // program or directory
	STRPTR argument; // additional argument for a program
};

enum enDockyDebugMode
{
	DOCKYDEBUGMODE_PreProcess    = 1,
	DOCKYDEBUGMODE_ProcessResult = 2,
	DOCKYDEBUGMODE_Response      = 3,
	DOCKYDEBUGMODE_Message       = 4
};

struct DockyDebug
{
	struct DockyObjectNr obj;
	STRPTR dockyName;
	uint32 mode;

	uint32 turnCount;
	uint32 msgType;
	uint32 msgData;
	BOOL anotherTurn;

	STRPTR message;
};

struct DockyAttention
{
	struct Task *amidockTask;
	BYTE attentionSignalBit;
};

// --- AmiDock stuff

enum enAmiDockDockWindow
{
	AMIDOCK_DockWindow_Horizontal_L          = 0,
	AMIDOCK_DockWindow_Horizontal_R          = 1,
	AMIDOCK_DockWindow_Vertical_T            = 2,
	AMIDOCK_DockWindow_Vertical_B            = 3,
	AMIDOCK_DockWindow__Count                = 4
};

enum enAmiDockSnapTo
{
	AMIDOCK_SnapTo_None           = 0,
	AMIDOCK_SnapTo_Locked         = 1,
	AMIDOCK_SnapTo_Top            = 2,
	AMIDOCK_SnapTo_TopLeft        = 3,
	AMIDOCK_SnapTo_TopRight       = 4,
	AMIDOCK_SnapTo_Left           = 5,
	AMIDOCK_SnapTo_Right          = 6,
	AMIDOCK_SnapTo_Bottom         = 7,
	AMIDOCK_SnapTo_BottomLeft     = 8,
	AMIDOCK_SnapTo_BottomRight    = 9,
	AMIDOCK_SnapTo_BottomCentered = 10,
	AMIDOCK_SnapTo_TopCentered    = 11,
	AMIDOCK_SnapTo_LeftCentered   = 12,
	AMIDOCK_SnapTo_RightCentered  = 13,
	AMIDOCK_SnapTo__Count         = 14
};

enum enAmiDockIconName
{
	AMIDOCK_IconName_None      = 0,
	AMIDOCK_IconName_FullLine  = 1,
	AMIDOCK_IconName_One       = 2,
	AMIDOCK_IconName_Two       = 3,
	AMIDOCK_IconName_Three     = 4,
	AMIDOCK_IconName_Full      = 5,
	AMIDOCK_IconName__Count    = 6
};

enum enAmiDockDockType
{
	AMIDOCK_DockType_Icons     = 0,
	AMIDOCK_DockType_Names     = 1,
	AMIDOCK_DockType_Buttons   = 2,
	AMIDOCK_DockType__Count    = 3
};

enum enAmiDockHotKeyAction
{
	AMIDOCK_HotKeyAction_ToFront          = 0,
	AMIDOCK_HotKeyAction_ToFrontToBack    = 1,
	AMIDOCK_HotKeyAction_ShowHide         = 2,
	AMIDOCK_HotKeyAction_MinimizeMaximize = 3,
	AMIDOCK_HotKeyAction__Count           = 4
};

enum enAmiDockPlacement
{
	AMIDOCK_Placement_Normal    = 0,
	AMIDOCK_Placement_Backdrop  = 1,
	AMIDOCK_Placement_StayTop   = 2,
	AMIDOCK_Placement__Count    = 3
};

enum enAmiDockTransparency
{
	AMIDOCK_Transparency_Picture       = 0,
	AMIDOCK_Transparency_Transparent   = 1,
	AMIDOCK_Transparency_PicTrans      = 2,
	AMIDOCK_Transparency_AlphaPicTrans = 3, // obsolete
	AMIDOCK_Transparency__Count        = 4
};

// ---


enum enDockyRenderMode
{
	DOCKYRENDERMODE_DockyIcon =  1,
	DOCKYRENDERMODE_Icon      =  2,
	DOCKYRENDERMODE_RP        =  3,
	DOCKYRENDERMODE_RPPA      =  4, // pseudo alpha (background shows through)
	DOCKYRENDERMODE_RGB       =  5,
	DOCKYRENDERMODE_RGBPA     =  6, // pseudo alpha (background shows through)
	DOCKYRENDERMODE_ARGB      =  7,
	DOCKYRENDERMODE_ARGBPA    =  8, // pseudo alpha (background shows through)
	DOCKYRENDERMODE_RGBA      =  9,
	DOCKYRENDERMODE_RGBAPA    = 10  // pseudo alpha (background shows through)
};

enum enDockyNotify
{
	DOCKYNOTIFY_NONE           = 0x00000000,
	DOCKYNOTIFY_MOUSEMOVE      = 0x00000001,
	DOCKYNOTIFY_RELMOUSE       = 0x00000002,
	DOCKYNOTIFY_MOUSEBUTTONS   = 0x00000004,
	DOCKYNOTIFY_DNDMOUSEOVER   = 0x00000008,
	DOCKYNOTIFY_DNDEVENTS      = 0x00000010,
	DOCKYNOTIFY_VISIBLECHANGE  = 0x00000020,
	DOCKYNOTIFY_DOCKYRAWKEYS   = 0x00000040,
	DOCKYNOTIFY_DOCKRAWKEYS    = 0x00000080,
	DOCKYNOTIFY_OBJECTCLICKS   = 0x00000100,
	DOCKYNOTIFY_MOVESIZECHANGE = 0x00000200,
	DOCKYNOTIFY_DOCKCHANGE     = 0x00000400,
	DOCKYNOTIFY_ADD            = 0x00000800,
	DOCKYNOTIFY_REMOVE         = 0x00001000,
	DOCKYNOTIFY_RENAME         = 0x00002000,
	DOCKYNOTIFY_MOVE           = 0x00004000,
	DOCKYNOTIFY_CHANGE         = 0x00008000
};

enum enDockySizeAttribs
{
	DOCKYSIZEATTR_USESNAMESPACE   = 0x00000001,
	DOCKYSIZEATTR_DYNAMICMAINSIZE = 0x00000002
};

enum enDockyCompositeMode
{
	DOCKYCOMPMODE_PreblendedRGB = 0,
	DOCKYCOMPMODE_RawRGB        = 1
};


/*
** DOCKYGET ********************************************************************
*/
enum enDockyGet
{
	DOCKYGET_Version           =  1, // uint32
	DOCKYGET_GetSize           =  2, // struct DockySize
	DOCKYGET_FrameDelay        =  3, // int32  (-1: no periodic processing)
	DOCKYGET_RenderMode        =  4, // uint32
	DOCKYGET_Notifications     =  5, // uint32
	DOCKYGET_Name              =  6, // STRPTR
	DOCKYGET_DockyPrefs        =  7, // PrefsObject ** - return a PrefsObject which contains the prefs for this docky
	DOCKYGET_InvisibleProcess  =  9, // -
	DOCKYGET_DockyPrefsChanged = 10, // - set if prefs have changed an need to be saved (only checked on AmiDock quit)
	DOCKYGET_Icon              = 11, // struct DiskObject * - if rendermode==DOCKYRENDERMODE_ICON, AmiDock will ask for this
	DOCKYGET_ContextMenu       = 12, // for example: DoMethod((Object *)msgData, OM_ADDMEMBER, ...);
	DOCKYGET_NeedsAttention    = 13, // uint32 BOOL - if true after Signal(dockyAttention->amidockTask, 1L<<dockyAttention->attentionSignalBit), this docky gets immediately processed
	DOCKYGET_ShowsName         = 14, // uint32 BOOL
	DOCKYGET_SizeAttribs       = 15, // uint32 (a mask of enum enDockySizeAttribs)
	DOCKYGET_AllowsRename      = 16, // uint32 BOOL
	DOCKYGET_SupportsComposite = 17, // uint32 BOOL (RenderDestination with alpha)
	DOCKYGET_AllowsIconChange  = 18, // uint32 BOOL
	DOCKYGET_IconPath          = 19, // STRPTR
	DOCKYGET_CompositeMode     = 20  // enum enDockyCompositeMode
};


/*
** DOCKYSET ********************************************************************
*/
enum enDockySet
{
	DOCKYSET_RenderDestination         =    1, // struct DockyRenderDestination *
	DOCKYSET_Window                    =    2, // struct Window *
	DOCKYSET_Screen                    =    3, // struct Screen *
	DOCKYSET_DockyPrefs                =    4, // PrefsObject *
	DOCKYSET_DockyChange               =    5, // struct DockyObjectNr *
	DOCKYSET_DockyRemove               =    6, // -
	DOCKYSET_DockyRemoveExit           =    7, // -
	DOCKYSET_AmiDockFlashOnClickChange =    8, // uint32 * (TRUE,FALSE)
	DOCKYSET_AmiDockQuitsNow           =    9, // -
	DOCKYSET_RedrawNow                 =   10, // -
	DOCKYSET_FileName                  =   11, // STRPTR
	DOCKYSET_HotKey                    =   12, // -
	DOCKYSET_DockyDebug                =   13, // struct DockyDebug *
	DOCKYSET_ContextMenuResult         =   14, // Object *
	DOCKYSET_DockyAttention            =   15, // struct DockyAttention *

// DOCKYNOTIFY_MOUSEMOVE (+DOCKYNOTIFY_RELMOUSE)
	DOCKYSET_MouseMove                 =  100, // DOCKYNOTIFY_RELMOUSE not set: struct DockyAbsPosition *
                                               // DOCKYNOTIFY_RELMOUSE set:     struct DockyPosition *
	DOCKYSET_MouseIsOverDocky          =  101, // BOOL mouseIsOver

// DOCKYNOTIFY_MOUSEBUTTONS
	DOCKYSET_SelectChange              =  200, // BOOL leftButtonIsDown
	DOCKYSET_SingleClick               =  201, // uint32 button
	DOCKYSET_DoubleClick               =  202, // uint32 button

// DOCKYNOTIFY_DNDMOUSEOVER
	DOCKYSET_DNDMouseOver              =  300, // BOOL mouseIsOver

// DOCKYNOTIFY_DNDEVENTS
	DOCKYSET_DockyDND                  =  400, // struct DockyDockyDND *
	DOCKYSET_ObjectDND                 =  401, // struct DockyObjectDND *

// DOCKYNOTIFY_VISIBLECHANGE
	DOCKYSET_DockyVisibleChange        =  500, // BOOL isVisible
	DOCKYSET_DockHide                  =  501, // struct DockyDockState *

// DOCKYNOTIFY_DOCKYRAWKEYS
	DOCKYSET_DockyRawKey               =  600, // uint32 rawkey code

// DOCKYNOTIFY_DOCKRAWKEYS
	DOCKYSET_DockRawKey                =  700, // uint32 rawkey code

// DOCKYNOTIFY_OBJECTCLICKS
	DOCKYSET_DockClick                 =  800, // struct DockyCategoryNr *
	DOCKYSET_ObjectClick               =  801, // struct DockyObjectClick *

// DOCKYNOTIFY_MOVESIZECHANGE
	DOCKYSET_DockWinMove               =  900, // struct DockyDockPosition *
	DOCKYSET_DockResize                =  901, // struct DockyDockSize *

// DOCKYNOTIFY_DOCKCHANGE
	DOCKYSET_DockMinimizeChange        = 1000, // struct DockyDockState *
	DOCKYSET_DockMinimizeableChange    = 1001, // struct DockyDockState *
	DOCKYSET_DockCategoryChange        = 1002, // struct DockyCategoryNr *
	DOCKYSET_DockOrientationChange     = 1003, // struct DockyDockState *
	DOCKYSET_DockSnapToChange          = 1004, // struct DockyDockState *
	DOCKYSET_DockIconNameLinesChange   = 1005, // struct DockyDockState *
	DOCKYSET_DockBarBackChange         = 1006, // struct DockyDockBackground *
	DOCKYSET_DockIconBackChange        = 1007, // struct DockyDockBackground *
	DOCKYSET_DockTypeChange            = 1008, // struct DockyDockType * // <- this notification is also always sent if the docky belongs to the dock
	DOCKYSET_DockFontChange            = 1009, // struct DockyDockFont *
	DOCKYSET_DockScaleFactor           = 1010, // uint32 factor (25->400)

// DOCKYNOTIFY_ADD
	DOCKYSET_DockAdd                   = 1100, // struct DockyDockInfo *
	DOCKYSET_CategoryAdd               = 1101, // struct DockyCategoryInfo *
	DOCKYSET_ObjectAdd                 = 1102, // struct DockyObjectInfo *

// DOCKYNOTIFY_REMOVE
	DOCKYSET_DockRemove                = 1200, // uint32 dockNr
	DOCKYSET_CategoryRemove            = 1201, // struct DockyCategoryNr *
	DOCKYSET_ObjectRemove              = 1202, // struct DockyObjectNr *

// DOCKYNOTIFY_RENAME
	DOCKYSET_DockRename                = 1300, // struct DockyDockInfo *
	DOCKYSET_CategoryRename            = 1301, // struct DockyCategoryInfo *
	DOCKYSET_ObjectRename              = 1302, // struct DockyObjectInfo *  (objectPath is NULL here)

// DOCKYNOTIFY_MOVE
	DOCKYSET_DockMove                  = 1400, // struct DockyDockMove *
	DOCKYSET_CategoryMove              = 1401, // struct DockyCategoryMove *
	DOCKYSET_ObjectMove                = 1402, // struct DockyObjectMove *

// DOCKYNOTIFY_CHANGE
	DOCKYSET_ObjectIconChange          = 1500  // struct DockyObjectInfo *
};


/*
** DOCKYPROCESS ************************************************************************************************
**
** Attention:
** ~~~~~~~~~~
** Always store the results of a DOCKYPROCESS-Request seperately as a copy!
** All results (pointers [structs, STRPTR's]) are only valid while in the answer-iteration of DockyProcess()!
*/

#define DOCKYPROCESS_ADDVALUE 0x7ffffff

//                                                      REQUEST               | RESPONSE
// ---------------------------------------------------------------------------+----------------------------
enum enDockyProcess
{
	DOCKYPROCESS_Null                  =   0, // -                            | -
	DOCKYPROCESS_DockyGetSelf          =   1, // -                            | struct DockyObjectInfo *
	DOCKYPROCESS_DockyRemoveSelf       =   2, // -                            | -
	DOCKYPROCESS_DockyChangeName       =   3, // -                            | -
	DOCKYPROCESS_DockyChangeRendSize   =   4, // -                            | -
	DOCKYPROCESS_DockyGetPosSize       =   5, // -                            | struct DockyPosSize *
	DOCKYPROCESS_DockyChangeFrameDelay =   6, // -                            | -

// ---                                                                        |

	DOCKYPROCESS_QuitAmiDock           = 100, // -                            | -
	DOCKYPROCESS_IsAmiDockIconified    = 101, // -                            | uint32 * (result: TRUE,FALSE)
	DOCKYPROCESS_IconifyAmiDock        = 102, // -                            | -
	DOCKYPROCESS_UniconifyAmiDock      = 103, // -                            | -
	DOCKYPROCESS_IgnoreNextObjectClick = 104, // int32 dockNr (-1: all)       | -
	DOCKYPROCESS_GetFlashOnClick       = 105, //                              | uint32 * (result: TRUE,FALSE)
	DOCKYPROCESS_SetFlashOnClick       = 106, // uint32 (boolean: TRUE/FALSE) | -
	DOCKYPROCESS_RunWB                 = 107, // struct DockyRunWB *          | -
	DOCKYPROCESS_SetNeedsDebugMode     = 108, // uint32 (boolean: TRUE/FALSE) | -
// ---                                                                        |

	DOCKYPROCESS_GetDockCount          = 200, // -                            | int32 *
	DOCKYPROCESS_GetDockInfo           = 201, // uint32 *dockNr               | struct DockyDockInfo *
	DOCKYPROCESS_InsertDock            = 202, // struct DockyDockInfo *       | int32 *newDockNr (-1: no success)
	DOCKYPROCESS_RemoveDock            = 203, // uint32 *dockNr               | -
	DOCKYPROCESS_MoveDock              = 204, // struct DockyDockMove *       | int32 *newDockNr (-1: error
	DOCKYPROCESS_RenameDock            = 205, // struct DockyDockInfo *       | -

	DOCKYPROCESS_GetDockHidden         = 206, // uint32 *dockNr               | int32 * (result: -1,TRUE,FALSE)
	DOCKYPROCESS_SetDockHidden         = 207, // struct DockyDockState *      | -
	DOCKYPROCESS_SetDockHiddenAnim     = 208, // struct DockyDockState *      | -

	DOCKYPROCESS_GetDockMinimized      = 209, // uint32 *dockNr               | int32 * (result: -1,TRUE,FALSE)
	DOCKYPROCESS_SetMinimizeDock       = 210, // struct DockyDockState *      | -

	DOCKYPROCESS_GetDockMinimizeable   = 211, // uint32 *dockNr               | int32 * (result: -1,TRUE,FALSE)
	DOCKYPROCESS_SetDockMinimizeable   = 212, // struct DockyDockState *      | -

	DOCKYPROCESS_GetDockOrientation    = 213, // uint32 *dockNr               | int32 *
	DOCKYPROCESS_SetDockOrientation    = 214, // struct DockyDockState *      | -

	DOCKYPROCESS_GetDockSnapTo         = 215, // uint32 *dockNr               | int32 *
	DOCKYPROCESS_SetDockSnapTo         = 216, // struct DockyDockState *      | -

	DOCKYPROCESS_GetDockIconNameLines  = 217, // uint32 *dockNr               | int32 *
	DOCKYPROCESS_SetDockIconNameLines  = 218, // struct DockyDockState *      | -

	DOCKYPROCESS_GetDockBarBack        = 219, // uint32 *dockNr               | struct DockyDockBackground *
	DOCKYPROCESS_SetDockBarBack        = 220, // struct DockyDockBackground * | -

	DOCKYPROCESS_GetDockIconBack       = 221, // uint32 *dockNr               | struct DockyDockBackground *
	DOCKYPROCESS_SetDockIconBack       = 222, // struct DockyDockBackground * | -

	DOCKYPROCESS_GetDockOrigin         = 223, // uint32 *dockNr               | struct DockyDockPosition *
	DOCKYPROCESS_SetDockOrigin         = 224, // struct DockyDockPosition *   | -

	DOCKYPROCESS_GetDockPosition       = 225, // uint32 *dockNr               | struct DockyDockPosition *
	DOCKYPROCESS_SetDockPosition       = 226, // struct DockyDockPosition *   | -

	DOCKYPROCESS_GetDockSize           = 227, // struct DockyCategoryNr *     | struct DockyDockSize *
	DOCKYPROCESS_SetDockSize           = 228, // struct DockyDockSize  *      | -

	DOCKYPROCESS_ResizeDock            = 229, // uint32 *dockNr               | -
	DOCKYPROCESS_RelayoutDock          = 230, // uint32 *dockNr               | -
	DOCKYPROCESS_DockToFront           = 231, // uint32 *dockNr               | -
	DOCKYPROCESS_DockToBack            = 232, // uint32 *dockNr               | -

	DOCKYPROCESS_GetDockWindowPS       = 233, // uint32 *dockNr               | struct DockyPosSize *
	DOCKYPROCESS_GetDockDragBarPS      = 234, // uint32 *dockNr               | struct DockyPosSize *

// ---                                                                        |

	DOCKYPROCESS_GetCategoryCount      = 300, // uint32 *dockNr               | int32 * (-1: error)
	DOCKYPROCESS_GetCategoryInfo       = 301, // struct DockyCategoryNr *     | struct DockyCategoryInfo *
	DOCKYPROCESS_InsertCategory        = 302, // struct DockyCategoryInfo *   | int32 *newCategoryNr (-1: no success)
	DOCKYPROCESS_RemoveCategory        = 303, // struct DockyCategoryNr *     | -
	DOCKYPROCESS_MoveCategory          = 304, // struct DockyCategoryMove *   | int32 *newCategoryNr (-1: error)
	DOCKYPROCESS_RenameCategory        = 305, // struct DockyCategoryInfo *   | -

// ---                                                                        |

	DOCKYPROCESS_GetObjectCount        = 400, // struct DockyCategoryNr *     | int32 * (-1: error)
	DOCKYPROCESS_GetObjectInfo         = 401, // struct DockyObjectNr *       | struct DockyObjectInfo *
	DOCKYPROCESS_InsertObject          = 402, // struct DockyObjectInfo *     | int32 *newObjectNr (-1: no success)
	DOCKYPROCESS_RemoveObject          = 403, // struct DockyObjectNr *       | -
	DOCKYPROCESS_MoveObject            = 404, // struct DockyObjectMove *     | int32 *newObjectNr (-1: error)
	DOCKYPROCESS_GetObjectPS           = 405  // struct DockyObjectNr *       | struct DockyPosSize *
};

/******************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/******************************************************************************/

#endif    /*  LIBRARIES_DOCKY_H  */
