#ifndef DOS_DATETIME_H
#define DOS_DATETIME_H
/*
**    $VER: datetime.h  54.100 (07.09.2020)
**
**    Date and time C header for AmigaDOS
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

/****************************************************************************/

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
/* For use by the V1.4+ DOS functions StrtoDate() and DatetoStr() */

struct DateTime
{
    struct DateStamp   dat_Stamp;     /* DOS DateStamp */
    uint8              dat_Format;    /* controls appearance of dat_StrDate */
    uint8              dat_Flags;     /* see BITDEF's below */
    STRPTR             dat_StrDay;    /* day of the week string */
    STRPTR             dat_StrDate;   /* date string */
    STRPTR             dat_StrTime;   /* time string */
};


/****************************************************************************/
/* You need at least this much room for each of the DateTime strings: */

#define LEN_DATSTRING    16


/****************************************************************************/
/* Flags for dat_Flags */

#define DTB_SUBST         0    /* substitute Today, Tomorrow, etc. */
#define DTB_FUTURE        1    /* day of the week is in future */

#define DTF_SUBST        (1<<DTB_SUBST)
#define DTF_FUTURE       (1<<DTB_FUTURE)


/****************************************************************************/
/* Date format values */

#define FORMAT_DOS    0        /* dd-mmm-yy */
#define FORMAT_INT    1        /* yy-mmm-dd */
#define FORMAT_USA    2        /* mm-dd-yy  */
#define FORMAT_CDN    3        /* dd-mm-yy  */
#define FORMAT_DEF    4        /* use default format, as defined
                                  by locale; if locale not available, 
                                  use FORMAT_DOS instead */
#define FORMAT_ISO    5        /* yyyy-mm-dd (ISO 8601)
                                  Requires locale V48 or dos V50.36 
                                  if locale not available */
#define FORMAT_MAX    FORMAT_ISO


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
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* DOS_DATETIME_H */
