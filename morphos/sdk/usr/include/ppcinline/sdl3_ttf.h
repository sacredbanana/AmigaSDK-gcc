/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SDL3_TTF_H
#define _PPCINLINE_SDL3_TTF_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SDL3_TTF_BASE_NAME
#define SDL3_TTF_BASE_NAME SDL3TTFBase
#endif /* !SDL3_TTF_BASE_NAME */

#ifndef TTF_Version
#define TTF_Version() \
	({ \
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 52))());\
	})
#endif

#ifndef TTF_GetFreeTypeVersion
#define TTF_GetFreeTypeVersion(__p0, __p1, __p2) \
	({ \
		int * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int *, int *, int *))*(void**)(__base - 58))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_GetHarfBuzzVersion
#define TTF_GetHarfBuzzVersion(__p0, __p1, __p2) \
	({ \
		int * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int *, int *, int *))*(void**)(__base - 64))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_Init
#define TTF_Init() \
	({ \
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(void))*(void**)(__base - 70))());\
	})
#endif

#ifndef TTF_OpenFont
#define TTF_OpenFont(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Font *(*)(const char *, float ))*(void**)(__base - 76))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_OpenFontIO
#define TTF_OpenFontIO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Font *(*)(SDL_IOStream *, bool , float ))*(void**)(__base - 82))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_OpenFontWithProperties
#define TTF_OpenFontWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Font *(*)(SDL_PropertiesID ))*(void**)(__base - 88))(__t__p0));\
	})
#endif

#ifndef TTF_CopyFont
#define TTF_CopyFont(__p0) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Font *(*)(TTF_Font *))*(void**)(__base - 94))(__t__p0));\
	})
#endif

#ifndef TTF_GetFontProperties
#define TTF_GetFontProperties(__p0) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(TTF_Font *))*(void**)(__base - 100))(__t__p0));\
	})
#endif

#ifndef TTF_GetFontGeneration
#define TTF_GetFontGeneration(__p0) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(TTF_Font *))*(void**)(__base - 106))(__t__p0));\
	})
#endif

#ifndef TTF_AddFallbackFont
#define TTF_AddFallbackFont(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		TTF_Font * __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, TTF_Font *))*(void**)(__base - 112))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_RemoveFallbackFont
#define TTF_RemoveFallbackFont(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		TTF_Font * __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *, TTF_Font *))*(void**)(__base - 118))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_ClearFallbackFonts
#define TTF_ClearFallbackFonts(__p0) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *))*(void**)(__base - 124))(__t__p0));\
	})
#endif

#ifndef TTF_SetFontSize
#define TTF_SetFontSize(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, float ))*(void**)(__base - 130))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_SetFontSizeDPI
#define TTF_SetFontSizeDPI(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, float , int , int ))*(void**)(__base - 136))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_GetFontSize
#define TTF_GetFontSize(__p0) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((float (*)(TTF_Font *))*(void**)(__base - 142))(__t__p0));\
	})
#endif

#ifndef TTF_GetFontDPI
#define TTF_GetFontDPI(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, int *, int *))*(void**)(__base - 148))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_SetFontStyle
#define TTF_SetFontStyle(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		TTF_FontStyleFlags  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *, TTF_FontStyleFlags ))*(void**)(__base - 154))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetFontStyle
#define TTF_GetFontStyle(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_FontStyleFlags (*)(const TTF_Font *))*(void**)(__base - 160))(__t__p0));\
	})
#endif

#ifndef TTF_SetFontOutline
#define TTF_SetFontOutline(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, int ))*(void**)(__base - 166))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetFontOutline
#define TTF_GetFontOutline(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 172))(__t__p0));\
	})
#endif

#ifndef TTF_SetFontHinting
#define TTF_SetFontHinting(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		TTF_HintingFlags  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *, TTF_HintingFlags ))*(void**)(__base - 178))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetNumFontFaces
#define TTF_GetNumFontFaces(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 184))(__t__p0));\
	})
#endif

#ifndef TTF_GetFontHinting
#define TTF_GetFontHinting(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_HintingFlags (*)(const TTF_Font *))*(void**)(__base - 190))(__t__p0));\
	})
#endif

#ifndef TTF_SetFontSDF
#define TTF_SetFontSDF(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, bool ))*(void**)(__base - 196))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetFontSDF
#define TTF_GetFontSDF(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const TTF_Font *))*(void**)(__base - 202))(__t__p0));\
	})
#endif

#ifndef TTF_GetFontWeight
#define TTF_GetFontWeight(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 208))(__t__p0));\
	})
#endif

#ifndef TTF_SetFontWrapAlignment
#define TTF_SetFontWrapAlignment(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		TTF_HorizontalAlignment  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *, TTF_HorizontalAlignment ))*(void**)(__base - 214))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetFontWrapAlignment
#define TTF_GetFontWrapAlignment(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_HorizontalAlignment (*)(const TTF_Font *))*(void**)(__base - 220))(__t__p0));\
	})
#endif

#ifndef TTF_GetFontHeight
#define TTF_GetFontHeight(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 226))(__t__p0));\
	})
#endif

#ifndef TTF_GetFontAscent
#define TTF_GetFontAscent(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 232))(__t__p0));\
	})
#endif

#ifndef TTF_GetFontDescent
#define TTF_GetFontDescent(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 238))(__t__p0));\
	})
#endif

#ifndef TTF_SetFontLineSkip
#define TTF_SetFontLineSkip(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *, int ))*(void**)(__base - 244))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetFontLineSkip
#define TTF_GetFontLineSkip(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 250))(__t__p0));\
	})
#endif

#ifndef TTF_SetFontKerning
#define TTF_SetFontKerning(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *, bool ))*(void**)(__base - 256))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetFontKerning
#define TTF_GetFontKerning(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const TTF_Font *))*(void**)(__base - 262))(__t__p0));\
	})
#endif

#ifndef TTF_FontIsFixedWidth
#define TTF_FontIsFixedWidth(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const TTF_Font *))*(void**)(__base - 268))(__t__p0));\
	})
#endif

#ifndef TTF_FontIsScalable
#define TTF_FontIsScalable(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(const TTF_Font *))*(void**)(__base - 274))(__t__p0));\
	})
#endif

#ifndef TTF_GetFontFamilyName
#define TTF_GetFontFamilyName(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const TTF_Font *))*(void**)(__base - 280))(__t__p0));\
	})
#endif

#ifndef TTF_GetFontStyleName
#define TTF_GetFontStyleName(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const TTF_Font *))*(void**)(__base - 286))(__t__p0));\
	})
#endif

#ifndef TTF_SetFontDirection
#define TTF_SetFontDirection(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		TTF_Direction  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, TTF_Direction ))*(void**)(__base - 292))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetFontDirection
#define TTF_GetFontDirection(__p0) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Direction (*)(TTF_Font *))*(void**)(__base - 298))(__t__p0));\
	})
#endif

#ifndef TTF_SetFontCharSpacing
#define TTF_SetFontCharSpacing(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, int ))*(void**)(__base - 304))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetFontCharSpacing
#define TTF_GetFontCharSpacing(__p0) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TTF_Font *))*(void**)(__base - 310))(__t__p0));\
	})
#endif

#ifndef TTF_StringToTag
#define TTF_StringToTag(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(const char *))*(void**)(__base - 316))(__t__p0));\
	})
#endif

#ifndef TTF_TagToString
#define TTF_TagToString(__p0, __p1, __p2) \
	({ \
		Uint32  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Uint32 , char *, size_t ))*(void**)(__base - 322))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_SetFontScript
#define TTF_SetFontScript(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, Uint32 ))*(void**)(__base - 328))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetFontScript
#define TTF_GetFontScript(__p0) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(TTF_Font *))*(void**)(__base - 334))(__t__p0));\
	})
#endif

#ifndef TTF_GetGlyphScript
#define TTF_GetGlyphScript(__p0) \
	({ \
		Uint32  __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(Uint32 ))*(void**)(__base - 340))(__t__p0));\
	})
#endif

#ifndef TTF_SetFontLanguage
#define TTF_SetFontLanguage(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, const char *))*(void**)(__base - 346))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_FontHasGlyph
#define TTF_FontHasGlyph(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, Uint32 ))*(void**)(__base - 352))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetGlyphImage
#define TTF_GetGlyphImage(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		TTF_ImageType * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, Uint32 , TTF_ImageType *))*(void**)(__base - 358))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_GetGlyphImageForIndex
#define TTF_GetGlyphImageForIndex(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		TTF_ImageType * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, Uint32 , TTF_ImageType *))*(void**)(__base - 364))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_GetGlyphMetrics
#define TTF_GetGlyphMetrics(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		int * __t__p5 = __p5;\
		int * __t__p6 = __p6;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, Uint32 , int *, int *, int *, int *, int *))*(void**)(__base - 370))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#ifndef TTF_GetGlyphKerning
#define TTF_GetGlyphKerning(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, Uint32 , Uint32 , int *))*(void**)(__base - 376))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_GetStringSize
#define TTF_GetStringSize(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, const char *, size_t , int *, int *))*(void**)(__base - 382))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef TTF_GetStringSizeWrapped
#define TTF_GetStringSizeWrapped(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		int * __t__p5 = __p5;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, const char *, size_t , int , int *, int *))*(void**)(__base - 388))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef TTF_MeasureString
#define TTF_MeasureString(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		size_t * __t__p5 = __p5;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Font *, const char *, size_t , int , int *, size_t *))*(void**)(__base - 394))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef TTF_RenderText_Solid
#define TTF_RenderText_Solid(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, size_t , SDL_Color ))*(void**)(__base - 400))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_RenderText_Solid_Wrapped
#define TTF_RenderText_Solid_Wrapped(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, size_t , SDL_Color , int ))*(void**)(__base - 406))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef TTF_RenderGlyph_Solid
#define TTF_RenderGlyph_Solid(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, Uint32 , SDL_Color ))*(void**)(__base - 412))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_RenderText_Shaded
#define TTF_RenderText_Shaded(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		SDL_Color  __t__p4 = __p4;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, size_t , SDL_Color , SDL_Color ))*(void**)(__base - 418))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef TTF_RenderText_Shaded_Wrapped
#define TTF_RenderText_Shaded_Wrapped(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		SDL_Color  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, size_t , SDL_Color , SDL_Color , int ))*(void**)(__base - 424))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef TTF_RenderGlyph_Shaded
#define TTF_RenderGlyph_Shaded(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, Uint32 , SDL_Color , SDL_Color ))*(void**)(__base - 430))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_RenderText_Blended
#define TTF_RenderText_Blended(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, size_t , SDL_Color ))*(void**)(__base - 436))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_RenderText_Blended_Wrapped
#define TTF_RenderText_Blended_Wrapped(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, size_t , SDL_Color , int ))*(void**)(__base - 442))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef TTF_RenderGlyph_Blended
#define TTF_RenderGlyph_Blended(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, Uint32 , SDL_Color ))*(void**)(__base - 448))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_RenderText_LCD
#define TTF_RenderText_LCD(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		SDL_Color  __t__p4 = __p4;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, size_t , SDL_Color , SDL_Color ))*(void**)(__base - 454))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef TTF_RenderText_LCD_Wrapped
#define TTF_RenderText_LCD_Wrapped(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		SDL_Color  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, size_t , SDL_Color , SDL_Color , int ))*(void**)(__base - 460))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef TTF_RenderGlyph_LCD
#define TTF_RenderGlyph_LCD(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, Uint32 , SDL_Color , SDL_Color ))*(void**)(__base - 466))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_CreateSurfaceTextEngine
#define TTF_CreateSurfaceTextEngine() \
	({ \
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_TextEngine *(*)(void))*(void**)(__base - 472))());\
	})
#endif

#ifndef TTF_DrawSurfaceText
#define TTF_DrawSurfaceText(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		SDL_Surface * __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int , int , SDL_Surface *))*(void**)(__base - 478))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_DestroySurfaceTextEngine
#define TTF_DestroySurfaceTextEngine(__p0) \
	({ \
		TTF_TextEngine * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_TextEngine *))*(void**)(__base - 484))(__t__p0));\
	})
#endif

#ifndef TTF_CreateRendererTextEngine
#define TTF_CreateRendererTextEngine(__p0) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_TextEngine *(*)(SDL_Renderer *))*(void**)(__base - 490))(__t__p0));\
	})
#endif

#ifndef TTF_CreateRendererTextEngineWithProperties
#define TTF_CreateRendererTextEngineWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_TextEngine *(*)(SDL_PropertiesID ))*(void**)(__base - 496))(__t__p0));\
	})
#endif

#ifndef TTF_DrawRendererText
#define TTF_DrawRendererText(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, float , float ))*(void**)(__base - 502))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_DestroyRendererTextEngine
#define TTF_DestroyRendererTextEngine(__p0) \
	({ \
		TTF_TextEngine * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_TextEngine *))*(void**)(__base - 508))(__t__p0));\
	})
#endif

#ifndef TTF_CreateGPUTextEngine
#define TTF_CreateGPUTextEngine(__p0) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_TextEngine *(*)(SDL_GPUDevice *))*(void**)(__base - 514))(__t__p0));\
	})
#endif

#ifndef TTF_CreateGPUTextEngineWithProperties
#define TTF_CreateGPUTextEngineWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_TextEngine *(*)(SDL_PropertiesID ))*(void**)(__base - 520))(__t__p0));\
	})
#endif

#ifndef TTF_GetGPUTextDrawData
#define TTF_GetGPUTextDrawData(__p0) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_GPUAtlasDrawSequence *(*)(TTF_Text *))*(void**)(__base - 526))(__t__p0));\
	})
#endif

#ifndef TTF_DestroyGPUTextEngine
#define TTF_DestroyGPUTextEngine(__p0) \
	({ \
		TTF_TextEngine * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_TextEngine *))*(void**)(__base - 532))(__t__p0));\
	})
#endif

#ifndef TTF_SetGPUTextEngineWinding
#define TTF_SetGPUTextEngineWinding(__p0, __p1) \
	({ \
		TTF_TextEngine * __t__p0 = __p0;\
		TTF_GPUTextEngineWinding  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_TextEngine *, TTF_GPUTextEngineWinding ))*(void**)(__base - 538))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetGPUTextEngineWinding
#define TTF_GetGPUTextEngineWinding(__p0) \
	({ \
		const TTF_TextEngine * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_GPUTextEngineWinding (*)(const TTF_TextEngine *))*(void**)(__base - 544))(__t__p0));\
	})
#endif

#ifndef TTF_CreateGLTextEngine
#define TTF_CreateGLTextEngine() \
	({ \
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_TextEngine *(*)(void))*(void**)(__base - 550))());\
	})
#endif

#ifndef TTF_CreateGLTextEngineWithProperties
#define TTF_CreateGLTextEngineWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_TextEngine *(*)(SDL_PropertiesID ))*(void**)(__base - 556))(__t__p0));\
	})
#endif

#ifndef TTF_GetGLTextDrawData
#define TTF_GetGLTextDrawData(__p0) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_GLAtlasDrawSequence *(*)(TTF_Text *))*(void**)(__base - 562))(__t__p0));\
	})
#endif

#ifndef TTF_DestroyGLTextEngine
#define TTF_DestroyGLTextEngine(__p0) \
	({ \
		TTF_TextEngine * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_TextEngine *))*(void**)(__base - 568))(__t__p0));\
	})
#endif

#ifndef TTF_SetGLTextEngineWinding
#define TTF_SetGLTextEngineWinding(__p0, __p1) \
	({ \
		TTF_TextEngine * __t__p0 = __p0;\
		TTF_GLTextEngineWinding  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_TextEngine *, TTF_GLTextEngineWinding ))*(void**)(__base - 574))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetGLTextEngineWinding
#define TTF_GetGLTextEngineWinding(__p0) \
	({ \
		const TTF_TextEngine * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_GLTextEngineWinding (*)(const TTF_TextEngine *))*(void**)(__base - 580))(__t__p0));\
	})
#endif

#ifndef TTF_CreateText
#define TTF_CreateText(__p0, __p1, __p2, __p3) \
	({ \
		TTF_TextEngine * __t__p0 = __p0;\
		TTF_Font * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		size_t  __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Text *(*)(TTF_TextEngine *, TTF_Font *, const char *, size_t ))*(void**)(__base - 586))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_GetTextProperties
#define TTF_GetTextProperties(__p0) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(TTF_Text *))*(void**)(__base - 592))(__t__p0));\
	})
#endif

#ifndef TTF_SetTextEngine
#define TTF_SetTextEngine(__p0, __p1) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		TTF_TextEngine * __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, TTF_TextEngine *))*(void**)(__base - 598))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetTextEngine
#define TTF_GetTextEngine(__p0) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_TextEngine *(*)(TTF_Text *))*(void**)(__base - 604))(__t__p0));\
	})
#endif

#ifndef TTF_SetTextFont
#define TTF_SetTextFont(__p0, __p1) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		TTF_Font * __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, TTF_Font *))*(void**)(__base - 610))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetTextFont
#define TTF_GetTextFont(__p0) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Font *(*)(TTF_Text *))*(void**)(__base - 616))(__t__p0));\
	})
#endif

#ifndef TTF_SetTextDirection
#define TTF_SetTextDirection(__p0, __p1) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		TTF_Direction  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, TTF_Direction ))*(void**)(__base - 622))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetTextDirection
#define TTF_GetTextDirection(__p0) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Direction (*)(TTF_Text *))*(void**)(__base - 628))(__t__p0));\
	})
#endif

#ifndef TTF_SetTextScript
#define TTF_SetTextScript(__p0, __p1) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, Uint32 ))*(void**)(__base - 634))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetTextScript
#define TTF_GetTextScript(__p0) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(TTF_Text *))*(void**)(__base - 640))(__t__p0));\
	})
#endif

#ifndef TTF_SetTextColor
#define TTF_SetTextColor(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		Uint8  __t__p3 = __p3;\
		Uint8  __t__p4 = __p4;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, Uint8 , Uint8 , Uint8 , Uint8 ))*(void**)(__base - 646))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef TTF_SetTextColorFloat
#define TTF_SetTextColorFloat(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		float  __t__p4 = __p4;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, float , float , float , float ))*(void**)(__base - 652))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef TTF_GetTextColor
#define TTF_GetTextColor(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		Uint8 * __t__p1 = __p1;\
		Uint8 * __t__p2 = __p2;\
		Uint8 * __t__p3 = __p3;\
		Uint8 * __t__p4 = __p4;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, Uint8 *, Uint8 *, Uint8 *, Uint8 *))*(void**)(__base - 658))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef TTF_GetTextColorFloat
#define TTF_GetTextColorFloat(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		float * __t__p2 = __p2;\
		float * __t__p3 = __p3;\
		float * __t__p4 = __p4;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, float *, float *, float *, float *))*(void**)(__base - 664))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef TTF_SetTextPosition
#define TTF_SetTextPosition(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int , int ))*(void**)(__base - 670))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_GetTextPosition
#define TTF_GetTextPosition(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int *, int *))*(void**)(__base - 676))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_SetTextWrapWidth
#define TTF_SetTextWrapWidth(__p0, __p1) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int ))*(void**)(__base - 682))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_GetTextWrapWidth
#define TTF_GetTextWrapWidth(__p0, __p1) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int *))*(void**)(__base - 688))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_SetTextWrapWhitespaceVisible
#define TTF_SetTextWrapWhitespaceVisible(__p0, __p1) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, bool ))*(void**)(__base - 694))(__t__p0, __t__p1));\
	})
#endif

#ifndef TTF_TextWrapWhitespaceVisible
#define TTF_TextWrapWhitespaceVisible(__p0) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *))*(void**)(__base - 700))(__t__p0));\
	})
#endif

#ifndef TTF_SetTextString
#define TTF_SetTextString(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, const char *, size_t ))*(void**)(__base - 706))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_InsertTextString
#define TTF_InsertTextString(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		size_t  __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int , const char *, size_t ))*(void**)(__base - 712))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_AppendTextString
#define TTF_AppendTextString(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		size_t  __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, const char *, size_t ))*(void**)(__base - 718))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_DeleteTextString
#define TTF_DeleteTextString(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int , int ))*(void**)(__base - 724))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_GetTextSize
#define TTF_GetTextSize(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int *, int *))*(void**)(__base - 730))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_GetTextSubString
#define TTF_GetTextSubString(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		TTF_SubString * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int , TTF_SubString *))*(void**)(__base - 736))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_GetTextSubStringForLine
#define TTF_GetTextSubStringForLine(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		TTF_SubString * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int , TTF_SubString *))*(void**)(__base - 742))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_GetTextSubStringsForRange
#define TTF_GetTextSubStringsForRange(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_SubString **(*)(TTF_Text *, int , int , int *))*(void**)(__base - 748))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_GetTextSubStringForPoint
#define TTF_GetTextSubStringForPoint(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		TTF_SubString * __t__p3 = __p3;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, int , int , TTF_SubString *))*(void**)(__base - 754))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef TTF_GetPreviousTextSubString
#define TTF_GetPreviousTextSubString(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		const TTF_SubString * __t__p1 = __p1;\
		TTF_SubString * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, const TTF_SubString *, TTF_SubString *))*(void**)(__base - 760))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_GetNextTextSubString
#define TTF_GetNextTextSubString(__p0, __p1, __p2) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		const TTF_SubString * __t__p1 = __p1;\
		TTF_SubString * __t__p2 = __p2;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *, const TTF_SubString *, TTF_SubString *))*(void**)(__base - 766))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef TTF_UpdateText
#define TTF_UpdateText(__p0) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(TTF_Text *))*(void**)(__base - 772))(__t__p0));\
	})
#endif

#ifndef TTF_DestroyText
#define TTF_DestroyText(__p0) \
	({ \
		TTF_Text * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Text *))*(void**)(__base - 778))(__t__p0));\
	})
#endif

#ifndef TTF_CloseFont
#define TTF_CloseFont(__p0) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *))*(void**)(__base - 784))(__t__p0));\
	})
#endif

#ifndef TTF_Quit
#define TTF_Quit() \
	({ \
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 790))());\
	})
#endif

#ifndef TTF_WasInit
#define TTF_WasInit() \
	({ \
		long __base = (long)(SDL3_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 796))());\
	})
#endif

#endif /* !_PPCINLINE_SDL3_TTF_H */
