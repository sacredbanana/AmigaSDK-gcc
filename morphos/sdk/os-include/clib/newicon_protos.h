#ifndef  CLIB_NEWICON_PROTOS_H
#define  CLIB_NEWICON_PROTOS_H

struct Screen;
struct Image;
struct NewDiskObject;
struct ChunkyImage;


#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  LIBRARIES_NEWICON_H
#include <libraries/newicon.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct NewDiskObject *GetNewDiskObject( UBYTE *name );
BOOL PutNewDiskObject( UBYTE *name, struct NewDiskObject *diskobj );
void FreeNewDiskObject( struct NewDiskObject *diskobj );
struct Image *RemapChunkyImage( struct ChunkyImage *cim, struct Screen *screen );
VOID FreeRemappedImage( struct Image *image, struct Screen *screen );
/* V40 */
struct NewDiskObject *GetDefNewDiskObject(LONG deftype);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	 /* CLIB_NEWICON_PROTOS_H */
