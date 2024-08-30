#ifndef CLIB_AC97MIXER_PROTOS_H
#define CLIB_AC97MIXER_PROTOS_H

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct AC97Mixer_CodecObject;

void	*AC97FindMixer(void *MixerObject,
                       LONG			mixerID,
                       struct TagItem *MyTags);

LONG	AC97ReadIndex(void *MixerObject,
                      ULONG			Offset);

LONG	AC97WriteIndex(void	*MixerObject,
                       ULONG		Offset,
                       ULONG		Data);


LONG	AC97GetMixerAttr(void	*MixerObject,
                           ULONG attr,
			   void	*valueptr);

LONG	AC97SetMixerAttr(void	*MixerObject,
                           ULONG	attr,
			   LONG	value);

LONG	AC97GetInputAttr(void	*MixerObject,
			   ULONG	index,
                           ULONG	attr,
			   void	*valueptr);

LONG	AC97GetOutputAttr(void	*MixerObject,
			   ULONG	index,
                           ULONG	attr,
			   void	*valueptr);

LONG	AC97SetInputAttr(void	*MixerObject,
			   ULONG	index,
                           ULONG	attr,
			   LONG		value);

LONG	AC97SetOutputAttr(void	*MixerObject,
			   ULONG	index,
                           ULONG	attr,
			   LONG		value);

LONG	AC97AddMixerNotify(void	*MixerObject,
			   ULONG	type,
                           struct Hook	*hook);

LONG	AC97RemMixerNotify(void	*MixerObject,
                           struct Hook	*hook);

LONG AC97AddCodec(struct AC97Mixer_CodecObject *CodecObject);

VOID AC97RemCodec(struct AC97Mixer_CodecObject *CodecObject);

void *AC97AddCodecTagList(struct AC97Mixer_CodecObject *CodecObject, CONST struct TagItem *taglist);

#if !defined(USE_INLINE_STDARG)
void *AC97AddCodecTags(struct AC97Mixer_CodecObject *CodecObject, Tag tag1Type, ... );
#endif

VOID AC97RemCodecByID(LONG MixerID);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_AC97MIXER_PROTOS_H */
