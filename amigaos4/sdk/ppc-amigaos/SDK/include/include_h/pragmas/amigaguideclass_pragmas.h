#ifndef PRAGMAS_AMIGAGUIDECLASS_PRAGMAS_H
#define PRAGMAS_AMIGAGUIDECLASS_PRAGMAS_H

/*
**    $VER: amigaguideclass_pragmas.h 54.16 (22.08.2022)
**
**    Direct ROM interface (pragma) definitions.
**
**    Copyright (C) 2001-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/* "amigaguide.class" */

/*
 * NOTE: These 68k platform specific #pragma header files are unlikely to see
 *       further updates with the AmigaOS4 update and following development
 *       efforts. If you can, please switch to native PowerPC development.
 */
#ifdef __amigaos4__
#error Include <proto/> header files, not <pragmas/> header files in OS4.
#endif

/*--- functions in V39 or higher (distributed as Release 3.0) ---*/

#pragma libcall AmigaGuideClassBase ObtainEngine 1e 00
#pragma libcall AmigaGuideClassBase LoadXRef 24 9802
#pragma libcall AmigaGuideClassBase ExpungeXRef 2a 00
#pragma libcall AmigaGuideClassBase AddPathEntries 30 0802
#pragma libcall AmigaGuideClassBase CopyPathList 36 801
#pragma libcall AmigaGuideClassBase FreePathList 3c 801
#pragma libcall AmigaGuideClassBase ParsePathString 42 18003
#pragma libcall AmigaGuideClassBase LockE 48 21803
#pragma libcall AmigaGuideClassBase OpenE 4e 21803
#pragma libcall AmigaGuideClassBase SetCurrentDirE 54 1802
#pragma libcall AmigaGuideClassBase GetAGString 5a 001
#pragma libcall AmigaGuideClassBase AddAGHostA 60 90803
#pragma libcall AmigaGuideClassBase RemoveAGHostA 66 9802

#endif /* PRAGMAS_AMIGAGUIDECLASS_PRAGMAS_H */
