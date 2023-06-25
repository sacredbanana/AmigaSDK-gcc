/*
 * $Id: fs_simple_notify_test.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 * :ts=4
 */

#include <dos/dosextens.h>
#include <dos/notify.h>

#include <string.h>

#define __NOLIBBASE__
#include <proto/dos.h>
#include <proto/exec.h>

/****************************************************************************/

extern struct Library *SysBase;
extern struct Library *DOSBase;

/****************************************************************************/

#if defined(__amigaos4__)
extern struct ExecIFace *	IExec;
extern struct DOSIFace *	IDOS;
#endif /* __amigaos4__ */

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

		nr.nr_Name							= (STRPTR)argv[1];
		nr.nr_Flags							= NRF_SEND_SIGNAL;
		nr.nr_stuff.nr_Signal.nr_Task		= (struct Task *)FindTask(NULL);
		nr.nr_stuff.nr_Signal.nr_SignalNum	= SIGBREAKB_CTRL_D;

		if(StartNotify(&nr))
		{
			ULONG signals;
			BOOL done;

			Printf("Notification for '%s' installed; ^C to stop...\n",argv[1]);

			done = FALSE;

			do
			{
				signals = Wait(SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_D);

				if(signals & SIGBREAKF_CTRL_D)
					Printf("'%s' has changed.\n",argv[1]);

				if(signals & SIGBREAKF_CTRL_C)
					done = TRUE;
			}
			while( !done );

			EndNotify((struct NotifyRequest *)&nr);

			VPrintf("Stopped.\n", NULL);

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
