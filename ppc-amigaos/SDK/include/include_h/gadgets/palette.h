#ifndef GADGETS_PALETTE_H
#define GADGETS_PALETTE_H
/*
**    $VER: palette.h 54.16 (22.08.2022)
**
**    Definitions for the Palette BOOPSI class
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef   INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

/*****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/*****************************************************************************/

/* Additional attributes defined by the Palette class */
#define PALETTE_Dummy        (REACTION_Dummy + 0x0004000)

#define PALETTE_Colour       (PALETTE_Dummy + 1)
    /* (UWORD) Index of current palette color (pen number). Defaults to 0. */

#define PALETTE_ColourOffset (PALETTE_Dummy + 2)
    /* (UWORD) Index of first palette color to display. Defaults to 0. */

#define PALETTE_ColourTable  (PALETTE_Dummy + 3)
    /* (UWORD *) Table of colors to use in the palette. Defaults to NULL. */

#define PALETTE_NumColours   (PALETTE_Dummy + 4)
    /* (UWORD) Number of colors in the palette (power of 2). Defaults to 4. */

#define PALETTE_MinColours   (PALETTE_Dummy + 5)
	/* (UWORD) Minimum amount of colours to display (power of 2). Defaults to 4. */
	
#define PALETTE_RenderHook   (PALETTE_Dummy + 7)
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

/* American spellings. */
#define PALETTE_Color       PALETTE_Colour
#define PALETTE_ColorOffset PALETTE_ColourOffset
#define PALETTE_ColorTable  PALETTE_ColourTable
#define PALETTE_NumColors   PALETTE_NumColours

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* GADGETS_PALETTE_H */
