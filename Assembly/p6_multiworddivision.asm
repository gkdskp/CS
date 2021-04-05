; Multiword division(32bit/16bit)

DATA SEGMENT
	dividend DD 1000000H
	divisor DW 1000H
	quotient DD ?
	remainder DD ?
ENDS DATA

CODE SEGMENT
ASSUME CS:CODE, DS:DATA 
START:
	MOV AX, DATA
	MOV DS, AX
	MOV AX, WORD PTR [dividend+2]
	MOV BX, WORD PTR [divisor]
	DIV BX
	MOV WORD PTR [quotient+2], AX
	MOV AX, WORD PTR [dividend]
	DIV BX
	MOV WORD PTR [quotient], AX
	MOV WORD PTR [remainder], DX
	MOV AH, 04CH
    INT 21H
ENDS CODE
END START