#ifndef GADGETS_SLIDER_H
#define GADGETS_SLIDER_H
/*
**    $VER: slider.h 54.16 (22.08.2022)
**
**    Definitions for the slider.gadget BOOPSI class
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

#ifndef  LIBRARIES_GADTOOLS_H
#include <libraries/gadtools.h>
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

/****************************************************************************/

/* Additional attributes defined by the slider.gadget class */

#define SLIDER_Dummy         (REACTION_Dummy+0x0028000)

#define SLIDER_Min           (SLIDER_Dummy+1L)
    /* (WORD) Minimum slider level. */

#define SLIDER_Max           (SLIDER_Dummy+2L)
    /* (WORD) Maximum slider level. */

#define SLIDER_Level         (SLIDER_Dummy+3L)
    /* (WORD) Current slider level. */

#define SLIDER_Orientation   (SLIDER_Dummy+4L)
    /* (WORD) Orientation of slider. */

#define SLIDER_DispHook      (SLIDER_Dummy+5L)
    /* (struct Hook *) Hook which is invoked whenever the
       slider's level changes; object is the gadget, message
       is a taglist with GA_ID, SLIDER_Level, SLIDER_Min,
       SLIDER_Max and GA_UserInput. */

#define SLIDER_Ticks         (SLIDER_Dummy+6L)
    /* (LONG) Display ticks along slider body? */

#define SLIDER_ShortTicks    (SLIDER_Dummy+7L)
    /* (BOOL) Alternate long and short ticks? */

#define SLIDER_TickSize      (SLIDER_Dummy+8L)
    /* (WORD) Size of slider ticks. */

#define SLIDER_KnobImage     (SLIDER_Dummy+9L)
    /* (struct Image *) Image for slider knob. */

#define SLIDER_BodyFill      (SLIDER_Dummy+10L)
    /* (WORD) NOT IMPLEMENTED YET. */

#define SLIDER_BodyImage     (SLIDER_Dummy+11L)
    /* (struct Image *) Image for slider body. */

#define SLIDER_Gradient      (SLIDER_Dummy+12L)
    /* (BOOL) Gradient slider mode. Defaults to FALSE. */

#define SLIDER_PenArray      (SLIDER_Dummy+13L)
    /* (UWORD *) Pens for gradient slider. */

#define SLIDER_Invert        (SLIDER_Dummy+14L)
    /* (BOOL) Flip Min/Max positions. Defaults to FALSE. */

#define SLIDER_KnobDelta     (SLIDER_Dummy+15L)
    /* (WORD) Level step when clicking in the container. */

#define SLIDER_LevelFormat   (SLIDER_Dummy+16L)
    /* (STRPTR) Format string for slider level display. (V50) */

#define SLIDER_LevelPlace    (SLIDER_Dummy+17L)
    /* (ULONG) Where to display the slider level, use the
     * PLACETEXT_#? defines from libraries/gadtools.h. (V50) */

#define SLIDER_LevelJustify  (SLIDER_Dummy+18L)
    /* (ULONG) Justification of slider level display. (V50)*/

#define SLIDER_LevelDomain   (SLIDER_Dummy+19L)
    /* (STRPTR) Domain string to determine maximum level extent. (V50) */

#define SLIDER_LevelSpace    (SLIDER_Dummy+20L)
    /* (UWORD) Explicit specification of level display extent. (V50) */

#define SLIDER_LevelHook     (SLIDER_Dummy+21L)
    /* (struct Hook *) Hook which is invoked to pre-process the level
       value before it goes through the format string; object is the
       slider gadget, message is a taglist with GA_ID, SLIDER_Level,
       SLIDER_Min and SLIDER_Max. (V50) */

#define SLIDER_LevelMaxLen   (SLIDER_Dummy+22L)
    /* (UWORD) Maximum possible length (in characters) of level. (V50) */

#define SLIDER_NotifyDisable (SLIDER_Dummy+23L)
    /* (BOOL) Notify GA_Disabled attribute changes to target? (V50) */

#define SLIDER_InitDispHook  (SLIDER_Dummy+24L)
    /* (BOOL) Call SLIDER_DispHook whenever a new
       hookfunction is passed to the gadget. (V50)
       Defaults to FALSE. */

/*****************************************************************************/

/* SLIDER_Orientation Modes */
#define SORIENT_HORIZ     FREEHORIZ
#define SORIENT_VERT      FREEVERT

#define SLIDER_HORIZONTAL SORIENT_HORIZ
#define SLIDER_VERTICAL   SORIENT_VERT

/* SLIDER_LevelJustify values */

#define SLJ_LEFT   0
#define SLJ_CENTER 1
#define SLJ_RIGHT  2

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

#endif /* GADGETS_SLIDER_H */
