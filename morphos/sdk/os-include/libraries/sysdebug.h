#ifndef LIBRARIES_SYSDEBUG_H
#define LIBRARIES_SYSDEBUG_H

/*
 * sysdebug.library include
 *
 * Copyright © 2019-2020 The MorphOS Development Team, All Rights Reserved.
 */

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/* Tags for SysDebugFindSegTagList() */

/* NOTE: In order to use the results safely you must lock the data in
 * memory while you're working with them. This ensures that the the
 * memory pointed by SYSDEBUG_SegListArrayPtr and
 * SYSDEBUG_SegNameArrayPtr arrays remains valid.
 *
 * To lock the data you can use SysDebugLock() and SysDebugUnLock()
 * functions, or you can obtain the SEG_SEM ("SegTracker") semaphore.
 *
 * Do not hold the lock for too long as it will block loading/unloading
 * segments.
 */

#define SYSDEBUG_Name             (TAG_USER + 0)   /*  IN: STRPTR    - Find modules matching the name */
#define SYSDEBUG_CaseSensitive    (TAG_USER + 1)   /*  IN: Boolean   - Is SYSDEBUG_Name case sensitive? (default TRUE) */
#define SYSDEBUG_NumResultsPtr    (TAG_USER + 2)   /* OUT: LONG *    - Pointer to number of results */
#define SYSDEBUG_SegListArrayPtr  (TAG_USER + 3)   /* OUT: BPTR **   - Pointer to array of result seglist pointers */
#define SYSDEBUG_SegNameArrayPtr  (TAG_USER + 4)   /* OUT: STRPTR ** - Pointer to array of result seglist name pointer */

#endif /* LIBRARIES_SYSDEBUG_H */

