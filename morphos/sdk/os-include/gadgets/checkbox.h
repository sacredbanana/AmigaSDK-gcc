#ifndef GADGETS_CHECKBOX_H
#define GADGETS_CHECKBOX_H

/*
	checkbox.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* Attributes defined by checkbox.gadget */

#define CHECKBOX_Dummy          (REACTION_Dummy + 0x11000)
#define CHECKBOX_TextPen        (CHECKBOX_Dummy + 1)
#define CHECKBOX_FillTextPen    (CHECKBOX_Dummy + 2)
#define CHECKBOX_BackgroundPen  (CHECKBOX_Dummy + 3)
#define CHECKBOX_BevelStyle     (CHECKBOX_Dummy + 4)
#define CHECKBOX_TextPlace      (CHECKBOX_Dummy + 5)
#define CHECKBOX_Checked        (GA_Selected)


#endif /* GADGETS_CHECKBOX_H */
