#ifndef GADGETS_CLICKTAB_H
#define GADGETS_CLICKTAB_H

/*
	clicktab.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif

/* clicktab.gadget node attributes */

#define TNA_Dummy       (TAG_USER + 0x010000)
#define TNA_UserData    (TNA_Dummy + 1)
#define TNA_Enabled     (TNA_Dummy + 2)
#define TNA_Spacing     (TNA_Dummy + 3)
#define TNA_Highlight   (TNA_Dummy + 4)
#define TNA_Image       (TNA_Dummy + 5)
#define TNA_SelImage    (TNA_Dummy + 6)
#define TNA_Text        (TNA_Dummy + 7)
#define TNA_Number      (TNA_Dummy + 8)
#define TNA_TextPen     (TNA_Dummy + 9)
#define TNA_Disabled    (TNA_Dummy + 10)


/* Attributes defined by clicktab.gadget */

#define CLICKTAB_Dummy              (REACTION_Dummy + 0x27000)
#define CLICKTAB_Labels             (CLICKTAB_Dummy + 1)
#define CLICKTAB_Current            (CLICKTAB_Dummy + 2)
#define CLICKTAB_CurrentNode        (CLICKTAB_Dummy + 3)
#define CLICKTAB_Orientation        (CLICKTAB_Dummy + 4)
#define CLICKTAB_PageGroup          (CLICKTAB_Dummy + 5)
#define CLICKTAB_PageGroupBackFill  (CLICKTAB_Dummy + 6)


/* CLICKTAB_Orientation modes */

#define CTORIENT_HORIZ      0
#define CTORIENT_VERT       1
#define CTORIENT_HORIZFLIP  2
#define CTORIENT_VERTFLIP   3


#endif /* GADGETS_CLICKTAB_H */
