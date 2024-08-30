#ifndef _SYS_UNISTD_H
#define _SYS_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <sys/types.h>
#include <sys/_types.h>
#define __need_size_t
#define __need_ptrdiff_t
#include <stddef.h>

struct _reent;

#define environ (*__environ())
extern char ***__environ (void);

void	_exit (int __status ) _ATTRIBUTE ((__noreturn__));

int     access (const char *__path, int __amode);
int     chdir (const char *__path);
int     chmod (const char *__path, mode_t __mode);
int     chown (const char *__path, uid_t __owner, gid_t __group);
int     close (int __fildes);
int     dup (int __fildes);
int     dup2 (int __fildes, int __fildes2);
int     fchmod (int __fildes, mode_t __mode);
int     fchown (int __fildes, uid_t __owner, gid_t __group);
int     fsync (int __fd);
char *  getcwd (char *__buf, size_t __size);
gid_t   getegid (void);
uid_t   geteuid (void);
gid_t   getgid (void);
int     getgroups (int __gidsetsize, gid_t __grouplist[]);
#if defined(__CYGWIN__)
long    gethostid (void);
#endif
char *  getlogin (void);
char *  getpass (const char *__prompt);
pid_t   getpgid (pid_t);
pid_t   getpgrp (void);
pid_t   getpid (void);
pid_t   getppid (void);
uid_t   getuid (void);
int     isatty (int __fildes);
int     link (const char *__path1, const char *__path2);
off_t   lseek (int __fildes, off_t __offset, int __whence);
#ifdef __LARGE64_FILES
_off64_t lseek64 (int __filedes, _off64_t __offset, int __whence);
#endif
ssize_t pread (int __fd, void *__buf, size_t __nbytes, off_t __offset);
ssize_t _pread_r (struct _reent *, int __fd, void *__buf, size_t __nbytes, off_t __offset);
ssize_t pwrite (int __fd, const void *__buf, size_t __nbytes, off_t __offset);
ssize_t _pwrite_r (struct _reent *, int __fd, const void *__buf, size_t __nbytes, off_t __offset);
_READ_WRITE_RETURN_TYPE read (int __fd, void *__buf, size_t __nbyte);
int     rmdir (const char *__path);
int     setgid (gid_t __gid);
int	setgroups (int ngroups, const gid_t *grouplist);
int	setregid (gid_t __rgid, gid_t __egid);
int	setreuid (uid_t __ruid, uid_t __euid);
pid_t   setsid (void);
int     setuid (uid_t __uid);
unsigned sleep (unsigned int __seconds);
int usleep (unsigned int __useconds);
void    swab (const void *, void *, ssize_t);
int     sysconf (int name);
int     unlink (const char *__path);
_READ_WRITE_RETURN_TYPE write (int __fd, const void *__buf, size_t __nbyte);

# define __UNISTD_GETOPT__
# include <getopt.h>
# undef __UNISTD_GETOPT__

#ifndef        _POSIX_SOURCE
extern char *suboptarg;			/* getsubopt(3) external variable */
int	 getsubopt(char **, char * const *, char **);
#endif /* _POSIX_SOURCE */

#ifdef _COMPILING_NEWLIB
/* Provide prototypes for most of the _<systemcall> names that are
   provided in newlib for some compilers.  */
int     _close (int __fildes);
pid_t   _fork (void);
pid_t   _getpid (void);
int     _link (const char *__path1, const char *__path2);
_off_t   _lseek (int __fildes, _off_t __offset, int __whence);
#ifdef __LARGE64_FILES
_off64_t _lseek64 (int __filedes, _off64_t __offset, int __whence);
#endif
_READ_WRITE_RETURN_TYPE _read (int __fd, void *__buf, size_t __nbyte);
int     _unlink (const char *__path);
_READ_WRITE_RETURN_TYPE _write (int __fd, const void *__buf, size_t __nbyte);
#endif

int     ftruncate (int __fd, off_t __length);
int     truncate (const char *, off_t __length);
#ifdef __LARGE64_FILES
int     ftruncate64 (int __fd, _off64_t __length);
int     truncate64 (const char *, _off64_t __length);
#endif
int	getdtablesize (void);
char * crypt (const char *key, const char *salt);
int	gethostname (char *__name, size_t __len);
char *	mktemp (char *);
int     readlink (const char *__path, char *__buf, int __buflen);
int     symlink (const char *__name1, const char *__name2);

#define	F_OK	0
#define	R_OK	4
#define	W_OK	2
#define	X_OK	1

# define	SEEK_SET	0
# define	SEEK_CUR	1
# define	SEEK_END	2

#include <sys/features.h>

#define STDIN_FILENO    0       /* standard input file descriptor */
#define STDOUT_FILENO   1       /* standard output file descriptor */
#define STDERR_FILENO   2       /* standard error file descriptor */


/* FIXME: This is temporary until winsup gets sorted out.  */
#ifdef __CYGWIN__
#define MAXPATHLEN (260 - 1 /* NUL */)
#else
# define	MAXPATHLEN	1024
#endif

/* 4.8.1 Get Configurable System Variables, P1003.1b-1993, p. 9 */
#define	_SC_ARG_MAX		1
#define	_SC_CHILD_MAX		2
#define	_SC_CLK_TCK		3
#define	_SC_NGROUPS_MAX		4
#define	_SC_OPEN_MAX		5
#define	_SC_JOB_CONTROL		6
#define	_SC_SAVED_IDS		7
#define	_SC_VERSION		8

#ifdef __cplusplus
}
#endif
#endif /* _SYS_UNISTD_H */
