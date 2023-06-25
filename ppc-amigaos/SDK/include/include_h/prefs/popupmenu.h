#ifndef PREFS_POPUPMENU_H
#define PREFS_POPUPMENU_H
/*
**    $VER: popupmenu.h 54.16 (22.08.2022)
**
**    File format for popupmenu preferences
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

#define ID_PMNU MAKE_ID('P','M','N','U')

struct PopupMenuPrefs
{
    UBYTE pmp_Flags;            /* Enable shadows, transparency, etc. */
    UBYTE pmp_SubMenuDelay;     /* Delay before opening submenus      */
    UBYTE pmp_Animation;        /* Animation, see below for defines   */
                                /* (Only one animation effect implemented currently) */
    UBYTE pmp_PulldownPos;      /* Where to show pulldownmenus        */
    BOOL  pmp_Sticky;           /* Use 'sticky' mode                  */
    BOOL  pmp_SameHeight;       /* Try to give all items same height  */
                                /* (not used currently)               */
    UBYTE pmp_MenuBorder;       /* Menu border                        */
    UBYTE pmp_SelItemBorder;    /* Border around selected item        */
    UBYTE pmp_SeparatorBar;     /* Separator bar style                */
    UBYTE pmp_MenuTitles;       /* Flags for drawing menu texts       */
    UBYTE pmp_MenuItems;        /* Flags for drawing menu item texts  */
    UBYTE pmp_XOffset;
    UBYTE pmp_YOffset;
    UBYTE pmp_XSpace;
    UBYTE pmp_YSpace;
    UBYTE pmp_Intermediate;
    BYTE  pmp_TextDisplace;
    BYTE  pmp_ShadowR;
    BYTE  pmp_ShadowG;
    BYTE  pmp_ShadowB;
    BYTE  pmp_TransparencyR;    /* not used currently      */
    BYTE  pmp_TransparencyG;    /* not used currently      */
    BYTE  pmp_TransparencyB;    /* not used currently      */
    UBYTE pmp_TransparencyBlur; /* not used currently      */
    UBYTE pmp_AnimationSpeed;   /* not used currently      */
    UBYTE pmp_IntArrow;         /* Use internal arrow image, instead of SYSICLASS one */
    UBYTE pmp_Reserved[15];     /* Reserved for future use */
};

#define PMP_FLAGS_SHADOWS       0x01
#define PMP_FLAGS_TRANSPARENCY  0x02
#define PMP_FLAGS_INTARROW      0x04
   
#define PMP_ANIM_NONE       0
#define PMP_ANIM_ZOOM       1
#define PMP_ANIM_FADE       2
#define PMP_ANIM_EXPLODE    3

#define PMP_PD_SCREENBAR    0
#define PMP_PD_WINDOWBAR    1
#define PMP_PD_MOUSE        2 /* Show as popup menu */

#define PMP_TITLE_NORMAL    0x00
#define PMP_TITLE_ITALIC    0x01
#define PMP_TITLE_BOLD      0x02
#define PMP_TITLE_UNDERLINE 0x04
#define PMP_TITLE_SHADOW    0x08
#define PMP_TITLE_EMBOSS    0x10
#define PMP_TITLE_OUTLINE   0x20
#define PMP_TITLE_CENTER    0x40

#define PMP_TEXT_NORMAL     0x00
#define PMP_TEXT_ITALIC     0x01
#define PMP_TEXT_BOLD       0x02
#define PMP_TEXT_UNDERLINE  0x04
#define PMP_TEXT_SHADOW     0x08
#define PMP_TEXT_EMBOSS     0x10
#define PMP_TEXT_OUTLINE    0x20
#define PMP_TEXT_CENTER     0x40

#define PMP_MENUBORDER_THIN     0
#define PMP_MENUBORDER_MM       1 /* Smooth */
#define PMP_MENUBORDER_THICK    2
#define PMP_MENUBORDER_RIDGE    3
#define PMP_MENUBORDER_DROPBOX  4 /* Wide Ridge */
#define PMP_MENUBORDER_OLDSTYLE 5

#define PMP_SELITEM_NO_BORDER   0
#define PMP_SELITEM_RECESSED    1
#define PMP_SELITEM_RAISED      2

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

#endif /* PREFS_POPUPMENU_H */
