#ifndef GADGETS_SPACE_H
#define GADGETS_SPACE_H

/*
	space.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* Attributes defined by space.gadget */

#define SPACE_Dummy        (REACTION_Dummy + 0x9000)
#define SPACE_MinHeight    (SPACE_Dummy + 1)
#define SPACE_MinWidth     (SPACE_Dummy + 2)
#define SPACE_MouseX       (SPACE_Dummy + 3)
#define SPACE_MouseY       (SPACE_Dummy + 4)
#define SPACE_Transparent  (SPACE_Dummy + 5)
#define SPACE_AreaBox      (SPACE_Dummy + 6)
#define SPACE_RenderHook   (SPACE_Dummy + 7)
#define SPACE_BevelStyle   (SPACE_Dummy + 8)


#endif /* GADGETS_SPACE_H */
