/* Generated automatically by the program 'build/genpreds'
   from the machine description file '/work/pkgsrc/cross/ppc-morphos-gcc-11/work/sdk-source/gcc11/gcc-11.2.0/gcc/config/rs6000/rs6000.md'.  */

#ifndef GCC_TM_PREDS_H
#define GCC_TM_PREDS_H

#ifdef HAVE_MACHINE_MODES
extern int general_operand (rtx, machine_mode);
extern int address_operand (rtx, machine_mode);
extern int register_operand (rtx, machine_mode);
extern int pmode_register_operand (rtx, machine_mode);
extern int scratch_operand (rtx, machine_mode);
extern int immediate_operand (rtx, machine_mode);
extern int const_int_operand (rtx, machine_mode);
extern int const_scalar_int_operand (rtx, machine_mode);
extern int const_double_operand (rtx, machine_mode);
extern int nonimmediate_operand (rtx, machine_mode);
extern int nonmemory_operand (rtx, machine_mode);
extern int push_operand (rtx, machine_mode);
extern int pop_operand (rtx, machine_mode);
extern int memory_operand (rtx, machine_mode);
extern int indirect_operand (rtx, machine_mode);
extern int ordered_comparison_operator (rtx, machine_mode);
extern int comparison_operator (rtx, machine_mode);
extern int any_operand (rtx, machine_mode);
extern int any_parallel_operand (rtx, machine_mode);
extern int count_register_operand (rtx, machine_mode);
extern int sf_subreg_operand (rtx, machine_mode);
extern int altivec_register_operand (rtx, machine_mode);
extern int vsx_register_operand (rtx, machine_mode);
extern int vsx_reg_sfsubreg_ok (rtx, machine_mode);
extern int vfloat_operand (rtx, machine_mode);
extern int vint_operand (rtx, machine_mode);
extern int vlogical_operand (rtx, machine_mode);
extern int ca_operand (rtx, machine_mode);
extern int zero_constant (rtx, machine_mode);
extern int all_ones_constant (rtx, machine_mode);
extern int s5bit_cint_operand (rtx, machine_mode);
extern int u1bit_cint_operand (rtx, machine_mode);
extern int u3bit_cint_operand (rtx, machine_mode);
extern int u5bit_cint_operand (rtx, machine_mode);
extern int u6bit_cint_operand (rtx, machine_mode);
extern int u7bit_cint_operand (rtx, machine_mode);
extern int u8bit_cint_operand (rtx, machine_mode);
extern int s8bit_cint_operand (rtx, machine_mode);
extern int u10bit_cint_operand (rtx, machine_mode);
extern int short_cint_operand (rtx, machine_mode);
extern int u_short_cint_operand (rtx, machine_mode);
extern int upper16_cint_operand (rtx, machine_mode);
extern int non_short_cint_operand (rtx, machine_mode);
extern int s32bit_cint_operand (rtx, machine_mode);
extern int c32bit_cint_operand (rtx, machine_mode);
extern int exact_log2_cint_operand (rtx, machine_mode);
extern int const_0_to_1_operand (rtx, machine_mode);
extern int const_m1_to_1_operand (rtx, machine_mode);
extern int const_0_to_3_operand (rtx, machine_mode);
extern int const_2_to_3_operand (rtx, machine_mode);
extern int const_0_to_7_operand (rtx, machine_mode);
extern int const_0_to_12_operand (rtx, machine_mode);
extern int const_0_to_15_operand (rtx, machine_mode);
extern int cint34_operand (rtx, machine_mode);
extern int gpc_reg_operand (rtx, machine_mode);
extern int int_reg_operand (rtx, machine_mode);
extern int int_reg_operand_not_pseudo (rtx, machine_mode);
extern int base_reg_operand (rtx, machine_mode);
extern int fpr_reg_operand (rtx, machine_mode);
extern int quad_int_reg_operand (rtx, machine_mode);
extern int cc_reg_operand (rtx, machine_mode);
extern int cc_reg_not_cr0_operand (rtx, machine_mode);
extern int reg_or_short_operand (rtx, machine_mode);
extern int reg_or_aligned_short_operand (rtx, machine_mode);
extern int reg_or_u_short_operand (rtx, machine_mode);
extern int reg_or_cint_operand (rtx, machine_mode);
extern int reg_or_zero_operand (rtx, machine_mode);
extern int add_cint_operand (rtx, machine_mode);
extern int reg_or_add_cint_operand (rtx, machine_mode);
extern int reg_or_sub_cint_operand (rtx, machine_mode);
extern int reg_or_logical_cint_operand (rtx, machine_mode);
extern int vsx_reg_or_cint_operand (rtx, machine_mode);
extern int easy_fp_constant (rtx, machine_mode);
extern int xxspltib_constant_split (rtx, machine_mode);
extern int xxspltib_constant_nosplit (rtx, machine_mode);
extern int easy_vector_constant (rtx, machine_mode);
extern int easy_vector_constant_add_self (rtx, machine_mode);
extern int easy_vector_constant_msb (rtx, machine_mode);
extern int easy_vector_constant_vsldoi (rtx, machine_mode);
extern int vector_int_reg_or_same_bit (rtx, machine_mode);
extern int zero_fp_constant (rtx, machine_mode);
extern int volatile_mem_operand (rtx, machine_mode);
extern int any_memory_operand (rtx, machine_mode);
extern int offsettable_mem_operand (rtx, machine_mode);
extern int simple_offsettable_mem_operand (rtx, machine_mode);
extern int quad_memory_operand (rtx, machine_mode);
extern int vsx_quad_dform_memory_operand (rtx, machine_mode);
extern int indexed_or_indirect_operand (rtx, machine_mode);
extern int reg_or_indexed_operand (rtx, machine_mode);
extern int altivec_indexed_or_indirect_operand (rtx, machine_mode);
extern int indexed_or_indirect_address (rtx, machine_mode);
extern int indexed_address (rtx, machine_mode);
extern int update_address_mem (rtx, machine_mode);
extern int non_update_memory_operand (rtx, machine_mode);
extern int indexed_address_mem (rtx, machine_mode);
extern int add_operand (rtx, machine_mode);
extern int adde_operand (rtx, machine_mode);
extern int non_add_cint_operand (rtx, machine_mode);
extern int logical_const_operand (rtx, machine_mode);
extern int logical_operand (rtx, machine_mode);
extern int non_logical_cint_operand (rtx, machine_mode);
extern int and_operand (rtx, machine_mode);
extern int scc_eq_operand (rtx, machine_mode);
extern int reg_or_mem_operand (rtx, machine_mode);
extern int zero_reg_mem_operand (rtx, machine_mode);
extern int vsx_scalar_64bit (rtx, machine_mode);
extern int lwa_operand (rtx, machine_mode);
extern int ds_form_mem_operand (rtx, machine_mode);
extern int symbol_ref_operand (rtx, machine_mode);
extern int got_operand (rtx, machine_mode);
extern int got_no_const_operand (rtx, machine_mode);
extern int rs6000_tls_symbol_ref (rtx, machine_mode);
extern int unspec_tls (rtx, machine_mode);
extern int call_operand (rtx, machine_mode);
extern int indirect_call_operand (rtx, machine_mode);
extern int current_file_function_operand (rtx, machine_mode);
extern int input_operand (rtx, machine_mode);
extern int splat_input_operand (rtx, machine_mode);
extern int mma_assemble_input_operand (rtx, machine_mode);
extern int mma_disassemble_output_operand (rtx, machine_mode);
extern int rotate_mask_operator (rtx, machine_mode);
extern int boolean_operator (rtx, machine_mode);
extern int boolean_or_operator (rtx, machine_mode);
extern int equality_operator (rtx, machine_mode);
extern int branch_comparison_operator (rtx, machine_mode);
extern int extra_insn_branch_comparison_operator (rtx, machine_mode);
extern int unsigned_comparison_operator (rtx, machine_mode);
extern int signed_comparison_operator (rtx, machine_mode);
extern int signed_or_equality_comparison_operator (rtx, machine_mode);
extern int unsigned_or_equality_comparison_operator (rtx, machine_mode);
extern int scc_comparison_operator (rtx, machine_mode);
extern int scc_rev_comparison_operator (rtx, machine_mode);
extern int fpmask_comparison_operator (rtx, machine_mode);
extern int invert_fpmask_comparison_operator (rtx, machine_mode);
extern int vecint_comparison_operator (rtx, machine_mode);
extern int branch_positive_comparison_operator (rtx, machine_mode);
extern int save_world_operation (rtx, machine_mode);
extern int restore_world_operation (rtx, machine_mode);
extern int vrsave_operation (rtx, machine_mode);
extern int mfcr_operation (rtx, machine_mode);
extern int mtcrf_operation (rtx, machine_mode);
extern int crsave_operation (rtx, machine_mode);
extern int lmw_operation (rtx, machine_mode);
extern int stmw_operation (rtx, machine_mode);
extern int tie_operand (rtx, machine_mode);
extern int small_toc_ref (rtx, machine_mode);
extern int fusion_gpr_addis (rtx, machine_mode);
extern int fusion_gpr_mem_load (rtx, machine_mode);
extern int fusion_addis_mem_combo_load (rtx, machine_mode);
extern int pcrel_local_address (rtx, machine_mode);
extern int pcrel_external_address (rtx, machine_mode);
extern int pcrel_local_or_external_address (rtx, machine_mode);
extern int prefixed_memory (rtx, machine_mode);
extern int d_form_memory (rtx, machine_mode);
extern int vec_set_index_operand (rtx, machine_mode);
#endif /* HAVE_MACHINE_MODES */

#define CONSTRAINT_NUM_DEFINED_P 1
enum constraint_num
{
  CONSTRAINT__UNKNOWN = 0,
  CONSTRAINT_r,
  CONSTRAINT_b,
  CONSTRAINT_f,
  CONSTRAINT_d,
  CONSTRAINT_v,
  CONSTRAINT_wa,
  CONSTRAINT_wd,
  CONSTRAINT_wf,
  CONSTRAINT_wi,
  CONSTRAINT_ws,
  CONSTRAINT_ww,
  CONSTRAINT_h,
  CONSTRAINT_c,
  CONSTRAINT_l,
  CONSTRAINT_x,
  CONSTRAINT_y,
  CONSTRAINT_z,
  CONSTRAINT_we,
  CONSTRAINT_wn,
  CONSTRAINT_wr,
  CONSTRAINT_wx,
  CONSTRAINT_wA,
  CONSTRAINT_I,
  CONSTRAINT_J,
  CONSTRAINT_K,
  CONSTRAINT_L,
  CONSTRAINT_M,
  CONSTRAINT_N,
  CONSTRAINT_O,
  CONSTRAINT_P,
  CONSTRAINT_m,
  CONSTRAINT_o,
  CONSTRAINT_wF,
  CONSTRAINT_wO,
  CONSTRAINT_wQ,
  CONSTRAINT_wY,
  CONSTRAINT_wZ,
  CONSTRAINT_es,
  CONSTRAINT_Q,
  CONSTRAINT_Y,
  CONSTRAINT_Z,
  CONSTRAINT_p,
  CONSTRAINT_a,
  CONSTRAINT_wB,
  CONSTRAINT_wD,
  CONSTRAINT_wL,
  CONSTRAINT_wM,
  CONSTRAINT_eI,
  CONSTRAINT_G,
  CONSTRAINT_H,
  CONSTRAINT_W,
  CONSTRAINT_V,
  CONSTRAINT__l,
  CONSTRAINT__g,
  CONSTRAINT_i,
  CONSTRAINT_s,
  CONSTRAINT_n,
  CONSTRAINT_E,
  CONSTRAINT_F,
  CONSTRAINT_X,
  CONSTRAINT_wE,
  CONSTRAINT_wS,
  CONSTRAINT_R,
  CONSTRAINT_U,
  CONSTRAINT_j,
  CONSTRAINT__LIMIT
};

extern enum constraint_num lookup_constraint_1 (const char *);
extern const unsigned char lookup_constraint_array[];

/* Return the constraint at the beginning of P, or CONSTRAINT__UNKNOWN if it
   isn't recognized.  */

static inline enum constraint_num
lookup_constraint (const char *p)
{
  unsigned int index = lookup_constraint_array[(unsigned char) *p];
  return (index == UCHAR_MAX
          ? lookup_constraint_1 (p)
          : (enum constraint_num) index);
}

extern bool (*constraint_satisfied_p_array[]) (rtx);

/* Return true if X satisfies constraint C.  */

static inline bool
constraint_satisfied_p (rtx x, enum constraint_num c)
{
  int i = (int) c - (int) CONSTRAINT_I;
  return i >= 0 && constraint_satisfied_p_array[i] (x);
}

static inline bool
insn_extra_register_constraint (enum constraint_num c)
{
  return c >= CONSTRAINT_r && c <= CONSTRAINT_wA;
}

static inline bool
insn_extra_memory_constraint (enum constraint_num c)
{
  return c >= CONSTRAINT_m && c <= CONSTRAINT_Z;
}

static inline bool
insn_extra_special_memory_constraint (enum constraint_num)
{
  return false;
}

static inline bool
insn_extra_relaxed_memory_constraint (enum constraint_num)
{
  return false;
}

static inline bool
insn_extra_address_constraint (enum constraint_num c)
{
  return c >= CONSTRAINT_p && c <= CONSTRAINT_a;
}

static inline void
insn_extra_constraint_allows_reg_mem (enum constraint_num c,
				      bool *allows_reg, bool *allows_mem)
{
  if (c >= CONSTRAINT_wB && c <= CONSTRAINT_W)
    return;
  if (c >= CONSTRAINT_V && c <= CONSTRAINT__g)
    {
      *allows_mem = true;
      return;
    }
  (void) c;
  *allows_reg = true;
  *allows_mem = true;
}

static inline size_t
insn_constraint_len (char fc, const char *str ATTRIBUTE_UNUSED)
{
  switch (fc)
    {
    case 'e': return 2;
    case 'w': return 2;
    default: break;
    }
  return 1;
}

#define CONSTRAINT_LEN(c_,s_) insn_constraint_len (c_,s_)

extern enum reg_class reg_class_for_constraint_1 (enum constraint_num);

static inline enum reg_class
reg_class_for_constraint (enum constraint_num c)
{
  if (insn_extra_register_constraint (c))
    return reg_class_for_constraint_1 (c);
  return NO_REGS;
}

extern bool insn_const_int_ok_for_constraint (HOST_WIDE_INT, enum constraint_num);
#define CONST_OK_FOR_CONSTRAINT_P(v_,c_,s_) \
    insn_const_int_ok_for_constraint (v_, lookup_constraint (s_))

enum constraint_type
{
  CT_REGISTER,
  CT_CONST_INT,
  CT_MEMORY,
  CT_SPECIAL_MEMORY,
  CT_RELAXED_MEMORY,
  CT_ADDRESS,
  CT_FIXED_FORM
};

static inline enum constraint_type
get_constraint_type (enum constraint_num c)
{
  if (c >= CONSTRAINT_p)
    {
      if (c >= CONSTRAINT_wB)
        return CT_FIXED_FORM;
      return CT_ADDRESS;
    }
  if (c >= CONSTRAINT_m)
    return CT_MEMORY;
  if (c >= CONSTRAINT_I)
    return CT_CONST_INT;
  return CT_REGISTER;
}
#endif /* tm-preds.h */
