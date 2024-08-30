#ifndef CLIB_BUGREPORT_PROTOS_H
#define CLIB_BUGREPORT_PROTOS_H

/*
        bugreport.library C prototypes

        Copyright (c) 2004 The MorphOS Development Team, All Rights Reserved.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void SendBug(STRPTR address, struct TagItem *taglist);
void BPrintf(STRPTR format, ...);
void BPutStr(STRPTR string);
void ClearBug(void);

#ifndef USE_INLINE_STDARG

void SendBugTags(STRPTR address, Tag tag1, ...);

#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_BUGREPORT_PROTOS_H */
