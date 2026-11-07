/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SDL3_IMAGE_H
#define _PPCINLINE_SDL3_IMAGE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SDL3_IMAGE_BASE_NAME
#define SDL3_IMAGE_BASE_NAME SDL3ImageBase
#endif /* !SDL3_IMAGE_BASE_NAME */

#ifndef IMG_FreeAnimation
#define IMG_FreeAnimation(__p0) \
	({ \
		IMG_Animation * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(IMG_Animation *))*(void**)(__base - 52))(__t__p0));\
	})
#endif

#ifndef IMG_Version
#define IMG_Version() \
	({ \
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 58))());\
	})
#endif

#ifndef IMG_Load
#define IMG_Load(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(const char *))*(void**)(__base - 64))(__t__p0));\
	})
#endif

#ifndef IMG_LoadAVIF_IO
#define IMG_LoadAVIF_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 70))(__t__p0));\
	})
#endif

#ifndef IMG_LoadAnimation
#define IMG_LoadAnimation(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_Animation *(*)(const char *))*(void**)(__base - 76))(__t__p0));\
	})
#endif

#ifndef IMG_LoadAnimationTyped_IO
#define IMG_LoadAnimationTyped_IO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_Animation *(*)(SDL_IOStream *, bool , const char *))*(void**)(__base - 82))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_LoadAnimation_IO
#define IMG_LoadAnimation_IO(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_Animation *(*)(SDL_IOStream *, bool ))*(void**)(__base - 88))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_LoadBMP_IO
#define IMG_LoadBMP_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 94))(__t__p0));\
	})
#endif

#ifndef IMG_LoadCUR_IO
#define IMG_LoadCUR_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 100))(__t__p0));\
	})
#endif

#ifndef IMG_LoadGIFAnimation_IO
#define IMG_LoadGIFAnimation_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_Animation *(*)(SDL_IOStream *))*(void**)(__base - 106))(__t__p0));\
	})
#endif

#ifndef IMG_LoadGIF_IO
#define IMG_LoadGIF_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 112))(__t__p0));\
	})
#endif

#ifndef IMG_LoadICO_IO
#define IMG_LoadICO_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 118))(__t__p0));\
	})
#endif

#ifndef IMG_LoadJPG_IO
#define IMG_LoadJPG_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 124))(__t__p0));\
	})
#endif

#ifndef IMG_LoadJXL_IO
#define IMG_LoadJXL_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 130))(__t__p0));\
	})
#endif

#ifndef IMG_LoadLBM_IO
#define IMG_LoadLBM_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 136))(__t__p0));\
	})
#endif

#ifndef IMG_LoadPCX_IO
#define IMG_LoadPCX_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 142))(__t__p0));\
	})
#endif

#ifndef IMG_LoadPNG_IO
#define IMG_LoadPNG_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 148))(__t__p0));\
	})
#endif

#ifndef IMG_LoadPNM_IO
#define IMG_LoadPNM_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 154))(__t__p0));\
	})
#endif

#ifndef IMG_LoadQOI_IO
#define IMG_LoadQOI_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 160))(__t__p0));\
	})
#endif

#ifndef IMG_LoadSVG_IO
#define IMG_LoadSVG_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 166))(__t__p0));\
	})
#endif

#ifndef IMG_LoadSizedSVG_IO
#define IMG_LoadSizedSVG_IO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *, int , int ))*(void**)(__base - 172))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_LoadTGA_IO
#define IMG_LoadTGA_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 178))(__t__p0));\
	})
#endif

#ifndef IMG_LoadTIF_IO
#define IMG_LoadTIF_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 184))(__t__p0));\
	})
#endif

#ifndef IMG_LoadTexture
#define IMG_LoadTexture(__p0, __p1) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Texture *(*)(SDL_Renderer *, const char *))*(void**)(__base - 190))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_LoadTextureTyped_IO
#define IMG_LoadTextureTyped_IO(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Texture *(*)(SDL_Renderer *, SDL_IOStream *, bool , const char *))*(void**)(__base - 196))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef IMG_LoadTexture_IO
#define IMG_LoadTexture_IO(__p0, __p1, __p2) \
	({ \
		SDL_Renderer * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Texture *(*)(SDL_Renderer *, SDL_IOStream *, bool ))*(void**)(__base - 202))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_LoadTyped_IO
#define IMG_LoadTyped_IO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *, bool , const char *))*(void**)(__base - 208))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_LoadWEBPAnimation_IO
#define IMG_LoadWEBPAnimation_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_Animation *(*)(SDL_IOStream *))*(void**)(__base - 214))(__t__p0));\
	})
#endif

#ifndef IMG_LoadWEBP_IO
#define IMG_LoadWEBP_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 220))(__t__p0));\
	})
#endif

#ifndef IMG_LoadXCF_IO
#define IMG_LoadXCF_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 226))(__t__p0));\
	})
#endif

#ifndef IMG_LoadXPM_IO
#define IMG_LoadXPM_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 232))(__t__p0));\
	})
#endif

#ifndef IMG_LoadXV_IO
#define IMG_LoadXV_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *))*(void**)(__base - 238))(__t__p0));\
	})
#endif

#ifndef IMG_Load_IO
#define IMG_Load_IO(__p0, __p1) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_IOStream *, bool ))*(void**)(__base - 244))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_ReadXPMFromArray
#define IMG_ReadXPMFromArray(__p0) \
	({ \
		char ** __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(char **))*(void**)(__base - 250))(__t__p0));\
	})
#endif

#ifndef IMG_ReadXPMFromArrayToRGB888
#define IMG_ReadXPMFromArrayToRGB888(__p0) \
	({ \
		char ** __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(char **))*(void**)(__base - 256))(__t__p0));\
	})
#endif

#ifndef IMG_SaveJPG
#define IMG_SaveJPG(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *, int ))*(void**)(__base - 262))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveJPG_IO
#define IMG_SaveJPG_IO(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool , int ))*(void**)(__base - 268))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef IMG_SavePNG
#define IMG_SavePNG(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *))*(void**)(__base - 274))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_SavePNG_IO
#define IMG_SavePNG_IO(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool ))*(void**)(__base - 280))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveAVIF
#define IMG_SaveAVIF(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *, int ))*(void**)(__base - 286))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveAVIF_IO
#define IMG_SaveAVIF_IO(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool , int ))*(void**)(__base - 292))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef IMG_isAVIF
#define IMG_isAVIF(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 298))(__t__p0));\
	})
#endif

#ifndef IMG_isBMP
#define IMG_isBMP(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 304))(__t__p0));\
	})
#endif

#ifndef IMG_isCUR
#define IMG_isCUR(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 310))(__t__p0));\
	})
#endif

#ifndef IMG_isGIF
#define IMG_isGIF(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 316))(__t__p0));\
	})
#endif

#ifndef IMG_isICO
#define IMG_isICO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 322))(__t__p0));\
	})
#endif

#ifndef IMG_isJPG
#define IMG_isJPG(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 328))(__t__p0));\
	})
#endif

#ifndef IMG_isJXL
#define IMG_isJXL(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 334))(__t__p0));\
	})
#endif

#ifndef IMG_isLBM
#define IMG_isLBM(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 340))(__t__p0));\
	})
#endif

#ifndef IMG_isPCX
#define IMG_isPCX(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 346))(__t__p0));\
	})
#endif

#ifndef IMG_isPNG
#define IMG_isPNG(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 352))(__t__p0));\
	})
#endif

#ifndef IMG_isPNM
#define IMG_isPNM(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 358))(__t__p0));\
	})
#endif

#ifndef IMG_isQOI
#define IMG_isQOI(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 364))(__t__p0));\
	})
#endif

#ifndef IMG_isSVG
#define IMG_isSVG(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 370))(__t__p0));\
	})
#endif

#ifndef IMG_isTIF
#define IMG_isTIF(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 376))(__t__p0));\
	})
#endif

#ifndef IMG_isWEBP
#define IMG_isWEBP(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 382))(__t__p0));\
	})
#endif

#ifndef IMG_isXCF
#define IMG_isXCF(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 388))(__t__p0));\
	})
#endif

#ifndef IMG_isXPM
#define IMG_isXPM(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 394))(__t__p0));\
	})
#endif

#ifndef IMG_isXV
#define IMG_isXV(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 400))(__t__p0));\
	})
#endif

#ifndef IMG_isANI
#define IMG_isANI(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_IOStream *))*(void**)(__base - 406))(__t__p0));\
	})
#endif

#ifndef IMG_SaveTGA
#define IMG_SaveTGA(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *))*(void**)(__base - 412))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_SaveTGA_IO
#define IMG_SaveTGA_IO(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool ))*(void**)(__base - 418))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveGIF
#define IMG_SaveGIF(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *))*(void**)(__base - 424))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_SaveGIF_IO
#define IMG_SaveGIF_IO(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool ))*(void**)(__base - 430))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveWEBP
#define IMG_SaveWEBP(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *, float ))*(void**)(__base - 436))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveWEBP_IO
#define IMG_SaveWEBP_IO(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool , float ))*(void**)(__base - 442))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef IMG_SaveBMP
#define IMG_SaveBMP(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *))*(void**)(__base - 448))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_SaveBMP_IO
#define IMG_SaveBMP_IO(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool ))*(void**)(__base - 454))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_Save
#define IMG_Save(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *))*(void**)(__base - 460))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_SaveTyped_IO
#define IMG_SaveTyped_IO(__p0, __p1, __p2, __p3) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool , const char *))*(void**)(__base - 466))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef IMG_CreateAnimationEncoder
#define IMG_CreateAnimationEncoder(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_AnimationEncoder *(*)(const char *))*(void**)(__base - 472))(__t__p0));\
	})
#endif

#ifndef IMG_CreateAnimationEncoder_IO
#define IMG_CreateAnimationEncoder_IO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_AnimationEncoder *(*)(SDL_IOStream *, bool , const char *))*(void**)(__base - 478))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_CreateAnimationEncoderWithProperties
#define IMG_CreateAnimationEncoderWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_AnimationEncoder *(*)(SDL_PropertiesID ))*(void**)(__base - 484))(__t__p0));\
	})
#endif

#ifndef IMG_AddAnimationEncoderFrame
#define IMG_AddAnimationEncoderFrame(__p0, __p1, __p2) \
	({ \
		IMG_AnimationEncoder * __t__p0 = __p0;\
		SDL_Surface * __t__p1 = __p1;\
		Uint64  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_AnimationEncoder *, SDL_Surface *, Uint64 ))*(void**)(__base - 490))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_CloseAnimationEncoder
#define IMG_CloseAnimationEncoder(__p0) \
	({ \
		IMG_AnimationEncoder * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_AnimationEncoder *))*(void**)(__base - 496))(__t__p0));\
	})
#endif

#ifndef IMG_LoadANIAnimation_IO
#define IMG_LoadANIAnimation_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_Animation *(*)(SDL_IOStream *))*(void**)(__base - 502))(__t__p0));\
	})
#endif

#ifndef IMG_LoadAPNGAnimation_IO
#define IMG_LoadAPNGAnimation_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_Animation *(*)(SDL_IOStream *))*(void**)(__base - 508))(__t__p0));\
	})
#endif

#ifndef IMG_LoadAVIFAnimation_IO
#define IMG_LoadAVIFAnimation_IO(__p0) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_Animation *(*)(SDL_IOStream *))*(void**)(__base - 514))(__t__p0));\
	})
#endif

#ifndef IMG_CreateAnimationDecoder
#define IMG_CreateAnimationDecoder(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_AnimationDecoder *(*)(const char *))*(void**)(__base - 520))(__t__p0));\
	})
#endif

#ifndef IMG_CreateAnimationDecoder_IO
#define IMG_CreateAnimationDecoder_IO(__p0, __p1, __p2) \
	({ \
		SDL_IOStream * __t__p0 = __p0;\
		bool  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_AnimationDecoder *(*)(SDL_IOStream *, bool , const char *))*(void**)(__base - 526))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_CreateAnimationDecoderWithProperties
#define IMG_CreateAnimationDecoderWithProperties(__p0) \
	({ \
		SDL_PropertiesID  __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_AnimationDecoder *(*)(SDL_PropertiesID ))*(void**)(__base - 532))(__t__p0));\
	})
#endif

#ifndef IMG_GetAnimationDecoderFrame
#define IMG_GetAnimationDecoderFrame(__p0, __p1, __p2) \
	({ \
		IMG_AnimationDecoder * __t__p0 = __p0;\
		SDL_Surface ** __t__p1 = __p1;\
		Uint64 * __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_AnimationDecoder *, SDL_Surface **, Uint64 *))*(void**)(__base - 538))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_ResetAnimationDecoder
#define IMG_ResetAnimationDecoder(__p0) \
	({ \
		IMG_AnimationDecoder * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_AnimationDecoder *))*(void**)(__base - 544))(__t__p0));\
	})
#endif

#ifndef IMG_CloseAnimationDecoder
#define IMG_CloseAnimationDecoder(__p0) \
	({ \
		IMG_AnimationDecoder * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_AnimationDecoder *))*(void**)(__base - 550))(__t__p0));\
	})
#endif

#ifndef IMG_GetAnimationDecoderProperties
#define IMG_GetAnimationDecoderProperties(__p0) \
	({ \
		IMG_AnimationDecoder * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_PropertiesID (*)(IMG_AnimationDecoder *))*(void**)(__base - 556))(__t__p0));\
	})
#endif

#ifndef IMG_GetAnimationDecoderStatus
#define IMG_GetAnimationDecoderStatus(__p0) \
	({ \
		IMG_AnimationDecoder * __t__p0 = __p0;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IMG_AnimationDecoderStatus (*)(IMG_AnimationDecoder *))*(void**)(__base - 562))(__t__p0));\
	})
#endif

#ifndef IMG_GetClipboardImage
#define IMG_GetClipboardImage() \
	({ \
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(void))*(void**)(__base - 568))());\
	})
#endif

#ifndef IMG_CreateAnimatedCursor
#define IMG_CreateAnimatedCursor(__p0, __p1, __p2) \
	({ \
		IMG_Animation * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Cursor *(*)(IMG_Animation *, int , int ))*(void**)(__base - 574))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveCUR
#define IMG_SaveCUR(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *))*(void**)(__base - 580))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_SaveCUR_IO
#define IMG_SaveCUR_IO(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool ))*(void**)(__base - 586))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveICO
#define IMG_SaveICO(__p0, __p1) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, const char *))*(void**)(__base - 592))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_SaveICO_IO
#define IMG_SaveICO_IO(__p0, __p1, __p2) \
	({ \
		SDL_Surface * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(SDL_Surface *, SDL_IOStream *, bool ))*(void**)(__base - 598))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveAnimation
#define IMG_SaveAnimation(__p0, __p1) \
	({ \
		IMG_Animation * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_Animation *, const char *))*(void**)(__base - 604))(__t__p0, __t__p1));\
	})
#endif

#ifndef IMG_SaveAnimationTyped_IO
#define IMG_SaveAnimationTyped_IO(__p0, __p1, __p2, __p3) \
	({ \
		IMG_Animation * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_Animation *, SDL_IOStream *, bool , const char *))*(void**)(__base - 610))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef IMG_SaveANIAnimation_IO
#define IMG_SaveANIAnimation_IO(__p0, __p1, __p2) \
	({ \
		IMG_Animation * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_Animation *, SDL_IOStream *, bool ))*(void**)(__base - 616))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveAPNGAnimation_IO
#define IMG_SaveAPNGAnimation_IO(__p0, __p1, __p2) \
	({ \
		IMG_Animation * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_Animation *, SDL_IOStream *, bool ))*(void**)(__base - 622))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveAVIFAnimation_IO
#define IMG_SaveAVIFAnimation_IO(__p0, __p1, __p2, __p3) \
	({ \
		IMG_Animation * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_Animation *, SDL_IOStream *, bool , int ))*(void**)(__base - 628))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef IMG_SaveGIFAnimation_IO
#define IMG_SaveGIFAnimation_IO(__p0, __p1, __p2) \
	({ \
		IMG_Animation * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_Animation *, SDL_IOStream *, bool ))*(void**)(__base - 634))(__t__p0, __t__p1, __t__p2));\
	})
#endif

#ifndef IMG_SaveWEBPAnimation_IO
#define IMG_SaveWEBPAnimation_IO(__p0, __p1, __p2, __p3) \
	({ \
		IMG_Animation * __t__p0 = __p0;\
		SDL_IOStream * __t__p1 = __p1;\
		bool  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((bool (*)(IMG_Animation *, SDL_IOStream *, bool , int ))*(void**)(__base - 640))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})
#endif

#ifndef IMG_LoadGPUTexture
#define IMG_LoadGPUTexture(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUCopyPass * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUTexture *(*)(SDL_GPUDevice *, SDL_GPUCopyPass *, const char *, int *, int *))*(void**)(__base - 646))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})
#endif

#ifndef IMG_LoadGPUTexture_IO
#define IMG_LoadGPUTexture_IO(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUCopyPass * __t__p1 = __p1;\
		SDL_IOStream * __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		int * __t__p5 = __p5;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUTexture *(*)(SDL_GPUDevice *, SDL_GPUCopyPass *, SDL_IOStream *, bool , int *, int *))*(void**)(__base - 652))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})
#endif

#ifndef IMG_LoadGPUTextureTyped_IO
#define IMG_LoadGPUTextureTyped_IO(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		SDL_GPUDevice * __t__p0 = __p0;\
		SDL_GPUCopyPass * __t__p1 = __p1;\
		SDL_IOStream * __t__p2 = __p2;\
		bool  __t__p3 = __p3;\
		const char * __t__p4 = __p4;\
		int * __t__p5 = __p5;\
		int * __t__p6 = __p6;\
		long __base = (long)(SDL3_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_GPUTexture *(*)(SDL_GPUDevice *, SDL_GPUCopyPass *, SDL_IOStream *, bool , const char *, int *, int *))*(void**)(__base - 658))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})
#endif

#endif /* !_PPCINLINE_SDL3_IMAGE_H */
