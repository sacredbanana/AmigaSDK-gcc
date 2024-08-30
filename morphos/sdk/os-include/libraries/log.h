#ifndef LIBRARIES_LOG_H
#define LIBRARIES_LOG_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_DEVICES_H
#include <exec/devices.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

struct LogNotifyMsg
{
	struct Message	Msg;
	ULONG		Version;
	ULONG		Type;
	/*
	 * unknown territory
	 */
};

enum
{
	LOGNOTIFYTYPE_PPCEXCEPTION,
	LOGNOTIFYTYPE_68KEXCEPTION,
	LOGNOTIFYTYPE_ALERT,
	LOGNOTIFYTYPE_LOG
};

#endif /* LIBRARIES_LOG_H */
