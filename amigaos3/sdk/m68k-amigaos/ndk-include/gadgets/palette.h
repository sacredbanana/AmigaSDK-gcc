#ifndef GADGETS_PALETTE_H
#define GADGETS_PALETTE_H
/*
**	$VER: palette.h 47.4 (22.7.2021)
**
**	Definitions for the Palette BOOPSI class
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

/*****************************************************************************/

/* Additional attributes defined by the Palette class
 */
#define PALETTE_Dummy			(REACTION_Dummy+0x0004000)

#define PALETTE_Colour			(PALETTE_Dummy+1)
	/* (UWORD) The value in the gadget.  Defaults to 0. */

#define PALETTE_ColourOffset		(PALETTE_Dummy+2)
	/* (UWORD) Maximum number of characters for the numer (including
	 * negative sign.  Defaults to 10. */

#define PALETTE_ColourTable		(PALETTE_Dummy+3)
        /* (UWORD *) Pointer to a table of pen numbers indicating which colors
         *           should be used and edited by the palette gadget. */

#define PALETTE_NumColours		(PALETTE_Dummy+4)
	/* (UWORD) Maximum value for the number. */

#define PALETTE_MinColours		(PALETTE_Dummy+5) /* OS4ONLY */

#define PALETTE_RenderHook		(PALETTE_Dummy+7)
	/* (struct Hook *) Render hook for palette boxes. Defaults to NULL. */

/*****************************************************************************/

/* The different types of messages that a palette callback hook can see */
#define PB_DRAW 0x202L  /* Draw yourself, with state */

/* Possible return values from a callback hook */
#define PBCB_OK      0  /* Callback understands this message type    */
#define PBCB_UNKNOWN 1  /* Callback does not understand this message */

/* States for PBoxDrawMsg.pbdm_State */
#define PBR_NORMAL           0  /* Unselected box */
#define PBR_SELECTED         1  /* Selected (active) box */
#define PBR_NORMALDISABLED   2  /* Disabled unselected box */
#define PBR_SELECTEDDISABLED 8  /* Disabled selected (active) box */

/* Messages received by a palette callback hook */
struct PBoxDrawMsg
{
    ULONG             pbdm_MethodID;  /* PB_DRAW */
    struct RastPort * pbdm_RastPort;  /* Where to render to */
    struct DrawInfo * pbdm_DrawInfo;  /* Useful to have around */
    struct Rectangle  pbdm_Bounds;    /* Limits of where to render */
    ULONG             pbdm_State;     /* How to render */
    ULONG             pbdm_Color;     /* Color index in palette */
    struct Gadget *   pbdm_Gadget;    /* The palette gadget */
};

/*****************************************************************************/

/* American spellings.
 */
#define PALETTE_Color PALETTE_Colour
#define PALETTE_ColorOffset PALETTE_ColourOffset
#define PALETTE_ColorTable PALETTE_ColourTable
#define PALETTE_NumColors PALETTE_NumColours

#endif /* GADGETS_PALETTE_H */
