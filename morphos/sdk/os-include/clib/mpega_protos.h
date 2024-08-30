#ifndef CLIB_MPEGA_PROTOS_H
#define CLIB_MPEGA_PROTOS_H

/*
	mpega.library C prototypes

	Copyright © 2007 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_MPEGA_H
# include <libraries/mpega.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

MPEGA_STREAM *MPEGA_open(char *stream_name, MPEGA_CTRL *ctrl);
void MPEGA_close(MPEGA_STREAM *mpds);
LONG MPEGA_decode_frame(MPEGA_STREAM *mpds, WORD *pcm[MPEGA_MAX_CHANNELS]);
LONG MPEGA_seek(MPEGA_STREAM *mpds, ULONG ms_time_position);
LONG MPEGA_time(MPEGA_STREAM *mpds, ULONG *ms_time_position);
LONG MPEGA_find_sync(BYTE *buffer, LONG buffer_size);
LONG MPEGA_scale(MPEGA_STREAM *mpds, LONG scale_percent);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_MPEGA_PROTOS_H */
