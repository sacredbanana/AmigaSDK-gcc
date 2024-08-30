#ifndef GADGETS_PALETTE_H
#define GADGETS_PALETTE_H

/*
	palette.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* Attributes defined by palette.gadget */

#define PALETTE_Dummy         (REACTION_Dummy + 0x0004000)
#define PALETTE_Colour        (PALETTE_Dummy + 1)
#define PALETTE_ColourOffset  (PALETTE_Dummy + 2)
#define PALETTE_ColourTable   (PALETTE_Dummy + 3)
#define PALETTE_NumColours    (PALETTE_Dummy + 4)


/* Language fix */

#define PALETTE_Color        PALETTE_Colour
#define PALETTE_ColorOffset  PALETTE_ColourOffset
#define PALETTE_ColorTable   PALETTE_ColourTable
#define PALETTE_NumColors    PALETTE_NumColours


#endif /* GADGETS_PALETTE_H */
