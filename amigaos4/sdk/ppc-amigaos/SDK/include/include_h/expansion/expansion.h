#ifndef EXPANSION_EXPANSION_H
#define EXPANSION_EXPANSION_H
/*
** External definitions for expansion.library
**
** Copyright 2003-2018,2022 Trevor Dickinson.
*/

#include <utility/tagitem.h>

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
    ADNF_STARTPROC = (1 << ADNB_STARTPROC)
};

/****************************************************************************/

/* Tag items for GetMachineInfo() */
#define GMIT_Machine             (TAG_USER + 1)
#define GMIT_MachineString       (TAG_USER + 2)
#define GMIT_MemoryAvailable     (TAG_USER + 3)
#define GMIT_MemorySize          GMIT_MemoryAvailable  // Deprecated alias
#define GMIT_Extensions          (TAG_USER + 4)
#define GMIT_TotalPhysicalMemory (TAG_USER + 5)

/* Machine type codes */
enum enMachineModel
{
    MACHINETYPE_UNKNOWN       = 0,
    MACHINETYPE_BLIZZARDPPC   = 1,
    MACHINETYPE_CYBERSTORMPPC = 2,
    MACHINETYPE_AMIGAONE      = 3,
    MACHINETYPE_SAM440	      = 4,
    MACHINETYPE_PEGASOS2      = 5,
    MACHINETYPE_X1000         = 6,
    MACHINETYPE_SAM460        = 7,
    MACHINETYPE_CHUNYE        = 8,     /* Code name, subject to change */
    MACHINETYPE_X5000_20      = 9,
    MACHINETYPE_X5000_40      = 10,
    MACHINETYPE_A1222         = 11
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
