/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_REQTOOLS_H
#define _INLINE_REQTOOLS_H

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

#ifndef REQTOOLS_BASE_NAME
#define REQTOOLS_BASE_NAME ReqToolsBase
#endif /* !REQTOOLS_BASE_NAME */

#define rtAllocRequestA(___type, ___taglist) \
      LP2(0x1e, APTR, rtAllocRequestA , ULONG, ___type, d0, struct TagItem *, ___taglist, a0,\
      , REQTOOLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define rtAllocRequest(___type, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; rtAllocRequestA((___type), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define rtFreeRequest(___req) \
      LP1NR(0x24, rtFreeRequest , APTR, ___req, a1,\
      , REQTOOLS_BASE_NAME)

#define rtFreeReqBuffer(___req) \
      LP1NR(0x2a, rtFreeReqBuffer , APTR, ___req, a1,\
      , REQTOOLS_BASE_NAME)

#define rtChangeReqAttrA(___req, ___taglist) \
      LP2(0x30, LONG, rtChangeReqAttrA , APTR, ___req, a1, struct TagItem *, ___taglist, a0,\
      , REQTOOLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define rtChangeReqAttr(___req, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; rtChangeReqAttrA((___req), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define rtFileRequestA(___filereq, ___file, ___title, ___taglist) \
      LP4(0x36, APTR, rtFileRequestA , struct rtFileRequester *, ___filereq, a1, char *, ___file, a2, char *, ___title, a3, struct TagItem *, ___taglist, a0,\
      , REQTOOLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define rtFileRequest(___filereq, ___file, ___title, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; rtFileRequestA((___filereq), (___file), (___title), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define rtFreeFileList(___filelist) \
      LP1NR(0x3c, rtFreeFileList , struct rtFileList *, ___filelist, a0,\
      , REQTOOLS_BASE_NAME)

#define rtEZRequestA(___bodyfmt, ___gadfmt, ___reqinfo, ___argarray, ___taglist) \
      LP5A4(0x42, ULONG, rtEZRequestA , char *, ___bodyfmt, a1, char *, ___gadfmt, a2, struct rtReqInfo *, ___reqinfo, a3, APTR, ___argarray, d7, struct TagItem *, ___taglist, a0,\
      , REQTOOLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define rtEZRequest(___bodyfmt, ___gadfmt, ___reqinfo, ___argarray, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; rtEZRequestA((___bodyfmt), (___gadfmt), (___reqinfo), (___argarray), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define rtGetStringA(___buffer, ___maxchars, ___title, ___reqinfo, ___taglist) \
      LP5(0x48, ULONG, rtGetStringA , UBYTE *, ___buffer, a1, ULONG, ___maxchars, d0, char *, ___title, a2, struct rtReqInfo *, ___reqinfo, a3, struct TagItem *, ___taglist, a0,\
      , REQTOOLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define rtGetString(___buffer, ___maxchars, ___title, ___reqinfo, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; rtGetStringA((___buffer), (___maxchars), (___title), (___reqinfo), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define rtGetLongA(___longptr, ___title, ___reqinfo, ___taglist) \
      LP4(0x4e, ULONG, rtGetLongA , ULONG *, ___longptr, a1, char *, ___title, a2, struct rtReqInfo *, ___reqinfo, a3, struct TagItem *, ___taglist, a0,\
      , REQTOOLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define rtGetLong(___longptr, ___title, ___reqinfo, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; rtGetLongA((___longptr), (___title), (___reqinfo), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define rtFontRequestA(___fontreq, ___title, ___taglist) \
      LP3(0x60, ULONG, rtFontRequestA , struct rtFontRequester *, ___fontreq, a1, char *, ___title, a3, struct TagItem *, ___taglist, a0,\
      , REQTOOLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define rtFontRequest(___fontreq, ___title, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; rtFontRequestA((___fontreq), (___title), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define rtPaletteRequestA(___title, ___reqinfo, ___taglist) \
      LP3(0x66, LONG, rtPaletteRequestA , char *, ___title, a2, struct rtReqInfo *, ___reqinfo, a3, struct TagItem *, ___taglist, a0,\
      , REQTOOLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define rtPaletteRequest(___title, ___reqinfo, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; rtPaletteRequestA((___title), (___reqinfo), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define rtReqHandlerA(___handlerinfo, ___sigs, ___taglist) \
      LP3(0x6c, ULONG, rtReqHandlerA , struct rtHandlerInfo *, ___handlerinfo, a1, ULONG, ___sigs, d0, struct TagItem *, ___taglist, a0,\
      , REQTOOLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define rtReqHandler(___handlerinfo, ___sigs, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; rtReqHandlerA((___handlerinfo), (___sigs), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define rtSetWaitPointer(___window) \
      LP1NR(0x72, rtSetWaitPointer , struct Window *, ___window, a0,\
      , REQTOOLS_BASE_NAME)

#define rtGetVScreenSize(___screen, ___widthptr, ___heightptr) \
      LP3(0x78, ULONG, rtGetVScreenSize , struct Screen *, ___screen, a0, ULONG *, ___widthptr, a1, ULONG *, ___heightptr, a2,\
      , REQTOOLS_BASE_NAME)

#define rtSetReqPosition(___reqpos, ___newwindow, ___screen, ___window) \
      LP4NR(0x7e, rtSetReqPosition , ULONG, ___reqpos, d0, struct NewWindow *, ___newwindow, a0, struct Screen *, ___screen, a1, struct Window *, ___window, a2,\
      , REQTOOLS_BASE_NAME)

#define rtSpread(___posarray, ___sizearray, ___length, ___min, ___max, ___num) \
      LP6NR(0x84, rtSpread , ULONG *, ___posarray, a0, ULONG *, ___sizearray, a1, ULONG, ___length, d0, ULONG, ___min, d1, ULONG, ___max, d2, ULONG, ___num, d3,\
      , REQTOOLS_BASE_NAME)

#define rtScreenToFrontSafely(___screen) \
      LP1NR(0x8a, rtScreenToFrontSafely , struct Screen *, ___screen, a0,\
      , REQTOOLS_BASE_NAME)

#define rtScreenModeRequestA(___screenmodereq, ___title, ___taglist) \
      LP3(0x90, ULONG, rtScreenModeRequestA , struct rtScreenModeRequester *, ___screenmodereq, a1, char *, ___title, a3, struct TagItem *, ___taglist, a0,\
      , REQTOOLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define rtScreenModeRequest(___screenmodereq, ___title, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; rtScreenModeRequestA((___screenmodereq), (___title), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define rtCloseWindowSafely(___win) \
      LP1NR(0x96, rtCloseWindowSafely , struct Window *, ___win, a0,\
      , REQTOOLS_BASE_NAME)

#define rtLockWindow(___win) \
      LP1(0x9c, APTR, rtLockWindow , struct Window *, ___win, a0,\
      , REQTOOLS_BASE_NAME)

#define rtUnlockWindow(___win, ___winlock) \
      LP2NR(0xa2, rtUnlockWindow , struct Window *, ___win, a0, APTR, ___winlock, a1,\
      , REQTOOLS_BASE_NAME)

#endif /* !_INLINE_REQTOOLS_H */
