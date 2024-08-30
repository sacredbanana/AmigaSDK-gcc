#ifndef GIFANIM_MCC_H
#define GIFANIM_MCC_H

/***************************************************************************

 Magic User Interface - MUI
 Copyright (C) 1992-2006 by Stefan Stuntz <stefan@stuntz.com>
 Copyright (C) 2006-2021 by Thore Boeckelmann, Jens Maus
 All Rights Reserved.

 This program/documents may not in whole or in part, be copied, photocopied
 reproduced, translated or reduced to any electronic medium or machine
 readable form without prior consent, in writing, from the above authors.

 With this document the authors makes no warrenties or representations,
 either expressed or implied, with respect to MUI. The information
 presented herein is being supplied on an "AS IS" basis and is expressly
 subject to change without notice. The entire risk as to the use of this
 information is assumed by the user.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 IN NO EVENT WILL THE AUTHORS BE LIABLE FOR DIRECT, INDIRECT, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES RESULTING FROM ANY CLAIM ARISING OUT OF THE
 INFORMATION PRESENTED HEREIN, EVEN IF IT HAS BEEN ADVISED OF THE
 POSSIBILITIES OF SUCH DAMAGES.

 MUI Official Support Site:  http://www.sasg.com/

 $Id$

***************************************************************************/

/*
 * GIFAnim.mcc
 *
 * GIFAnim.mcc was originally developed by Anfonso Ranieri.
 * This is an AmigaOS native reimplementation included in MUI for AmigaOS for convenience.
 */

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack(2)
  #elif defined(__VBCC__)
    #pragma amiga-align
  #endif
#endif

/***********************************************************************/

#define MUIC_GIFAnim        "GIFAnim.mcc"
#define GIFAnimObject       MUI_NewObject(MUIC_GIFAnim

/***********************************************************************/

#define MUIA_GIFAnim_File               0xfec90116 /* [I..]  CONST_STRPTR         */
#define MUIA_GIFAnim_Anim               0xfec90117 /* [I.G]  BOOL                 */
#define MUIA_GIFAnim_Decoded            0xfec90118 /* [..G]  BOOL                 */
#define MUIA_GIFAnim_Fallback           0xfec90119 /* [I..]  BOOL                 */
#define MUIA_GIFAnim_Transparent        0xfec9011a /* [IS.]  BOOL                 */
#define MUIA_GIFAnim_Pics               0xfec9011b /* [..G]  LONG                 */
#define MUIA_GIFAnim_Current            0xfec9011c /* [ISG]  ULONG                */
#define MUIA_GIFAnim_Invalid            0xfec9011e /* [..G]  BOOL                 */
#define MUIA_GIFAnim_Sync               0xfec90120 /* [I..]  BOOL                 */
#define MUIA_GIFAnim_Data               0xfec90121 /* [I..]  CONST_APTR           */
#define MUIA_GIFAnim_DataSize           0xfec90122 /* [I..]  ULONG                */
#define MUIA_GIFAnim_Scale              0xfec90123 /* [I..]  ULONG                */
#define MUIA_GIFAnim_Precision          0xfec90124 /* [I..]  ULONG                */

/***********************************************************************/

#define MUIM_GIFAnim_Play               0xfec90116
#define MUIM_GIFAnim_Next               0xfec90117
#define MUIM_GIFAnim_Pred               0xfec90118
#define MUIM_GIFAnim_First              0xfec90119
#define MUIM_GIFAnim_Last               0xfec9011a

struct MUIP_GIFAnim_Play
{
    ULONG MethodID;
    ULONG flags;
};

/***********************************************************************/

#define MUIV_GIFAnim_Play_Off           (0)
#define MUIV_GIFAnim_Play_On            (1<<0)
#define MUIV_GIFAnim_Play_Rewind        (MUIV_GIFAnim_Play_On|(1<<1))
#define MUIV_GIFAnim_Play_Once          (MUIV_GIFAnim_Play_On|(1<<2))

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* GIFANIM_MCC_H */
