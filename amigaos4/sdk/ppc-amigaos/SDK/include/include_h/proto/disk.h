#ifndef PROTO_DISK_H
#define PROTO_DISK_H

/*
**    $VER: disk.h 54.16 (22.08.2022)
**
**    Lattice `C' style prototype/pragma header file combo
**
**    (C) Copyright 2001-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   RESOURCES_DISK_H
#include <resources/disk.h>
#endif
#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifdef __GNUC__
#ifndef __PPC__
#include <inline/disk.h>
#endif
#else
#ifndef PRAGMAS_DISK_PRAGMAS_H
#include <pragmas/disk_pragmas.h>
#endif
#endif /* __GNUC__ */

#ifndef __NOLIBBASE__
extern struct Library * DiskBase;
#endif /* __NOLIBBASE__ */

#endif /* PROTO_DISK_H */
