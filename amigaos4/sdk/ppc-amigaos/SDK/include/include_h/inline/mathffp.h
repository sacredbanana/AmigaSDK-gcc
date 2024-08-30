#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_MATHFFP_H
#define _INLINE_MATHFFP_H

#ifndef CLIB_MATHFFP_PROTOS_H
#define CLIB_MATHFFP_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef MATHFFP_BASE_NAME
#define MATHFFP_BASE_NAME MathBase
#endif

#define SPFix(parm) ({ \
  FLOAT _SPFix_parm = (parm); \
  LONG _SPFix__re = \
  ({ \
  register struct Library * const __SPFix__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register LONG __SPFix__re __asm("d0"); \
  register FLOAT __SPFix_parm __asm("d0") = (_SPFix_parm); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__SPFix__re) \
  : "r"(__SPFix__bn), "r"(__SPFix_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPFix__re; \
  }); \
  _SPFix__re; \
})

#define SPFlt(integer) ({ \
  LONG _SPFlt_integer = (integer); \
  FLOAT _SPFlt__re = \
  ({ \
  register struct Library * const __SPFlt__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register FLOAT __SPFlt__re __asm("d0"); \
  register LONG __SPFlt_integer __asm("d0") = (_SPFlt_integer); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__SPFlt__re) \
  : "r"(__SPFlt__bn), "r"(__SPFlt_integer) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPFlt__re; \
  }); \
  _SPFlt__re; \
})

#define SPCmp(leftParm, rightParm) ({ \
  FLOAT _SPCmp_leftParm = (leftParm); \
  FLOAT _SPCmp_rightParm = (rightParm); \
  LONG _SPCmp__re = \
  ({ \
  register struct Library * const __SPCmp__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register LONG __SPCmp__re __asm("d0"); \
  register FLOAT __SPCmp_leftParm __asm("d1") = (_SPCmp_leftParm); \
  register FLOAT __SPCmp_rightParm __asm("d0") = (_SPCmp_rightParm); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__SPCmp__re) \
  : "r"(__SPCmp__bn), "r"(__SPCmp_leftParm), "r"(__SPCmp_rightParm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPCmp__re; \
  }); \
  _SPCmp__re; \
})

#define SPTst(parm) ({ \
  FLOAT _SPTst_parm = (parm); \
  LONG _SPTst__re = \
  ({ \
  register struct Library * const __SPTst__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register LONG __SPTst__re __asm("d0"); \
  register FLOAT __SPTst_parm __asm("d1") = (_SPTst_parm); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__SPTst__re) \
  : "r"(__SPTst__bn), "r"(__SPTst_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPTst__re; \
  }); \
  _SPTst__re; \
})

#define SPAbs(parm) ({ \
  FLOAT _SPAbs_parm = (parm); \
  FLOAT _SPAbs__re = \
  ({ \
  register struct Library * const __SPAbs__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register FLOAT __SPAbs__re __asm("d0"); \
  register FLOAT __SPAbs_parm __asm("d0") = (_SPAbs_parm); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__SPAbs__re) \
  : "r"(__SPAbs__bn), "r"(__SPAbs_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPAbs__re; \
  }); \
  _SPAbs__re; \
})

#define SPNeg(parm) ({ \
  FLOAT _SPNeg_parm = (parm); \
  FLOAT _SPNeg__re = \
  ({ \
  register struct Library * const __SPNeg__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register FLOAT __SPNeg__re __asm("d0"); \
  register FLOAT __SPNeg_parm __asm("d0") = (_SPNeg_parm); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__SPNeg__re) \
  : "r"(__SPNeg__bn), "r"(__SPNeg_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPNeg__re; \
  }); \
  _SPNeg__re; \
})

#define SPAdd(leftParm, rightParm) ({ \
  FLOAT _SPAdd_leftParm = (leftParm); \
  FLOAT _SPAdd_rightParm = (rightParm); \
  FLOAT _SPAdd__re = \
  ({ \
  register struct Library * const __SPAdd__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register FLOAT __SPAdd__re __asm("d0"); \
  register FLOAT __SPAdd_leftParm __asm("d1") = (_SPAdd_leftParm); \
  register FLOAT __SPAdd_rightParm __asm("d0") = (_SPAdd_rightParm); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__SPAdd__re) \
  : "r"(__SPAdd__bn), "r"(__SPAdd_leftParm), "r"(__SPAdd_rightParm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPAdd__re; \
  }); \
  _SPAdd__re; \
})

#define SPSub(leftParm, rightParm) ({ \
  FLOAT _SPSub_leftParm = (leftParm); \
  FLOAT _SPSub_rightParm = (rightParm); \
  FLOAT _SPSub__re = \
  ({ \
  register struct Library * const __SPSub__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register FLOAT __SPSub__re __asm("d0"); \
  register FLOAT __SPSub_leftParm __asm("d1") = (_SPSub_leftParm); \
  register FLOAT __SPSub_rightParm __asm("d0") = (_SPSub_rightParm); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__SPSub__re) \
  : "r"(__SPSub__bn), "r"(__SPSub_leftParm), "r"(__SPSub_rightParm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPSub__re; \
  }); \
  _SPSub__re; \
})

#define SPMul(leftParm, rightParm) ({ \
  FLOAT _SPMul_leftParm = (leftParm); \
  FLOAT _SPMul_rightParm = (rightParm); \
  FLOAT _SPMul__re = \
  ({ \
  register struct Library * const __SPMul__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register FLOAT __SPMul__re __asm("d0"); \
  register FLOAT __SPMul_leftParm __asm("d1") = (_SPMul_leftParm); \
  register FLOAT __SPMul_rightParm __asm("d0") = (_SPMul_rightParm); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__SPMul__re) \
  : "r"(__SPMul__bn), "r"(__SPMul_leftParm), "r"(__SPMul_rightParm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPMul__re; \
  }); \
  _SPMul__re; \
})

#define SPDiv(leftParm, rightParm) ({ \
  FLOAT _SPDiv_leftParm = (leftParm); \
  FLOAT _SPDiv_rightParm = (rightParm); \
  FLOAT _SPDiv__re = \
  ({ \
  register struct Library * const __SPDiv__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register FLOAT __SPDiv__re __asm("d0"); \
  register FLOAT __SPDiv_leftParm __asm("d1") = (_SPDiv_leftParm); \
  register FLOAT __SPDiv_rightParm __asm("d0") = (_SPDiv_rightParm); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__SPDiv__re) \
  : "r"(__SPDiv__bn), "r"(__SPDiv_leftParm), "r"(__SPDiv_rightParm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPDiv__re; \
  }); \
  _SPDiv__re; \
})

#define SPFloor(parm) ({ \
  FLOAT _SPFloor_parm = (parm); \
  FLOAT _SPFloor__re = \
  ({ \
  register struct Library * const __SPFloor__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register FLOAT __SPFloor__re __asm("d0"); \
  register FLOAT __SPFloor_parm __asm("d0") = (_SPFloor_parm); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__SPFloor__re) \
  : "r"(__SPFloor__bn), "r"(__SPFloor_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPFloor__re; \
  }); \
  _SPFloor__re; \
})

#define SPCeil(parm) ({ \
  FLOAT _SPCeil_parm = (parm); \
  FLOAT _SPCeil__re = \
  ({ \
  register struct Library * const __SPCeil__bn __asm("a6") = (struct Library *) (MATHFFP_BASE_NAME);\
  register FLOAT __SPCeil__re __asm("d0"); \
  register FLOAT __SPCeil_parm __asm("d0") = (_SPCeil_parm); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__SPCeil__re) \
  : "r"(__SPCeil__bn), "r"(__SPCeil_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPCeil__re; \
  }); \
  _SPCeil__re; \
})

#endif /*  _INLINE_MATHFFP_H  */
