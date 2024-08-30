#ifndef LAYGROUP_MCC_H
#define LAYGROUP_MCC_H

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
 * LayGroup.mcc
 *
 * LayGroup.mcc was originally developed by Alessandro Zummo and continued by LayGroup.mcc Open Source Team.
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

#define MUIC_LayGroup       "LayGroup.mcc"
#define LayGroupObject      MUI_NewObject(MUIC_LayGroup

/***********************************************************************/

#define MUIA_LayGroup_ChildNumber           0xa5530001 /* [..G]  ULONG  */
#define MUIA_LayGroup_MaxHeight             0xa5530002 /* [I..]  LONG   */ /* OBSOLETE */
#define MUIA_LayGroup_MaxWidth              0xa5530003 /* [I..]  LONG   */ /* OBSOLETE */
#define MUIA_LayGroup_HorizSpacing          0xa5530004 /* [ISG]  LONG   */
#define MUIA_LayGroup_VertSpacing           0xa5530005 /* [ISG]  LONG   */
#define MUIA_LayGroup_Spacing               0xa5530006 /* [IS.]  LONG   */
#define MUIA_LayGroup_LeftOffset            0xa5530007 /* [ISG]  LONG   */
#define MUIA_LayGroup_TopOffset             0xa5530008 /* [ISG]  LONG   */
#define MUIA_LayGroup_AskLayout             0xa5530009 /* [I..]  BOOL   */
#define MUIA_LayGroup_NumberOfColumns       0xa553000a /* [..G]  ULONG  */
#define MUIA_LayGroup_NumberOfRows          0xa553000b /* [..G]  ULONG  */
#define MUIA_LayGroup_InheritBackground     0xa553000c /* [I..]  BOOL   */
#define MUIA_LayGroup_Selection             0xa553000d /* [I..]  ULONG  */

#define MUIV_LayGroup_Spacing_Default       4
#define MUIV_LayGroup_Spacing_Minimum       0
#define MUIV_LayGroup_Spacing_Maximum       24

#define MUIV_LayGroup_LeftOffset_Default    0
#define MUIV_LayGroup_LeftOffset_Minimum    0
#define MUIV_LayGroup_LeftOffset_Maximum    32
#define MUIV_LayGroup_LeftOffset_Center     -1

#define MUIV_LayGroup_TopOffset_Default     0
#define MUIV_LayGroup_TopOffset_Minimum     0
#define MUIV_LayGroup_TopOffset_Maximum     32
#define MUIV_LayGroup_TopOffset_Center      -1

#define MUIV_LayGroup_Selection_None        0
#define MUIV_LayGroup_Selection_Immediate   1
#define MUIV_LayGroup_Selection_Immediat    MUIV_LayGroup_Selection_Immediate

/***********************************************************************/

#define MUIM_LayGroup_AskLayout             0xa5530101

struct MUIP_LayGroup_AskLayout
{
    ULONG MethodID;
    struct MUI_LayGroup_Layout *lgl;
};

// Values for MUIM_LayGroup_AskLayout
#define MUIV_LayGroup_MaxHeight_Auto        -1
#define MUIV_LayGroup_MaxWidth_Auto         -1

// Structure for object in layout
struct MUI_LayGroup_Layout
{
   Object *lgl_Object;
   UWORD   lgl_Height;
   UWORD   lgl_Width;
};

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* LAYGROUP_MCC_H */

