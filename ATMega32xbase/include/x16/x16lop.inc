#ifndef _X16_LOP_INC_
#define _X16_LOP_INC_


	;	Logical and between two virtual 16-bit registers
	;	6 Cycles
.macro and16

	and @0l, @1l
	brne normal
	nop
	
	and @0h, @1h
	rjmp end

	normal:
		and @0h, @1h
		clz
		nop
	end:

.endmacro


	;	Logical and between virtual 16-bit register and constant value
	;	6 Cycles
.macro andi16

	andi @0l, low(@1)
	brne normal
	nop
	
	andi @0h, high(@1)
	rjmp end

	normal:
		andi @0h, high(@1)
		clz
		nop
	end:

.endmacro


	;	Logical or between two virtual 16-bit registers
	;	6 Cycles
.macro or16

	or @0l, @1l
	brne normal
	nop
	
	or @0h, @1h
	rjmp end

	normal:
		or @0h, @1h
		clz
		nop
	end:

.endmacro


	;	Logical or between virtual 16-bit register and constant value
	;	6 Cycles
.macro ori16

	ori @0l, low(@1)
	brne normal
	nop
	
	ori @0h, high(@1)
	rjmp end

	normal:
		ori @0h, high(@1)
		clz
		nop
	end:

.endmacro


	;	Exclusive or between two virtual 16-bit registers
	;	6 Cycles
.macro eor16

	eor @0l, @1l
	brne normal
	nop
	
	eor @0h, @1h
	rjmp end

	normal:
		eor @0h, @1h
		clz
		nop
	end:

.endmacro


	;	Clears 16-bit virtual register
	;	2 Cycles
.macro clr16
	
	clr @0h
	clr @0l

.endmacro

	
	;	Sets 16-bit virtual register
	;	2 Cycles
.macro ser16

	ser @0h
	ser @0l

.endmacro


	;	Inverts 16-bit virtual register
	;	6 Cycles
.macro com16

	com @0l
	brne normal
	nop
	
	com @0h
	rjmp end

	normal:
		com @0h
		clz
		nop
	end:

.endmacro


	;	Negates 16-bit virtual register
	;	3 Cycles
.macro neg16
	
	com  @0h
	neg  @0l
	sbci @0h, $FF

.endmacro

	
	;	Checks 16-bit virtual register on zero and negative values
	;	6 Cycles
.macro tst16

	tst @0l
	brne normal
	nop
	
	tst @0h
	rjmp end

	normal:
		tst @0h
		clz
		nop
	end:

.endmacro


#endif
