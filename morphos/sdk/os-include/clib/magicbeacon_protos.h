#ifndef CLIB_MAGICBEACON_PROTOS_H
#define CLIB_MAGICBEACON_PROTOS_H

/***************************************************************************/

/*
**  $VER: magicbeacon_protos.h 1.0 (25.10.2021)
**
**   Copyright (C) 2021 Guido Mersmann <geit@gmx.de>
**   All rights reserved.
*/

/***************************************************************************/

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/***************************************************************************/

APTR MagicBeacon_ApplicationRegisterTagList(struct TagItem *tags);
#if !defined(USE_INLINE_STDARG)
APTR MagicBeacon_ApplicationRegisterTags(IPTR tag,...);
#endif
void MagicBeacon_ApplicationUnregister(APTR handle);
IPTR MagicBeacon_GetAttrsTagList(APTR handle,APTR beacon,struct TagItem *tags);
#if !defined(USE_INLINE_STDARG)
IPTR MagicBeacon_GetAttrsTags(APTR handle,APTR beacon,IPTR tag,...);
#endif
IPTR MagicBeacon_GetAttr(APTR handle,APTR beacon,IPTR tag);
IPTR MagicBeacon_BeaconSendTagList(APTR handle,struct TagItem *tags);
#if !defined(USE_INLINE_STDARG)
IPTR MagicBeacon_BeaconSendTags(APTR handle, IPTR tag,...);
#endif
APTR MagicBeacon_BeaconObtain(APTR handle);
void MagicBeacon_BeaconDispose(APTR handle,APTR beacon);


/***************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* CLIB_MAGICBEACON_PROTOS_H */