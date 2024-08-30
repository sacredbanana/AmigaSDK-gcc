#ifndef LIBRARIES_MATHFFP_H
#define LIBRARIES_MATHFFP_H 1
/*
**    $VER: mathffp.h 54.16 (22.08.2022)
**
**    general floating point declarations
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifdef __amigaos4__
#error mathffp.library and mathtrans.library are not supported on AmigaOS4
#endif

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

#ifndef PI
#define PI       ((float) 3.141592653589793)
#endif
#define TWO_PI   (((float) 2) * PI)
#define PI2      (PI / ((float) 2))
#define PI4      (PI / ((float) 4))
#ifndef E
#define E        ((float) 2.718281828459045)
#endif
#define LOG10    ((float) 2.302585092994046)

#define FPTEN    ((float) 10.0)
#define FPONE    ((float) 1.0)
#define FPHALF   ((float) 0.5)
#define FPZERO   ((float) 0.0)

#define trunc(x) ((int) (x))
#define round(x) ((int) ((x) + 0.5))
#define itof(i)  ((float) (i))

#define fabs     SPAbs
#define floor    SPFloor
#define ceil     SPCeil

#define tan      SPTan
#define atan     SPAtan
#define cos      SPCos
#define acos     SPAcos
#define sin      SPSin
#define asin     SPAsin
#define exp      SPExp
#define pow(a,b) SPPow((b),(a))
#define log      SPLog
#define log10    SPLog10
#define sqrt     SPSqrt

#define sinh     SPSinh
#define cosh     SPCosh
#define tanh     SPTanh

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

#endif /* LIBRARIES_MATHFFP_H */
