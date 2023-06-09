#ifndef GADGETS_FUELGAUGE_H
#define GADGETS_FUELGAUGE_H
/*
**    $VER: fuelgauge.h 54.16 (22.08.2022)
**
**    Definitions for the fuelgauge.gadget BOOPSI class
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

/****************************************************************************/

#define FUELGAUGE_Dummy         (REACTION_Dummy + 0x12000)

#define FUELGAUGE_Min           (FUELGAUGE_Dummy + 1)
    /* (LONG) fuelgauge minimum value. */

#define FUELGAUGE_Max           (FUELGAUGE_Dummy + 2)
    /* (LONG) fuelgauge maximum value. */

#define FUELGAUGE_Level         (FUELGAUGE_Dummy + 3)
    /* (LONG) fuelgauge level (value between min and max). */

#define FUELGAUGE_Orientation   (FUELGAUGE_Dummy + 4)
    /* (WORD) orientation mode. */

#define FUELGAUGE_Percent       (FUELGAUGE_Dummy + 5)
    /* (BOOL) render numeric percentage display. */

#define FUELGAUGE_Ticks         (FUELGAUGE_Dummy + 6)
    /* (WORD) enable tick marks if number of ticks set is not 0. */

#define FUELGAUGE_ShortTicks    (FUELGAUGE_Dummy + 7)
    /* (WORD) enable small intermediate tick marks. */

#define FUELGAUGE_TickSize      (FUELGAUGE_Dummy + 8)
    /* (WORD) height of  large tick makrs. */

#define FUELGAUGE_TickPen       (FUELGAUGE_Dummy + 9)
    /* (WORD) tickmark pen. */

#define FUELGAUGE_PercentPen    (FUELGAUGE_Dummy + 10)
    /* (WORD) pen number to use for inner gauge percange rendering. */

#define FUELGAUGE_FillPen       (FUELGAUGE_Dummy + 11)
    /* (WORD) pen number to use for the fuelbar. */

#define FUELGAUGE_EmptyPen      (FUELGAUGE_Dummy + 12)
    /* (WORD) fuelgauge background/empty pen number. */

#define FUELGAUGE_VarArgs       (FUELGAUGE_Dummy + 13)
    /* argument array for GA_Text varargs string */

#define FUELGAUGE_Justification (FUELGAUGE_Dummy + 14)
    /* GA_Text justification mode */

/*****************************************************************************/

/* FUELGAUGE_Orientation modes
 */
#define FGORIENT_HORIZ 0
#define FGORIENT_VERT  1

/* FUELGAUGE_Justification modes
 */
#define FGJ_LEFT   0          /* default */
#define FGJ_CENTER 1
#define FGJ_CENTRE FGJ_CENTER / english/canadian spellings */

/* Obsolete, DO NOT USE!
 */
#define FUELGAUGE_HORIZONTAL FGORIENT_HORIZ
#define FUELGAUGE_VERTICAL   FGORIENT_VERT

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

#endif /* GADGETS_FUELGAUGE_H */
