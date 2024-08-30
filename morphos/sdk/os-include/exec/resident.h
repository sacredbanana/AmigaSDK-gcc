#ifndef EXEC_RESIDENT_H
#define EXEC_RESIDENT_H

/*
	exec resident definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


struct Resident
{
	UWORD            rt_MatchWord;
	struct Resident *rt_MatchTag;
	APTR             rt_EndSkip;
	UBYTE            rt_Flags;
	UBYTE            rt_Version;
	UBYTE            rt_Type;
	BYTE             rt_Pri;
	char            *rt_Name;
	char            *rt_IdString;
	APTR             rt_Init;
	/*
	 * Only valid when RTF_EXTENDED is set
	 */
	UWORD            rt_Revision;	/* Revision Entry */
	struct TagItem  *rt_Tags;
};

#define RTC_MATCHWORD  (0x4AFC)


#define RTF_AUTOINIT    (1 << 7)
#define RTF_EXTENDED    (1 << 6)	/* structure extension is valid */
/* rt_Init points to a PPC function which must be defined as
 *
 * struct Library* LIB_Init(struct Library  *MyLibBase,
 *                          BPTR             SegList,
 *                          struct ExecBase *SysBase)
 */
#define RTF_PPC         (1 << 3)
#define RTF_AFTERDOS    (1 << 2)
#define RTF_SINGLETASK  (1 << 1)
#define RTF_COLDSTART   (1 << 0)

#define RTW_NEVER      0
#define RTW_COLDSTART  1


#pragma pack()

#endif
