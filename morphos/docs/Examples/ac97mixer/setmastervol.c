//gcc -noixemul -Wall -O2 setmastervol.c -o setmastervol -L./.. -lac97mixer 
//
// simple example to set the master output volume

#include <libraries/ac97mixer.h>
#include <proto/exec.h>
#include <clib/ac97mixer_protos.h>
#include <stdio.h>
#include <stdlib.h>

struct Library *AC97MixerBase;

int main(int argc,char **argv)
{
	int mastervol;
	ULONG newvol;

	if(argc < 2)
	{
		printf("Usage: %s <volume>\n",argv[0]);
		exit(100);
	}

	mastervol = atoi(argv[1]);

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

			if(AC97GetMixerAttr(MixerObject,AC97MA_OUTPUTS,&outputs))
			{
				int idx=0;
				char *oname;
				ULONG channels=1,minvol,maxvol,vol,muted;
				WORD leftvol,rightvol;

				printf("\n has %ld outputs\n",outputs);

				while(idx < outputs)
				{
					if(AC97GetOutputAttr(MixerObject,idx,AC97MOA_NAME,&oname))
					{
						printf("  output '%s'\n",oname);
					}

					if(AC97GetOutputAttr(MixerObject,idx,AC97MOA_CHANNELS,&channels))
					{
						printf("   has %ld channels\n",channels);
					}


					if(AC97GetOutputAttr(MixerObject,idx,AC97MOA_MAXVOLUME,&maxvol))
					{
						if(channels == 1)
						{
							WORD monovol;

							monovol = (WORD)maxvol;

							printf("   has max volume of %.1fdb (mono)\n",(float)monovol/2);
						}
						else
						if(channels == 2)
						{
							WORD lvol;
							WORD rvol;

							lvol = (WORD)maxvol;
							rvol = (WORD)(maxvol >> 16);

							printf("   has max volume of %.1fdb (left) and %.1fdb (right)\n",((float)lvol)/2.0,((float)rvol)/2.0);
						}
					}

					if(AC97GetOutputAttr(MixerObject,idx,AC97MOA_MINVOLUME,&minvol))
					{
						if(channels == 1)
						{
							WORD monovol;

							monovol = (WORD)minvol;

							printf("   has min volume of %.1fdb (mono)\n",(float)monovol/2);
						}
						else
						if(channels == 2)
						{
							WORD lvol;
							WORD rvol;

							lvol = (WORD)minvol;
							rvol = (WORD)(minvol >> 16);

							printf("   has min volume of %.1fdb (left) and %.1fdb (right)\n",((float)lvol)/2.0,((float)rvol)/2.0);
						}
					}


					if(AC97GetOutputAttr(MixerObject,idx,AC97MOA_VOLUME,&vol))
					{
						if(channels == 1)
						{
							WORD monovol;

							monovol = (WORD)vol;

							printf("   has current volume of %.1fdb (mono)\n",(float)monovol/2);
						}
						else
						if(channels == 2)
						{
							WORD lvol;
							WORD rvol;

							lvol = (WORD)vol;
							rvol = (WORD)(vol >> 16);

							printf("   has current volume of %.1fdb (left) and %.1fdb (right)\n",((float)lvol)/2.0,((float)rvol)/2.0);
						}
					}


					if(AC97GetOutputAttr(MixerObject,idx,AC97MOA_MUTE,&muted))
					{
						if(muted)
						{
							printf("   has %s muted\n",muted ? "been" : "NOT been");
						}
					}

					idx++;
				}

				printf("Trying to set master volume to %ddb\n",mastervol);

				leftvol = mastervol<<1;
				rightvol = mastervol<<1;
	
				newvol =  (ULONG)(leftvol << 16)&0xFFFF0000;
				newvol |= (ULONG)(rightvol << 0)&0x0000FFFF;

				AC97SetOutputAttr(MixerObject,0,AC97MOA_VOLUME,newvol);
			}

			printf("\n");

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
