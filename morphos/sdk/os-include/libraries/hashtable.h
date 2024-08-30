#ifndef LIBRARIES_HASHTABLE_H
#define LIBRARIES_HASHTABLE_H

/*
 * hashtable.library include
 *
 * Copyright © 2014 The MorphOS Development Team, All Rights Reserved.
 */

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/* Tags for CreateHashTableTagList() */

#define HASHTABLE_Capacity        (TAG_USER + 0)
#define HASHTABLE_Count           (TAG_USER + 1)
#define HASHTABLE_MemoryFootprint (TAG_USER + 2)
#define HASHTABLE_ThreadSafe      (TAG_USER + 3)   /* Boolean */
#define HASHTABLE_CompareFunction (TAG_USER + 4)   /* V53 ssize_t (*comparer)(APTR hash, size_t key1, size_t key2, APTR userdata) */
#define HASHTABLE_UserData        (TAG_USER + 5)   /* V53 */

#endif /* LIBRARIES_HASHTABLE_H */

