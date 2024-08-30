/* procmessages.c - Example program for the NP_StartupMsg and NP_TaskMsgPort
 *                  features
 *
 ***************************************************************************
 ***************************************************************************
 ***************************************************************************
 ***************************************************************************
 *
 * TASKTAG_STARTUPMSG / NP_StartupMsg / TASKINFOTYPE_STARTUPMSG
 *
 * Startup message to be passed to task/process, ReplyMsg'd at RemTask().
 * ti_Data: struct Message *
 *
 * TASKTAG_STARTUPMSG is used with AddTask()'s struct TaskInitExtension
 * taglist. NP_StartupMsg is used with CreateNewProc() taglist.
 *
 * You can get pointer to this message with NewGetTaskAttrs()
 * TASKINFOTYPE_STARTUPMSG.
 *
 ***************************************************************************
 ***************************************************************************
 ***************************************************************************
 ***************************************************************************
 *
 * TASKTAG_TASKMSGPORT / NP_TaskMsgPort / TASKINFOTYPE_TASKMSGPORT
 *
 * Create internal MsgPort for task/process, deleted at RemTask().
 * ti_Data: struct MsgPort **, can be NULL, in which case no local pointer
 * is saved. Use NULL if you don't need the MsgPort pointer in the parent
 * task/process.
 *
 * TASKTAG_TASKMSGPORT is used with AddTask()'s struct TaskInitExtension
 * taglist. NP_TaskMsgPort is used with CreateNewProc() taglist.
 *
 * You can get pointer to this msgport with NewGetTaskAttrs()
 * TASKINFOTYPE_TASKMSGPORT.
 *
 ***************************************************************************
 ***************************************************************************
 ***************************************************************************
 ***************************************************************************
 *
 * A WORD OF WARNING
 *
 * These new tags are only available in morphos-20020827.lha and later
 * releases.
 *
 ***************************************************************************
 ***************************************************************************
 ***************************************************************************
 ***************************************************************************
 *
 *  Written by Harry Sintonen.
 */

#define USE_INLINE_STDARG

#include <exec/nodes.h>
#include <exec/ports.h>
#include <exec/tasks.h>
#include <exec/libraries.h>
#include <exec/devices.h>
#include <exec/execbase.h>
#include <devices/timer.h>
#include <dos/dos.h>
#include <dos/dostags.h>

#include <proto/exec.h>
#include <proto/dos.h>


/* Custom startup message
 */
struct startupmsg
{
  struct Message  msg;		/* MUST be the first thing in the message */

  /* Could be anything here...
   */
  LONG            delaysecs;
  LONG            result;
};


/* Protos
 */
int main(void);
void subproc(void);



/* Custom kprintf, output to sushi/sashimi
 */
#if 1
#ifdef kprintf
#undef kprintf
#endif
static const
UWORD __dputch[5] = {0xCD4B, 0x4EAE, 0xFDFC, 0xCD4B, 0x4E75};
#define kprintf(fmt, tags...) \
	({ULONG _tags[] = { 0 , ## tags }; RawDoFmt(fmt, (APTR)&_tags[1], \
          (void (*)(void)) __dputch, (APTR) SysBase);})
#endif


int main(void)
{
	struct ExecBase *SysBase;
	struct DosLibrary *DOSBase;
	int ret;

	SysBase = *((struct ExecBase **) 4);
	ret = RETURN_FAIL;

	DOSBase = (struct DosLibrary *) OpenLibrary("dos.library", 50);
	if (DOSBase)
	{
		struct MsgPort *replyport;

		Printf("parent: entry.\n");

		replyport = CreateMsgPort();
		if (replyport)
		{
			struct startupmsg *msg;

			msg = AllocVec(sizeof(struct startupmsg), MEMF_PUBLIC);
			if (msg)
			{
				struct Process *proc;
				struct MsgPort *port;

				/* Standard message stuff
				 */
				msg->msg.mn_Node.ln_Type = NT_MESSAGE;
				msg->msg.mn_ReplyPort    = replyport;
				msg->msg.mn_Length       = sizeof(struct startupmsg);

				/* Set the parameters passed to subproc
				 */
				msg->delaysecs           = 5;

				proc = CreateNewProcTags(NP_CodeType,    CODETYPE_PPC,
				                         NP_Entry,       (ULONG) subproc,
				                         NP_StartupMsg,  (ULONG) msg,
				                         NP_TaskMsgPort, (ULONG) &port,
				                         TAG_DONE);
				if (proc)
				{
					struct startupmsg *reply;

					/* The port is not really used for anything here, but it could
					 * be used to pass custom messages to child. Note that port is
					 * only valid while the subproc is running. The port will
					 * disappear as soon as the child exit, so you must be careful
					 * not to screw up if you use it to pass messages. Leaving
					 * any messages to this port is illegal and will cause Alert()
					 * at subproc exit.
					 */
					Printf("parent: port: 0x%lx\n", (ULONG) port);

					/* Here we wait for the child process to exit.
					 */
					Printf("parent: waiting child 0x%lx to exit...\n", (ULONG) proc);
					WaitPort(replyport);

					/* Obviously if replyport would be shared with something else,
					 * it could get some other message here. But since this port
					 * is exclusive for startup message, it can't be anything else.
					 */
					reply = (struct startupmsg *) GetMsg(replyport);
					Printf("parent: got reply startupmsg 0x%lx...\n", (ULONG) reply);

					/* Dump the field to show that things can be passed back in
					 * the message.
					 */
					Printf("parent: reply->result: %ld\n", reply->result);

					ret = RETURN_OK;
				}
				else
				{
					Printf("parent: failed to start the subproc!\n");
				}

				/* Note that the message memory MUST only be released after
				 * receiving the reply. Releasing it before the subproc exit
				 * will lead to guaranteed crash (or at least random memory
				 * trash).
				 */
				FreeVec(msg);
			}
			else
			{
				Printf("parent: no message memory!\n");
			}

			DeleteMsgPort(replyport);
		}
		else
		{
			Printf("parent: no replyport!\n");
		}

		Printf("parent: exit.\n");

		CloseLibrary((struct Library *) DOSBase);
	}
	else
	{
		kprintf("parent: could not open dos.library V50\n");
	}

	return ret;
}

void subproc(void)
{
	struct ExecBase *SysBase = *(struct ExecBase **) 4;
	struct startupmsg *msg;

	kprintf("child: entry.\n");

	/* Get the startup message passed with NP_StartupMsg.
	 */
	if (NewGetTaskAttrs(NULL, &msg, sizeof(struct startupmsg *),
	                    TASKINFOTYPE_STARTUPMSG,
	                    TAG_DONE) && msg)
	{
		struct MsgPort *port;

		kprintf("child: startupmsg: 0x%lx\n", (ULONG) msg);

		/* Set default result
		 */
		msg->result = FALSE;


		/* Get the msgport created by NP_TaskMsgPort.
		 */
		if (NewGetTaskAttrs(NULL, &port, sizeof(struct MsgPort *),
		                    TASKINFOTYPE_TASKMSGPORT,
		                    TAG_DONE) && port)
		{
			struct timerequest *ioreq;

			kprintf("child: msgport: 0x%lx\n", (ULONG) port);

			ioreq = (struct timerequest *) CreateIORequest(port,
			sizeof(struct timerequest));
			if (ioreq)
			{
				if (!OpenDevice(TIMERNAME, UNIT_VBLANK, (struct IORequest *) ioreq,
				                0))
				{

					kprintf("child: waiting %ld seconds using timer.device.\n",
					        msg->delaysecs);

					ioreq->tr_node.io_Command = TR_ADDREQUEST;
					ioreq->tr_time.tv_secs    = msg->delaysecs;
					ioreq->tr_time.tv_micro   = 0;
					DoIO(&ioreq->tr_node);

					/* Just do something to demonstrate you can pass values back to
					 * parent, too.
					 */
					msg->result = TRUE;

					CloseDevice(&ioreq->tr_node);
				}
				else
				{
					kprintf("child: could not open timer.device!\n");
				}

				DeleteIORequest(&ioreq->tr_node);
			}
			else
			{
				kprintf("child: could not create timer iorequest!\n");
			}

			/* NOTE: Must not delete the port, it is deleted automagically!
			 */
		}
		else
		{
			kprintf("child: oops, no msgport!\n");
		}
	}
	else
    {
		kprintf("child: oops, could not get startupmsg!\n");
	}

	kprintf("child: all done, exit.\n");

	/* The startup message (msg) is replied by exec.library internally,
	 * you must *NOT* ReplyMsg() it.
	 */
}

