/*      $NetBSD: cdefs.h,v 1.2 1995/03/23 20:10:33 jtc Exp $    */

/*
 * Written by J.T. Conklin <jtc@wimsey.com> 01/17/95.
 * Public domain.
 */

#ifndef _MACHINE_CDEFS_H_
#define _MACHINE_CDEFS_H_

#ifdef __PPC__

#define _C_LABEL(x)     _STRING(x)
#define __indr_reference(sym,alias)     \
	__asm__(".globl " #sym); 	\
	__asm__(".set " #sym "," #alias)
#define __warn_references(sym,msg)      \
	__asm__(".stabs \"" msg "\",30,0,0,0"); \
	__asm__(".stabs \"_" #sym "\",1,0,0,0")

#else

#ifdef __STDC__
#define _C_LABEL(x)     _STRING(_ ## x)
#else
#define _C_LABEL(x)     _STRING(_/**/x)
#endif

#ifdef __GNUC__
#ifdef __STDC__
#define __indr_reference(sym,alias)     \
	__asm__(".stabs \"_" #alias "\",11,0,0,0");     \
	__asm__(".stabs \"_" #sym "\",1,0,0,0")
#define __warn_references(sym,msg)      \
	__asm__(".stabs \"" msg "\",30,0,0,0");         \
	__asm__(".stabs \"_" #sym "\",1,0,0,0")
#else
#define __indr_reference(sym,alias)     \
	__asm__(".stabs \"_/**/alias\",11,0,0,0");      \
	__asm__(".stabs \"_/**/sym\",1,0,0,0")
#define __warn_references(sym,msg)      \
	__asm__(".stabs msg,30,0,0,0");                 \
	__asm__(".stabs \"_/**/sym\",1,0,0,0")
#endif
#endif
#endif

#endif /* !_MACHINE_CDEFS_H_ */
