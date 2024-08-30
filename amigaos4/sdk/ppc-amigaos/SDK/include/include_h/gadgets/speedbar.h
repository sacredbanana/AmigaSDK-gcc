#ifndef GADGETS_SPEEDBAR_H
#define GADGETS_SPEEDBAR_H
/*
**    $VER: speedbar.h 54.16 (22.08.2022)
**
**    Definitions for the speedbar.gadget BOOPSI class
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef   INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
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

/*****************************************************************************/

/* Defines for the speedbar node attributes.
 */
#define SBNA_Dummy     (TAG_USER+0x010000)

#define SBNA_Left      (SBNA_Dummy+1)
    /* (WORD) Left offset of button. (OBSOLETE - DON'T USE) */

#define SBNA_Top       (SBNA_Dummy+2)
    /* (WORD) Top offset of button. (OBSOLETE - DON'T USE) */

#define SBNA_Width     (SBNA_Dummy+3)
    /* (WORD) Minimum inner width of button. */

#define SBNA_Height    (SBNA_Dummy+4)
    /* (WORD) Minimum inner height of button. */

#define SBNA_UserData  (SBNA_Dummy+5)
    /* (APTR) User data, have a blast. */

#define SBNA_Enabled   (SBNA_Dummy+6)
    /* (BOOL) Should this button actually be shown? */

#define SBNA_Spacing   (SBNA_Dummy+7)
    /* (WORD) Spacing between this button and the previous one. */

#define SBNA_Highlight (SBNA_Dummy+8)
    /* (UWORD) Highlight mode (see below). */

#define SBNA_Image     (SBNA_Dummy+9)
    /* (struct Image *) Render image pointer. */

#define SBNA_SelImage  (SBNA_Dummy+10)
    /* (struct Image *) Select image pointer. */

#define SBNA_Help      (SBNA_Dummy+11)
    /* (STRPTR) Optional help text message pointer. */

#define SBNA_Toggle    (SBNA_Dummy+12)
    /* (BOOL) Make button a toggle button. */

#define SBNA_Selected  (SBNA_Dummy+13)
    /* (BOOL) Sets state of a toggle button. */

#define SBNA_MXGroup   (SBNA_Dummy+14)
    /* (WORD) Mutual exclusion group ID of button, implies SBNA_Toggle. */

#define SBNA_Disabled  (SBNA_Dummy+15)
    /* (BOOL) Is this button disabled? */

#define SBNA_Text      (SBNA_Dummy+16)
    /* (STRPTR) Label to display below the image. (V50) */

#define SBNA_Spacer    (SBNA_Dummy+17)
    /* (BOOL) Is this button a spacer? (V53) */

#define SBNA_Separator (SBNA_Dummy+18)
    /* (BOOL) Is this button a separator? (V53) */

#define SBNA_HintInfo  (SBNA_Dummy+19)
    /* (STRPTR) Set the hintinfo for this button (V53) */

#define SBNA_ButtonID  (SBNA_Dummy+20)
    /* (UWORD) Button ID of button (V53.13) */

/* Possible highlight modes. */
#define SBH_NONE     0
#define SBH_BACKFILL 1
#define SBH_RECESS   2
#define SBH_IMAGE    3

/*****************************************************************************/

/* Additional attributes defined by the speedbar.gadget class */
#define SPEEDBAR_Dummy        (REACTION_Dummy + 0x13000)

#define SPEEDBAR_Buttons      (SPEEDBAR_Dummy+1)
    /* (struct List *) Button list */

#define SPEEDBAR_Orientation  (SPEEDBAR_Dummy+2)
    /* (UWORD) Horizontal/vertical mode (SBORIENT_HORIZ or SBORIENT_VERT) */

#define SPEEDBAR_Background   (SPEEDBAR_Dummy+3)
    /* (UWORD) Container background color */

#define SPEEDBAR_Window       (SPEEDBAR_Dummy+4)
    /* (struct Window *) Window for titlebar help */

#define SPEEDBAR_StrumBar     (SPEEDBAR_Dummy+5)
    /* (BOOL) Allow strumming of button bar (OBSOLETE - DON'T USE) */

#define SPEEDBAR_OnButton     (SPEEDBAR_Dummy+6)
    /* (WORD) Turn on a button by ID number */

#define SPEEDBAR_OffButton    (SPEEDBAR_Dummy+7)
    /* (WORD) Turn off a button by ID number */

#define SPEEDBAR_ScrollLeft   (SPEEDBAR_Dummy+8)
    /* (WORD) Scroll buttons left */

#define SPEEDBAR_ScrollRight  (SPEEDBAR_Dummy+9)
    /* (WORD) Scroll buttons right */

#define SPEEDBAR_Top          (SPEEDBAR_Dummy+10)
    /* (WORD) Index of first visible button */

#define SPEEDBAR_Visible      (SPEEDBAR_Dummy+11)
    /* (WORD) Number of visible buttons */

#define SPEEDBAR_Total        (SPEEDBAR_Dummy+12)
    /* (WORD) Total number of buttons in list */

#define SPEEDBAR_Help         (SPEEDBAR_Dummy+13)
    /* (STRPTR) Window/Screen help text */

#define SPEEDBAR_BevelStyle   (SPEEDBAR_Dummy+14)
    /* (UWORD) Bevel box style (BVS_DISPLAY, BVS_THIN, BVS_BOX, BVS_NONE) */

#define SPEEDBAR_Selected     (SPEEDBAR_Dummy+15)
    /* (WORD) Last selected speedbar node ID number */

#define SPEEDBAR_SelectedNode (SPEEDBAR_Dummy+16)
    /* (struct Node *) Last selected speedbar node pointer */

#define SPEEDBAR_EvenSize     (SPEEDBAR_Dummy+17)
    /* (BOOL) Size all buttons in bar evenly, according to largest contents */

#define SPEEDBAR_Font         (SPEEDBAR_Dummy+18)
    /* (struct TextFont *) Font to use for SBNA_Text labels (V50) */

#define SPEEDBAR_TopNode      (SPEEDBAR_Dummy+19)
    /* (struct Node *) Node pointer of first visible button (V53) */

#define SPEEDBAR_ButtonType   (SPEEDBAR_Dummy+20)
    /* (UWORD) Type of buttons: text, image or both (see below) (V53) */

#define SPEEDBAR_HorizPadding (SPEEDBAR_Dummy+21)
    /* (UWORD) Horizontal padding between buttons and container frame (V53) */

#define SPEEDBAR_VertPadding  (SPEEDBAR_Dummy+22)
    /* (UWORD) Vertical padding between buttons and container frame (V53) */

#define SPEEDBAR_Reserved1    (SPEEDBAR_Dummy+23)
    /* Reserved for future extension, do not use. */

/*****************************************************************************/

/* Changes attributes for a speedbar node without
 * the need of detaching the speedbar list first.
 * This methods also takes care of updating the
 * display. (V50).
 */
#define SBM_SETNODEATTRS (0x58000AL)

struct sbSetNodeAttrs
{
    ULONG               MethodID;    /* SBM_SETNODEATTRS */
    struct GadgetInfo * sb_GInfo;
    struct Node *       sb_Node;     /* node whose attributes
                                        you are changing. */
    struct TagItem *    sb_AttrList; /* list of attributes to change. */
};

/*****************************************************************************/

/* SPEEDBAR_Orientation modes */
#define SBORIENT_HORIZ 0
#define SBORIENT_VERT  1

/* OBSOLETE DO NOT USE. */
#define SPEEDBAR_HORIZONTAL SBORIENT_HORIZ
#define SPEEDBAR_VERTICAL   SBORIENT_VERT

/*****************************************************************************/

/* SPEEDBAR_ButtonType values */

#define SBTYPE_BOTH  0  /* Image and text */
#define SBTYPE_TEXT  1  /* Text only */
#define SBTYPE_IMAGE 2  /* Image only */

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

#endif /* GADGETS_SPEEDBAR_H */
