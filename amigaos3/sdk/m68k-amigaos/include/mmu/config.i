        IFND MMU_CONFIG_I
MMU_CONFIG_I    SET 1
;*************************************************************************
;** mmu.library                                                         **
;**                                                                     **
;** a system library for arbitration and control of the MC68K MMUs      **
;**                                                                     **
;** © 1998 THOR-Software, Thomas Richter                                **
;** No commercial use, reassembly, modification without prior, written  **
;** permission of the authors.                                          **
;** Including this library in any commercial software REQUIRES a        **
;** written permission and the payment of a small fee.                  **
;**                                                                     **
;**---------------------------------------------------------------------**
;** MMU configuration structure                                         **
;**                                                                     **
;** This stuff should really be used ONLY by debuggers. There's NO NEED **
;** to use this internal stuff for anything else                        **
;**									**
;** $VER: 42.1 (08.04.2001)						**
;*************************************************************************

    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC ; EXEC_TYPES_I


    STRUCTURE       MMUConfig,0
        STRUCT  mcf_UserRootPointer,8
        ;* the MMU root pointer or NULL. For 68040,68060, only
        ;* the first long is used *
        STRUCT  mcf_SupervisorRootPointer,8
        ;* the MMU supervisor root pointer or NULL. For 68040
        ;* and 68060, the first long word is used *
        ULONG   mcf_TranslationControl
        ;* for 68040 and 68060, only bits 15..0 are used *
        ULONG   mcf_DTT0
        ;* data transparent translation control 0, or
        ;* transparent translation control 0 *
        ULONG   mcf_DTT1
        ;* data transparent translation control 1, or
        ;* translation translation control 1 *
        ULONG   mcf_ITT0
        ;* instruction transparent translation control 0, or
        ;* NULL if no ITT0 is available. *
        ULONG   mcf_ITT1
        ;* instruction transparent translation control 1, or
        ;*  NULL if no ITT1 is available. *
    LABEL   mcf_SIZE


    ENDC    ;MMU_CONFIG_I

