#ifndef DEVICES_SERIAL_H
#define DEVICES_SERIAL_H

/*
	serial.device include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_IO_H
# include <exec/io.h>
#endif

#pragma pack(2)


struct IOTArray
{
	ULONG TermArray0;
	ULONG TermArray1;
};


#define SER_DEFAULT_CTLCHAR  0x11130000


struct IOExtSer
{
	struct IOStdReq IOSer;

	ULONG            io_CtlChar;
	ULONG            io_RBufLen;
	ULONG            io_ExtFlags;
	ULONG            io_Baud;
	ULONG            io_BrkTime;
	struct IOTArray  io_TermArray;
	UBYTE            io_ReadLen;
	UBYTE            io_WriteLen;
	UBYTE            io_StopBits;
	UBYTE            io_SerFlags;
	UWORD            io_Status;
};


#define SDCMD_QUERY      (CMD_NONSTD + 0)
#define SDCMD_BREAK      (CMD_NONSTD + 1)
#define SDCMD_SETPARAMS  (CMD_NONSTD + 2)


#define SERB_XDISABLED       7
#define SERF_XDISABLED       (1<<SERB_XDISABLED)
#define SERB_EOFMODE         6
#define SERF_EOFMODE         (1<<SERB_EOFMODE)
#define SERB_SHARED          5
#define SERF_SHARED          (1<<SERB_SHARED)
#define SERB_RAD_BOOGIE      4
#define SERF_RAD_BOOGIE      (1<<SERB_RAD_BOOGIE)
#define SERB_QUEUEDBRK       3
#define SERF_QUEUEDBRK       (1<<SERB_QUEUEDBRK)
#define SERB_7WIRE           2
#define SERF_7WIRE           (1<<SERB_7WIRE)
#define SERB_PARTY_ODD       1
#define SERF_PARTY_ODD       (1<<SERB_PARTY_ODD)
#define SERB_PARTY_ON        0
#define SERF_PARTY_ON        (1<<SERB_PARTY_ON)

#define IO_STATB_XOFFREAD    12
#define IO_STATF_XOFFREAD    (1<<IO_STATB_XOFFREAD)
#define IO_STATB_XOFFWRITE   11
#define IO_STATF_XOFFWRITE   (1<<IO_STATB_XOFFWRITE)
#define IO_STATB_READBREAK   10
#define IO_STATF_READBREAK   (1<<IO_STATB_READBREAK)
#define IO_STATB_WROTEBREAK  9
#define IO_STATF_WROTEBREAK  (1<<IO_STATB_WROTEBREAK)
#define IO_STATB_OVERRUN     8
#define IO_STATF_OVERRUN     (1<<IO_STATB_OVERRUN)


#define SEXTB_MSPON  1
#define SEXTF_MSPON  (1<<SEXTB_MSPON)
#define SEXTB_MARK   0
#define SEXTF_MARK   (1<<SEXTB_MARK)


#define SerErr_DevBusy         1
#define SerErr_BaudMismatch    2
#define SerErr_BufErr          4
#define SerErr_InvParam        5
#define SerErr_LineErr         6
#define SerErr_ParityErr       9
#define SerErr_TimerErr       11
#define SerErr_BufOverflow    12
#define SerErr_NoDSR          13
#define SerErr_DetectedBreak  15


#ifdef DEVICES_SERIAL_H_OBSOLETE

#define SerErr_InvBaud    3
#define SerErr_NotOpen    7
#define SerErr_PortReset  8
#define SerErr_InitErr    10
#define SerErr_NoCTS      14

#define IOSTB_XOFFREAD    4
#define IOSTF_XOFFREAD    (1<<IOSTB_XOFFREAD)
#define IOSTB_XOFFWRITE   3
#define IOSTF_XOFFWRITE   (1<<IOSTB_XOFFWRITE)
#define IOSTB_READBREAK   2
#define IOSTF_READBREAK   (1<<IOSTB_READBREAK)
#define IOSTB_WROTEBREAK  1
#define IOSTF_WROTEBREAK  (1<<IOSTB_WROTEBREAK)
#define IOSTB_OVERRUN     0
#define IOSTF_OVERRUN     (1<<IOSTB_OVERRUN)

#define IOSERB_BUFRREAD   7
#define IOSERF_BUFRREAD   (1<<IOSERB_BUFRREAD)
#define IOSERB_QUEUED     6
#define IOSERF_QUEUED     (1<<IOSERB_QUEUED)
#define IOSERB_ABORT      5
#define IOSERF_ABORT      (1<<IOSERB_ABORT)
#define IOSERB_ACTIVE     4
#define IOSERF_ACTIVE     (1<<IOSERB_ACTIVE)

#endif /* DEVICES_SERIAL_H_OBSOLETE */


#define SERIALNAME  "serial.device"


#pragma pack()

#endif /* DEVICES_SERIAL_H */
