/* Automatically generated header (sfdc 1.4)! Do not edit! */

#ifndef _INLINE_AHI_SUB_H
#define _INLINE_AHI_SUB_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#define AHIsub_AllocAudio(___tagList, ___AudioCtrl) \
	IAHIsub->AHIsub_AllocAudio(___tagList, ___AudioCtrl)

#define AHIsub_FreeAudio(___AudioCtrl) \
	IAHIsub->AHIsub_FreeAudio(___AudioCtrl)

#define AHIsub_Disable(___AudioCtrl) \
	IAHIsub->AHIsub_Disable(___AudioCtrl)

#define AHIsub_Enable(___AudioCtrl) \
	IAHIsub->AHIsub_Enable(___AudioCtrl)

#define AHIsub_Start(___Flags, ___AudioCtrl) \
	IAHIsub->AHIsub_Start(___Flags, ___AudioCtrl)

#define AHIsub_Update(___Flags, ___AudioCtrl) \
	IAHIsub->AHIsub_Update(___Flags, ___AudioCtrl)

#define AHIsub_Stop(___Flags, ___AudioCtrl) \
	IAHIsub->AHIsub_Stop(___Flags, ___AudioCtrl)

#define AHIsub_SetVol(___Channel, ___Volume, ___Pan, ___AudioCtrl, ___Flags) \
	IAHIsub->AHIsub_SetVol(___Channel, ___Volume, ___Pan, ___AudioCtrl, ___Flags)

#define AHIsub_SetFreq(___Channel, ___Freq, ___AudioCtrl, ___Flags) \
	IAHIsub->AHIsub_SetFreq(___Channel, ___Freq, ___AudioCtrl, ___Flags)

#define AHIsub_SetSound(___Channel, ___Sound, ___Offset, ___Length, ___AudioCtrl, ___Flags) \
	IAHIsub->AHIsub_SetSound(___Channel, ___Sound, ___Offset, ___Length, ___AudioCtrl, ___Flags)

#define AHIsub_SetEffect(___Effect, ___AudioCtrl) \
	IAHIsub->AHIsub_SetEffect(___Effect, ___AudioCtrl)

#define AHIsub_LoadSound(___Sound, ___Type, ___Info, ___AudioCtrl) \
	IAHIsub->AHIsub_LoadSound(___Sound, ___Type, ___Info, ___AudioCtrl)

#define AHIsub_UnloadSound(___Sound, ___Audioctrl) \
	IAHIsub->AHIsub_UnloadSound(___Sound, ___Audioctrl)

#define AHIsub_GetAttr(___Attribute, ___Argument, ___DefValue, ___tagList, ___AudioCtrl) \
	IAHIsub->AHIsub_GetAttr(___Attribute, ___Argument, ___DefValue, ___tagList, ___AudioCtrl)

#define AHIsub_HardwareControl(___Attribute, ___Argument, ___AudioCtrl) \
	IAHIsub->AHIsub_HardwareControl(___Attribute, ___Argument, ___AudioCtrl)

#endif /* !_INLINE_AHI_SUB_H */
