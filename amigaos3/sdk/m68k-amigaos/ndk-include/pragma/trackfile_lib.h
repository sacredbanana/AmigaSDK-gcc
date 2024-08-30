#ifndef PRAGMA_TRACKFILE_LIB_H
#define PRAGMA_TRACKFILE_LIB_H

/*
**	$VER: trackfile_lib.h 2.3 (10.8.2020)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_TRACKFILE_PROTOS_H
#include <clib/trackfile_protos.h>
#endif /* CLIB_TRACKFILE_PROTOS_H */

/* "trackfile.device" */
#pragma amicall(TrackFileBase, 0x2a, TFStartUnitTagList(d0,a0))
#if defined(__STORM__)
#pragma tagcall(TrackFileBase, 0x2a, TFStartUnitTags(d0,a0))
#endif /* __STORM__ */
#pragma amicall(TrackFileBase, 0x30, TFStopUnitTagList(d0,a0))
#if defined(__STORM__)
#pragma tagcall(TrackFileBase, 0x30, TFStopUnitTags(d0,a0))
#endif /* __STORM__ */
#pragma amicall(TrackFileBase, 0x36, TFInsertMediaTagList(d0,a0))
#if defined(__STORM__)
#pragma tagcall(TrackFileBase, 0x36, TFInsertMediaTags(d0,a0))
#endif /* __STORM__ */
#pragma amicall(TrackFileBase, 0x3c, TFEjectMediaTagList(d0,a0))
#if defined(__STORM__)
#pragma tagcall(TrackFileBase, 0x3c, TFEjectMediaTags(d0,a0))
#endif /* __STORM__ */
#pragma amicall(TrackFileBase, 0x42, TFGetUnitData(d0))
#pragma amicall(TrackFileBase, 0x48, TFFreeUnitData(a0))

/*--- functions in V2 or higher ---*/

#pragma amicall(TrackFileBase, 0x4e, TFChangeUnitTagList(d0,a0))
#if defined(__STORM__)
#pragma tagcall(TrackFileBase, 0x4e, TFChangeUnitTags(d0,a0))
#endif /* __STORM__ */
#pragma amicall(TrackFileBase, 0x54, TFExamineFileSize(d0))

#endif /* PRAGMA_TRACKFILE_LIB_H */
