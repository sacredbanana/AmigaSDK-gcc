#ifndef LIBRARIES_WBSTART_H
#define LIBRARIES_WBSTART_H

/*
	wbstart.library include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#define WBSTART_NAME    "wbstart.library"
#define WBSTART_VERSION 2

#define WBStart_Name          (TAG_USER + 1) /* STRPTR */
#define WBStart_DirectoryName (TAG_USER + 2) /* STRPTR */
#define WBStart_DirectoryLock (TAG_USER + 3) /* BPTR */
#define WBStart_Stack         (TAG_USER + 4) /* ULONG */
#define WBStart_Priority      (TAG_USER + 5) /* LONG */
#define WBStart_ArgumentCount (TAG_USER + 6) /* ULONG */
#define WBStart_ArgumentList  (TAG_USER + 7) /* struct WBArg * */


#endif /* LIBRARIES_WBSTART_H */
