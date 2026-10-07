#ifndef CLIB_TIMESYNC_PROTOS_H
#define CLIB_TIMESYNC_PROTOS_H


/*
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**    All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
**    Copyright (c) 2025 Hyperion Entertainment BV.
**        All Rights Reserved.
*/

#ifndef   LIBRARIES_TIMESYNC_H
#include <libraries/timesync.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

ULONG RemoteSyncA(const struct TagItem * taglist);
ULONG RemoteSync(Tag taglist, ...);

#endif /*  CLIB_TIMESYNC_PROTOS_H  */
