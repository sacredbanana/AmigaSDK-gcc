#ifndef CALLTIPS_MCC_H
#define CALLTIPS_MCC_H

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
 * Calltips.mcc
 *
 * Calltips.mcc was originally developed by Jacek Piszczek for MorphOS.
 * This is an AmigaOS native reimplementation included in MUI for AmigaOS for convenience.
 *
 * See NewStuff demo source for details.
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

#define MUIC_Calltips       "Calltips.mcc"
#define CalltipsObject      MUI_NewObject(MUIC_Calltips

/***********************************************************************/

#define MUIM_Calltips_SetRectangle         0xfecf1004
#define MUIM_Calltips_ParentSetup          0xfecf1005
#define MUIM_Calltips_ParentCleanup        0xfecf1006
#define MUIM_Calltips_ParentShow           0xfecf1007
#define MUIM_Calltips_ParentHide           0xfecf1008
#define MUIM_Calltips_ParentWindowArranged 0xfecf1009

struct MUIP_Calltips_SetRectangle
{
    ULONG MethodID;
    LONG MinX;
    LONG MinY;
    LONG MaxX;
    LONG MaxY;
};

/***********************************************************************/

#define MUIA_Calltips_Rectangle  0xfecf1004
#define MUIA_Calltips_Layout     0xfecf1005
#define MUIA_Calltips_Source     0xfecf1006
#define MUIA_Calltips_MarginLeft 0xfecf1008
#define MUIA_Calltips_MarginTop  0xfecf1009

/***********************************************************************/

#define MUIV_Calltips_Layout_Exact          0
#define MUIV_Calltips_Layout_RightThenBelow 1 /* not yet implemented */
#define MUIV_Calltips_Layout_BelowThenAbove 2 /* not yet implemented */

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* CALLTIPS_MCC_H */
