#ifndef PROTO_TRANSLATOR_H
#define PROTO_TRANSLATOR_H

/*
**    $VER: translator.h 54.16 (22.08.2022)
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

#ifdef __GNUC__
#ifndef __PPC__
#include <inline/translator.h>
#endif
#else
#ifndef   PRAGMAS_TRANSLATOR_PRAGMAS_H
#include <pragmas/translator_pragmas.h>
#endif
#endif /* __GNUC__ */

#ifndef __NOLIBBASE__
extern struct Library * TranslatorBase;
#endif /* __NOLIBBASE__ */

#endif /* PROTO_TRANSLATOR_H */
