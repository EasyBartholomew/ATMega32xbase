#ifndef _X16_LOP_INC_
#define _X16_LOP_INC_


.macro and16

	and @0l, @1l
	brne normal

	and @0h, @1h
	rjmp end

	normal:
		and @0h, @1h
		clz

	end:

.endmacro


.macro andi16

	andi @0l, low(@1)
	brne normal

	andi @0h, high(@1)
	rjmp end

	normal:
		andi @0h, high(@1)
		clz

	end:

.endmacro


.macro or16

	or @0l, @1l
	brne normal

	or @0h, @1h
	rjmp end

	normal:
		or @0h, @1h
		clz
	end:

.endmacro

.macro ori16

	ori @0l, low(@1)
	brne normal

	ori @0h, high(@1)
	rjmp end

	normal:
		ori @0h, high(@1)
		clz

	end:

.endmacro


.macro eor16

	eor @0l, @1l
	brne normal

	eor @0h, @1h
	rjmp end

	normal:
		eor @0h, @1h
		clz
	end:

.endmacro

.macro clr16
	
	clr @0h
	clr @0l

.endmacro


.macro ser16

	ser @0h
	ser @0l

.endmacro

//Do and check later
.macro com16

	com @0l
	brne normal

	com @0h
	rjmp end

	normal:
		com @0h
		clz
	end:

.endmacro

//Do and check later
.macro neg16
	
	neg @0l
	brne normal

	neg @0h
	rjmp end

	normal:
		neg @0h
		clz
	end:

.endmacro

//Add tst

#endif
