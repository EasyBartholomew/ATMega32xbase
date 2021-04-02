#ifndef _X32_AROP_INC_
#define _X32_AROP_INC_

	
	;	Adds two 32-bit virtual registers
	;	4 Cycles
.macro add32

	add @0l, @1l	;	Adds lower bytes without carry
	adc @0h, @1h	;	Add higher bytes with carry
	adc @0dl, @1dl	;	Add lower bytes of second word with carry
	adc @0dh, @1dh	;	Add higher bytes of second word with carry

.endmacro


	;	Adds two 32-bit virtual registers with carry
	;	4 Cycles
.macro adc32
	
	adc @0l, @1l	;	Adds lower bytes with carry
	adc @0h, @1h	;	Adds lower bytes with carry
	adc @0dl, @1dl	;	Adds lower bytes of second word with carry
	adc @0dh, @1dh	;	Adds lower bytes of second word with carry

.endmacro


	;	Subtracts two 32-bit virtual registers
	;	4 Cycles
.macro sub32

	sub @0l, @1l
	sbc @0h, @1h
	sbc @0dl, @1dl
	sbc @0dh, @1dh

.endmacro

	
	;	Subtracts two 32-bit virtual registers with carry
	;	4 Cycles
.macro sbc32
	
	sbc @0l, @1l
	sbc @0h, @1h
	sbc @0dl, @1dl
	sbc @0dh, @1dh

.endmacro 


	;	Subtracts two 32-bit virtual registers
	;	4 Cycles
.macro subi32

	subi @0l, LOW(@1)
	sbci @0h, BYTE2(@1)
	sbci @0dl, BYTE3(@1)
	sbci @0dh, BYTE4(@1)

.endmacro

	
	;	Subtracts two 32-bit virtual registers with carry
	;	4 Cycles
.macro sbci32
	
	sbci @0l, LOW(@1)
	sbci @0h, BYTE2(@1)
	sbci @0dl, BYTE3(@1)
	sbci @0dh, BYTE4(@1)

.endmacro 


	;	Increments 32-bit virtual register
	;	5 Cycles
.macro inc32 

	inc @0l		; Incrementing of lower byte	
	brne normal	; Jump if lower byte is overflowed
	nop				
	inc @0h		; Incrementing higher byte
	brne normal	; Jump if lower byte is overflowed
	nop				
	inc @0dl	; Incrementing higher byte
	brne normal	; Jump if lower byte is overflowed
	nop				
	inc @0dh	; Incrementing higher byte

	normal:

.endmacro


	;	Decrements 32-bit virtual register
	;	5 Cycles
.macro dec32
	
	dec @0l
	brpl pos
	dec @0h
	brpl pos
	dec @0dl
	brpl pos
	dec @0dh

	pos:	

.endmacro


#endif

