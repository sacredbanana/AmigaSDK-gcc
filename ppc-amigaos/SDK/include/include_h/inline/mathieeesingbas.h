#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_MATHIEEESINGBAS_H
#define _INLINE_MATHIEEESINGBAS_H

#ifndef CLIB_MATHIEEESINGBAS_PROTOS_H
#define CLIB_MATHIEEESINGBAS_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef MATHIEEESINGBAS_BASE_NAME
#define MATHIEEESINGBAS_BASE_NAME MathIeeeSingBasBase
#endif

#define IEEESPFix(parm) ({ \
  FLOAT _IEEESPFix_parm = (parm); \
  LONG _IEEESPFix__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPFix__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register LONG __IEEESPFix__re __asm("d0"); \
  register FLOAT __IEEESPFix_parm __asm("d0") = (_IEEESPFix_parm); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__IEEESPFix__re) \
  : "r"(__IEEESPFix__bn), "r"(__IEEESPFix_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPFix__re; \
  }); \
  _IEEESPFix__re; \
})

#define IEEESPFlt(integer) ({ \
  LONG _IEEESPFlt_integer = (integer); \
  FLOAT _IEEESPFlt__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPFlt__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register FLOAT __IEEESPFlt__re __asm("d0"); \
  register LONG __IEEESPFlt_integer __asm("d0") = (_IEEESPFlt_integer); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__IEEESPFlt__re) \
  : "r"(__IEEESPFlt__bn), "r"(__IEEESPFlt_integer) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPFlt__re; \
  }); \
  _IEEESPFlt__re; \
})

#define IEEESPCmp(leftParm, rightParm) ({ \
  FLOAT _IEEESPCmp_leftParm = (leftParm); \
  FLOAT _IEEESPCmp_rightParm = (rightParm); \
  LONG _IEEESPCmp__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPCmp__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register LONG __IEEESPCmp__re __asm("d0"); \
  register FLOAT __IEEESPCmp_leftParm __asm("d0") = (_IEEESPCmp_leftParm); \
  register FLOAT __IEEESPCmp_rightParm __asm("d1") = (_IEEESPCmp_rightParm); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__IEEESPCmp__re) \
  : "r"(__IEEESPCmp__bn), "r"(__IEEESPCmp_leftParm), "r"(__IEEESPCmp_rightParm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPCmp__re; \
  }); \
  _IEEESPCmp__re; \
})

#define IEEESPTst(parm) ({ \
  FLOAT _IEEESPTst_parm = (parm); \
  LONG _IEEESPTst__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPTst__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register LONG __IEEESPTst__re __asm("d0"); \
  register FLOAT __IEEESPTst_parm __asm("d0") = (_IEEESPTst_parm); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__IEEESPTst__re) \
  : "r"(__IEEESPTst__bn), "r"(__IEEESPTst_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPTst__re; \
  }); \
  _IEEESPTst__re; \
})

#define IEEESPAbs(parm) ({ \
  FLOAT _IEEESPAbs_parm = (parm); \
  FLOAT _IEEESPAbs__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPAbs__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register FLOAT __IEEESPAbs__re __asm("d0"); \
  register FLOAT __IEEESPAbs_parm __asm("d0") = (_IEEESPAbs_parm); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__IEEESPAbs__re) \
  : "r"(__IEEESPAbs__bn), "r"(__IEEESPAbs_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPAbs__re; \
  }); \
  _IEEESPAbs__re; \
})

#define IEEESPNeg(parm) ({ \
  FLOAT _IEEESPNeg_parm = (parm); \
  FLOAT _IEEESPNeg__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPNeg__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register FLOAT __IEEESPNeg__re __asm("d0"); \
  register FLOAT __IEEESPNeg_parm __asm("d0") = (_IEEESPNeg_parm); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__IEEESPNeg__re) \
  : "r"(__IEEESPNeg__bn), "r"(__IEEESPNeg_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPNeg__re; \
  }); \
  _IEEESPNeg__re; \
})

#define IEEESPAdd(leftParm, rightParm) ({ \
  FLOAT _IEEESPAdd_leftParm = (leftParm); \
  FLOAT _IEEESPAdd_rightParm = (rightParm); \
  FLOAT _IEEESPAdd__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPAdd__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register FLOAT __IEEESPAdd__re __asm("d0"); \
  register FLOAT __IEEESPAdd_leftParm __asm("d0") = (_IEEESPAdd_leftParm); \
  register FLOAT __IEEESPAdd_rightParm __asm("d1") = (_IEEESPAdd_rightParm); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__IEEESPAdd__re) \
  : "r"(__IEEESPAdd__bn), "r"(__IEEESPAdd_leftParm), "r"(__IEEESPAdd_rightParm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPAdd__re; \
  }); \
  _IEEESPAdd__re; \
})

#define IEEESPSub(leftParm, rightParm) ({ \
  FLOAT _IEEESPSub_leftParm = (leftParm); \
  FLOAT _IEEESPSub_rightParm = (rightParm); \
  FLOAT _IEEESPSub__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPSub__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register FLOAT __IEEESPSub__re __asm("d0"); \
  register FLOAT __IEEESPSub_leftParm __asm("d0") = (_IEEESPSub_leftParm); \
  register FLOAT __IEEESPSub_rightParm __asm("d1") = (_IEEESPSub_rightParm); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__IEEESPSub__re) \
  : "r"(__IEEESPSub__bn), "r"(__IEEESPSub_leftParm), "r"(__IEEESPSub_rightParm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPSub__re; \
  }); \
  _IEEESPSub__re; \
})

#define IEEESPMul(leftParm, rightParm) ({ \
  FLOAT _IEEESPMul_leftParm = (leftParm); \
  FLOAT _IEEESPMul_rightParm = (rightParm); \
  FLOAT _IEEESPMul__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPMul__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register FLOAT __IEEESPMul__re __asm("d0"); \
  register FLOAT __IEEESPMul_leftParm __asm("d0") = (_IEEESPMul_leftParm); \
  register FLOAT __IEEESPMul_rightParm __asm("d1") = (_IEEESPMul_rightParm); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__IEEESPMul__re) \
  : "r"(__IEEESPMul__bn), "r"(__IEEESPMul_leftParm), "r"(__IEEESPMul_rightParm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPMul__re; \
  }); \
  _IEEESPMul__re; \
})

#define IEEESPDiv(dividend, divisor) ({ \
  FLOAT _IEEESPDiv_dividend = (dividend); \
  FLOAT _IEEESPDiv_divisor = (divisor); \
  FLOAT _IEEESPDiv__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPDiv__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register FLOAT __IEEESPDiv__re __asm("d0"); \
  register FLOAT __IEEESPDiv_dividend __asm("d0") = (_IEEESPDiv_dividend); \
  register FLOAT __IEEESPDiv_divisor __asm("d1") = (_IEEESPDiv_divisor); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__IEEESPDiv__re) \
  : "r"(__IEEESPDiv__bn), "r"(__IEEESPDiv_dividend), "r"(__IEEESPDiv_divisor) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPDiv__re; \
  }); \
  _IEEESPDiv__re; \
})

#define IEEESPFloor(parm) ({ \
  FLOAT _IEEESPFloor_parm = (parm); \
  FLOAT _IEEESPFloor__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPFloor__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register FLOAT __IEEESPFloor__re __asm("d0"); \
  register FLOAT __IEEESPFloor_parm __asm("d0") = (_IEEESPFloor_parm); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__IEEESPFloor__re) \
  : "r"(__IEEESPFloor__bn), "r"(__IEEESPFloor_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPFloor__re; \
  }); \
  _IEEESPFloor__re; \
})

#define IEEESPCeil(parm) ({ \
  FLOAT _IEEESPCeil_parm = (parm); \
  FLOAT _IEEESPCeil__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPCeil__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGBAS_BASE_NAME);\
  register FLOAT __IEEESPCeil__re __asm("d0"); \
  register FLOAT __IEEESPCeil_parm __asm("d0") = (_IEEESPCeil_parm); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__IEEESPCeil__re) \
  : "r"(__IEEESPCeil__bn), "r"(__IEEESPCeil_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPCeil__re; \
  }); \
  _IEEESPCeil__re; \
})

#endif /*  _INLINE_MATHIEEESINGBAS_H  */
