# HW1: C Code Timing Analysis Part I

  - http://developer.mbed.org/platforms/mbed-LPC1768/
  - skip reading: schematics and data sheets
  - write a C program to toggle a assigned GPIO output pin
    (Please check the shared sheet)
  - use objdump to lookup machine code
  - use ARM data sheet to decode machine code
  - write a page report
    - hours that you spend
    - solutions 

## Report

  - Spent around 2-3 hours to set up the environment
  - Spent around 1-2 hours to understand the background knowledge of how to toggle the GPIO output PIN	
  - Spent around 1-2 hours to understand the instruction set and decode the machine code

## Machine Code from dump.txt

**48:	b580**	push	{r7, lr}

	0xb580 = 1011 | 0101 | 1000 0000
		 	 PUSH   L  R   Push Link Register and Register(r7) onto the stack

**4a:	af00**	add	r7, sp, #0

	0xaf00 = 1010 	 | 	1 	| 111 | 00000000
		 	 LOAD		SP	  Rd	Word8
		 	 Address 

	Add #Imm to the current value (#0) of the stack pointer (SP) and load the result into Register (r7)

**4c:	4804**	ldr	r0, [pc, #16]	; (60 <gpio_write+0x60>)

	0x4804 = 01001		| 000 | 00000100
		 	PC-related	  Rd	Add unsigned offset in Imm to the current value of the PC	
		 	Load				(#4 << 2 = #16)

**4e:	2101**  movs	r1, #1

	0x2101 = 001	00 | 001 | 00000001
			 		OP   Rd    Offset8

	Move 8-bit immediate value (#1) into Rd (r1)

**50:	f7ff fffe**	bl	1b810 <_GLOBAL__sub_I_ptr+0x1b77c>

	0xf7ff fffe = 1111 	  | 	0 		| 111 1111 1111 1111 1111 1111 1110
		      	Long Branch		Offset	  Long Branch and Link offset High
		      	w/ Link			High

**54:	4802**	ldr	r0, [pc, #8]	; (60 <gpio_write+0x60>)

	0x4802 = 01001		| 000 | 00000010
		 	PC-related	  Rd	Add unsigned offset in Imm to the current value of the PC	
		 	Load				(#2 << 2 = #8)

**56:	2100**	_movs	r1, #0_

	0x2100 = 001	00 | 001 | 00000000
			 		OP   Rd    Offset8

	Move 8-bit immediate value (#0) into Rd (r1)

**58:	f7ff fffe**	_bl	1b810 <_GLOBAL__sub_I_ptr+0x1b77c>_

	0xf7ff fffe = 1111 	    | 	0 		| 111 1111 1111 1111 1111 1111 1110
		      	Long Branch		Offset	  Long Branch and Link offset High
		      	w/ Link			High

**5c:	e7f6** b.n	4c <gpio_write+0x4c>

	0xe7f6 = 11100 		 | 	111 1111 0110
		 Unconditional	   	Offset11	
		 Branch		   	  	Immediate Value

	Branch PC to where label is 4c

**5e:	bf00**	nop

	0xbf00 = 1011 1111 0000 0000
		 	Add #0 to Stack Pointer (No Operation)

**60:	00000000** .word	0x00000000




