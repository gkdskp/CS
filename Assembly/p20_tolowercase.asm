; Convert a string in uppercase to lowercase.

DATA SEGMENT
    str DB 'HELLO WORLD$'
    strlen EQU $-str
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    MOV CX, strlen
    LEA SI, str

CHARLOOP:
    CMP BYTE PTR SI, ' '
    JE INCR
    OR [SI], 20H
INCR:
    INC SI
    LOOP CHARLOOP
    MOV DX, OFFSET str
    MOV AH, 09H
    INT 21H 
           
EXIT:
    MOV AH, 4CH
    INT 21H
CODE ENDS
END START

