#ifndef _X16SDOP_INC_
#define _X16SDOP_INC_


	;	Saving 16bit to stack
.macro push16

	push @0h	; Saving higher byte
	push @0l	; Saving lower byte
	
.endmacro
	

	;	Poping 16bit number
.macro pop16

	pop @0l
	pop @0h

.endmacro


	;	Writes 16bit number to SRAM
.macro sts16

	sts @0, @1l		; Writing of lower byte
	sts @0 + 1, @1h	; Writing of higher byte

.endmacro


	;	Loading 16bit number from SRAM
.macro lds16

	lds @0l, @1		; Loading of lower byte
	lds @0h, @1 + 1	; Loading of higer byte

.endmacro


.macro st16
	
	st @0+, @1l	;Little-endian
	st @0, @1h
	ld @1l, -@0	

.endmacro


.macro st16i

	st @0+, @1l
	st @0+, @1h 

.endmacro


.macro st16d
		
	st -@0, @1h
	st -@0, @1l

.endmacro


.macro ld16
		
	ld @0l, @1+
	ld @0h, @1	
	ld @0l, -@1 	
	 
.endmacro


.macro ld16i

	ld @0l, @1+
	ld @0h, @1+

.endmacro


.macro ld16d

	ld @1h, -@0
	ld @1l, -@0

.endmacro


.macro mov16
	
	mov @0h, @1h
	mov @0l, @1l

.endmacro


	;	Loads const 16bit value
.macro ldi16

	ldi @0h, high(@1) 
	ldi @0l, low(@1)

.endmacro


.macro ldd16

	ldd @0l, @1
	ldd @0h, @1 + 1

.endmacro


.macro std16
	
	std @0, @1l 
	std @0 + 1, @1h
	 
.endmacro

#endif
