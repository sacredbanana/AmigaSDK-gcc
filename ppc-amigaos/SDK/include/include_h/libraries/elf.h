#ifndef LIBRARIES_ELF_H
#define LIBRARIES_ELF_H
/*
**    $VER: elf.h 54.16 (22.08.2022)
**
**    Definitions for the ELF loader
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/* --- Typedefs and structures --- */

typedef ULONG Elf32_Addr;
typedef UWORD Elf32_Half;
typedef ULONG Elf32_Off;
typedef LONG  Elf32_Sword;
typedef ULONG Elf32_Word;

#define EI_NIDENT 16

/*
** The ELF header structure.
*/
typedef struct
{
    UBYTE      e_ident[EI_NIDENT];
    Elf32_Half e_type;
    Elf32_Half e_machine;
    Elf32_Word e_version;
    Elf32_Addr e_entry;
    Elf32_Off  e_phoff;
    Elf32_Off  e_shoff;
    Elf32_Word e_flags;
    Elf32_Half e_ehsize;
    Elf32_Half e_phentsize;
    Elf32_Half e_phnum;
    Elf32_Half e_shentsize;
    Elf32_Half e_shnum;
    Elf32_Half e_shstrndx;
} Elf32_Ehdr;

/*
** Section header structure.
*/
typedef struct
{
    Elf32_Word sh_name;
    Elf32_Word sh_type;
    Elf32_Word sh_flags;
    Elf32_Addr sh_addr;
    Elf32_Off  sh_offset;
    Elf32_Word sh_size;
    Elf32_Word sh_link;
    Elf32_Word sh_info;
    Elf32_Word sh_addralign;
    Elf32_Word sh_entsize;
} Elf32_Shdr;

/*
** Symbol table entry
*/

typedef struct
{
    Elf32_Word st_name;
    Elf32_Addr st_value;
    Elf32_Word st_size;
    UBYTE      st_info;
    UBYTE      st_other;
    Elf32_Half st_shndx;
} Elf32_Sym;

/*
** REL relocation structure. Usually not used in Elf32_PowerPC.
*/
typedef struct
{
    Elf32_Addr r_offset;
    Elf32_Word r_info;
} Elf32_Rel;

/*
** REL relocation with implicit addend.
*/
typedef struct
{
    Elf32_Addr  r_offset;
    Elf32_Word  r_info;
    Elf32_Sword r_addend;
} Elf32_Rela;

/*
** Program Header
*/
typedef struct
{
    Elf32_Word p_type;
    Elf32_Off  p_offset;
    Elf32_Addr p_vaddr;
    Elf32_Addr p_paddr;
    Elf32_Word p_filesz;
    Elf32_Word p_memsz;
    Elf32_Word p_flags;
    Elf32_Word p_align;
} Elf32_Phdr;

/*
** Dynamic Section Tag
*/
typedef struct
{
	Elf32_Sword	d_tag;
   	union
   	{
   		Elf32_Word	d_val;
   		Elf32_Addr	d_ptr;
	} d_un;
} Elf32_Dyn;

/****************************************************************************/

/*
** This typedef should prevent the programmer from
** passing any arbitrary APTR.
*/
typedef struct
{
    int dummy;
} *Elf32_Handle;

/****************************************************************************/

#if !defined(__NO_ELF_ENUMS__)
/* This is necessary because these names clash with gdb's internals */
/* --- Enums --- */
enum enElfFileTypes
{
    ET_NONE   = 0,
    ET_REL    = 1,
    ET_EXEC   = 2,
    ET_DYN    = 3,
    ET_CORE   = 4,
    ET_LOPROC = 0xff00,
    ET_HIPROC = 0xffff
};

enum enElfVersion
{
    EV_NONE    = 0,
    EV_CURRENT = 1
};

enum enElfIdentIndex
{
    ET_MAG0    = 0,
    ET_MAG1    = 1,
    ET_MAG2    = 2,
    ET_MAG3    = 3,
    ET_CLASS   = 4,
    ET_DATA    = 5,
    ET_VERSION = 6,
    ET_PAD     = 7,
    ET_NIDENT  = 16
};

enum enElfClass
{
    ELFCLASSNONE = 0,
    ELFCLASS32   = 1,
    ELFCLASS64   = 2,
    ELFDATANONE  = 0,
    ELFDATA2LSB  = 1,
    ELFDATA2MSB  = 2
};

enum enElfMachine
{
    EM_NONE  = 0,
    EM_M32   = 1,
    EM_SPARC = 2,
    EM_386   = 3,
    EM_68K   = 4,
    EM_88K   = 5,
    EM_860   = 7,
    EM_MIPS  = 8,
    EM_PPC   = 20
};


enum enElfSectionTypes
{
    SHT_NULL     = 0,
    SHT_PROGBITS = 1,
    SHT_SYMTAB   = 2,
    SHT_STRTAB   = 3,
    SHT_RELA     = 4,
    SHT_HASH     = 5,
    SHT_DYNAMIC  = 6,
    SHT_NOTE     = 7,
    SHT_NOBITS   = 8,
    SHT_REL      = 9,
    SHT_SHLIB    = 10,
    SHT_DYNSYM   = 11,
    SHT_LOPROC   = 0x70000000,
    SHT_HIPROC   = 0x7fffffff,
    SHT_LOUSER   = 0x80000000,
    SHT_HIUSER   = 0xffffffff
};

enum enElfSpecialRef
{
    SHN_UNDEF  = 0,
    SHN_ABS    = 0xfff1,
    SHN_COMMON = 0xfff2
};

enum enElfSectionAttrFlags
{
    SWF_WRITE        = 0x01,
    SWF_ALLOC        = 0x02,
    SWF_EXECINSTR    = 0x04,
    SWF_MASKPROC     = 0xf0000000,

    SWF_HANDLE_ALLOC = 0x80000000
};

enum enElfSymbolBinding
{
    STB_LOCAL  = 0,
    STB_GLOBAL = 1,
    STB_WEAK   = 2,
    STB_LOPROC = 13,
    STB_HIPROC = 15
};

enum enElfSymbolType
{
    STT_NOTYPE  = 0,
    STT_OBJECT  = 1,
    STT_FUNC    = 2,
    STT_SECTION = 3,
    STT_FILE    = 4,
    STT_LOPROC  = 13,
    STT_HIPROC  = 15
};

enum enElfRelocType
{
    R_PPC_NONE            =  0,
    R_PPC_ADDR32          =  1,
    R_PPC_ADDR24          =  2,
    R_PPC_ADDR16          =  3,
    R_PPC_ADDR16_LO       =  4,
    R_PPC_ADDR16_HI       =  5,
    R_PPC_ADDR16_HA       =  6,
    R_PPC_ADDR14          =  7,
    R_PPC_ADDR14_BRTAKEN  =  8,
    R_PPC_ADDR14_BRNTAKEN =  9,
    R_PPC_REL24           = 10,
    R_PPC_REL14           = 11,
    R_PPC_REL14_BRTAKEN   = 12,
    R_PPC_REL14_BRNTAKEN  = 13,
    R_PPC_GOT16           = 14,
    R_PPC_GOT16_LO        = 15,
    R_PPC_GOT16_HI        = 16,
    R_PPC_GOT16_HA        = 17,
    R_PPC_PLTREL24        = 18,
    R_PPC_COPY            = 19,
    R_PPC_GLOB_DAT        = 20,
    R_PPC_JMP_SLOT        = 21,
    R_PPC_RELATIVE        = 22,
    R_PPC_LOCAL24PC       = 23,
    R_PPC_UADDR32         = 24,
    R_PPC_UADDR16         = 25,
    R_PPC_REL32           = 26,
    R_PPC_PLT32           = 27,
    R_PPC_PLTREL32        = 28,
    R_PPC_PLT16_LO        = 29,
    R_PPC_PLT16_HI        = 30,
    R_PPC_PLT16_HA        = 31,
    R_PPC_SDAREL16        = 32,
    R_PPC_SECTOFF         = 33,
    R_PPC_SECTOFF_LO      = 34,
    R_PPC_SECTOFF_HI      = 35,
    R_PPC_SECTOFF_HA      = 36
};

enum enSegmentTypes
{
    PT_NULL    = 0,
    PT_LOAD    = 1,
    PT_DYNAMIC = 2,
    PT_INTERP  = 3,
    PT_NOTE    = 4,
    PT_SHLIB   = 5,
    PT_PHDR    = 6
};

enum enSegmentFlags
{
    PF_EXECUTE = 0x01,
    PF_WRITE   = 0x02,
    PF_READ    = 0x04
};

enum enDynamicArrayTags
{
	DT_NULL			= 0,
	DT_NEEDED		= 1,
	DT_PLTRELSIZE	= 2,
	DT_PLTGOT		= 3,
	DT_HASH			= 4,
	DT_STRTAB		= 5,
	DT_SYMTAB		= 6,
	DT_RELA			= 7,
	DT_RELASZ		= 8,
	DT_RELAENT		= 9,
	DT_STRSZ		= 10,
	DT_SYMENT		= 11,
	DT_INIT			= 12,
	DT_FINI			= 13,
	DT_SONAME		= 14,
	DT_RPATH		= 15,
	DT_SYMBOLIC		= 16,
	DT_REL			= 17,
	DT_RELSZ		= 18,
	DT_RELENT		= 19,
	DT_PLTREL		= 20,
	DT_DEBUG		= 21,
	DT_TEXTREL		= 22,
	DT_JMPREL		= 23,
	DT_BIND_NOW		= 24,
	DT_LOOS			= 0x6000000D,
	DT_HIOS			= 0x6ffff000,

	/*
	 * AmigaOS-specific tags
	 *
	 * DT_AMIGAOS_DYNVERISION specifies the version of dynamic linking
	 * used by a binary. Latest binutils (at the time of writing) will
 	 * use version 2.
	 */	
	DT_AMIGAOS_DYNVERSION = DT_LOOS + 1,

	DT_LOPROC		= 0x70000000,
	DT_HIGPROC		= 0x7fffffff
};

#endif /* __NO_ELF_ENUMS__ */

/* This enum specifies error codes */
typedef enum enElfError
{
    ELF32_NO_ERROR           = 0,
    ELF32_OUT_OF_MEMORY      = 1,
    ELF32_INVALID_HANDLE     = 2,
    ELF32_NO_MORE_RELOCS     = 3,
    ELF32_SECTION_NOT_LOADED = 4,
    ELF32_UNKNOWN_RELOC      = 5,
    ELF32_READ_ERROR         = 6,
    ELF32_INVALID_SDA_BASE   = 7,

    ELF32_SYMBOL_NOT_FOUND	 = 8,
    ELF32_INVALID_NAME		 = 9,
    ELF32_REQUIRED_OBJECT_MISSING = 10,

    ELF32_NO_SECTION         = 0xFFFFFFFF
} Elf32_Error;

/****************************************************************************/

/* Hook message for the ELF hooks */
struct ElfHookMsg
{
    ULONG OpCode;
    ULONG Arg1;
    ULONG Arg2;
    ULONG Arg3;
};

enum enElfCommands
{
    ELFCMD_DOS_READ  = 0, /* Read from handle.
                             Arg1: APTR buffer address
                             Arg2: ULONG number of bytes */
    ELFCMD_DOS_SEEK  = 1, /* Seek in handle
                             Arg1: ULONG Absolute stream position */
    ELFCMD_DOS_CLOSE = 2, /* Close the stream */

    ELFCMD_MEM_ALLOC = 3, /* Allocate memory for section
                             Arg1: ULONG # of bytes
                             Arg2: STRPTR section name or NULL
                             Arg3: ULONG section flags */
    ELFCMD_MEM_FREE  = 4  /* Free memory for section
                             Arg1: APTR Address of memory
                             Arg2: STRPTR section name or NULL
                             Arg3: ULONG Sectin Flags */
};

enum enLDSOFlags
{
	ELF32_RTLD_GLOBAL	=	0x0001,	/* Global scope for symbols */
	ELF32_RTLD_LOCAL	= 	0x0002,	/* symbols have local scope only */
};


#define	ELF32_RTLD_DEFAULT (APTR)0x00000000	/* Global search score */

/****************************************************************************/

/* Tag item definitions for OpenElf */

#define OET_Filename   (TAG_USER + 1) /* Try to open from a disk file */
#define OET_FileHandle (TAG_USER + 2) /* Use this open file handle */
#define OET_MemoryAddr (TAG_USER + 3) /* Use an already loaded memory image */
#define OET_ElfHandle  (TAG_USER + 4) /* Use an elf handle opened by
                                         someone else */
#define OET_DOSHook    (TAG_USER + 5) /* Hook for DOS callbacks */
#define OET_MEMHook    (TAG_USER + 6) /* Hook for Memory callbacks */
#define OET_Executable (TAG_USER + 7) /* Allocate executable memory
                                         for X flag */
#define OET_ReadOnlyCopy (TAG_USER+8) /* Create a read-only copy of a handle */
#define OET_NoDOS	   (TAG_USER + 9) /* Do not re-open the file handle */

/* Tag item definitions for Get/SetElfAttr */

#define EAT_NumSections        (TAG_USER + 1) /* Number of sections in the
                                                 ELF file */
#define EAT_DOSHook            (TAG_USER + 2) /* Hook for file handling */
#define EAT_MEMHook            (TAG_USER + 3) /* Hook for memory handling */
#define EAT_ElfHeader          (TAG_USER + 4) /* Elf Header structure */
#define EAT_SectionStringTable (TAG_USER + 5) /* Section index of the
                                                 section string tab  */
#define EAT_FileName           (TAG_USER + 6) /* Original file name of the
                                                 ELF file */
#define EAT_Reserved1          (TAG_USER + 7) /* Reserved for internal use */

/* Tag item definitions for GetSectionHeader/GetSection */

#define GST_SectionIndex  (TAG_USER + 1) /* Use the section index
                                            as reference */
#define GST_SectionName   (TAG_USER + 2) /* Use the section name
                                            as reference */
#define GST_Load          (TAG_USER + 3) /* GetSection only:
                                            Load section if unloaded */
#define GST_SearchAddress (TAG_USER + 4) /* Search for the section
                                            that contains addr */

/* Tag items for ElfLoadSeg */

#define ELS_Offset       (TAG_USER + 1) /* Relocate for the given offset */
#define ELS_FreeUnneeded (TAG_USER + 2) /* Free all unneeded sections */
#define ELS_ProgramEntry (TAG_USER + 3) /* Retrieve the address
                                           of the _start symbol */

/* TagItems for UnloadSection */

#define UTS_SectionIndex (TAG_USER + 1) /* Use section index as reference */
#define UTS_NonAlloc     (TAG_USER + 2) /* Unload all non-alloc sections  */

/* Tag Items for CloseElf */

#define CET_CloseInput   (TAG_USER + 1) /* Close the input stream           */
#define CET_UnloadSeg    (TAG_USER + 2) /* Free the process image           */
#define CET_FreeUnneeded (TAG_USER + 3) /* Free all unneeded sections       */
#define CET_CloseAll     (TAG_USER + 4) /* Free the handle                  */
#define CET_ReClose      (TAG_USER + 5) /* Close a handle that was reopened */
#define CET_UnloadAll 	 (TAG_USER + 6) /* Unload all external resources/shared objects */
/* Tag Items for ScanSymbolTable */
#define SST_Load         (TAG_USER + 1) /* Load sections if not loaded.     */

/****************************************************************************/

/* Structure Definition for SymbolQuery */

enum enSymQueryFlags
{
    ELF32_SQ_BYNAME  = 0x01,
    ELF32_SQ_BYVALUE = 0x02,
    ELF32_SQ_LOAD    = 0x80
};

struct Elf32_SymbolQuery
{
    uint32    Flags;      /* Flag value qualifying the search            */
    STRPTR    Name;       /* Name of symbol to search                    */
    uint32    NameLength; /* Length of the name buffer for BYVALUE query */
    uint32    Value;      /* Value of the symbol                         */
    BOOL      Found;      /* FALSE if symbol was not found               */
    uint16    pad1;       /* Pad for longword alignment                  */
    Elf32_Sym Sym;        /* Copy of the symbol's SymTable entry         */
};

struct SymbolMsg
{
    Elf32_Sym *Sym;
    uint32     AbsValue;
    STRPTR     Name;
};

/* Extract Reloc Symbol and Type */
#define ELF32_R_SYM(i)      ((i)>>8)
#define ELF32_R_TYPE(i)     ((unsigned char)(i))
#define ELF32_R_INFO(s,t)   (((s)<<8)+(unsigned char)(t))

#define ELF32_ST_TYPE(i)	((i) & 0xf)
#define ELF32_ST_BIND(i)	((i) >> 4)
#define ELF32_ST_INFO(b,t)	(((b) << 4) + ((t) & 0xf))

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

#endif
