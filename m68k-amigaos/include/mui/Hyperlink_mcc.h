#ifndef HYPERLINK_MCC_H
#define HYPERLINK_MCC_H

/***************************************************************************

 Magic User Interface - MUI
 Copyright (C) 1992-2006 by Stefan Stuntz <stefan@stuntz.com>
 Copyright (C) 2006-2020 by Thore Boeckelmann, Jens Maus
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

 $Id: Hyperlink_mcc.h 6513 2020-01-02 05:36:08Z tboeckel $

***************************************************************************/

/*
 * Hyperlink.mcc
 *
 * Hyperlink.mcc was originally developed by Christian Rosentreter.
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

#define MUIC_Hyperlink      "Hyperlink.mcc"
#define HyperlinkObject     MUI_NewObject(MUIC_Hyperlink

/***********************************************************************/

#define MUIA_Hyperlink_URI              0xfed10033 /* [ISG]  STRPTR  */
#define MUIA_Hyperlink_HoverTip         0xfed10036 /* [..G]  STRPTR  */

#define MUIA_Hyperlink_Text             MUIA_Text_Contents
#define MUIA_Hyperlink_SetMax           MUIA_Text_SetMax

/***********************************************************************/

#define MUIM_Hyperlink_Follow           0xfed10034
#define MUIM_Hyperlink_Copy             0xfed10035
#define MUIM_Hyperlink_Encode           0xfed10037
#define MUIM_Hyperlink_Decode           0xfed10038

struct MUIP_Hyperlink_Follow
{
	ULONG MethodID;
};

struct MUIP_Hyperlink_Copy
{
	ULONG MethodID;
	ULONG unit;
};

struct MUIP_Hyperlink_Encode
{
	ULONG MethodID;
	CONST_STRPTR input;
	STRPTR output;
};

struct MUIP_Hyperlink_Decode
{
	ULONG  MethodID;
	CONST_STRPTR input;
	STRPTR output;
};

/***********************************************************************/

#define MUIV_Hyperlink_Encode_Count     (NULL)

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* HYPERLINK_MCC_H */
