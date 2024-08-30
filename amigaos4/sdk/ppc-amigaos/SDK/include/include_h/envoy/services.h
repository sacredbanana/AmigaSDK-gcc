#ifndef ENVOY_SERVICES_H
#define ENVOY_SERVICES_H

/*
**    $VER: services.h 54.16 (22.08.2022)
**
**    Public Structures and definitions for services.library
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

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

/*--------------------------------------------------------------------------*/
/*
** Defined tags for FindService()
*/

#define FSVC_Dummy       (TAG_USER + 2048)

#define FSVC_Error       (FSVC_Dummy + 0x02)
#define FSVC_UserName    (FSVC_Dummy + 0x03)
#define FSVC_PassWord    (FSVC_Dummy + 0x04)

/*--------------------------------------------------------------------------*/
/*
** Defined tags for Get/SetServiceAttrsA()
*/

#define SVCAttrs_Dummy   (TAG_USER + 4096)

#define SVCAttrs_Name    (SVCAttrs_Dummy + 0x01) /* Your Service Name */

/* Two tags for internal housekeeping ONLY. */
#define SVCAttrs_Enable  (SVCAttrs_Dummy + 0x02)
#define SVCAttrs_Expunge (SVCAttrs_Dummy + 0x03)

/*--------------------------------------------------------------------------*/
/*
** Defined tags for StartServiceA()
*/

#define SSVC_Dummy       (TAG_USER + 8192)

#define SSVC_UserName    (SSVC_Dummy + 0x01)
#define SSVC_Password    (SSVC_Dummy + 0x02)
#define SSVC_EntityName  (SSVC_Dummy + 0x03)
#define SSVC_HostName    (SSVC_Dummy + 0x04)

/*--------------------------------------------------------------------------*/

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

#endif /* ENVOY_SERVICES_H */
