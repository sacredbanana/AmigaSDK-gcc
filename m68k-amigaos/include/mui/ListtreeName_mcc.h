#ifndef LISTTREENAME_MCC_H
#define LISTTREENAME_MCC_H

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

 $Id: ListtreeName_mcc.h 6513 2020-01-02 05:36:08Z tboeckel $

***************************************************************************/

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

#define MUIC_ListtreeName   "ListtreeName.mcc"
#define ListtreeNameObject  MUI_NewObject(MUIC_ListtreeName

/***********************************************************************/

#define MUIM_ListtreeName_Insert         0x80020022

struct MUIP_ListtreeName_Insert
{
	ULONG MethodID;
	char *SplitName;
	APTR  User;
};

/***********************************************************************/

#define MUIA_ListtreeName_MaxSplits      0x80020024
#define MUIA_ListtreeName_MinSplits      0x80020025
#define MUIA_ListtreeName_NotSplits      0x80020026
#define MUIA_ListtreeName_ShowSplitChars 0x80020027
#define MUIA_ListtreeName_SortLists      0x80020028
#define MUIA_ListtreeName_SplitChars     0x80020021

/*** Special attribute values ***/

#define MUIV_ListtreeName_SortLists_Sorted       0
#define MUIV_ListtreeName_SortLists_Begin        1
#define MUIV_ListtreeName_SortLists_End          2

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* LISTTREENAME_MCC_H */
