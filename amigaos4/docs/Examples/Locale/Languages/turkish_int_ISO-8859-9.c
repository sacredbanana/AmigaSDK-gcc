/*
 * C language library code by TetiSoft@apg.lahn.de (Detlef Würkner)
 */

/*-------------------------------------------------------------------------*/
/*                         variable part                                   */
/*-------------------------------------------------------------------------*/

/* IANA number for ISO-8859-9, see L:CharSets/character-sets */
#define CODESET 12

#include "turkish_int_ISO-8859-9.language_rev.h"

/* turkish without special sorting of turkish dotless i */
#define LIBNAME "turkish_int_ISO-8859-9.language"

/* constants for GetLocaleStr() */
#define GLS_CODE         "tur"        /* ISO-639-2/T 3-letter lowercase language code */

#define GLS_DAY_1        "Pazar"      /* Sunday    */
#define GLS_DAY_2        "Pazartesi"  /* Monday    */
#define GLS_DAY_3        "Salý"       /* Tuesday   */
#define GLS_DAY_4        "Çarþamba"   /* Wednesday */
#define GLS_DAY_5        "Perþembe"   /* Thursday  */
#define GLS_DAY_6        "Cuma"       /* Friday    */
#define GLS_DAY_7        "Cumartesi"  /* Saturday  */

#define GLS_ABDAY_1      "Paz"        /* Sun */
#define GLS_ABDAY_2      "Pzt"        /* Mon */
#define GLS_ABDAY_3      "Sal"        /* Tue */
#define GLS_ABDAY_4      "Çar"        /* Wed */
#define GLS_ABDAY_5      "Per"        /* Thu */
#define GLS_ABDAY_6      "Cum"        /* Fri */
#define GLS_ABDAY_7      "Cmt"        /* Sat */

#define GLS_MON_1        "Ocak"       /* January   */
#define GLS_MON_2        "Þubat"      /* February  */
#define GLS_MON_3        "Mart"       /* March     */
#define GLS_MON_4        "Nisan"      /* April     */
#define GLS_MON_5        "Mayýs"      /* May       */
#define GLS_MON_6        "Haziran"    /* June      */
#define GLS_MON_7        "Temmuz"     /* July      */
#define GLS_MON_8        "Aðustos"    /* August    */
#define GLS_MON_9        "Eylül"      /* September */
#define GLS_MON_10       "Ekim"       /* October   */
#define GLS_MON_11       "Kasým"      /* November  */
#define GLS_MON_12       "Aralýk"     /* December  */

#define GLS_ABMON_1      "Ock"        /* Jan */
#define GLS_ABMON_2      "Þub"        /* Feb */
#define GLS_ABMON_3      "Mar"        /* Mar */
#define GLS_ABMON_4      "Nis"        /* Apr */
#define GLS_ABMON_5      "May"        /* May */
#define GLS_ABMON_6      "Haz"        /* Jun */
#define GLS_ABMON_7      "Tem"        /* Jul */
#define GLS_ABMON_8      "Aus"        /* Aug */
#define GLS_ABMON_9      "Eyl"        /* Sep */
#define GLS_ABMON_10     "Ekm"        /* Oct */
#define GLS_ABMON_11     "Ksm"        /* Nov */
#define GLS_ABMON_12     "Ara"        /* Dec */

#define GLS_YESSTR       "Evet"       /* affirmative response for yes/no queries */
#define GLS_NOSTR        "Hayýr"      /* negative response for yes/no queries    */

#define GLS_AM_STR       "ÖÖ"         /* AM */
#define GLS_PM_STR       "ÖS"         /* PM */

#define GLS_SOFTHYPHEN   "-"          /* soft hyphenation */
#define GLS_HARDHYPHEN   "-"          /* hard hyphenation */

#define GLS_OPENQUOTE    "\""         /* start of quoted block */
#define GLS_CLOSEQUOTE   "\""         /* end of quoted block   */

#define GLS_YESTERDAYSTR "Dün"        /* Yesterday */
#define GLS_TODAYSTR     "Bugün"      /* Today     */
#define GLS_TOMORROWSTR  "Yarýn"      /* Tomorrow  */
#define GLS_FUTURESTR    "Gelecek"    /* Future    */

#define GLS_LANGNAME     "türkçe (i=I)" /* native language name */
                                        /* in this language and charset */

#define GLS_ALTDAY_1     GLS_DAY_1    /* no alternate day names */
#define GLS_ALTDAY_2     GLS_DAY_2
#define GLS_ALTDAY_3     GLS_DAY_3
#define GLS_ALTDAY_4     GLS_DAY_4
#define GLS_ALTDAY_5     GLS_DAY_5
#define GLS_ALTDAY_6     GLS_DAY_6
#define GLS_ALTDAY_7     GLS_DAY_7

#define GLS_ALTMON_1     GLS_MON_1    /* no alternate month names */
#define GLS_ALTMON_2     GLS_MON_2
#define GLS_ALTMON_3     GLS_MON_3
#define GLS_ALTMON_4     GLS_MON_4
#define GLS_ALTMON_5     GLS_MON_5
#define GLS_ALTMON_6     GLS_MON_6
#define GLS_ALTMON_7     GLS_MON_7
#define GLS_ALTMON_8     GLS_MON_8
#define GLS_ALTMON_9     GLS_MON_9
#define GLS_ALTMON_10    GLS_MON_10
#define GLS_ALTMON_11    GLS_MON_11
#define GLS_ALTMON_12    GLS_MON_12

/*-------------------------------------------------------------------------*/
/*                         constant part                                   */
/*-------------------------------------------------------------------------*/

/*
 * No special handling of dotless i,
 * use the generic ISO-8859-9 charset driver.
 */

#include "languagedriver.c"
