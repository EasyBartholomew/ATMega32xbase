#ifndef _x32TRUNC_ASM_
#define _x32TRUNC_ASM_

.include "m32def.inc"
.include "include/x32/x32sdop.inc"

/*
	arg in lx (64bit)
	result in lxq
*/
x32u_trunc:	
	mov32 lxq, lx
	ret

/*
	arg in lx (64bit)
	result in lxq
*/
x32s_trunc:
		
	in r16, SREG
	push r16

	bst lxqdh, 7
	mov32 lxq, lx
	bld lxqdh, 7

	pop r16
	out SREG, r16
	ret

#endif
