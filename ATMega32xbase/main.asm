;
; ATMega32base.asm
;
; Created: 06.03.2021 10:17:44 PM
; Author : easyb
;
.include "m32def.inc"
.include "include/x16base.inc"
.include "include/x32base.inc"
.include "include/x64base.inc"

.equ DELAY		=100

.cseg

.org $00
rjmp reset

num: .dw $F11F

reset:
	
	ldi16 lx, RAMEND
	out16 SP, lx

	ldi32 lx, 10
	ldi32 lxq, 10
			
	ldi64 lx, UINT64_MAX
	//ldi64 lxq, (UINT64_MAX - (1 << 14))

	sts64 $100, lx

    andi64 lx, (1 << 62)
	sts64 $100, lx

	ori64 lx, (1 << 61)
	sts64 $100, lx
	//call mul32s_tr	
	
	sts32 $100, lxq
				
	loop:
		rjmp loop



.include "lib/sdelay.asm"
.include "lib/x32mul.asm"
