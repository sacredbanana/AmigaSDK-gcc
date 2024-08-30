#ifndef DOS_EXALL_H
#define DOS_EXALL_H

/*
	dos ExAll definitions

	Copyright © 2002-2003 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#pragma pack(2)


#define ED_NAME        1
#define ED_TYPE        2
#define ED_SIZE        3
#define ED_PROTECTION  4
#define ED_DATE        5
#define ED_COMMENT     6
#define ED_OWNER       7


/* 64bit DOS extensions - V51 */

/* The ExAllData ed_Size64 field is filled. For files larger than 2^31-1
 * bytes, ed_Size is 0.
 */
#define ED_SIZE64      8


struct ExAllData
{
	struct ExAllData *ed_Next;
	UBYTE            *ed_Name;
	LONG              ed_Type;
	ULONG             ed_Size;
	ULONG             ed_Prot;
	ULONG             ed_Days;
	ULONG             ed_Mins;
	ULONG             ed_Ticks;
	UBYTE            *ed_Comment;

	UWORD             ed_OwnerUID;
	UWORD             ed_OwnerGID;

	/* 64bit DOS extensions - V51 */

	/* Filled for ED_SIZE64 */
	UQUAD             ed_Size64;
};

struct ExAllControl
{
	ULONG        eac_Entries;
	ULONG        eac_LastKey;
	UBYTE       *eac_MatchString;
	struct Hook *eac_MatchFunc;
};


#pragma pack()

#endif /* DOS_EXALL_H */
