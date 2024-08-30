#ifndef CLIB_XFDMASTER_PROTOS_H
#define CLIB_XFDMASTER_PROTOS_H


/*
**	$VER: xfdmaster_protos.h 39.0 (07.08.2002)
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2002 Dirk Stöcker and Georg Hörmann
**	All Rights Reserved
*/

#ifndef  LIBRARIES_XFDMASTER_H
#include <libraries/xfdmaster.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* --- functions in V33 or higher --- */

struct xfdBufferInfo * xfdAllocBufferInfo(void);
void xfdFreeBufferInfo(struct xfdBufferInfo * bufferinfo);
struct xfdSegmentInfo * xfdAllocSegmentInfo(void);
void xfdFreeSegmentInfo(struct xfdSegmentInfo * segmentinfo);
BOOL xfdRecogBuffer(struct xfdBufferInfo * bufferinfo);
BOOL xfdDecrunchBuffer(struct xfdBufferInfo * bufferinfo);
BOOL xfdRecogSegment(struct xfdSegmentInfo * segmentinfo);
BOOL xfdDecrunchSegment(struct xfdSegmentInfo * segmentinfo);
STRPTR xfdGetErrorText(ULONG error);
BOOL xfdTestHunkStructure(APTR buffer, ULONG length);

/* --- functions in V34 or higher --- */

UWORD xfdTestHunkStructureNew(APTR buffer, ULONG length);
UWORD xfdRelocate(APTR buffer, ULONG length, ULONG * result, ULONG mode);

/* --- functions in V36 or higher --- */

UWORD xfdTestHunkStructureFlags(APTR buffer, ULONG length, ULONG flags);
UWORD xfdStripHunks(APTR buffer, ULONG length, ULONG * result, ULONG flags);
APTR xfdAllocObject(ULONG objecttype);
void xfdFreeObject(APTR object);
BOOL xfdRecogLinker(struct xfdLinkerInfo * linkerinfo);
BOOL xfdUnlink(struct xfdLinkerInfo * linkerinfo);

/* --- functions in V37 or higher --- */

UWORD xfdScanData(APTR buffer, ULONG length, ULONG * result, ULONG flags,
	struct xfdScanHook * scanhook);
void xfdFreeScanList(struct xfdScanNode * scannode);
ULONG xfdObjectType(APTR object);
struct xfdScanHook * xfdInitScanHook(BOOL (*entry)(void), APTR data);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif	/*  CLIB_XFDMASTER_PROTOS_H  */
