/*
 * epu_core.inc
 *
 *  Created: 2016-06-14 09:38:15
 *   Author: £ukasz 'Hank' Drzewiecki
 */ 
 

 .equ X_PLAYER_ROUTINE_ADDR_H = 0x3c
 .equ X_ZEROPAGE_ADDR_H = 0x3d
 .equ X_STACK_ADDR_H = 0x3e
 .equ X_FORBIDDEN_MEMORY_SINK_ADDR_H = 0x3f	// 0x3f <- watch out! Here is the ATxmega128A3U's stack as well!

 .equ X_ALLOWED_ADDRESS_BOTTOM = 0x20		// including
 .equ X_ALLOWED_ADDRESS_TOP = 0x40			// excluding


EPU_OPCODES_TABLE:

jmp op_00			// each of them takes 2 host's cycles
jmp op_01
jmp op_02
jmp op_03
jmp op_04
jmp op_05
jmp op_06
jmp op_07
jmp op_08
jmp op_09
jmp op_0a
jmp op_0b
jmp op_0c
jmp op_0d
jmp op_0e
jmp op_0f
jmp op_10
jmp op_11
jmp op_12
jmp op_13
jmp op_14
jmp op_15
jmp op_16
jmp op_17
jmp op_18
jmp op_19
jmp op_1a
jmp op_1b
jmp op_1c
jmp op_1d
jmp op_1e
jmp op_1f
jmp op_20
jmp op_21
jmp op_22
jmp op_23
jmp op_24
jmp op_25
jmp op_26
jmp op_27
jmp op_28
jmp op_29
jmp op_2a
jmp op_2b
jmp op_2c
jmp op_2d
jmp op_2e
jmp op_2f
jmp op_30
jmp op_31
jmp op_32
jmp op_33
jmp op_34
jmp op_35
jmp op_36
jmp op_37
jmp op_38
jmp op_39
jmp op_3a
jmp op_3b
jmp op_3c
jmp op_3d
jmp op_3e
jmp op_3f
jmp op_40
jmp op_41
jmp op_42
jmp op_43
jmp op_44
jmp op_45
jmp op_46
jmp op_47
jmp op_48
jmp op_49
jmp op_4a
jmp op_4b
jmp op_4c
jmp op_4d
jmp op_4e
jmp op_4f
jmp op_50
jmp op_51
jmp op_52
jmp op_53
jmp op_54
jmp op_55
jmp op_56
jmp op_57
jmp op_58
jmp op_59
jmp op_5a
jmp op_5b
jmp op_5c
jmp op_5d
jmp op_5e
jmp op_5f
jmp op_60
jmp op_61
jmp op_62
jmp op_63
jmp op_64
jmp op_65
jmp op_66
jmp op_67
jmp op_68
jmp op_69
jmp op_6a
jmp op_6b
jmp op_6c
jmp op_6d
jmp op_6e
jmp op_6f
jmp op_70
jmp op_71
jmp op_72
jmp op_73
jmp op_74
jmp op_75
jmp op_76
jmp op_77
jmp op_78
jmp op_79
jmp op_7a
jmp op_7b
jmp op_7c
jmp op_7d
jmp op_7e
jmp op_7f
jmp op_80
jmp op_81
jmp op_82
jmp op_83
jmp op_84
jmp op_85
jmp op_86
jmp op_87
jmp op_88
jmp op_89
jmp op_8a
jmp op_8b
jmp op_8c
jmp op_8d
jmp op_8e
jmp op_8f
jmp op_90
jmp op_91
jmp op_92
jmp op_93
jmp op_94
jmp op_95
jmp op_96
jmp op_97
jmp op_98
jmp op_99
jmp op_9a
jmp op_9b
jmp op_9c
jmp op_9d
jmp op_9e
jmp op_9f
jmp op_a0
jmp op_a1
jmp op_a2
jmp op_a3
jmp op_a4
jmp op_a5
jmp op_a6
jmp op_a7
jmp op_a8
jmp op_a9
jmp op_aa
jmp op_ab
jmp op_ac
jmp op_ad
jmp op_ae
jmp op_af
jmp op_b0
jmp op_b1
jmp op_b2
jmp op_b3
jmp op_b4
jmp op_b5
jmp op_b6
jmp op_b7
jmp op_b8
jmp op_b9
jmp op_ba
jmp op_bb
jmp op_bc
jmp op_bd
jmp op_be
jmp op_bf
jmp op_c0
jmp op_c1
jmp op_c2
jmp op_c3
jmp op_c4
jmp op_c5
jmp op_c6
jmp op_c7
jmp op_c8
jmp op_c9
jmp op_ca
jmp op_cb
jmp op_cc
jmp op_cd
jmp op_ce
jmp op_cf
jmp op_d0
jmp op_d1
jmp op_d2
jmp op_d3
jmp op_d4
jmp op_d5
jmp op_d6
jmp op_d7
jmp op_d8
jmp op_d9
jmp op_da
jmp op_db
jmp op_dc
jmp op_dd
jmp op_de
jmp op_df
jmp op_e0
jmp op_e1
jmp op_e2
jmp op_e3
jmp op_e4
jmp op_e5
jmp op_e6
jmp op_e7
jmp op_e8
jmp op_e9
jmp op_ea
jmp op_eb
jmp op_ec
jmp op_ed
jmp op_ee
jmp op_ef
jmp op_f0
jmp op_f1
jmp op_f2
jmp op_f3
jmp op_f4
jmp op_f5
jmp op_f6
jmp op_f7
jmp op_f8
jmp op_f9
jmp op_fa
jmp op_fb
jmp op_fc
jmp op_fd
jmp op_fe
jmp op_ff
;------------------------------------------------------------------------------- end of jump table


// macros handling addressing mode

.macro macro_GetAddr_Immediate		// lda #$aa
	movw Z, Y
	ld cr, Y+	// dummy load, just to increase Y vector
.endmacro

.macro macro_GetAddr_Zeropage		// lda $aa
	ld cr, Y+
	ldi ZH, X_ZEROPAGE_ADDR_H
	mov ZL, cr
.endmacro

.macro macro_GetAddr_ZeroPage_X		// lda $aa,x
	ld cr, Y+
	add cr, rX
	mov ZL, cr
	ldi ZH, X_ZEROPAGE_ADDR_H
.endmacro

.macro macro_GetAddr_ZeroPage_Y		// lda $aa,y
	ld cr, Y+
	add cr, rY
	mov ZL, cr
	ldi ZH, X_ZEROPAGE_ADDR_H
.endmacro

.macro macro_GetAddr_Absolute		// lda $aaaa
	ld cr, Y+
	mov ZL, cr
	ld hr0, Y+
	ldi cr, 0x10
	add hr0, cr	// address offset
	mov ZH, hr0

	cpi ZH, X_ALLOWED_ADDRESS_BOTTOM
	brsh PC + 2
	ldi ZH, X_FORBIDDEN_MEMORY_SINK_ADDR_H
.endmacro

.macro macro_GetAddr_Absolute_X		// lda $aaaa,x
	ld cr, Y+
	mov ZL, cr
	ld hr0, Y+
	ldi cr, 0x10
	add hr0, cr	// address offset
	mov ZH, hr0
	add ZL, rX
	brcc PC+2
	inc ZH

	cpi ZH, X_ALLOWED_ADDRESS_BOTTOM
	brsh PC + 2
	ldi ZH, X_FORBIDDEN_MEMORY_SINK_ADDR_H
.endmacro

.macro macro_GetAddr_Absolute_Y		// lda $aaaa,y
	ld cr, Y+
	mov ZL, cr
	ld hr0, Y+
	ldi cr, 0x10
	add hr0, cr	// address offset
	mov ZH, hr0
	add ZL, rY
	brcc PC+2
	inc ZH

	cpi ZH, X_ALLOWED_ADDRESS_BOTTOM
	brsh PC + 2
	ldi ZH, X_FORBIDDEN_MEMORY_SINK_ADDR_H
.endmacro

.macro macro_GetAddr_Indirect		// jmp ($aaaa)
	ld cr, Y+
	mov ZL, cr
	ld hr0, Y+
	ldi cr, 0x10
	add hr0, cr	// address offset
	mov ZH, hr0
	ld cr, Z+
	ld hr0, Z
	mov ZL, cr
	mov ZH, hr0

	cpi ZH, X_ALLOWED_ADDRESS_BOTTOM
	brsh PC + 2
	ldi ZH, X_FORBIDDEN_MEMORY_SINK_ADDR_H
.endmacro

.macro macro_GetAddr_Indirect_X		// lda ($aa,x)
	ld cr, Y+
	mov ZL, cr
	ldi ZH, X_ZEROPAGE_ADDR_H
	add ZL, rX
	brcc PC + 2
	inc ZH

	ld cr, Z+
	ld hr0, Z
	mov ZL, cr
	mov ZH, hr0

	ldi cr, 0x10
	add hr0, cr	// address offset
	mov ZH, hr0

	cpi ZH, X_ALLOWED_ADDRESS_BOTTOM
	brsh PC + 2
	ldi ZH, X_FORBIDDEN_MEMORY_SINK_ADDR_H
.endmacro

.macro macro_GetAddr_Indirect_Y		// lda ($aa),y
	ld cr, Y+
	mov ZL, cr
	ldi ZH, X_ZEROPAGE_ADDR_H

	ld cr, Z+
	ld hr0, Z
	mov ZL, cr
	mov ZH, hr0

	ldi cr, 0x10
	add hr0, cr	// address offset
	mov ZH, hr0

	add ZL, rY
	brcc PC + 2
	inc ZH

	cpi ZH, X_ALLOWED_ADDRESS_BOTTOM
	brsh PC + 2
	ldi ZH, X_FORBIDDEN_MEMORY_SINK_ADDR_H
.endmacro

.macro macro_GetAddr_Relative		// beq $aaaa
	movw Z, Y
	ld cr, Y+	; dummy load, just to increase Y vector

	cpi ZH, X_ALLOWED_ADDRESS_BOTTOM
	brsh PC + 2
	ldi ZH, X_FORBIDDEN_MEMORY_SINK_ADDR_H
.endmacro

;-------------------------------------------------------------------------------


// macros handling logic of each opcode supported by the emulator

.macro macro_ADC
	mov cr, rFlags
	clc
	sbrc cr, 0
	sec

	andi rFlags, ~(fN+fV+fZ+fC)

	ld cr, Z

	adc rA, cr

	in hr0, CPU_SREG

	brcc PC+2
	ori rFlags, fC

	out CPU_SREG, hr0
	brne PC+2
	ori rFlags, fZ

	out CPU_SREG, hr0
	brvc PC+2
	ori rFlags, fV

	out CPU_SREG, hr0
	brpl PC+2
	ori rFlags, fN

	jmp EPU_OPCODE_END
.endmacro

.macro macro_SBC
	mov cr, rFlags
	sec
	sbrc cr, 0
	clc

	andi rFlags, ~(fN+fV+fZ+fC)

	ld cr, Z

	sbc rA, cr

	in hr0, CPU_SREG

	brcs PC+2
	ori rFlags, fC

	cpi rA, 0
	brne PC+2
	ori rFlags, fZ

	out CPU_SREG, hr0
	brvc PC+2
	ori rFlags, fV

	out CPU_SREG, hr0
	brpl PC+2
	ori rFlags, fN

	jmp EPU_OPCODE_END
.endmacro

.macro macro_AND
	andi rFlags, ~(fN+fZ)

	ld cr, Z
	and rA, cr
	
	cpi rA, 0x80
	brlo PC + 2
	ori rFlags, fN
	
	cpi rA, 0
	brne PC + 2
	ori rFlags, fZ
	jmp EPU_OPCODE_END
.endmacro

.macro macro_ASL
	andi rFlags, ~(fZ+fN+fC)

	ld cr, Z

	lsl cr
	st Z, cr

	brcc PC + 2
	ori rFlags, fC

	cpi cr, 0
	brne PC + 2
	ori rFlags, fZ

	cpi cr, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END
.endmacro

.macro macro_BIT
	andi rFlags, ~(fZ+fN+fV)

	mov cr, rA
	ld hr0, Z

	and cr, hr0
	brne PC + 2
	ori rFlags, fZ

	sbrc hr0, 7
	ori rFlags, fN

	sbrc hr0, 6
	ori rFlags, fV

	jmp EPU_OPCODE_END
.endmacro

.macro macro_BRANCH
	ld cr, Z

	mov hr0, cr
	andi hr0, 0x80
	breq dodawaj

	com cr
	sec
	sbc YL, cr
	ldi cr, 0
	sbc YH, cr
	jmp EPU_OPCODE_END

dodawaj:
	clc
	adc YL, cr
	ldi cr, 0
	adc YH, cr
	jmp EPU_OPCODE_END
.endmacro

.macro macro_CMP
	andi rFlags, ~(fZ+fN)
	ori rFlags, fC

	ld cr, Z

	cp rA, cr
	brne PC + 2
	ori rFlags, fZ

	cp rA, cr
	brpl PC + 2
	ori rFlags, fN

	cp rA, cr
	brsh PC + 2
	andi rFlags, ~fC

	jmp EPU_OPCODE_END
.endmacro

.macro macro_CPX
	andi rFlags, ~(fZ+fN)
	ori rFlags, fC

	ld cr, Z

	cp rX, cr
	brne PC + 2
	ori rFlags, fZ

	cp rX, cr
	brpl PC + 2
	ori rFlags, fN

	cp rX, cr
	brsh PC + 2
	andi rFlags, ~fC

	jmp EPU_OPCODE_END
.endmacro

.macro macro_CPY
	andi rFlags, ~(fZ+fN)
	ori rFlags, fC

	ld cr, Z

	cp rY, cr
	brne PC + 2
	ori rFlags, fZ

	cp rY, cr
	brpl PC + 2
	ori rFlags, fN

	cp rY, cr
	brsh PC + 2
	andi rFlags, ~fC

	jmp EPU_OPCODE_END
.endmacro

.macro macro_EOR
	andi rFlags, ~(fZ+fN)

	ld cr, Z
	eor rA, cr

	cpi rA, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rA, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END
.endmacro

.macro macro_LDA
	andi rFlags, ~(fZ+fN)

	ld rA, Z

	cpi rA, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rA, 0x80
	brlo PC + 2
	ori rFlags, fN
	
	jmp EPU_OPCODE_END
.endmacro

.macro macro_LDX
	andi rFlags, ~(fZ+fN)

	ld rX, Z

	cpi rX, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rX, 0x80
	brlo PC + 2
	ori rFlags, fN
	
	jmp EPU_OPCODE_END
.endmacro

.macro macro_LDY
	andi rFlags, ~(fZ+fN)

	ld rY, Z

	cpi rY, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rY, 0x80
	brlo PC + 2
	ori rFlags, fN
	
	jmp EPU_OPCODE_END
.endmacro

.macro macro_LSR
	andi rFlags, ~(fZ+fN+fC)

	ld cr, Z

	lsr cr
	st Z, cr

	brcc PC + 2
	ori rFlags, fC

	cpi cr, 0x00
	brne PC + 2
	ori rFlags, fZ

	cpi cr, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END
.endmacro

.macro macro_ORA
	andi rFlags, ~(fZ+fN)

	ld cr, Z
	or rA, cr
	
	brne PC + 2
	ori rFlags, fZ
	
	cpi rA, 0x80
	brlo PC + 2
	ori rFlags, fN
	
	jmp EPU_OPCODE_END
.endmacro

.macro macro_ROL
	mov cr, rFlags

	andi rFlags, ~(fZ+fN+fC)

	ld hr0, Z

	clc
	sbrc cr, 0
	sec
	rol hr0
	st Z, hr0

	brcc PC + 2
	ori rFlags, fC

	cpi hr0, 0
	brne PC + 2
	ori rFlags, fZ

	cpi hr0, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END
.endmacro

.macro macro_ROR
	mov cr, rFlags

	andi rFlags, ~(fZ+fN+fC)

	ld hr0, Z

	clc
	sbrc cr, 0
	sec
	ror hr0
	st Z, hr0

	brcc PC + 2
	ori rFlags, fC

	cpi hr0, 0
	brne PC + 2
	ori rFlags, fZ

	cpi hr0, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END
.endmacro

;-------------------------------------------------------------------------------

// The ones below are special cases as they may enable SID data transfer

.macro macro_STA
	cpi ZH, X_ALLOWED_ADDRESS_TOP
	brsh mSTA
	st Z, rA
mSTA_end:
	jmp EPU_OPCODE_END
	cpi ZH, 0xe4
	brne mSTA_end
mSTA:
	sts PORTD_OUT, rA		// data port
	sts PORTA_OUT, ZL		// address port (A0-A4)

	ldi cr, SID_CS_bm
	sts PORTE_OUTCLR, cr	// enable SID data transfer

	jmp EPU_OPCODE_END
.endmacro

.macro macro_STX
	cpi ZH, X_ALLOWED_ADDRESS_TOP
	brsh mSTX
	st Z, rX
mSTX_end:
	jmp EPU_OPCODE_END
	cpi ZH, 0xe4
	brne mSTX_end
mSTX:
	sts PORTD_OUT, rX		// data port
	sts PORTA_OUT, ZL		// address port (A0-A4)

	ldi cr, SID_CS_bm
	sts PORTE_OUTCLR, cr	// enable SID data transfer
	
	jmp EPU_OPCODE_END
.endmacro

.macro macro_STY
	cpi ZH, X_ALLOWED_ADDRESS_TOP
	brsh mSTY
	st Z, rY
mSTY_end:
	jmp EPU_OPCODE_END
	cpi ZH, 0xe4
	brne mSTY_end
mSTY:
	sts PORTD_OUT, rY		// data port
	sts PORTA_OUT, ZL		// address port (A0-A4)

	ldi cr, SID_CS_bm
	sts PORTE_OUTCLR, cr	// enable SID data transfer

	jmp EPU_OPCODE_END
.endmacro

.macro macro_DEC
	andi rFlags, ~(fZ+fN)

	ld cr, Z
	dec cr

	brne PC + 2
	ori rFlags, fZ

	cpi cr, 0x80
	brlo PC + 2
	ori rFlags, fN

	cpi ZH, X_ALLOWED_ADDRESS_TOP
	brsh mDEC
	st Z, cr
mDEC_end:
	jmp EPU_OPCODE_END
mDEC:
	cpi ZH, 0xe4
	brne mDEC_end

	sts PORTD_OUT, cr		// data port
	sts PORTA_OUT, ZL		// address port (A0-A4)

	ldi cr, SID_CS_bm
	sts PORTE_OUTCLR, cr	// enable SID data transfer

	jmp EPU_OPCODE_END
.endmacro

.macro macro_INC
	andi rFlags, ~(fZ+fN)

	ld cr, Z
	inc cr

	brne PC + 2
	ori rFlags, fZ

	cpi cr, 0x80
	brlo PC + 2
	ori rFlags, fN

	cpi ZH, X_ALLOWED_ADDRESS_TOP
	brsh mINC
	st Z, cr
mINC_end:
	jmp EPU_OPCODE_END
mINC:
	cpi ZH, 0xe4
	brne mINC_end

	sts PORTD_OUT, cr		// data port
	sts PORTA_OUT, ZL		// address port

	ldi cr, SID_CS_bm
	sts PORTE_OUTCLR, cr	// enable SID data transfer

	jmp EPU_OPCODE_END
.endmacro

;------------------------------------------------------------------------------- end of macros


// Implementation of each opcode

op_00: // BRK implied
	
	ldi rCycles, 255	// 255 simply for debug purposes

	jmp EPU_OPCODE_END

op_01: // ORA indirect x
	ldi rCycles, 6 - 1
	macro_GetAddr_Indirect_X
	macro_ORA

op_02: jmp EPU_OPCODE_END
op_03: jmp EPU_OPCODE_END
op_04: jmp EPU_OPCODE_END

op_05: // ORA zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_ORA

op_06: // ASL zeropage
	ldi rCycles, 5 - 1
	macro_GetAddr_Zeropage
	macro_ASL

op_07: jmp EPU_OPCODE_END

op_08: // PHP implied
	ldi rCycles, 3 - 1

	ldi ZH, X_STACK_ADDR_H
	mov ZL, rSP

	st Z, rFlags

	dec rSP

	jmp EPU_OPCODE_END

op_09: // ORA immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_ORA

op_0a: // ASL accumulator
	ldi rCycles, 2 - 1

	andi rFlags, ~(fZ+fN+fC)

	lsl rA

	brcc PC + 2
	ori rFlags, fC

	cpi rA, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rA, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END

op_0b: jmp EPU_OPCODE_END
op_0c: jmp EPU_OPCODE_END

op_0d: // ORA absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_ORA

op_0e: // ASL absolute
	ldi rCycles, 6 - 1
	macro_GetAddr_Absolute
	macro_ASL

op_0f: jmp EPU_OPCODE_END

op_10: // BPL relative
	ldi rCycles, 2 - 1
	macro_GetAddr_Relative

	sbrc rFlags, 7	; fN
	jmp EPU_OPCODE_END

	inc rCycles

	macro_BRANCH

op_11: // ORA indirect y
	ldi rCycles, 5 - 1
	macro_GetAddr_Indirect_Y
	macro_ORA

op_12: jmp EPU_OPCODE_END
op_13: jmp EPU_OPCODE_END
op_14: jmp EPU_OPCODE_END

op_15: // ORA zeropage x
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_X
	macro_ORA

op_16: // ASL zeropage x
	ldi rCycles, 6 - 1
	macro_GetAddr_Zeropage_X
	macro_ASL

op_17: jmp EPU_OPCODE_END

op_18: // CLC implied
	ldi rCycles, 2 - 1
	andi rFlags, ~fC
	jmp EPU_OPCODE_END

op_19: // ORA absolute y
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_Y
	macro_ORA

op_1a: jmp EPU_OPCODE_END
op_1b: jmp EPU_OPCODE_END
op_1c: jmp EPU_OPCODE_END

op_1d: // ORA absolute x
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_X
	macro_ORA

op_1e: // ASL absolute x
	ldi rCycles, 7 - 1
	macro_GetAddr_Absolute_X
	macro_ASL

op_1f: jmp EPU_OPCODE_END

op_20: // JSR absolute
	ldi rCycles, 6 - 1
	macro_GetAddr_Absolute

	ld cr, -Y		; dummy load to decrease Y for JSR purposes
	mov cr, YL
	mov hr0, YH

	movw Y, Z

	ldi ZH, X_STACK_ADDR_H
	mov ZL, rSP

	st Z, hr0
	st -Z, cr

	dec rSP
	dec rSP

	jmp EPU_OPCODE_END

op_21: // AND indirect x
	ldi rCycles, 6 - 1
	macro_GetAddr_Indirect_X
	macro_AND

op_22: jmp EPU_OPCODE_END
op_23: jmp EPU_OPCODE_END

op_24: // BIT zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_BIT

op_25: // AND zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_AND

op_26: // ROL zeropage
	ldi rCycles, 5 - 1
	macro_GetAddr_Zeropage
	macro_ROL

op_27: jmp EPU_OPCODE_END

op_28: // PLP implied
	ldi rCycles, 4 - 1

	inc rSP

	ldi ZH, X_STACK_ADDR_H
	mov ZL, rSP

	ld rFlags, Z

	jmp EPU_OPCODE_END

op_29: // AND immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_AND

op_2a: // ROL accumulator
	ldi rCycles, 2 - 1

	mov cr, rFlags

	andi rFlags, ~(fZ+fN+fC)

	clc
	sbrc cr, 0
	sec
	rol rA

	brcc PC + 2
	ori rFlags, fC

	cpi rA, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rA, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END

op_2b: jmp EPU_OPCODE_END

op_2c: // BIT absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_BIT

op_2d: // AND absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_AND

op_2e: // ROL absolute
	ldi rCycles, 6 - 1
	macro_GetAddr_Absolute
	macro_ROL

op_2f: jmp EPU_OPCODE_END

op_30: // BPL relative
	ldi rCycles, 2 - 1
	macro_GetAddr_Relative

	sbrs rFlags, 7	; fN
	jmp EPU_OPCODE_END

	inc rCycles

	macro_BRANCH

op_31: // AND indirect y
	ldi rCycles, 5 - 1
	macro_GetAddr_Indirect_Y
	macro_AND

op_32: jmp EPU_OPCODE_END
op_33: jmp EPU_OPCODE_END
op_34: jmp EPU_OPCODE_END

op_35: // AND zeropage x
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_X
	macro_AND

op_36: // ROL zeropage x
	ldi rCycles, 6 - 1
	macro_GetAddr_Zeropage_X
	macro_ROL

op_37: jmp EPU_OPCODE_END

op_38: // SEC implied
	ldi rCycles, 2 - 1
	ori rFlags, fC
	jmp EPU_OPCODE_END

op_39: // AND absolute y
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_Y
	macro_AND

op_3a: jmp EPU_OPCODE_END
op_3b: jmp EPU_OPCODE_END
op_3c: jmp EPU_OPCODE_END

op_3d: // AND absolute x
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_X
	macro_AND

op_3e: // ROL absolute x
	ldi rCycles, 7 - 1
	macro_GetAddr_Absolute_X
	macro_ROL

op_3f: jmp EPU_OPCODE_END

op_40: // RTI implied				// NOT IMPLEMENTED NOW, GO TO BRK
	rjmp op_00

op_41: // EOR indirect x
	ldi rCycles, 6 - 1
	macro_GetAddr_Indirect_X
	macro_EOR

op_42: jmp EPU_OPCODE_END
op_43: jmp EPU_OPCODE_END
op_44: jmp EPU_OPCODE_END

op_45: // EOR zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_EOR

op_46: // LSR zeropage
	ldi rCycles, 5 - 1
	macro_GetAddr_Zeropage
	macro_LSR

op_47: jmp EPU_OPCODE_END

op_48: // PHA implied
	ldi rCycles, 3 - 1

	ldi ZH, X_STACK_ADDR_H
	mov ZL, rSP

	st Z, rA

	dec rSP

	jmp EPU_OPCODE_END

op_49: // EOR immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_EOR

op_4a: // LSR accumulator
	ldi rCycles, 2 - 1

	andi rFlags, ~(fZ+fN+fC)

	lsr rA

	brcc PC + 2
	ori rFlags, fC

	cpi rA, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rA, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END

op_4b: jmp EPU_OPCODE_END

op_4c: // JMP absolute
	ldi rCycles, 3 - 1
	macro_GetAddr_Absolute

	movw Y, Z
	jmp EPU_OPCODE_END

op_4d: // EOR absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_EOR

op_4e: // LSR absolute
	ldi rCycles, 6 - 1
	macro_GetAddr_Absolute
	macro_LSR

op_4f: jmp EPU_OPCODE_END

op_50: // BVC relative
	ldi rCycles, 2 - 1
	macro_GetAddr_Relative

	sbrc rFlags, 6	; fV
	jmp EPU_OPCODE_END

	inc rCycles

	macro_BRANCH

op_51: // EOR indirect y
	ldi rCycles, 5 - 1
	macro_GetAddr_Indirect_Y
	macro_EOR

op_52: jmp EPU_OPCODE_END
op_53: jmp EPU_OPCODE_END
op_54: jmp EPU_OPCODE_END

op_55: // EOR zeropage x
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_X
	macro_EOR

op_56: // LSR zeropage x
	ldi rCycles, 6 - 1
	macro_GetAddr_Zeropage_X
	macro_LSR

op_57: jmp EPU_OPCODE_END

op_58: // CLI implied
	ldi rCycles, 2 - 1
	andi rFlags, ~fI
	jmp EPU_OPCODE_END

op_59: // EOR absolute y
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_Y
	macro_EOR

op_5a: jmp EPU_OPCODE_END
op_5b: jmp EPU_OPCODE_END
op_5c: jmp EPU_OPCODE_END

op_5d: // EOR absolute x
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_X
	macro_EOR

op_5e: // LSR absolute x
	ldi rCycles, 7 - 1
	macro_GetAddr_Absolute_X
	macro_LSR

op_5f: jmp EPU_OPCODE_END

op_60: // RTS implied
	ldi rCycles, 6 - 1

	inc rSP

	ldi ZH, X_STACK_ADDR_H
	mov ZL, rSP

	ld cr, Z+
	ld hr0, Z

	inc rSP

	mov YL, cr
	mov YH, hr0

	ld cr, Y+	; dummy load to increase Y for RTS purposes

	jmp EPU_OPCODE_END

op_61: // ADC indirect x
	ldi rCycles, 6 - 1
	macro_GetAddr_Indirect_X
	macro_ADC

op_62: jmp EPU_OPCODE_END
op_63: jmp EPU_OPCODE_END
op_64: jmp EPU_OPCODE_END

op_65: // ADC zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_ADC

op_66: // ROR zeropage
	ldi rCycles, 5 - 1
	macro_GetAddr_Zeropage
	macro_ROR

op_67: jmp EPU_OPCODE_END

op_68: // PLA implied
	ldi rCycles, 4 - 1

	inc rSP

	ldi ZH, X_STACK_ADDR_H
	mov ZL, rSP

	ld rA, Z

	jmp EPU_OPCODE_END

op_69: // ADC immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_ADC

op_6a: // ROR accumulator
	ldi rCycles, 2 - 1

	mov cr, rFlags

	andi rFlags, ~(fZ+fN+fC)

	clc
	sbrc cr, 0
	sec
	ror rA

	brcc PC + 2
	ori rFlags, fC

	cpi rA, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rA, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END

op_6b: jmp EPU_OPCODE_END

op_6c: // JMP indirect
	ldi rCycles, 5 - 1
	macro_GetAddr_Indirect

	movw Y, Z
	jmp EPU_OPCODE_END

op_6d: // ADC absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_ADC

op_6e: // ROR absolute
	ldi rCycles, 6 - 1
	macro_GetAddr_Absolute
	macro_ROR

op_6f: jmp EPU_OPCODE_END

op_70: // BVC relative
	ldi rCycles, 2 - 1
	macro_GetAddr_Relative

	sbrs rFlags, 6	; fV
	jmp EPU_OPCODE_END

	inc rCycles

	macro_BRANCH

op_71: // ADC indirect y
	ldi rCycles, 5 - 1
	macro_GetAddr_Indirect_Y
	macro_ADC

op_72: jmp EPU_OPCODE_END
op_73: jmp EPU_OPCODE_END
op_74: jmp EPU_OPCODE_END

op_75: // ADC zeropage x
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_X
	macro_ADC
	
op_76: // ROR zeropage x
	ldi rCycles, 6 - 1
	macro_GetAddr_Zeropage_X
	macro_ROR

op_77: jmp EPU_OPCODE_END

op_78: // SEI implied
	ldi rCycles, 2 - 1
	ori rFlags, fI
	jmp EPU_OPCODE_END

op_79: // ADC absolute y
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_Y
	macro_ADC

op_7a: jmp EPU_OPCODE_END
op_7b: jmp EPU_OPCODE_END
op_7c: jmp EPU_OPCODE_END

op_7d: // ADC absolute x
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_X
	macro_ADC

op_7e: // ROR absolute x
	ldi rCycles, 7 - 1
	macro_GetAddr_Absolute_X
	macro_ROR

op_7f: jmp EPU_OPCODE_END
op_80: jmp EPU_OPCODE_END

op_81: // STA indirect x
	ldi rCycles, 6 - 1
	macro_GetAddr_Indirect_X
	macro_STA

op_82: jmp EPU_OPCODE_END
op_83: jmp EPU_OPCODE_END

op_84: // STY zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_STY

op_85: // STA zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_STA

op_86: // STX zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_STX

op_87: jmp EPU_OPCODE_END

op_88: // DEY implied
	ldi rCycles, 2 - 1
	
	andi rFlags, ~(fZ+fN)

	dec rY

	brne PC + 2
	ori rFlags, fZ

	cpi rY, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END

op_89: jmp EPU_OPCODE_END

op_8a: // TXA implied
	ldi rCycles, 2 - 1

	andi rFlags, ~(fZ+fN)

	mov rA, rX

	cpi rA, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rA, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END

op_8b: jmp EPU_OPCODE_END

op_8c: // STY absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_STY

op_8d: // STA absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_STA

op_8e: // STX absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_STX

op_8f: jmp EPU_OPCODE_END

op_90: // BCC relative
	ldi rCycles, 2 - 1
	macro_GetAddr_Relative

	sbrc rFlags, 0x00	; fC
	jmp EPU_OPCODE_END

	inc rCycles

	macro_BRANCH

op_91: // STA indirect y
	ldi rCycles, 6 - 1
	macro_GetAddr_Indirect_Y
	macro_STA

op_92: jmp EPU_OPCODE_END
op_93: jmp EPU_OPCODE_END

op_94: // STY zeropage x
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_X
	macro_STY

op_95: // STA zeropage x
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_X
	macro_STA

op_96: // STX zeropage y
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_Y
	macro_STX

op_97: jmp EPU_OPCODE_END

op_98: // TYA implied
	ldi rCycles, 2 - 1

	andi rFlags, ~(fZ+fN)

	mov rA, rY

	cpi rA, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rA, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END

op_99: // STA absolute y
	ldi rCycles, 5 - 1
	macro_GetAddr_Absolute_Y
	macro_STA

op_9a: // TXS implied
	ldi rCycles, 2 - 1
	mov rSP, rX
	jmp EPU_OPCODE_END

op_9b: jmp EPU_OPCODE_END
op_9c: jmp EPU_OPCODE_END

op_9d: // STA absolute x
	ldi rCycles, 5 - 1
	macro_GetAddr_Absolute_X
	macro_STA

op_9e: jmp EPU_OPCODE_END
op_9f: jmp EPU_OPCODE_END

op_a0: // LDY immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_LDY

op_a1: // LDA indirect x
	ldi rCycles, 6 - 1
	macro_GetAddr_Indirect_X
	macro_LDA

op_a2: // LDX immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_LDX

op_a3: jmp EPU_OPCODE_END

op_a4: // LDY zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_LDY

op_a5: // LDA zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_LDA

op_a6: // LDX zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_LDX

op_a7: jmp EPU_OPCODE_END

op_a8: // TAY implied
	ldi rCycles, 2 - 1

	andi rFlags, ~(fZ+fN)

	mov rY, rA

	cpi rY, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rY, 0x80
	brlo PC + 2
	ori rFlags, fN
	
	jmp EPU_OPCODE_END

op_a9: // LDA immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_LDA

op_aa: // TAX implied
	ldi rCycles, 2 - 1

	andi rFlags, ~(fZ+fN)

	mov rX, rA

	cpi rX, 0
	brne PC + 2
	ori rFlags, fZ

	cpi rX, 0x80
	brlo PC + 2
	ori rFlags, fN
	
	jmp EPU_OPCODE_END

op_ab: jmp EPU_OPCODE_END

op_ac: // LDY absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_LDY

op_ad: // LDA absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_LDA

op_ae: // LDX absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_LDX

op_af: jmp EPU_OPCODE_END

op_b0: // BCS relative
	ldi rCycles, 2 - 1
	macro_GetAddr_Relative

	sbrs rFlags, 0x00	; fC
	jmp EPU_OPCODE_END

	inc rCycles

	macro_BRANCH

op_b1: // LDA indirect y
	ldi rCycles, 5 - 1
	macro_GetAddr_Indirect_Y
	macro_LDA

op_b2: jmp EPU_OPCODE_END
op_b3: jmp EPU_OPCODE_END

op_b4: // LDY zeropage x
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_X
	macro_LDY

op_b5: // LDA zeropage x
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_X
	macro_LDA

op_b6: // LDX zeropage y
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_Y
	macro_LDX

op_b7: jmp EPU_OPCODE_END

op_b8: // CLV implied
	ldi rCycles, 2 - 1
	andi rFlags, ~fV
	jmp EPU_OPCODE_END

op_b9: // LDA absolute y
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_Y
	macro_LDA

op_ba: // TSX implied
	ldi rCycles, 2 - 1
	mov rX, rSP
	jmp EPU_OPCODE_END

op_bb: jmp EPU_OPCODE_END

op_bc: // LDY absolute x
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_X
	macro_LDY

op_bd: // LDA absolute x
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_X
	macro_LDA

op_be: // LDX absolute y
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_Y
	macro_LDX

op_bf: jmp EPU_OPCODE_END

op_c0: // CPY immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_CPY

op_c1: // CMP indirect x
	ldi rCycles, 6 - 1
	macro_GetAddr_Indirect_X

	macro_CMP

op_c2: jmp EPU_OPCODE_END
op_c3: jmp EPU_OPCODE_END

op_c4: // CPY zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage

	macro_CPY

op_c5: // CMP zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage

	macro_CMP

op_c6: // DEC zeropage
	ldi rCycles, 5 - 1
	macro_GetAddr_Zeropage
	macro_DEC

op_c7: jmp EPU_OPCODE_END

op_c8: // INY implied
	ldi rCycles, 2 - 1
	
	andi rFlags, ~(fZ+fN)

	inc rY

	brne PC + 2
	ori rFlags, fZ

	cpi rY, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END

op_c9: // CMP immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_CMP

op_ca: // DEX implied
	ldi rCycles, 2 - 1
	
	andi rFlags, ~(fZ+fN)

	dec rX

	brne PC + 2
	ori rFlags, fZ

	cpi rX, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END

op_cb: jmp EPU_OPCODE_END

op_cc: // CPY absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute

	macro_CPY

op_cd: // CMP absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute

	macro_CMP

op_ce: // DEC absolute
	ldi rCycles, 6 - 1
	macro_GetAddr_Absolute
	macro_DEC

op_cf: jmp EPU_OPCODE_END

op_d0: // BNE relative
	ldi rCycles, 2 - 1
	macro_GetAddr_Relative

	sbrc rFlags, 1	; fZ
	jmp EPU_OPCODE_END

	inc rCycles

	macro_BRANCH

op_d1: // CMP indirect y
	ldi rCycles, 5 - 1
	macro_GetAddr_Indirect_Y

	macro_CMP

op_d2: jmp EPU_OPCODE_END
op_d3: jmp EPU_OPCODE_END
op_d4: jmp EPU_OPCODE_END

op_d5: // CMP zeropage x
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_X

	macro_CMP

op_d6: // DEC zeropage x
	ldi rCycles, 6 - 1
	macro_GetAddr_Zeropage_X
	macro_DEC

op_d7: jmp EPU_OPCODE_END

op_d8: // CLD implied
	ldi rCycles, 2 - 1
	andi rFlags, ~fD
	jmp EPU_OPCODE_END

op_d9: // CMP absolute y
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_Y

	macro_CMP

op_da: jmp EPU_OPCODE_END
op_db: jmp EPU_OPCODE_END
op_dc: jmp EPU_OPCODE_END

op_dd: // CMP absolute x
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_X

	macro_CMP

op_de: // DEC absolute x
	ldi rCycles, 7 - 1
	macro_GetAddr_Absolute_X
	macro_DEC

op_df: jmp EPU_OPCODE_END

op_e0: // CPX immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_CPX

op_e1: // SBC indirect x
	ldi rCycles, 6 - 1
	macro_GetAddr_Indirect_X
	macro_SBC

op_e2: jmp EPU_OPCODE_END
op_e3: jmp EPU_OPCODE_END

op_e4: // CPX zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage

	macro_CPX

op_e5: // SBC zeropage
	ldi rCycles, 3 - 1
	macro_GetAddr_Zeropage
	macro_SBC

op_e6: // INC zeropage
	ldi rCycles, 5 - 1
	macro_GetAddr_Zeropage
	macro_INC

op_e7: jmp EPU_OPCODE_END

op_e8: // INX implied
	ldi rCycles, 2 - 1
	
	andi rFlags, ~(fZ+fN)

	inc rX

	brne PC + 2
	ori rFlags, fZ

	cpi rX, 0x80
	brlo PC + 2
	ori rFlags, fN

	jmp EPU_OPCODE_END

op_e9: // SBC immediate
	ldi rCycles, 2 - 1
	macro_GetAddr_Immediate
	macro_SBC

op_ea: // NOP implied
	ldi rCycles, 2 - 1
	jmp EPU_OPCODE_END

op_eb: jmp EPU_OPCODE_END

op_ec: // CPX absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute

	macro_CPX

op_ed: // SBC absolute
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute
	macro_SBC

op_ee: // INC absolute
	ldi rCycles, 6 - 1
	macro_GetAddr_Absolute
	macro_INC

op_ef: jmp EPU_OPCODE_END

op_f0: // BNE relative
	ldi rCycles, 2 - 1
	macro_GetAddr_Relative

	sbrs rFlags, 1	; fZ
	jmp EPU_OPCODE_END

	inc rCycles

	macro_BRANCH

op_f1: // SBC indirect y
	ldi rCycles, 5 - 1
	macro_GetAddr_Indirect_Y
	macro_SBC

op_f2: jmp EPU_OPCODE_END
op_f3: jmp EPU_OPCODE_END
op_f4: jmp EPU_OPCODE_END

op_f5: // SBC zeropage x
	ldi rCycles, 4 - 1
	macro_GetAddr_Zeropage_X
	macro_SBC

op_f6: // INC zeropage x
	ldi rCycles, 6 - 1
	macro_GetAddr_Zeropage_X
	macro_INC

op_f7: jmp EPU_OPCODE_END
op_f8: // SED implied
	ldi rCycles, 2 - 1
	ori rFlags, fD
	jmp EPU_OPCODE_END

op_f9: // SBC absolute y
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_Y
	macro_SBC

op_fa: jmp EPU_OPCODE_END
op_fb: jmp EPU_OPCODE_END
op_fc: jmp EPU_OPCODE_END

op_fd: // SBC absolute x
	ldi rCycles, 4 - 1
	macro_GetAddr_Absolute_X
	macro_SBC

op_fe: // INC absolute x
	ldi rCycles, 7 - 1
	macro_GetAddr_Absolute_X
	macro_INC

op_ff: rjmp EPU_OPCODE_END

;------------------------
