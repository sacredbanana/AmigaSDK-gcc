/* Automatically generated header! Do not edit! */

#ifndef _VBCCINLINE_SMPEG_H
#define _VBCCINLINE_SMPEG_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EMUL_EMULREGS_H
#include <emul/emulregs.h>
#endif

void  __SMPEG_scale(SMPEG *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-106(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_scale(__p0, __p1) __SMPEG_scale((__p0), (__p1))

int  __SMPEG_playAudio(SMPEG *, Uint8 *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-184(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_playAudio(__p0, __p1, __p2) __SMPEG_playAudio((__p0), (__p1), (__p2))

void  __SMPEG_loop(SMPEG *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-94(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_loop(__p0, __p1) __SMPEG_loop((__p0), (__p1))

SMPEG * __SMPEG_new_data(void *, int , SMPEG_Info *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-40(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_new_data(__p0, __p1, __p2, __p3) __SMPEG_new_data((__p0), (__p1), (__p2), (__p3))

SMPEG * __SMPEG_new(const char *, SMPEG_Info *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-28(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_new(__p0, __p1, __p2) __SMPEG_new((__p0), (__p1), (__p2))

SMPEG * __SMPEG_new_rwops(SDL_RWops *, SMPEG_Info *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-46(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_new_rwops(__p0, __p1, __p2) __SMPEG_new_rwops((__p0), (__p1), (__p2))

void  __SMPEG_skip(SMPEG *, float ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-154(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_skip(__p0, __p1) __SMPEG_skip((__p0), (__p1))

SMPEGstatus  __SMPEG_status(SMPEG *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-76(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_status(__p0) __SMPEG_status((__p0))

void  __SMPEG_seek(SMPEG *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-148(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_seek(__p0, __p1) __SMPEG_seek((__p0), (__p1))

void  __SMPEG_setdisplay(SMPEG *, SDL_Surface *, SDL_mutex *, SMPEG_DisplayCallback ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-88(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_setdisplay(__p0, __p1, __p2, __p3) __SMPEG_setdisplay((__p0), (__p1), (__p2), (__p3))

SMPEG * __SMPEG_new_descr(int , SMPEG_Info *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-34(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_new_descr(__p0, __p1, __p2) __SMPEG_new_descr((__p0), (__p1), (__p2))

void  __SMPEG_renderFinal(SMPEG *, SDL_Surface *, int , int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-166(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_renderFinal(__p0, __p1, __p2, __p3) __SMPEG_renderFinal((__p0), (__p1), (__p2), (__p3))

void  __SMPEG_setvolume(SMPEG *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-82(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_setvolume(__p0, __p1) __SMPEG_setvolume((__p0), (__p1))

SMPEG_Filter * __SMPEG_filter(SMPEG *, SMPEG_Filter *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-172(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_filter(__p0, __p1) __SMPEG_filter((__p0), (__p1))

void  __SMPEG_getinfo(SMPEG *, SMPEG_Info *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-52(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_getinfo(__p0, __p1) __SMPEG_getinfo((__p0), (__p1))

void  __SMPEG_stop(SMPEG *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-136(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_stop(__p0) __SMPEG_stop((__p0))

void  __SMPEG_enablevideo(SMPEG *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-64(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_enablevideo(__p0, __p1) __SMPEG_enablevideo((__p0), (__p1))

void  __SMPEG_actualSpec(SMPEG *, SDL_AudioSpec *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-202(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_actualSpec(__p0, __p1) __SMPEG_actualSpec((__p0), (__p1))

void  __SMPEG_rewind(SMPEG *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-142(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_rewind(__p0) __SMPEG_rewind((__p0))

void  __SMPEG_delete(SMPEG *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-70(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_delete(__p0) __SMPEG_delete((__p0))

int  __SMPEG_wantedSpec(SMPEG *, SDL_AudioSpec *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-196(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_wantedSpec(__p0, __p1) __SMPEG_wantedSpec((__p0), (__p1))

void  __SMPEG_pause(SMPEG *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-130(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_pause(__p0) __SMPEG_pause((__p0))

void  __SMPEG_setdisplayregion(SMPEG *, int , int , int , int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-118(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_setdisplayregion(__p0, __p1, __p2, __p3, __p4) __SMPEG_setdisplayregion((__p0), (__p1), (__p2), (__p3), (__p4))

void  __SMPEG_scaleXY(SMPEG *, int , int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-100(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_scaleXY(__p0, __p1, __p2) __SMPEG_scaleXY((__p0), (__p1), (__p2))

void  __SMPEG_play(SMPEG *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-124(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_play(__p0) __SMPEG_play((__p0))

void  __SMPEG_renderFrame(SMPEG *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-160(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_renderFrame(__p0, __p1) __SMPEG_renderFrame((__p0), (__p1))

char * __SMPEG_error(SMPEG *) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-178(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_error(__p0) __SMPEG_error((__p0))

void  __SMPEG_enableaudio(SMPEG *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-58(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_enableaudio(__p0, __p1) __SMPEG_enableaudio((__p0), (__p1))

void  __SMPEG_playAudioSDL(void *, Uint8 *, int ) =
	"\tlis\t11,SMPEGBase@ha\n"
	"\tlwz\t12,SMPEGBase@l(11)\n"
	"\tlwz\t0,-190(12)\n"
	"\tmtlr\t0\n"
	"\tblrl";
#define SMPEG_playAudioSDL(__p0, __p1, __p2) __SMPEG_playAudioSDL((__p0), (__p1), (__p2))

#endif /* !_VBCCINLINE_SMPEG_H */
