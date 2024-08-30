#ifndef CLIB_TOUCHPAD_PROTOS_H
#define CLIB_TOUCHPAD_PROTOS_H

/*
	touchpad.library C prototypes

	Copyright (c) 2009-2010 The MorphOS Development Team / Jacek Piszczek,  All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR AddTouchpad(struct TagItem *taglist);
void RemoveTouchpad(APTR touchpad, struct TagItem *taglist);
void FeedTouchpad(APTR touchpad, UBYTE *xarray, UBYTE *yarray, ULONG buttonmask, struct TagItem *taglist);
APTR ObtainTouchpad(struct TagItem *taglist);
void ReleaseTouchpad(APTR touchpad, struct TagItem *taglist);
ULONG GetTouchpadAttr(APTR touchpad, struct TagItem *taglist);
ULONG SetTouchpadAttr(APTR touchpad, struct TagItem *taglist);

#ifndef USE_INLINE_STDARG

APTR AddTouchpadTags(Tag tag1, ...);
void RemoveTouchpadTags(APTR touchpad, Tag tag1, ...);
void FeedTouchpadTags(APTR touchpad, UBYTE *xarray, UBYTE *yarray, ULONG buttonmask, Tag tag1, ...);
APTR ObtainTouchpadTags(Tag tag1, ...);
void ReleaseTouchpadTags(APTR touchpad, Tag tag1, ...);
ULONG GetTouchpadAttrTags(APTR touchpad, Tag tag1, ...);
ULONG SetTouchpadAttrTags(APTR touchpad, Tag tag1, ...);

#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_TOUCHPAD_PROTOS_H */
