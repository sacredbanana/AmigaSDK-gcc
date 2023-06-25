#ifndef CLASSES_POPUPMENU_H
#define CLASSES_POPUPMENU_H
/*
**    $VER: popupmenu.h 54.16 (22.08.2022)
**
**    popupmenu.class definitions &
**    popupmenuitem.class definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifndef   INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

#ifndef   INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

/****************************************************************************/

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

/* popupmenu.class attributes */
#define POPUPMENU_Dummy  (REACTION_Dummy  + 0x25900)
#define PMA_AddItem      (POPUPMENU_Dummy + 1)  /* add item to menu (Object *) */
#define PMA_Left         (POPUPMENU_Dummy + 2)  /* horizontal position of the menu (LONG) */
#define PMA_RelRight     (POPUPMENU_Dummy + 3)  /* horizontal position of the menu, relative to its right edge (LONG) */
#define PMA_Top          (POPUPMENU_Dummy + 4)  /* vertical position of the menu (LONG) */
#define PMA_RelBottom    (POPUPMENU_Dummy + 5)  /* vertical position of the menu, relative to its top edge (LONG) */
#define PMA_PullDown     (POPUPMENU_Dummy + 6)  /* turn menu into a pulldown menu (BOOL) */
#define PMA_MenuHandler  (POPUPMENU_Dummy + 7)  /* menu handler (struct Hook *) */
#define PMA_CenterScreen (POPUPMENU_Dummy + 8)  /* center menu on screen (BOOL) */
#define PMA_UseLMB       (POPUPMENU_Dummy + 9)  /* reverses the function of the mouse buttons (BOOL) */
#define PMA_LocaleHook   (POPUPMENU_Dummy + 10) /* locale hook (struct Hook *) */
#define PMA_Font         (POPUPMENU_Dummy + 11) /* font to use for this menu (struct TextFont *) */
#define PMA_HintBox      (POPUPMENU_Dummy + 12) /* Make the menu dissappear when the mouse is moved. (BOOL) */
#define PMA_AutoPullDown (POPUPMENU_Dummy + 13) /* Set this to TRUE if you want a pulldown menu opened automatically
                                                 * when the user presses RMB (BOOL) */
#define PMA_Private1     (POPUPMENU_Dummy + 14)

/* POPUPMENU_MakeIDListA() attributes */
#define PMA_IncludeID    (POPUPMENU_Dummy + 16)
#define PMA_ExcludeID    (POPUPMENU_Dummy + 17)
#define PMA_InverseID    (POPUPMENU_Dummy + 18)
#define PMA_ReflectID    (POPUPMENU_Dummy + 19)

struct pmLocaleHookMsg
{
    ULONG LocaleID;
};

/* popupmenu.class methods */
#define PM_OPEN        (0x571000)  /* open menu (struct pmOpen *) */
#define PM_HANDLEINPUT (0x571001)  /* handle keyboard shortcuts (struct pmHandleInput *) */
#define PM_LAYOUT      (0x571002)  /* layout menus (struct pmLayout *) */
#define PM_INSERT      (0x571003)  /* insert menuitem (struct pmInsert *) */
#define PM_CHANGESTATE (0x571005)  /* change selection of multiple items (struct pmChangeState *) */
#define PM_FINDITEM    (0x571006)  /* find item (struct pmFindItem *) */

struct pmFindItem
{
    ULONG MethodID;
    ULONG ID;
};

struct pmChangeState
{
    ULONG MethodID;
    APTR  IDList;
    ULONG Action;
};

#define PMCS_SELECT   2 /*   select items (PM_CHANGESTATE) */
#define PMCS_DESELECT 3 /* deselect items (PM_CHANGESTATE) */

struct pmHandleInput
{
    ULONG                MethodID;
    struct IntuiMessage *IMsg;
};

struct pmInsert
{
    ULONG   MethodID;
    Object *object;   /* "Object *Object;" caused problems with C++ */
    Object *Pred;
};

struct pmOpen
{
    ULONG          MethodID;
    struct Window *Window;
};

struct pmLayout
{
    ULONG           MethodID;
    struct Window  *Window;
    struct TagItem *AttrList; /* unused, set to NULL */
};

/* popupmenuitem.class attributes */
#define PMIA_Title             (POPUPMENU_Dummy + 50) /* Pointer to the menu text you want (STRPTR) */
#define PMIA_UserData          (POPUPMENU_Dummy + 51) /* for your own use (APTR) */
#define PMIA_ID                (POPUPMENU_Dummy + 52) /* the item ID (ULONG) */
#define PMIA_SubMenu           (POPUPMENU_Dummy + 53) /* the submenu for this item (Object *) */
#define PMIA_ReadOnly          (POPUPMENU_Dummy + 54) /* item is not selectable (BOOL) */
#define PMIA_FillPen           (POPUPMENU_Dummy + 55) /* use FILLPEN to draw item title (BOOL) */
#define PMIA_CheckIt           (POPUPMENU_Dummy + 56) /* leave some space for a checkmark (BOOL) */
#define PMIA_Checked           (POPUPMENU_Dummy + 57) /* item is checked (BOOL) */
#define PMIA_Italic            (POPUPMENU_Dummy + 58) /* draw title in italic (BOOL) */
#define PMIA_Bold              (POPUPMENU_Dummy + 59) /* dto. bold */
#define PMIA_Underlined        (POPUPMENU_Dummy + 60) /* dto. underlined */
#define PMIA_Disabled          (POPUPMENU_Dummy + 61) /* item is disabled (BOOL) */
#define PMIA_Image             (POPUPMENU_Dummy + 62) /* image to be rendered under the title (struct Image *) */
#define PMIA_SelectImage       (POPUPMENU_Dummy + 63) /* dto. selected image */
#define PMIA_Icon              (POPUPMENU_Dummy + 64) /* image to be rendered to the left of the title (struct Image *) */
#define PMIA_SelectIcon        (POPUPMENU_Dummy + 65) /* dto. selected image */
#define PMIA_TextPen           (POPUPMENU_Dummy + 66) /* use TEXTPEN to draw title (BOOL) */
#define PMIA_CommKey           (POPUPMENU_Dummy + 67) /* keyboard shortcut for this item (STRPTR) */
#define PMIA_SubMenuConstruct  (POPUPMENU_Dummy + 68) /* for implementation of dynamic submenus (struct Hook *) */
#define PMIA_SubMenuDestruct   (POPUPMENU_Dummy + 69) /* dto. */
#define PMIA_Hidden            (POPUPMENU_Dummy + 70) /* item can't be drawn (BOOL) */
#define PMIA_TitleID           (POPUPMENU_Dummy + 71) /* locale ID of item title */
#define PMIA_Object            (POPUPMENU_Dummy + 72) /* BOOPSI image object to render item (Object *) */
#define PMIA_Members           (POPUPMENU_Dummy + 73) /* turns item into a group (Object *) */
#define PMIA_LayoutMode        (POPUPMENU_Dummy + 74) /* layout mode of this group, see definitions below (ULONG) */
#define PMIA_Toggle            (POPUPMENU_Dummy + 75) /* set to FALSE for MX items (BOOL) */
#define PMIA_ExcludeList       (POPUPMENU_Dummy + 76) /* list of items to (un)select when this item gets selected (APTR) */
#define PMIA_SharedExcludeList (POPUPMENU_Dummy + 77) /* don't free exclude list when item gets disposed (BOOL) */
#define PMIA_ShinePen          (POPUPMENU_Dummy + 78) /* use SHINEPEN to draw title (BOOL) */
#define PMIA_ShadowPen         (POPUPMENU_Dummy + 79) /* dto. SHADOWPEN */
#define PMIA_WideTitleBar      (POPUPMENU_Dummy + 80) /* draw a horizontal separator (BOOL) */
#define PMIA_Shadowed          (POPUPMENU_Dummy + 81) /* draw a shadowed title (BOOL) */
#define PMIA_Center            (POPUPMENU_Dummy + 82) /* center title (BOOL) */
#define PMIA_ColourBox         (POPUPMENU_Dummy + 83) /* draws a filled rectangle in using the specified pen (ULONG) */
#define PMIA_ColorBox          PMIA_ColourBox         /* for Americans ;) */

/* popupmenuitem.class methods */
#define PM_CHECKABORT (0x571004) /* check if the user released the button (struct pmCheckAbort *) */

struct pmCheckAbort
{
    ULONG MethodID;
    APTR  Handle;
};

/* possible values for PMIA_LayoutMode */
#define PMLM_None       0 /* Normal item      */
#define PMLM_Horizontal 1 /* Horizontal group */
#define PMLM_Vertical   2 /* Vertical group   */
#define PMLM_Table      3 /* Table group      */

#ifndef NO_POPUPMENUCLASS_MACROS

/****************************************************************************/
#if defined (__amigaos4__) && !defined(__USE_INLINE__)
/****************************************************************************/
#define PMMENU(t)   IIntuition->NewObject( IPopupMenu->POPUPMENU_GetClass(), NULL,\
                        PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL,\
                            PMIA_Title, (ULONG) t,\
                            PMIA_ReadOnly, TRUE,\
                            PMIA_ShinePen, TRUE,\
                            PMIA_Shadowed, TRUE,\
                            PMIA_Center, TRUE,\
                        TAG_DONE ),\
                        PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL,\
                            PMIA_WideTitleBar, TRUE,\
                        TAG_DONE )
#define PMMENUID(t) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetClass(), NULL,\
                        PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL,\
                            PMIA_TitleID, (ULONG) t,\
                            PMIA_ReadOnly, TRUE,\
                            PMIA_ShinePen, TRUE,\
                            PMIA_Shadowed, TRUE,\
                            PMIA_Center, TRUE,\
                        TAG_DONE ),\
                        PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL,\
                            PMIA_WideTitleBar, TRUE,\
                        TAG_DONE )
#define PMSUBMENU(t)    PMIA_SubMenu, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetClass(), NULL,\
                            PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL,\
                                PMIA_Title, (ULONG) t,\
                                PMIA_ReadOnly, TRUE,\
                                PMIA_ShinePen, TRUE,\
                            TAG_DONE ),\
                            PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL,\
                                PMIA_WideTitleBar, TRUE,\
                            TAG_DONE )
#define PMSIMPLESUB     PMIA_SubMenu, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetClass(), NULL
#define PMITEM(t)       PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL, PMIA_Title, (ULONG) t
#define PMITEMID(t)     PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL, PMIA_TitleID, (ULONG) t
#define PMBAR()         PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL, PMIA_Title, ~0
#define PMMENUTITLE(t)  PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL,\
                            PMIA_Title, (ULONG)t, PMIA_ReadOnly, TRUE, PMIA_ShinePen, TRUE,\
                            PMIA_Shadowed, TRUE, PMIA_Center, TRUE,\
                        TAG_DONE ),\
                        PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL,\
                            PMIA_WideTitleBar, TRUE,\
                        TAG_DONE )
#define PMHORIZGROUP    PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL, PMIA_LayoutMode, PMLM_Horizontal
#define PMVERTGROUP     PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL, PMIA_LayoutMode, PMLM_Vertical
#define PMMEMBERS       PMIA_Members, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetClass(), NULL
#define PMCHECKITEM(t,id)   PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL,\
                                PMIA_Title, (ULONG) t,  PMIA_ID, id, PMIA_CheckIt, TRUE
#define PMMXITEM(t,id)  PMA_AddItem, (ULONG) IIntuition->NewObject( IPopupMenu->POPUPMENU_GetItemClass(), NULL,\
                            PMIA_Title, (ULONG) t,  PMIA_ID, id, PMIA_CheckIt, TRUE, PMIA_Toggle, FALSE
#define PMEND           TAG_DONE )

/****************************************************************************/
#else /* !__amigaos4__ || __USE_INLINE__ */
/****************************************************************************/
#define PMMENU(t)   NewObject( POPUPMENU_GetClass(), NULL,\
                        PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL,\
                            PMIA_Title, (ULONG) t,\
                            PMIA_ReadOnly, TRUE,\
                            PMIA_ShinePen, TRUE,\
                            PMIA_Shadowed, TRUE,\
                            PMIA_Center, TRUE,\
                        TAG_DONE ),\
                        PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL,\
                            PMIA_WideTitleBar, TRUE,\
                        TAG_DONE )
#define PMMENUID(t) NewObject( POPUPMENU_GetClass(), NULL,\
                        PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL,\
                            PMIA_TitleID, (ULONG) t,\
                            PMIA_ReadOnly, TRUE,\
                            PMIA_ShinePen, TRUE,\
                            PMIA_Shadowed, TRUE,\
                            PMIA_Center, TRUE,\
                        TAG_DONE ),\
                        PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL,\
                            PMIA_WideTitleBar, TRUE,\
                        TAG_DONE )
#define PMSUBMENU(t)    PMIA_SubMenu, (ULONG) NewObject( POPUPMENU_GetClass(), NULL,\
                            PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL,\
                                PMIA_Title, (ULONG) t,\
                                PMIA_ReadOnly, TRUE,\
                                PMIA_ShinePen, TRUE,\
                            TAG_DONE ),\
                            PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL,\
                                PMIA_WideTitleBar, TRUE,\
                            TAG_DONE )
#define PMSIMPLESUB     PMIA_SubMenu, (ULONG) NewObject( POPUPMENU_GetClass(), NULL
#define PMITEM(t)       PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL, PMIA_Title, (ULONG) t
#define PMITEMID(t)     PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL, PMIA_TitleID, (ULONG) t
#define PMBAR()         PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL, PMIA_Title, ~0
#define PMMENUTITLE(t)  PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL,\
                            PMIA_Title, (ULONG)t, PMIA_ReadOnly, TRUE, PMIA_ShinePen, TRUE,\
                            PMIA_Shadowed, TRUE, PMIA_Center, TRUE,\
                        TAG_DONE ),\
                        PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL,\
                            PMIA_WideTitleBar, TRUE,\
                        TAG_DONE )
#define PMHORIZGROUP    PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL, PMIA_LayoutMode, PMLM_Horizontal
#define PMVERTGROUP     PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL, PMIA_LayoutMode, PMLM_Vertical
#define PMMEMBERS       PMIA_Members, (ULONG) NewObject( POPUPMENU_GetClass(), NULL
#define PMCHECKITEM(t,id)   PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL,\
                                PMIA_Title, (ULONG) t,  PMIA_ID, id, PMIA_CheckIt, TRUE
#define PMMXITEM(t,id)  PMA_AddItem, (ULONG) NewObject( POPUPMENU_GetItemClass(), NULL,\
                            PMIA_Title, (ULONG) t,  PMIA_ID, id, PMIA_CheckIt, TRUE, PMIA_Toggle, FALSE
#define PMEND           TAG_DONE )

/***************************************************************************/
#endif /* __amigaos4__ && !__USE_INLINE__ */

#endif /* NO_POPUPMENUCLASS_MACROS */

/****************************************************************************/

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

#endif /* CLASSES_POPUPMENU_H */
