#undef  MD_EXEC_PREFIX
#undef  MD_STARTFILE_PREFIX

#undef  PROCESSOR_DEFAULT
#define PROCESSOR_DEFAULT PROCESSOR_PPC604e

#undef  DEFAULT_ABI
#define DEFAULT_ABI ABI_V4

#undef  TARGET_DEFAULT
#define TARGET_DEFAULT 0

/* Put jump tables in .text to save some relocations */
#undef  JUMP_TABLES_IN_TEXT_SECTION
#define JUMP_TABLES_IN_TEXT_SECTION 1

#undef EH_FRAME_THROUGH_COLLECT2
#define EH_FRAME_THROUGH_COLLECT2 1

/* We don't care about compatibility in this case as ABI from 2.95.x is not compatible anyway */
#undef  DEFAULT_VTABLE_THUNKS
#define DEFAULT_VTABLE_THUNKS 1

/* Use same method of struct return as our 2.95.x */
#undef  DEFAULT_PCC_STRUCT_RETURN
#define DEFAULT_PCC_STRUCT_RETURN 1

#undef DBX_DEBUGGING_INFO
#define DBX_DEBUGGING_INFO 1

#undef DWARF2_DEBUGGING_INFO
#define DWARF2_DEBUGGING_INFO 1

#undef PREFERRED_DEBUGGING_TYPE
#define PREFERRED_DEBUGGING_TYPE DBX_DEBUG

#undef DWARF2_UNWIND_INFO
#define DWARF2_UNWIND_INFO 1

#ifdef TARGET_BASEREL
#undef USE_TM_CLONE_REGISTRY
#define USE_TM_CLONE_REGISTRY 0
#endif

#undef  WCHAR_TYPE
#define WCHAR_TYPE "int"

#undef  WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE 32


#define IS_MCLIB(__MCL__) \
  (strcmp(morphos_mclib_name, __MCL__) == 0)

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()                \
  do                                            \
    {                                           \
      builtin_define_std ("__PPC__");           \
      builtin_define_std ("__powerpc__");       \
      builtin_define_std ("__MORPHOS__");       \
      builtin_define_std ("__morphos__");       \
      builtin_define_std ("AMIGA");             \
      builtin_define_std ("_AMIGA");            \
      builtin_define_std ("amigaos");           \
      builtin_define_std ("__amigaos__");       \
      builtin_assert ("cpu=powerpc");           \
      builtin_assert ("machine=powerpc");       \
      builtin_assert ("system=morphos");        \
      if ( !morphos_mclib_name || IS_MCLIB("ixemul")) \
        {                                       \
          builtin_define_std ("ixemul");        \
         builtin_define_std ("__ixemul");      \
          builtin_define_std ("__ixemul__");    \
        }                                       \
      else if (IS_MCLIB("libnix"))              \
        {                                       \
          builtin_define_std ("libnix");        \
          builtin_define_std ("__libnix");      \
          builtin_define_std ("__libnix__");    \
        }                                       \
      else if (IS_MCLIB("newlib"))              \
        {                                       \
          builtin_define_std ("newlib");        \
          builtin_define_std ("__newlib");      \
         builtin_define_std ("__newlib__");    \
        }                                       \
     builtin_define ("__saveds=__attribute__((__saveds__))");    \
      TARGET_OS_SYSV_CPP_BUILTINS ();           \
    }                                           \
  while (0)

#undef  CPP_SPEC
#define CPP_SPEC "%{posix: -D_POSIX_SOURCE} %{pthread: -D_REENTRANT} %(cpp_os_default)"

#undef CC1_SPEC
#define        CC1_SPEC "%{G*} %(cc1_cpu)" \
"%{g: %{!fno-eliminate-unused-debug-symbols: -feliminate-unused-debug-symbols}} \
%{g1: %{!fno-eliminate-unused-debug-symbols: -feliminate-unused-debug-symbols}} \
%{msdata: -msdata=default} \
%{mno-sdata: -msdata=none} \
%{!mbss-plt: %{!msecure-plt: %(cc1_secure_plt_default)}} \
%{profile: -p} \
%{faltivec:-maltivec -include altivec.h} %{fno-altivec:-mno-altivec} \
%<faltivec %<fno-altivec \
%{vec:-maltivec -include altivec.h} %{fno-vec:-mno-altivec} \
%<fvec %<fno-vec "

#undef  NATIVE_SYSTEM_HEADER_DIR
//#define NATIVE_SYSTEM_HEADER_DIR     "/include"

#undef  LOCAL_INCLUDE_DIR
#define LOCAL_INCLUDE_DIR        "/usr/include"

#undef  OSINCLUDE_DIR
#define OSINCLUDE_DIR       "/os-include"

#define SUB3TARGET_OVERRIDE_OPTIONS  \
do                                   \
{                                    \
  if (TARGET_ALTIVEC)                \
  {                                  \
    rs6000_altivec_abi = 1;          \
    TARGET_ALTIVEC_VRSAVE = 1;       \
  }                                  \
  if (TARGET_RESIDENT)               \
  {                                  \
    target_flags |= MASK_BASEREL;    \
  }                                  \
} while(0)

/* We can't use 'bl' from .init/.fini to .text, so use a trampoline. */
#define CRT_CALL_STATIC_FUNCTION(SECTION_OP, FUNC) \
static void __attribute__((__used__))              \
call_ ## FUNC (void) {                             \
  asm(SECTION_OP "\n"                              \
      "lis 11," #FUNC "@ha\n"                      \
      "addi 11,11," #FUNC "@l\n"                   \
      "mtctr 11\n"                                 \
      "bctrl\n"                                    \
      TEXT_SECTION_ASM_OP); }

#undef ASM_OUTPUT_ALIGNED_DECL_LOCAL
#define        ASM_OUTPUT_ALIGNED_DECL_LOCAL(FILE, DECL, NAME, SIZE, ALIGN)    \
do {                                                                   \
  if ((TARGET_BASEREL) && TREE_READONLY (DECL)) \
    { \
      switch_to_section (readonly_data_section); \
      ASM_OUTPUT_ALIGN (FILE, exact_log2 (ALIGN / BITS_PER_UNIT));     \
      ASM_OUTPUT_LABEL (FILE, NAME);                                   \
      ASM_OUTPUT_SKIP (FILE, SIZE);                                    \
      if (!flag_inhibit_size_directive && (SIZE) > 0)                  \
       ASM_OUTPUT_SIZE_DIRECTIVE (FILE, NAME, SIZE);                   \
    } \
  else if ((DECL) && rs6000_elf_in_small_data_p (DECL))                        \
    {                                                                  \
      switch_to_section (sbss_section);                                        \
      ASM_OUTPUT_ALIGN (FILE, exact_log2 (ALIGN / BITS_PER_UNIT));     \
      ASM_OUTPUT_LABEL (FILE, NAME);                                   \
      ASM_OUTPUT_SKIP (FILE, SIZE);                                    \
      if (!flag_inhibit_size_directive && (SIZE) > 0)                  \
       ASM_OUTPUT_SIZE_DIRECTIVE (FILE, NAME, SIZE);                   \
    }                                                                  \
  else                                                                 \
    {                                                                  \
      fprintf (FILE, "%s", LCOMM_ASM_OP);                              \
      assemble_name ((FILE), (NAME));                                  \
      fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",         \
              (SIZE), (ALIGN) / BITS_PER_UNIT);                        \
    }                                                                  \
  ASM_OUTPUT_TYPE_DIRECTIVE (FILE, NAME, "object");                    \
} while (0)

#undef ASM_OUTPUT_ALIGNED_BSS
#define ASM_OUTPUT_ALIGNED_BSS(FILE, DECL, NAME, SIZE, ALIGN)          \
do {                                                                   \
  ASM_OUTPUT_ALIGNED_DECL_LOCAL (FILE, DECL, NAME, SIZE, ALIGN);       \
} while (0)

#undef  ASM_OUTPUT_ALIGNED_DECL_COMMON
#define ASM_OUTPUT_ALIGNED_DECL_COMMON(FILE, DECL, NAME, SIZE, ALIGN)          \
  do                                                                   \
    {                                                                  \
      if((TARGET_BASEREL) && TREE_READONLY (DECL)) \
        fprintf ((FILE), "%s", READONLY_DATA_SECTION_ASM_OP );                         \
      else \
        fprintf ((FILE), "%s", COMMON_ASM_OP);                         \
      assemble_name ((FILE), (NAME));                                  \
      fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",         \
              (SIZE), (ALIGN) / BITS_PER_UNIT);                        \
    }                                                                  \
  while (0)

/* C library */
#define CPP_MORPHOS_DEFAULT_SPEC       "%{mclib=default|!mclib=*:%<mclib=default -mclib=ixemul} %(cpp_ixemul)"
#define LINK_MORPHOS_DEFAULT_SPEC      "%(link_ixemul)"
#define STARTFILE_MORPHOS_DEFAULT_SPEC "%(startfile_ixemul)"
#define ENDFILE_MORPHOS_DEFAULT_SPEC   "%(endfile_ixemul)"

/* ... ixemul */
#define CPP_IXEMUL_SPEC       "-idirafter /opt/ppc-morphos/include"
#define LINK_IXEMUL_SPEC      "--flavor=ixemul"
#define STARTFILE_IXEMUL_SPEC "%{mbaserel32:%{!mresident32:lcrt0i.o%s}} %{mresident32:scrt0i.o%s} %{!mresident32:%{!mbaserel32:crt0i.o%s}} ecrti.o%s crtbegin.o%s"
#define ENDFILE_IXEMUL_SPEC   "crtend.o%s ecrtn.o%s"

/* ... libnix */
#define CPP_LIBNIX_SPEC       "-idirafter /opt/ppc-morphos/includestd -idirafter /opt/ppc-morphos/include"
#define LINK_LIBNIX_SPEC      "--flavor=libnix"
#define STARTFILE_LIBNIX_SPEC "%{mbaserel32:%{!mresident32:libnix/lcrt0i.o%s}} %{mresident32:libnix/scrt0i.o%s} %{!mresident32:%{!mbaserel32:libnix/crt0i.o%s}} ecrti.o%s crtbegin.o%s"
#define ENDFILE_LIBNIX_SPEC   "crtend.o%s ecrtn.o%s"

/* ... newlib */
#define CPP_NEWLIB_SPEC       "-isystem /opt/ppc-morphos/include-newlib -isystem /opt/ppc-morphos/includenl -isystem /opt/ppc-morphos/usr/include-newlib"
#define LINK_NEWLIB_SPEC      "--flavor=newlib"
#define STARTFILE_NEWLIB_SPEC "%{mbaserel32:%{!mresident32:newlib/lcrt0i.o%s}} %{mresident32:newlib/scrt0i.o%s} %{!mresident32:%{!mbaserel32:newlib/crt0i.o%s}} ecrti.o%s crtbegin.o%s"
#define ENDFILE_NEWLIB_SPEC   "crtend.o%s ecrtn.o%s"

/* ... general */
#undef  CPP_OS_DEFAULT_SPEC
#define CPP_OS_DEFAULT_SPEC " \
%{mbaserel32: %{msdata|msdata=default|msdata=sysv: %e-mbaserel32 and -msdata are not compatible}} \
%{mclib=ixemul: %(cpp_ixemul); \
mclib=libnix: %(cpp_libnix); \
mclib=newlib: %(cpp_newlib); \
mclib=default|!mclib=*: %{mclib=default|!nostdinc: %(cpp_morphos_default)}; \
: %eInvalid mclib}"


#undef LINK_SPEC
#define LINK_SPEC "\
--defsym __abox__=1 -Bstatic \
%{h*} %{v:-V} %{G*} \
%{Wl,*:%*} %{YP,*} %{R*} \
%{Qy:} %{!Qn:-Qy} \
%{mbaserel32: %{msdata|msdata=default|msdata=sysv: %e-mbaserel32 and -msdata are not compatible}} \
%{mbaserel32: %{!mresident32:-m morphos_baserel --flavor=libb32}} %{mresident32:-m morphos_baserel --datadata-reloc --flavor=libb32} \
%{mclib=ixemul: %(link_ixemul); \
mclib=libnix: %(link_libnix); \
mclib=newlib: %(link_newlib); \
mclib=default|!mclib=*: %(link_morphos_default); \
: %eInvalid mclib}"

#undef STARTFILE_SPEC
#define STARTFILE_SPEC "\
%{mclib=ixemul: %(startfile_ixemul); \
mclib=libnix: %(startfile_libnix); \
mclib=newlib: %(startfile_newlib); \
mclib=default|!mclib=*: %(startfile_morphos_default); \
: %eInvalid mclib}"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC "\
%{mclib=ixemul: %(endfile_ixemul); \
mclib=libnix: %(endfile_libnix); \
mclib=newlib: %(endfile_newlib); \
mclib=default|!mclib=*: %(endfile_morphos_default); \
: %eInvalid mclib}"


#undef LIB_SPEC
#define LIB_SPEC "%{!nostdlib: -L/opt/ppc-morphos/lib -L/opt/ppc-morphos/usr/lib} --start-group -lc -labox -laboxstubs -lsavl %{mclib=libnix: -lauto} %{pthread:-lpthread} --end-group"

#undef SUBTARGET_EXTRA_SPECS
#define SUBTARGET_EXTRA_SPECS \
  {"cpp_os_default", CPP_OS_DEFAULT_SPEC}, \
  /* default C runtime */ \
  {"cpp_morphos_default", CPP_MORPHOS_DEFAULT_SPEC}, \
  {"link_morphos_default", LINK_MORPHOS_DEFAULT_SPEC}, \
  {"startfile_morphos_default", STARTFILE_MORPHOS_DEFAULT_SPEC}, \
  {"endfile_morphos_default", ENDFILE_MORPHOS_DEFAULT_SPEC}, \
  /* ixemul */ \
  {"cpp_ixemul", CPP_IXEMUL_SPEC}, \
  {"link_ixemul", LINK_IXEMUL_SPEC}, \
  {"startfile_ixemul", STARTFILE_IXEMUL_SPEC}, \
  {"endfile_ixemul", ENDFILE_IXEMUL_SPEC}, \
  /* libnix */ \
  {"cpp_libnix", CPP_LIBNIX_SPEC}, \
  {"link_libnix", LINK_LIBNIX_SPEC}, \
  {"startfile_libnix", STARTFILE_LIBNIX_SPEC}, \
  {"endfile_libnix", ENDFILE_LIBNIX_SPEC}, \
  /* newlib */ \
  {"cpp_newlib", CPP_NEWLIB_SPEC}, \
  {"link_newlib", LINK_NEWLIB_SPEC}, \
  {"startfile_newlib", STARTFILE_NEWLIB_SPEC}, \
  {"endfile_newlib", ENDFILE_NEWLIB_SPEC},

/* MorphOS specific attributes */
#if 1
#define SUBTARGET_ATTRIBUTE_TABLE \
  { "saveds", 0, 0, false, true, true, false, morphos_handle_saveds_attribute, NULL }


/* Data-Data reloc name */
#define DATA_DATA_RELOC "drel"

/* MorphOS symbol-ref flags */
#define SYMBOL_FLAG_MORPHOS_BASEREL (SYMBOL_FLAG_MACH_DEP << 0)
#define SYMBOL_REF_MORPHOS_BASEREL_P(RTX) \
  (GET_CODE (RTX) == SYMBOL_REF && ((SYMBOL_REF_FLAGS (RTX) & SYMBOL_FLAG_MORPHOS_BASEREL) != 0))


/* Do not try to mix normal/baserel32 pch files */
#undef TARGET_CHECK_PCH_TARGET_FLAGS
#define TARGET_CHECK_PCH_TARGET_FLAGS morphos_check_pch_target_flags

/* Do not use anchors for brel ref objects */
#undef TARGET_USE_ANCHORS_FOR_SYMBOL_P
#define TARGET_USE_ANCHORS_FOR_SYMBOL_P morphos_use_anchors_for_symbol_p
#endif

/* We always use gas */
#undef TARGET_GAS
#define TARGET_GAS 1

/* Override TLS support to false */
#undef HAVE_AS_TLS
#define HAVE_AS_TLS 0

/* Use morphos.opt */
extern const char *morphos_mclib_name;
#define TARGET_USES_MORPHOS_OPT 1
