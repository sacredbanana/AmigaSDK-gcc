/*
 * C charset library code by TetiSoft@apg.lahn.de (Detlef W�rkner)
 */

#include <exec/types.h>

#include "ISO-8859-15.charset_rev.h"

#define LIBNAME "ISO-8859-15.charset"

#define ESZET '�'

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
/*161*/ '!',    /* � */
/*162*/ '$',    /* � */
/*163*/ '$',    /* � */
/*164*/ '$',    /* � */ /* Euro sign */
/*165*/ '$',    /* � */
/*166*/ 'S',    /* � */ /* S with caron */
/*167*/ '�',    /* � */
/*168*/ 'S',    /* � */ /* s with caron */
/*169*/ '�',    /* � */
/*170*/ 'A',    /* � */
/*171*/ '"',    /* � */
/*172*/ '�',    /* � */
/*173*/ '-',    /* � */
/*174*/ '�',    /* � */
/*175*/ '�',    /* � */
/*176*/ '�',    /* � */
/*177*/ '�',    /* � */
/*178*/ '2',    /* � */
/*179*/ '3',    /* � */
/*180*/ 'Z',    /* � */ /* Z with caron */
/*181*/ '�',    /* � */
/*182*/ '�',    /* � */
/*183*/ '�',    /* � */
/*184*/ 'Z',    /* � */ /* z with caron */
/*185*/ '1',    /* � */
/*186*/ 'O',    /* � */
/*187*/ '"',    /* � */
/*188*/ 'O',    /* � */ /* capital ligature OE */
/*189*/ 'O',    /* � */ /* small ligature OE */
/*190*/ 'Y',    /* � */ /* Y with diaeresis */
/*191*/ '?',    /* � */
/*192*/ 'A',    /* � */
/*193*/ 'A',    /* � */
/*194*/ 'A',    /* � */
/*195*/ 'A',    /* � */
/*196*/ 'A',    /* � */
/*197*/ 'A',    /* � */
/*198*/ 'A',    /* � */
/*199*/ 'C',    /* � */
/*200*/ 'E',    /* � */
/*201*/ 'E',    /* � */
/*202*/ 'E',    /* � */
/*203*/ 'E',    /* � */
/*204*/ 'I',    /* � */
/*205*/ 'I',    /* � */
/*206*/ 'I',    /* � */
/*207*/ 'I',    /* � */
/*208*/ 'D',    /* � */
/*209*/ 'N',    /* � */
/*210*/ 'O',    /* � */
/*211*/ 'O',    /* � */
/*212*/ 'O',    /* � */
/*213*/ 'O',    /* � */
/*214*/ 'O',    /* � */
/*215*/ '*',    /* � */
/*216*/ 'O',    /* � */
/*217*/ 'U',    /* � */
/*218*/ 'U',    /* � */
/*219*/ 'U',    /* � */
/*220*/ 'U',    /* � */
/*221*/ 'Y',    /* � */
/*222*/ '�',    /* � */
/*223*/ '�',    /* � */
/*224*/ 'A',    /* � */
/*225*/ 'A',    /* � */
/*226*/ 'A',    /* � */
/*227*/ 'A',    /* � */
/*228*/ 'A',    /* � */
/*229*/ 'A',    /* � */
/*230*/ 'A',    /* � */
/*231*/ 'C',    /* � */
/*232*/ 'E',    /* � */
/*233*/ 'E',    /* � */
/*234*/ 'E',    /* � */
/*235*/ 'E',    /* � */
/*236*/ 'I',    /* � */
/*237*/ 'I',    /* � */
/*238*/ 'I',    /* � */
/*239*/ 'I',    /* � */
/*240*/ 'D',    /* � */
/*241*/ 'N',    /* � */
/*242*/ 'O',    /* � */
/*243*/ 'O',    /* � */
/*244*/ 'O',    /* � */
/*245*/ 'O',    /* � */
/*246*/ 'O',    /* � */
/*247*/ '/',    /* � */
/*248*/ 'O',    /* � */
/*249*/ 'U',    /* � */
/*250*/ 'U',    /* � */
/*251*/ 'U',    /* � */
/*252*/ 'U',    /* � */
/*253*/ 'Y',    /* � */
/*254*/ '�',    /* � */
/*255*/ 'Y'     /* � */
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
    V_Z,
    V_MU,
    V_THORN
};

/* ISO-8859-15 sorting table */

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
/*188*/ V_O,        /* � */ /* capital ligature OE */
/*189*/ V_O,        /* � */ /* small ligature OE */
/*190*/ V_Y,        /* � */ /* Y with diaeresis */
/*191*/ V_PUNCT,    /* � */
/*192*/ V_A,        /* � */
/*193*/ V_A,        /* � */
/*194*/ V_A,        /* � */
/*195*/ V_A,        /* � */
/*196*/ V_A,        /* � */
/*197*/ V_A,        /* � */
/*198*/ V_A,        /* � */
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
/*214*/ V_O,        /* � */
/*215*/ V_PUNCT,    /* � */
/*216*/ V_O,        /* � */
/*217*/ V_U,        /* � */
/*218*/ V_U,        /* � */
/*219*/ V_U,        /* � */
/*220*/ V_U,        /* � */
/*221*/ V_Y,        /* � */
/*222*/ V_THORN,    /* � */
/*223*/ V_S,        /* � */
/*224*/ V_A,        /* � */
/*225*/ V_A,        /* � */
/*226*/ V_A,        /* � */
/*227*/ V_A,        /* � */
/*228*/ V_A,        /* � */
/*229*/ V_A,        /* � */
/*230*/ V_A,        /* � */
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
/*246*/ V_O,        /* � */
/*247*/ V_PUNCT,    /* � */
/*248*/ V_O,        /* � */
/*249*/ V_U,        /* � */
/*250*/ V_U,        /* � */
/*251*/ V_U,        /* � */
/*252*/ V_U,        /* � */
/*253*/ V_Y,        /* � */
/*254*/ V_THORN,    /* � */
/*255*/ V_Y         /* � */
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
/*222*/ '�',    /* � */
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
/*254*/ '�',    /* � */
/*255*/ '�'     /* � */
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
/*222*/ '�',    /* � */
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
/*254*/ '�',    /* � */
/*255*/ '�'     /* � */
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
/*161*/ PUNCTF,                /* � */
/*162*/ PUNCTF,                /* � */
/*163*/ PUNCTF,                /* � */
/*164*/ PUNCTF,                /* � */ /* Euro sign */
/*165*/ PUNCTF,                /* � */
/*166*/ ALPHAF|UPPERF,         /* � */ /* S with caron */
/*167*/ PUNCTF,                /* � */
/*168*/ ALPHAF|LOWERF,         /* � */ /* s with caron */
/*169*/ PUNCTF,                /* � */
/*170*/ ALPHAF,                /* � */
/*171*/ PUNCTF,                /* � */
/*172*/ PUNCTF,                /* � */
/*173*/ PUNCTF,                /* � */
/*174*/ PUNCTF,                /* � */
/*175*/ PUNCTF,                /* � */
/*176*/ PUNCTF,                /* � */
/*177*/ PUNCTF,                /* � */
/*178*/ PUNCTF,                /* � */
/*179*/ PUNCTF,                /* � */
/*180*/ ALPHAF|UPPERF,         /* � */ /* Z with caron */
/*181*/ ALPHAF|LOWERF,         /* � */
/*182*/ PUNCTF,                /* � */
/*183*/ PUNCTF,                /* � */
/*184*/ ALPHAF|LOWERF,         /* � */ /* z with caron */
/*185*/ PUNCTF,                /* � */
/*186*/ ALPHAF,                /* � */
/*187*/ PUNCTF,                /* � */
/*188*/ ALPHAF|UPPERF,         /* � */ /* capital ligature OE */
/*189*/ ALPHAF|LOWERF,         /* � */ /* small ligature OE */
/*190*/ ALPHAF|UPPERF,         /* � */ /* Y with diaeresis */
/*191*/ PUNCTF,                /* � */
/*192*/ ALPHAF|UPPERF,         /* � */
/*193*/ ALPHAF|UPPERF,         /* � */
/*194*/ ALPHAF|UPPERF,         /* � */
/*195*/ ALPHAF|UPPERF,         /* � */
/*196*/ ALPHAF|UPPERF,         /* � */
/*197*/ ALPHAF|UPPERF,         /* � */
/*198*/ ALPHAF|UPPERF,         /* � */
/*199*/ ALPHAF|UPPERF,         /* � */
/*200*/ ALPHAF|UPPERF,         /* � */
/*201*/ ALPHAF|UPPERF,         /* � */
/*202*/ ALPHAF|UPPERF,         /* � */
/*203*/ ALPHAF|UPPERF,         /* � */
/*204*/ ALPHAF|UPPERF,         /* � */
/*205*/ ALPHAF|UPPERF,         /* � */
/*206*/ ALPHAF|UPPERF,         /* � */
/*207*/ ALPHAF|UPPERF,         /* � */
/*208*/ ALPHAF|UPPERF,         /* � */
/*209*/ ALPHAF|UPPERF,         /* � */
/*210*/ ALPHAF|UPPERF,         /* � */
/*211*/ ALPHAF|UPPERF,         /* � */
/*212*/ ALPHAF|UPPERF,         /* � */
/*213*/ ALPHAF|UPPERF,         /* � */
/*214*/ ALPHAF|UPPERF,         /* � */
/*215*/ PUNCTF,                /* � */
/*216*/ ALPHAF|UPPERF,         /* � */
/*217*/ ALPHAF|UPPERF,         /* � */
/*218*/ ALPHAF|UPPERF,         /* � */
/*219*/ ALPHAF|UPPERF,         /* � */
/*220*/ ALPHAF|UPPERF,         /* � */
/*221*/ ALPHAF|UPPERF,         /* � */
/*222*/ ALPHAF|UPPERF,         /* � */
/*223*/ ALPHAF|LOWERF,         /* � */
/*224*/ ALPHAF|LOWERF,         /* � */
/*225*/ ALPHAF|LOWERF,         /* � */
/*226*/ ALPHAF|LOWERF,         /* � */
/*227*/ ALPHAF|LOWERF,         /* � */
/*228*/ ALPHAF|LOWERF,         /* � */
/*229*/ ALPHAF|LOWERF,         /* � */
/*230*/ ALPHAF|LOWERF,         /* � */
/*231*/ ALPHAF|LOWERF,         /* � */
/*232*/ ALPHAF|LOWERF,         /* � */
/*233*/ ALPHAF|LOWERF,         /* � */
/*234*/ ALPHAF|LOWERF,         /* � */
/*235*/ ALPHAF|LOWERF,         /* � */
/*236*/ ALPHAF|LOWERF,         /* � */
/*237*/ ALPHAF|LOWERF,         /* � */
/*238*/ ALPHAF|LOWERF,         /* � */
/*239*/ ALPHAF|LOWERF,         /* � */
/*240*/ ALPHAF|LOWERF,         /* � */
/*241*/ ALPHAF|LOWERF,         /* � */
/*242*/ ALPHAF|LOWERF,         /* � */
/*243*/ ALPHAF|LOWERF,         /* � */
/*244*/ ALPHAF|LOWERF,         /* � */
/*245*/ ALPHAF|LOWERF,         /* � */
/*246*/ ALPHAF|LOWERF,         /* � */
/*247*/ PUNCTF,                /* � */
/*248*/ ALPHAF|LOWERF,         /* � */
/*249*/ ALPHAF|LOWERF,         /* � */
/*250*/ ALPHAF|LOWERF,         /* � */
/*251*/ ALPHAF|LOWERF,         /* � */
/*252*/ ALPHAF|LOWERF,         /* � */
/*253*/ ALPHAF|LOWERF,         /* � */
/*254*/ ALPHAF|LOWERF,         /* � */
/*255*/ ALPHAF|LOWERF          /* � */
};
