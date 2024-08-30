#ifndef LIBRARIES_THUMBNAILS_H
#define LIBRARIES_THUMBNAILS_H

#include <utility/tagitem.h>

/*
 * Tags available for ThbGenerateThumbnail()
 */

#define THB_Width           (TAG_USER + 1)
#define THB_Height          (TAG_USER + 2)
#define THB_Format          (TAG_USER + 3)
#define THB_IgnoreAspect    (TAG_USER + 4)
#define THB_ResizeFilter    (TAG_USER + 5)
#define THB_Animated        (TAG_USER + 6)

/*
 * Additional tags available for ThbGetAttrs()
 */

#define THB_Data            (TAG_USER + 5)
#define THB_OriginalWidth   (TAG_USER + 6)
#define THB_OriginalHeight  (TAG_USER + 7)
#define THB_OriginalDepth   (TAG_USER + 8)
#define THB_IsAnimated      (TAG_USER + 9)
#define THB_FramesPerSecond (TAG_USER + 10)

/*
 * Available image formats
 */

#define THB_FORMAT_RGB888   0
#define THB_FORMAT_ARGB8888 1

/*
 * Available resizing/resampling filters.
 */

#define THB_FILTER_NONE 0
#define THB_FILTER_FAST 1 /* default */
#define THB_FILTER_QUALITY 2

#endif /* LIBRARIES_THUMBNAILS_H */
