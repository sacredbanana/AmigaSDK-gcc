/* Automatically generated header! Do not Edit! */
#ifndef CLIB_REQTOOLS_PROTOS_H
#define CLIB_REQTOOLS_PROTOS_H

struct Screen;
struct Window;
struct rtHandlerInfo;
struct NewWindow;
struct rtReqInfo;
struct rtFileList;
struct rtScreenModeRequester;
struct TagItem;
struct rtFontRequester;
struct rtFileRequester;



#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif	

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR  rtAllocRequestA (ULONG, struct TagItem *);
void  rtFreeRequest (APTR);
void  rtFreeReqBuffer (APTR);
LONG  rtChangeReqAttrA (APTR, struct TagItem *);
APTR  rtFileRequestA(struct rtFileRequester *,char *,char *,struct TagItem *);
void  rtFreeFileList (struct rtFileList *);
ULONG rtEZRequestA (char *,char *,struct rtReqInfo *,APTR,struct TagItem *);
ULONG rtGetStringA (UBYTE *,ULONG,char *,struct rtReqInfo *,struct TagItem *);
ULONG rtGetLongA (ULONG *, char *, struct rtReqInfo *, struct TagItem *);
ULONG rtFontRequestA (struct rtFontRequester *, char *, struct TagItem *);
LONG  rtPaletteRequestA (char *, struct rtReqInfo *, struct TagItem *);
ULONG rtReqHandlerA (struct rtHandlerInfo *, ULONG, struct TagItem *);
void  rtSetWaitPointer (struct Window *);
ULONG rtGetVScreenSize (struct Screen *, ULONG *, ULONG *);
void  rtSetReqPosition (ULONG, struct NewWindow *,
                        struct Screen *, struct Window *);
void  rtSpread (ULONG *, ULONG *, ULONG, ULONG, ULONG, ULONG);
void  rtScreenToFrontSafely (struct Screen *);
ULONG rtScreenModeRequestA (struct rtScreenModeRequester *,
                            char *, struct TagItem *);
void  rtCloseWindowSafely (struct Window *);
APTR  rtLockWindow (struct Window *);
void  rtUnlockWindow (struct Window *, APTR);



struct ReqToolsPrefs *rtLockPrefs (void);
void rtUnlockPrefs (void);



APTR  rtAllocRequest (ULONG, Tag,...);
LONG  rtChangeReqAttr (APTR, Tag,...);
APTR  rtFileRequest (struct rtFileRequester *, char *, char *, Tag,...);
ULONG rtEZRequest (char *, char *, struct rtReqInfo *, struct TagItem *,...);
ULONG rtEZRequestTags (char *, char *, struct rtReqInfo *, APTR, Tag,...);
ULONG rtGetString (UBYTE *, ULONG, char *, struct rtReqInfo *, Tag,...);
ULONG rtGetLong (ULONG *, char *, struct rtReqInfo *, Tag,...);
ULONG rtFontRequest (struct rtFontRequester *, char *, Tag,...);
LONG  rtPaletteRequest (char *, struct rtReqInfo *, Tag,...);
ULONG rtReqHandler (struct rtHandlerInfo *, ULONG, Tag,...);
ULONG rtScreenModeRequest (struct rtScreenModeRequester *, char *, Tag,...);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif 
