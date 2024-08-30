#ifndef __DECLGATE_H__
#define __DECLGATE_H__

/* Transparent MorphOS gate function macros

   Written by Harry "Piru" Sintonen, 2000-2001.
   Modified and extended by Chris Hodges, 2002.
   Public Domain.
*/
#ifdef __MORPHOS__
#  include <exec/types.h>
#  include <emul/emulregs.h>
#  include <emul/emulinterface.h>

#  define REG_a0 REG_A0
#  define REG_a1 REG_A1
#  define REG_a2 REG_A2
#  define REG_a3 REG_A3
#  define REG_a4 REG_A4
#  define REG_a5 REG_A5
#  define REG_a6 REG_A6
#  define REG_a7 REG_A7
#  define REG_d0 REG_D0
#  define REG_d1 REG_D1
#  define REG_d2 REG_D2
#  define REG_d3 REG_D3
#  define REG_d4 REG_D4
#  define REG_d5 REG_D5
#  define REG_d6 REG_D6
#  define REG_d7 REG_D7

#define LVOENTRY(func) (ULONG) stub_ ## func,

#define DECLGATE(t, fn, rt) \
t struct EmulLibEntry fn = {TRAP_ ## rt, 0, (void (*)(void)) _ ## fn};
#define DECLFUNC_0(fn) _ ## fn(void)
#define DECLFUNC_1(fn, r1, t1, n1) _ ## fn(void)
#define DECLFUNC_2(fn, r1, t1, n1, r2, t2, n2) _ ## fn(void)
#define DECLFUNC_3(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3) _ ## fn(void)
#define DECLFUNC_4(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) _ ## fn(void)
#define DECLFUNC_5(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) _ ## fn(void)
#define DECLFUNC_6(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) _ ## fn(void)
#define DECLFUNC_7(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) _ ## fn(void)
#define DECLFUNC_8(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) _ ## fn(void)

#define NATDECLGATE(t, fn, rt)
#define NATDECLFUNC_1(fn, r1, t1, n1) stub_ ## fn(void)
#define NATDECLFUNC_2(fn, r1, t1, n1, r2, t2, n2) stub_ ## fn(void)
#define NATDECLFUNC_3(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3) stub_ ## fn(void)
#define NATDECLFUNC_4(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) stub_ ## fn(void)
#define NATDECLFUNC_5(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) stub_ ## fn(void)
#define NATDECLFUNC_6(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) stub_ ## fn(void)
#define NATDECLFUNC_7(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) stub_ ## fn(void)
#define NATDECLFUNC_8(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) stub_ ## fn(void)

#define DEFDECLFUNC_1(r, fn, r1, t1, n1) r stub_ ## fn(void); r fn(t1 n1)
#define DEFDECLFUNC_2(r, fn, r1, t1, n1, r2, t2, n2) r stub_ ## fn(void); r fn(t1 n1, t2 n2)
#define DEFDECLFUNC_3(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3) r stub_ ## fn(void); r fn(t1 n1, t2 n2, t3 n3)
#define DEFDECLFUNC_4(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) r stub_ ## fn(void); r fn(t1 n1, t2 n2, t3 n3, t4 n4)
#define DEFDECLFUNC_5(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) r stub_ ## fn(void); r fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5)
#define DEFDECLFUNC_6(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) r stub_ ## fn(void); r fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5, t6 n6)
#define DEFDECLFUNC_7(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) r stub_ ## fn(void); r fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5, t6 n6, t7 n7)
#define DEFDECLFUNC_8(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) r stub_ ## fn(void); r fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5, t6 n6, t7 n7, t8 n8)

#define STUBDECLFUNC_1(r, fn, r1, t1, n1) \
  r stub_ ## fn(void) { return(fn((t1) REG_ ## r1)); } \
  r fn(t1 n1)
#define STUBDECLFUNC_2(r, fn, r1, t1, n1, r2, t2, n2) \
  r stub_ ## fn(void) { return(fn((t1) REG_ ## r1, (t2) REG_ ## r2)); } \
  r fn(t1 n1, t2 n2)
#define STUBDECLFUNC_3(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3) \
  r stub_ ## fn(void) { return(fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3)); } \
  r fn(t1 n1, t2 n2, t3 n3)
#define STUBDECLFUNC_4(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) \
  r stub_ ## fn(void) { return(fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3, (t4) REG_ ## r4)); } \
  r fn(t1 n1, t2 n2, t3 n3, t4 n4)
#define STUBDECLFUNC_5(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) \
  r stub_ ## fn(void) { return(fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3, (t4) REG_ ## r4, (t5) REG_ ## r5)); } \
  r fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5)
#define STUBDECLFUNC_6(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) \
  r stub_ ## fn(void) { return(fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3, (t4) REG_ ## r4, (t5) REG_ ## r5, (t6) REG_ ## r6)); } \
  r fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5, t6 n6)
#define STUBDECLFUNC_7(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) \
  r stub_ ## fn(void) { return(fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3, (t4) REG_ ## r4, (t5) REG_ ## r5, (t6) REG_ ## r6, (t7) REG_ ## r7)); } \
  r fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5, t6 n6, t7 n7)
#define STUBDECLFUNC_8(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) \
  r stub_ ## fn(void) { return(fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3, (t4) REG_ ## r4, (t5) REG_ ## r5, (t6) REG_ ## r6, (t7) REG_ ## r7, (t8) REG_ ## r8)); } \
  r fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5, t6 n6, t7 n7, t8 n8)

#define VSTUBDECLFUNC_1(fn, r1, t1, n1) \
  stub_ ## fn(void) { fn((t1) REG_ ## r1); } \
  void fn(t1 n1)
#define VSTUBDECLFUNC_2(fn, r1, t1, n1, r2, t2, n2) \
  stub_ ## fn(void) { fn((t1) REG_ ## r1, (t2) REG_ ## r2); } \
  void fn(t1 n1, t2 n2)
#define VSTUBDECLFUNC_3(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3) \
  stub_ ## fn(void) { fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3); } \
  void fn(t1 n1, t2 n2, t3 n3)
#define VSTUBDECLFUNC_4(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) \
  stub_ ## fn(void) { fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3, (t4) REG_ ## r4); } \
  void fn(t1 n1, t2 n2, t3 n3, t4 n4)
#define VSTUBDECLFUNC_5(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) \
  stub_ ## fn(void) { fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3, (t4) REG_ ## r4, (t5) REG_ ## r5); } \
  void fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5)
#define VSTUBDECLFUNC_6(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) \
  stub_ ## fn(void) { fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3, (t4) REG_ ## r4, (t5) REG_ ## r5, (t6) REG_ ## r6); } \
  void fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5, t6 n6)
#define VSTUBDECLFUNC_7(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) \
  stub_ ## fn(void) { fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3, (t4) REG_ ## r4, (t5) REG_ ## r5, (t6) REG_ ## r6, (t7) REG_ ## r7); } \
  void fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5, t6 n6, t7 n7)
#define VSTUBDECLFUNC_8(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) \
  stub_ ## fn(void) { fn((t1) REG_ ## r1, (t2) REG_ ## r2, (t3) REG_ ## r3, (t4) REG_ ## r4, (t5) REG_ ## r5, (t6) REG_ ## r6, (t7) REG_ ## r7, (t8) REG_ ## r8); } \
  void fn(t1 n1, t2 n2, t3 n3, t4 n4, t5 n5, t6 n6, t7 n7, t8 n8)


#define DECLARG_1(r1, t1, n1) \
  t1 n1 = (t1) REG_ ## r1;

#define DECLARG_2(r1, t1, n1, r2, t2, n2) \
  t1 n1 = (t1) REG_ ## r1; \
  t2 n2 = (t2) REG_ ## r2;

#define DECLARG_3(r1, t1, n1, r2, t2, n2, r3, t3, n3) \
  t1 n1 = (t1) REG_ ## r1; \
  t2 n2 = (t2) REG_ ## r2; \
  t3 n3 = (t3) REG_ ## r3;

#define DECLARG_4(r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) \
  t1 n1 = (t1) REG_ ## r1; \
  t2 n2 = (t2) REG_ ## r2; \
  t3 n3 = (t3) REG_ ## r3; \
  t4 n4 = (t4) REG_ ## r4;

#define DECLARG_5(r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) \
  t1 n1 = (t1) REG_ ## r1; \
  t2 n2 = (t2) REG_ ## r2; \
  t3 n3 = (t3) REG_ ## r3; \
  t4 n4 = (t4) REG_ ## r4; \
  t5 n5 = (t5) REG_ ## r5;

#define DECLARG_6(r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) \
  t1 n1 = (t1) REG_ ## r1; \
  t2 n2 = (t2) REG_ ## r2; \
  t3 n3 = (t3) REG_ ## r3; \
  t4 n4 = (t4) REG_ ## r4; \
  t5 n5 = (t5) REG_ ## r5; \
  t6 n6 = (t6) REG_ ## r6;

#define DECLARG_7(r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) \
  t1 n1 = (t1) REG_ ## r1; \
  t2 n2 = (t2) REG_ ## r2; \
  t3 n3 = (t3) REG_ ## r3; \
  t4 n4 = (t4) REG_ ## r4; \
  t5 n5 = (t5) REG_ ## r5; \
  t6 n6 = (t6) REG_ ## r6; \
  t7 n7 = (t7) REG_ ## r7;

#define DECLARG_8(r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) \
  t1 n1 = (t1) REG_ ## r1; \
  t2 n2 = (t2) REG_ ## r2; \
  t3 n3 = (t3) REG_ ## r3; \
  t4 n4 = (t4) REG_ ## r4; \
  t5 n5 = (t5) REG_ ## r5; \
  t6 n6 = (t6) REG_ ## r6; \
  t7 n7 = (t7) REG_ ## r7; \
  t8 n8 = (t8) REG_ ## r8;

#else /* __MORPHOS__ */

#include "myregargs.h"

#define LVOENTRY(func) (ULONG) func,

#define DECLARG_1(r1, t1, n1)
#define DECLARG_2(r1, t1, n1, r2, t2, n2)
#define DECLARG_3(r1, t1, n1, r2, t2, n2, r3, t3, n3)
#define DECLARG_4(r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4)
#define DECLARG_5(r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5)
#define DECLARG_6(r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6)
#define DECLARG_7(r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7)
#define DECLARG_8(r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8)

#define DECLGATE(t, fn, rt)

#define DECLFUNC_0(fn) \
  MASM fn(void)
#define DECLFUNC_1(fn, r1, t1, n1) \
  MASM fn(MREG(r1, t1 n1))
#define DECLFUNC_2(fn, r1, t1, n1, r2, t2, n2) \
  MASM fn(MREG(r1, t1 n1), MREG(r2, t2 n2))
#define DECLFUNC_3(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3) \
  MASM fn(MREG(r1, t1 n1), MREG(r2, t2 n2), MREG(r3, t3 n3))
#define DECLFUNC_4(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) \
  MASM fn(MREG(r1, t1 n1), MREG(r2, t2 n2), MREG(r3, t3 n3), MREG(r4, t4 n4))
#define DECLFUNC_5(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) \
  MASM fn(MREG(r1, t1 n1), MREG(r2, t2 n2), MREG(r3, t3 n3), MREG(r4, t4 n4), MREG(r5, t5 n5))
#define DECLFUNC_6(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) \
  MASM fn(MREG(r1, t1 n1), MREG(r2, t2 n2), MREG(r3, t3 n3), MREG(r4, t4 n4), MREG(r5, t5 n5), MREG(r6, t6 n6))
#define DECLFUNC_7(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) \
  MASM fn(MREG(r1, t1 n1), MREG(r2, t2 n2), MREG(r3, t3 n3), MREG(r4, t4 n4), MREG(r5, t5 n5), MREG(r6, t6 n6), MREG(r7, t7 n7))
#define DECLFUNC_8(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) \
  MASM fn(MREG(r1, t1 n1), MREG(r2, t2 n2), MREG(r3, t3 n3), MREG(r4, t4 n4), MREG(r5, t5 n5), MREG(r6, t6 n6), MREG(r7, t7 n7), MREG(r8, t8 n8))

#define NATDECLGATE(t, fn, rt)

#define NATDECLFUNC_1(fn, r1, t1, n1) \
  DECLFUNC_1(fn, r1, t1, n1)
#define NATDECLFUNC_2(fn, r1, t1, n1, r2, t2, n2) \
  DECLFUNC_2(fn, r1, t1, n1, r2, t2, n2)
#define NATDECLFUNC_3(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3) \
  DECLFUNC_3(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3)
#define NATDECLFUNC_4(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) \
  DECLFUNC_4(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4)
#define NATDECLFUNC_5(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) \
  DECLFUNC_5(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5)
#define NATDECLFUNC_6(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) \
  DECLFUNC_6(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6)
#define NATDECLFUNC_7(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) \
  DECLFUNC_7(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7)
#define NATDECLFUNC_8(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) \
  DECLFUNC_8(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8)

#define DEFDECLFUNC_1(r, fn, r1, t1, n1) \
  r DECLFUNC_1(fn, r1, t1, n1)
#define DEFDECLFUNC_2(r, fn, r1, t1, n1, r2, t2, n2) \
  r DECLFUNC_2(fn, r1, t1, n1, r2, t2, n2)
#define DEFDECLFUNC_3(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3) \
  r DECLFUNC_3(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3)
#define DEFDECLFUNC_4(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) \
  r DECLFUNC_4(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4)
#define DEFDECLFUNC_5(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) \
  r DECLFUNC_5(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5)
#define DEFDECLFUNC_6(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) \
  r DECLFUNC_6(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6)
#define DEFDECLFUNC_7(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) \
  r DECLFUNC_7(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7)
#define DEFDECLFUNC_8(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) \
  r DECLFUNC_8(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8)

#define STUBDECLFUNC_1(r, fn, r1, t1, n1) \
  r DECLFUNC_1(fn, r1, t1, n1)
#define STUBDECLFUNC_2(r, fn, r1, t1, n1, r2, t2, n2) \
  r DECLFUNC_2(fn, r1, t1, n1, r2, t2, n2)
#define STUBDECLFUNC_3(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3) \
  r DECLFUNC_3(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3)
#define STUBDECLFUNC_4(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) \
  r DECLFUNC_4(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4)
#define STUBDECLFUNC_5(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) \
  r DECLFUNC_5(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5)
#define STUBDECLFUNC_6(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) \
  r DECLFUNC_6(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6)
#define STUBDECLFUNC_7(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) \
  r DECLFUNC_7(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7)
#define STUBDECLFUNC_8(r, fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) \
  r DECLFUNC_8(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8)

#define VSTUBDECLFUNC_1(fn, r1, t1, n1) \
  DECLFUNC_1(fn, r1, t1, n1)
#define VSTUBDECLFUNC_2(fn, r1, t1, n1, r2, t2, n2) \
  DECLFUNC_2(fn, r1, t1, n1, r2, t2, n2)
#define VSTUBDECLFUNC_3(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3) \
  DECLFUNC_3(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3)
#define VSTUBDECLFUNC_4(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4) \
  DECLFUNC_4(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4)
#define VSTUBDECLFUNC_5(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5) \
  DECLFUNC_5(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5)
#define VSTUBDECLFUNC_6(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6) \
  DECLFUNC_6(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6)
#define VSTUBDECLFUNC_7(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7) \
  DECLFUNC_7(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7)
#define VSTUBDECLFUNC_8(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8) \
  DECLFUNC_8(fn, r1, t1, n1, r2, t2, n2, r3, t3, n3, r4, t4, n4, r5, t5, n5, r6, t6, n6, r7, t7, n7, r8, t8, n8)


#endif /* __MORPHOS__ */

#endif /* __DECLGATE_H__ */
