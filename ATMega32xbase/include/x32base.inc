#ifndef	_X32BASE_INC_
#define	_X32BASE_INC_

.include "include/xbase.inc"
.include "include/x32/x32cop.inc"
.include "include/x32/x32sdop.inc"
.include "include/x32/x32lop.inc"
.include "include/x32/x32arop.inc"

.equ UINT32_MIN		=$00000000
.equ UINT32_MAX		=$FFFFFFFF
					 
.equ INT32_MIN		=$80000000
.equ INT32_MAX		=$7FFFFFFF


#endif
