#ifndef CLASSES_DATA_ISO639_H
#define CLASSES_DATA_ISO639_H

/*
**  $VER: iso639.h 52.0 (29.9.2011)
**
**  Copyright © 2011 The MorphOS Development Team, All Rights Reserved.
**
**/

#ifndef CLASSES_DATA_DATA_H
# include <classes/data/data.h>
#endif

/*****************************************************************************/

typedef struct
{
	CONST_STRPTR Language;
	CONST_STRPTR Alpha2;
	CONST_STRPTR Alpha3B;
	CONST_STRPTR Alpha3T;
} iso639_entry;

/*****************************************************************************/

#define ISO639M_FindEntry  DATAM_FindEntry
#define ISO639M_NextEntry  DATAM_NextEntry
#define ISO639A_EntryCount DATAA_EntryCount

#define DATA_EntryType_ISO639_Alpha2   1
#define DATA_EntryType_ISO639_Alpha3   2
#define DATA_EntryType_ISO639_Language 4

struct ISO639P_FindEntry { ULONG MethodID; ULONG Type; CONST_STRPTR Definition; };
struct ISO639P_NextEntry { ULONG MethodID; APTR  Previous; };

/*****************************************************************************/

#endif /* CLASSES_DATA_ISO639_H */
