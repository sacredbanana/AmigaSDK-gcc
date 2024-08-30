#ifndef EMUL_EMULREGS_H
#define EMUL_EMULREGS_H

#ifndef EMUL_EMULINTERFACE_H
#include <emul/emulinterface.h>
#endif

#ifdef __VBCC__
__regsused("r2") __varsused("") __varsmodified("") __alwaysreturn __nosidefx
  __reg("r2") struct EmulHandle *__getEmulHandle(void) = "";
#define MyEmulHandle __getEmulHandle()

#ifdef EMUL_QUICKMODE
#error EMUL_QUICKMODE is not supported with VBCC!
#endif
#else   /* __VBCC__ */
register struct EmulHandle *MyEmulHandle __asm("r2");
#endif

#ifdef EMUL_QUICKMODE
register ULONG *REG_PC __asm("r13");
register UWORD  REG_SR __asm("r14");
register void (**OPCODETABLE)(void)     __asm("r15");

register ULONG  REG_D0 __asm("r16");
register ULONG  REG_D1 __asm("r17");
register ULONG  REG_D2 __asm("r18");
register ULONG  REG_D3 __asm("r19");
register ULONG  REG_D4 __asm("r20");
register ULONG  REG_D5 __asm("r21");
register ULONG  REG_D6 __asm("r22");
register ULONG  REG_D7 __asm("r23");
register ULONG  REG_A0 __asm("r24");
register ULONG  REG_A1 __asm("r25");
register ULONG  REG_A2 __asm("r26");
register ULONG  REG_A3 __asm("r27");
register ULONG  REG_A4 __asm("r28");
register ULONG  REG_A5 __asm("r29");
register ULONG  REG_A6 __asm("r30");
register ULONG  REG_A7 __asm("r31");
#else

#define REG_PC  (MyEmulHandle->PC)
#define REG_SR  (MyEmulHandle->SR)

#define REG_D0  (MyEmulHandle->Dn[0])
#define REG_D1  (MyEmulHandle->Dn[1])
#define REG_D2  (MyEmulHandle->Dn[2])
#define REG_D3  (MyEmulHandle->Dn[3])
#define REG_D4  (MyEmulHandle->Dn[4])
#define REG_D5  (MyEmulHandle->Dn[5])
#define REG_D6  (MyEmulHandle->Dn[6])
#define REG_D7  (MyEmulHandle->Dn[7])
#define REG_A0  (MyEmulHandle->An[0])
#define REG_A1  (MyEmulHandle->An[1])
#define REG_A2  (MyEmulHandle->An[2])
#define REG_A3  (MyEmulHandle->An[3])
#define REG_A4  (MyEmulHandle->An[4])
#define REG_A5  (MyEmulHandle->An[5])
#define REG_A6  (MyEmulHandle->An[6])
#define REG_A7  (MyEmulHandle->An[7])

#endif

#endif
