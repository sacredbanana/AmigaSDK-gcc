#ifndef DOS_EXALL_H
#define DOS_EXALL_H
/*
**    $VER: exall.h  54.126 (05.08.2023)
**
**    Include file for obsolete ExAll() data structures
**
**    (C) Copyright 1989-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2025 Hyperion Entertainment BV.
**        All Rights Reserved.
**
**    Copyright (c) 2010 Hyperion Entertainment BV.
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
/*   ExAll() definitions.
 *   NOTE: V37 dos.library, when doing ExAll() emulation, and V37 filesystems
 *   will return an error if passed ED_OWNER.  If you get ERROR_BAD_NUMBER,
 *   retry with ED_COMMENT to get everything but owner info.  All filesystems
 *   supporting ExAll() must support through ED_COMMENT, and must check Type
 *   and return ERROR_BAD_NUMBER if they don't support the type.
 */

/*   Values that can be passed for what data you want from ExAll() each higher
 *   value includes those below it (numerically) you MUST choose one of these values.
 */

#define ED_NAME        1
#define ED_TYPE        2
#define ED_SIZE        3
#define ED_PROTECTION  4
#define ED_DATE        5
#define ED_COMMENT     6
#define ED_OWNER       7

/****************************************************************************/
/* Handy macros for checking what kind of object a ExAllData's ed_Type describes;
   ExAll() */

#define EAD_IS_FILE(ead)    ((ead)->ed_Type <  0)

#define EAD_IS_DRAWER(ead)  ((ead)->ed_Type >= 0 && \
                             (ead)->ed_Type != ST_SOFTLINK)

#define EAD_IS_LINK(ead)    ((ead)->ed_Type == ST_SOFTLINK || \
                             (ead)->ed_Type == ST_LINKDIR || \
                             (ead)->ed_Type == ST_LINKFILE)

#define EAD_IS_SOFTLINK(ead) ((ead)->ed_Type == ST_SOFTLINK)

#define EAD_IS_LINKDIR(ead)  ((ead)->ed_Type == ST_LINKDIR)



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





