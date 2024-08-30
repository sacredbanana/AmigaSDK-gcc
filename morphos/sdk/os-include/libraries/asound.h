#ifndef LIBRARIES_AMBIENT_SOUND_H
#define LIBRARIES_AMBIENT_SOUND_H
/*
 * ambient_sound.library include
 * -----------------------------
 * © 2001-2004 by David Gerber <zapek@morphos.net>
 * All Rights Reserved
 */

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif


/*
 * ASound_Create()'s mode.
 */
enum {
	SOUNDMODE_NORMAL,   /* normal mode, just plays the sound */
};

/*
 * ASound_Create() tags.
 */
enum {
	SOUNDTAG_Channels = TAG_USER + 1, /* number of channels; default: 1 */
	SOUNDTAG_Resolution,              /* 8-bits, 16-bits, etc.. see the SOUNDVAL_Resolutions_#?; default: SOUNDVAL_Resolution_8 */
	SOUNDTAG_Precision,               /* sound precision, see SOUNDVAL_Precision_#?; default: integer */
	SOUNDTAG_Frequency,               /* frequency in Hz; default: 8000 */
	SOUNDTAG_Volume,                  /* volume from 0 to 65536 (0x10000 == 1.0); default: 0x10000 */
	SOUNDTAG_Priority,                /* sound priority in case there's not enough channels available, see SOUNDVAL_Priority_#?; default: SOUNDVAL_Priority_Event */
};

/*
 * SOUNDTAG_Resolution
 */
enum {
	SOUNDVAL_Resolution_8,  /* 8-bit signed fixed */
	SOUNDVAL_Resolution_16, /* 16-bit signed fixed */
	SOUNDVAL_Resolution_32, /* 32-bit signed fixed */
};

/*
 * SOUNDTAG_Priority
 */
enum {
	SOUNDVAL_Priority_Background,  /* background music */
	SOUNDVAL_Priority_Music,       /* music */
	SOUNDVAL_Priority_Event,       /* indication of some event */
	SOUNDVAL_Priority_Important,   /* important event */
	SOUNDVAL_Priority_Maximum,     /* emergency */
};

/*
 * SOUNDTAG_Precision
 */
enum {
	SOUNDVAL_Precision_Integer, /* integer */
};

/*
 * Some attributes can be queried for
 * a default context, this is what to
 * pass as default context then.
 */
#define SOUNDCONTEXT_DEFAULT ((APTR)1)

/*
 * Attributes for ASound_GetAttr()
 */
enum {
	SOUNDATTR_DriverName,      /* STRPTR: name of the sound driver (default context only) */
	SOUNDATTR_BufferFillState, /* ULONG: filled state of the buffer in state */
};


#endif /* LIBRARIES_AMBIENT_SOUND_H */
