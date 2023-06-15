#ifndef  CLIB_POSEIDON_PROTOS_H
#define  CLIB_POSEIDON_PROTOS_H

/*
**	$Id: poseidon_protos.h 1.2 2002/08/02 12:44:47 hodges Exp $
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef  EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef  EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif
#ifndef  EXEC_DEVICES_H
#include <exec/devices.h>
#endif
#ifndef  EXEC_IO_H
#include <exec/io.h>
#endif
#ifndef  EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef  UTILITY_UTILITY_H
#include <utility/utility.h>
#endif
#ifndef  DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef  LIBRARIES_POSEIDON_H
#include <libraries/poseidon.h>
#endif
APTR psdAllocVec( ULONG size );
VOID psdFreeVec( APTR memptr );
VOID psdLockWritePBase( VOID );
VOID psdLockReadPBase( VOID );
VOID psdUnlockPBase( VOID );
STRPTR psdCopyStr( STRPTR name );
VOID psdDelayMS( ULONG milli );
APTR psdAddHardware( STRPTR name, ULONG unit );
VOID psdRemHardware( APTR phw );
APTR psdEnumerateHardware( APTR phw );
APTR psdAllocDevice( APTR phw );
VOID psdFreeDevice( APTR pd );
VOID psdLockReadDevice( APTR pd );
VOID psdLockWriteDevice( APTR pd );
VOID psdUnlockDevice( APTR pd );
APTR psdEnumerateDevice( APTR pp );
APTR psdGetNextDevice( APTR pd );
LONG psdGetAttrsA( ULONG type, APTR psdstruct, struct TagItem *taglist );
LONG psdGetAttrs( ULONG type, APTR psdstruct, ULONG tag1, ... );
LONG psdSetAttrsA( ULONG type, APTR psdstruct, struct TagItem *taglist );
LONG psdSetAttrs( ULONG type, APTR psdstruct, ULONG tag1, ... );
APTR psdAllocPipe( APTR pd, struct MsgPort *mp, APTR ep );
APTR psdFreePipe( APTR pp );
VOID psdPipeSetup( APTR pp, ULONG rt, ULONG rq, ULONG val, ULONG idx );
LONG psdDoPipe( APTR pp, APTR data, ULONG len );
VOID psdSendPipe( APTR pp, APTR data, ULONG len );
VOID psdAbortPipe( APTR pp );
LONG psdWaitPipe( APTR pp );
ULONG psdGetPipeActual( APTR pp );
LONG psdGetPipeError( APTR pp );
STRPTR psdGetStringDescriptor( APTR pp, ULONG idx );
BOOL psdSetDeviceConfig( APTR pp, ULONG cfgnum );
APTR psdAddClass( STRPTR name, ULONG version );
VOID psdRemClass( APTR puc );
VOID psdClassScan( VOID );
STRPTR psdNumToStr( ULONG type, LONG idx, STRPTR defstr );
struct Task *psdSpawnSubTask( STRPTR name, APTR initpc, APTR userdata );
APTR psdAddErrorMsgA( ULONG level, STRPTR origin, STRPTR fmtstr, APTR fmtdata );
APTR psdAddErrorMsg( ULONG level, STRPTR origin, STRPTR fmtstr, ... );
VOID psdRemErrorMsg( APTR pem );
VOID psdSafeRawDoFmtA( STRPTR buf, ULONG len, STRPTR fmtstr, APTR fmtdata );
VOID psdSafeRawDoFmt( STRPTR buf, ULONG len, STRPTR fmtstr, ... );
BOOL psdSetAltInterface( APTR pp, APTR pif );
APTR psdFindDeviceA( APTR pd, struct TagItem *taglist );
APTR psdFindDevice( APTR pd, ... );
APTR psdClaimAppBindingA( struct TagItem *taglist );
APTR psdClaimAppBinding( ULONG tag1, ... );
APTR psdReleaseAppBinding( APTR pab );
APTR psdAddEventHandler( struct MsgPort *mp, ULONG msgmask );
VOID psdRemEventHandler( APTR peh );
VOID psdSendEvent( ULONG ehmt, APTR param1, APTR param2 );
VOID psdReleaseDevBinding( APTR pd );
VOID psdReleaseIfBinding( APTR pif );
BOOL psdReadCfg( APTR pic, APTR formdata );
APTR psdWriteCfg( APTR pic );
APTR psdFindCfgForm( APTR pic, ULONG formid );
APTR psdNextCfgForm( APTR pic );
BOOL psdRemCfgForm( APTR pic );
APTR psdAddCfgEntry( APTR pic, APTR formdata );
BOOL psdRemCfgChunk( APTR pic, ULONG chnkid );
APTR psdGetCfgChunk( APTR pic, ULONG chnkid );
VOID psdParseCfg( VOID );
VOID psdUnbindAll( VOID );
BOOL psdSetClsCfg( STRPTR owner, APTR form );
APTR psdGetClsCfg( STRPTR owner );
BOOL psdSetUsbDevCfg( STRPTR owner, STRPTR devid, STRPTR ifid, APTR form );
APTR psdGetUsbDevCfg( STRPTR owner, STRPTR devid, STRPTR ifid );
APTR psdFindInterfaceA( APTR pd, APTR pif, struct TagItem *taglist );
APTR psdFindInterface( APTR pd, APTR pif, ... );
APTR psdFindEndpointA( APTR pif, APTR pep, struct TagItem *taglist );
APTR psdFindEndpoint( APTR pif, APTR pep, ... );
STRPTR psdCopyStrFmtA( STRPTR fmtstr, APTR fmtdata );
STRPTR psdCopyStrFmt( STRPTR fmtstr, ... );
BOOL psdSetForcedBinding( STRPTR owner, STRPTR devid, STRPTR ifid );
STRPTR psdGetForcedBinding( STRPTR devid, STRPTR ifid );
APTR psdCheckPipe( APTR pp );
APTR psdOpenStreamA( APTR ep, struct TagItem *taglist );
APTR psdOpenStream( APTR ep, ... );
VOID psdCloseStream( APTR pps );
LONG psdStreamRead( APTR pps, APTR buffer, LONG length );
LONG psdStreamWrite( APTR pps, APTR buffer, LONG length );
LONG psdStreamFlush( APTR pps );
LONG psdGetStreamError( APTR pps );
VOID psdCalculatePower( APTR phw );
BOOL psdLoadCfgFromDisk( STRPTR filename );
BOOL psdSaveCfgToDisk( STRPTR filename, LONG mode );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_POSEIDON_PROTOS_H */
