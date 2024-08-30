#ifndef DOS_SEGTRACKER_H
#define DOS_SEGTRACKER_H

/*
	dos.library segtracker include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_SEMAPHORES_H
# include <exec/semaphores.h>
#endif


#pragma pack(2)


#define SEG_SEM "SegTracker"


/*
 * The SegTracker seg_Find function calling convention:
 *
 * STRPTR seg_Find(ULONG Address, ULONG *SegNum, ULONG *Offset)
 * D0              A0             A1             A2
 *
 * For given 'Address' seg_Find returns NULL or the segment name.
 * If non-NULL is returned, ULONG pointed by 'SegNum' and 'Offset'
 * hold the segment number and the offset within this segment.
 * To get seglist pointer, pass same pointer to 'SegNum' and
 * 'Offset'.
 */

/*
 * NOTE: For native MorphOS code you should use sysdebug.library
 * SysDebugFindSeg(), it has the same prototype as above, but uses
 * native calling convention instead (and no semaphore-locking is
 * required).
 */

struct SegSem
{
	struct SignalSemaphore   seg_Semaphore;
	STRPTR                 (*seg_Find)(VOID);
	/* Do not make any assumption about other content of
	   this structure. */
};


#pragma pack()

#endif /* DOS_SEGTRACKER_H */
