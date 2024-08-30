#ifndef GADGETS_FUELGAUGE_H
#define GADGETS_FUELGAUGE_H

/*
	fuelgauge.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* Attributes defined by fuelgauge.gadget */

#define FUELGAUGE_Dummy          (REACTION_Dummy + 0x12000)
#define FUELGAUGE_Min            (FUELGAUGE_Dummy + 1)
#define FUELGAUGE_Max            (FUELGAUGE_Dummy + 2)
#define FUELGAUGE_Level          (FUELGAUGE_Dummy + 3)
#define FUELGAUGE_Orientation    (FUELGAUGE_Dummy + 4)
#define FUELGAUGE_Percent        (FUELGAUGE_Dummy + 5)
#define FUELGAUGE_Ticks          (FUELGAUGE_Dummy + 6)
#define FUELGAUGE_ShortTicks     (FUELGAUGE_Dummy + 7)
#define FUELGAUGE_TickSize       (FUELGAUGE_Dummy + 8)
#define FUELGAUGE_TickPen        (FUELGAUGE_Dummy + 9)
#define FUELGAUGE_PercentPen     (FUELGAUGE_Dummy + 10)
#define FUELGAUGE_FillPen        (FUELGAUGE_Dummy + 11)
#define FUELGAUGE_EmptyPen       (FUELGAUGE_Dummy + 12)
#define FUELGAUGE_VarArgs        (FUELGAUGE_Dummy + 13)
#define FUELGAUGE_Justification  (FUELGAUGE_Dummy + 14)


/* FUELGAUGE_Orientation modes */

#define FGORIENT_HORIZ  0
#define FGORIENT_VERT   1


/* FUELGAUGE_Justification modes */

#define FGJ_LEFT    0
#define FGJ_CENTER  1

/* Language fix */

#define FGJ_CENTRE  FGJ_CENTER


/*** OBSOLETE ***/

#define FUELGAUGE_HORIZONTAL  FGORIENT_HORIZ
#define FUELGAUGE_VERTICAL    FGORIENT_VERT


#endif /* GADGETS_FUELGAUGE_H */
