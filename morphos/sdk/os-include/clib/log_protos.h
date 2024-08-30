#ifndef	CLIB_LOG_PROTOS_H
#define	CLIB_LOG_PROTOS_H

#ifndef	EXEC_TYPES_H
#  include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
#  include <utility/tagitem.h>
#endif

#ifndef LIBRARIES_LOG_H
# include <libraries/log.h>
#endif

#include <stdarg.h>


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void LogVPrintf(char *Category,char *Format, va_list args);
void LogPrintf(char *Category,char *Format, ...);
void LogShowWindow(void);
void LogHideWindow(void);
ULONG LogAddNotify(struct MsgPort *NotifyMsgPort);
ULONG LogRemNotify(struct MsgPort *NotifyMsgPort);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_LOG_PROTOS_H */
