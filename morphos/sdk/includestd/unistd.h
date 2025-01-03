/*	$NetBSD: unistd.h,v 1.25 1995/03/19 22:51:38 mycroft Exp $	*/

/*-
 * Copyright (c) 1991 The Regents of the University of California.
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
 *	@(#)unistd.h	5.13 (Berkeley) 6/17/91
 */

#ifndef _UNISTD_H_
#define	_UNISTD_H_

#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/unistd.h>

#ifndef PROTO_EXEC_H
#include <proto/exec.h>
#endif

#ifndef PROTO_SOCKET_H
#include <proto/socket.h>
#endif

#ifndef PROTO_USERGROUP_H
#include <proto/usergroup.h>
#endif

#define	STDIN_FILENO	0	/* standard input file descriptor */
#define	STDOUT_FILENO	1	/* standard output file descriptor */
#define	STDERR_FILENO	2	/* standard error file descriptor */

#ifndef NULL
#define	NULL		0	/* null pointer constant */
#endif

#ifndef _POSIX_SOURCE
#include <sys/select.h>
#endif

__BEGIN_DECLS
__dead void	 _exit __P((int)) __attribute__((noreturn));
int	 access __P((const char *, int));
unsigned alarm __P((unsigned));
int	 chdir __P((const char *));
int	 chown __P((const char *, uid_t, gid_t));
int	 close __P((int));
size_t	 confstr __P((int, char *, size_t));
char	*cuserid __P((char *));
int	 dup __P((int));
int	 dup2 __P((int, int));
int	 execl __P((const char *, const char *, ...));
int	 execle __P((const char *, const char *, ...));
int	 execlp __P((const char *, const char *, ...));
int	 execv __P((const char *, char * const *));
int	 execve __P((const char *, char * const *, char * const *));
int	 execvp __P((const char *, char * const *));
pid_t	 fork __P((void));
long	 fpathconf __P((int, int));		/* not yet */
char	*getcwd __P((char *, size_t));
gid_t	 getegid __P((void));
uid_t	 geteuid __P((void));
gid_t	 getgid __P((void));

#if 0
int	 initgroups __P((const char *, int));
int	 getgroups __P((int, int *));
int	 setgroups __P((int, const int *));
int	 setregid __P((int, int));
int	 setreuid __P((int, int));
#endif /* LIBRARIES_USERGROUP_H */

char	*getlogin __P((void));
pid_t	 getpgrp __P((void));
#if 1
#define	getpid() ((ULONG) FindTask(NULL))
#else
pid_t	 getpid __P((void));
#endif
pid_t	 getppid __P((void));
uid_t	 getuid __P((void));
int	 isatty __P((int));
int	 link __P((const char *, const char *));
off_t	 lseek __P((int, off_t, int));
long	 pathconf __P((const char *, int));	/* not yet */
int	 pause __P((void));
int	 pipe __P((int *));
ssize_t	 read __P((int, void *, size_t));
int	 rmdir __P((const char *));
int	 setgid __P((gid_t));
int	 setpgid __P((pid_t, pid_t));
pid_t	 setsid __P((void));
int	 setuid __P((uid_t));
unsigned sleep __P((unsigned));
long	 sysconf __P((int));			/* not yet */
pid_t	 tcgetpgrp __P((int));
int	 tcsetpgrp __P((int, pid_t));
char	*ttyname __P((int));
int	 unlink __P((const char *));
ssize_t	 write __P((int, const void *, size_t));

#define tell(x)    lseek(x, 0L, 1)

#ifndef	_POSIX_SOURCE
int	 acct __P((const char *));
char	*brk __P((const char *));
int	 chroot __P((const char *));
char	*crypt __P((const char *, const char *));
int	 des_cipher __P((const char *, char *, long, int));
int	 des_setkey __P((const char *key));
int	 encrypt __P((char *, int));
void	 endusershell __P((void));
int	 exect __P((const char *, char * const *, char * const *));
int	 fchdir __P((int));
int	 fchown __P((int, uid_t, gid_t));
int	 fsync __P((int));
int	 ftruncate __P((int, off_t));
int	 getdomainname __P((char *, int));
#if 1
#else
int	 getdtablesize __P((void));
long	 gethostid __P((void));
int	 gethostname __P((char *, int));
#endif /* proto/socket.h */

mode_t	 getmode __P((const void *, mode_t));
int	 getpagesize __P((void));
char	*getpass __P((const char *));
char	*getusershell __P((void));
char	*getwd __P((char *));			/* obsoleted by getcwd() */
int	 iruserok __P((u_long, int, const char *, const char *));
int	 mknod __P((const char *, mode_t, dev_t));
int	 mkstemp __P((char *));
char	*mktemp __P((char *));
int	 nfssvc __P((int, void *));
int	 nice __P((int));
void	 psignal __P((unsigned int, const char *));
#ifdef _KERNEL
extern char *sys_siglist[];
#else
extern const char *const sys_siglist[];
#endif
int	 profil __P((char *, int, int, int));
int	 rcmd __P((char **, int, const char *,
		const char *, const char *, int *));
char	*re_comp __P((const char *));
int	 re_exec __P((const char *));
int	 readlink __P((const char *, char *, int));
int	 reboot __P((int));
int	 revoke __P((const char *));
int	 rresvport __P((int *));
int	 ruserok __P((const char *, int, const char *, const char *));
char	*sbrk __P((int));
int	 setdomainname __P((const char *, int));
int	 setegid __P((gid_t));
int	 seteuid __P((uid_t));
void	 sethostid __P((long));
int	 sethostname __P((const char *, int));
int	 setkey __P((const char *));
int	 setlogin __P((const char *));
void	*setmode __P((const char *));
int	 setpgrp __P((pid_t pid, pid_t pgrp));	/* obsoleted by setpgid() */
int	 setrgid __P((gid_t));
int	 setruid __P((uid_t));
void	 setusershell __P((void));
int	 swapon __P((const char *));
int	 symlink __P((const char *, const char *));
void	 sync __P((void));
int	 syscall __P((int, ...));
int	 truncate __P((const char *, off_t));
int	 ttyslot __P((void));
u_int	 ualarm __P((u_int, u_int));
int	 undelete __P((const char *));
int	 usleep __P((u_int));
void	*valloc __P((size_t));			/* obsoleted by malloc() */
pid_t	 vfork __P((void));

int	 getopt __P((int, char * const *, const char *));
extern	 char *optarg;			/* getopt(3) external variables */
extern	 int opterr;
extern	 int optind;
extern	 int optopt;
extern	 int optreset;
int	 getsubopt __P((char **, char * const *, char **));
extern	 char *suboptarg;		/* getsubopt(3) external variable */
#endif /* !_POSIX_SOURCE */

#ifdef _LARGEFILE64_SOURCE
off64_t	 lseek64 __P((int, off64_t, int));
int	 ftruncate64 __P((int, off64_t));
int	 truncate64 __P((const char *, off64_t));
#endif
__END_DECLS

#endif /* !_UNISTD_H_ */
