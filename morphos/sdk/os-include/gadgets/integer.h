#ifndef GADGETS_INTEGER_H
#define GADGETS_INTEGER_H

/*
	integer.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* Attributes defined by integer.gadget */

#define INTEGER_Dummy       (REACTION_Dummy + 0x0002000)
#define INTEGER_Number      (INTEGER_Dummy + 1)
#define INTEGER_MaxChars    (INTEGER_Dummy + 2)
#define INTEGER_Minimum     (INTEGER_Dummy + 3)
#define INTEGER_Maximum     (INTEGER_Dummy + 4)
#define INTEGER_Arrows      (INTEGER_Dummy + 5)
#define INTEGER_MinVisible  (INTEGER_Dummy + 6)
#define INTEGER_SkipVal     (INTEGER_Dummy + 7)


#endif /* GADGETS_INTEGER_H */
