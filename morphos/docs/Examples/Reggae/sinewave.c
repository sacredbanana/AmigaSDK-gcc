/*----------------------------------------------------------------------------*/
/* Reggae example: playing a synthesized, continuous 1 kHz sine wave.         */
/* Sampling frequency is 44100 Hz. This example shows usage of memory.stream  */
/* and rawaudio.filter to use raw, synthesized audio data in Reggae.          */
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
#include <exec/memory.h>
#include <classes/multimedia/sound.h>
#include <math.h>

extern struct Library *SysBase, *DOSBase;

struct Library
	*IntuitionBase,
	*MultimediaBase,
	*AudioOutputBase,
	*MemoryStreamBase,
	*RawAudioFilterBase;


struct ReggaePipeline
{
	Object *stream;
	Object *rawaudio;
	Object *player;
};

/*----------------------------------------------------------------------------*/
/* In theory a single looped period of sine is enough to play a continuous    */
/* wave. Unfortunately one period of 1 kHz sine sampled at 44100 Hz occupies  */
/* 44.1 sampling periods, which is not integer. Using 10 periods (441         */
/* samples) would be enough, but I've used 100 periods, to avoid tight        */
/* looping, which is CPU consuming. Sample format in the table is 16-bit.     */
/*----------------------------------------------------------------------------*/

WORD SineWave[4410];


VOID wave_generate(VOID)
{
	LONG i;

	for (i = 0; i < 4410; i++) SineWave[i] = sin(100.0 * M_PI * (double)i / 2205.0) * 32767.0;
}



BOOL init_resources(VOID)
{
	if (!(IntuitionBase = OpenLibrary("intuition.library", 50))) return FALSE;
	if (!(MultimediaBase = OpenLibrary("multimedia/multimedia.class", 52))) return FALSE;
	if (!(AudioOutputBase = OpenLibrary("multimedia/audio.output", 51))) return FALSE;
	if (!(MemoryStreamBase = OpenLibrary("multimedia/memory.stream", 51))) return FALSE;
	if (!(RawAudioFilterBase = OpenLibrary("multimedia/rawaudio.filter", 51))) return FALSE;
	return TRUE;
}



VOID free_resources(VOID)
{
	if (RawAudioFilterBase) CloseLibrary(RawAudioFilterBase);
	if (MemoryStreamBase) CloseLibrary(MemoryStreamBase);
	if (AudioOutputBase) CloseLibrary(AudioOutputBase);
	if (MultimediaBase) CloseLibrary(MultimediaBase);
	if (IntuitionBase) CloseLibrary(IntuitionBase);
}



BOOL build_pipeline(struct ReggaePipeline *rpi)
{
	QUAD stream_length = 8820;                     // size of the sine table in *bytes*

	rpi->stream = NewObject(NULL, "memory.stream",
		MMA_StreamHandle, (LONG)SineWave,
		MMA_StreamLength, (LONG)&stream_length,    // pointer to 64-bit value!
	TAG_END);

	rpi->rawaudio = NewObject(NULL, "rawaudio.filter",
		MMA_Sound_Channels, 1,
		MMA_Sound_SampleRate, 44100,
		MMA_Sound_Volume, 65536,                   // full volume, this is the default, but let's set it anyway
	TAG_END);

	rpi->player = NewObject(NULL, "audio.output", TAG_END);

	if (rpi->stream && rpi->rawaudio && rpi->player)
	{
		MediaSetPort(rpi->rawaudio, 1, MMA_Port_Format, MMFC_AUDIO_INT16);   // default, but let's set it for clarity
		MediaConnectTagList(rpi->stream, 0, rpi->rawaudio, 0, NULL);
		MediaConnectTagList(rpi->rawaudio, 1, rpi->player, 0, NULL);
		return TRUE;
	}

	return FALSE;
}



VOID play_sound(struct ReggaePipeline *rpi)
{
	/*------------------------------------------------------------------------*/
	/* The sound will be looped, so it never ends. The only way to break it   */
	/* will be to press CTRL+C in the console or to send CTRL-C signal other  */
	/* way. I'm only waiting for this signal then.                            */
	/*------------------------------------------------------------------------*/

	MediaSetPort(rpi->player, 0, MMA_Sound_LoopedPlay, TRUE);     // turn looping on
	DoMethod(rpi->player, MMM_Play);
	Wait(SIGBREAKF_CTRL_C);
}



VOID destroy_pipeline(struct ReggaePipeline *rpi)
{
	DisposeObject(rpi->player);
	DisposeObject(rpi->rawaudio);
	DisposeObject(rpi->stream);
}



int main(void)
{
	int result = RETURN_OK;

	if (init_resources())
	{
		struct ReggaePipeline rpi;

		wave_generate();
		if (build_pipeline(&rpi)) play_sound(&rpi);
		else result = RETURN_FAIL;

		destroy_pipeline(&rpi);
	}
	else result = RETURN_FAIL;

	free_resources();

	return result;
}
