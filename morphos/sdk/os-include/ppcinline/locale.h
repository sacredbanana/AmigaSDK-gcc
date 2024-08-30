/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_LOCALE_H
#define _PPCINLINE_LOCALE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef LOCALE_BASE_NAME
#define LOCALE_BASE_NAME LocaleBase
#endif /* !LOCALE_BASE_NAME */

#define UCS4_IsAlNum(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 262))(__p0))

#define UCS4_Decompose(__p0) \
	(((CONST_WSTRPTR (*)(WCHAR , void *))*(void**)((long)(LOCALE_BASE_NAME) - 364))(__p0, (void*)(LOCALE_BASE_NAME)))

#define IsDigit(__p0, __p1) \
	LP2(102, BOOL , IsDigit, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UCS4_FormatClockData(__p0, __p1, __p2, __p3) \
	(((VOID (*)(CONST struct Locale *, CONST_WSTRPTR , CONST struct ClockData *, CONST struct Hook *, void *))*(void**)((long)(LOCALE_BASE_NAME) - 460))(__p0, __p1, __p2, __p3, (void*)(LOCALE_BASE_NAME)))

#define UCS4_GetCombiningClass(__p0) \
	(((ULONG (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 412))(__p0))

#define UCS4_IsXDigit(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 322))(__p0))

#define TZAscTime(__p0, __p1) \
	(((STRPTR (*)(const struct tm *, STRPTR , void *))*(void**)((long)(LOCALE_BASE_NAME) - 526))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))


#define FormatDate(__p0, __p1, __p2, __p3) \
	LP4NR(60, FormatDate, \
		CONST struct Locale *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		CONST struct DateStamp *, __p2, a2, \
		CONST struct Hook *, __p3, a3, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FormatClockData(__p0, __p1, __p2, __p3) \
	(((VOID (*)(CONST struct Locale *, CONST_STRPTR , CONST struct ClockData *, CONST struct Hook *, void *))*(void**)((long)(LOCALE_BASE_NAME) - 448))(__p0, __p1, __p2, __p3, (void*)(LOCALE_BASE_NAME)))

#define OpenCatalogA(__p0, __p1, __p2) \
	LP3(150, struct Catalog *, OpenCatalogA, \
		CONST struct Locale *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		CONST struct TagItem *, __p2, a2, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UCS4_IsNSM(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 370))(__p0))

#define GetCatalogStr(__p0, __p1, __p2) \
	LP3(72, STRPTR , GetCatalogStr, \
		CONST struct Catalog *, __p0, a0, \
		LONG , __p1, d0, \
		CONST_STRPTR , __p2, a1, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IsGraph(__p0, __p1) \
	LP2(108, BOOL , IsGraph, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StrnCmp(__p0, __p1, __p2, __p3, __p4) \
	LP5(180, LONG , StrnCmp, \
		CONST struct Locale *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		CONST_STRPTR , __p2, a2, \
		LONG , __p3, d0, \
		ULONG , __p4, d1, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UCS4_IsLower(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 292))(__p0))

#define UCS4_CanonicalDecompose(__p0) \
	(((CONST_WSTRPTR (*)(WCHAR , void *))*(void**)((long)(LOCALE_BASE_NAME) - 376))(__p0, (void*)(LOCALE_BASE_NAME)))

#define UCS4_ConvToUpper(__p0) \
	(((WCHAR (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 238))(__p0))

#define IsAlpha(__p0, __p1) \
	LP2(90, BOOL , IsAlpha, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IsPrint(__p0, __p1) \
	LP2(120, BOOL , IsPrint, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UCS4_StrToUpper(__p0, __p1, __p2, __p3, __p4) \
	(((LONG (*)(CONST struct Locale *, CONST_WSTRPTR , WSTRPTR , ULONG , ULONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 358))(__p0, __p1, __p2, __p3, __p4, (void*)(LOCALE_BASE_NAME)))

#define IsSpace(__p0, __p1) \
	LP2(132, BOOL , IsSpace, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TZGetSysLocalTime(__p0, __p1) \
	(((ULONG (*)(ULONG , CONST_STRPTR , void *))*(void**)((long)(LOCALE_BASE_NAME) - 484))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))

#define FormatString(__p0, __p1, __p2, __p3) \
	LP4(66, APTR , FormatString, \
		CONST struct Locale *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		CONST_APTR , __p2, a2, \
		CONST struct Hook *, __p3, a3, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IsPunct(__p0, __p1) \
	LP2(126, BOOL , IsPunct, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define VSNPrintf(__p0, __p1, __p2, __p3, __p4) \
	(((ssize_t (*)(CONST struct Locale *, STRPTR , ssize_t , CONST_STRPTR , va_list , void *))*(void**)((long)(LOCALE_BASE_NAME) - 466))(__p0, __p1, __p2, __p3, __p4, (void*)(LOCALE_BASE_NAME)))

#define UTF8_DecodeSafe(__p0, __p1, __p2) \
	(((ULONG (*)(CONST_STRPTR , WCHAR *, ULONG ))*(void**)((long)(LOCALE_BASE_NAME) - 442))(__p0, __p1, __p2))

#define UCS4_Compare(__p0, __p1, __p2, __p3, __p4) \
	(((LONG (*)(CONST struct Locale *, CONST_WSTRPTR , CONST_WSTRPTR , LONG , ULONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 406))(__p0, __p1, __p2, __p3, __p4, (void*)(LOCALE_BASE_NAME)))

#define UCS4_IsPunct(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 304))(__p0))

#define TZTime2Posix(__p0, __p1) \
	(((ULONG (*)(APTR , ULONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 514))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))

#define TZPosix2Time(__p0, __p1) \
	(((ULONG (*)(APTR , ULONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 520))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))

#define GetLocaleStr(__p0, __p1) \
	LP2(78, STRPTR , GetLocaleStr, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TZLocalTime(__p0, __p1, __p2) \
	(((struct tm *(*)(APTR , ULONG , struct tm *, void *))*(void**)((long)(LOCALE_BASE_NAME) - 502))(__p0, __p1, __p2, (void*)(LOCALE_BASE_NAME)))

#define ConvertUCS4ToUTF8(__p0, __p1, __p2) \
	(((ULONG (*)(CONST_WSTRPTR , STRPTR , LONG ))*(void**)((long)(LOCALE_BASE_NAME) - 394))(__p0, __p1, __p2))

#define UCS4_IsGraph(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 286))(__p0))

#define UTF8_Decode(__p0, __p1) \
	(((ULONG (*)(CONST_STRPTR , WCHAR *))*(void**)((long)(LOCALE_BASE_NAME) - 244))(__p0, __p1))

#define UCS4_IsCombining(__p0) \
	(((ULONG (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 400))(__p0))

#define TZCTime(__p0, __p1) \
	(((STRPTR (*)(ULONG , STRPTR , void *))*(void**)((long)(LOCALE_BASE_NAME) - 532))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))

#define UCS4_IsCntrl(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 274))(__p0))

#define UCS4_IsSpace(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 310))(__p0))

#define UCS4_IsUpper(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 316))(__p0))

#define UCS4_NormalizedLength(__p0, __p1, __p2) \
	(((ULONG (*)(CONST_WSTRPTR , LONG , ULONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 418))(__p0, __p1, __p2, (void*)(LOCALE_BASE_NAME)))

#define ConvToLower(__p0, __p1) \
	LP2(48, ULONG , ConvToLower, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define IsUpper(__p0, __p1) \
	LP2(138, BOOL , IsUpper, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TZMKTime(__p0, __p1) \
	(((ULONG (*)(APTR , struct tm *, void *))*(void**)((long)(LOCALE_BASE_NAME) - 508))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))

#define TZGetSysTimeZone(__p0, __p1) \
	(((LONG (*)(STRPTR , LONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 544))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))

#define TZGMTime(__p0, __p1) \
	(((struct tm *(*)(ULONG , struct tm *, void *))*(void**)((long)(LOCALE_BASE_NAME) - 538))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))

#define IsXDigit(__p0, __p1) \
	LP2(144, BOOL , IsXDigit, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TZFree(__p0) \
	(((VOID (*)(APTR , void *))*(void**)((long)(LOCALE_BASE_NAME) - 496))(__p0, (void*)(LOCALE_BASE_NAME)))

#define ConvToUpper(__p0, __p1) \
	LP2(54, ULONG , ConvToUpper, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UCS4_FormatString(__p0, __p1, __p2, __p3) \
	(((APTR (*)(CONST struct Locale *, CONST_WSTRPTR , CONST_APTR , CONST struct Hook *, void *))*(void**)((long)(LOCALE_BASE_NAME) - 334))(__p0, __p1, __p2, __p3, (void*)(LOCALE_BASE_NAME)))

#define IsUnicode(__p0, __p1) \
	(((ULONG (*)(APTR , ULONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 430))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))

#define UCS4_GetLocaleStr(__p0, __p1) \
	(((CONST_WSTRPTR (*)(CONST struct Locale *, ULONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 340))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))

#define CloseLocale(__p0) \
	LP1NR(42, CloseLocale, \
		CONST struct Locale *, __p0, a0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UCS4_ConvToLower(__p0) \
	(((WCHAR (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 232))(__p0))

#define IsCntrl(__p0, __p1) \
	LP2(96, BOOL , IsCntrl, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UCS4_Normalize(__p0, __p1, __p2, __p3) \
	(((VOID (*)(CONST_WSTRPTR , WSTRPTR , LONG , ULONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 382))(__p0, __p1, __p2, __p3, (void*)(LOCALE_BASE_NAME)))

#define TZAlloc(__p0) \
	(((APTR (*)(CONST_STRPTR , void *))*(void**)((long)(LOCALE_BASE_NAME) - 490))(__p0, (void*)(LOCALE_BASE_NAME)))

#define ParseDate(__p0, __p1, __p2, __p3) \
	LP4(162, BOOL , ParseDate, \
		CONST struct Locale *, __p0, a0, \
		CONST struct DateStamp *, __p1, a1, \
		CONST_STRPTR , __p2, a2, \
		CONST struct Hook *, __p3, a3, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UTF8_CheckEncoding(__p0, __p1) \
	(((LONG (*)(CONST_STRPTR , LONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 424))(__p0, __p1, (void*)(LOCALE_BASE_NAME)))

#if !defined(__STRICT_ANSI__)
#define SNPrintf(__p0, __p1, __p2, ...) \
	(((ssize_t (*)(CONST struct Locale *, STRPTR , ssize_t , CONST_STRPTR , ...))*(void**)((long)(LOCALE_BASE_NAME) - 472))(__p0, __p1, __p2, __VA_ARGS__))
#endif

#define IsAlNum(__p0, __p1) \
	LP2(84, BOOL , IsAlNum, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ConvertUTF8ToUCS4(__p0, __p1, __p2) \
	(((ULONG (*)(CONST_STRPTR , WSTRPTR , LONG ))*(void**)((long)(LOCALE_BASE_NAME) - 388))(__p0, __p1, __p2))

#define StrConvert(__p0, __p1, __p2, __p3, __p4) \
	LP5(174, ULONG , StrConvert, \
		CONST struct Locale *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		APTR , __p2, a2, \
		ULONG , __p3, d0, \
		ULONG , __p4, d1, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UCS4_StrnCmp(__p0, __p1, __p2, __p3, __p4) \
	(((LONG (*)(CONST struct Locale *, CONST_WSTRPTR , CONST_WSTRPTR , LONG , ULONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 346))(__p0, __p1, __p2, __p3, __p4, (void*)(LOCALE_BASE_NAME)))

#define UCS4_StrToLower(__p0, __p1, __p2, __p3, __p4) \
	(((LONG (*)(CONST struct Locale *, CONST_WSTRPTR , WSTRPTR , ULONG , ULONG , void *))*(void**)((long)(LOCALE_BASE_NAME) - 352))(__p0, __p1, __p2, __p3, __p4, (void*)(LOCALE_BASE_NAME)))

#define UCS4_IsPrint(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 298))(__p0))

#define IsLower(__p0, __p1) \
	LP2(114, BOOL , IsLower, \
		CONST struct Locale *, __p0, a0, \
		ULONG , __p1, d0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenLocale(__p0) \
	LP1(156, struct Locale *, OpenLocale, \
		CONST_STRPTR , __p0, a0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UTF8_Encode(__p0, __p1) \
	(((ULONG (*)(WCHAR , STRPTR ))*(void**)((long)(LOCALE_BASE_NAME) - 250))(__p0, __p1))

#define UCS4_FormatDate(__p0, __p1, __p2, __p3) \
	(((VOID (*)(CONST struct Locale *, CONST_WSTRPTR , CONST struct DateStamp *, CONST struct Hook *, void *))*(void**)((long)(LOCALE_BASE_NAME) - 328))(__p0, __p1, __p2, __p3, (void*)(LOCALE_BASE_NAME)))

#define CloseCatalog(__p0) \
	LP1NR(36, CloseCatalog, \
		CONST struct Catalog *, __p0, a0, \
		, LOCALE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UCS4_GetCatalogStr(__p0, __p1, __p2) \
	(((CONST_WSTRPTR (*)(CONST struct Catalog *, ULONG , CONST_WSTRPTR , void *))*(void**)((long)(LOCALE_BASE_NAME) - 256))(__p0, __p1, __p2, (void*)(LOCALE_BASE_NAME)))

#define UCS4_IsAlpha(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 268))(__p0))

#define UCS4_IsDigit(__p0) \
	(((BOOL (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 280))(__p0))

#define UTF8_EncodingLength(__p0) \
	(((ULONG (*)(WCHAR ))*(void**)((long)(LOCALE_BASE_NAME) - 436))(__p0))


#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define OpenCatalog(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	OpenCatalogA(__p0, __p1, (CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_LOCALE_H */
