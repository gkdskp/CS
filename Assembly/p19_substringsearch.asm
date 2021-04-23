; Substring search in a given string.

DATA SEGMENT
    str DB 'hello world$'
    strlen EQU $-str
    founds DB 'found$'
    notfounds DB 'not found$'
    substr DB 'ld'
    substrlen EQU $-substr
    nvowels DW ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    MOV CX, strlen
    XOR BX, BX
    LEA SI, str
    LEA DI, substr

COMP:
    MOV AL, [SI]
    CMP AL, [DI]
    JE SUBSTRCOMP
INCR:
    INC SI
    LEA DI, substr
    LOOP COMP
    LEA DX, notfounds
    MOV AH, 09H
    INT 21H
    JMP EXIT
    
SUBSTRCOMP:
    XOR BX, BX
COMPR:
    MOV AL, [SI]
    CMP AL, [DI]
    JNE INCR
    INC BX
    CMP BX, substrlen
    JE FOUND
    INC SI
    INC DI 
    JMP COMPR

FOUND:
    LEA DX, founds
    MOV AH, 09H
    INT 21H         
    
EXIT:
    MOV AH, 4CH
    INT 21H
CODE ENDS
END START