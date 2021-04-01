#ifndef _X32_LOP_INC_
#define _X32_LOP_INC_
.include "include/x16/x16lop.inc"


	;	Logical and between two virtual 32-bit registers
	;	16 Cycles
.macro and32

	and16 @0, @1
	brne normal
	nop
	
	and16 @0d, @1d
	rjmp end

	normal:
		and16 @0d, @1d
		clz
		nop
	end:

.endmacro


	;	Logical and between virtual 32-bit register and constant value
	;	16 Cycles
.macro andi32

	andi16 @0, LWRD(@1)
	brne normal
	nop
	
	andi16 @0d, HWRD(@1)
	rjmp end

	normal:
		andi16 @0d, HWRD(@1)
		clz
		nop
	end:

.endmacro


	;	Logical or between two virtual 32-bit registers
	;	16 Cycles
.macro or32

	or16 @0, @1
	brne normal
	nop
	
	or16 @0d, @1d
	rjmp end

	normal:
		or16 @0d, @1d
		clz
		nop
	end:

.endmacro


	;	Logical or between virtual 32-bit register and constant value
	;	16 Cycles
.macro ori32

	ori16 @0, LWRD(@1)
	brne normal
	nop
	
	ori16 @0d, HWRD(@1)
	rjmp end

	normal:
		ori16 @0d, HWRD(@1)
		clz
		nop
	end:

.endmacro


	;	Exclusive or between two virtual 32-bit registers
	;	16 Cycles
.macro eor32

	eor16 @0, @1
	brne normal
	nop
	
	eor16 @0d, @1d
	rjmp end

	normal:
		eor16 @0d, @1d
		clz
		nop
	end:

.endmacro


	; Clears 32-bit virtual register
	; 4 Cycles
	.macro clr32

	clr @0dh
	clr @0dl
	clr @0h
	clr @0l

	.endmacro


	; Sets 32-bit virtual register
	; 4 Cycles
	.macro ser32

	ser @0dh
	ser @0dl
	ser @0h
	ser @0l

	.endmacro

	;	Inverts 32-bit virtual register
	;	16 Cycles
.macro com32

	com16 @0
	brne normal
	nop
	
	com16 @0d
	rjmp end

	normal:
		com16 @0d
		clz
		nop
	end:

.endmacro


	;	Negates 32-bit virtual register
	;	7 Cycles
.macro neg32
	
	com  @0dh
	com  @0dl
	com  @0h
	neg  @0l
	sbci @0h, $FF
	sbci @0dl, $FF
	sbci @0dh, $FF

.endmacro

	
	;	Checks 32-bit virtual register on zero and negative values
	;	16 Cycles
.macro tst32

	tst16 @0
	brne normal
	nop
	
	tst16 @0d
	rjmp end

	normal:
		tst16 @0d
		clz
		nop
	end:

.endmacro


#endif
