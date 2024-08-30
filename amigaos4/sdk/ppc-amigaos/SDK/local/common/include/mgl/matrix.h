/*
 * $Id: matrix.h 399 2009-11-30 03:01:40Z HansR $
 *
 * $Date: 2009-11-30 06:01:40 +0300 (Mon, 30 Nov 2009) $
 * $Revision: 399 $
 *
 * (C) 1999 by Hyperion
 * All rights reserved
 *
 * This file is part of the MiniGL library project
 * See the file Licence.txt for more details
 *
 */

#ifndef _MATRIX_H
#define _MATRIX_H

#define ALIGNED16 __attribute__((aligned(16)))

#if defined(__VEC__)

#define LOAD_ALIGNED_MATRIX(m, vm1, vm2, vm3, vm4) \
{                                \
	vm1 = vec_ld(0, (float*)m);  \
	vm2 = vec_ld(16, (float*)m); \
	vm3 = vec_ld(32, (float*)m); \
	vm4 = vec_ld(48, (float*)m); \
}

#define STORE_ALIGNED_MATRIX(m, vm1, vm2, vm3, vm4) \
{                               \
	vec_st(vm1, 0, (float*)m);  \
	vec_st(vm2, 16, (float*)m); \
	vec_st(vm3, 32, (float*)m); \
	vec_st(vm4, 48, (float*)m); \
}

#define LOAD_UNALIGNED_MATRIX(m, vm1, vm2, vm3, vm4) \
{ \
	vector float MSQ, LSQ; \
	vector unsigned char mask; \
	MSQ = vec_ld(0, (float*)m); \
	LSQ = vec_ld(15, (float*)m); \
	mask = vec_lvsl(0, (float*)m); \
	vm1 = vec_perm(MSQ, LSQ, mask); \
	MSQ = vec_ld(16, (float*)m); \
	LSQ = vec_ld(31, (float*)m); \
	mask = vec_lvsl(16, (float*)m); \
	vm2 = vec_perm(MSQ, LSQ, mask); \
	MSQ = vec_ld(32, (float*)m); \
	LSQ = vec_ld(47, (float*)m); \
	mask = vec_lvsl(32, (float*)m); \
	vm3 = vec_perm(MSQ, LSQ, mask); \
	MSQ = vec_ld(48, (float*)m); \
	LSQ = vec_ld(63, (float*)m); \
	mask = vec_lvsl(48, (float*)m); \
	vm4 = vec_perm(MSQ, LSQ, mask); \
}
#endif

typedef struct Matrix_t
{
	float ALIGNED16 v[16];
	int flags;                  // Matrix flags
	struct Matrix_t *Inverse;   // optional inverse
} Matrix;

#define OF_11 0
#define OF_12 4
#define OF_13 8
#define OF_14 12

#define OF_21 1
#define OF_22 5
#define OF_23 9
#define OF_24 13

#define OF_31 2
#define OF_32 6
#define OF_33 10
#define OF_34 14

#define OF_41 3
#define OF_42 7
#define OF_43 11
#define OF_44 15


#define  MGLMAT_IDENTITY         0x01
#define  MGLMAT_ROTATION         0x02
#define  MGLMAT_TRANSLATION      0x04
#define  MGLMAT_UNIFORM_SCALE    0x08
#define  MGLMAT_GENERAL_SCALE    0x10
#define  MGLMAT_PERSPECTIVE      0x20
#define  MGLMAT_GENERAL          0x40
#define  MGLMAT_GENERAL_3D       0x80
#define  MGLMAT_ORTHO            0x100
#define  MGLMAT_0001             0x200


#define MGLMASK_0001 (MGLMAT_IDENTITY|MGLMAT_ROTATION|\
		MGLMAT_TRANSLATION|MGLMAT_UNIFORM_SCALE|MGLMAT_GENERAL_SCALE|MGLMAT_ORTHO|MGLMAT_0001)


#endif
