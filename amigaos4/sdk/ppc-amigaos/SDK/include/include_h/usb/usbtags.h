#ifndef USB_USBTAGS_H
#define USB_USBTAGS_H

/*
** $VER: usbtags.h 53.29 (10.8.2015)
**
** Defines tag items for various functions
**
** Copyright (c) 2001, Thomas Graff Thoeger
** Distributed by Hyperion Entertainment CVBA under permission.
*/

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

/* 
** Tag items used by USBAllocObject
*/

#define UAOT_ErrorCode			(TAG_USER +   1) /* (uint32 *) Pointer to store Error code on error */

/* USBIOReq */
#define UAOTIOR_IORequest		(TAG_USER + 101) /* Source to Opener IORequest */
#define UAOTIOR_ReplyPort		(TAG_USER + 102) /* ReplyPort to use */
#define UAOTIOR_TimeOut			(TAG_USER + 103) /* TimeOut is specified in milliseconds. */
#define UAOTIOR_Repeat			(TAG_USER + 104) /* If the request is used for Pulling an EndPoint */

/****************************************************************************/

/*
 * Object types for USBAllocObject
 */
enum enUSBAllocObjectTypes
{
	UAOT_USBIOREQUEST =  0,		/* USBIOReq */
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* USB_USBTAGS_H */
