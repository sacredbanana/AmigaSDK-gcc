#ifndef LIBRARIES_DYNLOAD_H
#define LIBRARIES_DYNLOAD_H

/*
	MorphOS Shared DLLib
	
	dynload.library include
	
	Copyright © 2005 The MorphOS Development Team, All Rights Reserved.
*/

#ifdef __cplusplus
extern "C" {
#endif

typedef
struct dl_info
{
	const char *dli_fname;
	void       *dli_fbase;
	const char *dli_sname;
	void       *dli_saddr;
} Dl_info;

#define RTLD_LOCAL    (0)
#define RTLD_LAZY     (1<<0)
#define RTLD_NOW      (1<<1)
#define RTLD_NOLOAD   (1<<2)
#define RTLD_GLOBAL   (1<<8)
#define RTLD_NODELETE (1<<12)

#define RTLD_DEFAULT  ((void *) 0)
#define RTLD_NEXT     ((void *)-1)
#define RTLD_SELF     ((void *)-2)

#ifdef __cplusplus
}
#endif

#endif /* LIBRARIES_DYNLOAD_H */
