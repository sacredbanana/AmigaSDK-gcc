#ifndef HARDWARE_BYTESWAP_H
#define HARDWARE_BYTESWAP_H

/*
	byteswap routines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

/*
** generic byteswap routines, 16, 32 and 2 x 16 bits
*/

#define __SWAPWORD_C(x) ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8))

#define __SWAPLONG_C(x)	\
	((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
	 (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))

#define __SWAP2WORD_C(x)	\
	((((x) & 0x00ff00ff) << 8) | \
	 (((x) & 0xff00ff00) >> 8))

#define __SWAPQUAD_C(x)	\
	((((x) & 0xff00000000000000ULL) >> 56) | \
	 (((x) & 0x00ff000000000000ULL) >> 40) | \
	 (((x) & 0x0000ff0000000000ULL) >> 24) | \
	 (((x) & 0x000000ff00000000ULL) >>  8) | \
	 (((x) & 0x00000000ff000000ULL) <<  8) | \
	 (((x) & 0x0000000000ff0000ULL) << 24) | \
	 (((x) & 0x000000000000ff00ULL) << 40) | \
	 (((x) & 0x00000000000000ffULL) << 56))

/*
** byteswap for constant values
*/
#define SWAPWORD_C(x)	__SWAPWORD_C((UWORD) (x))
#define SWAPLONG_C(x)	__SWAPLONG_C((ULONG) (x))
#define SWAP2WORD_C(x)	__SWAP2WORD_C((ULONG) (x))
#define SWAPQUAD_C(x)	__SWAPQUAD_C((UQUAD) (x))

/*
** __extension__ supress warnings of GNU C extensions if -pedantic is used
*/

#if defined(__GNUC__) && defined(mc68000)

/*
** m68k assembler byteswap routines
*/

#define SWAPWORD(x)					\
(__extension__						\
({	register UWORD __x;				\
	if (__builtin_constant_p(x))			\
	{						\
		__x = SWAPWORD_C(x);			\
	}						\
	else						\
	{						\
		__asm__ (				\
			"rolw #8,%0"			\
		: "=d" (__x)				\
		: "0" ((UWORD) (x))			\
		: "cc");				\
	}						\
	__x;						\
}))

#define SWAPLONG(x)					\
(__extension__						\
({	register ULONG __x;				\
	if (__builtin_constant_p(x))			\
	{						\
		__x = SWAPLONG_C(x);			\
	}						\
	else						\
	{						\
		__asm__ (				\
			"rolw #8,%0;"			\
		"	swap %0;"			\
		"	rolw #8,%0"			\
		: "=d" (__x)				\
		: "0" ((ULONG) (x))			\
		: "cc");				\
	}						\
	__x;						\
}))

#define SWAP2WORD(x)					\
(__extension__						\
({	register ULONG __x;				\
	if (__builtin_constant_p(x))			\
	{						\
		__x = SWAP2WORD_C(x);			\
	}						\
	else						\
	{						\
		__asm__ (				\
			"rolw #8,%0;"			\
		"	swap %0;"			\
		"	rolw #8,%0;"			\
		"	swap %0"			\
		: "=d" (__x)				\
		: "0" ((ULONG) (x))			\
		: "cc");				\
	}						\
	__x;						\
}))

#elif defined(__GNUC__) && (defined(PPC) || defined(__PPC__) || defined(__powerpc__))

/*
** powerpc assembler byteswap routines
*/

#define SWAPWORD(x)					\
(__extension__						\
({	register UWORD __x;				\
	if (__builtin_constant_p(x))			\
	{						\
		__x = SWAPWORD_C(x);			\
	}						\
	else						\
	{						\
		__asm__ (				\
			"rotrwi %0,%0,8;"		\
		"	inslwi %0,%0,8,16"		\
		: "=r" (__x)				\
		: "0" ((UWORD) (x)));			\
	}						\
	__x;						\
}))

#define SWAPLONG(x)					\
(__extension__						\
({	register ULONG __x;				\
	if (__builtin_constant_p(x))			\
	{						\
		__x = SWAPLONG_C(x);			\
	}						\
	else						\
	{						\
		__asm__ (				\
		"	rlwinm %0,%1,24,0,31;"       	\
		"	rlwimi %0,%1,8,8,15;"        	\
		"	rlwimi %0,%1,8,24,31;"		\
		: "=&r" (__x)				\
		: "r" ((unsigned int) (x)));		\
	}						\
	__x;						\
}))


#define SWAPWORD_P(x)					\
(__extension__						\
({							\
	__asm__ (					\
		"lhbrx 0,0,%0;"				\
	"	sth   0,0(%0)"				\
	: /* no outputs */				\
	: "r" ((UWORD *) (x))				\
	: "memory", "r0");				\
}))

#define SWAPLONG_P(x)					\
(__extension__						\
({							\
	__asm__ (					\
		"lwbrx 0,0,%0;"				\
	"	stw   0,0(%0)"				\
	: /* no outputs */				\
	: "r" ((ULONG *) (x))				\
	: "memory", "r0");				\
}))

#define SWAP2WORD_P(x)					\
(__extension__						\
({							\
	__asm__ (					\
		"lhbrx 0,0,%0;"				\
	"	sth   0,0(%0);"				\
	"	lhbrx 0,%1,%0;"				\
	"	sth   0,2(%0)"				\
	: /* no outputs */				\
	: "r" ((ULONG *) (x)), "r" (2)			\
	: "memory", "r0");				\
}))

#elif defined(__GNUC__)

/*
** Use default GCC routines... see below.
*/

#else /* defined(__GNUC__) */

/*
** CPU independant byteswap for all non-GCC systems
*/

#define SWAPWORD(x)		SWAPWORD_C(x)
#define SWAPLONG(x)		SWAPLONG_C(x)
#define SWAP2WORD(x)		SWAPWORD_C(x)
#define SWAPQUAD(x)		SWAPQUAD_C(x)

#define SWAPWORD_P(x)	\
do { register UWORD __xv, *__xx = (UWORD *) (x); \
	__xv = *__xx; *__xx = SWAPWORD(__xv); } while(0)

#define SWAPLONG_P(x)	\
do { register ULONG __xv, *__xx = (ULONG *) (x); __xv = *__xx; \
	*__xx = SWAPLONG(__xv); } while(0)

#define SWAP2WORD_P(x)	\
do { register ULONG __xv, *__xx = (ULONG *) (x); \
	__xv = *__xx; *__xx = SWAP2WORD(__xv); } while(0)


#define SWAPQUAD_P(x)	\
do { register UQUAD __xv, *__xx = (UQUAD *) (x); __xv = *__xx; \
	*__xx = SWAPQUAD(__xv); } while(0)

#endif /* defined(__GNUC__) && defined(mc68000) */


/*
** CPU independant byteswap for all GCC systems
*/
#ifndef SWAPWORD
#define SWAPWORD(x)					\
(__extension__						\
({	register UWORD __x;				\
	if (__builtin_constant_p(x))			\
	{						\
		__x = __SWAPWORD_C((UWORD) (x));	\
	}						\
	else						\
	{						\
		__x = ((UWORD) (x));			\
		__x = __SWAPWORD_C(__x);		\
	}						\
	__x;						\
}))
#endif /* SWAPWORD */

#ifndef SWAPLONG
#define SWAPLONG(x)					\
(__extension__						\
({	register ULONG __x;				\
	if (__builtin_constant_p(x))			\
	{						\
		__x = __SWAPLONG_C((ULONG) (x));	\
	}						\
	else						\
	{						\
		__x = ((ULONG) (x));			\
		__x = __SWAPLONG_C(__x);		\
	}						\
	__x;						\
}))
#endif /* SWAPLONG */

#ifndef SWAP2WORD
#define SWAP2WORD(x)					\
(__extension__						\
({	register ULONG __x;				\
	if (__builtin_constant_p(x))			\
	{						\
		__x = __SWAP2WORD_C((ULONG) (x));	\
	}						\
	else						\
	{						\
		__x = ((ULONG) (x));			\
		__x = __SWAP2WORD_C(__x);		\
	}						\
	__x;						\
}))
#endif /* SWAP2WORD */

#ifndef SWAPQUAD
#define SWAPQUAD(x)					\
(__extension__						\
({	register UQUAD __x;				\
	if (__builtin_constant_p(x))			\
	{						\
		__x = __SWAPQUAD_C((UQUAD) (x));	\
	}						\
	else						\
	{						\
		__x = ((UQUAD) (x));			\
		__x = __SWAPQUAD_C(__x);		\
	}						\
	__x;						\
}))
#endif /* SWAPQUAD */

#ifndef SWAPWORD_P
#define SWAPWORD_P(x)	\
({ register UWORD __xv, *__xx = (UWORD *) (x); \
	__xv = *__xx; *__xx = SWAPWORD(__xv); })
#endif /* SWAPWORD_P */

#ifndef SWAPLONG_P
#define SWAPLONG_P(x)	\
({ register ULONG __xv, *__xx = (ULONG *) (x); \
	__xv = *__xx; *__xx = SWAPLONG(__xv); })
#endif /* SWAPLONG_P */

#ifndef SWAP2WORD_P
#define SWAP2WORD_P(x)	\
({ register ULONG __xv, *__xx = (ULONG *) (x); \
	__xv = *__xx; *__xx = SWAP2WORD(__xv); })
#endif /* SWAP2WORD_P */

#ifndef SWAPQUAD_P
#define SWAPQUAD_P(x)	\
({ register UQUAD __xv, *__xx = (UQUAD *) (x); \
	__xv = *__xx; *__xx = SWAPQUAD(__xv); })
#endif /* SWAPQUAD_P */


#if defined(__BIG_ENDIAN__) | defined(_BIG_ENDIAN) | defined(mc68000) | \
	defined(__M68K__) | defined(__MORPHOS__) | defined(__SASC)

/*
** big-endian cpus
*/

#define BE_SWAPWORD_C(x)	SWAPWORD_C(x)
#define BE_SWAPLONG_C(x)	SWAPLONG_C(x)
#define BE_SWAP2WORD_C(x)	SWAP2WORD_C(x)
#define BE_SWAPQUAD_C(x)	SWAPQUAD_C(x)

#define BE_SWAPWORD(x)		SWAPWORD(x)
#define BE_SWAPLONG(x)		SWAPLONG(x)
#define BE_SWAP2WORD(x)		SWAP2WORD(x)
#define BE_SWAPQUAD(x)		SWAPQUAD(x)

#define BE_SWAPWORD_P(x)	SWAPWORD_P(x)
#define BE_SWAPLONG_P(x)	SWAPLONG_P(x)
#define BE_SWAP2WORD_P(x)	SWAP2WORD_P(x)
#define BE_SWAPQUAD_P(x)	SWAPQUAD_P(x)

#define LE_SWAPWORD_C(x)	(x)
#define LE_SWAPLONG_C(x)	(x)
#define LE_SWAP2WORD_C(x)	(x)
#define LE_SWAPQUAD_C(x)	(x)

#define LE_SWAPWORD(x)		(x)
#define LE_SWAPLONG(x)		(x)
#define LE_SWAP2WORD(x)		(x)
#define LE_SWAPQUAD(x)		(x)

#define LE_SWAPWORD_P(x)
#define LE_SWAPLONG_P(x)
#define LE_SWAP2WORD_P(x)
#define LE_SWAPQUAD_P(x)

#elif defined(__LITTLE_ENDIAN__) | defined(_LITTLE_ENDIAN)

/*
** little-endian cpus
*/

#define BE_SWAPWORD_C(x)	(x)
#define BE_SWAPLONG_C(x)	(x)
#define BE_SWAP2WORD_C(x)	(x)
#define BE_SWAPQUAD_C(x)	(x)

#define BE_SWAPWORD(x)		(x)
#define BE_SWAPLONG(x)		(x)
#define BE_SWAP2WORD(x)		(x)
#define BE_SWAPQUAD(x)		(x)

#define BE_SWAPWORD_P(x)
#define BE_SWAPLONG_P(x)
#define BE_SWAP2WORD_P(x)
#define BE_SWAPQUAD_P(x)

#define LE_SWAPWORD_C(x)	SWAPWORD_C(x)
#define LE_SWAPLONG_C(x)	SWAPLONG_C(x)
#define LE_SWAP2WORD_C(x)	SWAP2WORD_C(x)
#define LE_SWAPQUAD_C(x)	SWAPQUAD_C(x)

#define LE_SWAPWORD(x)		SWAPWORD(x)
#define LE_SWAPLONG(x)		SWAPLONG(x)
#define LE_SWAP2WORD(x)		SWAP2WORD(x)
#define LE_SWAPQUAD(x)		SWAPQUAD(x)

#define LE_SWAPWORD_P(x)	SWAPWORD_P(x)
#define LE_SWAPLONG_P(x)	SWAPLONG_P(x)
#define LE_SWAP2WORD_P(x)	SWAP2WORD_P(x)
#define LE_SWAPQUAD_P(x)	SWAPQUAD_P(x)

#else /* endianity */

#error UNKNOWN ENDIANITY!

#endif /* endianity */


#endif /* HARDWARE_BYTESWAP_H */
