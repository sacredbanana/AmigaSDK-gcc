#ifndef DOS_EXALL_H
#define DOS_EXALL_H
/*
**    $VER: exall.h  54.100 (07.09.2020)
**
**    Include file for obsolete ExAll() data structures
**
**    (C) Copyright 1989-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/
/****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   UTILITY_HOOKS_H
#include <utility/hooks.h>
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

/****************************************************************************
 * The ExAll() function and associated structures have been deprecated for V50.
 * Use ExamineDir()/ExamineObject() from V50 onwards.
 ****************************************************************************/

/*
 *   Structure in which exall results are returned in. 
 *   Note that only the fields asked for will exist!
 */
struct ExAllData
{
    struct ExAllData *ed_Next;
    STRPTR            ed_Name;
    int32             ed_Type;
    uint32            ed_Size;     /* NB: only works up to 4gig */
    uint32            ed_Prot;
    uint32            ed_Days;
    uint32            ed_Mins;
    uint32            ed_Ticks;
    STRPTR            ed_Comment;  /* strings will be after last used field */
    uint16            ed_OwnerUID; /* new for V39 */
    uint16            ed_OwnerGID;
};



/*
 *   Control structure passed to ExAll.  Unused fields MUST be initialized 
 *   to 0, expecially eac_LastKey.
 *   eac_MatchFunc is a hook (see utility.library documentation for usage)
 *   It should return true if the entry is to returned, false if it is to be
 *   ignored.
 *   This structure MUST be allocated by AllocDosObject()!
 */
struct ExAllControl
{
    uint32       eac_Entries;     /* number of entries returned in buffer */
    uint32       eac_LastKey;     /* Don't touch inbetween linked ExAll calls! */
    STRPTR       eac_MatchString; /* wildcard string for pattern match or NULL */
    struct Hook *eac_MatchFunc;   /* optional private wildcard function */
};


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
#endif  /* DOS_EXALL_H */
/****************************************************************************/





