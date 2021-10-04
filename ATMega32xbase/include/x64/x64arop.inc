#ifndef _X64_AROP_INC_
#define _X64_AROP_INC_

.macro add64

	add @0l, @1l	;	Adds lower bytes without carry
	adc @0h, @1h	;	Add higher bytes with carry
	adc @0dl, @1dl
	adc @0dh, @1dh
	adc @0ql, @1ql
	adc @0qh, @1qh
	adc @0qdl, @1qdl
	adc @0qdh, @1qdh

.endmacro

.macro adc64

	adc @0l, @1l	;	Adds lower bytes without carry
	adc @0h, @1h	;	Add higher bytes with carry
	adc @0dl, @1dl
	adc @0dh, @1dh
	adc @0ql, @1ql
	adc @0qh, @1qh
	adc @0qdl, @1qdl
	adc @0qdh, @1qdh

.endmacro

.macro sub64

	sub @0l, @1l	;	Adds lower bytes without carry
	sbc @0h, @1h	;	Add higher bytes with carry
	sbc @0dl, @1dl
	sbc @0dh, @1dh
	sbc @0ql, @1ql
	sbc @0qh, @1qh
	sbc @0qdl, @1qdl
	sbc @0qdh, @1qdh

.endmacro

.macro sbc64

	sbc @0l, @1l	;	Adds lower bytes without carry
	sbc @0h, @1h	;	Add higher bytes with carry
	sbc @0dl, @1dl
	sbc @0dh, @1dh
	sbc @0ql, @1ql
	sbc @0qh, @1qh
	sbc @0qdl, @1qdl
	sbc @0qdh, @1qdh

.endmacro

.macro inc64

	inc @0l		; Incrementing of lower byte	
	brne normal	; Jump if lower byte is overflowed
	nop				
	inc @0h		; Incrementing higher byte
	brne normal
	nop
	inc @0dl
	brne normal
	nop
	inc @0dh
	brne normal
	nop
	inc @0ql
	brne normal
	nop
	inc @0qh
	brne normal
	nop
	inc @0qdl
	brne normal
	nop
	inc @0qdh
	
	normal:

.endmacro

.macro dec64
	
	dec @0l
	brpl pos
	dec @0h
	brpl pos
	dec @0dl
	brpl pos
	dec @0dh
	brpl pos
	dec @0ql
	brpl pos
	dec @0qh
	brpl pos
	dec @0qdl
	brpl pos
	dec @0qdh

	pos:	

.endmacro

.macro subi64

	subi @0l, LOW(@1)
	sbci @0h, BYTE2(@1)
	sbci @0dl, BYTE3(@1)
	sbci @0dh, BYTE4(@1)
	sbci @0ql, BYTE5(@1)
	sbci @0qh, BYTE6(@1)
	sbci @0qdl, BYTE7(@1)
	sbci @0qdh, BYTE8(@1)

.endmacro

.macro sbci64

	sbci @0l, LOW(@1)
	sbci @0h, BYTE2(@1)
	sbci @0dl, BYTE3(@1)
	sbci @0dh, BYTE4(@1)
	sbci @0ql, BYTE5(@1)
	sbci @0qh, BYTE6(@1)
	sbci @0qdl, BYTE7(@1)
	sbci @0qdh, BYTE8(@1)

.endmacro



#endif
