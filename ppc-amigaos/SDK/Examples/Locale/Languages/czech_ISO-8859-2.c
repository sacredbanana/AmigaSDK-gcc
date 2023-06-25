/*
 * C language library code by TetiSoft@apg.lahn.de (Detlef Würkner)
 */

/*-------------------------------------------------------------------------*/
/*                         variable part                                   */
/*-------------------------------------------------------------------------*/

/* IANA number for ISO-8859-2, see L:CharSets/character-sets */
#define CODESET 5

#include "czech_ISO-8859-2.language_rev.h"

#define LIBNAME "czech_ISO-8859-2.language"

#define OWN_STRNCMP

/* constants for GetLocaleStr() */
#define GLS_CODE         "ces"        /* ISO-639-2/T 3-letter lowercase language code */

#define GLS_DAY_1        "nedìle"     /* Sunday    */
#define GLS_DAY_2        "pondìlí"    /* Monday    */
#define GLS_DAY_3        "úterý"      /* Tuesday   */
#define GLS_DAY_4        "støeda"     /* Wednesday */
#define GLS_DAY_5        "ètvrtek"    /* Thursday  */
#define GLS_DAY_6        "pátek"      /* Friday    */
#define GLS_DAY_7        "sobota"     /* Saturday  */

#define GLS_ABDAY_1      "Ne"         /* Sun */
#define GLS_ABDAY_2      "Po"         /* Mon */
#define GLS_ABDAY_3      "Út"         /* Tue */
#define GLS_ABDAY_4      "St"         /* Wed */
#define GLS_ABDAY_5      "Èt"         /* Thu */
#define GLS_ABDAY_6      "Pá"         /* Fri */
#define GLS_ABDAY_7      "So"         /* Sat */

#define GLS_MON_1        "leden"      /* January   */
#define GLS_MON_2        "únor"       /* February  */
#define GLS_MON_3        "bøezen"     /* March     */
#define GLS_MON_4        "duben"      /* April     */
#define GLS_MON_5        "kvìten"     /* May       */
#define GLS_MON_6        "èerven"     /* June      */
#define GLS_MON_7        "èervenec"   /* July      */
#define GLS_MON_8        "srpen"      /* August    */
#define GLS_MON_9        "záøí"       /* September */
#define GLS_MON_10       "øíjen"      /* October   */
#define GLS_MON_11       "listopad"   /* November  */
#define GLS_MON_12       "prosinec"   /* December  */

#define GLS_ABMON_1      "led"        /* Jan */
#define GLS_ABMON_2      "úno"        /* Feb */
#define GLS_ABMON_3      "bøe"        /* Mar */
#define GLS_ABMON_4      "dub"        /* Apr */
#define GLS_ABMON_5      "kvì"        /* May */
#define GLS_ABMON_6      "èen"        /* Jun */
#define GLS_ABMON_7      "èec"        /* Jul */
#define GLS_ABMON_8      "srp"        /* Aug */
#define GLS_ABMON_9      "záø"        /* Sep */
#define GLS_ABMON_10     "øíj"        /* Oct */
#define GLS_ABMON_11     "lis"        /* Nov */
#define GLS_ABMON_12     "pro"        /* Dec */

#define GLS_YESSTR       "Ano"        /* affirmative response for yes/no queries */
#define GLS_NOSTR        "Ne"         /* negative response for yes/no queries    */

#define GLS_AM_STR       "dop."       /* AM */
#define GLS_PM_STR       "odp."       /* PM */

#define GLS_SOFTHYPHEN   "-"          /* soft hyphenation */
#define GLS_HARDHYPHEN   "-"          /* hard hyphenation */

#define GLS_OPENQUOTE    "\""         /* start of quoted block */
#define GLS_CLOSEQUOTE   "\""         /* end of quoted block   */

#define GLS_YESTERDAYSTR "vèera"      /* Yesterday */
#define GLS_TODAYSTR     "dnes"       /* Today     */
#define GLS_TOMORROWSTR  "zítra"      /* Tomorrow  */
#define GLS_FUTURESTR    "budoucnost" /* Future    */

#define GLS_LANGNAME     "èe¹tina"    /* native language name */
                                      /* in this language and charset */

#define GLS_ALTDAY_1     GLS_DAY_1    /* no alternate day names */
#define GLS_ALTDAY_2     GLS_DAY_2
#define GLS_ALTDAY_3     GLS_DAY_3
#define GLS_ALTDAY_4     GLS_DAY_4
#define GLS_ALTDAY_5     GLS_DAY_5
#define GLS_ALTDAY_6     GLS_DAY_6
#define GLS_ALTDAY_7     GLS_DAY_7

/* alternate month names */
#define GLS_ALTMON_1     "ledna"      /* January   */
#define GLS_ALTMON_2     "února"      /* February  */
#define GLS_ALTMON_3     "bøezna"     /* March     */
#define GLS_ALTMON_4     "dubna"      /* April     */
#define GLS_ALTMON_5     "kvìtna"     /* May       */
#define GLS_ALTMON_6     "èervna"     /* June      */
#define GLS_ALTMON_7     "èervence"   /* July      */
#define GLS_ALTMON_8     "srpna"      /* August    */
#define GLS_ALTMON_9     "záøí"       /* September */
#define GLS_ALTMON_10    "øíjna"      /* October   */
#define GLS_ALTMON_11    "listopadu"  /* November  */
#define GLS_ALTMON_12    "prosince"   /* December  */

/*-------------------------------------------------------------------------*/
/*                         constant part                                   */
/*-------------------------------------------------------------------------*/

#include "languagestrncmpdriver.c"

/*-------------------------------------------------------------------------*/
/*                         variable part                                   */
/*-------------------------------------------------------------------------*/

/* Special table for czech alphabet
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
    V_C1,
    V_C2,
    V_D,
    V_E,
    V_F,
    V_G,
    V_H,
    V_CH,
    V_I,
    V_J,
    V_K,
    V_L1,
    V_L2,
    V_M,
    V_N,
    V_O,
    V_P,
    V_Q,
    V_R1,
    V_R2,
    V_S1,
    V_S2,
    V_T,
    V_U,
    V_V,
    V_W,
    V_X,
    V_Y,
    V_Z1,
    V_Z2
};

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
/* 67*/ V_C1,       /* C */
/* 68*/ V_D,        /* D */
/* 69*/ V_E,        /* E */
/* 70*/ V_F,        /* F */
/* 71*/ V_G,        /* G */
/* 72*/ V_H,        /* H */
/* 73*/ V_I,        /* I */
/* 74*/ V_J,        /* J */
/* 75*/ V_K,        /* K */
/* 76*/ V_L1,       /* L */
/* 77*/ V_M,        /* M */
/* 78*/ V_N,        /* N */
/* 79*/ V_O,        /* O */
/* 80*/ V_P,        /* P */
/* 81*/ V_Q,        /* Q */
/* 82*/ V_R1,       /* R */
/* 83*/ V_S1,       /* S */
/* 84*/ V_T,        /* T */
/* 85*/ V_U,        /* U */
/* 86*/ V_V,        /* V */
/* 87*/ V_W,        /* W */
/* 88*/ V_X,        /* X */
/* 89*/ V_Y,        /* Y */
/* 90*/ V_Z1,       /* Z */
/* 91*/ V_PUNCT,    /* [ */
/* 92*/ V_PUNCT,    /* \ */
/* 93*/ V_PUNCT,    /* ] */
/* 94*/ V_PUNCT,    /* ^ */
/* 95*/ V_PUNCT,    /* _ */
/* 96*/ V_PUNCT,    /* ` */
/* 97*/ V_A,        /* a */
/* 98*/ V_B,        /* b */
/* 99*/ V_C1,       /* c */
/*100*/ V_D,        /* d */
/*101*/ V_E,        /* e */
/*102*/ V_F,        /* f */
/*103*/ V_G,        /* g */
/*104*/ V_H,        /* h */
/*105*/ V_I,        /* i */
/*106*/ V_J,        /* j */
/*107*/ V_K,        /* k */
/*108*/ V_L1,       /* l */
/*109*/ V_M,        /* m */
/*110*/ V_N,        /* n */
/*111*/ V_O,        /* o */
/*112*/ V_P,        /* p */
/*113*/ V_Q,        /* q */
/*114*/ V_R1,       /* r */
/*115*/ V_S1,       /* s */
/*116*/ V_T,        /* t */
/*117*/ V_U,        /* u */
/*118*/ V_V,        /* v */
/*119*/ V_W,        /* w */
/*120*/ V_X,        /* x */
/*121*/ V_Y,        /* y */
/*122*/ V_Z1,       /* z */
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
/*161*/ V_A,        /* LATIN CAPITAL LETTER A WITH OGONEK */
/*162*/ V_PUNCT,    /* BREVE */
/*163*/ V_L2,       /* LATIN CAPITAL LETTER L WITH STROKE */
/*164*/ V_CURR,     /* ¤ */
/*165*/ V_L1,       /* LATIN CAPITAL LETTER L WITH CARON */
/*166*/ V_S2,       /* LATIN CAPITAL LETTER S WITH ACUTE */
/*167*/ V_PUNCT,    /* § */
/*168*/ V_PUNCT,    /* ¨ */
/*169*/ V_S2,       /* LATIN CAPITAL LETTER S WITH CARON */
/*170*/ V_S2,       /* LATIN CAPITAL LETTER S WITH CEDILLA */
/*171*/ V_T,        /* LATIN CAPITAL LETTER T WITH CARON */
/*172*/ V_Z2,       /* LATIN CAPITAL LETTER Z WITH ACUTE */
/*173*/ V_PUNCT,    /* ­ */
/*174*/ V_Z2,       /* LATIN CAPITAL LETTER Z WITH CARON */
/*175*/ V_Z2,       /* LATIN CAPITAL LETTER Z WITH DOT ABOVE */
/*176*/ V_PUNCT,    /* ° */
/*177*/ V_A,        /* LATIN SMALL LETTER A WITH OGONEK */
/*178*/ V_PUNCT,    /* OGONEK */
/*179*/ V_L2,       /* LATIN SMALL LETTER L WITH STROKE */
/*180*/ V_PUNCT,    /* ´ */
/*181*/ V_L1,       /* LATIN SMALL LETTER L WITH CARON */
/*182*/ V_S2,       /* LATIN SMALL LETTER S WITH ACUTE */
/*183*/ V_PUNCT,    /* CARON */
/*184*/ V_PUNCT,    /* ¸ */
/*185*/ V_S2,       /* LATIN SMALL LETTER S WITH CARON */
/*186*/ V_S2,       /* LATIN SMALL LETTER S WITH CEDILLA */
/*187*/ V_T,        /* LATIN SMALL LETTER T WITH CARON */
/*188*/ V_Z2,       /* LATIN SMALL LETTER Z WITH ACUTE */
/*189*/ V_PUNCT,    /* DOUBLE ACUTE ACCENT */
/*190*/ V_Z2,       /* LATIN SMALL LETTER Z WITH CARON */
/*191*/ V_Z2,       /* LATIN SMALL LETTER Z WITH DOT ABOVE */
/*192*/ V_R1,       /* LATIN CAPITAL LETTER R WITH ACUTE */
/*193*/ V_A,        /* Á */
/*194*/ V_A,        /* Â */
/*195*/ V_A,        /* LATIN CAPITAL LETTER A WITH BREVE */
/*196*/ V_A,        /* Ä */
/*197*/ V_L1,       /* LATIN CAPITAL LETTER L WITH ACUTE */
/*198*/ V_C2,       /* LATIN CAPITAL LETTER C WITH ACUTE */
/*199*/ V_C2,       /* Ç */
/*200*/ V_C2,       /* LATIN CAPITAL LETTER C WITH CARON */
/*201*/ V_E,        /* É */
/*202*/ V_E,        /* LATIN CAPITAL LETTER E WITH OGONEK */
/*203*/ V_E,        /* Ë */
/*204*/ V_E,        /* LATIN CAPITAL LETTER E WITH CARON */
/*205*/ V_I,        /* Í */
/*206*/ V_I,        /* Î */
/*207*/ V_D,        /* LATIN CAPITAL LETTER D WITH CARON */
/*208*/ V_D,        /* LATIN CAPITAL LETTER D WITH STROKE */
/*209*/ V_N,        /* LATIN CAPITAL LETTER N WITH ACUTE */
/*210*/ V_N,        /* LATIN CAPITAL LETTER N WITH CARON */
/*211*/ V_O,        /* Ó */
/*212*/ V_O,        /* Ô */
/*213*/ V_O,        /* LATIN CAPITAL LETTER O WITH DOUBLE ACUTE */
/*214*/ V_O,        /* Ö */
/*215*/ V_PUNCT,    /* × */
/*216*/ V_R2,       /* LATIN CAPITAL LETTER R WITH CARON */
/*217*/ V_U,        /* LATIN CAPITAL LETTER U WITH RING ABOVE */
/*218*/ V_U,        /* Ú */
/*219*/ V_U,        /* LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
/*220*/ V_U,        /* Ü */
/*221*/ V_Y,        /* Ý */
/*222*/ V_T,        /* LATIN CAPITAL LETTER T WITH CEDILLA */
/*223*/ V_S2,       /* ß */
/*224*/ V_R1,       /* LATIN SMALL LETTER R WITH ACUTE */
/*225*/ V_A,        /* á */
/*226*/ V_A,        /* â */
/*227*/ V_A,        /* LATIN SMALL LETTER A WITH BREVE */
/*228*/ V_A,        /* ä */
/*229*/ V_L1,       /* LATIN SMALL LETTER L WITH ACUTE */
/*230*/ V_C2,       /* LATIN SMALL LETTER C WITH ACUTE */
/*231*/ V_C2,       /* ç */
/*232*/ V_C2,       /* LATIN SMALL LETTER C WITH CARON */
/*233*/ V_E,        /* é */
/*234*/ V_E,        /* LATIN SMALL LETTER E WITH OGONEK */
/*235*/ V_E,        /* ë */
/*236*/ V_E,        /* LATIN SMALL LETTER E WITH CARON */
/*237*/ V_I,        /* í */
/*238*/ V_I,        /* î */
/*239*/ V_D,        /* LATIN SMALL LETTER D WITH CARON */
/*240*/ V_D,        /* LATIN SMALL LETTER D WITH STROKE */
/*241*/ V_N,        /* LATIN SMALL LETTER N WITH ACUTE */
/*242*/ V_N,        /* LATIN SMALL LETTER N WITH CARON */
/*243*/ V_O,        /* ó */
/*244*/ V_O,        /* ô */
/*245*/ V_O,        /* LATIN SMALL LETTER O WITH DOUBLE ACUTE */
/*246*/ V_O,        /* ö */
/*247*/ V_PUNCT,    /* ÷ */
/*248*/ V_R2,       /* LATIN SMALL LETTER R WITH CARON */
/*249*/ V_U,        /* LATIN SMALL LETTER U WITH RING ABOVE */
/*250*/ V_U,        /* ú */
/*251*/ V_U,        /* LATIN SMALL LETTER U WITH DOUBLE ACUTE */
/*252*/ V_U,        /* ü */
/*253*/ V_Y,        /* ý */
/*254*/ V_T,        /* LATIN SMALL LETTER T WITH CEDILLA */
/*255*/ V_PUNCT     /* DOT ABOVE */
};

/*-------------------------------------------------------------------------*/

/* standard ISO-8859-2 table */

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
/* 92*/ '\\',    /* \ */
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
/*161*/ 161,    /* LATIN CAPITAL LETTER A WITH OGONEK */
/*162*/ 162,    /* BREVE */
/*163*/ 163,    /* LATIN CAPITAL LETTER L WITH STROKE */
/*164*/ 164,    /* ¤ */
/*165*/ 165,    /* LATIN CAPITAL LETTER L WITH CARON */
/*166*/ 166,    /* LATIN CAPITAL LETTER S WITH ACUTE */
/*167*/ 167,    /* § */
/*168*/ 168,    /* ¨ */
/*169*/ 169,    /* LATIN CAPITAL LETTER S WITH CARON */
/*170*/ 170,    /* LATIN CAPITAL LETTER S WITH CEDILLA */
/*171*/ 171,    /* LATIN CAPITAL LETTER T WITH CARON */
/*172*/ 172,    /* LATIN CAPITAL LETTER Z WITH ACUTE */
/*173*/ 173,    /* ­ */
/*174*/ 174,    /* LATIN CAPITAL LETTER Z WITH CARON */
/*175*/ 175,    /* LATIN CAPITAL LETTER Z WITH DOT ABOVE */
/*176*/ 176,    /* ° */
/*177*/ 161,    /* LATIN SMALL LETTER A WITH OGONEK */
/*178*/ 178,    /* OGONEK */
/*179*/ 163,    /* LATIN SMALL LETTER L WITH STROKE */
/*180*/ 180,    /* ´ */
/*181*/ 165,    /* LATIN SMALL LETTER L WITH CARON */
/*182*/ 166,    /* LATIN SMALL LETTER S WITH ACUTE */
/*183*/ 183,    /* CARON */
/*184*/ 184,    /* ¸ */
/*185*/ 169,    /* LATIN SMALL LETTER S WITH CARON */
/*186*/ 170,    /* LATIN SMALL LETTER S WITH CEDILLA */
/*187*/ 171,    /* LATIN SMALL LETTER T WITH CARON */
/*188*/ 172,    /* LATIN SMALL LETTER Z WITH ACUTE */
/*189*/ 189,    /* DOUBLE ACUTE ACCENT */
/*190*/ 174,    /* LATIN SMALL LETTER Z WITH CARON */
/*191*/ 175,    /* LATIN SMALL LETTER Z WITH DOT ABOVE */
/*192*/ 192,    /* LATIN CAPITAL LETTER R WITH ACUTE */
/*193*/ 193,    /* Á */
/*194*/ 194,    /* Â */
/*195*/ 195,    /* LATIN CAPITAL LETTER A WITH BREVE */
/*196*/ 196,    /* Ä */
/*197*/ 197,    /* LATIN CAPITAL LETTER L WITH ACUTE */
/*198*/ 198,    /* LATIN CAPITAL LETTER C WITH ACUTE */
/*199*/ 199,    /* Ç */
/*200*/ 200,    /* LATIN CAPITAL LETTER C WITH CARON */
/*201*/ 201,    /* É */
/*202*/ 202,    /* LATIN CAPITAL LETTER E WITH OGONEK */
/*203*/ 203,    /* Ë */
/*204*/ 204,    /* LATIN CAPITAL LETTER E WITH CARON */
/*205*/ 205,    /* Í */
/*206*/ 206,    /* Î */
/*207*/ 207,    /* LATIN CAPITAL LETTER D WITH CARON */
/*208*/ 208,    /* LATIN CAPITAL LETTER D WITH STROKE */
/*209*/ 209,    /* LATIN CAPITAL LETTER N WITH ACUTE */
/*210*/ 210,    /* LATIN CAPITAL LETTER N WITH CARON */
/*211*/ 211,    /* Ó */
/*212*/ 212,    /* Ô */
/*213*/ 213,    /* LATIN CAPITAL LETTER O WITH DOUBLE ACUTE */
/*214*/ 214,    /* Ö */
/*215*/ 215,    /* × */
/*216*/ 216,    /* LATIN CAPITAL LETTER R WITH CARON */
/*217*/ 217,    /* LATIN CAPITAL LETTER U WITH RING ABOVE */
/*218*/ 218,    /* Ú */
/*219*/ 219,    /* LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
/*220*/ 220,    /* Ü */
/*221*/ 221,    /* Ý */
/*222*/ 222,    /* LATIN CAPITAL LETTER T WITH CEDILLA */
/*223*/ 223,    /* ß */
/*224*/ 192,    /* LATIN SMALL LETTER R WITH ACUTE */
/*225*/ 193,    /* á */
/*226*/ 194,    /* â */
/*227*/ 195,    /* LATIN SMALL LETTER A WITH BREVE */
/*228*/ 196,    /* ä */
/*229*/ 197,    /* LATIN SMALL LETTER L WITH ACUTE */
/*230*/ 198,    /* LATIN SMALL LETTER C WITH ACUTE */
/*231*/ 199,    /* ç */
/*232*/ 200,    /* LATIN SMALL LETTER C WITH CARON */
/*233*/ 201,    /* é */
/*234*/ 202,    /* LATIN SMALL LETTER E WITH OGONEK */
/*235*/ 203,    /* ë */
/*236*/ 204,    /* LATIN SMALL LETTER E WITH CARON */
/*237*/ 205,    /* í */
/*238*/ 206,    /* î */
/*239*/ 207,    /* LATIN SMALL LETTER D WITH CARON */
/*240*/ 208,    /* LATIN SMALL LETTER D WITH STROKE */
/*241*/ 209,    /* LATIN SMALL LETTER N WITH ACUTE */
/*242*/ 210,    /* LATIN SMALL LETTER N WITH CARON */
/*243*/ 211,    /* ó */
/*244*/ 212,    /* ô */
/*245*/ 213,    /* LATIN SMALL LETTER O WITH DOUBLE ACUTE */
/*246*/ 214,    /* ö */
/*247*/ 247,    /* ÷ */
/*248*/ 216,    /* LATIN SMALL LETTER R WITH CARON */
/*249*/ 217,    /* LATIN SMALL LETTER U WITH RING ABOVE */
/*250*/ 218,    /* ú */
/*251*/ 219,    /* LATIN SMALL LETTER U WITH DOUBLE ACUTE */
/*252*/ 220,    /* ü */
/*253*/ 221,    /* ý */
/*254*/ 222,    /* LATIN SMALL LETTER T WITH CEDILLA */
/*255*/ 255     /* DOT ABOVE */
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
    UBYTE Col1;
    UBYTE Col2;
#if 0
    UBYTE Up1;
    UBYTE Up2;
#endif
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
 * a,B,z,ä. We use this for compatibility to e.g. libnix,
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
 * a,ä,B,z
 */
            table = &Collate1Table[0];
            do
            {
                c1 = *string1++;
                c2 = *string2++;
                Col1 = table[c1];
                Col2 = table[c2];
                Up1  = ToUpperTable[c1];
                Up2  = ToUpperTable[c2];
                if ((Col1 == V_C1) && (length != 1) && (table[*((UBYTE *)string1)] == V_H))
                {
                    string1++;
                    Col1 = V_CH;
                    Up1  = 'H';
                    if ((Col2 == V_C1) && (table[*((UBYTE *)string2)] == V_H))
                    {
                        string2++;
                        Col2 = V_CH;
                        Up2  = 'H';
                    }
                    length--;
                }
                if ((Col2 == V_C1) && (length != 1) && (table[*((UBYTE *)string2)] == V_H))
                {
                    string2++;
                    length--;
                    Col2 = V_CH;
                    Up2  = 'H';
                }
                if (Col1 > Col2)
                {
                    return 1;
                }
                if (Col1 < Col2)
                {
                    return -1;
                }
                if (c1 == '\0')
                {
                    return 0;
                }
                if (type == SC_ASCII)
                {
                    if (Up1 > Up2)
                    {
                        return 1;
                    }
                    if (Up1 < Up2)
                    {
                        return -1;
                    }
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
                        /* c1 and c2 can differ only in case.
                         * In czech lowercase precedes uppercase
                         * if no other differences are there
                         */
                        if (ToUpperTable[c1] == c1)
                        {
                            /* c1 is uppercase, c2 lowercase */
                            res = 1;
                        }
                        else
                        {
                            /* c1 is lowercase, c2 uppercase */
                            res = -1;
                        }
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
                    c1 = *string1++;
                    c2 = *string2++;
                }
            }
            if (res == 0)
            {
                return 0;
            }

            table = &Collate1Table[0];
            for (;;)
            {
                Col1 = table[c1];
                Col2 = table[c2];
                if ((Col1 == V_C1) && (length != 1) && (table[*((UBYTE *)string1)] == V_H))
                {
                    string1++;
                    Col1 = V_CH;
                    if ((Col2 == V_C1) && (table[*((UBYTE *)string2)] == V_H))
                    {
                        string2++;
                        Col2 = V_CH;
                    }
                    length--;
                }
                if ((Col2 == V_C1) && (length != 1) && (table[*((UBYTE *)string2)] == V_H))
                {
                    string2++;
                    length--;
                    Col2 = V_CH;
                }
                if (Col1 > Col2)
                {
                    return 1;
                }
                if (Col1 < Col2)
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
                c1 = *string1++;
                c2 = *string2++;
            }
            return res;

        default:
            return 0;
    }
}
