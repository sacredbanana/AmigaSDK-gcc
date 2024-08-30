/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SPELLCHECKER_H
#define _PPCINLINE_SPELLCHECKER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SPELLCHECKER_BASE_NAME
#define SPELLCHECKER_BASE_NAME SpellCheckerBase
#endif /* !SPELLCHECKER_BASE_NAME */

#define OpenDictionary(__p0, __p1) \
	(((APTR (*)(void *, CONST_STRPTR , struct TagItem *))*(void**)((long)(SPELLCHECKER_BASE_NAME) - 28))((void*)(SPELLCHECKER_BASE_NAME), __p0, __p1))

#define CloseDictionary(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(SPELLCHECKER_BASE_NAME) - 34))((void*)(SPELLCHECKER_BASE_NAME), __p0))

#define Suggest(__p0, __p1, __p2) \
	(((STRPTR *(*)(void *, APTR , CONST_STRPTR , struct TagItem *))*(void**)((long)(SPELLCHECKER_BASE_NAME) - 40))((void*)(SPELLCHECKER_BASE_NAME), __p0, __p1, __p2))

#define Learn(__p0, __p1) \
	(((BOOL (*)(void *, APTR , CONST_STRPTR ))*(void**)((long)(SPELLCHECKER_BASE_NAME) - 46))((void*)(SPELLCHECKER_BASE_NAME), __p0, __p1))

#define SpellCheck(__p0, __p1, __p2) \
	(((BOOL (*)(void *, APTR , CONST_STRPTR , struct TagItem *))*(void**)((long)(SPELLCHECKER_BASE_NAME) - 52))((void*)(SPELLCHECKER_BASE_NAME), __p0, __p1, __p2))

#define ListDictionaries(__p0, __p1, __p2) \
	(((APTR (*)(void *, VOID *, ULONG , struct TagItem *))*(void**)((long)(SPELLCHECKER_BASE_NAME) - 58))((void*)(SPELLCHECKER_BASE_NAME), __p0, __p1, __p2))

#endif /* !_PPCINLINE_SPELLCHECKER_H */
