; Binary to BCD conversion.
; Code courtesy: http://mp-lab.blogspot.com/2009/11/16-bit-binary-to-bcd-conversion.html

DATA SEGMENT
  bin EQU 1000b
  result DW ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
  MOV AX, DATA
  MOV DS, AX
  MOV BX, bin
  XOR AX, AX
  XOR CX, CX

CONVLOOP:
  CMP BX, 0
  JE EXIT
  DEC BX
  MOV AL, CL
  ADD AL, 01H
  DAA
  MOV CL, AL
  MOV AL, CH
  ADC AL, 00H
  DAA
  MOV CH, AL
  JMP CONVLOOP

EXIT:
  MOV result, CX
  MOV AX, 4CH
  INT 21H
CODE ENDS
END START