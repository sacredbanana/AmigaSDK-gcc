#ifndef CLIB_CGXVIDEO_H
#define CLIB_CGXVIDEO_H

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

#ifndef INTUITION_SCREENS_H
#include <intuition/screens.h>
#endif

#ifndef LIBRARIES_CGXVIDEO_H
#include <cybergraphx/cgxvideo.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

struct VLayerHandle;


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct VLayerHandle *CreateVLayerHandleTagList(struct Screen *,struct TagItem *);

ULONG DeleteVLayerHandle(struct VLayerHandle *);

ULONG AttachVLayerTagList(struct VLayerHandle *,struct Window *,struct TagItem *);

ULONG DetachVLayer(struct VLayerHandle *);

ULONG GetVLayerAttr(struct VLayerHandle *,ULONG AttrID);

ULONG UnlockVLayer(struct VLayerHandle *);

ULONG LockVLayer(struct VLayerHandle *);

void SetVLayerAttrTagList(struct VLayerHandle *,struct TagItem *);

void SwapVLayerBuffer(struct VLayerHandle *);

ULONG WriteSPLine(struct VLayerHandle *,unsigned char *,int,int,int);

ULONG QueryVLayerAttr(struct Screen *,ULONG AttrID);

#if !defined(USE_INLINE_STDARG)
ULONG AttachVLayerTags(struct VLayerHandle *,struct Window *,Tag, ...);
#endif

#if !defined(USE_INLINE_STDARG)
struct VLayerHandle *CreateVLayerHandleTags(struct Screen *,Tag, ...);
#endif

#if !defined(USE_INLINE_STDARG)
void SetVLayerAttrTags(struct VLayerHandle *,Tag, ...);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif
