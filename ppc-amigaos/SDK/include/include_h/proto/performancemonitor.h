#ifndef PROTO_PERFORMANCEMONITOR_H
#define PROTO_PERFORMANCEMONITOR_H
 
/*
**    $VER: performancemonitor.h 53.29 (10.8.2015)
**
**    Prototype/inline/pragma header file combo
**
**    (C) Copyright 2003-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   UTILITY_UTILITY_H
#include <utility/utility.h>
#endif

#ifndef  _RESOURCES_PERFORMANCEMONITOR_H
#include <resources/performancemonitor.h>
#endif

#ifdef __amigaos4__
 #include <interfaces/performancemonitor.h>
 #ifndef __NOGLOBALIFACE__
  extern struct PerformanceMonitorIFace *IPM;
 #endif /* __NOGLOBALIFACE__ */
#endif /* __amigaos4__ */


#endif
