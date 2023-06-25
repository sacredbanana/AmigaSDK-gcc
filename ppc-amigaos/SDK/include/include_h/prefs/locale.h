#ifndef PREFS_LOCALE_H
#define PREFS_LOCALE_H
/*
**    $VER: locale.h 54.16 (22.08.2022)
**
**    File format for locale preferences
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

#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
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

#define ID_LCLE MAKE_ID('L','C','L','E')
#define ID_CTRY MAKE_ID('C','T','R','Y')

struct CountryPrefs
{
    uint32 cp_Reserved[4];
    uint32 cp_CountryCode;
    uint32 cp_TelephoneCode;
    uint8  cp_MeasuringSystem;

    TEXT   cp_DateTimeFormat[80];
    TEXT   cp_DateFormat[40];
    TEXT   cp_TimeFormat[40];

    TEXT   cp_ShortDateTimeFormat[80];
    TEXT   cp_ShortDateFormat[40];
    TEXT   cp_ShortTimeFormat[40];

    /* for numeric values */
    TEXT   cp_DecimalPoint[10];
    TEXT   cp_GroupSeparator[10];
    TEXT   cp_FracGroupSeparator[10];
    uint8  cp_Grouping[10];
    uint8  cp_FracGrouping[10];

    /* for monetary values */
    TEXT   cp_MonDecimalPoint[10];
    TEXT   cp_MonGroupSeparator[10];
    TEXT   cp_MonFracGroupSeparator[10];
    uint8  cp_MonGrouping[10];
    uint8  cp_MonFracGrouping[10];
    uint8  cp_MonFracDigits;
    uint8  cp_MonIntFracDigits;

    /* for currency symbols */
    TEXT   cp_MonCS[10];
    TEXT   cp_MonSmallCS[10];
    TEXT   cp_MonIntCS[10];

    /* for positive monetary values */
    TEXT   cp_MonPositiveSign[10];
    uint8  cp_MonPositiveSpaceSep;
    uint8  cp_MonPositiveSignPos;
    uint8  cp_MonPositiveCSPos;

    /* for negative monetary values */
    TEXT   cp_MonNegativeSign[10];
    uint8  cp_MonNegativeSpaceSep;
    uint8  cp_MonNegativeSignPos;
    uint8  cp_MonNegativeCSPos;

    uint8  cp_CalendarType;
};

struct LocalePrefs
{
    uint32              lp_Reserved[4];
    TEXT                lp_CountryName[32];
    TEXT                lp_PreferredLanguages[10][30];
    LONG                lp_GMTOffset;
    uint32              lp_Flags;
    struct CountryPrefs lp_CountryData;
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

#endif /* PREFS_LOCALE_H */
