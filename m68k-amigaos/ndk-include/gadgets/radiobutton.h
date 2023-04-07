#ifndef GADGETS_RADIOBUTTON_H
#define GADGETS_RADIOBUTTON_H
/*
**	$VER: radiobutton.h 47.3 (27.7.2020)
**
**	Definitions for the radiobutton.gadget BOOPSI class
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

/* Defines for the radiobutton node attributes.
 */
#define RBNA_Dummy			(TAG_USER+0x020000)

#define RBNA_UserData			(RBNA_Dummy+1)
	/* (APTR) User Data. */

#define RBNA_Labels			(RBNA_Dummy+2) /* obsolete tagname */
#define RBNA_Label			(RBNA_Dummy+2)
    /* (STRPTR) Text string of the node. */

#define RBNA_HintInfo			(RBNA_Dummy+3) /* OS4ONLY */

#define RBNA_Disabled			(RBNA_Dummy+4) /* OS4ONLY */

/*****************************************************************************/

/* Additional attributes defined by the RadioButton class
 */
#define RADIOBUTTON_Dummy		(REACTION_Dummy + 0x14000)

#define	RADIOBUTTON_Labels		(RADIOBUTTON_Dummy+1)
	/* (struct List *) Radio Button Label List. */

#define	RADIOBUTTON_Strings		(RADIOBUTTON_Dummy+2)
	/* RESERVED - presently unsupported */

#define	RADIOBUTTON_Spacing		(RADIOBUTTON_Dummy+3)
	/* (WORD) Spacing between radio buttons */

#define	RADIOBUTTON_Selected		(RADIOBUTTON_Dummy+4)
	/* (WORD) selected radio button (OM_GET/OM_SET/OM_NOTIFY) */

#define	RADIOBUTTON_LabelPlace		(RADIOBUTTON_Dummy+5)
	/* (WORD) label location (OM_GET/OM_SET) */

#define	RADIOBUTTON_LabelArray		(RADIOBUTTON_Dummy+6) /* OS4ONLY */

/*****************************************************************************/

#endif /* GADGETS_RADIOBUTTON_H */
