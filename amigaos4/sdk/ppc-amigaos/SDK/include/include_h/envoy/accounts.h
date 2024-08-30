#ifndef ENVOY_ACCOUNTS_H
#define ENVOY_ACCOUNTS_H

/*
**    $VER: accounts.h 54.16 (22.08.2022)
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**          All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

struct UserInfo
{
    TEXT  ui_UserName[32];
    UWORD ui_UserID;
    UWORD ui_PrimaryGroupID;
    ULONG ui_Flags;
};

struct GroupInfo
{
    TEXT  gi_GroupName[32];
    UWORD gi_GroupID;
};

/* Error codes for the security server */

#define ACCERROR_NORESOURCES   100
#define ACCERROR_NOPRIVS       101
#define ACCERROR_NOAUTHORITY   102
#define ACCERROR_UNKNOWNUSER   103
#define ACCERROR_UNKNOWNGROUP  104
#define ACCERROR_LASTUSER      105
#define ACCERROR_LASTGROUP     106
#define ACCERROR_LASTMEMBER    107
#define ACCERROR_GROUPEXISTS   108
#define ACCERROR_NOFREEGROUPS  109
#define ACCERROR_UNKNOWNMEMBER 110

/* Currently Defined Flags for the User Flags data */

#define UFLAGB_AdminName     0 /* Whether or not this User may change his/her own name */
#define UFLAGB_AdminPassword 1 /* Whether or not this User may change his/her own password */
#define UFLAGB_NeedsPassword 2 /* Whether or not a password is required for this user */
#define UFLAGB_AdminGroups   3 /* Whether or not this User may create/delete groups */
#define UFLAGB_AdminAll      4 /* User may do anything he wants. */

#define UFLAGF_AdminName     (1 << UFLAGB_AdminName)
#define UFLAGF_AdminPassword (1 << UFLAGB_AdminPassword)
#define UFLAGF_NeedsPassword (1 << UFLAGB_NeedsPassword)
#define UFLAGF_AdminGroups   (1 << UFLAGB_AdminGroups)
#define UFLAGF_AdminAll      (1 << UFLAGB_AdminAll)

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* ENVOY_ACCOUNTS_H */
