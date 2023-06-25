#ifndef	_MACHSETHMP_H_
#define	_MACHSETHMP_H_

_BEGIN_STD_C

#ifdef __PPC__
#if defined(__ALTIVEC__) || defined(__amigaos4__)
#define _JBLEN 64
#else
#define _JBLEN 32
#endif
#define _JBTYPE double
#endif

#ifdef _JBLEN
#ifdef _JBTYPE
typedef	_JBTYPE jmp_buf[_JBLEN];
#else
typedef	int jmp_buf[_JBLEN];
#endif
#endif

_END_STD_C

#endif	/* _MACHSETHMP_H_ */
