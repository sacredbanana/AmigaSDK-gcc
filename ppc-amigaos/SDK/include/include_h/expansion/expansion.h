#ifndef EXPANSION_EXPANSION_H
#define EXPANSION_EXPANSION_H
/*
**    $VER: expansion.h 53.29 (10.8.2015)
**
**    External definitions for expansion.library
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

#define EXPANSIONNAME "expansion.library"

/****************************************************************************/

/* flags for the AddDosNode() call */
enum enADNBits
{
    ADNB_STARTPROC = 0
};

enum enADNFlags
{
    ADNF_STARTPROC = (1<<ADNB_STARTPROC)
};

/****************************************************************************/

/* Tag items for GetMachineInfo() */
#define GMIT_Machine       (TAG_USER + 1)
#define GMIT_MachineString (TAG_USER + 2)
#define GMIT_MemorySize    (TAG_USER + 3)
#define GMIT_Extensions    (TAG_USER + 4)

/* Machine type codes */
enum enMachineModel
{
    MACHINETYPE_UNKNOWN       = 0,
    MACHINETYPE_BLIZZARDPPC   = 1,
    MACHINETYPE_CYBERSTORMPPC = 2,
    MACHINETYPE_AMIGAONE      = 3,
    MACHINETYPE_SAM440	      = 4,
    MACHINETYPE_PEGASOS2      = 5,
    MACHINETYPE_X1000		  = 6,
    MACHINETYPE_SAM460		  = 7,
    MACHINETYPE_CHUNYE		  = 8,	/* Code name, subject to change */
    MACHINETYPE_X5000_20	  = 9,
    MACHINETYPE_X5000_40	  = 10
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXPANSION_EXPANSION_H */
