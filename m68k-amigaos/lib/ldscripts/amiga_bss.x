/* Default linker script, for normal executables */
OUTPUT_FORMAT("amiga")
OUTPUT_ARCH(m68k)
SEARCH_DIR("/opt/amiga/m68k-amigaos/lib");
SECTIONS
{
  PROVIDE(___machtype = 0x0);
  . = 0x0;
  .text :
  {
    __stext = .;
    *(.text)
    *(.text.main)
    *(.text*)
    *(.rodata*)
    *(.data.rel.ro*)
    *(.gnu.linkonce.t.*)
    *(.gnu.linkonce.r.*)
    CONSTRUCTORS
    *(SORT_BY_NAME(.list___EH_FRAME*))
    *(SORT_BY_NAME(.list_*))
    *(.end_of_lists)
    ___datadata_relocs = .;
    __etext = .;
  }
  ___text_size = SIZEOF(.text);
  . = ALIGN(0x0);
  .data :
  {
    __sdata = .;
    *(SORT_BY_NAME(.list___EH_FRAME*))
    *(SORT_BY_NAME(.dlist_*))
    *(.end_of_dlists)
    *(.data)
    *(.data.*)
    *(.gnu.linkonce.d.*)
    ___a4_init = 0x7ffe;
    __edata = .;
  }
  .bss :
  {
    __bss_start = .;
    *(.bss)
    *(.bss.*)
    *(COMMON)
    __end = .;
  }
  ___data_size = SIZEOF(.data) + SIZEOF(.bss);
  ___bss_size = 0x0;
  ___bss_init_size = SIZEOF(.bss);
  .datachip :
  {
    *(.datachip)
  }
  .bsschip :
  {
    *(.bsschip)
  }
}
