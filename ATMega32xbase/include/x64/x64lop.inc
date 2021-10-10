#ifndef _X64_LOP_INC_
#define _X64_LOP_INC_
.include "include/x32/x32lop.inc"


	;	Logical and between two virtual 64-bit registers
	;	16 Cycles
.macro and64

	and32 @0, @1
	brne normal
	nop
	
	and32 @0q, @1q
	rjmp end

	normal:
		and32 @0q, @1q
		clz
		nop
	end:

.endmacro


	;	Logical and between virtual 64-bit register and constant value
	;	16 Cycles
.macro andi64

	andi32 @0, LWDWRD(@1)
	brne normal
	nop
	
	andi32 @0q, HWDWRD(@1)
	rjmp end

	normal:
		andi32 @0q, HWDWRD(@1)
		clz
		nop
	end:

.endmacro


	;	Logical or between two virtual 64-bit registers
	;	16 Cycles
.macro or64

	or32 @0, @1
	brne normal
	nop
	
	or32 @0q, @1q
	rjmp end

	normal:
		or32 @0q, @1q
		clz
		nop
	end:

.endmacro


	;	Logical or between virtual 64-bit register and constant value
	;	16 Cycles
.macro ori64

	ori32 @0, LWDWRD(@1)
	brne normal
	nop
	
	ori32 @0q, HWDWRD(@1)
	rjmp end

	normal:
		ori32 @0q, HWDWRD(@1)
		clz
		nop
	end:

.endmacro


	;	Exclusive or between two virtual 64-bit registers
	;	16 Cycles
.macro eor64

	eor32 @0, @1
	brne normal
	nop
	
	eor32 @0q, @1q
	rjmp end

	normal:
		eor32 @0q, @1q
		clz
		nop
	end:

.endmacro


	; Clears 64-bit virtual register
	; 8 Cycles
	.macro clr64

	clr32 @0
	clr32 @0q	
		
	.endmacro


	; Sets 64-bit virtual register
	; 4 Cycles
	.macro ser64

	ser32 @0
	ser32 @0q

	.endmacro

	;	Inverts 64-bit virtual register
	;	16 Cycles
.macro com64

	com32 @0
	brne normal
	nop
	
	com32 @0q
	rjmp end

	normal:
		com32 @0q
		clz
		nop
	end:

.endmacro


;	Negates 64-bit virtual register
	;	15 Cycles
.macro neg64
	
	com  @0qdh
	com  @0qdl
	com  @0qh
	com  @0ql
	com  @0dh
	com  @0dl
	com  @0h
	neg  @0l
	sbci @0h, $FF
	sbci @0dl, $FF
	sbci @0dh, $FF
	sbci @0ql, $FF
	sbci @0qh, $FF
	sbci @0qdl, $FF
	sbci @0qdh, $FF

.endmacro


	
	;	Checks 64-bit virtual register on zero and negative values
	;	32 Cycles
.macro tst64

	tst32 @0
	brne normal
	nop
	
	tst32 @0q
	rjmp end

	normal:
		tst32 @0q
		clz
		nop
	end:

.endmacro

#endif
