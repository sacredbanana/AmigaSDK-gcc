/* Generated automatically by the program `genflags'
   from the machine description file `md'.  */

#ifndef GCC_INSN_FLAGS_H
#define GCC_INSN_FLAGS_H

#define HAVE_zero_extendqisi2 1
#define HAVE_zero_extendqidi2 (TARGET_POWERPC64)
#define HAVE_zero_extendhisi2 1
#define HAVE_zero_extendhidi2 (TARGET_POWERPC64)
#define HAVE_zero_extendsidi2 (TARGET_POWERPC64)
#define HAVE_extendqisi2 1
#define HAVE_extendqidi2 (TARGET_POWERPC64)
#define HAVE_extendsidi2 (TARGET_POWERPC64)
#define HAVE_dlmzb (TARGET_DLMZB)
#define HAVE_addsi3_carry (TARGET_32BIT)
#define HAVE_adddi3_carry (TARGET_64BIT)
#define HAVE_addsi3_carry_in_0 1
#define HAVE_adddi3_carry_in_0 (TARGET_POWERPC64)
#define HAVE_addsi3_carry_in_m1 1
#define HAVE_adddi3_carry_in_m1 (TARGET_POWERPC64)
#define HAVE_subfsi3_imm 1
#define HAVE_subfdi3_imm (TARGET_POWERPC64)
#define HAVE_subfsi3_carry_dot2 ((SImode == Pmode) && (TARGET_32BIT))
#define HAVE_subfdi3_carry_dot2 ((DImode == Pmode) && (TARGET_64BIT))
#define HAVE_subfsi3_carry (TARGET_32BIT)
#define HAVE_subfdi3_carry (TARGET_64BIT)
#define HAVE_subfsi3_carry_in_0 1
#define HAVE_subfdi3_carry_in_0 (TARGET_POWERPC64)
#define HAVE_subfsi3_carry_in_m1 1
#define HAVE_subfdi3_carry_in_m1 (TARGET_POWERPC64)
#define HAVE_subfsi3_carry_in_xx 1
#define HAVE_subfdi3_carry_in_xx (TARGET_POWERPC64)
#define HAVE_negsi2 1
#define HAVE_negdi2 (TARGET_POWERPC64)
#define HAVE_clzsi2 1
#define HAVE_clzdi2 (TARGET_POWERPC64)
#define HAVE_ctzsi2_hw (TARGET_CTZ)
#define HAVE_ctzdi2_hw ((TARGET_CTZ) && (TARGET_POWERPC64))
#define HAVE_popcntbsi2 (TARGET_POPCNTB)
#define HAVE_popcntbdi2 ((TARGET_POPCNTB) && (TARGET_POWERPC64))
#define HAVE_popcntdsi2 (TARGET_POPCNTD)
#define HAVE_popcntddi2 ((TARGET_POPCNTD) && (TARGET_POWERPC64))
#define HAVE_paritysi2_cmpb (TARGET_CMPB && TARGET_POPCNTB)
#define HAVE_paritydi2_cmpb ((TARGET_CMPB && TARGET_POPCNTB) && (TARGET_POWERPC64))
#define HAVE_cfuged (TARGET_POWER10 && TARGET_64BIT)
#define HAVE_cntlzdm (TARGET_POWER10 && TARGET_POWERPC64)
#define HAVE_cnttzdm (TARGET_POWER10 && TARGET_POWERPC64)
#define HAVE_pdepd (TARGET_POWER10 && TARGET_POWERPC64)
#define HAVE_pextd (TARGET_POWER10 && TARGET_POWERPC64)
#define HAVE_cmpbsi3 (TARGET_CMPB)
#define HAVE_cmpbdi3 ((TARGET_CMPB) && (TARGET_POWERPC64))
#define HAVE_bswaphi2_load 1
#define HAVE_bswapsi2_load 1
#define HAVE_bswaphi2_store 1
#define HAVE_bswapsi2_store 1
#define HAVE_bswaphi2_reg 1
#define HAVE_bswapsi2_reg 1
#define HAVE_bswapdi2_load (TARGET_POWERPC64 && TARGET_LDBRX)
#define HAVE_bswapdi2_store (TARGET_POWERPC64 && TARGET_LDBRX)
#define HAVE_bswapdi2_brd (TARGET_P9_VECTOR)
#define HAVE_bswapdi2_reg (TARGET_POWERPC64 && TARGET_LDBRX && !TARGET_P9_VECTOR)
#define HAVE_bswapdi2_32bit (!TARGET_POWERPC64 && (REG_P (operands[0]) || REG_P (operands[1])))
#define HAVE_mulsi3 1
#define HAVE_muldi3 (TARGET_POWERPC64)
#define HAVE_smulsi3_highpart_le (!WORDS_BIG_ENDIAN && !TARGET_POWERPC64)
#define HAVE_umulsi3_highpart_le (!WORDS_BIG_ENDIAN && !TARGET_POWERPC64)
#define HAVE_smuldi3_highpart_le (!WORDS_BIG_ENDIAN && TARGET_POWERPC64)
#define HAVE_umuldi3_highpart_le (!WORDS_BIG_ENDIAN && TARGET_POWERPC64)
#define HAVE_smulsi3_highpart_64 (TARGET_POWERPC64)
#define HAVE_umulsi3_highpart_64 (TARGET_POWERPC64)
#define HAVE_udivsi3 1
#define HAVE_udivdi3 (TARGET_POWERPC64)
#define HAVE_udivti3 (TARGET_POWER10 && TARGET_POWERPC64)
#define HAVE_divsi3_sra 1
#define HAVE_divdi3_sra (TARGET_POWERPC64)
#define HAVE_divti3 (TARGET_POWER10 && TARGET_POWERPC64)
#define HAVE_umodsi3 (TARGET_MODULO)
#define HAVE_umoddi3 ((TARGET_MODULO) && (TARGET_POWERPC64))
#define HAVE_umodti3 (TARGET_POWER10 && TARGET_POWERPC64)
#define HAVE_modti3 (TARGET_POWER10 && TARGET_POWERPC64)
#define HAVE_andsi3_imm (!rs6000_is_valid_and_mask (operands[2], SImode))
#define HAVE_anddi3_imm ((!rs6000_is_valid_and_mask (operands[2], DImode)) && (TARGET_POWERPC64))
#define HAVE_andsi3_mask (rs6000_is_valid_and_mask (operands[2], SImode))
#define HAVE_anddi3_mask ((rs6000_is_valid_and_mask (operands[2], DImode)) && (TARGET_POWERPC64))
#define HAVE_rotlsi3_insert_3 (INTVAL (operands[2]) == exact_log2 (UINTVAL (operands[4]) + 1))
#define HAVE_rotldi3_insert_3 ((INTVAL (operands[2]) == exact_log2 (UINTVAL (operands[4]) + 1)) && (TARGET_POWERPC64))
#define HAVE_rotlsi3 1
#define HAVE_rotldi3 (TARGET_POWERPC64)
#define HAVE_ashlsi3 1
#define HAVE_ashldi3 (TARGET_POWERPC64)
#define HAVE_ashdi3_extswsli (TARGET_EXTSWSLI)
#define HAVE_ashdi3_extswsli_dot (TARGET_EXTSWSLI)
#define HAVE_ashdi3_extswsli_dot2 (TARGET_EXTSWSLI)
#define HAVE_lshrsi3 1
#define HAVE_lshrdi3 (TARGET_POWERPC64)
#define HAVE_ashrsi3 1
#define HAVE_ashrdi3 (TARGET_POWERPC64)
#define HAVE_fres (TARGET_FRES)
#define HAVE_fred (TARGET_FRE)
#define HAVE_signbitkf2_dm ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_signbittf2_dm ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_copysignsf3_fcpsgn (TARGET_HARD_FLOAT && (TARGET_CMPB || VECTOR_UNIT_VSX_P (SFmode)))
#define HAVE_copysigndf3_fcpsgn (TARGET_HARD_FLOAT && (TARGET_CMPB || VECTOR_UNIT_VSX_P (DFmode)))
#define HAVE_sminkf3 ((TARGET_POWER10 && TARGET_FLOAT128_HW) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_smaxkf3 ((TARGET_POWER10 && TARGET_FLOAT128_HW) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_smintf3 ((TARGET_POWER10 && TARGET_FLOAT128_HW) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_smaxtf3 ((TARGET_POWER10 && TARGET_FLOAT128_HW) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_isel_signed_si (TARGET_ISEL)
#define HAVE_isel_signed_di ((TARGET_ISEL) && (TARGET_POWERPC64))
#define HAVE_isel_unsigned_si (TARGET_ISEL)
#define HAVE_isel_unsigned_di ((TARGET_ISEL) && (TARGET_POWERPC64))
#define HAVE_setbc_signed_si (TARGET_POWER10)
#define HAVE_setbc_signed_di ((TARGET_POWER10) && (TARGET_POWERPC64))
#define HAVE_setbc_unsigned_si (TARGET_POWER10)
#define HAVE_setbc_unsigned_di ((TARGET_POWER10) && (TARGET_POWERPC64))
#define HAVE_lfiwax (TARGET_HARD_FLOAT && TARGET_LFIWAX)
#define HAVE_floatsisf2_lfiwax (TARGET_HARD_FLOAT && TARGET_LFIWAX \
   && TARGET_FCFIDS && can_create_pseudo_p ())
#define HAVE_floatsidf2_lfiwax (TARGET_HARD_FLOAT && TARGET_LFIWAX \
   && TARGET_FCFID && can_create_pseudo_p ())
#define HAVE_floatsisf2_lfiwax_mem (TARGET_HARD_FLOAT && TARGET_LFIWAX && TARGET_FCFIDS)
#define HAVE_floatsidf2_lfiwax_mem (TARGET_HARD_FLOAT && TARGET_LFIWAX && TARGET_FCFID)
#define HAVE_lfiwzx (TARGET_HARD_FLOAT && TARGET_LFIWZX)
#define HAVE_floatunssisf2_lfiwzx (TARGET_HARD_FLOAT && TARGET_LFIWZX && TARGET_FCFIDS)
#define HAVE_floatunssidf2_lfiwzx (TARGET_HARD_FLOAT && TARGET_LFIWZX && TARGET_FCFID)
#define HAVE_floatunssisf2_lfiwzx_mem (TARGET_HARD_FLOAT && TARGET_LFIWZX && TARGET_FCFIDS)
#define HAVE_floatunssidf2_lfiwzx_mem (TARGET_HARD_FLOAT && TARGET_LFIWZX && TARGET_FCFID)
#define HAVE_fix_truncsfsi2_stfiwx (TARGET_HARD_FLOAT && TARGET_STFIWX && can_create_pseudo_p () \
   && !(TARGET_P8_VECTOR && TARGET_DIRECT_MOVE))
#define HAVE_fix_truncdfsi2_stfiwx (TARGET_HARD_FLOAT && TARGET_STFIWX && can_create_pseudo_p () \
   && !(TARGET_P8_VECTOR && TARGET_DIRECT_MOVE))
#define HAVE_fix_truncsfsi2_internal (TARGET_HARD_FLOAT \
   && !(TARGET_P8_VECTOR && TARGET_DIRECT_MOVE))
#define HAVE_fix_truncdfsi2_internal (TARGET_HARD_FLOAT \
   && !(TARGET_P8_VECTOR && TARGET_DIRECT_MOVE))
#define HAVE_fix_truncsfqi2 (TARGET_DIRECT_MOVE)
#define HAVE_fixuns_truncsfqi2 (TARGET_DIRECT_MOVE)
#define HAVE_fix_truncsfhi2 (TARGET_DIRECT_MOVE)
#define HAVE_fixuns_truncsfhi2 (TARGET_DIRECT_MOVE)
#define HAVE_fix_truncdfqi2 (TARGET_DIRECT_MOVE)
#define HAVE_fixuns_truncdfqi2 (TARGET_DIRECT_MOVE)
#define HAVE_fix_truncdfhi2 (TARGET_DIRECT_MOVE)
#define HAVE_fixuns_truncdfhi2 (TARGET_DIRECT_MOVE)
#define HAVE_fixuns_truncsfsi2_stfiwx (TARGET_HARD_FLOAT && TARGET_FCTIWUZ \
   && TARGET_STFIWX && can_create_pseudo_p () \
   && !TARGET_P8_VECTOR)
#define HAVE_fixuns_truncdfsi2_stfiwx (TARGET_HARD_FLOAT && TARGET_FCTIWUZ \
   && TARGET_STFIWX && can_create_pseudo_p () \
   && !TARGET_P8_VECTOR)
#define HAVE_fixuns_truncsfdi2 (TARGET_HARD_FLOAT && TARGET_FCTIDUZ)
#define HAVE_fixuns_truncdfdi2 (TARGET_HARD_FLOAT && TARGET_FCTIDUZ)
#define HAVE_rs6000_mtfsb0 (TARGET_HARD_FLOAT)
#define HAVE_rs6000_mtfsb1 (TARGET_HARD_FLOAT)
#define HAVE_rs6000_mffscrn (TARGET_P9_MISC)
#define HAVE_rs6000_mffscdrn (TARGET_P9_MISC)
#define HAVE_fctiwz_sf (TARGET_HARD_FLOAT)
#define HAVE_fctiwz_df (TARGET_HARD_FLOAT)
#define HAVE_fctiwuz_sf (TARGET_HARD_FLOAT && TARGET_FCTIWUZ)
#define HAVE_fctiwuz_df (TARGET_HARD_FLOAT && TARGET_FCTIWUZ)
#define HAVE_lrintsfdi2 (TARGET_HARD_FLOAT && TARGET_FPRND)
#define HAVE_lrintdfdi2 (TARGET_HARD_FLOAT && TARGET_FPRND)
#define HAVE_btruncsf2 (TARGET_HARD_FLOAT && TARGET_FPRND)
#define HAVE_btruncdf2 (TARGET_HARD_FLOAT && TARGET_FPRND)
#define HAVE_ceilsf2 (TARGET_HARD_FLOAT && TARGET_FPRND)
#define HAVE_ceildf2 (TARGET_HARD_FLOAT && TARGET_FPRND)
#define HAVE_floorsf2 (TARGET_HARD_FLOAT && TARGET_FPRND)
#define HAVE_floordf2 (TARGET_HARD_FLOAT && TARGET_FPRND)
#define HAVE_roundsf2 (TARGET_HARD_FLOAT && TARGET_FPRND)
#define HAVE_rounddf2 (TARGET_HARD_FLOAT && TARGET_FPRND)
#define HAVE_stfiwx (TARGET_PPC_GFXOPT)
#define HAVE_floatdidf2 (TARGET_FCFID && TARGET_HARD_FLOAT)
#define HAVE_floattikf2 ((TARGET_POWER10) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floattitf2 ((TARGET_POWER10) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatunstikf2 ((TARGET_POWER10) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floatunstitf2 ((TARGET_POWER10) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fix_trunckfti2 ((TARGET_POWER10) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fix_trunctfti2 ((TARGET_POWER10) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fixuns_trunckfti2 ((TARGET_POWER10) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fixuns_trunctfti2 ((TARGET_POWER10) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatdisf2_fcfids (TARGET_HARD_FLOAT && TARGET_FCFIDS)
#define HAVE_floatdisf2_internal1 (TARGET_FCFID && TARGET_HARD_FLOAT && !TARGET_FCFIDS)
#define HAVE_floatunsdisf2_fcfidus (TARGET_HARD_FLOAT && TARGET_FCFIDUS)
#define HAVE_one_cmplti2 1
#define HAVE_one_cmplpti2 1
#define HAVE_one_cmplv16qi2 (TARGET_ALTIVEC)
#define HAVE_one_cmplv8hi2 (TARGET_ALTIVEC)
#define HAVE_one_cmplv4si2 (TARGET_ALTIVEC)
#define HAVE_one_cmplv4sf2 (TARGET_ALTIVEC)
#define HAVE_one_cmplv2di2 (TARGET_ALTIVEC)
#define HAVE_one_cmplv2df2 (TARGET_ALTIVEC)
#define HAVE_one_cmplv1ti2 (TARGET_ALTIVEC)
#define HAVE_movsi_from_sf (TARGET_NO_SF_SUBREG \
   && (register_operand (operands[0], SImode) \
       || register_operand (operands[1], SFmode)))
#define HAVE_movsf_hardfloat ((register_operand (operands[0], SFmode) \
   || register_operand (operands[1], SFmode)) \
   && TARGET_HARD_FLOAT \
   && (TARGET_ALLOW_SF_SUBREG \
       || valid_sf_si_move (operands[0], operands[1], SFmode)))
#define HAVE_movsd_hardfloat ((register_operand (operands[0], SDmode) \
   || register_operand (operands[1], SDmode)) \
   && TARGET_HARD_FLOAT)
#define HAVE_movsf_from_si (TARGET_NO_SF_SUBREG \
   && (register_operand (operands[0], SFmode) \
       || register_operand (operands[1], SImode)))
#define HAVE_movsf_from_si2 (TARGET_NO_SF_SUBREG)
#define HAVE_extenddfif2_fprs ((!TARGET_VSX && TARGET_HARD_FLOAT \
   && TARGET_LONG_DOUBLE_128 && FLOAT128_IBM_P (IFmode)) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_extenddftf2_fprs ((!TARGET_VSX && TARGET_HARD_FLOAT \
   && TARGET_LONG_DOUBLE_128 && FLOAT128_IBM_P (TFmode)) && (FLOAT128_IBM_P (TFmode)))
#define HAVE_extenddfif2_vsx ((TARGET_LONG_DOUBLE_128 && TARGET_VSX && FLOAT128_IBM_P (IFmode)) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_extenddftf2_vsx ((TARGET_LONG_DOUBLE_128 && TARGET_VSX && FLOAT128_IBM_P (TFmode)) && (FLOAT128_IBM_P (TFmode)))
#define HAVE_truncifdf2_internal1 ((FLOAT128_IBM_P (IFmode) && !TARGET_XL_COMPAT \
   && TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_trunctfdf2_internal1 ((FLOAT128_IBM_P (TFmode) && !TARGET_XL_COMPAT \
   && TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (FLOAT128_IBM_P (TFmode)))
#define HAVE_truncifdf2_internal2 ((FLOAT128_IBM_P (IFmode) && TARGET_XL_COMPAT && TARGET_HARD_FLOAT \
   && TARGET_LONG_DOUBLE_128) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_trunctfdf2_internal2 ((FLOAT128_IBM_P (TFmode) && TARGET_XL_COMPAT && TARGET_HARD_FLOAT \
   && TARGET_LONG_DOUBLE_128) && (FLOAT128_IBM_P (TFmode)))
#define HAVE_fix_trunc_helperif ((TARGET_HARD_FLOAT && FLOAT128_IBM_P (IFmode)) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_fix_trunc_helpertf ((TARGET_HARD_FLOAT && FLOAT128_IBM_P (TFmode)) && (FLOAT128_IBM_P (TFmode)))
#define HAVE_negif2_internal ((TARGET_HARD_FLOAT && FLOAT128_IBM_P (IFmode)) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_negtf2_internal ((TARGET_HARD_FLOAT && FLOAT128_IBM_P (TFmode)) && (FLOAT128_IBM_P (TFmode)))
#define HAVE_ieee_128bit_vsx_negkf2 ((TARGET_FLOAT128_TYPE && !TARGET_FLOAT128_HW) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_ieee_128bit_vsx_negtf2 ((TARGET_FLOAT128_TYPE && !TARGET_FLOAT128_HW) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_ieee_128bit_vsx_abskf2 ((TARGET_FLOAT128_TYPE && !TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_ieee_128bit_vsx_abstf2 ((TARGET_FLOAT128_TYPE && !TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_p8_fmrgow_di (!TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_fmrgow_df (!TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_fmrgow_dd (!TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mtvsrwz (!TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mtvsrwz_v16qisi2 (!TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mtvsrd_v16qidi2 (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_fpr_from_gprdi (!TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_fpr_from_gprdf (!TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_fpr_from_gprdd (!TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mtvsrd_df (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_xxpermdi_ti (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_xxpermdi_v16qi (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_xxpermdi_v8hi (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_xxpermdi_v4si (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_xxpermdi_v4sf (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_xxpermdi_v2di (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_xxpermdi_v2df (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_xxpermdi_v1ti (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_xxpermdi_kf ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_p8_xxpermdi_tf ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_reload_vsx_from_gprti (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_vsx_from_gprv16qi (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_vsx_from_gprv8hi (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_vsx_from_gprv4si (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_vsx_from_gprv4sf (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_vsx_from_gprv2di (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_vsx_from_gprv2df (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_vsx_from_gprv1ti (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_vsx_from_gprkf ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_reload_vsx_from_gprtf ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_p8_mtvsrd_sf (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_vsx_from_gprsf (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mfvsrd_3_ti (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mfvsrd_3_v16qi (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mfvsrd_3_v8hi (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mfvsrd_3_v4si (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mfvsrd_3_v4sf (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mfvsrd_3_v2di (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mfvsrd_3_v2df (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mfvsrd_3_v1ti (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_p8_mfvsrd_3_kf ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_p8_mfvsrd_3_tf ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_reload_gpr_from_vsxti (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_gpr_from_vsxv16qi (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_gpr_from_vsxv8hi (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_gpr_from_vsxv4si (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_gpr_from_vsxv4sf (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_gpr_from_vsxv2di (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_gpr_from_vsxv2df (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_gpr_from_vsxv1ti (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_reload_gpr_from_vsxkf ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_reload_gpr_from_vsxtf ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_reload_gpr_from_vsxsf (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_movdi_si_update ((TARGET_POWERPC64 && TARGET_UPDATE \
   && (!avoiding_indexed_address_p (DImode) \
       || !gpc_reg_operand (operands[2], Pmode) \
       || (REG_P (operands[0]) \
	   && REGNO (operands[0]) == STACK_POINTER_REGNUM))) && (TARGET_32BIT))
#define HAVE_movdi_di_update ((TARGET_POWERPC64 && TARGET_UPDATE \
   && (!avoiding_indexed_address_p (DImode) \
       || !gpc_reg_operand (operands[2], Pmode) \
       || (REG_P (operands[0]) \
	   && REGNO (operands[0]) == STACK_POINTER_REGNUM))) && (TARGET_64BIT))
#define HAVE_movdi_update_stack (TARGET_64BIT)
#define HAVE_movsi_si_update ((TARGET_UPDATE \
   && (!avoiding_indexed_address_p (SImode) \
       || !gpc_reg_operand (operands[2], Pmode) \
       || (REG_P (operands[0]) \
	   && REGNO (operands[0]) == STACK_POINTER_REGNUM))) && (TARGET_32BIT))
#define HAVE_movsi_di_update ((TARGET_UPDATE \
   && (!avoiding_indexed_address_p (SImode) \
       || !gpc_reg_operand (operands[2], Pmode) \
       || (REG_P (operands[0]) \
	   && REGNO (operands[0]) == STACK_POINTER_REGNUM))) && (TARGET_64BIT))
#define HAVE_movsi_update_stack (TARGET_32BIT)
#define HAVE_load_toc_v4_pic_si (DEFAULT_ABI == ABI_V4 && flag_pic == 1 && TARGET_32BIT)
#define HAVE_load_toc_v4_PIC_1_normal (!TARGET_LINK_STACK && TARGET_ELF && DEFAULT_ABI == ABI_V4 \
   && (flag_pic == 2 || (flag_pic && TARGET_SECURE_PLT)))
#define HAVE_load_toc_v4_PIC_1b_normal (!TARGET_LINK_STACK && TARGET_ELF && DEFAULT_ABI == ABI_V4 && flag_pic == 2)
#define HAVE_load_toc_v4_PIC_2 (TARGET_ELF && DEFAULT_ABI == ABI_V4 && flag_pic == 2)
#define HAVE_load_toc_v4_PIC_3b (TARGET_ELF && TARGET_SECURE_PLT && DEFAULT_ABI == ABI_V4 && flag_pic)
#define HAVE_load_toc_v4_PIC_3c (TARGET_ELF && TARGET_SECURE_PLT && DEFAULT_ABI == ABI_V4 && flag_pic)
#define HAVE_elf_base_high (TARGET_ELF && ! TARGET_64BIT && TARGET_BASEREL)
#define HAVE_elf_base_low (TARGET_ELF && ! TARGET_64BIT && TARGET_BASEREL && morphos_baserel_operand(operands[2]))
#define HAVE_elf_high (TARGET_ELF && !TARGET_64BIT && !flag_pic)
#define HAVE_elf_low (TARGET_ELF && !TARGET_64BIT && !flag_pic)
#define HAVE_blockage 1
#define HAVE_probe_stack_si (TARGET_32BIT)
#define HAVE_probe_stack_di (TARGET_64BIT)
#define HAVE_probe_stack_rangesi (TARGET_32BIT)
#define HAVE_probe_stack_rangedi (TARGET_64BIT)
#define HAVE_stack_protect_setsi (TARGET_32BIT)
#define HAVE_stack_protect_setdi (TARGET_64BIT)
#define HAVE_stack_protect_testsi (TARGET_32BIT)
#define HAVE_stack_protect_testdi (TARGET_64BIT)
#define HAVE_setsi_cc 1
#define HAVE_setdi_cc (TARGET_POWERPC64)
#define HAVE_eqsisi2_isel (!TARGET_POWER10 && TARGET_ISEL \
   && !(EQ == EQ && operands[2] == const0_rtx) \
   && !(EQ == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && SImode == Pmode))
#define HAVE_nesisi2_isel (!TARGET_POWER10 && TARGET_ISEL \
   && !(NE == EQ && operands[2] == const0_rtx) \
   && !(NE == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && SImode == Pmode))
#define HAVE_ltsisi2_isel (!TARGET_POWER10 && TARGET_ISEL \
   && !(LT == EQ && operands[2] == const0_rtx) \
   && !(LT == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && SImode == Pmode))
#define HAVE_ltusisi2_isel (!TARGET_POWER10 && TARGET_ISEL \
   && !(LTU == EQ && operands[2] == const0_rtx) \
   && !(LTU == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && SImode == Pmode))
#define HAVE_gtsisi2_isel (!TARGET_POWER10 && TARGET_ISEL \
   && !(GT == EQ && operands[2] == const0_rtx) \
   && !(GT == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && SImode == Pmode))
#define HAVE_gtusisi2_isel (!TARGET_POWER10 && TARGET_ISEL \
   && !(GTU == EQ && operands[2] == const0_rtx) \
   && !(GTU == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && SImode == Pmode))
#define HAVE_lesisi2_isel (!TARGET_POWER10 && TARGET_ISEL \
   && !(LE == EQ && operands[2] == const0_rtx) \
   && !(LE == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && SImode == Pmode))
#define HAVE_leusisi2_isel (!TARGET_POWER10 && TARGET_ISEL \
   && !(LEU == EQ && operands[2] == const0_rtx) \
   && !(LEU == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && SImode == Pmode))
#define HAVE_gesisi2_isel (!TARGET_POWER10 && TARGET_ISEL \
   && !(GE == EQ && operands[2] == const0_rtx) \
   && !(GE == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && SImode == Pmode))
#define HAVE_geusisi2_isel (!TARGET_POWER10 && TARGET_ISEL \
   && !(GEU == EQ && operands[2] == const0_rtx) \
   && !(GEU == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && SImode == Pmode))
#define HAVE_eqdisi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(EQ == EQ && operands[2] == const0_rtx) \
   && !(EQ == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && SImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_nedisi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(NE == EQ && operands[2] == const0_rtx) \
   && !(NE == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && SImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_ltdisi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LT == EQ && operands[2] == const0_rtx) \
   && !(LT == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && SImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_ltudisi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LTU == EQ && operands[2] == const0_rtx) \
   && !(LTU == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && SImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_gtdisi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GT == EQ && operands[2] == const0_rtx) \
   && !(GT == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && SImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_gtudisi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GTU == EQ && operands[2] == const0_rtx) \
   && !(GTU == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && SImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_ledisi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LE == EQ && operands[2] == const0_rtx) \
   && !(LE == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && SImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_leudisi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LEU == EQ && operands[2] == const0_rtx) \
   && !(LEU == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && SImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_gedisi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GE == EQ && operands[2] == const0_rtx) \
   && !(GE == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && SImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_geudisi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GEU == EQ && operands[2] == const0_rtx) \
   && !(GEU == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && SImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_eqsidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(EQ == EQ && operands[2] == const0_rtx) \
   && !(EQ == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_nesidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(NE == EQ && operands[2] == const0_rtx) \
   && !(NE == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_ltsidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LT == EQ && operands[2] == const0_rtx) \
   && !(LT == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_ltusidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LTU == EQ && operands[2] == const0_rtx) \
   && !(LTU == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_gtsidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GT == EQ && operands[2] == const0_rtx) \
   && !(GT == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_gtusidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GTU == EQ && operands[2] == const0_rtx) \
   && !(GTU == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_lesidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LE == EQ && operands[2] == const0_rtx) \
   && !(LE == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_leusidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LEU == EQ && operands[2] == const0_rtx) \
   && !(LEU == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_gesidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GE == EQ && operands[2] == const0_rtx) \
   && !(GE == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_geusidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GEU == EQ && operands[2] == const0_rtx) \
   && !(GEU == NE && operands[2] == const0_rtx \
	&& SImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_eqdidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(EQ == EQ && operands[2] == const0_rtx) \
   && !(EQ == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_nedidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(NE == EQ && operands[2] == const0_rtx) \
   && !(NE == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_ltdidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LT == EQ && operands[2] == const0_rtx) \
   && !(LT == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_ltudidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LTU == EQ && operands[2] == const0_rtx) \
   && !(LTU == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_gtdidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GT == EQ && operands[2] == const0_rtx) \
   && !(GT == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_gtudidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GTU == EQ && operands[2] == const0_rtx) \
   && !(GTU == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_ledidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LE == EQ && operands[2] == const0_rtx) \
   && !(LE == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_leudidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(LEU == EQ && operands[2] == const0_rtx) \
   && !(LEU == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_gedidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GE == EQ && operands[2] == const0_rtx) \
   && !(GE == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_geudidi2_isel ((!TARGET_POWER10 && TARGET_ISEL \
   && !(GEU == EQ && operands[2] == const0_rtx) \
   && !(GEU == NE && operands[2] == const0_rtx \
	&& DImode == Pmode && DImode == Pmode)) && (TARGET_POWERPC64))
#define HAVE_cceq_ior_compare_si 1
#define HAVE_cceq_ior_compare_di (TARGET_POWERPC64)
#define HAVE_cceq_ior_compare_complement 1
#define HAVE_cceq_rev_compare_si 1
#define HAVE_cceq_rev_compare_di (TARGET_POWERPC64)
#define HAVE_jump 1
#define HAVE_return (direct_return ())
#define HAVE_simple_return 1
#define HAVE_indirect_jumpsi_nospec ((!rs6000_speculate_indirect_jumps) && (TARGET_32BIT))
#define HAVE_indirect_jumpdi_nospec ((!rs6000_speculate_indirect_jumps) && (TARGET_64BIT))
#define HAVE_tablejumpsi_insn_normal ((rs6000_speculate_indirect_jumps) && (TARGET_32BIT))
#define HAVE_tablejumpdi_insn_normal ((rs6000_speculate_indirect_jumps) && (TARGET_64BIT))
#define HAVE_tablejumpsi_insn_nospec ((!rs6000_speculate_indirect_jumps) && (TARGET_32BIT))
#define HAVE_tablejumpdi_insn_nospec ((!rs6000_speculate_indirect_jumps) && (TARGET_64BIT))
#define HAVE_nop 1
#define HAVE_group_ending_nop 1
#define HAVE_speculation_barrier 1
#define HAVE_bdz_si (TARGET_32BIT)
#define HAVE_bdnz_si (TARGET_32BIT)
#define HAVE_bdz_di (TARGET_64BIT)
#define HAVE_bdnz_di (TARGET_64BIT)
#define HAVE_bdztf_si (TARGET_32BIT)
#define HAVE_bdnztf_si (TARGET_32BIT)
#define HAVE_bdztf_di (TARGET_64BIT)
#define HAVE_bdnztf_di (TARGET_64BIT)
#define HAVE_trap 1
#define HAVE_prologue_movesi_from_cr 1
#define HAVE_stack_tie 1
#define HAVE_stack_restore_tie (TARGET_32BIT)
#define HAVE_eh_set_lr_si (TARGET_32BIT)
#define HAVE_eh_set_lr_di (TARGET_64BIT)
#define HAVE_prefetch 1
#define HAVE_load_split_stack_limit_di (TARGET_64BIT)
#define HAVE_load_split_stack_limit_si (!TARGET_64BIT)
#define HAVE_split_stack_return 1
#define HAVE_bpermd_si ((TARGET_POPCNTD) && (TARGET_32BIT))
#define HAVE_bpermd_di ((TARGET_POPCNTD) && (TARGET_64BIT))
#define HAVE_rs6000_get_timebase_ppc32 (!TARGET_POWERPC64)
#define HAVE_rs6000_mftb_si 1
#define HAVE_rs6000_mftb_di (TARGET_POWERPC64)
#define HAVE_rs6000_mffsl_hw (TARGET_HARD_FLOAT)
#define HAVE_rs6000_mffs (TARGET_HARD_FLOAT)
#define HAVE_rs6000_mtfsf (TARGET_HARD_FLOAT)
#define HAVE_rs6000_mtfsf_hi (TARGET_HARD_FLOAT)
#define HAVE_addg6s (TARGET_POPCNTD)
#define HAVE_cdtbcd (TARGET_POPCNTD)
#define HAVE_cbcdtd (TARGET_POPCNTD)
#define HAVE_dive_si (TARGET_POPCNTD)
#define HAVE_diveu_si (TARGET_POPCNTD)
#define HAVE_dive_di ((TARGET_POPCNTD) && (TARGET_POWERPC64))
#define HAVE_diveu_di ((TARGET_POPCNTD) && (TARGET_POWERPC64))
#define HAVE_unpacktf_dm ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE && FLOAT128_2REG_P (TFmode)) && (TARGET_LONG_DOUBLE_128))
#define HAVE_unpackif_dm ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE && FLOAT128_2REG_P (IFmode)) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_unpacktd_dm ((TARGET_POWERPC64 && TARGET_DIRECT_MOVE && FLOAT128_2REG_P (TDmode)) && (TARGET_HARD_FLOAT))
#define HAVE_unpacktf_nodm (((!TARGET_POWERPC64 || !TARGET_DIRECT_MOVE) && FLOAT128_2REG_P (TFmode)) && (TARGET_LONG_DOUBLE_128))
#define HAVE_unpackif_nodm (((!TARGET_POWERPC64 || !TARGET_DIRECT_MOVE) && FLOAT128_2REG_P (IFmode)) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_unpacktd_nodm (((!TARGET_POWERPC64 || !TARGET_DIRECT_MOVE) && FLOAT128_2REG_P (TDmode)) && (TARGET_HARD_FLOAT))
#define HAVE_packtf ((FLOAT128_2REG_P (TFmode)) && (TARGET_LONG_DOUBLE_128))
#define HAVE_packif ((FLOAT128_2REG_P (IFmode)) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_packtd ((FLOAT128_2REG_P (TDmode)) && (TARGET_HARD_FLOAT))
#define HAVE_unpackv1ti (VECTOR_MEM_ALTIVEC_OR_VSX_P (V1TImode))
#define HAVE_unpackkf (VECTOR_MEM_ALTIVEC_OR_VSX_P (KFmode))
#define HAVE_packv1ti (TARGET_VSX)
#define HAVE_packkf (TARGET_VSX)
#define HAVE_addkf3 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_addtf3 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_subkf3 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_subtf3 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_mulkf3 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_multf3 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_divkf3 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_divtf3 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_sqrtkf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_sqrttf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_copysignkf3_hard ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_copysigntf3_hard ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_copysignkf3_soft ((!TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_copysigntf3_soft ((!TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_negkf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_negtf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_abskf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_abstf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fmakf4_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fmatf4_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_extendsfkf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_extendsftf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_extenddfkf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_extenddftf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_extendkftf2 (TARGET_FLOAT128_TYPE && TARGET_IEEEQUAD)
#define HAVE_trunctfkf2 (TARGET_FLOAT128_TYPE && TARGET_IEEEQUAD)
#define HAVE_trunckfdf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_trunctfdf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_trunckfsf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_trunctfsf2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fix_kfsi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fixuns_kfsi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fix_tfsi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fixuns_tfsi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fix_kfdi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fixuns_kfdi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fix_tfdi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fixuns_tfdi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fix_trunckfqi2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fixuns_trunckfqi2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fix_trunckfhi2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fixuns_trunckfhi2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fix_trunctfqi2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fixuns_trunctfqi2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fix_trunctfhi2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fixuns_trunctfhi2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_float_kfdi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_float_tfdi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_float_kfsi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_float_tfsi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatqikf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floathikf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floatqitf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floathitf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatuns_kfdi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floatuns_tfdi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatuns_kfsi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floatuns_tfsi2_hw ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatunsqikf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floatunshikf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floatunsqitf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatunshitf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floorkf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floortf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_ceilkf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_ceiltf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_btrunckf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_btrunctf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_roundkf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_roundtf2 ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_addkf3_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_addtf3_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_subkf3_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_subtf3_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_mulkf3_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_multf3_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_divkf3_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_divtf3_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_sqrtkf2_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_sqrttf2_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fmakf4_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fmatf4_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_trunckfdf2_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_trunctfdf2_odd ((TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_darn_32 (TARGET_P9_MISC)
#define HAVE_darn_raw (TARGET_P9_MISC && TARGET_64BIT)
#define HAVE_darn (TARGET_P9_MISC && TARGET_64BIT)
#define HAVE_setb_signed (TARGET_P9_MISC)
#define HAVE_setb_unsigned (TARGET_P9_MISC)
#define HAVE_hashst (TARGET_POWER10 && rs6000_rop_protect)
#define HAVE_hashchk (TARGET_POWER10 && rs6000_rop_protect)
#define HAVE_isync 1
#define HAVE_loadsync_qi 1
#define HAVE_loadsync_hi 1
#define HAVE_loadsync_si 1
#define HAVE_loadsync_di (TARGET_POWERPC64)
#define HAVE_loadsync_ti (TARGET_SYNC_TI)
#define HAVE_load_quadpti (TARGET_SYNC_TI \
   && !reg_mentioned_p (operands[0], operands[1]))
#define HAVE_store_quadpti (TARGET_SYNC_TI)
#define HAVE_load_lockedqi (TARGET_SYNC_HI_QI)
#define HAVE_load_lockedhi (TARGET_SYNC_HI_QI)
#define HAVE_load_lockedsi 1
#define HAVE_load_lockeddi (TARGET_POWERPC64)
#define HAVE_load_lockedqi_si (TARGET_SYNC_HI_QI)
#define HAVE_load_lockedhi_si (TARGET_SYNC_HI_QI)
#define HAVE_load_lockedpti (TARGET_SYNC_TI \
   && !reg_mentioned_p (operands[0], operands[1]) \
   && quad_int_reg_operand (operands[0], PTImode))
#define HAVE_store_conditionalqi (TARGET_SYNC_HI_QI)
#define HAVE_store_conditionalhi (TARGET_SYNC_HI_QI)
#define HAVE_store_conditionalsi 1
#define HAVE_store_conditionaldi (TARGET_POWERPC64)
#define HAVE_store_conditionalpti (TARGET_SYNC_TI && quad_int_reg_operand (operands[2], PTImode))
#define HAVE_vector_ltv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_lev4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_nev4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_ungtv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_ungev4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_unltv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_unlev4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_ltv2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_vector_lev2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_vector_nev2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_vector_ungtv2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_vector_ungev2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_vector_unltv2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_vector_unlev2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_vector_ltgtv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_uneqv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_unorderedv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_orderedv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) && can_create_pseudo_p ())
#define HAVE_vector_ltgtv2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_vector_uneqv2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_vector_unorderedv2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_vector_orderedv2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) && can_create_pseudo_p ())
#define HAVE_xxspltib_v16qi (TARGET_P9_VECTOR)
#define HAVE_xxspltib_v8hi_nosplit (TARGET_P9_VECTOR)
#define HAVE_xxspltib_v4si_nosplit (TARGET_P9_VECTOR)
#define HAVE_xxspltib_v2di_nosplit (TARGET_P9_VECTOR)
#define HAVE_vsx_movv16qi_64bit (TARGET_POWERPC64 && VECTOR_MEM_VSX_P (V16QImode) \
   && (register_operand (operands[0], V16QImode)  \
       || register_operand (operands[1], V16QImode)))
#define HAVE_vsx_movv8hi_64bit (TARGET_POWERPC64 && VECTOR_MEM_VSX_P (V8HImode) \
   && (register_operand (operands[0], V8HImode)  \
       || register_operand (operands[1], V8HImode)))
#define HAVE_vsx_movv4si_64bit (TARGET_POWERPC64 && VECTOR_MEM_VSX_P (V4SImode) \
   && (register_operand (operands[0], V4SImode)  \
       || register_operand (operands[1], V4SImode)))
#define HAVE_vsx_movv2di_64bit (TARGET_POWERPC64 && VECTOR_MEM_VSX_P (V2DImode) \
   && (register_operand (operands[0], V2DImode)  \
       || register_operand (operands[1], V2DImode)))
#define HAVE_vsx_movv4sf_64bit (TARGET_POWERPC64 && VECTOR_MEM_VSX_P (V4SFmode) \
   && (register_operand (operands[0], V4SFmode)  \
       || register_operand (operands[1], V4SFmode)))
#define HAVE_vsx_movv2df_64bit (TARGET_POWERPC64 && VECTOR_MEM_VSX_P (V2DFmode) \
   && (register_operand (operands[0], V2DFmode)  \
       || register_operand (operands[1], V2DFmode)))
#define HAVE_vsx_movv1ti_64bit (TARGET_POWERPC64 && VECTOR_MEM_VSX_P (V1TImode) \
   && (register_operand (operands[0], V1TImode)  \
       || register_operand (operands[1], V1TImode)))
#define HAVE_vsx_movkf_64bit ((TARGET_POWERPC64 && VECTOR_MEM_VSX_P (KFmode) \
   && (register_operand (operands[0], KFmode)  \
       || register_operand (operands[1], KFmode))) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_vsx_movtf_64bit ((TARGET_POWERPC64 && VECTOR_MEM_VSX_P (TFmode) \
   && (register_operand (operands[0], TFmode)  \
       || register_operand (operands[1], TFmode))) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_vsx_movti_64bit (TARGET_POWERPC64 && VECTOR_MEM_VSX_P (TImode) \
   && (register_operand (operands[0], TImode)  \
       || register_operand (operands[1], TImode)))
#define HAVE_vsx_lxvrbx (TARGET_POWER10)
#define HAVE_vsx_lxvrhx (TARGET_POWER10)
#define HAVE_vsx_lxvrwx (TARGET_POWER10)
#define HAVE_vsx_lxvrdx (TARGET_POWER10)
#define HAVE_vsx_stxvrbx (TARGET_POWER10)
#define HAVE_vsx_stxvrhx (TARGET_POWER10)
#define HAVE_vsx_stxvrwx (TARGET_POWER10)
#define HAVE_vsx_stxvrdx (TARGET_POWER10)
#define HAVE_vsx_ld_elemrev_v2di (VECTOR_MEM_VSX_P (V2DImode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_ld_elemrev_v1ti (VECTOR_MEM_VSX_P (V1TImode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_ld_elemrev_v2df (VECTOR_MEM_VSX_P (V2DFmode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_ld_elemrev_v4si (VECTOR_MEM_VSX_P (V4SImode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_ld_elemrev_v4sf (VECTOR_MEM_VSX_P (V4SFmode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_ld_elemrev_v16qi_internal (VECTOR_MEM_VSX_P (V16QImode) && !BYTES_BIG_ENDIAN && TARGET_P9_VECTOR)
#define HAVE_vsx_st_elemrev_v1ti (VECTOR_MEM_VSX_P (V2DImode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_st_elemrev_v2df (VECTOR_MEM_VSX_P (V2DFmode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_st_elemrev_v2di (VECTOR_MEM_VSX_P (V2DImode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_st_elemrev_v4sf (VECTOR_MEM_VSX_P (V4SFmode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_st_elemrev_v4si (VECTOR_MEM_VSX_P (V4SImode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_mul_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_div_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_udiv_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_div_v1ti (TARGET_POWER10)
#define HAVE_vsx_udiv_v1ti (TARGET_POWER10)
#define HAVE_vsx_dives_v1ti (TARGET_POWER10)
#define HAVE_vsx_diveu_v1ti (TARGET_POWER10)
#define HAVE_vsx_mods_v1ti (TARGET_POWER10)
#define HAVE_vsx_modu_v1ti (TARGET_POWER10)
#define HAVE_vsx_frev4sf2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_frev2df2 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_nabsv4sf2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_nabsv2df2 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_smaxv4sf3 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_smaxv2df3 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_eqv4sf (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_eqv2df (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_gtv4sf (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_gtv2df (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_copysignv4sf3 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_copysignv2df3 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_floatv4siv4sf2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_floatv2div2df2 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_floatunsv4siv4sf2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_floatunsv2div2df2 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_fix_truncv4sfv4si2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_fix_truncv2dfv2di2 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_fixuns_truncv4sfv4si2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_fixuns_truncv2dfv2di2 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xsrdpi (VECTOR_UNIT_VSX_P (DFmode))
#define HAVE_vsx_xvrspi (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_xvrdpi (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xsrdpic (VECTOR_UNIT_VSX_P (DFmode))
#define HAVE_vsx_xvrspic (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_xvrdpic (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_btruncv4sf2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_btruncv2df2 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_floorv4sf2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_floorv2df2 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_ceilv4sf2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_ceilv2df2 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xscvdpsp (VECTOR_UNIT_VSX_P (DFmode))
#define HAVE_vsx_xvcvspdp_be (VECTOR_UNIT_VSX_P (V4SFmode) && BYTES_BIG_ENDIAN)
#define HAVE_vsx_xvcvspdp_le (VECTOR_UNIT_VSX_P (V4SFmode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_xvcvdpsp (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xscvspdp (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_xscvspdp_scalar2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_xvcvhpsp (TARGET_P9_VECTOR)
#define HAVE_vsx_xvcvsphp (TARGET_P9_VECTOR)
#define HAVE_vsx_xscvdpsp_scalar (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_xscvdpspn (TARGET_XSCVDPSPN)
#define HAVE_vsx_xscvspdpn (TARGET_XSCVSPDPN)
#define HAVE_vsx_xscvdpspn_scalar (TARGET_XSCVDPSPN)
#define HAVE_vsx_xscvspdpn_directmove (TARGET_XSCVSPDPN)
#define HAVE_vsx_xvcvsxwsp (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_xvcvuxwsp (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_xvcvsxddp (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvuxddp (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvspsxws (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_xvcvspuxws (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_xvcvdpsxds (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvdpuxds (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvdpsxws (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvdpuxws (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvsxdsp (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvuxdsp (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvsxwdp_be (VECTOR_UNIT_VSX_P (V2DFmode) && BYTES_BIG_ENDIAN)
#define HAVE_vsx_xvcvuxwdp_be (VECTOR_UNIT_VSX_P (V2DFmode) && BYTES_BIG_ENDIAN)
#define HAVE_vsx_xvcvsxwdp_le (VECTOR_UNIT_VSX_P (V2DFmode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_xvcvuxwdp_le (VECTOR_UNIT_VSX_P (V2DFmode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_xvcvsxwdp_df (TARGET_VSX)
#define HAVE_vsx_xvcvuxwdp_df (TARGET_VSX)
#define HAVE_vsx_xvcvspsxds_be (VECTOR_UNIT_VSX_P (V2DFmode) && BYTES_BIG_ENDIAN)
#define HAVE_vsx_xvcvspuxds_be (VECTOR_UNIT_VSX_P (V2DFmode) && BYTES_BIG_ENDIAN)
#define HAVE_vsx_xvcvspsxds_le (VECTOR_UNIT_VSX_P (V2DFmode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_xvcvspuxds_le (VECTOR_UNIT_VSX_P (V2DFmode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_concat_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_concat_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_concat_v2sf (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_xxswapd_v16qi (TARGET_VSX)
#define HAVE_xxswapd_v8hi (TARGET_VSX)
#define HAVE_xxswapd_v4sf (TARGET_VSX)
#define HAVE_xxswapd_v4si (TARGET_VSX)
#define HAVE_xxswapd_v2df (TARGET_VSX)
#define HAVE_xxswapd_v2di (TARGET_VSX)
#define HAVE_xxswapd_v1ti (TARGET_POWER10)
#define HAVE_xxgenpcvm_v16qi_internal (TARGET_POWER10)
#define HAVE_xxgenpcvm_v8hi_internal (TARGET_POWER10)
#define HAVE_xxgenpcvm_v4si_internal (TARGET_POWER10)
#define HAVE_xxgenpcvm_v2di_internal (TARGET_POWER10)
#define HAVE_vsx_extract_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_extract_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_vslo_v2df (VECTOR_MEM_VSX_P (V2DFmode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_vslo_v2di (VECTOR_MEM_VSX_P (V2DImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_extract_v2df_var (VECTOR_MEM_VSX_P (V2DFmode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_extract_v2di_var (VECTOR_MEM_VSX_P (V2DImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_extract_v4sf (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_extract_v4sf_var (VECTOR_MEM_VSX_P (V4SFmode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_xxpermdi2_v2df_1 (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_xxpermdi2_v2di_1 (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_extract_v16qi_p9 (VECTOR_MEM_VSX_P (V16QImode) && TARGET_VEXTRACTUB)
#define HAVE_vsx_extract_v8hi_p9 (VECTOR_MEM_VSX_P (V8HImode) && TARGET_VEXTRACTUB)
#define HAVE_vsx_extract_v4si_p9 (VECTOR_MEM_VSX_P (V4SImode) && TARGET_VEXTRACTUB)
#define HAVE_vsx_extract_v16qi_var (VECTOR_MEM_VSX_P (V16QImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_extract_v8hi_var (VECTOR_MEM_VSX_P (V8HImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_extract_v4si_var (VECTOR_MEM_VSX_P (V4SImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vextractlv16qi_internal (TARGET_POWER10)
#define HAVE_vextractlv8hi_internal (TARGET_POWER10)
#define HAVE_vextractlv4si_internal (TARGET_POWER10)
#define HAVE_vextractlv2di_internal (TARGET_POWER10)
#define HAVE_vextractrv16qi_internal (TARGET_POWER10)
#define HAVE_vextractrv8hi_internal (TARGET_POWER10)
#define HAVE_vextractrv4si_internal (TARGET_POWER10)
#define HAVE_vextractrv2di_internal (TARGET_POWER10)
#define HAVE_vinsertvl_internal_v16qi (TARGET_POWER10)
#define HAVE_vinsertvl_internal_v8hi (TARGET_POWER10)
#define HAVE_vinsertvl_internal_v4si (TARGET_POWER10)
#define HAVE_vinsertvl_internal_v2di (TARGET_POWER10)
#define HAVE_vinsertvr_internal_v16qi (TARGET_POWER10)
#define HAVE_vinsertvr_internal_v8hi (TARGET_POWER10)
#define HAVE_vinsertvr_internal_v4si (TARGET_POWER10)
#define HAVE_vinsertvr_internal_v2di (TARGET_POWER10)
#define HAVE_vinsertgl_internal_v16qi (TARGET_POWER10)
#define HAVE_vinsertgl_internal_v8hi (TARGET_POWER10)
#define HAVE_vinsertgl_internal_v4si (TARGET_POWER10)
#define HAVE_vinsertgl_internal_v2di (TARGET_POWER10)
#define HAVE_vinsertgr_internal_v16qi (TARGET_POWER10)
#define HAVE_vinsertgr_internal_v8hi (TARGET_POWER10)
#define HAVE_vinsertgr_internal_v4si (TARGET_POWER10)
#define HAVE_vinsertgr_internal_v2di (TARGET_POWER10)
#define HAVE_vreplace_elt_v4si_inst (TARGET_POWER10)
#define HAVE_vreplace_elt_v4sf_inst (TARGET_POWER10)
#define HAVE_vreplace_elt_v2di_inst (TARGET_POWER10)
#define HAVE_vreplace_elt_v2df_inst (TARGET_POWER10)
#define HAVE_vsx_set_v16qi_p9 (VECTOR_MEM_VSX_P (V16QImode) && TARGET_P9_VECTOR && TARGET_POWERPC64)
#define HAVE_vsx_set_v8hi_p9 (VECTOR_MEM_VSX_P (V8HImode) && TARGET_P9_VECTOR && TARGET_POWERPC64)
#define HAVE_vsx_set_v4si_p9 (VECTOR_MEM_VSX_P (V4SImode) && TARGET_P9_VECTOR && TARGET_POWERPC64)
#define HAVE_vsx_set_v4sf_p9 (VECTOR_MEM_VSX_P (V4SFmode) && TARGET_P9_VECTOR && TARGET_POWERPC64)
#define HAVE_vsx_splat_v2df_reg (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_splat_v2di_reg (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_splat_v2df_mem (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_splat_v2di_mem (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_splat_v4si (TARGET_P9_VECTOR)
#define HAVE_vsx_splat_v4si_di (VECTOR_MEM_VSX_P (V4SImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_splat_v4sf (TARGET_P9_VECTOR)
#define HAVE_vsx_xxspltw_v4sf (VECTOR_MEM_VSX_P (V4SFmode))
#define HAVE_vsx_xxspltw_v4si (VECTOR_MEM_VSX_P (V4SImode))
#define HAVE_vsx_xxspltw_v4sf_direct (VECTOR_MEM_VSX_P (V4SFmode))
#define HAVE_vsx_xxspltw_v4si_direct (VECTOR_MEM_VSX_P (V4SImode))
#define HAVE_vsx_vspltb_di (VECTOR_MEM_VSX_P (V16QImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_vsplth_di (VECTOR_MEM_VSX_P (V8HImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_xxspltd_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_xxspltd_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_xxmrghw_v4sf (VECTOR_MEM_VSX_P (V4SFmode))
#define HAVE_vsx_xxmrghw_v4si (VECTOR_MEM_VSX_P (V4SImode))
#define HAVE_vsx_xxmrglw_v4sf (VECTOR_MEM_VSX_P (V4SFmode))
#define HAVE_vsx_xxmrglw_v4si (VECTOR_MEM_VSX_P (V4SImode))
#define HAVE_vsx_xxsldwi_v16qi (VECTOR_MEM_VSX_P (V16QImode))
#define HAVE_vsx_xxsldwi_v8hi (VECTOR_MEM_VSX_P (V8HImode))
#define HAVE_vsx_xxsldwi_v4si (VECTOR_MEM_VSX_P (V4SImode))
#define HAVE_vsx_xxsldwi_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_xxsldwi_v4sf (VECTOR_MEM_VSX_P (V4SFmode))
#define HAVE_vsx_xxsldwi_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_xxsldwi_v1ti (VECTOR_MEM_VSX_P (V1TImode))
#define HAVE_vsx_xxsldwi_ti (VECTOR_MEM_VSX_P (TImode))
#define HAVE_vsx_xxsldwi_kf ((VECTOR_MEM_VSX_P (KFmode)) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_vsx_xxsldwi_tf ((VECTOR_MEM_VSX_P (TFmode)) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_vsx_reduc_plus_v2df (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_reduc_smin_v2df (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_reduc_smax_v2df (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_reduc_plus_v4sf (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_reduc_smin_v4sf (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_reduc_smax_v4sf (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_sign_extend_v2di_v1ti (TARGET_POWER10)
#define HAVE_vsx_sign_extend_qi_v4si (TARGET_P9_VECTOR)
#define HAVE_vsx_sign_extend_qi_v2di (TARGET_P9_VECTOR)
#define HAVE_vsx_sign_extend_qi_di (TARGET_P9_VECTOR)
#define HAVE_vsx_sign_extend_qi_si (TARGET_P9_VECTOR)
#define HAVE_vsx_sign_extend_hi_v4si (TARGET_P9_VECTOR)
#define HAVE_vsx_sign_extend_hi_v2di (TARGET_P9_VECTOR)
#define HAVE_vsx_sign_extend_hi_di (TARGET_P9_VECTOR)
#define HAVE_vsx_sign_extend_hi_si (TARGET_P9_VECTOR)
#define HAVE_vsx_sign_extend_si_v2di (TARGET_P9_VECTOR)
#define HAVE_mtvsrdd_diti_w1 (TARGET_POWERPC64 && TARGET_DIRECT_MOVE)
#define HAVE_extendditi2_vector (TARGET_POWER10)
#define HAVE_xsxexpqp_kf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_xsxexpqp_tf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_xsxexpdp (TARGET_P9_VECTOR && TARGET_64BIT)
#define HAVE_xsxsigqp_kf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_xsxsigqp_tf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_xsxsigdp (TARGET_P9_VECTOR && TARGET_64BIT)
#define HAVE_xsiexpqpf_kf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_xsiexpqpf_tf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_xsiexpqp_kf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_xsiexpqp_tf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_xsiexpdp (TARGET_P9_VECTOR && TARGET_64BIT)
#define HAVE_xsiexpdpf (TARGET_P9_VECTOR && TARGET_64BIT)
#define HAVE_xvxexpsp (TARGET_P9_VECTOR)
#define HAVE_xvxexpdp (TARGET_P9_VECTOR)
#define HAVE_xvxsigsp (TARGET_P9_VECTOR)
#define HAVE_xvxsigdp (TARGET_P9_VECTOR)
#define HAVE_xviexpsp (TARGET_P9_VECTOR)
#define HAVE_xviexpdp (TARGET_P9_VECTOR)
#define HAVE_xvtstdcsp (TARGET_P9_VECTOR)
#define HAVE_xvtstdcdp (TARGET_P9_VECTOR)
#define HAVE_lxvll (TARGET_P9_VECTOR)
#define HAVE_stxvll (TARGET_P9_VECTOR)
#define HAVE_vcmpneb (TARGET_P9_VECTOR)
#define HAVE_vcmpnezb (TARGET_P9_VECTOR)
#define HAVE_vcmpnezb_p (TARGET_P9_VECTOR)
#define HAVE_vcmpneh (TARGET_P9_VECTOR)
#define HAVE_vcmpnezh (TARGET_P9_VECTOR)
#define HAVE_vcmpnew (TARGET_P9_VECTOR)
#define HAVE_vcmpnezw (TARGET_P9_VECTOR)
#define HAVE_vclzlsbb_v16qi (TARGET_P9_VECTOR)
#define HAVE_vclzlsbb_v8hi (TARGET_P9_VECTOR)
#define HAVE_vclzlsbb_v4si (TARGET_P9_VECTOR)
#define HAVE_vctzlsbb_v16qi (TARGET_P9_VECTOR)
#define HAVE_vctzlsbb_v8hi (TARGET_P9_VECTOR)
#define HAVE_vctzlsbb_v4si (TARGET_P9_VECTOR)
#define HAVE_vextublx (TARGET_P9_VECTOR)
#define HAVE_vextubrx (TARGET_P9_VECTOR)
#define HAVE_vextuhlx (TARGET_P9_VECTOR)
#define HAVE_vextuhrx (TARGET_P9_VECTOR)
#define HAVE_vextuwlx (TARGET_P9_VECTOR)
#define HAVE_vextuwrx (TARGET_P9_VECTOR)
#define HAVE_extract4b (TARGET_P9_VECTOR)
#define HAVE_p9_xxbrq_v1ti (TARGET_P9_VECTOR)
#define HAVE_p9_xxbrd_v2di (TARGET_P9_VECTOR)
#define HAVE_p9_xxbrw_v4si (TARGET_P9_VECTOR)
#define HAVE_p9_xxbrh_v8hi (TARGET_P9_VECTOR)
#define HAVE_vsx_xvcvspbf16 (TARGET_POWER10)
#define HAVE_vsx_xvcvbf16spn (TARGET_POWER10)
#define HAVE_vec_mtvsrbmi (TARGET_POWER10)
#define HAVE_vec_mtvsr_v16qi (TARGET_POWER10)
#define HAVE_vec_mtvsr_v8hi (TARGET_POWER10)
#define HAVE_vec_mtvsr_v4si (TARGET_POWER10)
#define HAVE_vec_mtvsr_v2di (TARGET_POWER10)
#define HAVE_vec_mtvsr_v1ti (TARGET_POWER10)
#define HAVE_vec_cntmb_v16qi (TARGET_POWER10)
#define HAVE_vec_cntmb_v8hi (TARGET_POWER10)
#define HAVE_vec_cntmb_v4si (TARGET_POWER10)
#define HAVE_vec_cntmb_v2di (TARGET_POWER10)
#define HAVE_vec_extract_v16qi (TARGET_POWER10)
#define HAVE_vec_extract_v8hi (TARGET_POWER10)
#define HAVE_vec_extract_v4si (TARGET_POWER10)
#define HAVE_vec_extract_v2di (TARGET_POWER10)
#define HAVE_vec_extract_v1ti (TARGET_POWER10)
#define HAVE_vec_expand_v16qi (TARGET_POWER10)
#define HAVE_vec_expand_v8hi (TARGET_POWER10)
#define HAVE_vec_expand_v4si (TARGET_POWER10)
#define HAVE_vec_expand_v2di (TARGET_POWER10)
#define HAVE_vec_expand_v1ti (TARGET_POWER10)
#define HAVE_dives_v2di (TARGET_POWER10)
#define HAVE_dives_v4si (TARGET_POWER10)
#define HAVE_diveu_v2di (TARGET_POWER10)
#define HAVE_diveu_v4si (TARGET_POWER10)
#define HAVE_divv2di3 (TARGET_POWER10)
#define HAVE_divv4si3 (TARGET_POWER10)
#define HAVE_udivv2di3 (TARGET_POWER10)
#define HAVE_udivv4si3 (TARGET_POWER10)
#define HAVE_mods_v2di (TARGET_POWER10)
#define HAVE_mods_v4si (TARGET_POWER10)
#define HAVE_modu_v2di (TARGET_POWER10)
#define HAVE_modu_v4si (TARGET_POWER10)
#define HAVE_mulhs_v2di (TARGET_POWER10)
#define HAVE_mulhs_v4si (TARGET_POWER10)
#define HAVE_mulhu_v2di (TARGET_POWER10)
#define HAVE_mulhu_v4si (TARGET_POWER10)
#define HAVE_mulv2di3 (TARGET_POWER10)
#define HAVE_get_vrsave_internal (TARGET_ALTIVEC)
#define HAVE_addv4si3 (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_addv8hi3 (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_addv16qi3 (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_addv2di3 (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vaddcuw (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vadduws (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vadduhs (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vaddubs (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_altivec_vaddsws (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vaddshs (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vaddsbs (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_subv4si3 (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_subv8hi3 (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_subv16qi3 (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_subv2di3 (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vsubcuw (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vsubuws (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vsubuhs (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vsububs (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_altivec_vsubsws (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vsubshs (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vsubsbs (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_uavgv4si3_ceil (TARGET_ALTIVEC)
#define HAVE_uavgv8hi3_ceil (TARGET_ALTIVEC)
#define HAVE_uavgv16qi3_ceil (TARGET_ALTIVEC)
#define HAVE_avgv4si3_ceil (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_avgv8hi3_ceil (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_avgv16qi3_ceil (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_altivec_vcmpbfp (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_eqv1ti (TARGET_POWER10)
#define HAVE_altivec_eqv4si (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_eqv8hi (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_eqv16qi (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_altivec_eqv2di (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_mulv4si3_p8 (TARGET_P8_VECTOR)
#define HAVE_vsldb_v4si (TARGET_POWER10)
#define HAVE_vsrdb_v4si (TARGET_POWER10)
#define HAVE_vsldb_v8hi (TARGET_POWER10)
#define HAVE_vsrdb_v8hi (TARGET_POWER10)
#define HAVE_vsldb_v16qi (TARGET_POWER10)
#define HAVE_vsrdb_v16qi (TARGET_POWER10)
#define HAVE_vsldb_v2di (TARGET_POWER10)
#define HAVE_vsrdb_v2di (TARGET_POWER10)
#define HAVE_xxspltiw_v4si (TARGET_POWER10)
#define HAVE_xxspltiw_v4sf_inst (TARGET_POWER10)
#define HAVE_xxspltidp_v2df_inst (TARGET_POWER10)
#define HAVE_xxsplti32dx_v4si_inst (TARGET_POWER10)
#define HAVE_xxsplti32dx_v4sf_inst (TARGET_POWER10)
#define HAVE_xxblend_v4si (TARGET_POWER10)
#define HAVE_xxblend_v8hi (TARGET_POWER10)
#define HAVE_xxblend_v16qi (TARGET_POWER10)
#define HAVE_xxblend_v4sf (TARGET_POWER10)
#define HAVE_xxblend_v2df (TARGET_POWER10)
#define HAVE_xxblend_v2di (TARGET_POWER10)
#define HAVE_xxpermx_inst (TARGET_POWER10)
#define HAVE_vstrir_code_v8hi (TARGET_POWER10)
#define HAVE_vstrir_code_v16qi (TARGET_POWER10)
#define HAVE_vstrir_p_code_v8hi (TARGET_POWER10)
#define HAVE_vstrir_p_code_v16qi (TARGET_POWER10)
#define HAVE_vstril_code_v8hi (TARGET_POWER10)
#define HAVE_vstril_code_v16qi (TARGET_POWER10)
#define HAVE_vstril_p_code_v8hi (TARGET_POWER10)
#define HAVE_vstril_p_code_v16qi (TARGET_POWER10)
#define HAVE_altivec_vmsumuhm (TARGET_ALTIVEC)
#define HAVE_altivec_vmsumubm (TARGET_ALTIVEC)
#define HAVE_altivec_vmsumudm (TARGET_P8_VECTOR)
#define HAVE_altivec_vmsummhm (TARGET_ALTIVEC)
#define HAVE_altivec_vmsummbm (TARGET_ALTIVEC)
#define HAVE_altivec_vmsumshm (TARGET_ALTIVEC)
#define HAVE_altivec_vmsumuhs (TARGET_ALTIVEC)
#define HAVE_altivec_vmsumshs (TARGET_ALTIVEC)
#define HAVE_umaxv4si3 (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_umaxv8hi3 (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_umaxv16qi3 (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_umaxv2di3 (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_smaxv4si3 (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_smaxv8hi3 (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_smaxv16qi3 (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_smaxv2di3 (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_uminv4si3 (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_uminv8hi3 (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_uminv16qi3 (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_uminv2di3 (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_sminv4si3 (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_sminv8hi3 (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_sminv16qi3 (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_sminv2di3 (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vmhaddshs (TARGET_ALTIVEC)
#define HAVE_altivec_vmhraddshs (TARGET_ALTIVEC)
#define HAVE_fmav8hi4 (TARGET_ALTIVEC)
#define HAVE_altivec_vmrghb_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vmrghh_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vmrghw_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vmrglb_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vmrglh_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vmrglw_direct (TARGET_ALTIVEC)
#define HAVE_p8_vmrgew_v4sf (TARGET_P8_VECTOR)
#define HAVE_p8_vmrgew_v4si (TARGET_P8_VECTOR)
#define HAVE_p8_vmrgow_v4sf (TARGET_P8_VECTOR)
#define HAVE_p8_vmrgow_v4si (TARGET_P8_VECTOR)
#define HAVE_p8_vmrgew_v4sf_direct (TARGET_P8_VECTOR)
#define HAVE_p8_vmrgew_v4si_direct (TARGET_P8_VECTOR)
#define HAVE_p8_vmrgow_v4sf_direct (TARGET_P8_VECTOR)
#define HAVE_p8_vmrgow_v4si_direct (TARGET_P8_VECTOR)
#define HAVE_altivec_vmuleub (TARGET_ALTIVEC)
#define HAVE_altivec_vmuloub (TARGET_ALTIVEC)
#define HAVE_altivec_vmulesb (TARGET_ALTIVEC)
#define HAVE_altivec_vmulosb (TARGET_ALTIVEC)
#define HAVE_altivec_vmuleuh (TARGET_ALTIVEC)
#define HAVE_altivec_vmulouh (TARGET_ALTIVEC)
#define HAVE_altivec_vmulesh (TARGET_ALTIVEC)
#define HAVE_altivec_vmulosh (TARGET_ALTIVEC)
#define HAVE_altivec_vmuleuw (TARGET_P8_VECTOR)
#define HAVE_altivec_vmuleud (TARGET_POWER10)
#define HAVE_altivec_vmulouw (TARGET_P8_VECTOR)
#define HAVE_altivec_vmuloud (TARGET_POWER10)
#define HAVE_altivec_vmulesw (TARGET_P8_VECTOR)
#define HAVE_altivec_vmulesd (TARGET_POWER10)
#define HAVE_altivec_vmulosw (TARGET_P8_VECTOR)
#define HAVE_altivec_vmulosd (TARGET_POWER10)
#define HAVE_altivec_vpkpx (TARGET_ALTIVEC)
#define HAVE_altivec_vpksdss (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vpkswss (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vpkshss (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vpksdus (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vpkswus (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vpkshus (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vpkudus (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vpkuwus (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vpkuhus (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vpkudum (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vpkuwum (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vpkuhum (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vpkudum_direct (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vpkuwum_direct (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vpkuhum_direct (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vrlq (TARGET_POWER10)
#define HAVE_altivec_vrldmi (TARGET_P9_VECTOR)
#define HAVE_altivec_vrlwmi (TARGET_P9_VECTOR)
#define HAVE_altivec_vrlqmi_inst (TARGET_POWER10)
#define HAVE_altivec_vrldnm (TARGET_P9_VECTOR)
#define HAVE_altivec_vrlwnm (TARGET_P9_VECTOR)
#define HAVE_altivec_vrlqnm_inst (TARGET_POWER10)
#define HAVE_altivec_vsl (TARGET_ALTIVEC)
#define HAVE_altivec_vslo (TARGET_ALTIVEC)
#define HAVE_vslv (TARGET_P9_VECTOR)
#define HAVE_vsrv (TARGET_P9_VECTOR)
#define HAVE_altivec_vslq_v1ti (TARGET_POWER10)
#define HAVE_altivec_vslq_ti (TARGET_POWER10)
#define HAVE_altivec_vsrq_v1ti (TARGET_POWER10)
#define HAVE_altivec_vsrq_ti (TARGET_POWER10)
#define HAVE_altivec_vsraq (TARGET_POWER10)
#define HAVE_altivec_vsr (TARGET_ALTIVEC)
#define HAVE_altivec_vsro (TARGET_ALTIVEC)
#define HAVE_altivec_vsum4ubs (TARGET_ALTIVEC)
#define HAVE_altivec_vsum4shs (TARGET_ALTIVEC)
#define HAVE_altivec_vsum4sbs (TARGET_ALTIVEC)
#define HAVE_altivec_vsum2sws_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vsumsws_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vspltb_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vsplth_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vspltw_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vspltisw (TARGET_ALTIVEC)
#define HAVE_altivec_vspltish (TARGET_ALTIVEC)
#define HAVE_altivec_vspltisb (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v4si_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v8hi_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v16qi_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v4sf_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v2df_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v2di_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v1ti_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_ti_direct (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_kf_direct ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_altivec_vperm_tf_direct ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_altivec_vperm_v8hiv16qi (TARGET_ALTIVEC)
#define HAVE_altivec_vrfip (TARGET_ALTIVEC)
#define HAVE_altivec_vrfin (TARGET_ALTIVEC)
#define HAVE_altivec_vcfux (TARGET_ALTIVEC)
#define HAVE_altivec_vcfsx (TARGET_ALTIVEC)
#define HAVE_altivec_vctuxs (TARGET_ALTIVEC)
#define HAVE_altivec_vctsxs (TARGET_ALTIVEC)
#define HAVE_altivec_vlogefp (TARGET_ALTIVEC)
#define HAVE_altivec_vexptefp (TARGET_ALTIVEC)
#define HAVE_altivec_vrefp (VECTOR_UNIT_ALTIVEC_P (V4SFmode))
#define HAVE_altivec_vsldoi_v4si (TARGET_ALTIVEC)
#define HAVE_altivec_vsldoi_v8hi (TARGET_ALTIVEC)
#define HAVE_altivec_vsldoi_v16qi (TARGET_ALTIVEC)
#define HAVE_altivec_vsldoi_v4sf (TARGET_ALTIVEC)
#define HAVE_altivec_vsldoi_v2df (TARGET_ALTIVEC)
#define HAVE_altivec_vsldoi_v2di (TARGET_ALTIVEC)
#define HAVE_altivec_vsldoi_v1ti (TARGET_ALTIVEC)
#define HAVE_altivec_vsldoi_ti (TARGET_ALTIVEC)
#define HAVE_altivec_vsldoi_kf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_altivec_vsldoi_tf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_altivec_vupkhsw (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vupkhsh (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vupkhsb (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vupklsw (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vupklsh (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vupklsb (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vupkhpx (TARGET_ALTIVEC)
#define HAVE_altivec_vupklpx (TARGET_ALTIVEC)
#define HAVE_altivec_vcmpequw_p (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vcmpequh_p (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_altivec_vcmpequb_p (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_altivec_vcmpequd_p (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_vcmpequt_p (TARGET_POWER10)
#define HAVE_altivec_vcmpbfp_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_altivec_mtvscr (TARGET_ALTIVEC)
#define HAVE_altivec_mfvscr (TARGET_ALTIVEC)
#define HAVE_altivec_dssall (TARGET_ALTIVEC)
#define HAVE_altivec_dss (TARGET_ALTIVEC)
#define HAVE_altivec_dst (TARGET_ALTIVEC && GET_MODE (operands[0]) == Pmode)
#define HAVE_altivec_dstt (TARGET_ALTIVEC && GET_MODE (operands[0]) == Pmode)
#define HAVE_altivec_dstst (TARGET_ALTIVEC && GET_MODE (operands[0]) == Pmode)
#define HAVE_altivec_dststt (TARGET_ALTIVEC && GET_MODE (operands[0]) == Pmode)
#define HAVE_altivec_lvsl_reg_si (TARGET_ALTIVEC)
#define HAVE_altivec_lvsl_reg_di ((TARGET_ALTIVEC) && (TARGET_POWERPC64))
#define HAVE_altivec_lvsl_direct (TARGET_ALTIVEC)
#define HAVE_altivec_lvsr_reg_si (TARGET_ALTIVEC)
#define HAVE_altivec_lvsr_reg_di ((TARGET_ALTIVEC) && (TARGET_POWERPC64))
#define HAVE_altivec_lvsr_direct (TARGET_ALTIVEC)
#define HAVE_altivec_lvewx (TARGET_ALTIVEC)
#define HAVE_altivec_lvehx (TARGET_ALTIVEC)
#define HAVE_altivec_lvebx (TARGET_ALTIVEC)
#define HAVE_altivec_lvxl_v4si (TARGET_ALTIVEC)
#define HAVE_altivec_lvxl_v8hi (TARGET_ALTIVEC)
#define HAVE_altivec_lvxl_v16qi (TARGET_ALTIVEC)
#define HAVE_altivec_lvxl_v4sf (TARGET_ALTIVEC)
#define HAVE_altivec_lvxl_v2df (TARGET_ALTIVEC)
#define HAVE_altivec_lvxl_v2di (TARGET_ALTIVEC)
#define HAVE_altivec_lvxl_v1ti (TARGET_ALTIVEC)
#define HAVE_altivec_lvxl_kf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_altivec_lvxl_tf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_altivec_lvx_v4si_internal (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v8hi_internal (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v16qi_internal (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v4sf_internal (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v2df_internal (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v2di_internal (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v1ti_internal (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_kf_internal ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_altivec_lvx_tf_internal ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_altivec_lvx_v4si_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v4si_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v8hi_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v8hi_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v16qi_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v16qi_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v4sf_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v4sf_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v2df_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v2df_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v2di_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v2di_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v1ti_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v1ti_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_kf_2op_si ((TARGET_ALTIVEC) && (((((FLOAT128_VECTOR_P (KFmode)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (TARGET_32BIT)))
#define HAVE_altivec_lvx_kf_2op_di ((TARGET_ALTIVEC) && (((((FLOAT128_VECTOR_P (KFmode)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (TARGET_64BIT)))
#define HAVE_altivec_lvx_tf_2op_si ((TARGET_ALTIVEC) && (((((FLOAT128_VECTOR_P (TFmode)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (TARGET_32BIT)))
#define HAVE_altivec_lvx_tf_2op_di ((TARGET_ALTIVEC) && (((((FLOAT128_VECTOR_P (TFmode)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (TARGET_64BIT)))
#define HAVE_altivec_lvx_v4si_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v4si_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v8hi_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v8hi_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v16qi_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v16qi_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v4sf_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v4sf_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v2df_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v2df_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v2di_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v2di_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_v1ti_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_lvx_v1ti_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_lvx_kf_1op_si ((TARGET_ALTIVEC) && (((FLOAT128_VECTOR_P (KFmode)) && (TARGET_32BIT)) && (TARGET_32BIT)))
#define HAVE_altivec_lvx_kf_1op_di ((TARGET_ALTIVEC) && (((FLOAT128_VECTOR_P (KFmode)) && (TARGET_64BIT)) && (TARGET_64BIT)))
#define HAVE_altivec_lvx_tf_1op_si ((TARGET_ALTIVEC) && (((FLOAT128_VECTOR_P (TFmode)) && (TARGET_32BIT)) && (TARGET_32BIT)))
#define HAVE_altivec_lvx_tf_1op_di ((TARGET_ALTIVEC) && (((FLOAT128_VECTOR_P (TFmode)) && (TARGET_64BIT)) && (TARGET_64BIT)))
#define HAVE_altivec_stvx_v4si_internal (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v8hi_internal (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v16qi_internal (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v4sf_internal (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v2df_internal (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v2di_internal (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v1ti_internal (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_kf_internal ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_altivec_stvx_tf_internal ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_altivec_stvx_v4si_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v4si_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v8hi_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v8hi_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v16qi_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v16qi_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v4sf_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v4sf_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v2df_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v2df_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v2di_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v2di_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v1ti_2op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v1ti_2op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_kf_2op_si ((TARGET_ALTIVEC) && ((((((FLOAT128_VECTOR_P (KFmode)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (FLOAT128_VECTOR_P (KFmode))))
#define HAVE_altivec_stvx_kf_2op_di ((TARGET_ALTIVEC) && ((((((FLOAT128_VECTOR_P (KFmode)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (FLOAT128_VECTOR_P (KFmode))))
#define HAVE_altivec_stvx_tf_2op_si ((TARGET_ALTIVEC) && ((((((FLOAT128_VECTOR_P (TFmode)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (FLOAT128_VECTOR_P (TFmode))))
#define HAVE_altivec_stvx_tf_2op_di ((TARGET_ALTIVEC) && ((((((FLOAT128_VECTOR_P (TFmode)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (FLOAT128_VECTOR_P (TFmode))))
#define HAVE_altivec_stvx_v4si_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v4si_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v8hi_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v8hi_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v16qi_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v16qi_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v4sf_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v4sf_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v2df_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v2df_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v2di_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v2di_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_v1ti_1op_si ((TARGET_ALTIVEC) && (TARGET_32BIT))
#define HAVE_altivec_stvx_v1ti_1op_di ((TARGET_ALTIVEC) && (TARGET_64BIT))
#define HAVE_altivec_stvx_kf_1op_si ((TARGET_ALTIVEC) && ((((FLOAT128_VECTOR_P (KFmode)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (FLOAT128_VECTOR_P (KFmode))))
#define HAVE_altivec_stvx_kf_1op_di ((TARGET_ALTIVEC) && ((((FLOAT128_VECTOR_P (KFmode)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (FLOAT128_VECTOR_P (KFmode))))
#define HAVE_altivec_stvx_tf_1op_si ((TARGET_ALTIVEC) && ((((FLOAT128_VECTOR_P (TFmode)) && (TARGET_32BIT)) && (TARGET_32BIT)) && (FLOAT128_VECTOR_P (TFmode))))
#define HAVE_altivec_stvx_tf_1op_di ((TARGET_ALTIVEC) && ((((FLOAT128_VECTOR_P (TFmode)) && (TARGET_64BIT)) && (TARGET_64BIT)) && (FLOAT128_VECTOR_P (TFmode))))
#define HAVE_altivec_stvxl_v4si (TARGET_ALTIVEC)
#define HAVE_altivec_stvxl_v8hi (TARGET_ALTIVEC)
#define HAVE_altivec_stvxl_v16qi (TARGET_ALTIVEC)
#define HAVE_altivec_stvxl_v4sf (TARGET_ALTIVEC)
#define HAVE_altivec_stvxl_v2df (TARGET_ALTIVEC)
#define HAVE_altivec_stvxl_v2di (TARGET_ALTIVEC)
#define HAVE_altivec_stvxl_v1ti (TARGET_ALTIVEC)
#define HAVE_altivec_stvxl_kf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_altivec_stvxl_tf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_altivec_stvewx (TARGET_ALTIVEC)
#define HAVE_altivec_stvehx (TARGET_ALTIVEC)
#define HAVE_altivec_stvebx (TARGET_ALTIVEC)
#define HAVE_vperm_v8hiv4si (TARGET_ALTIVEC)
#define HAVE_vperm_v16qiv8hi (TARGET_ALTIVEC)
#define HAVE_xxeval (TARGET_POWER10)
#define HAVE_altivec_lvlx (TARGET_ALTIVEC && rs6000_cpu == PROCESSOR_CELL)
#define HAVE_altivec_lvlxl (TARGET_ALTIVEC && rs6000_cpu == PROCESSOR_CELL)
#define HAVE_altivec_lvrx (TARGET_ALTIVEC && rs6000_cpu == PROCESSOR_CELL)
#define HAVE_altivec_lvrxl (TARGET_ALTIVEC && rs6000_cpu == PROCESSOR_CELL)
#define HAVE_altivec_stvlx (TARGET_ALTIVEC && rs6000_cpu == PROCESSOR_CELL)
#define HAVE_altivec_stvlxl (TARGET_ALTIVEC && rs6000_cpu == PROCESSOR_CELL)
#define HAVE_altivec_stvrx (TARGET_ALTIVEC && rs6000_cpu == PROCESSOR_CELL)
#define HAVE_altivec_stvrxl (TARGET_ALTIVEC && rs6000_cpu == PROCESSOR_CELL)
#define HAVE_p9_vaduv4si3 (TARGET_P9_VECTOR)
#define HAVE_p9_vaduv8hi3 (TARGET_P9_VECTOR)
#define HAVE_p9_vaduv16qi3 (TARGET_P9_VECTOR)
#define HAVE_p8v_vgbbd (TARGET_P8_VECTOR)
#define HAVE_altivec_vadduqm (TARGET_VADDUQM)
#define HAVE_altivec_vaddcuq (TARGET_VADDUQM)
#define HAVE_altivec_vsubuqm (TARGET_VADDUQM)
#define HAVE_altivec_vsubcuq (TARGET_VADDUQM)
#define HAVE_altivec_vaddeuqm (TARGET_VADDUQM)
#define HAVE_altivec_vaddecuq (TARGET_VADDUQM)
#define HAVE_altivec_vsubeuqm (TARGET_VADDUQM)
#define HAVE_altivec_vsubecuq (TARGET_VADDUQM)
#define HAVE_altivec_vbpermq (TARGET_P8_VECTOR)
#define HAVE_altivec_vbpermq2 (TARGET_P8_VECTOR)
#define HAVE_altivec_vbpermd (TARGET_P9_VECTOR)
#define HAVE_bcdadd_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdsub_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdadd_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdsub_v16qi (TARGET_P8_VECTOR)
#define HAVE_vcfuged (TARGET_POWER10)
#define HAVE_vclzdm (TARGET_POWER10)
#define HAVE_vctzdm (TARGET_POWER10)
#define HAVE_vpdepd (TARGET_POWER10)
#define HAVE_vpextd (TARGET_POWER10)
#define HAVE_vgnb (TARGET_POWER10)
#define HAVE_vclrlb (TARGET_POWER10)
#define HAVE_vclrrb (TARGET_POWER10)
#define HAVE_bcdshift_v16qi (TARGET_P8_VECTOR)
#define HAVE_mma_xxmfacc (TARGET_MMA)
#define HAVE_mma_xxmtacc (TARGET_MMA)
#define HAVE_mma_xvi4ger8 (TARGET_MMA)
#define HAVE_mma_xvi8ger4 (TARGET_MMA)
#define HAVE_mma_xvi16ger2 (TARGET_MMA)
#define HAVE_mma_xvi16ger2s (TARGET_MMA)
#define HAVE_mma_xvf16ger2 (TARGET_MMA)
#define HAVE_mma_xvbf16ger2 (TARGET_MMA)
#define HAVE_mma_xvf32ger (TARGET_MMA)
#define HAVE_mma_xvi4ger8pp (TARGET_MMA)
#define HAVE_mma_xvi8ger4pp (TARGET_MMA)
#define HAVE_mma_xvi8ger4spp (TARGET_MMA)
#define HAVE_mma_xvi16ger2pp (TARGET_MMA)
#define HAVE_mma_xvi16ger2spp (TARGET_MMA)
#define HAVE_mma_xvf16ger2pp (TARGET_MMA)
#define HAVE_mma_xvf16ger2pn (TARGET_MMA)
#define HAVE_mma_xvf16ger2np (TARGET_MMA)
#define HAVE_mma_xvf16ger2nn (TARGET_MMA)
#define HAVE_mma_xvbf16ger2pp (TARGET_MMA)
#define HAVE_mma_xvbf16ger2pn (TARGET_MMA)
#define HAVE_mma_xvbf16ger2np (TARGET_MMA)
#define HAVE_mma_xvbf16ger2nn (TARGET_MMA)
#define HAVE_mma_xvf32gerpp (TARGET_MMA)
#define HAVE_mma_xvf32gerpn (TARGET_MMA)
#define HAVE_mma_xvf32gernp (TARGET_MMA)
#define HAVE_mma_xvf32gernn (TARGET_MMA)
#define HAVE_mma_xvf64ger (TARGET_MMA)
#define HAVE_mma_xvf64gerpp (TARGET_MMA)
#define HAVE_mma_xvf64gerpn (TARGET_MMA)
#define HAVE_mma_xvf64gernp (TARGET_MMA)
#define HAVE_mma_xvf64gernn (TARGET_MMA)
#define HAVE_mma_pmxvi4ger8 (TARGET_MMA)
#define HAVE_mma_pmxvi4ger8pp (TARGET_MMA)
#define HAVE_mma_pmxvi16ger2 (TARGET_MMA)
#define HAVE_mma_pmxvi16ger2s (TARGET_MMA)
#define HAVE_mma_pmxvf16ger2 (TARGET_MMA)
#define HAVE_mma_pmxvbf16ger2 (TARGET_MMA)
#define HAVE_mma_pmxvi16ger2pp (TARGET_MMA)
#define HAVE_mma_pmxvi16ger2spp (TARGET_MMA)
#define HAVE_mma_pmxvf16ger2pp (TARGET_MMA)
#define HAVE_mma_pmxvf16ger2pn (TARGET_MMA)
#define HAVE_mma_pmxvf16ger2np (TARGET_MMA)
#define HAVE_mma_pmxvf16ger2nn (TARGET_MMA)
#define HAVE_mma_pmxvbf16ger2pp (TARGET_MMA)
#define HAVE_mma_pmxvbf16ger2pn (TARGET_MMA)
#define HAVE_mma_pmxvbf16ger2np (TARGET_MMA)
#define HAVE_mma_pmxvbf16ger2nn (TARGET_MMA)
#define HAVE_mma_pmxvf32ger (TARGET_MMA)
#define HAVE_mma_pmxvf32gerpp (TARGET_MMA)
#define HAVE_mma_pmxvf32gerpn (TARGET_MMA)
#define HAVE_mma_pmxvf32gernp (TARGET_MMA)
#define HAVE_mma_pmxvf32gernn (TARGET_MMA)
#define HAVE_mma_pmxvf64ger (TARGET_MMA)
#define HAVE_mma_pmxvf64gerpp (TARGET_MMA)
#define HAVE_mma_pmxvf64gerpn (TARGET_MMA)
#define HAVE_mma_pmxvf64gernp (TARGET_MMA)
#define HAVE_mma_pmxvf64gernn (TARGET_MMA)
#define HAVE_mma_pmxvi8ger4 (TARGET_MMA)
#define HAVE_mma_pmxvi8ger4pp (TARGET_MMA)
#define HAVE_mma_pmxvi8ger4spp (TARGET_MMA)
#define HAVE_movsd_store ((gpc_reg_operand (operands[0], DDmode) \
   || gpc_reg_operand (operands[1], SDmode)) \
   && TARGET_HARD_FLOAT)
#define HAVE_movsd_load ((gpc_reg_operand (operands[0], SDmode) \
   || gpc_reg_operand (operands[1], DDmode)) \
   && TARGET_HARD_FLOAT)
#define HAVE_extendsddd2 (TARGET_DFP)
#define HAVE_truncddsd2 (TARGET_DFP)
#define HAVE_negdd2 (TARGET_HARD_FLOAT)
#define HAVE_absdd2 (TARGET_HARD_FLOAT)
#define HAVE_negtd2 (TARGET_HARD_FLOAT)
#define HAVE_abstd2 (TARGET_HARD_FLOAT)
#define HAVE_extendddtd2 (TARGET_DFP)
#define HAVE_trunctddd2 (TARGET_DFP)
#define HAVE_trunctdsd2 (TARGET_DFP)
#define HAVE_adddd3 (TARGET_DFP)
#define HAVE_addtd3 (TARGET_DFP)
#define HAVE_subdd3 (TARGET_DFP)
#define HAVE_subtd3 (TARGET_DFP)
#define HAVE_muldd3 (TARGET_DFP)
#define HAVE_multd3 (TARGET_DFP)
#define HAVE_divdd3 (TARGET_DFP)
#define HAVE_divtd3 (TARGET_DFP)
#define HAVE_floatdidd2 (TARGET_DFP && TARGET_POPCNTD)
#define HAVE_floatditd2 (TARGET_DFP)
#define HAVE_floattitd2 (TARGET_POWER10)
#define HAVE_ftruncdd2 (TARGET_DFP)
#define HAVE_ftrunctd2 (TARGET_DFP)
#define HAVE_fixdddi2 (TARGET_DFP)
#define HAVE_fixtddi2 (TARGET_DFP)
#define HAVE_fixtdti2 (TARGET_POWER10)
#define HAVE_dfp_ddedpd_dd (TARGET_DFP)
#define HAVE_dfp_ddedpd_td (TARGET_DFP)
#define HAVE_dfp_denbcd_dd (TARGET_DFP)
#define HAVE_dfp_denbcd_td (TARGET_DFP)
#define HAVE_dfp_denbcd_v16qi_inst (TARGET_DFP)
#define HAVE_dfp_dxex_dd (TARGET_DFP)
#define HAVE_dfp_dxex_td (TARGET_DFP)
#define HAVE_dfp_diex_dd (TARGET_DFP)
#define HAVE_dfp_diex_td (TARGET_DFP)
#define HAVE_dfp_dscli_dd (TARGET_DFP)
#define HAVE_dfp_dscli_td (TARGET_DFP)
#define HAVE_dfp_dscri_dd (TARGET_DFP)
#define HAVE_dfp_dscri_td (TARGET_DFP)
#define HAVE_crypto_vcipher_v16qi (TARGET_CRYPTO)
#define HAVE_crypto_vncipher_v16qi (TARGET_CRYPTO)
#define HAVE_crypto_vcipherlast_v16qi (TARGET_CRYPTO)
#define HAVE_crypto_vncipherlast_v16qi (TARGET_CRYPTO)
#define HAVE_crypto_vcipher_v2di (TARGET_CRYPTO)
#define HAVE_crypto_vncipher_v2di (TARGET_CRYPTO)
#define HAVE_crypto_vcipherlast_v2di (TARGET_CRYPTO)
#define HAVE_crypto_vncipherlast_v2di (TARGET_CRYPTO)
#define HAVE_crypto_vpmsumb (TARGET_P8_VECTOR)
#define HAVE_crypto_vpmsumh (TARGET_P8_VECTOR)
#define HAVE_crypto_vpmsumw (TARGET_P8_VECTOR)
#define HAVE_crypto_vpmsumd (TARGET_P8_VECTOR)
#define HAVE_crypto_vpermxor_v16qi (TARGET_P8_VECTOR)
#define HAVE_crypto_vpermxor_v8hi (TARGET_P8_VECTOR)
#define HAVE_crypto_vpermxor_v4si (TARGET_P8_VECTOR)
#define HAVE_crypto_vpermxor_v2di (TARGET_P8_VECTOR)
#define HAVE_crypto_vsbox_v16qi (TARGET_CRYPTO)
#define HAVE_crypto_vsbox_v2di (TARGET_CRYPTO)
#define HAVE_crypto_vshasigmaw (TARGET_CRYPTO)
#define HAVE_crypto_vshasigmad (TARGET_CRYPTO)
#define HAVE_htm_mfspr_si (TARGET_HTM)
#define HAVE_htm_mfspr_di ((TARGET_HTM) && (TARGET_POWERPC64))
#define HAVE_htm_mtspr_si (TARGET_HTM)
#define HAVE_htm_mtspr_di ((TARGET_HTM) && (TARGET_POWERPC64))
#define HAVE_pcrel_opt_ld_addr (TARGET_PCREL_OPT \
   && reg_or_subregno (operands[0]) != reg_or_subregno (operands[3]))
#define HAVE_pcrel_opt_ld_addr_same_reg (TARGET_PCREL_OPT)
#define HAVE_extendhisi2 1
#define HAVE_extendhidi2 (TARGET_POWERPC64)
#define HAVE_strlensi (TARGET_DLMZB && WORDS_BIG_ENDIAN && !optimize_size)
#define HAVE_addsi3 1
#define HAVE_adddi3 1
#define HAVE_addsi3_carry_in 1
#define HAVE_adddi3_carry_in (TARGET_POWERPC64)
#define HAVE_one_cmplsi2 1
#define HAVE_one_cmpldi2 1
#define HAVE_subsi3 1
#define HAVE_subdi3 1
#define HAVE_subfsi3_carry_in 1
#define HAVE_subfdi3_carry_in (TARGET_POWERPC64)
#define HAVE_ctzsi2 1
#define HAVE_ctzdi2 (TARGET_POWERPC64)
#define HAVE_ffssi2 1
#define HAVE_ffsdi2 (TARGET_POWERPC64)
#define HAVE_popcountsi2 (TARGET_POPCNTB || TARGET_POPCNTD)
#define HAVE_popcountdi2 ((TARGET_POPCNTB || TARGET_POPCNTD) && (TARGET_POWERPC64))
#define HAVE_paritysi2 (TARGET_POPCNTB)
#define HAVE_paritydi2 ((TARGET_POPCNTB) && (TARGET_POWERPC64))
#define HAVE_bswaphi2 1
#define HAVE_bswapsi2 1
#define HAVE_bswapdi2 1
#define HAVE_smulsi3_highpart 1
#define HAVE_umulsi3_highpart 1
#define HAVE_smuldi3_highpart (TARGET_POWERPC64)
#define HAVE_umuldi3_highpart (TARGET_POWERPC64)
#define HAVE_mulsidi3 (!(SImode == SImode && TARGET_POWERPC64))
#define HAVE_umulsidi3 (!(SImode == SImode && TARGET_POWERPC64))
#define HAVE_mulditi3 ((!(DImode == SImode && TARGET_POWERPC64)) && (TARGET_POWERPC64))
#define HAVE_umulditi3 ((!(DImode == SImode && TARGET_POWERPC64)) && (TARGET_POWERPC64))
#define HAVE_divsi3 1
#define HAVE_divdi3 (TARGET_POWERPC64)
#define HAVE_modsi3 1
#define HAVE_moddi3 (TARGET_POWERPC64)
#define HAVE_andsi3 1
#define HAVE_anddi3 1
#define HAVE_iorsi3 1
#define HAVE_xorsi3 1
#define HAVE_iordi3 1
#define HAVE_xordi3 1
#define HAVE_recipsf3 (RS6000_RECIP_HAVE_RE_P (SFmode))
#define HAVE_recipdf3 (RS6000_RECIP_HAVE_RE_P (DFmode))
#define HAVE_recipv4sf3 (RS6000_RECIP_HAVE_RE_P (V4SFmode))
#define HAVE_recipv2df3 (RS6000_RECIP_HAVE_RE_P (V2DFmode))
#define HAVE_rsqrtsf2 (RS6000_RECIP_HAVE_RSQRTE_P (SFmode))
#define HAVE_rsqrtdf2 (RS6000_RECIP_HAVE_RSQRTE_P (DFmode))
#define HAVE_rsqrtv4sf2 (RS6000_RECIP_HAVE_RSQRTE_P (V4SFmode))
#define HAVE_rsqrtv2df2 (RS6000_RECIP_HAVE_RSQRTE_P (V2DFmode))
#define HAVE_abssf2 (TARGET_HARD_FLOAT)
#define HAVE_absdf2 (TARGET_HARD_FLOAT)
#define HAVE_negsf2 (TARGET_HARD_FLOAT)
#define HAVE_negdf2 (TARGET_HARD_FLOAT)
#define HAVE_addsf3 (TARGET_HARD_FLOAT)
#define HAVE_adddf3 (TARGET_HARD_FLOAT)
#define HAVE_subsf3 (TARGET_HARD_FLOAT)
#define HAVE_subdf3 (TARGET_HARD_FLOAT)
#define HAVE_mulsf3 (TARGET_HARD_FLOAT)
#define HAVE_muldf3 (TARGET_HARD_FLOAT)
#define HAVE_divsf3 (TARGET_HARD_FLOAT)
#define HAVE_divdf3 (TARGET_HARD_FLOAT)
#define HAVE_sqrtsf2 (TARGET_HARD_FLOAT && TARGET_PPC_GPOPT)
#define HAVE_sqrtdf2 (TARGET_HARD_FLOAT && TARGET_PPC_GPOPT)
#define HAVE_extendsfdf2 (TARGET_HARD_FLOAT)
#define HAVE_truncdfsf2 (TARGET_HARD_FLOAT)
#define HAVE_signbitkf2 ((TARGET_HARD_FLOAT \
   && (!FLOAT128_IEEE_P (KFmode) \
       || (TARGET_POWERPC64 && TARGET_DIRECT_MOVE))) && (TARGET_FLOAT128_TYPE))
#define HAVE_signbitif2 ((TARGET_HARD_FLOAT \
   && (!FLOAT128_IEEE_P (IFmode) \
       || (TARGET_POWERPC64 && TARGET_DIRECT_MOVE))) && (TARGET_FLOAT128_TYPE))
#define HAVE_signbittf2 ((TARGET_HARD_FLOAT \
   && (!FLOAT128_IEEE_P (TFmode) \
       || (TARGET_POWERPC64 && TARGET_DIRECT_MOVE))) && (TARGET_LONG_DOUBLE_128))
#define HAVE_copysignsf3 (TARGET_HARD_FLOAT \
   && ((TARGET_PPC_GFXOPT \
        && !HONOR_NANS (SFmode) \
        && !HONOR_SIGNED_ZEROS (SFmode)) \
       || TARGET_CMPB \
       || VECTOR_UNIT_VSX_P (SFmode)))
#define HAVE_copysigndf3 (TARGET_HARD_FLOAT \
   && ((TARGET_PPC_GFXOPT \
        && !HONOR_NANS (DFmode) \
        && !HONOR_SIGNED_ZEROS (DFmode)) \
       || TARGET_CMPB \
       || VECTOR_UNIT_VSX_P (DFmode)))
#define HAVE_sminsf3 (TARGET_MINMAX)
#define HAVE_smaxsf3 (TARGET_MINMAX)
#define HAVE_smindf3 (TARGET_MINMAX)
#define HAVE_smaxdf3 (TARGET_MINMAX)
#define HAVE_movsicc (TARGET_ISEL)
#define HAVE_movdicc ((TARGET_ISEL) && (TARGET_POWERPC64))
#define HAVE_movsfcc (TARGET_HARD_FLOAT && TARGET_PPC_GFXOPT)
#define HAVE_movdfcc (TARGET_HARD_FLOAT && TARGET_PPC_GFXOPT)
#define HAVE_movkfcc ((TARGET_POWER10 && TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_movtfcc ((TARGET_POWER10 && TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatsidf2 (TARGET_HARD_FLOAT)
#define HAVE_floatunssisf2 (TARGET_HARD_FLOAT \
   && ((TARGET_FCFIDUS && TARGET_LFIWZX) \
       || (TARGET_FCFID \
	   && (TARGET_POWERPC64 || flag_unsafe_math_optimizations))))
#define HAVE_floatunssidf2 (TARGET_HARD_FLOAT)
#define HAVE_floatqisf2 (TARGET_P9_VECTOR && TARGET_DIRECT_MOVE && TARGET_POWERPC64)
#define HAVE_floatqidf2 (TARGET_P9_VECTOR && TARGET_DIRECT_MOVE && TARGET_POWERPC64)
#define HAVE_floathisf2 (TARGET_P9_VECTOR && TARGET_DIRECT_MOVE && TARGET_POWERPC64)
#define HAVE_floathidf2 (TARGET_P9_VECTOR && TARGET_DIRECT_MOVE && TARGET_POWERPC64)
#define HAVE_floatunsqisf2 (TARGET_P9_VECTOR && TARGET_DIRECT_MOVE && TARGET_POWERPC64)
#define HAVE_floatunsqidf2 (TARGET_P9_VECTOR && TARGET_DIRECT_MOVE && TARGET_POWERPC64)
#define HAVE_floatunshisf2 (TARGET_P9_VECTOR && TARGET_DIRECT_MOVE && TARGET_POWERPC64)
#define HAVE_floatunshidf2 (TARGET_P9_VECTOR && TARGET_DIRECT_MOVE && TARGET_POWERPC64)
#define HAVE_fix_truncsfsi2 (TARGET_HARD_FLOAT)
#define HAVE_fix_truncdfsi2 (TARGET_HARD_FLOAT)
#define HAVE_fix_truncsfdi2 (TARGET_HARD_FLOAT && TARGET_FCFID)
#define HAVE_fix_truncdfdi2 (TARGET_HARD_FLOAT && TARGET_FCFID)
#define HAVE_fixuns_truncsfsi2 (TARGET_HARD_FLOAT && TARGET_FCTIWUZ && TARGET_STFIWX)
#define HAVE_fixuns_truncdfsi2 (TARGET_HARD_FLOAT && TARGET_FCTIWUZ && TARGET_STFIWX)
#define HAVE_rs6000_set_fpscr_rn (TARGET_HARD_FLOAT)
#define HAVE_rs6000_set_fpscr_drn (TARGET_HARD_FLOAT)
#define HAVE_lroundsfdi2 (TARGET_HARD_FLOAT && TARGET_VSX && TARGET_FPRND)
#define HAVE_lrounddfdi2 (TARGET_HARD_FLOAT && TARGET_VSX && TARGET_FPRND)
#define HAVE_floatsisf2 (TARGET_HARD_FLOAT \
   && ((TARGET_FCFIDS && TARGET_LFIWAX) \
       || (TARGET_FCFID \
	   && (TARGET_POWERPC64 || flag_unsafe_math_optimizations))))
#define HAVE_floatunsdidf2 (TARGET_HARD_FLOAT && TARGET_FCFIDU)
#define HAVE_floatdisf2 (TARGET_FCFID && TARGET_HARD_FLOAT \
   && (TARGET_FCFIDS || TARGET_POWERPC64 || flag_unsafe_math_optimizations))
#define HAVE_floatdisf2_internal2 (TARGET_POWERPC64 && TARGET_HARD_FLOAT && !TARGET_FCFIDS)
#define HAVE_floatunsdisf2 (TARGET_HARD_FLOAT && TARGET_FCFIDUS)
#define HAVE_addti3 (TARGET_64BIT)
#define HAVE_subti3 (TARGET_64BIT)
#define HAVE_andti3 1
#define HAVE_andpti3 1
#define HAVE_andv16qi3 (TARGET_ALTIVEC)
#define HAVE_andv8hi3 (TARGET_ALTIVEC)
#define HAVE_andv4si3 (TARGET_ALTIVEC)
#define HAVE_andv4sf3 (TARGET_ALTIVEC)
#define HAVE_andv2di3 (TARGET_ALTIVEC)
#define HAVE_andv2df3 (TARGET_ALTIVEC)
#define HAVE_andv1ti3 (TARGET_ALTIVEC)
#define HAVE_iorti3 1
#define HAVE_iorpti3 1
#define HAVE_iorv16qi3 (TARGET_ALTIVEC)
#define HAVE_iorv8hi3 (TARGET_ALTIVEC)
#define HAVE_iorv4si3 (TARGET_ALTIVEC)
#define HAVE_iorv4sf3 (TARGET_ALTIVEC)
#define HAVE_iorv2di3 (TARGET_ALTIVEC)
#define HAVE_iorv2df3 (TARGET_ALTIVEC)
#define HAVE_iorv1ti3 (TARGET_ALTIVEC)
#define HAVE_xorti3 1
#define HAVE_xorpti3 1
#define HAVE_xorv16qi3 (TARGET_ALTIVEC)
#define HAVE_xorv8hi3 (TARGET_ALTIVEC)
#define HAVE_xorv4si3 (TARGET_ALTIVEC)
#define HAVE_xorv4sf3 (TARGET_ALTIVEC)
#define HAVE_xorv2di3 (TARGET_ALTIVEC)
#define HAVE_xorv2df3 (TARGET_ALTIVEC)
#define HAVE_xorv1ti3 (TARGET_ALTIVEC)
#define HAVE_norti3 1
#define HAVE_norpti3 1
#define HAVE_norv16qi3 (TARGET_ALTIVEC)
#define HAVE_norv8hi3 (TARGET_ALTIVEC)
#define HAVE_norv4si3 (TARGET_ALTIVEC)
#define HAVE_norv4sf3 (TARGET_ALTIVEC)
#define HAVE_norv2di3 (TARGET_ALTIVEC)
#define HAVE_norv2df3 (TARGET_ALTIVEC)
#define HAVE_norv1ti3 (TARGET_ALTIVEC)
#define HAVE_andcti3 1
#define HAVE_andcpti3 1
#define HAVE_andcv16qi3 (TARGET_ALTIVEC)
#define HAVE_andcv8hi3 (TARGET_ALTIVEC)
#define HAVE_andcv4si3 (TARGET_ALTIVEC)
#define HAVE_andcv4sf3 (TARGET_ALTIVEC)
#define HAVE_andcv2di3 (TARGET_ALTIVEC)
#define HAVE_andcv2df3 (TARGET_ALTIVEC)
#define HAVE_andcv1ti3 (TARGET_ALTIVEC)
#define HAVE_eqvti3 1
#define HAVE_eqvpti3 1
#define HAVE_eqvv16qi3 ((V16QImode == TImode || V16QImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_eqvv8hi3 ((V8HImode == TImode || V8HImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_eqvv4si3 ((V4SImode == TImode || V4SImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_eqvv4sf3 ((V4SFmode == TImode || V4SFmode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_eqvv2di3 ((V2DImode == TImode || V2DImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_eqvv2df3 ((V2DFmode == TImode || V2DFmode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_eqvv1ti3 ((V1TImode == TImode || V1TImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_nandti3 1
#define HAVE_nandpti3 1
#define HAVE_nandv16qi3 ((V16QImode == TImode || V16QImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_nandv8hi3 ((V8HImode == TImode || V8HImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_nandv4si3 ((V4SImode == TImode || V4SImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_nandv4sf3 ((V4SFmode == TImode || V4SFmode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_nandv2di3 ((V2DImode == TImode || V2DImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_nandv2df3 ((V2DFmode == TImode || V2DFmode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_nandv1ti3 ((V1TImode == TImode || V1TImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_orcti3 1
#define HAVE_orcpti3 1
#define HAVE_orcv16qi3 ((V16QImode == TImode || V16QImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_orcv8hi3 ((V8HImode == TImode || V8HImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_orcv4si3 ((V4SImode == TImode || V4SImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_orcv4sf3 ((V4SFmode == TImode || V4SFmode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_orcv2di3 ((V2DImode == TImode || V2DImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_orcv2df3 ((V2DFmode == TImode || V2DFmode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_orcv1ti3 ((V1TImode == TImode || V1TImode == PTImode || TARGET_P8_VECTOR) && (TARGET_ALTIVEC))
#define HAVE_movsi_got (DEFAULT_ABI == ABI_V4 && flag_pic == 1)
#define HAVE_movqi 1
#define HAVE_movhi 1
#define HAVE_movsi 1
#define HAVE_movdi 1
#define HAVE_movti 1
#define HAVE_movpti 1
#define HAVE_movcc 1
#define HAVE_movsf 1
#define HAVE_movsd (TARGET_HARD_FLOAT)
#define HAVE_movdf 1
#define HAVE_movdd 1
#define HAVE_movtf (TARGET_LONG_DOUBLE_128)
#define HAVE_movif (FLOAT128_IBM_P (IFmode))
#define HAVE_movtd (TARGET_HARD_FLOAT)
#define HAVE_extenddfkf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_extenddfif2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_extenddftf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_LONG_DOUBLE_128))
#define HAVE_extendsfkf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_extendsfif2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_extendsftf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_LONG_DOUBLE_128))
#define HAVE_trunckfdf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_truncifdf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_trunctfdf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_LONG_DOUBLE_128))
#define HAVE_trunckfsf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_truncifsf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_trunctfsf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_LONG_DOUBLE_128))
#define HAVE_floatsikf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_floatsiif2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_floatsitf2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_LONG_DOUBLE_128))
#define HAVE_fix_trunckfsi2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_fix_truncifsi2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_FLOAT128_TYPE))
#define HAVE_fix_trunctfsi2 ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (TARGET_LONG_DOUBLE_128))
#define HAVE_fix_truncifsi2_fprs ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_fix_trunctfsi2_fprs ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (FLOAT128_IBM_P (TFmode)))
#define HAVE_fix_trunckfdi2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fix_trunctfdi2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fixuns_trunckfsi2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fixuns_trunctfsi2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_fixuns_trunckfdi2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_fixuns_trunctfdi2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatdikf2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floatditf2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatunsdikf2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floatunsditf2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_floatunskf2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_floatunstf2 ((TARGET_FLOAT128_TYPE) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_negkf2 ((FLOAT128_IEEE_P (KFmode) \
   || (FLOAT128_IBM_P (KFmode) && TARGET_HARD_FLOAT)) && (TARGET_FLOAT128_TYPE))
#define HAVE_negif2 ((FLOAT128_IEEE_P (IFmode) \
   || (FLOAT128_IBM_P (IFmode) && TARGET_HARD_FLOAT)) && (TARGET_FLOAT128_TYPE))
#define HAVE_negtf2 ((FLOAT128_IEEE_P (TFmode) \
   || (FLOAT128_IBM_P (TFmode) && TARGET_HARD_FLOAT)) && (TARGET_LONG_DOUBLE_128))
#define HAVE_abskf2 ((FLOAT128_IEEE_P (KFmode) \
   || (FLOAT128_IBM_P (KFmode) && TARGET_HARD_FLOAT)) && (TARGET_FLOAT128_TYPE))
#define HAVE_absif2 ((FLOAT128_IEEE_P (IFmode) \
   || (FLOAT128_IBM_P (IFmode) && TARGET_HARD_FLOAT)) && (TARGET_FLOAT128_TYPE))
#define HAVE_abstf2 ((FLOAT128_IEEE_P (TFmode) \
   || (FLOAT128_IBM_P (TFmode) && TARGET_HARD_FLOAT)) && (TARGET_LONG_DOUBLE_128))
#define HAVE_absif2_internal ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_abstf2_internal ((TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128) && (FLOAT128_IBM_P (TFmode)))
#define HAVE_ieee_128bit_negative_zero (TARGET_FLOAT128_TYPE)
#define HAVE_extendiftf2 (TARGET_FLOAT128_TYPE)
#define HAVE_extendifkf2 (TARGET_FLOAT128_TYPE)
#define HAVE_extendtfkf2 (TARGET_FLOAT128_TYPE)
#define HAVE_extendtfif2 (TARGET_FLOAT128_TYPE)
#define HAVE_trunciftf2 (TARGET_FLOAT128_TYPE)
#define HAVE_truncifkf2 (TARGET_FLOAT128_TYPE)
#define HAVE_trunckftf2 (TARGET_FLOAT128_TYPE)
#define HAVE_trunctfif2 (TARGET_FLOAT128_TYPE)
#define HAVE_reload_si_store 1
#define HAVE_reload_di_store (TARGET_POWERPC64)
#define HAVE_reload_si_load 1
#define HAVE_reload_di_load (TARGET_POWERPC64)
#define HAVE_reload_v16qi_si_store (TARGET_32BIT)
#define HAVE_reload_v8hi_si_store (TARGET_32BIT)
#define HAVE_reload_v4si_si_store (TARGET_32BIT)
#define HAVE_reload_v2di_si_store (TARGET_32BIT)
#define HAVE_reload_v4sf_si_store (TARGET_32BIT)
#define HAVE_reload_v2df_si_store (TARGET_32BIT)
#define HAVE_reload_v1ti_si_store (TARGET_32BIT)
#define HAVE_reload_sf_si_store (TARGET_32BIT)
#define HAVE_reload_sd_si_store (TARGET_32BIT)
#define HAVE_reload_si_si_store (TARGET_32BIT)
#define HAVE_reload_df_si_store (TARGET_32BIT)
#define HAVE_reload_dd_si_store (TARGET_32BIT)
#define HAVE_reload_di_si_store (TARGET_32BIT)
#define HAVE_reload_ti_si_store (TARGET_32BIT)
#define HAVE_reload_pti_si_store (TARGET_32BIT)
#define HAVE_reload_kf_si_store (TARGET_32BIT)
#define HAVE_reload_if_si_store (TARGET_32BIT)
#define HAVE_reload_tf_si_store (TARGET_32BIT)
#define HAVE_reload_oo_si_store (TARGET_32BIT)
#define HAVE_reload_xo_si_store (TARGET_32BIT)
#define HAVE_reload_v16qi_di_store (TARGET_64BIT)
#define HAVE_reload_v8hi_di_store (TARGET_64BIT)
#define HAVE_reload_v4si_di_store (TARGET_64BIT)
#define HAVE_reload_v2di_di_store (TARGET_64BIT)
#define HAVE_reload_v4sf_di_store (TARGET_64BIT)
#define HAVE_reload_v2df_di_store (TARGET_64BIT)
#define HAVE_reload_v1ti_di_store (TARGET_64BIT)
#define HAVE_reload_sf_di_store (TARGET_64BIT)
#define HAVE_reload_sd_di_store (TARGET_64BIT)
#define HAVE_reload_si_di_store (TARGET_64BIT)
#define HAVE_reload_df_di_store (TARGET_64BIT)
#define HAVE_reload_dd_di_store (TARGET_64BIT)
#define HAVE_reload_di_di_store (TARGET_64BIT)
#define HAVE_reload_ti_di_store (TARGET_64BIT)
#define HAVE_reload_pti_di_store (TARGET_64BIT)
#define HAVE_reload_kf_di_store (TARGET_64BIT)
#define HAVE_reload_if_di_store (TARGET_64BIT)
#define HAVE_reload_tf_di_store (TARGET_64BIT)
#define HAVE_reload_oo_di_store (TARGET_64BIT)
#define HAVE_reload_xo_di_store (TARGET_64BIT)
#define HAVE_reload_v16qi_si_load (TARGET_32BIT)
#define HAVE_reload_v8hi_si_load (TARGET_32BIT)
#define HAVE_reload_v4si_si_load (TARGET_32BIT)
#define HAVE_reload_v2di_si_load (TARGET_32BIT)
#define HAVE_reload_v4sf_si_load (TARGET_32BIT)
#define HAVE_reload_v2df_si_load (TARGET_32BIT)
#define HAVE_reload_v1ti_si_load (TARGET_32BIT)
#define HAVE_reload_sf_si_load (TARGET_32BIT)
#define HAVE_reload_sd_si_load (TARGET_32BIT)
#define HAVE_reload_si_si_load (TARGET_32BIT)
#define HAVE_reload_df_si_load (TARGET_32BIT)
#define HAVE_reload_dd_si_load (TARGET_32BIT)
#define HAVE_reload_di_si_load (TARGET_32BIT)
#define HAVE_reload_ti_si_load (TARGET_32BIT)
#define HAVE_reload_pti_si_load (TARGET_32BIT)
#define HAVE_reload_kf_si_load (TARGET_32BIT)
#define HAVE_reload_if_si_load (TARGET_32BIT)
#define HAVE_reload_tf_si_load (TARGET_32BIT)
#define HAVE_reload_oo_si_load (TARGET_32BIT)
#define HAVE_reload_xo_si_load (TARGET_32BIT)
#define HAVE_reload_v16qi_di_load (TARGET_64BIT)
#define HAVE_reload_v8hi_di_load (TARGET_64BIT)
#define HAVE_reload_v4si_di_load (TARGET_64BIT)
#define HAVE_reload_v2di_di_load (TARGET_64BIT)
#define HAVE_reload_v4sf_di_load (TARGET_64BIT)
#define HAVE_reload_v2df_di_load (TARGET_64BIT)
#define HAVE_reload_v1ti_di_load (TARGET_64BIT)
#define HAVE_reload_sf_di_load (TARGET_64BIT)
#define HAVE_reload_sd_di_load (TARGET_64BIT)
#define HAVE_reload_si_di_load (TARGET_64BIT)
#define HAVE_reload_df_di_load (TARGET_64BIT)
#define HAVE_reload_dd_di_load (TARGET_64BIT)
#define HAVE_reload_di_di_load (TARGET_64BIT)
#define HAVE_reload_ti_di_load (TARGET_64BIT)
#define HAVE_reload_pti_di_load (TARGET_64BIT)
#define HAVE_reload_kf_di_load (TARGET_64BIT)
#define HAVE_reload_if_di_load (TARGET_64BIT)
#define HAVE_reload_tf_di_load (TARGET_64BIT)
#define HAVE_reload_oo_di_load (TARGET_64BIT)
#define HAVE_reload_xo_di_load (TARGET_64BIT)
#define HAVE_setmemsi 1
#define HAVE_cmpstrnsi (TARGET_CMPB && (BYTES_BIG_ENDIAN || TARGET_LDBRX))
#define HAVE_cmpstrsi (TARGET_CMPB && (BYTES_BIG_ENDIAN || TARGET_LDBRX))
#define HAVE_cmpmemsi (TARGET_POPCNTD)
#define HAVE_cpymemsi 1
#define HAVE_movmemsi 1
#define HAVE_allocate_stack 1
#define HAVE_save_stack_function 1
#define HAVE_restore_stack_function 1
#define HAVE_restore_stack_block 1
#define HAVE_save_stack_nonlocal 1
#define HAVE_restore_stack_nonlocal 1
#define HAVE_load_toc_v4_PIC_1 (TARGET_ELF && DEFAULT_ABI == ABI_V4 \
   && (flag_pic == 2 || (flag_pic && TARGET_SECURE_PLT)))
#define HAVE_load_toc_v4_PIC_1b (TARGET_ELF && DEFAULT_ABI == ABI_V4 && flag_pic == 2)
#define HAVE_builtin_setjmp_receiver ((DEFAULT_ABI == ABI_V4 && flag_pic == 1) \
   || (TARGET_TOC && TARGET_MINIMAL_TOC) \
   || (DEFAULT_ABI == ABI_DARWIN && flag_pic))
#define HAVE_call 1
#define HAVE_call_value 1
#define HAVE_untyped_call 1
#define HAVE_sibcall 1
#define HAVE_sibcall_value 1
#define HAVE_sibcall_epilogue 1
#define HAVE_probe_stack_address 1
#define HAVE_cbranchsi4 1
#define HAVE_cbranchdi4 (TARGET_POWERPC64)
#define HAVE_cbranchsf4 (TARGET_HARD_FLOAT)
#define HAVE_cbranchdf4 (TARGET_HARD_FLOAT)
#define HAVE_cbranchtf4 (TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128)
#define HAVE_cbranchif4 (TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128)
#define HAVE_cbranchkf4 (TARGET_FLOAT128_TYPE)
#define HAVE_cbranchdd4 (TARGET_DFP)
#define HAVE_cbranchtd4 (TARGET_DFP)
#define HAVE_cstoresi4_signed (TARGET_32BIT)
#define HAVE_cstoredi4_signed (TARGET_64BIT)
#define HAVE_cstoresi4_unsigned (TARGET_32BIT)
#define HAVE_cstoredi4_unsigned (TARGET_64BIT)
#define HAVE_cstore_si_as_di 1
#define HAVE_cstoresi4_signed_imm 1
#define HAVE_cstoredi4_signed_imm (TARGET_POWERPC64)
#define HAVE_cstoresi4_unsigned_imm 1
#define HAVE_cstoredi4_unsigned_imm (TARGET_POWERPC64)
#define HAVE_cstoresi4 1
#define HAVE_cstoredi4 (TARGET_POWERPC64)
#define HAVE_cstoresf4 (TARGET_HARD_FLOAT)
#define HAVE_cstoredf4 (TARGET_HARD_FLOAT)
#define HAVE_cstoretf4 (TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128)
#define HAVE_cstoreif4 (TARGET_HARD_FLOAT && TARGET_LONG_DOUBLE_128)
#define HAVE_cstorekf4 (TARGET_FLOAT128_TYPE)
#define HAVE_cstoredd4 (TARGET_DFP)
#define HAVE_cstoretd4 (TARGET_DFP)
#define HAVE_stack_protect_set 1
#define HAVE_stack_protect_test 1
#define HAVE_eqsi3 1
#define HAVE_eqdi3 (TARGET_POWERPC64)
#define HAVE_nesi3 1
#define HAVE_nedi3 (TARGET_POWERPC64)
#define HAVE_indirect_jump 1
#define HAVE_tablejump 1
#define HAVE_tablejumpsi_normal ((rs6000_speculate_indirect_jumps && rs6000_relative_jumptables) && (TARGET_32BIT))
#define HAVE_tablejumpdi_normal ((rs6000_speculate_indirect_jumps && rs6000_relative_jumptables) && (TARGET_64BIT))
#define HAVE_tablejumpsi_absolute ((rs6000_speculate_indirect_jumps && !rs6000_relative_jumptables) && (TARGET_32BIT))
#define HAVE_tablejumpdi_absolute ((rs6000_speculate_indirect_jumps && !rs6000_relative_jumptables) && (TARGET_64BIT))
#define HAVE_tablejumpsi_nospec ((!rs6000_speculate_indirect_jumps && rs6000_relative_jumptables) && (TARGET_32BIT))
#define HAVE_tablejumpdi_nospec ((!rs6000_speculate_indirect_jumps && rs6000_relative_jumptables) && (TARGET_64BIT))
#define HAVE_tablejumpsi_absolute_nospec ((!rs6000_speculate_indirect_jumps && !rs6000_relative_jumptables) && (TARGET_32BIT))
#define HAVE_tablejumpdi_absolute_nospec ((!rs6000_speculate_indirect_jumps && !rs6000_relative_jumptables) && (TARGET_64BIT))
#define HAVE_doloop_end 1
#define HAVE_ctrsi (TARGET_32BIT)
#define HAVE_ctrdi (TARGET_64BIT)
#define HAVE_ctrapsi4 1
#define HAVE_ctrapdi4 (TARGET_POWERPC64)
#define HAVE_prologue 1
#define HAVE_epilogue 1
#define HAVE_movsi_to_cr_one 1
#define HAVE_eh_return 1
#define HAVE_split_stack_prologue 1
#define HAVE_load_split_stack_limit 1
#define HAVE_split_stack_space_check 1
#define HAVE_fmasf4 (TARGET_HARD_FLOAT)
#define HAVE_fmadf4 (TARGET_HARD_FLOAT || VECTOR_UNIT_VSX_P (DFmode))
#define HAVE_fmav4sf4 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_fmav2df4 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_fmakf4 (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode))
#define HAVE_fmatf4 (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode))
#define HAVE_fmssf4 ((!VECTOR_UNIT_ALTIVEC_P (SFmode)) && (TARGET_HARD_FLOAT))
#define HAVE_fmsdf4 ((!VECTOR_UNIT_ALTIVEC_P (DFmode)) && (TARGET_HARD_FLOAT || VECTOR_UNIT_VSX_P (DFmode)))
#define HAVE_fmsv4sf4 ((!VECTOR_UNIT_ALTIVEC_P (V4SFmode)) && (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode)))
#define HAVE_fmsv2df4 ((!VECTOR_UNIT_ALTIVEC_P (V2DFmode)) && (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode)))
#define HAVE_fmskf4 ((!VECTOR_UNIT_ALTIVEC_P (KFmode)) && (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)))
#define HAVE_fmstf4 ((!VECTOR_UNIT_ALTIVEC_P (TFmode)) && (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)))
#define HAVE_fnmasf4 ((!HONOR_SIGNED_ZEROS (SFmode)) && (TARGET_HARD_FLOAT))
#define HAVE_fnmadf4 ((!HONOR_SIGNED_ZEROS (DFmode)) && (TARGET_HARD_FLOAT || VECTOR_UNIT_VSX_P (DFmode)))
#define HAVE_fnmav4sf4 ((!HONOR_SIGNED_ZEROS (V4SFmode)) && (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode)))
#define HAVE_fnmav2df4 ((!HONOR_SIGNED_ZEROS (V2DFmode)) && (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode)))
#define HAVE_fnmakf4 ((!HONOR_SIGNED_ZEROS (KFmode)) && (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)))
#define HAVE_fnmatf4 ((!HONOR_SIGNED_ZEROS (TFmode)) && (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)))
#define HAVE_fnmssf4 ((!HONOR_SIGNED_ZEROS (SFmode) && !VECTOR_UNIT_ALTIVEC_P (SFmode)) && (TARGET_HARD_FLOAT))
#define HAVE_fnmsdf4 ((!HONOR_SIGNED_ZEROS (DFmode) && !VECTOR_UNIT_ALTIVEC_P (DFmode)) && (TARGET_HARD_FLOAT || VECTOR_UNIT_VSX_P (DFmode)))
#define HAVE_fnmsv4sf4 ((!HONOR_SIGNED_ZEROS (V4SFmode) && !VECTOR_UNIT_ALTIVEC_P (V4SFmode)) && (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode)))
#define HAVE_fnmsv2df4 ((!HONOR_SIGNED_ZEROS (V2DFmode) && !VECTOR_UNIT_ALTIVEC_P (V2DFmode)) && (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode)))
#define HAVE_fnmskf4 ((!HONOR_SIGNED_ZEROS (KFmode) && !VECTOR_UNIT_ALTIVEC_P (KFmode)) && (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)))
#define HAVE_fnmstf4 ((!HONOR_SIGNED_ZEROS (TFmode) && !VECTOR_UNIT_ALTIVEC_P (TFmode)) && (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)))
#define HAVE_nfmasf4 ((!VECTOR_UNIT_ALTIVEC_P (SFmode)) && (TARGET_HARD_FLOAT))
#define HAVE_nfmadf4 ((!VECTOR_UNIT_ALTIVEC_P (DFmode)) && (TARGET_HARD_FLOAT || VECTOR_UNIT_VSX_P (DFmode)))
#define HAVE_nfmav4sf4 ((!VECTOR_UNIT_ALTIVEC_P (V4SFmode)) && (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode)))
#define HAVE_nfmav2df4 ((!VECTOR_UNIT_ALTIVEC_P (V2DFmode)) && (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode)))
#define HAVE_nfmakf4 ((!VECTOR_UNIT_ALTIVEC_P (KFmode)) && (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode)))
#define HAVE_nfmatf4 ((!VECTOR_UNIT_ALTIVEC_P (TFmode)) && (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode)))
#define HAVE_nfmssf4 (TARGET_HARD_FLOAT)
#define HAVE_nfmsdf4 (TARGET_HARD_FLOAT || VECTOR_UNIT_VSX_P (DFmode))
#define HAVE_nfmsv4sf4 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_nfmsv2df4 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_nfmskf4 (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (KFmode))
#define HAVE_nfmstf4 (TARGET_FLOAT128_HW && FLOAT128_IEEE_P (TFmode))
#define HAVE_rs6000_get_timebase 1
#define HAVE_rs6000_mffsl (TARGET_HARD_FLOAT)
#define HAVE_unpacktf ((FLOAT128_2REG_P (TFmode)) && (TARGET_LONG_DOUBLE_128))
#define HAVE_unpackif ((FLOAT128_2REG_P (IFmode)) && (FLOAT128_IBM_P (IFmode)))
#define HAVE_unpacktd ((FLOAT128_2REG_P (TDmode)) && (TARGET_HARD_FLOAT))
#define HAVE_copysignkf3 1
#define HAVE_copysigntf3 (FLOAT128_IEEE_P (TFmode))
#define HAVE_cmprb (TARGET_P9_MISC)
#define HAVE_cmprb2 (TARGET_P9_MISC)
#define HAVE_cmpeqb (TARGET_P9_MISC && TARGET_64BIT)
#define HAVE_mem_thread_fence 1
#define HAVE_hwsync 1
#define HAVE_lwsync 1
#define HAVE_atomic_loadqi 1
#define HAVE_atomic_loadhi 1
#define HAVE_atomic_loadsi 1
#define HAVE_atomic_loaddi (TARGET_POWERPC64)
#define HAVE_atomic_loadti (TARGET_SYNC_TI)
#define HAVE_atomic_storeqi 1
#define HAVE_atomic_storehi 1
#define HAVE_atomic_storesi 1
#define HAVE_atomic_storedi (TARGET_POWERPC64)
#define HAVE_atomic_storeti (TARGET_SYNC_TI)
#define HAVE_load_lockedti (TARGET_SYNC_TI)
#define HAVE_store_conditionalti (TARGET_SYNC_TI)
#define HAVE_atomic_compare_and_swapqi 1
#define HAVE_atomic_compare_and_swaphi 1
#define HAVE_atomic_compare_and_swapsi 1
#define HAVE_atomic_compare_and_swapdi (TARGET_POWERPC64)
#define HAVE_atomic_compare_and_swapti (TARGET_SYNC_TI)
#define HAVE_atomic_exchangeqi 1
#define HAVE_atomic_exchangehi 1
#define HAVE_atomic_exchangesi 1
#define HAVE_atomic_exchangedi (TARGET_POWERPC64)
#define HAVE_atomic_exchangeti (TARGET_SYNC_TI)
#define HAVE_atomic_addqi 1
#define HAVE_atomic_subqi 1
#define HAVE_atomic_orqi 1
#define HAVE_atomic_xorqi 1
#define HAVE_atomic_andqi 1
#define HAVE_atomic_addhi 1
#define HAVE_atomic_subhi 1
#define HAVE_atomic_orhi 1
#define HAVE_atomic_xorhi 1
#define HAVE_atomic_andhi 1
#define HAVE_atomic_addsi 1
#define HAVE_atomic_subsi 1
#define HAVE_atomic_orsi 1
#define HAVE_atomic_xorsi 1
#define HAVE_atomic_andsi 1
#define HAVE_atomic_adddi (TARGET_POWERPC64)
#define HAVE_atomic_subdi (TARGET_POWERPC64)
#define HAVE_atomic_ordi (TARGET_POWERPC64)
#define HAVE_atomic_xordi (TARGET_POWERPC64)
#define HAVE_atomic_anddi (TARGET_POWERPC64)
#define HAVE_atomic_addti (TARGET_SYNC_TI)
#define HAVE_atomic_subti (TARGET_SYNC_TI)
#define HAVE_atomic_orti (TARGET_SYNC_TI)
#define HAVE_atomic_xorti (TARGET_SYNC_TI)
#define HAVE_atomic_andti (TARGET_SYNC_TI)
#define HAVE_atomic_nandqi 1
#define HAVE_atomic_nandhi 1
#define HAVE_atomic_nandsi 1
#define HAVE_atomic_nanddi (TARGET_POWERPC64)
#define HAVE_atomic_nandti (TARGET_SYNC_TI)
#define HAVE_atomic_fetch_addqi 1
#define HAVE_atomic_fetch_subqi 1
#define HAVE_atomic_fetch_orqi 1
#define HAVE_atomic_fetch_xorqi 1
#define HAVE_atomic_fetch_andqi 1
#define HAVE_atomic_fetch_addhi 1
#define HAVE_atomic_fetch_subhi 1
#define HAVE_atomic_fetch_orhi 1
#define HAVE_atomic_fetch_xorhi 1
#define HAVE_atomic_fetch_andhi 1
#define HAVE_atomic_fetch_addsi 1
#define HAVE_atomic_fetch_subsi 1
#define HAVE_atomic_fetch_orsi 1
#define HAVE_atomic_fetch_xorsi 1
#define HAVE_atomic_fetch_andsi 1
#define HAVE_atomic_fetch_adddi (TARGET_POWERPC64)
#define HAVE_atomic_fetch_subdi (TARGET_POWERPC64)
#define HAVE_atomic_fetch_ordi (TARGET_POWERPC64)
#define HAVE_atomic_fetch_xordi (TARGET_POWERPC64)
#define HAVE_atomic_fetch_anddi (TARGET_POWERPC64)
#define HAVE_atomic_fetch_addti (TARGET_SYNC_TI)
#define HAVE_atomic_fetch_subti (TARGET_SYNC_TI)
#define HAVE_atomic_fetch_orti (TARGET_SYNC_TI)
#define HAVE_atomic_fetch_xorti (TARGET_SYNC_TI)
#define HAVE_atomic_fetch_andti (TARGET_SYNC_TI)
#define HAVE_atomic_fetch_nandqi 1
#define HAVE_atomic_fetch_nandhi 1
#define HAVE_atomic_fetch_nandsi 1
#define HAVE_atomic_fetch_nanddi (TARGET_POWERPC64)
#define HAVE_atomic_fetch_nandti (TARGET_SYNC_TI)
#define HAVE_atomic_add_fetchqi 1
#define HAVE_atomic_sub_fetchqi 1
#define HAVE_atomic_or_fetchqi 1
#define HAVE_atomic_xor_fetchqi 1
#define HAVE_atomic_and_fetchqi 1
#define HAVE_atomic_add_fetchhi 1
#define HAVE_atomic_sub_fetchhi 1
#define HAVE_atomic_or_fetchhi 1
#define HAVE_atomic_xor_fetchhi 1
#define HAVE_atomic_and_fetchhi 1
#define HAVE_atomic_add_fetchsi 1
#define HAVE_atomic_sub_fetchsi 1
#define HAVE_atomic_or_fetchsi 1
#define HAVE_atomic_xor_fetchsi 1
#define HAVE_atomic_and_fetchsi 1
#define HAVE_atomic_add_fetchdi (TARGET_POWERPC64)
#define HAVE_atomic_sub_fetchdi (TARGET_POWERPC64)
#define HAVE_atomic_or_fetchdi (TARGET_POWERPC64)
#define HAVE_atomic_xor_fetchdi (TARGET_POWERPC64)
#define HAVE_atomic_and_fetchdi (TARGET_POWERPC64)
#define HAVE_atomic_add_fetchti (TARGET_SYNC_TI)
#define HAVE_atomic_sub_fetchti (TARGET_SYNC_TI)
#define HAVE_atomic_or_fetchti (TARGET_SYNC_TI)
#define HAVE_atomic_xor_fetchti (TARGET_SYNC_TI)
#define HAVE_atomic_and_fetchti (TARGET_SYNC_TI)
#define HAVE_atomic_nand_fetchqi 1
#define HAVE_atomic_nand_fetchhi 1
#define HAVE_atomic_nand_fetchsi 1
#define HAVE_atomic_nand_fetchdi (TARGET_POWERPC64)
#define HAVE_atomic_nand_fetchti (TARGET_SYNC_TI)
#define HAVE_movv16qi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_movv8hi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_movv4si (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_movv2di (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_movv4sf (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_movv2df (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_movv1ti (VECTOR_MEM_ALTIVEC_OR_VSX_P (V1TImode))
#define HAVE_movkf (VECTOR_MEM_ALTIVEC_OR_VSX_P (KFmode))
#define HAVE_vector_load_v16qi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_load_v8hi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_load_v4si (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_load_v2di (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_load_v4sf (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_load_v2df (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_load_v1ti (VECTOR_MEM_ALTIVEC_OR_VSX_P (V1TImode))
#define HAVE_vector_load_kf (VECTOR_MEM_ALTIVEC_OR_VSX_P (KFmode))
#define HAVE_vector_store_v16qi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_store_v8hi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_store_v4si (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_store_v2di (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_store_v4sf (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_store_v2df (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_store_v1ti (VECTOR_MEM_ALTIVEC_OR_VSX_P (V1TImode))
#define HAVE_vector_store_kf (VECTOR_MEM_ALTIVEC_OR_VSX_P (KFmode))
#define HAVE_addv4sf3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_addv2df3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_subv4sf3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_subv2df3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_mulv4sf3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_mulv2df3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_divv4sf3 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_divv2df3 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_negv4sf2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_negv2df2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_absv4sf2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_absv2df2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_sminv4sf3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_sminv2df3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_smaxv4sf3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_smaxv2df3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_sqrtv4sf2 (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_sqrtv2df2 (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_rsqrtev4sf2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_rsqrtev2df2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_rev4sf2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_rev2df2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_ftruncv4sf2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_ftruncv2df2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_ceilv4sf2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_ceilv2df2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_floorv4sf2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_floorv2df2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_btruncv4sf2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_btruncv2df2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_copysignv4sf3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_copysignv2df3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vcondv4sfv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vcondv2dfv2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vcondv16qiv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vcondv8hiv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vcondv4siv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vcondv2div2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vcondv4sfv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) \
   && VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_vcondv4siv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) \
   && VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_vcondv2dfv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) \
   && VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vcondv2div2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) \
   && VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vconduv16qiv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vconduv8hiv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vconduv4siv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vconduv2div2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vconduv4sfv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode) \
   && VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_vconduv2dfv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode) \
   && VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vcond_mask_v16qiv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vcond_mask_v8hiv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vcond_mask_v4siv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vcond_mask_v2div2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vcond_mask_v4sfv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vcond_mask_v2dfv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vec_cmpv16qiv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vec_cmpv8hiv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vec_cmpv4siv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vec_cmpv2div2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vec_cmpuv16qiv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vec_cmpuv8hiv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vec_cmpuv4siv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vec_cmpuv2div2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vec_cmpv4sfv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vec_cmpv2dfv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_eqv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_eqv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_eqv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_eqv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_eqv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_eqv2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_eqv1ti (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V1TImode))
#define HAVE_vector_gtv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_gtv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_gtv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_gtv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_gtv4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_gtv2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_gtv1ti (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V1TImode))
#define HAVE_vector_nltv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_nltv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_nltv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_nltv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_nltv1ti (TARGET_POWER10)
#define HAVE_vector_gtuv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_gtuv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_gtuv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_gtuv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_gtuv1ti (TARGET_POWER10)
#define HAVE_vector_nltuv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_nltuv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_nltuv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_nltuv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_nltuv1ti (TARGET_POWER10)
#define HAVE_vector_geuv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_geuv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_geuv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_geuv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_ngtv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_ngtv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_ngtv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_ngtv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_ngtv1ti (TARGET_POWER10)
#define HAVE_vector_ngtuv16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_ngtuv8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_ngtuv4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_ngtuv2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_ngtuv1ti (TARGET_POWER10)
#define HAVE_vector_gev4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_gev2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_select_v16qi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_select_v8hi (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_select_v4si (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_select_v2di (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_select_v4sf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_select_v2df (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_select_v1ti (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V1TImode))
#define HAVE_vector_select_ti (VECTOR_UNIT_ALTIVEC_OR_VSX_P (TImode))
#define HAVE_vector_select_kf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (KFmode))
#define HAVE_vector_select_tf (VECTOR_UNIT_ALTIVEC_OR_VSX_P (TFmode))
#define HAVE_vector_select_v16qi_uns (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_select_v8hi_uns (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_select_v4si_uns (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_select_v2di_uns (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_select_v4sf_uns (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_select_v2df_uns (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_select_v1ti_uns (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V1TImode))
#define HAVE_vector_select_ti_uns (VECTOR_UNIT_ALTIVEC_OR_VSX_P (TImode))
#define HAVE_vector_select_kf_uns (VECTOR_UNIT_ALTIVEC_OR_VSX_P (KFmode))
#define HAVE_vector_select_tf_uns (VECTOR_UNIT_ALTIVEC_OR_VSX_P (TFmode))
#define HAVE_vector_eq_v16qi_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_eq_v8hi_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_eq_v4si_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_eq_v2di_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_eq_v4sf_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_eq_v2df_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_eq_v1ti_p (TARGET_POWER10)
#define HAVE_vector_ne_v4si_p (TARGET_P9_VECTOR)
#define HAVE_vector_ne_v8hi_p (TARGET_P9_VECTOR)
#define HAVE_vector_ne_v16qi_p (TARGET_P9_VECTOR)
#define HAVE_vector_ae_v4si_p (TARGET_P9_VECTOR)
#define HAVE_vector_ae_v8hi_p (TARGET_P9_VECTOR)
#define HAVE_vector_ae_v16qi_p (TARGET_P9_VECTOR)
#define HAVE_vector_nez_v4si_p (TARGET_P9_VECTOR)
#define HAVE_vector_nez_v8hi_p (TARGET_P9_VECTOR)
#define HAVE_vector_nez_v16qi_p (TARGET_P9_VECTOR)
#define HAVE_vector_ne_v2di_p (TARGET_P9_VECTOR)
#define HAVE_vector_ne_v1ti_p (TARGET_POWER10)
#define HAVE_vector_ae_v2di_p (TARGET_P9_VECTOR)
#define HAVE_vector_ae_v1ti_p (TARGET_POWER10)
#define HAVE_vector_ne_v4sf_p (TARGET_P9_VECTOR)
#define HAVE_vector_ne_v2df_p (TARGET_P9_VECTOR)
#define HAVE_vector_ae_v4sf_p (TARGET_P9_VECTOR)
#define HAVE_vector_ae_v2df_p (TARGET_P9_VECTOR)
#define HAVE_vector_gt_v16qi_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_gt_v8hi_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_gt_v4si_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_gt_v2di_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_gt_v4sf_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_gt_v2df_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_gt_v1ti_p (TARGET_POWER10)
#define HAVE_vector_ge_v4sf_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vector_ge_v2df_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vector_gtu_v16qi_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vector_gtu_v8hi_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vector_gtu_v4si_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vector_gtu_v2di_p (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vector_gtu_v1ti_p (TARGET_POWER10)
#define HAVE_cr6_test_for_zero (TARGET_ALTIVEC || TARGET_VSX)
#define HAVE_cr6_test_for_zero_reverse (TARGET_ALTIVEC || TARGET_VSX)
#define HAVE_cr6_test_for_lt (TARGET_ALTIVEC || TARGET_VSX)
#define HAVE_cr6_test_for_lt_reverse (TARGET_ALTIVEC || TARGET_VSX)
#define HAVE_clzv16qi2 (TARGET_P8_VECTOR)
#define HAVE_clzv8hi2 (TARGET_P8_VECTOR)
#define HAVE_clzv4si2 (TARGET_P8_VECTOR)
#define HAVE_clzv2di2 (TARGET_P8_VECTOR)
#define HAVE_ctzv16qi2 (TARGET_P9_VECTOR)
#define HAVE_ctzv8hi2 (TARGET_P9_VECTOR)
#define HAVE_ctzv4si2 (TARGET_P9_VECTOR)
#define HAVE_ctzv2di2 (TARGET_P9_VECTOR)
#define HAVE_popcountv16qi2 (TARGET_P8_VECTOR)
#define HAVE_popcountv8hi2 (TARGET_P8_VECTOR)
#define HAVE_popcountv4si2 (TARGET_P8_VECTOR)
#define HAVE_popcountv2di2 (TARGET_P8_VECTOR)
#define HAVE_parityv8hi2 (TARGET_P9_VECTOR)
#define HAVE_parityv4si2 (TARGET_P9_VECTOR)
#define HAVE_parityv2di2 (TARGET_P9_VECTOR)
#define HAVE_parityv1ti2 (TARGET_P9_VECTOR)
#define HAVE_parityti2 (TARGET_P9_VECTOR)
#define HAVE_floatv4siv4sf2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_floatv2div2df2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_floatunsv4siv4sf2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_floatunsv2div2df2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_fix_truncv4sfv4si2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_fix_truncv2dfv2di2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_fixuns_truncv4sfv4si2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_fixuns_truncv2dfv2di2 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vec_initv16qiqi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vec_initv8hihi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vec_initv4sisi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vec_initv2didi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vec_initv4sfsf (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vec_initv2dfdf (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vec_setv16qi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vec_setv8hi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vec_setv4si (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vec_setv2di (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vec_setv4sf (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vec_setv2df (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vec_extractv16qiqi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vec_extractv8hihi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vec_extractv4sisi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vec_extractv2didi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vec_extractv4sfsf (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vec_extractv2dfdf (VECTOR_MEM_ALTIVEC_OR_VSX_P (V2DFmode))
#define HAVE_vec_pack_trunc_v2df (VECTOR_UNIT_VSX_P (V2DFmode) && TARGET_ALTIVEC)
#define HAVE_vec_pack_sfix_trunc_v2df (VECTOR_UNIT_VSX_P (V2DFmode) && TARGET_ALTIVEC)
#define HAVE_vec_pack_ufix_trunc_v2df (VECTOR_UNIT_VSX_P (V2DFmode) && TARGET_ALTIVEC)
#define HAVE_vec_unpacks_hi_v4sf (VECTOR_UNIT_VSX_P (V2DFmode) && VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vec_unpacks_lo_v4sf (VECTOR_UNIT_VSX_P (V2DFmode) && VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_vec_unpacks_float_hi_v4si (VECTOR_UNIT_VSX_P (V2DFmode) && VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vec_unpacks_float_lo_v4si (VECTOR_UNIT_VSX_P (V2DFmode) && VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vec_unpacku_float_hi_v4si (VECTOR_UNIT_VSX_P (V2DFmode) && VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vec_unpacku_float_lo_v4si (VECTOR_UNIT_VSX_P (V2DFmode) && VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vec_realign_load_v16qi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vec_realign_load_v8hi (VECTOR_MEM_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vec_realign_load_v4si (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vec_realign_load_v4sf (VECTOR_MEM_ALTIVEC_OR_VSX_P (V4SFmode))
#define HAVE_movmisalignv4si (VECTOR_MEM_VSX_P (V4SImode) && TARGET_ALLOW_MOVMISALIGN)
#define HAVE_movmisalignv4sf (VECTOR_MEM_VSX_P (V4SFmode) && TARGET_ALLOW_MOVMISALIGN)
#define HAVE_movmisalignv2di (VECTOR_MEM_VSX_P (V2DImode) && TARGET_ALLOW_MOVMISALIGN)
#define HAVE_movmisalignv2df (VECTOR_MEM_VSX_P (V2DFmode) && TARGET_ALLOW_MOVMISALIGN)
#define HAVE_movmisalignv1ti (VECTOR_MEM_VSX_P (V1TImode) && TARGET_ALLOW_MOVMISALIGN)
#define HAVE_movmisalignkf (VECTOR_MEM_VSX_P (KFmode) && TARGET_ALLOW_MOVMISALIGN)
#define HAVE_movmisaligntf (VECTOR_MEM_VSX_P (TFmode) && TARGET_ALLOW_MOVMISALIGN)
#define HAVE_vec_shr_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_shr_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_shr_v4si (TARGET_ALTIVEC)
#define HAVE_vec_shr_v2di (TARGET_ALTIVEC)
#define HAVE_vec_shr_v4sf (TARGET_ALTIVEC)
#define HAVE_vec_shr_v2df (TARGET_ALTIVEC)
#define HAVE_vec_shr_v1ti (TARGET_ALTIVEC)
#define HAVE_vec_shr_ti (TARGET_ALTIVEC)
#define HAVE_vec_shr_kf (TARGET_ALTIVEC)
#define HAVE_vec_shr_tf (TARGET_ALTIVEC)
#define HAVE_vrotlv16qi3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vrotlv8hi3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vrotlv4si3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vrotlv2di3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vrotlv1ti3 (TARGET_POWER10)
#define HAVE_vrotrv16qi3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vrotrv8hi3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vrotrv4si3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vrotrv2di3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vashlv16qi3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vashlv8hi3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vashlv4si3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vashlv2di3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vashlv1ti3 (TARGET_POWER10)
#define HAVE_vashlti3 (TARGET_POWER10)
#define HAVE_vlshrv16qi3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vlshrv8hi3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vlshrv4si3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vlshrv2di3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vlshrv1ti3 (TARGET_POWER10)
#define HAVE_vlshrti3 (TARGET_POWER10)
#define HAVE_vashrv16qi3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V16QImode))
#define HAVE_vashrv8hi3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V8HImode))
#define HAVE_vashrv4si3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V4SImode))
#define HAVE_vashrv2di3 (VECTOR_UNIT_ALTIVEC_OR_VSX_P (V2DImode))
#define HAVE_vashrv1ti3 (TARGET_POWER10)
#define HAVE_reduc_plus_scal_v4sf (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_reduc_smin_scal_v4sf (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_reduc_smax_scal_v4sf (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_reduc_plus_scal_v2df (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_reduc_smin_scal_v2df (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_reduc_smax_scal_v2df (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_load_v16qi (VECTOR_MEM_VSX_P (V16QImode))
#define HAVE_vsx_load_v8hi (VECTOR_MEM_VSX_P (V8HImode))
#define HAVE_vsx_load_v4si (VECTOR_MEM_VSX_P (V4SImode))
#define HAVE_vsx_load_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_load_v4sf (VECTOR_MEM_VSX_P (V4SFmode))
#define HAVE_vsx_load_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_load_v1ti (VECTOR_MEM_VSX_P (V1TImode))
#define HAVE_vsx_load_kf ((VECTOR_MEM_VSX_P (KFmode)) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_vsx_load_tf ((VECTOR_MEM_VSX_P (TFmode)) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_vsx_load_ti (VECTOR_MEM_VSX_P (TImode))
#define HAVE_vsx_store_v16qi (VECTOR_MEM_VSX_P (V16QImode))
#define HAVE_vsx_store_v8hi (VECTOR_MEM_VSX_P (V8HImode))
#define HAVE_vsx_store_v4si (VECTOR_MEM_VSX_P (V4SImode))
#define HAVE_vsx_store_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_store_v4sf (VECTOR_MEM_VSX_P (V4SFmode))
#define HAVE_vsx_store_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_store_v1ti (VECTOR_MEM_VSX_P (V1TImode))
#define HAVE_vsx_store_kf ((VECTOR_MEM_VSX_P (KFmode)) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_vsx_store_tf ((VECTOR_MEM_VSX_P (TFmode)) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_vsx_store_ti (VECTOR_MEM_VSX_P (TImode))
#define HAVE_vsx_ld_elemrev_v8hi (VECTOR_MEM_VSX_P (V8HImode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_ld_elemrev_v16qi (VECTOR_MEM_VSX_P (V16QImode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_st_elemrev_v8hi (VECTOR_MEM_VSX_P (V8HImode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_st_elemrev_v16qi (VECTOR_MEM_VSX_P (V16QImode) && !BYTES_BIG_ENDIAN)
#define HAVE_vsx_tdivdf3_fg (VECTOR_UNIT_VSX_P (DFmode))
#define HAVE_vsx_tdivv4sf3_fg (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_tdivv2df3_fg (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_tdivdf3_fe (VECTOR_UNIT_VSX_P (DFmode))
#define HAVE_vsx_tdivv4sf3_fe (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_tdivv2df3_fe (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_tsqrtdf2_fg (VECTOR_UNIT_VSX_P (DFmode))
#define HAVE_vsx_tsqrtv4sf2_fg (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_tsqrtv2df2_fg (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_tsqrtdf2_fe (VECTOR_UNIT_VSX_P (DFmode))
#define HAVE_vsx_tsqrtv4sf2_fe (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_tsqrtv2df2_fe (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_xvtlsbbo (TARGET_POWER10)
#define HAVE_xvtlsbbz (TARGET_POWER10)
#define HAVE_vsx_xvcvspdp (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsx_xvcvsxddp_scale (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvuxddp_scale (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvdpsxds_scale (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvdpuxds_scale (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvsxwdp (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvuxwdp (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvspsxds (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_vsx_xvcvspuxds (VECTOR_UNIT_VSX_P (V2DFmode))
#define HAVE_float2_v2df (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_float2_v2di (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_uns_float2_v2di (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_floatev2df (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_floatev2di (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_unsfloatev2di (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_floatov2df (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_floatov2di (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_unsfloatov2di (VECTOR_UNIT_VSX_P (V4SFmode))
#define HAVE_vsigned2_v2df (TARGET_VSX)
#define HAVE_vsignedo_v2df (TARGET_VSX)
#define HAVE_vsignede_v2df (TARGET_VSX)
#define HAVE_vunsigned2_v2df (TARGET_VSX)
#define HAVE_vunsignedo_v2df (TARGET_VSX)
#define HAVE_vunsignede_v2df (TARGET_VSX)
#define HAVE_vsx_init_v4si (VECTOR_MEM_VSX_P (V4SImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_xxgenpcvm_v16qi (TARGET_POWER10)
#define HAVE_xxgenpcvm_v8hi (TARGET_POWER10)
#define HAVE_xxgenpcvm_v4si (TARGET_POWER10)
#define HAVE_xxgenpcvm_v2di (TARGET_POWER10)
#define HAVE_vsx_set_v1ti (VECTOR_MEM_VSX_P (V1TImode))
#define HAVE_vsx_set_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_set_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_xxpermdi_v16qi (VECTOR_MEM_VSX_P (V16QImode))
#define HAVE_vsx_xxpermdi_v8hi (VECTOR_MEM_VSX_P (V8HImode))
#define HAVE_vsx_xxpermdi_v4si (VECTOR_MEM_VSX_P (V4SImode))
#define HAVE_vsx_xxpermdi_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_xxpermdi_v4sf (VECTOR_MEM_VSX_P (V4SFmode))
#define HAVE_vsx_xxpermdi_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_xxpermdi_v1ti (VECTOR_MEM_VSX_P (V1TImode))
#define HAVE_vsx_xxpermdi_ti (VECTOR_MEM_VSX_P (TImode))
#define HAVE_vsx_xxpermdi_kf ((VECTOR_MEM_VSX_P (KFmode)) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_vsx_xxpermdi_tf ((VECTOR_MEM_VSX_P (TFmode)) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_vsx_xxpermdi_v16qi_be (VECTOR_MEM_VSX_P (V16QImode))
#define HAVE_vsx_xxpermdi_v8hi_be (VECTOR_MEM_VSX_P (V8HImode))
#define HAVE_vsx_xxpermdi_v4si_be (VECTOR_MEM_VSX_P (V4SImode))
#define HAVE_vsx_xxpermdi_v2di_be (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_xxpermdi_v4sf_be (VECTOR_MEM_VSX_P (V4SFmode))
#define HAVE_vsx_xxpermdi_v2df_be (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_xxpermdi_v1ti_be (VECTOR_MEM_VSX_P (V1TImode))
#define HAVE_vsx_xxpermdi_ti_be (VECTOR_MEM_VSX_P (TImode))
#define HAVE_vsx_xxpermdi_kf_be ((VECTOR_MEM_VSX_P (KFmode)) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_vsx_xxpermdi_tf_be ((VECTOR_MEM_VSX_P (TFmode)) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_vsx_extract_v16qi (VECTOR_MEM_VSX_P (V16QImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_extract_v8hi (VECTOR_MEM_VSX_P (V8HImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vsx_extract_v4si (VECTOR_MEM_VSX_P (V4SImode) && TARGET_DIRECT_MOVE_64BIT)
#define HAVE_vextractlv4si (TARGET_POWER10)
#define HAVE_vextractlv8hi (TARGET_POWER10)
#define HAVE_vextractlv16qi (TARGET_POWER10)
#define HAVE_vextractlv2di (TARGET_POWER10)
#define HAVE_vextractrv4si (TARGET_POWER10)
#define HAVE_vextractrv8hi (TARGET_POWER10)
#define HAVE_vextractrv16qi (TARGET_POWER10)
#define HAVE_vextractrv2di (TARGET_POWER10)
#define HAVE_vinsertvl_v4si (TARGET_POWER10)
#define HAVE_vinsertvl_v8hi (TARGET_POWER10)
#define HAVE_vinsertvl_v16qi (TARGET_POWER10)
#define HAVE_vinsertvl_v2di (TARGET_POWER10)
#define HAVE_vinsertvr_v4si (TARGET_POWER10)
#define HAVE_vinsertvr_v8hi (TARGET_POWER10)
#define HAVE_vinsertvr_v16qi (TARGET_POWER10)
#define HAVE_vinsertvr_v2di (TARGET_POWER10)
#define HAVE_vinsertgl_v4si (TARGET_POWER10)
#define HAVE_vinsertgl_v8hi (TARGET_POWER10)
#define HAVE_vinsertgl_v16qi (TARGET_POWER10)
#define HAVE_vinsertgl_v2di (TARGET_POWER10)
#define HAVE_vinsertgr_v4si (TARGET_POWER10)
#define HAVE_vinsertgr_v8hi (TARGET_POWER10)
#define HAVE_vinsertgr_v16qi (TARGET_POWER10)
#define HAVE_vinsertgr_v2di (TARGET_POWER10)
#define HAVE_vreplace_elt_v4si (TARGET_POWER10)
#define HAVE_vreplace_elt_v4sf (TARGET_POWER10)
#define HAVE_vreplace_elt_v2di (TARGET_POWER10)
#define HAVE_vreplace_elt_v2df (TARGET_POWER10)
#define HAVE_vreplace_un_v4si (TARGET_POWER10)
#define HAVE_vreplace_un_v4sf (TARGET_POWER10)
#define HAVE_vreplace_un_v2di (TARGET_POWER10)
#define HAVE_vreplace_un_v2df (TARGET_POWER10)
#define HAVE_vsx_mergel_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_mergel_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_mergeh_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_mergeh_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsx_splat_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_vsx_splat_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vsignextend_v2di_v1ti (TARGET_POWER10)
#define HAVE_vsignextend_qi_v2di (TARGET_P9_VECTOR)
#define HAVE_vsignextend_qi_v4si (TARGET_P9_VECTOR)
#define HAVE_vsignextend_hi_v2di (TARGET_P9_VECTOR)
#define HAVE_vsignextend_hi_v4si (TARGET_P9_VECTOR)
#define HAVE_vsignextend_si_v2di (TARGET_P9_VECTOR)
#define HAVE_extendditi2 (TARGET_POWER10)
#define HAVE_xscmpexpdp_eq (TARGET_P9_VECTOR)
#define HAVE_xscmpexpdp_lt (TARGET_P9_VECTOR)
#define HAVE_xscmpexpdp_gt (TARGET_P9_VECTOR)
#define HAVE_xscmpexpdp_unordered (TARGET_P9_VECTOR)
#define HAVE_xscmpexpqp_eq_kf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_xscmpexpqp_lt_kf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_xscmpexpqp_gt_kf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_xscmpexpqp_unordered_kf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_xscmpexpqp_eq_tf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_xscmpexpqp_lt_tf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_xscmpexpqp_gt_tf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_xscmpexpqp_unordered_tf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_xststdcqp_kf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_xststdcqp_tf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_xststdcsp (TARGET_P9_VECTOR)
#define HAVE_xststdcdp (TARGET_P9_VECTOR)
#define HAVE_xststdcnegqp_kf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (KFmode)))
#define HAVE_xststdcnegqp_tf ((TARGET_P9_VECTOR) && (FLOAT128_IEEE_P (TFmode)))
#define HAVE_xststdcnegsp (TARGET_P9_VECTOR)
#define HAVE_xststdcnegdp (TARGET_P9_VECTOR)
#define HAVE_first_match_index_v16qi (TARGET_P9_VECTOR)
#define HAVE_first_match_index_v8hi (TARGET_P9_VECTOR)
#define HAVE_first_match_index_v4si (TARGET_P9_VECTOR)
#define HAVE_first_match_or_eos_index_v16qi (TARGET_P9_VECTOR)
#define HAVE_first_match_or_eos_index_v8hi (TARGET_P9_VECTOR)
#define HAVE_first_match_or_eos_index_v4si (TARGET_P9_VECTOR)
#define HAVE_first_mismatch_index_v16qi (TARGET_P9_VECTOR)
#define HAVE_first_mismatch_index_v8hi (TARGET_P9_VECTOR)
#define HAVE_first_mismatch_index_v4si (TARGET_P9_VECTOR)
#define HAVE_first_mismatch_or_eos_index_v16qi (TARGET_P9_VECTOR)
#define HAVE_first_mismatch_or_eos_index_v8hi (TARGET_P9_VECTOR)
#define HAVE_first_mismatch_or_eos_index_v4si (TARGET_P9_VECTOR)
#define HAVE_lxvl (TARGET_P9_VECTOR && TARGET_64BIT)
#define HAVE_xl_len_r 1
#define HAVE_stxvl (TARGET_P9_VECTOR && TARGET_64BIT)
#define HAVE_len_load_v16qi (TARGET_P9_VECTOR && TARGET_64BIT)
#define HAVE_len_store_v16qi (TARGET_P9_VECTOR && TARGET_64BIT)
#define HAVE_xst_len_r (UNSPEC_XST_LEN_R)
#define HAVE_vcmpnet (TARGET_POWER10)
#define HAVE_insert4b (TARGET_P9_VECTOR)
#define HAVE_vextract_fp_from_shorth (TARGET_P9_VECTOR)
#define HAVE_vextract_fp_from_shortl (TARGET_P9_VECTOR)
#define HAVE_p9_xxbrq_v16qi (TARGET_P9_VECTOR)
#define HAVE_p9_xxbrd_v2df (TARGET_P9_VECTOR)
#define HAVE_p9_xxbrw_v4sf (TARGET_P9_VECTOR)
#define HAVE_revb_v8hi 1
#define HAVE_revb_v4si 1
#define HAVE_revb_v2di 1
#define HAVE_revb_v4sf 1
#define HAVE_revb_v2df 1
#define HAVE_revb_v1ti 1
#define HAVE_revb_v16qi 1
#define HAVE_vec_packs_float_v2di (TARGET_VSX)
#define HAVE_vec_packu_float_v2di (TARGET_VSX)
#define HAVE_vec_unpack_sfix_trunc_hi_v4sf (TARGET_VSX)
#define HAVE_vec_unpack_ufix_trunc_hi_v4sf (TARGET_VSX)
#define HAVE_vec_unpack_sfix_trunc_lo_v4sf (TARGET_VSX)
#define HAVE_vec_unpack_ufix_trunc_lo_v4sf (TARGET_VSX)
#define HAVE_altivec_mulv4sf3 (VECTOR_UNIT_ALTIVEC_P (V4SFmode))
#define HAVE_mulv4si3 (TARGET_ALTIVEC)
#define HAVE_mulv8hi3 (TARGET_ALTIVEC)
#define HAVE_xxspltiw_v4sf (TARGET_POWER10)
#define HAVE_xxspltidp_v2df (TARGET_POWER10)
#define HAVE_xxsplti32dx_v4si (TARGET_POWER10)
#define HAVE_xxsplti32dx_v4sf (TARGET_POWER10)
#define HAVE_xxpermx (TARGET_POWER10)
#define HAVE_vstrir_v8hi (TARGET_POWER10)
#define HAVE_vstrir_v16qi (TARGET_POWER10)
#define HAVE_vstrir_p_v8hi (TARGET_POWER10)
#define HAVE_vstrir_p_v16qi (TARGET_POWER10)
#define HAVE_vstril_v8hi (TARGET_POWER10)
#define HAVE_vstril_v16qi (TARGET_POWER10)
#define HAVE_vstril_p_v8hi (TARGET_POWER10)
#define HAVE_vstril_p_v16qi (TARGET_POWER10)
#define HAVE_altivec_vmrghb (TARGET_ALTIVEC)
#define HAVE_altivec_vmrghh (TARGET_ALTIVEC)
#define HAVE_altivec_vmrghw (VECTOR_MEM_ALTIVEC_P (V4SImode))
#define HAVE_altivec_vmrglb (TARGET_ALTIVEC)
#define HAVE_altivec_vmrglh (TARGET_ALTIVEC)
#define HAVE_altivec_vmrglw (VECTOR_MEM_ALTIVEC_P (V4SImode))
#define HAVE_p8_vmrgew_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_p8_vmrgew_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_p8_vmrgow_v2df (VECTOR_MEM_VSX_P (V2DFmode))
#define HAVE_p8_vmrgow_v2di (VECTOR_MEM_VSX_P (V2DImode))
#define HAVE_vec_widen_umult_even_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_widen_smult_even_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_widen_umult_even_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_widen_smult_even_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_widen_umult_even_v4si (TARGET_P8_VECTOR)
#define HAVE_vec_widen_umult_even_v2di (TARGET_POWER10)
#define HAVE_vec_widen_smult_even_v4si (TARGET_P8_VECTOR)
#define HAVE_vec_widen_smult_even_v2di (TARGET_POWER10)
#define HAVE_vec_widen_umult_odd_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_widen_smult_odd_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_widen_umult_odd_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_widen_smult_odd_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_widen_umult_odd_v4si (TARGET_P8_VECTOR)
#define HAVE_vec_widen_umult_odd_v2di (TARGET_POWER10)
#define HAVE_vec_widen_smult_odd_v4si (TARGET_P8_VECTOR)
#define HAVE_vec_widen_smult_odd_v2di (TARGET_POWER10)
#define HAVE_altivec_vrlqmi (TARGET_POWER10)
#define HAVE_altivec_vrlqnm (TARGET_POWER10)
#define HAVE_altivec_vsum2sws (TARGET_ALTIVEC)
#define HAVE_altivec_vsumsws (TARGET_ALTIVEC)
#define HAVE_altivec_vspltb (TARGET_ALTIVEC)
#define HAVE_altivec_vsplth (TARGET_ALTIVEC)
#define HAVE_altivec_vspltw (TARGET_ALTIVEC)
#define HAVE_altivec_vspltsf (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v4si (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v8hi (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v16qi (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v4sf (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v2df (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v2di (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v1ti (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_ti (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_kf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_altivec_vperm_tf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_altivec_vperm_v4si_uns (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v8hi_uns (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v16qi_uns (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v4sf_uns (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v2df_uns (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v2di_uns (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_v1ti_uns (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_ti_uns (TARGET_ALTIVEC)
#define HAVE_altivec_vperm_kf_uns ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_altivec_vperm_tf_uns ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_vec_permv16qi (TARGET_ALTIVEC)
#define HAVE_altivec_copysign_v4sf3 (VECTOR_UNIT_ALTIVEC_P (V4SFmode))
#define HAVE_altivec_lvsl (TARGET_ALTIVEC)
#define HAVE_altivec_lvsr (TARGET_ALTIVEC)
#define HAVE_build_vector_mask_for_load (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v4si (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v8hi (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v16qi (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v4sf (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v2df (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v2di (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_v1ti (TARGET_ALTIVEC)
#define HAVE_altivec_lvx_kf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_altivec_lvx_tf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_altivec_stvx_v4si (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v8hi (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v16qi (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v4sf (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v2df (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v2di (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_v1ti (TARGET_ALTIVEC)
#define HAVE_altivec_stvx_kf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (KFmode)))
#define HAVE_altivec_stvx_tf ((TARGET_ALTIVEC) && (FLOAT128_VECTOR_P (TFmode)))
#define HAVE_doubleev4sf2 (TARGET_VSX)
#define HAVE_doubleev4si2 (TARGET_VSX)
#define HAVE_unsdoubleev4si2 (TARGET_VSX)
#define HAVE_doubleov4sf2 (TARGET_VSX)
#define HAVE_doubleov4si2 (TARGET_VSX)
#define HAVE_unsdoubleov4si2 (TARGET_VSX)
#define HAVE_doublehv4sf2 (TARGET_VSX)
#define HAVE_doublehv4si2 (TARGET_VSX)
#define HAVE_unsdoublehv4si2 (TARGET_VSX)
#define HAVE_doublelv4sf2 (TARGET_VSX)
#define HAVE_doublelv4si2 (TARGET_VSX)
#define HAVE_unsdoublelv4si2 (TARGET_VSX)
#define HAVE_convert_4f32_8i16 (TARGET_P9_VECTOR)
#define HAVE_convert_4f32_8f16 (TARGET_P9_VECTOR)
#define HAVE_absv4si2 (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_absv8hi2 (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_absv16qi2 (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_absv2di2 (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_nabsv4si2 (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_nabsv8hi2 (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_nabsv16qi2 (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_nabsv2di2 (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_altivec_absv4sf2 (TARGET_ALTIVEC)
#define HAVE_altivec_abss_v4si (TARGET_ALTIVEC)
#define HAVE_altivec_abss_v8hi (TARGET_ALTIVEC)
#define HAVE_altivec_abss_v16qi (TARGET_ALTIVEC)
#define HAVE_reduc_plus_scal_v8hi (TARGET_ALTIVEC)
#define HAVE_reduc_plus_scal_v16qi (TARGET_ALTIVEC)
#define HAVE_negv4si2 (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_negv8hi2 (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_negv16qi2 (VECTOR_UNIT_ALTIVEC_P (V16QImode))
#define HAVE_negv2di2 (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_udot_prodv8hi (TARGET_ALTIVEC)
#define HAVE_udot_prodv16qi (TARGET_ALTIVEC)
#define HAVE_sdot_prodv8hi (TARGET_ALTIVEC)
#define HAVE_widen_usumv8hi3 (TARGET_ALTIVEC)
#define HAVE_widen_usumv16qi3 (TARGET_ALTIVEC)
#define HAVE_widen_ssumv16qi3 (TARGET_ALTIVEC)
#define HAVE_widen_ssumv8hi3 (TARGET_ALTIVEC)
#define HAVE_vec_unpacks_hi_v4si (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_vec_unpacks_hi_v8hi (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_vec_unpacks_hi_v16qi (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_vec_unpacks_lo_v4si (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_vec_unpacks_lo_v8hi (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_vec_unpacks_lo_v16qi (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_vec_unpacku_hi_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_unpacku_hi_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_unpacku_lo_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_unpacku_lo_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_widen_umult_hi_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_widen_umult_lo_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_widen_smult_hi_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_widen_smult_lo_v16qi (TARGET_ALTIVEC)
#define HAVE_vec_widen_umult_hi_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_widen_umult_lo_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_widen_smult_hi_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_widen_smult_lo_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_pack_trunc_v2di (VECTOR_UNIT_P8_VECTOR_P (V2DImode))
#define HAVE_vec_pack_trunc_v4si (VECTOR_UNIT_ALTIVEC_P (V4SImode))
#define HAVE_vec_pack_trunc_v8hi (VECTOR_UNIT_ALTIVEC_P (V8HImode))
#define HAVE_mulv16qi3 (TARGET_ALTIVEC)
#define HAVE_altivec_vpermxor (TARGET_P8_VECTOR)
#define HAVE_altivec_negv4sf2 (TARGET_ALTIVEC)
#define HAVE_altivec_vreveti2 (TARGET_ALTIVEC)
#define HAVE_altivec_vrevev16qi2 (TARGET_ALTIVEC)
#define HAVE_altivec_vrevev8hi2 (TARGET_ALTIVEC)
#define HAVE_altivec_vrevev4si2 (TARGET_ALTIVEC)
#define HAVE_altivec_vrevev2di2 (TARGET_ALTIVEC)
#define HAVE_altivec_vrevev4sf2 (TARGET_ALTIVEC)
#define HAVE_altivec_vrevev2df2 (TARGET_ALTIVEC)
#define HAVE_vec_unpacks_float_hi_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_unpacks_float_lo_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_unpacku_float_hi_v8hi (TARGET_ALTIVEC)
#define HAVE_vec_unpacku_float_lo_v8hi (TARGET_ALTIVEC)
#define HAVE_vaduv4si3 (TARGET_P9_VECTOR)
#define HAVE_vaduv8hi3 (TARGET_P9_VECTOR)
#define HAVE_vaduv16qi3 (TARGET_P9_VECTOR)
#define HAVE_usadv16qi (TARGET_P9_VECTOR)
#define HAVE_usadv8hi (TARGET_P9_VECTOR)
#define HAVE_bcdadd_eq_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdsub_eq_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdadd_lt_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdsub_lt_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdadd_le_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdsub_le_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdadd_gt_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdsub_gt_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdadd_ge_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdsub_ge_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdadd_unordered_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdsub_unordered_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdadd_eq_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdsub_eq_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdadd_lt_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdsub_lt_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdadd_le_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdsub_le_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdadd_gt_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdsub_gt_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdadd_ge_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdsub_ge_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdadd_unordered_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdsub_unordered_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdinvalid_v1ti (TARGET_P8_VECTOR)
#define HAVE_bcdinvalid_v16qi (TARGET_P8_VECTOR)
#define HAVE_bcdmul10_v16qi (TARGET_P9_VECTOR)
#define HAVE_bcddiv10_v16qi (TARGET_P9_VECTOR)
#define HAVE_movoo (TARGET_MMA)
#define HAVE_movxo (TARGET_MMA)
#define HAVE_vsx_assemble_pair (TARGET_MMA)
#define HAVE_vsx_disassemble_pair (TARGET_MMA)
#define HAVE_mma_assemble_acc (TARGET_MMA)
#define HAVE_mma_disassemble_acc (TARGET_MMA)
#define HAVE_mma_xxsetaccz (TARGET_MMA)
#define HAVE_extendsdtd2 (TARGET_DFP)
#define HAVE_dfp_denbcd_v16qi (TARGET_DFP)
#define HAVE_dfptstsfi_eq_dd (TARGET_P9_MISC)
#define HAVE_dfptstsfi_lt_dd (TARGET_P9_MISC)
#define HAVE_dfptstsfi_gt_dd (TARGET_P9_MISC)
#define HAVE_dfptstsfi_unordered_dd (TARGET_P9_MISC)
#define HAVE_dfptstsfi_eq_td (TARGET_P9_MISC)
#define HAVE_dfptstsfi_lt_td (TARGET_P9_MISC)
#define HAVE_dfptstsfi_gt_td (TARGET_P9_MISC)
#define HAVE_dfptstsfi_unordered_td (TARGET_P9_MISC)
#define HAVE_tabort (TARGET_HTM)
#define HAVE_tabortwc (TARGET_HTM)
#define HAVE_tabortdc ((TARGET_HTM) && (TARGET_POWERPC64))
#define HAVE_tabortwci (TARGET_HTM)
#define HAVE_tabortdci ((TARGET_HTM) && (TARGET_POWERPC64))
#define HAVE_tbegin (TARGET_HTM)
#define HAVE_tcheck (TARGET_HTM)
#define HAVE_tend (TARGET_HTM)
#define HAVE_trechkpt (TARGET_HTM)
#define HAVE_treclaim (TARGET_HTM)
#define HAVE_tsr (TARGET_HTM)
#define HAVE_ttest (TARGET_HTM)
static inline rtx gen_adddi3_high                       (rtx, rtx, rtx);
static inline rtx
gen_adddi3_high(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_movdf_low_si                      (rtx, rtx, rtx);
static inline rtx
gen_movdf_low_si(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_movdf_low_di                      (rtx, rtx, rtx);
static inline rtx
gen_movdf_low_di(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_movdf_low_st_si                   (rtx, rtx, rtx);
static inline rtx
gen_movdf_low_st_si(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_movdf_low_st_di                   (rtx, rtx, rtx);
static inline rtx
gen_movdf_low_st_di(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_movsf_low_si                      (rtx, rtx, rtx);
static inline rtx
gen_movsf_low_si(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_movsf_low_di                      (rtx, rtx, rtx);
static inline rtx
gen_movsf_low_di(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_movsf_low_st_si                   (rtx, rtx, rtx);
static inline rtx
gen_movsf_low_st_si(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_movsf_low_st_di                   (rtx, rtx, rtx);
static inline rtx
gen_movsf_low_st_di(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_macho_high_si                     (rtx, rtx);
static inline rtx
gen_macho_high_si(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
static inline rtx gen_macho_high_di                     (rtx, rtx);
static inline rtx
gen_macho_high_di(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
static inline rtx gen_macho_low_si                      (rtx, rtx, rtx);
static inline rtx
gen_macho_low_si(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_macho_low_di                      (rtx, rtx, rtx);
static inline rtx
gen_macho_low_di(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_macho_correct_pic_si              (rtx, rtx, rtx, rtx);
static inline rtx
gen_macho_correct_pic_si(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
static inline rtx gen_macho_correct_pic_di              (rtx, rtx, rtx, rtx);
static inline rtx
gen_macho_correct_pic_di(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
static inline rtx gen_load_macho_picbase_si             (rtx);
static inline rtx
gen_load_macho_picbase_si(rtx ARG_UNUSED (a))
{
  return 0;
}
static inline rtx gen_load_macho_picbase_di             (rtx);
static inline rtx
gen_load_macho_picbase_di(rtx ARG_UNUSED (a))
{
  return 0;
}
static inline rtx gen_reload_macho_picbase_si           (rtx);
static inline rtx
gen_reload_macho_picbase_si(rtx ARG_UNUSED (a))
{
  return 0;
}
static inline rtx gen_reload_macho_picbase_di           (rtx);
static inline rtx
gen_reload_macho_picbase_di(rtx ARG_UNUSED (a))
{
  return 0;
}
static inline rtx gen_nonlocal_goto_receiver            (void);
static inline rtx
gen_nonlocal_goto_receiver(void)
{
  return 0;
}
extern rtx        gen_zero_extendqisi2                  (rtx, rtx);
extern rtx        gen_zero_extendqidi2                  (rtx, rtx);
extern rtx        gen_zero_extendhisi2                  (rtx, rtx);
extern rtx        gen_zero_extendhidi2                  (rtx, rtx);
extern rtx        gen_zero_extendsidi2                  (rtx, rtx);
extern rtx        gen_extendqisi2                       (rtx, rtx);
extern rtx        gen_extendqidi2                       (rtx, rtx);
extern rtx        gen_extendsidi2                       (rtx, rtx);
extern rtx        gen_dlmzb                             (rtx, rtx, rtx, rtx);
extern rtx        gen_addsi3_carry                      (rtx, rtx, rtx);
extern rtx        gen_adddi3_carry                      (rtx, rtx, rtx);
extern rtx        gen_addsi3_carry_in_0                 (rtx, rtx);
extern rtx        gen_adddi3_carry_in_0                 (rtx, rtx);
extern rtx        gen_addsi3_carry_in_m1                (rtx, rtx);
extern rtx        gen_adddi3_carry_in_m1                (rtx, rtx);
extern rtx        gen_subfsi3_imm                       (rtx, rtx, rtx);
extern rtx        gen_subfdi3_imm                       (rtx, rtx, rtx);
extern rtx        gen_subfsi3_carry_dot2                (rtx, rtx, rtx, rtx);
extern rtx        gen_subfdi3_carry_dot2                (rtx, rtx, rtx, rtx);
extern rtx        gen_subfsi3_carry                     (rtx, rtx, rtx);
extern rtx        gen_subfdi3_carry                     (rtx, rtx, rtx);
extern rtx        gen_subfsi3_carry_in_0                (rtx, rtx);
extern rtx        gen_subfdi3_carry_in_0                (rtx, rtx);
extern rtx        gen_subfsi3_carry_in_m1               (rtx, rtx);
extern rtx        gen_subfdi3_carry_in_m1               (rtx, rtx);
extern rtx        gen_subfsi3_carry_in_xx               (rtx);
extern rtx        gen_subfdi3_carry_in_xx               (rtx);
extern rtx        gen_negsi2                            (rtx, rtx);
extern rtx        gen_negdi2                            (rtx, rtx);
extern rtx        gen_clzsi2                            (rtx, rtx);
extern rtx        gen_clzdi2                            (rtx, rtx);
extern rtx        gen_ctzsi2_hw                         (rtx, rtx);
extern rtx        gen_ctzdi2_hw                         (rtx, rtx);
extern rtx        gen_popcntbsi2                        (rtx, rtx);
extern rtx        gen_popcntbdi2                        (rtx, rtx);
extern rtx        gen_popcntdsi2                        (rtx, rtx);
extern rtx        gen_popcntddi2                        (rtx, rtx);
extern rtx        gen_paritysi2_cmpb                    (rtx, rtx);
extern rtx        gen_paritydi2_cmpb                    (rtx, rtx);
extern rtx        gen_cfuged                            (rtx, rtx, rtx);
extern rtx        gen_cntlzdm                           (rtx, rtx, rtx);
extern rtx        gen_cnttzdm                           (rtx, rtx, rtx);
extern rtx        gen_pdepd                             (rtx, rtx, rtx);
extern rtx        gen_pextd                             (rtx, rtx, rtx);
extern rtx        gen_cmpbsi3                           (rtx, rtx, rtx);
extern rtx        gen_cmpbdi3                           (rtx, rtx, rtx);
extern rtx        gen_bswaphi2_load                     (rtx, rtx);
extern rtx        gen_bswapsi2_load                     (rtx, rtx);
extern rtx        gen_bswaphi2_store                    (rtx, rtx);
extern rtx        gen_bswapsi2_store                    (rtx, rtx);
extern rtx        gen_bswaphi2_reg                      (rtx, rtx);
extern rtx        gen_bswapsi2_reg                      (rtx, rtx);
extern rtx        gen_bswapdi2_load                     (rtx, rtx);
extern rtx        gen_bswapdi2_store                    (rtx, rtx);
extern rtx        gen_bswapdi2_brd                      (rtx, rtx);
extern rtx        gen_bswapdi2_reg                      (rtx, rtx);
extern rtx        gen_bswapdi2_32bit                    (rtx, rtx);
extern rtx        gen_mulsi3                            (rtx, rtx, rtx);
extern rtx        gen_muldi3                            (rtx, rtx, rtx);
extern rtx        gen_smulsi3_highpart_le               (rtx, rtx, rtx);
extern rtx        gen_umulsi3_highpart_le               (rtx, rtx, rtx);
extern rtx        gen_smuldi3_highpart_le               (rtx, rtx, rtx);
extern rtx        gen_umuldi3_highpart_le               (rtx, rtx, rtx);
extern rtx        gen_smulsi3_highpart_64               (rtx, rtx, rtx);
extern rtx        gen_umulsi3_highpart_64               (rtx, rtx, rtx);
extern rtx        gen_udivsi3                           (rtx, rtx, rtx);
extern rtx        gen_udivdi3                           (rtx, rtx, rtx);
extern rtx        gen_udivti3                           (rtx, rtx, rtx);
extern rtx        gen_divsi3_sra                        (rtx, rtx, rtx);
extern rtx        gen_divdi3_sra                        (rtx, rtx, rtx);
extern rtx        gen_divti3                            (rtx, rtx, rtx);
extern rtx        gen_umodsi3                           (rtx, rtx, rtx);
extern rtx        gen_umoddi3                           (rtx, rtx, rtx);
extern rtx        gen_umodti3                           (rtx, rtx, rtx);
extern rtx        gen_modti3                            (rtx, rtx, rtx);
extern rtx        gen_andsi3_imm                        (rtx, rtx, rtx);
extern rtx        gen_anddi3_imm                        (rtx, rtx, rtx);
extern rtx        gen_andsi3_mask                       (rtx, rtx, rtx);
extern rtx        gen_anddi3_mask                       (rtx, rtx, rtx);
extern rtx        gen_rotlsi3_insert_3                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_rotldi3_insert_3                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_rotlsi3                           (rtx, rtx, rtx);
extern rtx        gen_rotldi3                           (rtx, rtx, rtx);
extern rtx        gen_ashlsi3                           (rtx, rtx, rtx);
extern rtx        gen_ashldi3                           (rtx, rtx, rtx);
extern rtx        gen_ashdi3_extswsli                   (rtx, rtx, rtx);
extern rtx        gen_ashdi3_extswsli_dot               (rtx, rtx, rtx, rtx);
extern rtx        gen_ashdi3_extswsli_dot2              (rtx, rtx, rtx, rtx);
extern rtx        gen_lshrsi3                           (rtx, rtx, rtx);
extern rtx        gen_lshrdi3                           (rtx, rtx, rtx);
extern rtx        gen_ashrsi3                           (rtx, rtx, rtx);
extern rtx        gen_ashrdi3                           (rtx, rtx, rtx);
extern rtx        gen_fres                              (rtx, rtx);
extern rtx        gen_fred                              (rtx, rtx);
extern rtx        gen_signbitkf2_dm                     (rtx, rtx);
extern rtx        gen_signbittf2_dm                     (rtx, rtx);
extern rtx        gen_copysignsf3_fcpsgn                (rtx, rtx, rtx);
extern rtx        gen_copysigndf3_fcpsgn                (rtx, rtx, rtx);
extern rtx        gen_sminkf3                           (rtx, rtx, rtx);
extern rtx        gen_smaxkf3                           (rtx, rtx, rtx);
extern rtx        gen_smintf3                           (rtx, rtx, rtx);
extern rtx        gen_smaxtf3                           (rtx, rtx, rtx);
extern rtx        gen_isel_signed_si                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_isel_signed_di                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_isel_unsigned_si                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_isel_unsigned_di                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_setbc_signed_si                   (rtx, rtx, rtx);
extern rtx        gen_setbc_signed_di                   (rtx, rtx, rtx);
extern rtx        gen_setbc_unsigned_si                 (rtx, rtx, rtx);
extern rtx        gen_setbc_unsigned_di                 (rtx, rtx, rtx);
extern rtx        gen_lfiwax                            (rtx, rtx);
extern rtx        gen_floatsisf2_lfiwax                 (rtx, rtx);
extern rtx        gen_floatsidf2_lfiwax                 (rtx, rtx);
extern rtx        gen_floatsisf2_lfiwax_mem             (rtx, rtx);
extern rtx        gen_floatsidf2_lfiwax_mem             (rtx, rtx);
extern rtx        gen_lfiwzx                            (rtx, rtx);
extern rtx        gen_floatunssisf2_lfiwzx              (rtx, rtx);
extern rtx        gen_floatunssidf2_lfiwzx              (rtx, rtx);
extern rtx        gen_floatunssisf2_lfiwzx_mem          (rtx, rtx);
extern rtx        gen_floatunssidf2_lfiwzx_mem          (rtx, rtx);
extern rtx        gen_fix_truncsfsi2_stfiwx             (rtx, rtx);
extern rtx        gen_fix_truncdfsi2_stfiwx             (rtx, rtx);
extern rtx        gen_fix_truncsfsi2_internal           (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncdfsi2_internal           (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncsfqi2                    (rtx, rtx);
extern rtx        gen_fixuns_truncsfqi2                 (rtx, rtx);
extern rtx        gen_fix_truncsfhi2                    (rtx, rtx);
extern rtx        gen_fixuns_truncsfhi2                 (rtx, rtx);
extern rtx        gen_fix_truncdfqi2                    (rtx, rtx);
extern rtx        gen_fixuns_truncdfqi2                 (rtx, rtx);
extern rtx        gen_fix_truncdfhi2                    (rtx, rtx);
extern rtx        gen_fixuns_truncdfhi2                 (rtx, rtx);
extern rtx        gen_fixuns_truncsfsi2_stfiwx          (rtx, rtx);
extern rtx        gen_fixuns_truncdfsi2_stfiwx          (rtx, rtx);
extern rtx        gen_fixuns_truncsfdi2                 (rtx, rtx);
extern rtx        gen_fixuns_truncdfdi2                 (rtx, rtx);
extern rtx        gen_rs6000_mtfsb0                     (rtx);
extern rtx        gen_rs6000_mtfsb1                     (rtx);
extern rtx        gen_rs6000_mffscrn                    (rtx, rtx);
extern rtx        gen_rs6000_mffscdrn                   (rtx, rtx);
extern rtx        gen_fctiwz_sf                         (rtx, rtx);
extern rtx        gen_fctiwz_df                         (rtx, rtx);
extern rtx        gen_fctiwuz_sf                        (rtx, rtx);
extern rtx        gen_fctiwuz_df                        (rtx, rtx);
extern rtx        gen_lrintsfdi2                        (rtx, rtx);
extern rtx        gen_lrintdfdi2                        (rtx, rtx);
extern rtx        gen_btruncsf2                         (rtx, rtx);
extern rtx        gen_btruncdf2                         (rtx, rtx);
extern rtx        gen_ceilsf2                           (rtx, rtx);
extern rtx        gen_ceildf2                           (rtx, rtx);
extern rtx        gen_floorsf2                          (rtx, rtx);
extern rtx        gen_floordf2                          (rtx, rtx);
extern rtx        gen_roundsf2                          (rtx, rtx);
extern rtx        gen_rounddf2                          (rtx, rtx);
extern rtx        gen_stfiwx                            (rtx, rtx);
extern rtx        gen_floatdidf2                        (rtx, rtx);
extern rtx        gen_floattikf2                        (rtx, rtx);
extern rtx        gen_floattitf2                        (rtx, rtx);
extern rtx        gen_floatunstikf2                     (rtx, rtx);
extern rtx        gen_floatunstitf2                     (rtx, rtx);
extern rtx        gen_fix_trunckfti2                    (rtx, rtx);
extern rtx        gen_fix_trunctfti2                    (rtx, rtx);
extern rtx        gen_fixuns_trunckfti2                 (rtx, rtx);
extern rtx        gen_fixuns_trunctfti2                 (rtx, rtx);
extern rtx        gen_floatdisf2_fcfids                 (rtx, rtx);
extern rtx        gen_floatdisf2_internal1              (rtx, rtx);
extern rtx        gen_floatunsdisf2_fcfidus             (rtx, rtx);
extern rtx        gen_one_cmplti2                       (rtx, rtx);
extern rtx        gen_one_cmplpti2                      (rtx, rtx);
extern rtx        gen_one_cmplv16qi2                    (rtx, rtx);
extern rtx        gen_one_cmplv8hi2                     (rtx, rtx);
extern rtx        gen_one_cmplv4si2                     (rtx, rtx);
extern rtx        gen_one_cmplv4sf2                     (rtx, rtx);
extern rtx        gen_one_cmplv2di2                     (rtx, rtx);
extern rtx        gen_one_cmplv2df2                     (rtx, rtx);
extern rtx        gen_one_cmplv1ti2                     (rtx, rtx);
extern rtx        gen_movsi_from_sf                     (rtx, rtx);
extern rtx        gen_movsf_hardfloat                   (rtx, rtx);
extern rtx        gen_movsd_hardfloat                   (rtx, rtx);
extern rtx        gen_movsf_from_si                     (rtx, rtx);
extern rtx        gen_movsf_from_si2                    (rtx, rtx);
extern rtx        gen_extenddfif2_fprs                  (rtx, rtx, rtx);
extern rtx        gen_extenddftf2_fprs                  (rtx, rtx, rtx);
extern rtx        gen_extenddfif2_vsx                   (rtx, rtx);
extern rtx        gen_extenddftf2_vsx                   (rtx, rtx);
extern rtx        gen_truncifdf2_internal1              (rtx, rtx);
extern rtx        gen_trunctfdf2_internal1              (rtx, rtx);
extern rtx        gen_truncifdf2_internal2              (rtx, rtx);
extern rtx        gen_trunctfdf2_internal2              (rtx, rtx);
extern rtx        gen_fix_trunc_helperif                (rtx, rtx, rtx);
extern rtx        gen_fix_trunc_helpertf                (rtx, rtx, rtx);
extern rtx        gen_negif2_internal                   (rtx, rtx);
extern rtx        gen_negtf2_internal                   (rtx, rtx);
extern rtx        gen_ieee_128bit_vsx_negkf2            (rtx, rtx);
extern rtx        gen_ieee_128bit_vsx_negtf2            (rtx, rtx);
extern rtx        gen_ieee_128bit_vsx_abskf2            (rtx, rtx);
extern rtx        gen_ieee_128bit_vsx_abstf2            (rtx, rtx);
extern rtx        gen_p8_fmrgow_di                      (rtx, rtx, rtx);
extern rtx        gen_p8_fmrgow_df                      (rtx, rtx, rtx);
extern rtx        gen_p8_fmrgow_dd                      (rtx, rtx, rtx);
extern rtx        gen_p8_mtvsrwz                        (rtx, rtx);
extern rtx        gen_p8_mtvsrwz_v16qisi2               (rtx, rtx);
extern rtx        gen_p8_mtvsrd_v16qidi2                (rtx, rtx);
extern rtx        gen_reload_fpr_from_gprdi             (rtx, rtx, rtx);
extern rtx        gen_reload_fpr_from_gprdf             (rtx, rtx, rtx);
extern rtx        gen_reload_fpr_from_gprdd             (rtx, rtx, rtx);
extern rtx        gen_p8_mtvsrd_df                      (rtx, rtx);
extern rtx        gen_p8_xxpermdi_ti                    (rtx, rtx, rtx);
extern rtx        gen_p8_xxpermdi_v16qi                 (rtx, rtx, rtx);
extern rtx        gen_p8_xxpermdi_v8hi                  (rtx, rtx, rtx);
extern rtx        gen_p8_xxpermdi_v4si                  (rtx, rtx, rtx);
extern rtx        gen_p8_xxpermdi_v4sf                  (rtx, rtx, rtx);
extern rtx        gen_p8_xxpermdi_v2di                  (rtx, rtx, rtx);
extern rtx        gen_p8_xxpermdi_v2df                  (rtx, rtx, rtx);
extern rtx        gen_p8_xxpermdi_v1ti                  (rtx, rtx, rtx);
extern rtx        gen_p8_xxpermdi_kf                    (rtx, rtx, rtx);
extern rtx        gen_p8_xxpermdi_tf                    (rtx, rtx, rtx);
extern rtx        gen_reload_vsx_from_gprti             (rtx, rtx, rtx);
extern rtx        gen_reload_vsx_from_gprv16qi          (rtx, rtx, rtx);
extern rtx        gen_reload_vsx_from_gprv8hi           (rtx, rtx, rtx);
extern rtx        gen_reload_vsx_from_gprv4si           (rtx, rtx, rtx);
extern rtx        gen_reload_vsx_from_gprv4sf           (rtx, rtx, rtx);
extern rtx        gen_reload_vsx_from_gprv2di           (rtx, rtx, rtx);
extern rtx        gen_reload_vsx_from_gprv2df           (rtx, rtx, rtx);
extern rtx        gen_reload_vsx_from_gprv1ti           (rtx, rtx, rtx);
extern rtx        gen_reload_vsx_from_gprkf             (rtx, rtx, rtx);
extern rtx        gen_reload_vsx_from_gprtf             (rtx, rtx, rtx);
extern rtx        gen_p8_mtvsrd_sf                      (rtx, rtx);
extern rtx        gen_reload_vsx_from_gprsf             (rtx, rtx, rtx);
extern rtx        gen_p8_mfvsrd_3_ti                    (rtx, rtx);
extern rtx        gen_p8_mfvsrd_3_v16qi                 (rtx, rtx);
extern rtx        gen_p8_mfvsrd_3_v8hi                  (rtx, rtx);
extern rtx        gen_p8_mfvsrd_3_v4si                  (rtx, rtx);
extern rtx        gen_p8_mfvsrd_3_v4sf                  (rtx, rtx);
extern rtx        gen_p8_mfvsrd_3_v2di                  (rtx, rtx);
extern rtx        gen_p8_mfvsrd_3_v2df                  (rtx, rtx);
extern rtx        gen_p8_mfvsrd_3_v1ti                  (rtx, rtx);
extern rtx        gen_p8_mfvsrd_3_kf                    (rtx, rtx);
extern rtx        gen_p8_mfvsrd_3_tf                    (rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxti             (rtx, rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxv16qi          (rtx, rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxv8hi           (rtx, rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxv4si           (rtx, rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxv4sf           (rtx, rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxv2di           (rtx, rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxv2df           (rtx, rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxv1ti           (rtx, rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxkf             (rtx, rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxtf             (rtx, rtx, rtx);
extern rtx        gen_reload_gpr_from_vsxsf             (rtx, rtx, rtx);
extern rtx        gen_movdi_si_update                   (rtx, rtx, rtx, rtx);
extern rtx        gen_movdi_di_update                   (rtx, rtx, rtx, rtx);
extern rtx        gen_movdi_update_stack                (rtx, rtx, rtx, rtx);
extern rtx        gen_movsi_si_update                   (rtx, rtx, rtx, rtx);
extern rtx        gen_movsi_di_update                   (rtx, rtx, rtx, rtx);
extern rtx        gen_movsi_update_stack                (rtx, rtx, rtx, rtx);
static inline rtx gen_tls_dtprel_32                     (rtx, rtx, rtx);
static inline rtx
gen_tls_dtprel_32(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_dtprel_64                     (rtx, rtx, rtx);
static inline rtx
gen_tls_dtprel_64(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_dtprel_ha_32                  (rtx, rtx, rtx);
static inline rtx
gen_tls_dtprel_ha_32(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_dtprel_ha_64                  (rtx, rtx, rtx);
static inline rtx
gen_tls_dtprel_ha_64(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_dtprel_lo_32                  (rtx, rtx, rtx);
static inline rtx
gen_tls_dtprel_lo_32(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_dtprel_lo_64                  (rtx, rtx, rtx);
static inline rtx
gen_tls_dtprel_lo_64(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_got_dtprel_32                 (rtx, rtx, rtx);
static inline rtx
gen_tls_got_dtprel_32(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_got_dtprel_64                 (rtx, rtx, rtx);
static inline rtx
gen_tls_got_dtprel_64(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_tprel_32                      (rtx, rtx, rtx);
static inline rtx
gen_tls_tprel_32(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_tprel_64                      (rtx, rtx, rtx);
static inline rtx
gen_tls_tprel_64(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_tprel_ha_32                   (rtx, rtx, rtx);
static inline rtx
gen_tls_tprel_ha_32(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_tprel_ha_64                   (rtx, rtx, rtx);
static inline rtx
gen_tls_tprel_ha_64(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_tprel_lo_32                   (rtx, rtx, rtx);
static inline rtx
gen_tls_tprel_lo_32(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_tprel_lo_64                   (rtx, rtx, rtx);
static inline rtx
gen_tls_tprel_lo_64(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_got_tprel_32                  (rtx, rtx, rtx);
static inline rtx
gen_tls_got_tprel_32(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_got_tprel_64                  (rtx, rtx, rtx);
static inline rtx
gen_tls_got_tprel_64(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_tls_pcrel_32                  (rtx, rtx, rtx);
static inline rtx
gen_tls_tls_pcrel_32(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_tls_pcrel_64                  (rtx, rtx, rtx);
static inline rtx
gen_tls_tls_pcrel_64(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_tls_32                        (rtx, rtx, rtx);
static inline rtx
gen_tls_tls_32(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_tls_64                        (rtx, rtx, rtx);
static inline rtx
gen_tls_tls_64(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_get_tpointer_internal         (void);
static inline rtx
gen_tls_get_tpointer_internal(void)
{
  return 0;
}
static inline rtx gen_tls_get_addr_internalsi           (void);
static inline rtx
gen_tls_get_addr_internalsi(void)
{
  return 0;
}
static inline rtx gen_tls_get_addr_internaldi           (void);
static inline rtx
gen_tls_get_addr_internaldi(void)
{
  return 0;
}
static inline rtx gen_load_toc_aix_si                   (rtx);
static inline rtx
gen_load_toc_aix_si(rtx ARG_UNUSED (a))
{
  return 0;
}
static inline rtx gen_load_toc_aix_di                   (rtx);
static inline rtx
gen_load_toc_aix_di(rtx ARG_UNUSED (a))
{
  return 0;
}
extern rtx        gen_load_toc_v4_pic_si                (void);
extern rtx        gen_load_toc_v4_PIC_1_normal          (rtx);
static inline rtx gen_load_toc_v4_PIC_1_476             (rtx);
static inline rtx
gen_load_toc_v4_PIC_1_476(rtx ARG_UNUSED (a))
{
  return 0;
}
extern rtx        gen_load_toc_v4_PIC_1b_normal         (rtx, rtx);
static inline rtx gen_load_toc_v4_PIC_1b_476            (rtx, rtx);
static inline rtx
gen_load_toc_v4_PIC_1b_476(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_load_toc_v4_PIC_2                 (rtx, rtx, rtx, rtx);
extern rtx        gen_load_toc_v4_PIC_3b                (rtx, rtx, rtx, rtx);
extern rtx        gen_load_toc_v4_PIC_3c                (rtx, rtx, rtx, rtx);
extern rtx        gen_elf_base_high                     (rtx, rtx, rtx);
extern rtx        gen_elf_base_low                      (rtx, rtx, rtx);
extern rtx        gen_elf_high                          (rtx, rtx);
extern rtx        gen_elf_low                           (rtx, rtx, rtx);
extern rtx        gen_blockage                          (void);
extern rtx        gen_probe_stack_si                    (rtx);
extern rtx        gen_probe_stack_di                    (rtx);
extern rtx        gen_probe_stack_rangesi               (rtx, rtx, rtx, rtx);
extern rtx        gen_probe_stack_rangedi               (rtx, rtx, rtx, rtx);
extern rtx        gen_stack_protect_setsi               (rtx, rtx);
extern rtx        gen_stack_protect_setdi               (rtx, rtx);
extern rtx        gen_stack_protect_testsi              (rtx, rtx, rtx);
extern rtx        gen_stack_protect_testdi              (rtx, rtx, rtx);
extern rtx        gen_setsi_cc                          (rtx, rtx, rtx);
extern rtx        gen_setdi_cc                          (rtx, rtx, rtx);
extern rtx        gen_eqsisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_nesisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_ltsisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_ltusisi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_gtsisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_gtusisi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_lesisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_leusisi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_gesisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_geusisi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_eqdisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_nedisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_ltdisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_ltudisi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_gtdisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_gtudisi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_ledisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_leudisi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_gedisi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_geudisi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_eqsidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_nesidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_ltsidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_ltusidi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_gtsidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_gtusidi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_lesidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_leusidi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_gesidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_geusidi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_eqdidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_nedidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_ltdidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_ltudidi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_gtdidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_gtudidi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_ledidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_leudidi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_gedidi2_isel                      (rtx, rtx, rtx);
extern rtx        gen_geudidi2_isel                     (rtx, rtx, rtx);
extern rtx        gen_cceq_ior_compare_si               (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_cceq_ior_compare_di               (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_cceq_ior_compare_complement       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_cceq_rev_compare_si               (rtx, rtx, rtx);
extern rtx        gen_cceq_rev_compare_di               (rtx, rtx, rtx);
extern rtx        gen_jump                              (rtx);
extern rtx        gen_return                            (void);
extern rtx        gen_simple_return                     (void);
extern rtx        gen_indirect_jumpsi_nospec            (rtx, rtx);
extern rtx        gen_indirect_jumpdi_nospec            (rtx, rtx);
extern rtx        gen_tablejumpsi_insn_normal           (rtx, rtx);
extern rtx        gen_tablejumpdi_insn_normal           (rtx, rtx);
extern rtx        gen_tablejumpsi_insn_nospec           (rtx, rtx, rtx);
extern rtx        gen_tablejumpdi_insn_nospec           (rtx, rtx, rtx);
extern rtx        gen_nop                               (void);
extern rtx        gen_group_ending_nop                  (void);
extern rtx        gen_speculation_barrier               (void);
extern rtx        gen_bdz_si                            (rtx, rtx, rtx);
extern rtx        gen_bdnz_si                           (rtx, rtx, rtx);
extern rtx        gen_bdz_di                            (rtx, rtx, rtx);
extern rtx        gen_bdnz_di                           (rtx, rtx, rtx);
extern rtx        gen_bdztf_si                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_bdnztf_si                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_bdztf_di                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_bdnztf_di                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_trap                              (void);
extern rtx        gen_prologue_movesi_from_cr           (rtx);
extern rtx        gen_stack_tie                         (rtx);
extern rtx        gen_stack_restore_tie                 (rtx, rtx, rtx);
extern rtx        gen_eh_set_lr_si                      (rtx);
extern rtx        gen_eh_set_lr_di                      (rtx);
extern rtx        gen_prefetch                          (rtx, rtx, rtx);
extern rtx        gen_load_split_stack_limit_di         (rtx);
extern rtx        gen_load_split_stack_limit_si         (rtx);
extern rtx        gen_split_stack_return                (void);
extern rtx        gen_bpermd_si                         (rtx, rtx, rtx);
extern rtx        gen_bpermd_di                         (rtx, rtx, rtx);
extern rtx        gen_rs6000_get_timebase_ppc32         (rtx);
extern rtx        gen_rs6000_mftb_si                    (rtx);
extern rtx        gen_rs6000_mftb_di                    (rtx);
extern rtx        gen_rs6000_mffsl_hw                   (rtx);
extern rtx        gen_rs6000_mffs                       (rtx);
extern rtx        gen_rs6000_mtfsf                      (rtx, rtx);
extern rtx        gen_rs6000_mtfsf_hi                   (rtx, rtx);
extern rtx        gen_addg6s                            (rtx, rtx, rtx);
extern rtx        gen_cdtbcd                            (rtx, rtx);
extern rtx        gen_cbcdtd                            (rtx, rtx);
extern rtx        gen_dive_si                           (rtx, rtx, rtx);
extern rtx        gen_diveu_si                          (rtx, rtx, rtx);
extern rtx        gen_dive_di                           (rtx, rtx, rtx);
extern rtx        gen_diveu_di                          (rtx, rtx, rtx);
extern rtx        gen_unpacktf_dm                       (rtx, rtx, rtx);
extern rtx        gen_unpackif_dm                       (rtx, rtx, rtx);
extern rtx        gen_unpacktd_dm                       (rtx, rtx, rtx);
extern rtx        gen_unpacktf_nodm                     (rtx, rtx, rtx);
extern rtx        gen_unpackif_nodm                     (rtx, rtx, rtx);
extern rtx        gen_unpacktd_nodm                     (rtx, rtx, rtx);
extern rtx        gen_packtf                            (rtx, rtx, rtx);
extern rtx        gen_packif                            (rtx, rtx, rtx);
extern rtx        gen_packtd                            (rtx, rtx, rtx);
extern rtx        gen_unpackv1ti                        (rtx, rtx, rtx);
extern rtx        gen_unpackkf                          (rtx, rtx, rtx);
extern rtx        gen_packv1ti                          (rtx, rtx, rtx);
extern rtx        gen_packkf                            (rtx, rtx, rtx);
extern rtx        gen_addkf3                            (rtx, rtx, rtx);
extern rtx        gen_addtf3                            (rtx, rtx, rtx);
extern rtx        gen_subkf3                            (rtx, rtx, rtx);
extern rtx        gen_subtf3                            (rtx, rtx, rtx);
extern rtx        gen_mulkf3                            (rtx, rtx, rtx);
extern rtx        gen_multf3                            (rtx, rtx, rtx);
extern rtx        gen_divkf3                            (rtx, rtx, rtx);
extern rtx        gen_divtf3                            (rtx, rtx, rtx);
extern rtx        gen_sqrtkf2                           (rtx, rtx);
extern rtx        gen_sqrttf2                           (rtx, rtx);
extern rtx        gen_copysignkf3_hard                  (rtx, rtx, rtx);
extern rtx        gen_copysigntf3_hard                  (rtx, rtx, rtx);
extern rtx        gen_copysignkf3_soft                  (rtx, rtx, rtx);
extern rtx        gen_copysigntf3_soft                  (rtx, rtx, rtx);
extern rtx        gen_negkf2_hw                         (rtx, rtx);
extern rtx        gen_negtf2_hw                         (rtx, rtx);
extern rtx        gen_abskf2_hw                         (rtx, rtx);
extern rtx        gen_abstf2_hw                         (rtx, rtx);
extern rtx        gen_fmakf4_hw                         (rtx, rtx, rtx, rtx);
extern rtx        gen_fmatf4_hw                         (rtx, rtx, rtx, rtx);
extern rtx        gen_extendsfkf2_hw                    (rtx, rtx);
extern rtx        gen_extendsftf2_hw                    (rtx, rtx);
extern rtx        gen_extenddfkf2_hw                    (rtx, rtx);
extern rtx        gen_extenddftf2_hw                    (rtx, rtx);
extern rtx        gen_extendkftf2                       (rtx, rtx);
extern rtx        gen_trunctfkf2                        (rtx, rtx);
extern rtx        gen_trunckfdf2_hw                     (rtx, rtx);
extern rtx        gen_trunctfdf2_hw                     (rtx, rtx);
extern rtx        gen_trunckfsf2_hw                     (rtx, rtx);
extern rtx        gen_trunctfsf2_hw                     (rtx, rtx);
extern rtx        gen_fix_kfsi2_hw                      (rtx, rtx);
extern rtx        gen_fixuns_kfsi2_hw                   (rtx, rtx);
extern rtx        gen_fix_tfsi2_hw                      (rtx, rtx);
extern rtx        gen_fixuns_tfsi2_hw                   (rtx, rtx);
extern rtx        gen_fix_kfdi2_hw                      (rtx, rtx);
extern rtx        gen_fixuns_kfdi2_hw                   (rtx, rtx);
extern rtx        gen_fix_tfdi2_hw                      (rtx, rtx);
extern rtx        gen_fixuns_tfdi2_hw                   (rtx, rtx);
extern rtx        gen_fix_trunckfqi2                    (rtx, rtx);
extern rtx        gen_fixuns_trunckfqi2                 (rtx, rtx);
extern rtx        gen_fix_trunckfhi2                    (rtx, rtx);
extern rtx        gen_fixuns_trunckfhi2                 (rtx, rtx);
extern rtx        gen_fix_trunctfqi2                    (rtx, rtx);
extern rtx        gen_fixuns_trunctfqi2                 (rtx, rtx);
extern rtx        gen_fix_trunctfhi2                    (rtx, rtx);
extern rtx        gen_fixuns_trunctfhi2                 (rtx, rtx);
extern rtx        gen_float_kfdi2_hw                    (rtx, rtx);
extern rtx        gen_float_tfdi2_hw                    (rtx, rtx);
extern rtx        gen_float_kfsi2_hw                    (rtx, rtx);
extern rtx        gen_float_tfsi2_hw                    (rtx, rtx);
extern rtx        gen_floatqikf2                        (rtx, rtx);
extern rtx        gen_floathikf2                        (rtx, rtx);
extern rtx        gen_floatqitf2                        (rtx, rtx);
extern rtx        gen_floathitf2                        (rtx, rtx);
extern rtx        gen_floatuns_kfdi2_hw                 (rtx, rtx);
extern rtx        gen_floatuns_tfdi2_hw                 (rtx, rtx);
extern rtx        gen_floatuns_kfsi2_hw                 (rtx, rtx);
extern rtx        gen_floatuns_tfsi2_hw                 (rtx, rtx);
extern rtx        gen_floatunsqikf2                     (rtx, rtx);
extern rtx        gen_floatunshikf2                     (rtx, rtx);
extern rtx        gen_floatunsqitf2                     (rtx, rtx);
extern rtx        gen_floatunshitf2                     (rtx, rtx);
extern rtx        gen_floorkf2                          (rtx, rtx);
extern rtx        gen_floortf2                          (rtx, rtx);
extern rtx        gen_ceilkf2                           (rtx, rtx);
extern rtx        gen_ceiltf2                           (rtx, rtx);
extern rtx        gen_btrunckf2                         (rtx, rtx);
extern rtx        gen_btrunctf2                         (rtx, rtx);
extern rtx        gen_roundkf2                          (rtx, rtx);
extern rtx        gen_roundtf2                          (rtx, rtx);
extern rtx        gen_addkf3_odd                        (rtx, rtx, rtx);
extern rtx        gen_addtf3_odd                        (rtx, rtx, rtx);
extern rtx        gen_subkf3_odd                        (rtx, rtx, rtx);
extern rtx        gen_subtf3_odd                        (rtx, rtx, rtx);
extern rtx        gen_mulkf3_odd                        (rtx, rtx, rtx);
extern rtx        gen_multf3_odd                        (rtx, rtx, rtx);
extern rtx        gen_divkf3_odd                        (rtx, rtx, rtx);
extern rtx        gen_divtf3_odd                        (rtx, rtx, rtx);
extern rtx        gen_sqrtkf2_odd                       (rtx, rtx);
extern rtx        gen_sqrttf2_odd                       (rtx, rtx);
extern rtx        gen_fmakf4_odd                        (rtx, rtx, rtx, rtx);
extern rtx        gen_fmatf4_odd                        (rtx, rtx, rtx, rtx);
extern rtx        gen_trunckfdf2_odd                    (rtx, rtx);
extern rtx        gen_trunctfdf2_odd                    (rtx, rtx);
extern rtx        gen_darn_32                           (rtx);
extern rtx        gen_darn_raw                          (rtx);
extern rtx        gen_darn                              (rtx);
extern rtx        gen_setb_signed                       (rtx, rtx);
extern rtx        gen_setb_unsigned                     (rtx, rtx);
extern rtx        gen_hashst                            (rtx, rtx);
extern rtx        gen_hashchk                           (rtx, rtx);
extern rtx        gen_isync                             (void);
extern rtx        gen_loadsync_qi                       (rtx);
extern rtx        gen_loadsync_hi                       (rtx);
extern rtx        gen_loadsync_si                       (rtx);
extern rtx        gen_loadsync_di                       (rtx);
extern rtx        gen_loadsync_ti                       (rtx);
extern rtx        gen_load_quadpti                      (rtx, rtx);
extern rtx        gen_store_quadpti                     (rtx, rtx);
extern rtx        gen_load_lockedqi                     (rtx, rtx);
extern rtx        gen_load_lockedhi                     (rtx, rtx);
extern rtx        gen_load_lockedsi                     (rtx, rtx);
extern rtx        gen_load_lockeddi                     (rtx, rtx);
extern rtx        gen_load_lockedqi_si                  (rtx, rtx);
extern rtx        gen_load_lockedhi_si                  (rtx, rtx);
extern rtx        gen_load_lockedpti                    (rtx, rtx);
extern rtx        gen_store_conditionalqi               (rtx, rtx, rtx);
extern rtx        gen_store_conditionalhi               (rtx, rtx, rtx);
extern rtx        gen_store_conditionalsi               (rtx, rtx, rtx);
extern rtx        gen_store_conditionaldi               (rtx, rtx, rtx);
extern rtx        gen_store_conditionalpti              (rtx, rtx, rtx);
extern rtx        gen_vector_ltv4sf                     (rtx, rtx, rtx);
extern rtx        gen_vector_lev4sf                     (rtx, rtx, rtx);
extern rtx        gen_vector_nev4sf                     (rtx, rtx, rtx);
extern rtx        gen_vector_ungtv4sf                   (rtx, rtx, rtx);
extern rtx        gen_vector_ungev4sf                   (rtx, rtx, rtx);
extern rtx        gen_vector_unltv4sf                   (rtx, rtx, rtx);
extern rtx        gen_vector_unlev4sf                   (rtx, rtx, rtx);
extern rtx        gen_vector_ltv2df                     (rtx, rtx, rtx);
extern rtx        gen_vector_lev2df                     (rtx, rtx, rtx);
extern rtx        gen_vector_nev2df                     (rtx, rtx, rtx);
extern rtx        gen_vector_ungtv2df                   (rtx, rtx, rtx);
extern rtx        gen_vector_ungev2df                   (rtx, rtx, rtx);
extern rtx        gen_vector_unltv2df                   (rtx, rtx, rtx);
extern rtx        gen_vector_unlev2df                   (rtx, rtx, rtx);
extern rtx        gen_vector_ltgtv4sf                   (rtx, rtx, rtx);
extern rtx        gen_vector_uneqv4sf                   (rtx, rtx, rtx);
extern rtx        gen_vector_unorderedv4sf              (rtx, rtx, rtx);
extern rtx        gen_vector_orderedv4sf                (rtx, rtx, rtx);
extern rtx        gen_vector_ltgtv2df                   (rtx, rtx, rtx);
extern rtx        gen_vector_uneqv2df                   (rtx, rtx, rtx);
extern rtx        gen_vector_unorderedv2df              (rtx, rtx, rtx);
extern rtx        gen_vector_orderedv2df                (rtx, rtx, rtx);
extern rtx        gen_xxspltib_v16qi                    (rtx, rtx);
extern rtx        gen_xxspltib_v8hi_nosplit             (rtx, rtx);
extern rtx        gen_xxspltib_v4si_nosplit             (rtx, rtx);
extern rtx        gen_xxspltib_v2di_nosplit             (rtx, rtx);
extern rtx        gen_vsx_movv16qi_64bit                (rtx, rtx);
extern rtx        gen_vsx_movv8hi_64bit                 (rtx, rtx);
extern rtx        gen_vsx_movv4si_64bit                 (rtx, rtx);
extern rtx        gen_vsx_movv2di_64bit                 (rtx, rtx);
extern rtx        gen_vsx_movv4sf_64bit                 (rtx, rtx);
extern rtx        gen_vsx_movv2df_64bit                 (rtx, rtx);
extern rtx        gen_vsx_movv1ti_64bit                 (rtx, rtx);
extern rtx        gen_vsx_movkf_64bit                   (rtx, rtx);
extern rtx        gen_vsx_movtf_64bit                   (rtx, rtx);
extern rtx        gen_vsx_movti_64bit                   (rtx, rtx);
extern rtx        gen_vsx_lxvrbx                        (rtx, rtx);
extern rtx        gen_vsx_lxvrhx                        (rtx, rtx);
extern rtx        gen_vsx_lxvrwx                        (rtx, rtx);
extern rtx        gen_vsx_lxvrdx                        (rtx, rtx);
extern rtx        gen_vsx_stxvrbx                       (rtx, rtx);
extern rtx        gen_vsx_stxvrhx                       (rtx, rtx);
extern rtx        gen_vsx_stxvrwx                       (rtx, rtx);
extern rtx        gen_vsx_stxvrdx                       (rtx, rtx);
extern rtx        gen_vsx_ld_elemrev_v2di               (rtx, rtx);
extern rtx        gen_vsx_ld_elemrev_v1ti               (rtx, rtx);
extern rtx        gen_vsx_ld_elemrev_v2df               (rtx, rtx);
extern rtx        gen_vsx_ld_elemrev_v4si               (rtx, rtx);
extern rtx        gen_vsx_ld_elemrev_v4sf               (rtx, rtx);
extern rtx        gen_vsx_ld_elemrev_v16qi_internal     (rtx, rtx);
extern rtx        gen_vsx_st_elemrev_v1ti               (rtx, rtx);
extern rtx        gen_vsx_st_elemrev_v2df               (rtx, rtx);
extern rtx        gen_vsx_st_elemrev_v2di               (rtx, rtx);
extern rtx        gen_vsx_st_elemrev_v4sf               (rtx, rtx);
extern rtx        gen_vsx_st_elemrev_v4si               (rtx, rtx);
extern rtx        gen_vsx_mul_v2di                      (rtx, rtx, rtx);
extern rtx        gen_vsx_div_v2di                      (rtx, rtx, rtx);
extern rtx        gen_vsx_udiv_v2di                     (rtx, rtx, rtx);
extern rtx        gen_vsx_div_v1ti                      (rtx, rtx, rtx);
extern rtx        gen_vsx_udiv_v1ti                     (rtx, rtx, rtx);
extern rtx        gen_vsx_dives_v1ti                    (rtx, rtx, rtx);
extern rtx        gen_vsx_diveu_v1ti                    (rtx, rtx, rtx);
extern rtx        gen_vsx_mods_v1ti                     (rtx, rtx, rtx);
extern rtx        gen_vsx_modu_v1ti                     (rtx, rtx, rtx);
extern rtx        gen_vsx_frev4sf2                      (rtx, rtx);
extern rtx        gen_vsx_frev2df2                      (rtx, rtx);
extern rtx        gen_vsx_nabsv4sf2                     (rtx, rtx);
extern rtx        gen_vsx_nabsv2df2                     (rtx, rtx);
extern rtx        gen_vsx_smaxv4sf3                     (rtx, rtx, rtx);
extern rtx        gen_vsx_smaxv2df3                     (rtx, rtx, rtx);
extern rtx        gen_vsx_eqv4sf                        (rtx, rtx, rtx);
extern rtx        gen_vsx_eqv2df                        (rtx, rtx, rtx);
extern rtx        gen_vsx_gtv4sf                        (rtx, rtx, rtx);
extern rtx        gen_vsx_gtv2df                        (rtx, rtx, rtx);
extern rtx        gen_vsx_copysignv4sf3                 (rtx, rtx, rtx);
extern rtx        gen_vsx_copysignv2df3                 (rtx, rtx, rtx);
extern rtx        gen_vsx_floatv4siv4sf2                (rtx, rtx);
extern rtx        gen_vsx_floatv2div2df2                (rtx, rtx);
extern rtx        gen_vsx_floatunsv4siv4sf2             (rtx, rtx);
extern rtx        gen_vsx_floatunsv2div2df2             (rtx, rtx);
extern rtx        gen_vsx_fix_truncv4sfv4si2            (rtx, rtx);
extern rtx        gen_vsx_fix_truncv2dfv2di2            (rtx, rtx);
extern rtx        gen_vsx_fixuns_truncv4sfv4si2         (rtx, rtx);
extern rtx        gen_vsx_fixuns_truncv2dfv2di2         (rtx, rtx);
extern rtx        gen_vsx_xsrdpi                        (rtx, rtx);
extern rtx        gen_vsx_xvrspi                        (rtx, rtx);
extern rtx        gen_vsx_xvrdpi                        (rtx, rtx);
extern rtx        gen_vsx_xsrdpic                       (rtx, rtx);
extern rtx        gen_vsx_xvrspic                       (rtx, rtx);
extern rtx        gen_vsx_xvrdpic                       (rtx, rtx);
extern rtx        gen_vsx_btruncv4sf2                   (rtx, rtx);
extern rtx        gen_vsx_btruncv2df2                   (rtx, rtx);
extern rtx        gen_vsx_floorv4sf2                    (rtx, rtx);
extern rtx        gen_vsx_floorv2df2                    (rtx, rtx);
extern rtx        gen_vsx_ceilv4sf2                     (rtx, rtx);
extern rtx        gen_vsx_ceilv2df2                     (rtx, rtx);
extern rtx        gen_vsx_xscvdpsp                      (rtx, rtx);
extern rtx        gen_vsx_xvcvspdp_be                   (rtx, rtx);
extern rtx        gen_vsx_xvcvspdp_le                   (rtx, rtx);
extern rtx        gen_vsx_xvcvdpsp                      (rtx, rtx);
extern rtx        gen_vsx_xscvspdp                      (rtx, rtx);
extern rtx        gen_vsx_xscvspdp_scalar2              (rtx, rtx);
extern rtx        gen_vsx_xvcvhpsp                      (rtx, rtx);
extern rtx        gen_vsx_xvcvsphp                      (rtx, rtx);
extern rtx        gen_vsx_xscvdpsp_scalar               (rtx, rtx);
extern rtx        gen_vsx_xscvdpspn                     (rtx, rtx);
extern rtx        gen_vsx_xscvspdpn                     (rtx, rtx);
extern rtx        gen_vsx_xscvdpspn_scalar              (rtx, rtx);
extern rtx        gen_vsx_xscvspdpn_directmove          (rtx, rtx);
extern rtx        gen_vsx_xvcvsxwsp                     (rtx, rtx);
extern rtx        gen_vsx_xvcvuxwsp                     (rtx, rtx);
extern rtx        gen_vsx_xvcvsxddp                     (rtx, rtx);
extern rtx        gen_vsx_xvcvuxddp                     (rtx, rtx);
extern rtx        gen_vsx_xvcvspsxws                    (rtx, rtx);
extern rtx        gen_vsx_xvcvspuxws                    (rtx, rtx);
extern rtx        gen_vsx_xvcvdpsxds                    (rtx, rtx);
extern rtx        gen_vsx_xvcvdpuxds                    (rtx, rtx);
extern rtx        gen_vsx_xvcvdpsxws                    (rtx, rtx);
extern rtx        gen_vsx_xvcvdpuxws                    (rtx, rtx);
extern rtx        gen_vsx_xvcvsxdsp                     (rtx, rtx);
extern rtx        gen_vsx_xvcvuxdsp                     (rtx, rtx);
extern rtx        gen_vsx_xvcvsxwdp_be                  (rtx, rtx);
extern rtx        gen_vsx_xvcvuxwdp_be                  (rtx, rtx);
extern rtx        gen_vsx_xvcvsxwdp_le                  (rtx, rtx);
extern rtx        gen_vsx_xvcvuxwdp_le                  (rtx, rtx);
extern rtx        gen_vsx_xvcvsxwdp_df                  (rtx, rtx);
extern rtx        gen_vsx_xvcvuxwdp_df                  (rtx, rtx);
extern rtx        gen_vsx_xvcvspsxds_be                 (rtx, rtx);
extern rtx        gen_vsx_xvcvspuxds_be                 (rtx, rtx);
extern rtx        gen_vsx_xvcvspsxds_le                 (rtx, rtx);
extern rtx        gen_vsx_xvcvspuxds_le                 (rtx, rtx);
extern rtx        gen_vsx_concat_v2df                   (rtx, rtx, rtx);
extern rtx        gen_vsx_concat_v2di                   (rtx, rtx, rtx);
extern rtx        gen_vsx_concat_v2sf                   (rtx, rtx, rtx);
extern rtx        gen_xxswapd_v16qi                     (rtx, rtx);
extern rtx        gen_xxswapd_v8hi                      (rtx, rtx);
extern rtx        gen_xxswapd_v4sf                      (rtx, rtx);
extern rtx        gen_xxswapd_v4si                      (rtx, rtx);
extern rtx        gen_xxswapd_v2df                      (rtx, rtx);
extern rtx        gen_xxswapd_v2di                      (rtx, rtx);
extern rtx        gen_xxswapd_v1ti                      (rtx, rtx);
extern rtx        gen_xxgenpcvm_v16qi_internal          (rtx, rtx, rtx);
extern rtx        gen_xxgenpcvm_v8hi_internal           (rtx, rtx, rtx);
extern rtx        gen_xxgenpcvm_v4si_internal           (rtx, rtx, rtx);
extern rtx        gen_xxgenpcvm_v2di_internal           (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v2df                  (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v2di                  (rtx, rtx, rtx);
extern rtx        gen_vsx_vslo_v2df                     (rtx, rtx, rtx);
extern rtx        gen_vsx_vslo_v2di                     (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v2df_var              (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v2di_var              (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v4sf                  (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v4sf_var              (rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi2_v2df_1              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi2_v2di_1              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v16qi_p9              (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v8hi_p9               (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v4si_p9               (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v16qi_var             (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v8hi_var              (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v4si_var              (rtx, rtx, rtx);
extern rtx        gen_vextractlv16qi_internal           (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractlv8hi_internal            (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractlv4si_internal            (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractlv2di_internal            (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractrv16qi_internal           (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractrv8hi_internal            (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractrv4si_internal            (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractrv2di_internal            (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvl_internal_v16qi          (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvl_internal_v8hi           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvl_internal_v4si           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvl_internal_v2di           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvr_internal_v16qi          (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvr_internal_v8hi           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvr_internal_v4si           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvr_internal_v2di           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgl_internal_v16qi          (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgl_internal_v8hi           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgl_internal_v4si           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgl_internal_v2di           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgr_internal_v16qi          (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgr_internal_v8hi           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgr_internal_v4si           (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgr_internal_v2di           (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_elt_v4si_inst            (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_elt_v4sf_inst            (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_elt_v2di_inst            (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_elt_v2df_inst            (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_set_v16qi_p9                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_set_v8hi_p9                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_set_v4si_p9                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_set_v4sf_p9                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_splat_v2df_reg                (rtx, rtx);
extern rtx        gen_vsx_splat_v2di_reg                (rtx, rtx);
extern rtx        gen_vsx_splat_v2df_mem                (rtx, rtx);
extern rtx        gen_vsx_splat_v2di_mem                (rtx, rtx);
extern rtx        gen_vsx_splat_v4si                    (rtx, rtx);
extern rtx        gen_vsx_splat_v4si_di                 (rtx, rtx);
extern rtx        gen_vsx_splat_v4sf                    (rtx, rtx);
extern rtx        gen_vsx_xxspltw_v4sf                  (rtx, rtx, rtx);
extern rtx        gen_vsx_xxspltw_v4si                  (rtx, rtx, rtx);
extern rtx        gen_vsx_xxspltw_v4sf_direct           (rtx, rtx, rtx);
extern rtx        gen_vsx_xxspltw_v4si_direct           (rtx, rtx, rtx);
extern rtx        gen_vsx_vspltb_di                     (rtx, rtx);
extern rtx        gen_vsx_vsplth_di                     (rtx, rtx);
extern rtx        gen_vsx_xxspltd_v2df                  (rtx, rtx, rtx);
extern rtx        gen_vsx_xxspltd_v2di                  (rtx, rtx, rtx);
extern rtx        gen_vsx_xxmrghw_v4sf                  (rtx, rtx, rtx);
extern rtx        gen_vsx_xxmrghw_v4si                  (rtx, rtx, rtx);
extern rtx        gen_vsx_xxmrglw_v4sf                  (rtx, rtx, rtx);
extern rtx        gen_vsx_xxmrglw_v4si                  (rtx, rtx, rtx);
extern rtx        gen_vsx_xxsldwi_v16qi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxsldwi_v8hi                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxsldwi_v4si                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxsldwi_v2di                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxsldwi_v4sf                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxsldwi_v2df                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxsldwi_v1ti                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxsldwi_ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxsldwi_kf                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxsldwi_tf                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_reduc_plus_v2df               (rtx, rtx);
extern rtx        gen_vsx_reduc_smin_v2df               (rtx, rtx);
extern rtx        gen_vsx_reduc_smax_v2df               (rtx, rtx);
extern rtx        gen_vsx_reduc_plus_v4sf               (rtx, rtx);
extern rtx        gen_vsx_reduc_smin_v4sf               (rtx, rtx);
extern rtx        gen_vsx_reduc_smax_v4sf               (rtx, rtx);
extern rtx        gen_vsx_sign_extend_v2di_v1ti         (rtx, rtx);
extern rtx        gen_vsx_sign_extend_qi_v4si           (rtx, rtx);
extern rtx        gen_vsx_sign_extend_qi_v2di           (rtx, rtx);
extern rtx        gen_vsx_sign_extend_qi_di             (rtx, rtx);
extern rtx        gen_vsx_sign_extend_qi_si             (rtx, rtx);
extern rtx        gen_vsx_sign_extend_hi_v4si           (rtx, rtx);
extern rtx        gen_vsx_sign_extend_hi_v2di           (rtx, rtx);
extern rtx        gen_vsx_sign_extend_hi_di             (rtx, rtx);
extern rtx        gen_vsx_sign_extend_hi_si             (rtx, rtx);
extern rtx        gen_vsx_sign_extend_si_v2di           (rtx, rtx);
extern rtx        gen_mtvsrdd_diti_w1                   (rtx, rtx);
extern rtx        gen_extendditi2_vector                (rtx, rtx);
extern rtx        gen_xsxexpqp_kf                       (rtx, rtx);
extern rtx        gen_xsxexpqp_tf                       (rtx, rtx);
extern rtx        gen_xsxexpdp                          (rtx, rtx);
extern rtx        gen_xsxsigqp_kf                       (rtx, rtx);
extern rtx        gen_xsxsigqp_tf                       (rtx, rtx);
extern rtx        gen_xsxsigdp                          (rtx, rtx);
extern rtx        gen_xsiexpqpf_kf                      (rtx, rtx, rtx);
extern rtx        gen_xsiexpqpf_tf                      (rtx, rtx, rtx);
extern rtx        gen_xsiexpqp_kf                       (rtx, rtx, rtx);
extern rtx        gen_xsiexpqp_tf                       (rtx, rtx, rtx);
extern rtx        gen_xsiexpdp                          (rtx, rtx, rtx);
extern rtx        gen_xsiexpdpf                         (rtx, rtx, rtx);
extern rtx        gen_xvxexpsp                          (rtx, rtx);
extern rtx        gen_xvxexpdp                          (rtx, rtx);
extern rtx        gen_xvxsigsp                          (rtx, rtx);
extern rtx        gen_xvxsigdp                          (rtx, rtx);
extern rtx        gen_xviexpsp                          (rtx, rtx, rtx);
extern rtx        gen_xviexpdp                          (rtx, rtx, rtx);
extern rtx        gen_xvtstdcsp                         (rtx, rtx, rtx);
extern rtx        gen_xvtstdcdp                         (rtx, rtx, rtx);
extern rtx        gen_lxvll                             (rtx, rtx, rtx);
extern rtx        gen_stxvll                            (rtx, rtx, rtx);
extern rtx        gen_vcmpneb                           (rtx, rtx, rtx);
extern rtx        gen_vcmpnezb                          (rtx, rtx, rtx);
extern rtx        gen_vcmpnezb_p                        (rtx, rtx, rtx);
extern rtx        gen_vcmpneh                           (rtx, rtx, rtx);
extern rtx        gen_vcmpnezh                          (rtx, rtx, rtx);
extern rtx        gen_vcmpnew                           (rtx, rtx, rtx);
extern rtx        gen_vcmpnezw                          (rtx, rtx, rtx);
extern rtx        gen_vclzlsbb_v16qi                    (rtx, rtx);
extern rtx        gen_vclzlsbb_v8hi                     (rtx, rtx);
extern rtx        gen_vclzlsbb_v4si                     (rtx, rtx);
extern rtx        gen_vctzlsbb_v16qi                    (rtx, rtx);
extern rtx        gen_vctzlsbb_v8hi                     (rtx, rtx);
extern rtx        gen_vctzlsbb_v4si                     (rtx, rtx);
extern rtx        gen_vextublx                          (rtx, rtx, rtx);
extern rtx        gen_vextubrx                          (rtx, rtx, rtx);
extern rtx        gen_vextuhlx                          (rtx, rtx, rtx);
extern rtx        gen_vextuhrx                          (rtx, rtx, rtx);
extern rtx        gen_vextuwlx                          (rtx, rtx, rtx);
extern rtx        gen_vextuwrx                          (rtx, rtx, rtx);
extern rtx        gen_extract4b                         (rtx, rtx, rtx);
extern rtx        gen_p9_xxbrq_v1ti                     (rtx, rtx);
extern rtx        gen_p9_xxbrd_v2di                     (rtx, rtx);
extern rtx        gen_p9_xxbrw_v4si                     (rtx, rtx);
extern rtx        gen_p9_xxbrh_v8hi                     (rtx, rtx);
extern rtx        gen_vsx_xvcvspbf16                    (rtx, rtx);
extern rtx        gen_vsx_xvcvbf16spn                   (rtx, rtx);
extern rtx        gen_vec_mtvsrbmi                      (rtx, rtx);
extern rtx        gen_vec_mtvsr_v16qi                   (rtx, rtx);
extern rtx        gen_vec_mtvsr_v8hi                    (rtx, rtx);
extern rtx        gen_vec_mtvsr_v4si                    (rtx, rtx);
extern rtx        gen_vec_mtvsr_v2di                    (rtx, rtx);
extern rtx        gen_vec_mtvsr_v1ti                    (rtx, rtx);
extern rtx        gen_vec_cntmb_v16qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_cntmb_v8hi                    (rtx, rtx, rtx);
extern rtx        gen_vec_cntmb_v4si                    (rtx, rtx, rtx);
extern rtx        gen_vec_cntmb_v2di                    (rtx, rtx, rtx);
extern rtx        gen_vec_extract_v16qi                 (rtx, rtx);
extern rtx        gen_vec_extract_v8hi                  (rtx, rtx);
extern rtx        gen_vec_extract_v4si                  (rtx, rtx);
extern rtx        gen_vec_extract_v2di                  (rtx, rtx);
extern rtx        gen_vec_extract_v1ti                  (rtx, rtx);
extern rtx        gen_vec_expand_v16qi                  (rtx, rtx);
extern rtx        gen_vec_expand_v8hi                   (rtx, rtx);
extern rtx        gen_vec_expand_v4si                   (rtx, rtx);
extern rtx        gen_vec_expand_v2di                   (rtx, rtx);
extern rtx        gen_vec_expand_v1ti                   (rtx, rtx);
extern rtx        gen_dives_v2di                        (rtx, rtx, rtx);
extern rtx        gen_dives_v4si                        (rtx, rtx, rtx);
extern rtx        gen_diveu_v2di                        (rtx, rtx, rtx);
extern rtx        gen_diveu_v4si                        (rtx, rtx, rtx);
extern rtx        gen_divv2di3                          (rtx, rtx, rtx);
extern rtx        gen_divv4si3                          (rtx, rtx, rtx);
extern rtx        gen_udivv2di3                         (rtx, rtx, rtx);
extern rtx        gen_udivv4si3                         (rtx, rtx, rtx);
extern rtx        gen_mods_v2di                         (rtx, rtx, rtx);
extern rtx        gen_mods_v4si                         (rtx, rtx, rtx);
extern rtx        gen_modu_v2di                         (rtx, rtx, rtx);
extern rtx        gen_modu_v4si                         (rtx, rtx, rtx);
extern rtx        gen_mulhs_v2di                        (rtx, rtx, rtx);
extern rtx        gen_mulhs_v4si                        (rtx, rtx, rtx);
extern rtx        gen_mulhu_v2di                        (rtx, rtx, rtx);
extern rtx        gen_mulhu_v4si                        (rtx, rtx, rtx);
extern rtx        gen_mulv2di3                          (rtx, rtx, rtx);
extern rtx        gen_get_vrsave_internal               (rtx);
extern rtx        gen_addv4si3                          (rtx, rtx, rtx);
extern rtx        gen_addv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_addv16qi3                         (rtx, rtx, rtx);
extern rtx        gen_addv2di3                          (rtx, rtx, rtx);
extern rtx        gen_altivec_vaddcuw                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vadduws                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vadduhs                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vaddubs                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vaddsws                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vaddshs                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vaddsbs                   (rtx, rtx, rtx);
extern rtx        gen_subv4si3                          (rtx, rtx, rtx);
extern rtx        gen_subv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_subv16qi3                         (rtx, rtx, rtx);
extern rtx        gen_subv2di3                          (rtx, rtx, rtx);
extern rtx        gen_altivec_vsubcuw                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vsubuws                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vsubuhs                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vsububs                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vsubsws                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vsubshs                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vsubsbs                   (rtx, rtx, rtx);
extern rtx        gen_uavgv4si3_ceil                    (rtx, rtx, rtx);
extern rtx        gen_uavgv8hi3_ceil                    (rtx, rtx, rtx);
extern rtx        gen_uavgv16qi3_ceil                   (rtx, rtx, rtx);
extern rtx        gen_avgv4si3_ceil                     (rtx, rtx, rtx);
extern rtx        gen_avgv8hi3_ceil                     (rtx, rtx, rtx);
extern rtx        gen_avgv16qi3_ceil                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vcmpbfp                   (rtx, rtx, rtx);
extern rtx        gen_altivec_eqv1ti                    (rtx, rtx, rtx);
extern rtx        gen_altivec_eqv4si                    (rtx, rtx, rtx);
extern rtx        gen_altivec_eqv8hi                    (rtx, rtx, rtx);
extern rtx        gen_altivec_eqv16qi                   (rtx, rtx, rtx);
extern rtx        gen_altivec_eqv2di                    (rtx, rtx, rtx);
extern rtx        gen_mulv4si3_p8                       (rtx, rtx, rtx);
extern rtx        gen_vsldb_v4si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vsrdb_v4si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vsldb_v8hi                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vsrdb_v8hi                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vsldb_v16qi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_vsrdb_v16qi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_vsldb_v2di                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vsrdb_v2di                        (rtx, rtx, rtx, rtx);
extern rtx        gen_xxspltiw_v4si                     (rtx, rtx);
extern rtx        gen_xxspltiw_v4sf_inst                (rtx, rtx);
extern rtx        gen_xxspltidp_v2df_inst               (rtx, rtx);
extern rtx        gen_xxsplti32dx_v4si_inst             (rtx, rtx, rtx, rtx);
extern rtx        gen_xxsplti32dx_v4sf_inst             (rtx, rtx, rtx, rtx);
extern rtx        gen_xxblend_v4si                      (rtx, rtx, rtx, rtx);
extern rtx        gen_xxblend_v8hi                      (rtx, rtx, rtx, rtx);
extern rtx        gen_xxblend_v16qi                     (rtx, rtx, rtx, rtx);
extern rtx        gen_xxblend_v4sf                      (rtx, rtx, rtx, rtx);
extern rtx        gen_xxblend_v2df                      (rtx, rtx, rtx, rtx);
extern rtx        gen_xxblend_v2di                      (rtx, rtx, rtx, rtx);
extern rtx        gen_xxpermx_inst                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vstrir_code_v8hi                  (rtx, rtx);
extern rtx        gen_vstrir_code_v16qi                 (rtx, rtx);
extern rtx        gen_vstrir_p_code_v8hi                (rtx, rtx);
extern rtx        gen_vstrir_p_code_v16qi               (rtx, rtx);
extern rtx        gen_vstril_code_v8hi                  (rtx, rtx);
extern rtx        gen_vstril_code_v16qi                 (rtx, rtx);
extern rtx        gen_vstril_p_code_v8hi                (rtx, rtx);
extern rtx        gen_vstril_p_code_v16qi               (rtx, rtx);
extern rtx        gen_altivec_vmsumuhm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vmsumubm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vmsumudm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vmsummhm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vmsummbm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vmsumshm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vmsumuhs                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vmsumshs                  (rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv4si3                         (rtx, rtx, rtx);
extern rtx        gen_umaxv8hi3                         (rtx, rtx, rtx);
extern rtx        gen_umaxv16qi3                        (rtx, rtx, rtx);
extern rtx        gen_umaxv2di3                         (rtx, rtx, rtx);
extern rtx        gen_smaxv4si3                         (rtx, rtx, rtx);
extern rtx        gen_smaxv8hi3                         (rtx, rtx, rtx);
extern rtx        gen_smaxv16qi3                        (rtx, rtx, rtx);
extern rtx        gen_smaxv2di3                         (rtx, rtx, rtx);
extern rtx        gen_uminv4si3                         (rtx, rtx, rtx);
extern rtx        gen_uminv8hi3                         (rtx, rtx, rtx);
extern rtx        gen_uminv16qi3                        (rtx, rtx, rtx);
extern rtx        gen_uminv2di3                         (rtx, rtx, rtx);
extern rtx        gen_sminv4si3                         (rtx, rtx, rtx);
extern rtx        gen_sminv8hi3                         (rtx, rtx, rtx);
extern rtx        gen_sminv16qi3                        (rtx, rtx, rtx);
extern rtx        gen_sminv2di3                         (rtx, rtx, rtx);
extern rtx        gen_altivec_vmhaddshs                 (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vmhraddshs                (rtx, rtx, rtx, rtx);
extern rtx        gen_fmav8hi4                          (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vmrghb_direct             (rtx, rtx, rtx);
extern rtx        gen_altivec_vmrghh_direct             (rtx, rtx, rtx);
extern rtx        gen_altivec_vmrghw_direct             (rtx, rtx, rtx);
extern rtx        gen_altivec_vmrglb_direct             (rtx, rtx, rtx);
extern rtx        gen_altivec_vmrglh_direct             (rtx, rtx, rtx);
extern rtx        gen_altivec_vmrglw_direct             (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgew_v4sf                    (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgew_v4si                    (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgow_v4sf                    (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgow_v4si                    (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgew_v4sf_direct             (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgew_v4si_direct             (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgow_v4sf_direct             (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgow_v4si_direct             (rtx, rtx, rtx);
extern rtx        gen_altivec_vmuleub                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmuloub                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmulesb                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmulosb                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmuleuh                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmulouh                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmulesh                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmulosh                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmuleuw                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmuleud                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmulouw                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmuloud                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmulesw                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmulesd                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmulosw                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vmulosd                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkpx                     (rtx, rtx, rtx);
extern rtx        gen_altivec_vpksdss                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkswss                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkshss                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpksdus                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkswus                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkshus                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkudus                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkuwus                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkuhus                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkudum                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkuwum                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkuhum                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkudum_direct            (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkuwum_direct            (rtx, rtx, rtx);
extern rtx        gen_altivec_vpkuhum_direct            (rtx, rtx, rtx);
extern rtx        gen_altivec_vrlq                      (rtx, rtx, rtx);
extern rtx        gen_altivec_vrldmi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vrlwmi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vrlqmi_inst               (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vrldnm                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vrlwnm                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vrlqnm_inst               (rtx, rtx, rtx);
extern rtx        gen_altivec_vsl                       (rtx, rtx, rtx);
extern rtx        gen_altivec_vslo                      (rtx, rtx, rtx);
extern rtx        gen_vslv                              (rtx, rtx, rtx);
extern rtx        gen_vsrv                              (rtx, rtx, rtx);
extern rtx        gen_altivec_vslq_v1ti                 (rtx, rtx, rtx);
extern rtx        gen_altivec_vslq_ti                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vsrq_v1ti                 (rtx, rtx, rtx);
extern rtx        gen_altivec_vsrq_ti                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vsraq                     (rtx, rtx, rtx);
extern rtx        gen_altivec_vsr                       (rtx, rtx, rtx);
extern rtx        gen_altivec_vsro                      (rtx, rtx, rtx);
extern rtx        gen_altivec_vsum4ubs                  (rtx, rtx, rtx);
extern rtx        gen_altivec_vsum4shs                  (rtx, rtx, rtx);
extern rtx        gen_altivec_vsum4sbs                  (rtx, rtx, rtx);
extern rtx        gen_altivec_vsum2sws_direct           (rtx, rtx, rtx);
extern rtx        gen_altivec_vsumsws_direct            (rtx, rtx, rtx);
extern rtx        gen_altivec_vspltb_direct             (rtx, rtx, rtx);
extern rtx        gen_altivec_vsplth_direct             (rtx, rtx, rtx);
extern rtx        gen_altivec_vspltw_direct             (rtx, rtx, rtx);
extern rtx        gen_altivec_vspltisw                  (rtx, rtx);
extern rtx        gen_altivec_vspltish                  (rtx, rtx);
extern rtx        gen_altivec_vspltisb                  (rtx, rtx);
extern rtx        gen_altivec_vperm_v4si_direct         (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v8hi_direct         (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v16qi_direct        (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v4sf_direct         (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v2df_direct         (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v2di_direct         (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v1ti_direct         (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_ti_direct           (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_kf_direct           (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_tf_direct           (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v8hiv16qi           (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vrfip                     (rtx, rtx);
extern rtx        gen_altivec_vrfin                     (rtx, rtx);
extern rtx        gen_altivec_vcfux                     (rtx, rtx, rtx);
extern rtx        gen_altivec_vcfsx                     (rtx, rtx, rtx);
extern rtx        gen_altivec_vctuxs                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vctsxs                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vlogefp                   (rtx, rtx);
extern rtx        gen_altivec_vexptefp                  (rtx, rtx);
extern rtx        gen_altivec_vrefp                     (rtx, rtx);
extern rtx        gen_altivec_vsldoi_v4si               (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsldoi_v8hi               (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsldoi_v16qi              (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsldoi_v4sf               (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsldoi_v2df               (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsldoi_v2di               (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsldoi_v1ti               (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsldoi_ti                 (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsldoi_kf                 (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsldoi_tf                 (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vupkhsw                   (rtx, rtx);
extern rtx        gen_altivec_vupkhsh                   (rtx, rtx);
extern rtx        gen_altivec_vupkhsb                   (rtx, rtx);
extern rtx        gen_altivec_vupklsw                   (rtx, rtx);
extern rtx        gen_altivec_vupklsh                   (rtx, rtx);
extern rtx        gen_altivec_vupklsb                   (rtx, rtx);
extern rtx        gen_altivec_vupkhpx                   (rtx, rtx);
extern rtx        gen_altivec_vupklpx                   (rtx, rtx);
extern rtx        gen_altivec_vcmpequw_p                (rtx, rtx, rtx);
extern rtx        gen_altivec_vcmpequh_p                (rtx, rtx, rtx);
extern rtx        gen_altivec_vcmpequb_p                (rtx, rtx, rtx);
extern rtx        gen_altivec_vcmpequd_p                (rtx, rtx, rtx);
extern rtx        gen_altivec_vcmpequt_p                (rtx, rtx, rtx);
extern rtx        gen_altivec_vcmpbfp_p                 (rtx, rtx, rtx);
extern rtx        gen_altivec_mtvscr                    (rtx);
extern rtx        gen_altivec_mfvscr                    (rtx);
extern rtx        gen_altivec_dssall                    (void);
extern rtx        gen_altivec_dss                       (rtx);
extern rtx        gen_altivec_dst                       (rtx, rtx, rtx);
extern rtx        gen_altivec_dstt                      (rtx, rtx, rtx);
extern rtx        gen_altivec_dstst                     (rtx, rtx, rtx);
extern rtx        gen_altivec_dststt                    (rtx, rtx, rtx);
extern rtx        gen_altivec_lvsl_reg_si               (rtx, rtx);
extern rtx        gen_altivec_lvsl_reg_di               (rtx, rtx);
extern rtx        gen_altivec_lvsl_direct               (rtx, rtx);
extern rtx        gen_altivec_lvsr_reg_si               (rtx, rtx);
extern rtx        gen_altivec_lvsr_reg_di               (rtx, rtx);
extern rtx        gen_altivec_lvsr_direct               (rtx, rtx);
extern rtx        gen_altivec_lvewx                     (rtx, rtx);
extern rtx        gen_altivec_lvehx                     (rtx, rtx);
extern rtx        gen_altivec_lvebx                     (rtx, rtx);
extern rtx        gen_altivec_lvxl_v4si                 (rtx, rtx);
extern rtx        gen_altivec_lvxl_v8hi                 (rtx, rtx);
extern rtx        gen_altivec_lvxl_v16qi                (rtx, rtx);
extern rtx        gen_altivec_lvxl_v4sf                 (rtx, rtx);
extern rtx        gen_altivec_lvxl_v2df                 (rtx, rtx);
extern rtx        gen_altivec_lvxl_v2di                 (rtx, rtx);
extern rtx        gen_altivec_lvxl_v1ti                 (rtx, rtx);
extern rtx        gen_altivec_lvxl_kf                   (rtx, rtx);
extern rtx        gen_altivec_lvxl_tf                   (rtx, rtx);
extern rtx        gen_altivec_lvx_v4si_internal         (rtx, rtx);
extern rtx        gen_altivec_lvx_v8hi_internal         (rtx, rtx);
extern rtx        gen_altivec_lvx_v16qi_internal        (rtx, rtx);
extern rtx        gen_altivec_lvx_v4sf_internal         (rtx, rtx);
extern rtx        gen_altivec_lvx_v2df_internal         (rtx, rtx);
extern rtx        gen_altivec_lvx_v2di_internal         (rtx, rtx);
extern rtx        gen_altivec_lvx_v1ti_internal         (rtx, rtx);
extern rtx        gen_altivec_lvx_kf_internal           (rtx, rtx);
extern rtx        gen_altivec_lvx_tf_internal           (rtx, rtx);
extern rtx        gen_altivec_lvx_v4si_2op_si           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v4si_2op_di           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v8hi_2op_si           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v8hi_2op_di           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v16qi_2op_si          (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v16qi_2op_di          (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v4sf_2op_si           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v4sf_2op_di           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v2df_2op_si           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v2df_2op_di           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v2di_2op_si           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v2di_2op_di           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v1ti_2op_si           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v1ti_2op_di           (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_kf_2op_si             (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_kf_2op_di             (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_tf_2op_si             (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_tf_2op_di             (rtx, rtx, rtx);
extern rtx        gen_altivec_lvx_v4si_1op_si           (rtx, rtx);
extern rtx        gen_altivec_lvx_v4si_1op_di           (rtx, rtx);
extern rtx        gen_altivec_lvx_v8hi_1op_si           (rtx, rtx);
extern rtx        gen_altivec_lvx_v8hi_1op_di           (rtx, rtx);
extern rtx        gen_altivec_lvx_v16qi_1op_si          (rtx, rtx);
extern rtx        gen_altivec_lvx_v16qi_1op_di          (rtx, rtx);
extern rtx        gen_altivec_lvx_v4sf_1op_si           (rtx, rtx);
extern rtx        gen_altivec_lvx_v4sf_1op_di           (rtx, rtx);
extern rtx        gen_altivec_lvx_v2df_1op_si           (rtx, rtx);
extern rtx        gen_altivec_lvx_v2df_1op_di           (rtx, rtx);
extern rtx        gen_altivec_lvx_v2di_1op_si           (rtx, rtx);
extern rtx        gen_altivec_lvx_v2di_1op_di           (rtx, rtx);
extern rtx        gen_altivec_lvx_v1ti_1op_si           (rtx, rtx);
extern rtx        gen_altivec_lvx_v1ti_1op_di           (rtx, rtx);
extern rtx        gen_altivec_lvx_kf_1op_si             (rtx, rtx);
extern rtx        gen_altivec_lvx_kf_1op_di             (rtx, rtx);
extern rtx        gen_altivec_lvx_tf_1op_si             (rtx, rtx);
extern rtx        gen_altivec_lvx_tf_1op_di             (rtx, rtx);
extern rtx        gen_altivec_stvx_v4si_internal        (rtx, rtx);
extern rtx        gen_altivec_stvx_v8hi_internal        (rtx, rtx);
extern rtx        gen_altivec_stvx_v16qi_internal       (rtx, rtx);
extern rtx        gen_altivec_stvx_v4sf_internal        (rtx, rtx);
extern rtx        gen_altivec_stvx_v2df_internal        (rtx, rtx);
extern rtx        gen_altivec_stvx_v2di_internal        (rtx, rtx);
extern rtx        gen_altivec_stvx_v1ti_internal        (rtx, rtx);
extern rtx        gen_altivec_stvx_kf_internal          (rtx, rtx);
extern rtx        gen_altivec_stvx_tf_internal          (rtx, rtx);
extern rtx        gen_altivec_stvx_v4si_2op_si          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v4si_2op_di          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v8hi_2op_si          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v8hi_2op_di          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v16qi_2op_si         (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v16qi_2op_di         (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v4sf_2op_si          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v4sf_2op_di          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v2df_2op_si          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v2df_2op_di          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v2di_2op_si          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v2di_2op_di          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v1ti_2op_si          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v1ti_2op_di          (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_kf_2op_si            (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_kf_2op_di            (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_tf_2op_si            (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_tf_2op_di            (rtx, rtx, rtx);
extern rtx        gen_altivec_stvx_v4si_1op_si          (rtx, rtx);
extern rtx        gen_altivec_stvx_v4si_1op_di          (rtx, rtx);
extern rtx        gen_altivec_stvx_v8hi_1op_si          (rtx, rtx);
extern rtx        gen_altivec_stvx_v8hi_1op_di          (rtx, rtx);
extern rtx        gen_altivec_stvx_v16qi_1op_si         (rtx, rtx);
extern rtx        gen_altivec_stvx_v16qi_1op_di         (rtx, rtx);
extern rtx        gen_altivec_stvx_v4sf_1op_si          (rtx, rtx);
extern rtx        gen_altivec_stvx_v4sf_1op_di          (rtx, rtx);
extern rtx        gen_altivec_stvx_v2df_1op_si          (rtx, rtx);
extern rtx        gen_altivec_stvx_v2df_1op_di          (rtx, rtx);
extern rtx        gen_altivec_stvx_v2di_1op_si          (rtx, rtx);
extern rtx        gen_altivec_stvx_v2di_1op_di          (rtx, rtx);
extern rtx        gen_altivec_stvx_v1ti_1op_si          (rtx, rtx);
extern rtx        gen_altivec_stvx_v1ti_1op_di          (rtx, rtx);
extern rtx        gen_altivec_stvx_kf_1op_si            (rtx, rtx);
extern rtx        gen_altivec_stvx_kf_1op_di            (rtx, rtx);
extern rtx        gen_altivec_stvx_tf_1op_si            (rtx, rtx);
extern rtx        gen_altivec_stvx_tf_1op_di            (rtx, rtx);
extern rtx        gen_altivec_stvxl_v4si                (rtx, rtx);
extern rtx        gen_altivec_stvxl_v8hi                (rtx, rtx);
extern rtx        gen_altivec_stvxl_v16qi               (rtx, rtx);
extern rtx        gen_altivec_stvxl_v4sf                (rtx, rtx);
extern rtx        gen_altivec_stvxl_v2df                (rtx, rtx);
extern rtx        gen_altivec_stvxl_v2di                (rtx, rtx);
extern rtx        gen_altivec_stvxl_v1ti                (rtx, rtx);
extern rtx        gen_altivec_stvxl_kf                  (rtx, rtx);
extern rtx        gen_altivec_stvxl_tf                  (rtx, rtx);
extern rtx        gen_altivec_stvewx                    (rtx, rtx);
extern rtx        gen_altivec_stvehx                    (rtx, rtx);
extern rtx        gen_altivec_stvebx                    (rtx, rtx);
extern rtx        gen_vperm_v8hiv4si                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vperm_v16qiv8hi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_xxeval                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_lvlx                      (rtx, rtx);
extern rtx        gen_altivec_lvlxl                     (rtx, rtx);
extern rtx        gen_altivec_lvrx                      (rtx, rtx);
extern rtx        gen_altivec_lvrxl                     (rtx, rtx);
extern rtx        gen_altivec_stvlx                     (rtx, rtx);
extern rtx        gen_altivec_stvlxl                    (rtx, rtx);
extern rtx        gen_altivec_stvrx                     (rtx, rtx);
extern rtx        gen_altivec_stvrxl                    (rtx, rtx);
extern rtx        gen_p9_vaduv4si3                      (rtx, rtx, rtx);
extern rtx        gen_p9_vaduv8hi3                      (rtx, rtx, rtx);
extern rtx        gen_p9_vaduv16qi3                     (rtx, rtx, rtx);
extern rtx        gen_p8v_vgbbd                         (rtx, rtx);
extern rtx        gen_altivec_vadduqm                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vaddcuq                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vsubuqm                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vsubcuq                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vaddeuqm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vaddecuq                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsubeuqm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vsubecuq                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vbpermq                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vbpermq2                  (rtx, rtx, rtx);
extern rtx        gen_altivec_vbpermd                   (rtx, rtx, rtx);
extern rtx        gen_bcdadd_v1ti                       (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_v1ti                       (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_v16qi                      (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_v16qi                      (rtx, rtx, rtx, rtx);
extern rtx        gen_vcfuged                           (rtx, rtx, rtx);
extern rtx        gen_vclzdm                            (rtx, rtx, rtx);
extern rtx        gen_vctzdm                            (rtx, rtx, rtx);
extern rtx        gen_vpdepd                            (rtx, rtx, rtx);
extern rtx        gen_vpextd                            (rtx, rtx, rtx);
extern rtx        gen_vgnb                              (rtx, rtx, rtx);
extern rtx        gen_vclrlb                            (rtx, rtx, rtx);
extern rtx        gen_vclrrb                            (rtx, rtx, rtx);
extern rtx        gen_bcdshift_v16qi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xxmfacc                       (rtx, rtx);
extern rtx        gen_mma_xxmtacc                       (rtx, rtx);
extern rtx        gen_mma_xvi4ger8                      (rtx, rtx, rtx);
extern rtx        gen_mma_xvi8ger4                      (rtx, rtx, rtx);
extern rtx        gen_mma_xvi16ger2                     (rtx, rtx, rtx);
extern rtx        gen_mma_xvi16ger2s                    (rtx, rtx, rtx);
extern rtx        gen_mma_xvf16ger2                     (rtx, rtx, rtx);
extern rtx        gen_mma_xvbf16ger2                    (rtx, rtx, rtx);
extern rtx        gen_mma_xvf32ger                      (rtx, rtx, rtx);
extern rtx        gen_mma_xvi4ger8pp                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvi8ger4pp                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvi8ger4spp                   (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvi16ger2pp                   (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvi16ger2spp                  (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf16ger2pp                   (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf16ger2pn                   (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf16ger2np                   (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf16ger2nn                   (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvbf16ger2pp                  (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvbf16ger2pn                  (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvbf16ger2np                  (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvbf16ger2nn                  (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf32gerpp                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf32gerpn                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf32gernp                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf32gernn                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf64ger                      (rtx, rtx, rtx);
extern rtx        gen_mma_xvf64gerpp                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf64gerpn                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf64gernp                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_xvf64gernn                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvi4ger8                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvi4ger8pp                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvi16ger2                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvi16ger2s                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf16ger2                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvbf16ger2                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvi16ger2pp                 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvi16ger2spp                (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf16ger2pp                 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf16ger2pn                 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf16ger2np                 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf16ger2nn                 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvbf16ger2pp                (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvbf16ger2pn                (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvbf16ger2np                (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvbf16ger2nn                (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf32ger                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf32gerpp                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf32gerpn                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf32gernp                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf32gernn                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf64ger                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf64gerpp                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf64gerpn                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf64gernp                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvf64gernn                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvi8ger4                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvi8ger4pp                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_pmxvi8ger4spp                 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_movsd_store                       (rtx, rtx);
extern rtx        gen_movsd_load                        (rtx, rtx);
extern rtx        gen_extendsddd2                       (rtx, rtx);
extern rtx        gen_truncddsd2                        (rtx, rtx);
extern rtx        gen_negdd2                            (rtx, rtx);
extern rtx        gen_absdd2                            (rtx, rtx);
extern rtx        gen_negtd2                            (rtx, rtx);
extern rtx        gen_abstd2                            (rtx, rtx);
extern rtx        gen_extendddtd2                       (rtx, rtx);
extern rtx        gen_trunctddd2                        (rtx, rtx);
extern rtx        gen_trunctdsd2                        (rtx, rtx);
extern rtx        gen_adddd3                            (rtx, rtx, rtx);
extern rtx        gen_addtd3                            (rtx, rtx, rtx);
extern rtx        gen_subdd3                            (rtx, rtx, rtx);
extern rtx        gen_subtd3                            (rtx, rtx, rtx);
extern rtx        gen_muldd3                            (rtx, rtx, rtx);
extern rtx        gen_multd3                            (rtx, rtx, rtx);
extern rtx        gen_divdd3                            (rtx, rtx, rtx);
extern rtx        gen_divtd3                            (rtx, rtx, rtx);
extern rtx        gen_floatdidd2                        (rtx, rtx);
extern rtx        gen_floatditd2                        (rtx, rtx);
extern rtx        gen_floattitd2                        (rtx, rtx);
extern rtx        gen_ftruncdd2                         (rtx, rtx);
extern rtx        gen_ftrunctd2                         (rtx, rtx);
extern rtx        gen_fixdddi2                          (rtx, rtx);
extern rtx        gen_fixtddi2                          (rtx, rtx);
extern rtx        gen_fixtdti2                          (rtx, rtx);
extern rtx        gen_dfp_ddedpd_dd                     (rtx, rtx, rtx);
extern rtx        gen_dfp_ddedpd_td                     (rtx, rtx, rtx);
extern rtx        gen_dfp_denbcd_dd                     (rtx, rtx, rtx);
extern rtx        gen_dfp_denbcd_td                     (rtx, rtx, rtx);
extern rtx        gen_dfp_denbcd_v16qi_inst             (rtx, rtx, rtx);
extern rtx        gen_dfp_dxex_dd                       (rtx, rtx);
extern rtx        gen_dfp_dxex_td                       (rtx, rtx);
extern rtx        gen_dfp_diex_dd                       (rtx, rtx, rtx);
extern rtx        gen_dfp_diex_td                       (rtx, rtx, rtx);
extern rtx        gen_dfp_dscli_dd                      (rtx, rtx, rtx);
extern rtx        gen_dfp_dscli_td                      (rtx, rtx, rtx);
extern rtx        gen_dfp_dscri_dd                      (rtx, rtx, rtx);
extern rtx        gen_dfp_dscri_td                      (rtx, rtx, rtx);
extern rtx        gen_crypto_vcipher_v16qi              (rtx, rtx, rtx);
extern rtx        gen_crypto_vncipher_v16qi             (rtx, rtx, rtx);
extern rtx        gen_crypto_vcipherlast_v16qi          (rtx, rtx, rtx);
extern rtx        gen_crypto_vncipherlast_v16qi         (rtx, rtx, rtx);
extern rtx        gen_crypto_vcipher_v2di               (rtx, rtx, rtx);
extern rtx        gen_crypto_vncipher_v2di              (rtx, rtx, rtx);
extern rtx        gen_crypto_vcipherlast_v2di           (rtx, rtx, rtx);
extern rtx        gen_crypto_vncipherlast_v2di          (rtx, rtx, rtx);
extern rtx        gen_crypto_vpmsumb                    (rtx, rtx, rtx);
extern rtx        gen_crypto_vpmsumh                    (rtx, rtx, rtx);
extern rtx        gen_crypto_vpmsumw                    (rtx, rtx, rtx);
extern rtx        gen_crypto_vpmsumd                    (rtx, rtx, rtx);
extern rtx        gen_crypto_vpermxor_v16qi             (rtx, rtx, rtx, rtx);
extern rtx        gen_crypto_vpermxor_v8hi              (rtx, rtx, rtx, rtx);
extern rtx        gen_crypto_vpermxor_v4si              (rtx, rtx, rtx, rtx);
extern rtx        gen_crypto_vpermxor_v2di              (rtx, rtx, rtx, rtx);
extern rtx        gen_crypto_vsbox_v16qi                (rtx, rtx);
extern rtx        gen_crypto_vsbox_v2di                 (rtx, rtx);
extern rtx        gen_crypto_vshasigmaw                 (rtx, rtx, rtx, rtx);
extern rtx        gen_crypto_vshasigmad                 (rtx, rtx, rtx, rtx);
extern rtx        gen_htm_mfspr_si                      (rtx, rtx);
extern rtx        gen_htm_mfspr_di                      (rtx, rtx);
extern rtx        gen_htm_mtspr_si                      (rtx, rtx);
extern rtx        gen_htm_mtspr_di                      (rtx, rtx);
extern rtx        gen_pcrel_opt_ld_addr                 (rtx, rtx, rtx, rtx);
extern rtx        gen_pcrel_opt_ld_addr_same_reg        (rtx, rtx, rtx);
extern rtx        gen_extendhisi2                       (rtx, rtx);
extern rtx        gen_extendhidi2                       (rtx, rtx);
extern rtx        gen_strlensi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_addsi3                            (rtx, rtx, rtx);
extern rtx        gen_adddi3                            (rtx, rtx, rtx);
extern rtx        gen_addsi3_carry_in                   (rtx, rtx, rtx);
extern rtx        gen_adddi3_carry_in                   (rtx, rtx, rtx);
extern rtx        gen_one_cmplsi2                       (rtx, rtx);
extern rtx        gen_one_cmpldi2                       (rtx, rtx);
extern rtx        gen_subsi3                            (rtx, rtx, rtx);
extern rtx        gen_subdi3                            (rtx, rtx, rtx);
extern rtx        gen_subfsi3_carry_in                  (rtx, rtx, rtx);
extern rtx        gen_subfdi3_carry_in                  (rtx, rtx, rtx);
extern rtx        gen_ctzsi2                            (rtx, rtx);
extern rtx        gen_ctzdi2                            (rtx, rtx);
extern rtx        gen_ffssi2                            (rtx, rtx);
extern rtx        gen_ffsdi2                            (rtx, rtx);
extern rtx        gen_popcountsi2                       (rtx, rtx);
extern rtx        gen_popcountdi2                       (rtx, rtx);
extern rtx        gen_paritysi2                         (rtx, rtx);
extern rtx        gen_paritydi2                         (rtx, rtx);
extern rtx        gen_bswaphi2                          (rtx, rtx);
extern rtx        gen_bswapsi2                          (rtx, rtx);
extern rtx        gen_bswapdi2                          (rtx, rtx);
extern rtx        gen_smulsi3_highpart                  (rtx, rtx, rtx);
extern rtx        gen_umulsi3_highpart                  (rtx, rtx, rtx);
extern rtx        gen_smuldi3_highpart                  (rtx, rtx, rtx);
extern rtx        gen_umuldi3_highpart                  (rtx, rtx, rtx);
extern rtx        gen_mulsidi3                          (rtx, rtx, rtx);
extern rtx        gen_umulsidi3                         (rtx, rtx, rtx);
extern rtx        gen_mulditi3                          (rtx, rtx, rtx);
extern rtx        gen_umulditi3                         (rtx, rtx, rtx);
extern rtx        gen_divsi3                            (rtx, rtx, rtx);
extern rtx        gen_divdi3                            (rtx, rtx, rtx);
extern rtx        gen_modsi3                            (rtx, rtx, rtx);
extern rtx        gen_moddi3                            (rtx, rtx, rtx);
extern rtx        gen_andsi3                            (rtx, rtx, rtx);
extern rtx        gen_anddi3                            (rtx, rtx, rtx);
extern rtx        gen_iorsi3                            (rtx, rtx, rtx);
extern rtx        gen_xorsi3                            (rtx, rtx, rtx);
extern rtx        gen_iordi3                            (rtx, rtx, rtx);
extern rtx        gen_xordi3                            (rtx, rtx, rtx);
extern rtx        gen_recipsf3                          (rtx, rtx, rtx);
extern rtx        gen_recipdf3                          (rtx, rtx, rtx);
extern rtx        gen_recipv4sf3                        (rtx, rtx, rtx);
extern rtx        gen_recipv2df3                        (rtx, rtx, rtx);
extern rtx        gen_rsqrtsf2                          (rtx, rtx);
extern rtx        gen_rsqrtdf2                          (rtx, rtx);
extern rtx        gen_rsqrtv4sf2                        (rtx, rtx);
extern rtx        gen_rsqrtv2df2                        (rtx, rtx);
extern rtx        gen_abssf2                            (rtx, rtx);
extern rtx        gen_absdf2                            (rtx, rtx);
extern rtx        gen_negsf2                            (rtx, rtx);
extern rtx        gen_negdf2                            (rtx, rtx);
extern rtx        gen_addsf3                            (rtx, rtx, rtx);
extern rtx        gen_adddf3                            (rtx, rtx, rtx);
extern rtx        gen_subsf3                            (rtx, rtx, rtx);
extern rtx        gen_subdf3                            (rtx, rtx, rtx);
extern rtx        gen_mulsf3                            (rtx, rtx, rtx);
extern rtx        gen_muldf3                            (rtx, rtx, rtx);
extern rtx        gen_divsf3                            (rtx, rtx, rtx);
extern rtx        gen_divdf3                            (rtx, rtx, rtx);
extern rtx        gen_sqrtsf2                           (rtx, rtx);
extern rtx        gen_sqrtdf2                           (rtx, rtx);
extern rtx        gen_extendsfdf2                       (rtx, rtx);
extern rtx        gen_truncdfsf2                        (rtx, rtx);
extern rtx        gen_signbitkf2                        (rtx, rtx);
extern rtx        gen_signbitif2                        (rtx, rtx);
extern rtx        gen_signbittf2                        (rtx, rtx);
extern rtx        gen_copysignsf3                       (rtx, rtx, rtx);
extern rtx        gen_copysigndf3                       (rtx, rtx, rtx);
extern rtx        gen_sminsf3                           (rtx, rtx, rtx);
extern rtx        gen_smaxsf3                           (rtx, rtx, rtx);
extern rtx        gen_smindf3                           (rtx, rtx, rtx);
extern rtx        gen_smaxdf3                           (rtx, rtx, rtx);
extern rtx        gen_movsicc                           (rtx, rtx, rtx, rtx);
extern rtx        gen_movdicc                           (rtx, rtx, rtx, rtx);
extern rtx        gen_movsfcc                           (rtx, rtx, rtx, rtx);
extern rtx        gen_movdfcc                           (rtx, rtx, rtx, rtx);
extern rtx        gen_movkfcc                           (rtx, rtx, rtx, rtx);
extern rtx        gen_movtfcc                           (rtx, rtx, rtx, rtx);
extern rtx        gen_floatsidf2                        (rtx, rtx);
extern rtx        gen_floatunssisf2                     (rtx, rtx);
extern rtx        gen_floatunssidf2                     (rtx, rtx);
extern rtx        gen_floatqisf2                        (rtx, rtx);
extern rtx        gen_floatqidf2                        (rtx, rtx);
extern rtx        gen_floathisf2                        (rtx, rtx);
extern rtx        gen_floathidf2                        (rtx, rtx);
extern rtx        gen_floatunsqisf2                     (rtx, rtx);
extern rtx        gen_floatunsqidf2                     (rtx, rtx);
extern rtx        gen_floatunshisf2                     (rtx, rtx);
extern rtx        gen_floatunshidf2                     (rtx, rtx);
extern rtx        gen_fix_truncsfsi2                    (rtx, rtx);
extern rtx        gen_fix_truncdfsi2                    (rtx, rtx);
extern rtx        gen_fix_truncsfdi2                    (rtx, rtx);
extern rtx        gen_fix_truncdfdi2                    (rtx, rtx);
extern rtx        gen_fixuns_truncsfsi2                 (rtx, rtx);
extern rtx        gen_fixuns_truncdfsi2                 (rtx, rtx);
extern rtx        gen_rs6000_set_fpscr_rn               (rtx);
extern rtx        gen_rs6000_set_fpscr_drn              (rtx);
extern rtx        gen_lroundsfdi2                       (rtx, rtx);
extern rtx        gen_lrounddfdi2                       (rtx, rtx);
extern rtx        gen_floatsisf2                        (rtx, rtx);
extern rtx        gen_floatunsdidf2                     (rtx, rtx);
extern rtx        gen_floatdisf2                        (rtx, rtx);
extern rtx        gen_floatdisf2_internal2              (rtx, rtx, rtx);
extern rtx        gen_floatunsdisf2                     (rtx, rtx);
extern rtx        gen_addti3                            (rtx, rtx, rtx);
extern rtx        gen_subti3                            (rtx, rtx, rtx);
extern rtx        gen_andti3                            (rtx, rtx, rtx);
extern rtx        gen_andpti3                           (rtx, rtx, rtx);
extern rtx        gen_andv16qi3                         (rtx, rtx, rtx);
extern rtx        gen_andv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_andv4si3                          (rtx, rtx, rtx);
extern rtx        gen_andv4sf3                          (rtx, rtx, rtx);
extern rtx        gen_andv2di3                          (rtx, rtx, rtx);
extern rtx        gen_andv2df3                          (rtx, rtx, rtx);
extern rtx        gen_andv1ti3                          (rtx, rtx, rtx);
extern rtx        gen_iorti3                            (rtx, rtx, rtx);
extern rtx        gen_iorpti3                           (rtx, rtx, rtx);
extern rtx        gen_iorv16qi3                         (rtx, rtx, rtx);
extern rtx        gen_iorv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_iorv4si3                          (rtx, rtx, rtx);
extern rtx        gen_iorv4sf3                          (rtx, rtx, rtx);
extern rtx        gen_iorv2di3                          (rtx, rtx, rtx);
extern rtx        gen_iorv2df3                          (rtx, rtx, rtx);
extern rtx        gen_iorv1ti3                          (rtx, rtx, rtx);
extern rtx        gen_xorti3                            (rtx, rtx, rtx);
extern rtx        gen_xorpti3                           (rtx, rtx, rtx);
extern rtx        gen_xorv16qi3                         (rtx, rtx, rtx);
extern rtx        gen_xorv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_xorv4si3                          (rtx, rtx, rtx);
extern rtx        gen_xorv4sf3                          (rtx, rtx, rtx);
extern rtx        gen_xorv2di3                          (rtx, rtx, rtx);
extern rtx        gen_xorv2df3                          (rtx, rtx, rtx);
extern rtx        gen_xorv1ti3                          (rtx, rtx, rtx);
extern rtx        gen_norti3                            (rtx, rtx, rtx);
extern rtx        gen_norpti3                           (rtx, rtx, rtx);
extern rtx        gen_norv16qi3                         (rtx, rtx, rtx);
extern rtx        gen_norv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_norv4si3                          (rtx, rtx, rtx);
extern rtx        gen_norv4sf3                          (rtx, rtx, rtx);
extern rtx        gen_norv2di3                          (rtx, rtx, rtx);
extern rtx        gen_norv2df3                          (rtx, rtx, rtx);
extern rtx        gen_norv1ti3                          (rtx, rtx, rtx);
extern rtx        gen_andcti3                           (rtx, rtx, rtx);
extern rtx        gen_andcpti3                          (rtx, rtx, rtx);
extern rtx        gen_andcv16qi3                        (rtx, rtx, rtx);
extern rtx        gen_andcv8hi3                         (rtx, rtx, rtx);
extern rtx        gen_andcv4si3                         (rtx, rtx, rtx);
extern rtx        gen_andcv4sf3                         (rtx, rtx, rtx);
extern rtx        gen_andcv2di3                         (rtx, rtx, rtx);
extern rtx        gen_andcv2df3                         (rtx, rtx, rtx);
extern rtx        gen_andcv1ti3                         (rtx, rtx, rtx);
extern rtx        gen_eqvti3                            (rtx, rtx, rtx);
extern rtx        gen_eqvpti3                           (rtx, rtx, rtx);
extern rtx        gen_eqvv16qi3                         (rtx, rtx, rtx);
extern rtx        gen_eqvv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_eqvv4si3                          (rtx, rtx, rtx);
extern rtx        gen_eqvv4sf3                          (rtx, rtx, rtx);
extern rtx        gen_eqvv2di3                          (rtx, rtx, rtx);
extern rtx        gen_eqvv2df3                          (rtx, rtx, rtx);
extern rtx        gen_eqvv1ti3                          (rtx, rtx, rtx);
extern rtx        gen_nandti3                           (rtx, rtx, rtx);
extern rtx        gen_nandpti3                          (rtx, rtx, rtx);
extern rtx        gen_nandv16qi3                        (rtx, rtx, rtx);
extern rtx        gen_nandv8hi3                         (rtx, rtx, rtx);
extern rtx        gen_nandv4si3                         (rtx, rtx, rtx);
extern rtx        gen_nandv4sf3                         (rtx, rtx, rtx);
extern rtx        gen_nandv2di3                         (rtx, rtx, rtx);
extern rtx        gen_nandv2df3                         (rtx, rtx, rtx);
extern rtx        gen_nandv1ti3                         (rtx, rtx, rtx);
extern rtx        gen_orcti3                            (rtx, rtx, rtx);
extern rtx        gen_orcpti3                           (rtx, rtx, rtx);
extern rtx        gen_orcv16qi3                         (rtx, rtx, rtx);
extern rtx        gen_orcv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_orcv4si3                          (rtx, rtx, rtx);
extern rtx        gen_orcv4sf3                          (rtx, rtx, rtx);
extern rtx        gen_orcv2di3                          (rtx, rtx, rtx);
extern rtx        gen_orcv2df3                          (rtx, rtx, rtx);
extern rtx        gen_orcv1ti3                          (rtx, rtx, rtx);
extern rtx        gen_movsi_got                         (rtx, rtx);
extern rtx        gen_movqi                             (rtx, rtx);
extern rtx        gen_movhi                             (rtx, rtx);
extern rtx        gen_movsi                             (rtx, rtx);
extern rtx        gen_movdi                             (rtx, rtx);
extern rtx        gen_movti                             (rtx, rtx);
extern rtx        gen_movpti                            (rtx, rtx);
extern rtx        gen_movcc                             (rtx, rtx);
extern rtx        gen_movsf                             (rtx, rtx);
extern rtx        gen_movsd                             (rtx, rtx);
extern rtx        gen_movdf                             (rtx, rtx);
extern rtx        gen_movdd                             (rtx, rtx);
extern rtx        gen_movtf                             (rtx, rtx);
extern rtx        gen_movif                             (rtx, rtx);
extern rtx        gen_movtd                             (rtx, rtx);
extern rtx        gen_extenddfkf2                       (rtx, rtx);
extern rtx        gen_extenddfif2                       (rtx, rtx);
extern rtx        gen_extenddftf2                       (rtx, rtx);
extern rtx        gen_extendsfkf2                       (rtx, rtx);
extern rtx        gen_extendsfif2                       (rtx, rtx);
extern rtx        gen_extendsftf2                       (rtx, rtx);
extern rtx        gen_trunckfdf2                        (rtx, rtx);
extern rtx        gen_truncifdf2                        (rtx, rtx);
extern rtx        gen_trunctfdf2                        (rtx, rtx);
extern rtx        gen_trunckfsf2                        (rtx, rtx);
extern rtx        gen_truncifsf2                        (rtx, rtx);
extern rtx        gen_trunctfsf2                        (rtx, rtx);
extern rtx        gen_floatsikf2                        (rtx, rtx);
extern rtx        gen_floatsiif2                        (rtx, rtx);
extern rtx        gen_floatsitf2                        (rtx, rtx);
extern rtx        gen_fix_trunckfsi2                    (rtx, rtx);
extern rtx        gen_fix_truncifsi2                    (rtx, rtx);
extern rtx        gen_fix_trunctfsi2                    (rtx, rtx);
extern rtx        gen_fix_truncifsi2_fprs               (rtx, rtx);
extern rtx        gen_fix_trunctfsi2_fprs               (rtx, rtx);
extern rtx        gen_fix_trunckfdi2                    (rtx, rtx);
extern rtx        gen_fix_trunctfdi2                    (rtx, rtx);
extern rtx        gen_fixuns_trunckfsi2                 (rtx, rtx);
extern rtx        gen_fixuns_trunctfsi2                 (rtx, rtx);
extern rtx        gen_fixuns_trunckfdi2                 (rtx, rtx);
extern rtx        gen_fixuns_trunctfdi2                 (rtx, rtx);
extern rtx        gen_floatdikf2                        (rtx, rtx);
extern rtx        gen_floatditf2                        (rtx, rtx);
extern rtx        gen_floatunsdikf2                     (rtx, rtx);
extern rtx        gen_floatunsditf2                     (rtx, rtx);
extern rtx        gen_floatunskf2                       (rtx, rtx);
extern rtx        gen_floatunstf2                       (rtx, rtx);
extern rtx        gen_negkf2                            (rtx, rtx);
extern rtx        gen_negif2                            (rtx, rtx);
extern rtx        gen_negtf2                            (rtx, rtx);
extern rtx        gen_abskf2                            (rtx, rtx);
extern rtx        gen_absif2                            (rtx, rtx);
extern rtx        gen_abstf2                            (rtx, rtx);
extern rtx        gen_absif2_internal                   (rtx, rtx, rtx);
extern rtx        gen_abstf2_internal                   (rtx, rtx, rtx);
extern rtx        gen_ieee_128bit_negative_zero         (rtx);
extern rtx        gen_extendiftf2                       (rtx, rtx);
extern rtx        gen_extendifkf2                       (rtx, rtx);
extern rtx        gen_extendtfkf2                       (rtx, rtx);
extern rtx        gen_extendtfif2                       (rtx, rtx);
extern rtx        gen_trunciftf2                        (rtx, rtx);
extern rtx        gen_truncifkf2                        (rtx, rtx);
extern rtx        gen_trunckftf2                        (rtx, rtx);
extern rtx        gen_trunctfif2                        (rtx, rtx);
extern rtx        gen_reload_si_store                   (rtx, rtx, rtx);
extern rtx        gen_reload_di_store                   (rtx, rtx, rtx);
extern rtx        gen_reload_si_load                    (rtx, rtx, rtx);
extern rtx        gen_reload_di_load                    (rtx, rtx, rtx);
extern rtx        gen_reload_v16qi_si_store             (rtx, rtx, rtx);
extern rtx        gen_reload_v8hi_si_store              (rtx, rtx, rtx);
extern rtx        gen_reload_v4si_si_store              (rtx, rtx, rtx);
extern rtx        gen_reload_v2di_si_store              (rtx, rtx, rtx);
extern rtx        gen_reload_v4sf_si_store              (rtx, rtx, rtx);
extern rtx        gen_reload_v2df_si_store              (rtx, rtx, rtx);
extern rtx        gen_reload_v1ti_si_store              (rtx, rtx, rtx);
extern rtx        gen_reload_sf_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_sd_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_si_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_df_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_dd_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_di_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_ti_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_pti_si_store               (rtx, rtx, rtx);
extern rtx        gen_reload_kf_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_if_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_tf_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_oo_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_xo_si_store                (rtx, rtx, rtx);
extern rtx        gen_reload_v16qi_di_store             (rtx, rtx, rtx);
extern rtx        gen_reload_v8hi_di_store              (rtx, rtx, rtx);
extern rtx        gen_reload_v4si_di_store              (rtx, rtx, rtx);
extern rtx        gen_reload_v2di_di_store              (rtx, rtx, rtx);
extern rtx        gen_reload_v4sf_di_store              (rtx, rtx, rtx);
extern rtx        gen_reload_v2df_di_store              (rtx, rtx, rtx);
extern rtx        gen_reload_v1ti_di_store              (rtx, rtx, rtx);
extern rtx        gen_reload_sf_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_sd_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_si_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_df_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_dd_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_di_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_ti_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_pti_di_store               (rtx, rtx, rtx);
extern rtx        gen_reload_kf_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_if_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_tf_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_oo_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_xo_di_store                (rtx, rtx, rtx);
extern rtx        gen_reload_v16qi_si_load              (rtx, rtx, rtx);
extern rtx        gen_reload_v8hi_si_load               (rtx, rtx, rtx);
extern rtx        gen_reload_v4si_si_load               (rtx, rtx, rtx);
extern rtx        gen_reload_v2di_si_load               (rtx, rtx, rtx);
extern rtx        gen_reload_v4sf_si_load               (rtx, rtx, rtx);
extern rtx        gen_reload_v2df_si_load               (rtx, rtx, rtx);
extern rtx        gen_reload_v1ti_si_load               (rtx, rtx, rtx);
extern rtx        gen_reload_sf_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_sd_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_si_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_df_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_dd_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_di_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_ti_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_pti_si_load                (rtx, rtx, rtx);
extern rtx        gen_reload_kf_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_if_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_tf_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_oo_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_xo_si_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_v16qi_di_load              (rtx, rtx, rtx);
extern rtx        gen_reload_v8hi_di_load               (rtx, rtx, rtx);
extern rtx        gen_reload_v4si_di_load               (rtx, rtx, rtx);
extern rtx        gen_reload_v2di_di_load               (rtx, rtx, rtx);
extern rtx        gen_reload_v4sf_di_load               (rtx, rtx, rtx);
extern rtx        gen_reload_v2df_di_load               (rtx, rtx, rtx);
extern rtx        gen_reload_v1ti_di_load               (rtx, rtx, rtx);
extern rtx        gen_reload_sf_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_sd_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_si_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_df_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_dd_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_di_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_ti_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_pti_di_load                (rtx, rtx, rtx);
extern rtx        gen_reload_kf_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_if_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_tf_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_oo_di_load                 (rtx, rtx, rtx);
extern rtx        gen_reload_xo_di_load                 (rtx, rtx, rtx);
extern rtx        gen_setmemsi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_cmpstrnsi                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_cmpstrsi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_cmpmemsi                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_cpymemsi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_movmemsi                          (rtx, rtx, rtx, rtx);
static inline rtx gen_tls_get_tpointer                  (rtx);
static inline rtx
gen_tls_get_tpointer(rtx ARG_UNUSED (a))
{
  return 0;
}
static inline rtx gen_tls_get_addrsi                    (rtx, rtx, rtx);
static inline rtx
gen_tls_get_addrsi(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
static inline rtx gen_tls_get_addrdi                    (rtx, rtx, rtx);
static inline rtx
gen_tls_get_addrdi(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_allocate_stack                    (rtx, rtx);
extern rtx        gen_save_stack_function               (rtx, rtx);
extern rtx        gen_restore_stack_function            (rtx, rtx);
extern rtx        gen_restore_stack_block               (rtx, rtx);
extern rtx        gen_save_stack_nonlocal               (rtx, rtx);
extern rtx        gen_restore_stack_nonlocal            (rtx, rtx);
extern rtx        gen_load_toc_v4_PIC_1                 (rtx);
extern rtx        gen_load_toc_v4_PIC_1b                (rtx, rtx);
extern rtx        gen_builtin_setjmp_receiver           (rtx);
extern rtx        gen_call                              (rtx, rtx, rtx);
extern rtx        gen_call_value                        (rtx, rtx, rtx, rtx);
extern rtx        gen_untyped_call                      (rtx, rtx, rtx);
extern rtx        gen_sibcall                           (rtx, rtx, rtx);
extern rtx        gen_sibcall_value                     (rtx, rtx, rtx, rtx);
extern rtx        gen_sibcall_epilogue                  (void);
extern rtx        gen_probe_stack_address               (rtx);
extern rtx        gen_cbranchsi4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchdi4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchsf4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchdf4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchtf4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchif4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchkf4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchdd4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchtd4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresi4_signed                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredi4_signed                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresi4_unsigned                (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredi4_unsigned                (rtx, rtx, rtx, rtx);
extern rtx        gen_cstore_si_as_di                   (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresi4_signed_imm              (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredi4_signed_imm              (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresi4_unsigned_imm            (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredi4_unsigned_imm            (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresi4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredi4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresf4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredf4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoretf4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoreif4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_cstorekf4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredd4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoretd4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_stack_protect_set                 (rtx, rtx);
extern rtx        gen_stack_protect_test                (rtx, rtx, rtx);
extern rtx        gen_eqsi3                             (rtx, rtx, rtx);
extern rtx        gen_eqdi3                             (rtx, rtx, rtx);
extern rtx        gen_nesi3                             (rtx, rtx, rtx);
extern rtx        gen_nedi3                             (rtx, rtx, rtx);
extern rtx        gen_indirect_jump                     (rtx);
extern rtx        gen_tablejump                         (rtx, rtx);
extern rtx        gen_tablejumpsi_normal                (rtx, rtx);
extern rtx        gen_tablejumpdi_normal                (rtx, rtx);
extern rtx        gen_tablejumpsi_absolute              (rtx, rtx);
extern rtx        gen_tablejumpdi_absolute              (rtx, rtx);
extern rtx        gen_tablejumpsi_nospec                (rtx, rtx, rtx);
extern rtx        gen_tablejumpdi_nospec                (rtx, rtx, rtx);
extern rtx        gen_tablejumpsi_absolute_nospec       (rtx, rtx, rtx);
extern rtx        gen_tablejumpdi_absolute_nospec       (rtx, rtx, rtx);
extern rtx        gen_doloop_end                        (rtx, rtx);
extern rtx        gen_ctrsi                             (rtx, rtx);
extern rtx        gen_ctrdi                             (rtx, rtx);
extern rtx        gen_ctrapsi4                          (rtx, rtx, rtx, rtx);
extern rtx        gen_ctrapdi4                          (rtx, rtx, rtx, rtx);
extern rtx        gen_prologue                          (void);
extern rtx        gen_epilogue                          (void);
extern rtx        gen_movsi_to_cr_one                   (rtx, rtx);
extern rtx        gen_eh_return                         (rtx);
extern rtx        gen_split_stack_prologue              (void);
extern rtx        gen_load_split_stack_limit            (rtx);
extern rtx        gen_split_stack_space_check           (rtx, rtx);
extern rtx        gen_fmasf4                            (rtx, rtx, rtx, rtx);
extern rtx        gen_fmadf4                            (rtx, rtx, rtx, rtx);
extern rtx        gen_fmav4sf4                          (rtx, rtx, rtx, rtx);
extern rtx        gen_fmav2df4                          (rtx, rtx, rtx, rtx);
extern rtx        gen_fmakf4                            (rtx, rtx, rtx, rtx);
extern rtx        gen_fmatf4                            (rtx, rtx, rtx, rtx);
extern rtx        gen_fmssf4                            (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsdf4                            (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsv4sf4                          (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsv2df4                          (rtx, rtx, rtx, rtx);
extern rtx        gen_fmskf4                            (rtx, rtx, rtx, rtx);
extern rtx        gen_fmstf4                            (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmasf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmadf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmav4sf4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmav2df4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmakf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmatf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmssf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsdf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsv4sf4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsv2df4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmskf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmstf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmasf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmadf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmav4sf4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmav2df4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmakf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmatf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmssf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmsdf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmsv4sf4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmsv2df4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmskf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_nfmstf4                           (rtx, rtx, rtx, rtx);
extern rtx        gen_rs6000_get_timebase               (rtx);
extern rtx        gen_rs6000_mffsl                      (rtx);
extern rtx        gen_unpacktf                          (rtx, rtx, rtx);
extern rtx        gen_unpackif                          (rtx, rtx, rtx);
extern rtx        gen_unpacktd                          (rtx, rtx, rtx);
extern rtx        gen_copysignkf3                       (rtx, rtx, rtx);
extern rtx        gen_copysigntf3                       (rtx, rtx, rtx);
extern rtx        gen_cmprb                             (rtx, rtx, rtx);
extern rtx        gen_cmprb2                            (rtx, rtx, rtx);
extern rtx        gen_cmpeqb                            (rtx, rtx, rtx);
extern rtx        gen_mem_thread_fence                  (rtx);
extern rtx        gen_hwsync                            (void);
extern rtx        gen_lwsync                            (void);
extern rtx        gen_atomic_loadqi                     (rtx, rtx, rtx);
extern rtx        gen_atomic_loadhi                     (rtx, rtx, rtx);
extern rtx        gen_atomic_loadsi                     (rtx, rtx, rtx);
extern rtx        gen_atomic_loaddi                     (rtx, rtx, rtx);
extern rtx        gen_atomic_loadti                     (rtx, rtx, rtx);
extern rtx        gen_atomic_storeqi                    (rtx, rtx, rtx);
extern rtx        gen_atomic_storehi                    (rtx, rtx, rtx);
extern rtx        gen_atomic_storesi                    (rtx, rtx, rtx);
extern rtx        gen_atomic_storedi                    (rtx, rtx, rtx);
extern rtx        gen_atomic_storeti                    (rtx, rtx, rtx);
extern rtx        gen_load_lockedti                     (rtx, rtx);
extern rtx        gen_store_conditionalti               (rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapqi         (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swaphi         (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapsi         (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapdi         (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapti         (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangeqi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangehi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangesi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangedi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangeti                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_addqi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_subqi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_orqi                       (rtx, rtx, rtx);
extern rtx        gen_atomic_xorqi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_andqi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_addhi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_subhi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_orhi                       (rtx, rtx, rtx);
extern rtx        gen_atomic_xorhi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_andhi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_addsi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_subsi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_orsi                       (rtx, rtx, rtx);
extern rtx        gen_atomic_xorsi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_andsi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_adddi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_subdi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_ordi                       (rtx, rtx, rtx);
extern rtx        gen_atomic_xordi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_anddi                      (rtx, rtx, rtx);
extern rtx        gen_atomic_addti                      (rtx, rtx, rtx);
extern rtx        gen_atomic_subti                      (rtx, rtx, rtx);
extern rtx        gen_atomic_orti                       (rtx, rtx, rtx);
extern rtx        gen_atomic_xorti                      (rtx, rtx, rtx);
extern rtx        gen_atomic_andti                      (rtx, rtx, rtx);
extern rtx        gen_atomic_nandqi                     (rtx, rtx, rtx);
extern rtx        gen_atomic_nandhi                     (rtx, rtx, rtx);
extern rtx        gen_atomic_nandsi                     (rtx, rtx, rtx);
extern rtx        gen_atomic_nanddi                     (rtx, rtx, rtx);
extern rtx        gen_atomic_nandti                     (rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_addqi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_subqi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_orqi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_xorqi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_andqi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_addhi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_subhi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_orhi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_xorhi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_andhi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_addsi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_subsi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_orsi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_xorsi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_andsi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_adddi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_subdi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_ordi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_xordi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_anddi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_addti                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_subti                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_orti                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_xorti                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_andti                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_nandqi               (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_nandhi               (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_nandsi               (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_nanddi               (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_nandti               (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_add_fetchqi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_sub_fetchqi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_or_fetchqi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_xor_fetchqi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_and_fetchqi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_add_fetchhi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_sub_fetchhi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_or_fetchhi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_xor_fetchhi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_and_fetchhi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_add_fetchsi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_sub_fetchsi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_or_fetchsi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_xor_fetchsi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_and_fetchsi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_add_fetchdi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_sub_fetchdi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_or_fetchdi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_xor_fetchdi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_and_fetchdi                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_add_fetchti                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_sub_fetchti                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_or_fetchti                 (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_xor_fetchti                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_and_fetchti                (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_nand_fetchqi               (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_nand_fetchhi               (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_nand_fetchsi               (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_nand_fetchdi               (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_nand_fetchti               (rtx, rtx, rtx, rtx);
extern rtx        gen_movv16qi                          (rtx, rtx);
extern rtx        gen_movv8hi                           (rtx, rtx);
extern rtx        gen_movv4si                           (rtx, rtx);
extern rtx        gen_movv2di                           (rtx, rtx);
extern rtx        gen_movv4sf                           (rtx, rtx);
extern rtx        gen_movv2df                           (rtx, rtx);
extern rtx        gen_movv1ti                           (rtx, rtx);
extern rtx        gen_movkf                             (rtx, rtx);
extern rtx        gen_vector_load_v16qi                 (rtx, rtx);
extern rtx        gen_vector_load_v8hi                  (rtx, rtx);
extern rtx        gen_vector_load_v4si                  (rtx, rtx);
extern rtx        gen_vector_load_v2di                  (rtx, rtx);
extern rtx        gen_vector_load_v4sf                  (rtx, rtx);
extern rtx        gen_vector_load_v2df                  (rtx, rtx);
extern rtx        gen_vector_load_v1ti                  (rtx, rtx);
extern rtx        gen_vector_load_kf                    (rtx, rtx);
extern rtx        gen_vector_store_v16qi                (rtx, rtx);
extern rtx        gen_vector_store_v8hi                 (rtx, rtx);
extern rtx        gen_vector_store_v4si                 (rtx, rtx);
extern rtx        gen_vector_store_v2di                 (rtx, rtx);
extern rtx        gen_vector_store_v4sf                 (rtx, rtx);
extern rtx        gen_vector_store_v2df                 (rtx, rtx);
extern rtx        gen_vector_store_v1ti                 (rtx, rtx);
extern rtx        gen_vector_store_kf                   (rtx, rtx);
extern rtx        gen_addv4sf3                          (rtx, rtx, rtx);
extern rtx        gen_addv2df3                          (rtx, rtx, rtx);
extern rtx        gen_subv4sf3                          (rtx, rtx, rtx);
extern rtx        gen_subv2df3                          (rtx, rtx, rtx);
extern rtx        gen_mulv4sf3                          (rtx, rtx, rtx);
extern rtx        gen_mulv2df3                          (rtx, rtx, rtx);
extern rtx        gen_divv4sf3                          (rtx, rtx, rtx);
extern rtx        gen_divv2df3                          (rtx, rtx, rtx);
extern rtx        gen_negv4sf2                          (rtx, rtx);
extern rtx        gen_negv2df2                          (rtx, rtx);
extern rtx        gen_absv4sf2                          (rtx, rtx);
extern rtx        gen_absv2df2                          (rtx, rtx);
extern rtx        gen_sminv4sf3                         (rtx, rtx, rtx);
extern rtx        gen_sminv2df3                         (rtx, rtx, rtx);
extern rtx        gen_smaxv4sf3                         (rtx, rtx, rtx);
extern rtx        gen_smaxv2df3                         (rtx, rtx, rtx);
extern rtx        gen_sqrtv4sf2                         (rtx, rtx);
extern rtx        gen_sqrtv2df2                         (rtx, rtx);
extern rtx        gen_rsqrtev4sf2                       (rtx, rtx);
extern rtx        gen_rsqrtev2df2                       (rtx, rtx);
extern rtx        gen_rev4sf2                           (rtx, rtx);
extern rtx        gen_rev2df2                           (rtx, rtx);
extern rtx        gen_ftruncv4sf2                       (rtx, rtx);
extern rtx        gen_ftruncv2df2                       (rtx, rtx);
extern rtx        gen_vector_ceilv4sf2                  (rtx, rtx);
extern rtx        gen_vector_ceilv2df2                  (rtx, rtx);
extern rtx        gen_vector_floorv4sf2                 (rtx, rtx);
extern rtx        gen_vector_floorv2df2                 (rtx, rtx);
extern rtx        gen_vector_btruncv4sf2                (rtx, rtx);
extern rtx        gen_vector_btruncv2df2                (rtx, rtx);
extern rtx        gen_vector_copysignv4sf3              (rtx, rtx, rtx);
extern rtx        gen_vector_copysignv2df3              (rtx, rtx, rtx);
extern rtx        gen_vcondv4sfv4sf                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2dfv2df                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16qiv16qi                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8hiv8hi                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4siv4si                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2div2di                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4sfv4si                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4siv4sf                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2dfv2di                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2div2df                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16qiv16qi                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8hiv8hi                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4siv4si                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv2div2di                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4sfv4si                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv2dfv2di                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v16qiv16qi             (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v8hiv8hi               (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v4siv4si               (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v2div2di               (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v4sfv4si               (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v2dfv2di               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv16qiv16qi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv8hiv8hi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv4siv4si                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv2div2di                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv16qiv16qi                (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv8hiv8hi                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv4siv4si                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv2div2di                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv4sfv4si                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv2dfv2di                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_eqv16qi                    (rtx, rtx, rtx);
extern rtx        gen_vector_eqv8hi                     (rtx, rtx, rtx);
extern rtx        gen_vector_eqv4si                     (rtx, rtx, rtx);
extern rtx        gen_vector_eqv2di                     (rtx, rtx, rtx);
extern rtx        gen_vector_eqv4sf                     (rtx, rtx, rtx);
extern rtx        gen_vector_eqv2df                     (rtx, rtx, rtx);
extern rtx        gen_vector_eqv1ti                     (rtx, rtx, rtx);
extern rtx        gen_vector_gtv16qi                    (rtx, rtx, rtx);
extern rtx        gen_vector_gtv8hi                     (rtx, rtx, rtx);
extern rtx        gen_vector_gtv4si                     (rtx, rtx, rtx);
extern rtx        gen_vector_gtv2di                     (rtx, rtx, rtx);
extern rtx        gen_vector_gtv4sf                     (rtx, rtx, rtx);
extern rtx        gen_vector_gtv2df                     (rtx, rtx, rtx);
extern rtx        gen_vector_gtv1ti                     (rtx, rtx, rtx);
extern rtx        gen_vector_nltv16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_nltv8hi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_nltv4si                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_nltv2di                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_nltv1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_gtuv16qi                   (rtx, rtx, rtx);
extern rtx        gen_vector_gtuv8hi                    (rtx, rtx, rtx);
extern rtx        gen_vector_gtuv4si                    (rtx, rtx, rtx);
extern rtx        gen_vector_gtuv2di                    (rtx, rtx, rtx);
extern rtx        gen_vector_gtuv1ti                    (rtx, rtx, rtx);
extern rtx        gen_vector_nltuv16qi                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_nltuv8hi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_nltuv4si                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_nltuv2di                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_nltuv1ti                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_geuv16qi                   (rtx, rtx, rtx);
extern rtx        gen_vector_geuv8hi                    (rtx, rtx, rtx);
extern rtx        gen_vector_geuv4si                    (rtx, rtx, rtx);
extern rtx        gen_vector_geuv2di                    (rtx, rtx, rtx);
extern rtx        gen_vector_ngtv16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_ngtv8hi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_ngtv4si                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_ngtv2di                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_ngtv1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_ngtuv16qi                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_ngtuv8hi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_ngtuv4si                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_ngtuv2di                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_ngtuv1ti                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_gev4sf                     (rtx, rtx, rtx);
extern rtx        gen_vector_gev2df                     (rtx, rtx, rtx);
extern rtx        gen_vector_select_v16qi               (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v8hi                (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v4si                (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v2di                (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v4sf                (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v2df                (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v1ti                (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_ti                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_kf                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_tf                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v16qi_uns           (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v8hi_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v4si_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v2di_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v4sf_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v2df_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_v1ti_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_ti_uns              (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_kf_uns              (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_select_tf_uns              (rtx, rtx, rtx, rtx);
extern rtx        gen_vector_eq_v16qi_p                 (rtx, rtx, rtx);
extern rtx        gen_vector_eq_v8hi_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_eq_v4si_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_eq_v2di_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_eq_v4sf_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_eq_v2df_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_eq_v1ti_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ne_v4si_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ne_v8hi_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ne_v16qi_p                 (rtx, rtx, rtx);
extern rtx        gen_vector_ae_v4si_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ae_v8hi_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ae_v16qi_p                 (rtx, rtx, rtx);
extern rtx        gen_vector_nez_v4si_p                 (rtx, rtx, rtx);
extern rtx        gen_vector_nez_v8hi_p                 (rtx, rtx, rtx);
extern rtx        gen_vector_nez_v16qi_p                (rtx, rtx, rtx);
extern rtx        gen_vector_ne_v2di_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ne_v1ti_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ae_v2di_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ae_v1ti_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ne_v4sf_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ne_v2df_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ae_v4sf_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ae_v2df_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_gt_v16qi_p                 (rtx, rtx, rtx);
extern rtx        gen_vector_gt_v8hi_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_gt_v4si_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_gt_v2di_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_gt_v4sf_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_gt_v2df_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_gt_v1ti_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ge_v4sf_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_ge_v2df_p                  (rtx, rtx, rtx);
extern rtx        gen_vector_gtu_v16qi_p                (rtx, rtx, rtx);
extern rtx        gen_vector_gtu_v8hi_p                 (rtx, rtx, rtx);
extern rtx        gen_vector_gtu_v4si_p                 (rtx, rtx, rtx);
extern rtx        gen_vector_gtu_v2di_p                 (rtx, rtx, rtx);
extern rtx        gen_vector_gtu_v1ti_p                 (rtx, rtx, rtx);
extern rtx        gen_cr6_test_for_zero                 (rtx);
extern rtx        gen_cr6_test_for_zero_reverse         (rtx);
extern rtx        gen_cr6_test_for_lt                   (rtx);
extern rtx        gen_cr6_test_for_lt_reverse           (rtx);
extern rtx        gen_clzv16qi2                         (rtx, rtx);
extern rtx        gen_clzv8hi2                          (rtx, rtx);
extern rtx        gen_clzv4si2                          (rtx, rtx);
extern rtx        gen_clzv2di2                          (rtx, rtx);
extern rtx        gen_ctzv16qi2                         (rtx, rtx);
extern rtx        gen_ctzv8hi2                          (rtx, rtx);
extern rtx        gen_ctzv4si2                          (rtx, rtx);
extern rtx        gen_ctzv2di2                          (rtx, rtx);
extern rtx        gen_popcountv16qi2                    (rtx, rtx);
extern rtx        gen_popcountv8hi2                     (rtx, rtx);
extern rtx        gen_popcountv4si2                     (rtx, rtx);
extern rtx        gen_popcountv2di2                     (rtx, rtx);
extern rtx        gen_parityv8hi2                       (rtx, rtx);
extern rtx        gen_parityv4si2                       (rtx, rtx);
extern rtx        gen_parityv2di2                       (rtx, rtx);
extern rtx        gen_parityv1ti2                       (rtx, rtx);
extern rtx        gen_parityti2                         (rtx, rtx);
extern rtx        gen_floatv4siv4sf2                    (rtx, rtx);
extern rtx        gen_floatv2div2df2                    (rtx, rtx);
extern rtx        gen_floatunsv4siv4sf2                 (rtx, rtx);
extern rtx        gen_floatunsv2div2df2                 (rtx, rtx);
extern rtx        gen_fix_truncv4sfv4si2                (rtx, rtx);
extern rtx        gen_fix_truncv2dfv2di2                (rtx, rtx);
extern rtx        gen_fixuns_truncv4sfv4si2             (rtx, rtx);
extern rtx        gen_fixuns_truncv2dfv2di2             (rtx, rtx);
extern rtx        gen_vec_initv16qiqi                   (rtx, rtx);
extern rtx        gen_vec_initv8hihi                    (rtx, rtx);
extern rtx        gen_vec_initv4sisi                    (rtx, rtx);
extern rtx        gen_vec_initv2didi                    (rtx, rtx);
extern rtx        gen_vec_initv4sfsf                    (rtx, rtx);
extern rtx        gen_vec_initv2dfdf                    (rtx, rtx);
extern rtx        gen_vec_setv16qi                      (rtx, rtx, rtx);
extern rtx        gen_vec_setv8hi                       (rtx, rtx, rtx);
extern rtx        gen_vec_setv4si                       (rtx, rtx, rtx);
extern rtx        gen_vec_setv2di                       (rtx, rtx, rtx);
extern rtx        gen_vec_setv4sf                       (rtx, rtx, rtx);
extern rtx        gen_vec_setv2df                       (rtx, rtx, rtx);
extern rtx        gen_vec_extractv16qiqi                (rtx, rtx, rtx);
extern rtx        gen_vec_extractv8hihi                 (rtx, rtx, rtx);
extern rtx        gen_vec_extractv4sisi                 (rtx, rtx, rtx);
extern rtx        gen_vec_extractv2didi                 (rtx, rtx, rtx);
extern rtx        gen_vec_extractv4sfsf                 (rtx, rtx, rtx);
extern rtx        gen_vec_extractv2dfdf                 (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v2df               (rtx, rtx, rtx);
extern rtx        gen_vec_pack_sfix_trunc_v2df          (rtx, rtx, rtx);
extern rtx        gen_vec_pack_ufix_trunc_v2df          (rtx, rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v4sf               (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v4sf               (rtx, rtx);
extern rtx        gen_vec_unpacks_float_hi_v4si         (rtx, rtx);
extern rtx        gen_vec_unpacks_float_lo_v4si         (rtx, rtx);
extern rtx        gen_vec_unpacku_float_hi_v4si         (rtx, rtx);
extern rtx        gen_vec_unpacku_float_lo_v4si         (rtx, rtx);
extern rtx        gen_vec_realign_load_v16qi            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_realign_load_v8hi             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_realign_load_v4si             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_realign_load_v4sf             (rtx, rtx, rtx, rtx);
extern rtx        gen_movmisalignv4si                   (rtx, rtx);
extern rtx        gen_movmisalignv4sf                   (rtx, rtx);
extern rtx        gen_movmisalignv2di                   (rtx, rtx);
extern rtx        gen_movmisalignv2df                   (rtx, rtx);
extern rtx        gen_movmisalignv1ti                   (rtx, rtx);
extern rtx        gen_movmisalignkf                     (rtx, rtx);
extern rtx        gen_movmisaligntf                     (rtx, rtx);
extern rtx        gen_vec_shr_v16qi                     (rtx, rtx, rtx);
extern rtx        gen_vec_shr_v8hi                      (rtx, rtx, rtx);
extern rtx        gen_vec_shr_v4si                      (rtx, rtx, rtx);
extern rtx        gen_vec_shr_v2di                      (rtx, rtx, rtx);
extern rtx        gen_vec_shr_v4sf                      (rtx, rtx, rtx);
extern rtx        gen_vec_shr_v2df                      (rtx, rtx, rtx);
extern rtx        gen_vec_shr_v1ti                      (rtx, rtx, rtx);
extern rtx        gen_vec_shr_ti                        (rtx, rtx, rtx);
extern rtx        gen_vec_shr_kf                        (rtx, rtx, rtx);
extern rtx        gen_vec_shr_tf                        (rtx, rtx, rtx);
extern rtx        gen_vrotlv16qi3                       (rtx, rtx, rtx);
extern rtx        gen_vrotlv8hi3                        (rtx, rtx, rtx);
extern rtx        gen_vrotlv4si3                        (rtx, rtx, rtx);
extern rtx        gen_vrotlv2di3                        (rtx, rtx, rtx);
extern rtx        gen_vrotlv1ti3                        (rtx, rtx, rtx);
extern rtx        gen_vrotrv16qi3                       (rtx, rtx, rtx);
extern rtx        gen_vrotrv8hi3                        (rtx, rtx, rtx);
extern rtx        gen_vrotrv4si3                        (rtx, rtx, rtx);
extern rtx        gen_vrotrv2di3                        (rtx, rtx, rtx);
extern rtx        gen_vashlv16qi3                       (rtx, rtx, rtx);
extern rtx        gen_vashlv8hi3                        (rtx, rtx, rtx);
extern rtx        gen_vashlv4si3                        (rtx, rtx, rtx);
extern rtx        gen_vashlv2di3                        (rtx, rtx, rtx);
extern rtx        gen_vashlv1ti3                        (rtx, rtx, rtx);
extern rtx        gen_vashlti3                          (rtx, rtx, rtx);
extern rtx        gen_vlshrv16qi3                       (rtx, rtx, rtx);
extern rtx        gen_vlshrv8hi3                        (rtx, rtx, rtx);
extern rtx        gen_vlshrv4si3                        (rtx, rtx, rtx);
extern rtx        gen_vlshrv2di3                        (rtx, rtx, rtx);
extern rtx        gen_vlshrv1ti3                        (rtx, rtx, rtx);
extern rtx        gen_vlshrti3                          (rtx, rtx, rtx);
extern rtx        gen_vashrv16qi3                       (rtx, rtx, rtx);
extern rtx        gen_vashrv8hi3                        (rtx, rtx, rtx);
extern rtx        gen_vashrv4si3                        (rtx, rtx, rtx);
extern rtx        gen_vashrv2di3                        (rtx, rtx, rtx);
extern rtx        gen_vashrv1ti3                        (rtx, rtx, rtx);
extern rtx        gen_reduc_plus_scal_v4sf              (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v4sf              (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v4sf              (rtx, rtx);
extern rtx        gen_reduc_plus_scal_v2df              (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v2df              (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v2df              (rtx, rtx);
extern rtx        gen_vsx_load_v16qi                    (rtx, rtx);
extern rtx        gen_vsx_load_v8hi                     (rtx, rtx);
extern rtx        gen_vsx_load_v4si                     (rtx, rtx);
extern rtx        gen_vsx_load_v2di                     (rtx, rtx);
extern rtx        gen_vsx_load_v4sf                     (rtx, rtx);
extern rtx        gen_vsx_load_v2df                     (rtx, rtx);
extern rtx        gen_vsx_load_v1ti                     (rtx, rtx);
extern rtx        gen_vsx_load_kf                       (rtx, rtx);
extern rtx        gen_vsx_load_tf                       (rtx, rtx);
extern rtx        gen_vsx_load_ti                       (rtx, rtx);
extern rtx        gen_vsx_store_v16qi                   (rtx, rtx);
extern rtx        gen_vsx_store_v8hi                    (rtx, rtx);
extern rtx        gen_vsx_store_v4si                    (rtx, rtx);
extern rtx        gen_vsx_store_v2di                    (rtx, rtx);
extern rtx        gen_vsx_store_v4sf                    (rtx, rtx);
extern rtx        gen_vsx_store_v2df                    (rtx, rtx);
extern rtx        gen_vsx_store_v1ti                    (rtx, rtx);
extern rtx        gen_vsx_store_kf                      (rtx, rtx);
extern rtx        gen_vsx_store_tf                      (rtx, rtx);
extern rtx        gen_vsx_store_ti                      (rtx, rtx);
extern rtx        gen_vsx_ld_elemrev_v8hi               (rtx, rtx);
extern rtx        gen_vsx_ld_elemrev_v16qi              (rtx, rtx);
extern rtx        gen_vsx_st_elemrev_v8hi               (rtx, rtx);
extern rtx        gen_vsx_st_elemrev_v16qi              (rtx, rtx);
extern rtx        gen_vsx_tdivdf3_fg                    (rtx, rtx, rtx);
extern rtx        gen_vsx_tdivv4sf3_fg                  (rtx, rtx, rtx);
extern rtx        gen_vsx_tdivv2df3_fg                  (rtx, rtx, rtx);
extern rtx        gen_vsx_tdivdf3_fe                    (rtx, rtx, rtx);
extern rtx        gen_vsx_tdivv4sf3_fe                  (rtx, rtx, rtx);
extern rtx        gen_vsx_tdivv2df3_fe                  (rtx, rtx, rtx);
extern rtx        gen_vsx_tsqrtdf2_fg                   (rtx, rtx);
extern rtx        gen_vsx_tsqrtv4sf2_fg                 (rtx, rtx);
extern rtx        gen_vsx_tsqrtv2df2_fg                 (rtx, rtx);
extern rtx        gen_vsx_tsqrtdf2_fe                   (rtx, rtx);
extern rtx        gen_vsx_tsqrtv4sf2_fe                 (rtx, rtx);
extern rtx        gen_vsx_tsqrtv2df2_fe                 (rtx, rtx);
extern rtx        gen_xvtlsbbo                          (rtx, rtx);
extern rtx        gen_xvtlsbbz                          (rtx, rtx);
extern rtx        gen_vsx_xvcvspdp                      (rtx, rtx);
extern rtx        gen_vsx_xvcvsxddp_scale               (rtx, rtx, rtx);
extern rtx        gen_vsx_xvcvuxddp_scale               (rtx, rtx, rtx);
extern rtx        gen_vsx_xvcvdpsxds_scale              (rtx, rtx, rtx);
extern rtx        gen_vsx_xvcvdpuxds_scale              (rtx, rtx, rtx);
extern rtx        gen_vsx_xvcvsxwdp                     (rtx, rtx);
extern rtx        gen_vsx_xvcvuxwdp                     (rtx, rtx);
extern rtx        gen_vsx_xvcvspsxds                    (rtx, rtx);
extern rtx        gen_vsx_xvcvspuxds                    (rtx, rtx);
extern rtx        gen_float2_v2df                       (rtx, rtx, rtx);
extern rtx        gen_float2_v2di                       (rtx, rtx, rtx);
extern rtx        gen_uns_float2_v2di                   (rtx, rtx, rtx);
extern rtx        gen_floatev2df                        (rtx, rtx);
extern rtx        gen_floatev2di                        (rtx, rtx);
extern rtx        gen_unsfloatev2di                     (rtx, rtx);
extern rtx        gen_floatov2df                        (rtx, rtx);
extern rtx        gen_floatov2di                        (rtx, rtx);
extern rtx        gen_unsfloatov2di                     (rtx, rtx);
extern rtx        gen_vsigned2_v2df                     (rtx, rtx, rtx);
extern rtx        gen_vsignedo_v2df                     (rtx, rtx);
extern rtx        gen_vsignede_v2df                     (rtx, rtx);
extern rtx        gen_vunsigned2_v2df                   (rtx, rtx, rtx);
extern rtx        gen_vunsignedo_v2df                   (rtx, rtx);
extern rtx        gen_vunsignede_v2df                   (rtx, rtx);
extern rtx        gen_vsx_init_v4si                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xxgenpcvm_v16qi                   (rtx, rtx, rtx);
extern rtx        gen_xxgenpcvm_v8hi                    (rtx, rtx, rtx);
extern rtx        gen_xxgenpcvm_v4si                    (rtx, rtx, rtx);
extern rtx        gen_xxgenpcvm_v2di                    (rtx, rtx, rtx);
extern rtx        gen_vsx_set_v1ti                      (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_set_v2df                      (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_set_v2di                      (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v16qi                (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v8hi                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v4si                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v2di                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v4sf                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v2df                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v1ti                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_ti                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_kf                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_tf                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v16qi_be             (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v8hi_be              (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v4si_be              (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v2di_be              (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v4sf_be              (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v2df_be              (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_v1ti_be              (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_ti_be                (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_kf_be                (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_xxpermdi_tf_be                (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v16qi                 (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v8hi                  (rtx, rtx, rtx);
extern rtx        gen_vsx_extract_v4si                  (rtx, rtx, rtx);
extern rtx        gen_vextractlv4si                     (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractlv8hi                     (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractlv16qi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractlv2di                     (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractrv4si                     (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractrv8hi                     (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractrv16qi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vextractrv2di                     (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvl_v4si                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvl_v8hi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvl_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvl_v2di                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvr_v4si                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvr_v8hi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvr_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertvr_v2di                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgl_v4si                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgl_v8hi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgl_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgl_v2di                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgr_v4si                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgr_v8hi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgr_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vinsertgr_v2di                    (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_elt_v4si                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_elt_v4sf                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_elt_v2di                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_elt_v2df                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_un_v4si                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_un_v4sf                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_un_v2di                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vreplace_un_v2df                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vsx_mergel_v2df                   (rtx, rtx, rtx);
extern rtx        gen_vsx_mergel_v2di                   (rtx, rtx, rtx);
extern rtx        gen_vsx_mergeh_v2df                   (rtx, rtx, rtx);
extern rtx        gen_vsx_mergeh_v2di                   (rtx, rtx, rtx);
extern rtx        gen_vsx_splat_v2df                    (rtx, rtx);
extern rtx        gen_vsx_splat_v2di                    (rtx, rtx);
extern rtx        gen_vsignextend_v2di_v1ti             (rtx, rtx);
extern rtx        gen_vsignextend_qi_v2di               (rtx, rtx);
extern rtx        gen_vsignextend_qi_v4si               (rtx, rtx);
extern rtx        gen_vsignextend_hi_v2di               (rtx, rtx);
extern rtx        gen_vsignextend_hi_v4si               (rtx, rtx);
extern rtx        gen_vsignextend_si_v2di               (rtx, rtx);
extern rtx        gen_extendditi2                       (rtx, rtx);
extern rtx        gen_xscmpexpdp_eq                     (rtx, rtx, rtx);
extern rtx        gen_xscmpexpdp_lt                     (rtx, rtx, rtx);
extern rtx        gen_xscmpexpdp_gt                     (rtx, rtx, rtx);
extern rtx        gen_xscmpexpdp_unordered              (rtx, rtx, rtx);
extern rtx        gen_xscmpexpqp_eq_kf                  (rtx, rtx, rtx);
extern rtx        gen_xscmpexpqp_lt_kf                  (rtx, rtx, rtx);
extern rtx        gen_xscmpexpqp_gt_kf                  (rtx, rtx, rtx);
extern rtx        gen_xscmpexpqp_unordered_kf           (rtx, rtx, rtx);
extern rtx        gen_xscmpexpqp_eq_tf                  (rtx, rtx, rtx);
extern rtx        gen_xscmpexpqp_lt_tf                  (rtx, rtx, rtx);
extern rtx        gen_xscmpexpqp_gt_tf                  (rtx, rtx, rtx);
extern rtx        gen_xscmpexpqp_unordered_tf           (rtx, rtx, rtx);
extern rtx        gen_xststdcqp_kf                      (rtx, rtx, rtx);
extern rtx        gen_xststdcqp_tf                      (rtx, rtx, rtx);
extern rtx        gen_xststdcsp                         (rtx, rtx, rtx);
extern rtx        gen_xststdcdp                         (rtx, rtx, rtx);
extern rtx        gen_xststdcnegqp_kf                   (rtx, rtx);
extern rtx        gen_xststdcnegqp_tf                   (rtx, rtx);
extern rtx        gen_xststdcnegsp                      (rtx, rtx);
extern rtx        gen_xststdcnegdp                      (rtx, rtx);
extern rtx        gen_first_match_index_v16qi           (rtx, rtx, rtx);
extern rtx        gen_first_match_index_v8hi            (rtx, rtx, rtx);
extern rtx        gen_first_match_index_v4si            (rtx, rtx, rtx);
extern rtx        gen_first_match_or_eos_index_v16qi    (rtx, rtx, rtx);
extern rtx        gen_first_match_or_eos_index_v8hi     (rtx, rtx, rtx);
extern rtx        gen_first_match_or_eos_index_v4si     (rtx, rtx, rtx);
extern rtx        gen_first_mismatch_index_v16qi        (rtx, rtx, rtx);
extern rtx        gen_first_mismatch_index_v8hi         (rtx, rtx, rtx);
extern rtx        gen_first_mismatch_index_v4si         (rtx, rtx, rtx);
extern rtx        gen_first_mismatch_or_eos_index_v16qi (rtx, rtx, rtx);
extern rtx        gen_first_mismatch_or_eos_index_v8hi  (rtx, rtx, rtx);
extern rtx        gen_first_mismatch_or_eos_index_v4si  (rtx, rtx, rtx);
extern rtx        gen_lxvl                              (rtx, rtx, rtx);
extern rtx        gen_xl_len_r                          (rtx, rtx, rtx);
extern rtx        gen_stxvl                             (rtx, rtx, rtx);
extern rtx        gen_len_load_v16qi                    (rtx, rtx, rtx);
extern rtx        gen_len_store_v16qi                   (rtx, rtx, rtx);
extern rtx        gen_xst_len_r                         (rtx, rtx, rtx);
extern rtx        gen_vcmpnet                           (rtx, rtx, rtx);
extern rtx        gen_insert4b                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vextract_fp_from_shorth           (rtx, rtx);
extern rtx        gen_vextract_fp_from_shortl           (rtx, rtx);
extern rtx        gen_p9_xxbrq_v16qi                    (rtx, rtx);
extern rtx        gen_p9_xxbrd_v2df                     (rtx, rtx);
extern rtx        gen_p9_xxbrw_v4sf                     (rtx, rtx);
extern rtx        gen_revb_v8hi                         (rtx, rtx);
extern rtx        gen_revb_v4si                         (rtx, rtx);
extern rtx        gen_revb_v2di                         (rtx, rtx);
extern rtx        gen_revb_v4sf                         (rtx, rtx);
extern rtx        gen_revb_v2df                         (rtx, rtx);
extern rtx        gen_revb_v1ti                         (rtx, rtx);
extern rtx        gen_revb_v16qi                        (rtx, rtx);
extern rtx        gen_vec_packs_float_v2di              (rtx, rtx, rtx);
extern rtx        gen_vec_packu_float_v2di              (rtx, rtx, rtx);
extern rtx        gen_vec_unpack_sfix_trunc_hi_v4sf     (rtx, rtx);
extern rtx        gen_vec_unpack_ufix_trunc_hi_v4sf     (rtx, rtx);
extern rtx        gen_vec_unpack_sfix_trunc_lo_v4sf     (rtx, rtx);
extern rtx        gen_vec_unpack_ufix_trunc_lo_v4sf     (rtx, rtx);
extern rtx        gen_altivec_mulv4sf3                  (rtx, rtx, rtx);
extern rtx        gen_mulv4si3                          (rtx, rtx, rtx);
extern rtx        gen_mulv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_xxspltiw_v4sf                     (rtx, rtx);
extern rtx        gen_xxspltidp_v2df                    (rtx, rtx);
extern rtx        gen_xxsplti32dx_v4si                  (rtx, rtx, rtx, rtx);
extern rtx        gen_xxsplti32dx_v4sf                  (rtx, rtx, rtx, rtx);
extern rtx        gen_xxpermx                           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vstrir_v8hi                       (rtx, rtx);
extern rtx        gen_vstrir_v16qi                      (rtx, rtx);
extern rtx        gen_vstrir_p_v8hi                     (rtx, rtx);
extern rtx        gen_vstrir_p_v16qi                    (rtx, rtx);
extern rtx        gen_vstril_v8hi                       (rtx, rtx);
extern rtx        gen_vstril_v16qi                      (rtx, rtx);
extern rtx        gen_vstril_p_v8hi                     (rtx, rtx);
extern rtx        gen_vstril_p_v16qi                    (rtx, rtx);
extern rtx        gen_altivec_vmrghb                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vmrghh                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vmrghw                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vmrglb                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vmrglh                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vmrglw                    (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgew_v2df                    (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgew_v2di                    (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgow_v2df                    (rtx, rtx, rtx);
extern rtx        gen_p8_vmrgow_v2di                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_even_v16qi        (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_even_v16qi        (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_even_v8hi         (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_even_v8hi         (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_even_v4si         (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_even_v2di         (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_even_v4si         (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_even_v2di         (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_odd_v16qi         (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_odd_v16qi         (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_odd_v8hi          (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_odd_v8hi          (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_odd_v4si          (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_odd_v2di          (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_odd_v4si          (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_odd_v2di          (rtx, rtx, rtx);
extern rtx        gen_altivec_vrlqmi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vrlqnm                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vsum2sws                  (rtx, rtx, rtx);
extern rtx        gen_altivec_vsumsws                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vspltb                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vsplth                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vspltw                    (rtx, rtx, rtx);
extern rtx        gen_altivec_vspltsf                   (rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v4si                (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v8hi                (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v16qi               (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v4sf                (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v2df                (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v2di                (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v1ti                (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_ti                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_kf                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_tf                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v4si_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v8hi_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v16qi_uns           (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v4sf_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v2df_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v2di_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_v1ti_uns            (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_ti_uns              (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_kf_uns              (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_vperm_tf_uns              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv16qi                     (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_copysign_v4sf3            (rtx, rtx, rtx);
extern rtx        gen_altivec_lvsl                      (rtx, rtx);
extern rtx        gen_altivec_lvsr                      (rtx, rtx);
extern rtx        gen_build_vector_mask_for_load        (rtx, rtx);
extern rtx        gen_altivec_lvx_v4si                  (rtx, rtx);
extern rtx        gen_altivec_lvx_v8hi                  (rtx, rtx);
extern rtx        gen_altivec_lvx_v16qi                 (rtx, rtx);
extern rtx        gen_altivec_lvx_v4sf                  (rtx, rtx);
extern rtx        gen_altivec_lvx_v2df                  (rtx, rtx);
extern rtx        gen_altivec_lvx_v2di                  (rtx, rtx);
extern rtx        gen_altivec_lvx_v1ti                  (rtx, rtx);
extern rtx        gen_altivec_lvx_kf                    (rtx, rtx);
extern rtx        gen_altivec_lvx_tf                    (rtx, rtx);
extern rtx        gen_altivec_stvx_v4si                 (rtx, rtx);
extern rtx        gen_altivec_stvx_v8hi                 (rtx, rtx);
extern rtx        gen_altivec_stvx_v16qi                (rtx, rtx);
extern rtx        gen_altivec_stvx_v4sf                 (rtx, rtx);
extern rtx        gen_altivec_stvx_v2df                 (rtx, rtx);
extern rtx        gen_altivec_stvx_v2di                 (rtx, rtx);
extern rtx        gen_altivec_stvx_v1ti                 (rtx, rtx);
extern rtx        gen_altivec_stvx_kf                   (rtx, rtx);
extern rtx        gen_altivec_stvx_tf                   (rtx, rtx);
extern rtx        gen_doubleev4sf2                      (rtx, rtx);
extern rtx        gen_doubleev4si2                      (rtx, rtx);
extern rtx        gen_unsdoubleev4si2                   (rtx, rtx);
extern rtx        gen_doubleov4sf2                      (rtx, rtx);
extern rtx        gen_doubleov4si2                      (rtx, rtx);
extern rtx        gen_unsdoubleov4si2                   (rtx, rtx);
extern rtx        gen_doublehv4sf2                      (rtx, rtx);
extern rtx        gen_doublehv4si2                      (rtx, rtx);
extern rtx        gen_unsdoublehv4si2                   (rtx, rtx);
extern rtx        gen_doublelv4sf2                      (rtx, rtx);
extern rtx        gen_doublelv4si2                      (rtx, rtx);
extern rtx        gen_unsdoublelv4si2                   (rtx, rtx);
extern rtx        gen_convert_4f32_8i16                 (rtx, rtx, rtx);
extern rtx        gen_convert_4f32_8f16                 (rtx, rtx, rtx);
extern rtx        gen_absv4si2                          (rtx, rtx);
extern rtx        gen_absv8hi2                          (rtx, rtx);
extern rtx        gen_absv16qi2                         (rtx, rtx);
extern rtx        gen_absv2di2                          (rtx, rtx);
extern rtx        gen_nabsv4si2                         (rtx, rtx);
extern rtx        gen_nabsv8hi2                         (rtx, rtx);
extern rtx        gen_nabsv16qi2                        (rtx, rtx);
extern rtx        gen_nabsv2di2                         (rtx, rtx);
extern rtx        gen_altivec_absv4sf2                  (rtx, rtx);
extern rtx        gen_altivec_abss_v4si                 (rtx, rtx);
extern rtx        gen_altivec_abss_v8hi                 (rtx, rtx);
extern rtx        gen_altivec_abss_v16qi                (rtx, rtx);
extern rtx        gen_reduc_plus_scal_v8hi              (rtx, rtx);
extern rtx        gen_reduc_plus_scal_v16qi             (rtx, rtx);
extern rtx        gen_negv4si2                          (rtx, rtx);
extern rtx        gen_negv8hi2                          (rtx, rtx);
extern rtx        gen_negv16qi2                         (rtx, rtx);
extern rtx        gen_negv2di2                          (rtx, rtx);
extern rtx        gen_udot_prodv8hi                     (rtx, rtx, rtx, rtx);
extern rtx        gen_udot_prodv16qi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sdot_prodv8hi                     (rtx, rtx, rtx, rtx);
extern rtx        gen_widen_usumv8hi3                   (rtx, rtx, rtx);
extern rtx        gen_widen_usumv16qi3                  (rtx, rtx, rtx);
extern rtx        gen_widen_ssumv16qi3                  (rtx, rtx, rtx);
extern rtx        gen_widen_ssumv8hi3                   (rtx, rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v4si               (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v8hi               (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v16qi              (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v4si               (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v8hi               (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v16qi              (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v16qi              (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v8hi               (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v16qi              (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v8hi               (rtx, rtx);
extern rtx        gen_vec_widen_umult_hi_v16qi          (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_lo_v16qi          (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_hi_v16qi          (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_lo_v16qi          (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_hi_v8hi           (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_lo_v8hi           (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_hi_v8hi           (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_lo_v8hi           (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v2di               (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v4si               (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v8hi               (rtx, rtx, rtx);
extern rtx        gen_mulv16qi3                         (rtx, rtx, rtx);
extern rtx        gen_altivec_vpermxor                  (rtx, rtx, rtx, rtx);
extern rtx        gen_altivec_negv4sf2                  (rtx, rtx);
extern rtx        gen_altivec_vreveti2                  (rtx, rtx);
extern rtx        gen_altivec_vrevev16qi2               (rtx, rtx);
extern rtx        gen_altivec_vrevev8hi2                (rtx, rtx);
extern rtx        gen_altivec_vrevev4si2                (rtx, rtx);
extern rtx        gen_altivec_vrevev2di2                (rtx, rtx);
extern rtx        gen_altivec_vrevev4sf2                (rtx, rtx);
extern rtx        gen_altivec_vrevev2df2                (rtx, rtx);
extern rtx        gen_vec_unpacks_float_hi_v8hi         (rtx, rtx);
extern rtx        gen_vec_unpacks_float_lo_v8hi         (rtx, rtx);
extern rtx        gen_vec_unpacku_float_hi_v8hi         (rtx, rtx);
extern rtx        gen_vec_unpacku_float_lo_v8hi         (rtx, rtx);
extern rtx        gen_vaduv4si3                         (rtx, rtx, rtx);
extern rtx        gen_vaduv8hi3                         (rtx, rtx, rtx);
extern rtx        gen_vaduv16qi3                        (rtx, rtx, rtx);
extern rtx        gen_usadv16qi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_usadv8hi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_eq_v1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_eq_v1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_lt_v1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_lt_v1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_le_v1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_le_v1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_gt_v1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_gt_v1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_ge_v1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_ge_v1ti                    (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_unordered_v1ti             (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_unordered_v1ti             (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_eq_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_eq_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_lt_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_lt_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_le_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_le_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_gt_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_gt_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_ge_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_ge_v16qi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdadd_unordered_v16qi            (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdsub_unordered_v16qi            (rtx, rtx, rtx, rtx);
extern rtx        gen_bcdinvalid_v1ti                   (rtx, rtx);
extern rtx        gen_bcdinvalid_v16qi                  (rtx, rtx);
extern rtx        gen_bcdmul10_v16qi                    (rtx, rtx);
extern rtx        gen_bcddiv10_v16qi                    (rtx, rtx);
extern rtx        gen_movoo                             (rtx, rtx);
extern rtx        gen_movxo                             (rtx, rtx);
extern rtx        gen_vsx_assemble_pair                 (rtx, rtx, rtx);
extern rtx        gen_vsx_disassemble_pair              (rtx, rtx, rtx);
extern rtx        gen_mma_assemble_acc                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mma_disassemble_acc               (rtx, rtx, rtx);
extern rtx        gen_mma_xxsetaccz                     (rtx);
extern rtx        gen_extendsdtd2                       (rtx, rtx);
extern rtx        gen_dfp_denbcd_v16qi                  (rtx, rtx);
extern rtx        gen_dfptstsfi_eq_dd                   (rtx, rtx, rtx);
extern rtx        gen_dfptstsfi_lt_dd                   (rtx, rtx, rtx);
extern rtx        gen_dfptstsfi_gt_dd                   (rtx, rtx, rtx);
extern rtx        gen_dfptstsfi_unordered_dd            (rtx, rtx, rtx);
extern rtx        gen_dfptstsfi_eq_td                   (rtx, rtx, rtx);
extern rtx        gen_dfptstsfi_lt_td                   (rtx, rtx, rtx);
extern rtx        gen_dfptstsfi_gt_td                   (rtx, rtx, rtx);
extern rtx        gen_dfptstsfi_unordered_td            (rtx, rtx, rtx);
extern rtx        gen_tabort                            (rtx, rtx);
extern rtx        gen_tabortwc                          (rtx, rtx, rtx, rtx);
extern rtx        gen_tabortdc                          (rtx, rtx, rtx, rtx);
extern rtx        gen_tabortwci                         (rtx, rtx, rtx, rtx);
extern rtx        gen_tabortdci                         (rtx, rtx, rtx, rtx);
extern rtx        gen_tbegin                            (rtx, rtx);
extern rtx        gen_tcheck                            (rtx);
extern rtx        gen_tend                              (rtx, rtx);
extern rtx        gen_trechkpt                          (rtx);
extern rtx        gen_treclaim                          (rtx, rtx);
extern rtx        gen_tsr                               (rtx, rtx);
extern rtx        gen_ttest                             (rtx);

#endif /* GCC_INSN_FLAGS_H */
