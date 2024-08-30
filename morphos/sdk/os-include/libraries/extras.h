/*
    extras.library definitions

    Copyright © 2015 MorphOS Team. All rights reserved.
*/

#ifndef LIBRARIES_EXTRAS_H
#define LIBRARIES_EXTRAS_H

#include <utility/tagitem.h>


/* Tags for LoadImageToBitMap() */

#define EXTA_ImageWidth                (TAG_USER + 1)        // ULONG*
#define EXTA_ImageHeight               (TAG_USER + 2)        // ULONG*
#define EXTA_FriendBitmap              (TAG_USER + 3)        // struct BitMap*


/* Tags for LoadFile() */

#define EXTA_FileSize                  (TAG_USER + 101)      // UQUAD*



#endif      /* LIBRARIES_EXTRAS_H */
