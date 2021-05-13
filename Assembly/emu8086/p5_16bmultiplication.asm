; Multiplication of two 16-bit numbers

DATA SEGMENT
    multiplicand DW 1000H
    multiplicator DW 200H
    product DD ?
ENDS DATA 

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    MOV AX, [multiplicand]
    MUL [multiplicator]
    MOV [product], AX
    MOV [product+2], DX
    MOV AH, 04CH
    INT 21H
ENDS CODE
END START