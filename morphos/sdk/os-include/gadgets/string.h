#ifndef GADGETS_STRING_H
#define GADGETS_STRING_H

/*
	string.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/*** V44 ***/

#define STRINGA_MinVisible    (REACTION_Dummy + 0x0055000) 
#define STRINGA_HookType      (REACTION_Dummy + 0x0055001)

/*** V45 ***/

#define STRINGA_GetBlockPos   (REACTION_Dummy + 0x0055010)
#define STRINGA_Mark          (REACTION_Dummy + 0x0055011)
#define STRINGA_AllowMarking  (REACTION_Dummy + 0x0055012) 


/* STRINGA_HookType types */

#define SHK_CUSTOM       0
#define SHK_PASSWORD     1
#define SHK_IPADDRESS    2
#define SHK_FLOAT        3
#define SHK_HEXADECIMAL  4
#define SHK_TELEPHONE    5
#define SHK_POSTALCODE   6
#define SHK_AMOUNT       7
#define SHK_UPPERCASE    8

/*** V45 ***/

#define SHK_HOTKEY       9


/* Typo fix */

#define SHK_HEXIDECIMAL  SHK_HEXADECIMAL


#endif /* GADGETS_STRING_H */
