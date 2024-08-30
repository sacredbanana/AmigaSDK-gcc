#ifndef LAMP_MCC_H
#define LAMP_MCC_H

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

 $Id: Lamp_mcc.h 6513 2020-01-02 05:36:08Z tboeckel $

***************************************************************************/

/*
 * Lamp.mcc
 *
 * Lamp.mcc was originally developed by Maik Schreiber.
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

#define MUIC_Lamp           "Lamp.mcc"
#define LampObject          MUI_NewObject(MUIC_Lamp

/***********************************************************************/

#define MUIA_Lamp_Type                  0x85b90001 /* [ISG]  ULONG                */
#define MUIA_Lamp_Color                 0x85b90002 /* [ISG]  ULONG *              */
#define MUIA_Lamp_ColorType             0x85b90003 /* [ISG]  ULONG                */
#define MUIA_Lamp_Red                   0x85b90004 /* [ISG]  ULONG                */
#define MUIA_Lamp_Green                 0x85b90005 /* [ISG]  ULONG                */
#define MUIA_Lamp_Blue                  0x85b90006 /* [ISG]  ULONG                */
#define MUIA_Lamp_PenSpec               0x85b90007 /* [ISG]  struct MUI_PenSpec * */

/***********************************************************************/

#define MUIM_Lamp_SetRGB                0x85b90008

struct MUIP_Lamp_SetRGB
{
    ULONG methodid;
    ULONG red;
    ULONG green;
    ULONG blue;
};

/***********************************************************************/

#define MUIV_Lamp_Type_Tiny             0
#define MUIV_Lamp_Type_Small            1
#define MUIV_Lamp_Type_Medium           2
#define MUIV_Lamp_Type_Big              3
#define MUIV_Lamp_Type_Huge             4
#define MUIV_Lamp_Type_Mammoth          5
#define MUIV_Lamp_Type_Gigantic         6
#define MUIV_Lamp_Type_Size(pixels)     ((pixels < 5) ? 0 : (pixels - 5))

#define MUIV_Lamp_ColorType_UserDefined 0
#define MUIV_Lamp_ColorType_Color       1
#define MUIV_Lamp_ColorType_PenSpec     2
#define MUIV_Lamp_ColorType_Transparent 3

#define MUIV_Lamp_Color_Off             0
#define MUIV_Lamp_Color_Ok              1
#define MUIV_Lamp_Color_Warning         2
#define MUIV_Lamp_Color_Error           3
#define MUIV_Lamp_Color_FatalError      4
#define MUIV_Lamp_Color_Processing      5
#define MUIV_Lamp_Color_LookingUp       6
#define MUIV_Lamp_Color_Connecting      7
#define MUIV_Lamp_Color_SendingData     8
#define MUIV_Lamp_Color_ReceivingData   9
#define MUIV_Lamp_Color_LoadingData     10
#define MUIV_Lamp_Color_SavingData      11

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* LAMP_MCC_H */
