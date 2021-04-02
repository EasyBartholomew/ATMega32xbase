#ifndef _MEMBASE_ASM_
#define _MEMBASE_ASM_


.include "include/x16base.inc"


;	Args:
	;	lxqd - address
	;	lxq - size	
;	usage:
	;	lxl, lxd, X

#define sz  lxd

mem_cl:
	
	movw lxdh:lxdl, lxqh:lxql

	ldi16 lxq, $0000
	call mem_set8

	ret

#undef sz


;	Args:
	;	lxqd - address
	;	lxql - value to set
	;	lxd	- size
;	usage:
	;	lxl, X
#define val lxql
#define sz  lxd

mem_set8:

	in lxl, SREG

	movw Xh:Xl, lxqdh:lxqdl
	
	mem_set8_copy_loop:
		
		st X+, val 
		dec16 sz
		brne mem_set8_copy_loop

	out SREG, lxl

	ret

#undef val
#undef sz


	;	Args:
	;	lxqd - address
	;	lxq - value to set
	;	lxd	- size
	;	usage:
	;	lxl, X
#define val lxq
#define sz  lxd

mem_set16:

	in lxl, SREG

	movw Xh:Xl, lxqdh:lxqdl
	
	mem_set16_copy_loop:
		
		st16i X, val 
		dec16 sz
		brne mem_set16_copy_loop

	out SREG, lxl

	ret

#undef src
#undef sz


	; Copies memory region from src address to dst address
	; lxqd - dst; lxq - src; lxd - size, X, Z
mem_cpy:
	
	in lxl, SREG				; backup SREG
		
	movw Xh:Xl, lxqh:lxql		; load src to X
	movw Zh:Zl, lxqdh:lxqdl		; load dst to Z

	mem_cpy_copy_loop:

		ld txl, X+				; load value from address in X to txl
		st Z+, txl				; store value to address in Z from txl
		dec16 lxd				; size = size - 1
		brne mem_cpy_copy_loop	; while(size != 0)
			
	out SREG, lxl				; restore SREG
	ret

#endif
