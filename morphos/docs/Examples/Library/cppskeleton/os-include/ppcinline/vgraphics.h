/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_VGRAPHICS_H
#define _PPCINLINE_VGRAPHICS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef VGRAPHICS_BASE_NAME
#define VGRAPHICS_BASE_NAME VGraphicsBase
#endif /* !VGRAPHICS_BASE_NAME */

#if !defined(__STRICT_ANSI__)
#define VG_Query(__p0, ...) \
	(((BOOL (*)(VGObject , ULONG , ...))*(void**)((long)(VGRAPHICS_BASE_NAME) - 46))(__p0, __VA_ARGS__))
#endif

#define VG_Dispose(__p0) \
	(((BOOL (*)(VGObject ))*(void**)((long)(VGRAPHICS_BASE_NAME) - 52))(__p0))

#if !defined(__STRICT_ANSI__)
#define VG_InjectVertices(__p0, ...) \
	(((BOOL (*)(VertObject , ULONG , ...))*(void**)((long)(VGRAPHICS_BASE_NAME) - 40))(__p0, __VA_ARGS__))
#endif

#if !defined(__STRICT_ANSI__)
#define VG_Render(__p0, __p1, ...) \
	(((BOOL (*)(struct RastPort *, VGObject , ULONG , ...))*(void**)((long)(VGRAPHICS_BASE_NAME) - 34))(__p0, __p1, __VA_ARGS__))
#endif

#if !defined(__STRICT_ANSI__)
#define VG_ImportSVG(__p0, ...) \
	(((VGObject (*)(char *, ULONG , ...))*(void**)((long)(VGRAPHICS_BASE_NAME) - 28))(__p0, __VA_ARGS__))
#endif

#endif /* !_PPCINLINE_VGRAPHICS_H */
