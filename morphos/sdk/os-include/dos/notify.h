#ifndef DOS_NOTIFY_H
#define DOS_NOTIFY_H

/*
	dos notification definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef EXEC_TASKS_H
# include <exec/tasks.h>
#endif

#pragma pack(2)


#define NOTIFY_CLASS  0x40000000
#define NOTIFY_CODE   0x1234


struct NotifyMessage
{
	struct Message        nm_ExecMessage;
	ULONG                 nm_Class;
	UWORD                 nm_Code;
	struct NotifyRequest *nm_NReq;
	ULONG                 nm_DoNotTouch;
	ULONG                 nm_DoNotTouch2;
};

struct NotifyRequest
{
	UBYTE          *nr_Name;
	UBYTE          *nr_FullName;
	ULONG           nr_UserData;
	ULONG           nr_Flags;

	union
	{
		struct
		{
			struct MsgPort *nr_Port;
		} nr_Msg;

		struct
		{
			struct Task *nr_Task;
			UBYTE        nr_SignalNum;
			UBYTE        nr_pad[3];
		} nr_Signal;
	}               nr_stuff;

	ULONG           nr_Reserved[4];

	ULONG           nr_MsgCount;
	struct MsgPort *nr_Handler;
};


#define NRB_SEND_MESSAGE    0
#define NRB_SEND_SIGNAL     1
#define NRB_WAIT_REPLY      3
#define NRB_NOTIFY_INITIAL  4

#define NRB_MAGIC           31

#define NRF_SEND_MESSAGE    (1<<NRB_SEND_MESSAGE)
#define NRF_SEND_SIGNAL     (1<<NRB_SEND_SIGNAL)
#define NRF_WAIT_REPLY      (1<<NRB_WAIT_REPLY)
#define NRF_NOTIFY_INITIAL  (1<<NRB_NOTIFY_INITIAL)

#define NRF_MAGIC           (1<<NRB_MAGIC)


#define NR_HANDLER_FLAGS  0xffff0000


#pragma pack()

#endif /* DOS_NOTIFY_H */
