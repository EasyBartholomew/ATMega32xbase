#ifndef _X64_COP_INC_
#define _X64_COP_INC_

.macro cp64
		
	cp @0l, @0l		;	Compare lower byte of a word
	cpc @0h, @1h	;	Compare higher byte of a word
	cpc @0dl, @1dl
	cpc @0dh, @1dh
	cpc @0ql, @1ql
	cpc @0qh, @1qh
	cpc @0qdl, @1qdl
	cpc @0qdh, @1qdh
	
.endmacro

 .macro cpc64
		
	cpc @0l, @0l		;	Compare lower byte of a word
	cpc @0h, @1h		;	Compare higher byte of a word
	cpc @0dl, @1dl
	cpc @0dh, @1dh
	cpc @0ql, @1ql
	cpc @0qh, @1qh
	cpc @0qdl, @1qdl
	cpc @0qdh, @1qdh
	
.endmacro

.macro cpi64

	cpi @0qdh, BYTE8(@1)
	brne nq
	nop

	cpi @0qdl, BYTE7(@1)
	brne nq
	nop

	cpi @0qh, BYTE6(@1)
	brne nq
	nop

	cpi @0ql, BYTE5(@1)
	brne nq
	nop

	cpi @0dh, BYTE4(@1)
	brne nq
	nop

	cpi @0dl, BYTE3(@1)
	brne nq
	nop

	cpi @0h, BYTE2(@1)
	brne nq
	nop

	cpi @0l, LOW(@1)
	brne nq
	nop

	sez
	rjmp eq

	nq:
		clz

	eq:

.endmacro

.macro cpse64

	cpse @0l, @1l
	rjmp end
	cpse @0h, @1h
	rjmp end
	cpse @0dl, @1dl
	rjmp end
	cpse @0dh, @1dh
	rjmp end
	cpse @0ql, @1ql
	rjmp end
	cpse @0qh, @1qh
	rjmp end
	cpse @0qdl, @1qdl
	rjmp end
	cpse @0qdh, @1qdh
	rjmp end

	end:

.endmacro

#endif