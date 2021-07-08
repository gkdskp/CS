; Linear Search in an array of 8-bit numbers.

ORG 0000H

MOV R0, #00H ; Resetting R0
MOV DPTR, #0000H ; Starting location of array
MOV R2, #08H ; Count of array
MOV R1, #18H ; Search Element

LOOP:
	MOVX A, @DPTR
	CLR C ; Clear the borrow
	SUBB A, R1
	JZ FOUND
	INC DPTR
	DJNZ R2, LOOP
	JMP EXIT

FOUND:
	MOV R0, #01H

EXIT:
	NOP

END
	
	
