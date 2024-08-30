#ifndef CLIB_PPCDISS_PROTOS_H
#define CLIB_PPCDISS_PROTOS_H

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR	PPCDissCreateObjectTagList(struct  TagItem *);
void	PPCDissDeleteObject(APTR);
ULONG	PPCDissTranslateTagList(APTR,
					  struct TagItem *);

#if !defined(USE_INLINE_STDARG)
APTR	PPCDissCreateObjectTags(Tag, ...);
#endif
#if !defined(USE_INLINE_STDARG)
ULONG	PPCDissTranslateTags(APTR,
			   Tag, ...);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif
