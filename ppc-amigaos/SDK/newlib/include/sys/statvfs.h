#ifndef _SYS_STATVFS_H
#define _SYS_STATVFS_H

#include <_ansi.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long fsblkcnt_t;
typedef unsigned long fsfilcnt_t;

struct statvfs
{
	unsigned long f_bsize;
	unsigned long f_frsize;
	fsblkcnt_t    f_blocks;
	fsblkcnt_t    f_bfree;
	fsblkcnt_t    f_bavail;

	fsfilcnt_t    f_files;
	fsfilcnt_t    f_ffree;
	fsfilcnt_t    f_favail;

	unsigned long f_fsid;
	unsigned long f_flag;
	unsigned long f_namemax;
};

#define ST_RDONLY         0x0001 /* Read-only file system. */
#define ST_NOSUID         0x0002 /* Does not support the semantics of the ST_ISUID and ST_ISGID file mode bits. */
#define ST_CASE_SENSITIVE 0x0004 /* The file system is case sensitive. */

int statvfs (const char *, struct statvfs *);
int fstatvfs (int, struct statvfs *);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_STATVFS_H */
