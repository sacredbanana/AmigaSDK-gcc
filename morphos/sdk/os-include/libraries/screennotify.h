#ifndef LIBRARIES_SCREENNOTIFY_H
#define LIBRARIES_SCREENNOTIFY_H

/*
	screennotify.library include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#pragma pack(2)


#define SCREENNOTIFY_NAME       "screennotify.library"
#define SCREENNOTIFY_VERSION    1


struct ScreenNotifyMessage
{
	struct Message snm_Message;
	ULONG          snm_Type;
	APTR           snm_Value;
};


#define SCREENNOTIFY_TYPE_CLOSESCREEN   0
#define SCREENNOTIFY_TYPE_PUBLICSCREEN  1
#define SCREENNOTIFY_TYPE_PRIVATESCREEN 2
#define SCREENNOTIFY_TYPE_WORKBENCH     3


#pragma pack()

#endif /* LIBRARIES_SCREENNOTIFY_H */
