#ifndef PREFS_ASL_H
#define PREFS_ASL_H
/*
**	$VER: asl.h 47.1 (2.8.2019)
**
**	File format for ASL ("application support library") preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/


#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#ifndef LIBRARIES_ASL_H
#include <libraries/asl.h>
#endif


/*****************************************************************************/


#define ID_ASL MAKE_ID('A','S','L',' ')


struct AslPrefs
{
	LONG	ap_Reserved[4];

	/* These members correspond directly to the associated
	 * members of the 'AslSemaphore' data structure defined
	 * in the <libraries/asl.h> header file by the same names.
	 */
	UBYTE	ap_SortBy;
	UBYTE	ap_SortDrawers;
	UBYTE	ap_SortOrder;

	UBYTE	ap_SizePosition;

	WORD	ap_RelativeLeft;
	WORD	ap_RelativeTop;

	UBYTE	ap_RelativeWidth;
	UBYTE	ap_RelativeHeight;
};


/*****************************************************************************/


#endif /* PREFS_ASL_H */
