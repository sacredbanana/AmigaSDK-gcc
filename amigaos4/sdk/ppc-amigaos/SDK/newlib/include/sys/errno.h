/* errno is not a global variable, because that would make using it
   non-reentrant.  Instead, its address is returned by the function
   __errno.  */

#ifndef _SYS_ERRNO_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SYS_ERRNO_H_

#include <sys/reent.h>

#define errno (*__errno())
extern int *__errno (void);
#define h_errno (*__h_errno())
extern int *__h_errno (void);

/* Please don't use these variables directly.
   Use strerror instead. */
extern __IMPORT const char * const _sys_errlist[];
extern __IMPORT int _sys_nerr;
#ifdef __CYGWIN__
extern __IMPORT const char * const sys_errlist[];
extern __IMPORT int sys_nerr;
#endif

#define __errno_r(ptr) ((ptr)->_errno)

#define	EPERM 1		/* Not super-user */
#define	ENOENT 2	/* No such file or directory */
#define	ESRCH 3		/* No such process */
#define	EINTR 4		/* Interrupted system call */
#define	EIO 5		/* I/O error */
#define	ENXIO 6		/* No such device or address */
#define	E2BIG 7		/* Arg list too long */
#define	ENOEXEC 8	/* Exec format error */
#define	EBADF 9		/* Bad file number */
#define	ECHILD 10	/* No children */
#define	EDEADLK 11	/* Resource deadlock avoided */
#define	ENOMEM 12	/* Not enough core */
#define	EACCES 13	/* Permission denied */
#define	EFAULT 14	/* Bad address */
#define	ENOTBLK 15	/* Block device required */
#define	EBUSY 16	/* Mount device busy */
#define	EEXIST 17	/* File exists */
#define	EXDEV 18	/* Cross-device link */
#define	ENODEV 19	/* No such device */
#define	ENOTDIR 20	/* Not a directory */
#define	EISDIR 21	/* Is a directory */
#define	EINVAL 22	/* Invalid argument */
#define	ENFILE 23	/* Too many open files in system */
#define	EMFILE 24	/* Too many open files */
#define	ENOTTY 25	/* Not a typewriter */
#define	ETXTBSY 26	/* Text file busy */
#define	EFBIG 27	/* File too large */
#define	ENOSPC 28	/* No space left on device */
#define	ESPIPE 29	/* Illegal seek */
#define	EROFS 30	/* Read only file system */
#define	EMLINK 31	/* Too many links */
#define	EPIPE 32	/* Broken pipe */
#define	EDOM 33		/* Math arg out of domain of func */
#define	ERANGE 34	/* Math result not representable */
#define	EAGAIN 35	/* Resource temporarily unavailable */
#define	EINPROGRESS 36	/* Operation now in progress */
#define	EALREADY 37		/* Operation already in progress */
#define	ENOTSOCK	38		/* Socket operation on non-socket */
#define	EDESTADDRREQ	39		/* Destination address required */
#define	EMSGSIZE	40		/* Message too long */
#define	EPROTOTYPE	41		/* Protocol wrong type for socket */
#define	ENOPROTOOPT	42		/* Protocol not available */
#define	EPROTONOSUPPORT	43		/* Protocol not supported */
#define	ESOCKTNOSUPPORT	44		/* Socket type not supported */
#define	EOPNOTSUPP	45		/* Operation not supported on socket */
#define	EPFNOSUPPORT	46		/* Protocol family not supported */
#define	EAFNOSUPPORT	47		/* Address family not supported by protocol family */
#define	EADDRINUSE	48		/* Address already in use */
#define	EADDRNOTAVAIL	49		/* Can't assign requested address */
#define	ENETDOWN 50		/* Network is down */
#define	ENETUNREACH 51	/* Network is unreachable */
#define	ENETRESET 52	/* Network dropped connection on reset */
#define	ECONNABORTED 53	/* Software caused connection abort */
#define	ECONNRESET 54	/* Connection reset by peer */
#define	ENOBUFS 55		/* No buffer space available */
#define	EISCONN 56		/* Socket is already connected */
#define	ENOTCONN 57		/* Socket is not connected */
#define	ESHUTDOWN 58	/* Can't send after socket shutdown */
#define	ETOOMANYREFS 59	/* Too many references: can't splice */
#define	ETIMEDOUT 60	/* Connection timed out */
#define	ECONNREFUSED 61	/* Connection refused */
#define	ELOOP 62		/* Too many levels of symbolic links */
#define	ENAMETOOLONG 63	/* File name too long */
#define	EHOSTDOWN 64	/* Host is down */
#define	EHOSTUNREACH 65	/* No route to host */
#define	ENOTEMPTY 66	/* Directory not empty */
#define	EPROCLIM 67		/* Too many processes */
#define	EUSERS 68		/* Too many users */
#define	EDQUOT 69		/* Disc quota exceeded */
#define	ESTALE 70		/* Stale NFS file handle */
#define	EREMOTE 71		/* Too many levels of remote in path */
#define	EBADRPC 72		/* RPC struct is bad */
#define	ERPCMISMATCH 73	/* RPC version wrong */
#define	EPROGUNAVAIL 74	/* RPC prog. not avail */
#define	EPROGMISMATCH 75	/* Program version wrong */
#define	EPROCUNAVAIL 76	/* Bad procedure for program */
#define	ENOLCK 77		/* No locks available */
#define	ENOSYS 78		/* Function not implemented */
#define	EFTYPE 79		/* Inappropriate file type or format */
#define	EAUTH 80		/* Authentication error */
#define	ENEEDAUTH 81	/* Need authenticator */
#define	EIDRM 82		/* Identifier removed */
#define	ENOMSG 83		/* No message of desired type */
#define EOVERFLOW 84	/* Value too large for defined data type */
#define EILSEQ 85		/* Encoding error detected */

#define	ECHRNG 1037	/* Channel number out of range */
#define	EL2NSYNC 1038	/* Level 2 not synchronized */
#define	EL3HLT 1039	/* Level 3 halted */
#define	EL3RST 1040	/* Level 3 reset */
#define	ELNRNG 1041	/* Link number out of range */
#define	EUNATCH 1042	/* Protocol driver not attached */
#define	ENOCSI 1043	/* No CSI structure available */
#define	EL2HLT 1044	/* Level 2 halted */
#define EBADE 1050	/* Invalid exchange */
#define EBADR 1051	/* Invalid request descriptor */
#define EXFULL 1052	/* Exchange full */
#define ENOANO 1053	/* No anode */
#define EBADRQC 1054	/* Invalid request code */
#define EBADSLT 1055	/* Invalid slot */
#define EDEADLOCK 1056	/* File locking deadlock error */
#define EBFONT 1057	/* Bad font file fmt */
#define ENOSTR 1060	/* Device not a stream */
#define ENODATA 1061	/* No data (for no delay io) */
#define ETIME 1062	/* Timer expired */
#define ENOSR 1063	/* Out of streams resources */
#define ENONET 1064	/* Machine is not on the network */
#define ENOPKG 1065	/* Package not installed */
#define ENOLINK 1067	/* The link has been severed */
#define EADV 1068		/* Advertise error */
#define ESRMNT 1069	/* Srmount error */
#define	ECOMM 1070	/* Communication error on send */
#define EPROTO 1071	/* Protocol error */
#define	EMULTIHOP 1074	/* Multihop attempted */
#define	ELBIN 1075	/* Inode is remote (not really error) */
#define	EDOTDOT 1076	/* Cross mount point (not really error) */
#define EBADMSG 1077	/* Trying to read unreadable message */
#define ENOTUNIQ 1080	/* Given log. name not unique */
#define EBADFD 1081	/* f.d. invalid for this operation */
#define EREMCHG 1082	/* Remote address changed */
#define ELIBACC 1083	/* Can't access a needed shared lib */
#define ELIBBAD 1084	/* Accessing a corrupted shared lib */
#define ELIBSCN 1085	/* .lib section in a.out corrupted */
#define ELIBMAX 1086	/* Attempting to link in too many libs */
#define ELIBEXEC 1087	/* Attempting to exec a shared library */
#define ENMFILE 1089      /* No more files */
#define ENOTSUP 1134		/* Not supported */
#define ENOMEDIUM 1135   /* No medium (in tape drive) */
#define ENOSHARE 1136    /* No such host or network path */
#define ECASECLASH 1137  /* Filename exists with different case */

/* From cygwin32.  */
#define EWOULDBLOCK EAGAIN	/* Operation would block */

#define __ELASTERROR 2000	/* Users can add values starting here */

#ifdef __cplusplus
}
#endif
#endif /* _SYS_ERRNO_H */
