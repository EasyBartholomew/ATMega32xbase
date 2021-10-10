#ifndef	_XBASE_INC_
#define	_XBASE_INC_

/*************************************************************************************************************************************************
*	This register naming concept allows easily implement 8-bit, 16-bit, 32-bit and 64-bit logic.
*
*	There are three general purpose 64-bit virtual registers:
*		*	rx (Right eXtendable) should be used for result data and for data that should be loaded from RAM and other locations.
*		*	mx (Middle eXtendable) should be used for result data and for data that should be loaded from RAM and other locations.
*		*	lx (Left eXtendable) should be used for loading data immediately.
*			
*	There are six general purpose 32-bit virtual registers:
*		*	rx
*		*	mx
*		*	lx		
*		*	rxq
*		*	mxq
*		*	lxq
*		Registers rx, rxq, mx, mxq and lx, lxq are parts of rx, mx and lx 64-bit registers and could not be using if rx, mx or lx contains 64-bit data.
*		All logical and arithmetical operations with lower data and 64-bit data should be implemented by extending lower data to 64-bit.
*
*	There are five general purpose 16-bit virtual registers:
*		*	rx
*		*	mx
*		*	lx
*		*	rxd
*		*	mxd
*		*	lxd
*		*	tx (temp eXtendable) is independent 16-bit register and can be used as need
*	Registers rx, rxd, mx, mxd and lx, lxd are parts of rx, mx and lx 64-bit registers and could not be using if rx, mx or lx contains 64-bit or 32-bit data.
*	All logical and arithmetical operations with lower data and 64-bit or 32-bit data should be implemented by extending lower data to 64-bit or to 32-bit.
*
*	There are 24 general purpose 8-bit virtual registers. 
*	All of them are parts of large data registers and should be used only if no larger data stored in the same register.
*
*	There are postfixes for 64-bit data registers:
*		*	l - the least significant byte
*		*	qdh - the most significant byte
*
*
*		Schema of 64-bit data storage in little-endian format:
*		 		
*		rx:	|rxl|rxh|rxdl|rxdh|rxql|rxqh|rxqdl|rxqdh|
*			  0   1   2    3    4    5    6     7
*
*		mx:	|mxl|mxh|mxdl|mxdh|mxql|mxqh|mxqdl|mxqdh|
*			  0   1   2    3    4    5    6     7
*
*		lx: |lxl|lxh|lxdl|lxdh|lxql|lxqh|lxqdl|lxqdh|
*		      0   1   2    3    4    5    6     7
*
*
*		There are postfixes for 32-bit data registers:
*		*	l - the least significant byte
*		*	dh - the most significant byte
*
*
*		Shema of 32-bit data storage:
*
*		rx: |rxl|rxh|rxdl|rxdh|
*			  0   1   2    3
*		
*		mx: |mxl|mxh|mxdl|mxdh|
*			  0   1   2    3
*
*		lx:	|lxl|lxh|lxdl|lxdh|
*			  0   1   2    3
*
*		rxq: |rxql|rxqh|rxqdl|rxqdh|
*			   0    1    2     3
*
*		mxq: |mxql|mxqh|mxqdl|mxqdh|
*			   0    1    2     3
*
*		lxq: |lxql|lxqh|lxqdl|lxqdh|
*		       0    1    2     3
*
*
*		There are postfixes for 16-bit data registers:
*		*	l - the least significant byte
*		*	h - the most significant byte
*
*
*		Shema of data 16-bit storage:
*		
*		rx:	|rxl|rxh|
*			  0   1
*
*		mx:	|mxl|mxh|
*			  0   1
*
*		lx: |lxl|lxh|
*			  0   1
*
*		rxd: |rxdl|rxdh|
*		       0    1
*		
*		mxd: |mxdl|mxdh|
*		       0    1
*
*		lxd: |lxdl|lxdh|
*			   0    1
*
*		tx: |txl|txh|
*			  0   1
*
*************************************************************************************************************************************************/


// tx definition
.def txl	=r0
.def txh	=r1


// rx family definition
.def rxl	=r2
.def rxh	=r3
.def rxdl	=r4
.def rxdh	=r5

.def rxql	=r6
.def rxqh	=r7
.def rxqdl	=r8
.def rxqdh	=r9


// mx family definition
.def mxl	=r10
.def mxh	=r11
.def mxdl	=r12
.def mxdh	=r13

.def mxql	=r14
.def mxqh	=r15
.def mxqdl	=r16
.def mxqdh	=r17


// lx family definition
.def lxl	=r18
.def lxh	=r19
.def lxdl	=r20
.def lxdh	=r21

.def lxql	=r22
.def lxqh	=r23
.def lxqdl	=r24
.def lxqdh	=r25


#define BYTE(VAL, N) ((VAL) >> (8 * (N)))

#define BYTE0(VAL) BYTE(VAL, 0)
#define BYTE1(VAL) BYTE(VAL, 1)
#define BYTE2(VAL) BYTE(VAL, 2)
#define BYTE3(VAL) BYTE(VAL, 3)
#define BYTE4(VAL) BYTE(VAL, 4)
#define BYTE5(VAL) BYTE(VAL, 5)
#define BYTE6(VAL) BYTE(VAL, 6)
#define BYTE7(VAL) BYTE(VAL, 7)

#define LWDWRD(VAL) ((VAL) & $00000000FFFFFFFF)
#define HWDWRD(VAL) ((VAL) >> 32)

// Makes (slimes) new name
#define MKNAME(prefix, postfix) prefix##postfix


#endif
