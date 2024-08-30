/*
 * $Id: fs_md5.h,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 * :ts=4
 *
 * Amiga ROM file system reimplementation
 * Copyright © 2001-2005 by Olaf Barthel
 * All Rights Reserved
 */

#ifndef _FS_MD5_H
#define _FS_MD5_H

/****************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif /* EXEC_TYPES_H */

/****************************************************************************/

struct md5_context
{
	ULONG	md5_X[16];
	LONG	md5_NumBytesInBuffer;
	ULONG	md5_ABCD[4];
	LONG	md5_NumBytesProcessed;
};

/****************************************************************************/

void md5_init(struct md5_context *md5);
void md5_update(struct md5_context *md5, UBYTE *data, LONG len);
void md5_final(struct md5_context *md5, UBYTE *digest);

/****************************************************************************/

#endif /* _FS_MD5_H */
