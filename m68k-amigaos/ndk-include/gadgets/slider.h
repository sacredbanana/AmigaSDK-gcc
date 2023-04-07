#ifndef GADGETS_SLIDER_H
#define GADGETS_SLIDER_H
/*
**	$VER: slider.h 47.1 (13.12.2019)
**
**	Definitions for the slider.gadget BOOPSI class
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    All Rights Reserved.
*/

/*****************************************************************************/

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

/*****************************************************************************/

/* Additional attributes defined by the slider.gadget class
 */

#define SLIDER_Dummy         (REACTION_Dummy+0x0028000)

#define SLIDER_Min           (SLIDER_Dummy+1L)
	/* (WORD) Minimum slider level. */

#define SLIDER_Max           (SLIDER_Dummy+2L)
	/* (WORD) Maximum slider level. */

#define SLIDER_Level         (SLIDER_Dummy+3L)
	/* (WORD) Current slider level. */

#define SLIDER_Orientation   (SLIDER_Dummy+4L)
	/* (UWORD) Orientation of slider. Defaults to SORIENT_VERT. */

#define SLIDER_DispHook      (SLIDER_Dummy+5L)
	/* (struct Hook *) Hook which is invoked whenever the slider's
	 * level changes; object (A2) is the gadget, message (A1) is a
	 * taglist with GA_ID, SLIDER_Level, SLIDER_Min, SLIDER_Max and
	 * GA_UserInput. */

#define SLIDER_Ticks         (SLIDER_Dummy+6L)
	/* (WORD) How many ticks to display along the slider's body. */

#define SLIDER_ShortTicks    (SLIDER_Dummy+7L)
	/* (BOOL) Alternate long and short ticks? Defaults to FALSE. */

#define SLIDER_TickSize      (SLIDER_Dummy+8L)
	/* (LONG) Size of the slider's ticks. */

#define SLIDER_KnobImage     (SLIDER_Dummy+9L)
	/* (struct Image *) BOOPSI image for the slider's knob. */

#define SLIDER_BodyFill      (SLIDER_Dummy+10L)
	/* (WORD) NOT IMPLEMENTED YET. */

#define SLIDER_BodyImage     (SLIDER_Dummy+11L)
	/* (struct Image *) BOOPSI image for the slider's body. */

#define SLIDER_Gradient      (SLIDER_Dummy+12L)
	/* (BOOL) Gradient slider mode? Defaults to FALSE. (OBSOLETE) */

#define SLIDER_PenArray      (SLIDER_Dummy+13L)
	/* (UWORD *) Pens for gradient slider. (OBSOLETE) */

#define SLIDER_Invert        (SLIDER_Dummy+14L)
	/* (BOOL) Flip Min/Max positions? Defaults to FALSE. */

#define SLIDER_KnobDelta     (SLIDER_Dummy+15L)
	/* (WORD) Level step when clicking in the container. */

#define SLIDER_LevelFormat   (SLIDER_Dummy+16L)
	/* (CONST_STRPTR) Format string for slider level display. (V47) */

#define SLIDER_LevelPlace    (SLIDER_Dummy+17L)
	/* (ULONG) Where to display the slider level, use the
	 * PLACETEXT_#? defines from libraries/gadtools.h. (V47) */

#define SLIDER_LevelJustify  (SLIDER_Dummy+18L)
	/* (ULONG) Justification of slider level display. (V47)*/

#define SLIDER_LevelDomain   (SLIDER_Dummy+19L)
	/* (CONST_STRPTR) Domain string to determine maximum level extent.
	 * (V47) */

#define SLIDER_LevelSpace    (SLIDER_Dummy+20L)
	/* (UWORD) Explicit specification of level display extent. (V47) */

#define SLIDER_LevelHook     (SLIDER_Dummy+21L)
	/* (struct Hook *) Hook which is invoked to pre-process the level
	 * value before it goes through the format string; object (A2) is
	 * the gadget, message (A1) is a taglist with GA_ID, SLIDER_Level,
	 * SLIDER_Min and SLIDER_Max. (V47) */

#define SLIDER_LevelMaxLen   (SLIDER_Dummy+22L)
	/* (UWORD) Maximum possible length (in characters) of level.
	 * Defaults to 3. (V47) */

#define SLIDER_NotifyDisable (SLIDER_Dummy+23L)
	/* (BOOL) Notify GA_Disabled attribute changes to target? Defaults
	 * to TRUE. (V47) */

#define SLIDER_InitDispHook  (SLIDER_Dummy+24L)
	/* (BOOL) Invoke SLIDER_DispHook immediately whenever a new hook
	 * function is passed to the gadget? Defaults to FALSE. (V47) */

/*****************************************************************************/

/* SLIDER_Orientation Modes
 */
#define SORIENT_HORIZ     FREEHORIZ
#define SORIENT_VERT      FREEVERT

#define SLIDER_HORIZONTAL SORIENT_HORIZ
#define SLIDER_VERTICAL   SORIENT_VERT

/* SLIDER_LevelJustify values
 */
#define SLJ_LEFT   0
#define SLJ_CENTER 1
#define SLJ_RIGHT  2

#endif /* GADGETS_SLIDER_H */
