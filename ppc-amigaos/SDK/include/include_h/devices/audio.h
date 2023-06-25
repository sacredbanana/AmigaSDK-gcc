#ifndef DEVICES_AUDIO_H
#define DEVICES_AUDIO_H
/*
**    $VER: audio.h 54.16 (22.08.2022)
**
**    audio.device include file
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_IO_H
#include <exec/io.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

#define AUDIONAME "audio.device"

#define ADHARD_CHANNELS  4

#define ADALLOC_MINPREC -128
#define ADALLOC_MAXPREC  127

#define ADCMD_FREE      (CMD_NONSTD+0)
#define ADCMD_SETPREC   (CMD_NONSTD+1)
#define ADCMD_FINISH    (CMD_NONSTD+2)
#define ADCMD_PERVOL    (CMD_NONSTD+3)
#define ADCMD_LOCK      (CMD_NONSTD+4)
#define ADCMD_WAITCYCLE (CMD_NONSTD+5)
#define ADCMD_ALLOCATE  32

#define ADIOB_PERVOL       4
#define ADIOF_PERVOL       (1<<4)
#define ADIOB_SYNCCYCLE    5
#define ADIOF_SYNCCYCLE    (1<<5)
#define ADIOB_NOWAIT       6
#define ADIOF_NOWAIT       (1<<6)
#define ADIOB_WRITEMESSAGE 7
#define ADIOF_WRITEMESSAGE (1<<7)

#define ADIOERR_NOALLOCATION  -10
#define ADIOERR_ALLOCFAILED   -11
#define ADIOERR_CHANNELSTOLEN -12

struct IOAudio
{
    struct IORequest ioa_Request;
    WORD             ioa_AllocKey;
    UBYTE *          ioa_Data;
    ULONG            ioa_Length;
    UWORD            ioa_Period;
    UWORD            ioa_Volume;
    UWORD            ioa_Cycles;
    struct Message   ioa_WriteMsg;
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* DEVICES_AUDIO_H */
