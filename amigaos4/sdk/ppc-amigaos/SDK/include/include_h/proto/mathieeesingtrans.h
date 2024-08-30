#ifndef PROTO_MATHIEEESINGTRANS_H
#define PROTO_MATHIEEESINGTRANS_H

/*
**    $VER: mathieeesingtrans.h 54.16 (22.08.2022)
**
**    Lattice `C' style prototype/pragma header file combo
**
**    (C) Copyright 2001-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

/****************************************************************************/

#ifdef __amigaos4__

/****************************************************************************/

#error mathieeesingtrans.library is not supported on AmigaOS4

/****************************************************************************/

#else

/****************************************************************************/

#ifdef __GNUC__
#include <inline/mathieeesingtrans.h>
#else
#ifndef   PRAGMAS_MATHIEEESINGTRANS_PRAGMAS_H
#include <pragmas/mathieeesingtrans_pragmas.h>
#endif
#endif /* __GNUC__ */

#ifndef __NOLIBBASE__
extern struct Library * MathIeeeSingTransBase;
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_MATHIEEESINGTRANS_H */
