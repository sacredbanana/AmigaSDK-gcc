#ifndef GADGETS_CHOOSER_H
#define GADGETS_CHOOSER_H

/*
**    $VER: chooser.h 54.16 (22.08.2022)
**
**    Definitions for the Chooser BOOPSI class
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

/* Predefined Minimum dimensions for safe operation.
 */
#define CHOOSER_MinWidth  36
#define CHOOSER_MinHeight 10

/*****************************************************************************/

/* Chooser node attributes.
 */
#define CNA_Dummy     (TAG_USER+0x5001500)

#define CNA_Text      (CNA_Dummy+1)
    /* (STRPTR) Text for the node. */

#define CNA_Image     (CNA_Dummy+2)
    /* (struct Image *) Normal image for node. */

#define CNA_SelImage  (CNA_Dummy+3)
    /* (struct Image *) Select image for node. */

#define CNA_UserData  (CNA_Dummy+4)
    /* (APTR) User data, use as desired. */

#define CNA_Separator (CNA_Dummy+5)
    /* (BOOL) Render a separator bar. */

#define CNA_Disabled  (CNA_Dummy+6)
    /* (BOOL) Disabled entry. */

#define CNA_BGPen     (CNA_Dummy+7)
    /* (WORD) Background Pen. (V51) */

#define CNA_FGPen     (CNA_Dummy+8)
    /* (WORD) Foreground Pen. (V51) */

#define CNA_ReadOnly  (CNA_Dummy+9)
    /* (BOOL) Non-selectable entry. */

#define CNA_CopyText  (CNA_Dummy+10)
	/* (BOOL) Copy CNA_Text into internal buffer */

/*****************************************************************************/

/* Additional attributes defined by the Chooser class
 */
#define CHOOSER_Dummy              (REACTION_Dummy+0x0001000)

#define CHOOSER_PopUp              (CHOOSER_Dummy+1)
    /* (BOOL) Make it a popup menu. Defaults to FALSE.
     * This item is mutually exclusive to CHOOSER_DropDown,
     * one of the two MUST be TRUE.
     */

#define CHOOSER_DropDown           (CHOOSER_Dummy+2)
    /* (BOOL) Make it a dropdown menu. Defaults to FALSE.
     * This item is mutually exclusive to CHOOSER_PopUp,
     * one of the two MUST be TRUE.
     */

#define CHOOSER_Title              (CHOOSER_Dummy+3)
    /* (STRPTR) Title for the dropdown. Defaults to NULL. */

#define CHOOSER_Labels             (CHOOSER_Dummy+4)
    /* (struct List *) Exec List of labels for the menu. Either this or
     * CHOOSER_LabelArray (see below) is required. */

#define CHOOSER_Active             (CHOOSER_Dummy+5)
    /* (WORD) Active label in the list. Defaults to 0. */

#define CHOOSER_Selected           (CHOOSER_Active)
    /* A more logical NEW NAME for the above. */

#define CHOOSER_Width              (CHOOSER_Dummy+6)
    /* (WORD) The width of the popup menu. Defaults to the width of the
     * gadget. */

#define CHOOSER_AutoFit            (CHOOSER_Dummy+7)
    /* (BOOL) Make the menu automatically fit its labels. Defaults to FALSE.
     * NOTE: Obsolete starting with V51, don't use in new code. */

#define CHOOSER_MaxLabels          (CHOOSER_Dummy+9)
    /* (WORD) Maximum number of labels to be shown in the menu regardless
     * of how many are in the CHOOSER_Labels list. Defaults to 12. */

#define CHOOSER_Offset             (CHOOSER_Dummy+10)
    /* (WORD) Add a fixed value offset to the CHOOSER_Selected value
     * for notification methods. This is useful in connecting a Chooser
     * with item IDs 0 thru 11 to a Calendar's month which is 1 thru 12.
     * In that situation, a CHOOSER_Offset of 1 would be used to match
     * the starting offsets of the respective tags.
     * Defaults to 0. (V41) */

#define CHOOSER_Hidden             (CHOOSER_Dummy+11)
    /* (BOOL) If set, the Chooser will not render its main body and you
     * may use WM_ACTIVATEGADGET to make the Chooser appear.
     * Defaults to FALSE. (V42 prerelease - V41.101 or later) */

#define CHOOSER_LabelArray         (CHOOSER_Dummy+12)
    /* (STRPTR *) A NULL-terminated array of strings to use as labels. Use
     * ~0UL as string to add a separator bar to the list. Either this or
     * CHOOSER_Labels (see above) is required. New for V45.2 */

#define CHOOSER_Justification      (CHOOSER_Dummy+13)
    /* (WORD) How to align the labels. New for V45.3 */

#define CHOOSER_ImageJustification (CHOOSER_Dummy+14)
    /* (WORD) How to align the images. New for V51.2 */

#define CHOOSER_SelectedNode       (CHOOSER_Dummy+15)
    /* (struct Node *) Get the active Chooser node pointer. New for V52.5 */
	
/*    Possible values for CHOOSER_Justification
 *    and CHOOSER_ImageJustification
 */
#define CHJ_LEFT   0  /* Default */
#define CHJ_CENTER 1
#define CHJ_RIGHT  2

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

#endif /* GADGETS_CHOOSER_H */
