#ifndef _X32MUL_ASM_
#define _X32MUL_ASM_

.include "include/x32base.inc"
.include "include/x64base.inc"

;***************************************************
;* Mutiply 32x32 -> 64 bit
;;  
;;  Arg 1 in lxq
;;  Arg 2 in lx
;;  return in lx (64 bit)
;;  Need to use temp registers R31-r30-r27-r26 and
;;; R5-r4-r3-r2 also r16  (need to stack these on entry)
;;; uint64_t mul32u(uint32_t x, uint32_t y)
mul32u:
        push    r2              ; save working registers
        push    r3              ; 
        push    r4
        push    r5
        push    r16
		
		in r16, SREG
		push r16

		clr     r16             ; clear new zero register
        mov     r31,r25         ; copy arguments to working registers
        mov     r30,r24         ; so we can pass the result in
        mov     r27,r23         ; same registers that were used to
        mov     r26,r22         ; pass the arguments in.
        mov     r5,r21
        mov     r4,r20
        mov     r3,r19
        mov     r2,r18
        ;; mult by ls digit of multiplier
        mul     r26,r2          ; a0xb0
		movw	r18,r0          ; result in p1-p0
		clr     r20             ; clear p2-p7
		clr     r21
		clr     r22
		clr     r23
		clr     r24
		clr     r25
		mul     r27,r2          ; a1xb0
		add     r19,r0          ; add at p1
		adc     r20,r1          ; add in msp at p2 with carry
		mul     r30,r2          ; a2xb0
		add     r20,r0          ; add at p2
		adc     r21,r1          ; include msp and  carry in p3
		mul     r31,r2          ; a3xb0
		add     r21,r0          ; add at p3
		adc     r22,r1          ; include msp and carry in p4
        ;; mult by 2nd digit of multiplier
		mul     r26,r3          ; a0xb1
		add     r19,r0          ; add at p1
		adc     r20,r1          ; add msp and carry at p2
		adc     r21,r16         ; add carry to p3
		adc     r22,r16         ; add carry to p4
		adc     r23,r16         ; add carry to p5
		mul     r27,r3          ; a1xb1
		add     r20,r0          ; add at p2
		adc     r21,r1          ; add msp and carry at p3
		adc     r22,r16         ; add carry to p4
		adc     r23,r16         ; add carry to p5
		mul     r30,r3          ; a2xb1
		add     r21,r0          ; add at p3
		adc     r22,r1          ; add msp and carry at p4
		adc     r23,r16         ; add carry at p5
		mul     r31,r3          ; a3xb1
		add     r22,r0          ; add at p4
		adc     r23,r1          ; add msp and carry at p5
        ;; mult by 3rd digit of multiplier
		mul     r26,r4          ; a0xb2
		add     r20,r0          ; add at p2
		adc     r21,r1          ; add msp with carry at p3
		adc     r22,r16         ; add carry to p4
		adc     r23,r16         ; add carry to p5
		adc     r24,r16         ; add carry to p6
		mul     r27,r4          ; a1xb2
		add     r21,r0          ; add at p3
		adc     r22,r1          ; add msp with carry at p4
		adc     r23,r16         ; add carry to p5
		adc     r24,r16         ; add carry to p6
		mul     r30,r4          ; a2xb2
		add     r22,r0          ; add at p4
		adc     r23,r1          ; add msp with carry at p5
		adc     r24,r16         ; add carry to p6
		mul     r31,r4          ; a3xb2
		add     r23,r0          ; add at p5
		adc     r24,r1          ; add msp with carry at p6
        ;; mult by 4th digit of multiplier
		mul     r26,r5          ; a0xb3
		add     r21,r0          ; add at p3
		adc     r22,r1          ; add msp with carry at p4
		adc     r23,r16         ; add carry to p5
		adc     r24,r16         ; add carry to p6
		adc     r25,r16         ; add carry to p7
		mul     r27,r5          ; a1xb3
		add     r22,r0          ; add at p4
		adc     r23,r1          ; add msp with carry to p5
		adc     r24,r16         ; add carry to p6
		adc     r25,r16         ; add carry to p7
		mul     r30,r5          ; a2xb3
		add     r23,r0          ; add at p5
		adc     r24,r1          ; add msp and carry at p6
		adc     r25,r16         ; add carry to p6
		mul     r31,r5          ; a3xb3
		add     r24,r0          ; add at p6
		adc     r25,r1          ; add msp and carry at p7
        ;; restore registers

		pop r16
		out SREG, r16

        pop     r16
        pop     r5
        pop     r4
        pop     r3
        pop     r2
        clr     r1              ; clear zero register				
		ret


;***************************************************
;* Mutiply 32x32 -> 64 bit
;;  Arg 1 in lxq
;;  Arg 2 in lx
;;  return in lx (64 bit)
;;  Need to use temp registers R31-r30-r27-r26 and
;;; R5-r4-r3-r2 also r16  (need to stack these on entry)
;;; int64_t mul32s(int32_t x, int32_t y)
mul32s:
        push    r2              ; save working registers
        push    r3              ; 
        push    r4
        push    r5
        push    r16

		in r16, SREG
		push r16


		; Getting sign to T flag
		mov r16, r25
		eor r16, r21
		bst r16, 7
		
		; Getting first arg in direct
		tst r25
		brpl mul32s_arg1_pos				
		neg32 lxq

		mul32s_arg1_pos:

		; Getting second arg in direct
		tst r21
		brpl mul32s_arg2_pos
		neg32 lx

		mul32s_arg2_pos:
        clr     r16             ; clear new zero register
        mov     r31,r25         ; copy arguments to working registers
        mov     r30,r24         ; so we can pass the result in
        mov     r27,r23         ; same registers that were used to
        mov     r26,r22         ; pass the arguments in.
        mov     r5,r21
        mov     r4,r20
        mov     r3,r19
        mov     r2,r18
        ;; mult by ls digit of multiplier
        mul     r26,r2          ; a0xb0
		movw	r18,r0          ; result in p1-p0
		clr     r20             ; clear p2-p7
		clr     r21
		clr     r22
		clr     r23
		clr     r24
		clr     r25
		mul     r27,r2          ; a1xb0
		add     r19,r0          ; add at p1
		adc     r20,r1          ; add in msp at p2 with carry
		mul     r30,r2          ; a2xb0
		add     r20,r0          ; add at p2
		adc     r21,r1          ; include msp and  carry in p3
		mul     r31,r2          ; a3xb0
		add     r21,r0          ; add at p3
		adc     r22,r1          ; include msp and carry in p4
        ;; mult by 2nd digit of multiplier
		mul     r26,r3          ; a0xb1
		add     r19,r0          ; add at p1
		adc     r20,r1          ; add msp and carry at p2
		adc     r21,r16         ; add carry to p3
		adc     r22,r16         ; add carry to p4
		adc     r23,r16         ; add carry to p5
		mul     r27,r3          ; a1xb1
		add     r20,r0          ; add at p2
		adc     r21,r1          ; add msp and carry at p3
		adc     r22,r16         ; add carry to p4
		adc     r23,r16         ; add carry to p5
		mul     r30,r3          ; a2xb1
		add     r21,r0          ; add at p3
		adc     r22,r1          ; add msp and carry at p4
		adc     r23,r16         ; add carry at p5
		mul     r31,r3          ; a3xb1
		add     r22,r0          ; add at p4
		adc     r23,r1          ; add msp and carry at p5
        ;; mult by 3rd digit of multiplier
		mul     r26,r4          ; a0xb2
		add     r20,r0          ; add at p2
		adc     r21,r1          ; add msp with carry at p3
		adc     r22,r16         ; add carry to p4
		adc     r23,r16         ; add carry to p5
		adc     r24,r16         ; add carry to p6
		mul     r27,r4          ; a1xb2
		add     r21,r0          ; add at p3
		adc     r22,r1          ; add msp with carry at p4
		adc     r23,r16         ; add carry to p5
		adc     r24,r16         ; add carry to p6
		mul     r30,r4          ; a2xb2
		add     r22,r0          ; add at p4
		adc     r23,r1          ; add msp with carry at p5
		adc     r24,r16         ; add carry to p6
		mul     r31,r4          ; a3xb2
		add     r23,r0          ; add at p5
		adc     r24,r1          ; add msp with carry at p6
        ;; mult by 4th digit of multiplier
		mul     r26,r5          ; a0xb3
		add     r21,r0          ; add at p3
		adc     r22,r1          ; add msp with carry at p4
		adc     r23,r16         ; add carry to p5
		adc     r24,r16         ; add carry to p6
		adc     r25,r16         ; add carry to p7
		mul     r27,r5          ; a1xb3
		add     r22,r0          ; add at p4
		adc     r23,r1          ; add msp with carry to p5
		adc     r24,r16         ; add carry to p6
		adc     r25,r16         ; add carry to p7
		mul     r30,r5          ; a2xb3
		add     r23,r0          ; add at p5
		adc     r24,r1          ; add msp and carry at p6
		adc     r25,r16         ; add carry to p6
		mul     r31,r5          ; a3xb3
		add     r24,r0          ; add at p6
		adc     r25,r1          ; add msp and carry at p7
		       			
		;Restoring sign		
		brtc mul32s_ret
		
		neg64 lx

		mul32s_ret:
		bld r25, 7

		 ;; restore registers
		pop r16
		out SREG, r16

        pop     r16
        pop     r5
        pop     r4
        pop     r3
        pop     r2
        clr     r1              ; clear zero register

		ret

#endif
