; Substraction of two 16-bit numbers using immediate addressing mode

DATA SEGMENT
    difference DW ?
ENDS DATA

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    MOV AX, 200
    MOV BX, 100
    SUB AX, BX
    MOV [difference], AX
    MOV AH, 04CH
    INT 21H
CODE ENDS
END START