/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_MATHFFP_H
#define _INLINE_MATHFFP_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

LONG __SPFix(__reg("a6") struct Library * , __reg("d0") FLOAT parm ) = "\tjsr\t-30(a6)";
#define SPFix(parm) __SPFix(MathBase, (parm))

FLOAT __SPFlt(__reg("a6") struct Library * , __reg("d0") LONG integer ) = "\tjsr\t-36(a6)";
#define SPFlt(integer) __SPFlt(MathBase, (integer))

LONG __SPCmp(__reg("a6") struct Library * , __reg("d1") FLOAT leftParm , __reg("d0") FLOAT rightParm ) = "\tjsr\t-42(a6)";
#define SPCmp(leftParm, rightParm) __SPCmp(MathBase, (leftParm), (rightParm))

LONG __SPTst(__reg("a6") struct Library * , __reg("d1") FLOAT parm ) = "\tjsr\t-48(a6)";
#define SPTst(parm) __SPTst(MathBase, (parm))

FLOAT __SPAbs(__reg("a6") struct Library * , __reg("d0") FLOAT parm ) = "\tjsr\t-54(a6)";
#define SPAbs(parm) __SPAbs(MathBase, (parm))

FLOAT __SPNeg(__reg("a6") struct Library * , __reg("d0") FLOAT parm ) = "\tjsr\t-60(a6)";
#define SPNeg(parm) __SPNeg(MathBase, (parm))

FLOAT __SPAdd(__reg("a6") struct Library * , __reg("d1") FLOAT leftParm , __reg("d0") FLOAT rightParm ) = "\tjsr\t-66(a6)";
#define SPAdd(leftParm, rightParm) __SPAdd(MathBase, (leftParm), (rightParm))

FLOAT __SPSub(__reg("a6") struct Library * , __reg("d1") FLOAT leftParm , __reg("d0") FLOAT rightParm ) = "\tjsr\t-72(a6)";
#define SPSub(leftParm, rightParm) __SPSub(MathBase, (leftParm), (rightParm))

FLOAT __SPMul(__reg("a6") struct Library * , __reg("d1") FLOAT leftParm , __reg("d0") FLOAT rightParm ) = "\tjsr\t-78(a6)";
#define SPMul(leftParm, rightParm) __SPMul(MathBase, (leftParm), (rightParm))

FLOAT __SPDiv(__reg("a6") struct Library * , __reg("d1") FLOAT leftParm , __reg("d0") FLOAT rightParm ) = "\tjsr\t-84(a6)";
#define SPDiv(leftParm, rightParm) __SPDiv(MathBase, (leftParm), (rightParm))

FLOAT __SPFloor(__reg("a6") struct Library * , __reg("d0") FLOAT parm ) = "\tjsr\t-90(a6)";
#define SPFloor(parm) __SPFloor(MathBase, (parm))

FLOAT __SPCeil(__reg("a6") struct Library * , __reg("d0") FLOAT parm ) = "\tjsr\t-96(a6)";
#define SPCeil(parm) __SPCeil(MathBase, (parm))

#endif /* !_INLINE_MATHFFP_H */
