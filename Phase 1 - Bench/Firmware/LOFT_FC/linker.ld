ENTRY(reset_handler)

/* 
 * Memory Regions 
 *
 * F446RE chip:
 * 512K FLASH memory
 * 128K SRAM memory
 *
 * FLASH starting address: 0x08000000
 * SRAM starting address:  0x20000000
 *
 */

MEMORY
{
	FLASH(rx): ORIGIN = 0x08000000, LENGTH = 512k
	SRAM(wx): ORIGIN = 0x20000000, LENGTH = 128k
}


/* 
 * Sections in Memory
 *
 * Defining sections in SRAM and FLASH
 *
 */

SECTIONS
{
	/* Interupt service rountine vector
	 *
	 * Default address: 0x00000000
	 * */
	.isr_vector :
	{
		KEEP(*(.isr_vector))

	} >FLASH

	.text :
	{
		. = ALIGN(4);
		
		*(.text)
		*(.rodata)

		. = ALIGN(4);
		_etext = .;
	} >FLASH

	.data :
	{
		. = ALIGN(4);
		_sdata = .;

		*(.data)

		. = ALIGN(4);
		_edata = .;

	} >SRAM AT> FLASH

	.bss :
	{
		. = ALIGN(4);
		_SBSS = .;

		*(.bss)

		. = ALIGN(4);
		_ebss = .;
	
	} >SRAM
}
