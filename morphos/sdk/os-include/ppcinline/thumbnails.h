/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_THUMBNAILS_H
#define _PPCINLINE_THUMBNAILS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef THUMBNAILS_BASE_NAME
#define THUMBNAILS_BASE_NAME ThumbnailsBase
#endif /* !THUMBNAILS_BASE_NAME */

#define ThbDeleteThumbnail(__p0) \
	(((VOID (*)(APTR ))*(void**)((long)(THUMBNAILS_BASE_NAME) - 34))(__p0))

#define ThbGetAttrsA(__p0, __p1) \
	(((ULONG (*)(APTR , struct TagItem *))*(void**)((long)(THUMBNAILS_BASE_NAME) - 40))(__p0, __p1))

#define ThbGenerateThumbnailA(__p0, __p1) \
	(((APTR (*)(CONST_STRPTR , struct TagItem *))*(void**)((long)(THUMBNAILS_BASE_NAME) - 28))(__p0, __p1))

#define ThbNextFrame(__p0) \
	(((ULONG (*)(APTR ))*(void**)((long)(THUMBNAILS_BASE_NAME) - 46))(__p0))

#endif /* !_PPCINLINE_THUMBNAILS_H */
