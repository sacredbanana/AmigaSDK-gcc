/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_POWERSDL_IMAGE_H
#define _PPCINLINE_POWERSDL_IMAGE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef POWERSDL_IMAGE_BASE_NAME
#define POWERSDL_IMAGE_BASE_NAME PowerSDLImageBase
#endif /* !POWERSDL_IMAGE_BASE_NAME */

#define IMG_Load(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(const char *))*(void**)(__base - 34))(__t__p0));\
	})

#define IMG_InvertAlpha(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 46))(__t__p0));\
	})

#define IMG_isGIF(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 82))(__t__p0));\
	})

#define IMG_isXV(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 190))(__t__p0));\
	})

#define IMG_LoadXV_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 196))(__t__p0));\
	})

#define IMG_isPCX(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 76))(__t__p0));\
	})

#define IMG_isBMP(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 52))(__t__p0));\
	})

#define IMG_LoadXPM_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 124))(__t__p0));\
	})

#define IMG_Linked_Version() \
	({ \
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_version *(*)())*(void**)(__base - 184))());\
	})

#define IMG_isPNG(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 100))(__t__p0));\
	})

#define IMG_LoadXCF_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 130))(__t__p0));\
	})

#define IMG_isXCF(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 70))(__t__p0));\
	})

#define IMG_isTIF(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 94))(__t__p0));\
	})

#define IMG_LoadTyped_RW(__p0, __p1, __p2) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		char * __t__p2 = __p2;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *, int , char *))*(void**)(__base - 28))(__t__p0, __t__p1, __t__p2));\
	})

#define IMG_isLBM(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 106))(__t__p0));\
	})

#define IMG_isXPM(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 64))(__t__p0));\
	})

#define IMG_LoadPNM_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 118))(__t__p0));\
	})

#define IMG_ReadXPMFromArray(__p0) \
	({ \
		char ** __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(char **))*(void**)(__base - 178))(__t__p0));\
	})

#define IMG_LoadTIF_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 154))(__t__p0));\
	})

#define IMG_isPNM(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 58))(__t__p0));\
	})

#define IMG_LoadTGA_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 166))(__t__p0));\
	})

#define IMG_LoadPNG_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 160))(__t__p0));\
	})

#define IMG_Load_RW(__p0, __p1) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *, int ))*(void**)(__base - 40))(__t__p0, __t__p1));\
	})

#define IMG_LoadLBM_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 172))(__t__p0));\
	})

#define IMG_LoadJPG_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 148))(__t__p0));\
	})

#define IMG_isJPG(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDL_RWops *))*(void**)(__base - 88))(__t__p0));\
	})

#define IMG_LoadBMP_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 112))(__t__p0));\
	})

#define IMG_LoadGIF_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 142))(__t__p0));\
	})

#define IMG_LoadPCX_RW(__p0) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_IMAGE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_Surface *(*)(SDL_RWops *))*(void**)(__base - 136))(__t__p0));\
	})

#endif /* !_PPCINLINE_POWERSDL_IMAGE_H */
