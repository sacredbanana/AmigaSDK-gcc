/*
 * $Id: fs_notify_test.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 * :ts=4
 */

#include <dos/dosextens.h>
#include <dos/notify.h>

#include <string.h>

/******************************************************************************/

/* Kludge for new utility.library header files... */
#define UTILITY_DATA_STRUCTURES_H

#define __NOLIBBASE__
#include <proto/exec.h>
#include <proto/dos.h>

/****************************************************************************/

extern struct Library *SysBase;
extern struct Library *DOSBase;

/****************************************************************************/

#if defined(__amigaos4__)
extern struct ExecIFace *	IExec;
extern struct DOSIFace *	IDOS;
#endif /* __amigaos4__ */

/****************************************************************************/

#ifndef __amigaos4__

struct NewNotifyRequest
{
	UBYTE *	nr_Name;
	UBYTE *	nr_FullName;	/* set by dos - don't touch */
	ULONG	nr_UserData;	/* for applications use */
	ULONG	nr_Flags;

	union
	{
		struct
		{
			struct MsgPort * nr_Port;	/* for SEND_MESSAGE */
	    } nr_Msg;

	    struct
		{
			struct Task *	nr_Task;		/* for SEND_SIGNAL */
			UBYTE			nr_SignalNum;	/* for SEND_SIGNAL */
			UBYTE			nr_pad[3];
		} nr_Signal;

		struct
		{
			struct Hook * nr_Hook;		/* for CALL_HOOK */
		} nr_CallHook;
	} nr_stuff;

	ULONG				nr_Reserved[4];	/* leave 0 for now */

	/* internal use by handlers */
	ULONG				nr_MsgCount;	/* # of outstanding msgs */
	struct MsgPort *	nr_Handler;		/* handler sent to (for EndNotify) */
};

#define NotifyRequest NewNotifyRequest

/* NotifyRequest Flags  */
#define NRF_CALL_HOOK	32

/* bit numbers */
#define NRB_CALL_HOOK	5

struct NotifyHookMsg
{
	LONG	nhm_Size;
	LONG	nhm_Action;
	STRPTR	nhm_Name;
};

#define NHM_ACTION_INITIAL	-1
#define NHM_ACTION_ADD		0
#define NHM_ACTION_CHANGE	1
#define NHM_ACTION_DELETE	2

#endif /* __amigaos4 __*/

/******************************************************************************/

extern void kprintf(const char * fmt,...);

/******************************************************************************/

LONG __saveds __asm
hook_function(
	register __a0 struct Hook *				hooh,
	register __a2 APTR						reserved,
	register __a1 struct NotifyHookMsg *	nhm)
{
	switch(nhm->nhm_Action)
	{
		case NHM_ACTION_INITIAL:

			kprintf("NHM_ACTION_INITIAL: ");
			break;

		case NHM_ACTION_ADD:

			kprintf("NHM_ACTION_ADD: ");
			break;

		case NHM_ACTION_CHANGE:

			kprintf("NHM_ACTION_CHANGE: ");
			break;

		case NHM_ACTION_DELETE:

			kprintf("NHM_ACTION_DELETE: ");
			break;

		default:

			kprintf("%ld: ",nhm->nhm_Action);
			break;
	}

	if(nhm->nhm_Name != NULL)
		kprintf("'%s'\n",nhm->nhm_Name);
	else
		kprintf("-\n");

	return(0);
}

/******************************************************************************/

int
main(int argc,char ** argv)
{
	int return_code = RETURN_ERROR;

	if(argc > 1)
	{
		struct NotifyRequest nr;
		struct Hook hook;

		memset(&nr,0,sizeof(nr));
		memset(&hook,0,sizeof(hook));

		nr.nr_Name						= (STRPTR)argv[1];
		nr.nr_Flags						= NRF_CALL_HOOK;
		nr.nr_stuff.nr_CallHook.nr_Hook	= &hook;

		hook.h_Entry = (HOOKFUNC)hook_function;

		if(StartNotify((struct NotifyRequest *)&nr))
		{
			Printf("Notification for '%s' installed; ^C to stop... ",argv[1]);
			Flush(Output());

			Wait(SIGBREAKF_CTRL_C);

			EndNotify((struct NotifyRequest *)&nr);

			Printf("Stopped.\n");

			return_code = RETURN_OK;
		}
		else
		{
			PrintFault(IoErr(),argv[1]);
		}
	}
	else
	{
		PrintFault(ERROR_REQUIRED_ARG_MISSING,argv[0]);
	}

	return(return_code);
}
