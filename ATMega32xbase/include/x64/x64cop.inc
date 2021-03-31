#ifndef _X16COP_INC_
#define _X16COP_INC_

.macro cp16
		
	cp @0l, @0l		;	Compare lower byte of a word
	cpc @0h, @1h	;	Compare higher byte of a word
	cpc @0dl, @1dl
	cpc @0dh, @1dh
	cpc @0ql, @1ql
	cpc @0qh, @1qh
	cpc @0qdl, @1qdl
	cpc @0qdh, @1qdh
	
.endmacro

 .macro cpc16
		
	cpc @0l, @0l		;	Compare lower byte of a word
	cpc @0h, @1h	;	Compare higher byte of a word
	cpc @0dl, @1dl
	cpc @0dh, @1dh
	cpc @0ql, @1ql
	cpc @0qh, @1qh
	cpc @0qdl, @1qdl
	cpc @0qdh, @1qdh
	
.endmacro

#endif