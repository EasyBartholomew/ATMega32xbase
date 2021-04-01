#ifndef _X32SDOP_INC_
#define _X32SDOP_INC_


	;	Saving 32bit to stack
.macro push32

	push @0dh	; Saving second word higher byte
	push @0dl	; Saving second word lower byte
	push @0h	; Saving higher byte
	push @0l	; Saving lower byte
	
.endmacro
	

	;	Poping 32bit number
.macro pop32

	pop @0l
	pop @0h
	pop @0dl
	pop @0dh

.endmacro


	;	Writes 32bit number to SRAM
.macro sts32

	sts @0, @1l			; Writing of lower byte
	sts @0 + 1, @1h		; Writing of higher byte
	sts @0 + 2, @1dl	; Writing of lower byte of second word
	sts @0 + 3, @1dh	; Writing of higher byte of second word

.endmacro

.macro st32
	
	st @0+, @1l	;Little-endian
	st @0, @1h
	ld @1l, -@0

	st @0 + 2, @1dl	;Little-endian
	st @0 + 1, @1dh
	ld @1l, -@0 + 1		

.endmacro


.macro st32i

	st @0+, @1l
	st @0+, @1h 
	st @0+, @1dl
	st @0+, @1dh 

.endmacro


.macro st32d
		
	st -@0, @1dh
	st -@0, @1dl
	st -@0, @1h
	st -@0, @1l

.endmacro


.macro std32
	
	std @0, @1l 
	std @0 + 1, @1h
	std @0 + 2, @1dl 
	std @0 + 3, @1dh
	 
.endmacro


.macro ld32
		
	ld @0l, @1+
	ld @0h, @1	
	ld @0l, -@1 
	ld @0dl, @1 + 1
	ld @0dh, @1+	
	ld @0dl, -@1+ 	
	 
.endmacro


.macro ld32i

	ld @0l, @1+
	ld @0h, @1+
	ld @0dl, @1+
	ld @0dh, @1+

.endmacro


.macro ld32d

	ld @1dh, -@0
	ld @1dl, -@0
	ld @1h, -@0
	ld @1l, -@0

.endmacro

	;	Loading 32bit number from SRAM
.macro lds32

	lds @0l, @1			; Loading of lower byte
	lds @0h, @1 + 1		; Loading of higer byte
	lds @0dl, @1 + 2	; Loading of lower byte of second word
	lds @0dh, @1 + 3	; Loading of higer byte of second word

.endmacro


	;	Loads const 32bit value
.macro ldi32

	ldi @0l, low(@1)			
	ldi @0h, byte2(@1)		
	ldi @0dl, byte3(@1)		
	ldi @0dh, byte4(@1)		

.endmacro


.macro ldd32

	ldd @0l, @1
	ldd @0h, @1 + 1
	ldd @0l, @1 + 2
	ldd @0h, @1 + 3

.endmacro


.macro mov32
	
	mov @0dh, @1dh
	mov @0dl, @1dl
	mov @0h, @1h
	mov @0l, @1l

.endmacro


.macro in32
	
	in @0dh, @1dh
	in @0dl, @1dl
	in @0h, @1h
	in @0l, @1l

.endmacro


.macro out32
	
	out @0dh, @1dh
	out @0dl, @1dl
	out @0h, @1h
	out @0l, @1l

.endmacro


#endif

