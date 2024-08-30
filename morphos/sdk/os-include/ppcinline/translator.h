/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_TRANSLATOR_H
#define _PPCINLINE_TRANSLATOR_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef TRANSLATOR_BASE_NAME
#define TRANSLATOR_BASE_NAME TranslatorBase
#endif /* !TRANSLATOR_BASE_NAME */

#define Translate(__p0, __p1, __p2, __p3) \
	LP4(30, LONG , Translate, \
		CONST_STRPTR , __p0, a0, \
		LONG , __p1, d0, \
		STRPTR , __p2, a1, \
		LONG , __p3, d1, \
		, TRANSLATOR_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_TRANSLATOR_H */
