#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_MATHTRANS_H
#define _INLINE_MATHTRANS_H

#ifndef CLIB_MATHTRANS_PROTOS_H
#define CLIB_MATHTRANS_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef MATHTRANS_BASE_NAME
#define MATHTRANS_BASE_NAME MathTransBase
#endif

#define SPAtan(parm) ({ \
  FLOAT _SPAtan_parm = (parm); \
  FLOAT _SPAtan__re = \
  ({ \
  register struct Library * const __SPAtan__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPAtan__re __asm("d0"); \
  register FLOAT __SPAtan_parm __asm("d0") = (_SPAtan_parm); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__SPAtan__re) \
  : "r"(__SPAtan__bn), "r"(__SPAtan_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPAtan__re; \
  }); \
  _SPAtan__re; \
})

#define SPSin(parm) ({ \
  FLOAT _SPSin_parm = (parm); \
  FLOAT _SPSin__re = \
  ({ \
  register struct Library * const __SPSin__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPSin__re __asm("d0"); \
  register FLOAT __SPSin_parm __asm("d0") = (_SPSin_parm); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__SPSin__re) \
  : "r"(__SPSin__bn), "r"(__SPSin_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPSin__re; \
  }); \
  _SPSin__re; \
})

#define SPCos(parm) ({ \
  FLOAT _SPCos_parm = (parm); \
  FLOAT _SPCos__re = \
  ({ \
  register struct Library * const __SPCos__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPCos__re __asm("d0"); \
  register FLOAT __SPCos_parm __asm("d0") = (_SPCos_parm); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__SPCos__re) \
  : "r"(__SPCos__bn), "r"(__SPCos_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPCos__re; \
  }); \
  _SPCos__re; \
})

#define SPTan(parm) ({ \
  FLOAT _SPTan_parm = (parm); \
  FLOAT _SPTan__re = \
  ({ \
  register struct Library * const __SPTan__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPTan__re __asm("d0"); \
  register FLOAT __SPTan_parm __asm("d0") = (_SPTan_parm); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__SPTan__re) \
  : "r"(__SPTan__bn), "r"(__SPTan_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPTan__re; \
  }); \
  _SPTan__re; \
})

#define SPSincos(cosResult, parm) ({ \
  FLOAT * _SPSincos_cosResult = (cosResult); \
  FLOAT _SPSincos_parm = (parm); \
  FLOAT _SPSincos__re = \
  ({ \
  register struct Library * const __SPSincos__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPSincos__re __asm("d0"); \
  register FLOAT * __SPSincos_cosResult __asm("d1") = (_SPSincos_cosResult); \
  register FLOAT __SPSincos_parm __asm("d0") = (_SPSincos_parm); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__SPSincos__re) \
  : "r"(__SPSincos__bn), "r"(__SPSincos_cosResult), "r"(__SPSincos_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPSincos__re; \
  }); \
  _SPSincos__re; \
})

#define SPSinh(parm) ({ \
  FLOAT _SPSinh_parm = (parm); \
  FLOAT _SPSinh__re = \
  ({ \
  register struct Library * const __SPSinh__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPSinh__re __asm("d0"); \
  register FLOAT __SPSinh_parm __asm("d0") = (_SPSinh_parm); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__SPSinh__re) \
  : "r"(__SPSinh__bn), "r"(__SPSinh_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPSinh__re; \
  }); \
  _SPSinh__re; \
})

#define SPCosh(parm) ({ \
  FLOAT _SPCosh_parm = (parm); \
  FLOAT _SPCosh__re = \
  ({ \
  register struct Library * const __SPCosh__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPCosh__re __asm("d0"); \
  register FLOAT __SPCosh_parm __asm("d0") = (_SPCosh_parm); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__SPCosh__re) \
  : "r"(__SPCosh__bn), "r"(__SPCosh_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPCosh__re; \
  }); \
  _SPCosh__re; \
})

#define SPTanh(parm) ({ \
  FLOAT _SPTanh_parm = (parm); \
  FLOAT _SPTanh__re = \
  ({ \
  register struct Library * const __SPTanh__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPTanh__re __asm("d0"); \
  register FLOAT __SPTanh_parm __asm("d0") = (_SPTanh_parm); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__SPTanh__re) \
  : "r"(__SPTanh__bn), "r"(__SPTanh_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPTanh__re; \
  }); \
  _SPTanh__re; \
})

#define SPExp(parm) ({ \
  FLOAT _SPExp_parm = (parm); \
  FLOAT _SPExp__re = \
  ({ \
  register struct Library * const __SPExp__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPExp__re __asm("d0"); \
  register FLOAT __SPExp_parm __asm("d0") = (_SPExp_parm); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__SPExp__re) \
  : "r"(__SPExp__bn), "r"(__SPExp_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPExp__re; \
  }); \
  _SPExp__re; \
})

#define SPLog(parm) ({ \
  FLOAT _SPLog_parm = (parm); \
  FLOAT _SPLog__re = \
  ({ \
  register struct Library * const __SPLog__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPLog__re __asm("d0"); \
  register FLOAT __SPLog_parm __asm("d0") = (_SPLog_parm); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__SPLog__re) \
  : "r"(__SPLog__bn), "r"(__SPLog_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPLog__re; \
  }); \
  _SPLog__re; \
})

#define SPPow(power, arg) ({ \
  FLOAT _SPPow_power = (power); \
  FLOAT _SPPow_arg = (arg); \
  FLOAT _SPPow__re = \
  ({ \
  register struct Library * const __SPPow__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPPow__re __asm("d0"); \
  register FLOAT __SPPow_power __asm("d1") = (_SPPow_power); \
  register FLOAT __SPPow_arg __asm("d0") = (_SPPow_arg); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__SPPow__re) \
  : "r"(__SPPow__bn), "r"(__SPPow_power), "r"(__SPPow_arg) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPPow__re; \
  }); \
  _SPPow__re; \
})

#define SPSqrt(parm) ({ \
  FLOAT _SPSqrt_parm = (parm); \
  FLOAT _SPSqrt__re = \
  ({ \
  register struct Library * const __SPSqrt__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPSqrt__re __asm("d0"); \
  register FLOAT __SPSqrt_parm __asm("d0") = (_SPSqrt_parm); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__SPSqrt__re) \
  : "r"(__SPSqrt__bn), "r"(__SPSqrt_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPSqrt__re; \
  }); \
  _SPSqrt__re; \
})

#define SPTieee(parm) ({ \
  FLOAT _SPTieee_parm = (parm); \
  FLOAT _SPTieee__re = \
  ({ \
  register struct Library * const __SPTieee__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPTieee__re __asm("d0"); \
  register FLOAT __SPTieee_parm __asm("d0") = (_SPTieee_parm); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__SPTieee__re) \
  : "r"(__SPTieee__bn), "r"(__SPTieee_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPTieee__re; \
  }); \
  _SPTieee__re; \
})

#define SPFieee(parm) ({ \
  FLOAT _SPFieee_parm = (parm); \
  FLOAT _SPFieee__re = \
  ({ \
  register struct Library * const __SPFieee__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPFieee__re __asm("d0"); \
  register FLOAT __SPFieee_parm __asm("d0") = (_SPFieee_parm); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__SPFieee__re) \
  : "r"(__SPFieee__bn), "r"(__SPFieee_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPFieee__re; \
  }); \
  _SPFieee__re; \
})

#define SPAsin(parm) ({ \
  FLOAT _SPAsin_parm = (parm); \
  FLOAT _SPAsin__re = \
  ({ \
  register struct Library * const __SPAsin__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPAsin__re __asm("d0"); \
  register FLOAT __SPAsin_parm __asm("d0") = (_SPAsin_parm); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__SPAsin__re) \
  : "r"(__SPAsin__bn), "r"(__SPAsin_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPAsin__re; \
  }); \
  _SPAsin__re; \
})

#define SPAcos(parm) ({ \
  FLOAT _SPAcos_parm = (parm); \
  FLOAT _SPAcos__re = \
  ({ \
  register struct Library * const __SPAcos__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPAcos__re __asm("d0"); \
  register FLOAT __SPAcos_parm __asm("d0") = (_SPAcos_parm); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__SPAcos__re) \
  : "r"(__SPAcos__bn), "r"(__SPAcos_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPAcos__re; \
  }); \
  _SPAcos__re; \
})

#define SPLog10(parm) ({ \
  FLOAT _SPLog10_parm = (parm); \
  FLOAT _SPLog10__re = \
  ({ \
  register struct Library * const __SPLog10__bn __asm("a6") = (struct Library *) (MATHTRANS_BASE_NAME);\
  register FLOAT __SPLog10__re __asm("d0"); \
  register FLOAT __SPLog10_parm __asm("d0") = (_SPLog10_parm); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__SPLog10__re) \
  : "r"(__SPLog10__bn), "r"(__SPLog10_parm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPLog10__re; \
  }); \
  _SPLog10__re; \
})

#endif /*  _INLINE_MATHTRANS_H  */
