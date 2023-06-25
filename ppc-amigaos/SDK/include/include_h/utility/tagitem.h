#ifndef UTILITY_TAGITEM_H
#define UTILITY_TAGITEM_H
/*
**    $VER: tagitem.h 53.29 (10.8.2015)
**
**    Extended specification mechanism
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

/*****************************************************************************/

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

/* Tags are a general mechanism of extensible data arrays for parameter
 * specification and property inquiry. In practice, tags are used in arrays,
 * or chain of arrays.
 *
 */
typedef uint32 Tag;

struct TagItem
{
    Tag    ti_Tag;  /* identifies the type of data */
    uint32 ti_Data; /* type-specific data          */
};

/* constants for Tag.ti_Tag, control tag values */
#define TAG_DONE   (0UL) /* terminates array of TagItems. ti_Data unused */
#define TAG_END    (0UL) /* synonym for TAG_DONE */
#define TAG_IGNORE (1UL) /* ignore this item, not end of array */
#define TAG_MORE   (2UL) /* ti_Data is pointer to another array of TagItems
                            note that this tag terminates the current array */
#define TAG_SKIP   (3UL) /* skip this and the next ti_Data items */

/* differentiates user tags from control tags */
#define TAG_USER   (1UL<<31)

/* If the TAG_USER bit is set in a tag number, it tells utility.library that
 * the tag is not a control tag (like TAG_DONE, TAG_IGNORE, TAG_MORE) and is
 * instead an application tag. "USER" means a client of utility.library in
 * general, including system code like Intuition or ASL, it has nothing to do
 * with user code.
 */

/*****************************************************************************/

/* Tag filter logic specifiers for use with FilterTagItems() */
enum enTagLogic
{
    TAGFILTER_AND = 0, /* exclude everything but filter hits */
    TAGFILTER_NOT = 1  /* exclude only filter hits           */
};

/*****************************************************************************/

/* Mapping types for use with MapTags() */
enum enTagMap
{
    MAP_REMOVE_NOT_FOUND = 0, /* remove tags that aren't in mapList */
    MAP_KEEP_NOT_FOUND   = 1  /* keep tags that aren't in mapList   */
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

#endif /* UTILITY_TAGITEM_H */
