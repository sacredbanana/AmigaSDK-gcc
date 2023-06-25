#ifndef DEVICES_PARALLEL_H
#define DEVICES_PARALLEL_H
/*
**    $VER: parallel.h 54.16 (22.08.2022)
**
**    parallel.device I/O request structure information
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All rights reserved.
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_IO_H
#include <exec/io.h>
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

struct IOPArray
{
    ULONG PTermArray0;
    ULONG PTermArray1;
};

/****************************************************************************/

/****************************************************************** 
   CAUTION !!  IF YOU ACCESS the parallel.device, you MUST (!!!!) use
   an IOExtPar-sized structure or you may overlay innocent memory !!
 ******************************************************************/

struct IOExtPar
{
    struct IOStdReq IOPar;

/*     STRUCT MsgNode
*   0    APTR  Succ
*   4    APTR  Pred
*   8    UBYTE Type
*   9    UBYTE Pri
*   A    APTR  Name
*   E    APTR  ReplyPort
*  12    UWORD MNLength
*     STRUCT IOExt
*  14    APTR  io_Device
*  18    APTR  io_Unit
*  1C    UWORD io_Command
*  1E    UBYTE io_Flags
*  1F    UBYTE io_Error
*     STRUCT IOStdExt
*  20    ULONG io_Actual
*  24    ULONG io_Length
*  28    APTR  io_Data
*  2C    ULONG io_Offset
*  30
*/
    ULONG           io_PExtFlags;  /* (not used) flag extension area */
    UBYTE           io_Status;     /* status of parallel port and registers */
    UBYTE           io_ParFlags;   /* see PARFLAGS bit definitions below */
    struct IOPArray io_PTermArray; /* termination character array */
};

/****************************************************************************/

#define PARB_SHARED     5      /* ParFlags non-exclusive access bit */
#define PARF_SHARED     (1<<5) /*     "     non-exclusive access mask */
#define PARB_SLOWMODE   4      /*     "     slow printer bit */
#define PARF_SLOWMODE   (1<<4) /*     "     slow printer mask */
#define PARB_FASTMODE   3      /*     "     fast I/O mode selected bit */
#define PARF_FASTMODE   (1<<3) /*     "     fast I/O mode selected mask */
#define PARB_RAD_BOOGIE 3      /*     "     for backward compatibility */
#define PARF_RAD_BOOGIE (1<<3) /*     "     for backward compatibility */

#define PARB_ACKMODE    2      /*     "     ACK interrupt handshake bit */
#define PARF_ACKMODE    (1<<2) /*     "     ACK interrupt handshake mask */

#define PARB_EOFMODE    1      /*     "     EOF mode enabled bit */
#define PARF_EOFMODE    (1<<1) /*     "     EOF mode enabled mask */

#define IOPARB_QUEUED   6      /* IO_FLAGS rqst-queued bit */
#define IOPARF_QUEUED   (1<<6) /*     "     rqst-queued mask */
#define IOPARB_ABORT    5      /*     "     rqst-aborted bit */
#define IOPARF_ABORT    (1<<5) /*     "     rqst-aborted mask */
#define IOPARB_ACTIVE   4      /*     "     rqst-qued-or-current bit */
#define IOPARF_ACTIVE   (1<<4) /*     "     rqst-qued-or-current mask */
#define IOPTB_RWDIR     3      /* IO_STATUS read=0,write=1 bit */
#define IOPTF_RWDIR     (1<<3) /*     "     read=0,write=1 mask */
#define IOPTB_PARSEL    2      /*     "     printer selected on the A1000 */
#define IOPTF_PARSEL    (1<<2) /* printer selected & serial "Ring Indicator"
                                  on the A500 & A2000.  Be careful when
                                  making cables */
#define IOPTB_PAPEROUT  1      /*     "     paper out bit */
#define IOPTF_PAPEROUT  (1<<1) /*     "     paper out mask */
#define IOPTB_PARBUSY   0      /*     "     printer in busy toggle bit */
#define IOPTF_PARBUSY   (1<<0) /*     "     printer in busy toggle mask */
/* Note: previous versions of this include files had bits 0 and 2 swapped */

/****************************************************************************/

#define PARALLELNAME "parallel.device"

/****************************************************************************/

#define PDCMD_QUERY     (CMD_NONSTD)
#define PDCMD_SETPARAMS (CMD_NONSTD+1)

/****************************************************************************/

#define ParErr_DevBusy   1
#define ParErr_BufTooBig 2
#define ParErr_InvParam  3
#define ParErr_LineErr   4
#define ParErr_NotOpen   5
#define ParErr_PortReset 6
#define ParErr_InitErr   7

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

#endif /* DEVICES_PARALLEL_H */
