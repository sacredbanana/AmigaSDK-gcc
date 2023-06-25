/*
 *	$Id: compiler.h,v 1.1 2008-09-15 13:14:19 sarcher Exp $
 *
 *	:ts=4
 *
 *	Amiga ROM file system reimplementation
 *	Copyright © 2001-2005 by Olaf Barthel
 *	All Rights Reserved
 */

#ifndef _COMPILER_H
#define _COMPILER_H

/****************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif /* EXEC_TYPES_H */

/****************************************************************************/

#ifdef __SASC

/* Profiling support code. */
#include <sprof.h>

/* Data copying */
#undef bcopy
#undef memcpy
extern void __regargs bcopy(const void *from,void *to,long size);
#define memcpy(to,from,size) bcopy(from,to,size)

#else

#define PROFILE_OFF() ((void)0)
#define PROFILE_ON()  ((void)0)

#endif /* __SASC */

/****************************************************************************/

/* The following definitions are redundant in the V50 AmigaOS header files. */
#ifndef AMIGA_COMPILER_H

#if defined(__SASC)
#define ASM __asm
#define REG(r,p) register __##r p
#define INLINE __inline
#define INTERRUPT __interrupt
#define FAR __far
#define STDARGS __stdargs
#elif defined(__MORPHOS__)
#define ASM
#define REG(r,p) p
#define INLINE __inline__
#define INTERRUPT
#define FAR
#define STDARGS
#elif defined(__GNUC__)
#define ASM
#define REG(r,p) p __asm(#r)
#define INLINE __inline__
#define INTERRUPT __attribute__((__interrupt__))
#define FAR
#define STDARGS __attribute__((__stkparm__))
#else
#define ASM
#define REG(x)
#define INLINE
#define INTERRUPT
#define FAR
#define STDARGS
#endif /* __SASC */

#endif /* AMIGA_COMPILER_H */

/****************************************************************************/

#if defined(__MORPHOS__)
#define VAR_ARGS __varargs68k
#elif defined(__amigaos4__)
#define VAR_ARGS __attribute__((linearvarargs))
#else
#define VAR_ARGS
#endif /* __MORPHOS__ */

/****************************************************************************/

#endif /* _COMPILER_H */
