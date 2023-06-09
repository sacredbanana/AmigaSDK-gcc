#ifndef CLIB_XADMASTER_PROTOS_H
#define CLIB_XADMASTER_PROTOS_H


/*
**	$VER: xadmaster_protos.h 12.2 (04.10.2003)
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright � 2003 Dirk St�cker
**	All Rights Reserved
*/

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  LIBRARIES_XADMASTER_H
#include <libraries/xadmaster.h>
#endif

APTR xadAllocObjectA(LONG type, const struct TagItem * tags);
APTR xadAllocObject(LONG type, Tag tags, ...);
void xadFreeObjectA(APTR object, const struct TagItem * tags);
void xadFreeObject(APTR object, Tag tags, ...);
struct xadClient * xadRecogFileA(ULONG size, APTR memory, const struct TagItem * tags);
struct xadClient * xadRecogFile(ULONG size, APTR memory, Tag tags, ...);
LONG xadGetInfoA(struct xadArchiveInfo * ai, const struct TagItem * tags);
LONG xadGetInfo(struct xadArchiveInfo * ai, Tag tags, ...);
void xadFreeInfo(struct xadArchiveInfo * ai);
LONG xadFileUnArcA(struct xadArchiveInfo * ai, const struct TagItem * tags);
LONG xadFileUnArc(struct xadArchiveInfo * ai, Tag tags, ...);
LONG xadDiskUnArcA(struct xadArchiveInfo * ai, const struct TagItem * tags);
LONG xadDiskUnArc(struct xadArchiveInfo * ai, Tag tags, ...);
STRPTR xadGetErrorText(ULONG errnum);
struct xadClient * xadGetClientInfo(void);

/* This HookAccess function can be called from clients only! */

LONG xadHookAccess(ULONG command, LONG data, APTR buffer, struct xadArchiveInfo * ai);
LONG xadConvertDatesA(const struct TagItem * tags);
LONG xadConvertDates(Tag tags, ...);
UWORD xadCalcCRC16(ULONG id, ULONG init, ULONG size, STRPTR buffer);
ULONG xadCalcCRC32(ULONG id, ULONG init, ULONG size, STRPTR buffer);

/* --- functions in V2 or higher --- */

APTR xadAllocVec(ULONG size, ULONG flags);
void xadCopyMem(const void * src, APTR dest, ULONG size);

/* --- functions in V3 or higher --- */

LONG xadHookTagAccessA(ULONG command, LONG data, APTR buffer, struct xadArchiveInfo * ai,
	const struct TagItem * tags);
LONG xadHookTagAccess(ULONG command, LONG data, APTR buffer, struct xadArchiveInfo * ai,
	Tag tags, ...);

/* --- functions in V4 or higher --- */

LONG xadConvertProtectionA(const struct TagItem * tags);
LONG xadConvertProtection(Tag tags, ...);
LONG xadGetDiskInfoA(struct xadArchiveInfo * ai, const struct TagItem * tags);
LONG xadGetDiskInfo(struct xadArchiveInfo * ai, Tag tags, ...);
LONG xadDiskFileUnArcA(struct xadArchiveInfo * ai, const struct TagItem * tags);
LONG xadDiskFileUnArc(struct xadArchiveInfo * ai, Tag tags, ...);

/* --- functions in V8 or higher --- */

LONG xadGetHookAccessA(struct xadArchiveInfo * ai, const struct TagItem * tags);
LONG xadGetHookAccess(struct xadArchiveInfo * ai, Tag tags, ...);
LONG xadFreeHookAccessA(struct xadArchiveInfo * ai, const struct TagItem * tags);
LONG xadFreeHookAccess(struct xadArchiveInfo * ai, Tag tags, ...);

/* --- functions in V10 or higher --- */

LONG xadAddFileEntryA(struct xadFileInfo * fi, struct xadArchiveInfo * ai,
	const struct TagItem * tags);
LONG xadAddFileEntry(struct xadFileInfo * fi, struct xadArchiveInfo * ai, Tag tags, ...);
LONG xadAddDiskEntryA(struct xadDiskInfo * di, struct xadArchiveInfo * ai,
	const struct TagItem * tags);
LONG xadAddDiskEntry(struct xadDiskInfo * di, struct xadArchiveInfo * ai, Tag tags, ...);

/* --- functions in V12 or higher --- */

LONG xadGetFilenameA(ULONG buffersize, STRPTR buffer, STRPTR path, STRPTR name,
	const struct TagItem * tags);
LONG xadGetFilename(ULONG buffersize, STRPTR buffer, STRPTR path, STRPTR name, Tag tags,
	...);
STRPTR xadConvertNameA(ULONG charset, const struct TagItem * tags);
STRPTR xadConvertName(ULONG charset, Tag tags, ...);

#endif	/*  CLIB_XADMASTER_PROTOS_H  */
