/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_RANDOM_H
#define _PPCINLINE_RANDOM_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef RANDOM_BASE_NAME
#define RANDOM_BASE_NAME RandomBase
#endif /* !RANDOM_BASE_NAME */

#define Random() \
	(((ULONG (*)(void *))*(void**)((long)(RANDOM_BASE_NAME) - 28))((void*)(RANDOM_BASE_NAME)))

#define RandomStir() \
	(((void (*)(void *))*(void**)((long)(RANDOM_BASE_NAME) - 40))((void*)(RANDOM_BASE_NAME)))

#define RandomBytes(__p0, __p1) \
	(((void (*)(void *, APTR , LONG ))*(void**)((long)(RANDOM_BASE_NAME) - 46))((void*)(RANDOM_BASE_NAME), __p0, __p1))

#define RandomByte() \
	(((UBYTE (*)(void *))*(void**)((long)(RANDOM_BASE_NAME) - 34))((void*)(RANDOM_BASE_NAME)))

#endif /* !_PPCINLINE_RANDOM_H */
