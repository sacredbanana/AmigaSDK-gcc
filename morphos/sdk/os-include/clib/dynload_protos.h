#ifndef CLIB_DYNLOAD_PROTOS_H
#define CLIB_DYNLOAD_PROTOS_H

/*
	dynload.library C prototypes

	Copyright © 2005 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_DYNLOAD_H
# include <libraries/dynload.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

void *dlopen(const char *, int);
int dlclose(void *);
void *dlsym(void *, const char *);
int dladdr(const void *, Dl_info *);
const char *dlerror(void);

#ifdef __cplusplus
}
#endif

#endif /* CLIB_DYNLOAD_PROTOS_H */
