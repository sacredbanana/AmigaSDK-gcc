/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_CDPLAYER_H
#define _INLINE_CDPLAYER_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef CDPLAYER_BASE_NAME
#define CDPLAYER_BASE_NAME CDPlayerBase
#endif /* !CDPLAYER_BASE_NAME */

#define CDEject(___io_ptr) \
      LP1A5(0x1e, BYTE, CDEject , struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDPlay(___starttrack, ___endtrack, ___io_ptr) \
      LP3A5(0x24, BYTE, CDPlay , ULONG, ___starttrack, a0, ULONG, ___endtrack, a1, struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDResume(___Mode, ___io_ptr) \
      LP2A5(0x2a, BYTE, CDResume , BOOL, ___Mode, a0, struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDStop(___io_ptr) \
      LP1A5(0x30, BYTE, CDStop , struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDJump(___Blocks, ___io_ptr) \
      LP2A5(0x36, BYTE, CDJump , ULONG, ___Blocks, a0, struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDActive(___io_ptr) \
      LP1A5(0x3c, BOOL, CDActive , struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDCurrentTitle(___io_ptr) \
      LP1A5(0x42, ULONG, CDCurrentTitle , struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDTitleTime(___cd_time, ___io_ptr) \
      LP2A5(0x48, BYTE, CDTitleTime , struct CD_Time *, ___cd_time, a0, struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDGetVolume(___vol, ___io_ptr) \
      LP2A5(0x4e, BYTE, CDGetVolume , struct CD_Volume *, ___vol, a0, struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDSetVolume(___vol, ___io_ptr) \
      LP2A5(0x54, BYTE, CDSetVolume , struct CD_Volume *, ___vol, a0, struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDReadTOC(___toc, ___io_ptr) \
      LP2A5(0x5a, BYTE, CDReadTOC , struct CD_TOC *, ___toc, a0, struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#define CDInfo(___cdi, ___io_ptr) \
      LP2A5(0x60, BYTE, CDInfo , struct CD_Info *, ___cdi, a0, struct IOStdReq *, ___io_ptr, d7,\
      , CDPLAYER_BASE_NAME)

#endif /* !_INLINE_CDPLAYER_H */
