#ifndef PREFS_TIMEZONE_H
#define PREFS_TIMEZONE_H
/*
**    $VER: timezone.h 54.16 (22.08.2022)
**
**    File format for timezone preferences
**
**    Copyright (C) 1985-2006 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   LIBRARIES_TIMEZONE_H
#include <libraries/timezone.h>
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

#define ID_ZONE MAKE_ID('Z','O','N','E')

#define MAX_ZONE_SIZE       32+1

struct TimezonePrefs
{
    uint16  tzp_Version;                     /* Version of TimezonePrefs structure  */
    uint16  tzp_Reserved;                    /* System reserved                     */
    uint32  tzp_Reserved0[3];                /* System reserved                     */
    uint32  tzp_CountryCode;                 /* 3-letter country code (ISO 3166-1)  */
    TEXT    tzp_TZ[MAX_ZONE_SIZE];           /* time zone string                    */
    TEXT    tzp_RuleName[MAX_ZONE_SIZE];     /* rule name                           */
    uint16  tzp_Flags;                       /* see below                           */
};

/* Public tzp_Flags values */
#define TZP_NOASK    0x0002      /* Don't ask before switching from and to DST */
#define TZP_NOREQ    0x0004      /* Don't display DST notification requester   */
#define TZP_NOSWITCH 0x0008      /* Don't automatically switch from and to DST */

#define TZP_TZMODE1  0x0010      /* Write TZ in the same format as TZONE       */
#define TZP_TZMODE2  0x0020      /* Write TZ using the Zone #?.timezone field  */
#define TZP_TZMODE3  0x0040      /* Currently unused                           */
#define TZP_TZMODE4  0x0080      /* Currently unused                           */
#define TZP_TZMASK   0x00F0

/* see internal/libraries/timezone.h for private values */

/* Current version of TimezonePrefs structure */
#define TZPREFS_VERSION (1)

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

#endif /* PREFS_TIMEZONE_H */
