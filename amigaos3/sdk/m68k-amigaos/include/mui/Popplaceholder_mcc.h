#ifndef POPPLACEHOLDER_MCC_H
#define POPPLACEHOLDER_MCC_H

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

 $Id: Popplaceholder_mcc.h 6513 2020-01-02 05:36:08Z tboeckel $

***************************************************************************/

/*
 * Popplaceholder.mcc
 *
 * Popplaceholder.mcc was originally developed by Marcin Orlowski for AmigaOS.
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

#define MUIC_Popplaceholder  "Popplaceholder.mcc"
#define PopplaceholderObject MUI_NewObject(MUIC_Popplaceholder

#define MUIC_Popph           "Popplaceholder.mcc"
#define PopphObject          MUI_NewObject(MUIC_Popph

/***********************************************************************/

#define MUIA_Popph_Array                0x898f0010 /* [IS.]  STRPTR *             */
#define MUIA_Popph_Separator            0x898f0011 /* [ISG]  char                 */
#define MUIA_Popph_Contents             0x898f0012 /* [ISG]  STRPTR               */
#define MUIA_Popph_StringKey            0x898f0013 /* [IS.]  char                 */
#define MUIA_Popph_PopbuttonKey         0x898f0014 /* [IS.]  char                 */
#define MUIA_Popph_StringMaxLen         0x898f0015 /* [I..]  ULONG                */
#define MUIA_Popph_CopyEntries          0x898f0016 /* [ISG]  BOOL                 */
#define MUIA_Popph_PopAsl               0x898f0017 /* [I..]  BOOL                 */
#define MUIA_Popph_AslActive            0x898f0018 /* [..G]  ULONG                */
#define MUIA_Popph_AslType              0x898f0019 /* [I..]  ULONG                */
#define MUIA_Popph_Avoid                0x898f001a /* [I..]  ULONG                */
#define MUIA_Popph_StringType           0x898f001b /* [..G]  ULONG                */
#define MUIA_Popph_ReplaceMode          0x898f001c /* [ISG]  BOOL                 */
#define MUIA_Popph_StringObject         0x898f001d /* [..G]  Object *             */
#define MUIA_Popph_ListObject           0x898f001e /* [..G]  Object *             */
#define MUIA_Popph_ContextMenu          0x898f0022 /* [ISG]  BOOL                 */
#define MUIA_Popph_PopCycleChain        0x898f0023 /* [ISG]  BOOL                 */
#define MUIA_Popph_Title                0x898f0024 /* [IS.]  STRPTR               */
#define MUIA_Popph_SingleColumn         0x898f0025 /* [ISG]  BOOL                 */
#define MUIA_Popph_AutoClose            0x898f0026 /* [ISG]  BOOL                 */
#define MUIA_Popph_InsertMode           0x898f0027 /* [ISG]  ULONG                */

#define MUIV_Popph_StringType_String        0
#define MUIV_Popph_StringType_Betterstring  1
#define MUIV_Popph_StringType_Textinput     2

#define MUIV_Popph_Avoid_Betterstring       (1<<0)
#define MUIV_Popph_Avoid_Textinput          (1<<1)
#define MUIV_Popph_Avoid_Nlist              (1<<2) /* not yet implemented */

#define MUIV_Popph_InsertMode_DD_Default    (1<<0)
#define MUIV_Popph_InsertMode_DD_CursorPos  (1<<1)
#define MUIV_Popph_InsertMode_DD_Append     (1<<2)
#define MUIV_Popph_InsertMode_DD_Apend      (1<<2) /* for compatibility to old sources */
#define MUIV_Popph_InsertMode_DD_Prepend    (1<<3)
#define MUIV_Popph_InsertMode_DC_Default    (1<<4)
#define MUIV_Popph_InsertMode_DC_CursorPos  (1<<5)
#define MUIV_Popph_InsertMode_DC_Append     (1<<6) /* for compatibility to old sources */
#define MUIV_Popph_InsertMode_DC_Apend      (1<<6)
#define MUIV_Popph_InsertMode_DC_Prepend    (1<<7)

#define MUIV_Popph_InsertMode_Default       (MUIV_Popph_InsertMode_DD_Default   | MUIV_Popph_InsertMode_DC_Default)
#define MUIV_Popph_InsertMode_CursorPos     (MUIV_Popph_InsertMode_DD_CursorPos | MUIV_Popph_InsertMode_DC_CursorPos)
#define MUIV_Popph_InsertMode_Append        (MUIV_Popph_InsertMode_DD_Append    | MUIV_Popph_InsertMode_DC_Append)
#define MUIV_Popph_InsertMode_Apend         MUIV_Popph_InsertMode_Append /* for compatibility to old sources */
#define MUIV_Popph_InsertMode_Prepend       (MUIV_Popph_InsertMode_DD_Prepend   | MUIV_Popph_InsertMode_DC_Prepend)

/***********************************************************************/

#define MUIM_Popph_DoCut                0x898f0001
#define MUIM_Popph_DoCopy               0x898f0002
#define MUIM_Popph_DoPaste              0x898f0003
#define MUIM_Popph_DoClear              0x898f0004

/***********************************************************************/

#define POPPH_MAX_KEY_LEN       50       /* touch this and die! */
#define POPPH_MAX_STRING_LEN   128       /* touch this and die! */

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* POPPLACEHOLDER_MCC_H */
