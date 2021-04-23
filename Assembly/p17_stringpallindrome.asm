; To check whether the given string is palindrome or not.

DATA SEGMENT
    str DB 'abcdba$'
    strlen EQU $-str
    pallindromes DB 'pallindrome$'
    notpallindromes DB 'not pallindrome$'
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    LEA SI, str
    LEA DI, str
    ADD DI, strlen
    SUB DI, 2 
    MOV CX, strlen
    SUB CX, 2

COMP:
    MOV AL, [DI]
    CMP AL, [SI]
    JNE NOTPALLINDROME
    INC SI
    DEC DI
    LOOP COMP

OUTPUT:   
    LEA DX, pallindromes
    MOV AH, 09H
    INT 21H
    JMP EXIT
    
NOTPALLINDROME:
    LEA DX, notpallindromes
    MOV AH, 09H
    INT 21H
    
EXIT:
    MOV AH, 4CH
    INT 21H
CODE ENDS
END START

