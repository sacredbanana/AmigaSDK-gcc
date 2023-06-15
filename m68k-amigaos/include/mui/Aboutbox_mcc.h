#ifndef ABOUTBOX_MCC_H
#define ABOUTBOX_MCC_H

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

 $Id: Aboutbox_mcc.h 6700 2020-10-28 16:23:02Z tboeckel $

***************************************************************************/

/*
 * Aboutbox.mcc
 *
 * Aboutbox.mcc was originally developed by Christian Rosentreter for MorphOS.
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

#define MUIC_Aboutbox       "Aboutbox.mcc"
#define AboutboxObject      MUI_NewObject(MUIC_Aboutbox

/***********************************************************************/

#define MUIA_Aboutbox_Credits            0xfed10001    /* [I..] CONST_STRPTR                       */
#define MUIA_Aboutbox_LogoData           0xfed10002    /* [I..] const struct MUI_RawimageData *    */
#define MUIA_Aboutbox_LogoFallbackMode   0xfed10003    /* [I..] ULONG                              */
#define MUIA_Aboutbox_LogoFile           0xfed10004    /* [I..] CONST_STRPTR                       */
#define MUIA_Aboutbox_Build              0xfed1001e    /* [I..] CONST_STRPTR                       */
#define MUIA_Aboutbox_URL                0xfed10021    /* [I..] CONST_STRPTR                       */
#define MUIA_Aboutbox_URLText            0xfed10022    /* [I..] CONST_STRPTR                       */

/***********************************************************************/

/*
 * the fallback mode defines in which order Aboutbox.mcc tries to obtain valid image
 * data for the logo:
 *
 * D = PROGDIR:<program_name>.info
 * E = file specified with MUIA_Aboutbox_LogoFile
 * I = data specified with MUIA_Aboutbox_LogoData
 */
#define MUIV_Aboutbox_LogoFallbackMode_NoLogo     0
#define MUIV_Aboutbox_LogoFallbackMode_Auto       MAKE_ID('D' , 'E' , 'I' , '\0')

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* ABOUTBOX_MCC_H */
