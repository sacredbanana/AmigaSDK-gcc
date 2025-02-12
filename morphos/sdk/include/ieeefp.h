/*	$NetBSD: ieeefp.h,v 1.4 1998/01/09 08:03:43 perry Exp $	*/
/* $FreeBSD: src/include/ieeefp.h,v 1.7 2003/01/19 06:01:32 marcel Exp $ */

/* 
 * Written by J.T. Conklin, Apr 6, 1995
 * Public domain.
 */

#ifndef _IEEEFP_H_
#define _IEEEFP_H_

#include <sys/cdefs.h>
#include <machine/ieeefp.h>

__BEGIN_DECLS
extern fp_rnd_t    fpgetround(void);
extern fp_rnd_t    fpsetround(fp_rnd_t);
extern fp_except_t fpgetmask(void);
extern fp_except_t fpsetmask(fp_except_t);
extern fp_except_t fpgetsticky(void);
extern fp_except_t fpsetsticky(fp_except_t);
__END_DECLS

#endif /* _IEEEFP_H_ */
