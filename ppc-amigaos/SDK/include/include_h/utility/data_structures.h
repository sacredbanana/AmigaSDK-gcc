#ifndef UTILITY_DATA_STRUCTURES_H
#define UTILITY_DATA_STRUCTURES_H
/*
**    $VER: data_structures.h 53.29 (10.8.2015)
**
**    Complex data structures
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif /* EXEC_TYPES_H */

/*****************************************************************************/

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

/* Lists with probabilistic balancing */
struct SkipList
{
    LONG sl_Error; /* If an insertion fails, here is why */
};

struct SkipNode
{
    APTR sn_Reserved;
    APTR sn_Key;      /* Unique key associated with this node */
};

/*****************************************************************************/

/* Self-organizing binary trees */
struct SplayTree
{
    LONG st_Error; /* If an insertion fails, here is why */
};

struct SplayNode
{
    APTR sn_UserData; /* Points to user data area for this node */
};

/*****************************************************************************/

/* Error codes that may be returned by the insertion functions. */
enum enErrorCodes
{
    INSERTNODE_OUT_OF_MEMORY = 1, /* Not enough memory */
    INSERTNODE_DUPLICATE_KEY = 2, /* Key is not unique */
    INSERTNODE_TOO_SHORT     = 3, /* Node size must be at least
                                     as large as
                                     sizeof(struct SkipNode). */
};

/*****************************************************************************/

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

#endif /* UTILITY_DATA_STRUCTURES_H */
