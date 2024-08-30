#ifndef PROTO_MATHIEEEDOUBTRANS_H
#define PROTO_MATHIEEEDOUBTRANS_H

/*
**    $VER: mathieeedoubtrans.h 54.16 (22.08.2022)
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

#error mathieeedoubtrans.library is not supported on AmigaOS4

/****************************************************************************/

#else

/****************************************************************************/

#ifdef __GNUC__
#include <inline/mathieeedoubtrans.h>
#else
#ifndef   PRAGMAS_MATHIEEEDOUBTRANS_PRAGMAS_H
#include <pragmas/mathieeedoubtrans_pragmas.h>
#endif
#endif /* __GNUC__ */

#ifndef __NOLIBBASE__
extern struct Library * MathIeeeDoubTransBase;
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_MATHIEEEDOUBTRANS_H */
