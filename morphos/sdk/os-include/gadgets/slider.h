#ifndef GADGETS_SLIDER_H
#define GADGETS_SLIDER_H

/*
	slider.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* Attributes defined by slider.gadget */

#define SLIDER_Dummy        (REACTION_Dummy + 0x0028000)
#define SLIDER_Min          (SLIDER_Dummy + 1)
#define SLIDER_Max          (SLIDER_Dummy + 2)
#define SLIDER_Level        (SLIDER_Dummy + 3)
#define SLIDER_Orientation  (SLIDER_Dummy + 4)
#define SLIDER_DispHook     (SLIDER_Dummy + 5)
#define SLIDER_Ticks        (SLIDER_Dummy + 6)
#define SLIDER_ShortTicks   (SLIDER_Dummy + 7)
#define SLIDER_TickSize     (SLIDER_Dummy + 8)
#define SLIDER_KnobImage    (SLIDER_Dummy + 9)
#define SLIDER_BodyFill     (SLIDER_Dummy + 10)
#define SLIDER_BodyImage    (SLIDER_Dummy + 11)
#define SLIDER_Gradient     (SLIDER_Dummy + 12)
#define SLIDER_PenArray     (SLIDER_Dummy + 13)
#define SLIDER_Invert       (SLIDER_Dummy + 14)
#define SLIDER_KnobDelta    (SLIDER_Dummy + 15)


/* SLIDER_Orientation modes */

#define SORIENT_HORIZ  FREEHORIZ
#define SORIENT_VERT   FREEVERT

/*** OBSOLETE ***/

#define SLIDER_HORIZONTAL  SORIENT_HORIZ
#define SLIDER_VERTICAL    SORIENT_VERT


#endif /* GADGETS_SLIDER_H */
