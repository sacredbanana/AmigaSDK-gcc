#ifndef DOS_RECORD_H
#define DOS_RECORD_H
/*
**    $VER: record.h  54.100 (07.09.2020)
**
**    include file for record locking
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef DOS_DOS_H
#include <dos/dos.h>
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
/* Modes for LockRecord/LockRecords() */

#define REC_EXCLUSIVE          0
#define REC_EXCLUSIVE_IMMED    1
#define REC_SHARED             2
#define REC_SHARED_IMMED       3

/*
** Control flags to be ORed with any mode value above.
** This forces the use of the DOS method, regardless of whether 
** the underlying filesystem supports record locking or not. - Added 53.114 
*/
#define RECF_DOS_METHOD_ONLY   (1<<16)

/*
** Control flag mask used to filter mode values from control flags.
** This is generally used internally and of no real use to applications. 
*/
#define REC_MODE_MASK          0xFF



/****************************************************************************/
/* Struct to be passed to LockRecords()/UnLockRecords() v53.86+             */
/* Note: the rec_Size member MUST be set in each struct or it won't work.   */ 

struct RecordLock
{
    uint32   rec_Size;       /* This MUST be set to sizeof(struct RecordLock) */  
    BPTR     rec_FH;         /* filehandle */
    int64    rec_Offset;     /* offset in file */
    int64    rec_Length;     /* length of file record to be locked */
    uint32   rec_Mode;       /* Mode of lock, as defined above. */
};



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

#endif /* DOS_RECORD_H */
