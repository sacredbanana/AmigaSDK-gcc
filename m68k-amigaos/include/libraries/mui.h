/***************************************************************************
**
** MUI - MagicUserInterface
** Copyright (C) 1992-2006 by Stefan Stuntz <stefan@stuntz.com>
** Copyright (C) 2006-2020 by Thore Boeckelmann, Jens Maus
**
** Main Header File
**
****************************************************************************
** Class Tree
****************************************************************************
**
** rootclass                           (BOOPSI's base class)
** +-- Notify                          (implements notification mechanism)
** |   +-- Application                 (main class for all applications)
** |   +-- Area                        (base class for all GUI elements)
** |   |   +-- Balance                 (balancing separator bar)
** |   |   +-- Bitmap                  (draws bitmaps)
** |   |   |   \-- Bodychunk           (makes bitmap from ILBM body chunk)
** |   |   +-- Colorfield              (field with changeable color)
** |   |   +-- Dtpic                   (display images loaded by datatypes.library)
** |   |   +-- Gadget                  (base class for intuition gadgets)
** |   |   |   +-- Boopsi              (interface to BOOPSI gadgets)
** |   |   |   \-- Prop                (proportional gadget)
** |   |   +-- Gauge                   (fuel gauge)
** |   |   +-- Group                   (groups other GUI elements)
** |   |   |   +-- Argstring           (build dynamic GUIs from ReadArgs() template)
** |   |   |   +-- Coloradjust         (several gadgets to adjust a color)
** |   |   |   +-- Cycle               (cycle gadget)
** |   |   |   +-- Keyadjust           (for configuring keyboard events)
** |   |   |   +-- Listview            (listview)
** |   |   |   +-- Mccprefs            (base class for prefs)
** |   |   |   +-- Palette             (complete palette gadget)
** |   |   |   +-- Panel               (base class for panels)
** |   |   |   |   +-- Filepanel       (an ASL like file selector)
** |   |   |   |   +-- Fontpanel       (an ASL like font selector)
** |   |   |   |   \-- Screenmodepanel (an ASL like screenmode selector)
** |   |   |   +-- Popstring           (base class for popup objects)
** |   |   |   |   +-- Popasl          (popup an asl requester)
** |   |   |   |   \-- Popobject       (popup aynthing in a separate window)
** |   |   |   |       +-- Poplist     (popup a simple listview)
** |   |   |   |       \-- Popscreen   (popup a list of public screens)
** |   |   |   +-- Radio               (radio button)
** |   |   |   +-- Register            (handles page groups with titles)
** |   |   |   |   \-- Penadjust       (group to adjust a pen)
** |   |   |   +-- Scrollbar           (traditional scrollbar)
** |   |   |   +-- Scrollgroup         (virtual groups with scrollbars)
** |   |   |   +-- Selectgroup         (selection group with radio buttons and labels)
** |   |   |   +-- Title               (handles page groups with titles)
** |   |   |   \-- Virtgroup           (handles virtual groups)
** |   |   +-- Image                   (image display)
** |   |   +-- List                    (line-oriented list)
** |   |   |   +-- Dirlist             (special list with files)
** |   |   |   +-- Floattext           (special list with floating text)
** |   |   |   +-- Scrmodelist         (special list with screen modes)
** |   |   |   \-- Volumelist          (special list with volumes)
** |   |   +-- Numeric                 (base class for slider gadgets)
** |   |   |   +-- Knob                (turning knob)
** |   |   |   +-- Levelmeter          (level display)
** |   |   |   +-- Numericbutton       (space saving popup slider)
** |   |   |   \-- Slider              (traditional slider)
** |   |   +-- Pendisplay              (displays a pen specification)
** |   |   |   \-- Poppen              (popup button to adjust a pen spec)
** |   |   +-- Pixmap                  (draws raw image data)
** |   |   +-- Rectangle               (spacing object)
** |   |   +-- Scale                   (percentage scale)
** |   |   +-- String                  (string gadget)
** |   |   \-- Text                    (text display)
** |   |       \-- Fontdisplay         (displays a font example string)
** |   +-- Family                      (handles multiple children)
** |   |   +-- Menu                    (describes a single menu)
** |   |   +-- Menuitem                (describes a single menu item)
** |   |   \-- Menustrip               (describes a complete menu strip)
** |   +-- Textdata                    (handles encoded text)
** |   \-- Window                      (main class for all windows)
** |       \-- Aboutmui                (About window of MUI preferences)
** \-- Semaphore                       (semaphore equipped objects)
**     +-- Datamap                     (handles general purpose data maps)
**     +-- Dataspace                   (handles general purpose data spaces)
**     +-- Objectmap                   (handles general purpose object maps)
**     \-- Process                     (simplify handling sub-tasks)
**         \-- Slave                   (simplify handling sub-tasks)
**
****************************************************************************
** General Header File Information
****************************************************************************
**
** All macro and structure definitions follow these rules:
**
** Name                       Meaning
**
** MUIC_<class>               Name of a class
** MUIM_<class>_<method>      Method
** MUIP_<class>_<method>      Methods parameter structure
** MUIV_<class>_<method>_<x>  Special method value
** MUIA_<class>_<attrib>      Attribute
** MUIV_<class>_<attrib>_<x>  Special attribute value
** MUIE_<error>               Error return code from MUI_Error()
** MUII_<name>                Standard MUI image
** MUIX_<code>                Control codes for text strings
** MUIO_<name>                Object type for MUI_MakeObject()
**
** MUIA_... attribute definitions are followed by a comment
** consisting of the three possible letters I, S and G.
** I: it's possible to specify this attribute at object creation time.
** S: it's possible to change this attribute with SetAttrs().
** G: it's possible to get this attribute with GetAttr().
**
** Items marked with "Custom Class" are for use in custom classes only!
*/

#ifdef __AROS__
#include <libraries/muiaros.h>
#else

#ifndef LIBRARIES_MUI_H
#define LIBRARIES_MUI_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef INTUITION_SCREENS_H
#include <intuition/screens.h>
#endif

#ifndef PROTO_INTUITION_H
#include <proto/intuition.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack(2)
  #elif defined(__VBCC__)
    #pragma amiga-align
  #endif
#endif

/***************************************************************************
** Library specification
***************************************************************************/

#define MUIMASTER_NAME    "muimaster.library"
#define MUIMASTER_VMIN    19
#define MUIMASTER_VLATEST 20

/*
** !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
** Warning, some of the macros in this header file work only with
** uptodate versions of muimaster.library. If you recompile your programs,
** be sure to open muimaster.library with MUIMASTER_VMIN as version number.
** !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/


/* include obsolete identifiers for backward compatibility */
#define MUI_OBSOLETE


/*************************************************************************
** Config items for MUIM_GetConfigItem
*************************************************************************/

#define MUICFG_PublicScreen            36



/***************************************************************************
** Object Types for MUI_MakeObject()
***************************************************************************/

#define MUIO_Label          1   /* STRPTR label, ULONG flags */
#define MUIO_Button         2   /* STRPTR label */
#define MUIO_Checkmark      3   /* STRPTR label */
#define MUIO_Cycle          4   /* STRPTR label, STRPTR *entries */
#define MUIO_Radio          5   /* STRPTR label, STRPTR *entries */
#define MUIO_Slider         6   /* STRPTR label, LONG min, LONG max */
#define MUIO_String         7   /* STRPTR label, LONG maxlen */
#define MUIO_PopButton      8   /* STRPTR imagespec */
#define MUIO_HSpace         9   /* LONG space   */
#define MUIO_VSpace        10   /* LONG space   */
#define MUIO_HBar          11   /* LONG space   */
#define MUIO_VBar          12   /* LONG space   */
#define MUIO_MenustripNM   13   /* struct NewMenu *nm, ULONG flags */
#define MUIO_Menuitem      14   /* STRPTR label, STRPTR shortcut, ULONG flags, ULONG data  */
#define MUIO_BarTitle      15   /* STRPTR label */
#define MUIO_NumericButton 16   /* STRPTR label, LONG min, LONG max, STRPTR format */

#define MUIO_Menuitem_CopyStrings (1<<30)

#define MUIO_Label_SingleFrame   (1<< 8)
#define MUIO_Label_DoubleFrame   (1<< 9)
#define MUIO_Label_LeftAligned   (1<<10)
#define MUIO_Label_Centered      (1<<11)
#define MUIO_Label_FreeVert      (1<<12)
#define MUIO_Label_Tiny          (1<<13)
#define MUIO_Label_DontCopy      (1<<14)

#define MUIO_MenustripNM_CommandKeyCheck (1<<0) /* check for "localized" menu items such as "O\0Open" */



/***************************************************************************
** ARexx Interface
***************************************************************************/

struct MUI_Command
{
    CONST_STRPTR mc_Name;
    CONST_STRPTR mc_Template;
    LONG         mc_Parameters;
    struct Hook *mc_Hook;
    LONG         mc_Reserved[5];
};

#define MC_TEMPLATE_ID ((CONST_STRPTR)~0)

#define MUI_RXERR_BADDEFINITION  -1
#define MUI_RXERR_OUTOFMEMORY    -2
#define MUI_RXERR_UNKNOWNCOMMAND -3
#define MUI_RXERR_BADSYNTAX      -4


/***************************************************************************
** Return values for MUI_Error()
***************************************************************************/

#define MUIE_OK                  0
#define MUIE_OutOfMemory         1
#define MUIE_OutOfGfxMemory      2
#define MUIE_InvalidWindowObject 3
#define MUIE_MissingLibrary      4
#define MUIE_NoARexx             5
#define MUIE_SingleTask          6



/***************************************************************************
** Standard MUI Images & Backgrounds
***************************************************************************/

#define MUII_WindowBack         0   /* These images are configured   */
#define MUII_RequesterBack      1   /* with the preferences program. */
#define MUII_ButtonBack         2
#define MUII_ListBack           3
#define MUII_TextBack           4
#define MUII_PropBack           5
#define MUII_PopupBack          6
#define MUII_SelectedBack       7
#define MUII_ListCursor         8
#define MUII_ListSelect         9
#define MUII_ListSelCur        10
#define MUII_ArrowUp           11
#define MUII_ArrowDown         12
#define MUII_ArrowLeft         13
#define MUII_ArrowRight        14
#define MUII_CheckMark         15
#define MUII_RadioButton       16
#define MUII_Cycle             17
#define MUII_PopUp             18
#define MUII_PopFile           19
#define MUII_PopDrawer         20
#define MUII_PropKnob          21
#define MUII_Drawer            22
#define MUII_HardDisk          23
#define MUII_Disk              24
#define MUII_Chip              25
#define MUII_Volume            26
#define MUII_RegisterBack      27
#define MUII_Network           28
#define MUII_Assign            29
#define MUII_TapePlay          30
#define MUII_TapePlayBack      31
#define MUII_TapePause         32
#define MUII_TapeStop          33
#define MUII_TapeRecord        34
#define MUII_GroupBack         35
#define MUII_SliderBack        36
#define MUII_SliderKnob        37
#define MUII_TapeUp            38
#define MUII_TapeDown          39
#define MUII_PageBack          40
#define MUII_ReadListBack      41
#define MUII_PopFont           42
#define MUII_ImageButtonBack   43
#define MUII_ImageSelectedBack 44
#define MUII_GaugeFull         45
#define MUII_GaugeEmpty        46
#define MUII_Menudisplay       47
#define MUII_PullOpen          48
#define MUII_StringBack        49
#define MUII_StringActiveBack  50
#define MUII_ListTitle         51
#define MUII_GroupTitle        52
#define MUII_RegisterTitle     53
#define MUII_Close             54
#define MUII_Count             55

#define MUII_BACKGROUND       128    /* These are direct color    */
#define MUII_SHADOW           129    /* combinations and are not  */
#define MUII_SHINE            130    /* affected by users prefs.  */
#define MUII_FILL             131
#define MUII_SHADOWBACK       132    /* Generally, you should     */
#define MUII_SHADOWFILL       133    /* avoid using them. Better  */
#define MUII_SHADOWSHINE      134    /* use one of the customized */
#define MUII_FILLBACK         135    /* images above.             */
#define MUII_FILLSHINE        136
#define MUII_SHINEBACK        137
#define MUII_FILLBACK2        138
#define MUII_HSHINEBACK       139
#define MUII_HSHADOWBACK      140
#define MUII_HSHINESHINE      141
#define MUII_HSHADOWSHADOW    142
#define MUII_MARKSHINE        143
#define MUII_MARKHALFSHINE    144
#define MUII_MARKBACKGROUND   145
#define MUII_BARBLOCK         146
#define MUII_BARDETAIL        147
#define MUII_LASTPAT          147



/***************************************************************************
** Special values for some methods
***************************************************************************/

#define MUIV_TriggerValue    0x49893131
#define MUIV_NotTriggerValue 0x49893133
#define MUIV_EveryTime       0x49893131

#define MUIV_Notify_Self        1
#define MUIV_Notify_Window      2
#define MUIV_Notify_Application 3
#define MUIV_Notify_Parent      4
#define MUIV_Notify_ParentParent 5
#define MUIV_Notify_ParentParentParent 6

#define MUIV_Application_Save_ENV     ((STRPTR) 0)
#define MUIV_Application_Save_ENVARC  ((STRPTR)~0)
#define MUIV_Application_Load_ENV     ((STRPTR) 0)
#define MUIV_Application_Load_ENVARC  ((STRPTR)~0)

#define MUIV_Application_ReturnID_Quit -1

#define MUIV_List_Insert_Top             0
#define MUIV_List_Insert_Active         -1
#define MUIV_List_Insert_Sorted         -2
#define MUIV_List_Insert_Bottom         -3

#define MUIV_List_Remove_First           0
#define MUIV_List_Remove_Active         -1
#define MUIV_List_Remove_Last           -2
#define MUIV_List_Remove_Selected       -3

#define MUIV_List_Select_Off             0
#define MUIV_List_Select_On              1
#define MUIV_List_Select_Toggle          2
#define MUIV_List_Select_Ask             3

#define MUIV_List_GetEntry_Active       -1
#define MUIV_List_EditEntry_Active      -1
#define MUIV_List_Edit_Active           -1
#define MUIV_List_Select_Active         -1
#define MUIV_List_Select_All            -2

#define MUIV_List_Redraw_Active         -1
#define MUIV_List_Redraw_All            -2
#define MUIV_List_Redraw_Entry          -3

#define MUIV_List_Move_Top               0
#define MUIV_List_Move_Active           -1
#define MUIV_List_Move_Bottom           -2
#define MUIV_List_Move_Next             -3 /* only valid for second parameter */
#define MUIV_List_Move_Previous         -4 /* only valid for second parameter */

#define MUIV_List_Exchange_Top           0
#define MUIV_List_Exchange_Active       -1
#define MUIV_List_Exchange_Bottom       -2
#define MUIV_List_Exchange_Next         -3 /* only valid for second parameter */
#define MUIV_List_Exchange_Previous     -4 /* only valid for second parameter */

#define MUIV_List_Jump_Top               0
#define MUIV_List_Jump_Active           -1
#define MUIV_List_Jump_Bottom           -2
#define MUIV_List_Jump_Up               -4
#define MUIV_List_Jump_Down             -3

#define MUIV_List_NextSelected_Start    -1
#define MUIV_List_NextSelected_End      -1

#define MUIV_Dirlist_Rename_Active         -1
#define MUIV_Dirlist_SetComment_Active     -1
#define MUIV_Dirlist_SetProtection_Active  -1

#define MUIV_DragQuery_Refuse 0
#define MUIV_DragQuery_Accept 1

#define MUIV_DragReport_Abort    0
#define MUIV_DragReport_Continue 1
#define MUIV_DragReport_Lock     2
#define MUIV_DragReport_Refresh  3

#define MUIV_CreateBubble_DontHidePointer (1<<0)

#define MUIV_Application_OCW_ScreenPage (1<<1) /* show just the screen page of the config window */

#define MUIV_ContextMenuBuild_Default 0xffffffff

#define MUIV_PushMethod_Delay(millis) MIN(0x0ffffff0,(((ULONG)millis)<<8))

#define MUIV_Family_GetChild_First     0
#define MUIV_Family_GetChild_Last     -1
#define MUIV_Family_GetChild_Next     -2
#define MUIV_Family_GetChild_Previous -3
#define MUIV_Family_GetChild_Iterate  -4

#define MUIV_Group_GetChild_First     MUIV_Family_GetChild_First
#define MUIV_Group_GetChild_Last      MUIV_Family_GetChild_Last
#define MUIV_Group_GetChild_Next      MUIV_Family_GetChild_Next
#define MUIV_Group_GetChild_Previous  MUIV_Family_GetChild_Previous
#define MUIV_Group_GetChild_Iterate   MUIV_Family_GetChild_Iterate



/***************************************************************************
** Control codes for text strings
***************************************************************************/

#define MUIX_R "\033r"    /* right justified */
#define MUIX_C "\033c"    /* centered        */
#define MUIX_L "\033l"    /* left justified  */

#define MUIX_N "\033n"    /* normal     */
#define MUIX_B "\033b"    /* bold       */
#define MUIX_I "\033i"    /* italic     */
#define MUIX_U "\033u"    /* underlined */

#define MUIX_PT "\0332"   /* text pen           */
#define MUIX_PH "\0338"   /* highlight text pen */



/***************************************************************************
** Parameter structures for some classes
***************************************************************************/

struct MUI_PenSpec   { char buf[ 32]; }; /* black box */

struct MUI_Palette_Entry
{
    LONG  mpe_ID;
    ULONG mpe_Red;
    ULONG mpe_Green;
    ULONG mpe_Blue;
    LONG  mpe_Group;
};

#define MUIV_Palette_Entry_End -1


/*****************************/
/* Application Input Handler */
/*****************************/

struct MUI_InputHandlerNode
{
    struct MinNode ihn_Node;
    Object        *ihn_Object;

    union
    {
        ULONG ihn_sigs;
        struct
        {
            UWORD ihn_millis;
            UWORD ihn_current;
        } ihn_timer;
    } ihn_stuff;

    ULONG          ihn_Flags; /* see below */
    ULONG          ihn_Method;
};

#define ihn_Signals ihn_stuff.ihn_sigs
#define ihn_Millis  ihn_stuff.ihn_timer.ihn_millis
#define ihn_Current ihn_stuff.ihn_timer.ihn_current

/* Flags for ihn_Flags */
#define MUIIHNF_TIMER           (1<<0) /* set ihn_Millis to number of 1/1000 sec ticks you want to be triggered */
#define MUIIHNF_TIMER_SCALE10   (1<<1) /* ihn_Millis is in 1/100 seconds instead */
#define MUIIHNF_TIMER_SCALE100  (1<<2) /* ihn_Millis is in 1/10 seconds instead */
                                       /* setting both SCALE10|SCALE100 makes ihn_Millis 1/1 seconds */



/************************/
/* Window Event Handler */
/************************/

struct MUI_EventHandlerNode
{
    struct MinNode ehn_Node;
    BYTE           ehn_Reserved; /* don't touch! */
    BYTE           ehn_Priority; /* event handlers are inserted according to their priority. */
    UWORD          ehn_Flags;    /* certain flags, see below for definitions. */
    Object        *ehn_Object;   /* object which should receive MUIM_HandleEvent. */
    struct IClass *ehn_Class;    /* if !=NULL, MUIM_HandleEvent is invoked on exactly this class with CoerceMethod(). */
    ULONG          ehn_Events;   /* one or more IDCMP flags this handler should react on. */
};

/* flags for ehn_Flags */

#define MUI_EHF_ALWAYSKEYS  (1<<0)  /* not for public use */

#define MUI_EHF_GUIMODE     (1<<1)  /* set this if you dont want your handler to be called */
                                    /* when your object is disabled or invisible */

#define MUI_EHF_PRIORITY    (1<<11) /* not for public use */

#define MUI_EHF_ISACTIVEGRP (1<<12) /* not for public use */

#define MUI_EHF_ISACTIVE    (1<<13) /* this flag is maintained by MUI and READ-ONLY: */
                                    /* set when ehn_Object is a window's active or default object. */

#define MUI_EHF_ISCALLING   (1<<14) /* not for public use */

#define MUI_EHF_ISENABLED   (1<<15) /* this flag is maintained by MUI and READ-ONLY: */
                                    /* it is set when the handler is added (after MUIM_Window_AddEventHandler) */
                                    /* and cleared when the handler is removed (after MUIM_Window_RemEventHandler). */
                                    /* you may not change the state of this flag yourself, but you may read it */
                                    /* to find out whether your handler is currently added to a window or not. */


/* other values reserved for future use */

/* return values for MUIM_HandleEvent (bit-masked, all other bits must be 0) */
#define MUI_EventHandlerRC_Eat (1<<0) /* stop MUI from calling other handlers */


/**********************/
/* List Position Test */
/**********************/

struct MUI_List_TestPos_Result
{
    LONG  entry;   /* number of entry, -1 if mouse not over valid entry */
    WORD  column;  /* numer of column, -1 if no valid column */
    UWORD flags;   /* see below */
    WORD  xoffset; /* x offset of mouse click relative to column start */
    WORD  yoffset; /* y offset of mouse click from center of line
                      (negative values mean click was above center,
                       positive values mean click was below center) */
};

#define MUI_LPR_ABOVE  (1<<0)
#define MUI_LPR_BELOW  (1<<1)
#define MUI_LPR_LEFT   (1<<2)
#define MUI_LPR_RIGHT  (1<<3)


/***************************************************************************
**
** Macro Section
** -------------
**
** To make GUI creation more easy and understandable, you can use the
** macros below. If you dont want, just define MUI_NOSHORTCUTS to disable
** them.
**
** These macros are available to C programmers only.
**
***************************************************************************/

#ifndef MUI_NOSHORTCUTS



/***************************************************************************
**
** Object Generation
** -----------------
**
** The xxxObject (and xChilds) macros generate new instances of MUI classes.
** Every xxxObject can be followed by tagitems specifying initial create
** time attributes for the new object and must be terminated with the
** End macro:
**
** obj = StringObject,
**          MUIA_String_Contents, "foo",
**          MUIA_String_MaxLen  , 40,
**          End;
**
** With the Child, SubWindow and WindowContents shortcuts you can
** construct a complete GUI within one command:
**
** app = ApplicationObject,
**
**          ...
**
**          SubWindow, WindowObject,
**             WindowContents, VGroup,
**                Child, String("foo",40),
**                Child, String("bar",50),
**                Child, HGroup,
**                   Child, CheckMark(TRUE),
**                   Child, CheckMark(FALSE),
**                   End,
**                End,
**             End,
**
**          SubWindow, WindowObject,
**             WindowContents, HGroup,
**                Child, ...,
**                Child, ...,
**                End,
**             End,
**
**          ...
**
**          End;
**
***************************************************************************/

#define MenustripObject     MUI_NewObject(MUIC_Menustrip
#define MenuObject          MUI_NewObject(MUIC_Menu
#define MenuObjectT(name)   MUI_NewObject(MUIC_Menu,MUIA_Menu_Title,name
#define PopmenuObject       MUI_NewObject(MUIC_Popmenu
#define MenuitemObject      MUI_NewObject(MUIC_Menuitem
#define WindowObject        MUI_NewObject(MUIC_Window
#define DtpicObject         MUI_NewObject(MUIC_Dtpic
#define ImageObject         MUI_NewObject(MUIC_Image
#define BitmapObject        MUI_NewObject(MUIC_Bitmap
#define BodychunkObject     MUI_NewObject(MUIC_Bodychunk
#define PixmapObject        MUI_NewObject(MUIC_Pixmap
#define NotifyObject        MUI_NewObject(MUIC_Notify
#define ApplicationObject   MUI_NewObject(MUIC_Application
#define TextObject          MUI_NewObject(MUIC_Text
#define RectangleObject     MUI_NewObject(MUIC_Rectangle
#define BalanceObject       MUI_NewObject(MUIC_Balance
#define ListObject          MUI_NewObject(MUIC_List
#define PropObject          MUI_NewObject(MUIC_Prop
#define StringObject        MUI_NewObject(MUIC_String
#define ScrollbarObject     MUI_NewObject(MUIC_Scrollbar
#define ListviewObject      MUI_NewObject(MUIC_Listview
#define RadioObject         MUI_NewObject(MUIC_Radio
#define VolumelistObject    MUI_NewObject(MUIC_Volumelist
#define FloattextObject     MUI_NewObject(MUIC_Floattext
#define DirlistObject       MUI_NewObject(MUIC_Dirlist
#define CycleObject         MUI_NewObject(MUIC_Cycle
#define GaugeObject         MUI_NewObject(MUIC_Gauge
#define ScaleObject         MUI_NewObject(MUIC_Scale
#define NumericObject       MUI_NewObject(MUIC_Numeric
#define SliderObject        MUI_NewObject(MUIC_Slider
#define NumericbuttonObject MUI_NewObject(MUIC_Numericbutton
#define KnobObject          MUI_NewObject(MUIC_Knob
#define LevelmeterObject    MUI_NewObject(MUIC_Levelmeter
#define BoopsiObject        MUI_NewObject(MUIC_Boopsi
#define ColorfieldObject    MUI_NewObject(MUIC_Colorfield
#define PenadjustObject     MUI_NewObject(MUIC_Penadjust
#define ColoradjustObject   MUI_NewObject(MUIC_Coloradjust
#define PaletteObject       MUI_NewObject(MUIC_Palette
#define GroupObject         MUI_NewObject(MUIC_Group
#define RegisterObject      MUI_NewObject(MUIC_Register
#define VirtgroupObject     MUI_NewObject(MUIC_Virtgroup
#define ScrollgroupObject   MUI_NewObject(MUIC_Scrollgroup
#define PopstringObject     MUI_NewObject(MUIC_Popstring
#define PopobjectObject     MUI_NewObject(MUIC_Popobject
#define PoplistObject       MUI_NewObject(MUIC_Poplist
#define PopaslObject        MUI_NewObject(MUIC_Popasl
#define PendisplayObject    MUI_NewObject(MUIC_Pendisplay
#define PoppenObject        MUI_NewObject(MUIC_Poppen
#define AboutmuiObject      MUI_NewObject(MUIC_Aboutmui
#define DataspaceObject     MUI_NewObject(MUIC_Dataspace
#define DatamapObject       MUI_NewObject(MUIC_Datamap
#define ObjectmapObject     MUI_NewObject(MUIC_Objectmap
#define TextdataObject      MUI_NewObject(MUIC_Textdata
#define VGroup              MUI_NewObject(MUIC_Group
#define HGroup              MUI_NewObject(MUIC_Group,MUIA_Group_Horiz,TRUE
#define ColGroup(cols)      MUI_NewObject(MUIC_Group,MUIA_Group_Columns,(cols)
#define RowGroup(rows)      MUI_NewObject(MUIC_Group,MUIA_Group_Rows   ,(rows)
#define PageGroup           MUI_NewObject(MUIC_Group,MUIA_Group_PageMode,TRUE
#define VGroupV             MUI_NewObject(MUIC_Virtgroup
#define HGroupV             MUI_NewObject(MUIC_Virtgroup,MUIA_Group_Horiz,TRUE
#define ColGroupV(cols)     MUI_NewObject(MUIC_Virtgroup,MUIA_Group_Columns,(cols)
#define RowGroupV(rows)     MUI_NewObject(MUIC_Virtgroup,MUIA_Group_Rows   ,(rows)
#define PageGroupV          MUI_NewObject(MUIC_Virtgroup,MUIA_Group_PageMode,TRUE
#define RegisterGroup(t)    MUI_NewObject(MUIC_Register,MUIA_Register_Titles,(t)
#define TitleObject         MUI_NewObject(MUIC_Title
#define End                 TAG_DONE)

#define Child             MUIA_Group_Child
#define SubWindow         MUIA_Application_Window
#define WindowContents    MUIA_Window_RootObject



/***************************************************************************
**
** Frame Types
** -----------
**
** These macros may be used to specify one of MUI's different frame types.
** Note that every macro consists of one { ti_Tag, ti_Data } pair.
**
** GroupFrameT() is a special kind of frame that contains a centered
** title text.
**
** HGroup, GroupFrameT("Horiz Groups"),
**    Child, RectangleObject, TextFrame  , End,
**    Child, RectangleObject, StringFrame, End,
**    Child, RectangleObject, ButtonFrame, End,
**    Child, RectangleObject, ListFrame  , End,
**    End,
**
***************************************************************************/

#define NoFrame          MUIA_Frame, MUIV_Frame_None
#define ButtonFrame      MUIA_Frame, MUIV_Frame_Button
#define ImageButtonFrame MUIA_Frame, MUIV_Frame_ImageButton
#define TextFrame        MUIA_Frame, MUIV_Frame_Text
#define StringFrame      MUIA_Frame, MUIV_Frame_String
#define ReadListFrame    MUIA_Frame, MUIV_Frame_ReadList
#define InputListFrame   MUIA_Frame, MUIV_Frame_InputList
#define PropFrame        MUIA_Frame, MUIV_Frame_Prop
#define SliderFrame      MUIA_Frame, MUIV_Frame_Slider
#define GaugeFrame       MUIA_Frame, MUIV_Frame_Gauge
#define VirtualFrame     MUIA_Frame, MUIV_Frame_Virtual
#define GroupFrame       MUIA_Frame, MUIV_Frame_Group
#define GroupFrameT(s)   MUIA_Frame, MUIV_Frame_Group, MUIA_FrameTitle, s, MUIA_Background, MUII_GroupBack



/***************************************************************************
**
** Spacing Macros
** --------------
**
***************************************************************************/

#define HVSpace           MUI_NewObject(MUIC_Rectangle,TAG_DONE)
#define HSpace(x)         MUI_MakeObject(MUIO_HSpace,(x))
#define VSpace(x)         MUI_MakeObject(MUIO_VSpace,(x))
#define HCenter(obj)      (HGroup, GroupSpacing(0), Child, HSpace(0), Child, (obj), Child, HSpace(0), End)
#define VCenter(obj)      (VGroup, GroupSpacing(0), Child, VSpace(0), Child, (obj), Child, VSpace(0), End)
#define InnerSpacing(h,v) MUIA_InnerLeft,(h),MUIA_InnerRight,(h),MUIA_InnerTop,(v),MUIA_InnerBottom,(v)
#define GroupSpacing(x)   MUIA_Group_Spacing,(x)



#ifdef MUI_OBSOLETE

/***************************************************************************
**
** String-Object
** -------------
**
** The following macro creates a simple string gadget.
**
***************************************************************************/

#define String(contents,maxlen)\
    StringObject,\
        StringFrame,\
        MUIA_String_MaxLen  , maxlen,\
        MUIA_String_Contents, contents,\
        End

#define KeyString(contents,maxlen,controlchar)\
    StringObject,\
        StringFrame,\
        MUIA_ControlChar    , controlchar,\
        MUIA_String_MaxLen  , maxlen,\
        MUIA_String_Contents, contents,\
        End

#endif



#ifdef MUI_OBSOLETE

/***************************************************************************
**
** CheckMark-Object
** ----------------
**
** The following macro creates a checkmark gadget.
**
***************************************************************************/

#define CheckMark(selected)\
    ImageObject,\
        ImageButtonFrame,\
        MUIA_InputMode        , MUIV_InputMode_Toggle,\
        MUIA_Image_Spec       , MUII_CheckMark,\
        MUIA_Image_FreeVert   , TRUE,\
        MUIA_Selected         , selected,\
        MUIA_Background       , MUII_ButtonBack,\
        MUIA_ShowSelState     , FALSE,\
        End

#define KeyCheckMark(selected,control)\
    ImageObject,\
        ImageButtonFrame,\
        MUIA_InputMode        , MUIV_InputMode_Toggle,\
        MUIA_Image_Spec       , MUII_CheckMark,\
        MUIA_Image_FreeVert   , TRUE,\
        MUIA_Selected         , selected,\
        MUIA_Background       , MUII_ButtonBack,\
        MUIA_ShowSelState     , FALSE,\
        MUIA_ControlChar      , control,\
        End

#endif


/***************************************************************************
**
** Button-Objects
** --------------
**
** Note: Use small letters for KeyButtons, e.g.
**       KeyButton("Cancel",'c')  and not  KeyButton("Cancel",'C') !!
**
***************************************************************************/

#define SimpleButton(label) MUI_MakeObject(MUIO_Button,(unsigned long)label)

#ifdef MUI_OBSOLETE

#define KeyButton(name,key)\
    TextObject,\
        ButtonFrame,\
        MUIA_Font, MUIV_Font_Button,\
        MUIA_Text_Contents, name,\
        MUIA_Text_PreParse, "\33c",\
        MUIA_Text_HiChar  , key,\
        MUIA_ControlChar  , key,\
        MUIA_InputMode    , MUIV_InputMode_RelVerify,\
        MUIA_Background   , MUII_ButtonBack,\
        End

#endif


#ifdef MUI_OBSOLETE

/***************************************************************************
**
** Cycle-Object
** ------------
**
***************************************************************************/

#define Cycle(entries)        CycleObject, MUIA_Font, MUIV_Font_Button, MUIA_Cycle_Entries, entries, End
#define KeyCycle(entries,key) CycleObject, MUIA_Font, MUIV_Font_Button, MUIA_Cycle_Entries, entries, MUIA_ControlChar, key, End



/***************************************************************************
**
** Radio-Object
** ------------
**
***************************************************************************/

#define Radio(name,array)\
    RadioObject,\
        GroupFrameT(name),\
        MUIA_Radio_Entries,array,\
        End

#define KeyRadio(name,array,key)\
    RadioObject,\
        GroupFrameT(name),\
        MUIA_Radio_Entries,array,\
        MUIA_ControlChar, key,\
        End



/***************************************************************************
**
** Slider-Object
** -------------
**
***************************************************************************/


#define Slider(min,max,level)\
    SliderObject,\
        MUIA_Numeric_Min  , min,\
        MUIA_Numeric_Max  , max,\
        MUIA_Numeric_Value, level,\
        End

#define KeySlider(min,max,level,key)\
    SliderObject,\
        MUIA_Numeric_Min  , min,\
        MUIA_Numeric_Max  , max,\
        MUIA_Numeric_Value, level,\
        MUIA_ControlChar , key,\
        End

#endif



/***************************************************************************
**
** Button to be used for popup objects
**
***************************************************************************/

#define PopButton(img) MUI_MakeObject(MUIO_PopButton,(unsigned long)img)



/***************************************************************************
**
** Labeling Objects
** ----------------
**
** Labeling objects, e.g. a group of string gadgets,
**
**   Small: |foo   |
**  Normal: |bar   |
**     Big: |foobar|
**    Huge: |barfoo|
**
** is done using a 2 column group:
**
** ColGroup(2),
**  Child, Label2("Small:" ),
**    Child, StringObject, End,
**  Child, Label2("Normal:"),
**    Child, StringObject, End,
**  Child, Label2("Big:"   ),
**    Child, StringObject, End,
**  Child, Label2("Huge:"  ),
**    Child, StringObject, End,
**    End,
**
** Note that we have three versions of the label macro, depending on
** the frame type of the right hand object:
**
** Label1(): For use with standard frames (e.g. checkmarks).
** Label2(): For use with double high frames (e.g. string gadgets).
** Label() : For use with objects without a frame.
**
** These macros ensure that your label will look fine even if the
** user of your application configured some strange spacing values.
** If you want to use your own labeling, you'll have to pay attention
** on this topic yourself.
**
***************************************************************************/

#define Label(label)   MUI_MakeObject(MUIO_Label,(unsigned long)label,0)
#define Label1(label)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_SingleFrame)
#define Label2(label)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_DoubleFrame)
#define LLabel(label)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_LeftAligned)
#define LLabel1(label) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_LeftAligned|MUIO_Label_SingleFrame)
#define LLabel2(label) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_LeftAligned|MUIO_Label_DoubleFrame)
#define CLabel(label)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_Centered)
#define CLabel1(label) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_Centered|MUIO_Label_SingleFrame)
#define CLabel2(label) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_Centered|MUIO_Label_DoubleFrame)

#define FreeLabel(label)   MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert)
#define FreeLabel1(label)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_SingleFrame)
#define FreeLabel2(label)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_DoubleFrame)
#define FreeLLabel(label)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_LeftAligned)
#define FreeLLabel1(label) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_LeftAligned|MUIO_Label_SingleFrame)
#define FreeLLabel2(label) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_LeftAligned|MUIO_Label_DoubleFrame)
#define FreeCLabel(label)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_Centered)
#define FreeCLabel1(label) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_Centered|MUIO_Label_SingleFrame)
#define FreeCLabel2(label) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_Centered|MUIO_Label_DoubleFrame)

#define KeyLabel(label,key)   MUI_MakeObject(MUIO_Label,(unsigned long)label,key)
#define KeyLabel1(label,key)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_SingleFrame|(key))
#define KeyLabel2(label,key)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_DoubleFrame|(key))
#define KeyLLabel(label,key)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_LeftAligned|(key))
#define KeyLLabel1(label,key) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_LeftAligned|MUIO_Label_SingleFrame|(key))
#define KeyLLabel2(label,key) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_LeftAligned|MUIO_Label_DoubleFrame|(key))
#define KeyCLabel(label,key)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_Centered|(key))
#define KeyCLabel1(label,key) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_Centered|MUIO_Label_SingleFrame|(key))
#define KeyCLabel2(label,key) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_Centered|MUIO_Label_DoubleFrame|(key))

#define FreeKeyLabel(label,key)   MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|(key))
#define FreeKeyLabel1(label,key)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_SingleFrame|(key))
#define FreeKeyLabel2(label,key)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_DoubleFrame|(key))
#define FreeKeyLLabel(label,key)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_LeftAligned|(key))
#define FreeKeyLLabel1(label,key) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_LeftAligned|MUIO_Label_SingleFrame|(key))
#define FreeKeyLLabel2(label,key) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_LeftAligned|MUIO_Label_DoubleFrame|(key))
#define FreeKeyCLabel(label,key)  MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_Centered|(key))
#define FreeKeyCLabel1(label,key) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_Centered|MUIO_Label_SingleFrame|(key))
#define FreeKeyCLabel2(label,key) MUI_MakeObject(MUIO_Label,(unsigned long)label,MUIO_Label_FreeVert|MUIO_Label_Centered|MUIO_Label_DoubleFrame|(key))



/***************************************************************************
**
** Textdata shortcuts
**
***************************************************************************/

#ifndef MIBENUM_ISO_8859_1
#define MIBENUM_ISO_8859_1      4
#endif
#ifndef MIBENUM_UTF_8
#define MIBENUM_UTF_8           106
#endif
#ifndef MIBENUM_ISO_10646_UCS_2
#define MIBENUM_ISO_10646_UCS_2 1000
#endif

#define Textdata(s)      TextdataObject, MUIA_Textdata_Contents, (s), End
#define LTextdata(s)     TextdataObject, MUIA_Textdata_Contents, (s), MUIA_Textdata_Encoding, MIBENUM_ISO_10646_UCS_2, End
#define UTextdata(s)     TextdataObject, MUIA_Textdata_Contents, (s), MUIA_Textdata_Encoding, MIBENUM_UTF_8, End
#define ATextdata(s)     TextdataObject, MUIA_Textdata_Contents, (s), MUIA_Textdata_Encoding, MIBENUM_ISO_8859_1, End

/***************************************************************************
**
** Controlling Objects
** -------------------
**
** set() and get() are two short stubs for BOOPSI GetAttr() and SetAttrs()
** calls:
**
** {
**    char *x;
**
**    set(obj,MUIA_String_Contents,"foobar");
**    get(obj,MUIA_String_Contents,&x);
**
**    printf("gadget contains '%s'\n",x);
** }
**
** nnset() sets an attribute without triggering a possible notification.
**
***************************************************************************/

#ifndef __cplusplus

#define get(obj, attr, store) GetAttr((attr), (obj), (ULONG *)(void *)(store))
#define set(obj, attr, value) SetAttrs((obj), (attr), value, TAG_DONE)
#define nnset(obj, attr, value) SetAttrs((obj), MUIA_NoNotify, TRUE, (attr), (value), TAG_DONE)

#define setmutex(obj, n)     set(obj, MUIA_Radio_Active, (n))
#define setcycle(obj, n)     set(obj, MUIA_Cycle_Active, (n))
#define setstring(obj, s)    set(obj, MUIA_String_Contents, (s))
#define setcheckmark(obj, b) set(obj, MUIA_Selected, (b))
#define setslider(obj, l)    set(obj, MUIA_Numeric_Value, (l))

#endif

#endif /* MUI_NOSHORTCUTS */


/***************************************************************************
**
** For Boopsi Image Implementors Only:
**
** If MUI is using a boopsi image object, it will send a special method
** immediately after object creation. This method has a parameter structure
** where the boopsi can fill in its minimum and maximum size and learn if
** its used in a horizontal or vertical context.
**
** The boopsi image must use the method id (MUIM_BoopsiQuery) as return
** value. That's how MUI sees that the method is implemented.
**
** Note: MUI does not depend on this method. If the boopsi image doesn't
**       implement it, minimum size will be 0 and maximum size unlimited.
**
***************************************************************************/

#define MUIM_BoopsiQuery 0x80427157 /* this is send to the boopsi and */
                                    /* must be used as return value   */

struct MUI_BoopsiQuery              /* parameter structure */
{
    ULONG mbq_MethodID;              /* always MUIM_BoopsiQuery */

    struct Screen *mbq_Screen;       /* obsolete, use mbq_RenderInfo */
    ULONG mbq_Flags;                 /* read only, see below */

    LONG mbq_MinWidth ;              /* write only, fill in min width  */
    LONG mbq_MinHeight;              /* write only, fill in min height */
    LONG mbq_MaxWidth ;              /* write only, fill in max width  */
    LONG mbq_MaxHeight;              /* write only, fill in max height */
    LONG mbq_DefWidth ;              /* write only, fill in def width  */
    LONG mbq_DefHeight;              /* write only, fill in def height */

    struct MUI_RenderInfo *mbq_RenderInfo;  /* read only, display context */

    /* may grow in future ... */
};

#define MUIP_BoopsiQuery MUI_BoopsiQuery  /* old structure name */

#define MBQF_HORIZ (1<<0)           /* object used in a horizontal */
                                    /* context (else vertical)     */

#define MBQ_MUI_MAXMAX (10000)          /* use this for unlimited MaxWidth/Height */

#define IDCMP_MOUSEOBJECT 0x40000000 /* special idcmp message created by MUI */

/* Flags for Slave.mui MUIM_Slave_Delegate */
#define MUIF_Slave_Delegate_ForceSlave (1<<0) /* skip caller task check and always dispatch the
                                                 method on Slave's thread; useful when calling
                                                 from a process which is neither the main MUI
                                                 process nor the Slave's process */

/* useful macros to extract the individual dimensions from the value returned by MUIM_TextDim */
#define DIM2WIDTH(dim)  (((LONG)(dim)) & 0xffff)
#define DIM2HEIGHT(dim) (((LONG)(dim)) >> 16)


/*******************************************/
/* Begin of automatic header file creation */
/*******************************************/




/****************************************************************************/
/** Notify                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Notify[];
#else
#define MUIC_Notify "Notify.mui"
#endif

/* Methods */

#define MUIM_CallHook                       0x8042b96b /* V4  */
#define MUIM_Export                         0x80420f1c /* V12 */
#define MUIM_FindObject                     0x8042038f /* V13 */
#define MUIM_FindUData                      0x8042c196 /* V8  */
#define MUIM_GetConfigItem                  0x80423edb /* V11 */
#define MUIM_GetUData                       0x8042ed0c /* V8  */
#define MUIM_Import                         0x8042d012 /* V12 */
#define MUIM_KillNotify                     0x8042d240 /* V4  */
#define MUIM_KillNotifyObj                  0x8042b145 /* V16 */
#define MUIM_MultiSet                       0x8042d356 /* V7  */
#define MUIM_NoNotifySet                    0x8042216f /* V9  */
#define MUIM_Notify                         0x8042c9cb /* V4  */
#define MUIM_Set                            0x8042549a /* V4  */
#define MUIM_SetAsString                    0x80422590 /* V4  */
#define MUIM_SetUData                       0x8042c920 /* V8  */
#define MUIM_SetUDataOnce                   0x8042ca19 /* V11 */
#define MUIM_WriteLong                      0x80428d86 /* V6  */
#define MUIM_WriteString                    0x80424bf4 /* V6  */
struct  MUIP_CallHook                       { ULONG MethodID; struct Hook *Hook; ULONG param1; /* ... */ };
struct  MUIP_Export                         { ULONG MethodID; Object *dataspace; };
struct  MUIP_FindObject                     { ULONG MethodID; Object *findme; };
struct  MUIP_FindUData                      { ULONG MethodID; ULONG udata; };
struct  MUIP_GetConfigItem                  { ULONG MethodID; ULONG id; ULONG *storage; };
struct  MUIP_GetUData                       { ULONG MethodID; ULONG udata; ULONG attr; ULONG *storage; };
struct  MUIP_Import                         { ULONG MethodID; Object *dataspace; };
struct  MUIP_KillNotify                     { ULONG MethodID; ULONG TrigAttr; };
struct  MUIP_KillNotifyObj                  { ULONG MethodID; ULONG TrigAttr; Object *dest; };
struct  MUIP_MultiSet                       { ULONG MethodID; ULONG attr; ULONG val; Object *obj; /* ... */ };
struct  MUIP_NoNotifySet                    { ULONG MethodID; ULONG attr; ULONG val; /* ... */ };
struct  MUIP_Notify                         { ULONG MethodID; ULONG TrigAttr; ULONG TrigVal; Object *DestObj; ULONG FollowParams; /* ... */ };
struct  MUIP_Set                            { ULONG MethodID; ULONG attr; ULONG val; };
struct  MUIP_SetAsString                    { ULONG MethodID; ULONG attr; CONST_STRPTR format; ULONG val; /* ... */ };
struct  MUIP_SetUData                       { ULONG MethodID; ULONG udata; ULONG attr; ULONG val; };
struct  MUIP_SetUDataOnce                   { ULONG MethodID; ULONG udata; ULONG attr; ULONG val; };
struct  MUIP_WriteLong                      { ULONG MethodID; ULONG val; ULONG *memory; };
struct  MUIP_WriteString                    { ULONG MethodID; CONST_STRPTR str; STRPTR memory; };

/* Attributes */

#define MUIA_ApplicationObject              0x8042d3ee /* V4  ..g Object *          */
#define MUIA_AppMessage                     0x80421955 /* V5  ..g struct AppMessage * */
#define MUIA_HelpLine                       0x8042a825 /* V4  isg LONG              */
#define MUIA_HelpNode                       0x80420b85 /* V4  isg STRPTR            */
#define MUIA_NoNotify                       0x804237f9 /* V7  .s. BOOL              */
#define MUIA_NoNotifyMethod                 0x80420a74 /* V20 .s. ULONG             */
#define MUIA_ObjectID                       0x8042d76e /* V11 isg ULONG             */
#define MUIA_Parent                         0x8042e35f /* V11 ..g Object *          */
#define MUIA_Revision                       0x80427eaa /* V4  ..g LONG              */
#define MUIA_UserData                       0x80420313 /* V4  isg ULONG             */
#define MUIA_Version                        0x80422301 /* V4  ..g LONG              */



/****************************************************************************/
/** Family                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Family[];
#else
#define MUIC_Family "Family.mui"
#endif

/* Methods */

#define MUIM_Family_AddHead                 0x8042e200 /* V8  */
#define MUIM_Family_AddTail                 0x8042d752 /* V8  */
#define MUIM_Family_DoChildMethods          0x80429a3c /* V20 */
#define MUIM_Family_GetChild                0x8042c556 /* V20 */
#define MUIM_Family_Insert                  0x80424d34 /* V8  */
#define MUIM_Family_Remove                  0x8042f8a9 /* V8  */
#define MUIM_Family_Reorder                 0x80426008 /* V21 */
#define MUIM_Family_Sort                    0x80421c49 /* V8  */
#define MUIM_Family_Transfer                0x8042c14a /* V8  */
struct  MUIP_Family_AddHead                 { ULONG MethodID; Object *obj; };
struct  MUIP_Family_AddTail                 { ULONG MethodID; Object *obj; };
struct  MUIP_Family_DoChildMethods          { ULONG MethodID; /* ... */ };
struct  MUIP_Family_GetChild                { ULONG MethodID; LONG nr; Object *ref; };
struct  MUIP_Family_Insert                  { ULONG MethodID; Object *obj; Object *pred; };
struct  MUIP_Family_Remove                  { ULONG MethodID; Object *obj; };
struct  MUIP_Family_Reorder                 { ULONG MethodID; Object *after; Object *array[1]; };
struct  MUIP_Family_Sort                    { ULONG MethodID; Object *obj[1]; };
struct  MUIP_Family_Transfer                { ULONG MethodID; Object *family; };

/* Attributes */

#define MUIA_Family_Child                   0x8042c696 /* V8  i.. Object *          */
#define MUIA_Family_ChildCount              0x8042b25a /* V20 ..g LONG              */
#define MUIA_Family_List                    0x80424b9e /* V8  ..g struct MinList *  */



/****************************************************************************/
/** Menustrip                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Menustrip[];
#else
#define MUIC_Menustrip "Menustrip.mui"
#endif

/* Methods */

#define MUIM_Menustrip_ExitChange           0x8042ce4d /* V20 */
#define MUIM_Menustrip_InitChange           0x8042dcd9 /* V20 */
#define MUIM_Menustrip_Popup                0x80420e76 /* V20 */
#define MUIM_Menustrip_WillOpen             0x804230e9 /* V22 */
struct  MUIP_Menustrip_ExitChange           { ULONG MethodID; };
struct  MUIP_Menustrip_InitChange           { ULONG MethodID; };
struct  MUIP_Menustrip_Popup                { ULONG MethodID; Object *parent; ULONG flags; LONG x; LONG y; };
struct  MUIP_Menustrip_WillOpen             { ULONG MethodID; };

/* Attributes */

#define MUIA_Menustrip_CaseSensitive        0x8042d718 /* V20 i.g BOOL              */
#define MUIA_Menustrip_Enabled              0x8042815b /* V8  isg BOOL              */



/****************************************************************************/
/** Menu                                                                   **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Menu[];
#else
#define MUIC_Menu "Menu.mui"
#endif

/* Attributes */

#define MUIA_Menu_CopyStrings               0x8042dbe2 /* V20 i.. BOOL              */
#define MUIA_Menu_Enabled                   0x8042ed48 /* V8  isg BOOL              */
#define MUIA_Menu_Title                     0x8042a0e3 /* V8  isg STRPTR            */



/****************************************************************************/
/** Menuitem                                                               **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Menuitem[];
#else
#define MUIC_Menuitem "Menuitem.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Menuitem_AISSName              0x804248f2 /* V21 isg STRPTR            */
#define MUIA_Menuitem_Checked               0x8042562a /* V8  isg BOOL              */
#define MUIA_Menuitem_Checkit               0x80425ace /* V8  isg BOOL              */
#define MUIA_Menuitem_CommandString         0x8042b9cc /* V16 isg BOOL              */
#define MUIA_Menuitem_CopyStrings           0x8042dc1b /* V16 i.. BOOL              */
#define MUIA_Menuitem_Enabled               0x8042ae0f /* V8  isg BOOL              */
#define MUIA_Menuitem_Exclude               0x80420bc6 /* V8  isg LONG              */
#define MUIA_Menuitem_FreeImage             0x8042f95f /* V20 i.. BOOL              */
#define MUIA_Menuitem_Image                 0x8042080b /* V20 isg struct Image *    */
#define MUIA_Menuitem_Menuitem              0x80424b21 /* V20 isg Object *          */
#define MUIA_Menuitem_Shortcut              0x80422030 /* V8  isg STRPTR            */
#define MUIA_Menuitem_Title                 0x804218be /* V8  isg STRPTR            */
#define MUIA_Menuitem_Toggle                0x80424d5c /* V8  isg BOOL              */
#define MUIA_Menuitem_Trigger               0x80426f32 /* V8  .sg struct MenuItem * */

#define MUIV_Menuitem_Shortcut_Check -1


/****************************************************************************/
/** Application                                                            **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Application[];
#else
#define MUIC_Application "Application.mui"
#endif

/* Methods */

#define MUIM_Application_AboutMUI           0x8042d21d /* V14 */
#define MUIM_Application_AddInputHandler    0x8042f099 /* V11 */
#define MUIM_Application_BuildSettingsPanel 0x8042b58f /* V20 */
#define MUIM_Application_CheckRefresh       0x80424d68 /* V11 */
#define MUIM_Application_DefaultConfigItem  0x8042d934 /* V20 */
#define MUIM_Application_Execute            0x804253f3 /* V20 */
#ifdef MUI_OBSOLETE
#define MUIM_Application_GetMenuCheck       0x8042c0a7 /* V4  */
#endif /* MUI_OBSOLETE */
#ifdef MUI_OBSOLETE
#define MUIM_Application_GetMenuState       0x8042a58f /* V4  */
#endif /* MUI_OBSOLETE */
#ifdef MUI_OBSOLETE
#define MUIM_Application_Input              0x8042d0f5 /* V4  */
#endif /* MUI_OBSOLETE */
#define MUIM_Application_InputBuffered      0x80427e59 /* V4  */
#define MUIM_Application_Load               0x8042f90d /* V4  */
#define MUIM_Application_NewInput           0x80423ba6 /* V11 */
#define MUIM_Application_OpenConfigWindow   0x804299ba /* V11 */
#define MUIM_Application_PushMethod         0x80429ef8 /* V4  */
#define MUIM_Application_RemInputHandler    0x8042e7af /* V11 */
#define MUIM_Application_ReturnID           0x804276ef /* V4  */
#define MUIM_Application_Run                0x90420103 /* Extension method */ /* V20 */
#define MUIM_Application_Save               0x804227ef /* V4  */
#define MUIM_Application_SetConfigItem      0x80424a80 /* V11 */
#ifdef MUI_OBSOLETE
#define MUIM_Application_SetMenuCheck       0x8042a707 /* V4  */
#endif /* MUI_OBSOLETE */
#ifdef MUI_OBSOLETE
#define MUIM_Application_SetMenuState       0x80428bef /* V4  */
#endif /* MUI_OBSOLETE */
#define MUIM_Application_ShowHelp           0x80426479 /* V4  */
#define MUIM_Application_UnpushMethod       0x804211dd /* V20 */
struct  MUIP_Application_AboutMUI           { ULONG MethodID; Object *refwindow; };
struct  MUIP_Application_AddInputHandler    { ULONG MethodID; struct MUI_InputHandlerNode *ihnode; };
struct  MUIP_Application_BuildSettingsPanel { ULONG MethodID; ULONG number; };
struct  MUIP_Application_CheckRefresh       { ULONG MethodID; };
struct  MUIP_Application_DefaultConfigItem  { ULONG MethodID; ULONG cfgid; };
struct  MUIP_Application_Execute            { ULONG MethodID; };
struct  MUIP_Application_GetMenuCheck       { ULONG MethodID; ULONG MenuID; };
struct  MUIP_Application_GetMenuState       { ULONG MethodID; ULONG MenuID; };
struct  MUIP_Application_Input              { ULONG MethodID; ULONG *signal; };
struct  MUIP_Application_InputBuffered      { ULONG MethodID; };
struct  MUIP_Application_Load               { ULONG MethodID; CONST_STRPTR name; };
struct  MUIP_Application_NewInput           { ULONG MethodID; ULONG *signal; };
struct  MUIP_Application_OpenConfigWindow   { ULONG MethodID; ULONG flags; STRPTR classid; };
struct  MUIP_Application_PushMethod         { ULONG MethodID; Object *dest; LONG count; /* ... */ };
struct  MUIP_Application_RemInputHandler    { ULONG MethodID; struct MUI_InputHandlerNode *ihnode; };
struct  MUIP_Application_ReturnID           { ULONG MethodID; ULONG retid; };
struct  MUIP_Application_Run                { ULONG MethodID; }; /* Extension method */
struct  MUIP_Application_Save               { ULONG MethodID; CONST_STRPTR name; };
struct  MUIP_Application_SetConfigItem      { ULONG MethodID; ULONG item; CONST_APTR data; };
struct  MUIP_Application_SetMenuCheck       { ULONG MethodID; ULONG MenuID; LONG stat; };
struct  MUIP_Application_SetMenuState       { ULONG MethodID; ULONG MenuID; LONG stat; };
struct  MUIP_Application_ShowHelp           { ULONG MethodID; Object *window; CONST_STRPTR name; CONST_STRPTR node; LONG line; };
struct  MUIP_Application_UnpushMethod       { ULONG MethodID; Object *targetobj; ULONG methodid; ULONG method; };

/* Attributes */

#define MUIA_Application_Active             0x804260ab /* V4  isg BOOL              */
#define MUIA_Application_Author             0x80424842 /* V4  i.g STRPTR            */
#define MUIA_Application_Base               0x8042e07a /* V4  i.g STRPTR            */
#define MUIA_Application_Broker             0x8042dbce /* V4  ..g CxObj *           */
#define MUIA_Application_BrokerHook         0x80428f4b /* V4  isg struct Hook *     */
#define MUIA_Application_BrokerPort         0x8042e0ad /* V6  ..g struct MsgPort *  */
#define MUIA_Application_BrokerPri          0x8042c8d0 /* V6  i.g LONG              */
#define MUIA_Application_Commands           0x80428648 /* V4  isg struct MUI_Command * */
#define MUIA_Application_Copyright          0x8042ef4d /* V4  i.g STRPTR            */
#define MUIA_Application_Description        0x80421fc6 /* V4  i.g STRPTR            */
#define MUIA_Application_DiskObject         0x804235cb /* V4  isg struct DiskObject * */
#define MUIA_Application_DoubleStart        0x80423bc6 /* V4  ..g BOOL              */
#define MUIA_Application_DropObject         0x80421266 /* V5  is. Object *          */
#define MUIA_Application_ForceQuit          0x804257df /* V8  .sg BOOL              */
#define MUIA_Application_HelpFile           0x804293f4 /* V8  isg STRPTR            */
#define MUIA_Application_Iconified          0x8042a07f /* V4  .sg BOOL              */
#define MUIA_Application_IconifyTitle       0x80422cb8 /* V18 isg STRPTR            */
#ifdef MUI_OBSOLETE
#define MUIA_Application_Menu               0x80420e1f /* V4  i.g struct NewMenu *  */
#endif /* MUI_OBSOLETE */
#define MUIA_Application_MenuAction         0x80428961 /* V4  ..g ULONG             */
#define MUIA_Application_MenuHelp           0x8042540b /* V4  ..g ULONG             */
#define MUIA_Application_Menustrip          0x804252d9 /* V8  i.g Object *          */
#define MUIA_Application_RexxHook           0x80427c42 /* V7  isg struct Hook *     */
#define MUIA_Application_RexxMsg            0x8042fd88 /* V4  ..g struct RxMsg *    */
#define MUIA_Application_RexxString         0x8042d711 /* V4  .s. STRPTR            */
#define MUIA_Application_SingleTask         0x8042a2c8 /* V4  i.. BOOL              */
#define MUIA_Application_Sleep              0x80425711 /* V4  .sg BOOL              */
#define MUIA_Application_Title              0x804281b8 /* V4  i.g STRPTR            */
#define MUIA_Application_UseCommodities     0x80425ee5 /* V10 i.. BOOL              */
#define MUIA_Application_UsedClasses        0x8042e9a7 /* V20 isg STRPTR *          */
#define MUIA_Application_UseRexx            0x80422387 /* V10 i.. BOOL              */
#define MUIA_Application_UseScreenNotify    0x80420861 /* V20 i.. BOOL              */
#define MUIA_Application_Version            0x8042b33f /* V4  i.g STRPTR            */
#define MUIA_Application_Window             0x8042bfe0 /* V4  i.. Object *          */
#define MUIA_Application_WindowList         0x80429abe /* V13 ..g struct List *     */



/****************************************************************************/
/** Window                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Window[];
#else
#define MUIC_Window "Window.mui"
#endif

/* Methods */

#define MUIM_Window_AddEventHandler         0x804203b7 /* V16 */
#define MUIM_Window_Cleanup                 0x8042ab26 /* V18 */
#ifdef MUI_OBSOLETE
#define MUIM_Window_GetMenuCheck            0x80420414 /* V4  */
#endif /* MUI_OBSOLETE */
#ifdef MUI_OBSOLETE
#define MUIM_Window_GetMenuState            0x80420d2f /* V4  */
#endif /* MUI_OBSOLETE */
#define MUIM_Window_RemEventHandler         0x8042679e /* V16 */
#define MUIM_Window_ScreenToBack            0x8042913d /* V4  */
#define MUIM_Window_ScreenToFront           0x804227a4 /* V4  */
#ifdef MUI_OBSOLETE
#define MUIM_Window_SetCycleChain           0x80426510 /* V4  */
#endif /* MUI_OBSOLETE */
#ifdef MUI_OBSOLETE
#define MUIM_Window_SetMenuCheck            0x80422243 /* V4  */
#endif /* MUI_OBSOLETE */
#ifdef MUI_OBSOLETE
#define MUIM_Window_SetMenuState            0x80422b5e /* V4  */
#endif /* MUI_OBSOLETE */
#define MUIM_Window_Setup                   0x8042c34c /* V18 */
#define MUIM_Window_Snapshot                0x8042945e /* V11 */
#define MUIM_Window_ToBack                  0x8042152e /* V4  */
#define MUIM_Window_ToFront                 0x8042554f /* V4  */
struct  MUIP_Window_AddEventHandler         { ULONG MethodID; struct MUI_EventHandlerNode *ehnode; };
struct  MUIP_Window_Cleanup                 { ULONG MethodID; };
struct  MUIP_Window_GetMenuCheck            { ULONG MethodID; ULONG MenuID; };
struct  MUIP_Window_GetMenuState            { ULONG MethodID; ULONG MenuID; };
struct  MUIP_Window_RemEventHandler         { ULONG MethodID; struct MUI_EventHandlerNode *ehnode; };
struct  MUIP_Window_ScreenToBack            { ULONG MethodID; };
struct  MUIP_Window_ScreenToFront           { ULONG MethodID; };
struct  MUIP_Window_SetCycleChain           { ULONG MethodID; Object *obj[1]; };
struct  MUIP_Window_SetMenuCheck            { ULONG MethodID; ULONG MenuID; LONG stat; };
struct  MUIP_Window_SetMenuState            { ULONG MethodID; ULONG MenuID; LONG stat; };
struct  MUIP_Window_Setup                   { ULONG MethodID; };
struct  MUIP_Window_Snapshot                { ULONG MethodID; LONG flags; };
struct  MUIP_Window_ToBack                  { ULONG MethodID; };
struct  MUIP_Window_ToFront                 { ULONG MethodID; };

/* Attributes */

#define MUIA_Window_Activate                0x80428d2f /* V4  isg BOOL              */
#define MUIA_Window_ActiveObject            0x80427925 /* V4  .sg Object *          */
#define MUIA_Window_AltHeight               0x8042cce3 /* V4  i.g LONG              */
#define MUIA_Window_AltLeftEdge             0x80422d65 /* V4  i.g LONG              */
#define MUIA_Window_AltTopEdge              0x8042e99b /* V4  i.g LONG              */
#define MUIA_Window_AltWidth                0x804260f4 /* V4  i.g LONG              */
#define MUIA_Window_AppWindow               0x804280cf /* V5  i.. BOOL              */
#define MUIA_Window_Backdrop                0x8042c0bb /* V4  i.. BOOL              */
#define MUIA_Window_Borderless              0x80429b79 /* V4  i.. BOOL              */
#define MUIA_Window_CloseGadget             0x8042a110 /* V4  i.. BOOL              */
#define MUIA_Window_CloseRequest            0x8042e86e /* V4  .sg BOOL              */
#define MUIA_Window_DefaultObject           0x804294d7 /* V4  isg Object *          */
#define MUIA_Window_DepthGadget             0x80421923 /* V4  i.. BOOL              */
#define MUIA_Window_DisableKeys             0x80424c36 /* V15 isg ULONG             */
#define MUIA_Window_DragBar                 0x8042045d /* V4  i.. BOOL              */
#define MUIA_Window_DrawInfo                0x80423726 /* V4  ..g struct DrawInfo * */
#ifdef MUI_OBSOLETE
#define MUIA_Window_FancyDrawing            0x8042bd0e /* V8  isg BOOL              */
#endif /* MUI_OBSOLETE */
#define MUIA_Window_Height                  0x80425846 /* V4  isg LONG              */
#define MUIA_Window_ID                      0x804201bd /* V4  isg ULONG             */
#define MUIA_Window_InputEvent              0x804247d8 /* V4  ..g struct InputEvent * */
#define MUIA_Window_IsSubWindow             0x8042b5aa /* V4  isg BOOL              */
#define MUIA_Window_LeftEdge                0x80426c65 /* V4  isg LONG              */
#ifdef MUI_OBSOLETE
#define MUIA_Window_Menu                    0x8042db94 /* V4  i.. struct NewMenu *  */
#endif /* MUI_OBSOLETE */
#define MUIA_Window_MenuAction              0x80427521 /* V8  isg ULONG             */
#define MUIA_Window_Menustrip               0x8042855e /* V8  isg Object *          */
#define MUIA_Window_MouseObject             0x8042bf9b /* V10 ..g Object *          */
#ifdef MUI_OBSOLETE
#define MUIA_Window_NeedsMouseObject        0x8042372a /* V10 i.. BOOL              */
#endif /* MUI_OBSOLETE */
#define MUIA_Window_NoMenus                 0x80429df5 /* V4  isg BOOL              */
#define MUIA_Window_Opacity                 0x80429617 /* V20 isg LONG              */
#define MUIA_Window_Open                    0x80428aa0 /* V4  .sg BOOL              */
#define MUIA_Window_PublicScreen            0x804278e4 /* V6  isg STRPTR            */
#define MUIA_Window_RefWindow               0x804201f4 /* V4  is. Object *          */
#define MUIA_Window_RootObject              0x8042cba5 /* V4  isg Object *          */
#define MUIA_Window_Screen                  0x8042df4f /* V4  isg struct Screen *   */
#define MUIA_Window_ScreenTitle             0x804234b0 /* V5  isg STRPTR            */
#define MUIA_Window_SizeGadget              0x8042e33d /* V4  i.. BOOL              */
#define MUIA_Window_SizeRight               0x80424780 /* V4  i.. BOOL              */
#define MUIA_Window_Sleep                   0x8042e7db /* V4  .sg BOOL              */
#define MUIA_Window_Title                   0x8042ad3d /* V4  isg STRPTR            */
#define MUIA_Window_TopEdge                 0x80427c66 /* V4  isg LONG              */
#define MUIA_Window_UseBottomBorderScroller 0x80424e79 /* V13 isg BOOL              */
#define MUIA_Window_UseLeftBorderScroller   0x8042433e /* V13 isg BOOL              */
#define MUIA_Window_UseRightBorderScroller  0x8042c05e /* V13 isg BOOL              */
#define MUIA_Window_Width                   0x8042dcae /* V4  isg LONG              */
#define MUIA_Window_Window                  0x80426a42 /* V4  ..g struct Window *   */

#define MUIV_Window_ActiveObject_None 0
#define MUIV_Window_ActiveObject_Next -1
#define MUIV_Window_ActiveObject_Prev -2
#define MUIV_Window_ActiveObject_Left -3
#define MUIV_Window_ActiveObject_Right -4
#define MUIV_Window_ActiveObject_Up -5
#define MUIV_Window_ActiveObject_Down -6
#define MUIV_Window_AltHeight_MinMax(p) (0-(p))
#define MUIV_Window_AltHeight_Visible(p) (-100-(p))
#define MUIV_Window_AltHeight_Screen(p) (-200-(p))
#define MUIV_Window_AltHeight_Scaled -1000
#define MUIV_Window_AltLeftEdge_Centered -1
#define MUIV_Window_AltLeftEdge_Moused -2
#define MUIV_Window_AltLeftEdge_NoChange -1000
#define MUIV_Window_AltTopEdge_Centered -1
#define MUIV_Window_AltTopEdge_Moused -2
#define MUIV_Window_AltTopEdge_Delta(p) (-3-(p))
#define MUIV_Window_AltTopEdge_NoChange -1000
#define MUIV_Window_AltWidth_MinMax(p) (0-(p))
#define MUIV_Window_AltWidth_Visible(p) (-100-(p))
#define MUIV_Window_AltWidth_Screen(p) (-200-(p))
#define MUIV_Window_AltWidth_Scaled -1000
#define MUIV_Window_Height_MinMax(p) (0-(p))
#define MUIV_Window_Height_Visible(p) (-100-(p))
#define MUIV_Window_Height_Screen(p) (-200-(p))
#define MUIV_Window_Height_Scaled -1000
#define MUIV_Window_Height_Default -1001
#define MUIV_Window_LeftEdge_Centered -1
#define MUIV_Window_LeftEdge_Moused -2
#define MUIV_Window_LeftEdge_Right(n) (-1000-(n))
#ifdef MUI_OBSOLETE
#define MUIV_Window_Menu_NoMenu -1
#endif /* MUI_OBSOLETE */
#define MUIV_Window_TopEdge_Centered -1
#define MUIV_Window_TopEdge_Moused -2
#define MUIV_Window_TopEdge_Delta(p) (-3-(p))
#define MUIV_Window_TopEdge_Bottom(n) (-1000-(n))
#define MUIV_Window_Width_MinMax(p) (0-(p))
#define MUIV_Window_Width_Visible(p) (-100-(p))
#define MUIV_Window_Width_Screen(p) (-200-(p))
#define MUIV_Window_Width_Scaled -1000
#define MUIV_Window_Width_Default -1001


/****************************************************************************/
/** Aboutmui                                                               **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Aboutmui[];
#else
#define MUIC_Aboutmui "Aboutmui.mui"
#endif

/* Attributes */

#define MUIA_Aboutmui_Application           0x80422523 /* V11 i.. Object *          */



/****************************************************************************/
/** Area                                                                   **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Area[];
#else
#define MUIC_Area "Area.mui"
#endif

/* Methods */

#define MUIM_AskMinMax                      0x80423874 /* Custom Class */ /* V4  */
#define MUIM_Cleanup                        0x8042d985 /* Custom Class */ /* V4  */
#define MUIM_ContextMenuAdd                 0x8042df9e /* V20 */
#define MUIM_ContextMenuBuild               0x80429d2e /* V11 */
#define MUIM_ContextMenuChoice              0x80420f0e /* V11 */
#define MUIM_CreateBubble                   0x80421c41 /* V18 */
#define MUIM_CreateDragImage                0x8042eb6f /* Custom Class */ /* V18 */
#define MUIM_CreateShortHelp                0x80428e93 /* V11 */
#define MUIM_DeleteBubble                   0x804211af /* V18 */
#define MUIM_DeleteDragImage                0x80423037 /* Custom Class */ /* V18 */
#define MUIM_DeleteShortHelp                0x8042d35a /* V11 */
#define MUIM_DoDrag                         0x804216bb /* V20 */
#define MUIM_DragBegin                      0x8042c03a /* V11 */
#define MUIM_DragDrop                       0x8042c555 /* V11 */
#define MUIM_DragEvent                      0x8042b774 /* Custom Class */ /* V20 */
#define MUIM_DragFinish                     0x804251f0 /* V11 */
#define MUIM_DragQuery                      0x80420261 /* V11 */
#define MUIM_DragReport                     0x8042edad /* V11 */
#define MUIM_Draw                           0x80426f3f /* Custom Class */ /* V4  */
#define MUIM_DrawBackground                 0x804238ca /* V11 */
#define MUIM_DrawBackgroundParent           0x804240e7 /* V20 */
#define MUIM_GoActive                       0x8042491a /* Custom Class */ /* V8  */
#define MUIM_GoInactive                     0x80422c0c /* Custom Class */ /* V8  */
#define MUIM_HandleEvent                    0x80426d66 /* Custom Class */ /* V16 */
#define MUIM_HandleInput                    0x80422a1a /* Custom Class */ /* V4  */
#define MUIM_Hide                           0x8042f20f /* Custom Class */ /* V4  */
#define MUIM_Layout                         0x8042845b /* V4  */
#define MUIM_Relayout                       0x8042b381 /* V22 */
#define MUIM_Setup                          0x80428354 /* Custom Class */ /* V4  */
#define MUIM_Show                           0x8042cc84 /* Custom Class */ /* V4  */
#define MUIM_Text                           0x8042ee70 /* V20 */
#define MUIM_TextDim                        0x80422ad7 /* V20 */
#define MUIM_UpdateConfig                   0x8042b0a9 /* V20 */
#define MUIM_WhichPointerType               0x8042e212 /* V20 */
struct  MUIP_AskMinMax                      { ULONG MethodID; struct MUI_MinMax *MinMaxInfo; }; /* Custom Class */
struct  MUIP_Cleanup                        { ULONG MethodID; }; /* Custom Class */
struct  MUIP_ContextMenuAdd                 { ULONG MethodID; Object *menustrip; LONG mx; LONG my; LONG *mxp; LONG *myp; };
struct  MUIP_ContextMenuBuild               { ULONG MethodID; LONG mx; LONG my; };
struct  MUIP_ContextMenuChoice              { ULONG MethodID; Object *item; };
struct  MUIP_CreateBubble                   { ULONG MethodID; LONG x; LONG y; CONST_STRPTR txt; ULONG flags; };
struct  MUIP_CreateDragImage                { ULONG MethodID; LONG touchx; LONG touchy; ULONG flags; }; /* Custom Class */
struct  MUIP_CreateShortHelp                { ULONG MethodID; LONG mx; LONG my; };
struct  MUIP_DeleteBubble                   { ULONG MethodID; APTR bubble; };
struct  MUIP_DeleteDragImage                { ULONG MethodID; struct MUI_DragImage *di; }; /* Custom Class */
struct  MUIP_DeleteShortHelp                { ULONG MethodID; STRPTR help; };
struct  MUIP_DoDrag                         { ULONG MethodID; LONG touchx; LONG touchy; ULONG flags; };
struct  MUIP_DragBegin                      { ULONG MethodID; Object *obj; };
struct  MUIP_DragDrop                       { ULONG MethodID; Object *obj; LONG x; LONG y; ULONG qualifier; };
struct  MUIP_DragEvent                      { ULONG MethodID; struct Window *objwindow; Object *obj; struct MUI_DragImage *di; struct IntuiMessage *imsg; LONG muikey; ULONG mouseptrtype; ULONG flags; }; /* Custom Class */
struct  MUIP_DragFinish                     { ULONG MethodID; Object *obj; LONG dropfollows; };
struct  MUIP_DragQuery                      { ULONG MethodID; Object *obj; };
struct  MUIP_DragReport                     { ULONG MethodID; Object *obj; LONG x; LONG y; LONG update; ULONG qualifier; };
struct  MUIP_Draw                           { ULONG MethodID; ULONG flags; }; /* Custom Class */
struct  MUIP_DrawBackground                 { ULONG MethodID; LONG left; LONG top; LONG width; LONG height; LONG xoffset; LONG yoffset; LONG flags; };
struct  MUIP_DrawBackgroundParent           { ULONG MethodID; LONG left; LONG top; LONG width; LONG height; LONG brightness; LONG xoffset; LONG yoffset; LONG flags; };
struct  MUIP_GoActive                       { ULONG MethodID; ULONG flags; }; /* Custom Class */
struct  MUIP_GoInactive                     { ULONG MethodID; ULONG flags; }; /* Custom Class */
struct  MUIP_HandleEvent                    { ULONG MethodID; struct IntuiMessage *imsg; LONG muikey; struct MUI_EventHandlerNode *ehn; }; /* Custom Class */
struct  MUIP_HandleInput                    { ULONG MethodID; struct IntuiMessage *imsg; LONG muikey; }; /* Custom Class */
struct  MUIP_Hide                           { ULONG MethodID; }; /* Custom Class */
struct  MUIP_Layout                         { ULONG MethodID; LONG left; LONG top; LONG width; LONG height; ULONG flags; };
struct  MUIP_Relayout                       { ULONG MethodID; ULONG flags; };
struct  MUIP_Setup                          { ULONG MethodID; struct MUI_RenderInfo *RenderInfo; }; /* Custom Class */
struct  MUIP_Show                           { ULONG MethodID; struct LongRect *clip; }; /* Custom Class */
struct  MUIP_Text                           { ULONG MethodID; LONG left; LONG top; LONG width; LONG height; CONST_STRPTR text; LONG len; CONST_STRPTR preparse; LONG ulchar; };
struct  MUIP_TextDim                        { ULONG MethodID; CONST_STRPTR text; LONG len; CONST_STRPTR preparse; ULONG flags; };
struct  MUIP_UpdateConfig                   { ULONG MethodID; ULONG cfgid; LONG redrawcount; Object *redrawobj[64]; UBYTE redrawflags[64]; };
struct  MUIP_WhichPointerType               { ULONG MethodID; LONG mx; LONG my; };

/* Attributes */

#define MUIA_Background                     0x8042545b /* V4  is. LONG              */
#define MUIA_BottomEdge                     0x8042e552 /* V4  ..g LONG              */
#define MUIA_ContextMenu                    0x8042b704 /* V11 isg Object *          */
#define MUIA_ContextMenuHook                0x80427c6e /* V20 isg struct Hook *     */
#define MUIA_ContextMenuTrigger             0x8042a2c1 /* V11 ..g Object *          */
#define MUIA_ControlChar                    0x8042120b /* V4  isg char              */
#define MUIA_CycleChain                     0x80421ce7 /* V11 isg LONG              */
#define MUIA_Disabled                       0x80423661 /* V4  isg BOOL              */
#define MUIA_DoubleBuffer                   0x8042a9c7 /* V20 isg BOOL              */
#define MUIA_DoubleClick                    0x8042f057 /* V20 ..g BOOL              */
#define MUIA_Draggable                      0x80420b6e /* V11 isg BOOL              */
#define MUIA_Dropable                       0x8042fbce /* V11 isg BOOL              */
#ifdef MUI_OBSOLETE
#define MUIA_ExportID                       0x8042d76e /* V4  isg ULONG             */
#endif /* MUI_OBSOLETE */
#define MUIA_FillArea                       0x804294a3 /* V4  is. BOOL              */
#define MUIA_FixHeight                      0x8042a92b /* V4  i.. LONG              */
#define MUIA_FixHeightTxt                   0x804276f2 /* V4  i.. STRPTR            */
#define MUIA_FixWidth                       0x8042a3f1 /* V4  i.. LONG              */
#define MUIA_FixWidthTxt                    0x8042d044 /* V4  i.. STRPTR            */
#define MUIA_Floating                       0x80429753 /* V20 isg BOOL              */
#define MUIA_Font                           0x8042be50 /* V4  i.g struct TextFont * */
#define MUIA_Frame                          0x8042ac64 /* V4  i.. LONG              */
#define MUIA_FrameDynamic                   0x804223c9 /* V20 isg BOOL              */
#define MUIA_FramePhantomHoriz              0x8042ed76 /* V4  i.. BOOL              */
#define MUIA_FrameTitle                     0x8042d1c7 /* V4  isg STRPTR            */
#define MUIA_FrameVisible                   0x80426498 /* V20 isg BOOL              */
#define MUIA_Height                         0x80423237 /* V4  ..g LONG              */
#define MUIA_HorizDisappear                 0x80429615 /* V11 isg LONG              */
#define MUIA_HorizWeight                    0x80426db9 /* V4  isg WORD              */
#define MUIA_InnerBottom                    0x8042f2c0 /* V4  i.g LONG              */
#define MUIA_InnerLeft                      0x804228f8 /* V4  i.g LONG              */
#define MUIA_InnerRight                     0x804297ff /* V4  i.g LONG              */
#define MUIA_InnerTop                       0x80421eb6 /* V4  i.g LONG              */
#define MUIA_InputMode                      0x8042fb04 /* V4  i.. LONG              */
#define MUIA_KnowsDisabled                  0x8042deef /* V20 isg BOOL              */
#define MUIA_LeftEdge                       0x8042bec6 /* V4  ..g LONG              */
#define MUIA_MaxHeight                      0x804293e4 /* V11 i.. LONG              */
#define MUIA_MaxWidth                       0x8042f112 /* V11 i.. LONG              */
#define MUIA_MinHeight                      0x8042c04a /* V20 i.. LONG              */
#define MUIA_MinWidth                       0x80424342 /* V20 i.. LONG              */
#define MUIA_PointerType                    0x8042b467 /* V20 isg LONG              */
#define MUIA_Pressed                        0x80423535 /* V4  ..g BOOL              */
#define MUIA_RightEdge                      0x8042ba82 /* V4  ..g LONG              */
#define MUIA_Selected                       0x8042654b /* V4  isg BOOL              */
#define MUIA_ShortHelp                      0x80428fe3 /* V11 isg STRPTR            */
#define MUIA_ShowMe                         0x80429ba8 /* V4  isg BOOL              */
#define MUIA_ShowSelState                   0x8042caac /* V4  i.. BOOL              */
#define MUIA_TextColor                      0x8042dba6 /* V22 is. struct PenSpec *  */
#define MUIA_Timer                          0x80426435 /* V4  ..g LONG              */
#define MUIA_TopEdge                        0x8042509b /* V4  ..g LONG              */
#define MUIA_VertDisappear                  0x8042d12f /* V11 isg LONG              */
#define MUIA_VertWeight                     0x804298d0 /* V4  isg WORD              */
#define MUIA_Weight                         0x80421d1f /* V4  i.. WORD              */
#define MUIA_Width                          0x8042b59c /* V4  ..g LONG              */
#define MUIA_Window                         0x80421591 /* V4  ..g struct Window *   */
#define MUIA_WindowObject                   0x8042669e /* V4  ..g Object *          */

#define MUIV_Font_Inherit 0
#define MUIV_Font_Normal -1
#define MUIV_Font_List -2
#define MUIV_Font_Tiny -3
#define MUIV_Font_Fixed -4
#define MUIV_Font_Title -5
#define MUIV_Font_Big -6
#define MUIV_Font_Button -7
#define MUIV_Font_Slider -8
#define MUIV_Font_Gauge -9
#define MUIV_Font_Menu -10
#define MUIV_Font_Tab -11
#define MUIV_Font_Bubble -12
#define MUIV_Font_Huge -13
#define MUIV_Font_Last -13
#define MUIV_Font_Count 14
#define MUIV_Frame_None 0
#define MUIV_Frame_Button 1
#define MUIV_Frame_ImageButton 2
#define MUIV_Frame_Text 3
#define MUIV_Frame_String 4
#define MUIV_Frame_ReadList 5
#define MUIV_Frame_InputList 6
#define MUIV_Frame_Prop 7
#define MUIV_Frame_Gauge 8
#define MUIV_Frame_Group 9
#define MUIV_Frame_PopUp 10
#define MUIV_Frame_Virtual 11
#define MUIV_Frame_Slider 12
#define MUIV_Frame_SliderKnob 13
#define MUIV_Frame_GaugeInner 14
#define MUIV_Frame_Menudisplay 15
#define MUIV_Frame_MenudisplayMenu 16
#define MUIV_Frame_PropKnob 17
#define MUIV_Frame_Window 18
#define MUIV_Frame_Requester 19
#define MUIV_Frame_Page 20
#define MUIV_Frame_Register 21
#define MUIV_Frame_GroupTitle 22
#define MUIV_Frame_RegisterTitle 23
#define MUIV_Frame_Count 24
#define MUIV_InputMode_None 0
#define MUIV_InputMode_RelVerify 1
#define MUIV_InputMode_Immediate 2
#define MUIV_InputMode_Toggle 3
#define MUIV_PointerType_Parent -1
#define MUIV_PointerType_Normal 0
#define MUIV_PointerType_Busy 1
#define MUIV_PointerType_Alias 2
#define MUIV_PointerType_Cell 3
#define MUIV_PointerType_ColumnResize 4
#define MUIV_PointerType_ContextMenu 5
#define MUIV_PointerType_Copy 6
#define MUIV_PointerType_Cross 7
#define MUIV_PointerType_DragAndDrop 8
#define MUIV_PointerType_EastResize 9
#define MUIV_PointerType_EastWestResize 10
#define MUIV_PointerType_Hand 11
#define MUIV_PointerType_Help 12
#define MUIV_PointerType_Link 13
#define MUIV_PointerType_Menu 14
#define MUIV_PointerType_NoDrop 15
#define MUIV_PointerType_None 16
#define MUIV_PointerType_NorthEastResize 17
#define MUIV_PointerType_NorthEastSouthWestResize 18
#define MUIV_PointerType_NorthResize 19
#define MUIV_PointerType_NorthSouthResize 20
#define MUIV_PointerType_NorthWestResize 21
#define MUIV_PointerType_NorthWestSouthEastResize 22
#define MUIV_PointerType_NotAllowed 23
#define MUIV_PointerType_Progress 24
#define MUIV_PointerType_RowResize 25
#define MUIV_PointerType_ScrollAll 26
#define MUIV_PointerType_SouthEastResize 27
#define MUIV_PointerType_SouthResize 28
#define MUIV_PointerType_SouthWestResize 29
#define MUIV_PointerType_Text 30
#define MUIV_PointerType_VerticalText 31
#define MUIV_PointerType_WestResize 32
#define MUIV_PointerType_ZoomIn 33
#define MUIV_PointerType_ZoomOut 34
#define MUIV_PointerType_Pen 35
#define MUIV_PointerType_Rotate 36
#define MUIV_PointerType_Rotation 36 /* deprecated definition for compatibility */
#define MUIV_PointerType_Rubber 37
#define MUIV_PointerType_Select 38
#define MUIV_PointerType_Smudge 39
#define MUIV_PointerType_Count 40


/****************************************************************************/
/** Dtpic                                                                  **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Dtpic[];
#else
#define MUIC_Dtpic "Dtpic.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Dtpic_Alpha                    0x8042b4db /* V20 isg LONG              */
#define MUIA_Dtpic_DarkenSelState           0x80423247 /* V20 i.g BOOL              */
#define MUIA_Dtpic_Fade                     0x80420429 /* V20 isg LONG              */
#define MUIA_Dtpic_LightenOnMouse           0x8042966a /* V20 i.g BOOL              */
#define MUIA_Dtpic_Name                     0x80423d72 /* V18 isg STRPTR            */



/****************************************************************************/
/** Rectangle                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Rectangle[];
#else
#define MUIC_Rectangle "Rectangle.mui"
#endif

/* Attributes */

#define MUIA_Rectangle_BarTitle             0x80426689 /* V11 i.g STRPTR            */
#define MUIA_Rectangle_HBar                 0x8042c943 /* V7  i.g BOOL              */
#define MUIA_Rectangle_VBar                 0x80422204 /* V7  i.g BOOL              */



/****************************************************************************/
/** Balance                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Balance[];
#else
#define MUIC_Balance "Balance.mui"
#endif

/* Attributes */

#define MUIA_Balance_Quiet                  0x80427486 /* V20 i.. LONG              */



/****************************************************************************/
/** Image                                                                  **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Image[];
#else
#define MUIC_Image "Image.mui"
#endif

/* Attributes */

#define MUIA_Image_BuiltinSpec              0x8042b907 /* V21 i.. ULONG             */
#define MUIA_Image_CopySpec                 0x8042a784 /* V20 i.. BOOL              */
#define MUIA_Image_FontMatch                0x8042815d /* V4  is. BOOL              */
#define MUIA_Image_FontMatchHeight          0x80429f26 /* V4  is. BOOL              */
#define MUIA_Image_FontMatchString          0x804263c1 /* V20 is. CONST_STRPTR      */
#define MUIA_Image_FontMatchWidth           0x804239bf /* V4  is. BOOL              */
#define MUIA_Image_FreeHoriz                0x8042da84 /* V4  is. BOOL              */
#define MUIA_Image_FreeVert                 0x8042ea28 /* V4  is. BOOL              */
#define MUIA_Image_OldImage                 0x80424f3d /* V4  i.. struct Image *    */
#define MUIA_Image_Spec                     0x804233d5 /* V4  is. STRPTR            */
#define MUIA_Image_State                    0x8042a3ad /* V4  is. LONG              */



/****************************************************************************/
/** Menubar                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Menubar[];
#else
#define MUIC_Menubar "Menubar.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Bitmap                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Bitmap[];
#else
#define MUIC_Bitmap "Bitmap.mui"
#endif

/* Attributes */

#define MUIA_Bitmap_Alpha                   0x80423e71 /* V20 isg ULONG             */
#define MUIA_Bitmap_Bitmap                  0x804279bd /* V8  isg struct BitMap *   */
#define MUIA_Bitmap_Height                  0x80421560 /* V8  isg LONG              */
#define MUIA_Bitmap_MappingTable            0x8042e23d /* V8  isg UBYTE *           */
#define MUIA_Bitmap_Precision               0x80420c74 /* V11 isg LONG              */
#define MUIA_Bitmap_RemappedBitmap          0x80423a47 /* V11 ..g struct BitMap *   */
#define MUIA_Bitmap_SourceColors            0x80425360 /* V8  isg ULONG *           */
#define MUIA_Bitmap_Transparent             0x80422805 /* V8  isg LONG              */
#define MUIA_Bitmap_UseFriend               0x804239d8 /* V11 i.. BOOL              */
#define MUIA_Bitmap_Width                   0x8042eb3a /* V8  isg LONG              */



/****************************************************************************/
/** Bodychunk                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Bodychunk[];
#else
#define MUIC_Bodychunk "Bodychunk.mui"
#endif

/* Attributes */

#define MUIA_Bodychunk_Body                 0x8042ca67 /* V8  isg UBYTE *           */
#define MUIA_Bodychunk_Compression          0x8042de5f /* V8  isg UBYTE             */
#define MUIA_Bodychunk_Depth                0x8042c392 /* V8  isg LONG              */
#define MUIA_Bodychunk_Masking              0x80423b0e /* V8  isg UBYTE             */



/****************************************************************************/
/** Text                                                                   **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Text[];
#else
#define MUIC_Text "Text.mui"
#endif

/* Attributes */

#define MUIA_Text_Contents                  0x8042f8dc /* V4  isg STRPTR            */
#define MUIA_Text_ControlChar               0x8042e6d0 /* V20 isg char              */
#define MUIA_Text_Copy                      0x80427727 /* V20 isg BOOL              */
#define MUIA_Text_Data                      0x80424838 /* V21 isg Object *          */
#define MUIA_Text_HiChar                    0x804218ff /* V4  i.. char              */
#define MUIA_Text_Marking                   0x8042f780 /* V20 i.g BOOL              */
#define MUIA_Text_PreParse                  0x8042566d /* V4  isg STRPTR            */
#define MUIA_Text_SetMax                    0x80424d0a /* V4  i.. BOOL              */
#define MUIA_Text_SetMin                    0x80424e10 /* V4  i.. BOOL              */
#define MUIA_Text_SetVMax                   0x80420d8b /* V11 is. BOOL              */
#define MUIA_Text_Shorten                   0x80428bbd /* V20 isg LONG              */
#define MUIA_Text_Shortened                 0x80425a86 /* V20 ..g BOOL              */

#define MUIV_Text_Shorten_Nothing 0
#define MUIV_Text_Shorten_Cutoff 1
#define MUIV_Text_Shorten_Hide 2
#define MUIV_Text_Shorten_ElideLeft 3
#define MUIV_Text_Shorten_ElideCenter 4
#define MUIV_Text_Shorten_ElideRight 5


/****************************************************************************/
/** Gadget                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Gadget[];
#else
#define MUIC_Gadget "Gadget.mui"
#endif

/* Attributes */

#define MUIA_Gadget_Gadget                  0x8042ec1a /* V11 ..g struct Gadget *   */



/****************************************************************************/
/** String                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_String[];
#else
#define MUIC_String "String.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_String_Accept                  0x8042e3e1 /* V4  isg STRPTR            */
#define MUIA_String_Acknowledge             0x8042026c /* V4  ..g STRPTR            */
#define MUIA_String_AdvanceOnCR             0x804226de /* V11 isg BOOL              */
#define MUIA_String_AttachedList            0x80420fd2 /* V4  isg Object *          */
#define MUIA_String_BufferPos               0x80428b6c /* V4  .sg LONG              */
#define MUIA_String_Contents                0x80428ffd /* V4  isg STRPTR            */
#define MUIA_String_DisplayPos              0x8042ccbf /* V4  .sg LONG              */
#define MUIA_String_EditHook                0x80424c33 /* V7  isg struct Hook *     */
#define MUIA_String_Format                  0x80427484 /* V4  i.g LONG              */
#define MUIA_String_InactiveContents        0x80427ecf /* V20 isg CONST_STRPTR      */
#define MUIA_String_Integer                 0x80426e8a /* V4  isg ULONG             */
#define MUIA_String_Integer64               0x80424820 /* V20 isg int64 *           */
#define MUIA_String_LonelyEditHook          0x80421569 /* V11 isg BOOL              */
#define MUIA_String_MaxLen                  0x80424984 /* V4  i.g LONG              */
#define MUIA_String_Placeholder             0x8042ae65 /* V21 isg CONST_STRPTR      */
#define MUIA_String_Reject                  0x8042179c /* V4  isg STRPTR            */
#define MUIA_String_Secret                  0x80428769 /* V4  i.g BOOL              */

#define MUIV_String_Format_Left 0
#define MUIV_String_Format_Center 1
#define MUIV_String_Format_Right 2


/****************************************************************************/
/** Boopsi                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Boopsi[];
#else
#define MUIC_Boopsi "Boopsi.mui"
#endif

/* Attributes */

#define MUIA_Boopsi_Class                   0x80426999 /* V4  isg struct IClass *   */
#define MUIA_Boopsi_ClassID                 0x8042bfa3 /* V4  isg STRPTR            */
#define MUIA_Boopsi_MaxHeight               0x8042757f /* V4  isg ULONG             */
#define MUIA_Boopsi_MaxWidth                0x8042bcb1 /* V4  isg ULONG             */
#define MUIA_Boopsi_MinHeight               0x80422c93 /* V4  isg ULONG             */
#define MUIA_Boopsi_MinWidth                0x80428fb2 /* V4  isg ULONG             */
#define MUIA_Boopsi_Object                  0x80420178 /* V4  ..g Object *          */
#define MUIA_Boopsi_Remember                0x8042f4bd /* V4  i.. ULONG             */
#define MUIA_Boopsi_Smart                   0x8042b8d7 /* V9  i.. BOOL              */
#define MUIA_Boopsi_TagDrawInfo             0x8042bae7 /* V4  isg ULONG             */
#define MUIA_Boopsi_TagScreen               0x8042bc71 /* V4  isg ULONG             */
#define MUIA_Boopsi_TagWindow               0x8042e11d /* V4  isg ULONG             */



/****************************************************************************/
/** Prop                                                                   **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Prop[];
#else
#define MUIC_Prop "Prop.mui"
#endif

/* Methods */

#define MUIM_Prop_Decrease                  0x80420dd1 /* V16 */
#define MUIM_Prop_Increase                  0x8042cac0 /* V16 */
struct  MUIP_Prop_Decrease                  { ULONG MethodID; LONG amount; };
struct  MUIP_Prop_Increase                  { ULONG MethodID; LONG amount; };

/* Attributes */

#define MUIA_Prop_DeltaFactor               0x80427c5e /* V4  isg LONG              */
#define MUIA_Prop_Entries                   0x8042fbdb /* V4  isg LONG              */
#define MUIA_Prop_First                     0x8042d4b2 /* V4  isg LONG              */
#define MUIA_Prop_Horiz                     0x8042f4f3 /* V4  i.g BOOL              */
#ifdef MUI_OBSOLETE
#define MUIA_Prop_Slider                    0x80429c3a /* V4  isg BOOL              */
#endif /* MUI_OBSOLETE */
#define MUIA_Prop_UseWinBorder              0x8042deee /* V13 i.. LONG              */
#define MUIA_Prop_Visible                   0x8042fea6 /* V4  isg LONG              */

#define MUIV_Prop_UseWinBorder_None 0
#define MUIV_Prop_UseWinBorder_Left 1
#define MUIV_Prop_UseWinBorder_Right 2
#define MUIV_Prop_UseWinBorder_Bottom 3


/****************************************************************************/
/** Gauge                                                                  **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Gauge[];
#else
#define MUIC_Gauge "Gauge.mui"
#endif

/* Attributes */

#define MUIA_Gauge_Current                  0x8042f0dd /* V4  isg LONG              */
#define MUIA_Gauge_Divide                   0x8042d8df /* V4  isg ULONG             */
#define MUIA_Gauge_Horiz                    0x804232dd /* V4  i.. BOOL              */
#define MUIA_Gauge_InfoRate                 0x804253c8 /* V4  isg LONG              */
#define MUIA_Gauge_InfoText                 0x8042bf15 /* V7  isg STRPTR            */
#define MUIA_Gauge_Max                      0x8042bcdb /* V4  isg LONG              */



/****************************************************************************/
/** Scale                                                                  **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Scale[];
#else
#define MUIC_Scale "Scale.mui"
#endif

/* Attributes */

#define MUIA_Scale_Horiz                    0x8042919a /* V4  isg BOOL              */



/****************************************************************************/
/** Colorfield                                                             **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Colorfield[];
#else
#define MUIC_Colorfield "Colorfield.mui"
#endif

/* Attributes */

#define MUIA_Colorfield_Blue                0x8042d3b0 /* V4  isg ULONG             */
#define MUIA_Colorfield_Green               0x80424466 /* V4  isg ULONG             */
#define MUIA_Colorfield_Pen                 0x8042713a /* V4  ..g ULONG             */
#define MUIA_Colorfield_Red                 0x804279f6 /* V4  isg ULONG             */
#define MUIA_Colorfield_RGB                 0x8042677a /* V4  isg ULONG *           */



/****************************************************************************/
/** Numeric                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Numeric[];
#else
#define MUIC_Numeric "Numeric.mui"
#endif

/* Methods */

#define MUIM_Numeric_Decrease               0x804243a7 /* V11 */
#define MUIM_Numeric_Increase               0x80426ecd /* V11 */
#define MUIM_Numeric_ScaleToValue           0x8042032c /* V11 */
#define MUIM_Numeric_SetDefault             0x8042ab0a /* V11 */
#define MUIM_Numeric_Stringify              0x80424891 /* V11 */
#define MUIM_Numeric_ValueToScale           0x80423e4f /* V11 */
struct  MUIP_Numeric_Decrease               { ULONG MethodID; LONG amount; };
struct  MUIP_Numeric_Increase               { ULONG MethodID; LONG amount; };
struct  MUIP_Numeric_ScaleToValue           { ULONG MethodID; LONG scalemin; LONG scalemax; LONG scale; };
struct  MUIP_Numeric_SetDefault             { ULONG MethodID; };
struct  MUIP_Numeric_Stringify              { ULONG MethodID; LONG value; };
struct  MUIP_Numeric_ValueToScale           { ULONG MethodID; LONG scalemin; LONG scalemax; };

/* Attributes */

#define MUIA_Numeric_CheckAllSizes          0x80421594 /* V11 isg BOOL              */
#define MUIA_Numeric_Default                0x804263e8 /* V11 isg LONG              */
#define MUIA_Numeric_Format                 0x804263e9 /* V11 isg STRPTR            */
#define MUIA_Numeric_Max                    0x8042d78a /* V11 isg LONG              */
#define MUIA_Numeric_Min                    0x8042e404 /* V11 isg LONG              */
#define MUIA_Numeric_Reverse                0x8042f2a0 /* V11 isg BOOL              */
#define MUIA_Numeric_RevLeftRight           0x804294a7 /* V11 isg BOOL              */
#define MUIA_Numeric_RevUpDown              0x804252dd /* V11 isg BOOL              */
#define MUIA_Numeric_Value                  0x8042ae3a /* V11 isg LONG              */



/****************************************************************************/
/** Knob                                                                   **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Knob[];
#else
#define MUIC_Knob "Knob.mui"
#endif


/****************************************************************************/
/** Levelmeter                                                             **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Levelmeter[];
#else
#define MUIC_Levelmeter "Levelmeter.mui"
#endif

/* Attributes */

#define MUIA_Levelmeter_Label               0x80420dd5 /* V11 isg STRPTR            */



/****************************************************************************/
/** Numericbutton                                                          **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Numericbutton[];
#else
#define MUIC_Numericbutton "Numericbutton.mui"
#endif


/****************************************************************************/
/** Slider                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Slider[];
#else
#define MUIC_Slider "Slider.mui"
#endif

/* Attributes */

#define MUIA_Slider_Horiz                   0x8042fad1 /* V11 isg BOOL              */
#ifdef MUI_OBSOLETE
#define MUIA_Slider_Level                   0x8042ae3a /* V4  isg LONG              */
#endif /* MUI_OBSOLETE */
#ifdef MUI_OBSOLETE
#define MUIA_Slider_Max                     0x8042d78a /* V4  isg LONG              */
#endif /* MUI_OBSOLETE */
#ifdef MUI_OBSOLETE
#define MUIA_Slider_Min                     0x8042e404 /* V4  isg LONG              */
#endif /* MUI_OBSOLETE */
#define MUIA_Slider_Quiet                   0x80420b26 /* V6  i.. BOOL              */
#ifdef MUI_OBSOLETE
#define MUIA_Slider_Reverse                 0x8042f2a0 /* V4  isg BOOL              */
#endif /* MUI_OBSOLETE */



/****************************************************************************/
/** Framedisplay                                                           **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Framedisplay[];
#else
#define MUIC_Framedisplay "Framedisplay.mui"
#endif

/* Attributes */




/****************************************************************************/
/** Imagedisplay                                                           **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Imagedisplay[];
#else
#define MUIC_Imagedisplay "Imagedisplay.mui"
#endif

/* Attributes */




/****************************************************************************/
/** Frimagedisplay                                                         **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Frimagedisplay[];
#else
#define MUIC_Frimagedisplay "Frimagedisplay.mui"
#endif

/* Attributes */




/****************************************************************************/
/** Popimage                                                               **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Popimage[];
#else
#define MUIC_Popimage "Popimage.mui"
#endif


/****************************************************************************/
/** Popframe                                                               **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Popframe[];
#else
#define MUIC_Popframe "Popframe.mui"
#endif


/****************************************************************************/
/** Popfrimage                                                             **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Popfrimage[];
#else
#define MUIC_Popfrimage "Popfrimage.mui"
#endif


/****************************************************************************/
/** Pendisplay                                                             **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Pendisplay[];
#else
#define MUIC_Pendisplay "Pendisplay.mui"
#endif

/* Methods */

#define MUIM_Pendisplay_SetColormap         0x80426c80 /* V13 */
#define MUIM_Pendisplay_SetMUIPen           0x8042039d /* V13 */
#define MUIM_Pendisplay_SetRGB              0x8042c131 /* V13 */
struct  MUIP_Pendisplay_SetColormap         { ULONG MethodID; LONG colormap; };
struct  MUIP_Pendisplay_SetMUIPen           { ULONG MethodID; LONG muipen; };
struct  MUIP_Pendisplay_SetRGB              { ULONG MethodID; ULONG red; ULONG green; ULONG blue; };

/* Attributes */

#define MUIA_Pendisplay_Pen                 0x8042a748 /* V13 ..g ULONG             */
#define MUIA_Pendisplay_Reference           0x8042dc24 /* V13 isg Object *          */
#define MUIA_Pendisplay_RGBcolor            0x8042a1a9 /* V11 isg struct MUI_RGBcolor * */
#define MUIA_Pendisplay_Spec                0x8042a204 /* V11 isg struct MUI_PenSpec  * */



/****************************************************************************/
/** Poppen                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Poppen[];
#else
#define MUIC_Poppen "Poppen.mui"
#endif


/****************************************************************************/
/** Fontdisplay                                                            **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Fontdisplay[];
#else
#define MUIC_Fontdisplay "Fontdisplay.mui"
#endif

/* Attributes */




/****************************************************************************/
/** Group                                                                  **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Group[];
#else
#define MUIC_Group "Group.mui"
#endif

/* Methods */

#define MUIM_Group_AddHead                  0x8042e200 /* V8  */
#define MUIM_Group_AddTail                  0x8042d752 /* V8  */
#define MUIM_Group_ExitChange               0x8042d1cc /* V11 */
#define MUIM_Group_ExitChange2              0x8042e541 /* V12 */
#define MUIM_Group_InitChange               0x80420887 /* V11 */
#define MUIM_Group_MoveMember               0x8042ff4e /* V16 */
#define MUIM_Group_Remove                   0x8042f8a9 /* V8  */
#define MUIM_Group_Reorder                  0x80426c3f /* V21 */
#define MUIM_Group_Sort                     0x80427417 /* V4  */
struct  MUIP_Group_AddHead                  { ULONG MethodID; Object *obj; };
struct  MUIP_Group_AddTail                  { ULONG MethodID; Object *obj; };
struct  MUIP_Group_ExitChange               { ULONG MethodID; };
struct  MUIP_Group_ExitChange2              { ULONG MethodID; ULONG flags; };
struct  MUIP_Group_InitChange               { ULONG MethodID; };
struct  MUIP_Group_MoveMember               { ULONG MethodID; Object *o; LONG pos; };
struct  MUIP_Group_Remove                   { ULONG MethodID; Object *obj; };
struct  MUIP_Group_Reorder                  { ULONG MethodID; Object *after; Object *array[1]; };
struct  MUIP_Group_Sort                     { ULONG MethodID; Object *obj[1]; };

/* Attributes */

#define MUIA_Group_ActivePage               0x80424199 /* V5  isg LONG              */
#define MUIA_Group_Child                    0x804226e6 /* V4  i.. Object *          */
#define MUIA_Group_ChildCount               0x80420322 /* V20 ..g LONG              */
#define MUIA_Group_ChildList                0x80424748 /* V4  ..g struct List *     */
#define MUIA_Group_Columns                  0x8042f416 /* V4  is. LONG              */
#define MUIA_Group_Forward                  0x80421422 /* V11 .s. BOOL              */
#define MUIA_Group_ForwardDepth             0x80428488 /* V20 .s. ULONG             */
#define MUIA_Group_Horiz                    0x8042536b /* V4  i.. BOOL              */
#define MUIA_Group_HorizCenter              0x8042cc64 /* V20 isg LONG              */
#define MUIA_Group_HorizSpacing             0x8042c651 /* V4  isg LONG              */
#define MUIA_Group_LayoutHook               0x8042c3b2 /* V11 i.. struct Hook *     */
#define MUIA_Group_PageMode                 0x80421a5f /* V5  i.. BOOL              */
#define MUIA_Group_Rows                     0x8042b68f /* V4  is. LONG              */
#define MUIA_Group_SameHeight               0x8042037e /* V4  i.. BOOL              */
#define MUIA_Group_SameSize                 0x80420860 /* V4  i.. BOOL              */
#define MUIA_Group_SameWidth                0x8042b3ec /* V4  i.. BOOL              */
#define MUIA_Group_Spacing                  0x8042866d /* V4  is. LONG              */
#define MUIA_Group_VertCenter               0x8042c008 /* V20 isg LONG              */
#define MUIA_Group_VertSpacing              0x8042e1bf /* V4  isg LONG              */

#define MUIV_Group_ActivePage_First 0
#define MUIV_Group_ActivePage_Last -1
#define MUIV_Group_ActivePage_Prev -2
#define MUIV_Group_ActivePage_Next -3
#define MUIV_Group_ActivePage_Advance -4
#define MUIV_Group_HorizCenter_Left 0
#define MUIV_Group_HorizCenter_Center 1
#define MUIV_Group_HorizCenter_Right 2
#define MUIV_Group_Spacing_Default -100
#define MUIV_Group_Spacing_Percent(p) (-(p))
#define MUIV_Group_VertCenter_Top 0
#define MUIV_Group_VertCenter_Center 1
#define MUIV_Group_VertCenter_Bottom 2


/****************************************************************************/
/** List                                                                   **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_List[];
#else
#define MUIC_List "List.mui"
#endif

/* Methods */

#define MUIM_List_Clear                     0x8042ad89 /* V4  */
#define MUIM_List_Compare                   0x80421b68 /* V20 */
#define MUIM_List_Construct                 0x8042d662 /* V20 */
#define MUIM_List_CreateEditObject          0x804219ae /* V21 */
#define MUIM_List_CreateImage               0x80429804 /* V11 */
#define MUIM_List_DeleteImage               0x80420f58 /* V11 */
#define MUIM_List_Destruct                  0x80427d51 /* V20 */
#define MUIM_List_Display                   0x80425377 /* V20 */
#define MUIM_List_Edit                      0x8042843d /* V21 */
#define MUIM_List_EditDone                  0x80423ab3 /* V21 */
#define MUIM_List_Exchange                  0x8042468c /* V4  */
#define MUIM_List_GetEntry                  0x804280ec /* V4  */
#define MUIM_List_Insert                    0x80426c87 /* V4  */
#define MUIM_List_InsertSingle              0x804254d5 /* V7  */
#define MUIM_List_Jump                      0x8042baab /* V4  */
#define MUIM_List_Move                      0x804253c2 /* V9  */
#define MUIM_List_NextSelected              0x80425f17 /* V6  */
#define MUIM_List_QueryColumnWidth          0x8042e09e /* V11 */
#define MUIM_List_Redraw                    0x80427993 /* V4  */
#define MUIM_List_Remove                    0x8042647e /* V4  */
#define MUIM_List_Select                    0x804252d8 /* V4  */
#define MUIM_List_Sort                      0x80422275 /* V4  */
#define MUIM_List_TestPos                   0x80425f48 /* V11 */
struct  MUIP_List_Clear                     { ULONG MethodID; };
struct  MUIP_List_Compare                   { ULONG MethodID; APTR entry1; APTR entry2; LONG column; };
struct  MUIP_List_Construct                 { ULONG MethodID; APTR entry; APTR pool; };
struct  MUIP_List_CreateEditObject          { ULONG MethodID; LONG row; LONG column; APTR entry; };
struct  MUIP_List_CreateImage               { ULONG MethodID; Object *obj; ULONG flags; };
struct  MUIP_List_DeleteImage               { ULONG MethodID; APTR listimg; };
struct  MUIP_List_Destruct                  { ULONG MethodID; APTR entry; APTR pool; };
struct  MUIP_List_Display                   { ULONG MethodID; APTR entry; CONST_STRPTR *array; LONG row; };
struct  MUIP_List_Edit                      { ULONG MethodID; LONG row; LONG column; };
struct  MUIP_List_EditDone                  { ULONG MethodID; LONG row; LONG column; APTR entry; Object *editobj; };
struct  MUIP_List_Exchange                  { ULONG MethodID; LONG pos1; LONG pos2; };
struct  MUIP_List_GetEntry                  { ULONG MethodID; LONG pos; APTR *entry; };
struct  MUIP_List_Insert                    { ULONG MethodID; APTR *entries; LONG count; LONG pos; };
struct  MUIP_List_InsertSingle              { ULONG MethodID; APTR entry; LONG pos; };
struct  MUIP_List_Jump                      { ULONG MethodID; LONG pos; };
struct  MUIP_List_Move                      { ULONG MethodID; LONG from; LONG to; };
struct  MUIP_List_NextSelected              { ULONG MethodID; LONG *pos; };
struct  MUIP_List_QueryColumnWidth          { ULONG MethodID; LONG colnr; };
struct  MUIP_List_Redraw                    { ULONG MethodID; LONG pos; APTR entry; };
struct  MUIP_List_Remove                    { ULONG MethodID; LONG pos; };
struct  MUIP_List_Select                    { ULONG MethodID; LONG pos; LONG seltype; LONG *state; };
struct  MUIP_List_Sort                      { ULONG MethodID; };
struct  MUIP_List_TestPos                   { ULONG MethodID; LONG x; LONG y; struct MUI_List_TestPos_Result *res; };

/* Attributes */

#define MUIA_List_Active                    0x8042391c /* V4  isg LONG              */
#define MUIA_List_AdjustHeight              0x8042850d /* V4  i.. BOOL              */
#define MUIA_List_AdjustWidth               0x8042354a /* V4  i.. BOOL              */
#define MUIA_List_AgainClick                0x804214c2 /* V20 i.g BOOL              */
#define MUIA_List_AutoLineHeight            0x8042bc08 /* V20 i.. BOOL              */
#define MUIA_List_AutoVisible               0x8042a445 /* V11 isg BOOL              */
#define MUIA_List_ClickColumn               0x8042d1b3 /* V7  ..g LONG              */
#define MUIA_List_ColumnOrder               0x9d5100f6 /* V20 .sg BYTE *            */
#define MUIA_List_CompareHook               0x80425c14 /* V4  is. struct Hook *     */
#define MUIA_List_ConstructHook             0x8042894f /* V4  is. struct Hook *     */
#define MUIA_List_DefClickColumn            0x8042b296 /* V7  isg LONG              */
#define MUIA_List_DestructHook              0x804297ce /* V4  is. struct Hook *     */
#define MUIA_List_DisplayHook               0x8042b4d5 /* V4  is. struct Hook *     */
#define MUIA_List_DoubleClick               0x80424635 /* V4  i.g BOOL              */
#define MUIA_List_DragSortable              0x80426099 /* V11 isg BOOL              */
#define MUIA_List_DragType                  0x80425cd3 /* V11 isg LONG              */
#define MUIA_List_DropMark                  0x8042aba6 /* V11 ..g LONG              */
#define MUIA_List_Editable                  0x8042f9b9 /* V21 isg BOOL              */
#define MUIA_List_Entries                   0x80421654 /* V4  ..g LONG              */
#define MUIA_List_First                     0x804238d4 /* V4  .sg LONG              */
#define MUIA_List_Format                    0x80423c0a /* V4  isg CONST_STRPTR      */
#define MUIA_List_HideColumn                0x80428052 /* V21 is. LONG              */
#define MUIA_List_HScrollerVisibility       0x804280a6 /* V20 i.. LONG              */
#define MUIA_List_Input                     0x8042682d /* V4  i.. BOOL              */
#define MUIA_List_InsertPosition            0x8042d0cd /* V9  ..g LONG              */
#define MUIA_List_LineHeight                0x80425880 /* V20 .sg ULONG             */
#define MUIA_List_MaxColumns                0x8042a98b /* V21 i.. LONG              */
#define MUIA_List_MinLineHeight             0x8042d1c3 /* V4  is. LONG              */
#define MUIA_List_MultiSelect               0x80427e08 /* V7  i.. LONG              */
#define MUIA_List_MultiTestHook             0x8042c2c6 /* V4  is. struct Hook *     */
#define MUIA_List_Pool                      0x80423431 /* V13 i.g APTR              */
#define MUIA_List_PoolPuddleSize            0x8042a4eb /* V13 i.. ULONG             */
#define MUIA_List_PoolThreshSize            0x8042c48c /* V13 i.. ULONG             */
#define MUIA_List_Quiet                     0x8042d8c7 /* V4  .sg BOOL              */
#define MUIA_List_ScrollerPos               0x8042b1b4 /* V10 i.. LONG              */
#define MUIA_List_SelectChange              0x8042178f /* V4  ..g BOOL              */
#define MUIA_List_ShowColumn                0x8042c840 /* V21 is. LONG              */
#define MUIA_List_ShowDropMarks             0x8042c6f3 /* V11 isg BOOL              */
#define MUIA_List_SortColumn                0x8042cafb /* V21 isg LONG              */
#define MUIA_List_SourceArray               0x8042c0a0 /* V4  i.. APTR              */
#define MUIA_List_Stripes                   0x8042a308 /* V21 isg BOOL              */
#define MUIA_List_Title                     0x80423e66 /* V6  isg CONST_STRPTR      */
#define MUIA_List_TitleArray                0x80427d95 /* V21 isg CONST_STRPTR *    */
#define MUIA_List_TitleClick                0x80422fd9 /* V20 ..g LONG              */
#define MUIA_List_TopPixel                  0x80429df3 /* V4  ..g LONG              */
#define MUIA_List_TotalPixel                0x8042a8f5 /* V4  ..g LONG              */
#define MUIA_List_Visible                   0x8042191f /* V4  ..g LONG              */
#define MUIA_List_VisiblePixel              0x804273e9 /* V4  ..g LONG              */

#define MUIV_List_Active_Off -1
#define MUIV_List_Active_Top -2
#define MUIV_List_Active_Bottom -3
#define MUIV_List_Active_Up -4
#define MUIV_List_Active_Down -5
#define MUIV_List_Active_PageUp -6
#define MUIV_List_Active_PageDown -7
#define MUIV_List_CompareHook_String -1
#define MUIV_List_CompareHook_StringArray -2
#define MUIV_List_ConstructHook_String -1
#define MUIV_List_ConstructHook_StringArray -2
#define MUIV_List_DestructHook_String -1
#define MUIV_List_DestructHook_StringArray -2
#define MUIV_List_DisplayHook_String -1
#define MUIV_List_DisplayHook_StringArray -2
#define MUIV_List_DragType_None 0
#define MUIV_List_DragType_Immediate 1
#define MUIV_List_HScrollerVisibility_Always 1
#define MUIV_List_HScrollerVisibility_Never 2
#define MUIV_List_HScrollerVisibility_Auto 0
#define MUIV_List_MultiSelect_None 0
#define MUIV_List_MultiSelect_Default 1
#define MUIV_List_MultiSelect_Shifted 2
#define MUIV_List_MultiSelect_Always 3
#define MUIV_List_ScrollerPos_Default 0
#define MUIV_List_ScrollerPos_Left 1
#define MUIV_List_ScrollerPos_Right 2
#define MUIV_List_ScrollerPos_None 3


/****************************************************************************/
/** Floattext                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Floattext[];
#else
#define MUIC_Floattext "Floattext.mui"
#endif

/* Methods */

#define MUIM_Floattext_Append               0x8042a221 /* V20 */
struct  MUIP_Floattext_Append               { ULONG MethodID; CONST_STRPTR Text; };

/* Attributes */

#define MUIA_Floattext_Justify              0x8042dc03 /* V4  isg BOOL              */
#define MUIA_Floattext_KeepStyles           0x80427b9f /* V20 i.. BOOL              */
#define MUIA_Floattext_SkipChars            0x80425c7d /* V4  is. STRPTR            */
#define MUIA_Floattext_TabSize              0x80427d17 /* V4  is. LONG              */
#define MUIA_Floattext_Text                 0x8042d16a /* V4  isg STRPTR            */



/****************************************************************************/
/** Volumelist                                                             **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Volumelist[];
#else
#define MUIC_Volumelist "Volumelist.mui"
#endif

/* Attributes */

#define MUIA_Volumelist_ExampleMode         0x804246a5 /* V20 i.. BOOL              */



/****************************************************************************/
/** Scrmodelist                                                            **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Scrmodelist[];
#else
#define MUIC_Scrmodelist "Scrmodelist.mui"
#endif

/* Attributes */




/****************************************************************************/
/** Dirlist                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Dirlist[];
#else
#define MUIC_Dirlist "Dirlist.mui"
#endif

/* Methods */

#define MUIM_Dirlist_Rename                 0x8042d336 /* V21 */
#define MUIM_Dirlist_ReRead                 0x80422d71 /* V4  */
#define MUIM_Dirlist_SetComment             0x8042b378 /* V21 */
#define MUIM_Dirlist_SetProtection          0x804202bb /* V21 */
struct  MUIP_Dirlist_Rename                 { ULONG MethodID; LONG row; CONST_STRPTR newname; };
struct  MUIP_Dirlist_ReRead                 { ULONG MethodID; };
struct  MUIP_Dirlist_SetComment             { ULONG MethodID; LONG row; CONST_STRPTR comment; };
struct  MUIP_Dirlist_SetProtection          { ULONG MethodID; LONG row; ULONG flags; };

/* Attributes */

#define MUIA_Dirlist_AcceptPattern          0x8042760a /* V4  isg STRPTR            */
#define MUIA_Dirlist_Directory              0x8042ea41 /* V4  isg STRPTR            */
#define MUIA_Dirlist_DrawersOnly            0x8042b379 /* V4  is. BOOL              */
#define MUIA_Dirlist_ExAllType              0x8042cd7c /* V20 i.g ULONG             */
#define MUIA_Dirlist_FilesOnly              0x8042896a /* V4  is. BOOL              */
#define MUIA_Dirlist_FilterDrawers          0x80424ad2 /* V4  is. BOOL              */
#define MUIA_Dirlist_FilterHook             0x8042ae19 /* V4  is. struct Hook *     */
#define MUIA_Dirlist_MultiSelDirs           0x80428653 /* V6  is. BOOL              */
#define MUIA_Dirlist_NumBytes               0x80429e26 /* V4  ..g LONG              */
#define MUIA_Dirlist_NumBytes64             0x80428050 /* V20 ..g int64 *           */
#define MUIA_Dirlist_NumDrawers             0x80429cb8 /* V4  ..g LONG              */
#define MUIA_Dirlist_NumFiles               0x8042a6f0 /* V4  ..g LONG              */
#define MUIA_Dirlist_Path                   0x80426176 /* V4  ..g STRPTR            */
#define MUIA_Dirlist_Pattern                0x8042c761 /* V20 is. STRPTR            */
#define MUIA_Dirlist_RejectIcons            0x80424808 /* V4  is. BOOL              */
#define MUIA_Dirlist_RejectPattern          0x804259c7 /* V4  isg STRPTR            */
#define MUIA_Dirlist_SortDirs               0x8042bbb9 /* V4  is. LONG              */
#define MUIA_Dirlist_SortHighLow            0x80421896 /* V4  is. BOOL              */
#define MUIA_Dirlist_SortType               0x804228bc /* V4  is. LONG              */
#define MUIA_Dirlist_Status                 0x804240de /* V4  ..g LONG              */

#define MUIV_Dirlist_SortDirs_First 0
#define MUIV_Dirlist_SortDirs_Last 1
#define MUIV_Dirlist_SortDirs_Mix 2
#define MUIV_Dirlist_SortType_Name 0
#define MUIV_Dirlist_SortType_Date 1
#define MUIV_Dirlist_SortType_Size 2
#define MUIV_Dirlist_SortType_Comment 3
#define MUIV_Dirlist_SortType_Flags 4
#define MUIV_Dirlist_SortType_Type 5
#define MUIV_Dirlist_SortType_Used 6
#define MUIV_Dirlist_SortType_Time 7
#define MUIV_Dirlist_SortType_DateTime 8
#define MUIV_Dirlist_SortType_Count 9
#define MUIV_Dirlist_Status_Invalid 0
#define MUIV_Dirlist_Status_Reading 1
#define MUIV_Dirlist_Status_Valid 2


/****************************************************************************/
/** Selectgroup                                                            **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Selectgroup[];
#else
#define MUIC_Selectgroup "Selectgroup.mui"
#endif

/* Attributes */

#define MUIA_Selectgroup_Active             0x80421788 /* V21 isg LONG              */

#define MUIV_Selectgroup_Active_Next -1
#define MUIV_Selectgroup_Active_Prev -2


/****************************************************************************/
/** Argstring                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Argstring[];
#else
#define MUIC_Argstring "Argstring.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Argstring_Contents             0x80429456 /* V20 isg STRPTR            */
#define MUIA_Argstring_Template             0x80422904 /* V20 isg STRPTR            */



/****************************************************************************/
/** Menudisplay                                                            **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Menudisplay[];
#else
#define MUIC_Menudisplay "Menudisplay.mui"
#endif

/* Methods */



/****************************************************************************/
/** Mccprefs                                                               **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Mccprefs[];
#else
#define MUIC_Mccprefs "Mccprefs.mui"
#endif

/* Methods */

#define MUIM_Mccprefs_ConfigToGadgets       0x80427043 /* V11 */
#define MUIM_Mccprefs_GadgetsToConfig       0x80425242 /* V11 */
#define MUIM_Mccprefs_RegisterGadget        0x80424828 /* V20 */
struct  MUIP_Mccprefs_ConfigToGadgets       { ULONG MethodID; Object *configdata; };
struct  MUIP_Mccprefs_GadgetsToConfig       { ULONG MethodID; Object *configdata; Object *originator; };
struct  MUIP_Mccprefs_RegisterGadget        { ULONG MethodID; Object *gadget; ULONG id; ULONG params; CONST_STRPTR title; ULONG attr; Object *label; };

/* Attributes */




/****************************************************************************/
/** Register                                                               **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Register[];
#else
#define MUIC_Register "Register.mui"
#endif

/* Attributes */

#ifdef MUI_OBSOLETE
#define MUIA_Register_Frame                 0x8042349b /* V7  i.g BOOL              */
#endif /* MUI_OBSOLETE */
#define MUIA_Register_Titles                0x804297ec /* V7  isg STRPTR *          */

#define MUIV_Register_Titles_UData -1
#define MUIV_Register_Titles_Frame -2


/****************************************************************************/
/** Penadjust                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Penadjust[];
#else
#define MUIC_Penadjust "Penadjust.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Penadjust_PSIMode              0x80421cbb /* V11 i.. BOOL              */



/****************************************************************************/
/** Settingsgroup                                                          **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Settingsgroup[];
#else
#define MUIC_Settingsgroup "Settingsgroup.mui"
#endif

/* Methods */

#define MUIM_Settingsgroup_ConfigToGadgets  0x80427043 /* V11 */
#define MUIM_Settingsgroup_GadgetsToConfig  0x80425242 /* V11 */
struct  MUIP_Settingsgroup_ConfigToGadgets  { ULONG MethodID; Object *configdata; };
struct  MUIP_Settingsgroup_GadgetsToConfig  { ULONG MethodID; Object *configdata; Object *originator; };

/* Attributes */




/****************************************************************************/
/** Settings                                                               **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Settings[];
#else
#define MUIC_Settings "Settings.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Frameadjust                                                            **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Frameadjust[];
#else
#define MUIC_Frameadjust "Frameadjust.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Imageadjust                                                            **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Imageadjust[];
#else
#define MUIC_Imageadjust "Imageadjust.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Backgroundadjust                                                       **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Backgroundadjust[];
#else
#define MUIC_Backgroundadjust "Backgroundadjust.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Virtgroup                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Virtgroup[];
#else
#define MUIC_Virtgroup "Virtgroup.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Virtgroup_Height               0x80423038 /* V6  ..g LONG              */
#define MUIA_Virtgroup_Input                0x80427f7e /* V11 i.. BOOL              */
#define MUIA_Virtgroup_Left                 0x80429371 /* V6  isg LONG              */
#define MUIA_Virtgroup_Top                  0x80425200 /* V6  isg LONG              */
#define MUIA_Virtgroup_TryFit               0x80429427 /* V20 isg BOOL              */
#define MUIA_Virtgroup_Width                0x80427c49 /* V6  ..g LONG              */



/****************************************************************************/
/** Scrollgroup                                                            **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Scrollgroup[];
#else
#define MUIC_Scrollgroup "Scrollgroup.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Scrollgroup_AutoBars           0x8042f50e /* V20 isg BOOL              */
#define MUIA_Scrollgroup_Contents           0x80421261 /* V4  i.g Object *          */
#define MUIA_Scrollgroup_FreeHoriz          0x804292f3 /* V9  i.. BOOL              */
#define MUIA_Scrollgroup_FreeVert           0x804224f2 /* V9  i.. BOOL              */
#define MUIA_Scrollgroup_HorizBar           0x8042b63d /* V16 ..g Object *          */
#define MUIA_Scrollgroup_NoHorizBar         0x8042cab1 /* V20 isg BOOL              */
#define MUIA_Scrollgroup_NoVertBar          0x804264c3 /* V20 isg BOOL              */
#define MUIA_Scrollgroup_UseWinBorder       0x804284c1 /* V13 i.. BOOL              */
#define MUIA_Scrollgroup_VertBar            0x8042cdc0 /* V16 ..g Object *          */



/****************************************************************************/
/** Scrollbar                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Scrollbar[];
#else
#define MUIC_Scrollbar "Scrollbar.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Scrollbar_IncDecSize           0x80426c07 /* V20 isg ULONG             */
#define MUIA_Scrollbar_Type                 0x8042fb6b /* V11 i.. LONG              */

#define MUIV_Scrollbar_Type_Default 0
#define MUIV_Scrollbar_Type_Bottom 1
#define MUIV_Scrollbar_Type_Top 2
#define MUIV_Scrollbar_Type_Sym 3
#define MUIV_Scrollbar_Type_None 4


/****************************************************************************/
/** Listview                                                               **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Listview[];
#else
#define MUIC_Listview "Listview.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Listview_AgainClick            0x804214c2 /* V20 i.g BOOL              */
#define MUIA_Listview_ClickColumn           0x8042d1b3 /* V7  ..g LONG              */
#define MUIA_Listview_DefClickColumn        0x8042b296 /* V7  isg LONG              */
#define MUIA_Listview_DoubleClick           0x80424635 /* V4  i.g BOOL              */
#define MUIA_Listview_DragType              0x80425cd3 /* V11 isg LONG              */
#define MUIA_Listview_Input                 0x8042682d /* V4  i.. BOOL              */
#define MUIA_Listview_List                  0x8042bcce /* V4  i.g Object *          */
#define MUIA_Listview_MultiSelect           0x80427e08 /* V7  i.. LONG              */
#define MUIA_Listview_ScrollerPos           0x8042b1b4 /* V10 i.. BOOL              */
#define MUIA_Listview_SelectChange          0x8042178f /* V4  ..g BOOL              */

#define MUIV_Listview_DragType_None 0
#define MUIV_Listview_DragType_Immediate 1
#define MUIV_Listview_MultiSelect_None 0
#define MUIV_Listview_MultiSelect_Default 1
#define MUIV_Listview_MultiSelect_Shifted 2
#define MUIV_Listview_MultiSelect_Always 3
#define MUIV_Listview_ScrollerPos_Default 0
#define MUIV_Listview_ScrollerPos_Left 1
#define MUIV_Listview_ScrollerPos_Right 2
#define MUIV_Listview_ScrollerPos_None 3


/****************************************************************************/
/** Radio                                                                  **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Radio[];
#else
#define MUIC_Radio "Radio.mui"
#endif

/* Attributes */

#define MUIA_Radio_Active                   0x80429b41 /* V4  isg LONG              */
#define MUIA_Radio_Entries                  0x8042b6a1 /* V4  i.. STRPTR *          */



/****************************************************************************/
/** Cycle                                                                  **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Cycle[];
#else
#define MUIC_Cycle "Cycle.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Cycle_Active                   0x80421788 /* V4  isg LONG              */
#define MUIA_Cycle_Entries                  0x80420629 /* V4  is. STRPTR *          */

#define MUIV_Cycle_Active_Next -1
#define MUIV_Cycle_Active_Prev -2


/****************************************************************************/
/** Palette                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Palette[];
#else
#define MUIC_Palette "Palette.mui"
#endif

/* Attributes */

#define MUIA_Palette_Entries                0x8042a3d8 /* V6  i.g struct MUI_Palette_Entry * */
#define MUIA_Palette_Groupable              0x80423e67 /* V6  isg BOOL              */
#define MUIA_Palette_Names                  0x8042c3a2 /* V6  isg STRPTR *          */



/****************************************************************************/
/** Popstring                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Popstring[];
#else
#define MUIC_Popstring "Popstring.mui"
#endif

/* Methods */

#define MUIM_Popstring_Close                0x8042dc52 /* V7  */
#define MUIM_Popstring_Open                 0x804258ba /* V7  */
struct  MUIP_Popstring_Close                { ULONG MethodID; LONG result; };
struct  MUIP_Popstring_Open                 { ULONG MethodID; };

/* Attributes */

#define MUIA_Popstring_Button               0x8042d0b9 /* V7  i.g Object *          */
#define MUIA_Popstring_CloseHook            0x804256bf /* V7  isg struct Hook *     */
#define MUIA_Popstring_OpenHook             0x80429d00 /* V7  isg struct Hook *     */
#define MUIA_Popstring_String               0x804239ea /* V7  i.g Object *          */
#define MUIA_Popstring_Toggle               0x80422b7a /* V7  isg BOOL              */



/****************************************************************************/
/** Pubscreenadjust                                                        **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Pubscreenadjust[];
#else
#define MUIC_Pubscreenadjust "Pubscreenadjust.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Pubscreenpanel                                                         **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Pubscreenpanel[];
#else
#define MUIC_Pubscreenpanel "Pubscreenpanel.mui"
#endif

/* Methods */



/****************************************************************************/
/** Pubscreenlist                                                          **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Pubscreenlist[];
#else
#define MUIC_Pubscreenlist "Pubscreenlist.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Pubscreenlist_Selection        0x8042fe58 /* V20 ..g STRPTR            */



/****************************************************************************/
/** Popobject                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Popobject[];
#else
#define MUIC_Popobject "Popobject.mui"
#endif

/* Attributes */

#define MUIA_Popobject_Follow               0x80424cb5 /* V7  isg BOOL              */
#define MUIA_Popobject_Light                0x8042a5a3 /* V7  isg BOOL              */
#define MUIA_Popobject_Object               0x804293e3 /* V7  i.g Object *          */
#define MUIA_Popobject_ObjStrHook           0x8042db44 /* V7  isg struct Hook *     */
#define MUIA_Popobject_StrObjHook           0x8042fbe1 /* V7  isg struct Hook *     */
#define MUIA_Popobject_Volatile             0x804252ec /* V7  isg BOOL              */
#define MUIA_Popobject_WindowHook           0x8042f194 /* V9  isg struct Hook *     */



/****************************************************************************/
/** Poplist                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Poplist[];
#else
#define MUIC_Poplist "Poplist.mui"
#endif

/* Attributes */

#define MUIA_Poplist_Array                  0x8042084c /* V8  i.. STRPTR *          */



/****************************************************************************/
/** Popscreen                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Popscreen[];
#else
#define MUIC_Popscreen "Popscreen.mui"
#endif

/* Attributes */




/****************************************************************************/
/** Popasl                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Popasl[];
#else
#define MUIC_Popasl "Popasl.mui"
#endif

/* Attributes */

#define MUIA_Popasl_Active                  0x80421b37 /* V7  ..g BOOL              */
#define MUIA_Popasl_StartHook               0x8042b703 /* V7  isg struct Hook *     */
#define MUIA_Popasl_StopHook                0x8042d8d2 /* V7  isg struct Hook *     */
#define MUIA_Popasl_Type                    0x8042df3d /* V7  i.g ULONG             */



/****************************************************************************/
/** Semaphore                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Semaphore[];
#else
#define MUIC_Semaphore "Semaphore.mui"
#endif

/* Methods */

#define MUIM_Semaphore_Attempt              0x80426ce2 /* V11 */
#define MUIM_Semaphore_AttemptShared        0x80422551 /* V11 */
#define MUIM_Semaphore_Obtain               0x804276f0 /* V11 */
#define MUIM_Semaphore_ObtainShared         0x8042ea02 /* V11 */
#define MUIM_Semaphore_Release              0x80421f2d /* V11 */
struct  MUIP_Semaphore_Attempt              { ULONG MethodID; };
struct  MUIP_Semaphore_AttemptShared        { ULONG MethodID; };
struct  MUIP_Semaphore_Obtain               { ULONG MethodID; };
struct  MUIP_Semaphore_ObtainShared         { ULONG MethodID; };
struct  MUIP_Semaphore_Release              { ULONG MethodID; };

/* Attributes */




/****************************************************************************/
/** Applist                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Applist[];
#else
#define MUIC_Applist "Applist.mui"
#endif

/* Methods */



/****************************************************************************/
/** Cclist                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Cclist[];
#else
#define MUIC_Cclist "Cclist.mui"
#endif

/* Methods */



/****************************************************************************/
/** Dataspace                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Dataspace[];
#else
#define MUIC_Dataspace "Dataspace.mui"
#endif

/* Methods */

#define MUIM_Dataspace_Add                  0x80423366 /* V11 */
#define MUIM_Dataspace_Clear                0x8042b6c9 /* V11 */
#define MUIM_Dataspace_Find                 0x8042832c /* V11 */
#define MUIM_Dataspace_Get                  0x8042483f /* V21 */
#define MUIM_Dataspace_Merge                0x80423e2b /* V11 */
#define MUIM_Dataspace_ReadIFF              0x80420dfb /* V11 */
#define MUIM_Dataspace_Remove               0x8042dce1 /* V11 */
#define MUIM_Dataspace_WriteIFF             0x80425e8e /* V11 */
struct  MUIP_Dataspace_Add                  { ULONG MethodID; CONST_APTR data; LONG len; ULONG id; };
struct  MUIP_Dataspace_Clear                { ULONG MethodID; };
struct  MUIP_Dataspace_Find                 { ULONG MethodID; ULONG id; };
struct  MUIP_Dataspace_Get                  { ULONG MethodID; ULONG id; ULONG *size; };
struct  MUIP_Dataspace_Merge                { ULONG MethodID; Object *dataspace; };
struct  MUIP_Dataspace_ReadIFF              { ULONG MethodID; struct IFFHandle *handle; };
struct  MUIP_Dataspace_Remove               { ULONG MethodID; ULONG id; };
struct  MUIP_Dataspace_WriteIFF             { ULONG MethodID; struct IFFHandle *handle; ULONG type; ULONG id; };

/* Attributes */

#define MUIA_Dataspace_Count                0x8042e7ea /* V20 ..g ULONG             */
#define MUIA_Dataspace_Pool                 0x80424cf9 /* V11 i.. APTR              */



/****************************************************************************/
/** Configdata                                                             **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Configdata[];
#else
#define MUIC_Configdata "Configdata.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Screenspace                                                            **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Screenspace[];
#else
#define MUIC_Screenspace "Screenspace.mui"
#endif

/* Methods */



/****************************************************************************/
/** Imagespace                                                             **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Imagespace[];
#else
#define MUIC_Imagespace "Imagespace.mui"
#endif

/* Methods */



/****************************************************************************/
/** Rootgrp                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Rootgrp[];
#else
#define MUIC_Rootgrp "Rootgrp.mui"
#endif


/****************************************************************************/
/** Audiocontrols                                                          **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Audiocontrols[];
#else
#define MUIC_Audiocontrols "Audiocontrols.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Audiomixer                                                             **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Audiomixer[];
#else
#define MUIC_Audiomixer "Audiomixer.mui"
#endif

/* Attributes */




/****************************************************************************/
/** Popmenu                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Popmenu[];
#else
#define MUIC_Popmenu "Popmenu.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Panel                                                                  **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Panel[];
#else
#define MUIC_Panel "Panel.mui"
#endif

/* Methods */

#define MUIM_Panel_Run                      0x8042d789 /* V21 */
struct  MUIP_Panel_Run                      { ULONG MethodID; Object *app; Object *win; };

/* Attributes */




/****************************************************************************/
/** Filepanel                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Filepanel[];
#else
#define MUIC_Filepanel "Filepanel.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Filepanel_AcceptPattern        0x80426f3b /* V20 i.g STRPTR            */
#define MUIA_Filepanel_DoMultiSelect        0x8042fd78 /* V20 i.g BOOL              */
#define MUIA_Filepanel_DoPatterns           0x80420b3b /* V20 i.g BOOL              */
#define MUIA_Filepanel_DoSaveMode           0x80429022 /* V20 i.g BOOL              */
#define MUIA_Filepanel_Drawer               0x8042e802 /* V20 isg STRPTR            */
#define MUIA_Filepanel_DrawersOnly          0x80427726 /* V20 i.g BOOL              */
#define MUIA_Filepanel_File                 0x80427acf /* V20 isg STRPTR            */
#define MUIA_Filepanel_FilterDrawers        0x804298a1 /* V20 i.g BOOL              */
#define MUIA_Filepanel_FilterFunc           0x80429c9d /* V20 i.g struct Hook *     */
#define MUIA_Filepanel_Pattern              0x8042c330 /* V20 isg STRPTR            */
#define MUIA_Filepanel_RejectIcons          0x80423450 /* V20 i.g BOOL              */
#define MUIA_Filepanel_RejectPattern        0x804281ab /* V20 i.g STRPTR            */



/****************************************************************************/
/** Fontpanel                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Fontpanel[];
#else
#define MUIC_Fontpanel "Fontpanel.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Fontpanel_ShowCollection       0x804225ea /* V20 i.. LONG              */

#define MUIV_Fontpanel_ShowCollection_All -1
#define MUIV_Fontpanel_ShowCollection_FixedWidth 1
#define MUIV_Fontpanel_ShowCollection_Bitmap 2
#define MUIV_Fontpanel_ShowCollection_TrueType 4
#define MUIV_Fontpanel_ShowCollection_User 8


/****************************************************************************/
/** Screenmodepanel                                                        **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Screenmodepanel[];
#else
#define MUIC_Screenmodepanel "Screenmodepanel.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Keyadjust                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Keyadjust[];
#else
#define MUIC_Keyadjust "Keyadjust.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Keyadjust_AllowDoubleClick     0x8042be82 /* V20 isg BOOL              */
#define MUIA_Keyadjust_AllowMouseEvents     0x8042b61c /* V20 isg BOOL              */
#define MUIA_Keyadjust_AllowMultipleKeys    0x8042890b /* V20 isg BOOL              */
#define MUIA_Keyadjust_AllowTripleClick     0x8042fd79 /* V20 isg BOOL              */
#define MUIA_Keyadjust_Key                  0x8042e161 /* V20 isg STRPTR            */



/****************************************************************************/
/** Imagebrowser                                                           **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Imagebrowser[];
#else
#define MUIC_Imagebrowser "Imagebrowser.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Colorring                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Colorring[];
#else
#define MUIC_Colorring "Colorring.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Coloradjust                                                            **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Coloradjust[];
#else
#define MUIC_Coloradjust "Coloradjust.mui"
#endif

/* Methods */


/* Attributes */

#define MUIA_Coloradjust_Blue               0x8042b8a3 /* V4  isg ULONG             */
#define MUIA_Coloradjust_Green              0x804285ab /* V4  isg ULONG             */
#define MUIA_Coloradjust_ModeID             0x8042ec59 /* V4  isg ULONG             */
#define MUIA_Coloradjust_Red                0x80420eaa /* V4  isg ULONG             */
#define MUIA_Coloradjust_RGB                0x8042f899 /* V4  isg ULONG *           */



/****************************************************************************/
/** Process                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Process[];
#else
#define MUIC_Process "Process.mui"
#endif

/* Methods */

#define MUIM_Process_Kill                   0x804264cf /* V20 */
#define MUIM_Process_Launch                 0x80425df7 /* V20 */
#define MUIM_Process_Process                0x804230aa /* V20 */
#define MUIM_Process_Signal                 0x8042e791 /* V20 */
struct  MUIP_Process_Kill                   { ULONG MethodID; LONG maxdelay; };
struct  MUIP_Process_Launch                 { ULONG MethodID; };
struct  MUIP_Process_Process                { ULONG MethodID; ULONG *kill; Object *proc; };
struct  MUIP_Process_Signal                 { ULONG MethodID; ULONG sigs; };

/* Attributes */

#define MUIA_Process_AutoLaunch             0x80428855 /* V20 i.. ULONG             */
#define MUIA_Process_Name                   0x8042732b /* V20 i.. ULONG             */
#define MUIA_Process_Priority               0x80422a54 /* V20 i.. ULONG             */
#define MUIA_Process_SourceClass            0x8042cf8b /* V20 i.. ULONG             */
#define MUIA_Process_SourceObject           0x804212a2 /* V20 i.. ULONG             */
#define MUIA_Process_StackSize              0x804230d0 /* V20 i.. ULONG             */
#define MUIA_Process_Task                   0x8042b123 /* V20 ..g ULONG             */



/****************************************************************************/
/** Pubscreen                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Pubscreen[];
#else
#define MUIC_Pubscreen "Pubscreen.mui"
#endif

/* Attributes */




/****************************************************************************/
/** Aboutpage                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Aboutpage[];
#else
#define MUIC_Aboutpage "Aboutpage.mui"
#endif

/* Methods */



/****************************************************************************/
/** Title                                                                  **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Title[];
#else
#define MUIC_Title "Title.mui"
#endif

/* Methods */

#define MUIM_Title_Close                    0x8042303a /* V20 */
struct  MUIP_Title_Close                    { ULONG MethodID; Object *tito; };

/* Attributes */

#define MUIA_Title_Clickable                0x80425959 /* V20 i.. LONG              */
#define MUIA_Title_Closable                 0x80420402 /* V20 isg BOOL              */
#define MUIA_Title_EventHandlerPriority     0x804286bc /* V20 i.. LONG              */
#define MUIA_Title_OnLastClose              0x804253cf /* V21 is. LONG              */
#define MUIA_Title_Position                 0x804273a3 /* V20 isg LONG              */
#define MUIA_Title_Sortable                 0x804211f1 /* V20 isg BOOL              */

#define MUIV_Title_EventHandlerPriority_Default 0
#define MUIV_Title_OnLastClose_Remove 0
#define MUIV_Title_OnLastClose_WindowAction 1
#define MUIV_Title_Position_Top 0
#define MUIV_Title_Position_Bottom 1
#define MUIV_Title_Position_Left 2
#define MUIV_Title_Position_Right 3


/****************************************************************************/
/** Pixmap                                                                 **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Pixmap[];
#else
#define MUIC_Pixmap "Pixmap.mui"
#endif

/* Methods */

#define MUIM_Pixmap_DrawSection             0x8042ce0f /* V20 */
struct  MUIP_Pixmap_DrawSection             { ULONG MethodID; LONG sx; LONG sy; LONG sw; LONG sh; struct MUI_RenderInfo *mri; LONG dx; LONG dy; ULONG alpha; };

/* Attributes */

#define MUIA_Pixmap_Alpha                   0x80421fef /* V20 isg ULONG             */
#define MUIA_Pixmap_CLUT                    0x8042042a /* V20 isg ULONG *           */
#define MUIA_Pixmap_CLUTSize                0x8042bde3 /* V20 isg ULONG             */
#define MUIA_Pixmap_CompressedSize          0x8042e7e4 /* V20 isg ULONG             */
#define MUIA_Pixmap_Compression             0x8042ce74 /* V20 isg ULONG             */
#define MUIA_Pixmap_Data                    0x80429ea0 /* V20 isg CONST_APTR        */
#define MUIA_Pixmap_Format                  0x8042ab14 /* V20 isg ULONG             */
#define MUIA_Pixmap_Height                  0x804288be /* V20 isg LONG              */
#define MUIA_Pixmap_TransparencyThreshold   0x8042437c /* V20 isg UBYTE             */
#define MUIA_Pixmap_UncompressedData        0x8042b085 /* V20 ..g CONST_APTR        */
#define MUIA_Pixmap_Width                   0x8042ccb8 /* V20 isg LONG              */

#define MUIV_Pixmap_Compression_None 0
#define MUIV_Pixmap_Compression_RLE 1
#define MUIV_Pixmap_Compression_BZip2 2
#define MUIV_Pixmap_Compression_Z 3
#define MUIV_Pixmap_Compression_LZMA 4
#define MUIV_Pixmap_Format_CLUT8 0
#define MUIV_Pixmap_Format_RGB24 1
#define MUIV_Pixmap_Format_ARGB32 2


/****************************************************************************/
/** Winborder                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Winborder[];
#else
#define MUIC_Winborder "Winborder.mui"
#endif

/* Methods */


/* Attributes */




/****************************************************************************/
/** Datamap                                                                **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Datamap[];
#else
#define MUIC_Datamap "Datamap.mui"
#endif

/* Methods */

#define MUIM_Datamap_Clear                  0x8042eebc /* V20 */
#define MUIM_Datamap_Find                   0x8042d650 /* V20 */
#define MUIM_Datamap_Get                    0x8042c2ba /* V21 */
#define MUIM_Datamap_Iterate                0x8042fda1 /* V20 */
#define MUIM_Datamap_IterationKey           0x8042bc15 /* V20 */
#define MUIM_Datamap_Remove                 0x804203d8 /* V20 */
#define MUIM_Datamap_Set                    0x8042b84f /* V20 */
struct  MUIP_Datamap_Clear                  { ULONG MethodID; };
struct  MUIP_Datamap_Find                   { ULONG MethodID; CONST_STRPTR key; };
struct  MUIP_Datamap_Get                    { ULONG MethodID; CONST_STRPTR key; ULONG *size; };
struct  MUIP_Datamap_Iterate                { ULONG MethodID; ULONG *counter; };
struct  MUIP_Datamap_IterationKey           { ULONG MethodID; ULONG *counter; };
struct  MUIP_Datamap_Remove                 { ULONG MethodID; CONST_STRPTR key; };
struct  MUIP_Datamap_Set                    { ULONG MethodID; CONST_APTR data; LONG len; CONST_STRPTR key; };

/* Attributes */

#define MUIA_Datamap_AutoLock               0x8042fbe4 /* V20 i.. BOOL              */
#define MUIA_Datamap_CopyKeys               0x8042a179 /* V20 i.. BOOL              */
#define MUIA_Datamap_Count                  0x80427580 /* V21 ..g ULONG             */
#define MUIA_Datamap_Pool                   0x80424724 /* V20 i.. APTR              */



/****************************************************************************/
/** Slave                                                                  **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Slave[];
#else
#define MUIC_Slave "Slave.mui"
#endif

/* Methods */

#define MUIM_Slave_Cleanup                  0x80425e72 /* V20 */
#define MUIM_Slave_Dispatch                 0x8042361f /* V20 */
#define MUIM_Slave_Error                    0x8042e544 /* V20 */
#define MUIM_Slave_Setup                    0x80429faa /* V20 */
#define MUIM_Slave_SignalsReceived          0x8042d21a /* V20 */
struct  MUIP_Slave_Cleanup                  { ULONG MethodID; };
struct  MUIP_Slave_Dispatch                 { ULONG MethodID; ULONG flags; LONG count; /* ... */ };
struct  MUIP_Slave_Error                    { ULONG MethodID; Msg FailedDispatch; /* ... */ };
struct  MUIP_Slave_Setup                    { ULONG MethodID; };
struct  MUIP_Slave_SignalsReceived          { ULONG MethodID; ULONG sigmask; };

/* Attributes */

#define MUIA_Slave_Application              0x80427767 /* V20 i.. Object *          */
#define MUIA_Slave_Class                    0x80420f8c /* V20 i.. Object *          */
#define MUIA_Slave_Object                   0x804202ab /* V20 i.. Object *          */



/****************************************************************************/
/** Objectmap                                                              **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Objectmap[];
#else
#define MUIC_Objectmap "Objectmap.mui"
#endif

/* Methods */

#define MUIM_Objectmap_Clear                0x80422ee5 /* V20 */
#define MUIM_Objectmap_Find                 0x80426506 /* V20 */
#define MUIM_Objectmap_Iterate              0x804262bc /* V20 */
#define MUIM_Objectmap_IterationKey         0x8042d7ff /* V20 */
#define MUIM_Objectmap_Remove               0x8042f649 /* V20 */
#define MUIM_Objectmap_Set                  0x80421ec5 /* V20 */
struct  MUIP_Objectmap_Clear                { ULONG MethodID; };
struct  MUIP_Objectmap_Find                 { ULONG MethodID; CONST_STRPTR key; };
struct  MUIP_Objectmap_Iterate              { ULONG MethodID; ULONG *counter; };
struct  MUIP_Objectmap_IterationKey         { ULONG MethodID; ULONG *counter; };
struct  MUIP_Objectmap_Remove               { ULONG MethodID; CONST_STRPTR key; };
struct  MUIP_Objectmap_Set                  { ULONG MethodID; Object *o; CONST_STRPTR key; };

/* Attributes */

#define MUIA_Objectmap_AutoLock             0x8042e65f /* V20 i.. BOOL              */
#define MUIA_Objectmap_CopyKeys             0x8042b964 /* V20 i.. BOOL              */
#define MUIA_Objectmap_Count                0x80426006 /* V21 ..g ULONG             */
#define MUIA_Objectmap_Pool                 0x80422ed3 /* V20 i.. APTR              */



/****************************************************************************/
/** Textdata                                                               **/
/****************************************************************************/

#ifdef _DCC
extern char MUIC_Textdata[];
#else
#define MUIC_Textdata "Textdata.mui"
#endif

/* Methods */

#define MUIM_Textdata_Convert               0x80425988 /* V21 */
struct  MUIP_Textdata_Convert               { ULONG MethodID; ULONG encoding; };

/* Attributes */

#define MUIA_Textdata_Contents              0x80420c3f /* V21 i.g CONST_STRPTR      */
#define MUIA_Textdata_Encoding              0x8042c587 /* V21 i.g ULONG             */
#define MUIA_Textdata_SourceBytes           0x804242c0 /* V21 i.. LONG              */
#define MUIA_Textdata_SourceEncoding        0x80426d1a /* V21 i.. ULONG             */



/*****************************************/
/* End of automatic header file creation */
/*****************************************/






/*************************************************************************
** Structures and Macros for creating custom classes.
*************************************************************************/


/*
** GENERAL NOTES:
**
** - Everything described in this header file is only valid within
**   MUI classes. You may never use any of these things out of
**   a class, e.g. in a traditional MUI application.
**
** - Except when otherwise stated, all structures are strictly read only.
*/


/* Global information for every object */

struct MUI_GlobalInfo
{
	ULONG priv0;
	Object *mgi_ApplicationObject;

	/* ... private data follows ... */
};


/* Instance data of notify class */

struct MUI_NotifyData
{
	struct MUI_GlobalInfo *mnd_GlobalInfo;
	ULONG                  mnd_UserData;
	ULONG                  mnd_ObjectID;
	ULONG priv1;
	ULONG priv2;
	ULONG priv3;
	ULONG priv4;
};


/* MUI_MinMax structure holds information about minimum, maximum
   and default dimensions of an object. */

struct MUI_MinMax
{
	WORD MinWidth;
	WORD MinHeight;
	WORD MaxWidth;
	WORD MaxHeight;
	WORD DefWidth;
	WORD DefHeight;
};

#define MUI_MAXMAX 10000 /* use this if a dimension is not limited. */


/* Hook message for custom layout */

struct MUI_LayoutMsg
{
	ULONG                  lm_Type;     /* type of message (see defines below)                      */
	struct MinList        *lm_Children; /* list of this groups children, traverse with NextObject() */
	struct MUI_MinMax      lm_MinMax;   /* results for MUILM_MINMAX                                 */
	struct
	{
		LONG Width;
		LONG Height;
		ULONG priv5;
		ULONG priv6;
	} lm_Layout;   /* size (and result) for MUILM_LAYOUT                       */
};

#define MUILM_MINMAX    1  /* MUI wants you to calc your min & max sizes */
#define MUILM_LAYOUT    2  /* MUI wants you to layout your children      */

#define MUILM_UNKNOWN  -1  /* return this if your hook doesn't implement lm_Type */


/* (partial) instance data of area class */

struct MUI_AreaData
{
	struct MUI_RenderInfo *mad_RenderInfo;     /* RenderInfo for this object */
	ULONG priv7;
	struct TextFont       *mad_Font;           /* Font */
	struct MUI_MinMax      mad_MinMax;         /* min/max/default sizes */
	struct IBox            mad_Box;            /* position and dimension */
	BYTE                   mad_addleft;        /* frame & innerspacing left offset */
	BYTE                   mad_addtop;         /* frame & innerspacing top offset  */
	BYTE                   mad_subwidth;       /* frame & innerspacing add. width  */
	BYTE                   mad_subheight;      /* frame & innerspacing add. height */
	ULONG                  mad_Flags;          /* see definitions below */

	/* ... private data follows ... */
};

/* Definitions for mad_Flags, other flags are private */

#define MADF_DRAWOBJECT        (1<< 0) /* completely redraw yourself */
#define MADF_DRAWUPDATE        (1<< 1) /* only update yourself */


/* Drag and drop */

struct MUI_DragImage
{
	struct BitMap *bm;
	WORD width;  /* exact width and height of bitmap */
	WORD height;
	WORD touchx; /* position of pointer click relative to bitmap */
	WORD touchy;
	ULONG flags; /* see flags below, all other flags reserved for future use */
	PLANEPTR mask;
};

/* flags for struct MUI_DragImage */
#define MUIF_DRAGIMAGE_HASMASK       (1<<0) /* set this if mask contains a valid masking plane */
#define MUIF_DRAGIMAGE_SOURCEALPHA   (1<<1) /* set this if the bitmap contains information about pixel transparency */

/* flags for MUIM_DragEvent */
#define MUIF_DRAGEVENT_REDRAW        (1<<0) /* set by the overloader in case the MUI_DragImage was modified during MUIM_DragEvent */
#define MUIF_DRAGEVENT_FOREIGNDROP   (1<<1) /* set by the overloader in case it can drop to a foreign window, the actual drop must be implemented in the Application's MUIM_DragDrop */
#define MUIF_DRAGEVENT_MOUSECHANGED  (1<<2) /* set by the overloader to force a custom mouse pointer instead of the one picked by MUI */


/* MUI's draw pens */

#define MPEN_SHINE      0
#define MPEN_HALFSHINE  1
#define MPEN_BACKGROUND 2
#define MPEN_HALFSHADOW 3
#define MPEN_SHADOW     4
#define MPEN_TEXT       5
#define MPEN_FILL       6
#define MPEN_MARK       7
#define MPEN_MARKTEXT   8
#define MPEN_COUNT      9


/* flags for MUI_Request() */

#define MUIREQ_XYPOS     (1<<31)


/* image types for the "flags" variable of MUI_Request() */
#define MUIV_Requester_Image_None       0x00ffffff  /* don't display any image */
#define MUIV_Requester_Image_Default    0           /* let MUI_Request() decide what image to use */
#define MUIV_Requester_Image_Info       1           /* display a '!' sign */
#define MUIV_Requester_Image_Question   2           /* display a '?' sign */
#define MUIV_Requester_Image_Warning    3           /* display a warning sign */
#define MUIV_Requester_Image_Error      4           /* display an error sign */
#define MUIV_Requester_Image_InsertDisk 5           /* display an insert disk sign */


/* Mask for pens from MUI_ObtainPen() */

#define MUIPEN_MASK 0x0000ffff
#define MUIPEN(pen) ((pen) & MUIPEN_MASK)

/* Information on display environment */

struct MUI_RenderInfo
{
	Object          *mri_WindowObject;  /* valid between MUIM_Setup/MUIM_Cleanup */

	struct Screen   *mri_Screen;        /* valid between MUIM_Setup/MUIM_Cleanup */
	struct DrawInfo *mri_DrawInfo;      /* valid between MUIM_Setup/MUIM_Cleanup */
	UWORD           *mri_Pens;          /* valid between MUIM_Setup/MUIM_Cleanup */
	struct Window   *mri_Window;        /* valid between MUIM_Show/MUIM_Hide */
	struct RastPort *mri_RastPort;      /* valid between MUIM_Show/MUIM_Hide */

	ULONG            mri_Flags;         /* valid between MUIM_Setup/MUIM_Cleanup */

	/* ... private data follows ... */
};


/*
** If mri_Flags & MUIMRI_RECTFILL, RectFill() is quicker
** than Move()/Draw() for horizontal or vertical lines.
** on the current display.
*/
#define MUIMRI_RECTFILL (1<<0)

/*
** If mri_Flags & MUIMRI_TRUECOLOR, display environment is a
** cybergraphics emulated hicolor or true color display.
*/
#define MUIMRI_TRUECOLOR (1<<1)

/*
** If mri_Flags & MUIMRI_THINFRAMES, MUI uses thin frames
** (1:1) apsect ratio instead of standard 2:1 frames.
*/
#define MUIMRI_THINFRAMES (1<<2)

/*
** If mri_Flags & MUIMRI_REFRESHMODE, MUI is currently
** refreshing a WFLG_SIMPLEREFRESH window and is inbetween
** a BeginRefresh()/EndRefresh() pair.
*/
#define MUIMRI_REFRESHMODE (1<<3)

/*
** If mri_Flags & MUIMRI_PLANAR, display environment is an
** old-style planar display.
*/
#define MUIMRI_PLANAR (1<<4)

/* the following macros can be used to get pointers to an objects
   GlobalInfo and RenderInfo structures. */

struct __dummyXFC2__
{
	struct MUI_NotifyData mnd;
	struct MUI_AreaData   mad;
};

#define muiNotifyData(obj) (&(((struct __dummyXFC2__ *)(obj))->mnd))
#define muiAreaData(obj)   (&(((struct __dummyXFC2__ *)(obj))->mad))

#define muiGlobalInfo(obj) (((struct __dummyXFC2__ *)(obj))->mnd.mnd_GlobalInfo)
#define muiUserData(obj)   (((struct __dummyXFC2__ *)(obj))->mnd.mnd_UserData)
#define muiRenderInfo(obj) (((struct __dummyXFC2__ *)(obj))->mad.mad_RenderInfo)

struct __dummyAUX5__
{
	struct MUI_NotifyData mnd;
	APTR                  mtd_text;
	ULONG                 mtd_encoding;
};

#define muiTextdata(obj)   ((struct __dummyAUX5__ *)(obj))

/* User configurable keyboard events coming with MUIM_HandleInput */

enum
{
	MUIKEY_RELEASE = -2, /* not a real key, faked when MUIKEY_PRESS is released */
	MUIKEY_NONE    = -1,
	MUIKEY_PRESS,
	MUIKEY_TOGGLE,
	MUIKEY_UP,
	MUIKEY_DOWN,
	MUIKEY_PAGEUP,
	MUIKEY_PAGEDOWN,
	MUIKEY_TOP,
	MUIKEY_BOTTOM,
	MUIKEY_LEFT,
	MUIKEY_RIGHT,
	MUIKEY_WORDLEFT,
	MUIKEY_WORDRIGHT,
	MUIKEY_LINESTART,
	MUIKEY_LINEEND,
	MUIKEY_GADGET_NEXT,
	MUIKEY_GADGET_PREV,
	MUIKEY_GADGET_OFF,
	MUIKEY_WINDOW_CLOSE,
	MUIKEY_WINDOW_NEXT,
	MUIKEY_WINDOW_PREV,
	MUIKEY_HELP,
	MUIKEY_POPUP,
	MUIKEY_CUT,
	MUIKEY_COPY,
	MUIKEY_PASTE,
	MUIKEY_UNDO,
	MUIKEY_REDO,
	MUIKEY_DELETE,
	MUIKEY_BACKSPACE,
	MUIKEY_ICONIFY,
};

#ifdef MUI_OBSOLETE /* keys are never used in bitmasks */
#define MUIKEYF_PRESS        (1<<MUIKEY_PRESS)
#define MUIKEYF_TOGGLE       (1<<MUIKEY_TOGGLE)
#define MUIKEYF_UP           (1<<MUIKEY_UP)
#define MUIKEYF_DOWN         (1<<MUIKEY_DOWN)
#define MUIKEYF_PAGEUP       (1<<MUIKEY_PAGEUP)
#define MUIKEYF_PAGEDOWN     (1<<MUIKEY_PAGEDOWN)
#define MUIKEYF_TOP          (1<<MUIKEY_TOP)
#define MUIKEYF_BOTTOM       (1<<MUIKEY_BOTTOM)
#define MUIKEYF_LEFT         (1<<MUIKEY_LEFT)
#define MUIKEYF_RIGHT        (1<<MUIKEY_RIGHT)
#define MUIKEYF_WORDLEFT     (1<<MUIKEY_WORDLEFT)
#define MUIKEYF_WORDRIGHT    (1<<MUIKEY_WORDRIGHT)
#define MUIKEYF_LINESTART    (1<<MUIKEY_LINESTART)
#define MUIKEYF_LINEEND      (1<<MUIKEY_LINEEND)
#define MUIKEYF_GADGET_NEXT  (1<<MUIKEY_GADGET_NEXT)
#define MUIKEYF_GADGET_PREV  (1<<MUIKEY_GADGET_PREV)
#define MUIKEYF_GADGET_OFF   (1<<MUIKEY_GADGET_OFF)
#define MUIKEYF_WINDOW_CLOSE (1<<MUIKEY_WINDOW_CLOSE)
#define MUIKEYF_WINDOW_NEXT  (1<<MUIKEY_WINDOW_NEXT)
#define MUIKEYF_WINDOW_PREV  (1<<MUIKEY_WINDOW_PREV)
#define MUIKEYF_HELP         (1<<MUIKEY_HELP)
#define MUIKEYF_POPUP        (1<<MUIKEY_POPUP)
#endif


/* Some useful shortcuts. define MUI_NOSHORTCUTS to get rid of them */
/* NOTE: These macros may only be used in custom classes and are    */
/* only valid if your class is inbetween the specified methods!     */

#ifndef MUI_NOSHORTCUTS

#define _app(obj)         (muiGlobalInfo(obj)->mgi_ApplicationObject) /* valid between MUIM_Setup/Cleanup */
#define _win(obj)         (muiRenderInfo(obj)->mri_WindowObject)      /* valid between MUIM_Setup/Cleanup */
#define _dri(obj)         (muiRenderInfo(obj)->mri_DrawInfo)          /* valid between MUIM_Setup/Cleanup */
#define _screen(obj)      (muiRenderInfo(obj)->mri_Screen)            /* valid between MUIM_Setup/Cleanup */
#define _pens(obj)        (muiRenderInfo(obj)->mri_Pens)              /* valid between MUIM_Setup/Cleanup */
#define _window(obj)      (muiRenderInfo(obj)->mri_Window)            /* valid between MUIM_Show/Hide */
#define _rp(obj)          (muiRenderInfo(obj)->mri_RastPort)          /* valid between MUIM_Show/Hide */
#define _left(obj)        (muiAreaData(obj)->mad_Box.Left)            /* valid during MUIM_Draw */
#define _top(obj)         (muiAreaData(obj)->mad_Box.Top)             /* valid during MUIM_Draw */
#define _width(obj)       (muiAreaData(obj)->mad_Box.Width)           /* valid during MUIM_Draw */
#define _height(obj)      (muiAreaData(obj)->mad_Box.Height)          /* valid during MUIM_Draw */
#define _right(obj)       (_left(obj)+_width(obj)-1)                  /* valid during MUIM_Draw */
#define _bottom(obj)      (_top(obj)+_height(obj)-1)                  /* valid during MUIM_Draw */
#define _addleft(obj)     (muiAreaData(obj)->mad_addleft  )           /* valid during MUIM_Draw */
#define _addtop(obj)      (muiAreaData(obj)->mad_addtop   )           /* valid during MUIM_Draw */
#define _subwidth(obj)    (muiAreaData(obj)->mad_subwidth )           /* valid during MUIM_Draw */
#define _subheight(obj)   (muiAreaData(obj)->mad_subheight)           /* valid during MUIM_Draw */
#define _text(obj)        (muiTextdata(obj)->mtd_text)
#define _encoding(obj)    (muiTextdata(obj)->mtd_encoding)
#define _mleft(obj)       (_left(obj)+_addleft(obj))                  /* valid during MUIM_Draw */
#define _mtop(obj)        (_top(obj)+_addtop(obj))                    /* valid during MUIM_Draw */
#define _mwidth(obj)      (_width(obj)-_subwidth(obj))                /* valid during MUIM_Draw */
#define _mheight(obj)     (_height(obj)-_subheight(obj))              /* valid during MUIM_Draw */
#define _mright(obj)      (_mleft(obj)+_mwidth(obj)-1)                /* valid during MUIM_Draw */
#define _mbottom(obj)     (_mtop(obj)+_mheight(obj)-1)                /* valid during MUIM_Draw */
#define _font(obj)        (muiAreaData(obj)->mad_Font)                /* valid between MUIM_Setup/Cleanup */
#define _minwidth(obj)    (muiAreaData(obj)->mad_MinMax.MinWidth)     /* valid between MUIM_Show/Hide */
#define _minheight(obj)   (muiAreaData(obj)->mad_MinMax.MinHeight)    /* valid between MUIM_Show/Hide */
#define _maxwidth(obj)    (muiAreaData(obj)->mad_MinMax.MaxWidth)     /* valid between MUIM_Show/Hide */
#define _maxheight(obj)   (muiAreaData(obj)->mad_MinMax.MaxHeight)    /* valid between MUIM_Show/Hide */
#define _defwidth(obj)    (muiAreaData(obj)->mad_MinMax.DefWidth)     /* valid between MUIM_Show/Hide */
#define _defheight(obj)   (muiAreaData(obj)->mad_MinMax.DefHeight)    /* valid between MUIM_Show/Hide */
#define _flags(obj)       (muiAreaData(obj)->mad_Flags)

#endif

/* MUI_CustomClass returned by MUI_CreateCustomClass() */

struct MUI_CustomClass
{
	APTR mcc_UserData;                  /* use for whatever you want */

	struct Library *mcc_UtilityBase;    /* MUI has opened these libraries */
	struct Library *mcc_DOSBase;        /* for you automatically. You can */
	struct Library *mcc_GfxBase;        /* use them or decide to open     */
	struct Library *mcc_IntuitionBase;  /* your libraries yourself.       */

	struct IClass *mcc_Super;           /* pointer to super class   */
	struct IClass *mcc_Class;           /* pointer to the new class */

	/* ... private data follows ... */
};


/* alpha data structure used by MUI text engine to */
/* display embedded raw ARGB image data */

struct MUI_AlphaData
{
	LONG width;
	LONG height;
	LONG dummy[2]; // 16-byte align for data
	ULONG data[0];
};

/* Textinput.mcc */
#ifndef TEXTINPUT_MCC_H
#define TEXTINPUT_MCC_H
#define MUIC_Textinput "Textinput.mcc"
#define TextinputObject MUI_NewObject(MUIC_Textinput
#define MUIC_Textinputscroll "Textinputscroll.mcc"
#define TextinputscrollObject MUI_NewObject(MUIC_Textinputscroll
#define MCC_TI_TAGBASE ((TAG_USER)|((1307<<16)+0x712))
#define MCC_TI_ID(x) (MCC_TI_TAGBASE+(x))
#define MCC_Textinput_Version 29
#define MCC_Textinput_Revision 1
#define MUIM_Textinput_ExternalEdit MCC_TI_ID(1)        /* V1 */
#define MUIM_Textinput_SaveToFile MCC_TI_ID(5)          /* V1 */
#define MUIM_Textinput_LoadFromFile MCC_TI_ID(6)        /* V1 */
#define MUIM_Textinput_DoRevert MCC_TI_ID(8)            /* V1 */
#define MUIM_Textinput_DoDelLine MCC_TI_ID(9)           /* V1 */
#define MUIM_Textinput_DoMarkStart MCC_TI_ID(10)        /* V1 */
#define MUIM_Textinput_DoMarkAll MCC_TI_ID(11)          /* V1 */
#define MUIM_Textinput_DoCut MCC_TI_ID(12)              /* V1 */
#define MUIM_Textinput_DoCopy MCC_TI_ID(13)             /* V1 */
#define MUIM_Textinput_DoPaste MCC_TI_ID(14)            /* V1 */
#define MUIM_Textinput_AppendText MCC_TI_ID(15)         /* V1 */
#define MUIM_Textinput_DoToggleWordwrap MCC_TI_ID(19)   /* V1 */
#define MUIM_Textinput_Acknowledge MCC_TI_ID(20)        /* V1 */
#define MUIM_Textinput_TranslateEvent MCC_TI_ID(21)     /* V1 */
#define MUIM_Textinput_InsertText MCC_TI_ID(22)         /* V1 */
#define MUIM_Textinput_DoLeft MCC_TI_ID(23)             /* V1 */
#define MUIM_Textinput_DoRight MCC_TI_ID(24)            /* V1 */
#define MUIM_Textinput_DoUp MCC_TI_ID(25)               /* V1 */
#define MUIM_Textinput_DoDown MCC_TI_ID(26)             /* V1 */
#define MUIM_Textinput_DoLineStart MCC_TI_ID(27)        /* V1 */
#define MUIM_Textinput_DoLineEnd MCC_TI_ID(28)          /* V1 */
#define MUIM_Textinput_DoTop MCC_TI_ID(29)              /* V1 */
#define MUIM_Textinput_DoBottom MCC_TI_ID(30)           /* V1 */
#define MUIM_Textinput_DoPageUp MCC_TI_ID(31)           /* V1 */
#define MUIM_Textinput_DoPageDown MCC_TI_ID(32)         /* V1 */
#define MUIM_Textinput_DoPopup MCC_TI_ID(33)            /* V1 */
#define MUIM_Textinput_DoPrevWord MCC_TI_ID(34)         /* V1 */
#define MUIM_Textinput_DoNextWord MCC_TI_ID(35)         /* V1 */
#define MUIM_Textinput_DoDel MCC_TI_ID(36)              /* V1 */
#define MUIM_Textinput_DoDelEOL MCC_TI_ID(37)           /* V1 */
#define MUIM_Textinput_DoBS MCC_TI_ID(38)               /* V1 */
#define MUIM_Textinput_DoBSSOL MCC_TI_ID(39)            /* V1 */
#define MUIM_Textinput_DoubleClick MCC_TI_ID(42)        /* V1 */
#define MUIM_Textinput_DoBSWord MCC_TI_ID(43)           /* V1 */
#define MUIM_Textinput_DoDelWord MCC_TI_ID(44)          /* V1 */
#define MUIM_Textinput_DoInsertFile MCC_TI_ID(45)       /* V1 */
#define MUIM_Textinput_InsertFromFile MCC_TI_ID(46)     /* V1 */
#define MUIM_Textinput_HandleChar MCC_TI_ID(47)         /* V14 */
#define MUIM_Textinput_HandleURL MCC_TI_ID(48)          /* V16 */
#define MUIM_Textinput_DoToggleCase MCC_TI_ID(51)       /* V21 */
#define MUIM_Textinput_DoToggleCaseEOW MCC_TI_ID(52)    /* V21 */
#define MUIM_Textinput_DoIncrementDec MCC_TI_ID(53)     /* V21 */
#define MUIM_Textinput_DoDecrementDec MCC_TI_ID(54)     /* V21 */
#define MUIM_Textinput_DoUndo MCC_TI_ID(56)             /* V21 */
#define MUIM_Textinput_DoRedo MCC_TI_ID(57)             /* V21 */
#define MUIM_Textinput_DoTab MCC_TI_ID(58)              /* V22 */
#define MUIM_Textinput_DoNextGadget MCC_TI_ID(59)       /* V22 */
#define MUIM_Textinput_DoSetBookmark1 MCC_TI_ID(60)     /* V22 */
#define MUIM_Textinput_DoSetBookmark2 MCC_TI_ID(61)     /* V22 */
#define MUIM_Textinput_DoSetBookmark3 MCC_TI_ID(62)     /* V22 */
#define MUIM_Textinput_DoGotoBookmark1 MCC_TI_ID(63)    /* V22 */
#define MUIM_Textinput_DoGotoBookmark2 MCC_TI_ID(64)    /* V22 */
#define MUIM_Textinput_DoGotoBookmark3 MCC_TI_ID(65)    /* V22 */
#define MUIM_Textinput_DoCutLine MCC_TI_ID(66)          /* V22 */
#define MUIM_Textinput_DoCopyCut MCC_TI_ID(67)          /* V29 */
struct MUIP_Textinput_ExternalEdit { ULONG MethodID; };
struct MUIP_Textinputscroll_Inform { ULONG MethodID; ULONG xo; ULONG yo; ULONG xs; ULONG ys; ULONG xv; ULONG yv; ULONG noedit; };
struct MUIP_Textinputmcp_GrabCols  { ULONG MethodID; ULONG notall; };
struct MUIP_Textinput_Blink { ULONG MethodID; };
struct MUIP_Textinput_SaveToFile { ULONG MethodID; STRPTR filename; };
struct MUIP_Textinput_LoadFromFile { ULONG MethodID; STRPTR filename; };
struct MUIP_Textinput_ExternalEditDone { ULONG MethodID; ULONG changed; };
struct MUIP_Textinput_DoRevert { ULONG MethodID; };
struct MUIP_Textinput_DoDelLine { ULONG MethodID; };
struct MUIP_Textinput_DoCutLine { ULONG MethodID; };
struct MUIP_Textinput_DoMarkStart { ULONG MethodID; };
struct MUIP_Textinput_DoMarkAll { ULONG MethodID; };
struct MUIP_Textinput_DoCut { ULONG MethodID; };
struct MUIP_Textinput_DoCopyCut { ULONG MethodID; };
struct MUIP_Textinput_DoCopy { ULONG MethodID; };
struct MUIP_Textinput_DoPaste { ULONG MethodID; };
struct MUIP_Textinput_AppendText { ULONG MethodID; STRPTR text; LONG len; };
struct MUIP_Textinputmcp_LAct { ULONG MethodID; ULONG which; };
struct MUIP_Textinputmcp_LCopy { ULONG MethodID; };
struct MUIP_Textinputmcp_LAdd { ULONG MethodID; };
struct MUIP_Textinput_DoToggleWordwrap { ULONG MethodID; };
struct MUIP_Textinput_Acknowledge { ULONG MethodID; STRPTR contents; };
struct MUIP_Textinput_TranslateEvent { ULONG MethodID; struct InputEvent *ie; STRPTR mappedstring; ULONG *mappedlen; };
struct MUIP_Textinput_InsertText { ULONG MethodID; STRPTR text; LONG len; };
struct MUIP_Textinput_DoLeft { ULONG MethodID; };
struct MUIP_Textinput_DoRight { ULONG MethodID; };
struct MUIP_Textinput_DoUp { ULONG MethodID; };
struct MUIP_Textinput_DoDown { ULONG MethodID; };
struct MUIP_Textinput_DoLineStart { ULONG MethodID; };
struct MUIP_Textinput_DoLineEnd { ULONG MethodID; };
struct MUIP_Textinput_DoTop { ULONG MethodID; };
struct MUIP_Textinput_DoBottom { ULONG MethodID; };
struct MUIP_Textinput_DoPageUp { ULONG MethodID; };
struct MUIP_Textinput_DoPageDown { ULONG MethodID; };
struct MUIP_Textinput_DoPopup { ULONG MethodID; };
struct MUIP_Textinput_DoPrevWord { ULONG MethodID; };
struct MUIP_Textinput_DoNextWord { ULONG MethodID; };
struct MUIP_Textinput_DoDel { ULONG MethodID; };
struct MUIP_Textinput_DoDelEOL { ULONG MethodID; };
struct MUIP_Textinput_DoBS { ULONG MethodID; };
struct MUIP_Textinput_DoBSSOL { ULONG MethodID; };
struct MUIP_Textinput_DoubleClick { ULONG MethodID; ULONG xp; ULONG yp; ULONG cnt; };
struct MUIP_Textinput_DoDelWord { ULONG MethodID; };
struct MUIP_Textinput_DoBSWord { ULONG MethodID; };
struct MUIP_Textinput_DoInsertFile { ULONG MethodID; };
struct MUIP_Textinput_InsertFromFile { ULONG MethodID; STRPTR filename; };
struct MUIP_Textinput_HandleChar { ULONG MethodID; ULONG ch; ULONG quiet; };
struct MUIP_Textinput_HandleURL { ULONG MethodID; STRPTR url; };
struct MUIP_Textinput_HandleRexxSignal { ULONG MethodID; };
struct MUIP_Textinput_HandleMisspell { ULONG MethodID; STRPTR word; STRPTR pos; STRPTR correction; };
struct MUIP_Textinput_DoToggleCase { ULONG MethodID; };
struct MUIP_Textinput_DoToggleCaseEOW { ULONG MethodID; };
struct MUIP_Textinput_DoIncrementDec { ULONG MethodID; };
struct MUIP_Textinput_DoDecrementDec { ULONG MethodID; };
struct MUIP_Textinputmcp_DefaultKeys { ULONG MethodID; };
struct MUIP_Textinput_DoUndo { ULONG MethodID; };
struct MUIP_Textinput_DoRedo { ULONG MethodID; };
struct MUIP_Textinput_DoTab { ULONG MethodID; };
struct MUIP_Textinput_DoNextGadget { ULONG MethodID; };
struct MUIP_Textinput_DoSetBookmark1 { ULONG MethodID; };
struct MUIP_Textinput_DoSetBookmark2 { ULONG MethodID; };
struct MUIP_Textinput_DoSetBookmark3 { ULONG MethodID; };
struct MUIP_Textinput_DoGotoBookmark1 { ULONG MethodID; };
struct MUIP_Textinput_DoGotoBookmark2 { ULONG MethodID; };
struct MUIP_Textinput_DoGotoBookmark3 { ULONG MethodID; };
#define MUIA_Textinput_Multiline MCC_TI_ID(100)             /* V1 i.g BOOL */
#define MUIA_Textinput_MaxLen MCC_TI_ID(101)                /* V1 i.g ULONG */
#define MUIA_Textinput_MaxLines MCC_TI_ID(102)              /* V1 i.g ULONG */
#define MUIA_Textinput_AutoExpand MCC_TI_ID(103)            /* V1 isg BOOL */
#define MUIA_Textinput_Contents MCC_TI_ID(104)              /* V1 isg STRPTR */
#define MUIA_Textinput_Blinkrate MCC_TI_ID(108)             /* V1 isg ULONG */
#define MUIA_Textinput_Cursorstyle MCC_TI_ID(109)           /* V1 isg ULONG */
#define MUIA_Textinput_AdvanceOnCR MCC_TI_ID(110)           /* V1 isg BOOL */
#define MUIA_Textinput_TmpExtension MCC_TI_ID(111)          /* V1 isg STRPTR */
#define MUIA_Textinput_Quiet MCC_TI_ID(112)                 /* V1 .sg BOOL */
#define MUIA_Textinput_Acknowledge MCC_TI_ID(113)           /* V1 ..g STRPTR */
#define MUIA_Textinput_Integer MCC_TI_ID(114)               /* V1 isg ULONG */
#define MUIA_Textinput_MinVersion MCC_TI_ID(115)            /* V1 i.. ULONG */
#define MUIA_Textinput_DefaultPopup MCC_TI_ID(117)          /* V1 i.. BOOL */
#define MUIA_Textinput_WordWrap MCC_TI_ID(118)              /* V1 isg ULONG */
#define MUIA_Textinput_IsNumeric MCC_TI_ID(119)             /* V1 isg BOOL */
#define MUIA_Textinput_MinVal MCC_TI_ID(120)                /* V1 isg ULONG */
#define MUIA_Textinput_MaxVal MCC_TI_ID(121)                /* V1 isg ULONG */
#define MUIA_Textinput_AcceptChars MCC_TI_ID(122)           /* V1 isg STRPTR */
#define MUIA_Textinput_RejectChars MCC_TI_ID(123)           /* V1 isg STRPTR */
#define MUIA_Textinput_Changed MCC_TI_ID(124)               /* V1 .sg BOOL */
#define MUIA_Textinput_AttachedList MCC_TI_ID(125)          /* V1 isg Object */
#define MUIA_Textinput_RemainActive MCC_TI_ID(126)          /* V1 isg BOOL */
#define MUIA_Textinput_CursorPos MCC_TI_ID(127)             /* V1 .sg ULONG */
#define MUIA_Textinput_Secret MCC_TI_ID(128)                /* V1 isg BOOL */
#define MUIA_Textinput_Lines MCC_TI_ID(129)                 /* V1 ..g ULONG */
#define MUIA_Textinput_Editable MCC_TI_ID(130)              /* V1 isg BOOL */
#define MUIA_Textinputscroll_UseWinBorder MCC_TI_ID(131)    /* V1 i.. BOOL */
#define MUIA_Textinput_IsOld MCC_TI_ID(132)                 /* V1 isg BOOL */
#define MUIA_Textinput_MarkStart MCC_TI_ID(133)             /* V13 isg ULONG */
#define MUIA_Textinput_MarkEnd MCC_TI_ID(134)               /* V13 isg ULONG */
#define MUIA_Textinputscroll_VertScrollerOnly MCC_TI_ID(135)/* V14 i.. BOOL */
#define MUIA_Textinput_NoInput MCC_TI_ID(136)               /* V15 i.g BOOL */
#define MUIA_Textinput_SetMin MCC_TI_ID(137)                /* V15 isg BOOL */
#define MUIA_Textinput_SetMax MCC_TI_ID(138)                /* V15 isg BOOL */
#define MUIA_Textinput_SetVMax MCC_TI_ID(139)               /* V15 isg BOOL */
#define MUIA_Textinput_Styles MCC_TI_ID(140)                /* V15 isg ULONG */
#define MUIA_Textinput_PreParse MCC_TI_ID(141)              /* V18 isg STRPTR */
#define MUIA_Textinput_Format MCC_TI_ID(142)                /* V19 i.g ULONG */
#define MUIA_Textinput_SetVMin MCC_TI_ID(143)               /* V20 isg BOOL */
#define MUIA_Textinput_HandleURLHook MCC_TI_ID(144)         /* V22 isg struct Hook * */
#define MUIA_Textinput_Tabs MCC_TI_ID(145)                  /* V22 i** ULONG */
#define MUIA_Textinput_TabLen MCC_TI_ID(146)                /* V22 i** ULONG */
#define MUIA_Textinput_Bookmark1 MCC_TI_ID(147)             /* V22 isg ULONG */
#define MUIA_Textinput_Bookmark2 MCC_TI_ID(148)             /* V22 isg ULONG */
#define MUIA_Textinput_Bookmark3 MCC_TI_ID(149)             /* V22 isg ULONG */
#define MUIA_Textinput_CursorSize MCC_TI_ID(150)            /* V22 isg ULONG */
#define MUIA_Textinput_TopLine MCC_TI_ID(151)               /* V22 isg ULONG */
#define MUIA_Textinput_Font MCC_TI_ID(152)                  /* V23 isg ULONG */
#define MUIA_Textinput_SuggestParse MCC_TI_ID(153)          /* V24 isg ULONG */
#define MUIA_Textinput_ProhibitParse MCC_TI_ID(154)         /* V24 isg ULONG */
#define MUIA_Textinput_NoCopy MCC_TI_ID(155)                /* V26 isg ULONG */
#define MUIA_Textinput_MinimumWidth MCC_TI_ID(156)          /* V26 i.g ULONG */
#define MUIA_Textinput_ResetMarkOnCursor MCC_TI_ID(157)     /* V29 isg BOOL */
#define MUIA_Textinput_NoExtraSpacing MCC_TI_ID(158)        /* V29 isg BOOL */
#define MUIA_Textinputscroll_VertBar MCC_TI_ID(159)         /* V29 i   APTR */
#define MUIA_Textinputscroll_HorizBar MCC_TI_ID(160)        /* V29 i   APTR */
#define MUIV_Textinput_ParseB_URL      0
#define MUIV_Textinput_ParseB_Misspell 1
#define MUIV_Textinput_ParseF_URL      (1<<MUIV_Textinput_ParseB_URL)
#define MUIV_Textinput_ParseF_Misspell (1<<MUIV_Textinput_ParseB_Misspell)
#define MUIV_Textinput_Tabs_Ignore  0
#define MUIV_Textinput_Tabs_Spaces  1
#define MUIV_Textinput_Tabs_Disk    2
#define MUIV_Textinput_Tabs_Tabs    3
#define MUIV_Textinput_NoMark ((ULONG)~0)
#define MUIV_Textinput_Styles_None  0
#define MUIV_Textinput_Styles_MUI   1
#define MUIV_Textinput_Styles_IRC   2
#define MUIV_Textinput_Styles_Email 3
#define MUIV_Textinput_Styles_HTML  4
#define MUIV_Textinput_Format_Left      0
#define MUIV_Textinput_Format_Center    1
#define MUIV_Textinput_Format_Centre    1
#define MUIV_Textinput_Format_Right     2
#define MUIV_Textinput_Font_Normal 0
#define MUIV_Textinput_Font_Fixed  1
#endif

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* MUI_H */

#endif /* __AROS__ */
