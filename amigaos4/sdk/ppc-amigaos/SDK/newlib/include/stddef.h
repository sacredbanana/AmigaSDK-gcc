#if defined(__GNUC__)
#include_next <stddef.h>
#elif defined(__VBCC__) 

#ifndef __STDDEF_H
#define __STDDEF_H 1

/*
  Adapt as needed.
*/
#ifndef __SIZE_T
#define __SIZE_T 1
typedef unsigned long size_t;
#endif

/*
  Adapt as needed.
*/
#ifndef __PTRDIFF_T
#define __PTRDIFF_T 1
typedef long ptrdiff_t;
#endif

#ifndef __WCHAR_T
#define __WCHAR_T
typedef int wchar_t;
#endif

#ifndef __WINT_T
#define __WINT_T
typedef unsigned int wint_t;
#endif

#undef NULL
#define NULL ((void *)0)

#undef offsetof
#define offsetof(P,M) __offsetof(P,M)

#endif

#else
#error Compiler not supported
#endif 
