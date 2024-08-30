#ifndef PRAGMA_NONVOLATILE_H
#define PRAGMA_NONVOLATILE_H

/*
**    $VER: nonvolatile_lib.h 54.16 (22.08.2022)
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

#ifndef   PRAGMAS_NONVOLATILE_PRAGMAS_H
#include <pragmas/nonvolatile_pragmas.h>
#endif

#endif /* PRAGMA_NONVOLATILE_H */
