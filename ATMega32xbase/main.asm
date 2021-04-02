;
; ATMega32base.asm
;
; Created: 06.03.2021 10:17:44 PM
; Author : easyb
;

.include "include/x16base.inc"
.include "include/x32base.inc"


.equ DELAY		=100

.cseg

.org $00
rjmp reset

num: .dw $F11F

reset:
	
	ldi32 lx, UINT32_MAX
	
	subi32 lx, 1
		
	loop:
		rjmp loop


.include "lib/sdelay.asm"
