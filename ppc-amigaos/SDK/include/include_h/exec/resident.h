#ifndef EXEC_RESIDENT_H
#define EXEC_RESIDENT_H
/*
**    $VER: resident.h 53.29 (10.8.2015)
**
**    Resident/ROMTag stuff.  Used to identify and initialize code modules.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
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

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

struct Resident
{
    uint16            rt_MatchWord; /* word to match on (ILLEGAL) */
    struct Resident * rt_MatchTag;  /* pointer to the above */
    APTR              rt_EndSkip;   /* address to continue scan */
    uint8             rt_Flags;     /* various tag flags */
    uint8             rt_Version;   /* release version number */
    uint8             rt_Type;      /* type of module (NT_XXXXXX) */
    int8              rt_Pri;       /* initialization priority */
    CONST_STRPTR      rt_Name;      /* pointer to node name */
    CONST_STRPTR      rt_IdString;  /* pointer to identification string */
    APTR              rt_Init;      /* pointer to init code */
};

#define RTC_MATCHWORD 0x4AFC /* The 68000 "ILLEGAL" instruction */

enum enResidentFlags
{
    RTF_AUTOINIT   = (1<<7), /* rt_Init points to data structure */
    RTF_NATIVE     = (1<<5), /* rt_Init points to a native function
                              * (otherwise, 68k is assumed) */
    RTF_AFTERDOS   = (1<<2),
    RTF_SINGLETASK = (1<<1),
    RTF_COLDSTART  = (1<<0)
};

/* Compatibility: (obsolete) */
/* THF: Note: Removed all of them. They shouldn't be in active use anymore */
/* #define RTM_WHEN      3 */
/* #define RTW_NEVER     0 */
/* #define RTW_COLDSTART 1 */

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

#endif /* EXEC_RESIDENT_H */
