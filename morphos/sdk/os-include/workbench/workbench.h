#ifndef WORKBENCH_WORKBENCH_H
#define WORKBENCH_WORKBENCH_H

/*
	workbench.library include (V50)

	Copyright © 2002-2010 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TASKS_H
# include <exec/tasks.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#pragma pack(2)


#define WBDISK     1
#define WBDRAWER   2
#define WBTOOL     3
#define WBPROJECT  4
#define WBGARBAGE  5
#define WBDEVICE   6
#define WBKICK     7
#define WBAPPICON  8


struct OldDrawerData
{
	struct NewWindow dd_NewWindow;
	LONG             dd_CurrentX;
	LONG             dd_CurrentY;
};

#define OLDDRAWERDATAFILESIZE  (sizeof(struct OldDrawerData))

struct DrawerData
{
	struct NewWindow dd_NewWindow;
	LONG             dd_CurrentX;
	LONG             dd_CurrentY;
	ULONG            dd_Flags;
	UWORD            dd_ViewModes;
};

#define DRAWERDATAFILESIZE  (sizeof(struct DrawerData))


#define DDVM_BYDEFAULT  0
#define DDVM_BYICON     1
#define DDVM_BYNAME     2
#define DDVM_BYDATE     3
#define DDVM_BYSIZE     4
#define DDVM_BYTYPE     5


#define DDFLAGS_SHOWDEFAULT  0
#define DDFLAGS_SHOWICONS    1
#define DDFLAGS_SHOWALL      2


struct DiskObject
{
	UWORD              do_Magic;
	UWORD              do_Version;
	struct Gadget      do_Gadget;
	UBYTE              do_Type;
	STRPTR             do_DefaultTool;
	STRPTR            *do_ToolTypes;
	LONG               do_CurrentX;
	LONG               do_CurrentY;
	struct DrawerData *do_DrawerData;
	STRPTR             do_ToolWindow;
	LONG               do_StackSize;
};


#define WB_DISKMAGIC         0xe310
#define WB_DISKVERSION       1
#define WB_DISKREVISION      1
#define WB_DISKREVISIONMASK  255


struct FreeList
{
	WORD        fl_NumFree;
	struct List fl_MemList;
};


#define GFLG_GADGBACKFILL  0x0001
#define GADGBACKFILL  GFLG_GADGBACKFILL


#define NO_ICON_POSITION  (0x80000000)

#define WORKBENCH_NAME  "workbench.library"


#define AM_VERSION 1

struct AppMessage
{
	struct Message am_Message;
	UWORD          am_Type;
	ULONG          am_UserData;
	ULONG          am_ID;
	LONG           am_NumArgs;
	struct WBArg  *am_ArgList;
	UWORD          am_Version;
	UWORD          am_Class;
	WORD           am_MouseX;
	WORD           am_MouseY;
	ULONG          am_Seconds;
	ULONG          am_Micros;
	ULONG          am_Reserved[8];
};


#define AMTYPE_APPWINDOW      7
#define AMTYPE_APPICON        8
#define AMTYPE_APPMENUITEM    9
#define AMTYPE_APPWINDOWZONE  10


/*** V44 ***/


#define AMCLASSICON_Open         0
#define AMCLASSICON_Copy         1
#define AMCLASSICON_Rename       2
#define AMCLASSICON_Information  3
#define AMCLASSICON_Snapshot     4
#define AMCLASSICON_UnSnapshot   5
#define AMCLASSICON_LeaveOut     6
#define AMCLASSICON_PutAway      7
#define AMCLASSICON_Delete       8
#define AMCLASSICON_FormatDisk   9
#define AMCLASSICON_EmptyTrash   10

#define AMCLASSICON_Selected     11
#define AMCLASSICON_Unselected   12


struct AppWindow          { APTR aw_PRIVATE; };
struct AppWindowDropZone  { APTR awdz_PRIVATE; };
struct AppIcon            { APTR ai_PRIVATE; };
struct AppMenuItem        { APTR ami_PRIVATE; };
struct AppMenu            { APTR am_PRIVATE; };


#define WBA_Dummy                       (TAG_USER + 0xA000)
#define WBAPPICONA_SupportsOpen         (WBA_Dummy + 1)
#define WBAPPICONA_SupportsCopy         (WBA_Dummy + 2)
#define WBAPPICONA_SupportsRename       (WBA_Dummy + 3)
#define WBAPPICONA_SupportsInformation  (WBA_Dummy + 4)
#define WBAPPICONA_SupportsSnapshot     (WBA_Dummy + 5)
#define WBAPPICONA_SupportsUnSnapshot   (WBA_Dummy + 6)
#define WBAPPICONA_SupportsLeaveOut     (WBA_Dummy + 7)
#define WBAPPICONA_SupportsPutAway      (WBA_Dummy + 8)
#define WBAPPICONA_SupportsDelete       (WBA_Dummy + 9)
#define WBAPPICONA_SupportsFormatDisk   (WBA_Dummy + 10)
#define WBAPPICONA_SupportsEmptyTrash   (WBA_Dummy + 11)
#define WBAPPICONA_PropagatePosition    (WBA_Dummy + 12)
#define WBAPPICONA_RenderHook           (WBA_Dummy + 13)
#define WBAPPICONA_NotifySelectState    (WBA_Dummy + 14)

#define WBAPPMENUA_CommandKeyString     (WBA_Dummy + 15)

#define WBOPENA_ArgLock                 (WBA_Dummy + 16)
#define WBOPENA_ArgName                 (WBA_Dummy + 17)

#define WBCTRLA_IsOpen                  (WBA_Dummy + 18)
#define WBCTRLA_DuplicateSearchPath     (WBA_Dummy + 19)
#define WBCTRLA_FreeSearchPath          (WBA_Dummy + 20)
#define WBCTRLA_GetDefaultStackSize     (WBA_Dummy + 21)
#define WBCTRLA_SetDefaultStackSize     (WBA_Dummy + 22)
#define WBCTRLA_RedrawAppIcon           (WBA_Dummy + 23)
#define WBCTRLA_GetProgramList          (WBA_Dummy + 24)
#define WBCTRLA_FreeProgramList         (WBA_Dummy + 25)

#define WBDZA_Left                      (WBA_Dummy + 26)
#define WBDZA_RelRight                  (WBA_Dummy + 27)
#define WBDZA_Top                       (WBA_Dummy + 28)
#define WBDZA_RelBottom                 (WBA_Dummy + 29)
#define WBDZA_Width                     (WBA_Dummy + 30)
#define WBDZA_RelWidth                  (WBA_Dummy + 31)
#define WBDZA_Height                    (WBA_Dummy + 32)
#define WBDZA_RelHeight                 (WBA_Dummy + 33)
#define WBDZA_Box                       (WBA_Dummy + 34)
#define WBDZA_Hook                      (WBA_Dummy + 35)

#define WBCTRLA_GetSelectedIconList     (WBA_Dummy + 36)
#define WBCTRLA_FreeSelectedIconList    (WBA_Dummy + 37)
#define WBCTRLA_GetOpenDrawerList       (WBA_Dummy + 38)
#define WBCTRLA_FreeOpenDrawerList      (WBA_Dummy + 39)

#define WBA_Reserved1                   (WBA_Dummy + 40)
#define WBA_Reserved2                   (WBA_Dummy + 41)

#define WBCTRLA_GetHiddenDeviceList     (WBA_Dummy + 42)
#define WBCTRLA_FreeHiddenDeviceList    (WBA_Dummy + 43)
#define WBCTRLA_AddHiddenDeviceName     (WBA_Dummy + 44)
#define WBCTRLA_RemoveHiddenDeviceName  (WBA_Dummy + 45)

#define WBA_Reserved3                   (WBA_Dummy + 46)

#define WBCTRLA_GetTypeRestartTime      (WBA_Dummy + 47)
#define WBCTRLA_SetTypeRestartTime      (WBA_Dummy + 48)

#define WBA_Reserved4                   (WBA_Dummy + 49)

#define WBA_Reserved5                   (WBA_Dummy + 50)
#define WBA_Reserved6                   (WBA_Dummy + 51)
#define WBA_Reserved7                   (WBA_Dummy + 52)
#define WBA_Reserved8                   (WBA_Dummy + 53)
#define WBA_Reserved9                   (WBA_Dummy + 54)
#define WBA_Reserved10                  (WBA_Dummy + 55)
#define WBA_Reserved11                  (WBA_Dummy + 56)
#define WBA_Reserved12                  (WBA_Dummy + 57)
#define WBA_Reserved13                  (WBA_Dummy + 58)
#define WBA_Reserved14                  (WBA_Dummy + 59)
#define WBA_Reserved15                  (WBA_Dummy + 60)
#define WBA_Reserved16                  (WBA_Dummy + 61)
#define WBA_Reserved17                  (WBA_Dummy + 62)
#define WBA_Reserved18                  (WBA_Dummy + 63)
#define WBA_Reserved19                  (WBA_Dummy + 64)

#define WBAPPMENUA_GetKey               (WBA_Dummy + 65)
#define WBAPPMENUA_UseKey               (WBA_Dummy + 66)

#define WBA_Reserved20                  (WBA_Dummy + 67)
#define WBA_Reserved21                  (WBA_Dummy + 68)

/*** V45 ***/

#define WBCTRLA_GetCopyHook             (WBA_Dummy + 69)
#define WBCTRLA_SetCopyHook             (WBA_Dummy + 70)
#define WBCTRLA_GetDeleteHook           (WBA_Dummy + 71)
#define WBCTRLA_SetDeleteHook           (WBA_Dummy + 72)
#define WBCTRLA_GetTextInputHook        (WBA_Dummy + 73)
#define WBCTRLA_SetTextInputHook        (WBA_Dummy + 74)

#define WBOPENA_Show                    (WBA_Dummy + 75)
#define WBOPENA_ViewBy                  (WBA_Dummy + 76)

#define WBAPPMENUA_GetTitleKey          (WBA_Dummy + 77)

#define WBCTRLA_AddSetupCleanupHook     (WBA_Dummy + 78)
#define WBCTRLA_RemSetupCleanupHook     (WBA_Dummy + 79)

/*** V50 ***/

#define WBAPPICONA_Clone                (WBA_Dummy + 80) /* V50 Clone appicon (default: FALSE) */
#define WBCREATEDRAWER_CreateIcon       (WBA_Dummy + 81) /* Create icon: defaults to TRUE */
#define WBCREATEDRAWER_IgnoreFile       (WBA_Dummy + 88) /* ignore name component: defaults to FALSE */

#ifdef SYSTEM_PRIVATE
#define WBCREATEDRAWER_CreateHook       (WBA_Dummy + 82)
#define WBCREATEDRAWER_ErrorHook        (WBA_Dummy + 83)
#endif


#define WBCREATEICON_MimeType           (WBA_Dummy + 84)
#define WBCREATEICON_File               (WBA_Dummy + 85)
#define WBCREATEICON_DefIcon            (WBA_Dummy + 86) /* Default is TRUE */
#define WBCREATEICON_AppendInfo         (WBA_Dummy + 87) /* Default is FALSE */

#define WBCREATEDRAWER_NoIcons          (WBA_Dummy + 81) /* DO NOT USE */

#define WBA_LAST_TAG  WBCREATEDRAWER_IgnoreFile

/*
 * ManageDesktopObject actions
 */
#define DESKACTION_AddShortcut             0 /* V50 add shortcut */
#define DESKACTION_RemoveShortcut          1 /* V50 remove shortcut */


struct SetupCleanupHookMsg
{
	ULONG schm_Length;
	LONG  schm_State;
};


#define SCHMSTATE_TryCleanup  0
#define SCHMSTATE_Cleanup     1
#define SCHMSTATE_Setup       2


struct AppIconRenderMsg
{
	struct RastPort   *arm_RastPort;
	struct DiskObject *arm_Icon;
	STRPTR             arm_Label;
	struct TagItem    *arm_Tags;

	WORD               arm_Left;
	WORD               arm_Top;

	WORD               arm_Width;
	WORD               arm_Height;

	ULONG              arm_State;
};


struct AppWindowDropZoneMsg
{
	struct RastPort *adzm_RastPort;
	struct IBox      adzm_DropZoneBox;
	ULONG            adzm_ID;
	ULONG            adzm_UserData;
	LONG             adzm_Action;
};

#define ADZMACTION_Enter  (0)
#define ADZMACTION_Leave  (1)


struct IconSelectMsg
{
	ULONG           ism_Length;
	BPTR            ism_Drawer;
	STRPTR          ism_Name;
	UWORD           ism_Type;
	BOOL            ism_Selected;
	struct TagItem *ism_Tags;
	struct Window  *ism_DrawerWindow;
	struct Window  *ism_ParentWindow;

	WORD            ism_Left;
	WORD            ism_Top;
	WORD            ism_Width;
	WORD            ism_Height;
};

#define ISMACTION_Unselect  (0)
#define ISMACTION_Select    (1)
#define ISMACTION_Ignore    (2)
#define ISMACTION_Stop      (3)


struct CopyBeginMsg
{
	ULONG cbm_Length;
	LONG  cbm_Action;
	BPTR  cbm_SourceDrawer;
	BPTR  cbm_DestinationDrawer;
};

struct CopyDataMsg
{
	ULONG  cdm_Length;
	LONG   cdm_Action;

	BPTR   cdm_SourceLock;
	STRPTR cdm_SourceName;

	BPTR   cdm_DestinationLock;
	STRPTR cdm_DestinationName;
	LONG   cdm_DestinationX;
	LONG   cdm_DestinationY;
};

struct CopyEndMsg
{
	ULONG cem_Length;
	LONG  cem_Action;
};

#define CPACTION_Begin  (0)
#define CPACTION_Copy   (1)
#define CPACTION_End    (2)


struct DeleteBeginMsg
{
	ULONG dbm_Length;
	LONG  dbm_Action;
};

struct DeleteDataMsg
{
	ULONG  ddm_Length;
	LONG   ddm_Action;
	BPTR   ddm_Lock;
	STRPTR ddm_Name;
};

struct DeleteEndMsg
{
	ULONG dem_Length;
	LONG  dem_Action;
};

#define DLACTION_BeginDiscard     (0)
#define DLACTION_BeginEmptyTrash  (1)
#define DLACTION_DeleteContents   (3)
#define DLACTION_DeleteObject     (4)
#define DLACTION_End              (5)


struct TextInputMsg
{
	ULONG  tim_Length;
	LONG   tim_Action;
	STRPTR tim_Prompt;
};

#define TIACTION_Rename         (0)
#define TIACTION_RelabelVolume  (1)
#define TIACTION_NewDrawer      (2)
#define TIACTION_Execute        (3)


#define UPDATEWB_ObjectRemoved  (0)
#define UPDATEWB_ObjectAdded    (1)


#pragma pack()

#endif /* WORKBENCH_WORKBENCH_H */
