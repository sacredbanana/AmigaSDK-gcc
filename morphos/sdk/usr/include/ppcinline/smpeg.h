/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SMPEG_H
#define _PPCINLINE_SMPEG_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SMPEG_BASE_NAME
#define SMPEG_BASE_NAME SMPEGBase
#endif /* !SMPEG_BASE_NAME */

#define SMPEG_scale(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, int ))*(void**)(__base - 106))(__t__p0, __t__p1));\
	})

#define SMPEG_playAudio(__p0, __p1, __p2) \
	({ \
		SMPEG * __t__p0 = __p0;\
		Uint8 * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SMPEG *, Uint8 *, int ))*(void**)(__base - 184))(__t__p0, __t__p1, __t__p2));\
	})

#define SMPEG_loop(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, int ))*(void**)(__base - 94))(__t__p0, __t__p1));\
	})

#define SMPEG_new_data(__p0, __p1, __p2, __p3) \
	({ \
		void * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		SMPEG_Info * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SMPEG *(*)(void *, int , SMPEG_Info *, int ))*(void**)(__base - 40))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define SMPEG_new(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		SMPEG_Info * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SMPEG *(*)(const char *, SMPEG_Info *, int ))*(void**)(__base - 28))(__t__p0, __t__p1, __t__p2));\
	})

#define SMPEG_new_rwops(__p0, __p1, __p2) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		SMPEG_Info * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SMPEG *(*)(SDL_RWops *, SMPEG_Info *, int ))*(void**)(__base - 46))(__t__p0, __t__p1, __t__p2));\
	})

#define SMPEG_skip(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, float ))*(void**)(__base - 154))(__t__p0, __t__p1));\
	})

#define SMPEG_status(__p0) \
	({ \
		SMPEG * __t__p0 = __p0;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SMPEGstatus (*)(SMPEG *))*(void**)(__base - 76))(__t__p0));\
	})

#define SMPEG_seek(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, int ))*(void**)(__base - 148))(__t__p0, __t__p1));\
	})

#define SMPEG_setdisplay(__p0, __p1, __p2, __p3) \
	({ \
		SMPEG * __t__p0 = __p0;\
		SDL_Surface * __t__p1 = __p1;\
		SDL_mutex * __t__p2 = __p2;\
		SMPEG_DisplayCallback  __t__p3 = __p3;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, SDL_Surface *, SDL_mutex *, SMPEG_DisplayCallback ))*(void**)(__base - 88))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define SMPEG_new_descr(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		SMPEG_Info * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SMPEG *(*)(int , SMPEG_Info *, int ))*(void**)(__base - 34))(__t__p0, __t__p1, __t__p2));\
	})

#define SMPEG_renderFinal(__p0, __p1, __p2, __p3) \
	({ \
		SMPEG * __t__p0 = __p0;\
		SDL_Surface * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, SDL_Surface *, int , int ))*(void**)(__base - 166))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define SMPEG_setvolume(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, int ))*(void**)(__base - 82))(__t__p0, __t__p1));\
	})

#define SMPEG_filter(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		SMPEG_Filter * __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SMPEG_Filter *(*)(SMPEG *, SMPEG_Filter *))*(void**)(__base - 172))(__t__p0, __t__p1));\
	})

#define SMPEG_getinfo(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		SMPEG_Info * __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, SMPEG_Info *))*(void**)(__base - 52))(__t__p0, __t__p1));\
	})

#define SMPEG_stop(__p0) \
	({ \
		SMPEG * __t__p0 = __p0;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *))*(void**)(__base - 136))(__t__p0));\
	})

#define SMPEG_enablevideo(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, int ))*(void**)(__base - 64))(__t__p0, __t__p1));\
	})

#define SMPEG_actualSpec(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		SDL_AudioSpec * __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, SDL_AudioSpec *))*(void**)(__base - 202))(__t__p0, __t__p1));\
	})

#define SMPEG_rewind(__p0) \
	({ \
		SMPEG * __t__p0 = __p0;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *))*(void**)(__base - 142))(__t__p0));\
	})

#define SMPEG_delete(__p0) \
	({ \
		SMPEG * __t__p0 = __p0;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *))*(void**)(__base - 70))(__t__p0));\
	})

#define SMPEG_wantedSpec(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		SDL_AudioSpec * __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SMPEG *, SDL_AudioSpec *))*(void**)(__base - 196))(__t__p0, __t__p1));\
	})

#define SMPEG_pause(__p0) \
	({ \
		SMPEG * __t__p0 = __p0;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *))*(void**)(__base - 130))(__t__p0));\
	})

#define SMPEG_setdisplayregion(__p0, __p1, __p2, __p3, __p4) \
	({ \
		SMPEG * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, int , int , int , int ))*(void**)(__base - 118))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define SMPEG_scaleXY(__p0, __p1, __p2) \
	({ \
		SMPEG * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, int , int ))*(void**)(__base - 100))(__t__p0, __t__p1, __t__p2));\
	})

#define SMPEG_play(__p0) \
	({ \
		SMPEG * __t__p0 = __p0;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *))*(void**)(__base - 124))(__t__p0));\
	})

#define SMPEG_renderFrame(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, int ))*(void**)(__base - 160))(__t__p0, __t__p1));\
	})

#define SMPEG_error(__p0) \
	({ \
		SMPEG * __t__p0 = __p0;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(SMPEG *))*(void**)(__base - 178))(__t__p0));\
	})

#define SMPEG_enableaudio(__p0, __p1) \
	({ \
		SMPEG * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SMPEG *, int ))*(void**)(__base - 58))(__t__p0, __t__p1));\
	})

#define SMPEG_playAudioSDL(__p0, __p1, __p2) \
	({ \
		void * __t__p0 = __p0;\
		Uint8 * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SMPEG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *, Uint8 *, int ))*(void**)(__base - 190))(__t__p0, __t__p1, __t__p2));\
	})

#endif /* !_PPCINLINE_SMPEG_H */
