#ifndef UTILITY_DATE_H
#define UTILITY_DATE_H
/*
**    $VER: date.h 53.29 (10.8.2015)
**
**    Date conversion routines ClockData definition.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

/*****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

struct ClockData
{
    uint16 sec;   /* 0..59 */
    uint16 min;   /* 0..59 */
    uint16 hour;  /* 0..23 */
    uint16 mday;  /* 1..31 */
    uint16 month; /* 1..12 */
    uint16 year;  /* 1978.. */
    uint16 wday;  /* 0..6; 0 == Sunday */
};

/*****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* UTILITY_DATE_H */
