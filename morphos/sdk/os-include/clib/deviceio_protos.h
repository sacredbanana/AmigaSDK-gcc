#ifndef CLIB_DEVICEIO_PROTOS_H
#define CLIB_DEVICEIO_PROTOS_H

#ifndef EXEC_TYPES_H
	#include <exec/types.h>
#endif

#ifndef LIBRARIES_DEVICEIO_H
	#include <libraries/deviceio.h>
#endif /* LIBRARIES_DEVICEIO_H */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * Init/Cleanup
 */

struct DeviceIO *DIO_InitDeviceIOA(CONST_STRPTR name, CONST struct TagItem *tagList); 
VOID DIO_CleanupDeviceIO(struct DeviceIO *dio);

/*
 * Query/Set
 */

VOID DIO_QueryDeviceIOA(struct DeviceIO *dio, struct TagItem *tagList);
LONG DIO_SetDeviceIOA(struct DeviceIO *dio, CONST struct TagItem *tagList);

/*
 * General
 */

LONG DIO_WriteProtection(struct DeviceIO *dio);  
VOID DIO_Update(struct DeviceIO *dio); 
VOID DIO_MotorOFF(struct DeviceIO *dio); 
UBYTE DIO_IsDiskPresent(struct DeviceIO *dio);

/*
 * Cache
 */

LONG DIO_SetIOCache(struct DeviceIO *dio, ULONG lines, ULONG readahead, BOOL copyback); 
LONG DIO_FlushIOCache(struct DeviceIO *dio);
LONG DIO_FlushBlocks(struct DeviceIO *dio, ULONG start_block, ULONG count);

/*
 * Device I/O
 */

LONG DIO_ReadBlocks(struct DeviceIO *dio, DBLCK block, UBYTE *buffer, ULONG blocks);
LONG DIO_ReadBytes(struct DeviceIO *dio, DBLCK block, UBYTE *buffer, UWORD offsetinblock, UWORD bytes);

LONG DIO_WriteBlocks(struct DeviceIO *dio, DBLCK block, UBYTE *buffer, ULONG blocks);
LONG DIO_WriteBytes(struct DeviceIO *dio, DBLCK block, UBYTE *buffer, UWORD offsetinblock, UWORD bytes);

/*
 * Memory
 */

UBYTE *DIO_AllocateBlocks(struct DeviceIO *dio, ULONG n);
UBYTE *DIO_AllocateBlocksV(struct DeviceIO *dio, ULONG n);

VOID DIO_FreeBlocks(struct DeviceIO *dio, APTR block);
VOID DIO_FreeBlocksV(struct DeviceIO *dio, APTR block);

/*
 * Misc
 */

BOOL DIO_Abort(struct DeviceIO *dio);
VOID DIO_SetAbort(struct DeviceIO *dio, BOOL flag);
VOID DIO_Dump(struct DeviceIO *dio);

/*
 * Tagged
 */

#if !defined(USE_INLINE_STDARG)
	struct DeviceIO *DIO_InitDeviceIO(CONST_STRPTR name, ...); 

	VOID DIO_QueryDeviceIO(struct DeviceIO *dio, ...);
	LONG DIO_SetDeviceIO(struct DeviceIO *dio, ...);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CDIO_DEVICEIO_PROTOS_H */
