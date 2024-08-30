#ifndef GADGETS_SCROLLER_H
#define GADGETS_SCROLLER_H

/*
	scroller.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* Attributes defined by scroller.gadget */

#define SCROLLER_Dummy          (REACTION_Dummy + 0x0005000)
#define SCROLLER_Top            (SCROLLER_Dummy + 1)
#define SCROLLER_Visible        (SCROLLER_Dummy + 2)
#define SCROLLER_Total          (SCROLLER_Dummy + 3)
#define SCROLLER_Orientation    (SCROLLER_Dummy + 4)
#define SCROLLER_Arrows         (SCROLLER_Dummy + 5)
#define SCROLLER_Stretch        (SCROLLER_Dummy + 6)
#define SCROLLER_ArrowDelta     (SCROLLER_Dummy + 7)
#define SCROLLER_SignalTask     (SCROLLER_Dummy + 10)
#define SCROLLER_SignalTaskBit  (SCROLLER_Dummy + 11)


/* SCROLLER_Orientation modes */

#define SORIENT_HORIZ  FREEHORIZ
#define SORIENT_VERT   FREEVERT

/*** OBSOLETE ***/

#define SCROLLER_HORIZONTAL  SORIENT_HORIZ
#define SCROLLER_VERTICAL    SORIENT_VERT


#endif /* GADGETS_SCROLLER_H */
