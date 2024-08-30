#ifndef NEWSTRING_MCC_H
#define NEWSTRING_MCC_H

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
 * Newstring.mcc
 *
 * Newstring.mcc was originally developed by Rüdiger Sopp and Mikolaj Calusinski.
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

#define MUIC_Newstring      "Newstring.mcc"
#define NewstringObject     MUI_NewObject(MUIC_Newstring

/***********************************************************************/

#define MUIA_Newstring_EditHook            0x81cd0001 /* [I..]  struct Hook *        */
#define MUIA_Newstring_WordSeparators      0x81cd0002 /* [ISG]  STRPTR               */
#define MUIA_Newstring_StartPos            0x81cd0025 /* [.SG]  ULONG                */
#define MUIA_Newstring_Version             0x81cd0026 /* [..G]  CONST_STRPTR         */ /* used by old 68k Newstring.mcp only */
#define MUIA_Newstring_Copyright           0x81cd0027 /* [..G]  CONST_STRPTR         */ /* used by old 68k Newstring.mcp only */

/***********************************************************************/

#define MUIV_Newstring_EditHook_None    0
#define MUIV_Newstring_EditHook_Integer -1
#define MUIV_Newstring_EditHook_Float   -2

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* NEWSTRING_MCC_H */
