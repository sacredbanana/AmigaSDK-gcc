#ifndef _SYS_SELECT_H_
#define _SYS_SELECT_H_

#include <_ansi.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <signal.h>

_BEGIN_STD_C

#ifdef __TIMEVAL_ALREADY_DEFINED
# ifdef __USE_OLD_TIMEVAL__
#  define tv_sec  tv_secs
#  define tv_usec tv_micro
# endif /* __USE_OLD_TIMEVAL__ */
#else
struct timeval
{
   time_t      tv_sec;
   suseconds_t tv_usec;
};
# define __TIMEVAL_ALREADY_DEFINED
# ifdef __USE_OLD_TIMEVAL__
#  define tv_secs  tv_sec
#  define tv_micro tv_usec
# endif /* __USE_OLD_TIMEVAL__ */
#endif /* __TIMEVAL_ALREADY_DEFINED */


/*
 * In case the select() data structures and macros are already
 * defined by somebody else...
 */

#ifndef FD_SET

#define	NBBY 8	/* number of bits in a byte */

/*
 * Select uses bit masks of file descriptors in longs.  These macros
 * manipulate such bit fields (the filesystem macros use chars).
 * FD_SETSIZE may be defined by the user, but the default here should
 * be enough for most uses.
 */
#ifndef	FD_SETSIZE
#define	FD_SETSIZE 256
#endif

typedef long fd_mask;
#define NFDBITS	(sizeof(fd_mask) * NBBY) /* bits per mask */

#ifndef howmany
#define	howmany(x, y)	(((x) + ((y) - 1)) / (y))
#endif

typedef	struct fd_set
{
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} fd_set;

#define	FD_SET(n, p)	((void)((p)->fds_bits[(n)/NFDBITS] |= (1 << ((n) % NFDBITS))))
#define	FD_CLR(n, p)	((void)((p)->fds_bits[(n)/NFDBITS] &= ~(1 << ((n) % NFDBITS))))
#define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1 << ((n) % NFDBITS)))
#define	FD_COPY(f, t)	((void)memmove((t), (f), sizeof(*(f))))
#define	FD_ZERO(p)	((void)memset((p), 0, sizeof(*(p))))

#endif /* FD_SET */

#ifdef __amigaos4__
int waitselect (int, fd_set *, fd_set *, fd_set *, struct timeval *, unsigned int *);
#else
int pselect (int, fd_set *, fd_set *, fd_set *, const struct timespec *, const sigset_t *);
#endif
int select (int, fd_set *, fd_set *, fd_set *, struct timeval *);


_END_STD_C

#endif /* _SYS_SELECT_H_ */
