; Find sum of 16-bit numbers in an array.

DATA SEGMENT
  arr DW 1000H, 2000H, 3000H, 4000H
  count DW 4
  sum DW ?
ENDS DATA

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
  MOV AX, DATA
  MOV DS, AX
  MOV CX, count
  LEA SI, arr
  XOR AX, AX

SUMLOOP:
  ADD AX, [SI]
  ADD SI, 2
  LOOP SUMLOOP

EXIT:
  MOV sum, AX
  MOV AX, 4CH
  INT 21H
ENDS CODE
END START