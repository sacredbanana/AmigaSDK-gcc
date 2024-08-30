#ifndef	CLIB_MOUNT_PROTOS_H
#define	CLIB_MOUNT_PROTOS_H

#ifndef	EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef LIBRARIES_MOUNT_H
#include <libraries/mount.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void	*MountCreateNotifyUnitTagList(struct TagItem	*MyTags);

void	MountDeleteNotifyUnit(void	*MyNotifyUnit);

void	*MountCreateNotifyNodeTagList(void *MyNotifyUnit,
                                      struct TagItem	*MyTags);

void	MountDeleteNotifyNode(void *MyNotifyNode);

ULONG	MountGetNotifyUnitAttr(void	*MyNotifyUnit,
                               APTR	Data,
                               ULONG	Attr);

void	*MountFindNotifyNodeTagList(void		*MyNotifyUnit,
                                    struct TagItem	*MyTags);

ULONG	MountMountTagList(void			*MyNotifyUnit,
                          struct TagItem	*MyTags);

ULONG	MountDisMountTagList(void		*MyNotifyUnit,
                             struct TagItem	*MyTags);

void	MountNotifyAll(void	*MyNotifyUnit,
                       ULONG	ChangeState);

void	MountNotifySet(void	*MyNotifyUnit,
                        ULONG	ChangeState);

void	MountNotifyTask(void		*MyNotifyUnit,
                        struct Task	*MyTask,
                        ULONG		ChangeState);

ULONG	MountUpdateNotifyUnitConfigTagList(void			*MyNotifyUnit,
                                           struct TagItem	*MyTags);

ULONG	MountMountDiskHandlersTagList(struct TagItem	*MyTags);


#if !defined(USE_INLINE_STDARG)
void	*MountCreateNotifyUnitTags(Tag tag1,...);
void	*MountCreateNotifyNodeTags(void *MyNotifyUnit,...);
void	*MountFindNotifyNodeTags(void		*MyNotifyUnit,...);
ULONG	MountMountTags(void	*MyNotifyUnit,...);
ULONG	MountDisMountTags(void	*MyNotifyUnit,...);
ULONG	MountUpdateNotifyUnitConfigTags(void		*MyNotifyUnit,...);
ULONG	MountMountDiskHandlersTags(Tag tag,...);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
