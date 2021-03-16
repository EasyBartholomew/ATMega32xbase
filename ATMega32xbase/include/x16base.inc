#ifndef	_X16BASE_INC_
#define	_X16BASE_INC_


.include "include/xbase.inc"
.include "include/x16/x16arop.inc"
.include "include/x16/x16cop.inc"
.include "include/x16/x16lop.inc"
.include "include/x16/x16sdop.inc"



.equ UINT16_MIN		=$0000
.equ UINT16_MAX		=$FFFF

.equ INT16_MIN		=$8000
.equ INT16_MAX		=$7FFF


.equ INT8_MIN		=$80
.equ INT8_MAX		=$7F

.equ UINT8_MIN		=$00
.equ UINT8_MAX		=$FF


#endif
