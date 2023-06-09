/* -------------------- Open ---------------------------*/
	.section   .data
	.globl     stub_Open
	.type      stub_Open, @function

stub_Open:
	.short     0x4ef8                /* JMP.w */
	.short     0                     /* Indicate switch */
	.short     1                     /* Trap type */
	.globl		stub_OpenPPC	
	.long      stub_OpenPPC
	/* Register mapping */
	.byte      2
	.byte      1,REG68K_A7          
	.byte      3,REG68K_A6

	.section .text
	.align     4

stub_OpenPPC:
		addi       r12, r1, -16          /* Calculate stackframe size */
		rlwinm     r12, r12, 0, 0, 27    /* Align it */
		stw        r1, 0(r12)            /* Store backchain pointer */
		mr         r1, r12               /* Set real stack pointer */

		stw		r11,12(r1)				/* Store Enter68kQuick vector */

		lhz		r12,LIB_POSSIZE(r3)
		add		r3, r3, r12				/* by addind posSize */
		lwz		r3, ExtLib_ILibrary(r3) /* Get the real interface pointer */
		xor		r4,r4,r4				/* set interface version to 0 */

		CallLib	lmi_Open
		
		lwz		r11,12(r1)
		mtlr	r11
	
		lwz     r1, 0(r1)				/* Cleanup stack frame */

		blrl							/* Return to emulation */
		.globl	   stub_Open68K
		.long      stub_Open68K
		.byte      0                     /* Flags */
		.byte      2                     /* Two registers (a7 and d0) */
		.byte      1                     /* Map r1 */
		.byte      REG68K_A7             /* to A7 */
		.byte      3                     /* Map r3 */
		.byte      REG68K_D0             /* to D0 */
		.section .data
		.align     4

stub_Open68K:
	.short     0x4e75                /* RTS */



/* -------------------- Close ---------------------------*/
	.section .data
	.globl     stub_Close
	.type      stub_Close, @function

stub_Close:
	.short     0x4ef8                /* JMP.w */
	.short     0                     /* Indicate switch */
	.short     1                     /* Trap type */
	.globl     stub_ClosePPC
	.long      stub_ClosePPC
	/* Register mapping */
	.byte      2
	.byte      1                     /* r1 */
	.byte      REG68K_A7             /* maps to a7 */
	.byte	   3,REG68K_A6

	.section .text	
	.align     4

stub_ClosePPC:
		addi       r12, r1, -16          /* Calculate stackframe size */
		rlwinm     r12, r12, 0, 0, 27    /* Align it */
		stw        r1, 0(r12)            /* Store backchain pointer */
		mr         r1, r12               /* Set real stack pointer */

		stw		r11,12(r1)				/* Store Enter68kQuick vector */

		lhz		r12,LIB_POSSIZE(r3)
		add		r3, r3, r12				/* by addind posSize */
		lwz		r3, ExtLib_ILibrary(r3) /* Get the real interface pointer */

		CallLib	lmi_Close
		
		lwz		r11,12(r1)
		mtlr	r11
	
		lwz     r1, 0(r1)				/* Cleanup stack frame */

		blrl							/* Return to emulation */
		.globl stub_Close68K
	.long      stub_Close68K
	.byte      0                     /* Flags */
	.byte      1                     /* One register (a7 only) */
	.byte      1                     /* Map r1 */
	.byte      REG68K_A7             /* to A7 */
	.section	.data
	.align     4

stub_Close68K:
	.short     0x4e75                /* RTS */



/* -------------------- Expunge ---------------------------*/
		.section .data
	.globl     stub_Expunge
	.type      stub_Expunge, @function

stub_Expunge:
	.short     0x7000                /* moveq #0, d0 */
	.short     0x4e75                /* RTS */



/* -------------------- RESERVED ---------------------------*/
		.section .data
	.globl     stub_Reserved
	.type      stub_Reserved, @function

stub_Reserved:
	.short     0x7000                /* moveq #0, d0 */
	.short     0x4e75                /* RTS */

