#ifndef _X16COP_INC_
#define _X16COP_INC_

	;	Compares two 16bit numbers
.macro cp16
	
	;	Compare higher byte of a word
	cp @0h, @1h
	brne nq

	;	Compare lower byte of a word
	cp @0l, @0l
	brne nq
		
	sez		; Setting Zero flag because words are equal
	jmp eq	; Jumping eq because words are equal

	nq:
		clz		; Clearing Zero flag

	eq:

.endmacro


.macro cpi16
	
	;	Compare higher byte of a word
	cpi @0h, high(@1)
	brne nq

	;	Compare lower byte of a word
	cpi @0l, low(@1)
	brne nq
		
	sez		; Setting Zero flag because words are equal
	jmp eq	; Jumping eq because words are equal

	nq:
		clz		; Clearing Zero flag

	eq:
	
.endmacro



#endif
