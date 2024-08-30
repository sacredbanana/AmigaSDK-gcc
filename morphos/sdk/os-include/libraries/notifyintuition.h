#ifndef LIBRARIES_NOTIFYINTUITION_H
#define LIBRARIES_NOTIFYINTUITION_H

/*
	notifyintuition library include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef EXEC_TASKS_H
#include <exec/tasks.h>
#endif

#pragma pack(2)


#define NOTIFYINTUITIONNAME     "notifyintuition.library"
#define NOTIFYINTUITION_VMIN    2


struct IntNotifyRequest
{
	UBYTE *inr_Name;

	UBYTE *inr_Tokenstring;
	ULONG  inr_UserData;
	ULONG  inr_Flags;

	union
	{
		struct
		{
			struct Task    *inr_Task;
		} inr_Signal;
		struct
		{
			struct MsgPort *inr_Port;
		} inr_Msg;
		struct
		{
			APTR            inr_Hook;
		} inr_Hook;
	} inr_stuff;

	UBYTE  inr_SignalNum;
	BYTE   inr_Error;

	BYTE   inr_Pri;
	BYTE   inr_pad;

	ULONG  inr_UniqueID;

	ULONG  inr_Reserved[3];

	ULONG  inr_MsgCount;
	APTR   inr_ReqSemaphore;
};

#define inr_Task inr_stuff.inr_Signal.inr_Task
#define inr_Port inr_stuff.inr_Msg.inr_Task
#define inr_Hook inr_stuff.inr_Hook.inr_Task


struct IntNotifyMessage
{
	struct Message inm_Message;

	ULONG          inm_Class;
	UWORD          inm_Code;

	struct IntNotifyRequest *inm_NReq;

	APTR           inm_IntObject;
	APTR           inm_TagListPtr;

	struct Task   *inm_Task;
	ULONG          inm_DoNotTouch1;
};


#define INTNOTIFY_CLASS               0x43210000

#define INRF_SEND_MESSAGE                (1UL <<  0)
#define INRF_SEND_SIGNAL                 (1UL <<  1)
#define INRF_USE_HOOK                    (1UL <<  2)
#define INRF_WAIT_REPLY                  (1UL <<  4)
#define INRF_NOTIFY_INITIAL              (1UL <<  5)
#define INRF_BEFORE_OPENSCREEN           (1UL <<  6)
#define INRF_AFTER_OPENSCREEN            (1UL <<  7)
#define INRF_BEFORE_CLOSESCREEN          (1UL <<  8)
#define INRF_AFTER_CLOSEWINDOW_ON_SCREEN (1UL <<  9)
#define INRF_AFTER_PUBSCREENMODE         (1UL << 10)
#define INRF_BEFORE_OPENWINDOW           (1UL << 11)
#define INRF_AFTER_OPENWINDOW            (1UL << 12)
#define INRF_BEFORE_CLOSEWINDOW          (1UL << 13)
#define INRF_AFTER_OPENWORKBENCH         (1UL << 14)
#define INRF_BEFORE_CLOSEWORKBENCH       (1UL << 15)
#define INRF_BEFORE_LOCKPUBSCREEN        (1UL << 16)
#define INRF_AFTER_SCREENTOFRONT         (1UL << 17)
#define INRF_AFTER_SCREENTOBACK          (1UL << 18)
#define INRF_NOT_MYOWNREQUEST            (1UL << 23)

#define INR_LIBRARY_FLAGS             0xff000000

#define INRCODE_BEFORE_OPENSCREEN     0x0001
#define INRCODE_AFTER_OPENSCREEN      0x0002
#define INRCODE_BEFORE_CLOSESCREEN    0x0004
#define INRCODE_AFTER_CLOSEWINSCREEN  0x0008
#define INRCODE_AFTER_CHANGEPUBMODE   0x0010
#define INRCODE_BEFORE_OPENWINDOW     0x0020
#define INRCODE_AFTER_OPENWINDOW      0x0040
#define INRCODE_BEFORE_CLOSEWINDOW    0x0080
#define INRCODE_AFTER_OPENWORKBENCH   0x0100
#define INRCODE_BEFORE_CLOSEWORKBENCH 0x0200
#define INRCODE_BEFORE_LOCKPUBSCREEN  0x0400
#define INRCODE_AFTER_SCREENTOFRONT   0x0800
#define INRCODE_AFTER_SCREENTOBACK    0x1000

#define INRERROR_UNIQUE                98
#define INRERROR_NOFLAGS               99
#define INRERROR_WRONGTYPE            100
#define INRERROR_NOSIGNAL             101
#define INRERROR_NOTHINGTODO          102
#define INRERROR_LOWMEM               103
#define INRERROR_OUTSTANDING_MSGS     -1
#define INRERROR_ISLOCKED             -2
#define INRERROR_UNKNOWN              -3
#define INRERROR_INUSE                -4


#pragma pack()

#endif /* LIBRARIES_NOTIFYINTUITION_H */
