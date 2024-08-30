#ifndef _CLIB_NETLIB_PROTOS_H_
#define _CLIB_NETLIB_PROTOS_H_
/*
 * netlib.lib C prototypes
 *
 * Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
 *
 * $Id: netlib_protos.h,v 1.1.1.1 2005/03/15 16:00:48 laire Exp $
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef _SYS_TYPES_H_
#include <sys/types.h>
#endif
#ifndef _SYS_CDEFS_H_
#include <sys/cdefs.h>
#endif
#ifndef EXEC_LIBRARIES_H
struct Library;
#endif
#ifndef _SYS_TIME_H_
#include <sys/time.h>
#endif
#ifndef _SYS_SOCKET_H_
#include <sys/socket.h>
#endif
#ifndef _NETDB_H_
struct hostent;
struct netent;
struct servent;
struct protoent;
#endif
#ifndef _NETINET_IN_H_
#include <netinet/in.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef DOS_RDARGS_H
#include <dos/rdargs.h>
#endif
#ifndef _SYS_STAT_H
#include <sys/stat.h>
#endif

#ifndef _STDARG_H
#include <stdarg.h>
#endif


#if 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ioctl.c */
int ioctl(int fd, unsigned int request, char *argp);

ULONG VCSPrintf(struct CSource *, const char *, va_list);
ULONG CSPrintf(struct CSource *, const char *, ...);

/* printfault.c */
void  PrintNetFault(LONG code, const UBYTE *banner);

/* printuserfault.c */
void  PrintUserFault(LONG code, const UBYTE *banner);

/* herror.c */
void  herror(const char *banner);

/* perror.c */
void  perror(const char *banner);

/* strerror.c */
char *strerror(int code);

#else
/* access.c */
int __access(const char *name, int mode);

/* autoinit.c */
extern int h_errno;
extern struct Library *SocketBase;
LONG  _STI_200_openSockets(void);
void  _STD_200_closeSockets(void);

/* chmod.c */
int chmod(const char *path, int mode);

/* dosio_init.c */
extern BPTR __dosio_files[3];
long  _STI_500_dosio_init(void);

/* dosio_sprintf.c */
ULONG VCSPrintf(struct CSource *, const char *, va_list);
ULONG CSPrintf(struct CSource *, const char *, ...);
ULONG VSPrintf(STRPTR, const char *, va_list);
ULONG SPrintf(STRPTR, const char *, ...);

/* dummy.c */
struct hostent  *gethostent(void);
struct netent  *getnetent(void);
struct servent  *getservent(void);
struct protoent *getprotoent(void);

/* fhopen.c */
int fhopen(long file, int mode);

/* getopt.c */
extern int opterr;
extern int optind;
extern int optopt;
extern char *optarg;
int   getopt(int argc, char * const argv[], char const *opts);

/* getpid.c */
pid_t getpid(void);

/* gettimeofday.c */
int   gettimeofday(struct timeval *tp, struct timezone *tzp);

/* herror.c */
void  herror(const char *banner);

/* init_inet_daemon.c */
int init_inet_daemon(void);

/* init_usergroup.c */
extern struct Library *UserGroupBase;
LONG  _STI_200_openUserGroup(void);
void  _STD_200_closeUserGroup(void);

/* ioctl.c */
int ioctl(int fd, unsigned int request, char *argp);

/* iomode.c */
int iomode(int fd, int mode);

/* isatty.c */
int isatty(int fd);

/* lineread.c */
int   lineRead(struct LineRead * rl);

/* perror.c */
void  perror(const char *banner);

/* popen.c */
#ifndef _STDIO_H
struct __iobuf; /* typedef struct __iobuf FILE */
#endif
struct __iobuf *popen(const char *cmd, const char *mode);
struct __iobuf *popenl(const char *arg0, ...);
int pclose(struct __iobuf *fptr);
void  _STD_4000_popen(void);
char *mktemp(char * template);

/* printfault.c */
void  PrintNetFault(LONG code, const UBYTE *banner);

/* printuserfault.c */
void  PrintUserFault(LONG code, const UBYTE *banner);

/* rcmd.c */
int   rcmd(char **, int, const char *, const char *, const char *, int *);
int   rresvport(int *alport);

/* serveraccept.c */
long serveraccept(char *pname, struct sockaddr_in *ha);

/* set_socket_stdio.c */
int set_socket_stdio(int sock);

/* setegid.c */
int setegid(gid_t g);

/* seteuid.c */
int seteuid(uid_t u);

/* sleep.c */
void sleep(unsigned int secs);

/* stat.c */
int stat(const char *name, struct stat *st);

/* strerror.c */
char *strerror(int code);

/* stubs.c */
#if !defined(__SASC) || !defined(_OPTINLINE) /* these are inlined for SAS/C */
char * inet_ntoa(struct in_addr addr);
struct in_addr inet_makeaddr(int net, int host);
unsigned long inet_lnaof(struct in_addr addr);
unsigned long inet_netof(struct in_addr addr);
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exeptfds,
	   struct timeval *timeout);
#endif

/* syslog.c */
void  openlog(const char *ident, int logstat, int logfac);
void  closelog(void);
int   setlogmask(int pmask);

/* timerinit.c */
extern long __local_to_GMT;
extern struct Library *TimerBase; /* actually struct Device * */
LONG  _STI_200_openTimer(void);
void  _STD_200_closeTimer(void);

/* usleep.c */
void usleep(unsigned int usecs);

/* utime.c */
#ifndef UTIME_H
struct utimbuf;
#endif
int utime(const char *name, const struct utimbuf *times);

#ifndef _IOS1_H
struct UFB;
#endif

/* _allocufb.c */
struct UFB * __allocufb(int *fdp);

/* _chkufb.c */
long  _STI_1000_install_AmiTCP_callback(void);
long ASM SAVEDS fdCallback(__reg(d0, int fd), __reg(d1, int action));
struct UFB * __chkufb(int fd);

/* _close.c */
int __close(int fd);

/* _dup.c */
/* _dup2.c */

/* _fstat.c */
int fstat(int fd, struct stat *st);

/* _lseek.c */
long __lseek(int fd, long rpos, int mode);

/* _open.c */
 int __open(const char *name, int mode, ...);

/* _read.c */
int __read(int fd, void *buffer, unsigned int length);

/* _write.c */
int __write(int fd, const void *buffer, unsigned int length);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

#endif /* !_CLIB_NETLIB_PROTOS_H_ */
