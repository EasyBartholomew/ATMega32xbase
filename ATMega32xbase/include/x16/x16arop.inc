#ifndef _X16_AROP_INC_
#define _X16_AROP_INC_

	
	;	Adds two 16-bit virtual registers
	;	2 Cycles
.macro add16

	add @0l, @1l	;	Adds lower bytes without carry
	adc @0h, @1h	;	Add higher bytes with carry

.endmacro


	;	Adds two 16-bit virtual registers with carry
	;	2 Cycles
.macro adc16
	
	adc @0l, @1l	;	Adds lower bytes with carry
	adc @0h, @1h	;	Adds lower bytes with carry

.endmacro


	;	Subtracts two 16-bit virtual registers
	;	2 Cycles
.macro sub16

	sub @0l, @1l
	sbc @0h, @0l

.endmacro

	
	;	Subtracts two 16-bit virtual registers with carry
	;	2 Cycles
.macro sbc16
	
	sbc @0l, @1l
	sbc @0h, @0l

.endmacro 


	;	Increments 16-bit virtual register
	;	4 Cycles
.macro inc16 

	inc @0l		; Incrementing of lower byte	
	brne normal	; Jump if lower byte is overflowed
	nop				
	inc @0h		; Incrementing higher byte
	
	normal:

.endmacro


	;	Decrements 16-bit virtual register
	;	4 Cycles
.macro dec16
	
	dec @0l
	brpl pos
	dec @0h

	pos:	

.endmacro


#endif
