#ifndef _SDELAY_ASM_
#define _SDELAY_ASM_

.include "include/x16base.inc"


; Performs 1us delay 
sdelay_1us:
	ret


; Performs 2us delay 
sdelay_2us:
	call sdelay_1us
	ret


; Performs specified us delay 
; args:
;	lxqd	should contain value between 3 and UINT16_MAX (us)
; usage: 
;	lxql, lxqd
sdelay_us:
	
	in lxql, SREG	; 1 cycle	

	nop				; 1 cycle
	nop				; 1 cycle

	sbiw lxqdl, 2	; 2 cycles
	sbiw lxqdl, 1	; 2 cycles
	push lxql		; 2 cycles
	pop	 lxql		; 2 cycles
	brne PC - $03	; 2 cycles (last time 1 cycle)
	nop				; 1 cycle (brne aligment)
		
	out SREG, lxql	; 1 cycle
	ret


; Performs specified ms delay 
; args:
;	lxqd	should contain value between 1 and UINT16_MAX (ms)
; usage: 
;	lxqh, lxqd
sdelay_ms:
	
	in lxqh, SREG	; 1 cycle, backup SREG	
		
	push16 lxqd		; 4 cycle
	
	ldi16 lxqd, 997	; 2 cycles
	call sdelay_us	; 997 us

	pop16 lxqd		; 4 cycles

	sbiw lxqdl, 1	; 2 cycles
	breq PC + $0F	; 2 cycles (last time 1 cycle), skip general cycle
	nop				; 1 cycle (brne aligment)

	sbiw lxqdl, 1	; 2 cycles

	push16 lxqd		; 4 cycles
	ldi16 lxqd, 998	; 2 cycles
	call sdelay_us	; 998 us
	pop16 lxqd		; 4 cycles
			
	push lxqdl		; 2 cycles, wasting time
	pop  lxqdl		; 2 cycles, wasting time

	brne PC - $0B	; 2 cycles (last time 1 cycle)
	nop				; 1 cycle (brne aligment)
							
	out SREG, lxqh	; 1 cycle, restore SREG
	ret


#endif
