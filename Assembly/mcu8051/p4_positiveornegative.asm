; To check whether the given number is positive or negative.

ORG 0000H

; Resetting R0
MOV R0, #00H

; Number to check whether positive or negative
MOV R1, #0FFH

; Rotating the number, MSB goes to carry
MOV A, R1
RLC A
JC NEG ; Jump to NEG if carry flag is set

MOV R0, #0H
JMP EXIT

NEG:
	MOV R0, #1H

EXIT:
	NOP

END






