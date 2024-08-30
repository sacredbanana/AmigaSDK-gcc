#ifndef GADGETS_SCROLLER_H
#define GADGETS_SCROLLER_H
/*
**    $VER: scroller.h 54.16 (22.08.2022)
**
**    Definitions for the scroller.gadget BOOPSI class
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

/* Additional attributes defined by the scroller.gadget class */

#define SCROLLER_Dummy         (REACTION_Dummy+0x0005000)

#define SCROLLER_Top           (SCROLLER_Dummy+1L)
    /* (WORD) scroller Top value (Defaults to 0). */

#define SCROLLER_Visible       (SCROLLER_Dummy+2L)
    /* (WORD) visible part of total. */

#define SCROLLER_Total         (SCROLLER_Dummy+3L)
    /* (WORD) total scroller size. */

#define SCROLLER_Orientation   (SCROLLER_Dummy+4L)
    /* (WORD) Vertical or Horizontal mode. */

#define SCROLLER_Arrows        (SCROLLER_Dummy+5L)
    /* (BOOL) Render arrows. */

#define SCROLLER_Stretch       (SCROLLER_Dummy+6L)
    /* (BOOL) AutoExpand/Stretch Total. */

#define SCROLLER_ArrowDelta    (SCROLLER_Dummy+7L)
    /* (WORD) Change arrow click makes. */

#define SCROLLER_SignalTask    (SCROLLER_Dummy+10L)
    /* (struct Task *) Signal this Task while scroller is active */

#define SCROLLER_SignalTaskBit (SCROLLER_Dummy+11L)
    /* (ULONG) Signal with this Bit. */

/*****************************************************************************/

/* SCROLLER_Orientation Modes */

#define SORIENT_HORIZ       FREEHORIZ
#define SORIENT_VERT        FREEVERT

#define SCROLLER_HORIZONTAL SORIENT_HORIZ
#define SCROLLER_VERTICAL   SORIENT_VERT

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

#endif /* GADGETS_SCROLLER_H */
