#ifndef LIBRARIES_AC97MIXER_H
#define LIBRARIES_AC97MIXER_H

/*
	ac97mixer library definitions

	Copyright © 2003-2010 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#define	MIN_MIXERVERSION	(51UL)

#define AC97MA_OUTPUTS		0x84340001	/* (ULONG *) */
#define AC97MA_INPUTS		0x84340002	/* (ULONG *) */
#define AC97MA_S3DCAPABLE	0x84340003	/* (ULONG *) */
#define AC97MA_SPDIFOUTCAPABLE	0x84340004	/* (ULONG *) */
#define AC97MA_S3DLEVEL		0x84340005	/* (ULONG) */
#define AC97MA_SPDIFOUTENABLE	0x84340006	/* (ULONG) */
#define AC97MA_NAME		0x87650007	/* (char **) */
#define AC97MA_VOLUMEHOOK	0x84340008	/* (struct Hook *) */

#define AC97MIA_MAXVOLUME	0x85630001	/* 32bit data word containing 2 signed 16bit words */
						/* in 15.1 fractional format (upper is left, lower word is right (or mono) */
						/* unit is db in 0.5db steps */

#define AC97MIA_MINVOLUME	0x85630002	/* 32bit data word containing 2 signed 16bit words */
						/* in 15.1 fractional format (upper is left, lower word is right (or mono) */
						/* unit is db in 0.5db steps */

#define AC97MIA_NAME		0x85630003	/* (char **) */
#define AC97MIA_CHANNELS	0x85630004	/* (ULONG *) */
#define AC97MIA_VOLUME		0x85630005	/* 32bit data word containing 2 signed 16bit words */
						/* in 15.1 fractional format (upper is left, lower word is right (or mono) */
						/* unit is db in 0.5db steps */
#define AC97MIA_MUTE		0x87650007	/* (ULONG) */
#define AC97MIA_HASBOOST	0x87650008	/* (ULONG *) */
#define AC97MIA_BOOST		0x87650009	/* (ULONG) */



#define AC97MOA_MAXVOLUME	0x87650001	/* 32bit data word containing 2 signed 16bit words */
						/* in 15.1 fractional format (upper is left, lower word is right (or mono) */
						/* unit is db in 0.5db steps */

#define AC97MOA_MINVOLUME	0x87650002	/* 32bit data word containing 2 signed 16bit words */
						/* in 15.1 fractional format (upper is left, lower word is right (or mono) */
						/* unit is db in 0.5db steps */

#define AC97MOA_NAME		0x87650003	/* (char **) */
#define AC97MOA_CHANNELS	0x87650004	/* (ULONG *) */
#define AC97MOA_VOLUME		0x87650005	/* 32bit data word containing 2 signed 16bit words */
						/* in 15.1 fractional format (upper is left, lower word is right (or mono) */
						/* unit is db in 0.5db steps */
#define AC97MOA_MUTE		0x87650007	/* (ULONG) */


enum
{
	AC97TAG_CodecName = 0x88770000,
	AC97TAG_UserData,
	AC97TAG_SetMixerAttrFunc,
	AC97TAG_GetMixerAttrFunc,
	AC97TAG_SetInputAttrFunc,
	AC97TAG_GetInputAttrFunc,
	AC97TAG_SetOutputAttrFunc,
	AC97TAG_GetOutputAttrFunc,
	AC97TAG_RegWriteFunc,
	AC97TAG_RegReadFunc,
	AC97TAG_SoftVolume
};

struct	AC97MixerMsg
{
	ULONG	msg_id;
	ULONG	index;
	ULONG	attr;
	ULONG	value;
};

enum
{
	AC97MMSG_SETINPUT = 1,
	AC97MMSG_SETOUTPUT = 2,
	AC97MMSG_SETMIXER = 3,
	AC97MMSG_REMOVED = 4
};


struct	AC97VolAdjMsg
{
	void	*buffer;
	ULONG	samples;
	ULONG	format;
};

#pragma pack()

#endif /* LIBRARIES_AC97MIXER_H */
