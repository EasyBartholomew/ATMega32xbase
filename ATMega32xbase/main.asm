;
; ATMega32base.asm
;
; Created: 06.03.2021 10:17:44 PM
; Author : easyb
;

.include "include/x16base.inc"


.cseg

.org $00
rjmp reset


reset:

	ldi16 lx, UINT16_MIN

	loop:
		
		inc16 lx
		cpi16 lx, 3
		brne loop
	
	sts16 $0100, lx
			
	start:    	
		rjmp start
