ENTRY(kmain)
OUTPUT_FORMAT(elf32-i386)
SECTIONS {
  . = 0x1000;
  .kernel :
  {
    *(.text*)
    *(.rodata*)
    *(.rdata*)
    *(.data)
    _bss_start = .;
    *(.bss)
    *(COMMON)
    _bss_end = .;
  }
  /DISCARD/ : {
        *(.eh_frame)
        *(.comment)
  }
}