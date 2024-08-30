#ifndef	LIBRARIES_WHATIS_H
#define	LIBRARIES_WHATIS_H	1

/*
**	$Filename: libraries/whatisbase.h $
**	$Release: 3
**	$Revision: 2 $
**	$Date: 92/12/13 $
**
**	(C) Copyright 1990,1992 S.R. & P.C.
**		All Rights Reserved
*/

#include <utility/TagItem.h>

/*  For  some  technical reason, user of version 1 ( for Pro-2.x KickStart)
MUST open Arp.library ( if needed ) AFTER whatis.library */

/*
 *	After thinking a lot I decided to define a new type, this allow maximum
 *	control by compiler. If you have reason against that, please let me know.
 */

typedef ULONG FileType; /* the magic number you get after a WhatIs() */

#define TYPE_UNSCANNED 0L	/* we haven't look what is this file */
#define TYPE_UNKNOWNFILETYPE 0x0000FFFE
#define TYPE_UNKNOWNIDSTRING 0xFFFFFFFF
/*
 *	The FileType you get have an internal private format.
 *	Assume anything about it, it can change !
 *	The only thing you can be sure: if == 0L: you didn't call WhatIs (type is Unscanned)
 */

/* the 2 scan type actualy possible */
#define LIGHTTYPE	0
#define DEEPTYPE	1

/*
 *	Tags for WhatIs():
 *	More information you pass, less whatis.library make mistake.
 *	In DEEP mode whatis.library look for this information if you don't pass to it.
 */
#define WI_FIB		(TAG_USER + 202)	/* TagItem.ti_data = struct FileInfoBlock *FIB, default = NULL */
#define WI_Deep 	(TAG_USER + 203)	/* TagItem.ti_data = UBYTE Deep, default = 0 */
#define WI_Buffer	(TAG_USER + 204)	/* TagItem.ti_data = Buffer ptr WARNING: your buffer MUST be NULL terminated */
#define WI_BufLen	(TAG_USER + 205)	/* TagItem.ti_data = Buffer Len */
#define WI_DLX		(TAG_USER + 206)	/* TagItem.ti_data = DLX_numble, found in ArpBase.h */
/* Version 2.1 or higher */
#define WI_DLT 		(TAG_USER + 207)	/* TagItem.ti_data = DLT_numble, found in DOS 2.0 */

#define WBF_UPDATEFILETYPE 0x01


/* Note:  About private field, there are here only for debuging, if you use
it,  I  remove it (like Commodore do for IntuitionBase) so be a Good Boy...
Also, I promise you that for each revision, I MOVE ALL private field, you'll be warned...
*/
struct WhatIsBase
{
	/* Public field */
	struct Library Lib;

	/* Next Field are private for Author */
	ULONG  SegList;					/* seg list of lib itself */

	/* Specific field to WhatIs */
	UWORD NumType;
	struct Remember *TypeListMem;	/* You MUST allocate string, and ID tagArray whith that */
	struct MinList TypeList;
	struct WhatIs **TypeArray;
	ULONG Flags;
};

#endif

