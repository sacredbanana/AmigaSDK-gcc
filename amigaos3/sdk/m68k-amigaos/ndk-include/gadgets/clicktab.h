#ifndef GADGETS_CLICKTAB_H
#define GADGETS_CLICKTAB_H
/*
**	$VER: clicktab.h 47.14 (12.7.2021)
**
**	Definitions for the clicktab.gadget BOOPSI class
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

/*****************************************************************************/

/* Defines for the clicktab node attributes.
 */
#define TNA_Dummy		(TAG_USER+0x010000)

#define TNA_UserData		(TNA_Dummy+1)
    /* (APTR) user data, have a blast. */

#define TNA_Enabled		(TNA_Dummy+2)	/* was never implemented, now obsolete! */
#define TNA_Spacing		(TNA_Dummy+3)	/* obsolete! */
#define TNA_Highlight		(TNA_Dummy+4)	/* obsolete! */

#define TNA_Image		(TNA_Dummy+5)
    /* (strcut Image *) render image pointer. */

#define TNA_SelImage		(TNA_Dummy+6)
    /* (struct Image *) select image pointer. */

#define TNA_Text		(TNA_Dummy+7)
    /* (STRPTR) tab text label string pointer. */

#define TNA_Number		(TNA_Dummy+8)
    /* (WORD) numeric ID assignment for tab. */

#define TNA_TextPen		(TNA_Dummy+9)
    /* (WORD) Text pen ID to render tab text. */

#define TNA_Disabled		(TNA_Dummy+10)
    /* (BOOL) Is this button disabled?. (V42) */

#define TNA_Flagged		(TNA_Dummy+11) /* OS4ONLY */

#define TNA_HintInfo		(TNA_Dummy+12) /* OS4ONLY */

#define TNA_CloseGadget		(TNA_Dummy+13)
    /* (BOOL) specify if this tab has a close gadget V53 and V47) */

#define TNA_SoftStyle		(TNA_Dummy+14) // OSONLY

#define TNA_HelpText		(TNA_Dummy+15)
    /* (STRPTR) help text to take precedence of that of the gadget (V47) */

/*****************************************************************************/

/* Additional attributes defined by the clicktab.gadget class
 */
#define CLICKTAB_Dummy				(REACTION_Dummy + 0x27000)

#define	CLICKTAB_Labels				(CLICKTAB_Dummy+1)
    /* (struct List *) button list */

#define	CLICKTAB_Current			(CLICKTAB_Dummy+2)
    /* (WORD) Currently selected tab id# */

#define	CLICKTAB_CurrentNode			(CLICKTAB_Dummy+3)
    /* (struct TabNode *) Currently selected tab node */

#define	CLICKTAB_Orientation			(CLICKTAB_Dummy+4)
    /* (WORD) Horizontal/Vertical/Flip mode - **Not Implemented!** */

#define	CLICKTAB_PageGroup			(CLICKTAB_Dummy+5)
    /* (Object *) Embedded PageObject child pointer. (V42) */

#define CLICKTAB_PageGroupBackFill		(CLICKTAB_Dummy+6)
    /* (Object *) Embedded PageObject + selected ClickTab backfill pointer. (V42) */

#define CLICKTAB_LabelTruncate			(CLICKTAB_Dummy+7) /* OS4ONLY */

#define CLICKTAB_FlagImage			(CLICKTAB_Dummy+8) /* OS4ONLY */

#define CLICKTAB_EvenSize			(CLICKTAB_Dummy+9) /* OS4ONLY */

#define CLICKTAB_Total				(CLICKTAB_Dummy+10) /* OS4ONLY */

#define CLICKTAB_PageGroupBorder		(CLICKTAB_Dummy+11)
#define CLICKTAB_PageBorder			CLICKTAB_PageGroupBorder
    /* (BOOL) Specify whether the border is to be drawn around pages
       attached to the clicktab. (V53.7 and V47) */

#define CLICKTAB_AutoFit			(CLICKTAB_Dummy+12)
    /* (BOOL) Automatically fit dynamic tabs. (V53.20 and V47) */

#define CLICKTAB_AutoTabNumbering		(CLICKTAB_Dummy+13)
    /* (BOOL) Automatically number tabs. (V53.23 and V47) */

#define CLICKTAB_CloseImage			(CLICKTAB_Dummy+14)
    /* (Object *) Specify a BOOPSI image to use for the TABs close
       gadget. (V53.29 and V47) */

#define CLICKTAB_Closed				(CLICKTAB_Dummy+15) /* OS4ONLY */

#define CLICKTAB_NodeClosed			(CLICKTAB_Dummy+16)
    /* (struct Node *) Returns the tab node address in which the close
       gadget was last used (V53.29 and V47) */

#define CLICKTAB_ClosePlacement			(CLICKTAB_Dummy+17)
    /* (ULONG) Specify which side of the tab the close gadget should
       appear. (V53.30 and V47) */

#define CLICKTAB_ChooserFlagImage		(CLICKTAB_Dummy+18)
    /* (Object *) Specify a BOOPSI image to use for the choosers
       menu flag image. (V53.49) */

#define CLICKTAB_MinorLabelChange		(CLICKTAB_Dummy+19)
    /* (BOOL) Set when setting CLICKTAB_Labels only affected text or
     * tooltips. It can help avoid flicker as no relayout of page widget
     * will take place. (V47) */

#define CLICKTAB_TabsOffsetAsLayoutSpacing		(CLICKTAB_Dummy+20)
    /* (BOOL) Set this if tabs should be indented from left and right by 1
     * layout.gadget space. This should be set to TRUE when you use
     * the tabs without PageBorder. At the same time the clicktab.gadget
     * should extend from side to side of the window with no other spacing
     * creating an unbroken illusion.(V47) */

/*****************************************************************************/

/* CLICKTAB_Orientation Modes
 */
#define CTORIENT_HORIZ		0
#define CTORIENT_VERT		1
#define CTORIENT_HORIZFLIP	2
#define CTORIENT_VERTFLIP	3

/* Close gadget placement
 */
#define PLACECLOSE_LEFT  0
#define PLACECLOSE_RIGHT 1

#endif /* GADGETS_CLICKTAB_H */
