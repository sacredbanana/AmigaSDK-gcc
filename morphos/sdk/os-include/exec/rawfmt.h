#ifndef EXEC_RAWFMT_H
#define EXEC_RAWFMT_H

/*
	exec rawfmt include (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/


/*
 * Used to act like sprintf
 */
#define RAWFMTFUNC_STRING  0

/*
 * Used to act like kprintf
 */
#define RAWFMTFUNC_SERIAL  1

/*
 * Used to count the chars needed.
 * PutChData = (ULONG*) to the counter
 */
#define	RAWFMTFUNC_COUNT   2


#endif
