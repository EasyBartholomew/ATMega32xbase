; ATMega32base.asm

.include "include/x64base.inc"
.include "include/x16base.inc"


.equ DELAY		=100

.cseg

.org $00
rjmp reset

num: .dw $F11F

reset:
	
	ldi16 lx, RAMEND
	out16 SP, lx
		
	add64 lx, lx
	inc64 lx

	nop
	nop	



	ldi16 lxqd, DELAY			
	call sdelay_us
		
	loop:
		rjmp loop


.include "lib/sdelay.asm"
