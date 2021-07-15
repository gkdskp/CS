; Decimal to hex conversion
; Code from https://www.tutorialspoint.com/bcd-to-binary-conversion-in-8051

ORG 0000H

MOV R0, #85H
MOV R1, #00H
MOV A, #00H

LOOP:
	ADD A, #01H
	DA A
	INC R1
	CJNE A, 00H, LOOP ; Run the loop until A = R0

END