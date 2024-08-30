/*
 * C language library code by TetiSoft@apg.lahn.de (Detlef W�rkner)
 */

/* IANA number for ISO-8859-15, see L:CharSets/character-sets */
#define CODESET 111

#include "danish_ISO-8859-15.language_rev.h"

#define LIBNAME "danish_ISO-8859-15.language"

#define OWN_STRNCMP

/* constants for GetLocaleStr() */
#define GLS_CODE         "dan"        /* ISO-639-2/T 3-letter lowercase language code */

#define GLS_DAY_1        "S�ndag"     /* Sunday    */
#define GLS_DAY_2        "Mandag"     /* Monday    */
#define GLS_DAY_3        "Tirsdag"    /* Tuesday   */
#define GLS_DAY_4        "Onsdag"     /* Wednesday */
#define GLS_DAY_5        "Torsdag"    /* Thursday  */
#define GLS_DAY_6        "Fredag"     /* Friday    */
#define GLS_DAY_7        "L�rdag"     /* Saturday  */

#define GLS_ABDAY_1      "S�n"        /* Sun */
#define GLS_ABDAY_2      "Man"        /* Mon */
#define GLS_ABDAY_3      "Tir"        /* Tue */
#define GLS_ABDAY_4      "Ons"        /* Wed */
#define GLS_ABDAY_5      "Tor"        /* Thu */
#define GLS_ABDAY_6      "Fre"        /* Fri */
#define GLS_ABDAY_7      "L�r"        /* Sat */

#define GLS_MON_1        "Januar"     /* January   */
#define GLS_MON_2        "Februar"    /* February  */
#define GLS_MON_3        "Marts"      /* March     */
#define GLS_MON_4        "April"      /* April     */
#define GLS_MON_5        "Maj"        /* May       */
#define GLS_MON_6        "Juni"       /* June      */
#define GLS_MON_7        "Juli"       /* July      */
#define GLS_MON_8        "August"     /* August    */
#define GLS_MON_9        "September"  /* September */
#define GLS_MON_10       "Oktober"    /* October   */
#define GLS_MON_11       "November"   /* November  */
#define GLS_MON_12       "December"   /* December  */

#define GLS_ABMON_1      "Jan"        /* Jan */
#define GLS_ABMON_2      "Feb"        /* Feb */
#define GLS_ABMON_3      "Mar"        /* Mar */
#define GLS_ABMON_4      "Apr"        /* Apr */
#define GLS_ABMON_5      "Maj"        /* May */
#define GLS_ABMON_6      "Jun"        /* Jun */
#define GLS_ABMON_7      "Jul"        /* Jul */
#define GLS_ABMON_8      "Aug"        /* Aug */
#define GLS_ABMON_9      "Sep"        /* Sep */
#define GLS_ABMON_10     "Okt"        /* Oct */
#define GLS_ABMON_11     "Nov"        /* Nov */
#define GLS_ABMON_12     "Dec"        /* Dec */

#define GLS_YESSTR       "Ja"         /* affirmative response for yes/no queries */
#define GLS_NOSTR        "Nej"        /* negative response for yes/no queries    */

#define GLS_AM_STR       "AM"         /* AM */
#define GLS_PM_STR       "PM"         /* PM */

#define GLS_SOFTHYPHEN   "-"          /* soft hyphenation */
#define GLS_HARDHYPHEN   "-"          /* hard hyphenation */

#define GLS_OPENQUOTE    "\""         /* start of quoted block */
#define GLS_CLOSEQUOTE   "\""         /* end of quoted block   */

#define GLS_YESTERDAYSTR "i g�r"      /* Yesterday */
#define GLS_TODAYSTR     "i dag"      /* Today     */
#define GLS_TOMORROWSTR  "i morgen"   /* Tomorrow  */
#define GLS_FUTURESTR    "fremtid"    /* Future    */

#define GLS_LANGNAME     "dansk (�)"  /* native language name */
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

#include "languagestrncmpdriver.c"

/*-------------------------------------------------------------------------*/
/*                         variable part                                   */
/*-------------------------------------------------------------------------*/

/* Special table for danish alphabet
 * We use this sort order: control chars, white space, punctuation,
 * quotation marks, currency symbols, digits, letters.
 */

enum SortValues
{
    V_CNTRL1,
    V_CNTRL2,
    V_CNTRL3,
    V_CNTRL4,
    V_CNTRL5,
    V_CNTRL6,
    V_CNTRL7,
    V_CNTRL8,
/*  V_CNTRL9, */
    V_CNTRL10,
    V_CNTRL11,
    V_CNTRL12,
    V_CNTRL13,
    V_CNTRL14,
    V_CNTRL15,
    V_CNTRL16,
    V_CNTRL17,
    V_CNTRL18,
    V_CNTRL19,
    V_CNTRL20,
    V_CNTRL21,
    V_CNTRL22,
    V_CNTRL23,
    V_CNTRL24,
    V_CNTRL25,
    V_CNTRL26,
    V_CNTRL27,
    V_CNTRL28,
    V_CNTRL29,
    V_CNTRL30,
    V_CNTRL31,
    V_CNTRL127,
    V_CNTRL128,
    V_CNTRL129,
    V_CNTRL130,
    V_CNTRL131,
    V_CNTRL132,
    V_CNTRL133,
    V_CNTRL134,
    V_CNTRL135,
    V_CNTRL136,
    V_CNTRL137,
    V_CNTRL138,
    V_CNTRL139,
    V_CNTRL140,
    V_CNTRL141,
    V_CNTRL142,
    V_CNTRL143,
    V_CNTRL144,
    V_CNTRL145,
    V_CNTRL146,
    V_CNTRL147,
    V_CNTRL148,
    V_CNTRL149,
    V_CNTRL150,
    V_CNTRL151,
    V_CNTRL152,
    V_CNTRL153,
    V_CNTRL154,
    V_CNTRL155,
    V_CNTRL156,
    V_CNTRL157,
    V_CNTRL158,
    V_CNTRL159,
    V_SPACE,
    V_PUNCT,
    V_QUOTE,
    V_CURR,
    V_DIGIT0,
    V_DIGIT1,
    V_DIGIT2,
    V_DIGIT3,
    V_DIGIT4,
    V_DIGIT5,
    V_DIGIT6,
    V_DIGIT7,
    V_DIGIT8,
    V_DIGIT9,
    V_A,
    V_B,
    V_C,
    V_D,
    V_E,
    V_F,
    V_G,
    V_H,
    V_I,
    V_J,
    V_K,
    V_L,
    V_M,
    V_N,
    V_O,
    V_P,
    V_Q,
    V_R,
    V_S,
    V_T,
    V_U,
    V_V,
    V_W,
    V_X,
    V_Y,
    V_Z,
    V_AE,
    V_OSLASH,
    V_ARING,
    V_MU
};

/* ISO-8859-15 with special handling of ��� to be sorted after Z,
   thorn as T, �=�, �=�, OE=�, �=Y. */

STATIC CONST TEXT Collate1Table[256] =
{
/*  0*/ 0,          /* NUL */
/*  1*/ V_CNTRL1,   /* STX */
/*  2*/ V_CNTRL2,   /* SOT */
/*  3*/ V_CNTRL3,   /* ETX */
/*  4*/ V_CNTRL4,   /* EOT */
/*  5*/ V_CNTRL5,   /* ENQ */
/*  6*/ V_CNTRL6,   /* ACK */
/*  7*/ V_CNTRL7,   /* BEL */
/*  8*/ V_CNTRL8,   /* BS  */
/*  9*/ V_SPACE,    /* TAB */
/* 10*/ V_CNTRL10,  /* LF  */
/* 11*/ V_CNTRL11,  /* VT  */
/* 12*/ V_CNTRL12,  /* FF  */
/* 13*/ V_CNTRL13,  /* CR  */
/* 14*/ V_CNTRL14,  /* SO  */
/* 15*/ V_CNTRL15,  /* SI  */
/* 16*/ V_CNTRL16,  /* DLE */
/* 17*/ V_CNTRL17,  /* DC1 */
/* 18*/ V_CNTRL18,  /* DC2 */
/* 19*/ V_CNTRL19,  /* DC3 */
/* 20*/ V_CNTRL20,  /* DC4 */
/* 21*/ V_CNTRL21,  /* NAK */
/* 22*/ V_CNTRL22,  /* SYN */
/* 23*/ V_CNTRL23,  /* ETB */
/* 24*/ V_CNTRL24,  /* CAN */
/* 25*/ V_CNTRL25,  /* EM  */
/* 26*/ V_CNTRL26,  /* SUB */
/* 27*/ V_CNTRL27,  /* ESC */
/* 28*/ V_CNTRL28,  /* FS  */
/* 29*/ V_CNTRL29,  /* GS  */
/* 30*/ V_CNTRL30,  /* RS  */
/* 31*/ V_CNTRL31,  /* US  */
/* 32*/ V_SPACE,    /*   */
/* 33*/ V_PUNCT,    /* ! */
/* 34*/ V_QUOTE,    /* " */
/* 35*/ V_PUNCT,    /* # */
/* 36*/ V_CURR,     /* $ */
/* 37*/ V_PUNCT,    /* % */
/* 38*/ V_PUNCT,    /* & */
/* 39*/ V_PUNCT,    /* ' */
/* 40*/ V_PUNCT,    /* ( */
/* 41*/ V_PUNCT,    /* ) */
/* 42*/ V_PUNCT,    /* * */
/* 43*/ V_PUNCT,    /* + */
/* 44*/ V_PUNCT,    /* , */
/* 45*/ V_PUNCT,    /* - */
/* 46*/ V_PUNCT,    /* . */
/* 47*/ V_PUNCT,    /* / */
/* 48*/ V_DIGIT0,   /* 0 */
/* 49*/ V_DIGIT1,   /* 1 */
/* 50*/ V_DIGIT2,   /* 2 */
/* 51*/ V_DIGIT3,   /* 3 */
/* 52*/ V_DIGIT4,   /* 4 */
/* 53*/ V_DIGIT5,   /* 5 */
/* 54*/ V_DIGIT6,   /* 6 */
/* 55*/ V_DIGIT7,   /* 7 */
/* 56*/ V_DIGIT8,   /* 8 */
/* 57*/ V_DIGIT9,   /* 9 */
/* 58*/ V_PUNCT,    /* : */
/* 59*/ V_PUNCT,    /* ; */
/* 60*/ V_PUNCT,    /* < */
/* 61*/ V_PUNCT,    /* = */
/* 62*/ V_PUNCT,    /* > */
/* 63*/ V_PUNCT,    /* ? */
/* 64*/ V_PUNCT,    /* @ */
/* 65*/ V_A,        /* A */
/* 66*/ V_B,        /* B */
/* 67*/ V_C,        /* C */
/* 68*/ V_D,        /* D */
/* 69*/ V_E,        /* E */
/* 70*/ V_F,        /* F */
/* 71*/ V_G,        /* G */
/* 72*/ V_H,        /* H */
/* 73*/ V_I,        /* I */
/* 74*/ V_J,        /* J */
/* 75*/ V_K,        /* K */
/* 76*/ V_L,        /* L */
/* 77*/ V_M,        /* M */
/* 78*/ V_N,        /* N */
/* 79*/ V_O,        /* O */
/* 80*/ V_P,        /* P */
/* 81*/ V_Q,        /* Q */
/* 82*/ V_R,        /* R */
/* 83*/ V_S,        /* S */
/* 84*/ V_T,        /* T */
/* 85*/ V_U,        /* U */
/* 86*/ V_V,        /* V */
/* 87*/ V_W,        /* W */
/* 88*/ V_X,        /* X */
/* 89*/ V_Y,        /* Y */
/* 90*/ V_Z,        /* Z */
/* 91*/ V_PUNCT,    /* [ */
/* 92*/ V_PUNCT,    /* \ */
/* 93*/ V_PUNCT,    /* ] */
/* 94*/ V_PUNCT,    /* ^ */
/* 95*/ V_PUNCT,    /* _ */
/* 96*/ V_PUNCT,    /* ` */
/* 97*/ V_A,        /* a */
/* 98*/ V_B,        /* b */
/* 99*/ V_C,        /* c */
/*100*/ V_D,        /* d */
/*101*/ V_E,        /* e */
/*102*/ V_F,        /* f */
/*103*/ V_G,        /* g */
/*104*/ V_H,        /* h */
/*105*/ V_I,        /* i */
/*106*/ V_J,        /* j */
/*107*/ V_K,        /* k */
/*108*/ V_L,        /* l */
/*109*/ V_M,        /* m */
/*110*/ V_N,        /* n */
/*111*/ V_O,        /* o */
/*112*/ V_P,        /* p */
/*113*/ V_Q,        /* q */
/*114*/ V_R,        /* r */
/*115*/ V_S,        /* s */
/*116*/ V_T,        /* t */
/*117*/ V_U,        /* u */
/*118*/ V_V,        /* v */
/*119*/ V_W,        /* w */
/*120*/ V_X,        /* x */
/*121*/ V_Y,        /* y */
/*122*/ V_Z,        /* z */
/*123*/ V_PUNCT,    /* { */
/*124*/ V_PUNCT,    /* | */
/*125*/ V_PUNCT,    /* } */
/*126*/ V_PUNCT,    /* ~ */
/*127*/ V_CNTRL127, /* DEL */
/*128*/ V_CNTRL128, /* XXX */
/*129*/ V_CNTRL129, /* XXX */
/*130*/ V_CNTRL130, /* BPH */
/*131*/ V_CNTRL131, /* NBH */
/*132*/ V_CNTRL132, /* IND */
/*133*/ V_CNTRL133, /* NEL */
/*134*/ V_CNTRL134, /* SSA */
/*135*/ V_CNTRL135, /* ESA */
/*136*/ V_CNTRL136, /* HTS */
/*137*/ V_CNTRL137, /* HTJ */
/*138*/ V_CNTRL138, /* VTS */
/*139*/ V_CNTRL139, /* PLD */
/*140*/ V_CNTRL140, /* PLU */
/*141*/ V_CNTRL141, /* RI  */
/*142*/ V_CNTRL142, /* SS2 */
/*143*/ V_CNTRL143, /* SS3 */
/*144*/ V_CNTRL144, /* DCS */
/*145*/ V_CNTRL145, /* PU1 */
/*146*/ V_CNTRL146, /* PU2 */
/*147*/ V_CNTRL147, /* STS */
/*148*/ V_CNTRL148, /* CCH */
/*149*/ V_CNTRL149, /* MW  */
/*150*/ V_CNTRL150, /* SPA */
/*151*/ V_CNTRL151, /* EPA */
/*152*/ V_CNTRL152, /* SOS */
/*153*/ V_CNTRL153, /* XXX */
/*154*/ V_CNTRL154, /* SCI */
/*155*/ V_CNTRL155, /* CSI */
/*156*/ V_CNTRL156, /* ST  */
/*157*/ V_CNTRL157, /* OSC */
/*158*/ V_CNTRL158, /* PM  */
/*159*/ V_CNTRL159, /* APC */
/*160*/ V_PUNCT,    /* NBSP */
/*161*/ V_PUNCT,    /* � */
/*162*/ V_CURR,     /* � */
/*163*/ V_CURR,     /* � */
/*164*/ V_CURR,     /* � */ /* Euro sign */
/*165*/ V_CURR,     /* � */
/*166*/ V_S,        /* � */ /* S with caron */
/*167*/ V_PUNCT,    /* � */
/*168*/ V_S,        /* � */ /* s with caron */
/*169*/ V_PUNCT,    /* � */
/*170*/ V_A,        /* � */
/*171*/ V_QUOTE,    /* � */
/*172*/ V_PUNCT,    /* � */
/*173*/ V_PUNCT,    /* � */
/*174*/ V_PUNCT,    /* � */
/*175*/ V_PUNCT,    /* � */
/*176*/ V_PUNCT,    /* � */
/*177*/ V_PUNCT,    /* � */
/*178*/ V_DIGIT2,   /* � */
/*179*/ V_DIGIT3,   /* � */
/*180*/ V_Z,        /* � */ /* Z with caron */
/*181*/ V_MU,       /* � */
/*182*/ V_PUNCT,    /* � */
/*183*/ V_PUNCT,    /* � */
/*184*/ V_Z,        /* � */ /* z with caron */
/*185*/ V_DIGIT1,   /* � */
/*186*/ V_O,        /* � */
/*187*/ V_QUOTE,    /* � */
/*188*/ V_OSLASH,   /* � */ /* capital ligature OE */ /* OE=� */
/*189*/ V_OSLASH,   /* � */ /* small ligature OE */ /* OE=� */
/*190*/ V_Y,        /* � */ /* Y with diaeresis */
/*191*/ V_PUNCT,    /* � */
/*192*/ V_A,        /* � */
/*193*/ V_A,        /* � */
/*194*/ V_A,        /* � */
/*195*/ V_A,        /* � */
/*196*/ V_AE,       /* � */ /* �=� */
/*197*/ V_ARING,    /* � */ /* Extra letter 29 of danish alphabet */
/*198*/ V_AE,       /* � */ /* Extra letter 27 of danish alphabet */
/*199*/ V_C,        /* � */
/*200*/ V_E,        /* � */
/*201*/ V_E,        /* � */
/*202*/ V_E,        /* � */
/*203*/ V_E,        /* � */
/*204*/ V_I,        /* � */
/*205*/ V_I,        /* � */
/*206*/ V_I,        /* � */
/*207*/ V_I,        /* � */
/*208*/ V_D,        /* � */
/*209*/ V_N,        /* � */
/*210*/ V_O,        /* � */
/*211*/ V_O,        /* � */
/*212*/ V_O,        /* � */
/*213*/ V_O,        /* � */
/*214*/ V_OSLASH,   /* � */ /* �=� */
/*215*/ V_PUNCT,    /* � */
/*216*/ V_OSLASH,   /* � */ /* Extra letter 28 of danish alphabet */
/*217*/ V_U,        /* � */
/*218*/ V_U,        /* � */
/*219*/ V_U,        /* � */
/*220*/ V_Y,        /* � */ /* �=Y */
/*221*/ V_Y,        /* � */
/*222*/ V_T,        /* � */ /* THORN */
/*223*/ V_S,        /* � */
/*224*/ V_A,        /* � */
/*225*/ V_A,        /* � */
/*226*/ V_A,        /* � */
/*227*/ V_A,        /* � */
/*228*/ V_AE,       /* � */ /* �=� */
/*229*/ V_ARING,    /* � */ /* Extra letter 29 of danish alphabet */
/*230*/ V_AE,       /* � */ /* Extra letter 27 of danish alphabet */
/*231*/ V_C,        /* � */
/*232*/ V_E,        /* � */
/*233*/ V_E,        /* � */
/*234*/ V_E,        /* � */
/*235*/ V_E,        /* � */
/*236*/ V_I,        /* � */
/*237*/ V_I,        /* � */
/*238*/ V_I,        /* � */
/*239*/ V_I,        /* � */
/*240*/ V_D,        /* � */
/*241*/ V_N,        /* � */
/*242*/ V_O,        /* � */
/*243*/ V_O,        /* � */
/*244*/ V_O,        /* � */
/*245*/ V_O,        /* � */
/*246*/ V_OSLASH,   /* � */ /* �=� */
/*247*/ V_PUNCT,    /* � */
/*248*/ V_OSLASH,   /* � */ /* Extra letter 28 of danish alphabet */
/*249*/ V_U,        /* � */
/*250*/ V_U,        /* � */
/*251*/ V_U,        /* � */
/*252*/ V_Y,        /* � */ /* �=Y */
/*253*/ V_Y,        /* � */
/*254*/ V_T,        /* � */ /* THORN */
/*255*/ V_Y         /* � */
};

/*-------------------------------------------------------------------------*/

/* ISO-8859-15 table with Thorn->T */

STATIC CONST TEXT ToUpperTable[256] =
{
/*  0*/   0,    /* NUL */
/*  1*/   1,    /* STX */
/*  2*/   2,    /* SOT */
/*  3*/   3,    /* ETX */
/*  4*/   4,    /* EOT */
/*  5*/   5,    /* ENQ */
/*  6*/   6,    /* ACK */
/*  7*/   7,    /* BEL */
/*  8*/   8,    /* BS  */
/*  9*/   9,    /* TAB */
/* 10*/  10,    /* LF  */
/* 11*/  11,    /* VT  */
/* 12*/  12,    /* FF  */
/* 13*/  13,    /* CR  */
/* 14*/  14,    /* SO  */
/* 15*/  15,    /* SI  */
/* 16*/  16,    /* DLE */
/* 17*/  17,    /* DC1 */
/* 18*/  18,    /* DC2 */
/* 19*/  19,    /* DC3 */
/* 20*/  20,    /* DC4 */
/* 21*/  21,    /* NAK */
/* 22*/  22,    /* SYN */
/* 23*/  23,    /* ETB */
/* 24*/  24,    /* CAN */
/* 25*/  25,    /* EM  */
/* 26*/  26,    /* SUB */
/* 27*/  27,    /* ESC */
/* 28*/  28,    /* FS  */
/* 29*/  29,    /* GS  */
/* 30*/  30,    /* RS  */
/* 31*/  31,    /* US  */
/* 32*/ ' ',    /*   */
/* 33*/ '!',    /* ! */
/* 34*/ '"',    /* " */
/* 35*/ '#',    /* # */
/* 36*/ '$',    /* $ */
/* 37*/ '%',    /* % */
/* 38*/ '&',    /* & */
/* 39*/ '\'',    /* ' */
/* 40*/ '(',    /* ( */
/* 41*/ ')',    /* ) */
/* 42*/ '*',    /* * */
/* 43*/ '+',    /* + */
/* 44*/ ',',    /* , */
/* 45*/ '-',    /* - */
/* 46*/ '.',    /* . */
/* 47*/ '/',    /* / */
/* 48*/ '0',    /* 0 */
/* 49*/ '1',    /* 1 */
/* 50*/ '2',    /* 2 */
/* 51*/ '3',    /* 3 */
/* 52*/ '4',    /* 4 */
/* 53*/ '5',    /* 5 */
/* 54*/ '6',    /* 6 */
/* 55*/ '7',    /* 7 */
/* 56*/ '8',    /* 8 */
/* 57*/ '9',    /* 9 */
/* 58*/ ':',    /* : */
/* 59*/ ';',    /* ; */
/* 60*/ '<',    /* < */
/* 61*/ '=',    /* = */
/* 62*/ '>',    /* > */
/* 63*/ '?',    /* ? */
/* 64*/ '@',    /* @ */
/* 65*/ 'A',    /* A */
/* 66*/ 'B',    /* B */
/* 67*/ 'C',    /* C */
/* 68*/ 'D',    /* D */
/* 69*/ 'E',    /* E */
/* 70*/ 'F',    /* F */
/* 71*/ 'G',    /* G */
/* 72*/ 'H',    /* H */
/* 73*/ 'I',    /* I */
/* 74*/ 'J',    /* J */
/* 75*/ 'K',    /* K */
/* 76*/ 'L',    /* L */
/* 77*/ 'M',    /* M */
/* 78*/ 'N',    /* N */
/* 79*/ 'O',    /* O */
/* 80*/ 'P',    /* P */
/* 81*/ 'Q',    /* Q */
/* 82*/ 'R',    /* R */
/* 83*/ 'S',    /* S */
/* 84*/ 'T',    /* T */
/* 85*/ 'U',    /* U */
/* 86*/ 'V',    /* V */
/* 87*/ 'W',    /* W */
/* 88*/ 'X',    /* X */
/* 89*/ 'Y',    /* Y */
/* 90*/ 'Z',    /* Z */
/* 91*/ '[',    /* [ */
/* 92*/ '\\',   /* \ */
/* 93*/ ']',    /* ] */
/* 94*/ '^',    /* ^ */
/* 95*/ '_',    /* _ */
/* 96*/ '`',    /* ` */
/* 97*/ 'A',    /* a */
/* 98*/ 'B',    /* b */
/* 99*/ 'C',    /* c */
/*100*/ 'D',    /* d */
/*101*/ 'E',    /* e */
/*102*/ 'F',    /* f */
/*103*/ 'G',    /* g */
/*104*/ 'H',    /* h */
/*105*/ 'I',    /* i */
/*106*/ 'J',    /* j */
/*107*/ 'K',    /* k */
/*108*/ 'L',    /* l */
/*109*/ 'M',    /* m */
/*110*/ 'N',    /* n */
/*111*/ 'O',    /* o */
/*112*/ 'P',    /* p */
/*113*/ 'Q',    /* q */
/*114*/ 'R',    /* r */
/*115*/ 'S',    /* s */
/*116*/ 'T',    /* t */
/*117*/ 'U',    /* u */
/*118*/ 'V',    /* v */
/*119*/ 'W',    /* w */
/*120*/ 'X',    /* x */
/*121*/ 'Y',    /* y */
/*122*/ 'Z',    /* z */
/*123*/ '{',    /* { */
/*124*/ '|',    /* | */
/*125*/ '}',    /* } */
/*126*/ '~',    /* ~ */
/*127*/ 127,    /* DEL */
/*128*/ 128,    /* XXX */
/*129*/ 129,    /* XXX */
/*130*/ 130,    /* BPH */
/*131*/ 131,    /* NBH */
/*132*/ 132,    /* IND */
/*133*/ 133,    /* NEL */
/*134*/ 134,    /* SSA */
/*135*/ 135,    /* ESA */
/*136*/ 136,    /* HTS */
/*137*/ 137,    /* HTJ */
/*138*/ 138,    /* VTS */
/*139*/ 139,    /* PLD */
/*140*/ 140,    /* PLU */
/*141*/ 141,    /* RI  */
/*142*/ 142,    /* SS2 */
/*143*/ 143,    /* SS3 */
/*144*/ 144,    /* DCS */
/*145*/ 145,    /* PU1 */
/*146*/ 146,    /* PU2 */
/*147*/ 147,    /* STS */
/*148*/ 148,    /* CCH */
/*149*/ 149,    /* MW  */
/*150*/ 150,    /* SPA */
/*151*/ 151,    /* EPA */
/*152*/ 152,    /* SOS */
/*153*/ 153,    /* XXX */
/*154*/ 154,    /* SCI */
/*155*/ 155,    /* CSI */
/*156*/ 156,    /* ST  */
/*157*/ 157,    /* OSC */
/*158*/ 158,    /* PM  */
/*159*/ 159,    /* APC */
/*160*/ 160,    /* NBSP */
/*161*/ '�',    /* � */
/*162*/ '�',    /* � */
/*163*/ '�',    /* � */
/*164*/ '�',    /* � */ /* Euro sign */
/*165*/ '�',    /* � */
/*166*/ '�',    /* � */ /* S with caron */
/*167*/ '�',    /* � */
/*168*/ '�',    /* � */ /* s with caron */
/*169*/ '�',    /* � */
/*170*/ '�',    /* � */
/*171*/ '�',    /* � */
/*172*/ '�',    /* � */
/*173*/ '�',    /* � */
/*174*/ '�',    /* � */
/*175*/ '�',    /* � */
/*176*/ '�',    /* � */
/*177*/ '�',    /* � */
/*178*/ '�',    /* � */
/*179*/ '�',    /* � */
/*180*/ '�',    /* � */ /* Z with caron */
/*181*/ '�',    /* � */
/*182*/ '�',    /* � */
/*183*/ '�',    /* � */
/*184*/ '�',    /* � */ /* z with caron */
/*185*/ '�',    /* � */
/*186*/ '�',    /* � */
/*187*/ '�',    /* � */
/*188*/ '�',    /* � */ /* capital ligature OE */
/*189*/ '�',    /* � */ /* small ligature OE */
/*190*/ '�',    /* � */ /* Y with diaeresis */
/*191*/ '�',    /* � */
/*192*/ '�',    /* � */
/*193*/ '�',    /* � */
/*194*/ '�',    /* � */
/*195*/ '�',    /* � */
/*196*/ '�',    /* � */
/*197*/ '�',    /* � */
/*198*/ '�',    /* � */
/*199*/ '�',    /* � */
/*200*/ '�',    /* � */
/*201*/ '�',    /* � */
/*202*/ '�',    /* � */
/*203*/ '�',    /* � */
/*204*/ '�',    /* � */
/*205*/ '�',    /* � */
/*206*/ '�',    /* � */
/*207*/ '�',    /* � */
/*208*/ '�',    /* � */
/*209*/ '�',    /* � */
/*210*/ '�',    /* � */
/*211*/ '�',    /* � */
/*212*/ '�',    /* � */
/*213*/ '�',    /* � */
/*214*/ '�',    /* � */
/*215*/ '�',    /* � */
/*216*/ '�',    /* � */
/*217*/ '�',    /* � */
/*218*/ '�',    /* � */
/*219*/ '�',    /* � */
/*220*/ '�',    /* � */
/*221*/ '�',    /* � */
/*222*/ 'T',    /* � */
/*223*/ '�',    /* � */
/*224*/ '�',    /* � */
/*225*/ '�',    /* � */
/*226*/ '�',    /* � */
/*227*/ '�',    /* � */
/*228*/ '�',    /* � */
/*229*/ '�',    /* � */
/*230*/ '�',    /* � */
/*231*/ '�',    /* � */
/*232*/ '�',    /* � */
/*233*/ '�',    /* � */
/*234*/ '�',    /* � */
/*235*/ '�',    /* � */
/*236*/ '�',    /* � */
/*237*/ '�',    /* � */
/*238*/ '�',    /* � */
/*239*/ '�',    /* � */
/*240*/ '�',    /* � */
/*241*/ '�',    /* � */
/*242*/ '�',    /* � */
/*243*/ '�',    /* � */
/*244*/ '�',    /* � */
/*245*/ '�',    /* � */
/*246*/ '�',    /* � */
/*247*/ '�',    /* � */
/*248*/ '�',    /* � */
/*249*/ '�',    /* � */
/*250*/ '�',    /* � */
/*251*/ '�',    /* � */
/*252*/ '�',    /* � */
/*253*/ '�',    /* � */
/*254*/ 'T',    /* � */
/*255*/ '�'     /* � */
};

/*-------------------------------------------------------------------------*/

STATIC LONG ASM LIB_StrnCmp(REG(a6, BASE_OR_IFACE_PARAM),
                            REG(a1, CONST_STRPTR string1),
                            REG(a2, CONST_STRPTR string2),
                            REG(d0, LONG length),
                            REG(d1, ULONG type))
{
    CONST_STRPTR table;
    UBYTE c1;
    UBYTE c2;
    LONG  res;

    UNUSEDBI
    if (!length)
    {
        return 0;
    }
    switch ((int)type)
    {
        case SC_ASCII:
        case SC_COLLATE1:
#if 1
/* TetiSoft: Old behaviour of SC_ASCII which sorts diacritical
 * marks behind all other "normal" characters:
 * a,B,z,�. We use this for compatibility to e.g. libnix,
 * also other applications may assume that '_' follows letters
 * ("uses ASCII ordering").
 */
            if (type == SC_ASCII)
            {
                table = &ToUpperTable[0];
            }
            else
            {
                table = &Collate1Table[0];
            }

            do
            {
                c1 = *string1++;
                c2 = *string2++;
                c1 = table[c1];
                if (c1 > table[c2])
                {
                    return 1;
                }
                if (c1 < table[c2])
                {
                    return -1;
                }
                if (c1 == '\0')
                {
                    return 0;
                }
            } while (--length);
            return 0;
#else
/* TetiSoft: New behaviour of SC_ASCII which sorts diacritical
 * marks behind the "normal" character they're supposed to be
 * nealy equivalent:
 * a,�,B,z
 */
            table = &Collate1Table[0];
            c1 = *string1++;
            c2 = *string2++;
            do
            {
                if (table[c1] > table[c2])
                {
                    return 1;
                }
                if (table[c1] < table[c2])
                {
                    return -1;
                }
                if (c1 == '\0')
                {
                    return 0;
                }
                if (type == SC_ASCII)
                {
                    if (ToUpperTable[c1] > ToUpperTable[c2])
                    {
                        return 1;
                    }
                    if (ToUpperTable[c1] < ToUpperTable[c2])
                    {
                        return -1;
                    }
                }
                if (((c1 == '�') || (c1 == '�')) && !((c2 == '�') || (c2 == '�')) && (length != 1))
                {
                    c1 = 'H';
                    c2 = *string2++;
                    length--;
                }
                else if (!((c1 == '�') || (c1 == '�')) && ((c2 == '�') || (c2 == '�')) && (length != 1))
                {
                    c1 = *string1++;
                    c2 = 'H';
                    length--;
                }
                else
                {
                    c1 = *string1++;
                    c2 = *string2++;
                }
            } while (--length);
            return 0;
#endif

/* TetiSoft: New behaviour of SC_COLLATE2 which is case
 * insensitive in pass 2 but distinguishes diacritical marks
 * as documented: "SC_COLLATE2 would make a second pass over
 * the string comparing diacritical marks instead of actual
 * characters." Case comparison is done in pass 3.
 */
        case SC_COLLATE2:
            table = &ToUpperTable[0];
            res = 0;

            /* Compare case (pass 3) */
            do
            {
                c1 = *string1++;
                c2 = *string2++;
                if ((c1 == '\0') && (c2 == '\0'))
                {
                    return 0;
                }
                if (c1 != c2)
                {
                    if (table[c1] == table[c2])
                    {
                        if (((c1 == '�') || (c1 == '�')) && !((c2 == '�') || (c2 == '�')))
                        {
                            res = 1;
                        }
                        else if (!((c1 == '�') || (c1 == '�')) && ((c2 == '�') || (c2 == '�')))
                        {
                            res = -1;
                        }
                        else if ((c1 == '�') && (c2 == '�'))
                        {
                            /* c1 is uppercase, c2 lowercase */
                            res = -1;
                        }
                        else if ((c1 == '�') && (c2 == '�'))
                        {
                            /* c1 is lowercase, c2 uppercase */
                            res = 1;
                        }
                        /* c1 and c2 can differ only in case */
                        else if (table[c1] == c1)
                        {
                            /* c1 is uppercase, c2 lowercase */
                            res = -1;
                        }
                        else
                        {
                            /* c1 is lowercase, c2 uppercase */
                            res = 1;
                        }
#ifdef LOWERCASE_FIRST
                        res = -res;
#endif
                    }
                    break;
                }
            } while (--length);
            if (length)
            {
                /* Compare diacritical marks (pass 2) */
                for (;;)
                {
                    if (table[c1] > table[c2])
                    {
                        res = 1;
                        break;
                    }
                    if (table[c1] < table[c2])
                    {
                        res = -1;
                        break;
                    }
                    if (c1 == '\0')
                    {
                        break;
                    }
                    if (--length == 0)
                    {
                        break;
                    }
                    if (((c1 == '�') || (c1 == '�')) && !((c2 == '�') || (c2 == '�')) && (length != 1))
                    {
                        c1 = 'H';
                        c2 = *string2++;
                        length--;
                    }
                    else if (!((c1 == '�') || (c1 == '�')) && ((c2 == '�') || (c2 == '�')) && (length != 1))
                    {
                        c1 = *string1++;
                        c2 = 'H';
                        length--;
                    }
                    else
                    {
                        c1 = *string1++;
                        c2 = *string2++;
                    }
                }
            }
            if (res == 0)
            {
                return 0;
            }

            table = &Collate1Table[0];
            for (;;)
            {
                if (table[c1] > table[c2])
                {
                    return 1;
                }
                if (table[c1] < table[c2])
                {
                    return -1;
                }
                if (c1 == '\0')
                {
                    break;
                }
                if (--length == 0)
                {
                    break;
                }
                if (((c1 == '�') || (c1 == '�')) && !((c2 == '�') || (c2 == '�')) && (length != 1))
                {
                    c1 = 'H';
                    c2 = *string2++;
                    length--;
                }
                else if (!((c1 == '�') || (c1 == '�')) && ((c2 == '�') || (c2 == '�')) && (length != 1))
                {
                    c1 = *string1++;
                    c2 = 'H';
                    length--;
                }
                else
                {
                    c1 = *string1++;
                    c2 = *string2++;
                }
            }
            return res;

        default:
            return 0;
    }
}
