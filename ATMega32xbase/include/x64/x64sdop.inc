#ifndef _X64_SDOP_INC_
#define _X64_SDOP_INC_

.macro ldi64

	ldi @0l, BYTE0(@1)
	ldi @0h, BYTE1(@1)
	ldi @0dl, BYTE2(@1)
	ldi @0dh, BYTE3(@1)
	ldi @0ql, BYTE4(@1)
	ldi @0qh, BYTE5(@1)
	ldi @0qdl, BYTE6(@1)
	ldi @0qdh, BYTE7(@1)

.endmacro 

.macro push64

	push @0qdh
	push @0qdl
	push @0qh
	push @0ql
	push @0dh
	push @0dl
	push @0h
	push @0l

.endmacro

.macro pop64

	pop @0l
	pop @0h
	pop @0dl
	pop @0dh
	pop @0ql
	pop @0qh
	pop @0qdl
	pop @0qdh

.endmacro

.macro mov64
	
	mov @0qdh, @1qdh
	mov @0qdl, @1qdl
	mov @0qh, @1qh
	mov @0ql, @1ql
	mov @0dh, @1dh
	mov @0dl, @1dl
	mov @0h, @1h
	mov @0l, @1l

.endmacro

.macro lds64

	lds @0l, @1			; Loading of lower byte
	lds @0h, @1 + 1		; Loading of higher byte
	lds @0dl, @1 + 2	; Loading of lower byte of second word
	lds @0dh, @1 + 3	; Loading of higher byte of second word
	lds @0ql, @1 + 4	; Loading of lower byte of third word
	lds @0qh, @1 + 5	; Loading of higher byte of third word
	lds @0qdl, @1 + 6	; Loading of lower byte of fourth word
	lds @0qdh, @1 + 7	; Loading of higher byte of fourth word

.endmacro


.macro sts64

	sts @0, @1l		; Loading of lower byte
	sts @0 + 1, @1h	; Loading of higher byte
	sts @0 + 2, @1dl	; Loading of lower byte of second word
	sts @0 + 3, @1dh	; Loading of higher byte of second word
	sts @0 + 4, @1ql	; Loading of lower byte of third word
	sts @0 + 5, @1qh	; Loading of higher byte of third word
	sts @0 + 6, @1qdl	; Loading of lower byte of fourth word
	sts @0 + 7, @1qdh	; Loading of higher byte of fourth word

.endmacro

#endif
