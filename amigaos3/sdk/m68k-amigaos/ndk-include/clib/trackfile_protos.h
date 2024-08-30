#ifndef CLIB_TRACKFILE_PROTOS_H
#define CLIB_TRACKFILE_PROTOS_H

/*
**	$VER: trackfile_protos.h 2.3 (10.8.2020)
**
**	'C' prototypes. For use with 32 bit integers only.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  DEVICES_TRACKFILE_H
#include <devices/trackfile.h>
#endif
LONG  __stdargs TFStartUnitTagList( LONG which_unit, CONST struct TagItem *tags );
LONG  __stdargs TFStartUnitTags( LONG which_unit, ... );
LONG  __stdargs TFStopUnitTagList( LONG which_unit, CONST struct TagItem *tags );
LONG  __stdargs TFStopUnitTags( LONG which_unit, ... );
LONG  __stdargs TFInsertMediaTagList( LONG which_unit, CONST struct TagItem *tags );
LONG  __stdargs TFInsertMediaTags( LONG which_unit, ... );
LONG  __stdargs TFEjectMediaTagList( LONG which_unit, CONST struct TagItem *tags );
LONG  __stdargs TFEjectMediaTags( LONG which_unit, ... );
struct TrackFileUnitData * __stdargs TFGetUnitData( LONG which_unit );
VOID  __stdargs TFFreeUnitData( struct TrackFileUnitData *tfud );

/*--- functions in V2 or higher ---*/

LONG  __stdargs TFChangeUnitTagList( LONG which_unit, CONST struct TagItem *tags );
LONG  __stdargs TFChangeUnitTags( LONG which_unit, ... );
LONG  __stdargs TFExamineFileSize( LONG file_size );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_TRACKFILE_PROTOS_H */
