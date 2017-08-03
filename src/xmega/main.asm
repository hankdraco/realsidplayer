/*
 * main.asm
 *
 *  Created: 2017-02-19 02:31:09
 *   Author: £ukasz 'Hank' Drzewiecki
 */


// The TEST define is used to improve simulator's performance
;#define TEST

#ifdef TEST
	.warning "Test mode enabled"
#endif

.def cr = r16			// common register
.def hr0 = r17			// helper register

.def rLineNumber = r25
.def rLineCycles = r24
.def rSP = r23
.def rFlags = r22
.def rY = r21
.def rX = r20
.def rA = r19
.def rCycles = r18


.equ SID_CS_bp = 6			// CS line bit position
.equ SID_CS_bm = 0x40		// CS line bit map

.equ SID_RESET_bp = 4		// RESET line bit position
.equ SID_RESET_bm = 0x10	// RESET line bit map

.equ SID_CLK_bp = 0			// CLOCK line bit position
.equ SID_CLK_bm = 0x01		// CLOCK line bit map


.org 0
	jmp start
.org TCC0_OVF_vect
	jmp TCC0_OVF_handler

.cseg

.include "epu.asm"

.include "c64_resources.inc"

start:
	cli

/* clock setup */
	ldi cr, OSC_XOSCEN_bm			// external clock source (here 7.88 MHz)..
	;ldi cr, OSC_RC32MEN_bm			// ..or internal 32 MHz oscillator
	sts OSC_CTRL, cr

clk_ready:
	lds cr, OSC_STATUS
	sbrs cr, OSC_XOSCRDY_bp			// external clock source (here 7.88 MHz)..
	;sbrs cr, OSC_RC32MRDY_bp		// ..or internal 32 MHz oscillator
	rjmp clk_ready

	ldi cr, CCP_IOREG_gc
	sts CPU_CCP, cr
	ldi cr, CLK_SCLKSEL_XOSC_gc		// external clock source (here 7.88 MHz)..
	;ldi cr, CLK_SCLKSEL_RC32M_gc	// ..or internal 32 MHz oscillator
	sts CLK_CTRL, cr
/* end of clock setup */

/* PLL setup */
	;ldi cr, OSC_PLLSRC_RC32M_gc		// base frequency is 32MHz, but internally is divided by 4, so effective frequency is 8MHz
	;ori cr, 8							// multiply base frequency 8 times - to get 64MHz

	ldi cr, OSC_PLLSRC_XOSC_gc		// base frequency here is 7.88Mhz
	ori cr, 8						// multiply base frequency 8 times - to get 63.04MHz

	sts OSC_PLLCTRL, cr

	ldi cr, OSC_PLLEN_bm
	sts OSC_CTRL, cr

pll_ready:
	lds cr, OSC_STATUS
	sbrs cr, OSC_PLLRDY_bp
	rjmp pll_ready

	ldi cr, CCP_IOREG_gc
	sts CPU_CCP, cr

	ldi cr, CLK_SCLKSEL_PLL_gc
	sts CLK_CTRL, cr
/* end of PLL setup */


/* PWM 1MHz timer setup on pin E0 */
	ldi cr, TC0_CCAEN_bm | TC_WGMODE_SINGLESLOPE_gc		// Single-slope mode. Produces PWM 1MHz on pin E0 (c64 system clock) without generating interrupts
	sts TCE0_CTRLB, cr									//

	ldi cr, 0x3f
	sts TCE0_PER, cr
	ldi cr, 0x00
	sts TCE0_PER + 1, cr

	ldi cr, 0x20-1			// !!! Czy 0 czy 1 czy 2 to jest bez znaczenia dla d³ugoœci zaka. Ta wartoœæ ma p³yw na na wype³nienie fali prostok¹tnej generowanej przez ten timer. Wp³yw na brzmienie ew. do zbadania. !!!
	sts TCE0_CCA, cr
	ldi cr, 0x00
	sts TCE0_CCA + 1, cr

	ldi cr, TC_CLKSEL_DIV1_gc	// prescaler 1x
	sts TCE0_CTRLA, cr			//
/* end of PWM timer setup */
	
	
	nop							// These ones are to ensure the right phase shift
	nop							// between CLK signal (configured above) and
	nop							// stepping C64 cycle interrupt (configured below this section of NOPs).
	nop							//
	nop							// The case is that the latter one controls the CS line 
	nop							// of SID chip putting it LOW (which enables writing to SID).
	nop							// This -has to- be done at a HIGH PHASE of C64's CLK clock cycle.
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//
	nop							//


/* interrupt 1MHz timer setup */
	ldi cr, TC_WGMODE_NORMAL_gc		// Normal mode. Generates interrupt every 64 XMEGA's cycles
	sts TCC0_CTRLB, cr				//

	ldi cr, TC_OVFINTLVL_LO_gc
	sts TCC0_INTCTRLA, cr
	ldi cr, PMIC_LOLVLEN_bm
	sts PMIC_CTRL, cr

	ldi cr, 0x40-1
	sts TCC0_PER, cr
	ldi cr, 0x00
	sts TCC0_PER+1, cr

	ldi cr, TC_CLKSEL_DIV1_gc		// prescaler 1x
	sts TCC0_CTRLA, cr
	/* */
	

	/* PORTS SETUP */

	// address bus
	ldi cr, 0xff
	sts PORTA_DIRSET, cr

	// data bus
	ldi cr, 0xff
	sts PORTD_DIRSET, cr

	// main bus
	ldi cr, 0xff
	sts PORTE_DIRSET, cr

	// hardware button ZAK INIT connected to line F0, pull-up line F0
	ldi cr, 0b11111110			; line F0 INPUT, rest OUTPUT
	sts PORTF_DIRSET, cr		;
	ldi cr, PORT_OPC_PULLUP_gc		; pull-up resistor enabled for F0
	sts PORTF_PIN0CTRL, cr			;


#ifndef TEST
	/* LOAD ZAK */
	ldi ZL, LOW(zak_code * 2)
	ldi ZH, HIGH(zak_code * 2)

	ldi YL, LOW(0x2000)
	ldi YH, HIGH(0x2000)

c0:	lpm cr, Z+
	st Y+, cr
	cpi ZL, LOW(zak_code_end * 2)
	brne c0
	cpi ZH, HIGH(zak_code_end * 2)
	brne c0
	/* */
#endif

	/* LOAD PLAYER PROGRAM */
	ldi ZL, LOW(c64_code * 2)
	ldi ZH, HIGH(c64_code * 2)

#ifndef TEST
	ldi YL, 0x00
	ldi YH, X_PLAYER_ROUTINE_ADDR_H
#else
	ldi YL, 0x10
	ldi YH, 0x28
#endif

c1:	lpm cr, Z+
	st Y+, cr
	cpi ZL, LOW(c64_code_end * 2)
	brne c1
	cpi ZH, HIGH(c64_code_end * 2)
	brne c1
	/* */

	sei

	jmp EPU_RESET


TCC0_OVF_handler:
	sbi GPIO_GPIOR0, 0	// 1
	reti				// 4 (from datasheet: return from an interrupt handling routine takes four to five clock cycles, depending on the size of the program counter)
