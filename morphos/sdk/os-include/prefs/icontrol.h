#ifndef PREFS_ICONTROL_H
#define PREFS_ICONTROL_H

/*
	icontrol prefs definitions

	Copyright ? 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#pragma pack(2)


#define ID_ICTL  MAKE_ID('I','C','T','L')

struct IControlPrefs
{
	LONG  ic_Reserved[4];
	UWORD ic_TimeOut;
	WORD  ic_MetaDrag;
	ULONG ic_Flags;	
	UBYTE ic_WBtoFront;
	UBYTE ic_FrontToBack;
	UBYTE ic_ReqTrue;
	UBYTE ic_ReqFalse;
};

#define ICB_COERCE_COLORS        0
#define ICB_COERCE_LACE          1
#define ICB_STRGAD_FILTER        2
#define ICB_MENUSNAP             3
#define ICB_MODEPROMOTE          4
#define ICB_SQUARE_RATIO         5


#define ICF_COERCE_COLORS        (1<<ICB_COERCE_COLORS)
#define ICF_COERCE_LACE          (1<<ICB_COERCE_LACE)
#define ICF_STRGAD_FILTER        (1<<ICB_STRGAD_FILTER)
#define ICF_MENUSNAP             (1<<ICB_MENUSNAP)
#define ICF_MODEPROMOTE          (1<<ICB_MODEPROMOTE)
#define ICF_SQUARE_RATIO         (1<<ICB_SQUARE_RATIO)




#pragma pack()

#endif /* PREFS_ICONTROL_H */
