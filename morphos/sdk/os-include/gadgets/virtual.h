#ifndef GADGETS_VIRTUAL_H
#define GADGETS_VIRTUAL_H

/*
	virtual.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* Attributes defined by virtual.gadget */

#define VIRTUALA_Base         (REACTION_Dummy + 0x24500)
#define VIRTUALA_Contents     (VIRTUALA_Base)
#define VIRTUALA_Scroller     (VIRTUALA_Base + 1)
#define VIRTUALA_ScrollX      (VIRTUALA_Base + 2)
#define VIRTUALA_ScrollY      (VIRTUALA_Base + 3)
#define VIRTUALA_VisibleX     (VIRTUALA_Base + 4)
#define VIRTUALA_VisibleY     (VIRTUALA_Base + 5)
#define VIRTUALA_TopX         (VIRTUALA_Base + 6)
#define VIRTUALA_TopY         (VIRTUALA_Base + 7)
#define VIRTUALA_TotalX       (VIRTUALA_Base + 8)
#define VIRTUALA_TotalY       (VIRTUALA_Base + 9)
#define VIRTUALA_ScrollerX    (VIRTUALA_Base + 10)
#define VIRTUALA_ScrollerY    (VIRTUALA_Base + 11)
#define VIRTUALA_InputScroll  (VIRTUALA_Base + 12)
#define VIRTUALA_NoDispose    (VIRTUALA_Base + 13)


#endif /* GADGETS_VIRTUAL_H */
