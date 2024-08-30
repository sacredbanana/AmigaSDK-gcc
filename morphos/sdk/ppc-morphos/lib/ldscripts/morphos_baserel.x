/* Default linker script, for normal executables */
OUTPUT_FORMAT("elf32-morphos", "elf32-morphos",
	      "elf32-morphos")
OUTPUT_ARCH(powerpc)
SEARCH_DIR("/opt/ppc-morphos/ppc-morphos/lib");
/* Do we need any of these for elf?
   __DYNAMIC = 0;    */
PROVIDE (__stack = 0);
PROVIDE (__machtype = 0x1);
SECTIONS
{
  /* Read-only sections, merged into text segment: */
  . =  + SIZEOF_HEADERS;
  .interp   : { *(.interp) }
  .hash		  : { *(.hash)		}
  .dynsym	  : { *(.dynsym)		}
  .dynstr	  : { *(.dynstr)		}
  .gnu.version   : { *(.gnu.version)      }
  .gnu.version_d   : { *(.gnu.version_d)  }
  .gnu.version_r   : { *(.gnu.version_r)  }
  .rela.text     :
    { *(.rela.text) *(.rela.gnu.linkonce.t*) }
  .rela.got	  : { *(.rela.got)	}
  .rela.got1	  : { *(.rela.got1)	}
  .rela.got2	  : { *(.rela.got2)	}
  .rela.ctors	  : { *(.rela.ctors)	}
  .rela.dtors	  : { *(.rela.dtors)	}
  .rela.init	  : { *(.rela.init)	}
  .rela.fini	  : { *(.rela.fini)	}
  .rela.plt	  : { *(.rela.plt)	}
  .rela.rodata    :
    { *(.rela.rodata) *(.rela.gnu.linkonce.r*) }
  .rela.sdata	  :
  {
    *(.rela.data)
    *(.rela.gnu.linkonce.d*)
    *(.rela.sdata)
  }
  .rela.sbss	  :
  {
    *(.rela.sbss)
    *(.rela.bss)
  }
  .rela.sdata2	  : { *(.rela.sdata2)	}
  .rela.sbss2	  : { *(.rela.sbss2)	}
  .text      :
  {
    PROVIDE (__text_start = .);
    *(.text)
    *(.text.*)
    KEEP(*(.eh_frame*))
    /* .gnu.warning sections are handled specially by elf32.em.  */
    *(.gnu.warning)
    *(.gnu.linkonce.t*)
    PROVIDE (__text_end = .);
  } =0
  PROVIDE (__text_size = SIZEOF(.text));
  .init		  : { *(.init)		} =0
  .fini		  : { *(.fini)		} =0
  _etext = .;
  PROVIDE (etext = .);
  .sdata2   : { *(.sdata2) }
  .sbss2   : { *(.sbss2) }
  .got1		  : { *(.got1) }
  .dynamic	  : { *(.dynamic) }
  /* Put .ctors and .dtors next to the .got2 section, so that the pointers
     get relocated with -mrelocatable. Also put in the .fixup pointers.
     The current compiler no longer needs this, but keep it around for 2.7.2  */
		PROVIDE (_GOT2_START_ = .);
  .got2		  :  { *(.got2) }
		PROVIDE (__CTOR_LIST__ = .);
  .ctors	  : { *(.ctors) }
		PROVIDE (__CTOR_END__ = .);
		PROVIDE (__DTOR_LIST__ = .);
  .dtors	  : { *(.dtors) }
		PROVIDE (__DTOR_END__ = .);
		PROVIDE (_FIXUP_START_ = .);
  .fixup	  : { *(.fixup) }
		PROVIDE (_FIXUP_END_ = .);
		PROVIDE (_GOT2_END_ = .);
		PROVIDE (_GOT_START_ = .);
  .got		  : { *(.got) }
  .got.plt	  : { *(.got.plt) }
		PROVIDE (_GOT_END_ = .);
  .rodata	  : { *(.rodata) }
 /* We want the small data sections together, so single-instruction offsets
     can access them all, and initialized data all before uninitialized, so
     we can shorten the on-disk segment size.  */
  .sdata	  :
  {
    /*PROVIDE (__sdata_start = .);*/
    __sdata_start = .;
    *(.data)
    *(.data.*)
    *(.data1)
    *(.data1.*)
    *(.data.rel)
    *(.data.rel.local)
    __small_start = .;
    *(.sdata)
    *(.sdata.*)
    *(.gnu.linkonce.s.*)
    CONSTRUCTORS
    PROVIDE (__r13_init = /*__small_start*/ __sdata_start + 0x8000);
    PROVIDE (__sdata_end = .);
  }
  /*PROVIDE (__sdata_size = SIZEOF(.sdata));*/
  _edata  =  .;
  PROVIDE (edata = .);
  .sbss      :
  {
    /*PROVIDE (__sbss_start = .);*/
    __sbss_start = .;
    *(.sbss)
    *(.sbss.*)
    *(.scommon)
    *(.gnu.linkonce.sb.*)
    *(.dynsbss)
    *(.bss)
    *(.bss.*)
    *(.gnu.linkonce.b.*)
    *(COMMON)
    PROVIDE (__sbss_end = .);
  }
  PROVIDE (__sdata_size = __sbss_start - __sdata_start);
  PROVIDE (__sbss_size = SIZEOF(.sbss));
  /* These are needed for ELF backends which have not yet been
     converted to the new style linker.  */
  .stab 0 : { *(.stab) }
  .stabstr 0 : { *(.stabstr) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }
  /* These must appear regardless of  .  */
}
