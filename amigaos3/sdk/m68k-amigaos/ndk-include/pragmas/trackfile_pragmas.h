#ifndef PRAGMAS_TRACKFILE_PRAGMAS_H
#define PRAGMAS_TRACKFILE_PRAGMAS_H

/*
**	$VER: trackfile_pragmas.h 2.3 (10.8.2020)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_TRACKFILE_PROTOS_H
#include <clib/trackfile_protos.h>
#endif /* CLIB_TRACKFILE_PROTOS_H */

/* "trackfile.device" */
#pragma libcall TrackFileBase TFStartUnitTagList 2a 8002
#if defined(__SASC_60)
#pragma tagcall TrackFileBase TFStartUnitTags 2a 8002
#endif /* __SASC_60 */
#pragma libcall TrackFileBase TFStopUnitTagList 30 8002
#if defined(__SASC_60)
#pragma tagcall TrackFileBase TFStopUnitTags 30 8002
#endif /* __SASC_60 */
#pragma libcall TrackFileBase TFInsertMediaTagList 36 8002
#if defined(__SASC_60)
#pragma tagcall TrackFileBase TFInsertMediaTags 36 8002
#endif /* __SASC_60 */
#pragma libcall TrackFileBase TFEjectMediaTagList 3c 8002
#if defined(__SASC_60)
#pragma tagcall TrackFileBase TFEjectMediaTags 3c 8002
#endif /* __SASC_60 */
#pragma libcall TrackFileBase TFGetUnitData 42 001
#pragma libcall TrackFileBase TFFreeUnitData 48 801

/*--- functions in V2 or higher ---*/

#pragma libcall TrackFileBase TFChangeUnitTagList 4e 8002
#if defined(__SASC_60)
#pragma tagcall TrackFileBase TFChangeUnitTags 4e 8002
#endif /* __SASC_60 */
#pragma libcall TrackFileBase TFExamineFileSize 54 001

#endif /* PRAGMAS_TRACKFILE_PRAGMAS_H */
