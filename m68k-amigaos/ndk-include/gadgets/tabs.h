#ifndef	GADGETS_TABS_H
#define	GADGETS_TABS_H

/*
**	$VER: tabs.h 47.2 (1.9.2019)
**
**	Definitions for the tabs BOOPSI gadget class
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

/*****************************************************************************/

#define	TL_TEXTPEN		0
#define	TL_BACKGROUNDPEN	1
#define	TL_FILLTEXTPEN		2
#define	TL_FILLPEN		3
#define	MAX_TL_PENS		4

/*****************************************************************************/

/* This structure is used to describe the labels for each of the tabs */
typedef struct tagTabLabel
{
    STRPTR		 tl_Label;		/* Label */
    WORD		 tl_Pens[MAX_TL_PENS];	/* Pens */
    struct TagItem	*tl_Attrs;		/* Additional attributes */

} TabLabel, *TabLabelP;

/*****************************************************************************/

/* Additional attributes defined by the tabs.gadget class */
#define TABS_Dummy		(TAG_USER+0x04000000)

#define	TABS_Labels		(TABS_Dummy+1)
    /* (TabLabelP) Array of labels */

#define	TABS_Current		(TABS_Dummy+2)
    /* (LONG) Current tab */

/*****************************************************************************/

#endif /* GADGETS_TABS_H */
