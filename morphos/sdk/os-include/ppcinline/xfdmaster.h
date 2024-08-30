/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_XFDMASTER_H
#define _PPCINLINE_XFDMASTER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef XFDMASTER_BASE_NAME
#define XFDMASTER_BASE_NAME xfdMasterBase
#endif /* !XFDMASTER_BASE_NAME */

#define xfdRecogLinker(__p0) \
	LP1(126, BOOL , xfdRecogLinker, \
		struct xfdLinkerInfo *, __p0, a0, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdAllocBufferInfo() \
	LP0(30, struct xfdBufferInfo *, xfdAllocBufferInfo, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdInitScanHook(__p0, __p1) \
	LP2FP(156, struct xfdScanHook *, xfdInitScanHook, \
		__ft, __p0, a0, \
		APTR , __p1, a1, \
		, XFDMASTER_BASE_NAME, BOOL (* __ft)(), 0, 0, 0, 0, 0, 0)

#define xfdRecogSegment(__p0) \
	LP1(66, BOOL , xfdRecogSegment, \
		struct xfdSegmentInfo *, __p0, a0, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdGetErrorText(__p0) \
	LP1(78, STRPTR , xfdGetErrorText, \
		ULONG , __p0, d0, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdFreeBufferInfo(__p0) \
	LP1NR(36, xfdFreeBufferInfo, \
		struct xfdBufferInfo *, __p0, a1, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdStripHunks(__p0, __p1, __p2, __p3) \
	LP4(108, UWORD , xfdStripHunks, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG *, __p2, a1, \
		ULONG , __p3, d1, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdObjectType(__p0) \
	LP1(150, ULONG , xfdObjectType, \
		APTR , __p0, a1, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdDecrunchBuffer(__p0) \
	LP1(60, BOOL , xfdDecrunchBuffer, \
		struct xfdBufferInfo *, __p0, a0, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdFreeScanList(__p0) \
	LP1NR(144, xfdFreeScanList, \
		struct xfdScanNode *, __p0, a1, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdAllocObject(__p0) \
	LP1(114, APTR , xfdAllocObject, \
		ULONG , __p0, d0, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdRelocate(__p0, __p1, __p2, __p3) \
	LP4(96, UWORD , xfdRelocate, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG *, __p2, a1, \
		ULONG , __p3, d1, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdTestHunkStructure(__p0, __p1) \
	LP2(84, BOOL , xfdTestHunkStructure, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdFreeSegmentInfo(__p0) \
	LP1NR(48, xfdFreeSegmentInfo, \
		struct xfdSegmentInfo *, __p0, a1, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdRecogBuffer(__p0) \
	LP1(54, BOOL , xfdRecogBuffer, \
		struct xfdBufferInfo *, __p0, a0, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdFreeObject(__p0) \
	LP1NR(120, xfdFreeObject, \
		APTR , __p0, a1, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdAllocSegmentInfo() \
	LP0(42, struct xfdSegmentInfo *, xfdAllocSegmentInfo, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdUnlink(__p0) \
	LP1(132, BOOL , xfdUnlink, \
		struct xfdLinkerInfo *, __p0, a0, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdDecrunchSegment(__p0) \
	LP1(72, BOOL , xfdDecrunchSegment, \
		struct xfdSegmentInfo *, __p0, a0, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdTestHunkStructureFlags(__p0, __p1, __p2) \
	LP3(102, UWORD , xfdTestHunkStructureFlags, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdTestHunkStructureNew(__p0, __p1) \
	LP2(90, UWORD , xfdTestHunkStructureNew, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define xfdScanData(__p0, __p1, __p2, __p3, __p4) \
	LP5(138, UWORD , xfdScanData, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG *, __p2, a1, \
		ULONG , __p3, d1, \
		struct xfdScanHook *, __p4, a2, \
		, XFDMASTER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_XFDMASTER_H */
