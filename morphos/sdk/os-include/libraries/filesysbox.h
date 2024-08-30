#ifndef LIBRARIES_FILESYSBOX_H
#define LIBRARIES_FILESYSBOX_H 1

/*********************************************************************/
/********** Public structures and definitions of Filesysbox **********/
/*********************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#if !defined(_FILESYSBOX_SYS_TYPES_H_) || !defined(_FILESYSBOX_SYS_STAT_H_) || !defined(_FILESYSBOX_SYS_STATVFS_H_)
#error "filesysbox include priority is wrong"
#endif
#include <utime.h>
#include <fcntl.h>

#include <utility/tagitem.h>

#define FILESYSBOX_VERSION 3
#define FILESYSBOX_NAME "filesysbox.library"

#define FUSE_VERSION 26

#define FBXQMM_MOUNT_NAME 1
#define FBXQMM_MOUNT_CONTROL 2
// v1
#define FBXQMM_FSSM 3
#define FBXQMM_ENVIRON 4

#define CONN_VOLUME_NAME_BYTES 128

// v1: attributes for fs->getfsattr(), fs->setfsattr() 
#define GFSA_VOLUME_TIMESPEC 0 // struct timespec 
//#define GFSA_VOLUME_NAME 1     // CSTRING

// v1: FbxCauseVolumeChange() numbers
#define FBX_VCHANGE_SETUP 1
#define FBX_VCHANGE_CLEANUP 2
#define FBX_VCHANGE_RESETUP 3 

struct fuse_conn_info {
   /* not used yet, just cleared */
   unsigned proto_major;
   unsigned proto_minor;
   unsigned async_read;
   unsigned max_write;
   unsigned max_readahead;
   unsigned reserved[27];
   /* filesysbox addition */
   char	   volume_name[CONN_VOLUME_NAME_BYTES]; // for .init() to fill 
};

// filesysbox sets flags and reads nonseekable for now. 
// rest is cleared and untouched. "fh_old" and "fh" are
// safe to be poked by FS.
struct fuse_file_info {
   int flags;
   unsigned long fh_old;
   int writepage;
   unsigned int direct_io : 1;
   unsigned int keep_cache : 1;
   unsigned int flush : 1;
   unsigned int nonseekable : 1; // fuse 2.9
   unsigned int padding : 28;
   long long fh; 
   long long lock_owner; /* not used */
};

// flags  for FBXT_FSFLAGS
#define FBXF_ENABLE_UTF8_NAMES 1	// does nothing as of v1
// v1 
#define FBXF_STAT_PROTECTION 2   
// v2
#define FBXF_PROPER_READDIR 4

// tags for FbxSetupFS()
#define FBXT_FSFLAGS (TAG_USER + 1)			// ULONG
#define FBXT_FSSM (TAG_USER + 2)    		// struct FileSysStartupMsg*
#define FBXT_DOSTYPE (TAG_USER + 3)			// ULONG
#define FBXT_GET_CONTEXT (TAG_USER + 4)   // struct fuse_context**
// v1
#define FBXT_AUTO_UPDATE (TAG_USER + 5)   // ULONG ((iaut << 16) | aut)  
// iaut: inactive update timeout in tens of seconds
// aut: active update timeout in tens of seconds
// v4
#define FBXT_PATH_PREFIX (TAG_USER + 6) // pass cstring (gets copied).
// 4.10
#define FBXT_ADD_DEVICE (TAG_USER + 7) // pass name of dummy device

typedef int (*fuse_fill_dir_t ) (void *buf, const char *name, const struct FbxStat *stbuf, off_t off);

// v1. 
struct FbxDiskChange {
	void *userdata;
	void *privdata;
	struct Library *sysbase;
	int   num_methods; // 2
	int (*isdiskinserted) (struct FbxDiskChange *);
	int (*isdiskprotected) (struct FbxDiskChange *);
};
typedef void (*FbxDiskChangeFunc) (struct FbxDiskChange *);

// v1: errors set by FbxInstallDiskChangeHandler()
#define IDCHERR_MEMORY 1
#define IDCHERR_MSGPORT 2
#define IDCHERR_OPENDEV 3 

// lazy macros
#define fuse_get_context() _fuse_context_
#define fuse_version() FbxFuseVersion()
#define fuse_new(fh,tags,ops,opssize,udata) FbxSetupFS(fh,tags,ops,opssize,udata)
#define fuse_loop(fh) FbxEventLoop(fh)
#define fuse_destroy(fh) FbxCleanupFS(fh)

struct FbxFS;

struct fuse_context {

	// return value of FbxSetupFS()
   struct FbxFS *fuse; 
   
   // these are all zero for now, but may change in future
   uid_t uid;
   gid_t gid;
   pid_t pid;
   
   // user_data argument of FbxSetupFS()
   void *private_data; 
};

struct fuse_operations {
   int (*getattr) (const char *, struct FbxStat *);	
   int (*readlink) (const char *, char *, size_t); 
   int (*mknod) (const char *, mode_t, dev_t);
   int (*mkdir) (const char *, mode_t);
   int (*unlink) (const char *);
   int (*rmdir) (const char *);
   int (*symlink) (const char *, const char *);
   int (*rename) (const char *, const char *);
   int (*link) (const char *, const char *);
   int (*chmod) (const char *, mode_t); 
   int (*chown) (const char *, uid_t, gid_t); 
   int (*truncate) (const char *, off_t); 
   int (*utime) (const char *, struct utimbuf *);
   int (*open) (const char *, struct fuse_file_info *);
   int (*read) (const char *, char *, size_t, off_t, struct fuse_file_info *);
   int (*write) (const char *, const char *, size_t, off_t, struct fuse_file_info *);
   int (*statfs) (const char *, struct statvfs *);
   int (*flush) (const char *, struct fuse_file_info *);
   int (*release) (const char *, struct fuse_file_info *);
   int (*fsync) (const char *, int, struct fuse_file_info *);
   int (*setxattr) (const char *, const char *, const char *, size_t, int);
   int (*getxattr) (const char *, const char *, char *, size_t);
   int (*listxattr) (const char *, char *, size_t);
   int (*removexattr) (const char *, const char *); 
   int (*opendir) (const char *, struct fuse_file_info *); 
   int (*readdir) (const char *, void *, fuse_fill_dir_t, off_t, struct fuse_file_info *);
   int (*releasedir) (const char *, struct fuse_file_info *); 
   int (*fsyncdir) (const char *, int, struct fuse_file_info *); 
   void *(*init) (struct fuse_conn_info *conn);
   void (*destroy) (void *);
   int (*access) (const char *, int); 
   int (*create) (const char *, mode_t, struct fuse_file_info *); 
   int (*ftruncate) (const char *, off_t, struct fuse_file_info *);
   int (*fgetattr) (const char *, struct FbxStat *, struct fuse_file_info *);
   int (*lock) (const char *, struct fuse_file_info *, int cmd, struct flock *);  
   int (*utimens) (const char *, const struct timespec tv[2]);
   int (*bmap) (const char *, size_t blocksize, off_t *idx);
   unsigned int flag_nullpath_ok : 1; 
   unsigned int flag_reserved : 31;
   /* v1 additions */
	int (*setprotect) (const char *, unsigned long);
	int (*update) (void);
	int (*getfsattr) (int, void *,  int); // not used yet
	int (*setfsattr) (int, void *,  int);	// not used yet
	int (*relabel) (const char *); // not used yet
};


// v2
typedef void (*FbxTimerCallbackFunc)(struct fuse_context *fcntx);
typedef void (*FbxSignalCallbackFunc)(size_t matching_signals, struct fuse_context *fcntx);

// V2, forward declaration
struct FbxTimerCallbackData;

// v3
typedef void (*FbxPushCallbackFunc)(void *arg, struct fuse_context *fcntx);

#endif /* LIBRARIES_FILESYSBOX_H */
