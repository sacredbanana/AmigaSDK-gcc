/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_POWERSDL_TTF_H
#define _PPCINLINE_POWERSDL_TTF_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef POWERSDL_TTF_BASE_NAME
#define POWERSDL_TTF_BASE_NAME PowerSDLTTFBase
#endif /* !POWERSDL_TTF_BASE_NAME */

#define TTF_OpenFont(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Font *(*)(const char *, int ))*(void**)(__base - 46))(__t__p0, __t__p1));\
	})

#define TTF_GetFontOutline(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 244))(__t__p0));\
	})

#define TTF_SetFontStyle(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *, int ))*(void**)(__base - 76))(__t__p0, __t__p1));\
	})

#define TTF_RenderUNICODE_Solid(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const Uint16 * __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const Uint16 *, SDL_Color ))*(void**)(__base - 166))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_GetFontKerning(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 268))(__t__p0));\
	})

#define TTF_GlyphIsProvided(__p0, __p1) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *, Uint16 ))*(void**)(__base - 280))(__t__p0, __t__p1));\
	})

#define TTF_FontLineSkip(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 100))(__t__p0));\
	})

#define TTF_RenderText_Blended(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, SDL_Color ))*(void**)(__base - 202))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_FontAscent(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 88))(__t__p0));\
	})

#define TTF_RenderUTF8_Solid(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, SDL_Color ))*(void**)(__base - 160))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_OpenFontIndex(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Font *(*)(const char *, int , long ))*(void**)(__base - 52))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_Linked_Version() \
	({ \
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_version *(*)(void))*(void**)(__base - 28))());\
	})

#define TTF_Init() \
	({ \
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 40))());\
	})

#define TTF_SetFontHinting(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *, int ))*(void**)(__base - 262))(__t__p0, __t__p1));\
	})

#define TTF_RenderGlyph_Blended(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, Uint16 , SDL_Color ))*(void**)(__base - 220))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_FontFaceIsFixedWidth(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 112))(__t__p0));\
	})

#define TTF_GetFontKerningSize(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TTF_Font *, int , int ))*(void**)(__base - 286))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_RenderUNICODE_Shaded(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const Uint16 * __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const Uint16 *, SDL_Color , SDL_Color ))*(void**)(__base - 190))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TTF_RenderUNICODE_Blended(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const Uint16 * __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const Uint16 *, SDL_Color ))*(void**)(__base - 214))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_FontFaceFamilyName(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const TTF_Font *))*(void**)(__base - 118))(__t__p0));\
	})

#define TTF_FontFaces(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((long (*)(const TTF_Font *))*(void**)(__base - 106))(__t__p0));\
	})

#define TTF_SizeUNICODE(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const Uint16 * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TTF_Font *, const Uint16 *, int *, int *))*(void**)(__base - 148))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TTF_RenderGlyph_Solid(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, Uint16 , SDL_Color ))*(void**)(__base - 172))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_FontHeight(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 82))(__t__p0));\
	})

#define TTF_RenderUTF8_Shaded(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, SDL_Color , SDL_Color ))*(void**)(__base - 184))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TTF_RenderUTF8_Blended(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, SDL_Color ))*(void**)(__base - 208))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_Quit() \
	({ \
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 232))());\
	})

#define TTF_SetFontOutline(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *, int ))*(void**)(__base - 250))(__t__p0, __t__p1));\
	})

#define TTF_WasInit() \
	({ \
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 238))());\
	})

#define TTF_FontDescent(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 94))(__t__p0));\
	})

#define TTF_GetFontHinting(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 256))(__t__p0));\
	})

#define TTF_ByteSwappedUNICODE(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 34))(__t__p0));\
	})

#define TTF_RenderText_Shaded(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, SDL_Color , SDL_Color ))*(void**)(__base - 178))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TTF_OpenFontRW(__p0, __p1, __p2) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Font *(*)(SDL_RWops *, int , int ))*(void**)(__base - 58))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_SetFontKerning(__p0, __p1) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *, int ))*(void**)(__base - 274))(__t__p0, __t__p1));\
	})

#define TTF_OpenFontIndexRW(__p0, __p1, __p2, __p3) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long  __t__p3 = __p3;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TTF_Font *(*)(SDL_RWops *, int , int , long ))*(void**)(__base - 64))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TTF_SizeText(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TTF_Font *, const char *, int *, int *))*(void**)(__base - 136))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TTF_GetFontStyle(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const TTF_Font *))*(void**)(__base - 70))(__t__p0));\
	})

#define TTF_FontFaceStyleName(__p0) \
	({ \
		const TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const TTF_Font *))*(void**)(__base - 124))(__t__p0));\
	})

#define TTF_CloseFont(__p0) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TTF_Font *))*(void**)(__base - 226))(__t__p0));\
	})

#define TTF_RenderText_Solid(__p0, __p1, __p2) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, const char *, SDL_Color ))*(void**)(__base - 154))(__t__p0, __t__p1, __t__p2));\
	})

#define TTF_RenderGlyph_Shaded(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		SDL_Color  __t__p2 = __p2;\
		SDL_Color  __t__p3 = __p3;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(TTF_Font *, Uint16 , SDL_Color , SDL_Color ))*(void**)(__base - 196))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TTF_GlyphMetrics(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		int * __t__p5 = __p5;\
		int * __t__p6 = __p6;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TTF_Font *, Uint16 , int *, int *, int *, int *, int *))*(void**)(__base - 130))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define TTF_SizeUTF8(__p0, __p1, __p2, __p3) \
	({ \
		TTF_Font * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(POWERSDL_TTF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TTF_Font *, const char *, int *, int *))*(void**)(__base - 142))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#endif /* !_PPCINLINE_POWERSDL_TTF_H */
