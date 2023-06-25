#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_TIMESYNC_H
#define _INLINE_TIMESYNC_H

#ifndef CLIB_TIMESYNC_PROTOS_H
#define CLIB_TIMESYNC_PROTOS_H
#endif

#ifndef  LIBRARIES_TIMESYNC_H
#include <libraries/timesync.h>
#endif

#ifndef TIMESYNC_BASE_NAME
#define TIMESYNC_BASE_NAME TimesyncBase
#endif

#define RemoteSyncA(taglist) ({ \
  const struct TagItem * _RemoteSyncA_taglist = (taglist); \
  ULONG _RemoteSyncA__re = \
  ({ \
  register struct Library * const __RemoteSyncA__bn __asm("a6") = (struct Library *) (TIMESYNC_BASE_NAME);\
  register ULONG __RemoteSyncA__re __asm("d0"); \
  register const struct TagItem * __RemoteSyncA_taglist __asm("a0") = (_RemoteSyncA_taglist); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__RemoteSyncA__re) \
  : "r"(__RemoteSyncA__bn), "r"(__RemoteSyncA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoteSyncA__re; \
  }); \
  _RemoteSyncA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___RemoteSync(struct Library * TimesyncBase, Tag taglist, ...)
{
  return RemoteSyncA((const struct TagItem *) &taglist);
}

#define RemoteSync(tags...) ___RemoteSync(TIMESYNC_BASE_NAME, tags)
#endif

#endif /*  _INLINE_TIMESYNC_H  */
