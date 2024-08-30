/*----------------------------------------------------------------------------*/
/* Reggae example: playing audio file from disk, end of sound is signalled    */
/* with a message reply. File name is read from the commandline.              */
/*                                                                            */
/* This example has only very basic error handling without user feedback.     */
/* This is done for code simplicity. Reggae problems may be traced with       */
/* MediaLogger tool.                                                          */
/* ---------------------------------------------------------------------------*/

#define __NOLIBBASE__
#define USE_INLINE_STDARG

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/multimedia.h>
#include <exec/memory.h>
#include <classes/multimedia/sound.h>


extern struct Library *SysBase, *DOSBase;
struct Library *IntuitionBase, *MultimediaBase, *AudioOutputBase;
CONST_STRPTR Template = "FILE/A";


BOOL init_resources(VOID)
{
	if (!(IntuitionBase = OpenLibrary("intuition.library", 50))) return FALSE;
	if (!(MultimediaBase = OpenLibrary("multimedia/multimedia.class", 52))) return FALSE;
	if (!(AudioOutputBase = OpenLibrary("multimedia/audio.output", 51))) return FALSE;
	return TRUE;
}



VOID free_resources(VOID)
{
	if (AudioOutputBase) CloseLibrary(AudioOutputBase);
	if (MultimediaBase) CloseLibrary(MultimediaBase);
	if (IntuitionBase) CloseLibrary(IntuitionBase);
}



STRPTR read_args(VOID)
{
	struct RDArgs *args;
	LONG params[1];
	STRPTR filename = NULL;

	if ((args = ReadArgs(Template, params, NULL)))
	{
		if ((filename = AllocVecTaskPooled(strlen((STRPTR)params[0]) + 1)))
		{
			strcpy(filename, (STRPTR)params[0]);
		}

		FreeArgs(args);
	}

	return filename;
}



VOID play_sound(STRPTR filename)
{
	Object *source, *player;
	struct MsgPort *port;
	struct Message *msg;


	if ((port = CreateMsgPort()))
	{
		if ((msg = AllocVec(sizeof(struct Message), MEMF_PUBLIC | MEMF_CLEAR)))
		{
			msg->mn_Node.ln_Type = NT_MESSAGE;
			msg->mn_ReplyPort = port;
			msg->mn_Length = sizeof(struct Message);

			if ((source = MediaNewObjectTags(
				MMA_StreamName, (LONG)filename,
				MMA_StreamType, (LONG)"file.stream",
				MMA_MediaType, MMT_SOUND,
			TAG_END)))
			{
				if ((player = NewObject(NULL, "audio.output", TAG_END)))
				{
					if (MediaConnectTagList(source, 0, player, 0, NULL))
					{
						ULONG signals, sigmask = 1 << port->mp_SigBit;

						/*-----------------------------------------------------------*/
						/* I want to wait both for message reply (end of sound) and  */
						/* CTRL-C signal (user break). That is why I calculate       */
						/* signal mask and use Wait() instead of WaitPort().         */
						/*-----------------------------------------------------------*/

						DoMethod(player, MMM_MessageAtEnd, (LONG)msg);
						DoMethod(player, MMM_Play);
						signals = Wait(SIGBREAKF_CTRL_C | sigmask);

						if (signals & SIGBREAKF_CTRL_C) PutStr("User break!\n");

						if (signals & sigmask)
						{
							GetMsg(port);                // empty port queue
							PutStr("End of sound.\n");
						}
					}

					DisposeObject(player);
				}

				DisposeObject(source);
			}
			else Printf("Reggae was unable to decode \"%s\".\n", (LONG)filename);

			FreeVec(msg);
		}

		DeleteMsgPort(port);
	}

}



int main(void)
{
	int result = RETURN_OK;
	STRPTR filename;

	if (init_resources())
	{
		if ((filename = read_args()))
		{
			play_sound(filename);
			FreeVecTaskPooled(filename);
		}
		else result = RETURN_ERROR;
	}
	else result = RETURN_FAIL;

	free_resources();

	return result;
}
