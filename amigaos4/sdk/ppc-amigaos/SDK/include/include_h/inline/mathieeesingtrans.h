#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_MATHIEEESINGTRANS_H
#define _INLINE_MATHIEEESINGTRANS_H

#ifndef CLIB_MATHIEEESINGTRANS_PROTOS_H
#define CLIB_MATHIEEESINGTRANS_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef MATHIEEESINGTRANS_BASE_NAME
#define MATHIEEESINGTRANS_BASE_NAME MathIeeeSingTransBase
#endif

#define IEEESPAtan(parm) ({ \
  FLOAT _IEEESPAtan_parm = (parm); \
  FLOAT _IEEESPAtan__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPAtan__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPAtan__re __asm("d0"); \
  register FLOAT __IEEESPAtan_parm __asm("d0") = (_IEEESPAtan_parm); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__IEEESPAtan__re) \
  : "r"(__IEEESPAtan__bn), "r"(__IEEESPAtan_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPAtan__re; \
  }); \
  _IEEESPAtan__re; \
})

#define IEEESPSin(parm) ({ \
  FLOAT _IEEESPSin_parm = (parm); \
  FLOAT _IEEESPSin__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPSin__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPSin__re __asm("d0"); \
  register FLOAT __IEEESPSin_parm __asm("d0") = (_IEEESPSin_parm); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__IEEESPSin__re) \
  : "r"(__IEEESPSin__bn), "r"(__IEEESPSin_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPSin__re; \
  }); \
  _IEEESPSin__re; \
})

#define IEEESPCos(parm) ({ \
  FLOAT _IEEESPCos_parm = (parm); \
  FLOAT _IEEESPCos__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPCos__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPCos__re __asm("d0"); \
  register FLOAT __IEEESPCos_parm __asm("d0") = (_IEEESPCos_parm); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__IEEESPCos__re) \
  : "r"(__IEEESPCos__bn), "r"(__IEEESPCos_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPCos__re; \
  }); \
  _IEEESPCos__re; \
})

#define IEEESPTan(parm) ({ \
  FLOAT _IEEESPTan_parm = (parm); \
  FLOAT _IEEESPTan__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPTan__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPTan__re __asm("d0"); \
  register FLOAT __IEEESPTan_parm __asm("d0") = (_IEEESPTan_parm); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__IEEESPTan__re) \
  : "r"(__IEEESPTan__bn), "r"(__IEEESPTan_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPTan__re; \
  }); \
  _IEEESPTan__re; \
})

#define IEEESPSincos(cosptr, parm) ({ \
  FLOAT * _IEEESPSincos_cosptr = (cosptr); \
  FLOAT _IEEESPSincos_parm = (parm); \
  FLOAT _IEEESPSincos__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPSincos__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPSincos__re __asm("d0"); \
  register FLOAT * __IEEESPSincos_cosptr __asm("a0") = (_IEEESPSincos_cosptr); \
  register FLOAT __IEEESPSincos_parm __asm("d0") = (_IEEESPSincos_parm); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__IEEESPSincos__re) \
  : "r"(__IEEESPSincos__bn), "r"(__IEEESPSincos_cosptr), "r"(__IEEESPSincos_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPSincos__re; \
  }); \
  _IEEESPSincos__re; \
})

#define IEEESPSinh(parm) ({ \
  FLOAT _IEEESPSinh_parm = (parm); \
  FLOAT _IEEESPSinh__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPSinh__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPSinh__re __asm("d0"); \
  register FLOAT __IEEESPSinh_parm __asm("d0") = (_IEEESPSinh_parm); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__IEEESPSinh__re) \
  : "r"(__IEEESPSinh__bn), "r"(__IEEESPSinh_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPSinh__re; \
  }); \
  _IEEESPSinh__re; \
})

#define IEEESPCosh(parm) ({ \
  FLOAT _IEEESPCosh_parm = (parm); \
  FLOAT _IEEESPCosh__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPCosh__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPCosh__re __asm("d0"); \
  register FLOAT __IEEESPCosh_parm __asm("d0") = (_IEEESPCosh_parm); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__IEEESPCosh__re) \
  : "r"(__IEEESPCosh__bn), "r"(__IEEESPCosh_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPCosh__re; \
  }); \
  _IEEESPCosh__re; \
})

#define IEEESPTanh(parm) ({ \
  FLOAT _IEEESPTanh_parm = (parm); \
  FLOAT _IEEESPTanh__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPTanh__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPTanh__re __asm("d0"); \
  register FLOAT __IEEESPTanh_parm __asm("d0") = (_IEEESPTanh_parm); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__IEEESPTanh__re) \
  : "r"(__IEEESPTanh__bn), "r"(__IEEESPTanh_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPTanh__re; \
  }); \
  _IEEESPTanh__re; \
})

#define IEEESPExp(parm) ({ \
  FLOAT _IEEESPExp_parm = (parm); \
  FLOAT _IEEESPExp__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPExp__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPExp__re __asm("d0"); \
  register FLOAT __IEEESPExp_parm __asm("d0") = (_IEEESPExp_parm); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__IEEESPExp__re) \
  : "r"(__IEEESPExp__bn), "r"(__IEEESPExp_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPExp__re; \
  }); \
  _IEEESPExp__re; \
})

#define IEEESPLog(parm) ({ \
  FLOAT _IEEESPLog_parm = (parm); \
  FLOAT _IEEESPLog__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPLog__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPLog__re __asm("d0"); \
  register FLOAT __IEEESPLog_parm __asm("d0") = (_IEEESPLog_parm); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__IEEESPLog__re) \
  : "r"(__IEEESPLog__bn), "r"(__IEEESPLog_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPLog__re; \
  }); \
  _IEEESPLog__re; \
})

#define IEEESPPow(exp, arg) ({ \
  FLOAT _IEEESPPow_exp = (exp); \
  FLOAT _IEEESPPow_arg = (arg); \
  FLOAT _IEEESPPow__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPPow__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPPow__re __asm("d0"); \
  register FLOAT __IEEESPPow_exp __asm("d1") = (_IEEESPPow_exp); \
  register FLOAT __IEEESPPow_arg __asm("d0") = (_IEEESPPow_arg); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__IEEESPPow__re) \
  : "r"(__IEEESPPow__bn), "r"(__IEEESPPow_exp), "r"(__IEEESPPow_arg) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPPow__re; \
  }); \
  _IEEESPPow__re; \
})

#define IEEESPSqrt(parm) ({ \
  FLOAT _IEEESPSqrt_parm = (parm); \
  FLOAT _IEEESPSqrt__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPSqrt__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPSqrt__re __asm("d0"); \
  register FLOAT __IEEESPSqrt_parm __asm("d0") = (_IEEESPSqrt_parm); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__IEEESPSqrt__re) \
  : "r"(__IEEESPSqrt__bn), "r"(__IEEESPSqrt_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPSqrt__re; \
  }); \
  _IEEESPSqrt__re; \
})

#define IEEESPTieee(parm) ({ \
  FLOAT _IEEESPTieee_parm = (parm); \
  FLOAT _IEEESPTieee__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPTieee__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPTieee__re __asm("d0"); \
  register FLOAT __IEEESPTieee_parm __asm("d0") = (_IEEESPTieee_parm); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__IEEESPTieee__re) \
  : "r"(__IEEESPTieee__bn), "r"(__IEEESPTieee_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPTieee__re; \
  }); \
  _IEEESPTieee__re; \
})

#define IEEESPFieee(parm) ({ \
  FLOAT _IEEESPFieee_parm = (parm); \
  FLOAT _IEEESPFieee__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPFieee__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPFieee__re __asm("d0"); \
  register FLOAT __IEEESPFieee_parm __asm("d0") = (_IEEESPFieee_parm); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__IEEESPFieee__re) \
  : "r"(__IEEESPFieee__bn), "r"(__IEEESPFieee_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPFieee__re; \
  }); \
  _IEEESPFieee__re; \
})

#define IEEESPAsin(parm) ({ \
  FLOAT _IEEESPAsin_parm = (parm); \
  FLOAT _IEEESPAsin__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPAsin__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPAsin__re __asm("d0"); \
  register FLOAT __IEEESPAsin_parm __asm("d0") = (_IEEESPAsin_parm); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__IEEESPAsin__re) \
  : "r"(__IEEESPAsin__bn), "r"(__IEEESPAsin_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPAsin__re; \
  }); \
  _IEEESPAsin__re; \
})

#define IEEESPAcos(parm) ({ \
  FLOAT _IEEESPAcos_parm = (parm); \
  FLOAT _IEEESPAcos__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPAcos__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPAcos__re __asm("d0"); \
  register FLOAT __IEEESPAcos_parm __asm("d0") = (_IEEESPAcos_parm); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__IEEESPAcos__re) \
  : "r"(__IEEESPAcos__bn), "r"(__IEEESPAcos_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPAcos__re; \
  }); \
  _IEEESPAcos__re; \
})

#define IEEESPLog10(parm) ({ \
  FLOAT _IEEESPLog10_parm = (parm); \
  FLOAT _IEEESPLog10__re = \
  ({ \
  register struct MathIEEEBase * const __IEEESPLog10__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEESINGTRANS_BASE_NAME);\
  register FLOAT __IEEESPLog10__re __asm("d0"); \
  register FLOAT __IEEESPLog10_parm __asm("d0") = (_IEEESPLog10_parm); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__IEEESPLog10__re) \
  : "r"(__IEEESPLog10__bn), "r"(__IEEESPLog10_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEESPLog10__re; \
  }); \
  _IEEESPLog10__re; \
})

#endif /*  _INLINE_MATHIEEESINGTRANS_H  */
