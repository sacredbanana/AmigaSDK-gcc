#ifndef MUI_AUDIOPLAYER_MCC_H
#define MUI_AUDIOPLAYER_MCC_H

/*
 * AudioPlayer.mcc - Area subclass: waveform, spectrum and AHI playback
 *
 * Load a WAV or raw PCM file with MUIA_AudioPlayer_FileName. The gadget
 * draws a waveform with a playhead and a control bar (play/pause, stop,
 * rewind, elapsed time). Click the waveform to seek.
 */

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

#define MUIC_AudioPlayer "AudioPlayer.mcc"

#define AudioPlayer_Dummy (0xbd001000UL)
#define MUIA_AudioPlayer_FileName (AudioPlayer_Dummy + 0x01)
#define MUIA_AudioPlayer_Position (AudioPlayer_Dummy + 0x02)
#define MUIA_AudioPlayer_Duration (AudioPlayer_Dummy + 0x03)
#define MUIA_AudioPlayer_Seek (AudioPlayer_Dummy + 0x04)
#define MUIA_AudioPlayer_Playing (AudioPlayer_Dummy + 0x05)
#define MUIA_AudioPlayer_Paused (AudioPlayer_Dummy + 0x06)
#define MUIA_AudioPlayer_HasSpeech (AudioPlayer_Dummy + 0x07)
#define MUIA_AudioPlayer_Command (AudioPlayer_Dummy + 0x08)
#define MUIA_AudioPlayer_SampleRate (AudioPlayer_Dummy + 0x09)
#define MUIA_AudioPlayer_Channels (AudioPlayer_Dummy + 0x0A)
#define MUIA_AudioPlayer_Bits (AudioPlayer_Dummy + 0x0B)
#define MUIA_AudioPlayer_LittleEndian (AudioPlayer_Dummy + 0x0C)
#define MUIA_AudioPlayer_WavePen (AudioPlayer_Dummy + 0x0D)
#define MUIA_AudioPlayer_PeakPen (AudioPlayer_Dummy + 0x0E)
#define MUIA_AudioPlayer_SpectrumPen (AudioPlayer_Dummy + 0x0F)
#define MUIA_AudioPlayer_BackPen (AudioPlayer_Dummy + 0x10)
#define MUIA_AudioPlayer_BarPen (AudioPlayer_Dummy + 0x11)
#define MUIA_AudioPlayer_TextPen (AudioPlayer_Dummy + 0x12)

#define MUIV_AudioPlayer_Pen_Default ((ULONG)~0)

#define MUIV_AudioPlayer_Command_Play 1
#define MUIV_AudioPlayer_Command_Pause 2
#define MUIV_AudioPlayer_Command_Stop 3
#define MUIV_AudioPlayer_Command_Rewind 4

#define MUIM_AudioPlayer_Play (AudioPlayer_Dummy + 0x20)
#define MUIM_AudioPlayer_Pause (AudioPlayer_Dummy + 0x21)
#define MUIM_AudioPlayer_Stop (AudioPlayer_Dummy + 0x22)
#define MUIM_AudioPlayer_Rewind (AudioPlayer_Dummy + 0x23)
#define MUIM_AudioPlayer_Service (AudioPlayer_Dummy + 0x24)

#if defined(__AROS__) && !defined(NO_INLINE_STDARG)
#define AudioPlayerObject MUIOBJMACRO_START(MUIC_AudioPlayer)
#else
#define AudioPlayerObject MUI_NewObject(MUIC_AudioPlayer
#endif

#endif /* MUI_AUDIOPLAYER_MCC_H */
