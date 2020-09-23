
SECTIONS {
  .text : {
    _text = .;
  	*(.startup)
    *(.text.*)
	} >ram
  
  . = ALIGN(4);
  _etext = .;
  .data : {
    _data = .;
    *(.data)
    *(.data.*)
	} >ram
  _edata = .;

  .bss : {
    _bss = .;
    *(.bss)
    *(.bss.*)
    } >ram
  . = ALIGN(4);
  _ebss = .;
}

PROVIDE ( _stack_pointer = (ORIGIN(ram) + LENGTH(ram)) );