#ifndef POWERSDL_SOUND_PROTOS
#define POWERSDL_SOUND_PROTOS

/* Protos are for cvinclude.pl script */

#if 0
#ifdef __cplusplus
extern "C" {
#endif

void Sound_GetLinkedVersion(Sound_Version *ver);
int Sound_Init(void);
int Sound_Quit(void);
const Sound_DecoderInfo **Sound_AvailableDecoders(void);
const char *Sound_GetError(void);
void Sound_ClearError(void);
Sound_Sample *Sound_NewSample(SDL_RWops *rw, const char *ext, Sound_AudioInfo *desired, Uint32 bufferSize);
Sound_Sample *Sound_NewSampleFromFile(const char *fname, Sound_AudioInfo *desired, Uint32 bufferSize);
void Sound_FreeSample(Sound_Sample *sample);
int Sound_SetBufferSize(Sound_Sample *sample, Uint32 new_size);
Uint32 Sound_Decode(Sound_Sample *sample);
Uint32 Sound_DecodeAll(Sound_Sample *sample);
int Sound_Rewind(Sound_Sample *sample);
int Sound_Seek(Sound_Sample *sample, Uint32 ms);

#ifdef __cplusplus
}
#endif
#endif

#endif /* POWERSDL_SOUND_PROTOS */