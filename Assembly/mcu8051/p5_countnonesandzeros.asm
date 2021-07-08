; Count the number of ones and zeroes in a given number.

ORG 0000H

MOV R0, #00H ; Resetting R0
MOV R1, #00H ; Resetting R1

MOV R3, #0F1H ; The number
MOV R2, #08H ; Length of the number in bits

MOV A, R3

LOOP:
	RLC A
	JC ONES
	INC R1
	JMP INC
ONES:	INC R0
INC:	DJNZ R2, LOOP

END
