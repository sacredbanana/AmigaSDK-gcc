#ifndef LIBRARIES_TIMEZONE_H
#define LIBRARIES_TIMEZONE_H
/*
**    $VER: timezone.h 54.16 (22.08.2022)
**
**    Timezone definitions
**
**    Copyright (C) 2005-2007 Stefan Falke
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
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

/* GetTimezoneAttrsA() attributes */
#define TZA_Timezone            (TAG_USER+1)
    /* (STRPTR) Name of local standard or daylight saving time zone (G). */

#define TZA_TimezoneSTD         (TAG_USER+10)
    /* (STRPTR) Name of local standard time zone (G). */

#define TZA_TimezoneDST         (TAG_USER+18)
    /* (STRPTR) Name of local daylight saving time zone (G). */

#define TZA_UTCOffset           (TAG_USER+2)
    /* (int32 *) Offset between current local time and UTC/GMT in minutes (G). */

#define TZA_UTCOffsetSTD        (TAG_USER+11)
    /* (int32 *) Offset between local standard time and UTC/GMT (G). */

#define TZA_UTCOffsetDST        (TAG_USER+15)
    /* (int32 *) Offset between local daylight saving time and UTC/GMT (G). */

#define TZA_TimeFlag            (TAG_USER+3)
    /* (BYTE *) See TFLG defines below (G). */

#define TZA_UTCOffsetRFC        (TAG_USER+13)
    /* (STRPTR) RFC 2822 compliant timezone string (G). */

#define TZA_DSTStart            (TAG_USER+16)
    /* (uint32 *) Number of seconds from 01-Jan-1978 to the date of the next
                 DST switch (G). */

#define TZA_DSTEnd              (TAG_USER+17)
    /* (uint32 *) Number of seconds from 01-Jan-1978 to the date of the next
                 DST switch (G). */

#define TZA_NextDSTSwitch       (TAG_USER+12)
    /* (uint32 *) Number of seconds from 01-Jan-1978 to the date of the next
                 DST switch (G). */


/* GetTimezoneAttrsA() cltags attributes */

#define TZA_CountryCode         (TAG_USER+14)
    /* (STRPTR) Country Code. */

#define TZA_CountryName         (TAG_USER+23)
    /* (STRPTR) Country name. */

#define TZA_RuleName            (TAG_USER+19)
    /* (STRPTR) Name of time zone rule. */


/* see internal/libraries/timezone.h for private attributes */

/* Flags for the TZA_TimeFlag attribute. */
#define TFLG_ISSTD      0   /* Standard time is in effect for current location */
#define TFLG_ISDST      1   /* Daylight saving time is in effect for current location */
#define TFLG_UNKNOWN    -1  /* Unknown whether standard or daylight saving time is in effect */

#define MAX_TZSIZE      5+1        /* Maximum length of time zone name
                                      including final NULL byte */
#define MAX_RFCSIZE     MAX_TZSIZE /* Maximum length of RFC 2822 compliant UTC offset string
                                      including final NULL byte */
#define MAX_ZONESIZE    128+1      /* Maximum length of TZ env var
                                      including final NULL byte */

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

#ifdef __cplusplus
}
#endif

/****************************************************************************/

#endif /* LIBRARIES_TIMEZONE_H */
