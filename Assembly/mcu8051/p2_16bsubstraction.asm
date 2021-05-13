; Substraction of two 16-bit numbers

ORG 0000H

; R0R1 forms 2000H
MOV R0, #20H
MOV R1, #00H

; R2R3 form 1000H
MOV R2, #10H
MOV R3, #00H

; Substraction of upper bytes
MOV A, R0
SUBB A, R2
MOV R4, A ; Upper byte of result stored in R4

; Substraction of lower bytes
MOV A, R1
SUBB A, R3
MOV R5, A ; Upper byte of result stored in R5

END