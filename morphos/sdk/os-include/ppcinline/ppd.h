/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_PPD_H
#define _PPCINLINE_PPD_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef PPD_BASE_NAME
#define PPD_BASE_NAME PPDBase
#endif /* !PPD_BASE_NAME */

#define OpenPPDFromIFF(__p0, __p1) \
	(((PPD *(*)(void *, STRPTR , PPD_ERROR *))*(void**)((long)(PPD_BASE_NAME) - 34))((void*)(PPD_BASE_NAME), __p0, __p1))

#define FindPPD_Option(__p0, __p1) \
	(((OPTION_NODE *(*)(void *, PPD *, STRPTR ))*(void**)((long)(PPD_BASE_NAME) - 46))((void*)(PPD_BASE_NAME), __p0, __p1))

#define FindPPD_CustomOptionItem(__p0, __p1) \
	(((CUSTOM_ITEM_NODE *(*)(void *, CUSTOM_OPTION_NODE *, STRPTR ))*(void**)((long)(PPD_BASE_NAME) - 88))((void*)(PPD_BASE_NAME), __p0, __p1))

#define OpenPPD(__p0, __p1) \
	(((PPD *(*)(void *, STRPTR , PPD_ERROR *))*(void**)((long)(PPD_BASE_NAME) - 76))((void*)(PPD_BASE_NAME), __p0, __p1))

#define PPDWritePPDToIFF(__p0, __p1) \
	(((PPD_ERROR (*)(void *, STRPTR , PPD *))*(void**)((long)(PPD_BASE_NAME) - 40))((void*)(PPD_BASE_NAME), __p0, __p1))

#define ClosePPD(__p0) \
	(((void (*)(void *, PPD *))*(void**)((long)(PPD_BASE_NAME) - 58))((void*)(PPD_BASE_NAME), __p0))

#define FindPPD_PageSize(__p0, __p1) \
	(((PAGE_SIZE_NODE *(*)(void *, PPD *, STRPTR ))*(void**)((long)(PPD_BASE_NAME) - 52))((void*)(PPD_BASE_NAME), __p0, __p1))

#define FindPPD_Attribute(__p0, __p1, __p2) \
	(((ATTRIBUTE_NODE *(*)(void *, PPD *, STRPTR , STRPTR ))*(void**)((long)(PPD_BASE_NAME) - 70))((void*)(PPD_BASE_NAME), __p0, __p1, __p2))

#define FindPPD_OptionItem(__p0, __p1) \
	(((OPTION_ITEM_NODE *(*)(void *, OPTION_NODE *, STRPTR ))*(void**)((long)(PPD_BASE_NAME) - 64))((void*)(PPD_BASE_NAME), __p0, __p1))

#define OpenPPDFromPPD(__p0, __p1) \
	(((PPD *(*)(void *, STRPTR , PPD_ERROR *))*(void**)((long)(PPD_BASE_NAME) - 28))((void*)(PPD_BASE_NAME), __p0, __p1))

#define FindPPD_CustomOption(__p0, __p1) \
	(((CUSTOM_OPTION_NODE *(*)(void *, PPD *, STRPTR ))*(void**)((long)(PPD_BASE_NAME) - 82))((void*)(PPD_BASE_NAME), __p0, __p1))

#define FaultPPD(__p0) \
	(((CONST_STRPTR (*)(void *, PPD_ERROR ))*(void**)((long)(PPD_BASE_NAME) - 94))((void*)(PPD_BASE_NAME), __p0))

#endif /* !_PPCINLINE_PPD_H */
