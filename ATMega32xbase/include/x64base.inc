#ifndef	_X64BASE_INC_
#define	_X64BASE_INC_

#define BYTEN(val, n) ((val) >> (8 * ((n)-1)))

#define BYTE8(val) BYTEN(val, 8)
#define BYTE7(val) BYTEN(val, 7)
#define BYTE6(val) BYTEN(val, 6)
#define BYTE5(val) BYTEN(val, 5)

.include "include/xbase.inc"
.include "include/x64/x64arop.inc"
.include "include/x64/x64cop.inc"
.include "include/x64/x64sdop.inc"

.equ UINT64_MIN		=$0000000000000000
.equ UINT64_MAX		=$FFFFFFFFFFFFFFFF
					 
.equ INT64_MIN		=$8000000000000000
.equ INT64_MAX		=$7FFFFFFFFFFFFFFF

#endif
