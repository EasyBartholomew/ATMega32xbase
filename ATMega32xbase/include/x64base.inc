#ifndef	_X64BASE_INC_
#define	_X64BASE_INC_


.include "include/xbase.inc"
.include "include/x64/x64arop.inc"
//.include "include/x64/x64cop.inc"


.equ UINT64_MIN		=$0000000000000000
.equ UINT64_MAX		=$FFFFFFFFFFFFFFFF
					 
.equ INT64_MIN		=$8000000000000000
.equ INT64_MAX		=$7FFFFFFFFFFFFFFF

#endif
