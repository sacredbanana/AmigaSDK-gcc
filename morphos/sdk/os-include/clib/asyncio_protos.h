#ifndef CLIB_ASYNCIO_PROTOS_H
#define CLIB_ASYNCIO_PROTOS_H

struct ExecBase;
struct DosLibrary;


#ifndef LIBRARIES_ASYNCIO_H
#include <libraries/asyncio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Hook;

#ifdef ASIO_NOEXTERNALS
AsyncFile * OpenAsync( const STRPTR fileName, OpenModes mode, LONG bufferSize, struct ExecBase *SysBase, struct DosLibrary *DOSBase );
AsyncFile * OpenAsyncFromFH( BPTR handle, OpenModes mode, LONG bufferSize, struct ExecBase *SysBase, struct DosLibrary *DOSBase );
#else
AsyncFile * OpenAsync( const STRPTR fileName, OpenModes mode, LONG bufferSize );
AsyncFile * OpenAsyncFromFH( BPTR handle, OpenModes mode, LONG bufferSize );
#endif
LONG CloseAsync( AsyncFile *file );
LONG PeekAsync( AsyncFile *file, APTR buffer, LONG numBytes );
LONG ReadAsync( AsyncFile *file, APTR buffer, LONG numBytes );
LONG ReadCharAsync( AsyncFile *file );
LONG ReadLineAsync( AsyncFile *file, APTR buffer, LONG size );
APTR FGetsAsync( AsyncFile *file, APTR buffer, LONG size );
APTR FGetsLenAsync( AsyncFile *file, APTR buffer, LONG size, LONG *length );
LONG WriteAsync( AsyncFile *file, APTR buffer, LONG numBytes );
LONG WriteCharAsync( AsyncFile *file, UBYTE ch );
LONG WriteLineAsync( AsyncFile *file, STRPTR line );
LONG SeekAsync( AsyncFile *file, LONG position, SeekModes mode);
QUAD SeekAsync64( AsyncFile *file, QUAD position, SeekModes mode);
LONG ReadAsyncPkt( AsyncFile *file, struct Hook *hook, LONG numBytes );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_LIBRARIES_ASYNCIO_H */
