#ifndef _X16COP_INC_
#define _X16COP_INC_


	;	Compares two virtual 16-bit registers
	;	2 Cycles
.macro cp16
		
	cp @0l, @0l		;	Compare lower byte of a word
	cpc @0h, @1h	;	Compare higher byte of a word
	
.endmacro


	;	Compares two 16-bit virtual registers with carry
	;	2 Cycles
.macro cpc16

	cpc @0l, @1l
	cpc @0h, @1h

.endmacro


	;	Compares 16-bit virtual register with constant value
	;	10 Cycles
.macro cpi16
	
	;	Compare higher byte of a word
	cpi @0h, high(@1)
	brne nq
	nop

	;	Compare lower byte of a word
	cpi @0l, low(@1)
	brne nq
	nop
		
	sez		; Setting Zero flag because words are equal
	rjmp eq	; Jumping eq because words are equal

	nq:
		clz		; Clearing Zero flag

	eq:
	
.endmacro


	;	Skips next command if 16-bit virtual registers are equal
	;	3 Cycles if condition is wrong; 
	;	4 if condition is true and next command is one word; 
	;	5 if condition is true and next command is double word;
.macro cpse16
	
	cpse @0l, @1l
	rjmp end
	cpse @0h, @0h

	end:

.endmacro


#endif
