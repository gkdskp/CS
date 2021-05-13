; Bit manipulation to check whether the data is positive or negative.
; Reference: https://www.geeksforgeeks.org/check-number-positive-negative-zero-using-bit-operators/

DATA SEGMENT
    num DW 0000H
    positives DB 'Positive', '$'
    negatives DB 'Negative', '$'
    zeros DB 'Zero', '$'   
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA  
START:
    MOV AX, DATA
    MOV DS, AX
    MOV AX, num
    SHR AX, 15 
    MOV BX, AX
    MOV AX, num
    NEG AX
    SHR AX, 15
    SUB AX, BX
    ADD AX, 1
    CMP AX, 2
    JE POSITIVE
    CMP AX, 1
    JE ZERO
    LEA DX, negatives
    MOV AH, 09H
    INT 21H
    JMP EXIT
POSITIVE:
    LEA DX, positives
    MOV AH, 09H
    INT 21H
    JMP EXIT
ZERO:
    LEA DX, zeros
    MOV AH, 09H
    INT 21H
EXIT:
    MOV AH, 4CH
    INT 21H
CODE ENDS
END START