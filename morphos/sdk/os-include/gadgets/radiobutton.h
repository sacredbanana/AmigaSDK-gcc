#ifndef GADGETS_RADIOBUTTON_H
#define GADGETS_RADIOBUTTON_H

/*
	radiobutton.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* radiobutton.gadget node attributes */

#define RBNA_Dummy     (TAG_USER + 0x020000)
#define RBNA_UserData  (RBNA_Dummy + 1)
#define RBNA_Labels    (RBNA_Dummy + 2)


/* Attributes defined by radiobutton.gadget */

#define RADIOBUTTON_Dummy       (REACTION_Dummy + 0x14000)
#define RADIOBUTTON_Labels      (RADIOBUTTON_Dummy + 1)
#define RADIOBUTTON_Strings     (RADIOBUTTON_Dummy + 2)
#define RADIOBUTTON_Spacing     (RADIOBUTTON_Dummy + 3)
#define RADIOBUTTON_Selected    (RADIOBUTTON_Dummy + 4)
#define RADIOBUTTON_LabelPlace  (RADIOBUTTON_Dummy + 5)


#endif /* GADGETS_RADIOBUTTON_H */
