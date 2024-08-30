/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_POWERSDLSOUND_H
#define _PPCINLINE_POWERSDLSOUND_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef POWERSDLSOUND_BASE_NAME
#define POWERSDLSOUND_BASE_NAME PowerSDLSoundBase
#endif /* !POWERSDLSOUND_BASE_NAME */

#define Sound_Seek(__p0, __p1) \
	({ \
		Sound_Sample * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(Sound_Sample *, Uint32 ))*(void**)(__base - 106))(__t__p0, __t__p1));\
	})

#define Sound_Rewind(__p0) \
	({ \
		Sound_Sample * __t__p0 = __p0;\
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(Sound_Sample *))*(void**)(__base - 100))(__t__p0));\
	})

#define Sound_AvailableDecoders() \
	({ \
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const Sound_DecoderInfo **(*)(void))*(void**)(__base - 46))());\
	})

#define Sound_GetError() \
	({ \
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 52))());\
	})

#define Sound_NewSample(__p0, __p1, __p2, __p3) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		Sound_AudioInfo * __t__p2 = __p2;\
		Uint32  __t__p3 = __p3;\
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sound_Sample *(*)(SDL_RWops *, const char *, Sound_AudioInfo *, Uint32 ))*(void**)(__base - 64))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define Sound_GetLinkedVersion(__p0) \
	({ \
		Sound_Version * __t__p0 = __p0;\
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Sound_Version *))*(void**)(__base - 28))(__t__p0));\
	})

#define Sound_DecodeAll(__p0) \
	({ \
		Sound_Sample * __t__p0 = __p0;\
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(Sound_Sample *))*(void**)(__base - 94))(__t__p0));\
	})

#define Sound_NewSampleFromFile(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		Sound_AudioInfo * __t__p1 = __p1;\
		Uint32  __t__p2 = __p2;\
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Sound_Sample *(*)(const char *, Sound_AudioInfo *, Uint32 ))*(void**)(__base - 70))(__t__p0, __t__p1, __t__p2));\
	})

#define Sound_SetBufferSize(__p0, __p1) \
	({ \
		Sound_Sample * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(Sound_Sample *, Uint32 ))*(void**)(__base - 82))(__t__p0, __t__p1));\
	})

#define Sound_ClearError() \
	({ \
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 58))());\
	})

#define Sound_Quit() \
	({ \
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 40))());\
	})

#define Sound_Init() \
	({ \
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 34))());\
	})

#define Sound_FreeSample(__p0) \
	({ \
		Sound_Sample * __t__p0 = __p0;\
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Sound_Sample *))*(void**)(__base - 76))(__t__p0));\
	})

#define Sound_Decode(__p0) \
	({ \
		Sound_Sample * __t__p0 = __p0;\
		long __base = (long)(POWERSDLSOUND_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Uint32 (*)(Sound_Sample *))*(void**)(__base - 88))(__t__p0));\
	})

#endif /* !_PPCINLINE_POWERSDLSOUND_H */
