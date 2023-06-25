#ifndef PRAGMA_DOS_H
#define PRAGMA_DOS_H

/*
**    $VER: dos_lib.h 54.16 (22.08.2022)
**
**    Aztec `C' style pragma header file wrapper
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifdef __amigaos4__
#error Include <proto/> header files, not <pragma/> header files in OS4.
#endif

#ifndef   PRAGMAS_DOS_PRAGMAS_H
#include <pragmas/dos_pragmas.h>
#endif

#endif /* PRAGMA_DOS_H */
