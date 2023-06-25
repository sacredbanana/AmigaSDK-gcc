#ifndef CLIB_MACROS_H
#define CLIB_MACROS_H
/*
**    $Id: macros.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
**
**    C macros
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x)   ((x<0)?(-(x)):(x))

#endif /* CLIB_MACROS_H */
