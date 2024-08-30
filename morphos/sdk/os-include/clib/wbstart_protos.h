#ifndef CLIB_WBSTART_PROTOS_H
#define CLIB_WBSTART_PROTOS_H

/*
	wbstart.library	C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_WBSTART_H
# include <libraries/wbstart.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

LONG WBStartTagList(struct TagItem *);
#if !defined(USE_INLINE_STDARG)
LONG WBStartTags(Tag, ...);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_WBSTART_PROTOS_H */

