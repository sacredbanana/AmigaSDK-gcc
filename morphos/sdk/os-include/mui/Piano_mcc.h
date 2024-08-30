#ifndef PIANO_MCC_H
#define PIANO_MCC_H

/*
 *  Piano.mcc
 *
 *  Copyright © 2015 Antoine Dubourg <tcheko@no-log.org>
 *  All rights reserved.
 *
 *  $Id: Piano_mcc.h,v 1.1 2015/10/31 10:31:49 tcheko Exp $
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#pragma pack(2)

#define MUIC_Piano  "Piano.mcc"
#define PianoObject MUI_NewObject(MUIC_Piano

/* Attributes */

#define MUIA_Piano_ReadOnly			0xFED90000 + 0	/* [ISG] BOOL set to true to discard user interactions */
#define MUIA_Piano_KeyColor			0xFED90000 + 1	/* [ISG] LONG Color 0x00RRGGBB */
#define MUIA_Piano_Octaves			0xFED90000 + 3	/* [ISG] LONG valid values range from 1 to 11 */
#define MUIA_Piano_OctaveBeginAt	0xFED90000 + 4	/* [ISG] LONG valid values range from 0 to 10 */

/* Values */

#define MUIV_Piano_KeyColor 		-2				/* Use the default color defined with Piano.mcp */

#define MUIV_Piano_KeyEvent_Down	1				/* status value set when a key is pressed */
#define MUIV_Piano_KeyEvent_Up		0				/* status value set when a key is released */

/* Methods */

#define MUIM_Piano_KeyEvent			0xFED90000 + 1	/* Subclass this method for handling user event with keyboard */
#define MUIM_Piano_KeyClear			0xFED90000 + 2	/* Clears all the selected keys in one go */

/* Method Structure Messages */

struct MUIP_Piano_KeyEvent
{
	ULONG methodid;
	LONG key;										/* value ranging from 0 to 127 included. */
	LONG status;									/* Set to 1 when key is pressed, 0 when key is released */
};

#pragma pack()

#endif /* PIANO_MCC_H */
