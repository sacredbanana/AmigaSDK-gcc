#ifndef GADGETS_CHOOSER_H
#define GADGETS_CHOOSER_H

/*
	chooser.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


#define CHOOSER_MinWidth   36
#define CHOOSER_MinHeight  10


/* chooser.gadget node attributes */

#define CNA_Dummy           (TAG_USER + 0x5001500)
#define CNA_Text            (CNA_Dummy + 1)
#define CNA_Image           (CNA_Dummy + 2)
#define CNA_SelImage        (CNA_Dummy + 3)
#define CNA_UserData        (CNA_Dummy + 4)
#define CNA_Separator       (CNA_Dummy + 5)
#define CNA_Disabled        (CNA_Dummy + 6)
#define CNA_BGPen           (CNA_Dummy + 7)
#define CNA_FGPen           (CNA_Dummy + 8)
#define CNA_ReadOnly        (CNA_Dummy + 9)


/* Attributes defined by chooser.gadget */

#define CHOOSER_Dummy           (REACTION_Dummy + 0x0001000)
#define CHOOSER_PopUp           (CHOOSER_Dummy + 1)
#define CHOOSER_DropDown        (CHOOSER_Dummy + 2)
#define CHOOSER_Title           (CHOOSER_Dummy + 3)
#define CHOOSER_Labels          (CHOOSER_Dummy + 4)
#define CHOOSER_Active          (CHOOSER_Dummy + 5)
#define CHOOSER_Selected        (CHOOSER_Active)
#define CHOOSER_Width           (CHOOSER_Dummy + 6)
#define CHOOSER_AutoFit         (CHOOSER_Dummy + 7)
#define CHOOSER_MaxLabels       (CHOOSER_Dummy + 9)
#define CHOOSER_Offset          (CHOOSER_Dummy + 10)
#define CHOOSER_Hidden          (CHOOSER_Dummy + 11)
#define CHOOSER_LabelArray      (CHOOSER_Dummy + 12)
#define CHOOSER_Justification   (CHOOSER_Dummy + 13)


/* CHOOSER_Justification values */

#define CHJ_LEFT    0
#define CHJ_CENTER  1
#define CHJ_RIGHT   2

/* Language fix */

#define CHJ_CENTRE  CHJ_CENTER


#endif /* GADGETS_CHOOSER_H */
