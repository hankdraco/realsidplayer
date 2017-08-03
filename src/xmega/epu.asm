/*
 * epu.asm
 *
 *  Created: 2016-06-14 09:33:41
 *   Author: £ukasz 'Hank' Drzewiecki
 */ 

 .equ fN = 0x80					// NEGATIVE flag
 .equ fV = 0x40					// OVERFLOW flag
 .equ fB = 0x10					// BREAK INTERRUPT flag
 .equ fD = 0x08					// DECIMAL CODE flag
 .equ fI = 0x04					// INTERRUPT flag
 .equ fZ = 0x02					// ZERO flag
 .equ fC = 0x01					// CARRY flag

 .include "epu_core.inc"


.macro macro_d012
	dec rLineCycles					// 1
	brne cycle						// 1 if condition is false / 2 if condition is true
	ldi rLineCycles, 0x7e			// 1
	inc rLineNumber					// 1
	cpi rLineNumber, 156
	brne cycle						// 1 if condition is false / 2 if condition is true
	ldi rLineNumber, 0				// 1
cycle:
	ldi ZL, 0						// 1
	ldi ZH, X_ZEROPAGE_ADDR_H		// 1
	st Z, rLineNumber				// 1 http://www.atmel.com/webdoc/avrassembler/avrassembler.wb_STD_Z.html
.endmacro


EPU_RESET:
	ldi rLineCycles, 0x7e
	ldi rLineNumber, 0

	ldi rSP, 0xfd		; set stack pointer

	clr rFlags			; clear flags
	ori rFlags, fI		; set I flag to disable interrupts

#ifndef TEST
	ldi YL, 0x00						; set start address
	ldi YH, X_PLAYER_ROUTINE_ADDR_H		; to player routine

	/* Wait at least 10 c64 cycles with RESET line LOW */
	ldi cr, SID_RESET_bm
	sts PORTE_OUTCLR, cr

	ldi rCycles, 25
er_wait:
	sbis GPIO_GPIOR0, 0
	rjmp er_wait
	cbi GPIO_GPIOR0, 0
er:	dec rCycles
	cpi rCycles, 1
    brne er_wait
    rjmp PC+1
	sts PORTE_OUTSET, cr

	ldi rCycles, 0		; reset opcode's duration latch
	cbi GPIO_GPIOR0, 0	;
#else
	ldi YL, 0x10					; set start address
	ldi YH, 0x28					; to test code

	ldi rCycles, 0		; reset opcode duration latch
#endif
	


/* MAIN LOOP */

EPU_CLK:
#ifndef TEST
	sbis GPIO_GPIOR0, 0				// 2 if condition is false / 3 if condition is true and skipping 1 word (2 bytes) / 4 if condition is true and skipping 2 words (4 bytes)
									// here is 2 if not skipped and 3 if skipped
	rjmp EPU_CLK					// 2
	cbi GPIO_GPIOR0, 0				// 1
#endif

	macro_d012		// twice here, because in second cycle there's not enough time for doing this,
	macro_d012		// so here we need to compensate that (from the outside world's perspective it is not noticeable at all)

	/* pull SID_CS high to prevent writing */
	ldi cr, SID_CS_bm				// 1 -> disable SID data transfer (CS line goes HIGH)
	sts PORTE_OUTSET, cr			// 2 (3 for external SRAM)

	ld cr, Y+						// 1(2?) http://www.atmel.com/webdoc/avrassembler/avrassembler.wb_LDD.html

	ldi ZL, LOW(EPU_OPCODES_TABLE)		// 1
	ldi ZH, HIGH(EPU_OPCODES_TABLE)		// 1

	
	add ZL, cr						// 1
	adc ZH, rCycles					// 1 -> hack to increase the speed: rCycles is 0 here
	add ZL, cr						// 1
	adc ZH, rCycles					// 1 -> hack to increase the speed: rCycles is 0 here
	

/* SECOND CYCLE */
EPU_SECOND_CYCLE:
#ifndef TEST
	sbis GPIO_GPIOR0, 0				// 2 if condition is false / 3 if condition is true and skipping 1 word (2 bytes) / 4 if condition is true and skipping 2 words (4 bytes)
									// here is 2 if not skipped and 3 if skipped
	rjmp EPU_SECOND_CYCLE			// 2
	cbi GPIO_GPIOR0, 0				// 1
#endif

	ijmp							// 2
	
EPU_OPCODE_END:
	dec rCycles
	breq EPU_CLK


/* THIRD OR FURTHER CYCLE */
EPU_FREE_CYCLE:
#ifndef TEST
	sbis GPIO_GPIOR0, 0				// 2 if condition is false / 3 if condition is true and skipping 1 word (2 bytes) / 4 if condition is true and skipping 2 words (4 bytes)
									// here is 2 if not skipped and 3 if skipped
	rjmp EPU_FREE_CYCLE				// 2
	cbi GPIO_GPIOR0, 0				// 1
#endif

	macro_d012

	/* pull SID_CS high to prevent writing */
	ldi cr, SID_CS_bm				// 1 -> disable SID data transfer (CS line goes HIGH)
	sts PORTE_OUTSET, cr			// 2 (3 for external SRAM)


#ifndef TEST
	lds cr, PORTF_IN
	sbrc cr, 0
	rjmp EPU_END
	ldi YL, 0x04						; set start address
	ldi YH, X_PLAYER_ROUTINE_ADDR_H		; to player routine
#endif



EPU_END:
	dec rCycles
	breq EPU_CLK

	rjmp EPU_FREE_CYCLE
