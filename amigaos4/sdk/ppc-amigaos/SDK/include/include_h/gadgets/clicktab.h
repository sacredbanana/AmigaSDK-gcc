#ifndef GADGETS_CLICKTAB_H
#define GADGETS_CLICKTAB_H
/*
**    $VER: clicktab.h 54.16 (22.08.2022)
**
**    Definitions for the clicktab.gadget BOOPSI class
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

/****************************************************************************/

/* Defines for the clicktab node attributes.
 */
#define TNA_Dummy     (TAG_USER+0x010000)

#define TNA_UserData  (TNA_Dummy+1)
    /* (APTR) user data, have a blast. */

#define TNA_Enabled   (TNA_Dummy+2) /* was never implemented, now obsolete! */
#define TNA_Spacing   (TNA_Dummy+3) /* obsolete! */
#define TNA_Highlight (TNA_Dummy+4) /* obsolete! */

#define TNA_Image     (TNA_Dummy+5)
    /* (struct Image *) render image pointer. */

#define TNA_SelImage  (TNA_Dummy+6)
    /* (struct Image *) select image pointer. */

#define TNA_Text      (TNA_Dummy+7)
    /* (CONST_STRPTR) tab text label string pointer. */

#define TNA_Number    (TNA_Dummy+8)
    /* (uint16) numeric ID assignment for tab. */

#define TNA_TextPen   (TNA_Dummy+9)
    /* (int16) Text pen ID to render tab text. */

#define TNA_Disabled  (TNA_Dummy+10)
    /* (BOOL) Is this button disabled?. (V42) */

#define TNA_Flagged   (TNA_Dummy+11)
    /* (BOOL) show the "flag" image in the tab (V52.6) */

#define TNA_HintInfo  (TNA_Dummy+12)
    /* (CONST_STRPTR) define a hintinfo for this clicktab node (V53.10) */

#define TNA_CloseGadget (TNA_Dummy+13 )
    /* (BOOL) specify if this tab has a close gadget */

#define TNA_SoftStyle (TNA_Dummy+14)
    /* (int32) Specify a custom softstyle for this tabs title */

/*****************************************************************************/

/* Additional attributes defined by the clicktab.gadget class
 */
#define CLICKTAB_Dummy             (REACTION_Dummy + 0x27000)

#define CLICKTAB_Labels            (CLICKTAB_Dummy+1)
    /* (struct List *) button list */

#define CLICKTAB_Current           (CLICKTAB_Dummy+2)
    /* (uint16) Currently selected tab id# */

#define CLICKTAB_CurrentNode       (CLICKTAB_Dummy+3)
    /* (struct Node *) Currently selected tab node */

#define CLICKTAB_Orientation       (CLICKTAB_Dummy+4)
    /* (int16) Horizontal/Vertical/Flip mode - **Not Implemented!** */

#define CLICKTAB_PageGroup         (CLICKTAB_Dummy+5)
    /* (Object *) Embedded page.gadget object child pointer. (V42) */

#define CLICKTAB_PageGroupBackFill (CLICKTAB_Dummy+6)
    /* (struct Hook *) Embedded page.gadget object + selected ClickTab backfill
       pointer. (V42) */

#define CLICKTAB_LabelTruncate     (CLICKTAB_Dummy+7)
    /* (BOOL) Allow labels to become truncated when gadget width
       is compressed. (V51) */

#define CLICKTAB_FlagImage         (CLICKTAB_Dummy+8)
    /* (struct Image *) Bitmap to be rendered in the tab if 
       TNA_Flagged is TRUE (V52.6) */

#define CLICKTAB_EvenSize          (CLICKTAB_Dummy+9)
    /* (BOOL) Allows the user to override the system prefs setting
       for even size tabs. Defaults to system settings. (V53.1) */

#define CLICKTAB_Total             (CLICKTAB_Dummy+10)
    /* (uint32) Total number of nodes attached to the gadget. (V53.3) */

#define CLICKTAB_PageGroupBorder   (CLICKTAB_Dummy+11)
#define CLICKTAB_PageBorder        CLICKTAB_PageGroupBorder
    /* (BOOL) Specify whether the border is to be drawn around pages
       attached to the clicktab. (V53.7) */

#define CLICKTAB_AutoFit           (CLICKTAB_Dummy+12)
    /* (BOOL) Automatically fit dynamic tabs. (V53.20) */

#define CLICKTAB_AutoTabNumbering  (CLICKTAB_Dummy+13)
    /* (BOOL) Automatically number tabs. (V53.23) */

#define CLICKTAB_CloseImage        (CLICKTAB_Dummy+14)
    /* (Object *) Specify a BOOPSI image to use for the TABs close 
       gadget. (V53.29) */

#define CLICKTAB_Closed            (CLICKTAB_Dummy+15)
    /* (ULONG) Returns the number of the last tab on which a close gadget 
        was used (V53.29) */

#define CLICKTAB_NodeClosed        (CLICKTAB_Dummy+16)
    /* (struct Node *) Returns the tab node address in which the close
       gadget was last used (V53.29) */

#define CLICKTAB_ClosePlacement    (CLICKTAB_Dummy+17)
    /* (ULONG) Specify which side of the tab the close gadget should 
       appear. (V53.30) */

#define CLICKTAB_ChooserFlagImage   (CLICKTAB_Dummy+18)
    /* (Object *) Specify a BOOPSI image to use for the choosers 
       menu flag image. (V53.49) */

/*****************************************************************************/

/* CLICKTAB_Orientation Modes
 */
#define CTORIENT_HORIZ     0
#define CTORIENT_VERT      1
#define CTORIENT_HORIZFLIP 2
#define CTORIENT_VERTFLIP  3


/* Close gadget placement
 */
#define PLACECLOSE_LEFT  0
#define PLACECLOSE_RIGHT 1


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

#endif /* GADGETS_CLICKTAB_H */
