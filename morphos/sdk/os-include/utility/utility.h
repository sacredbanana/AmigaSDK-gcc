#ifndef UTILITY_UTILITY_H
#define UTILITY_UTILITY_H

/*
	utility.library include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#pragma pack(2)


#define UTILITYNAME  "utility.library"


struct UtilityBase
{
	struct Library ub_LibNode;
	UBYTE          ub_Language;
	UBYTE          ub_Reserved;
};


#pragma pack()

#endif /* UTILITY_UTILITY_H */
