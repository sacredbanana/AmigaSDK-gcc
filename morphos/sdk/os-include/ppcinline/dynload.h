/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_DYNLOAD_H
#define _PPCINLINE_DYNLOAD_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef DYNLOAD_BASE_NAME
#define DYNLOAD_BASE_NAME DynLoadBase
#endif /* !DYNLOAD_BASE_NAME */

#define dladdr(__p0, __p1) \
	(((int (*)(const void *, Dl_info *, void *))*(void**)((long)(DYNLOAD_BASE_NAME) - 46))(__p0, __p1, (void*)(DYNLOAD_BASE_NAME)))

#define dlclose(__p0) \
	(((int (*)(void *, void *))*(void**)((long)(DYNLOAD_BASE_NAME) - 34))(__p0, (void*)(DYNLOAD_BASE_NAME)))

#define dlerror() \
	(((const char *(*)(void *))*(void**)((long)(DYNLOAD_BASE_NAME) - 52))((void*)(DYNLOAD_BASE_NAME)))

#define dlopen(__p0, __p1) \
	(((void *(*)(const char *, int , void *))*(void**)((long)(DYNLOAD_BASE_NAME) - 28))(__p0, __p1, (void*)(DYNLOAD_BASE_NAME)))

#define dlsym(__p0, __p1) \
	(((void *(*)(void *, const char *, void *))*(void**)((long)(DYNLOAD_BASE_NAME) - 40))(__p0, __p1, (void*)(DYNLOAD_BASE_NAME)))

#endif /* !_PPCINLINE_DYNLOAD_H */
