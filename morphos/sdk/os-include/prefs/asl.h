#ifndef PREFS_ASL_H
#define PREFS_ASL_H

/*
	asl.library prefs definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#ifndef LIBRARIES_ASL_H
# include <libraries/asl.h>
#endif

#pragma pack(2)


#define ID_ASL  MAKE_ID('A','S','L',' ')


struct AslPrefs
{
	LONG  ap_Reserved[4];

	UBYTE ap_SortBy;
	UBYTE ap_SortDrawers;
	UBYTE ap_SortOrder;

	UBYTE ap_SizePosition;

	WORD  ap_RelativeLeft;
	WORD  ap_RelativeTop;

	UBYTE ap_RelativeWidth;
	UBYTE ap_RelativeHeight;
};


#pragma pack()

#endif /* PREFS_ASL_H */
