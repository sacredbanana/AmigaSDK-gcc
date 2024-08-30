#ifndef DOS_ERRORS_H
#define DOS_ERRORS_H
/*
**    $VER: errors.h  54.100 (07.09.2020)
**
**    All error codes defined by the dos.library API
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/
/* Errors from IoErr(), etc. */
/****************************************************************************/

#define ERROR_INVALID_PACKET_MESSAGE     101
#define ERROR_WRONG_PACKET_RETURNED      102
#define ERROR_NO_FREE_STORE              103
#define ERROR_TASK_TABLE_FULL            105
#define ERROR_BAD_TEMPLATE               114
#define ERROR_BAD_NUMBER                 115
#define ERROR_REQUIRED_ARG_MISSING       116
#define ERROR_KEY_NEEDS_ARG              117
#define ERROR_TOO_MANY_ARGS              118
#define ERROR_UNMATCHED_QUOTES           119
#define ERROR_LINE_TOO_LONG              120
#define ERROR_FILE_NOT_OBJECT            121
#define ERROR_INVALID_RESIDENT_LIBRARY   122
#define ERROR_NO_DEFAULT_DIR             201
#define ERROR_OBJECT_IN_USE              202
#define ERROR_OBJECT_EXISTS              203
#define ERROR_DIR_NOT_FOUND              204
#define ERROR_OBJECT_NOT_FOUND           205
#define ERROR_BAD_STREAM_NAME            206
#define ERROR_OBJECT_TOO_LARGE           207
#define ERROR_ACTION_NOT_KNOWN           209
#define ERROR_INVALID_COMPONENT_NAME     210
#define ERROR_INVALID_LOCK               211
#define ERROR_OBJECT_WRONG_TYPE          212
#define ERROR_DISK_NOT_VALIDATED         213
#define ERROR_DISK_WRITE_PROTECTED       214
#define ERROR_RENAME_ACROSS_DEVICES      215
#define ERROR_DIRECTORY_NOT_EMPTY        216
#define ERROR_TOO_MANY_LEVELS            217
#define ERROR_DEVICE_NOT_MOUNTED         218
#define ERROR_SEEK_ERROR                 219
#define ERROR_COMMENT_TOO_BIG            220
#define ERROR_DISK_FULL                  221
#define ERROR_DELETE_PROTECTED           222
#define ERROR_WRITE_PROTECTED            223
#define ERROR_READ_PROTECTED             224
#define ERROR_NOT_A_DOS_DISK             225
#define ERROR_NO_DISK                    226
#define ERROR_NO_MORE_ENTRIES            232

/****************************************************************************/

/* added for 1.4 */
#define ERROR_IS_SOFT_LINK               233
#define ERROR_OBJECT_LINKED              234
#define ERROR_BAD_HUNK                   235
#define ERROR_NOT_IMPLEMENTED            236
#define ERROR_RECORD_NOT_LOCKED          240
#define ERROR_LOCK_COLLISION             241
#define ERROR_LOCK_TIMEOUT               242
#define ERROR_UNLOCK_ERROR               243

/****************************************************************************/

/* ErrorReport() special code, (see dosextens.h) */  
/* #define ABORT_BUSY                    288    "You MUST replace..." */
/* #define ABORT_DISK_ERROR              296    Read/write error */

/****************************************************************************/

#define ERROR_BUFFER_OVERFLOW            303    /* User or internal buffer
                                                   overflow */
#define ERROR_BREAK                      304    /* A break character was
                                                   received */
#define ERROR_NOT_EXECUTABLE             305    /* A file has E bit cleared */

#define ERROR_IS_PIPE                    306    /* Operation is not permitted
                                                   on pipes */
#define ERROR_BROKEN_PIPE                307    /* No more data can be read
                                                   from or written to this
                                                   pipe */
#define ERROR_WOULD_BLOCK                308    /* Operation cannot complete
                                                   immediately, as requested */

#define ERROR_BAD_SIGNAL_BIT             309    /* An invalid signal bit number
                                                   was specified */

/****************************************************************************/

#define ERROR_UNSUPPORTED_HARDWARE       350    /* The hardware found is
                                                   unsupported by software */

/****************************************************************************/

/* Special error codes that can be set by MountDevice(). */

/* Device to be mounted is neither handler nor file system. */
#define ERROR_INVALID_DEVICE_TYPE        401

/* Name of device to be mounted does contain more colon characters
   than necessary, or in the wrong place */
#define ERROR_INVALID_DEVICE_NAME        402

/* Name of device to be mounted is longer than 255 characters */
#define ERROR_DEVICE_NAME_TOO_LONG       403

/* Sector size is not a multiple of four */
#define ERROR_INVALID_SECTOR_SIZE        404

/* Control string for device to be mounted is longer than 255 characters */
#define ERROR_CONTROL_STRING_TOO_LONG    405

/* Exec device driver name for device to be mounted is longer than 255
   characters */
#define ERROR_EXEC_DEVICE_NAME_TOO_LONG  406

/* Name of handler to be mounted is longer than 255 characters */
#define ERROR_HANDLER_STRING_TOO_LONG    407

/* Startup string for device to be mounted is longer than 255 characters */
#define ERROR_STARTUP_STRING_TOO_LONG    408

/* Number of surfaces, sector size, number of sectors per block or number
   of sectors per track is zero */
#define ERROR_SIZE_MISSING               409

/* No exec device driver name was given */
#define ERROR_DEVICE_NAME_MISSING        410

/* Number of cylinders to use is negative */
#define ERROR_INVALID_NUMBER_OF_CYLINDERS 411

/* No handler name, segment list or port address was given */
#define ERROR_HANDLER_CANNOT_BE_STARTED   412

/* Global vector must be one of -2 or -1 */
#define ERROR_INVALID_GLOBAL_VECTOR       413

/* The task priority is not in the range -128..127 */
#define ERROR_INVALID_TASK_PRIORITY       414

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* DOS_ERRORS_H */
