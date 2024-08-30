//gcc -noixemul -Wall -O2 mixernotify.c -o mixernotify -L./.. -lac97mixer 
//
// simple example to listen to mixer changes

#include <libraries/ac97mixer.h>
#include <proto/exec.h>
#include <clib/ac97mixer_protos.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos/dosextens.h>

struct Library *AC97MixerBase;

void HFunc_MixerNotify(void)
{
	struct Hook *hook=(struct Hook *)REG_A0;
	struct AC97MixerMsg *mixermsg=(struct AC97MixerMsg *)REG_A1;
	void *MixerObject=(void *)REG_A2;

	printf("MixerNotify msg %p MixerObject %p\n",mixermsg,MixerObject);


	printf("            msg_id %d index %d attr %08lx value %08lx\n",mixermsg->msg_id,mixermsg->index,mixermsg->attr,mixermsg->value);
}
const struct EmulLibEntry HTrap_MixerNotify =
{
	TRAP_LIB,
	0,
	HFunc_MixerNotify
};

int main(int argc,char **argv)
{
	struct Hook hook;

	if(argc > 1)
	{
		printf("Usage: %s>\n",argv[0]);
		exit(100);
	}

	if((AC97MixerBase = OpenLibrary("ac97mixer.library",MIN_MIXERVERSION)) != NULL)
	{
		APTR MixerObject;

		struct TagItem taglist[]=
		{
			{TAG_DONE}
		};

		if((MixerObject = AC97FindMixer(NULL,-1L,taglist)) != NULL)
		{
			char *mixername;
			ULONG outputs;

			printf("Found Mixer Object ID%p\n",MixerObject);

			if(AC97GetMixerAttr(MixerObject,AC97MA_NAME,&mixername))
			{
				printf(" Mixer name is '%s'\n",mixername);
			}

			hook.h_Entry = (HOOKFUNC)&HTrap_MixerNotify;

			if(AC97AddMixerNotify(MixerObject,0,&hook) == 0)
			{
				Wait(SIGBREAKF_CTRL_C);

				AC97RemMixerNotify(MixerObject,&hook);
			}
			else
			{
			}
		}
		else
		{
			printf("No mixer found!\n");
		}

		CloseLibrary(AC97MixerBase);
	}
	else
	{
		printf("Unable to open ac97mixer V%ld\n",MIN_MIXERVERSION);
	}

	return 0;
}
