;
; ATMega32base.asm
;
; Created: 06.03.2021 10:17:44 PM
; Author : easyb
;

.include "include/x16base.inc"

.equ DELAY		=100

.cseg

.org $00
rjmp reset

num: .dw $F11F

reset:
	
	ldi16 lx, RAMEND
	out16 SP, lx
	
	nop
	nop	

	ldi16 lxqd, DELAY			
	call sdelay_us
		
	loop:
		rjmp loop


.include "lib/sdelay.asm"
