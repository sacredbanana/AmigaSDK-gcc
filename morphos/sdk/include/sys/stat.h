/*-
 * Copyright (c) 1982, 1986, 1989 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)stat.h	7.11 (Berkeley) 3/3/91
 */

#ifndef _SYS_STAT_H_
#define _SYS_STAT_H_

#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/time.h>

/* ixemul needs 2 bytes alignment for compatibility, libnix doesn't. */
#ifdef __ixemul__
#pragma pack(2)
#endif
#if __POSIX_VISIBLE >= 200809 || \
    defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_SVID_SOURCE)
# define SYS_STAT_POSIX_TIME_FIELDS 1
#else
# define SYS_STAT_POSIX_TIME_FIELDS 0
#endif
struct  stat
{
	dev_t   st_dev;
	ino_t   st_ino;
	unsigned short st_mode;
	short   st_nlink;
	uid_t   st_uid;
	gid_t   st_gid;
	dev_t   st_rdev;
	off64_t st_size;
#if SYS_STAT_POSIX_TIME_FIELDS
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
# define st_atime st_atim.tv_sec
# define st_mtime st_mtim.tv_sec
# define st_ctime st_ctim.tv_sec
#else
	time_t  st_atime;
	long    st_atimensec;
	int32_t st_atime_pad;
	time_t  st_mtime;
	long    st_mtimensec;
	int32_t st_mtime_pad;
	time_t  st_ctime;
	long    st_ctimensec;
	int32_t st_ctime_pad;
#endif
	long    st_blksize;
	int64_t st_blocks;
	int     st_spare2; /* at_amode */
	long    st_spare3; /* st_handler */
};
struct  stat64
{
	dev_t   st_dev;
	ino_t   st_ino;
	unsigned short st_mode;
	short   st_nlink;
	uid_t   st_uid;
	gid_t   st_gid;
	dev_t   st_rdev;
	off64_t st_size;
#if SYS_STAT_POSIX_TIME_FIELDS
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
#else
	time_t  st_atime;
	long    st_atimensec;
	int32_t st_atime_pad;
	time_t  st_mtime;
	long    st_mtimensec;
	int32_t st_mtime_pad;
	time_t  st_ctime;
	long    st_ctimensec;
	int32_t st_ctime_pad;
#endif
	long    st_blksize;
	int64_t st_blocks;
	int     st_spare2; /* at_amode */
	long    st_spare3; /* st_handler */
};

#ifdef _KERNEL_T32_STRUCTURES
struct	stat_t32
{
	dev_t	st_dev;
	ino_t	st_ino;
	unsigned short st_mode;
	short	st_nlink;
	uid_t	st_uid;
	gid_t	st_gid;
	dev_t	st_rdev;
	int32_t	st_size;
#if SYS_STAT_POSIX_TIME_FIELDS
	struct { time32_t tv_sec; } st_atim;
#else
	time32_t st_atime;
#endif
	int	st_spare1;
#if SYS_STAT_POSIX_TIME_FIELDS
	struct { time32_t tv_sec; } st_mtim;
#else
	time32_t st_mtime;
#endif
	int	st_spare2;
#if SYS_STAT_POSIX_TIME_FIELDS
	struct { time32_t tv_sec; } st_ctim;
#else
	time32_t st_ctime;
#endif
	int	st_spare3;
	long	st_blksize;
	long	st_blocks;
	long	st_spare4[2];
};
struct  stat64_t32
{
	dev_t   st_dev;
	ino_t   st_ino;
	unsigned short st_mode;
	short   st_nlink;
	uid_t   st_uid;
	gid_t   st_gid;
	dev_t   st_rdev;
	int32_t st_size32;
#if SYS_STAT_POSIX_TIME_FIELDS
	struct { time32_t tv_sec; } st_atim;
#else
	time32_t st_atime;
#endif
	int	st_spare1;
#if SYS_STAT_POSIX_TIME_FIELDS
	struct { time32_t tv_sec; } st_mtim;
#else
	time32_t st_mtime;
#endif
	int	st_spare2;
#if SYS_STAT_POSIX_TIME_FIELDS
	struct { time32_t tv_sec; } st_ctim;
#else
	time32_t st_ctime;
#endif
	int     st_spare3;
	long    st_blksize;
	int32_t st_blocks32;
	long    st_spare4[2];
	off64_t st_size;
	int64_t st_blocks;
};
#endif
#ifdef __ixemul__
#pragma pack()
#endif

#ifdef __amigaos__
#define st_handler st_spare3
#define st_amode   st_spare2
#endif

#ifndef _KERNEL
#if __BSD_VISIBLE
#define	st_atimespec		st_atim
#define	st_mtimespec		st_mtim
#define	st_ctimespec		st_ctim
#if !SYS_STAT_POSIX_TIME_FIELDS
#define	st_atimensec            st_atim.tv_nsec
#define	st_mtimensec		st_mtim.tv_nsec
#define	st_ctimensec		st_ctim.tv_nsec
#endif
#endif
#endif /* !_KERNEL */

#define	S_ISUID	0004000			/* set user id on execution */
#define	S_ISGID	0002000			/* set group id on execution */
#if __BSD_VISIBLE
#define	S_ISTXT	0001000			/* sticky bit */
#endif

#define	S_IRWXU	0000700			/* RWX mask for owner */
#define	S_IRUSR	0000400			/* R for owner */
#define	S_IWUSR	0000200			/* W for owner */
#define	S_IXUSR	0000100			/* X for owner */

#if __BSD_VISIBLE
#define	S_IREAD		S_IRUSR
#define	S_IWRITE	S_IWUSR
#define	S_IEXEC		S_IXUSR
#endif

#define	S_IRWXG	0000070			/* RWX mask for group */
#define	S_IRGRP	0000040			/* R for group */
#define	S_IWGRP	0000020			/* W for group */
#define	S_IXGRP	0000010			/* X for group */

#define	S_IRWXO	0000007			/* RWX mask for other */
#define	S_IROTH	0000004			/* R for other */
#define	S_IWOTH	0000002			/* W for other */
#define	S_IXOTH	0000001			/* X for other */

#if __XSI_VISIBLE
#define	S_IFMT	 0170000		/* type of file */
#define	S_IFIFO	 0010000		/* named pipe (fifo) */
#define	S_IFCHR	 0020000		/* character special */
#define	S_IFDIR	 0040000		/* directory */
#define	S_IFBLK	 0060000		/* block special */
#define	S_IFREG	 0100000		/* regular */
#define	S_IFLNK	 0120000		/* symbolic link */
#define	S_IFSOCK 0140000		/* socket */
#define	S_ISVTX	 0001000		/* save swapped text even after use */
#endif

#define	S_ISDIR(m)	((m & 0170000) == 0040000)	/* directory */
#define	S_ISCHR(m)	((m & 0170000) == 0020000)	/* char special */
#define	S_ISBLK(m)	((m & 0170000) == 0060000)	/* block special */
#define	S_ISREG(m)	((m & 0170000) == 0100000)	/* regular file */
#define	S_ISFIFO(m)	((m & 0170000) == 0010000)	/* fifo */
#if __POSIX_VISIBLE >= 200112
#define	S_ISLNK(m)	((m & 0170000) == 0120000)	/* symbolic link */
#define	S_ISSOCK(m)	((m & 0170000) == 0140000)	/* socket */
#endif

#if __BSD_VISIBLE
#define	ACCESSPERMS	(S_IRWXU|S_IRWXG|S_IRWXO)	/* 0777 */
							/* 7777 */
#define	ALLPERMS	(S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
							/* 0666 */
#define	DEFFILEMODE	(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

#define S_BLKSIZE	512		/* block size used in the stat struct */
#endif

#if __POSIX_VISIBLE >= 200809
#define	UTIME_NOW	-1
#define	UTIME_OMIT	-2
#endif

__BEGIN_DECLS
int	chmod __P((const char *, mode_t));
#if __POSIX_VISIBLE >= 200112
int	fchmod __P((int, mode_t));
#endif
#if __POSIX_VISIBLE >= 200809
int	fchmodat __P((int, const char *, mode_t, int));
int	futimens __P((int fd, const struct timespec times[2]));
int	utimensat __P((int fd, const char *path, const struct timespec times[2], int flag));
#endif
int	fstat __P((int, struct stat *));
#if __POSIX_VISIBLE >= 200112
int	lstat __P((const char *, struct stat *));
#endif
int	mkdir __P((const char *, mode_t));
int	mkfifo __P((const char *, mode_t));
#if !defined(_MKNOD_DECLARED) && __XSI_VISIBLE
int	mknod __P((const char *, mode_t, dev_t));
#define	_MKNOD_DECLARED
#endif
int	stat __P((const char *, struct stat *));
mode_t	umask __P((mode_t));
#if __POSIX_VISIBLE >= 200809
int	fstatat __P((int, const char *, struct stat *, int));
int	mkdirat __P((int, const char *, mode_t));
/*int	mkfifoat __P((int, const char *, mode_t));*/
#endif
#if __XSI_VISIBLE >= 700
int	mknodat __P((int, const char *, mode_t, dev_t));
#endif
#ifdef _LARGEFILE64_SOURCE
int     fstat64 __P((int, struct stat64 *));
int     stat64 __P((const char *, struct stat64 *));
#if __POSIX_VISIBLE >= 200809
int     fstatat64 __P((int, const char *, struct stat64 *, int));
int     lstat64 __P((const char *, struct stat64 *));
#endif
#endif
__END_DECLS

#endif /* _SYS_STAT_H_ */
