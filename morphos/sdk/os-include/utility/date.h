#ifndef UTILITY_DATE_H
#define UTILITY_DATE_H

/*
	utility.library date defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


struct ClockData
{
	UWORD sec;
	UWORD min;
	UWORD hour;
	UWORD mday;
	UWORD month;
	UWORD year;
	UWORD wday;
};


#pragma pack()

#endif /* UTILITY_DATE_H */
