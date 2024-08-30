#ifndef CLOCK_MCC_H
#define CLOCK_MCC_H

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
 * Clock.mcc
 *
 * Clock.mcc was originally developed by Michal Rybinski for MorphOS.
 * This is an AmigaOS native reimplementation included in MUI for AmigaOS for convenience.
*/

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif
#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack(2)
  #elif defined(__VBCC__)
    #pragma amiga-align
  #endif
#endif

/***********************************************************************/

#define MUIC_Clock          "Clock.mcc"
#define ClockObject         MUI_NewObject(MUIC_Clock

/***********************************************************************/

#define	MUIA_Clock_Hour                    0xfecd0030 /* [.SG] LONG  */
#define	MUIA_Clock_Minute                  0xfecd0031 /* [.SG] LONG  */
#define	MUIA_Clock_Second                  0xfecd0032 /* [.SG] LONG  */
/* set a MUIV_Everytime notification to hear about a wrap to next day (hour = 0) */
#define MUIA_Clock_Wrapped                 0xfecd0033 /* [..G] BOOL  */

/***********************************************************************/

#define MUIM_Clock_OffsetFromTime          0xfecd0070

struct MUIP_Clock_OffsetFromTime
{
    ULONG MethodID;
    LONG hour;
    LONG min;
    LONG sec;
};

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* CLOCK_MCC_H */
