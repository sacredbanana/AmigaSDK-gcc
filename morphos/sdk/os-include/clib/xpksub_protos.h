#ifndef  CLIB_XPKSUB_PROTOS_H
#define  CLIB_XPKSUB_PROTOS_H

/*
**	$VER: clib/xpksub_protos.h 3.10 (01.10.96) by SDI
**
**	(C) Copyright 1991-1996 by 
**          Urban Dominik Mueller, Bryan Ford,
**          Christian Schneider, Christian von Roques,
**	    Dirk Stöcker
**	    All Rights Reserved
*/

#ifndef XPK_XPKSUB_H
#include <xpk/xpksub.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct XpkInfo *XpksPackerInfo (void);
LONG XpksPackChunk (struct XpkSubParams *);
void XpksPackFree (struct XpkSubParams *);
LONG XpksPackReset (struct XpkSubParams *);
LONG XpksUnpackChunk(struct XpkSubParams *);
void XpksUnpackFree (struct XpkSubParams *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	/* CLIB_XPKSUB_PROTOS_H */
