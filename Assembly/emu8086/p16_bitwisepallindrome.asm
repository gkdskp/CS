; Bitwise palindrome of a given no.
; Reference: https://www.geeksforgeeks.org/check-actual-binary-representation-number-palindrome/

DATA SEGMENT
    num DB 10H
    pallindromes DB 'Pallindrome', '$'
    notpallindromes DB 'Not pallindrome', '$'
    ones DW ? 
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA  
START:
    MOV AX, DATA
    MOV DS, AX
    MOV AL, num 
    MOV SI, OFFSET num
    MOV DI, OFFSET num
    MOV CX, 8

LOOP1:
    ROL AL, 1
    JC NEXT
    INC SI
    LOOP LOOP1

NEXT:
    ROR AX, 1
    
LOOP2:
    ROL AL, 1
    JC ZERO
    JMP ONE

ZERO:
    ROR NUM, 1
    JNC NOTPALLINDROME
    LOOP LOOP2
    JMP PALLINDROME

ONE:
    ROR NUM, 1
    JC NOTPALLINDROME
    LOOP LOOP2
    JMP PALLINDROME

PALLINDROME:
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
