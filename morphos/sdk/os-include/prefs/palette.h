#ifndef PREFS_PALETTE_H
#define PREFS_PALETTE_H

/*
	palette prefs definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#pragma pack(2)


#define ID_PALT  MAKE_ID('P','A','L','T')


struct PalettePrefs
{
	LONG             pap_Reserved[4];
	UWORD            pap_4ColorPens[32];
	UWORD            pap_8ColorPens[32];
	struct ColorSpec pap_Colors[32];
};


#pragma pack()

#endif /* PREFS_PALETTE_H */
