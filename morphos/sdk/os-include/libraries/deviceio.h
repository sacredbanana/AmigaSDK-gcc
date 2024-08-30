#ifndef LIBRARIES_DEVICEIO_H
#define LIBRARIES_DEVICEIO_H

#ifndef EXEC_TYPES_H
	#include <exec/types.h>
#endif /* EXEC_TYPES_H */

#ifndef UTILITY_TAGITEM_H
   #include <utility/tagitem.h>
#endif /* UTILITY_TAGITEM_H */

/* ============================================ */

#define DEVICEIO_NAME    "deviceio.library"
#define DEVICEIO_VERSION (1)

/* ============================================ */

#ifndef DEVICEIO_PRIVATE_H

/* 
 * There's really nothing in this structure you need to care about
 */

struct DeviceIO
{
   /* 
    * more below this point !
    *
    * please do not tuch anything here, use 
    * QueryDeviceIOA or SetDeviceIOA if you need
    * to query/set something inside
    *
    * look in to private.h for more info
    */
};

#endif /* DEVICEIO_PRIVATE_H */

/* ============================================ */

/*
 * DeviceIO BLCK
 */

typedef unsigned long DBLCK;

/*
 * DeviceIO - Tag base
 */

#define DEVICEIO_TAGBASE   (TAG_USER)

/*
 * DeviceIO - Error base
 */

#define DEVICEIO_ERRBASE   (1024)

/* ============================================ */

/*
 * InitDeviceIOA - Tags
 */

#define IDIO_LockDosListFlags  (DEVICEIO_TAGBASE + 1)    /* Flags used to LockDosList() */
#define IDIO_MarkToState       (DEVICEIO_TAGBASE + 2)    /* See below */

#define IDIO_IOC_Lines         (DEVICEIO_TAGBASE + 101)  /* IOC Lines */
#define IDIO_IOC_ReadAheadSize (DEVICEIO_TAGBASE + 102)  /* IOC ReadAheadSize (Bytes) */
#define IDIO_IOC_Copyback      (DEVICEIO_TAGBASE + 103)  /* IOC Copyback (BOOL) */

#define IDIO_PoolSize          (DEVICEIO_TAGBASE + 201)  /* Internal Pool size */
#define IDIO_PoolTreshold      (DEVICEIO_TAGBASE + 202)  /* Internal Pool trashold */

#define IDIO_CTRL_C            (DEVICEIO_TAGBASE + 301)  /* enable/disable CTRL_C checking (BOOL) */

#define IDIO_Force             (DEVICEIO_TAGBASE + 401)  /* */
#define IDIO_ForceBlockSize    (DEVICEIO_TAGBASE + 402)  /* */

#define IDIO_FSSM              (DEVICEIO_TAGBASE + 501)  /* */

/*
 * QueryDeviceIOA - Tags
 */

#define DEVICEIO_QUERY_TAGBASE   (TAG_USER)

#define DIOQ_ADOS_FileSysStartupMsg (DEVICEIO_QUERY_TAGBASE + 1)
#define DIOQ_ADOS_DosEnvec          (DEVICEIO_QUERY_TAGBASE + 2)
#define DIOQ_ADOS_MsgPort           (DEVICEIO_QUERY_TAGBASE + 3)
#define DIOQ_LL_MsgPort             (DEVICEIO_QUERY_TAGBASE + 11)
#define DIOQ_LL_IORequest           (DEVICEIO_QUERY_TAGBASE + 12)  /* User reserved IOReq */
#define DIOQ_Start_ByteH            (DEVICEIO_QUERY_TAGBASE + 101) /* the byte offset of our partition on the disk */
#define DIOQ_Start_ByteL            (DEVICEIO_QUERY_TAGBASE + 102) /* high 32 bits */
#define DIOQ_End_ByteH              (DEVICEIO_QUERY_TAGBASE + 103) /* the byte offset of the end of our partition (excluding) on the disk */
#define DIOQ_End_ByteL              (DEVICEIO_QUERY_TAGBASE + 104) /* high 32 bits */
#define DIOQ_Sector_Low             (DEVICEIO_QUERY_TAGBASE + 105)
#define DIOQ_Sector_High            (DEVICEIO_QUERY_TAGBASE + 106)
#define DIOQ_Device_API             (DEVICEIO_QUERY_TAGBASE + 201)
#define DIOQ_Device_APIUsed         (DEVICEIO_QUERY_TAGBASE + 202)
#define DIOQ_Blocks_Total           (DEVICEIO_QUERY_TAGBASE + 301) /* size of the partition in blocks */
#define DIOQ_Blocks_Reserved_Start  (DEVICEIO_QUERY_TAGBASE + 302) /* number of blocks reserved at start (=reserved) */
#define DIOQ_Blocks_Reserved_End    (DEVICEIO_QUERY_TAGBASE + 303) /* number of blocks reserved at end (=prealloc) */
#define DIOQ_Blocks_MaxTransfer     (DEVICEIO_QUERY_TAGBASE + 304) /* max. blocks which may be transfered to the device at once (limits io_Length) */
#define DIOQ_Sectors_Block          (DEVICEIO_QUERY_TAGBASE + 311) /* number of sectors in a block */
#define DIOQ_Sectors_PerCylinder    (DEVICEIO_QUERY_TAGBASE + 312)
#define DIOQ_Sectors_Total          (DEVICEIO_QUERY_TAGBASE + 313) /* size of the partition in sectors */
#define DIOQ_Bytes_Block            (DEVICEIO_QUERY_TAGBASE + 321) /* size of a block in bytes */
#define DIOQ_Bytes_Sector           (DEVICEIO_QUERY_TAGBASE + 322)
#define DIOQ_Shifts_Block           (DEVICEIO_QUERY_TAGBASE + 331) /* shift count needed to convert a blockoffset<->byteoffset */
#define DIOQ_Shifts_Block32         (DEVICEIO_QUERY_TAGBASE + 332) /* shift count needed to convert a blockoffset<->32byteoffset */
#define DIOQ_Mask_Block             (DEVICEIO_QUERY_TAGBASE + 341)
#define DIOQ_Mask_Block32           (DEVICEIO_QUERY_TAGBASE + 342) /* masks the least significant bits of a BLCKf pointer */
#define DIOQ_Mask_Mask              (DEVICEIO_QUERY_TAGBASE + 343) /* mask as specified by mountlist */
#define DIOQ_Cache_Lines            (DEVICEIO_QUERY_TAGBASE + 501)
#define DIOQ_Cache_RAHS             (DEVICEIO_QUERY_TAGBASE + 502)
#define DIOQ_Cache_Copyback         (DEVICEIO_QUERY_TAGBASE + 503)

#define DIOQ_Flags                  (DEVICEIO_QUERY_TAGBASE + 1024)

/*
 * SetDeviceIOA - Tags
 */

#define DEVICEIO_SET_TAGBASE     (TAG_USER)

#define DIOS_TransferFunc_Ptr    (DEVICEIO_SET_TAGBASE + 1) /* transfer() hook (Prototype = void func(struct DeviceIO *, arg1, arg2, arg3) */
#define DIOS_TransferFunc_Arg1   (DEVICEIO_SET_TAGBASE + 2) /* transfer hook arg1 (Default 0) */
#define DIOS_TransferFunc_Arg2   (DEVICEIO_SET_TAGBASE + 3) /* transfer hook arg2 (Default 0) */
#define DIOS_TransferFunc_Arg3   (DEVICEIO_SET_TAGBASE + 4) /* transfer hook arg3 (Default 0) */

#define DIOS_CTRL_C              (DEVICEIO_SET_TAGBASE + 11) /* enable/disable CTRL_C checking */

#define DIOS_State               (DEVICEIO_SET_TAGBASE + 21) /* Set to specyfic 'state' */

/* ============================================ */

/*
 * Device Flags
 */

#define DF_DeviceOpen      (1)
#define DF_CachedIO        (1 << 1)
#define DF_WriteProtected  (1 << 2)
#define DF_Inhibited       (1 << 3)
#define DF_Disable_CTRLC   (1 << 4)
#define DF_Forced          (1 << 5)
#define DF_BlockSizeFucked (1 << 6)

/*
 * Interfaces
 */

#define DIOI_Standard   (0)      /* All devices support this */
#define DIOI_NSD        (1)      /* NewStyleDevcie intraface */
#define DIOI_TD64       (1 << 1) /* TrackDisk64 interface    */
#define DIOI_ScsiDirect (1 << 2) /* SCSIDirect interface     */

/*
 * IDIO_MarkToState
 */

#define MTS_None         (0)      /* */
#define MTS_WriteProtect (1)      /* Set device to WriteProtected state */
#define MTS_Inhibit      (1 << 1) /* Set device to Inhibit state */


/*
 * InitDeviceIOA - Errors
 */

#define DIO_ERROR_READ_GEOMETRY     (DEVICEIO_ERRBASE + 1)
#define DIO_ERROR_NO_64BIT_SUPPORT  (DEVICEIO_ERRBASE + 2)

/*
 * CachedIO - Errors
 */

#define DIO_ERROR_OUTSIDE_PARTITION (DEVICEIO_ERRBASE + 3)

/* ============================================ */

/*
 * InitDeviceData
 */

struct InitDeviceData
{
   /* ADOS Device */
   STRPTR      device_name;
   ULONG       device_unit;
   ULONG       device_flags;
};

/*
 * Global Macros
 */

/*===============*/
/* Global Macros */
/*===============*/

#define STRIPDEVNAME(_name)              \
   {                                     \
      int _name_lenght = strlen(_name);  \
                                         \
      if(_name[_name_lenght - 1] == ':') \
         _name[_name_lenght - 1] = 0;    \
   }                                    

#define ReadBlock(_dio, _blck, _buff) ReadBlocks(_dio, _blck, _buff, 1L)
#define WriteBlock(_dio, _blck, _buff) WriteBlocks(_dio, _blck, _buff, 1L)

#define AllocateBlock(_dio) AllocateBlocks(_dio, 1L)

/* ============================================ */

#ifndef FSTM_NO_ALIASES

#define InitDeviceIOA		DIO_InitDeviceIOA
#define CleanupDeviceIO		DIO_CleanupDeviceIO

#define QueryDeviceIOA		DIO_QueryDeviceIOA
#define SetDeviceIOA			DIO_SetDeviceIOA

#define WriteProtection		DIO_WriteProtection
#define Update					DIO_Update
#define MotorOFF				DIO_MotorOFF
#define IsDiskPresent		DIO_IsDiskPresent

#define SetIOCache			DIO_SetIOCache
#define FlushIOCache			DIO_FlushIOCache
#define FlushBlocks			DIO_FlushBlocks

#define ReadBlocks			DIO_ReadBlocks
#define ReadBytes				DIO_ReadBytes

#define WriteBlocks			DIO_WriteBlocks
#define WriteBytes			DIO_WriteBytes

#define AllocateBlocks		DIO_AllocateBlocks
#define AllocateBlocksV		DIO_AllocateBlocksV

#define FreeBlocks			DIO_FreeBlocks
#define FreeBlocksV			DIO_FreeBlocksV

#define Abort					DIO_Abort
#define SetAbort				DIO_SetAbort
#define Dump					DIO_Dump

#ifdef USE_INLINE_STDARG

	#define InitDeviceIO		DIO_InitDeviceIO

	#define QueryDeviceIO	DIO_QueryDeviceIO
	#define SetDeviceIO		DIO_SetDeviceIO

#endif /* USE_INLINE_STDARG */

#endif /* FSTM_NO_ALIASES */

/* ============================================ */

#endif /* LIBRARIES_DEVICEIO_H */
