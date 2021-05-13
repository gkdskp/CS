; Multiplication and division of two 8 bit numbers

ORG 0000H

; Multiplying 20H with 10H
MOV A, #20H
MOV B, #10H
MUL AB
MOV R0, B ; Storing upper byte of result
MOV R1, A ; Storing lower byte of result

; Dividing 20H with 10H
MOV A, #20H
MOV B, #10H
DIV AB
MOV R2, B ; Remainder of division
MOV R3, A ; Quotient of division	

END