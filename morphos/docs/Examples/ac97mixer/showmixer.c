//gcc -noixemul -Wall -O2 showmixer.c -o showmixer -L./.. -lac97mixer 
//
// simple example to dump default mixer settings

#include <libraries/ac97mixer.h>
#include <proto/exec.h>
#include <clib/ac97mixer_protos.h>
#include <stdio.h>

struct Library *AC97MixerBase;

int main(void)
{
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
			ULONG outputs,inputs;

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
			}

			printf("\n");

			if(AC97GetMixerAttr(MixerObject,AC97MA_INPUTS,&inputs))
			{
				int idx=0;
				char *iname;
				ULONG channels=1,minvol,maxvol,vol,muted,boost,boosted;

				printf(" has %ld inputs\n",inputs);

				while(idx < inputs)
				{
					if(AC97GetInputAttr(MixerObject,idx,AC97MIA_NAME,&iname))
					{
						printf("  input '%s'\n",iname);
					}

					if(AC97GetInputAttr(MixerObject,idx,AC97MIA_CHANNELS,&channels))
					{
						printf("   has %ld channels\n",channels);
					}

					if(AC97GetInputAttr(MixerObject,idx,AC97MIA_HASBOOST,&boost))
					{
						if(boost)
						{
							printf("   has 20db boost option (MIC)\n");

							if(AC97GetInputAttr(MixerObject,idx,AC97MIA_BOOST,&boosted))
							{
								printf("   has boost option %s\n",boosted ? "enabled" : "NOT enabled");
							}

						}
					}

					if(AC97GetInputAttr(MixerObject,idx,AC97MIA_MAXVOLUME,&maxvol))
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

					if(AC97GetInputAttr(MixerObject,idx,AC97MIA_MINVOLUME,&minvol))
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

					if(AC97GetInputAttr(MixerObject,idx,AC97MIA_VOLUME,&vol))
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

					if(AC97GetInputAttr(MixerObject,idx,AC97MIA_MUTE,&muted))
					{
						if(muted)
						{
							printf("   has %s muted\n",muted ? "been" : "NOT been");
						}
					}

					idx++;
				}
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
