; Bit manipulation to count the no. of 1s and 0s in a given no.

DATA SEGMENT
    num DW 0810H
    zeros DW ?
    ones DW ? 
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA  
START:
    MOV AX, DATA
    MOV DS, AX
    MOV AX, num 
    XOR BX, BX
    XOR CX, CX
SHIFTLOOP:
    SHR AX, 1
    JNC ZERO
    INC BX
    CMP AX, 0
    JNE SHIFTLOOP
    JMP EXIT
ZERO:
    INC CX
    CMP AX, 0
    JNE SHIFTLOOP 
EXIT:
    MOV ones, BX
    MOV zeros, CX
    MOV AH, 4CH
    INT 21H
CODE ENDS
END START
