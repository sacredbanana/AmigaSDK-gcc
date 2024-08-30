#ifndef PREFS_PREFHDR_H
#define PREFS_PREFHDR_H

/*
	prefs header definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#pragma pack(2)


#define ID_PREF  MAKE_ID('P','R','E','F')
#define ID_PRHD  MAKE_ID('P','R','H','D')


struct PrefHeader
{
	UBYTE ph_Version;
	UBYTE ph_Type;
	ULONG ph_Flags;
};


#pragma pack()

#endif /* PREFS_PREFHDR_H */
