#ifndef _CONSTRUCTOR_H
#define _CONSTRUCTOR_H
/*
 * Constructors/destructors (SAS/C like)
 *
 * Priority can be a number between 0 and 32767,
 * default is 30000. Constructors return a nonzero value
 * to indicate failure, unlike SAS/C, returning a void is
 * not supported so beware!
 *
 * $Id: constructor.h,v 1.1.1.1 2005/03/15 16:00:48 laire Exp $
 */

#define CONSTRUCTOR(x) int __attribute__ ((constructor)) _CST_##x(void)
#define DESTRUCTOR(x) int __attribute__ ((destructor)) _DST_##x(void)

#define CONSTRUCTOR_P(x, pri) int __CSTP_##x(void); \
						   long _CSTP_##x[2] __attribute__ ((section(".ctdt"))) = {(long)__CSTP_##x,(long)pri}; \
						   int __CSTP_##x(void)

#define DESTRUCTOR_P(x, pri) void __DSTP_##x(void); \
						   long _DSTP_##x[2] __attribute__ ((section(".ctdt"))) = {(long)__DSTP_##x,(long)(-pri)-1}; \
						   void __DSTP_##x(void)

#define FP_CONSTRUCTOR(x) CONSTRUCTOR_P(x,100)
#define FP_DESTRUCTOR(x) DESTRUCTOR_P(x,100)

#define CBMLIB_CONSTRUCTOR(x) CONSTRUCTOR_P(x,110)
#define CBMLIB_DESTRUCTOR(x) DESTRUCTOR_P(x,110)

#define CLOCK_CONSTRUCTOR(x) CONSTRUCTOR_P(x,150)
#define CLOCK_DESTRUCTOR(x) DESTRUCTOR_P(x,150)

#define PROFILE_CONSTRUCTOR(x) CONSTRUCTOR_P(x,150)
#define PROFILE_DESTRUCTOR(x) DESTRUCTOR_P(x,150)
#define PROFILE_DESTRUCTOR_NAME(x) DESTRUCTOR_NAME(x,150)

#define COVER_CONSTRUCTOR(x) CONSTRUCTOR_P(x,210)
#define COVER_DESTRUCTOR(x) DESTRUCTOR_P(x,210)

#define MEMCLEANUP_CONSTRUCTOR(x) CONSTRUCTOR_P(x,250)
#define MEMCLEANUP_DESTRUCTOR(x) DESTRUCTOR_P(x,250)

#define STACKEXT_CONSTRUCTOR(x) CONSTRUCTOR_P(x,250)
#define STACKEXT_DESTRUCTOR(x) DESTRUCTOR_P(x,250)

#define DFIND_CONSTRUCTOR(x) DESTRUCTOR_P(x,300)
#define DFIND_DESTRUCTOR(x) DESTRUCTOR_P(x,300)

#define STDIO_CONSTRUCTOR(x) CONSTRUCTOR_P(x,500)
#define STDIO_DESTRUCTOR(x) DESTRUCTOR_P(x,500)

#define CPPIO_CONSTRUCTOR(x) CONSTRUCTOR_P(x,4990)
#define CPPIO_DESTRUCTOR(x) DESTRUCTOR_P(x,4990)

#define CPP_CONSTRUCTOR(x) CONSTRUCTOR_P(x,5000)
#define CPP_DESTRUCTOR(x) DESTRUCTOR_P(x,5000)

#define DEFAULT_CONSTRUCTOR(x) CONSTRUCTOR_P(x,30000)
#define DEFAULT_DESTRUCTOR(x) DESTRUCTOR_P(x,30000)

#endif
