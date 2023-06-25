#ifndef _SYS_UIO_H
#define _SYS_UIO_H

#include <sys/types.h>
#include <stddef.h>
#include <sys/syslimits.h>

_BEGIN_STD_C

#define UIO_MAXIOV	IOV_MAX
#define	MAX_IOVEC	IOV_MAX

typedef struct iovec
{
	void *	iov_base;
	size_t	iov_len;
} iovec_t;

extern ssize_t readv (int, const struct iovec *, int);
extern ssize_t writev (int, const struct iovec *, int);

_END_STD_C

#endif /* _SYS_UIO_H */
