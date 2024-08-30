#ifndef PROTO_CIAB_H
#define PROTO_CIAB_H

/*
**    $VER: ciab.h 54.16 (22.08.2022)
**
**    Lattice `C' style prototype/pragma header file combo
**
**    (C) Copyright 2001-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef   EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifdef __GNUC__
#ifndef __PPC__
#include <inline/ciab.h>
#endif
#else
#ifndef   PRAGMAS_CIAB_PRAGMAS_H
#include <pragmas/ciab_pragmas.h>
#endif
#endif /* __GNUC__ */

#endif /* PROTO_CIAB_H */
