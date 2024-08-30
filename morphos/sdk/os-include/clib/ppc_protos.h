#ifndef POWERUP_PPCLIB_PROTOS_H
#define POWERUP_PPCLIB_PROTOS_H

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef POWERUP_PPCLIB_INTERFACE_H
# include <ppclib/interface.h>
#endif

#ifndef POWERUP_PPCLIB_OBJECT_H
# include <ppclib/object.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void*	PPCLoadObject(char*);
void	PPCUnLoadObject(void*);
ULONG	PPCRunObject(void*,void*);
void*	PPCAllocMem(ULONG,ULONG);
void	PPCFreeMem(void*,ULONG);
void*	PPCAllocVec(ULONG,ULONG);
void*	PPCFreeVec(void*);

void	*PPCCreateTask(void*,
							   struct TagItem*);
#if !defined(USE_INLINE_STDARG)
void	*PPCCreateTaskTags(void*,
								   unsigned long tag1Type, ... );
#endif
BOOL	PPCDeleteTask(void*);

void	PPCSignalTask(void*,ULONG);
void	*PPCFindTask(char	*);
ULONG	PPCRunKernelObject(void*,
								   struct ModuleArgs*);
DOUBLE	PPCRunKernelObjectFPU(void*,
									  struct ModuleArgs*);
ULONG	PPCGetTaskAttrs(void*,
								struct TagItem*);
#if !defined(USE_INLINE_STDARG)
ULONG	PPCGetTaskAttrsTags(void*,
									unsigned long tag1Type,
									...);
#endif
ULONG	PPCGetAttrs(struct TagItem*);
#if !defined(USE_INLINE_STDARG)
ULONG	PPCGetAttrsTags(unsigned long tag1Type,
								...);
#endif
void	*PPCFindTaskObject(void*);
ULONG	PPCReadLong(ULONG*);
void	PPCWriteLong(ULONG*,ULONG);
BOOL	PPCStartTask(void*,
							 struct TagItem*);
#if !defined(USE_INLINE_STDARG)
BOOL	PPCStartTaskTags(void*,
								 unsigned long tag1Type, ... );
#endif
BOOL	PPCStopTask(void*,
							struct TagItem*);
#if !defined(USE_INLINE_STDARG)
BOOL	PPCStopTaskTags(void*,
								unsigned long tag1Type, ... );
#endif
ULONG	PPCSetTaskAttrs(void*,
								struct TagItem*);
#if !defined(USE_INLINE_STDARG)
ULONG	PPCSetTaskAttrsTags(void*,
									unsigned long tag1Type,
									...);
#endif
ULONG	PPCGetObjectAttrs(void*,
								  struct PPCObjectInfo*,
								  struct TagItem*);
#if !defined(USE_INLINE_STDARG)
ULONG	PPCGetObjectAttrsTags(void*,
									  struct PPCObjectInfo*,
									  unsigned long tag1Type,
									  ... );
#endif
void	PPCWriteLongFlush(ULONG*,ULONG);
UWORD	PPCReadWord(UWORD*);
void	PPCWriteWord(UWORD*,UWORD);
UBYTE	PPCReadByte(UBYTE*);
void	PPCWriteByte(UBYTE*,UBYTE);
void*	PPCCreatePool(ULONG		MemFlags,
							  ULONG		PuddleSize,
							  ULONG		ThreshSize);
BOOL	PPCDeletePool(void*);
void*	PPCAllocPooled(void*,
							   ULONG);
void	PPCFreePooled(void*,
							  void*,
							  ULONG);
void	PPCFreeVecPooled(void*,
								 void*);
void*	PPCAllocVecPooled(void*,
								  ULONG);



void*	PPCCreatePort(struct TagItem*);
#if !defined(USE_INLINE_STDARG)
void*	PPCCreatePortTags(unsigned long tag1Type, ... );
#endif
BOOL	PPCDeletePort(void*);
void*	PPCObtainPort(struct TagItem*);
#if !defined(USE_INLINE_STDARG)
void*	PPCObtainPortTags(unsigned long tag1Type, ... );
#endif
BOOL	PPCReleasePort(void*);
void*	PPCCreateMessage(void*,
								 ULONG);
void	PPCDeleteMessage(void*);
ULONG	PPCGetMessageAttr(void*,
								  ULONG);
void*	PPCGetMessage(void*);
BOOL	PPCReplyMessage(void*);
BOOL	PPCSendMessage(void*,
							   void*,
							   void*,
							   ULONG,
							   ULONG);
void*	PPCWaitPort(void*);
void	PPCCacheClearE(void*,
							   ULONG,
							   ULONG);

void	PPCCacheInvalidE(void*,
								 ULONG,
								 ULONG);


void*	PPCCreatePortList(void**,ULONG);
void	PPCDeletePortList(void*);
BOOL	PPCAddPortList(void*,
							   void*);
void	PPCRemPortList(void*,
							   void*);
void*	PPCWaitPortList(void*);
ULONG	PPCGetPortListAttr(void*,
								   ULONG);
void	PPCSetPortListAttr(void*,
								   ULONG,
								   ULONG);

#if !defined(USE_INLINE_STDARG)
void*	PPCLoadObjectTags(unsigned long tag1Type, ... );
#endif
void*	PPCLoadObjectTagList(struct TagItem*);


BOOL	PPCSetAttrs(struct TagItem*);
#if !defined(USE_INLINE_STDARG)
BOOL	PPCSetAttrsTags(unsigned long tag1Type, ... );
#endif

void	PPCCacheTrashE(void*,
							   ULONG,
							   ULONG);

void	*PPCOpenLibrary(char*,
								struct TagItem*);

void	PPCCloseLibrary(void*);

void	*PPCGetLibSymbol(void*,
								 char*);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif
