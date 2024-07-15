#ifndef __DLFCN_H__
#define __DLFCN_H__

/*
 * To be used withlibraries created with -noixemul -shared
 */
char const * __stdargs dlerror();
void * __stdargs dlopen (__const char *__file, int __mode);
int __stdargs dlclose (void *__handle);
void * __stdargs dlvsym (void *__restrict __handle,
		     __const char *__restrict __name,
		     __const char *__restrict __version);
void * __stdargs dlsym (void *__restrict __handle,
		    __const char *__restrict __name);

// the implementation ignores these flags...
#define RTLD_LAZY   0
#define RTLD_NOW    1
#define RTLD_GLOBAL 2
#define RTLD_LOCAL  4

#endif //__DLFCN_H__
