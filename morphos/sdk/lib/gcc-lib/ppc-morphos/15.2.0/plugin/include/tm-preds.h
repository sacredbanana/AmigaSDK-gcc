/* Generated automatically by the program 'build/genpreds'
   from the machine description file '/work/pkgsrc/cross/ppc-morphos-gcc/work/gcc-15.2.0/gcc/config/rs6000/rs6000.md'.  */

#ifndef GCC_TM_PREDS_H
#define GCC_TM_PREDS_H

#ifdef HAVE_MACHINE_MODES
extern bool general_operand (rtx, machine_mode);
extern bool address_operand (rtx, machine_mode);
extern bool register_operand (rtx, machine_mode);
extern bool pmode_register_operand (rtx, machine_mode);
extern bool scratch_operand (rtx, machine_mode);
extern bool immediate_operand (rtx, machine_mode);
extern bool const_int_operand (rtx, machine_mode);
extern bool const_scalar_int_operand (rtx, machine_mode);
extern bool const_double_operand (rtx, machine_mode);
extern bool nonimmediate_operand (rtx, machine_mode);
extern bool nonmemory_operand (rtx, machine_mode);
extern bool push_operand (rtx, machine_mode);
extern bool pop_operand (rtx, machine_mode);
extern bool memory_operand (rtx, machine_mode);
extern bool indirect_operand (rtx, machine_mode);
extern bool ordered_comparison_operator (rtx, machine_mode);
extern bool comparison_operator (rtx, machine_mode);
extern bool aligned_register_operand (rtx, machine_mode);
extern bool any_operand (rtx, machine_mode);
extern bool any_parallel_operand (rtx, machine_mode);
extern bool count_register_operand (rtx, machine_mode);
extern bool sf_subreg_operand (rtx, machine_mode);
extern bool altivec_register_operand (rtx, machine_mode);
extern bool vsx_register_operand (rtx, machine_mode);
extern bool vsx_reg_sfsubreg_ok (rtx, machine_mode);
extern bool vfloat_operand (rtx, machine_mode);
extern bool vint_operand (rtx, machine_mode);
extern bool vlogical_operand (rtx, machine_mode);
extern bool ca_operand (rtx, machine_mode);
extern bool zero_constant (rtx, machine_mode);
extern bool all_ones_constant (rtx, machine_mode);
extern bool s5bit_cint_operand (rtx, machine_mode);
extern bool u1bit_cint_operand (rtx, machine_mode);
extern bool u3bit_cint_operand (rtx, machine_mode);
extern bool u5bit_cint_operand (rtx, machine_mode);
extern bool u6bit_cint_operand (rtx, machine_mode);
extern bool u7bit_cint_operand (rtx, machine_mode);
extern bool u8bit_cint_operand (rtx, machine_mode);
extern bool s8bit_cint_operand (rtx, machine_mode);
extern bool u10bit_cint_operand (rtx, machine_mode);
extern bool short_cint_operand (rtx, machine_mode);
extern bool u_short_cint_operand (rtx, machine_mode);
extern bool upper16_cint_operand (rtx, machine_mode);
extern bool non_short_cint_operand (rtx, machine_mode);
extern bool s32bit_cint_operand (rtx, machine_mode);
extern bool c32bit_cint_operand (rtx, machine_mode);
extern bool exact_log2_cint_operand (rtx, machine_mode);
extern bool const_0_to_1_operand (rtx, machine_mode);
extern bool const_m1_to_1_operand (rtx, machine_mode);
extern bool const_0_to_3_operand (rtx, machine_mode);
extern bool const_2_to_3_operand (rtx, machine_mode);
extern bool const_0_to_7_operand (rtx, machine_mode);
extern bool const_0_to_12_operand (rtx, machine_mode);
extern bool const_0_to_15_operand (rtx, machine_mode);
extern bool cint34_operand (rtx, machine_mode);
extern bool gpc_reg_operand (rtx, machine_mode);
extern bool int_reg_operand (rtx, machine_mode);
extern bool int_reg_operand_not_pseudo (rtx, machine_mode);
extern bool base_reg_operand (rtx, machine_mode);
extern bool fpr_reg_operand (rtx, machine_mode);
extern bool quad_int_reg_operand (rtx, machine_mode);
extern bool cc_reg_operand (rtx, machine_mode);
extern bool cc_reg_not_cr0_operand (rtx, machine_mode);
extern bool reg_or_short_operand (rtx, machine_mode);
extern bool reg_or_aligned_short_operand (rtx, machine_mode);
extern bool reg_or_u_short_operand (rtx, machine_mode);
extern bool reg_or_cint_operand (rtx, machine_mode);
extern bool reg_or_zero_operand (rtx, machine_mode);
extern bool add_cint_operand (rtx, machine_mode);
extern bool reg_or_add_cint_operand (rtx, machine_mode);
extern bool reg_or_sub_cint_operand (rtx, machine_mode);
extern bool reg_or_logical_cint_operand (rtx, machine_mode);
extern bool vsx_reg_or_cint_operand (rtx, machine_mode);
extern bool easy_fp_constant (rtx, machine_mode);
extern bool vsx_prefixed_constant (rtx, machine_mode);
extern bool easy_vector_constant_ieee128 (rtx, machine_mode);
extern bool xxspltib_constant_split (rtx, machine_mode);
extern bool vspltisw_vupkhsw_constant_split (rtx, machine_mode);
extern bool xxspltib_constant_nosplit (rtx, machine_mode);
extern bool easy_vector_constant (rtx, machine_mode);
extern bool easy_vector_constant_add_self (rtx, machine_mode);
extern bool easy_vector_constant_msb (rtx, machine_mode);
extern bool easy_vector_constant_vsldoi (rtx, machine_mode);
extern bool const_vector_each_byte_same (rtx, machine_mode);
extern bool vector_int_reg_or_same_bit (rtx, machine_mode);
extern bool vector_shift_constant (rtx, machine_mode);
extern bool zero_fp_constant (rtx, machine_mode);
extern bool volatile_mem_operand (rtx, machine_mode);
extern bool any_memory_operand (rtx, machine_mode);
extern bool offsettable_mem_operand (rtx, machine_mode);
extern bool simple_offsettable_mem_operand (rtx, machine_mode);
extern bool quad_memory_operand (rtx, machine_mode);
extern bool vsx_quad_dform_memory_operand (rtx, machine_mode);
extern bool indexed_or_indirect_operand (rtx, machine_mode);
extern bool reg_or_indexed_operand (rtx, machine_mode);
extern bool altivec_indexed_or_indirect_operand (rtx, machine_mode);
extern bool indexed_or_indirect_address (rtx, machine_mode);
extern bool indexed_address (rtx, machine_mode);
extern bool update_address_mem (rtx, machine_mode);
extern bool non_update_memory_operand (rtx, machine_mode);
extern bool indexed_address_mem (rtx, machine_mode);
extern bool add_operand (rtx, machine_mode);
extern bool adde_operand (rtx, machine_mode);
extern bool non_add_cint_operand (rtx, machine_mode);
extern bool logical_const_operand (rtx, machine_mode);
extern bool logical_operand (rtx, machine_mode);
extern bool non_logical_cint_operand (rtx, machine_mode);
extern bool and_operand (rtx, machine_mode);
extern bool scc_eq_operand (rtx, machine_mode);
extern bool reg_or_mem_operand (rtx, machine_mode);
extern bool zero_reg_mem_operand (rtx, machine_mode);
extern bool vsx_scalar_64bit (rtx, machine_mode);
extern bool lwa_operand (rtx, machine_mode);
extern bool symbol_ref_operand (rtx, machine_mode);
extern bool got_operand (rtx, machine_mode);
extern bool got_no_const_operand (rtx, machine_mode);
extern bool rs6000_tls_symbol_ref (rtx, machine_mode);
extern bool unspec_tls (rtx, machine_mode);
extern bool call_operand (rtx, machine_mode);
extern bool indirect_call_operand (rtx, machine_mode);
extern bool current_file_function_operand (rtx, machine_mode);
extern bool input_operand (rtx, machine_mode);
extern bool splat_input_operand (rtx, machine_mode);
extern bool mma_assemble_input_operand (rtx, machine_mode);
extern bool mma_disassemble_output_operand (rtx, machine_mode);
extern bool rotate_mask_operator (rtx, machine_mode);
extern bool boolean_operator (rtx, machine_mode);
extern bool boolean_or_operator (rtx, machine_mode);
extern bool equality_operator (rtx, machine_mode);
extern bool branch_comparison_operator (rtx, machine_mode);
extern bool extra_insn_branch_comparison_operator (rtx, machine_mode);
extern bool unsigned_comparison_operator (rtx, machine_mode);
extern bool signed_comparison_operator (rtx, machine_mode);
extern bool signed_or_equality_comparison_operator (rtx, machine_mode);
extern bool unsigned_or_equality_comparison_operator (rtx, machine_mode);
extern bool scc_comparison_operator (rtx, machine_mode);
extern bool scc_rev_comparison_operator (rtx, machine_mode);
extern bool fpmask_comparison_operator (rtx, machine_mode);
extern bool invert_fpmask_comparison_operator (rtx, machine_mode);
extern bool vecint_comparison_operator (rtx, machine_mode);
extern bool branch_positive_comparison_operator (rtx, machine_mode);
extern bool save_world_operation (rtx, machine_mode);
extern bool restore_world_operation (rtx, machine_mode);
extern bool vrsave_operation (rtx, machine_mode);
extern bool mfcr_operation (rtx, machine_mode);
extern bool mtcrf_operation (rtx, machine_mode);
extern bool crsave_operation (rtx, machine_mode);
extern bool lmw_operation (rtx, machine_mode);
extern bool stmw_operation (rtx, machine_mode);
extern bool tie_operand (rtx, machine_mode);
extern bool small_toc_ref (rtx, machine_mode);
extern bool fusion_gpr_addis (rtx, machine_mode);
extern bool fusion_gpr_mem_load (rtx, machine_mode);
extern bool fusion_addis_mem_combo_load (rtx, machine_mode);
extern bool pcrel_local_address (rtx, machine_mode);
extern bool pcrel_external_address (rtx, machine_mode);
extern bool pcrel_local_or_external_address (rtx, machine_mode);
extern bool prefixed_memory (rtx, machine_mode);
extern bool d_form_memory (rtx, machine_mode);
extern bool vec_set_index_operand (rtx, machine_mode);
extern bool macho_pic_address (rtx, machine_mode);
extern bool lowpart_subreg_operator (rtx, machine_mode);
#endif /* HAVE_MACHINE_MODES */

#ifdef GCC_HARD_REG_SET_H
struct target_constraints {
  HARD_REG_SET register_filters[1];
};

extern struct target_constraints default_target_constraints;
#if SWITCHABLE_TARGET
extern struct target_constraints *this_target_constraints;
#else
#define this_target_constraints (&default_target_constraints)
#endif

#define TEST_REGISTER_FILTER_BIT(ID, REGNO) \
  ((void) (ID), (void) (REGNO), false)

inline bool
test_register_filters (unsigned int, unsigned int)
{
  return true;
}
#endif

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
  CONSTRAINT_wL,
  CONSTRAINT_wM,
  CONSTRAINT_eI,
  CONSTRAINT_eP,
  CONSTRAINT_eQ,
  CONSTRAINT_G,
  CONSTRAINT_H,
  CONSTRAINT_W,
  CONSTRAINT_V,
  CONSTRAINT__l,
  CONSTRAINT__g,
  CONSTRAINT_i,
  CONSTRAINT_s,
  CONSTRAINT__c,
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

#ifdef GCC_HARD_REG_SET_H
static inline const HARD_REG_SET *
get_register_filter (constraint_num)
{
  return nullptr;
}
#endif

static inline int
get_register_filter_id (constraint_num)
{
  return -1;
}
#endif /* tm-preds.h */
