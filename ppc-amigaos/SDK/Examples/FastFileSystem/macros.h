/*
 *	$Id: macros.h,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 *	:ts=4
 *
 *	Amiga ROM file system reimplementation
 *	Copyright © 2001-2005 by Olaf Barthel
 *	All Rights Reserved
 *
 *	"But, for my own part, it was Greek to me."
 */

#ifndef _MACROS_H
#define _MACROS_H

/****************************************************************************/

typedef unsigned char flag_t;

/****************************************************************************/

#ifndef EXEC_EXECBASE_H
#include <exec/execbase.h>
#endif /* EXEC_EXECBASE_H */

#ifndef AbsExecBase
#define AbsExecBase (*(struct ExecBase **)4)
#endif /* AbsExecBase */

/****************************************************************************/

#ifndef EXEC_IO_H
#include <exec/io.h>
#endif /* EXEC_IO_H */

#ifndef BUSY
#define BUSY ((struct IORequest *)NULL)
#endif /* BUSY */

/****************************************************************************/

#ifndef ID_LONGNAME_DOS_DISK
#define ID_LONGNAME_DOS_DISK (0x444F5306) /* 'DOS\6' */
#endif /* ID_LONGNAME_DOS_DISK */

#ifndef ID_LONGNAME_FFS_DISK
#define ID_LONGNAME_FFS_DISK (0x444F5307) /* 'DOS\7' */
#endif /* ID_LONGNAME_FFS_DISK */

#ifndef ID_BUSY_DISK
#define ID_BUSY_DISK 0x42555359 /* 'BUSY' */
#endif /* ID_BUSY_DISK */

/****************************************************************************/

#ifndef ACTION_GET_DISK_FSSM
#define ACTION_GET_DISK_FSSM 4201
#endif /* ACTION_GET_DISK_FSSM */

#ifndef ACTION_FREE_DISK_FSSM
#define ACTION_FREE_DISK_FSSM 4202
#endif /* ACTION_FREE_DISK_FSSM */

/****************************************************************************/

#define NO !
#define NOT !
#define CANNOT !
#define SAME (0)

/****************************************************************************/

#define NUM_ENTRIES(t) (sizeof(t) / sizeof(t[0]))

/****************************************************************************/

#ifndef ZERO
#define ZERO ((BPTR)NULL)
#endif /* ZERO */

/****************************************************************************/

#define BIT_IS_SET(l,b)		((((ULONG)l) & (1UL << (b))) != 0)
#define BIT_IS_CLEAR(l,b)	((((ULONG)l) & (1UL << (b))) == 0)

#define SET_BIT(l,b)		((VOID)(l |=  (1UL << (b))))
#define CLEAR_BIT(l,b)		((VOID)(l &= ~(1UL << (b))))

/****************************************************************************/

#define FLAG_IS_SET(l,f)	((((ULONG)l) & (f)) == (f))
#define FLAG_IS_CLEAR(l,f)	((((ULONG)l) & (f)) ==  0 )

/****************************************************************************/

#define IS_ODD(v) (((v) & 1) != 0)

/****************************************************************************/

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif /* min */

#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif /* max */

/****************************************************************************/

#if defined(__GNUC__)
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif /* __GNUC__ */

/****************************************************************************/

#define NOTHING ((void)0)

/****************************************************************************/

#endif /* _MACROS_H */
