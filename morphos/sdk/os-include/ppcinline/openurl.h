/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_OPENURL_H
#define _PPCINLINE_OPENURL_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef OPENURL_BASE_NAME
#define OPENURL_BASE_NAME OpenURLBase
#endif /* !OPENURL_BASE_NAME */

#define URL_OpenA(url, tags) \
	LP2(0x1e, BOOL, URL_OpenA, STRPTR, url, a0, struct TagItem *, tags, a1, \
	, OPENURL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define URL_GetPrefsA(tags) \
	LP1(0x48, struct URL_Prefs *, URL_GetPrefsA, struct TagItem *, tags, a0, \
	, OPENURL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define URL_FreePrefsA(prefs, tags) \
	LP2NR(0x4e, URL_FreePrefsA, struct URL_Prefs *, prefs, a0, struct TagItem *, tags, a1, \
	, OPENURL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define URL_SetPrefsA(up, tags) \
	LP2(0x54, BOOL, URL_SetPrefsA, struct URL_Prefs *, up, a0, struct TagItem *, tags, a1, \
	, OPENURL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define URL_LaunchPrefsAppA(tags) \
	LP1(0x5a, BOOL, URL_LaunchPrefsAppA, struct TagItem *, tags, a0, \
	, OPENURL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define URL_GetAttr(attr, storage) \
	LP2(0x60, ULONG, URL_GetAttr, ULONG, attr, d0, ULONG *, storage, a0, \
	, OPENURL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#ifdef USE_INLINE_STDARG

#include <stdarg.h>

#define URL_Open(__p0, ...) \
	({ULONG _tags[] = {__VA_ARGS__}; URL_OpenA(__p0, (struct TagItem *) _tags);})

#define URL_GetPrefs(...) \
	({ULONG _tags[] = {__VA_ARGS__}; URL_GetPrefsA((struct TagItem *) _tags);})

#define URL_FreePrefs(__p0, ...) \
	({ULONG _tags[] = {__VA_ARGS__}; URL_FreePrefsA(__p0, (struct TagItem *) _tags);})

#define URL_SetPrefs(__p0, ...) \
	({ULONG _tags[] = {__VA_ARGS__}; URL_SetPrefsA(__p0, (struct TagItem *) _tags);})

#define URL_LaunchPrefsApp(...) \
	({ULONG _tags[] = {__VA_ARGS__}; URL_LaunchPrefsAppA((struct TagItem *) _tags);})

#endif

#endif /*  _PPCINLINE_OPENURL_H  */
