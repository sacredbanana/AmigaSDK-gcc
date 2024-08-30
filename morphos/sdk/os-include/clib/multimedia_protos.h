/*
$VER: multimedia_protos.h 55.1 (07.10.2012)
*/

#ifndef CLIB_MULTIMEDIA_PROTOS_H
#define CLIB_MULTIMEDIA_PROTOS_H


#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef INTUITION_CLASSES_H
# include <intuition/classes.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void MediaLog(ULONG, STRPTR, STRPTR, STRPTR, ...);
BOOL MediaConnectTagList(Boopsiobject*, ULONG, Boopsiobject*, ULONG, struct TagItem*);
Boopsiobject* MediaNewObjectTagList(struct TagItem*);
STRPTR MediaFindClassTagList(APTR, struct TagItem*);
BOOL MediaGetClassAttr(STRPTR, ULONG, ULONG*);
APTR MediaAllocVec(ULONG);
void MediaFreeVec(APTR);
ULONG MediaSetLogLevel(ULONG);
QUAD MediaAudioFrameToTime(QUAD, LONG);
QUAD MediaTimeToAudioFrame(QUAD, LONG);
Boopsiobject* MediaGetGuiTagList(struct TagItem*); 
Boopsiobject* MediaBuildFromGuiTagList(Boopsiobject*, Boopsiobject*, LONG, struct TagItem*);
CONST_STRPTR MediaFault(LONG);
Boopsiobject* MediaBuildFromArgsTagList(STRPTR, Boopsiobject*, LONG, struct TagItem*);
STRPTR MediaGetArgsFromGui(Boopsiobject*);

#ifndef USE_INLINE_STDARG

BOOL MediaConnectTags(Boopsiobject*, ULONG, Boopsiobject*, ULONG, Tag tag1, ...);
Boopsiobject* MediaNewObjectTags(Tag tag1, ...);
STRPTR MediaFindClassTags(APTR, Tag tag1, ...);
Boopsiobject* MediaGetGuiTags(Tag tag1, ...);
Boopsiobject* MediaBuildFromGuiTags(Boopsiobject*, Boopsiobject*, LONG, Tag tag1, ...);
Boopsiobject* MediaBuildFromArgsTags(STRPTR, Boopsiobject*, LONG, Tag tag1, ...);
 
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_MULTIMEDIA_PROTOS_H */
