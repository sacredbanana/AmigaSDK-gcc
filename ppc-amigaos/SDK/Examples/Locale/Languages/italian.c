/*
 * C language library code by TetiSoft@apg.lahn.de (Detlef Würkner)
 */

/*-------------------------------------------------------------------------*/
/*                         variable part                                   */
/*-------------------------------------------------------------------------*/

/* IANA number for ISO-8859-1, see L:CharSets/character-sets */
#define CODESET 4

#include "italian.language_rev.h"

#define LIBNAME "italian.language"

/* constants for GetLocaleStr() */
#define GLS_CODE         "ita"        /* ISO-639-2/T 3-letter lowercase language code */

#define GLS_DAY_1        "Domenica"   /* Sunday    */
#define GLS_DAY_2        "Lunedì"     /* Monday    */
#define GLS_DAY_3        "Martedì"    /* Tuesday   */
#define GLS_DAY_4        "Mercoledì"  /* Wednesday */
#define GLS_DAY_5        "Giovedì"    /* Thursday  */
#define GLS_DAY_6        "Venerdì"    /* Friday    */
#define GLS_DAY_7        "Sabato"     /* Saturday  */

#define GLS_ABDAY_1      "Dom"        /* Sun */
#define GLS_ABDAY_2      "Lun"        /* Mon */
#define GLS_ABDAY_3      "Mar"        /* Tue */
#define GLS_ABDAY_4      "Mer"        /* Wed */
#define GLS_ABDAY_5      "Gio"        /* Thu */
#define GLS_ABDAY_6      "Ven"        /* Fri */
#define GLS_ABDAY_7      "Sab"        /* Sat */

#define GLS_MON_1        "Gennaio"    /* January   */
#define GLS_MON_2        "Febbraio"   /* February  */
#define GLS_MON_3        "Marzo"      /* March     */
#define GLS_MON_4        "Aprile"     /* April     */
#define GLS_MON_5        "Maggio"     /* May       */
#define GLS_MON_6        "Giugno"     /* June      */
#define GLS_MON_7        "Luglio"     /* July      */
#define GLS_MON_8        "Agosto"     /* August    */
#define GLS_MON_9        "Settembre"  /* September */
#define GLS_MON_10       "Ottobre"    /* October   */
#define GLS_MON_11       "Novembre"   /* November  */
#define GLS_MON_12       "Dicembre"   /* December  */

#define GLS_ABMON_1      "Gen"        /* Jan */
#define GLS_ABMON_2      "Feb"        /* Feb */
#define GLS_ABMON_3      "Mar"        /* Mar */
#define GLS_ABMON_4      "Apr"        /* Apr */
#define GLS_ABMON_5      "Mag"        /* May */
#define GLS_ABMON_6      "Giu"        /* Jun */
#define GLS_ABMON_7      "Lug"        /* Jul */
#define GLS_ABMON_8      "Ago"        /* Aug */
#define GLS_ABMON_9      "Set"        /* Sep */
#define GLS_ABMON_10     "Ott"        /* Oct */
#define GLS_ABMON_11     "Nov"        /* Nov */
#define GLS_ABMON_12     "Dic"        /* Dec */

#define GLS_YESSTR       "Si"         /* affirmative response for yes/no queries */
#define GLS_NOSTR        "No"         /* negative response for yes/no queries    */

#define GLS_AM_STR       "AM"         /* AM */
#define GLS_PM_STR       "PM"         /* PM */

#define GLS_SOFTHYPHEN   "-"          /* soft hyphenation */
#define GLS_HARDHYPHEN   "-"          /* hard hyphenation */

#define GLS_OPENQUOTE    "\""         /* start of quoted block */
#define GLS_CLOSEQUOTE   "\""         /* end of quoted block   */

#define GLS_YESTERDAYSTR "Ieri"       /* Yesterday */
#define GLS_TODAYSTR     "Oggi"       /* Today     */
#define GLS_TOMORROWSTR  "Domani"     /* Tomorrow  */
#define GLS_FUTURESTR    "Futuro"     /* Future    */

#define GLS_LANGNAME     "italiano"   /* native language name */
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

#include "languagedriver.c"
