; BCD to binary conversion.
; Code credits: https://qr.ae/pGNAE8

DATA SEGMENT
    BCD DB 29H
    BIN DB ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    MOV AH, BCD
    MOV BH, AH
    AND BH, 0FH
    AND AH, 0F0H
    ROR AH, 04
    MOV CL, 10
    MOV AL, AH
    AND AX, 00FFH
    MUL CL
    ADD AL, BH
    MOV BIN, AL
    MOV AH, 04CH
    INT 21H
CODE ENDS
END START
