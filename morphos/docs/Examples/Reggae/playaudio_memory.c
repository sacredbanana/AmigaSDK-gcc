/*----------------------------------------------------------------------------*/
/* Reggae example: loads a sound to memory buffer, then plays it at every     */
/* keypress. Demonstrates usage of memory.stream for low playback latency.    */
/* To have real fun load some short sample like gun shot.                     */
/*                                                                            */
/* Every [ENTER] stops the sample (to rewind it to the start) and plays it    */
/* again. Even if sample ends before keypress, stopping it is harmless.       */
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
#include <classes/multimedia/sound.h>


extern struct Library *SysBase, *DOSBase;
struct Library *IntuitionBase, *MultimediaBase, *AudioOutputBase;
CONST_STRPTR Template = "FILE/A";


struct BufInfo
{
	APTR buffer;
	LONG size;
};


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



BOOL load_sound(STRPTR filename, struct BufInfo *binf)
{
	BPTR file;
	struct FileInfoBlock *fib;
	BOOL result = FALSE;

	SetIoErr(0);
	binf->buffer = NULL;

	if ((fib = AllocDosObject(DOS_FIB, NULL)))
	{
		if ((file = Open(filename, MODE_OLDFILE)))
		{
			if (ExamineFH(file, fib))
			{
				binf->size = fib->fib_Size;

				if ((binf->buffer = AllocTaskPooled(binf->size)))
				{
					if (Read(file, binf->buffer, binf->size) == binf->size) result = TRUE;
					else
					{
						FreeTaskPooled(binf->buffer, binf->size);
						result = FALSE;
						PrintFault(IoErr(), "Loading failed");
					}
				}
			}

			Close(file);
		}
		else PrintFault(IoErr(), "Can't open file");

		FreeDosObject(DOS_FIB, fib);
	}

	return result;
}



VOID main_loop(struct BufInfo *binf)
{
	Object *source, *player;
	QUAD stream_length = (QUAD)binf->size;

	if ((source = MediaNewObjectTags(
		MMA_StreamHandle, (LONG)binf->buffer,
		MMA_StreamType, (LONG)"memory.stream",
		MMA_StreamLength, (LONG)&stream_length,
		MMA_MediaType, MMT_SOUND,
	TAG_END)))
	{
		if ((player = NewObject(NULL, "audio.output", TAG_END)))
		{
			if (MediaConnectTagList(source, 0, player, 0, NULL))
			{
				LONG c;

				for (;;)
				{
					c = FGetC(Input());
					if (c == 'q') break;
					else
					{
						DoMethod(player, MMM_Stop);
						DoMethod(player, MMM_Play);
					}
				}
			}

			DisposeObject(player);
		}

		DisposeObject(source);
	}
	else PutStr("Reggae was unable to decode buffer.\n");
}



int main(void)
{
	int result = RETURN_OK;
	STRPTR filename;
	struct BufInfo binf;

	if (init_resources())
	{
		if ((filename = read_args()))
		{
			if (load_sound(filename, &binf))
			{
				PutStr("Press [ENTER] to (re)trigger sound. Press [Q] then [ENTER] to quit.\n");
				main_loop(&binf);
				FreeTaskPooled(binf.buffer, binf.size);
			}
			else result = RETURN_ERROR;

			FreeVecTaskPooled(filename);
		}
		else result = RETURN_ERROR;
	}
	else result = RETURN_FAIL;

	free_resources();

	return result;
}
