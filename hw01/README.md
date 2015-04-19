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

## Machine Code from objdump_O0.txt

**238:	b580**	push	{r3, lr}

	0xb508 = 1011 | 0101 | 0000 1000
		 	 PUSH   L  R   Push Link Register and Register(r3) onto the stack

**23a:	4804**	ldr		r0, [pc, #16]	;(24c <main+0x14>)

	0x4804 = 01001		| 000 | 00000100
		 	PC-related	  Rd	Add unsigned offset in Imm to the current value of the PC	
		 	Load				(#4 << 2 = #16)

**23c:	2101**  movs	r1, #1

	0x2101 = 001	00 | 001 | 00000001
			 		OP   Rd    Offset8

	Move 8-bit immediate value (#1) into Rd (r1)

**23e:	f7ff ffed**	bl	21c <_ZN4mbed10DigitalOutaSEi>

	0xf7ff ffed = 1111 	  | 	0 		| 111 1111 1111 1111 1111 1110 1101
		      	Long Branch		Offset	  Long Branch and Link offset High
		      	w/ Link			High

**242:	4802**	ldr		r0, [pc, #8]	;(24c <main+0x14>)

	0x4802 = 01001		| 000 | 00000010
		 	PC-related	  Rd	Add unsigned offset in Imm to the current value of the PC	
		 	Load				(#2 << 2 = #8)

**244:	2100**	movs	r1, #0

	0x2100 = 001	00 | 001 | 00000000
			 		OP   Rd    Offset8

	Move 8-bit immediate value (#0) into Rd (r1)

**246:	f7ff ffe9**	bl	21c <_ZN4mbed10DigitalOutaSEi>

	0xf7ff ffe9 = 1111 	    | 	0 		| 111 1111 1111 1111 1111 1110 1001
		      	Long Branch		Offset	  Long Branch and Link offset High
		      	w/ Link			High

**24a:	e7f6** b.n	4c	23a <main+0x2>

	0xe7f6 = 11100 		 | 	111 1111 0110
		 Unconditional	   	Offset11	
		 Branch		   	  	Immediate Value

	Branch PC to where label is 4c

**24c:	10000198** .word	0x10000198




