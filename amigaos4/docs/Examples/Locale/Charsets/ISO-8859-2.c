/*
 * C charset library code by TetiSoft@apg.lahn.de (Detlef Würkner)
 */

#include <exec/types.h>

#include "ISO-8859-2.charset_rev.h"

#define LIBNAME "ISO-8859-2.charset"

#define ESZET 'ß'

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
/*161*/ 'A',    /* LATIN CAPITAL LETTER A WITH OGONEK */
/*162*/ 162,    /* BREVE */
/*163*/ 'L',    /* LATIN CAPITAL LETTER L WITH STROKE */
/*164*/ '$',    /* ¤ */
/*165*/ 'L',    /* LATIN CAPITAL LETTER L WITH CARON */
/*166*/ 'S',    /* LATIN CAPITAL LETTER S WITH ACUTE */
/*167*/ 167,    /* § */
/*168*/ 168,    /* ¨ */
/*169*/ 'S',    /* LATIN CAPITAL LETTER S WITH CARON */
/*170*/ 'S',    /* LATIN CAPITAL LETTER S WITH CEDILLA */
/*171*/ 'T',    /* LATIN CAPITAL LETTER T WITH CARON */
/*172*/ 'Z',    /* LATIN CAPITAL LETTER Z WITH ACUTE */
/*173*/ '-',    /* ­ */
/*174*/ 'Z',    /* LATIN CAPITAL LETTER Z WITH CARON */
/*175*/ 'Z',    /* LATIN CAPITAL LETTER Z WITH DOT ABOVE */
/*176*/ 176,    /* ° */
/*177*/ 'A',    /* LATIN SMALL LETTER A WITH OGONEK */
/*178*/ 178,    /* OGONEK */
/*179*/ 'L',    /* LATIN SMALL LETTER L WITH STROKE */
/*180*/ '\'',    /* ´ */
/*181*/ 'L',    /* LATIN SMALL LETTER L WITH CARON */
/*182*/ 'S',    /* LATIN SMALL LETTER S WITH ACUTE */
/*183*/ 183,    /* CARON */
/*184*/ 184,    /* ¸ */
/*185*/ 'S',    /* LATIN SMALL LETTER S WITH CARON */
/*186*/ 'S',    /* LATIN SMALL LETTER S WITH CEDILLA */
/*187*/ 'T',    /* LATIN SMALL LETTER T WITH CARON */
/*188*/ 'Z',    /* LATIN SMALL LETTER Z WITH ACUTE */
/*189*/ 189,    /* DOUBLE ACUTE ACCENT */
/*190*/ 'Z',    /* LATIN SMALL LETTER Z WITH CARON */
/*191*/ 'Z',    /* LATIN SMALL LETTER Z WITH DOT ABOVE */
/*192*/ 'R',    /* LATIN CAPITAL LETTER R WITH ACUTE */
/*193*/ 'A',    /* Á */
/*194*/ 'A',    /* Â */
/*195*/ 'A',    /* LATIN CAPITAL LETTER A WITH BREVE */
/*196*/ 'A',    /* Ä */
/*197*/ 'L',    /* LATIN CAPITAL LETTER L WITH ACUTE */
/*198*/ 'C',    /* LATIN CAPITAL LETTER C WITH ACUTE */
/*199*/ 'C',    /* Ç */
/*200*/ 'C',    /* LATIN CAPITAL LETTER C WITH CARON */
/*201*/ 'E',    /* É */
/*202*/ 'E',    /* LATIN CAPITAL LETTER E WITH OGONEK */
/*203*/ 'E',    /* Ë */
/*204*/ 'E',    /* LATIN CAPITAL LETTER E WITH CARON */
/*205*/ 'I',    /* Í */
/*206*/ 'I',    /* Î */
/*207*/ 'D',    /* LATIN CAPITAL LETTER D WITH CARON */
/*208*/ 'D',    /* LATIN CAPITAL LETTER D WITH STROKE */
/*209*/ 'N',    /* LATIN CAPITAL LETTER N WITH ACUTE */
/*210*/ 'N',    /* LATIN CAPITAL LETTER N WITH CARON */
/*211*/ 'O',    /* Ó */
/*212*/ 'O',    /* Ô */
/*213*/ 'O',    /* LATIN CAPITAL LETTER O WITH DOUBLE ACUTE */
/*214*/ 'O',    /* Ö */
/*215*/ '*',    /* × */
/*216*/ 'R',    /* LATIN CAPITAL LETTER R WITH CARON */
/*217*/ 'U',    /* LATIN CAPITAL LETTER U WITH RING ABOVE */
/*218*/ 'U',    /* Ú */
/*219*/ 'U',    /* LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
/*220*/ 'U',    /* Ü */
/*221*/ 'Y',    /* Ý */
/*222*/ 'T',    /* LATIN CAPITAL LETTER T WITH CEDILLA */
/*223*/ 223,    /* ß */
/*224*/ 'R',    /* LATIN SMALL LETTER R WITH ACUTE */
/*225*/ 'A',    /* á */
/*226*/ 'A',    /* â */
/*227*/ 'A',    /* LATIN SMALL LETTER A WITH BREVE */
/*228*/ 'A',    /* ä */
/*229*/ 'L',    /* LATIN SMALL LETTER L WITH ACUTE */
/*230*/ 'C',    /* LATIN SMALL LETTER C WITH ACUTE */
/*231*/ 'C',    /* ç */
/*232*/ 'C',    /* LATIN SMALL LETTER C WITH CARON */
/*233*/ 'E',    /* é */
/*234*/ 'E',    /* LATIN SMALL LETTER E WITH OGONEK */
/*235*/ 'E',    /* ë */
/*236*/ 'E',    /* LATIN SMALL LETTER E WITH CARON */
/*237*/ 'I',    /* í */
/*238*/ 'I',    /* î */
/*239*/ 'D',    /* LATIN SMALL LETTER D WITH CARON */
/*240*/ 'D',    /* LATIN SMALL LETTER D WITH STROKE */
/*241*/ 'N',    /* LATIN SMALL LETTER N WITH ACUTE */
/*242*/ 'N',    /* LATIN SMALL LETTER N WITH CARON */
/*243*/ 'O',    /* ó */
/*244*/ 'O',    /* ô */
/*245*/ 'O',    /* LATIN SMALL LETTER O WITH DOUBLE ACUTE */
/*246*/ 'O',    /* ö */
/*247*/ '/',    /* ÷ */
/*248*/ 'R',    /* LATIN SMALL LETTER R WITH CARON */
/*249*/ 'U',    /* LATIN SMALL LETTER U WITH RING ABOVE */
/*250*/ 'U',    /* ú */
/*251*/ 'U',    /* LATIN SMALL LETTER U WITH DOUBLE ACUTE */
/*252*/ 'U',    /* ü */
/*253*/ 'Y',    /* ý */
/*254*/ 'T',    /* LATIN SMALL LETTER T WITH CEDILLA */
/*255*/ 255     /* DOT ABOVE */
};

/*-------------------------------------------------------------------------*/

/* Used by StrnCmp()
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
    V_Z
};

/* ISO-8859-2 sorting table */

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
/*161*/ V_A,        /* LATIN CAPITAL LETTER A WITH OGONEK */
/*162*/ V_PUNCT,    /* BREVE */
/*163*/ V_L,        /* LATIN CAPITAL LETTER L WITH STROKE */
/*164*/ V_CURR,     /* ¤ */
/*165*/ V_L,        /* LATIN CAPITAL LETTER L WITH CARON */
/*166*/ V_S,        /* LATIN CAPITAL LETTER S WITH ACUTE */
/*167*/ V_PUNCT,    /* § */
/*168*/ V_PUNCT,    /* ¨ */
/*169*/ V_S,        /* LATIN CAPITAL LETTER S WITH CARON */
/*170*/ V_S,        /* LATIN CAPITAL LETTER S WITH CEDILLA */
/*171*/ V_T,        /* LATIN CAPITAL LETTER T WITH CARON */
/*172*/ V_Z,        /* LATIN CAPITAL LETTER Z WITH ACUTE */
/*173*/ V_PUNCT,    /* ­ */
/*174*/ V_Z,        /* LATIN CAPITAL LETTER Z WITH CARON */
/*175*/ V_Z,        /* LATIN CAPITAL LETTER Z WITH DOT ABOVE */
/*176*/ V_PUNCT,    /* ° */
/*177*/ V_A,        /* LATIN SMALL LETTER A WITH OGONEK */
/*178*/ V_PUNCT,    /* OGONEK */
/*179*/ V_L,        /* LATIN SMALL LETTER L WITH STROKE */
/*180*/ V_PUNCT,    /* ´ */
/*181*/ V_L,        /* LATIN SMALL LETTER L WITH CARON */
/*182*/ V_S,        /* LATIN SMALL LETTER S WITH ACUTE */
/*183*/ V_PUNCT,    /* CARON */
/*184*/ V_PUNCT,    /* ¸ */
/*185*/ V_S,        /* LATIN SMALL LETTER S WITH CARON */
/*186*/ V_S,        /* LATIN SMALL LETTER S WITH CEDILLA */
/*187*/ V_T,        /* LATIN SMALL LETTER T WITH CARON */
/*188*/ V_Z,        /* LATIN SMALL LETTER Z WITH ACUTE */
/*189*/ V_PUNCT,    /* DOUBLE ACUTE ACCENT */
/*190*/ V_Z,        /* LATIN SMALL LETTER Z WITH CARON */
/*191*/ V_Z,        /* LATIN SMALL LETTER Z WITH DOT ABOVE */
/*192*/ V_R,        /* LATIN CAPITAL LETTER R WITH ACUTE */
/*193*/ V_A,        /* Á */
/*194*/ V_A,        /* Â */
/*195*/ V_A,        /* LATIN CAPITAL LETTER A WITH BREVE */
/*196*/ V_A,        /* Ä */
/*197*/ V_L,        /* LATIN CAPITAL LETTER L WITH ACUTE */
/*198*/ V_C,        /* LATIN CAPITAL LETTER C WITH ACUTE */
/*199*/ V_C,        /* Ç */
/*200*/ V_C,        /* LATIN CAPITAL LETTER C WITH CARON */
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
/*216*/ V_R,        /* LATIN CAPITAL LETTER R WITH CARON */
/*217*/ V_U,        /* LATIN CAPITAL LETTER U WITH RING ABOVE */
/*218*/ V_U,        /* Ú */
/*219*/ V_U,        /* LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
/*220*/ V_U,        /* Ü */
/*221*/ V_Y,        /* Ý */
/*222*/ V_T,        /* LATIN CAPITAL LETTER T WITH CEDILLA */
/*223*/ V_S,        /* ß */
/*224*/ V_R,        /* LATIN SMALL LETTER R WITH ACUTE */
/*225*/ V_A,        /* á */
/*226*/ V_A,        /* â */
/*227*/ V_A,        /* LATIN SMALL LETTER A WITH BREVE */
/*228*/ V_A,        /* ä */
/*229*/ V_L,        /* LATIN SMALL LETTER L WITH ACUTE */
/*230*/ V_C,        /* LATIN SMALL LETTER C WITH ACUTE */
/*231*/ V_C,        /* ç */
/*232*/ V_C,        /* LATIN SMALL LETTER C WITH CARON */
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
/*248*/ V_R,        /* LATIN SMALL LETTER R WITH CARON */
/*249*/ V_U,        /* LATIN SMALL LETTER U WITH RING ABOVE */
/*250*/ V_U,        /* ú */
/*251*/ V_U,        /* LATIN SMALL LETTER U WITH DOUBLE ACUTE */
/*252*/ V_U,        /* ü */
/*253*/ V_Y,        /* ý */
/*254*/ V_T,        /* LATIN SMALL LETTER T WITH CEDILLA */
/*255*/ V_PUNCT     /* DOT ABOVE */
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
/*161*/ 177,    /* LATIN CAPITAL LETTER A WITH OGONEK */
/*162*/ 162,    /* BREVE */
/*163*/ 179,    /* LATIN CAPITAL LETTER L WITH STROKE */
/*164*/ 164,    /* ¤ */
/*165*/ 181,    /* LATIN CAPITAL LETTER L WITH CARON */
/*166*/ 182,    /* LATIN CAPITAL LETTER S WITH ACUTE */
/*167*/ 167,    /* § */
/*168*/ 168,    /* ¨ */
/*169*/ 185,    /* LATIN CAPITAL LETTER S WITH CARON */
/*170*/ 186,    /* LATIN CAPITAL LETTER S WITH CEDILLA */
/*171*/ 187,    /* LATIN CAPITAL LETTER T WITH CARON */
/*172*/ 188,    /* LATIN CAPITAL LETTER Z WITH ACUTE */
/*173*/ 173,    /* ­ */
/*174*/ 190,    /* LATIN CAPITAL LETTER Z WITH CARON */
/*175*/ 191,    /* LATIN CAPITAL LETTER Z WITH DOT ABOVE */
/*176*/ 176,    /* ° */
/*177*/ 177,    /* LATIN SMALL LETTER A WITH OGONEK */
/*178*/ 178,    /* OGONEK */
/*179*/ 179,    /* LATIN SMALL LETTER L WITH STROKE */
/*180*/ 180,    /* ´ */
/*181*/ 181,    /* LATIN SMALL LETTER L WITH CARON */
/*182*/ 182,    /* LATIN SMALL LETTER S WITH ACUTE */
/*183*/ 183,    /* CARON */
/*184*/ 184,    /* ¸ */
/*185*/ 185,    /* LATIN SMALL LETTER S WITH CARON */
/*186*/ 186,    /* LATIN SMALL LETTER S WITH CEDILLA */
/*187*/ 187,    /* LATIN SMALL LETTER T WITH CARON */
/*188*/ 188,    /* LATIN SMALL LETTER Z WITH ACUTE */
/*189*/ 189,    /* DOUBLE ACUTE ACCENT */
/*190*/ 190,    /* LATIN SMALL LETTER Z WITH CARON */
/*191*/ 191,    /* LATIN SMALL LETTER Z WITH DOT ABOVE */
/*192*/ 224,    /* LATIN CAPITAL LETTER R WITH ACUTE */
/*193*/ 225,    /* Á */
/*194*/ 226,    /* Â */
/*195*/ 227,    /* LATIN CAPITAL LETTER A WITH BREVE */
/*196*/ 228,    /* Ä */
/*197*/ 229,    /* LATIN CAPITAL LETTER L WITH ACUTE */
/*198*/ 230,    /* LATIN CAPITAL LETTER C WITH ACUTE */
/*199*/ 231,    /* Ç */
/*200*/ 232,    /* LATIN CAPITAL LETTER C WITH CARON */
/*201*/ 233,    /* É */
/*202*/ 234,    /* LATIN CAPITAL LETTER E WITH OGONEK */
/*203*/ 235,    /* Ë */
/*204*/ 236,    /* LATIN CAPITAL LETTER E WITH CARON */
/*205*/ 237,    /* Í */
/*206*/ 238,    /* Î */
/*207*/ 239,    /* LATIN CAPITAL LETTER D WITH CARON */
/*208*/ 240,    /* LATIN CAPITAL LETTER D WITH STROKE */
/*209*/ 241,    /* LATIN CAPITAL LETTER N WITH ACUTE */
/*210*/ 242,    /* LATIN CAPITAL LETTER N WITH CARON */
/*211*/ 243,    /* Ó */
/*212*/ 244,    /* Ô */
/*213*/ 245,    /* LATIN CAPITAL LETTER O WITH DOUBLE ACUTE */
/*214*/ 246,    /* Ö */
/*215*/ 215,    /* × */
/*216*/ 248,    /* LATIN CAPITAL LETTER R WITH CARON */
/*217*/ 249,    /* LATIN CAPITAL LETTER U WITH RING ABOVE */
/*218*/ 250,    /* Ú */
/*219*/ 251,    /* LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
/*220*/ 252,    /* Ü */
/*221*/ 253,    /* Ý */
/*222*/ 254,    /* LATIN CAPITAL LETTER T WITH CEDILLA */
/*223*/ 223,    /* ß */
/*224*/ 224,    /* LATIN SMALL LETTER R WITH ACUTE */
/*225*/ 225,    /* á */
/*226*/ 226,    /* â */
/*227*/ 227,    /* LATIN SMALL LETTER A WITH BREVE */
/*228*/ 228,    /* ä */
/*229*/ 229,    /* LATIN SMALL LETTER L WITH ACUTE */
/*230*/ 230,    /* LATIN SMALL LETTER C WITH ACUTE */
/*231*/ 231,    /* ç */
/*232*/ 232,    /* LATIN SMALL LETTER C WITH CARON */
/*233*/ 233,    /* é */
/*234*/ 234,    /* LATIN SMALL LETTER E WITH OGONEK */
/*235*/ 235,    /* ë */
/*236*/ 236,    /* LATIN SMALL LETTER E WITH CARON */
/*237*/ 237,    /* í */
/*238*/ 238,    /* î */
/*239*/ 239,    /* LATIN SMALL LETTER D WITH CARON */
/*240*/ 240,    /* LATIN SMALL LETTER D WITH STROKE */
/*241*/ 241,    /* LATIN SMALL LETTER N WITH ACUTE */
/*242*/ 242,    /* LATIN SMALL LETTER N WITH CARON */
/*243*/ 243,    /* ó */
/*244*/ 244,    /* ô */
/*245*/ 245,    /* LATIN SMALL LETTER O WITH DOUBLE ACUTE */
/*246*/ 246,    /* ö */
/*247*/ 247,    /* ÷ */
/*248*/ 248,    /* LATIN SMALL LETTER R WITH CARON */
/*249*/ 249,    /* LATIN SMALL LETTER U WITH RING ABOVE */
/*250*/ 250,    /* ú */
/*251*/ 251,    /* LATIN SMALL LETTER U WITH DOUBLE ACUTE */
/*252*/ 252,    /* ü */
/*253*/ 253,    /* ý */
/*254*/ 254,    /* LATIN SMALL LETTER T WITH CEDILLA */
/*255*/ 255     /* DOT ABOVE */
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
/*161*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER A WITH OGONEK */
/*162*/ PUNCTF,                /* BREVE */
/*163*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER L WITH STROKE */
/*164*/ PUNCTF,                /* ¤ */
/*165*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER L WITH CARON */
/*166*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER S WITH ACUTE */
/*167*/ PUNCTF,                /* § */
/*168*/ PUNCTF,                /* ¨ */
/*169*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER S WITH CARON */
/*170*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER S WITH CEDILLA */
/*171*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER T WITH CARON */
/*172*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER Z WITH ACUTE */
/*173*/ PUNCTF,                /* ­ */
/*174*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER Z WITH CARON */
/*175*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER Z WITH DOT ABOVE */
/*176*/ PUNCTF,                /* ° */
/*177*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER A WITH OGONEK */
/*178*/ PUNCTF,                /* OGONEK */
/*179*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER L WITH STROKE */
/*180*/ PUNCTF,                /* ´ */
/*181*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER L WITH CARON */
/*182*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER S WITH ACUTE */
/*183*/ PUNCTF,                /* CARON */
/*184*/ PUNCTF,                /* ¸ */
/*185*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER S WITH CARON */
/*186*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER S WITH CEDILLA */
/*187*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER T WITH CARON */
/*188*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER Z WITH ACUTE */
/*189*/ PUNCTF,                /* DOUBLE ACUTE ACCENT */
/*190*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER Z WITH CARON */
/*191*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER Z WITH DOT ABOVE */
/*192*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER R WITH ACUTE */
/*193*/ ALPHAF|UPPERF,         /* Á */
/*194*/ ALPHAF|UPPERF,         /* Â */
/*195*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER A WITH BREVE */
/*196*/ ALPHAF|UPPERF,         /* Ä */
/*197*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER L WITH ACUTE */
/*198*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER C WITH ACUTE */
/*199*/ ALPHAF|UPPERF,         /* Ç */
/*200*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER C WITH CARON */
/*201*/ ALPHAF|UPPERF,         /* É */
/*202*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER E WITH OGONEK */
/*203*/ ALPHAF|UPPERF,         /* Ë */
/*204*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER E WITH CARON */
/*205*/ ALPHAF|UPPERF,         /* Í */
/*206*/ ALPHAF|UPPERF,         /* Î */
/*207*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER D WITH CARON */
/*208*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER D WITH STROKE */
/*209*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER N WITH ACUTE */
/*210*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER N WITH CARON */
/*211*/ ALPHAF|UPPERF,         /* Ó */
/*212*/ ALPHAF|UPPERF,         /* Ô */
/*213*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER O WITH DOUBLE ACUTE */
/*214*/ ALPHAF|UPPERF,         /* Ö */
/*215*/ PUNCTF,                /* × */
/*216*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER R WITH CARON */
/*217*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER U WITH RING ABOVE */
/*218*/ ALPHAF|UPPERF,         /* Ú */
/*219*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
/*220*/ ALPHAF|UPPERF,         /* Ü */
/*221*/ ALPHAF|UPPERF,         /* Ý */
/*222*/ ALPHAF|UPPERF,         /* LATIN CAPITAL LETTER T WITH CEDILLA */
/*223*/ ALPHAF|LOWERF,         /* ß */
/*224*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER R WITH ACUTE */
/*225*/ ALPHAF|LOWERF,         /* á */
/*226*/ ALPHAF|LOWERF,         /* â */
/*227*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER A WITH BREVE */
/*228*/ ALPHAF|LOWERF,         /* ä */
/*229*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER L WITH ACUTE */
/*230*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER C WITH ACUTE */
/*231*/ ALPHAF|LOWERF,         /* ç */
/*232*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER C WITH CARON */
/*233*/ ALPHAF|LOWERF,         /* é */
/*234*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER E WITH OGONEK */
/*235*/ ALPHAF|LOWERF,         /* ë */
/*236*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER E WITH CARON */
/*237*/ ALPHAF|LOWERF,         /* í */
/*238*/ ALPHAF|LOWERF,         /* î */
/*239*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER D WITH CARON */
/*240*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER D WITH STROKE */
/*241*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER N WITH ACUTE */
/*242*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER N WITH CARON */
/*243*/ ALPHAF|LOWERF,         /* ó */
/*244*/ ALPHAF|LOWERF,         /* ô */
/*245*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER O WITH DOUBLE ACUTE */
/*246*/ ALPHAF|LOWERF,         /* ö */
/*247*/ PUNCTF,                /* ÷ */
/*248*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER R WITH CARON */
/*249*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER U WITH RING ABOVE */
/*250*/ ALPHAF|LOWERF,         /* ú */
/*251*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER U WITH DOUBLE ACUTE */
/*252*/ ALPHAF|LOWERF,         /* ü */
/*253*/ ALPHAF|LOWERF,         /* ý */
/*254*/ ALPHAF|LOWERF,         /* LATIN SMALL LETTER T WITH CEDILLA */
/*255*/ PUNCTF                 /* DOT ABOVE */
};
