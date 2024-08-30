/* Automatically generated header (sfdc 1.4)! Do not edit! */

#ifndef _INLINE_AHI_H
#define _INLINE_AHI_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#define AHI_AllocAudioA(___tagList) \
	IAHI->AHI_AllocAudioA(___tagList)

#ifndef NO_INLINE_STDARG
#define AHI_AllocAudio(___tag1, ...) \
	IAHI->AHI_AllocAudio(___tag1, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#define AHI_FreeAudio(___AudioCtrl) \
	IAHI->AHI_FreeAudio(___AudioCtrl)

#define AHI_ControlAudioA(___AudioCtrl, ___tagList) \
	IAHI->AHI_ControlAudioA(___AudioCtrl, ___tagList)

#ifndef NO_INLINE_STDARG
#define AHI_ControlAudio(___AudioCtrl, ___tag1, ...) \
	IAHI->AHI_ControlAudio(___AudioCtrl, ___tag1, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#define AHI_SetVol(___Channel, ___Volume, ___Pan, ___AudioCtrl, ___Flags) \
	IAHI->AHI_SetVol(___Channel, ___Volume, ___Pan, ___AudioCtrl, ___Flags)

#define AHI_SetFreq(___Channel, ___Freq, ___AudioCtrl, ___Flags) \
	IAHI->AHI_SetFreq(___Channel, ___Freq, ___AudioCtrl, ___Flags)

#define AHI_SetSound(___Channel, ___Sound, ___Offset, ___Length, ___AudioCtrl, ___Flags) \
	IAHI->AHI_SetSound(___Channel, ___Sound, ___Offset, ___Length, ___AudioCtrl, ___Flags)

#define AHI_SetEffect(___Effect, ___AudioCtrl) \
	IAHI->AHI_SetEffect(___Effect, ___AudioCtrl)

#define AHI_LoadSound(___Sound, ___Type, ___Info, ___AudioCtrl) \
	IAHI->AHI_LoadSound(___Sound, ___Type, ___Info, ___AudioCtrl)

#define AHI_UnloadSound(___Sound, ___Audioctrl) \
	IAHI->AHI_UnloadSound(___Sound, ___Audioctrl)

#define AHI_NextAudioID(___Last_ID) \
	IAHI->AHI_NextAudioID(___Last_ID)

#define AHI_GetAudioAttrsA(___ID, ___Audioctrl, ___tagList) \
	IAHI->AHI_GetAudioAttrsA(___ID, ___Audioctrl, ___tagList)

#ifndef NO_INLINE_STDARG
#define AHI_GetAudioAttrs(___ID, ___Audioctrl, ___tag1, ...) \
	IAHI->AHI_GetAudioAttrs(___ID, ___Audioctrl, ___tag1, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#define AHI_BestAudioIDA(___tagList) \
	IAHI->AHI_BestAudioIDA(___tagList)

#ifndef NO_INLINE_STDARG
#define AHI_BestAudioID(___tag1, ...) \
	IAHI->AHI_BestAudioID(___tag1, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#define AHI_AllocAudioRequestA(___tagList) \
	IAHI->AHI_AllocAudioRequestA(___tagList)

#ifndef NO_INLINE_STDARG
#define AHI_AllocAudioRequest(___tag1, ...) \
	IAHI->AHI_AllocAudioRequest(___tag1, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#define AHI_AudioRequestA(___Requester, ___tagList) \
	IAHI->AHI_AudioRequestA(___Requester, ___tagList)

#ifndef NO_INLINE_STDARG
#define AHI_AudioRequest(___Requester, ___tag1, ...) \
	IAHI->AHI_AudioRequest(___Requester, ___tag1, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#define AHI_FreeAudioRequest(___Requester) \
	IAHI->AHI_FreeAudioRequest(___Requester)

#define AHI_PlayA(___Audioctrl, ___tagList) \
	IAHI->AHI_PlayA(___Audioctrl, ___tagList)

#ifndef NO_INLINE_STDARG
#define AHI_Play(___Audioctrl, ___tag1, ...) \
	IAHI->AHI_Play(___Audioctrl, ___tag1, __VA_ARGS__)
#endif /* !NO_INLINE_STDARG */

#define AHI_SampleFrameSize(___SampleType) \
	IAHI->AHI_SampleFrameSize(___SampleType)

#define AHI_AddAudioMode(___AHIPrivate) \
	IAHI->AHI_AddAudioMode(___AHIPrivate)

#define AHI_RemoveAudioMode(___AHIPrivate) \
	IAHI->AHI_RemoveAudioMode(___AHIPrivate)

#define AHI_LoadModeFile(___AHIPrivate) \
	IAHI->AHI_LoadModeFile(___AHIPrivate)

#endif /* !_INLINE_AHI_H */
