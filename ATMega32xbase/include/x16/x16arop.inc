#ifndef _X16_AROP_INC_
#define _X16_AROP_INC_

	
	;	Adds 16bit numbers with carry
.macro add16

	add @0l, @1l	;	Adds lower bytes without carry
	adc @0h, @1h	;	Add higher bytes with carry

.endmacro

	
.macro sub16

	sub @0l, @1l
	sbc @0h, @0l

.endmacro

	;	Increments 16bit number 
.macro inc16 

	inc @0l		; Incrementing of lower byte	
	brne normal	; Jump if lower byte is overflowed				
	inc @0h		; Incrementing higher byte
	
	normal:

.endmacro


.macro dec16
	
	dec @0l
	brpl pos	
	dec @0h

	pos:	

.endmacro

#endif
