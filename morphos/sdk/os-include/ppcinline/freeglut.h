/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_FREEGLUT_H
#define _PPCINLINE_FREEGLUT_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef FREEGLUT_BASE_NAME
#define FREEGLUT_BASE_NAME FreeGLUTBase
#endif /* !FREEGLUT_BASE_NAME */

#define glutAddMenuEntry(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const char *, int ))*(void**)(__base - 28))(__t__p0, __t__p1));\
	})

#define glutAddSubMenu(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const char *, int ))*(void**)(__base - 34))(__t__p0, __t__p1));\
	})

#define glutAppStatusFunc(__p0) \
	({ \
		void (* __t__p0)(int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int)))*(void**)(__base - 40))(__t__p0));\
	})

#define glutAppStatusFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, void *), void *))*(void**)(__base - 46))(__t__p0, __t__p1));\
	})

#define glutAttachMenu(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 52))(__t__p0));\
	})

#define glutBitmapCharacter(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *, int ))*(void**)(__base - 58))(__t__p0, __t__p1));\
	})

#define glutBitmapHeight(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void *))*(void**)(__base - 64))(__t__p0));\
	})

#define glutBitmapLength(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		const unsigned char * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void *, const unsigned char *))*(void**)(__base - 70))(__t__p0, __t__p1));\
	})

#define glutBitmapString(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		const unsigned char * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *, const unsigned char *))*(void**)(__base - 76))(__t__p0, __t__p1));\
	})

#define glutBitmapWidth(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void *, int ))*(void**)(__base - 82))(__t__p0, __t__p1));\
	})

#define glutButtonBoxFunc(__p0) \
	({ \
		void (* __t__p0)(int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int)))*(void**)(__base - 88))(__t__p0));\
	})

#define glutButtonBoxFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, void *), void *))*(void**)(__base - 94))(__t__p0, __t__p1));\
	})

#define glutChangeToMenuEntry(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , const char *, int ))*(void**)(__base - 100))(__t__p0, __t__p1, __t__p2));\
	})

#define glutChangeToSubMenu(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , const char *, int ))*(void**)(__base - 106))(__t__p0, __t__p1, __t__p2));\
	})

#define glutCloseFunc(__p0) \
	({ \
		void (* __t__p0)(void) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void)))*(void**)(__base - 112))(__t__p0));\
	})

#define glutCloseFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void *), void *))*(void**)(__base - 118))(__t__p0, __t__p1));\
	})

#define glutCopyColormap(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 124))(__t__p0));\
	})

#define glutCreateMenu(__p0) \
	({ \
		void (* __t__p0)(int menu) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void (*)(int menu)))*(void**)(__base - 130))(__t__p0));\
	})

#define glutCreateMenuUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int menu, void *user_data) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void (*)(int menu, void *user_data), void *))*(void**)(__base - 136))(__t__p0, __t__p1));\
	})

#define glutCreateSubWindow(__p0, __p1, __p2, __p3, __p4) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int , int , int , int ))*(void**)(__base - 142))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define glutCreateWindow(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 148))(__t__p0));\
	})

#define glutDestroyMenu(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 154))(__t__p0));\
	})

#define glutDestroyWindow(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 160))(__t__p0));\
	})

#define glutDetachMenu(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 166))(__t__p0));\
	})

#define glutDeviceGet(__p0) \
	({ \
		GLenum  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(GLenum ))*(void**)(__base - 172))(__t__p0));\
	})

#define glutDialsFunc(__p0) \
	({ \
		void (* __t__p0)(int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int)))*(void**)(__base - 178))(__t__p0));\
	})

#define glutDialsFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, void *), void *))*(void**)(__base - 184))(__t__p0, __t__p1));\
	})

#define glutDisplayFunc(__p0) \
	({ \
		void (* __t__p0)(void) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void)))*(void**)(__base - 190))(__t__p0));\
	})

#define glutDisplayFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void *), void *))*(void**)(__base - 196))(__t__p0, __t__p1));\
	})

#define glutEnterGameMode() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 202))());\
	})

#define glutEntryFunc(__p0) \
	({ \
		void (* __t__p0)(int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int)))*(void**)(__base - 208))(__t__p0));\
	})

#define glutEntryFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, void *), void *))*(void**)(__base - 214))(__t__p0, __t__p1));\
	})

#define glutEstablishOverlay() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 220))());\
	})

#define glutExit() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 226))());\
	})

#define glutExtensionSupported(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 232))(__t__p0));\
	})

#define glutForceJoystickFunc() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 238))());\
	})

#define glutFullScreen() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 244))());\
	})

#define glutFullScreenToggle() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 250))());\
	})

#define glutGameModeGet(__p0) \
	({ \
		GLenum  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(GLenum ))*(void**)(__base - 256))(__t__p0));\
	})

#define glutGameModeString(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const char *))*(void**)(__base - 262))(__t__p0));\
	})

#define glutGet(__p0) \
	({ \
		GLenum  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(GLenum ))*(void**)(__base - 268))(__t__p0));\
	})

#define glutGetColor(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((GLfloat (*)(int , int ))*(void**)(__base - 274))(__t__p0, __t__p1));\
	})

#define glutGetMenu() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 280))());\
	})

#define glutGetMenuData() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void))*(void**)(__base - 286))());\
	})

#define glutGetModeValues(__p0, __p1) \
	({ \
		GLenum  __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int *(*)(GLenum , int *))*(void**)(__base - 292))(__t__p0, __t__p1));\
	})

#define glutGetModifiers() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 298))());\
	})

#define glutGetProcAddress(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((GLUTproc (*)(const char *))*(void**)(__base - 304))(__t__p0));\
	})

#define glutGetWindow() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 310))());\
	})

#define glutGetWindowData() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void))*(void**)(__base - 316))());\
	})

#define glutHideOverlay() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 322))());\
	})

#define glutHideWindow() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 328))());\
	})

#define glutIconifyWindow() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 334))());\
	})

#define glutIdleFunc(__p0) \
	({ \
		void (* __t__p0)(void) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void)))*(void**)(__base - 340))(__t__p0));\
	})

#define glutIdleFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void *), void *))*(void**)(__base - 346))(__t__p0, __t__p1));\
	})

#define glutIgnoreKeyRepeat(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 352))(__t__p0));\
	})

#define glutInit(__p0, __p1) \
	({ \
		int * __t__p0 = __p0;\
		char ** __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int *, char **))*(void**)(__base - 358))(__t__p0, __t__p1));\
	})

#define glutInitContextFlags(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 364))(__t__p0));\
	})

#define glutInitContextFunc(__p0) \
	({ \
		void (* __t__p0)(void) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void)))*(void**)(__base - 370))(__t__p0));\
	})

#define glutInitContextFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void *), void *))*(void**)(__base - 376))(__t__p0, __t__p1));\
	})

#define glutInitContextProfile(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 382))(__t__p0));\
	})

#define glutInitContextVersion(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , int ))*(void**)(__base - 388))(__t__p0, __t__p1));\
	})

#define glutInitDisplayMode(__p0) \
	({ \
		unsigned int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(unsigned int ))*(void**)(__base - 394))(__t__p0));\
	})

#define glutInitDisplayString(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const char *))*(void**)(__base - 400))(__t__p0));\
	})

#define glutInitErrorFunc(__p0) \
	({ \
		void (* __t__p0)(const char *fmt, va_list ap) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(const char *fmt, va_list ap)))*(void**)(__base - 406))(__t__p0));\
	})

#define glutInitErrorFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(const char *fmt, va_list ap, void *user_data) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(const char *fmt, va_list ap, void *user_data), void *))*(void**)(__base - 412))(__t__p0, __t__p1));\
	})

#define glutInitWarningFunc(__p0) \
	({ \
		void (* __t__p0)(const char *fmt, va_list ap) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(const char *fmt, va_list ap)))*(void**)(__base - 418))(__t__p0));\
	})

#define glutInitWarningFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(const char *fmt, va_list ap, void *user_data) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(const char *fmt, va_list ap, void *user_data), void *))*(void**)(__base - 424))(__t__p0, __t__p1));\
	})

#define glutInitWindowPosition(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , int ))*(void**)(__base - 430))(__t__p0, __t__p1));\
	})

#define glutInitWindowSize(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , int ))*(void**)(__base - 436))(__t__p0, __t__p1));\
	})

#define glutJoystickFunc(__p0, __p1) \
	({ \
		void (* __t__p0)(unsigned int, int, int, int) = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(unsigned int, int, int, int), int ))*(void**)(__base - 442))(__t__p0, __t__p1));\
	})

#define glutJoystickFuncUcall(__p0, __p1, __p2) \
	({ \
		void (* __t__p0)(unsigned int, int, int, int, void *) = __p0;\
		int  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(unsigned int, int, int, int, void *), int , void *))*(void**)(__base - 448))(__t__p0, __t__p1, __t__p2));\
	})

#define glutKeyboardFunc(__p0) \
	({ \
		void (* __t__p0)(unsigned char, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(unsigned char, int, int)))*(void**)(__base - 454))(__t__p0));\
	})

#define glutKeyboardFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(unsigned char, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(unsigned char, int, int, void *), void *))*(void**)(__base - 460))(__t__p0, __t__p1));\
	})

#define glutKeyboardUpFunc(__p0) \
	({ \
		void (* __t__p0)(unsigned char, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(unsigned char, int, int)))*(void**)(__base - 466))(__t__p0));\
	})

#define glutKeyboardUpFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(unsigned char, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(unsigned char, int, int, void *), void *))*(void**)(__base - 472))(__t__p0, __t__p1));\
	})

#define glutLayerGet(__p0) \
	({ \
		GLenum  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(GLenum ))*(void**)(__base - 478))(__t__p0));\
	})

#define glutLeaveFullScreen() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 484))());\
	})

#define glutLeaveGameMode() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 490))());\
	})

#define glutLeaveMainLoop() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 496))());\
	})

#define glutMainLoop() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 502))());\
	})

#define glutMainLoopEvent() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 508))());\
	})

#define glutMenuDestroyFunc(__p0) \
	({ \
		void (* __t__p0)(void) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void)))*(void**)(__base - 514))(__t__p0));\
	})

#define glutMenuDestroyFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void *), void *))*(void**)(__base - 520))(__t__p0, __t__p1));\
	})

#define glutMenuStateFunc(__p0) \
	({ \
		void (* __t__p0)(int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int)))*(void**)(__base - 526))(__t__p0));\
	})

#define glutMenuStatusFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int)))*(void**)(__base - 532))(__t__p0));\
	})

#define glutMenuStatusFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, void *), void *))*(void**)(__base - 538))(__t__p0, __t__p1));\
	})

#define glutMorphOSInit(__p0, __p1) \
	({ \
		void ** __t__p0 = __p0;\
		void (* __t__p1)(int) = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void **, void (*)(int)))*(void**)(__base - 544))(__t__p0, __t__p1));\
	})

#define glutMorphOSInit2(__p0, __p1, __p2) \
	({ \
		void ** __t__p0 = __p0;\
		void (* __t__p1)(int) = __p1;\
		unsigned int  __t__p2 = __p2;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void **, void (*)(int), unsigned int ))*(void**)(__base - 1234))(__t__p0, __t__p1, __t__p2));\
	})

#define glutMotionFunc(__p0) \
	({ \
		void (* __t__p0)(int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int)))*(void**)(__base - 550))(__t__p0));\
	})

#define glutMotionFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, void *), void *))*(void**)(__base - 556))(__t__p0, __t__p1));\
	})

#define glutMouseFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, int)))*(void**)(__base - 562))(__t__p0));\
	})

#define glutMouseFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, int, void *), void *))*(void**)(__base - 568))(__t__p0, __t__p1));\
	})

#define glutMouseWheelFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, int)))*(void**)(__base - 574))(__t__p0));\
	})

#define glutMouseWheelFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, int, void *), void *))*(void**)(__base - 580))(__t__p0, __t__p1));\
	})

#define glutMultiButtonFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, int, int)))*(void**)(__base - 586))(__t__p0));\
	})

#define glutMultiButtonFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, int, int, void *), void *))*(void**)(__base - 592))(__t__p0, __t__p1));\
	})

#define glutMultiEntryFunc(__p0) \
	({ \
		void (* __t__p0)(int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int)))*(void**)(__base - 598))(__t__p0));\
	})

#define glutMultiEntryFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, void *), void *))*(void**)(__base - 604))(__t__p0, __t__p1));\
	})

#define glutMultiMotionFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int)))*(void**)(__base - 610))(__t__p0));\
	})

#define glutMultiMotionFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, void *), void *))*(void**)(__base - 616))(__t__p0, __t__p1));\
	})

#define glutMultiPassiveFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int)))*(void**)(__base - 622))(__t__p0));\
	})

#define glutMultiPassiveFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, void *), void *))*(void**)(__base - 628))(__t__p0, __t__p1));\
	})

#define glutOverlayDisplayFunc(__p0) \
	({ \
		void (* __t__p0)(void) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void)))*(void**)(__base - 634))(__t__p0));\
	})

#define glutOverlayDisplayFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void *), void *))*(void**)(__base - 640))(__t__p0, __t__p1));\
	})

#define glutPassiveMotionFunc(__p0) \
	({ \
		void (* __t__p0)(int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int)))*(void**)(__base - 646))(__t__p0));\
	})

#define glutPassiveMotionFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, void *), void *))*(void**)(__base - 652))(__t__p0, __t__p1));\
	})

#define glutPopWindow() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 658))());\
	})

#define glutPositionFunc(__p0) \
	({ \
		void (* __t__p0)(int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int)))*(void**)(__base - 664))(__t__p0));\
	})

#define glutPositionFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, void *), void *))*(void**)(__base - 670))(__t__p0, __t__p1));\
	})

#define glutPositionWindow(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , int ))*(void**)(__base - 676))(__t__p0, __t__p1));\
	})

#define glutPostOverlayRedisplay() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 682))());\
	})

#define glutPostRedisplay() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 688))());\
	})

#define glutPostWindowOverlayRedisplay(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 694))(__t__p0));\
	})

#define glutPostWindowRedisplay(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 700))(__t__p0));\
	})

#define glutPushWindow() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 706))());\
	})

#define glutRemoveMenuItem(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 712))(__t__p0));\
	})

#define glutRemoveOverlay() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 718))());\
	})

#define glutReportErrors() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 724))());\
	})

#define glutReshapeFunc(__p0) \
	({ \
		void (* __t__p0)(int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int)))*(void**)(__base - 730))(__t__p0));\
	})

#define glutReshapeFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, void *), void *))*(void**)(__base - 736))(__t__p0, __t__p1));\
	})

#define glutReshapeWindow(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , int ))*(void**)(__base - 742))(__t__p0, __t__p1));\
	})

#define glutSetColor(__p0, __p1, __p2, __p3) \
	({ \
		int  __t__p0 = __p0;\
		GLfloat  __t__p1 = __p1;\
		GLfloat  __t__p2 = __p2;\
		GLfloat  __t__p3 = __p3;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , GLfloat , GLfloat , GLfloat ))*(void**)(__base - 748))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define glutSetCursor(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 754))(__t__p0));\
	})

#define glutSetIconTitle(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const char *))*(void**)(__base - 760))(__t__p0));\
	})

#define glutSetKeyRepeat(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 766))(__t__p0));\
	})

#define glutSetMenu(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 772))(__t__p0));\
	})

#define glutSetMenuData(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *))*(void**)(__base - 778))(__t__p0));\
	})

#define glutSetMenuFont(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , void *))*(void**)(__base - 784))(__t__p0, __t__p1));\
	})

#define glutSetOption(__p0, __p1) \
	({ \
		GLenum  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(GLenum , int ))*(void**)(__base - 790))(__t__p0, __t__p1));\
	})

#define glutSetVertexAttribCoord3(__p0) \
	({ \
		GLint  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(GLint ))*(void**)(__base - 796))(__t__p0));\
	})

#define glutSetVertexAttribNormal(__p0) \
	({ \
		GLint  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(GLint ))*(void**)(__base - 802))(__t__p0));\
	})

#define glutSetVertexAttribTexCoord2(__p0) \
	({ \
		GLint  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(GLint ))*(void**)(__base - 808))(__t__p0));\
	})

#define glutSetWindow(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 814))(__t__p0));\
	})

#define glutSetWindowData(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *))*(void**)(__base - 820))(__t__p0));\
	})

#define glutSetWindowTitle(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const char *))*(void**)(__base - 826))(__t__p0));\
	})

#define glutSetupVideoResizing() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 832))());\
	})

#define glutShowOverlay() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 838))());\
	})

#define glutShowWindow() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 844))());\
	})

#define glutSolidCone(__p0, __p1, __p2, __p3) \
	({ \
		double  __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		GLint  __t__p2 = __p2;\
		GLint  __t__p3 = __p3;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double , double , GLint , GLint ))*(void**)(__base - 850))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define glutSolidCube(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double ))*(void**)(__base - 856))(__t__p0));\
	})

#define glutSolidCylinder(__p0, __p1, __p2, __p3) \
	({ \
		double  __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		GLint  __t__p2 = __p2;\
		GLint  __t__p3 = __p3;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double , double , GLint , GLint ))*(void**)(__base - 862))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define glutSolidDodecahedron() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 868))());\
	})

#define glutSolidIcosahedron() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 874))());\
	})

#define glutSolidOctahedron() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 880))());\
	})

#define glutSolidRhombicDodecahedron() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 886))());\
	})

#define glutSolidSierpinskiSponge(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		double * __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , double *, double ))*(void**)(__base - 892))(__t__p0, __t__p1, __t__p2));\
	})

#define glutSolidSphere(__p0, __p1, __p2) \
	({ \
		double  __t__p0 = __p0;\
		GLint  __t__p1 = __p1;\
		GLint  __t__p2 = __p2;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double , GLint , GLint ))*(void**)(__base - 898))(__t__p0, __t__p1, __t__p2));\
	})

#define glutSolidTeacup(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double ))*(void**)(__base - 904))(__t__p0));\
	})

#define glutSolidTeapot(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double ))*(void**)(__base - 910))(__t__p0));\
	})

#define glutSolidTeaspoon(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double ))*(void**)(__base - 916))(__t__p0));\
	})

#define glutSolidTetrahedron() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 922))());\
	})

#define glutSolidTorus(__p0, __p1, __p2, __p3) \
	({ \
		double  __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		GLint  __t__p2 = __p2;\
		GLint  __t__p3 = __p3;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double , double , GLint , GLint ))*(void**)(__base - 928))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define glutSpaceballButtonFunc(__p0) \
	({ \
		void (* __t__p0)(int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int)))*(void**)(__base - 934))(__t__p0));\
	})

#define glutSpaceballButtonFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, void *), void *))*(void**)(__base - 940))(__t__p0, __t__p1));\
	})

#define glutSpaceballMotionFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int)))*(void**)(__base - 946))(__t__p0));\
	})

#define glutSpaceballMotionFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, void *), void *))*(void**)(__base - 952))(__t__p0, __t__p1));\
	})

#define glutSpaceballRotateFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int)))*(void**)(__base - 958))(__t__p0));\
	})

#define glutSpaceballRotateFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, void *), void *))*(void**)(__base - 964))(__t__p0, __t__p1));\
	})

#define glutSpecialFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int)))*(void**)(__base - 970))(__t__p0));\
	})

#define glutSpecialFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, void *), void *))*(void**)(__base - 976))(__t__p0, __t__p1));\
	})

#define glutSpecialUpFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int)))*(void**)(__base - 982))(__t__p0));\
	})

#define glutSpecialUpFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, void *), void *))*(void**)(__base - 988))(__t__p0, __t__p1));\
	})

#define glutStopVideoResizing() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 994))());\
	})

#define glutStrokeCharacter(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *, int ))*(void**)(__base - 1000))(__t__p0, __t__p1));\
	})

#define glutStrokeHeight(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((GLfloat (*)(void *))*(void**)(__base - 1006))(__t__p0));\
	})

#define glutStrokeLength(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		const unsigned char * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void *, const unsigned char *))*(void**)(__base - 1012))(__t__p0, __t__p1));\
	})

#define glutStrokeLengthf(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		const unsigned char * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((GLfloat (*)(void *, const unsigned char *))*(void**)(__base - 1018))(__t__p0, __t__p1));\
	})

#define glutStrokeString(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		const unsigned char * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *, const unsigned char *))*(void**)(__base - 1024))(__t__p0, __t__p1));\
	})

#define glutStrokeWidth(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void *, int ))*(void**)(__base - 1030))(__t__p0, __t__p1));\
	})

#define glutStrokeWidthf(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((GLfloat (*)(void *, int ))*(void**)(__base - 1036))(__t__p0, __t__p1));\
	})

#define glutSwapBuffers() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 1042))());\
	})

#define glutTabletButtonFunc(__p0) \
	({ \
		void (* __t__p0)(int, int, int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, int)))*(void**)(__base - 1048))(__t__p0));\
	})

#define glutTabletButtonFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, int, int, void *), void *))*(void**)(__base - 1054))(__t__p0, __t__p1));\
	})

#define glutTabletMotionFunc(__p0) \
	({ \
		void (* __t__p0)(int, int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int)))*(void**)(__base - 1060))(__t__p0));\
	})

#define glutTabletMotionFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, int, void *), void *))*(void**)(__base - 1066))(__t__p0, __t__p1));\
	})

#define glutTimerFunc(__p0, __p1, __p2) \
	({ \
		unsigned int  __t__p0 = __p0;\
		void (* __t__p1)(int) = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(unsigned int , void (*)(int), int ))*(void**)(__base - 1072))(__t__p0, __t__p1, __t__p2));\
	})

#define glutTimerFuncUcall(__p0, __p1, __p2, __p3) \
	({ \
		unsigned int  __t__p0 = __p0;\
		void (* __t__p1)(int, void *) = __p1;\
		int  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(unsigned int , void (*)(int, void *), int , void *))*(void**)(__base - 1078))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define glutUseLayer(__p0) \
	({ \
		GLenum  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(GLenum ))*(void**)(__base - 1084))(__t__p0));\
	})

#define glutVideoPan(__p0, __p1, __p2, __p3) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , int , int , int ))*(void**)(__base - 1090))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define glutVideoResize(__p0, __p1, __p2, __p3) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , int , int , int ))*(void**)(__base - 1096))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define glutVideoResizeGet(__p0) \
	({ \
		GLenum  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(GLenum ))*(void**)(__base - 1102))(__t__p0));\
	})

#define glutVisibilityFunc(__p0) \
	({ \
		void (* __t__p0)(int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int)))*(void**)(__base - 1108))(__t__p0));\
	})

#define glutVisibilityFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, void *), void *))*(void**)(__base - 1114))(__t__p0, __t__p1));\
	})

#define glutWMCloseFunc(__p0) \
	({ \
		void (* __t__p0)(void) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void)))*(void**)(__base - 1120))(__t__p0));\
	})

#define glutWMCloseFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void *), void *))*(void**)(__base - 1126))(__t__p0, __t__p1));\
	})

#define glutWarpPointer(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , int ))*(void**)(__base - 1132))(__t__p0, __t__p1));\
	})

#define glutWindowStatusFunc(__p0) \
	({ \
		void (* __t__p0)(int) = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int)))*(void**)(__base - 1138))(__t__p0));\
	})

#define glutWindowStatusFuncUcall(__p0, __p1) \
	({ \
		void (* __t__p0)(int, void *) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int, void *), void *))*(void**)(__base - 1144))(__t__p0, __t__p1));\
	})

#define glutWireCone(__p0, __p1, __p2, __p3) \
	({ \
		double  __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		GLint  __t__p2 = __p2;\
		GLint  __t__p3 = __p3;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double , double , GLint , GLint ))*(void**)(__base - 1150))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define glutWireCube(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double ))*(void**)(__base - 1156))(__t__p0));\
	})

#define glutWireCylinder(__p0, __p1, __p2, __p3) \
	({ \
		double  __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		GLint  __t__p2 = __p2;\
		GLint  __t__p3 = __p3;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double , double , GLint , GLint ))*(void**)(__base - 1162))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define glutWireDodecahedron() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 1168))());\
	})

#define glutWireIcosahedron() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 1174))());\
	})

#define glutWireOctahedron() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 1180))());\
	})

#define glutWireRhombicDodecahedron() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 1186))());\
	})

#define glutWireSierpinskiSponge(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		double * __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , double *, double ))*(void**)(__base - 1192))(__t__p0, __t__p1, __t__p2));\
	})

#define glutWireSphere(__p0, __p1, __p2) \
	({ \
		double  __t__p0 = __p0;\
		GLint  __t__p1 = __p1;\
		GLint  __t__p2 = __p2;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double , GLint , GLint ))*(void**)(__base - 1198))(__t__p0, __t__p1, __t__p2));\
	})

#define glutWireTeacup(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double ))*(void**)(__base - 1204))(__t__p0));\
	})

#define glutWireTeapot(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double ))*(void**)(__base - 1210))(__t__p0));\
	})

#define glutWireTeaspoon(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double ))*(void**)(__base - 1216))(__t__p0));\
	})

#define glutWireTetrahedron() \
	({ \
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 1222))());\
	})

#define glutWireTorus(__p0, __p1, __p2, __p3) \
	({ \
		double  __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		GLint  __t__p2 = __p2;\
		GLint  __t__p3 = __p3;\
		long __base = (long)(FREEGLUT_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double , double , GLint , GLint ))*(void**)(__base - 1228))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#endif /* !_PPCINLINE_FREEGLUT_H */
