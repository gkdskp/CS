; Addition of two 16-bit numbers using direct addressing mode

DATA SEGMENT
    sum DW ?
ENDS DATA

CODE SEGMENT
ASSUME DS:DATA, CS:CODE
START:
    MOV AX, DATA
    MOV DS, AX
    MOV [1000H], 100
    MOV [1002H], 200
    MOV AX, [1000H]
    MOV BX, [1002H]
    ADD AX, BX
    MOV [sum], AX
    MOV AH, 04CH
    INT 21H
CODE ENDS
END START