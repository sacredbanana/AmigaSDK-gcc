#ifndef GADGETS_SPACE_H
#define GADGETS_SPACE_H
/*
**    $VER: space.h 54.16 (22.08.2022)
**
**    Definitions for the space.gadget BOOPSI class
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

/* Additional attributes defined by the space.gadget class */

#define SPACE_Dummy       (REACTION_Dummy + 0x9000)

#define SPACE_MinHeight   (SPACE_Dummy+1)
    /* (WORD) Height of space gadget
       (OM_NEW,OM_SET,OM_UPDATE,OM_GET) */

#define SPACE_MinWidth    (SPACE_Dummy+2)
    /* (WORD) Width of space gadget
       (OM_NEW,OM_SET,OM_UPDATE,OM_GET) */

#define SPACE_MouseX      (SPACE_Dummy+3)
    /* (WORD) X Position of Mouse within space gadget
       (OM_NOTIFY) */

#define SPACE_MouseY      (SPACE_Dummy+4)
    /* (WORD) Y Position of Mouse within space gadget
       (OM_NOTIFY) */

#define SPACE_Transparent (SPACE_Dummy+5)
    /* (BOOL) Will not EraseRect() background before redraw if true.
       (OM_NEW,OM_SET,OM_UPDATE) */

#define SPACE_AreaBox     (SPACE_Dummy+6)
    /* (struct IBox **) Inner area IBox application rendering bounds
       (OM_GET) */

#define SPACE_RenderHook  (SPACE_Dummy+7)
    /* (struct Hook *) render hook is called when the gadget refreshes.
       (OM_NEW,OM_SET,OM_UPDATE) */

#define SPACE_BevelStyle  (SPACE_Dummy+8)
    /* (WORD) Defaults to BVS_NONE (no bevel - see images/bevel.h)
       (OM_NEW,OM_SET,OM_UPDATE) */
     
#define SPACE_DomainBevel (SPACE_Dummy+9)
    /* (BOOL) take size of bevel into account when calculating
       the gadget size. Defaults to FALSE. (V50)
       (OM_NEW,OM_SET,OM_UPDATE) */

#define SPACE_RenderBox   (SPACE_Dummy+10)
    /* (struct IBox *) Inner area IBox application rendering bounds (V53.6) */

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

#endif /* GADGETS_SPACE_H */
