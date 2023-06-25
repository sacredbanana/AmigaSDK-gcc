#ifndef _DLFCN_H_
#define _DLFCN_H_
/*
**    $Id: dlfcn.h,v 1.2 2010-03-25 18:18:34 ssolie Exp $
**
**    dynamic loading library
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**    All Rights Reserved.
*/


#ifdef __cplusplus
extern "C" {
#endif

#define RTLD_GLOBAL	  0x01
#define RTLD_LOCAL    0x02
#define RTLD_LAZY     0x04
#define RTLD_NOW      0x08
#define RTLD_DEFAULT  (void *)0

void *dlopen (const char *filename, int flag);
const char *dlerror(void);
void *dlsym(void *handle, const char *symbol);
int dlclose (void *handle);

#ifdef __cplusplus
}
#endif
       
#endif //_DLFCN_H_
