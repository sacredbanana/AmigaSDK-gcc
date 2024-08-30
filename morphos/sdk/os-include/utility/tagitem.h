#ifndef UTILITY_TAGITEM_H
#define UTILITY_TAGITEM_H

/*
	utility.library tagitem defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#pragma pack(2)


typedef ULONG Tag;

struct TagItem
{
	Tag   ti_Tag;
	ULONG ti_Data;
};


#define TAG_DONE    (0L)
#define TAG_END     (0L)
#define TAG_IGNORE  (1L)
#define TAG_MORE    (2L)
#define TAG_SKIP    (3L)

#define TAG_USER    ((ULONG)(1<<31))


#define TAGFILTER_AND  0
#define TAGFILTER_NOT  1


#define MAP_REMOVE_NOT_FOUND  0
#define MAP_KEEP_NOT_FOUND    1


#pragma pack()

#endif /* UTILITY_TAGITEM_H */
