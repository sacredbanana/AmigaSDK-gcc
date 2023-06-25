#ifndef LIBRARIES_MATHIEEESP_H
#define LIBRARIES_MATHIEEESP_H
/*
**    $VER: mathieeesp.h 54.16 (22.08.2022)
**
**    Include file to use for <math.h>
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifdef __amigaos4__
#error mathieeesingbas.library & mathieeesingtrans.library not supported on OS4
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
#define PI       ((float) 3.141592653589793))
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
#define trunc(x) ((int)   (x))
#define round(x) ((int)   ((x) + 0.5))
#define itof(i)  ((float) (i))

#define fabs     IEEESPAbs
#define floor    IEEESPFloor
#define ceil     IEEESPCeil

#define tan      IEEESPTan
#define atan     IEEESPAtan
#define cos      IEEESPCos
#define acos     IEEESPAcos
#define sin      IEEESPSin
#define asin     IEEESPAsin
#define exp      IEEESPExp
#define pow(a,b) IEEESPPow((b),(a))
#define log      IEEESPLog
#define log10    IEEESPLog10
#define sqrt     IEEESPSqrt

#define sinh     IEEESPSinh
#define cosh     IEEESPCosh
#define tanh     IEEESPTanh

#if 0 /* Use <clib/mathieeesingbas_protos.h> and
       *     <clib/mathieeesingtrans_protos.h> instead.
       */
float IEEESPTan(),IEEESPAtan();
float IEEESPCos(),IEEESPACos();
float IEEESPSin(),IEEESPASin();
float IEEESPExp(),IEEESPLog();
float IEEESPSqrt();
float IEEESPLog10(),IEEESPPow();
float IEEESPSincos();
float IEEESPSinh(),IEEESPCosh(),IEEESPTanh();
float IEEESPTieee();
float IEEESPFieee();

int   IEEESPFix();
int   IEEESPCmp(),IEEESPTst();
float IEEESPFlt();
float IEEESPAbs();
float IEEESPNeg();
float IEEESPAdd();
float IEEESPSub();
float IEEESPMul();
float IEEESPDiv();
float IEEESPFloor();
float IEEESPCeil();
#endif

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

#endif /* LIBRARIES_MATHIEEESP_H */
