#ifndef _X32COP_INC_
#define _X32COP_INC_


	;	Compares two virtual 32-bit registers
	;	4 Cycles
.macro cp32
		
	cp @0l, @0l		;	Compare lower byte of a word
	cpc @0h, @1h	;	Compare higher byte of a word
	cpc @0dl, @1dl	;	Compare higher byte of a word
	cpc @0dh, @1dh	;	Compare higher byte of a word
	
.endmacro


	;	Compares two 32-bit virtual registers with carry
	;	4 Cycles
.macro cpc32

	cpc @0l, @1l
	cpc @0h, @1h
	cpc @0dl, @1dl
	cpc @0dh, @1dh

.endmacro


	;	Compares 32-bit virtual register with constant value
	;	15 Cycles
.macro cpi32
	
	;	Compare higher byte of second word
	cpi @0dh, byte4(@1)
	brne nq
	nop

	;	Compare lower byte of second word
	cpi @0dl, byte3(@1)
	brne nq
	nop

	;	Compare higher byte of first word
	cpi @0h, byte2(@1)
	brne nq
	nop

	;	Compare lower byte of first word
	cpi @0l, low(@1)
	brne nq
	nop
		
	sez		; Setting Zero flag because words are equal
	rjmp eq	; Jumping eq because words are equal

	nq:
		clz		; Clearing Zero flag

	eq:
	
.endmacro


	;	Skips next command if 32-bit virtual registers are equal
	;	7 Cycles if condition is wrong; 
	;	8 if condition is true and next command is one word; 
	;	9 if condition is true and next command is double word;
.macro cpse32
	
	cpse @0l, @1l
	rjmp end
	cpse @0h, @0h
	rjmp end
	cpse @0dl, @1dl
	rjmp end
	cpse @0dh, @0dh

	end:

.endmacro


#endif
