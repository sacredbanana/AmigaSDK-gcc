#ifndef GADGETS_CHECKBOX_H
#define GADGETS_CHECKBOX_H
/*
**    $VER: checkbox.h 54.16 (22.08.2022)
**
**    Definitions for the checkbox.gadget BOOPSI class
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

/* Additional attributes defined by the checkbox.gadget class */
#define CHECKBOX_Dummy         (REACTION_Dummy + 0x11000)

#define CHECKBOX_TextPen       (CHECKBOX_Dummy+1)
    /* (WORD) Pen to use for text (~0 uses TEXTPEN). */

#define CHECKBOX_FillTextPen   (CHECKBOX_Dummy+2)
    /* (WORD) Pen to use for fill (~0 uses FILLTEXTPEN). */

#define CHECKBOX_BackgroundPen (CHECKBOX_Dummy+3)
    /* (WORD) Pen to use for background (~0 uses BACKGROUNDPEN) */

#define CHECKBOX_BevelStyle    (CHECKBOX_Dummy+4)
    /* (WORD) Optional outer bevel style - OBSOLETE */

#define CHECKBOX_TextPlace     (CHECKBOX_Dummy+5)
    /* (LONG) Gadget Text Location (PLACETEXT_LEFT or PLACETEXT_RIGHT). */

#define CHECKBOX_Checked       GA_Selected
    /* (BOOL) Checkmark state. */

#define CHECKBOX_Invert        (CHECKBOX_Dummy+6)
    /* (BOOL) CheckMark state: TRUE is FALSE and FALSE is TRUE. V50. */

/*****************************************************************************/

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

#endif /* GADGETS_CHECKBOX_H */
