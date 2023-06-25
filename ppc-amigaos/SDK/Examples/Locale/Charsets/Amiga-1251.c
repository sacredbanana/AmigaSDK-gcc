/*
 * C charset library code by TetiSoft@apg.lahn.de (Detlef Würkner)
 *
 * Modifications by Michael_Malyshev@mail.ru (Michael Malyshev)
 */

#include <exec/types.h>

#include "Amiga-1251.charset_rev.h"

#define LIBNAME "Amiga-1251.charset"


/*-------------------------------------------------------------------------*/
/*                         constant part                                   */
/*-------------------------------------------------------------------------*/

#include "charsetdriver.c"

/*-------------------------------------------------------------------------*/
/*                         variable part                                   */
/*-------------------------------------------------------------------------*/

/* Used by StrConvert() */

STATIC CONST TEXT StrConvertTable[256] =
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
/* 39*/ '\'',   /* ' */
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
/*160*/ ' ',    /* NBSP */
/*161*/ '!',    /* ¡ */
/*162*/ '$',    /* ¢ */
/*163*/ '$',    /* £ */
/*164*/ '$',    /* ¤ */ /* Euro sign */
/*165*/ '$',    /* ¥ */
/*166*/ '|',    /* ¦ */
/*167*/ 167,    /* § */
/*168*/ 168,    /* CYRILLIC CAPITAL LETTER IO */
/*169*/ 169,    /* © */
/*170*/ 170,    /* ª */ /* Numero sign */
/*171*/ '"',    /* « */
/*172*/ 172,    /* ¬ */
/*173*/ '-',    /* ­ */
/*174*/ 174,    /* ® */
/*175*/ 175,    /* ¯ */
/*176*/ 176,    /* ° */
/*177*/ 177,    /* ± */
/*178*/ '2',    /* ² */
/*179*/ '3',    /* ³ */
/*180*/ '\'',   /* ´ */
/*181*/ 181,    /* µ */
/*182*/ 182,    /* ¶ */
/*183*/ 183,    /* · */
/*184*/ 168,    /* CYRILLIC SMALL LETTER IO */
/*185*/ '1',    /* ¹ */
/*186*/ 'O',    /* º */
/*187*/ '"',    /* » */
/*188*/ 188,    /* ¼ */
/*189*/ 189,    /* ½ */
/*190*/ 190,    /* ¾ */
/*191*/ '?',    /* ¿ */
/*192*/ 192,    /* CYRILLIC CAPITAL LETTER A */
/*193*/ 193,    /* CYRILLIC CAPITAL LETTER BE */
/*194*/ 194,    /* CYRILLIC CAPITAL LETTER VE */
/*195*/ 195,    /* CYRILLIC CAPITAL LETTER GHE */
/*196*/ 196,    /* CYRILLIC CAPITAL LETTER DE */
/*197*/ 197,    /* CYRILLIC CAPITAL LETTER IE */
/*198*/ 198,    /* CYRILLIC CAPITAL LETTER ZHE */
/*199*/ 199,    /* CYRILLIC CAPITAL LETTER ZE */
/*200*/ 200,    /* CYRILLIC CAPITAL LETTER I */
/*201*/ 201,    /* CYRILLIC CAPITAL LETTER SHORT I */
/*202*/ 202,    /* CYRILLIC CAPITAL LETTER KA */
/*203*/ 203,    /* CYRILLIC CAPITAL LETTER EL */
/*204*/ 204,    /* CYRILLIC CAPITAL LETTER EM */
/*205*/ 205,    /* CYRILLIC CAPITAL LETTER EN */
/*206*/ 206,    /* CYRILLIC CAPITAL LETTER O */
/*207*/ 207,    /* CYRILLIC CAPITAL LETTER PE */
/*208*/ 208,    /* CYRILLIC CAPITAL LETTER ER */
/*209*/ 209,    /* CYRILLIC CAPITAL LETTER ES */
/*210*/ 210,    /* CYRILLIC CAPITAL LETTER TE */
/*211*/ 211,    /* CYRILLIC CAPITAL LETTER U */
/*212*/ 212,    /* CYRILLIC CAPITAL LETTER EF */
/*213*/ 213,    /* CYRILLIC CAPITAL LETTER HA */
/*214*/ 214,    /* CYRILLIC CAPITAL LETTER TSE */
/*215*/ 215,    /* CYRILLIC CAPITAL LETTER CHE */
/*216*/ 216,    /* CYRILLIC CAPITAL LETTER SHA */
/*217*/ 217,    /* CYRILLIC CAPITAL LETTER SHCHA */
/*218*/ 218,    /* CYRILLIC CAPITAL LETTER HARD SIGN */
/*219*/ 219,    /* CYRILLIC CAPITAL LETTER YERU */
/*220*/ 220,    /* CYRILLIC CAPITAL LETTER SOFT SIGN */
/*221*/ 221,    /* CYRILLIC CAPITAL LETTER E */
/*222*/ 222,    /* CYRILLIC CAPITAL LETTER YU */
/*223*/ 223,    /* CYRILLIC CAPITAL LETTER YA */
/*224*/ 192,    /* CYRILLIC SMALL LETTER A */
/*225*/ 193,    /* CYRILLIC SMALL LETTER BE */
/*226*/ 194,    /* CYRILLIC SMALL LETTER VE */
/*227*/ 195,    /* CYRILLIC SMALL LETTER GHE */
/*228*/ 196,    /* CYRILLIC SMALL LETTER DE */
/*229*/ 197,    /* CYRILLIC SMALL LETTER IE */
/*230*/ 198,    /* CYRILLIC SMALL LETTER ZHE */
/*231*/ 199,    /* CYRILLIC SMALL LETTER ZE */
/*232*/ 200,    /* CYRILLIC SMALL LETTER I */
/*233*/ 201,    /* CYRILLIC SMALL LETTER SHORT I */
/*234*/ 202,    /* CYRILLIC SMALL LETTER KA */
/*235*/ 203,    /* CYRILLIC SMALL LETTER EL */
/*236*/ 204,    /* CYRILLIC SMALL LETTER EM */
/*237*/ 205,    /* CYRILLIC SMALL LETTER EN */
/*238*/ 206,    /* CYRILLIC SMALL LETTER O */
/*239*/ 207,    /* CYRILLIC SMALL LETTER PE */
/*240*/ 208,    /* CYRILLIC SMALL LETTER ER */
/*241*/ 209,    /* CYRILLIC SMALL LETTER ES */
/*242*/ 210,    /* CYRILLIC SMALL LETTER TE */
/*243*/ 211,    /* CYRILLIC SMALL LETTER U */
/*244*/ 212,    /* CYRILLIC SMALL LETTER EF */
/*245*/ 213,    /* CYRILLIC SMALL LETTER HA */
/*246*/ 214,    /* CYRILLIC SMALL LETTER TSE */
/*247*/ 215,    /* CYRILLIC SMALL LETTER CHE */
/*248*/ 216,    /* CYRILLIC SMALL LETTER SHA */
/*249*/ 217,    /* CYRILLIC SMALL LETTER SHCHA */
/*250*/ 218,    /* CYRILLIC SMALL LETTER HARD SIGN */
/*251*/ 219,    /* CYRILLIC SMALL LETTER YERU */
/*252*/ 220,    /* CYRILLIC SMALL LETTER SOFT SIGN */
/*253*/ 221,    /* CYRILLIC SMALL LETTER E */
/*254*/ 222,    /* CYRILLIC SMALL LETTER YU */
/*255*/ 223     /* CYRILLIC SMALL LETTER YA */
};

/*-------------------------------------------------------------------------*/

/* Used by StrnCmp()
 * We use this sort order: control chars, white space, punctuation,
 * quotation marks, currency symbols, digits, latin letters,
 * cyrillic letters.
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
    V_MU,
    V__A,
    V_BE,
    V_VE,
    V_GHE,
    V_DE,
    V_IE,
    V_IO, /* cyrillic letter out of order in the charset */
    V_ZHE,
    V_ZE,
    V__I,
    V_ISHORT,
    V_KA,
    V_EL,
    V_EM,
    V_EN,
    V__O,
    V_PE,
    V_ER,
    V_ES,
    V_TE,
    V__U,
    V_EF,
    V_HA,
    V_TSE,
    V_CHE,
    V_SHA,
    V_SHCHA,
    V_HARDSIGN,
    V_YERU,
    V_SOFTSIGN,
    V__E,
    V_YU,
    V_YA
};

/* Amiga-1251 sorting table */

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
/*161*/ V_PUNCT,    /* ¡ */
/*162*/ V_CURR,     /* ¢ */
/*163*/ V_CURR,     /* £ */
/*164*/ V_CURR,     /* ¤ */ /* Euro sign */
/*165*/ V_CURR,     /* ¥ */
/*166*/ V_PUNCT,    /* ¦ */
/*167*/ V_PUNCT,    /* § */
/*168*/ V_IO,       /* CYRILLIC CAPITAL LETTER IO */
/*169*/ V_PUNCT,    /* © */
/*170*/ V_PUNCT,    /* ª */ /* Numero sign */
/*171*/ V_QUOTE,    /* « */
/*172*/ V_PUNCT,    /* ¬ */
/*173*/ V_PUNCT,    /* ­ */
/*174*/ V_PUNCT,    /* ® */
/*175*/ V_PUNCT,    /* ¯ */
/*176*/ V_PUNCT,    /* ° */
/*177*/ V_PUNCT,    /* ± */
/*178*/ V_DIGIT2,   /* ² */
/*179*/ V_DIGIT3,   /* ³ */
/*180*/ V_PUNCT,    /* ´ */
/*181*/ V_MU,       /* µ */
/*182*/ V_PUNCT,    /* ¶ */
/*183*/ V_PUNCT,    /* · */
/*184*/ V_IO,       /* CYRILLIC SMALL LETTER IO */
/*185*/ V_DIGIT1,   /* ¹ */
/*186*/ V_O,        /* º */
/*187*/ V_QUOTE,    /* » */
/*188*/ V_PUNCT,    /* ¼ */
/*189*/ V_PUNCT,    /* ½ */
/*190*/ V_PUNCT,    /* ¾ */
/*191*/ V_PUNCT,    /* ¿ */
/*192*/ V__A,       /* CYRILLIC CAPITAL LETTER A */
/*193*/ V_BE,       /* CYRILLIC CAPITAL LETTER BE */
/*194*/ V_VE,       /* CYRILLIC CAPITAL LETTER VE */
/*195*/ V_GHE,      /* CYRILLIC CAPITAL LETTER GHE */
/*196*/ V_DE,       /* CYRILLIC CAPITAL LETTER DE */
/*197*/ V_IE,       /* CYRILLIC CAPITAL LETTER IE */
/*198*/ V_ZHE,      /* CYRILLIC CAPITAL LETTER ZHE */
/*199*/ V_ZE,       /* CYRILLIC CAPITAL LETTER ZE */
/*200*/ V__I,       /* CYRILLIC CAPITAL LETTER I */
/*201*/ V_ISHORT,   /* CYRILLIC CAPITAL LETTER SHORT I */
/*202*/ V_KA,       /* CYRILLIC CAPITAL LETTER KA */
/*203*/ V_EL,       /* CYRILLIC CAPITAL LETTER EL */
/*204*/ V_EM,       /* CYRILLIC CAPITAL LETTER EM */
/*205*/ V_EN,       /* CYRILLIC CAPITAL LETTER EN */
/*206*/ V__O,       /* CYRILLIC CAPITAL LETTER O */
/*207*/ V_PE,       /* CYRILLIC CAPITAL LETTER PE */
/*208*/ V_ER,       /* CYRILLIC CAPITAL LETTER ER */
/*209*/ V_ES,       /* CYRILLIC CAPITAL LETTER ES */
/*210*/ V_TE,       /* CYRILLIC CAPITAL LETTER TE */
/*211*/ V__U,       /* CYRILLIC CAPITAL LETTER U */
/*212*/ V_EF,       /* CYRILLIC CAPITAL LETTER EF */
/*213*/ V_HA,       /* CYRILLIC CAPITAL LETTER HA */
/*214*/ V_TSE,      /* CYRILLIC CAPITAL LETTER TSE */
/*215*/ V_CHE,      /* CYRILLIC CAPITAL LETTER CHE */
/*216*/ V_SHA,      /* CYRILLIC CAPITAL LETTER SHA */
/*217*/ V_SHCHA,    /* CYRILLIC CAPITAL LETTER SHCHA */
/*218*/ V_HARDSIGN, /* CYRILLIC CAPITAL LETTER HARD SIGN */
/*219*/ V_YERU,     /* CYRILLIC CAPITAL LETTER YERU */
/*220*/ V_SOFTSIGN, /* CYRILLIC CAPITAL LETTER SOFT SIGN */
/*221*/ V__E,       /* CYRILLIC CAPITAL LETTER E */
/*222*/ V_YU,       /* CYRILLIC CAPITAL LETTER YU */
/*223*/ V_YA,       /* CYRILLIC CAPITAL LETTER YA */
/*224*/ V__A,       /* CYRILLIC SMALL LETTER A */
/*225*/ V_BE,       /* CYRILLIC SMALL LETTER BE */
/*226*/ V_VE,       /* CYRILLIC SMALL LETTER VE */
/*227*/ V_GHE,      /* CYRILLIC SMALL LETTER GHE */
/*228*/ V_DE,       /* CYRILLIC SMALL LETTER DE */
/*229*/ V_IE,       /* CYRILLIC SMALL LETTER IE */
/*230*/ V_ZHE,      /* CYRILLIC SMALL LETTER ZHE */
/*231*/ V_ZE,       /* CYRILLIC SMALL LETTER ZE */
/*232*/ V__I,       /* CYRILLIC SMALL LETTER I */
/*233*/ V_ISHORT,   /* CYRILLIC SMALL LETTER SHORT I */
/*234*/ V_KA,       /* CYRILLIC SMALL LETTER KA */
/*235*/ V_EL,       /* CYRILLIC SMALL LETTER EL */
/*236*/ V_EM,       /* CYRILLIC SMALL LETTER EM */
/*237*/ V_EN,       /* CYRILLIC SMALL LETTER EN */
/*238*/ V__O,       /* CYRILLIC SMALL LETTER O */
/*239*/ V_PE,       /* CYRILLIC SMALL LETTER PE */
/*240*/ V_ER,       /* CYRILLIC SMALL LETTER ER */
/*241*/ V_ES,       /* CYRILLIC SMALL LETTER ES */
/*242*/ V_TE,       /* CYRILLIC SMALL LETTER TE */
/*243*/ V__U,       /* CYRILLIC SMALL LETTER U */
/*244*/ V_EF,       /* CYRILLIC SMALL LETTER EF */
/*245*/ V_HA,       /* CYRILLIC SMALL LETTER HA */
/*246*/ V_TSE,      /* CYRILLIC SMALL LETTER TSE */
/*247*/ V_CHE,      /* CYRILLIC SMALL LETTER CHE */
/*248*/ V_SHA,      /* CYRILLIC SMALL LETTER SHA */
/*249*/ V_SHCHA,    /* CYRILLIC SMALL LETTER SHCHA */
/*250*/ V_HARDSIGN, /* CYRILLIC SMALL LETTER HARD SIGN */
/*251*/ V_YERU,     /* CYRILLIC SMALL LETTER YERU */
/*252*/ V_SOFTSIGN, /* CYRILLIC SMALL LETTER SOFT SIGN */
/*253*/ V__E,       /* CYRILLIC SMALL LETTER E */
/*254*/ V_YU,       /* CYRILLIC SMALL LETTER YU */
/*255*/ V_YA        /* CYRILLIC SMALL LETTER YA */
};

/*-------------------------------------------------------------------------*/

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
/* 39*/ '\'',   /* ' */
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
/*161*/ 161,    /* ¡ */
/*162*/ 162,    /* ¢ */
/*163*/ 163,    /* £ */
/*164*/ 164,    /* ¤ */ /* Euro sign */
/*165*/ 165,    /* ¥ */
/*166*/ 166,    /* ¦ */
/*167*/ 167,    /* § */
/*168*/ 168,    /* CYRILLIC CAPITAL LETTER IO */
/*169*/ 169,    /* © */
/*170*/ 170,    /* ª */ /* Numero sign */
/*171*/ 171,    /* « */
/*172*/ 172,    /* ¬ */
/*173*/ 173,    /* ­ */
/*174*/ 174,    /* ® */
/*175*/ 175,    /* ¯ */
/*176*/ 176,    /* ° */
/*177*/ 177,    /* ± */
/*178*/ 178,    /* ² */
/*179*/ 179,    /* ³ */
/*180*/ 180,    /* ´ */
/*181*/ 181,    /* µ */
/*182*/ 182,    /* ¶ */
/*183*/ 183,    /* · */
/*184*/ 168,    /* CYRILLIC SMALL LETTER IO */
/*185*/ 185,    /* ¹ */
/*186*/ 186,    /* º */
/*187*/ 187,    /* » */
/*188*/ 188,    /* ¼ */
/*189*/ 189,    /* ½ */
/*190*/ 190,    /* ¾ */
/*191*/ 191,    /* ¿ */
/*192*/ 192,    /* CYRILLIC CAPITAL LETTER A */
/*193*/ 193,    /* CYRILLIC CAPITAL LETTER BE */
/*194*/ 194,    /* CYRILLIC CAPITAL LETTER VE */
/*195*/ 195,    /* CYRILLIC CAPITAL LETTER GHE */
/*196*/ 196,    /* CYRILLIC CAPITAL LETTER DE */
/*197*/ 197,    /* CYRILLIC CAPITAL LETTER IE */
/*198*/ 198,    /* CYRILLIC CAPITAL LETTER ZHE */
/*199*/ 199,    /* CYRILLIC CAPITAL LETTER ZE */
/*200*/ 200,    /* CYRILLIC CAPITAL LETTER I */
/*201*/ 201,    /* CYRILLIC CAPITAL LETTER SHORT I */
/*202*/ 202,    /* CYRILLIC CAPITAL LETTER KA */
/*203*/ 203,    /* CYRILLIC CAPITAL LETTER EL */
/*204*/ 204,    /* CYRILLIC CAPITAL LETTER EM */
/*205*/ 205,    /* CYRILLIC CAPITAL LETTER EN */
/*206*/ 206,    /* CYRILLIC CAPITAL LETTER O */
/*207*/ 207,    /* CYRILLIC CAPITAL LETTER PE */
/*208*/ 208,    /* CYRILLIC CAPITAL LETTER ER */
/*209*/ 209,    /* CYRILLIC CAPITAL LETTER ES */
/*210*/ 210,    /* CYRILLIC CAPITAL LETTER TE */
/*211*/ 211,    /* CYRILLIC CAPITAL LETTER U */
/*212*/ 212,    /* CYRILLIC CAPITAL LETTER EF */
/*213*/ 213,    /* CYRILLIC CAPITAL LETTER HA */
/*214*/ 214,    /* CYRILLIC CAPITAL LETTER TSE */
/*215*/ 215,    /* CYRILLIC CAPITAL LETTER CHE */
/*216*/ 216,    /* CYRILLIC CAPITAL LETTER SHA */
/*217*/ 217,    /* CYRILLIC CAPITAL LETTER SHCHA */
/*218*/ 218,    /* CYRILLIC CAPITAL LETTER HARD SIGN */
/*219*/ 219,    /* CYRILLIC CAPITAL LETTER YERU */
/*220*/ 220,    /* CYRILLIC CAPITAL LETTER SOFT SIGN */
/*221*/ 221,    /* CYRILLIC CAPITAL LETTER E */
/*222*/ 222,    /* CYRILLIC CAPITAL LETTER YU */
/*223*/ 223,    /* CYRILLIC CAPITAL LETTER YA */
/*224*/ 192,    /* CYRILLIC SMALL LETTER A */
/*225*/ 193,    /* CYRILLIC SMALL LETTER BE */
/*226*/ 194,    /* CYRILLIC SMALL LETTER VE */
/*227*/ 195,    /* CYRILLIC SMALL LETTER GHE */
/*228*/ 196,    /* CYRILLIC SMALL LETTER DE */
/*229*/ 197,    /* CYRILLIC SMALL LETTER IE */
/*230*/ 198,    /* CYRILLIC SMALL LETTER ZHE */
/*231*/ 199,    /* CYRILLIC SMALL LETTER ZE */
/*232*/ 200,    /* CYRILLIC SMALL LETTER I */
/*233*/ 201,    /* CYRILLIC SMALL LETTER SHORT I */
/*234*/ 202,    /* CYRILLIC SMALL LETTER KA */
/*235*/ 203,    /* CYRILLIC SMALL LETTER EL */
/*236*/ 204,    /* CYRILLIC SMALL LETTER EM */
/*237*/ 205,    /* CYRILLIC SMALL LETTER EN */
/*238*/ 206,    /* CYRILLIC SMALL LETTER O */
/*239*/ 207,    /* CYRILLIC SMALL LETTER PE */
/*240*/ 208,    /* CYRILLIC SMALL LETTER ER */
/*241*/ 209,    /* CYRILLIC SMALL LETTER ES */
/*242*/ 210,    /* CYRILLIC SMALL LETTER TE */
/*243*/ 211,    /* CYRILLIC SMALL LETTER U */
/*244*/ 212,    /* CYRILLIC SMALL LETTER EF */
/*245*/ 213,    /* CYRILLIC SMALL LETTER HA */
/*246*/ 214,    /* CYRILLIC SMALL LETTER TSE */
/*247*/ 215,    /* CYRILLIC SMALL LETTER CHE */
/*248*/ 216,    /* CYRILLIC SMALL LETTER SHA */
/*249*/ 217,    /* CYRILLIC SMALL LETTER SHCHA */
/*250*/ 218,    /* CYRILLIC SMALL LETTER HARD SIGN */
/*251*/ 219,    /* CYRILLIC SMALL LETTER YERU */
/*252*/ 220,    /* CYRILLIC SMALL LETTER SOFT SIGN */
/*253*/ 221,    /* CYRILLIC SMALL LETTER E */
/*254*/ 222,    /* CYRILLIC SMALL LETTER YU */
/*255*/ 223     /* CYRILLIC SMALL LETTER YA */
};

/*-------------------------------------------------------------------------*/

STATIC CONST TEXT ToLowerTable[256] =
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
/* 39*/ '\'',   /* ' */
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
/* 65*/ 'a',    /* A */
/* 66*/ 'b',    /* B */
/* 67*/ 'c',    /* C */
/* 68*/ 'd',    /* D */
/* 69*/ 'e',    /* E */
/* 70*/ 'f',    /* F */
/* 71*/ 'g',    /* G */
/* 72*/ 'h',    /* H */
/* 73*/ 'i',    /* I */
/* 74*/ 'j',    /* J */
/* 75*/ 'k',    /* K */
/* 76*/ 'l',    /* L */
/* 77*/ 'm',    /* M */
/* 78*/ 'n',    /* N */
/* 79*/ 'o',    /* O */
/* 80*/ 'p',    /* P */
/* 81*/ 'q',    /* Q */
/* 82*/ 'r',    /* R */
/* 83*/ 's',    /* S */
/* 84*/ 't',    /* T */
/* 85*/ 'u',    /* U */
/* 86*/ 'v',    /* V */
/* 87*/ 'w',    /* W */
/* 88*/ 'x',    /* X */
/* 89*/ 'y',    /* Y */
/* 90*/ 'z',    /* Z */
/* 91*/ '[',    /* [ */
/* 92*/ '\\',   /* \ */
/* 93*/ ']',    /* ] */
/* 94*/ '^',    /* ^ */
/* 95*/ '_',    /* _ */
/* 96*/ '`',    /* ` */
/* 97*/ 'a',    /* a */
/* 98*/ 'b',    /* b */
/* 99*/ 'c',    /* c */
/*100*/ 'd',    /* d */
/*101*/ 'e',    /* e */
/*102*/ 'f',    /* f */
/*103*/ 'g',    /* g */
/*104*/ 'h',    /* h */
/*105*/ 'i',    /* i */
/*106*/ 'j',    /* j */
/*107*/ 'k',    /* k */
/*108*/ 'l',    /* l */
/*109*/ 'm',    /* m */
/*110*/ 'n',    /* n */
/*111*/ 'o',    /* o */
/*112*/ 'p',    /* p */
/*113*/ 'q',    /* q */
/*114*/ 'r',    /* r */
/*115*/ 's',    /* s */
/*116*/ 't',    /* t */
/*117*/ 'u',    /* u */
/*118*/ 'v',    /* v */
/*119*/ 'w',    /* w */
/*120*/ 'x',    /* x */
/*121*/ 'y',    /* y */
/*122*/ 'z',    /* z */
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
/*161*/ 161,    /* ¡ */
/*162*/ 162,    /* ¢ */
/*163*/ 163,    /* £ */
/*164*/ 164,    /* ¤ */ /* Euro sign */
/*165*/ 165,    /* ¥ */
/*166*/ 166,    /* ¦ */
/*167*/ 167,    /* § */
/*168*/ 184,    /* CYRILLIC CAPITAL LETTER IO */
/*169*/ 169,    /* © */
/*170*/ 170,    /* ª */ /* Numero sign */
/*171*/ 171,    /* « */
/*172*/ 172,    /* ¬ */
/*173*/ 173,    /* ­ */
/*174*/ 174,    /* ® */
/*175*/ 175,    /* ¯ */
/*176*/ 176,    /* ° */
/*177*/ 177,    /* ± */
/*178*/ 178,    /* ² */
/*179*/ 179,    /* ³ */
/*180*/ 180,    /* ´ */
/*181*/ 181,    /* µ */
/*182*/ 182,    /* ¶ */
/*183*/ 183,    /* · */
/*184*/ 184,    /* CYRILLIC SMALL LETTER IO */
/*185*/ 185,    /* ¹ */
/*186*/ 186,    /* º */
/*187*/ 187,    /* » */
/*188*/ 188,    /* ¼ */
/*189*/ 189,    /* ½ */
/*190*/ 190,    /* ¾ */
/*191*/ 191,    /* ¿ */
/*192*/ 224,    /* CYRILLIC CAPITAL LETTER A */
/*193*/ 225,    /* CYRILLIC CAPITAL LETTER BE */
/*194*/ 226,    /* CYRILLIC CAPITAL LETTER VE */
/*195*/ 227,    /* CYRILLIC CAPITAL LETTER GHE */
/*196*/ 228,    /* CYRILLIC CAPITAL LETTER DE */
/*197*/ 229,    /* CYRILLIC CAPITAL LETTER IE */
/*198*/ 230,    /* CYRILLIC CAPITAL LETTER ZHE */
/*199*/ 231,    /* CYRILLIC CAPITAL LETTER ZE */
/*200*/ 232,    /* CYRILLIC CAPITAL LETTER I */
/*201*/ 233,    /* CYRILLIC CAPITAL LETTER SHORT I */
/*202*/ 234,    /* CYRILLIC CAPITAL LETTER KA */
/*203*/ 235,    /* CYRILLIC CAPITAL LETTER EL */
/*204*/ 236,    /* CYRILLIC CAPITAL LETTER EM */
/*205*/ 237,    /* CYRILLIC CAPITAL LETTER EN */
/*206*/ 238,    /* CYRILLIC CAPITAL LETTER O */
/*207*/ 239,    /* CYRILLIC CAPITAL LETTER PE */
/*208*/ 240,    /* CYRILLIC CAPITAL LETTER ER */
/*209*/ 241,    /* CYRILLIC CAPITAL LETTER ES */
/*210*/ 242,    /* CYRILLIC CAPITAL LETTER TE */
/*211*/ 243,    /* CYRILLIC CAPITAL LETTER U */
/*212*/ 244,    /* CYRILLIC CAPITAL LETTER EF */
/*213*/ 245,    /* CYRILLIC CAPITAL LETTER HA */
/*214*/ 246,    /* CYRILLIC CAPITAL LETTER TSE */
/*215*/ 247,    /* CYRILLIC CAPITAL LETTER CHE */
/*216*/ 248,    /* CYRILLIC CAPITAL LETTER SHA */
/*217*/ 249,    /* CYRILLIC CAPITAL LETTER SHCHA */
/*218*/ 250,    /* CYRILLIC CAPITAL LETTER HARD SIGN */
/*219*/ 251,    /* CYRILLIC CAPITAL LETTER YERU */
/*220*/ 252,    /* CYRILLIC CAPITAL LETTER SOFT SIGN */
/*221*/ 253,    /* CYRILLIC CAPITAL LETTER E */
/*222*/ 254,    /* CYRILLIC CAPITAL LETTER YU */
/*223*/ 255,    /* CYRILLIC CAPITAL LETTER YA */
/*224*/ 224,    /* CYRILLIC SMALL LETTER A */
/*225*/ 225,    /* CYRILLIC SMALL LETTER BE */
/*226*/ 226,    /* CYRILLIC SMALL LETTER VE */
/*227*/ 227,    /* CYRILLIC SMALL LETTER GHE */
/*228*/ 228,    /* CYRILLIC SMALL LETTER DE */
/*229*/ 229,    /* CYRILLIC SMALL LETTER IE */
/*230*/ 230,    /* CYRILLIC SMALL LETTER ZHE */
/*231*/ 231,    /* CYRILLIC SMALL LETTER ZE */
/*232*/ 232,    /* CYRILLIC SMALL LETTER I */
/*233*/ 233,    /* CYRILLIC SMALL LETTER SHORT I */
/*234*/ 234,    /* CYRILLIC SMALL LETTER KA */
/*235*/ 235,    /* CYRILLIC SMALL LETTER EL */
/*236*/ 236,    /* CYRILLIC SMALL LETTER EM */
/*237*/ 237,    /* CYRILLIC SMALL LETTER EN */
/*238*/ 238,    /* CYRILLIC SMALL LETTER O */
/*239*/ 239,    /* CYRILLIC SMALL LETTER PE */
/*240*/ 240,    /* CYRILLIC SMALL LETTER ER */
/*241*/ 241,    /* CYRILLIC SMALL LETTER ES */
/*242*/ 242,    /* CYRILLIC SMALL LETTER TE */
/*243*/ 243,    /* CYRILLIC SMALL LETTER U */
/*244*/ 244,    /* CYRILLIC SMALL LETTER EF */
/*245*/ 245,    /* CYRILLIC SMALL LETTER HA */
/*246*/ 246,    /* CYRILLIC SMALL LETTER TSE */
/*247*/ 247,    /* CYRILLIC SMALL LETTER CHE */
/*248*/ 248,    /* CYRILLIC SMALL LETTER SHA */
/*249*/ 249,    /* CYRILLIC SMALL LETTER SHCHA */
/*250*/ 250,    /* CYRILLIC SMALL LETTER HARD SIGN */
/*251*/ 251,    /* CYRILLIC SMALL LETTER YERU */
/*252*/ 252,    /* CYRILLIC SMALL LETTER SOFT SIGN */
/*253*/ 253,    /* CYRILLIC SMALL LETTER E */
/*254*/ 254,    /* CYRILLIC SMALL LETTER YU */
/*255*/ 255     /* CYRILLIC SMALL LETTER YA */
};

/*-------------------------------------------------------------------------*/

STATIC CONST UBYTE CharAttrTable[256] =
{
/*  0*/ CNTRLF,                /* NUL */
/*  1*/ CNTRLF,                /* STX */
/*  2*/ CNTRLF,                /* SOT */
/*  3*/ CNTRLF,                /* ETX */
/*  4*/ CNTRLF,                /* EOT */
/*  5*/ CNTRLF,                /* ENQ */
/*  6*/ CNTRLF,                /* ACK */
/*  7*/ CNTRLF,                /* BEL */
/*  8*/ CNTRLF,                /* BS  */
/*  9*/ CNTRLF|SPACEF,         /* TAB */
/* 10*/ CNTRLF|SPACEF,         /* LF  */
/* 11*/ CNTRLF|SPACEF,         /* VT  */
/* 12*/ CNTRLF|SPACEF,         /* FF  */
/* 13*/ CNTRLF|SPACEF,         /* CR  */
/* 14*/ CNTRLF,                /* SO  */
/* 15*/ CNTRLF,                /* SI  */
/* 16*/ CNTRLF,                /* DLE */
/* 17*/ CNTRLF,                /* DC1 */
/* 18*/ CNTRLF,                /* DC2 */
/* 19*/ CNTRLF,                /* DC3 */
/* 20*/ CNTRLF,                /* DC4 */
/* 21*/ CNTRLF,                /* NAK */
/* 22*/ CNTRLF,                /* SYN */
/* 23*/ CNTRLF,                /* ETB */
/* 24*/ CNTRLF,                /* CAN */
/* 25*/ CNTRLF,                /* EM  */
/* 26*/ CNTRLF,                /* SUB */
/* 27*/ CNTRLF,                /* ESC */
/* 28*/ CNTRLF,                /* FS  */
/* 29*/ CNTRLF,                /* GS  */
/* 30*/ CNTRLF,                /* RS  */
/* 31*/ CNTRLF,                /* US  */
/* 32*/ SPACEF,                /*   */
/* 33*/ PUNCTF,                /* ! */
/* 34*/ PUNCTF,                /* " */
/* 35*/ PUNCTF,                /* # */
/* 36*/ PUNCTF,                /* $ */
/* 37*/ PUNCTF,                /* % */
/* 38*/ PUNCTF,                /* & */
/* 39*/ PUNCTF,                /* ' */
/* 40*/ PUNCTF,                /* ( */
/* 41*/ PUNCTF,                /* ) */
/* 42*/ PUNCTF,                /* * */
/* 43*/ PUNCTF,                /* + */
/* 44*/ PUNCTF,                /* , */
/* 45*/ PUNCTF,                /* - */
/* 46*/ PUNCTF,                /* . */
/* 47*/ PUNCTF,                /* / */
/* 48*/ DIGITF|XDIGITF,        /* 0 */
/* 49*/ DIGITF|XDIGITF,        /* 1 */
/* 50*/ DIGITF|XDIGITF,        /* 2 */
/* 51*/ DIGITF|XDIGITF,        /* 3 */
/* 52*/ DIGITF|XDIGITF,        /* 4 */
/* 53*/ DIGITF|XDIGITF,        /* 5 */
/* 54*/ DIGITF|XDIGITF,        /* 6 */
/* 55*/ DIGITF|XDIGITF,        /* 7 */
/* 56*/ DIGITF|XDIGITF,        /* 8 */
/* 57*/ DIGITF|XDIGITF,        /* 9 */
/* 58*/ PUNCTF,                /* : */
/* 59*/ PUNCTF,                /* ; */
/* 60*/ PUNCTF,                /* < */
/* 61*/ PUNCTF,                /* = */
/* 62*/ PUNCTF,                /* > */
/* 63*/ PUNCTF,                /* ? */
/* 64*/ PUNCTF,                /* @ */
/* 65*/ ALPHAF|UPPERF|XDIGITF, /* A */
/* 66*/ ALPHAF|UPPERF|XDIGITF, /* B */
/* 67*/ ALPHAF|UPPERF|XDIGITF, /* C */
/* 68*/ ALPHAF|UPPERF|XDIGITF, /* D */
/* 69*/ ALPHAF|UPPERF|XDIGITF, /* E */
/* 70*/ ALPHAF|UPPERF|XDIGITF, /* F */
/* 71*/ ALPHAF|UPPERF,         /* G */
/* 72*/ ALPHAF|UPPERF,         /* H */
/* 73*/ ALPHAF|UPPERF,         /* I */
/* 74*/ ALPHAF|UPPERF,         /* J */
/* 75*/ ALPHAF|UPPERF,         /* K */
/* 76*/ ALPHAF|UPPERF,         /* L */
/* 77*/ ALPHAF|UPPERF,         /* M */
/* 78*/ ALPHAF|UPPERF,         /* N */
/* 79*/ ALPHAF|UPPERF,         /* O */
/* 80*/ ALPHAF|UPPERF,         /* P */
/* 81*/ ALPHAF|UPPERF,         /* Q */
/* 82*/ ALPHAF|UPPERF,         /* R */
/* 83*/ ALPHAF|UPPERF,         /* S */
/* 84*/ ALPHAF|UPPERF,         /* T */
/* 85*/ ALPHAF|UPPERF,         /* U */
/* 86*/ ALPHAF|UPPERF,         /* V */
/* 87*/ ALPHAF|UPPERF,         /* W */
/* 88*/ ALPHAF|UPPERF,         /* X */
/* 89*/ ALPHAF|UPPERF,         /* Y */
/* 90*/ ALPHAF|UPPERF,         /* Z */
/* 91*/ PUNCTF,                /* [ */
/* 92*/ PUNCTF,                /* \ */
/* 93*/ PUNCTF,                /* ] */
/* 94*/ PUNCTF,                /* ^ */
/* 95*/ PUNCTF,                /* _ */
/* 96*/ PUNCTF,                /* ` */
/* 97*/ ALPHAF|LOWERF|XDIGITF, /* a */
/* 98*/ ALPHAF|LOWERF|XDIGITF, /* b */
/* 99*/ ALPHAF|LOWERF|XDIGITF, /* c */
/*100*/ ALPHAF|LOWERF|XDIGITF, /* d */
/*101*/ ALPHAF|LOWERF|XDIGITF, /* e */
/*102*/ ALPHAF|LOWERF|XDIGITF, /* f */
/*103*/ ALPHAF|LOWERF,         /* g */
/*104*/ ALPHAF|LOWERF,         /* h */
/*105*/ ALPHAF|LOWERF,         /* i */
/*106*/ ALPHAF|LOWERF,         /* j */
/*107*/ ALPHAF|LOWERF,         /* k */
/*108*/ ALPHAF|LOWERF,         /* l */
/*109*/ ALPHAF|LOWERF,         /* m */
/*110*/ ALPHAF|LOWERF,         /* n */
/*111*/ ALPHAF|LOWERF,         /* o */
/*112*/ ALPHAF|LOWERF,         /* p */
/*113*/ ALPHAF|LOWERF,         /* q */
/*114*/ ALPHAF|LOWERF,         /* r */
/*115*/ ALPHAF|LOWERF,         /* s */
/*116*/ ALPHAF|LOWERF,         /* t */
/*117*/ ALPHAF|LOWERF,         /* u */
/*118*/ ALPHAF|LOWERF,         /* v */
/*119*/ ALPHAF|LOWERF,         /* w */
/*120*/ ALPHAF|LOWERF,         /* x */
/*121*/ ALPHAF|LOWERF,         /* y */
/*122*/ ALPHAF|LOWERF,         /* z */
/*123*/ PUNCTF,                /* { */
/*124*/ PUNCTF,                /* | */
/*125*/ PUNCTF,                /* } */
/*126*/ PUNCTF,                /* ~ */
/*127*/ CNTRLF,                /* DEL */
/*128*/ CNTRLF,                /* XXX */
/*129*/ CNTRLF,                /* XXX */
/*130*/ CNTRLF,                /* BPH */
/*131*/ CNTRLF,                /* NBH */
/*132*/ CNTRLF,                /* IND */
/*133*/ CNTRLF,                /* NEL */
/*134*/ CNTRLF,                /* SSA */
/*135*/ CNTRLF,                /* ESA */
/*136*/ CNTRLF,                /* HTS */
/*137*/ CNTRLF,                /* HTJ */
/*138*/ CNTRLF,                /* VTS */
/*139*/ CNTRLF,                /* PLD */
/*140*/ CNTRLF,                /* PLU */
/*141*/ CNTRLF,                /* RI  */
/*142*/ CNTRLF,                /* SS2 */
/*143*/ CNTRLF,                /* SS3 */
/*144*/ CNTRLF,                /* DCS */
/*145*/ CNTRLF,                /* PU1 */
/*146*/ CNTRLF,                /* PU2 */
/*147*/ CNTRLF,                /* STS */
/*148*/ CNTRLF,                /* CCH */
/*149*/ CNTRLF,                /* MW  */
/*150*/ CNTRLF,                /* SPA */
/*151*/ CNTRLF,                /* EPA */
/*152*/ CNTRLF,                /* SOS */
/*153*/ CNTRLF,                /* XXX */
/*154*/ CNTRLF,                /* SCI */
/*155*/ CNTRLF,                /* CSI */
/*156*/ CNTRLF,                /* ST  */
/*157*/ CNTRLF,                /* OSC */
/*158*/ CNTRLF,                /* PM  */
/*159*/ CNTRLF,                /* APC */
/*160*/ PUNCTF,                /* NBSP */
/*161*/ PUNCTF,                /* ¡ */
/*162*/ PUNCTF,                /* ¢ */
/*163*/ PUNCTF,                /* £ */
/*164*/ PUNCTF,                /* ¤ */ /* Euro sign */
/*165*/ PUNCTF,                /* ¥ */
/*166*/ PUNCTF,                /* ¦ */
/*167*/ PUNCTF,                /* § */
/*168*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER IO */
/*169*/ PUNCTF,                /* © */
/*170*/ PUNCTF,                /* ª */ /* Numero sign */
/*171*/ PUNCTF,                /* « */
/*172*/ PUNCTF,                /* ¬ */
/*173*/ PUNCTF,                /* ­ */
/*174*/ PUNCTF,                /* ® */
/*175*/ PUNCTF,                /* ¯ */
/*176*/ PUNCTF,                /* ° */
/*177*/ PUNCTF,                /* ± */
/*178*/ PUNCTF,                /* ² */
/*179*/ PUNCTF,                /* ³ */
/*180*/ PUNCTF,                /* ´ */
/*181*/ ALPHAF|LOWERF,         /* µ */
/*182*/ PUNCTF,                /* ¶ */
/*183*/ PUNCTF,                /* · */
/*184*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER IO */
/*185*/ PUNCTF,                /* ¹ */
/*186*/ ALPHAF,                /* º */
/*187*/ PUNCTF,                /* » */
/*188*/ PUNCTF,                /* ¼ */
/*189*/ PUNCTF,                /* ½ */
/*190*/ PUNCTF,                /* ¾ */
/*191*/ PUNCTF,                /* ¿ */
/*192*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER A */
/*193*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER BE */
/*194*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER VE */
/*195*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER GHE */
/*196*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER DE */
/*197*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER IE */
/*198*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER ZHE */
/*199*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER ZE */
/*200*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER I */
/*201*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER SHORT I */
/*202*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER KA */
/*203*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER EL */
/*204*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER EM */
/*205*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER EN */
/*206*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER O */
/*207*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER PE */
/*208*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER ER */
/*209*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER ES */
/*210*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER TE */
/*211*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER U */
/*212*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER EF */
/*213*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER HA */
/*214*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER TSE */
/*215*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER CHE */
/*216*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER SHA */
/*217*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER SHCHA */
/*218*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER HARD SIGN */
/*219*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER YERU */
/*220*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER SOFT SIGN */
/*221*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER E */
/*222*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER YU */
/*223*/ ALPHAF|UPPERF,         /* CYRILLIC CAPITAL LETTER YA */
/*224*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER A */
/*225*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER BE */
/*226*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER VE */
/*227*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER GHE */
/*228*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER DE */
/*229*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER IE */
/*230*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER ZHE */
/*231*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER ZE */
/*232*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER I */
/*233*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER SHORT I */
/*234*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER KA */
/*235*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER EL */
/*236*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER EM */
/*237*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER EN */
/*238*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER O */
/*239*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER PE */
/*240*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER ER */
/*241*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER ES */
/*242*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER TE */
/*243*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER U */
/*244*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER EF */
/*245*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER HA */
/*246*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER TSE */
/*247*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER CHE */
/*248*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER SHA */
/*249*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER SHCHA */
/*250*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER HARD SIGN */
/*251*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER YERU */
/*252*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER SOFT SIGN */
/*253*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER E */
/*254*/ ALPHAF|LOWERF,         /* CYRILLIC SMALL LETTER YU */
/*255*/ ALPHAF|LOWERF          /* CYRILLIC SMALL LETTER YA */
};
