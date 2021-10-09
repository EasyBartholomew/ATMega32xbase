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

	ldi32 lx, 5
	ldi32 lxq, -10
			
	call mul32s
	call x32s_trunc
	
	sts32 $100, lxq
				
	loop:
		rjmp loop



.include "lib/sdelay.asm"
.include "lib/x32mul.asm"
.include "lib/x32trunc.asm"
