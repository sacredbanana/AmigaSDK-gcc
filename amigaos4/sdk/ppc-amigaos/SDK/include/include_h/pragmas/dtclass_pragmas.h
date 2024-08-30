#ifndef PRAGMAS_DTCLASS_PRAGMAS_H
#define PRAGMAS_DTCLASS_PRAGMAS_H

/*
**    $VER: dtclass_pragmas.h 54.16 (22.08.2022)
**
**    Direct ROM interface (pragma) definitions.
**
**    Copyright (C) 2001-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*
 * NOTE: These 68k platform specific #pragma header files are unlikely to see
 *       further updates with the AmigaOS4 update and following development
 *       efforts. If you can, please switch to native PowerPC development.
 */
#ifdef __amigaos4__
#error Include <proto/> header files, not <pragmas/> header files in OS4.
#endif

/* "dtclass.class" */
/*--- functions in V39 or higher (distributed as Release 3.0) ---*/

#pragma libcall DTClassBase ObtainEngine 1e 00

#endif /* PRAGMAS_DTCLASS_PRAGMAS_H */
