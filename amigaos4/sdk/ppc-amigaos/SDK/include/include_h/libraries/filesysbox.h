/*********************************************************************/
/********** Public structures and definitions of Filesysbox **********/
/*********************************************************************/

#ifndef LIBRARIES_FILESYSBOX_H
#define LIBRARIES_FILESYSBOX_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <utime.h>
#include <fcntl.h>

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef INCLUDE_PTHREAD_H
#include <pthread.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if (defined(PTHREAD_H) || defined(SCHED_H)) && !defined(__timespec_defined)
#define __timespec_defined
#endif

#ifndef __timespec_defined
struct timespec {
	unsigned int tv_sec;
	unsigned int tv_nsec;
};
#define __timespec_defined
#endif

typedef int64 fbx_off_t;

#ifndef FBX_USE_OLD_16BIT_UIDS
typedef uint16 fbx_obsolete_uid_t; /* Backwards compatibility */
typedef uint16 fbx_obsolete_gid_t; /* Backwards compatibility */

typedef int32 fbx_uid_t;
typedef int32 fbx_gid_t;
#else
typedef uint16 fbx_uid_t;
typedef uint16 fbx_gid_t;
#endif

struct fbx_stat {
	mode_t             st_mode;
	uint64             st_ino;
	nlink_t            st_nlink;

#ifndef FBX_USE_OLD_16BIT_UIDS
	fbx_obsolete_uid_t st_obsolete_uid; /* Backwards compatibility */
	fbx_obsolete_gid_t st_obsolete_gid; /* Backwards compatibility */
#else
	fbx_uid_t          st_uid;
	fbx_gid_t          st_gid;
#endif

	dev_t              st_rdev;
	union {
		struct {
			time_t       st_atime;
			unsigned int st_atimensec;
		};
		struct timespec  st_atimespec;
	};
	union {
		struct {
			time_t       st_mtime;
			unsigned int st_mtimensec;
		};
		struct timespec  st_mtimespec;
	};
	union {
		struct {
			time_t       st_ctime;
			unsigned int st_ctimensec;
		};
		struct timespec  st_ctimespec;
	};
	fbx_off_t          st_size;
	int64              st_blocks;
	int32              st_blksize;
	/* New in V54 */
#ifndef FBX_USE_OLD_16BIT_UIDS
	fbx_uid_t          st_uid;
	fbx_gid_t          st_gid;
#endif
};

#define XATTR_CREATE  0x1 /* set the value, fail if attr already exists */
#define XATTR_REPLACE 0x2 /* set the value, fail if attr does not exist */

#define FILESYSBOX_VERSION 54
#define FILESYSBOX_NAME    "filesysbox.library"

#define FUSE_VERSION 26

#define FBXQMM_MOUNT_NAME    1
#define FBXQMM_MOUNT_CONTROL 2
#define FBXQMM_FSSM          3
#define FBXQMM_ENVIRON       4

#define CONN_VOLUME_NAME_BYTES 128
#define UUID_BYTES              16

struct fuse_conn_info {
	/* not used yet, just cleared */
	unsigned      proto_major;
	unsigned      proto_minor;
	unsigned      async_read;
	unsigned      max_write;
	unsigned      max_readahead;
	unsigned      reserved[27];
	/* filesysbox additions */
	char          volume_name[CONN_VOLUME_NAME_BYTES]; /* for .init() to fill */
	unsigned char uuid[UUID_BYTES]; /* V54.3 */
};

/* filesysbox sets flags and reads nonseekable for now. 
 * rest is cleared and untouched. "fh_old" and "fh" are
 * safe to be poked by FS. */
struct fuse_file_info {
	int           flags;
	unsigned long fh_old;
	int           writepage;
	unsigned int  direct_io : 1;
	unsigned int  keep_cache : 1;
	unsigned int  flush : 1;
	unsigned int  nonseekable : 1; /* fuse 2.9 */
	unsigned int  padding : 28;
	long long     fh;
	long long     lock_owner; /* not used */
};

/* flags  for SFST_FSFLAGS */
#define FBXF_ENABLE_UTF8_NAMES            (1UL << 0) /* set to enable utf8 names for FS */
#define FBXF_ENABLE_DISK_CHANGE_DETECTION (1UL << 1) /* set to enable disk change detection */
#define FBXF_ENABLE_32BIT_UIDS            (1UL << 2) /* (V54) set to enable 32-bit user IDs */
#define FBXF_USE_INO                      (1UL << 3) /* filesystem sets st_ino */
#define FBXF_USE_FILL_DIR_STAT            (1UL << 4) /* (V54.8) valid stat data passed to readdir() callback */

/* tags for FbxSetupFS() */
#define FBXT_FSFLAGS                 (TAG_USER + 1)
#define FBXT_FSSM                    (TAG_USER + 2)
#define FBXT_DOSTYPE                 (TAG_USER + 3)
#define FBXT_GET_CONTEXT             (TAG_USER + 4)
#define FBXT_ACTIVE_UPDATE_TIMEOUT   (TAG_USER + 5) /* default: 10000 ms */
#define FBXT_INACTIVE_UPDATE_TIMEOUT (TAG_USER + 6) /* default: 500 ms */

/* tags for FbxQueryFS() */
#define FBXT_GMT_OFFSET              (TAG_USER + 101) /* equivalent to TZA_UTCOffset */

typedef int (*fuse_fill_dir_t) (void *udata, const char *fsname, const struct fbx_stat *stbuf, fbx_off_t off);

typedef void *fuse_dirfil_t;

#define fuse_get_context() _fuse_context_
#ifdef __USE_INLINE__
#define fuse_version() (int)FbxFuseVersion()
#define fuse_new(msg,tags,ops,opssize,udata) FbxSetupFS(msg,tags,ops,opssize,udata)
#define fuse_loop(fs) FbxEventLoop(fs)
#define fuse_destroy(fs) FbxCleanupFS(fs)
#else
#define fuse_version() (int)IFileSysBox->FbxFuseVersion()
#define fuse_new(msg,tags,ops,opssize,udata) IFileSysBox->FbxSetupFS(msg,tags,ops,opssize,udata)
#define fuse_loop(fs) IFileSysBox->FbxEventLoop(fs)
#define fuse_destroy(fs) IFileSysBox->FbxCleanupFS(fs)
#endif

struct FbxFS;

struct fuse_context {
	/* return value of FbxSetupFS() */
	struct FbxFS      *fuse; 
   
	/* these are all zero for now, but may change in future */
#ifndef FBX_USE_OLD_16BIT_UIDS
	fbx_obsolete_uid_t obsolete_uid;
	fbx_obsolete_gid_t obsolete_gid;
#else
	fbx_uid_t          uid;
	fbx_gid_t          gid;
#endif
	pid_t              pid;
   
	/* user_data argument of FbxSetupFS() */
	void              *private_data;

	/* New in V54 */
#ifndef FBX_USE_OLD_16BIT_UIDS
	fbx_uid_t          uid;
	fbx_gid_t          gid;
#endif
};

struct fuse_operations {
	unsigned int flag_nullpath_ok : 1;
	unsigned int flag_reserved : 31;
	int (*getattr) (const char *, struct fbx_stat *);
	int (*readlink) (const char *, char *, size_t);
	int (*mknod) (const char *, mode_t, dev_t);
	int (*mkdir) (const char *, mode_t);
	int (*unlink) (const char *);
	int (*rmdir) (const char *);
	int (*symlink) (const char *, const char *);
	int (*rename) (const char *, const char *);
	int (*link) (const char *, const char *);
	int (*chmod) (const char *, mode_t);
	int (*chown) (const char *, fbx_uid_t, fbx_gid_t);
	int (*truncate) (const char *, fbx_off_t);
	int (*utime) (const char *, struct utimbuf *);
	int (*open) (const char *, struct fuse_file_info *);
	int (*read) (const char *, char *, size_t, fbx_off_t, struct fuse_file_info *);
	int (*write) (const char *, const char *, size_t, fbx_off_t, struct fuse_file_info *);
	int (*statfs) (const char *, struct statvfs *);
	int (*flush) (const char *, struct fuse_file_info *);
	int (*release) (const char *, struct fuse_file_info *);
	int (*fsync) (const char *, int, struct fuse_file_info *);
	int (*setxattr) (const char *, const char *, const char *, size_t, int);
	int (*getxattr) (const char *, const char *, char *, size_t);
	int (*listxattr) (const char *, char *, size_t);
	int (*removexattr) (const char *, const char *);
	int (*opendir) (const char *, struct fuse_file_info *);
	int (*readdir) (const char *, void *, fuse_fill_dir_t, fbx_off_t, struct fuse_file_info *);
	int (*releasedir) (const char *, struct fuse_file_info *);
	int (*fsyncdir) (const char *, int, struct fuse_file_info *);
	void *(*init) (struct fuse_conn_info *conn);
	void (*destroy) (void *);
	int (*access) (const char *, int);
	int (*create) (const char *, mode_t, struct fuse_file_info *);
	int (*ftruncate) (const char *, fbx_off_t, struct fuse_file_info *);
	int (*fgetattr) (const char *, struct fbx_stat *, struct fuse_file_info *);
	int (*lock) (const char *, struct fuse_file_info *, int cmd, struct flock *);
	int (*utimens) (const char *, const struct timespec tv[2]);
	int (*bmap) (const char *, size_t blocksize, uint64 *idx);
	int (*format) (const char *, uint32);
	int (*relabel) (const char *);
};

typedef void (*FbxSignalCallbackFunc)(uint32 matching_signals);
typedef void (*FbxTimerCallbackFunc)(void);

struct FbxTimerCallbackData;

#ifdef __cplusplus
}
#endif

#endif

