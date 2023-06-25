#ifndef ENVOY_ENVOY_H
#define ENVOY_ENVOY_H

/*
**    $VER: envoy.h 54.16 (22.08.2022)
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**          All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   ENVOY_NIPC_H
#include <envoy/nipc.h>
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

#define HREQ_Dummy         (TAG_USER + 0xB1300)
#define HREQ_Buffer        (HREQ_Dummy + 1)
#define HREQ_BuffSize      (HREQ_Dummy + 2)
#define HREQ_Left          (HREQ_Dummy + 3)
#define HREQ_Top           (HREQ_Dummy + 4)
#define HREQ_Width         (HREQ_Dummy + 5)
#define HREQ_Height        (HREQ_Dummy + 6)
#define HREQ_DefaultRealm  (HREQ_Dummy + 7)
#define HREQ_NoRealms      (HREQ_Dummy + 8)
#define HREQ_Screen        (HREQ_Dummy + 9)
#define HREQ_Title         (HREQ_Dummy + 10)
#define HREQ_NoResizer     (HREQ_Dummy + 11)
#define HREQ_NoDragBar     (HREQ_Dummy + 12)

#define LREQ_Dummy         (TAG_USER + 0xB1400)
#define LREQ_NameBuff      (LREQ_Dummy + 1)
#define LREQ_NameBuffLen   (LREQ_Dummy + 2)
#define LREQ_PassBuff      (LREQ_Dummy + 3)
#define LREQ_PassBuffLen   (LREQ_Dummy + 4)
#define LREQ_Left          (LREQ_Dummy + 5)
#define LREQ_Top           (LREQ_Dummy + 6)
#define LREQ_Width         (LREQ_Dummy + 7)
#define LREQ_Height        (LREQ_Dummy + 8)
#define LREQ_Screen        (LREQ_Dummy + 9)
#define LREQ_Title         (LREQ_Dummy + 10)
#define LREQ_NoDragBar     (LREQ_Dummy + 11)
#define LREQ_Window        (LREQ_Dummy + 12)
#define LREQ_CallBack      (LREQ_Dummy + 13)
#define LREQ_MsgPort       (LREQ_Dummy + 14)
#define LREQ_NoSizeGadget  (LREQ_Dummy + 15)
#define LREQ_OptimWindow   (LREQ_Dummy + 16)
#define LREQ_UserName      (LREQ_Dummy + 17)
#define LREQ_Password      (LREQ_Dummy + 18)

#define UGREQ_Dummy        (TAG_USER + 0xB1400)
#define UGREQ_UserBuff     (UGREQ_Dummy + 1)
#define UGREQ_UserBuffLen  (UGREQ_Dummy + 2)
#define UGREQ_GroupBuff    (UGREQ_Dummy + 3)
#define UGREQ_GroupBuffLen (UGREQ_Dummy + 4)
#define UGREQ_Left         (UGREQ_Dummy + 5)
#define UGREQ_Top          (UGREQ_Dummy + 6)
#define UGREQ_Width        (UGREQ_Dummy + 7)
#define UGREQ_Height       (UGREQ_Dummy + 8)
#define UGREQ_Screen       (UGREQ_Dummy + 9)
#define UGREQ_Title        (UGREQ_Dummy + 10)
#define UGREQ_NoDragBar    (UGREQ_Dummy + 11)
#define UGREQ_Window       (UGREQ_Dummy + 12)
#define UGREQ_CallBack     (UGREQ_Dummy + 13)
#define UGREQ_MsgPort      (UGREQ_Dummy + 14)
#define UGREQ_NoSizeGadget (UGREQ_Dummy + 15)
#define UGREQ_UserList     (UGREQ_Dummy + 16)
#define UGREQ_GroupList    (UGREQ_Dummy + 17)

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

#endif
