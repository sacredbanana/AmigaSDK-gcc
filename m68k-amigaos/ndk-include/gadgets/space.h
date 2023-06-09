#ifndef GADGETS_SPACE_H
#define GADGETS_SPACE_H
/*
**	$VER: space.h 47.1 (1.9.2019)
**
**	Definitions for the space.gadget BOOPSI class
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

/* Additional attributes defined by the space.gadget class
 */

#define SPACE_Dummy		(REACTION_Dummy + 0x9000)

#define SPACE_MinHeight		(SPACE_Dummy+1)
    /* (WORD) Height of space gadget
     * (OM_NEW,OM_SET,OM_UPDATE,OM_GET) */

#define SPACE_MinWidth		(SPACE_Dummy+2)
    /* (WORD) Width of space gadget
     * (OM_NEW,OM_SET,OM_UPDATE,OM_GET) */

#define SPACE_MouseX		(SPACE_Dummy+3)
    /* (WORD) X Position of Mouse within space gadget
     * (OM_NOTIFY) */

#define SPACE_MouseY		(SPACE_Dummy+4)
    /* (WORD) Y Position of Mouse within space gadget
     * (OM_NOTIFY) */

#define SPACE_Transparent	(SPACE_Dummy+5)
    /* (BOOL) Will not EraseRect() background before redraw if true.
     * (OM_NEW,OM_SET,OM_UPDATE) */

#define SPACE_AreaBox		(SPACE_Dummy+6)
    /* (struct IBox *) Inner area IBox application rendering bounds
     * (OM_GET) */

#define SPACE_RenderHook	(SPACE_Dummy+7)
    /* (struct Hook *) render hook is called when the gadget refreshes.
     * a0: struct Hook *, a2: Object *, a1: struct gpRender *
     * (OM_NEW,OM_SET,OM_UPDATE) */

#define SPACE_BevelStyle	(SPACE_Dummy+8)
    /* (WORD) Defaults to BVS_NONE (no bevel - see images/bevel.h)
     * !!! broken before 45.1 !!!
     * (OM_NEW,OM_SET,OM_UPDATE) */

#define SPACE_DomainBevel	(SPACE_Dummy+9)
    /* (BOOL) take size of bevel into account when calculating
       the gadget size. Defaults to FALSE. (V50)
       (OM_NEW,OM_SET,OM_UPDATE) */

#define SPACE_RenderBox		(SPACE_Dummy+10) /* OS4ONLY */

/*****************************************************************************/

#endif /* GADGETS_SPACE_H */
