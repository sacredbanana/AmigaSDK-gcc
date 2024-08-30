#ifndef DEVICES_PARALLEL_H
#define DEVICES_PARALLEL_H

/*
	parallel.device include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_IO_H
# include <exec/io.h>
#endif

#pragma pack(2)


struct IOPArray
{
	ULONG PTermArray0;
	ULONG PTermArray1;
};


struct IOExtPar
{
	struct IOStdReq IOPar;

	ULONG           io_PExtFlags;
	UBYTE           io_Status;
	UBYTE           io_ParFlags;
	struct IOPArray io_PTermArray;
};


/* io_ParFlags values */

#define PARB_SHARED      5
#define PARF_SHARED      (1<<PARB_SHARED)
#define PARB_SLOWMODE    4
#define PARF_SLOWMODE    (1<<PARB_SLOWMODE)
#define PARB_FASTMODE    3
#define PARF_FASTMODE    (1<<PARB_FASTMODE)
#define PARB_RAD_BOOGIE  3
#define PARF_RAD_BOOGIE  (1<<PARB_RAD_BOOGIE)

#define PARB_ACKMODE     2
#define PARF_ACKMODE     (1<<PARB_ACKMODE)

#define PARB_EOFMODE     1
#define PARF_EOFMODE     (1<<PARB_EOFMODE)

/* MorphOS extension for Pegasos */

#define PARF_MODEMASK    0xc0
#define PARMODE_STD      0x00           /* Standard parallel mode */
#define PARMODE_EPP      0x40           /* EPP mode */
#define PARMODE_ECP      0x80           /* ECP mode, RLE compression disabled */
#define PARMODE_ECP_COMP 0xc0           /* ECP mode, RLE compression enabled */


/* io_Status values */

#define IOPARB_QUEUED    6
#define IOPARF_QUEUED    (1<<IOPARB_QUEUED)
#define IOPARB_ABORT     5
#define IOPARF_ABORT     (1<<IOPARB_ABORT)
#define IOPARB_ACTIVE    4
#define IOPARF_ACTIVE    (1<<IOPARB_ACTIVE)

#define IOPTB_RWDIR      3
#define IOPTF_RWDIR      (1<<IOPTB_RWDIR)
#define IOPTB_PARSEL     2
#define IOPTF_PARSEL     (1<<IOPTB_PARSEL)
#define IOPTB_PAPEROUT   1
#define IOPTF_PAPEROUT   (1<<IOPTB_PAPEROUT)
#define IOPTB_PARBUSY    0
#define IOPTF_PARBUSY    (1<<IOPTB_PARBUSY)


#define PARALLELNAME  "parallel.device"


#define PDCMD_QUERY      (CMD_NONSTD + 0)
#define PDCMD_SETPARAMS  (CMD_NONSTD + 1)


#define ParErr_DevBusy    1
#define ParErr_BufTooBig  2
#define ParErr_InvParam   3
#define ParErr_LineErr    4
#define ParErr_NotOpen    5
#define ParErr_PortReset  6
#define ParErr_InitErr    7


#pragma pack()

#endif /* DEVICES_PARALLEL_H */
