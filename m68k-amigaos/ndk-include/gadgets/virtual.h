#ifndef GADGETS_VIRTUAL_H
#define GADGETS_VIRTUAL_H
/*
**	$VER: virtual.h 47.4 (18.6.2020)
**
**	Definitions for the virtual.gadget BOOPSI class
**
**	(C) Copyright 2001 Stephan Rupprecht
**	    All Rights Reserved
*/

/*****************************************************************************/

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

/*****************************************************************************/

/* Additional attributes defined by the virtual.gadget class
 */

#define VIRTUALA_Base			(REACTION_Dummy + 0x24500)

#define VIRTUALA_Contents		(VIRTUALA_Base + 0)
	/* (Object *) [IS] */
	 
#define VIRTUALA_Scroller		(VIRTUALA_Base + 1)
	/* (BOOL) [IS] */
	
#define VIRTUALA_ScrollX		(VIRTUALA_Base + 2)
	/* (WORD) [ISU] */
	
#define VIRTUALA_ScrollY		(VIRTUALA_Base + 3)
	/* (WORD) [ISU] */
		
#define VIRTUALA_VisibleX		(VIRTUALA_Base + 4)
	/* (WORD) [GN] */
	
#define VIRTUALA_VisibleY		(VIRTUALA_Base + 5)
	/* (WORD) [GN] */
	
#define VIRTUALA_TopX			(VIRTUALA_Base + 6)
	/* (WORD) [ISUGN] */
	
#define VIRTUALA_TopY			(VIRTUALA_Base + 7)
	/* (WORD) [ISUGN] */
		
#define VIRTUALA_TotalX			(VIRTUALA_Base + 8)
	/* (WORD) [GN] */
	
#define VIRTUALA_TotalY			(VIRTUALA_Base + 9)
	/* (WORD) [GN] */
	
#define VIRTUALA_ScrollerX		(VIRTUALA_Base + 10)
	/* (Object *) [I] */
	
#define VIRTUALA_ScrollerY		(VIRTUALA_Base + 11)
	/* (Object *) [I] */
	
#define VIRTUALA_InputScroll		(VIRTUALA_Base + 12)
	/* (BOOL) [IS] */
	
#define VIRTUALA_NoDispose		(VIRTUALA_Base + 13)
	/* (BOOL) [IS] */

#define VIRTUALA_TargetX		(VIRTUALA_Base + 14) /* OS4ONLY */

#define VIRTUALA_TargetY		(VIRTUALA_Base + 15) /* OS4ONLY */

#define VIRTUALA_MapX			(VIRTUALA_Base + 16) /* OS4ONLY */

#define VIRTUALA_MapY			(VIRTUALA_Base + 17) /* OS4ONLY */

/*****************************************************************************/

#endif /* GADGETS_VIRTUAL_H */
