#ifndef _FLASH_INC_
#define _FLASH_INC_

.include "include/x16base.inc"


	; args:
	; lxqd - destenation address
	; lxq - source address
	; lxd - size
	; usage:
	; Z, X, txl
flash_ld:

	movw Xh:Xl, lxqdh:lxqdl
	movw Zh:Zl, lxqh:lxql
		
	lpm txl, Z+
	st X+, txl

	dec16 lxd
	brne PC - $5

	ret


#endif
