/*
 *  This file is part of ixemul.library for the Amiga.
 *  Copyright (C) 2026 Harry Sintonen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef _SYS_STATVFS_H_
#define _SYS_STATVFS_H_

#include <sys/cdefs.h>
#include <sys/types.h>

struct statvfs
{
	fsblkcnt_t    f_bavail;   /* Number of free blocks available to
	                             non-privileged process. */
	fsblkcnt_t    f_bfree;    /* Total number of free blocks. */
	fsblkcnt_t    f_blocks;   /* Total number of blocks on file system in units of f_frsize. */
	fsfilcnt_t    f_favail;   /* Number of file serial numbers available to
	                             non-privileged process. */
	fsfilcnt_t    f_ffree;    /* Total number of free file serial numbers. */
	fsfilcnt_t    f_files;    /* Total number of file serial numbers. */
	unsigned long f_bsize;    /* File system block size */
	unsigned long f_flag;     /* Bit mask of f_flag values. */
	unsigned long f_frsize;   /* Fundamental file system block size. */
	unsigned long f_fsid;     /* File system ID. */
	unsigned long f_namemax;  /* Maximum filename length. */

	unsigned long f_extsize;  /* Extra bytes available, 0 if none, */
};

/* Flags for f_flag */
#define ST_RDONLY     0x1
#define ST_NOSUID     0x2

__BEGIN_DECLS
int	fstatvfs __P((int, struct statvfs *));
int	statvfs __P((const char *__restrict, struct statvfs *__restrict));
__END_DECLS

#endif /* !_SYS_STATVFS_H_ */
