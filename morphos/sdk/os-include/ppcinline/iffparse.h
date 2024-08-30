/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_IFFPARSE_H
#define _PPCINLINE_IFFPARSE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef IFFPARSE_BASE_NAME
#define IFFPARSE_BASE_NAME IFFParseBase
#endif /* !IFFPARSE_BASE_NAME */

#define OpenClipboard(__p0) \
	LP1(246, struct ClipboardHandle *, OpenClipboard, \
		LONG , __p0, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PropChunk(__p0, __p1, __p2) \
	LP3(114, LONG , PropChunk, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CollectionChunk(__p0, __p1, __p2) \
	LP3(138, LONG , CollectionChunk, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StoreLocalItem(__p0, __p1, __p2) \
	LP3(216, LONG , StoreLocalItem, \
		struct IFFHandle *, __p0, a0, \
		struct LocalContextItem *, __p1, a1, \
		LONG , __p2, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseIFF(__p0) \
	LP1NR(48, CloseIFF, \
		struct IFFHandle *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindCollection(__p0, __p1, __p2) \
	LP3(162, struct CollectionItem *, FindCollection, \
		CONST struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ParseIFF(__p0, __p1) \
	LP2(42, LONG , ParseIFF, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StopChunks(__p0, __p1, __p2) \
	LP3(132, LONG , StopChunks, \
		struct IFFHandle *, __p0, a0, \
		CONST LONG *, __p1, a1, \
		LONG , __p2, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LocalItemData(__p0) \
	LP1(192, APTR , LocalItemData, \
		CONST struct LocalContextItem *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CollectionChunks(__p0, __p1, __p2) \
	LP3(144, LONG , CollectionChunks, \
		struct IFFHandle *, __p0, a0, \
		CONST LONG *, __p1, a1, \
		LONG , __p2, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindProp(__p0, __p1, __p2) \
	LP3(156, struct StoredProperty *, FindProp, \
		CONST struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindPropContext(__p0) \
	LP1(168, struct ContextNode *, FindPropContext, \
		CONST struct IFFHandle *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define EntryHandler(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6(102, LONG , EntryHandler, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		struct Hook *, __p4, a1, \
		APTR , __p5, a2, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindLocalItem(__p0, __p1, __p2, __p3) \
	LP4(210, struct LocalContextItem *, FindLocalItem, \
		CONST struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CurrentChunk(__p0) \
	LP1(174, struct ContextNode *, CurrentChunk, \
		CONST struct IFFHandle *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ParentChunk(__p0) \
	LP1(180, struct ContextNode *, ParentChunk, \
		CONST struct ContextNode *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitIFFasClip(__p0) \
	LP1NR(240, InitIFFasClip, \
		struct IFFHandle *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenIFF(__p0, __p1) \
	LP2(36, LONG , OpenIFF, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SeekChunkRecords(__p0, __p1, __p2, __p3) \
	LP4(282, LONG , SeekChunkRecords, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WriteChunkRecords(__p0, __p1, __p2, __p3) \
	LP4(78, LONG , WriteChunkRecords, \
		struct IFFHandle *, __p0, a0, \
		CONST APTR , __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeIFF(__p0) \
	LP1NR(54, FreeIFF, \
		struct IFFHandle *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadChunkRecords(__p0, __p1, __p2, __p3) \
	LP4(72, LONG , ReadChunkRecords, \
		struct IFFHandle *, __p0, a0, \
		APTR , __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetLocalItemPurge(__p0, __p1) \
	LP2NR(198, SetLocalItemPurge, \
		struct LocalContextItem *, __p0, a0, \
		CONST struct Hook *, __p1, a1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeLocalItem(__p0) \
	LP1NR(204, FreeLocalItem, \
		struct LocalContextItem *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocLocalItem(__p0, __p1, __p2, __p3) \
	LP4(186, struct LocalContextItem *, AllocLocalItem, \
		LONG , __p0, d0, \
		LONG , __p1, d1, \
		LONG , __p2, d2, \
		LONG , __p3, d3, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SeekChunkBytes(__p0, __p1, __p2) \
	LP3(276, LONG , SeekChunkBytes, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GoodType(__p0) \
	LP1(264, LONG , GoodType, \
		LONG , __p0, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GoodID(__p0) \
	LP1(258, LONG , GoodID, \
		LONG , __p0, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PushChunk(__p0, __p1, __p2, __p3) \
	LP4(84, LONG , PushChunk, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadChunkBytes(__p0, __p1, __p2) \
	LP3(60, LONG , ReadChunkBytes, \
		struct IFFHandle *, __p0, a0, \
		APTR , __p1, a1, \
		LONG , __p2, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocIFF() \
	LP0(30, struct IFFHandle *, AllocIFF, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitIFFasDOS(__p0) \
	LP1NR(234, InitIFFasDOS, \
		struct IFFHandle *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseClipboard(__p0) \
	LP1NR(252, CloseClipboard, \
		struct ClipboardHandle *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IDtoStr(__p0, __p1) \
	LP2(270, STRPTR , IDtoStr, \
		LONG , __p0, d0, \
		STRPTR , __p1, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PropChunks(__p0, __p1, __p2) \
	LP3(120, LONG , PropChunks, \
		struct IFFHandle *, __p0, a0, \
		CONST LONG *, __p1, a1, \
		LONG , __p2, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ExitHandler(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6(108, LONG , ExitHandler, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		struct Hook *, __p4, a1, \
		APTR , __p5, a2, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StoreItemInContext(__p0, __p1, __p2) \
	LP3NR(222, StoreItemInContext, \
		struct IFFHandle *, __p0, a0, \
		struct LocalContextItem *, __p1, a1, \
		struct ContextNode *, __p2, a2, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StopOnExit(__p0, __p1, __p2) \
	LP3(150, LONG , StopOnExit, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StopChunk(__p0, __p1, __p2) \
	LP3(126, LONG , StopChunk, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PopChunk(__p0) \
	LP1(90, LONG , PopChunk, \
		struct IFFHandle *, __p0, a0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitIFF(__p0, __p1, __p2) \
	LP3NR(228, InitIFF, \
		struct IFFHandle *, __p0, a0, \
		LONG , __p1, d0, \
		CONST struct Hook *, __p2, a1, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WriteChunkBytes(__p0, __p1, __p2) \
	LP3(66, LONG , WriteChunkBytes, \
		struct IFFHandle *, __p0, a0, \
		CONST APTR , __p1, a1, \
		LONG , __p2, d0, \
		, IFFPARSE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_IFFPARSE_H */
