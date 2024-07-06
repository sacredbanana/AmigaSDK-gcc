#ifndef URLTEXT_MCC_H
#define URLTEXT_MCC_H

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
 * Urltext.mcc
 *
 * Urltext.mcc was originally developed by Alfonso Ranieri.
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

#ifdef USE_HYPERLINK_MCC

#ifndef HYPERLINK_MCC_H
#include <mui/Hyperlink_mcc.h>
#endif

/***********************************************************************/

#define MUIC_Urltext        MUIC_Hyperlink
#define UrltextObject       MUI_NewObject(MUIC_Urltext

/***********************************************************************/

#define MUIA_Urltext_Url            MUIA_Hyperlink_URI
#define MUIA_Urltext_Text           MUIA_Text_Contents
#define MUIA_Urltext_SetMax         MUIA_Text_SetMax
#define MUIA_Urltext_Active         TAG_IGNORE /* obsolete */
#define MUIA_Urltext_Visited        TAG_IGNORE /* obsolete */
#define MUIA_Urltext_Underline      TAG_IGNORE /* obsolete */
#define MUIA_Urltext_FallBack       TAG_IGNORE /* obsolete */
#define MUIA_Urltext_DoVisitedPen   TAG_IGNORE /* obsolete */
#define MUIA_Urltext_DoOpenURL      TAG_IGNORE /* obsolete */
/* Overload MUIM_Urltext_OpenURL or kill notify on MUIA_Pressed, FALSE */
#define MUIA_Urltext_NoMenu         TAG_IGNORE /* obsolete */
/* Simply pass MUIA_ContextMenu, NULL  or provide your own context menu */
#define MUIA_Urltext_NoOpenURLPrefs TAG_IGNORE /* obsolete */

/***********************************************************************/

#define MUIM_Urltext_OpenURL        MUIM_Hyperlink_Follow
#define MUIM_Urltext_Copy           MUIM_Hyperlink_Copy

struct MUIP_Urltext_OpenURL
{
    ULONG   MethodID;
    ULONG   obsolete;
};

struct MUIP_Urltext_Copy
{
    ULONG   MethodID;
    ULONG   unit;
};

/***********************************************************************/

#else //  USE_HYPERLINK_MCC

/***********************************************************************/

#define MUIC_Urltext        "Urltext.mcc"
#define UrltextObject       MUI_NewObject(MUIC_Urltext

/***********************************************************************/

#define MUIA_Urltext_Url            0xfec900d0 /* [ISGN] (CONST_STRPTR) */
#define MUIA_Urltext_Text           0xfec900d1 /* [ISG.] (CONST_STRPTR) */
#define MUIA_Urltext_Active         0xfec900d2 /* [..G.] (BOOL)         */
#define MUIA_Urltext_Visited        0xfec900d3 /* [..GN] (BOOL)         */
#define MUIA_Urltext_Underline      0xfec900d4 /* [I...] (BOOL)         */
#define MUIA_Urltext_FallBack       0xfec900d5 /* [I...] (BOOL)         */
#define MUIA_Urltext_DoVisitedPen   0xfec900d6 /* [I...] (BOOL)         */
#define MUIA_Urltext_SetMax         0xfec900d7 /* [I...] (BOOL)         */
#define MUIA_Urltext_DoOpenURL      0xfec900d8 /* [I...] (BOOL)         */
#define MUIA_Urltext_NoMenu         0xfec900d9 /* [I...] (BOOL)         */
#define MUIA_Urltext_NoOpenURLPrefs 0xfec900dc /* [I...] (BOOL)         */

/***********************************************************************/

#define MUIM_Urltext_OpenURL        0xfec900c9
#define MUIM_Urltext_Copy           0xfec900ca

struct MUIP_Urltext_OpenURL
{
    ULONG   MethodID;
    ULONG   flags;      /* private, set to 0 */
};

struct MUIP_Urltext_Copy
{
    ULONG   MethodID;
    ULONG   unit;
};

/***********************************************************************/

#endif // USE_HYPERLINK_MCC

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* URLTEXT_MCC_H */
