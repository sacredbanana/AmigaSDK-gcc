/*
 * ToDo Europe:
 * Country    Phone CurrInt   CurrLoc
 * Georgia    995   GEL Laris <U10DA> (no 8Bit charset).
 */
/*
 * $Id: make_country_files.c,v 1.1 2008-09-15 13:16:17 sarcher Exp $
 *
 * $VER: make_country_files.c 51.6 (12.12.2005)
 *
 * Copyright (C) 1999-2005 Hyperion Entertainment VOF and Amiga, Inc.
 * All Rights Reserved
 *
 * This program contains the definitions of all country files used by the
 * AmigaOS locale.library subsystem. Each definition consists of three
 * parts: the country name (e.g. "australia"), the country file
 * version (e.g. "51.4 (12.12.2005)") and the actual country data as
 * defined in <prefs/locale.h>. What actually makes up the country data is
 * difficult to explain. If you don't know how to put one together you
 * probably shouldn't try to add a new one.
 *
 * If you really want to add a new country definition, first make sure that
 * you know what it takes to fill in the country data. Then decide upon a
 * name (US-ASCII only) and make a copy of an existing entry and modify it.
 * When you are finished, fill in the version string, add a pointer in the
 * countries[] table and recompile this program, then start it. It should
 * create a new .country file which should then be copied to
 * "LOCALE:countries". Now fire up the Locale preferences editor and pick
 * your new country definition.
 *
 * The country codes used in the entries below are now fixed to conform
 * to the ISO 3166 standard, using the Alpha-3 names. This used to be a
 * somewhat confusing mix of Alpha-3 names and international car license
 * plate codes. For example, the international car license plate code for
 * Belgium is 'B', and this is what used to be associated with the respective
 * country data. However, the international car license plate code for Canada
 * is 'CDN', yet what used to be listed in the country file was 'CAN' which
 * is the ISO 3166 Alpha-3 name. A short list of country names and associated
 * Alpha-3 names is included below.
 *
 * For more information, contact Olaf Barthel <olsen@amiga.com>
 */

#include <libraries/iffparse.h>
#include <libraries/locale.h>

#include <prefs/prefhdr.h>
#include <prefs/locale.h>

#include <dos/dos.h>

#define __NOLIBBASE__
#define __NOGLOBALIFACE__
#define __USE_INLINE__
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/iffparse.h>
#include <proto/utility.h>

#include <string.h>

/****************************************************************************/

/*
A short list of ISO 3166 country code, alpha-3 names, as used in the
'cp_CountryCode' field:

First column:  '*': implemented
               ' ': ToDo
Second column: '-': no 8Bit charset for the language

  AFGHANISTAN                                  AFG
* ALBANIA                                      ALB
* ALGERIA                                      DZA
  AMERICAN SAMOA                               ASM
* ANDORRA                                      AND
  ANGOLA                                       AGO
  ANGUILLA                                     AIA
  ANTARCTICA                                   ATA
  ANTIGUA AND BARBUDA                          ATG
* ARGENTINA                                    ARG
*-ARMENIA                                      ARM
  ARUBA                                        ABW
* AUSTRALIA                                    AUS
* AUSTRIA                                      AUT
*-AZERBAIJAN                                   AZE
  BAHAMAS                                      BHS
* BAHRAIN                                      BHR
  BANGLADESH                                   BGD
  BARBADOS                                     BRB
* BELARUS                                      BLR
* BELGIUM                                      BEL
  BELIZE                                       BLZ
  BENIN                                        BEN
  BERMUDA                                      BMU
  BHUTAN                                       BTN
* BOLIVIA                                      BOL
* BOSNIA AND HERZEGOWINA                       BIH
* BOTSWANA                                     BWA
  BOUVET ISLAND                                BVT
* BRAZIL                                       BRA
  BRITISH INDIAN OCEAN TERRITORY               IOT
  BRUNEI DARUSSALAM                            BRN
* BULGARIA                                     BGR
  BURKINA FASO                                 BFA
  BURUNDI                                      BDI
  CAMBODIA                                     KHM
  CAMEROON                                     CMR
* CANADA                                       CAN
  CAPE VERDE                                   CPV
  CAYMAN ISLANDS                               CYM
  CENTRAL AFRICAN REPUBLIC                     CAF
  CHAD                                         TCD
* CHILE                                        CHL
 -CHINA                                        CHN
  CHRISTMAS ISLAND                             CXR
  COCOS (KEELING) ISLANDS                      CCK
* COLOMBIA                                     COL
  COMOROS                                      COM
  CONGO                                        COG
  CONGO, THE DEMOCRATIC REPUBLIC OF THE        COD
  COOK ISLANDS                                 COK
* COSTA RICA                                   CRI
  COTE D'IVOIRE                                CIV
* CROATIA (local name: Hrvatska)               HRV
  CUBA                                         CUB
* CYPRUS                                       CYP
* CZECH REPUBLIC                               CZE
* DENMARK                                      DNK
  DJIBOUTI                                     DJI
  DOMINICA                                     DMA
* DOMINICAN REPUBLIC                           DOM
  EAST TIMOR                                   TMP
* ECUADOR                                      ECU
* EGYPT                                        EGY
* EL SALVADOR                                  SLV
  EQUATORIAL GUINEA                            GNQ
 -ERITREA                                      ERI
* ESTONIA                                      EST
 -ETHIOPIA                                     ETH
  FALKLAND ISLANDS (MALVINAS)                  FLK
* FAROE ISLANDS                                FRO
  FIJI                                         FJI
* FINLAND                                      FIN
* FRANCE                                       FRA
  FRANCE, METROPOLITAN                         FXX
  FRENCH GUIANA                                GUF
  FRENCH POLYNESIA                             PYF
  FRENCH SOUTHERN TERRITORIES                  ATF
  GABON                                        GAB
  GAMBIA                                       GMB
--GEORGIA                                      GEO
* GERMANY                                      DEU
  GHANA                                        GHA
* GIBRALTAR                                    GIB
* GREECE                                       GRC
* GREENLAND                                    GRL
  GRENADA                                      GRD
  GUADELOUPE                                   GLP
  GUAM                                         GUM
* GUATEMALA                                    GTM
  GUINEA                                       GIN
  GUINEA-BISSAU                                GNB
  GUYANA                                       GUY
  HAITI                                        HTI
  HEARD AND MC DONALD ISLANDS                  HMD
* HOLY SEE (VATICAN CITY STATE)                VAT
* HONDURAS                                     HND
* HONG KONG                                    HKG
* HUNGARY                                      HUN
* ICELAND                                      ISL
* INDIA                                        IND
* INDONESIA                                    IDN
*-IRAN (ISLAMIC REPUBLIC OF)                   IRN
* IRAQ                                         IRQ
* IRELAND                                      IRL
* ISRAEL                                       ISR
* ITALY                                        ITA
  JAMAICA                                      JAM
*-JAPAN                                        JPN
* JORDAN                                       JOR
  KAZAKHSTAN                                   KAZ
  KENYA                                        KEN
  KIRIBATI                                     KIR
 -KOREA, DEMOCRATIC PEOPLE'S REPUBLIC OF       PRK
*-KOREA, REPUBLIC OF                           KOR
* KUWAIT                                       KWT
  KYRGYZSTAN                                   KGZ
  LAO PEOPLE'S DEMOCRATIC REPUBLIC             LAO
* LATVIA                                       LVA
* LEBANON                                      LBN
  LESOTHO                                      LSO
  LIBERIA                                      LBR
* LIBYAN ARAB JAMAHIRIYA                       LBY
* LIECHTENSTEIN                                LIE
* LITHUANIA                                    LTU
* LUXEMBOURG                                   LUX
  MACAU                                        MAC
* MACEDONIA, THE FORMER YUGOSLAV REPUBLIC OF   MKD
  MADAGASCAR                                   MDG
  MALAWI                                       MWI
* MALAYSIA                                     MYS
  MALDIVES                                     MDV
  MALI                                         MLI
* MALTA                                        MLT
  MARSHALL ISLANDS                             MHL
  MARTINIQUE                                   MTQ
  MAURITANIA                                   MRT
  MAURITIUS                                    MUS
  MAYOTTE                                      MYT
* MEXICO                                       MEX
  MICRONESIA, FEDERATED STATES OF              FSM
  MOLDOVA, REPUBLIC OF                         MDA
* MONACO                                       MCO
  MONGOLIA                                     MNG
  MONTSERRAT                                   MSR
* MOROCCO                                      MAR
  MOZAMBIQUE                                   MOZ
  MYANMAR                                      MMR
  NAMIBIA                                      NAM
  NAURU                                        NRU
  NEPAL                                        NPL
* NETHERLANDS                                  NLD
  NETHERLANDS ANTILLES                         ANT
  NEW CALEDONIA                                NCL
* NEW ZEALAND                                  NZL
* NICARAGUA                                    NIC
  NIGER                                        NER
  NIGERIA                                      NGA
  NIUE                                         NIU
  NORFOLK ISLAND                               NFK
  NORTHERN MARIANA ISLANDS                     MNP
* NORWAY                                       NOR
* OMAN                                         OMN
  PAKISTAN                                     PAK
  PALAU                                        PLW
* PANAMA                                       PAN
  PAPUA NEW GUINEA                             PNG
* PARAGUAY                                     PRY
* PERU                                         PER
* PHILIPPINES                                  PHL
  PITCAIRN                                     PCN
* POLAND                                       POL
* PORTUGAL                                     PRT
* PUERTO RICO                                  PRI
* QATAR                                        QAT
  REUNION                                      REU
* ROMANIA                                      ROM
* RUSSIAN FEDERATION                           RUS
  RWANDA                                       RWA
  SAINT KITTS AND NEVIS                        KNA
  SAINT LUCIA                                  LCA
  SAINT VINCENT AND THE GRENADINES             VCT
  SAMOA                                        WSM
* SAN MARINO                                   SMR
  SAO TOME AND PRINCIPE                        STP
* SAUDI ARABIA                                 SAU
  SENEGAL                                      SEN
* SERBIA AND MONTENEGRO                        SCG
  SEYCHELLES                                   SYC
  SIERRA LEONE                                 SLE
* SINGAPORE                                    SGP
* SLOVAKIA (Slovak Republic)                   SVK
* SLOVENIA                                     SVN
  SOLOMON ISLANDS                              SLB
  SOMALIA                                      SOM
* SOUTH AFRICA                                 ZAF
  SOUTH GEORGIA AND THE SOUTH SANDWICH ISLANDS SGS
* SPAIN                                        ESP
  SRI LANKA                                    LKA
  ST. HELENA                                   SHN
  ST. PIERRE AND MIQUELON                      SPM
* SUDAN                                        SDN
  SURINAME                                     SUR
  SVALBARD AND JAN MAYEN ISLANDS               SJM
  SWAZILAND                                    SWZ
* SWEDEN                                       SWE
* SWITZERLAND                                  CHE
* SYRIAN ARAB REPUBLIC                         SYR
 -TAIWAN, PROVINCE OF CHINA                    TWN
  TAJIKISTAN                                   TJK
  TANZANIA, UNITED REPUBLIC OF                 TZA
* THAILAND                                     THA
  TOGO                                         TGO
  TOKELAU                                      TKL
  TONGA                                        TON
  TRINIDAD AND TOBAGO                          TTO
* TUNISIA                                      TUN
* TURKEY                                       TUR
  TURKMENISTAN                                 TKM
  TURKS AND CAICOS ISLANDS                     TCA
  TUVALU                                       TUV
* UGANDA                                       UGA
* UKRAINE                                      UKR
* UNITED ARAB EMIRATES                         ARE
* UNITED KINGDOM                               GBR
* UNITED STATES                                USA
  UNITED STATES MINOR OUTLYING ISLANDS         UMI
* URUGUAY                                      URY
* UZBEKISTAN                                   UZB
  VANUATU                                      VUT
* VENEZUELA                                    VEN
 -VIET NAM                                     VNM
  VIRGIN ISLANDS (BRITISH)                     VGB
  VIRGIN ISLANDS (U.S.)                        VIR
  WALLIS AND FUTUNA ISLANDS                    WLF
  WESTERN SAHARA                               ESH
* YEMEN                                        YEM
* YUGOSLAVIA                                   YUG OBSOLETE
  ZAMBIA                                       ZMB
* ZIMBABWE                                     ZWE
*/

/* We have flags for:
  Afghanistan                      American Samoa
  Angola                           Anguilla
  Antarctica                       Antigua and Barbuda
  Aruba                            Bahamas
  Bangladesh                       Barbados
  Belize                           Benin
  Bermuda                          Bhutan
  British Indian Ocean Territory   Brunei
  Burkina Faso                     Burundi
*/

/****************************************************************************/

#define ID_FVER MAKE_ID('F','V','E','R')
#define ID_CSET	MAKE_ID('C','S','E','T')
#define ID_STRS	MAKE_ID('S','T','R','S')

/****************************************************************************/

#define OK (0)
#define ZERO ((BPTR)NULL)

/****************************************************************************/

struct CountryData
{
    STRPTR              cd_Name;
    ULONG               cd_Charset;    /* TetiSoft: If this is non-zero, */
    STRPTR              cd_NativeName; /* this is the name in this charset */
    STRPTR              cd_Version;
    struct CountryPrefs cd_Prefs;
};

/****************************************************************************/

/* Setup by startup code */
extern struct Library *SysBase;
extern struct Library *DOSBase;
#ifdef __amigaos4__
extern struct ExecIFace *IExec;
extern struct DOSIFace  *IDOS;
#endif

STATIC struct Library *IFFParseBase;
#ifdef __amigaos4__
STATIC struct IFFParseIFace *IIFFParse;
#endif

/****************************************************************************/

STATIC CONST struct CountryData albania_prefs =
{
    "Albania", 4, /* ISO-8859-1 */ "ShqipÎria",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('A','L','B',0),
    /* cp_TelephoneCode         */ 355,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%Y-%b-%d %H.%M.%S.",
    /* cp_DateFormat            */ "%Y-%b-%d",
    /* cp_TimeFormat            */ "%H.%M.%S.",
    /* cp_ShortDateTimeFormat   */ "%y-%b-%d %H.%M.",
    /* cp_ShortDateFormat       */ "%y-%b-%d",
    /* cp_ShortTimeFormat       */ "%H.%M.",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "Lek",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "ALL†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData algeria_prefs =
{
    "Algeria", 9, /* ISO-8859-6 */ "«‰Ã“«∆—",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('D','Z','A',0),
    /* cp_TelephoneCode         */ 213,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "œ.Ã.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "DZD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData andorra_prefs =
{
    "Andorra", 111, /* ISO-8859-15 */ "Andorra (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('A','N','D',0),
    /* cp_TelephoneCode         */ 376,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%e-%m-%Y %H:%M:%S",
    /* cp_DateFormat            */ "%e-%m-%Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%e-%m-%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%e-%m-%Y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ "'",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData argentina_prefs =
{
    "Argentina", 3, /* US-ASCII */ "Argentina",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('A','R','G',0),
    /* cp_TelephoneCode         */ 54,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "ARS†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData armenia_prefs =
{
    "Armenia", 0, /* no 8Bit charset for armenian language */ NULL,
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('A','R','M',0),
    /* cp_TelephoneCode         */ 374,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%m/%d/%y %H:%M",
    /* cp_ShortDateFormat       */ "%m/%d/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Dram", /* <U0534> */
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "AMD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData australia_prefs =
{
    "Australia", 3, /* US-ASCII */ "Australia",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('A','U','S',0),
    /* cp_TelephoneCode         */ 61,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %B %e %Y %I:%M%p",
    /* cp_DateFormat            */ "%A %B %e %Y",
    /* cp_TimeFormat            */ "%I:%M:%S%p",
    /* cp_ShortDateTimeFormat   */ "%e/%m/%Y %I:%M%p",
    /* cp_ShortDateFormat       */ "%e/%m/%Y",
    /* cp_ShortTimeFormat       */ "%I:%M%p",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "c",
    /* cp_MonIntCS              */ "AUD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PARENS,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7SUN
    }
};

STATIC CONST struct CountryData austria_prefs =
{
    "Austria", 111, /* ISO-8859-15 */ "÷sterreich (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('A','U','T',0),
    /* cp_TelephoneCode         */ 43,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e. %B %Y, %H:%M:%S",
    /* cp_DateFormat            */ "%A, %e. %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%Y-%m-%d %H:%M:%S",
    /* cp_ShortDateFormat       */ "%Y-%m-%d",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData azerbaijan_prefs =
{
    "Azerbaijan", 0, /* no 8Bit charset for azeri in latin */ NULL,
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('A','Z','E',0),
    /* cp_TelephoneCode         */ 994,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %d %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A, %d %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%Y %H:%M",
    /* cp_ShortDateFormat       */ "%d.%m.%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ " ",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "man.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "AZM†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData bahrain_prefs =
{
    "Bahrain", 9, /* ISO-8859-6 */ "«‰»Õ—ÍÊ",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('B','H','R',0),
    /* cp_TelephoneCode         */ 973,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "œ.».",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "BHD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData belarus_prefs =
{
    "Belarus", 8, /* ISO-8859-5 */ "±’€–‡„·Ï",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('B','L','R',0),
    /* cp_TelephoneCode         */ 375,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %H:%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%y %H:%M",
    /* cp_ShortDateFormat       */ "%d.%m.%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "‡„—",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "BYR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData belgium_dutch_prefs =
{
    "Belgium_dutch", 111, /* ISO-8859-15 */ "BelgiÎ (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('B','E','L',0),
    /* cp_TelephoneCode         */ 32,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%e-%b-%Y %H:%M:%S",
    /* cp_DateFormat            */ "%e-%b-%Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData belgium_french_prefs =
{
    "Belgium_french", 111, /* ISO-8859-15 */ "Belgique (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('B','E','L',0),
    /* cp_TelephoneCode         */ 32,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%e-%b-%Y %Hh%M",
    /* cp_DateFormat            */ "%e-%b-%Y",
    /* cp_TimeFormat            */ "%Hh%M",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %Hh%M",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%Hh%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData bolivia_prefs =
{
    "Bolivia", 3, /* US-ASCII */ "Bolivia",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('B','O','L',0),
    /* cp_TelephoneCode         */ 591,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$b",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "BOB†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData bosnia_and_herzegowina_prefs =
{
    "Bosnia and Herzegowina", 3, /* US-ASCII */ "Bosna i Hercegovina",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('B','I','H',0),
    /* cp_TelephoneCode         */ 387,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%q:%M:%S %d. %m. %Y.",
    /* cp_DateFormat            */ "%A, %e. %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d. %m. %Y. %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d. %m. %Y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 255 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "KM",
    /* cp_MonSmallCS            */ "Pf",
    /* cp_MonIntCS              */ "BAK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData botswana_prefs =
{
    "Botswana", 3, /* US-ASCII */ "Botswana",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('B','W','A',0),
    /* cp_TelephoneCode         */ 267,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Pu",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "BWP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData brazil_prefs =
{
    "Brazil", 3, /* US-ASCII */ "Brasil",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('B','R','A',0),
    /* cp_TelephoneCode         */ 55,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%q:%M:%S %e de %B, %Y",
    /* cp_DateFormat            */ "%A, %e de %B, %Y",
    /* cp_TimeFormat            */ "%q:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%q:%M:%S %d/%m/%y",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%q:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 0,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "R$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "BRL†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_SUCC_CURR,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_CURR,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7SUN
    }
};

STATIC CONST struct CountryData bulgaria_prefs =
{
    "Bulgaria", 8, /* ISO-8859-5 */ "±Í€”–‡ÿÔ",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('B','G','R',0),
    /* cp_TelephoneCode         */ 359,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%q:%M:%S %e.%m.%Y",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%q:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%H:%M:%S",
    /* cp_ShortDateFormat       */ "%e.%m.%Y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 0,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "€“",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "BGL†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PARENS,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData canada_english_prefs =
{
    "Canada_english", 3, /* US-ASCII */ "Canada (english)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('C','A','N',0),
    /* cp_TelephoneCode         */ 1,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %B %e %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A %B %e %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ ",",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ ",",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "CAD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7SUN
    }
};

STATIC CONST struct CountryData canada_french_prefs =
{
    "Canada_french", 4, /* ISO-8859-1 */ "Canada (franÁais)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('C','A','N',0),
    /* cp_TelephoneCode         */ 1,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%Y-%m-%d %H:%M:%S",
    /* cp_ShortDateFormat       */ "%Y-%m-%d",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "†", /* NBSP */
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "†", /* NBSP */
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "CAD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7SUN
    }
};

STATIC CONST struct CountryData chile_prefs =
{
    "Chile", 3, /* US-ASCII */ "Chile",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('C','H','L',0),
    /* cp_TelephoneCode         */ 56,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "CLP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData colombia_prefs =
{
    "Colombia", 3, /* US-ASCII */ "Colombia",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('C','O','L',0),
    /* cp_TelephoneCode         */ 57,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "COP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData costa_rica_prefs =
{
    "Costa Rica", 3, /* US-ASCII */ "Costa Rica",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('C','R','I',0),
    /* cp_TelephoneCode         */ 506,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "C",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "CRC†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData croatia_prefs =
{
    "Croatia", 3, /* US-ASCII */ "Hrvatska",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('H','R','V',0),
    /* cp_TelephoneCode         */ 385,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e. %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A, %e. %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d.%m.%y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ ".",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Kn",
    /* cp_MonSmallCS            */ "Lp",
    /* cp_MonIntCS              */ "HRK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData cyprus_prefs =
{
    "Cyprus", 10, /* ISO-8859-7 */ " ˝ÒÔÚ",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('C','Y','P',0),
    /* cp_TelephoneCode         */ 357,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %H:%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "CP",
    /* cp_MonSmallCS            */ "c",
    /* cp_MonIntCS              */ "CYP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData czech_republic_prefs =
{
    "Czech Republic", 5, /* ISO-8859-2 */ "»esk· republika",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('C','Z','E',0),
    /* cp_TelephoneCode         */ 420,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %-d.†%<B†%Y,†%q:%M:%S",
    /* cp_DateFormat            */ "%A†%-d.†%<B†%Y",
    /* cp_TimeFormat            */ "%q:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%-d.%-m.%Y†%q:%M",
    /* cp_ShortDateFormat       */ "%-d.%-m.%Y",
    /* cp_ShortTimeFormat       */ "%q:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "†", /* NBSP */
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "KË",
    /* cp_MonSmallCS            */ "h",
    /* cp_MonIntCS              */ "CZK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData denmark_prefs =
{
    "Denmark", 3, /* US-ASCII */ "Danmark",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('D','N','K',0),
    /* cp_TelephoneCode         */ 45,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%e. %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%e. %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m-%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d/%m-%Y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ ".",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "kr.",
    /* cp_MonSmallCS            */ "¯re",
    /* cp_MonIntCS              */ "DKK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData dominican_republic_prefs =
{
    "Dominican Republic", 4, /* ISO-8859-1 */ "Rep˙blica Dominicana",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('D','O','M',0),
    /* cp_TelephoneCode         */ 1809,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "DOP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData ecuador_prefs =
{
    "Ecuador", 3, /* US-ASCII */ "Ecuador",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('E','C','U',0),
    /* cp_TelephoneCode         */ 593,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "ECS†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData egypt_prefs =
{
    "Egypt", 9, /* ISO-8859-6 */ "Â’—",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('E','G','Y',0),
    /* cp_TelephoneCode         */ 20,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "Ã.Â.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "EGP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData el_salvador_prefs =
{
    "El Salvador", 3, /* US-ASCII */ "El Salvador",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('S','L','V',0),
    /* cp_TelephoneCode         */ 503,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "¢",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "SVC†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData estonia_prefs =
{
    "Estonia", 3, /* US-ASCII */ "Eesti",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('E','S','T',0),
    /* cp_TelephoneCode         */ 372,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d.%m.%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "kr",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "EEK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData faroe_islands_prefs =
{
    "Faroe Islands", 4, /* ISO-8859-1 */ "F¯roya",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('F','R','O',0),
    /* cp_TelephoneCode         */ 298,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m-%Y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m-%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ ".",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "kr.",
    /* cp_MonSmallCS            */ "¯re",
    /* cp_MonIntCS              */ "DKK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData finland_prefs =
{
    "Finland", 111, /* ISO-8859-15 */ "Suomi (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('F','I','N',0),
    /* cp_TelephoneCode         */ 358,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%>A, %-d. p‰iv‰n‰ %<B %Y klo %H.%M.%S",
    /* cp_DateFormat            */ "%>A, %-d. p‰iv‰n‰ %<B %Y",
    /* cp_TimeFormat            */ "%H.%M.%S",
    /* cp_ShortDateTimeFormat   */ "%-d.%-m.%y klo %H.%M",
    /* cp_ShortDateFormat       */ "%-d.%-m.%y",
    /* cp_ShortTimeFormat       */ "%H.%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "snt",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData france_prefs =
{
    "France", 111, /* ISO-8859-15 */ "France (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('F','R','A',0),
    /* cp_TelephoneCode         */ 33,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %Hh%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%Hh%M",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %Hh%M",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%Hh%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "†", /* NBSP */
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "†", /* NBSP */
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData germany_prefs =
{
    "Germany", 111, /* ISO-8859-15 */ "Deutschland (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('D','E','U',0),
    /* cp_TelephoneCode         */ 49,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e. %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A, %e. %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d.%m.%Y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ ".",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData gibraltar_prefs =
{
    "Gibraltar", 3, /* US-ASCII */ "Gibraltar",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('G','I','B',0),
    /* cp_TelephoneCode         */ 350,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y  %H:%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "£",
    /* cp_MonSmallCS            */ "p",
    /* cp_MonIntCS              */ "GIP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PARENS,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData greece_prefs =
{
    "Greece", 10, /* ISO-8859-7 */ "≈ÎÎ‹‰· (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('G','R','C',0),
    /* cp_TelephoneCode         */ 30,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %H:%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData greenland_prefs =
{
    "Greenland", 3, /* US_ASCII */ "Kalaallit Nunaat",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('G','R','L',0),
    /* cp_TelephoneCode         */ 299,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%e. %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%e. %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%Y/%m/%d %H:%M:%S",
    /* cp_ShortDateFormat       */ "%Y/%m/%d",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ ".",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "kr.",
    /* cp_MonSmallCS            */ "¯re",
    /* cp_MonIntCS              */ "DKK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData guatemala_prefs =
{
    "Guatemala", 3, /* US-ASCII */ "Guatemala",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('G','T','M',0),
    /* cp_TelephoneCode         */ 502,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Q",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "GTQ†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData holy_see_prefs =
{
    "Vatican", 111, /* ISO-8859-15 */ "Citta del Vaticano (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('V','A','T',0),
    /* cp_TelephoneCode         */ 39,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%q:%M:%S %d/%m/%Y",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%q:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%H:%M:%S %d/%m/%Y",
    /* cp_ShortDateFormat       */ "%e-%b-%Y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_CURR,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7SUN
    }
};

STATIC CONST struct CountryData honduras_prefs =
{
    "Honduras", 3, /* US-ASCII */ "Honduras",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('H','N','D',0),
    /* cp_TelephoneCode         */ 504,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "L.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "HNL†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData hong_kong_prefs =
{
    "Hong Kong", 3, /* US-ASCII */ "Hong Kong",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('H','K','G',0),
    /* cp_TelephoneCode         */ 852,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %B %d, %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A, %B %d, %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "HK$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "HKD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData hungary_prefs =
{
    "Hungary", 5, /* ISO-8859-2 */ "Magyarorsz·g",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('H','U','N',0),
    /* cp_TelephoneCode         */ 36,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%Y. %B %e. %A, %H:%M:%S",
    /* cp_DateFormat            */ "%Y. %B %e. %A",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%Y. %b. %d., %H:%M:%S",
    /* cp_ShortDateFormat       */ "%Y.%m.%d.",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Ft",
    /* cp_MonSmallCS            */ "f",
    /* cp_MonIntCS              */ "HUF†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData iceland_prefs =
{
    "Iceland", 4, /* ISO-8859-1 */ "Õsland",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('I','S','L',0),
    /* cp_TelephoneCode         */ 354,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e.%B %Y, %H:%M:%S",
    /* cp_DateFormat            */ "%A %e.%B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%a %e.%b %y %H:%M",
    /* cp_ShortDateFormat       */ "%a %e.%b %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "kr",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "ISK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData india_prefs =
{
    "India", 3, /* US-ASCII */ "India",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('I','N','D',0),
    /* cp_TelephoneCode         */ 91,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %d %B %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%A %d %B %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%a %d %b %y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%a %d %b %y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Rs",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "INR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData indonesia_prefs =
{
    "Indonesia", 3, /* US-ASCII */ "Indonesia",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('I','D','N',0),
    /* cp_TelephoneCode         */ 62,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Rp",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "IDR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData iran_prefs =
{
    "Iran", 0, /* X-ATO-farsi */ NULL,
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('I','R','N',0),
    /* cp_TelephoneCode         */ 98,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%Y %B %e %p %Q:%M %A",
    /* cp_DateFormat            */ "%Y %B %e %A",
    /* cp_TimeFormat            */ "%p %Q:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%y/%m/%d %p %Q:%M",
    /* cp_ShortDateFormat       */ "%y/%m/%d",
    /* cp_ShortTimeFormat       */ "%p %Q:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ ",",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ ",",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Rls",
    /* cp_MonSmallCS            */ "Toomans",
    /* cp_MonIntCS              */ "IRR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7SAT
    }
};

STATIC CONST struct CountryData iraq_prefs =
{
    "Iraq", 9, /* ISO-8859-6 */ "«‰Ÿ—«‚",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('I','R','Q',0),
    /* cp_TelephoneCode         */ 964,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "œ.Ÿ.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "IQD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData ireland_prefs =
{
    "Ireland", 111, /* ISO-8859-15 */ "Ireland (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('I','R','L',0),
    /* cp_TelephoneCode         */ 353,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y  %H:%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PARENS,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData israel_prefs =
{
    "Israel", 11, /* ISO-8859-8 */ "È˘¯‡Ï",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('I','S','R',0),
    /* cp_TelephoneCode         */ 972,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%H:%M:%S %Y %b %d %a",
    /* cp_DateFormat            */ "%Y %b %d %a",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%H:%M %d/%m/%y",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "˘Á",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "ILS†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_SUCC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData italy_prefs =
{
    "Italy", 111, /* ISO-8859-15 */ "Italia (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('I','T','A',0),
    /* cp_TelephoneCode         */ 39,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%q:%M:%S %d/%m/%Y",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%q:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%H:%M:%S %d/%m/%Y",
    /* cp_ShortDateFormat       */ "%e-%b-%Y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_CURR,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7SUN
    }
};

STATIC CONST struct CountryData japan_prefs =
{
    "Japan", 3, /* US-ASCII */ "Nihon", /* Should be in EUC-JP */
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('J','P','N',0),
    /* cp_TelephoneCode         */ 81,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "«Ø%m∑Ó%e∆¸ %Hª˛%M ¨%S…√",
    /* cp_DateFormat            */ "%Y«Ø%m∑Ó%e∆¸",
    /* cp_TimeFormat            */ "%Hª˛%M ¨%S…√",
    /* cp_ShortDateTimeFormat   */ "«Ø%m∑Ó%e∆¸ %Hª˛%M ¨%S…√",
    /* cp_ShortDateFormat       */ "%Y«Ø%m∑Ó%e∆¸",
    /* cp_ShortTimeFormat       */ "%Hª˛%M ¨",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "YEN",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "JPY†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7SUN
    }
};

STATIC CONST struct CountryData jordan_prefs =
{
    "Jordan", 9, /* ISO-8859-6 */ "«‰√—œÊ",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('J','O','R',0),
    /* cp_TelephoneCode         */ 962,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "œ.√.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "JOD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData korea_republic_prefs =
{
    "South Korea", 3, /* US-ASCII */ "hangook", /* Should be in EUC-KR */
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('K','O','R',0),
    /* cp_TelephoneCode         */ 82,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%Y %B %e %A %p %Q:%M:%S",
    /* cp_DateFormat            */ "%Y %B %e %A",
    /* cp_TimeFormat            */ "%p %Q:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%y-%m-%d %p:%Q:%M",
    /* cp_ShortDateFormat       */ "%y-%m-%d",
    /* cp_ShortTimeFormat       */ "%p:%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Won",
    /* cp_MonSmallCS            */ "Jeon",
    /* cp_MonIntCS              */ "KRW†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData kuwait_prefs =
{
    "Kuwait", 9, /* ISO-8859-6 */ "«‰„ËÍ ",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('K','W','T',0),
    /* cp_TelephoneCode         */ 965,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "œ.„.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "KWD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData latvia_prefs =
{
    "Latvia", 3, /* US-ASCII */ "Latvija",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('L','V','A',0),
    /* cp_TelephoneCode         */ 371,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %Y. gada %e. %B, plkst. %H un %M",
    /* cp_DateFormat            */ "%Y.%m.%d.",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%y.%m.%d. %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d.%m.%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Ls",
    /* cp_MonSmallCS            */ "santÓmu",
    /* cp_MonIntCS              */ "LVL†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData lebanon_prefs =
{
    "Lebanon", 9, /* ISO-8859-6 */ "‰»Ê«Ê",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('L','B','N',0),
    /* cp_TelephoneCode         */ 961,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "‰.‰.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "LBP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData libyan_arab_jamahiriya_prefs =
{
    "Libya", 9, /* ISO-8859-6 */ "‰Í»Í«",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('L','B','Y',0),
    /* cp_TelephoneCode         */ 218,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "œ.‰.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "LYD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData liechtenstein_prefs =
{
    "Liechtenstein", 3, /* US-ASCII */ "Liechtenstein",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('L','I','E',0),
    /* cp_TelephoneCode         */ 423,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e. %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A, %e. %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%e.%m.%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%e.%m.%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "'",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ "'",
    /* cp_MonFracGroupSeparator */ "'",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Fr.",
    /* cp_MonSmallCS            */ "Rp.",
    /* cp_MonIntCS              */ "CHF†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_CURR,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData lithuania_prefs =
{
    "Lithuania", 3, /* US-ASCII */ "Lietuva",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('L','T','U',0),
    /* cp_TelephoneCode         */ 370,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%Y m. %B %d d. %H:%M:%S",
    /* cp_DateFormat            */ "%Y.%m.%d",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%y.%m.%d. %H:%M:%S",
    /* cp_ShortDateFormat       */ "%y.%m.%d",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Lt",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "LTL†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData luxembourg_prefs =
{
    "Luxembourg", 111, /* ISO-8859-15 */ "Luxembourg (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('L','U','X',0),
    /* cp_TelephoneCode         */ 352,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %Hh%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%Hh%M",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%Y %Hh%M",
    /* cp_ShortDateFormat       */ "%d.%m.%Y",
    /* cp_ShortTimeFormat       */ "%Hh%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "†", /* NBSP */
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "†", /* NBSP */
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData macedonia_prefs =
{
    "Macedonia", 8, /* ISO-8859-5 */ "º–⁄’‘ﬁ›ÿ¯–",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('M','K','D',0),
    /* cp_TelephoneCode         */ 389,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e %B %Y %H:%M",
    /* cp_DateFormat            */ "%A, %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%y %H:%M",
    /* cp_ShortDateFormat       */ "%d.%m.%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Den",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "MKD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData malaysia_prefs =
{
    "Malaysia", 3, /* US-ASCII */ "Malaysia",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('M','Y','S',0),
    /* cp_TelephoneCode         */ 60,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "RM",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "MYR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PARENS,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData malta_prefs =
{
    "Malta", 3, /* US-ASCII */ "Malta",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('M','L','T',0),
    /* cp_TelephoneCode         */ 356,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %d ta %b, %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A, %d ta %b, %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%A, %d ta %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%A, %d ta %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Lm",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "MTL†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData mexico_prefs =
{
    "Mexico", 4, /* ISO-8859-1 */ "MÈxico",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('M','E','X',0),
    /* cp_TelephoneCode         */ 52,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "MXP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData monaco_prefs =
{
    "Monaco", 111, /* ISO-8859-15 */ "Monaco (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('M','C','O',0),
    /* cp_TelephoneCode         */ 377,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %Hh%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%Hh%M",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %Hh%M",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%Hh%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "†", /* NBSP */
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "†", /* NBSP */
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData morocco_prefs =
{
    "Morocco", 9, /* ISO-8859-6 */ "«‰Â⁄—»",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('M','A','R',0),
    /* cp_TelephoneCode         */ 212,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "œ.Â.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "MAD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData netherlands_prefs =
{
    "Netherlands", 111, /* ISO-8859-15 */ "Nederland (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('N','L','D',0),
    /* cp_TelephoneCode         */ 31,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A, %e %B,%Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%e-%m-%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%e-%m-%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData new_zealand_prefs =
{
    "New Zealand", 3, /* US-ASCII */ "New Zealand", /* Aotearoa */
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('N','Z','L',0),
    /* cp_TelephoneCode         */ 64,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "NZD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData nicaragua_prefs =
{
    "Nicaragua", 3, /* US-ASCII */ "Nicaragua",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('N','I','C',0),
    /* cp_TelephoneCode         */ 505,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$C",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "NIO†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData norway_prefs =
{
    "Norway", 3, /* US-ASCII */ "Norge", /* In bokmÂl language */
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('N','O','R',0),
    /* cp_TelephoneCode         */ 47,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%e %B %Y %H.%M.%S",
    /* cp_DateFormat            */ "%e %B %Y",
    /* cp_TimeFormat            */ "%H.%M.%S",
    /* cp_ShortDateTimeFormat   */ "%e.%b.%Y %H.%M.%S",
    /* cp_ShortDateFormat       */ "%e.%b.%Y",
    /* cp_ShortTimeFormat       */ "%H.%M.%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "kr.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "NOK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData oman_prefs =
{
    "Oman", 9, /* ISO-8859-6 */ "”‰◊Ê… ŸÂ«Ê",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('O','M','N',0),
    /* cp_TelephoneCode         */ 968,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "—.Ÿ.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "OMR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData panama_prefs =
{
    "Panama", 4, /* ISO-8859-1 */ "Panam·",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('P','A','N',0),
    /* cp_TelephoneCode         */ 507,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "B/",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "PAB†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData paraguay_prefs =
{
    "Paraguay", 3, /* US-ASCII */ "Paraguay",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('P','R','Y',0),
    /* cp_TelephoneCode         */ 595,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Gs.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "PYG†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData peru_prefs =
{
    "Peru", 4, /* ISO-8859-1 */ "Per˙",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('P','E','R',0),
    /* cp_TelephoneCode         */ 51,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "S/",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "PEN†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData philippines_prefs =
{
    "Philippines", 3, /* US-ASCII */ "Philippines", /* Pilipinas */
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('P','H','L',0),
    /* cp_TelephoneCode         */ 63,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %d %B, %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A, %d %B, %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Php",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "PHP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PARENS,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData poland_prefs =
{
    "Poland", 3, /* US-ASCII */ "Polska",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('P','O','L',0),
    /* cp_TelephoneCode         */ 48,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %<B %Y, %H:%M:%S",
    /* cp_DateFormat            */ "%A %e %<B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%Y, %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d.%m.%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 6, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 6, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "z≥", /* ISO-8859-2 */
    /* cp_MonSmallCS            */ "gr",
    /* cp_MonIntCS              */ "PLN†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData portugal_prefs =
{
    "Portugal", 111, /* ISO-8859-15 */ "Portugal (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('P','R','T',0),
    /* cp_TelephoneCode         */ 351,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e de %B de %Y, %H:%M:%S",
    /* cp_DateFormat            */ "%A, %e de %B de %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%e %b %Y, %H:%M:%S",
    /* cp_ShortDateFormat       */ "%e %b %Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "'",
    /* cp_FracGroupSeparator    */ "'",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "+",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData puerto_rico_prefs =
{
    "Puerto Rico", 3, /* US-ASCII */ "Puerto Rico",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('P','R','I',0),
    /* cp_TelephoneCode         */ 1787,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "USD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData qatar_prefs =
{
    "Qatar", 9, /* ISO-8859-6 */ "‚◊—",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('Q','A','T',0),
    /* cp_TelephoneCode         */ 974,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "—.‚.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "QAR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData romania_prefs =
{
    "Romania", 112, /* ISO-8859-16 */ "Rom‚nia",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('R','O','M',0),
    /* cp_TelephoneCode         */ 40,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%Y-%m-%d",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%a %d %b %y %H:%M",
    /* cp_ShortDateFormat       */ "%y-%m-%d",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Lei",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "ROL†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData russian_federation_ISO_8859_5_prefs =
{
    "Russia_ISO-8859-5", 8, /* ISO-8859-5 */ "¿ﬁ··ÿÔ (ISO-8859-5)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('R','U','S',0),
    /* cp_TelephoneCode         */ 7,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %>B %Y ”ﬁ‘– %H:%M:%S",
    /* cp_DateFormat            */ "%A %e %>B %Y ”ﬁ‘–",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "‡„—.",
    /* cp_MonSmallCS            */ "⁄ﬁﬂ.",
    /* cp_MonIntCS              */ "RUR†",
    /* cp_MonPositiveSign       */ "+",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData russian_federation_Amiga_1251_prefs =
{
    "Russia_Amiga-1251", 2104, /* Amiga-1251 */ "–ÓÒÒËˇ (Amiga-1251)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('R','U','S',0),
    /* cp_TelephoneCode         */ 7,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %>B %Y „Ó‰‡ %H:%M:%S",
    /* cp_DateFormat            */ "%A %e %>B %Y „Ó‰‡",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Û·.",
    /* cp_MonSmallCS            */ "ÍÓÔ.",
    /* cp_MonIntCS              */ "RUR†",
    /* cp_MonPositiveSign       */ "+",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData san_marino_prefs =
{
    "San Marino", 111, /* ISO-8859-15 */ "San Marino (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('S','M','R',0),
    /* cp_TelephoneCode         */ 378,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%q:%M:%S %d/%m/%Y",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%q:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%H:%M:%S %d/%m/%Y",
    /* cp_ShortDateFormat       */ "%e-%b-%Y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ ".",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_CURR,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7SUN
    }
};

STATIC CONST struct CountryData saudi_arabia_prefs =
{
    "Saudi Arabia", 9, /* ISO-8859-6 */ "«‰”ŸËœÍ…",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('S','A','U',0),
    /* cp_TelephoneCode         */ 966,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %q:%M:%S",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%q:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%a %e %b, %y %q:%M",
    /* cp_ShortDateFormat       */ "%a %e %b, %y",
    /* cp_ShortTimeFormat       */ "%q:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "œ.Ÿ.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "IQD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData serbia_and_montenegro_prefs =
{
    "Serbia and Montenegro", 3, /* US-ASCII */ "Srbija i Crna Gora",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('S','C','G',0),
    /* cp_TelephoneCode         */ 381,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e. %B %Y. %T",
    /* cp_DateFormat            */ "%A, %e. %B %Y.",
    /* cp_TimeFormat            */ "%T",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%Y. %T",
    /* cp_ShortDateFormat       */ "%d.%m.%Y.",
    /* cp_ShortTimeFormat       */ "%T",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 255 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "din.",
    /* cp_MonSmallCS            */ "p.",
    /* cp_MonIntCS              */ "YUM†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData singapore_prefs =
{
    "Singapore", 3, /* US-ASCII */ "Singapore",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('S','G','P',0),
    /* cp_TelephoneCode         */ 65,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %d,%B,%Y %H:%M:%S",
    /* cp_DateFormat            */ "%A %d,%B,%Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "SGD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PARENS,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData slovakia_prefs =
{
    "Slovakia", 5, /* ISO-8859-2 */ "Slovensk· republika",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('S','V','K',0),
    /* cp_TelephoneCode         */ 421,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %-d.†%<B†%Y,†%q:%M:%S",
    /* cp_DateFormat            */ "%A†%-d.†%<B†%Y",
    /* cp_TimeFormat            */ "%q:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%-d.%-m.%Y†%q:%M",
    /* cp_ShortDateFormat       */ "%-d.%-m.%Y",
    /* cp_ShortTimeFormat       */ "%q:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "†", /* NBSP */
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Sk",
    /* cp_MonSmallCS            */ "h",
    /* cp_MonIntCS              */ "SKK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData slovenia_prefs =
{
    "Slovenia", 3, /* US-ASCII */ "Slovenija",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('S','V','N',0),
    /* cp_TelephoneCode         */ 386,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e. %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A, %e. %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d.%m.%y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "SIT",
    /* cp_MonSmallCS            */ "1/100",
    /* cp_MonIntCS              */ "SIT†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData south_africa_prefs =
{
    "South Africa", 3, /* US-ASCII */ "South Africa", /* Suid Africa */
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('Z','A','F',0),
    /* cp_TelephoneCode         */ 27,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "R",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "ZAR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData spain_prefs =
{
    "Spain", 111, /* ISO-8859-15 */ "EspaÒa (§)",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('E','S','P',0),
    /* cp_TelephoneCode         */ 34,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%e-%m-%Y %H:%M:%S",
    /* cp_DateFormat            */ "%e-%m-%Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%e-%m-%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%e-%m-%Y",
    /* cp_ShortTimeFormat       */ "%H:%M:%S",
    /* cp_DecimalPoint          */ "'",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "§",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "EUR†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData sudan_prefs =
{
    "Sudan", 9, /* ISO-8859-6 */ "«‰”Ëœ«Ê",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('S','D','N',0),
    /* cp_TelephoneCode         */ 249,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "Ã.”.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "SDP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData sweden_prefs =
{
    "Sweden", 3, /* US-ASCII */ "Sverige",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('S','W','E',0),
    /* cp_TelephoneCode         */ 46,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%Y-%m-%d kl %H.%M.%S",
    /* cp_DateFormat            */ "%Y-%m-%d",
    /* cp_TimeFormat            */ "%H.%M.%S",
    /* cp_ShortDateTimeFormat   */ "%Y-%m-%d kl %H.%M.%S",
    /* cp_ShortDateFormat       */ "%Y-%m-%d",
    /* cp_ShortTimeFormat       */ "%H.%M.%S",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "†", /* NBSP */
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "†", /* NBSP */
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 2, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "kr",
    /* cp_MonSmallCS            */ "ˆre",
    /* cp_MonIntCS              */ "SEK†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData switzerland_french_prefs =
{
    "Switzerland_french", 3, /* US-ASCII */ "Suisse",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('C','H','E',0),
    /* cp_TelephoneCode         */ 41,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%e.%m.%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%e.%m.%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "'",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ "'",
    /* cp_MonFracGroupSeparator */ "'",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Fr.",
    /* cp_MonSmallCS            */ "ct.",
    /* cp_MonIntCS              */ "CHF†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_CURR,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData switzerland_german_prefs =
{
    "Switzerland_german", 3, /* US-ASCII */ "Schweiz",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('C','H','E',0),
    /* cp_TelephoneCode         */ 41,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e. %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A, %e. %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%e.%m.%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%e.%m.%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "'",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ "'",
    /* cp_MonFracGroupSeparator */ "'",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Fr.",
    /* cp_MonSmallCS            */ "Rp.",
    /* cp_MonIntCS              */ "CHF†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_CURR,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData switzerland_italian_prefs =
{
    "Switzerland_italian", 3, /* US-ASCII */ "Svizzera",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('C','H','E',0),
    /* cp_TelephoneCode         */ 41,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%e.%m.%Y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%e.%m.%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "'",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ "'",
    /* cp_MonFracGroupSeparator */ "'",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Fr.",
    /* cp_MonSmallCS            */ "ct.",
    /* cp_MonIntCS              */ "CHF†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_CURR,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData syrian_arab_republic_prefs =
{
    "Syria", 9, /* ISO-8859-6 */ "”Ë—Í«",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('S','Y','R',0),
    /* cp_TelephoneCode         */ 963,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "‰.”.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "SYP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData thailand_prefs =
{
    "Thailand", 2259, /* TIS-620 */ "ª√–‡∑»‰∑¬",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('T','H','A',0),
    /* cp_TelephoneCode         */ 66,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %e %b %Y, %H:%M:%S",
    /* cp_DateFormat            */ "%a %e %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y, %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "ﬂ", /* THAI CURRENCY SYMBOL BAHT */
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "THB†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_SUCC_CURR,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_SUCC_CURR,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData tunisia_prefs =
{
    "Tunisia", 9, /* ISO-8859-6 */ " ËÊ”",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('T','U','N',0),
    /* cp_TelephoneCode         */ 216,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "œ. .",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "TND†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData turkey_prefs =
{
    "Turkey", 12, /* ISO-8859-9 */ "T¸rkiye",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('T','U','R',0),
    /* cp_TelephoneCode         */ 90,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%e %B %Y %H:%M:%S",
    /* cp_DateFormat            */ "%e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M:%S",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ "'",
    /* cp_FracGroupSeparator    */ ",",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ ",",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "TL",
    /* cp_MonSmallCS            */ "kuru˛",
    /* cp_MonIntCS              */ "TRL†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7SUN
    }
};

STATIC CONST struct CountryData uganda_prefs =
{
    "Uganda", 3, /* US-ASCII */ "Yuganda", /* in Luganda language, uses ISO-8859-10 */
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('U','G','A',0),
    /* cp_TelephoneCode         */ 256,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "/-",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "UGX†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData ukraine_prefs =
{
    "Ukraine", 8, /* ISO-8859-5 */ "√⁄‡–˜›–",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('U','K','R',0),
    /* cp_TelephoneCode         */ 380,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A %e %B %Y %H:%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%y %H:%M",
    /* cp_ShortDateFormat       */ "%d.%m.%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ ".",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ "†", /* NBSP */
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "”‡",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "UAH†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData united_arab_emirates_prefs =
{
    "United Arab Emirates", 9, /* ISO-8859-6 */ "«‰≈Â«—« ",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('A','R','E',0),
    /* cp_TelephoneCode         */ 971,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "œ.≈.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "AED†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

#if 0
STATIC CONST struct CountryData united_kingdom_gb_prefs =
{
    "Great Britain", 3, /* US-ASCII */ "Great Britain",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('G','B','R',0),
    /* cp_TelephoneCode         */ 44,
    /* cp_MeasuringSystem       */ MS_BRITISH,
    /* cp_DateTimeFormat        */ "%A %e %B %Y  %H:%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "£",
    /* cp_MonSmallCS            */ "p",
    /* cp_MonIntCS              */ "GBP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PARENS,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};
#endif

/* UK includes northern ireland, GB not... */
STATIC CONST struct CountryData united_kingdom_uk_prefs =
{
    "United Kingdom", 3, /* US-ASCII */ "United Kingdom",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('G','B','R',0),
    /* cp_TelephoneCode         */ 44,
    /* cp_MeasuringSystem       */ MS_BRITISH,
    /* cp_DateTimeFormat        */ "%A %e %B %Y  %H:%M",
    /* cp_DateFormat            */ "%A %e %B %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%Y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%Y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "£",
    /* cp_MonSmallCS            */ "p",
    /* cp_MonIntCS              */ "GBP†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PARENS,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData united_states_prefs =
{
    "United States", 3, /* US-ASCII */ "United States",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('U','S','A',0),
    /* cp_TelephoneCode         */ 1,
    /* cp_MeasuringSystem       */ MS_AMERICAN,
    /* cp_DateTimeFormat        */ "%A %B %e %Y %Q:%M %p",
    /* cp_DateFormat            */ "%A %B %e %Y",
    /* cp_TimeFormat            */ "%Q:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%m/%d/%Y %Q:%M %p",
    /* cp_ShortDateFormat       */ "%m/%d/%Y",
    /* cp_ShortTimeFormat       */ "%Q:%M %p",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ ",",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 3, 0 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ ",",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 3, 0 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "$",
    /* cp_MonSmallCS            */ "Cent",
    /* cp_MonIntCS              */ "USD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7SUN
    }
};

STATIC CONST struct CountryData uruguay_prefs =
{
    "Uruguay", 3, /* US-ASCII */ "Uruguay",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('U','R','Y',0),
    /* cp_TelephoneCode         */ 598,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "N$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "UYU†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData uzbekistan_prefs =
{
    "Uzbekistan", 0, /* ISO-8859-1 ??? */ NULL, /* Uzbekiston */
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('U','Z','B',0),
    /* cp_TelephoneCode         */ 27,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%H:%M:%S, %d %B, %Y yil, %A",
    /* cp_DateFormat            */ "%d %B, %Y yil, %A",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%H:%M, %d/%m/%y",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "so'm",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "UZS†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData venezuela_prefs =
{
    "Venezuela", 3, /* US-ASCII */ "Venezuela",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('V','E','N',0),
    /* cp_TelephoneCode         */ 58,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ ".",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Bs.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "VEB†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

STATIC CONST struct CountryData yemen_prefs =
{
    "Yemen", 9, /* ISO-8859-6 */ "«‰ÍÂÊ",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('Y','E','M',0),
    /* cp_TelephoneCode         */ 967,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%d %b, %Y %I:%M:%S %p",
    /* cp_DateFormat            */ "%d %b, %Y",
    /* cp_TimeFormat            */ "%I:%M:%S %p",
    /* cp_ShortDateTimeFormat   */ "%d %b, %y %H:%M",
    /* cp_ShortDateFormat       */ "%d %b, %y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 3,
    /* cp_MonIntFracDigits      */ 3,
    /* cp_MonCS                 */ "—.Í.",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "YER†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_PRECEDES,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_PRECEDES,
    /* cp_CalendarType          */ CT_7MON
    }
};

#if 0 /* obsolete */
STATIC CONST struct CountryData yugoslavia_prefs =
{
    "Yugoslavia", 3, /* US-ASCII */ "Jugoslavija",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('Y','U','G',0),
    /* cp_TelephoneCode         */ 381,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%A, %e. %B %Y. %T",
    /* cp_DateFormat            */ "%A, %e. %B %Y.",
    /* cp_TimeFormat            */ "%T",
    /* cp_ShortDateTimeFormat   */ "%d.%m.%Y. %T",
    /* cp_ShortDateFormat       */ "%d.%m.%Y.",
    /* cp_ShortTimeFormat       */ "%T",
    /* cp_DecimalPoint          */ ",",
    /* cp_GroupSeparator        */ "",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 255 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ",",
    /* cp_MonGroupSeparator     */ "",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 255 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "din.",
    /* cp_MonSmallCS            */ "p.",
    /* cp_MonIntCS              */ "YUM†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_SPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_SPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};
#endif

STATIC CONST struct CountryData zimbabwe_prefs =
{
    "Zimbabwe", 3, /* US-ASCII */ "Zimbabwe",
    "51.4 (12.12.2005)",

    {
    /* cp_Reserved              */ { 0 },
    /* cp_CountryCode           */ MAKE_ID('Z','W','E',0),
    /* cp_TelephoneCode         */ 263,
    /* cp_MeasuringSystem       */ MS_ISO,
    /* cp_DateTimeFormat        */ "%a %d %b %Y %H:%M:%S",
    /* cp_DateFormat            */ "%a %d %b %Y",
    /* cp_TimeFormat            */ "%H:%M:%S",
    /* cp_ShortDateTimeFormat   */ "%d/%m/%y %H:%M",
    /* cp_ShortDateFormat       */ "%d/%m/%y",
    /* cp_ShortTimeFormat       */ "%H:%M",
    /* cp_DecimalPoint          */ ".",
    /* cp_GroupSeparator        */ ",",
    /* cp_FracGroupSeparator    */ "",
    /* cp_Grouping              */ { 3, 0 },
    /* cp_FracGrouping          */ { 255 },
    /* cp_MonDecimalPoint       */ ".",
    /* cp_MonGroupSeparator     */ ",",
    /* cp_MonFracGroupSeparator */ "",
    /* cp_MonGrouping           */ { 3, 0 },
    /* cp_MonFracGrouping       */ { 255 },
    /* cp_MonFracDigits         */ 2,
    /* cp_MonIntFracDigits      */ 2,
    /* cp_MonCS                 */ "Z$",
    /* cp_MonSmallCS            */ "",
    /* cp_MonIntCS              */ "ZWD†",
    /* cp_MonPositiveSign       */ "",
    /* cp_MonPositiveSpaceSep   */ SS_NOSPACE,
    /* cp_MonPositiveSignPos    */ SP_PREC_ALL,
    /* cp_MonPositiveCSPos      */ CSP_SUCCEEDS,
    /* cp_MonNegativeSign       */ "-",
    /* cp_MonNegativeSpaceSep   */ SS_NOSPACE,
    /* cp_MonNegativeSignPos    */ SP_PREC_ALL,
    /* cp_MonNegativeCSPos      */ CSP_SUCCEEDS,
    /* cp_CalendarType          */ CT_7MON
    }
};

/*------------------------------------------------------*/

STATIC CONST struct CountryData * regular_countries[] =
{
    &albania_prefs,
    &algeria_prefs,
    &andorra_prefs,
    &argentina_prefs,
    &armenia_prefs,
    &australia_prefs,
    &austria_prefs,
    &azerbaijan_prefs,
    &bahrain_prefs,
    &belarus_prefs,
    &belgium_dutch_prefs,
    &belgium_french_prefs,
    &bolivia_prefs,
    &bosnia_and_herzegowina_prefs,
    &botswana_prefs,
    &bulgaria_prefs,
    &brazil_prefs,
    &canada_english_prefs,
    &canada_french_prefs,
    &chile_prefs,
    &colombia_prefs,
    &costa_rica_prefs,
    &croatia_prefs,
    &cyprus_prefs,
    &czech_republic_prefs,
    &denmark_prefs,
    &dominican_republic_prefs,
    &ecuador_prefs,
    &egypt_prefs,
    &el_salvador_prefs,
    &estonia_prefs,
    &faroe_islands_prefs,
    &finland_prefs,
    &france_prefs,
    &germany_prefs,
    &gibraltar_prefs,
    &greece_prefs,
    &greenland_prefs,
    &guatemala_prefs,
    &holy_see_prefs,
    &honduras_prefs,
    &hong_kong_prefs,
    &hungary_prefs,
    &iceland_prefs,
    &india_prefs,
    &indonesia_prefs,
    &iran_prefs,
    &iraq_prefs,
    &ireland_prefs,
    &israel_prefs,
    &italy_prefs,
    &japan_prefs,
    &jordan_prefs,
    &korea_republic_prefs,
    &kuwait_prefs,
    &latvia_prefs,
    &lebanon_prefs,
    &libyan_arab_jamahiriya_prefs,
    &liechtenstein_prefs,
    &lithuania_prefs,
    &luxembourg_prefs,
    &macedonia_prefs,
    &malaysia_prefs,
    &malta_prefs,
    &mexico_prefs,
    &monaco_prefs,
    &morocco_prefs,
    &netherlands_prefs,
    &new_zealand_prefs,
    &nicaragua_prefs,
    &norway_prefs,
    &oman_prefs,
    &panama_prefs,
    &paraguay_prefs,
    &peru_prefs,
    &philippines_prefs,
    &poland_prefs,
    &portugal_prefs,
    &puerto_rico_prefs,
    &qatar_prefs,
    &romania_prefs,
    &russian_federation_Amiga_1251_prefs,
    &russian_federation_ISO_8859_5_prefs,
    &san_marino_prefs,
    &saudi_arabia_prefs,
    &serbia_and_montenegro_prefs,
    &singapore_prefs,
    &slovakia_prefs,
    &slovenia_prefs,
    &south_africa_prefs,
    &spain_prefs,
    &sudan_prefs,
    &sweden_prefs,
    &switzerland_french_prefs,
    &switzerland_german_prefs,
    &switzerland_italian_prefs,
    &syrian_arab_republic_prefs,
    &thailand_prefs,
    &tunisia_prefs,
    &turkey_prefs,
    &uganda_prefs,
    &ukraine_prefs,
    &united_arab_emirates_prefs,
#if 0
    &united_kingdom_gb_prefs,
#endif
    &united_kingdom_uk_prefs,
    &united_states_prefs,
    &uruguay_prefs,
    &uzbekistan_prefs,
    &venezuela_prefs,
    &yemen_prefs,
#if 0
    &yugoslavia_prefs,
#endif
    &zimbabwe_prefs,
    NULL
};

/****************************************************************************/

struct CodeSet
{
    LONG  cs_CodeSet;
    ULONG cs_Reserved[7];
};

LONG WriteOne(CONST struct CountryData * cd)
{
    TEXT versionString[100];
    TEXT fileName[100];
    struct PrefHeader ph;
    struct IFFHandle * iff;
    BOOL opened = FALSE;
    BPTR file = ZERO;
    LONG error;

    strcpy(fileName, cd->cd_Name);
    strcat(fileName, ".country");

    iff = AllocIFF();
    if (iff == NULL)
    {
        error = ERROR_NO_FREE_STORE;
        goto out;
    }

    file = Open(fileName, MODE_NEWFILE);
    if (file == ZERO)
    {
        error = IoErr();
        goto out;
    }

    iff->iff_Stream = (ULONG)file;

    InitIFFasDOS(iff);

    error = OpenIFF(iff, IFFF_WRITE);
    if (error != OK)
    {
        goto out;
    }

    opened = TRUE;

    error = PushChunk(iff, ID_PREF, ID_FORM, IFFSIZE_UNKNOWN);
    if (error != OK)
    {
        goto out;
    }

    error = PushChunk(iff, 0, ID_PRHD, sizeof(ph));
    if (error != OK)
    {
        goto out;
    }

    memset(&ph, 0, sizeof(ph));

    error = WriteChunkBytes(iff, &ph, sizeof(ph));
    if (error > 0)
    {
        error = OK;
    }

    if (error != OK)
    {
        goto out;
    }

    error = PopChunk(iff);
    if (error != OK)
    {
        goto out;
    }


    error = PushChunk(iff, 0, ID_CTRY, sizeof(cd->cd_Prefs));
    if (error != OK)
    {
        goto out;
    }

    error = WriteChunkBytes(iff, (APTR)&cd->cd_Prefs, sizeof(cd->cd_Prefs));
    if (error > 0)
    {
        error = OK;
    }

    if (error != OK)
    {
        goto out;
    }

    error = PopChunk(iff);
    if (error != OK)
    {
        goto out;
    }

    if (cd->cd_Charset && cd->cd_NativeName && cd->cd_NativeName[0])
    {
        struct CatEntry
        {
            ULONG ID;
            ULONG stringlen;
        } ce;
        ULONG zero = 0;
        ULONG pad;
        struct CodeSet cs;

        memset(&cs, 0, sizeof(struct CodeSet));
        cs.cs_CodeSet = cd->cd_Charset;

        error = PushChunk(iff, 0, ID_CSET, IFFSIZE_UNKNOWN);
        if (error != OK)
        {
            goto out;
        }

        error = WriteChunkBytes(iff, &cs, sizeof(struct CodeSet));
        if (error > 0)
        {
            error = OK;
        }

        if (error != OK)
        {
            goto out;
        }

        error = PopChunk(iff);
        if (error != OK)
        {
            goto out;
        }

        error = PushChunk(iff, 0, ID_STRS, IFFSIZE_UNKNOWN);
        if (error != OK)
        {
            goto out;
        }

        ce.ID = 0;
        ce.stringlen = strlen(cd->cd_NativeName);
        switch (ce.stringlen % 4)
        {
            default:
            case 0: ce.stringlen++;
                    pad = 3;
                    break;

            case 1: pad = 3;
                    break;

            case 2: pad = 2;
                    break;

            case 3: pad = 1;
                    break;
        }

        error = WriteChunkBytes(iff, &ce, sizeof(struct CatEntry));
        if (error > 0)
        {
            error = OK;
        }

        if (error != OK)
        {
            goto out;
        }

        if ((cs.cs_CodeSet == 9) || (cs.cs_CodeSet == 11))
        {
            /* TetiSoft: We have to reverse the arabic and hebrew strings
             * here, currently no bidirectional algorithm implemented in the
             * OS but the strings must be written from right to left...
             */
            ULONG len = strlen(cd->cd_NativeName);
            STRPTR revstring = AllocVec(ce.stringlen, MEMF_CLEAR);
            STRPTR src, dst;

            if (!revstring)
            {
                error = -1;
                goto out;
            }
            src = &cd->cd_NativeName[len - 1];
            dst = revstring;
            while (len--)
            {
                *dst++ = *src--;
            }
            error = WriteChunkBytes(iff, revstring, ce.stringlen);
            FreeVec(revstring);
        }
        else
        {
            error = WriteChunkBytes(iff, cd->cd_NativeName, ce.stringlen);
        }

        if (error > 0)
        {
            error = OK;
        }

        if (error != OK)
        {
            goto out;
        }

        error = WriteChunkBytes(iff, &zero, pad);
        if (error > 0)
        {
            error = OK;
        }

        if (error != OK)
        {
            goto out;
        }

        error = PopChunk(iff);
        if (error != OK)
        {
            goto out;
        }
    }

    error = PushChunk(iff, 0, ID_FVER, IFFSIZE_UNKNOWN);
    if (error != OK)
    {
        goto out;
    }

    strcpy(versionString, "$VER: ");
    strcat(versionString, fileName);
    strcat(versionString, " ");
    strcat(versionString, cd->cd_Version);
    strcat(versionString, "\r\n");

    error = WriteChunkBytes(iff, versionString, strlen(versionString) + 1);
    if (error > 0)
    {
        error = OK;
    }

    if (error != OK)
    {
        goto out;
    }

    /* error = */ PopChunk(iff);


    error = PopChunk(iff);
    if (error != OK)
    {
        goto out;
    }


 out:

    if (opened)
    {
        CloseIFF(iff);
    }

    if (file != ZERO)
    {
        Close(file);
    }

    if (iff != NULL)
    {
        FreeIFF(iff);
    }

    if (error != OK && file != ZERO)
    {
        DeleteFile(fileName);
    }
    else
    {
        SetProtection(fileName, FIBF_EXECUTE);
    }

    return error;
}

/****************************************************************************/

LONG WriteCountries(CONST struct CountryData ** table)
{
    LONG error = OK;

    while ((*table) != NULL)
    {
        error = WriteOne((*table++));
        if (error != OK)
        {
            break;
        }
    }

    return error;
}

/****************************************************************************/

int main(void)
{
    BPTR dir;
    int result = RETURN_FAIL;

    IFFParseBase = OpenLibrary("iffparse.library", 37);
    if (IFFParseBase != NULL)
    {
#ifdef __amigaos4__
        IIFFParse = (struct IFFParseIFace *)GetInterface(IFFParseBase, "main", 1, NULL);
        if (IIFFParse != NULL)
#endif
        {
            UnLock(CreateDir("countries"));
            dir = Lock("countries", SHARED_LOCK);
            if (dir != ZERO)
            {
                BPTR oldDir;

                oldDir = CurrentDir(dir);
                if (WriteCountries(regular_countries) == OK)
                {
                    result = RETURN_OK;
                }
                else
                {
                    result = RETURN_ERROR;
                }
                CurrentDir(oldDir);

                UnLock(dir);
            }

#ifdef __amigaos4__
            DropInterface((struct Interface *)IIFFParse);
#endif
        }
        CloseLibrary(IFFParseBase);
    }
    return result;
}
